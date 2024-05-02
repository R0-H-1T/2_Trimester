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


// declared extern for the value of the variable to persist
// across files.
extern int Movie_Counter;

void topMenu();
void secondMenu();
Movie* getMovie();
void menuHandler();
Movie* loadMovieFromFile();


//void displayMovie(Movie *p);
//void display_movietitle(Movie* ptr);
//Movie* getAnotherData();
// void deleteMovies(Movie* , int );
#endif
