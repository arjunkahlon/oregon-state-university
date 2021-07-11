/* CS261- Assignment 1 - Q.1*/
/* Name: Arjun Kahlon
 * Date: January 15th, 2019
 * Solution description: Practice with structs. Manipulating struct variables. Dynamic allocation.  
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

    struct student{
        int id;
        int score;
    };

    struct student* allocate(){
        /*Allocate memory for ten students*/
        struct student* ptr = (struct student*) malloc(sizeof(struct student)*10);

        /*Return the pointer*/
        return ptr;
    }

    void generate(struct student* students){
        /*Generate random and unique IDs and random scores for ten students,
   IDs being between 1 and 10, scores between 0 and 100*/
        srand(time(0));


        students[0].id = (rand() % 10) + 1;
        students[0].score = rand() % 101;

        for (int i =1; i < 10; i++) {
            int isUnique;
            do {
                isUnique = 1;
                students[i].id = (rand() % 10) + 1;

                for (int j = 0; j < i; j++) {
                    if (students[j].id == students[i].id) {
                        isUnique = 0;
                        break;
                    }
                }
            } while(isUnique == 0);

            students[i].score = rand() % 101;

        }

    }

    void output(struct student* students){
        /*Output information about the ten students in the format:
                 ID1 Score1
                 ID2 score2
                 ID3 score3
                 ...
                 ID10 score10*/

        int idCompare = 1; /*ensures proper order*/
        int printComplete = 0;
        do {


            for (int i = 0; i < 10; i++) {
                if (idCompare == students[i].id) {
                    printf("ID: %d", students[i].id);
                    printf(" Score: %d\n", students[i].score);
                    idCompare++;
                }
            }

            if (idCompare > 10)
            {
                printComplete = 1;
            }
        } while (printComplete == 0);
    }

    void summary(struct student* students){
        /*Compute and print the minimum, maximum and average scores of the
   ten students*/

        int max, min;
        int sum = 0;
        float average;
        max = students[0].score;
        min = students[0].score;

        for (int i = 0; i < 9; i++)
        {
            if (students[i+1].score > max)
            {
                max = students[i+1].score;
            }

            if(min > students[i+1].score)
            {
                min = students[i+1].score;
            }
        }

        for (int i = 0; i < 10; i++)
            sum += students[i].score;;

        average = (float)sum/10;
        printf("Max: %d\n", max);
        printf("Min: %d\n", min);
        printf("Average: %.6f", average);

    }

    void deallocate(struct student* stud){
        /*Deallocate memory from stud*/
        if (stud != NULL) {
            free(stud);
        }
    }

    int main(){
        struct student* stud = NULL;

        /*Call allocate*/
        stud = allocate();

        /*Call generate*/
        generate(stud);

        /*Call output*/
        output(stud);

        /*Call summary*/
        summary(stud);

        /*Call deallocate*/
        deallocate(stud);

        return 0;
    }
