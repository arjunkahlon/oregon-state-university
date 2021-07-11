#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

void execCD(char * args[]);
pid_t executeCommand(char *command, char * args[], char *inFile, char *outFile, int backgroundFlag, int *status);
//int changeIO(char * ioFile, int isInput);
//void replaceIO(int fileHandle);
//void hand_SIGINT(int signo);

void hand_SIGINT(int signo){
    char * message = "\nterminated by signal";
    write(fileno(stdout), message, 22);
    //write(fileno(stdout), signo, sizeof(int));
    exit(0);
}

/*execCD function
 * Changes to directory provided in argument. If no argument exists,
 * change to default directory
 * */

void execCD(char * args[]) {

    char cwd[1024];

    //printf("\nHome = %s\n", getenv("HOME"));

    if(args[1] != NULL) {
        printf("%s\n", args[1]);
        chdir(args[1]);
    }
    else {
        chdir(getenv("HOME")); //changes to home if no argument
    }

    getcwd(cwd, sizeof(cwd));
    printf("Current working directory: %s\n", cwd); //prints directory
    fflush(stdout);
}

/*changeIO function
 * This was a input/output redirection function that I experimented with
 * before implementing my input/output redirection in my executeCommand function
**/

/*int changeIO(char * ioFile, int isInput) {
    int handles[2];

    if (ioFile != NULL) {
        int fileNum;

        if (isInput == 1) {
            fileNum = fileno(stdin);
            handles[0] = open(ioFile, O_RDONLY, 0444);
            handles[1] = dup(fileno(stdin));
        }
        else {
            fileNum = fileNum(stdout);
            handles[0] = open(ioFile, O_CREAT|O_WRONLY|O_TRUNC, 0222);
            handles[1] = dup(fileno(stdin));
        }

        if (handles[0] == -1) {
            printf("\nError: Invalid Input\n");
            exit(1);
        }

        //int saveIn = dup(fileno(stdin));
        if (dup2(handles[0], fileNum) == -1) {
            printf("dup2 input redirection error");
            exit(1);
        }
    }
    return handles;
}*/

/* replaceIO function
 * Reversed IO back to stdin/stdout from input/output stream
 * ***/

/*void replaceIO(int fileHandle) {
    if (fileHandle != -1) {
        fflush(stdin);
        close(fileHandle);

    }
    else {
        fflush(stdin);
    }
}*/

/* executeCommand function
 * This function executes the shell command passed from main.
 *
 * Args are passed in as an array.
 *
 * Input/Output redirection is handled if operators are specified
 *
 * backgroundFlag specifies if process is in foreground or background
 *
 * Returns process id which is stored in pid_t array
 * ***/

pid_t executeCommand(char *command, char * args[], char *inFile, char *outFile, int backgroundFlag, int * status) {
    int INPUT_STREAM = fileno(stdin);
    int OUTPUT_STREAM = fileno(stdout);

    //int fileNum;
    //save input and output
    int saveIn = -1;
    int saveOut = -1;

    //if input is specified with <
    if (inFile != NULL) {

        //fileNum = fileno(stdin);
        int in = open(inFile, O_RDONLY, 0444);
        saveIn = dup(INPUT_STREAM);

        //input failure
        if (in == -1) {
            printf("\nError opening input file %s\n", inFile);
            fflush(stdout);
        }

        //input redirection failure
        if (dup2(in, INPUT_STREAM) == -1) {
            printf("\nError redirecting input\n");
            fflush(stdout);
        }
        //close input
        close(in);
    }

    //if output is specified with >>
    if (outFile != NULL) {
        //fileNum = fileno(stdin);

        //call open function with create, truncate, write only
        int out = open(outFile, O_CREAT|O_WRONLY|O_TRUNC, 0777);
        saveOut = dup(OUTPUT_STREAM);

        //output failure
        if (out == -1) {
             printf("\nError opening output file %s\n", outFile);
            fflush(stdout);
        }

        //output redirection failure
        if (dup2(out, OUTPUT_STREAM) == -1) {
            printf("\nError redirecting output\n");
            fflush(stdout);
        }
        //close output
        close(out);
    }

    //fork
    pid_t cpid = fork();

    //switch case for cpid. -1 is Failure. 0 is child. 1 is parent.
    switch(cpid) {
        case -1:
            printf("\nFork error\n");
            fflush(stdout);
            exit(1);
        case 0:
            //if command is to be in background
            if (backgroundFlag == 1) {
                printf("background pid is %ld\n", (long) getpid());
                fflush(stdout);

                struct sigaction SIGINT_action = {0};
                SIGINT_action.sa_handler = hand_SIGINT;
                sigfillset(&SIGINT_action.sa_mask);
                SIGINT_action.sa_flags = 0;
                sigaction(SIGINT, &SIGINT_action, NULL);
            }
           //execute arguement
            if(execvp(command, args) == -1) {
                printf("\nThere is no such file or directory\n"); //handle execute failure
                exit(-1);
            }
            //printf("Got here");
            break;
        default:
            if (backgroundFlag == 0) {
                waitpid(cpid, status, 0);
            }
            break;
    }

    fflush(stdin);
    fflush(stdout);

    //redirect input if input file is specified
    if (inFile != NULL) {
        //printf("\nfileno Input is %d",(fileno(stdin)));
        dup2(saveIn, INPUT_STREAM);
        close(saveIn);
    }

    //redirect output if output file is specified
    if (outFile != NULL) {
        //printf("\nfileno Output is %d",(fileno(stdout)));
        dup2(saveOut, OUTPUT_STREAM);
        close(saveOut);
    }
    //return process id pid_t
    return cpid;
}

