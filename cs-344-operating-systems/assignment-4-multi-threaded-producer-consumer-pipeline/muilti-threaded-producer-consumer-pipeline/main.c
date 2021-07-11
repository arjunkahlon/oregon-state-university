#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


//Buffer 1 - will accessible to threads 1 and 2
char lineBuffer1[50][1000];
pthread_mutex_t mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty_1 = PTHREAD_COND_INITIALIZER;

//Buffer 2 - will be accessible to threads 2 and 3
char lineBuffer2[50][1000];
pthread_mutex_t mutex_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty_2 = PTHREAD_COND_INITIALIZER;

//Buffer 3 - will be accessible to threads 3 and 4
char lineBuffer3[625][80]; //80 character line array
pthread_mutex_t mutex_3 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty_3 = PTHREAD_COND_INITIALIZER;

//count variable indicate producer/consumer lines available for processing
int count1 = 0;
int count2 = 0;
int count3 = 0;

/**********************************************************************************
*Input Thread function uses fgets() to read lines via stdin
*When STOP is encountered, the program sends a signal to other threads to complete
*STOP input string will not be processed and its memory allocation is reset
***********************************************************************************/

void *inputThread(void *args) {

    //pthread_t pw_tid = pthread_self();

    int readStop = 0; //LCV that exits when STOP is encountered
    int i = 0; //increments with each iteration
    char tempBuffer[1000]; //temporary buffer for reading input

    while (readStop == 0) {
        //write(fileno(stdout), "\na", 2);
        fgets(tempBuffer, 1000, stdin);
        //write(fileno(stdout), tempBuffer, 4);
        pthread_mutex_lock(&mutex_1);
        //write(fileno(stdout), "\nafter fgets", 12);
        strcpy(lineBuffer1[i], tempBuffer); //stores temp buffer in lineBuffer1
        count1++;
        if (strcmp(lineBuffer1[i], "STOP\n") == 0) {
            memset(lineBuffer1[i], 0, strlen(lineBuffer1[i]));
            count1 = -1;
            readStop = 1;
        }
        //printf("\nLine number %d is %s\n", i, lineBuffer1[i]);
        i++;
        pthread_cond_signal(&empty_1); //signal to thread 2 that line available
        //write(fileno(stdout), "\nb", 2);
        pthread_mutex_unlock(&mutex_1);
        //write(fileno(stdout), "\nc", 2);
    }
    return NULL;
}

/**********************************************************************************
*Line Separation Function replaces new line with " " space.
*This function consumes from lineBuffer1 and produces lineBuffer2
*Signals to thread 3 when line is ready to be processed
***********************************************************************************/

void *lineSeparatorThread(void *args) {

    for (int i = 0; i < 50; i++) {
        //write(fileno(stdout), "\nd", 2);
        pthread_mutex_lock(&mutex_1);

        while (count1 == 0) {
            //wait on signal from thread 1
            pthread_cond_wait(&empty_1, &mutex_1);
        }

        pthread_mutex_lock(&mutex_2);
        //Termination of subsequent threads
        if (count1 < 0) {
            //write(fileno(stdout), "\nz", 2);
            count2 = -1;
            pthread_cond_signal(&empty_2);
            pthread_mutex_unlock(&mutex_1);
            pthread_mutex_unlock(&mutex_2);
            break;
        }
        //stores empty stace if new line character is encountered in buffer
        for (int j = 0; j < 1000; j++) {
            if (strcmp("\n", &lineBuffer1[i][j]) == 0) {
                strcpy(&lineBuffer2[i][j], " ");
            }
            else {
                strcpy(&lineBuffer2[i][j], &lineBuffer1[i][j]);
            }
        }
        //write(fileno(stdout), "\ng", 2);

        count1--; //decrements count1 after consumption
        count2++; //increments count2 and production

        pthread_cond_signal(&empty_2); //signal to thread 3 that line available for processing
        pthread_mutex_unlock(&mutex_1);
        pthread_mutex_unlock(&mutex_2);
    }
    return NULL;
}

