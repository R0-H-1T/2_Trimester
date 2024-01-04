#include"cinema.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main() {
    srand(time(0));

    Movie *m;
    m = loadMovieFromFile();
    printMovie(m);

    sortMovies(m);
    printMovie(m);

    free(m);
    return 0;
}