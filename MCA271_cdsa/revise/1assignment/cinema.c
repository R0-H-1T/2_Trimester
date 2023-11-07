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


// void sum( Cinema**c1 ,Cinema**c2, float**ptr, int rows, int cols, int ch){
//     switch(ch){
//         case 1:     for( int i=0; i<rows; i++){
//                        for(int j=0; j<cols; j++){
//                             ptr[i][j] = (*(c1 + i) + j)->imdb_rating + (*(c2 + i) + j)->imdb_rating;
//                         }
//                     }
//                 break;
//         case 2:     for( int i=0; i<rows; i++){
//                        for(int j=0; j<cols; j++){
//                             ptr[i][j] = (*(c1 + i) + j)->box_office_earnings + (*(c2 + i) + j)->box_office_earnings;
//                         }
//                     }
//                 break;
//         case 3:     for( int i=0; i<rows; i++){
//                        for(int j=0; j<cols; j++){
//                             ptr[i][j] = (*(c1 + i) + j)->release_year + (*(c2 + i) + j)->release_year;
//                         }
//                     }
//                 break;
//         default: 
//                 exit(0);   
//     }

// }

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
            printf("\nMovie %d", (*(c + i) + j)->cinema_id + 1);
            printf("\nMovie name: %s", (*(c + i) + j)->movie_name);
            printf("\nRelease year: %hu",  (*(c + i) + j)->release_year);
            printf("\nRating: %1f",  (*(c + i) + j)->imdb_rating);
            printf("\nBox office earnings: %lu",  (*(c + i) + j)->box_office_earnings);
            printf("\nRuntime: %2f\n",  (*(c + i) + j)->runtime);
        }
    }
}

void disp_imdb_rating( float ** ptr, int rows, int cols ) {
    printf("ANALYSIS --------------------------------\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%2f\t\t", ptr[i][j]);
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
        printf("\nRating: %1f",  c.imdb_rating);
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
                // unsigned long int **ptr1;
                // ptr1 = init_unsigned_long_int(ptr1, rows, cols);
                
                long unsigned int sum = box_office_average(c1, rows, cols);
                printf("\nAverage box office of CINEMA 1: Rs %li", sum/ (rows * cols));
                sum = 0;
                sum = box_office_average(c2, rows, cols);
                printf("\nAverage box office of CINEMA 2: Rs %li\n\n", sum/ (rows * cols));
                // disp_box_office_earnings(ptr1, rows, cols);
                // free(ptr1);
                break;
        case 3:
                // FILTER BY YEARS
                int year;
                printf("\nEnter year: ");
                scanf("%d", &year);
                char ch;
                printf("\nLess than or greater than %d? l/g", year);
                getchar();
                scanf("%c", &ch);
                if( ch == 'l'){
                    int flag = 0;
                    for(int i=0; i<rows; i++) {
                        for(int j=0; j<cols; j++) {
                            if( (*(c1 + i) + j)->imdb_rating < year ) {
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
                            if( (*(c1 + i) + j)->imdb_rating > year ) {
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

                break;
        case 5:
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