/**********************************************************************************
*plusSignThread function replaces ++ with a ^.
*Function consumes from lineBuffer2 and produces lineBuffer3
*Creates a new buffer with an 80 character per line index called lineBuffer3
*Signals to Thread 4 when 80 characters are ready to be written
***********************************************************************************/

void *plusSignThread(void *args) {

    //pthread_t pw_tid = pthread_self();
    //char tempBuffer[50][1000]; used for testing


    int count_row = 0; //first index for new buffer
    int count_column = 0; //second index for new buffer

    for (int i = 0; i < 50; i++) {
        pthread_mutex_lock(&mutex_2);

        while (count2 == 0) {
            //wait on signal from thread 2
            pthread_cond_wait(&empty_2, &mutex_2);
        }

        //pthread_mutex_lock(&mutex_3);

        if (count2 < 0) {
            //Signal for termination
            count3 = -1;
            pthread_cond_signal(&empty_3);
            pthread_mutex_unlock(&mutex_2);
            pthread_mutex_unlock(&mutex_3);
            break;
        }

        //write(fileno(stdout), "\nh", 2);

        //Store new buffer based on ++ condition

        for (int j = 0; j < 1000; j++) {
            if (strncmp("\0", &lineBuffer2[i][j], 1) == 0){
                //write(fileno(stdout), "\nw", 2);
                break;
            }
            if (strncmp("++", &lineBuffer2[i][j], 2) == 0) {
                //strcpy(&lineBuffer3[i][j1], "^");
                strcpy(&lineBuffer3[count_row][count_column], "^");
                j++;
            } else {
                strcpy(&lineBuffer3[count_row][count_column], &lineBuffer2[i][j]);
            }
            count_column++; //increment second index each iteration
            //increment row index when 80 characters are reached
            if (count_column == 80) {
                count_row++; //increment row index
                count_column = 0; //reset count_column for new line
                count3++; //increment count 3
                pthread_cond_signal(&empty_3); //signal thread 4 for output writing
            }
        }
        count2--; //consumed line from thread 2
        pthread_mutex_unlock(&mutex_2);
        pthread_mutex_unlock(&mutex_3);
    }

    return NULL;
}

/**********************************************************************************
*Output Thread function writes lineBuffer3 via stdout
*This thread will only print when there are 80 characters available for printing
***********************************************************************************/

void *outputThread(void *args) {

    //pthread_t pw_tid = pthread_self();

    for (int i = 0; i < 625; i++) {

        pthread_mutex_lock(&mutex_3);

        while (count3 == 0) {
            pthread_cond_wait(&empty_3, &mutex_3); //wait on thread 3 signal
            //write(fileno(stdout), "\nq", 2);
        }
        //terminate process
        if (count3 < 0) {
            pthread_mutex_unlock(&mutex_3);
            break;
        }

        //write(fileno(stdout), "\ni", 2);

        //writes lineBufffer3 via stdout

        for (int j = 0; j < 80; j++) {
            write(fileno(stdout), &lineBuffer3[i][j], 1);
        }
        write(fileno(stdout), "\n", 1); //new line after line
        count3--; //consumes line produced from thread 3
        pthread_mutex_unlock(&mutex_3);
    }
    return NULL;
}


int main(int argc, char *argv[]) {
    //Declare pthread_t thread variables
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;

    //Create processes
    pthread_create(&t1, NULL, inputThread, NULL);
    pthread_create(&t2, NULL, lineSeparatorThread, NULL);
    pthread_create(&t3, NULL, plusSignThread, NULL);
    pthread_create(&t4, NULL, outputThread, NULL);

    //Join Processes
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    //Prints Thread Completed. I will remove this to match Canvas Example
    //printf("\nAll threads completed successfully\n");
    exit(EXIT_SUCCESS);
}
