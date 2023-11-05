#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cinema.h"
#define MOVIE_SIZE 100

int cinema_count = 0;

Cinema** create_db(Cinema **c, int rows, int cols) {
    c = ( Cinema** )malloc( sizeof(Cinema*) * rows );
    
    for(int i=0; i<rows; i++){
        c[i] = ( Cinema* )malloc( sizeof(Cinema) * cols );
    }

    return c;
}

void get_movies(Cinema** c, int rows, int cols) {
    printf("\n\n---- CINEMA #%d ----", ++cinema_count);
    int count = 0;
    for( int i=0; i<rows; i++) {
        for( int j=0; j<cols; j++) {
            (*(c + i) + j)->cinema_id = count++;
            printf("\nMovie %d", count);
            if(count-1 == 0){ // as \n was disrupting the newline -> appearance of output
                printf("\n");
            }
            getchar();
            char movie[MOVIE_SIZE];
            printf("Movie name: ");
            // fgets((*(c + i) + j)->movie_name, MOVIE_SIZE, stdin);
            fgets(movie, MOVIE_SIZE, stdin);
            movie[strcspn(movie, "\n")] = '\0';
            strcpy((*(c + i) + j)->movie_name, movie);

            printf("Release year: ");
            scanf("%hu", &(*(c + i) + j)->release_year);
            getchar();

            printf("Rating: ");
            scanf("%f", &(*(c + i) + j)->imdb_rating);
            getchar();

            printf("Box office earnings: ");
            scanf("%lu", &(*(c + i) + j)->box_office_earnings);
            getchar();

            printf("Runtime: ");
            scanf("%f", &(*(c + i) + j)->runtime);
            getchar();

        }
    }
}

void display_movies( Cinema** c, int rows, int cols ) {
    printf("\n\n---- CINEMA #%d ----", cinema_count);
    int count = 0;
    for( int i=0; i<rows; i++) {
        for( int j=0; j<cols; j++) {
            printf("\nMovie %d", (*(c + i) + j)->cinema_id + 1);
            printf("\nMovie name: %s", (*(c + i) + j)->movie_name);
            printf("\nRelease year: %hu",  (*(c + i) + j)->release_year);
            printf("\nRating: %f",  (*(c + i) + j)->imdb_rating);
            printf("\nBox office earnings: %lu",  (*(c + i) + j)->box_office_earnings);
            printf("\nRuntime: %f\n",  (*(c + i) + j)->runtime);
        }
    }
}


