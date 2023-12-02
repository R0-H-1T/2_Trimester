#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"cinema.h"
#include "dlinkedlist.h"
#include"helper.c"

int movie_counter = 0;

void displayMovie(Movie *ptr) {
    for(int i=0; i<MOVIE_NO; i++){
            printf("ID: %d\nTitle: %s\nActors: ", ptr[i].movie_id, ptr[i].movie_name);
            for (int j = 0; j < 3; j++) {
                printf("%s%s", ptr[i].movie_cast[j], (j == CAST_NO-1)? "": ", ");
            }//m2.movie_cast[i], (i < actorCount - 1) ? "," : ""
            printf("\nRating: %.1f\nWatch duration: %huh %hum\n\n",
                   ptr[i].movie_rating ,ptr[i].movie_watch_duration[0],   ptr[i].movie_watch_duration[1]);
    }
}

void topmenu(){
    printf("\n\nOptions\n");
    printf("\n1. Use Existing movie list.");
    printf("\n2. Create your movie list.");
    printf("\n3. Exit.");
    printf("\nEnter choice: ");
}

void secondmenu(){
    printf("\n\nOptions\n");
    printf("\n1. Display title only.");
    printf("\n2. Display movie in detail.");
    printf("\n3. Add movie at end.");
    printf("\n4. Display movie in beginning.");
    printf("\n5. Delete a movie at position.");
    printf("\n6. Go back.");

    printf("\nEnter choice: ");
}


Movie* getMovie(){
    printf("\n\nEnter details of movie --");
    Movie *ptr = (Movie*) malloc (sizeof(Movie));

    // 2
    getchar();
    char movie_title[MAX_MOVIE_SIZE];
    printf("\nEnter movie name: ");
    fgets(movie_title, MAX_MOVIE_SIZE, stdin);
    movie_title[strcspn(movie_title, "\n")] = '\0';
    strcpy(ptr->movie_name, movie_title);

    // 3
    printf("Enter movie rating: ");
    scanf("%f", &ptr->movie_rating);
    getchar();

    // 4
    printf("Enter min 3 actors -\n");
    char movie_cast[CAST_SIZE];
    for(int i=0; i<3; i++) {
        printf("%d: ", i+1);
        fgets(movie_cast, CAST_SIZE, stdin);
        movie_cast[strcspn(movie_cast, "\n")] = '\0';
        strcpy(ptr->movie_cast[i], movie_cast);
    }

    // 5
    printf("Enter watch duration in (hh mm) format: ");
    scanf("%hu %hu", &ptr->movie_watch_duration[0], &ptr->movie_watch_duration[1]);
    getchar();
    // 1
    ptr->movie_id = ++movie_counter;
    
    return ptr;
}

int inner_menuHandler(Dlist *movie_ptr) {
    while(1){
        int ch1;
        secondmenu();   
        scanf("%d", &ch1);
        switch(ch1) {
            case 1: 
                    display_llmovies(movie_ptr);
                    break;
            case 2: 
                    char order;
                    printf("\nDisplay in ascening or descending?(a/d): ");
                    getchar();  
                    scanf("%c", &order);
                    if( order == 'a'){
                        display_llmovies_in_detail(movie_ptr, false);
                    }else if ( order == 'd') {
                        display_llmovies_in_detail(movie_ptr, true);
                    }else{
                        printf("\nKey Invalid");
                    }
                    break;
            case 3:
                    addEnd(movie_ptr); 
                    break;
            case 4:
                    insertInBeginning(&movie_ptr);
                    break;
            case 5:
                    int pos;
                    printf("\nEnter pos of the movie to be deleted: ");
                    scanf("%d", &pos);
                    getchar();
                    delAtPos(&movie_ptr, pos);
                    break;
            case 6:
                    return 1;            
            default:
                    printf("Invalid choice provided");
                    break;
        }
    }
        // clear();
}

void menuHandler(){
    int ch;
    topmenu();
    scanf("%d", &ch);
    Dlist *movie_ptr = NULL;
    switch (ch){
    case 1:
        Movie *ptr = getData();
        movie_ptr = convert_to_dlinkedlist(ptr, MOVIE_NO);
        if(inner_menuHandler(movie_ptr)) break;
        break;
    case 2:
        movie_ptr = createList();
        break;
    case 3:
        printf("\n\nExiting...\nGood Bye\n");
        deleteList(movie_ptr);
        exit(EXIT_FAILURE);
        break;
    default:
        printf("\nInvalid choice selected");
        break;
    }    
}

void display_movietitle(Movie* ptr) {
    for(int i=0; i<MOVIE_NO; i++){
            printf("\nID: %d Title: %s", ptr[i].movie_id, ptr[i].movie_name);
    }
}

Movie* getData(){
    movie_counter = 0;
    Movie *m2 = (Movie*) malloc (sizeof(Movie) * MOVIE_NO);
    FILE *file = fopen("data.txt", "r");
    if ( file == NULL ) {
        fprintf(stderr, "\nUnable to open file...\nExiting");
        exit(EXIT_FAILURE);
    }
    char temp_cast[132];
    while (fscanf(
                    file,
                    // "%d\n %[^\n]\n %d\n %[^\n]\n %f\n %d %d\n"
                    "%hu\n%[^\n]\n%f\n%[^\n]\n%hu %hu\n",
                    //&(*(c + i) + j)->release_year
                    &m2[movie_counter].movie_id, m2[movie_counter].movie_name, &m2[movie_counter].movie_rating, temp_cast,
                    &m2[movie_counter].movie_watch_duration[0], &m2[movie_counter].movie_watch_duration[1]
                )== 6) {

        // Process actors string and store each actor in the array
        char *token = strtok(temp_cast, ",");
        int actorCount = 0;
        while (token != NULL && actorCount < CAST_NO) {
            strcpy(m2[movie_counter].movie_cast[actorCount], token);
            actorCount++;
            token = strtok(NULL, ",");
        }
        //printf("BEFORE: %d\n", m2[movie_count].movie_id);
        
        // Print or process the read data
        movie_counter++;
    }
    fclose(file);


    return m2;
}


// TEST FUNCTION
Movie* getAnotherData(){
    Movie *m1 = (Movie*) malloc (sizeof(Movie));
    m1->movie_id = 1;
    strcpy(m1->movie_name, "The Avengers");
    m1->movie_rating = 7.8;
    strcpy(m1->movie_cast[0], "Robert Downey Jr");
    strcpy(m1->movie_cast[1], "Jeremy Renner");
    strcpy(m1->movie_cast[2], "Chris Hemsworth");
    m1->movie_watch_duration[0] = 3;
    m1->movie_watch_duration[1] = 12;

    return m1;
}