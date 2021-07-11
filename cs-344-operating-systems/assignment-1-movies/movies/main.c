/* Arjun Kahlon
 * CS 344
 * Homework 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//movie structure
struct movie {
    char *movie_title;
    int movie_year;
    double rating;
    struct movie *next;
    char *language[5];
};

void yearMenu(struct movie *list); //submenu for user year choice
struct movie *createMovie (char *currLine); //parses currLine and creates movie struct
struct movie *processFile(char *filePath); //reads file and passes lines into createMovie()
void printMovie(struct movie* aMovie); //prints Movie fields (test function)
void languageMenu(struct movie *list); //submenu for language menu


struct movie *createMovie (char *currLine) {
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

    free(currLine); //frees memory
    fclose((movieFile)); //closes file
    return head;
}
//test function for confirming correct linked list member fields
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

//test function for printing entire list
void printMovieList(struct movie *list)
{
    while (list != NULL)
    {
        printMovie(list);
        list = list->next;
    }
}

//prints all movies corresponding to user inputted date
void printMoviesByDate(struct movie *list, int date)
{
    int movieFound = 0; //bool variable for confirming movie data being found
    while (list != NULL)
    {
        if (list->movie_year == date)
        {
            movieFound = 1; //if movie found, bool is non 0
            printf("%s\n", list->movie_title);
        }
        list = list->next;
    }
    //if no movie data is found, movieFound remains 0 and triggers error message
    if (movieFound == 0) {
        printf("%s %d\n", "No data about movies released in the year", date);
    }
}
//copies passed in node and returns copied node
struct movie *copyNode(struct movie *node)
{
    struct movie *copiedNode = malloc(sizeof(struct movie));
    copiedNode->movie_title = calloc(strlen(node->movie_title) + 1, sizeof(char));
    copiedNode->movie_year = node->movie_year;
    strcpy(copiedNode->movie_title, node->movie_title);
    copiedNode->rating = node->rating;
    copiedNode->next = NULL;
    return copiedNode;
}
//frees memory
void deleteNode(struct movie *node)
{
    //free(node->language);
    //node->next = NULL;
    free(node->movie_title);
    free(node);
}

//creates new list and stores highest rated movies per year
void printHighestRatingPerYear(struct movie *list)
{
    struct movie *ratingList;
    struct movie *head = NULL;

    head = copyNode(list);
    ratingList = head;

    while (list != NULL)
    {
        struct movie *currNode = head;
        struct movie *prevNode = NULL;

        while (currNode != NULL) {
            //checks is movie years are same
            if (list->movie_year == currNode->movie_year){
                if (list->rating > currNode->rating) {
                    struct movie *newNode = copyNode(list);

                    if (prevNode == NULL){
                        head = newNode;
                    }
                    else
                    {
                        prevNode->next = newNode;
                    }
                    newNode->next = currNode->next; //connects nodes
                    deleteNode(currNode); //frees memory for current Node
                }
                break;
            }
            else if (currNode->next == NULL) {
                currNode->next = copyNode(list);
            }

            prevNode = currNode;
            currNode = currNode->next;
        }

        list = list->next;
    }
    //prints new list
    struct movie *currentNode;
    while (head != NULL){

        printf("%d %.1f %s\n", head->movie_year, head->rating, head->movie_title);
        //increments head
        currentNode = head;
        head = head->next;
        deleteNode(currentNode);
    }
}

//prints movie by user inputted language choice
void printMovieByLanguage(struct movie *list, char *language)
{
    int languageFound = 0; //bool variable for language found
    while (list != NULL)
    {
        for (int i = 0; i < 5; i++) {
            if ((list->language[i] != NULL) && (strcmp(language, list->language[i]) == 0))
            {
                languageFound = 1; //language data found
                printf("%d %s\n", list->movie_year, list->movie_title);
            }
        }
        list = list->next; //updates list pointer to next structure
    }
    //If no language movie data found, error message is displayed
    if (languageFound == 0) {
        printf("%s %s\n", "No data about movies released in", language);
    }
}

//main user menu that validates int range of 1-4
void user_menu(struct movie *list) {

    int user_choice;

    do
    {
        printf("\n1. Show movies released in the specified year\n");
        printf("2. Show highest rated movie for each year\n");
        printf("3. Show the title and year of release of all movies in a specific language\n");
        printf("4. Exit\n");
        printf("Enter a choice from 1 to 4: ");
        scanf("%d",&user_choice);
        //switch statement for user choice 1 through 4
        switch(user_choice)
        {
            case 1: //calls submenu that prompts for year
                yearMenu(list);
                break;
            case 2: //print highest rated movie for each year
                printHighestRatingPerYear(list);
                break;
            case 3: //searches link list for all movies in certain language;
                languageMenu(list);
                break;
            case 4: printf("Exiting Program\n"); //exits program
                exit(0);
                break;
            default: printf("Invalid choice!\n"); //invalid input error
                break;
        }

    } while (user_choice != 4); //loop exits on input choiec 4

}
//submenu that prompts user for year input
void yearMenu(struct movie *list) {
    int year;
    printf("\nEnter the year for which you want to see movies: ");
    scanf("%d", &year);
    printMoviesByDate(list, year); //prints movie data with corresponding date
}
//submenu that prompts user for language choice
void languageMenu(struct movie *list) {
    char lang[20];
    printf("\nEnter the language for which you want to see movies: ");
    scanf("%s", lang);
    printMovieByLanguage(list, lang); //prints movie data with corresponding language
}
//returns length of linked list
int listLength(struct movie *list) {
    int count = 0; //count variable that increments with each structure
    while (list != NULL)
    {
        count++;
        list = list->next;
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 2) //when program is ran without an input file in argument
    {
        printf("You must provide the name of the file to process\n");
        printf("Example usage: ./movies movie_info1.txt\n");
        return EXIT_FAILURE;
    }
    //Process file and create linked list structure
    struct movie *list = processFile(argv[1]);
    //Alerts user that file has been processed
    printf("%s %s %s %d %s\n","Processed file", argv[1], "and parsed data for", listLength(list), "movies");

    //User Menu
    user_menu(list);
    return EXIT_SUCCESS;
}