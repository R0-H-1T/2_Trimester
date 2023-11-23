#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"cinema.h"



void getData(){
    Movie m2;
    FILE *file = fopen("data.txt", "r");
    if ( file == NULL ) {
        fprintf(stderr, "Unable to open file.");
        exit(EXIT_FAILURE);
    }

    while (fscanf(
                    file,
                    // "%d\n %[^\n]\n %d\n %[^\n]\n %f\n %d %d\n"
                    "%hu\n%[^\n]\n%f\n%[^\n]\n%hu %hu\n",
                    &m2.movie_id, m2.movie_name, &m2.movie_rating, m2.movie_cast[0],
                    &m2.movie_watch_duration[0], &m2.movie_watch_duration[1]
                )== 6) 
    {

        // Process actors string and store each actor in the array
        char *token = strtok(m2.movie_cast[0], ", ");
        int actorCount = 0;

        while (token != NULL && actorCount < CAST_NO) {
            strcpy(m2.movie_cast[actorCount], token);
            actorCount++;
            token = strtok(NULL, ",");
        }

        // Print or process the read data
        printf("ID: %d\nTitle: %s\nActors: ", m2.movie_id, m2.movie_name);

        for (int i = 0; i < actorCount; i++) {
            printf("%s%s", m2.movie_cast[i], (i < actorCount - 1) ? "," : "");
        }

        printf("\nRating: %.1f\nWatch duration: %huh %hum\n\n",
               m2.movie_rating ,m2.movie_watch_duration[0],   m2.movie_watch_duration[1]);
    }

    fclose(file);
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
