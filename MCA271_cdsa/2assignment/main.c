#include<stdio.h>
#include"cinema.h"
#include"dlinkedlist.h"
#include<stdlib.h>
#include<string.h>




Movie* test2(void){
    Movie *ptr = (Movie*) malloc (sizeof(Movie));

    char movie_title[MAX_MOVIE_SIZE];
    printf("\nEnter movie name: ");
    fgets(movie_title, MAX_MOVIE_SIZE, stdin);
    strcpy(ptr->movie_name, movie_title);

    printf("\nEnter movie rating: ");
    scanf("%f", &ptr->movie_rating);
    getchar();

    printf("\nEnter movie cast -\n");
    char cast1[CAST_SIZE];
    for(int i=0; i<3; i++) {
        printf("%d: ", i+1);
        fgets(cast1, CAST_SIZE, stdin);
        strcpy(ptr->movie_cast[i], cast1);
    }
    
    printf("Enter watch duration in (hh mm) format: ");
    scanf("%hu %hu", &ptr->movie_watch_duration[0], &ptr->movie_watch_duration[1]);
    // printf("\n%.1f", ptr->movie_rating);
    // printf("%s", ptr->movie_cast[0]);
    // printf("%s", ptr->movie_cast[1]);
    // printf("%s", ptr->movie_cast[2]);
    // printf("\n\n%hu %hu", ptr->movie_watch_duration[0], ptr->movie_watch_duration[1]);   
    return ptr;
}

void test1(Movie *ptr) {
    printf("ID: %d\nTitle: %s\nActors: ", ptr->movie_id, ptr->movie_name);
            for (int j = 0; j < 3; j++) {
                printf("%s", ptr->movie_cast[j]);
            }//m2.movie_cast[i], (i < actorCount - 1) ? "," : ""
            printf("\nRating: %.1f\nWatch duration: %huh %hum\n\n",
                   ptr->movie_rating ,ptr->movie_watch_duration[0],   ptr->movie_watch_duration[1]);
}


int main(){

    printf("\n\n ########### WELCOME TO CINEMA ############\n\n");
    while(1){
        menuHandler();
    }

    // Movie *ptr = getMovie();
    // test1(ptr);
    // free(ptr);

    
    // test1(ptr);
    // printf("FROM MAIN:-> %s\n",ptr[0].movie_cast[2]);

  //  displayMovie(ptr);


    //free(ptr);


    return 0;
}
