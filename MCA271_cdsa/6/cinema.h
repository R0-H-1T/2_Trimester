#ifndef _CINEMA_H
#define _CINEMA_H

#define MOVIE_SIZE 64
#define MOVIE_COUNT 6

typedef struct {
    unsigned short int movie_release_year;
    char movie_title[MOVIE_SIZE];
    float movie_rating;
} Movie;


Movie* loadMovieFromFile();
void printMovie(Movie *);
void addPadding(int );
unsigned short int getRandomYear(unsigned short int , unsigned short int );

void swap(Movie *, Movie *);
int hoares_partition(Movie *, int , int );
void quicksort(Movie *, int , int );
void sortMovies(Movie *);


#endif