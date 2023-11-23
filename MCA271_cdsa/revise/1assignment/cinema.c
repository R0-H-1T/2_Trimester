#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cinema.h"
#define MOVIE_SIZE 100

int cinema_count = 0;

Cinema** create_db(Cinema **c, int rows, int cols) {
  
    c = ( Cinema** )malloc( sizeof(Cinema*) * rows );

    for(int i=0; i<rows; i++){
        c[i] = ( Cinema* )malloc( sizeof(Cinema) * cols );
    }

    return c;
}

float** init_float_arr(float** ptr, int rows, int cols) {
    ptr = (float**) malloc(sizeof(float*) * rows);

    for(int i=0; i<rows; i++){
        ptr[i] = (float*) malloc (sizeof(float) * cols);
    }

    return ptr;
}

unsigned long int** init_unsigned_long_int( unsigned long int **ptr, int rows, int cols) {
    ptr = (unsigned long int **) malloc(sizeof(unsigned long int*) * rows);

    for(int i=0; i<rows; i++){
        ptr[i] = (unsigned long int*) malloc (sizeof(unsigned long int) * cols);
    }

    return ptr;
}

void get_movies(Cinema** c, int rows, int cols) {
    printf("\n\n---- CINEMA #%d ----", ++cinema_count);
    int count = 0;
    for( int i=0; i<rows; i++) {
        for( int j=0; j<cols; j++) {
            (*(c + i) + j)->cinema_id = count++;
            printf("\nMovie %d", count);
            if(count-1 == 0){ // as \n was disrupting the newline -> appearance of output
                printf("\n");
            }
            getchar();
            char movie[MOVIE_SIZE];
            printf("Movie name: ");
            // fgets((*(c + i) + j)->movie_name, MOVIE_SIZE, stdin);
            fgets(movie, MOVIE_SIZE, stdin);
            movie[strcspn(movie, "\n")] = '\0';
            strcpy((*(c + i) + j)->movie_name, movie);

            printf("Release year: ");
            scanf("%hu", &(*(c + i) + j)->release_year);
            getchar();

            printf("Rating: ");
            scanf("%f", &(*(c + i) + j)->imdb_rating);
            getchar();

            fflush(stdin);
            printf("Box office earnings: ");
            scanf("%lu", &(*(c + i) + j)->box_office_earnings);
            getchar();

            printf("Runtime: ");
            scanf("%f", &(*(c + i) + j)->runtime);
            getchar();

        }
    }
}

void display_movies( Cinema** c, int rows, int cols ) {
    printf("\n\n---- CINEMA #%d ----", cinema_count);
    int count = 0;
    for( int i=0; i<rows; i++) {
        for( int j=0; j<cols; j++) {
            if ( (*(c + i) + j)->cinema_id != 0){    
                printf("\nMovie %d", (*(c + i) + j)->cinema_id + 1);
                printf("\nMovie name: %s", (*(c + i) + j)->movie_name);
                printf("\nRelease year: %hu",  (*(c + i) + j)->release_year);
                printf("\nRating: %.1f",  (*(c + i) + j)->imdb_rating);
                printf("\nBox office earnings: %lu",  (*(c + i) + j)->box_office_earnings);
                printf("\nRuntime: %2f\n",  (*(c + i) + j)->runtime);
            }
        }
    }
}

void disp_imdb_rating( float ** ptr, int rows, int cols ) {
    printf("\n\nMovie rating comparision between 2 cinemas\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%.1f\t\t", ptr[i][j]);
        }
        printf("\n");
    }
}

void disp_box_office_earnings( unsigned long int ** ptr, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%lu\t\t", ptr[i][j]);
        }
        printf("\n");
    }
}

unsigned long int box_office_average(Cinema **c, int rows, int cols) {
    unsigned long int sum=0,avg=0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            sum += (*(c + i) + j)->box_office_earnings;
        }
    }
    return sum;
}

void display_movie( Cinema c ) {
        printf("\nMovie %d", c.cinema_id + 1);
        printf("\nMovie name: %s", c.movie_name);
        printf("\nRelease year: %hu",  c.release_year);
        printf("\nRating: %.1f",  c.imdb_rating);
        printf("\nBox office earnings: %lu",  c.box_office_earnings);
        printf("\nRuntime: %2f\n",  c.runtime);
}

