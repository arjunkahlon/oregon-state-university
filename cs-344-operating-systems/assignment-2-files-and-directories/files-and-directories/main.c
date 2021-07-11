#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "time.h"
#include <fcntl.h>
#include <unistd.h>


struct movie {
    char *movie_title; //name of movie
    int movie_year; //year of movie
    double rating; //movie rating
    struct movie *next; //pointer to next movie struct in list
    char *language[5]; //array of c strings
};

struct movie *createMovie (char *currLine); //parses currLine and creates movie struct
struct movie *processFile(char *filePath); //reads file and passes lines into createMovie()
int verifyCSV(char * fileName); //verfies that file name meets conditions
char* findLargest(DIR *d); //returns largest file in directory with verified name
char* findSmallest(DIR *d); //returns smallest file
char* searchDirectory(DIR *d); //search the directory for user input string
void user_menu(); //main menu
void fileChoice (DIR *d); //process file menu
void printMovie(struct movie* aMovie); //print movie data (for testing)
void printMovieList(struct movie *list); //print movie list
char* createDirectory(); //creates directory
void createFiles(char * directoryName, struct movie *list); //creates file in directory

void user_menu(DIR *currDir) {

    int user_choice; //user input for either processing file or exiting

    do {
        printf("\n1. Select file to process\n");;
        printf("2. Exit\n");
        printf("Enter a choice from 1 or 2: ");
        scanf("%d", &user_choice);
        fflush(stdin);
        //switch statement for user choice
        switch (user_choice) {
            case 1: //calls submenu that prompts for file choice
                fileChoice(currDir);
                break;
            case 2:
                printf("Exiting Program\n"); //exits program
                exit(0);
                break;
            default:
                printf("Invalid choice!\n"); //invalid input error
                break;
        }

    } while (user_choice != 2); //loop exits on input choice e 2
}

//creates movie struct
//sourced from my submission for homework 1
struct movie *createMovie (char *currLine) {
    //printf("createMovie malloc\n");
    struct movie *currMovie = malloc(sizeof(struct movie));
    //printf("movie = %ld + %ld\n", currMovie, sizeof(struct movie));
    //char *saveptr;

    //first token is movie title
    char *token = strtok_r(NULL, ",", &currLine);
    currMovie->movie_title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->movie_title, token);
    //printf("DEBUG: %s\n", currMovie->movie_title);
    //printf("title = %ld + %ld\n", currMovie->movie_title, ((strlen(token) + 1) * sizeof(char)));

    //next token is year
    token = strtok_r(NULL, ",", &currLine);
    currMovie->movie_year = atoi(token); //converts cstring to int

    //next token is language

    char *languages = strtok_r(NULL, ",", &currLine);
    //printf("%s\n", languages);
    //currMovie->language = calloc(strlen(token) + 1, sizeof(char));
    //strcpy(currMovie->language, token);

    int i = 0;
    do{
        token = strtok_r(NULL, "[];", &languages);
        //printf("%s\n", token);
        if (token != NULL) {
            //int size = ((strlen(token) + 1) * sizeof(char)); (memory test)
            currMovie->language[i] = calloc(strlen(token) + 1, sizeof(char));
            //printf(",%ld + %ld", currMovie->language[i], ((strlen(token) + 1) * sizeof(char)));
            strcpy(currMovie->language[i], token); //copies token to language index
        }
        i++; //increments for loop variable
    }while (strcmp(languages, "\0") != 0); //executes until null character

    //printf("\n");

    //last token is rating
    token = strtok_r(NULL, "\n", &currLine);
    currMovie->rating = atof(token); //converts to floating type

    return currMovie;
}

//Processes file and creates linked list data structure
//sourced from my submission for homework 1

struct movie *processFile(char *filePath){
    FILE *movieFile = fopen(filePath, "r"); //opens file
    char *currLine = NULL; //initialize current line
    size_t len = 0;
    ssize_t nread;
    char *token; //declare token

    struct movie *head = NULL; //initializes head of linked list
    struct movie *tail = NULL; //initializes tail of linked list

