#ifndef _CINEMA_V1
#define _CINEMA_V1

#define MOVIE_NO 6
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

extern int movie_counter;

Movie* getData();
Movie* getAnotherData();
void displayMovie(Movie* );
void menuHandler();
void display_movietitle(Movie* );
Movie* getMovie();


// void deleteMovies(Movie* , int );
#endif
