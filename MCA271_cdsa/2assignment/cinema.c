#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"cinema.h"
#include "dlinkedlist.h"
#include"helper.c"


void displayMovie(Movie *ptr) {
    for(int i=0; i<MOVIE_NO; i++){
            printf("ID: %d\nTitle: %s\nActors: ", ptr[i].movie_id, ptr[i].movie_name);
            for (int j = 0; j < 3; j++) {
                printf("%s%s", ptr[i].movie_cast[j], (j == CAST_NO-1)? "": ", ");
            }//m2.movie_cast[i], (i < actorCount - 1) ? "," : ""
            printf("\nRating: %.1f\nWatch duration: %huh %hum\n\n",
                   ptr[i].movie_rating ,ptr[i].movie_watch_duration[0],   ptr[i].movie_watch_duration[1]);
    }
}

void topmenu(){
    printf("\n\nOptions\n");
    printf("\n1. Use Existing movie list.");
    printf("\n2. Create your movie list.");
    printf("\n3. Exit.");
    printf("\nEnter choice: ");
}

void menuHandler(){
    int ch;
    topmenu();
    scanf("%d", &ch);
    Dlist *movie_ptr = NULL;
    switch (ch){
    case 1:
        Movie *ptr = getData();
        // display_movietitle(ptr);
        movie_ptr = convert_to_dlinkedlist(ptr, MOVIE_NO);
        clear();
        display_llmovies(movie_ptr);
        deleteList(movie_ptr);
        break;
    case 2:
        movie_ptr = createList();
        break;
    case 3:
        printf("\n\nExiting...\nGood Bye\n");
        exit(EXIT_FAILURE);
        break;
    default:
        printf("\nInvalid choice selected");
        break;
    }    
}

void display_movietitle(Movie* ptr) {
    for(int i=0; i<MOVIE_NO; i++){
            printf("\nID: %d Title: %s", ptr[i].movie_id, ptr[i].movie_name);
    }
}

Movie* getData(){
    int movie_count = 0;
    Movie *m2 = (Movie*) malloc (sizeof(Movie) * MOVIE_NO);
    FILE *file = fopen("data.txt", "r");
    if ( file == NULL ) {
        fprintf(stderr, "\nUnable to open file...\nExiting");
        exit(EXIT_FAILURE);
    }
    char temp_cast[132];
    while (fscanf(
                    file,
                    // "%d\n %[^\n]\n %d\n %[^\n]\n %f\n %d %d\n"
                    "%hu\n%[^\n]\n%f\n%[^\n]\n%hu %hu\n",
                    //&(*(c + i) + j)->release_year
                    &m2[movie_count].movie_id, m2[movie_count].movie_name, &m2[movie_count].movie_rating, temp_cast,
                    &m2[movie_count].movie_watch_duration[0], &m2[movie_count].movie_watch_duration[1]
                )== 6) {

        // Process actors string and store each actor in the array
        char *token = strtok(temp_cast, ",");
        int actorCount = 0;
        while (token != NULL && actorCount < CAST_NO) {
            strcpy(m2[movie_count].movie_cast[actorCount], token);
            actorCount++;
            token = strtok(NULL, ",");
        }
        //printf("BEFORE: %d\n", m2[movie_count].movie_id);
        
        // Print or process the read data
        movie_count++;
    }
    fclose(file);


    return m2;
}


// TEST FUNCTION
Movie* getAnotherData(){
    Movie *m1 = (Movie*) malloc (sizeof(Movie));
    m1->movie_id = 1;
    strcpy(m1->movie_name, "The Avengers");
    m1->movie_rating = 7.8;
    strcpy(m1->movie_cast[0], "Robert Downey Jr");
    strcpy(m1->movie_cast[1], "Jeremy Renner");
    strcpy(m1->movie_cast[2], "Chris Hemsworth");
    m1->movie_watch_duration[0] = 3;
    m1->movie_watch_duration[1] = 12;

    return m1;
}
