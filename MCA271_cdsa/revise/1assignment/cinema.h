#ifndef _CINEMA_DB
#define _CINEMA_DB
#define MOVIE_SIZE 100

typedef struct Cinema {
    unsigned int cinema_id;
    char movie_name[MOVIE_SIZE];
    unsigned short int release_year;
    float imdb_rating;
    unsigned long int box_office_earnings;
    float runtime;
}Cinema;

Cinema** create_db( Cinema **, int , int );

void get_movies( Cinema** , int , int  );

void display_movies( Cinema** , int , int  );

#endif