#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"cinema.h"



void getData(){
    Movie m[5];
    int movie_count = 0;
    Movie m2[5];
    FILE *file = fopen("data.txt", "r");
    if ( file == NULL ) {
        fprintf(stderr, "Unable to open file.");
        exit(EXIT_FAILURE);
    }
    char temp_cast[132];
    while (fscanf(
                    file,
                    // "%d\n %[^\n]\n %d\n %[^\n]\n %f\n %d %d\n"
                    "%hu\n%[^\n]\n%f\n%[^\n]\n%hu %hu\n",
                    &m2[movie_count].movie_id, m2[movie_count].movie_name, &m2[movie_count].movie_rating, temp_cast,
                    &m2[movie_count].movie_watch_duration[0], &m2[movie_count].movie_watch_duration[1]
                )== 6) {

        // Process actors string and store each actor in the array
        printf("%s\n", temp_cast);
        char *token = strtok(temp_cast, ",");
        int actorCount = 0;
        while (token != NULL && actorCount < CAST_NO) {
            strcpy(m2[movie_count].movie_cast[actorCount], token);
            actorCount++;
            token = strtok(NULL, ",");
        }
        printf("%d\n", actorCount);
        printf("0: %s\n",m2[movie_count].movie_cast[0]);
        printf("1: %s\n",m2[movie_count].movie_cast[1]);
        printf("2: %s\n",m2[movie_count].movie_cast[2]);
        // Print or process the read data
        movie_count++;
    }
    fclose(file);
    for(int i=0; i<movie_count; i++){
            printf("ID: %d\nTitle: %s\nActors: ", m2[i].movie_id, m2[i].movie_name);
            for (int j = 0; j < 3; j++) {
                printf("%s%s", m2[i].movie_cast[j], (j == 3-1)? "": ", ");
            }//m2.movie_cast[i], (i < actorCount - 1) ? "," : ""
            printf("\nRating: %.1f\nWatch duration: %huh %hum\n\n",
                   m2[i].movie_rating ,m2[i].movie_watch_duration[0],   m2[i].movie_watch_duration[1]);
        }
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
