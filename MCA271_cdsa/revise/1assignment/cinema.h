#ifndef _CINEMA_DB
#define _CINEMA_DB
#define MOVIE_SIZE 100
#define INVALID_CINEMA_ID 0 
typedef struct Cinema {
    unsigned int cinema_id;
    char movie_name[MOVIE_SIZE];
    unsigned short int release_year;
    float imdb_rating;
    unsigned long int box_office_earnings;
    float runtime;
}Cinema;

Cinema** create_db( Cinema **, int , int );

float** init_float_arr( float**, int, int );

void display_movie( Cinema  ); 

unsigned long int** init_unsigned_long_int( unsigned long int **, int, int );

void get_movies( Cinema** , int , int  );

void display_movies( Cinema** , int , int  );

// void sum( Cinema** ,Cinema**, float**, int, int, int );

void diff( Cinema** ,Cinema**, int**, int, int );

void do_analysis( Cinema**, Cinema**, int, int, int );

void disp_imdb_rating( float ** , int, int );

void disp_box_office_earnings( unsigned long int ** , int, int );

void delete_cinemaDB(Cinema** c, int);

#endif