    //skip first line
    getline(&currLine, &len, movieFile);

    //parses each line of file to build movie struct linked list
    while ((nread = getline(&currLine, &len, movieFile)) != -1){
        struct movie *newNode = createMovie(currLine);

        //check if linked list is empty and createst head and tail
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode; //adds onto end of list
            tail = newNode;
        }
    }

    //free(currLine); //frees memory
    fclose((movieFile)); //closes file
    return head;
}

//user menu for processing files
void fileChoice(DIR *d) {

    int user_choice; //user input
    int choice_pass; //checks if user entered correct input
    char* fileName = malloc(20);

    do
    {
        //printf("fileChoice malloc\n"); debug
        //file processing menu
        printf("\nEnter 1 to pick the largest file\n");
        printf("Enter 2 to pick the smallest file\n");
        printf("Enter 3 to specify the name of a file\n");
        printf("Enter a choice from 1 to 3: ");
        scanf("%d", &user_choice);
        fflush(stdin); //clear input buffer
        //switch statement for user choice 1 through 4
        switch(user_choice)
        {
            case 1: //pick largest file
                strcpy(fileName, findLargest(d));
                printf("\nNow processing the chosen file named %s\n", fileName);
                choice_pass = 0;
                break;
            case 2: //pick smallest file
                strcpy(fileName, findSmallest(d));
                printf("\nNow processing the chosen file named %s\n", fileName);
                choice_pass = 0;
                break;
            case 3: //Specify name of file
                strcpy(fileName, searchDirectory(d));
                printf("\nNow processing the chosen file named %s\n", fileName);
                choice_pass = 0;
                break;
            default: printf("Invalid choice!\n"); //invalid input error
                choice_pass = 1;
                break;
        }
        //Process file if choice pass = 0
        if (choice_pass == 0) {
            struct movie *list = processFile(fileName);
            //printMovieList(list); test data structure
            //printf("createMovie malloc 2\n"); test debug
            char *directoryName = malloc(30);
            strcpy(directoryName, createDirectory()); //creates directory
            createFiles(directoryName, list); //creates files in new directory
            free(directoryName);
        }

    } while (choice_pass == 1); //loop exits on input choice

}

//returns name of largest file
 char* findLargest(DIR *d) {
    char *largestFILE; //file size that will be returned
    struct dirent *dir;
    struct stat st;
    unsigned int largestSize;
    off_t fileSize;

    largestSize = 0; //initialize largest size
    d = opendir("."); //open current directory

    if (d) {
        while ((dir = readdir(d)) != NULL){
            stat(dir->d_name, &st);
            fileSize = st.st_size; //obtain file size
            if (((unsigned int)fileSize > largestSize) && (verifyCSV(dir->d_name) == 0)) {
                //printf("findLargest malloc\n");
                largestFILE = malloc(strlen((dir->d_name) + 1));
                strcpy(largestFILE, dir->d_name); //store file name
                largestSize = fileSize; //update largest file size
            }
        }
    }
    //close directory
    closedir(d);

    return largestFILE;
}

//returns name of smallest file
char *findSmallest(DIR *d) {
    char *smallestFILE; //file name that will be returned
    struct dirent *dir;
    struct stat st;
    unsigned int smallestSize;
    off_t fileSize;

    smallestSize = 0; //initialize smallest size
    d = opendir("."); //open current directory

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            stat(dir->d_name, &st);
            fileSize = st.st_size;

            if ((smallestSize == 0) && (verifyCSV(dir->d_name) ==0)) {
                smallestSize = fileSize;
            }

            if (((unsigned int)fileSize <= (unsigned int)smallestSize) && (verifyCSV(dir->d_name) == 0)) {
                //printf("findSmallest malloc\n");
                smallestFILE = malloc(strlen((dir->d_name) + 1));
                strcpy(smallestFILE, dir->d_name);
                smallestSize = fileSize;
            }
        }
    }

    //strcpy(smallestFILE, "movies_sample_2.csv");

    closedir(d);

    return smallestFILE;
}

