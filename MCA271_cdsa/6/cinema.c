#include"cinema.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printMovie(Movie *ptr) {
    printf("\n\nMOVIE");    addPadding(MOVIE_SIZE-5);     printf("RATING\tRELEASE YEAR\n");
    for(int i=0; i<MOVIE_COUNT; i++){
        printf("%s", ptr[i].movie_title);
        addPadding(MOVIE_SIZE-strlen(ptr[i].movie_title));
        printf("%.1f\t%hu\n", ptr[i].movie_rating, ptr[i].movie_release_year);
    }
}

// Args: (unsigned short int) lower, higher;
unsigned short int getRandomYear(unsigned short int lower, unsigned short int higher) {
    return (rand() % (higher - lower + 1)) + lower; 
}

// add padding based on MOVIE_SIZE
void addPadding(int num) {
    for(int i=0; i<num; i++) {
        printf(" ");
    }
}

void swap(Movie *m1, Movie *m2) {
    Movie temp = *m1;
    *m1 = *m2;
    *m2 = temp;    
}

int hoares_partition(Movie *ptr, int left, int right) {
    // Movie pivot = *(ptr+right);
    Movie pivot = ptr[right];
    int high = right;

    while (left < right) {
        while (ptr[left].movie_release_year <= pivot.movie_release_year && left < right) {
            left++;
        }
        while (ptr[right].movie_release_year >= pivot.movie_release_year && left < right) {
            right--;
        }
        swap(&ptr[left], &ptr[right]);
    }
    swap(&ptr[left], &ptr[high]);

    return left;
}

void quicksort(Movie *ptr, int left, int right) {
    if (left < right) {
        int pivot = hoares_partition(ptr, left, right);
        quicksort(ptr, left, pivot-1);
        quicksort(ptr, pivot+1, right);
    }
}

void sortMovies(Movie *ptr) {
    quicksort(ptr, 0, MOVIE_COUNT-1);
}

void readData(char *readfile) {
    Movie m;

    FILE *file = fopen(readfile, "r");
    if (file == NULL) {
        fprintf (stderr, "\nERROR: Failed to open file.");
        exit(EXIT_FAILURE);
    }
    printf("\n\nReading from file: %s", readfile);
    printf("\n\nMOVIE");    addPadding(MOVIE_SIZE-5);     printf("RATING\tRELEASE YEAR\n");
    while (fread(&m, sizeof(Movie), 1, file) ){
        printf("%s", m.movie_title);
        addPadding(MOVIE_SIZE-strlen(m.movie_title));
        printf("%.1f\t%hu\n", m.movie_rating, m.movie_release_year);
    }
}

void writeData(char *outputFile, Movie *ptr) {
    FILE *file = fopen(outputFile, "w");

    if (file != NULL) {
        for (int i=0; i<MOVIE_COUNT; i++) {
            int result = fwrite(&ptr[i], sizeof(Movie), 1, file);
            if (result == 0) {  
                perror("fwrite");
                fprintf(stderr,"%s",strerror(result));   
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
        printf("\n\nSuccessfully written to file.");
        fclose(file);
    } else {
        // perror("\nERROR: Failed to open the file.");
        // fprintf(stderr,"%s",strerror(-1));
        fclose(file);
        perror("fopen");
        exit(EXIT_FAILURE);
    }
}

Movie* loadMovieFromFile() {
    int movie_counter = 0;
    Movie *m = (Movie*) malloc (sizeof(Movie) * MOVIE_COUNT);
    // open file
    FILE *file = fopen("data.txt", "r");
    if ( file == NULL ) {
        fprintf(stderr, "\nUnable to open file...\nExiting");
        exit(EXIT_FAILURE);
    }

    while(
        fscanf(
            file,
            "%[^\n]\n%f\n",
            m[movie_counter].movie_title, &m[movie_counter].movie_rating
        ) == 2
    ) {
        
        m[movie_counter].movie_release_year = getRandomYear(1978, 2023);
        movie_counter++;
    }

    fclose(file);
    return m;
}
