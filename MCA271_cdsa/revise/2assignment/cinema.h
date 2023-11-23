#ifndef _CINEMA_V1
#define _CINEMA_V1

#define MAX_MOVIE_SIZE 128
#define CAST_NO 3
#define CAST_SIZE 64

typedef struct Movie{
    unsigned short int movie_id;
    char movie_name[MAX_MOVIE_SIZE];
    float movie_rating;
    char movie_cast[CAST_NO][CAST_SIZE];
    unsigned short int movie_watch_duration[2];
}Movie;

void getData();
Movie* getAnotherData();

#endif