void do_analysis( Cinema** c1, Cinema** c2, int rows, int cols, int ch ){
    switch(ch) {
        case 1:
                // Difference of ratings between two matrices
                float **ptr;
                ptr = init_float_arr(ptr, rows, cols);
                for(int i=0; i<rows; i++) {
                    for(int j=0; j<cols; j++) {
                        ptr[i][j] = (*(c1 + i) + j)->imdb_rating - (*(c2 + i) + j)->imdb_rating;
                    }
                }
                disp_imdb_rating(ptr, rows, cols);
                free(ptr);
                break;
        case 2:
                // Average profit earnings 
                long unsigned int sum = box_office_average(c1, rows, cols);
                printf("\nAverage box office of CINEMA 1: Rs %li", sum/ (rows * cols));
                sum = 0;
                sum = box_office_average(c2, rows, cols);
                printf("\nAverage box office of CINEMA 2: Rs %li\n\n", sum/ (rows * cols));
                break;
        case 3:
                // Filter by years
                int year;
                printf("\nEnter year: ");
                scanf("%d", &year);
                char ch;
                printf("Less than or greater than year %d? l/g: ", year);
                getchar();
                scanf("%c", &ch);
                if( ch == 'l'){
                    int flag = 0;
                    for(int i=0; i<rows; i++) {
                        for(int j=0; j<cols; j++) {
                            if( (*(c1 + i) + j)->release_year < year ) {
                                flag = 1;
                                display_movie(c1[i][j]);
                            }
                        }
                    }        
                    if (flag == 0 )     printf("\nNo Movies found !!\n");
                }else if ( ch == 'g' ) {
                    int flag = 0;
                    for(int i=0; i<rows; i++) {
                        for(int j=0; j<cols; j++) {
                            if( (*(c1 + i) + j)->release_year > year ) {
                                flag = 1;
                                display_movie(c1[i][j]);
                            }
                        }
                    }
                    if (flag == 0 )     printf("\nNo Movies found !!\n");
                }else {
                    printf("\n\nWrong character entered.\nTry Again..\n");
                }
                break;
        case 4:
                // Delete the movie at row and col.
                // Initalize 0 or null to the fields of the structure.
                int c, drow, dcol;
                printf("\nDelete movie from cinema 1 or 2 (1/2): ");
                scanf("%d", &c);

                printf("\nYour cinema DB is of %d rows and %d cols\nEnter row and col to delete: ", rows, cols);
                scanf("%d %d", &drow, &dcol);
                if( c == 1 ) {
                    c1[drow][dcol].cinema_id = INVALID_CINEMA_ID;
                    printf("\nMovie deleted from cinema\n---------- Movies in CINEMA 1 ----------\n");
                    display_movies(c1, rows, cols);

                }else if ( c == 2 ) {
                    c2[drow][dcol].cinema_id = INVALID_CINEMA_ID;
                    printf("\nMovie deleted from cinema\n---------- Movies in CINEMA 2 ----------\n");
                    display_movies(c2, rows, cols);

                }else {  
                    printf("\nWrong choice entered :(\n ");
                }
                break;
        case 5:
            /**
             * Major @TODO
             * Insertion is completely dependent on rows and cols.
             * Need to individualy keep track of rows and cols for each cinema.
             * Depending on the movie id (which is automatically assigned to a movie),
             * we can get a count of total movies in the matrix and decide whether to resize the cols or not.
             * If the movie id == rows * cols, we'll have to resize the matrix using realloc.
             * Using realloc we'll add one more column to the matrix. so col + 1. For this we need to 
             *                   c1[i] = (Cinema*) realloc (c1[i], sizeof(Cinema) * (cols + 1));
             * track cols for each cinema. 
            */
                int cinema_no;
                printf("\nWhich cinema do you want to add movie to? (1/2): ");
                scanf("%d", &cinema_no);

                if( cinema_no == 1 ) {
                    // for(int i=0; i<rows; i++) {
                    //     c1[i] = (Cinema*) realloc (c1[i], sizeof(Cinema) * cols);
                    // }
                    printf("\nMovie inserted\n");
                }else if ( cinema_no == 2 ) {
                    printf("\nMovie inserted\n");
                    
                }else {
                    printf("\nInvalid key entered :(\n");
                }
                break;
        case 6:
                printf("\n\nExiting ...");
                exit(0);
        default:
                fprintf(stderr, "\nWrong choice selected.\n Try Again\n");
                abort();
    }
}
// can try stdargs lib for this --> @TODO
void delete_cinemaDB( Cinema** c, int cols ) {
    for(int i=0; i<cols; i++){
        free(c[i]);
    }
    free(c);
}