//prompts user for input string and verifies user input
//returns c string if there is a match
char* searchDirectory(DIR *d) {
    //printf("searchDirectory malloc\n");
    int file_found = 0; //verifies user input matches file in directory
    struct dirent *dir;
    char* searchFILE = malloc(20);

    do {
        printf("\nEnter the complete file name: ");
        scanf("%s", searchFILE);

        d = opendir(".");

        while ((dir = readdir(d)) != NULL) {

            if ((strcmp((dir->d_name), searchFILE) == 0)) {
                file_found = 1; //file is found and outter loop can exit
                break;
            }
        }

        closedir(d); //close directory

    } while(file_found == 0);
    return searchFILE;
}

//verifies that file name meets conditions
int verifyCSV(char * fileName) {

    char prefixName[8];
    memcpy( prefixName, &fileName[0], 7 );
    prefixName[7] = '\0';

    //if file contains prefix movies_ and .csv extension, it is verified
    if ((strcmp(&fileName[strlen(fileName)-4], ".csv") == 0) && (strcmp(prefixName, "movies_") == 0))  {
        return 0;
    }
    return 1;
}
//prints movie data fields
//sourced from my submission for homework 1
void printMovie(struct movie* aMovie){
    printf("%s, %d, %.1f,", aMovie->movie_title,
           aMovie->movie_year,
           aMovie->rating);

    //char *title = aMovie->movie_title;
    //printf("%s,", title);
    char **a = aMovie->language;
    for ( int i = 0; i < 5; i++ ){
        char *lang = aMovie->language[i];
        if (lang == NULL) {
            break;
        } else {
            printf("%s,", lang); //prints language
        }
    }
    printf("\n");

}
//prints all movie struct data
//sourced from my submission for homework 1
void printMovieList(struct movie *list)
{
    while (list != NULL)
    {
        printMovie(list);
        list = list->next;
    }
}
//creates Directory with correct permissions and returns name of directory
char* createDirectory() {
    int directCreate;
    unsigned long randNum;
    //printf("createDirectory malloc\n");
    char * digitArr = malloc(5);
    char *prefix = "kahlona.movies.";
    srand(time(NULL));
    randNum = rand() % (99999 + 1 - 0) + 0;
    sprintf(digitArr, "%lu", randNum);
    //printf("\ndigitArr is %s\n", digitArr);

    //printf("createDirectory malloc 2\n");
    char *directoryName = malloc(strlen(prefix) + strlen(digitArr) + 1);
    strcpy(directoryName, prefix);
    strcat(directoryName, digitArr);

    //printf("Directory name is: %s", directoryName);

    directCreate = mkdir(directoryName, 0750);

    if (!directCreate)
        printf("\nCreated directory with name %s\n", directoryName);
    else {
        printf("Unable to create directory\n");
        exit(1);
    }

    return directoryName;
}
//changes current working directory to newly created directory and creates files with permissions
void createFiles(char *directoryName, struct movie *list) {

    chdir(directoryName);
    DIR *d;
    d = opendir(".");

    d = opendir(directoryName);
    struct dirent *dir;

    while (list != NULL) {

        //printf("createFiles malloc\n");
        char *yearName = malloc(9);
        sprintf(yearName, "%d.txt", list->movie_year);
        //printf("\n%s\n", yearName);


        int file_descriptor; //used for opening/creating/appending to file
        file_descriptor = open(yearName, O_RDWR | O_CREAT | O_APPEND , 0640);
        write(file_descriptor, list->movie_title, strlen(list->movie_title) + 1);
        write(file_descriptor, "\n", strlen(("\n")));
        //lseek(file_descriptor, 0, SEEK_END);
        close(file_descriptor);

            list = list->next;
    }
    chdir(".."); //changes to parent directory
    d = opendir("."); //opens parent directory
    closedir(d); //closes directory

}


int main(void) {
    DIR *d; //declares Directory pointer
    user_menu(d); //enters menu
    closedir(d); //closes directory
    return 0; //exit function
}