/* main function
 * Main function for smallsh
 *
 * Contains main function loop which prompts user with a colon before
 * each command
 *
 * Keeps track of status and process ids of processes
 * ***/


int main() {

    int exitLoop = 0; //loop condition
    int status = 0; //status
    char *args[512]; //argument array
    char *inFile = NULL; //input file name
    char *outFile = NULL; //output file name
    char *token; //parsing token
    char *command; //command to be executed
    pid_t processArr[512]; //process id array
    int processIndex = 0; //index for looping through process array

    struct sigaction ignore_action = {0};
    ignore_action.sa_handler = SIG_IGN;
    sigaction(SIGINT, &ignore_action, NULL);

    //printf("\nin is %d\n",fileno(stdin));
    //printf("\nout is %d\n",fileno(stdout));


    while (exitLoop == 0) {
        char *curr_line; //will store line
        int index = 1; //argument array index
        int backgroundFlag = 0; //is background flag?

        //kill background processes

        for (int i = 0; i < processIndex; i++) {
            if (waitpid(processArr[i], NULL, 0) == processArr[i]) {
                kill(processArr[i], 0);
            }
        }
        //allocate memory for curr_line
        curr_line = (char *)malloc(2048);
        //dup2(dup(1), 1);
        fflush(stdin);
        fflush(stdout);
        //prompt user with :
        printf(": ");
        if (fgets(curr_line, 2048, stdin) == NULL) {
            exitLoop = 1;
            //return 0;
        }


        //fflush(stdin);
        //printf("%s", curr_line);

        //create if statement to see if last character of line is &

        /*char curr_line_repl[2048];
        int repl_index = 0;
        char currPid[8];
        sprintf(currPid, "%d", (int)getpid());
        printf("PID = %d", (int)getpid());

        for (int i = 0; i < strlen(curr_line); i++) {
            if (curr_line[i] == '$' && curr_line[i+1] == '$') {
                strcpy(&curr_line_repl[repl_index], currPid);
                i++;
                repl_index += strlen(currPid);
            } else {
                curr_line_repl[repl_index] = curr_line[i];
                repl_index++;
            }
        }*/

        //printf("\ncurr_line_repl is %s\n", curr_line_repl);

        // store curr_line in line
        char *line = curr_line;

        //store initial token
        token = strtok_r(line, " \n", &line);

        //printf("%s\n", line);
        //printf("%s\n", token);

        //handles blank lines and comments for input
        if (token == NULL || strcmp(token, "#") == 0) {
            continue;
        }
        //store command from token
        command = malloc(sizeof(token));
        strcpy(command, token);

        //store arguments in arg array
        args[0] = malloc(sizeof(token));
        strcpy(args[0], token);

        //if ((strcmp(token, "exit") != 0 && strcmp(token, "cd") != 0 && strcmp(token, "status") != 0))

        //strok_r line to store input file, output file and background process based on delim

        while ((token = strtok_r(NULL, " \n", &line)) != NULL) {
            //printf("\nindex is %c\n", line[strlen(line) - 2]);
            //printf("\ntoken = %s\n", token);

            if (strcmp(token, "<") == 0) {
                token = strtok_r(line, " \n", &line);
                inFile = malloc(sizeof(token));
                strcpy(inFile, token);
                //printf("\ninFile is %s\n", inFile);

            } else if (strcmp(token, ">") == 0) {
                token = strtok_r(line, " \n", &line);
                outFile = malloc(sizeof(token));
                strcpy(outFile, token);
                //printf("\noutFile is %s\n", outFile);
                //printf("\nsize of outfile: %lu\n", strlen(outFile));
            } else if ((strcmp(token, "&") == 0) && (token == &line[strlen(line) - 2])) {
                //printf("\n& test works\n");
                backgroundFlag = 1;
            } else {
                //handle arguements
                args[index] = malloc(sizeof(token));
                strcpy(args[index], token);
                index++;
                //printf("\ntest arguments entry works\n");
            }
        }
        //allocate args
        args[index] = malloc(sizeof(char));
        args[index] = '\0';

        if (strcmp(command, "cd") == 0) {
            //printf("\nPlaceholder for cd\n");
            execCD(args);
            //execute change directory function
        }
        else if (strcmp(command, "status") == 0) {
            printf("\nExit status is %d\n", status);
            //execute status function
        }
        else if (strcmp(command, "exit") == 0) {
            //printf("\nPlaceholder for exit\n");
            //call exit processes function

            //kills processes
            for (int i = 0; i < processIndex; i++) {
                    kill(processArr[i], 0);
            }
            exit(0);
        }
        else{
            //printf("\nbackgroundFlag = %d\n", backgroundFlag);
            pid_t pid = executeCommand(command, args, inFile, outFile, backgroundFlag, &status);
            if (pid >= 0) {
                processArr[processIndex] = pid;
                //printf("\nReturned pid is %ld\n", (long) processArr[processIndex]);
                processIndex++;
            }

            //break;
        }
        //free memory
        free(curr_line);
        inFile = NULL;
        outFile = NULL;

        //free args array
        for (int i = 0; i < (sizeof(args)/sizeof(args[0])); i++) {
            args[i] = NULL;
        }

    }

    return 0;
}
