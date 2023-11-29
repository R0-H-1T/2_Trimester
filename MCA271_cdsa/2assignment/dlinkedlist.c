#include"dlinkedlist.h"
#include<stdio.h>
#include<stdlib.h>
#include"cinema.h"
#include<stdbool.h>


Dlist* make_movie(Movie m) {
    Dlist *newnode = (Dlist*) malloc (sizeof(Dlist));
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->movie = m;

    return newnode;
}


int lengthList(Dlist* temp){
   int count = 0;
    while( temp!= NULL ){
        temp = temp->next;
        count++;
    }
    return count;
}



Dlist* getAMovieNode() {
    Movie *m = getMovie();
    Dlist* newnode = (Dlist*) malloc (sizeof(Dlist));    
    newnode->prev  = NULL;
    newnode->movie = *m;
    newnode->next = NULL;

    return newnode;
}

void test3(Movie *ptr) {
    printf("ID: %d\nTitle: %s\nActors: ", ptr->movie_id, ptr->movie_name);
            for (int j = 0; j < 3; j++) {
                printf("%s", ptr->movie_cast[j]);
            }//m2.movie_cast[i], (i < actorCount - 1) ? "," : ""
            printf("\nRating: %.1f\nWatch duration: %huh %hum\n\n",
                   ptr->movie_rating ,ptr->movie_watch_duration[0],   ptr->movie_watch_duration[1]);
}

Dlist* insertInBeginning(Dlist **head) {
    Dlist* newnode = getAMovieNode();
    
    
    newnode->next = *head;
    (*head)->prev = newnode;
    *head = newnode;

}



Dlist* convert_to_dlinkedlist(Movie *ptr, int total_movies) {
    Dlist *head = NULL;
    Dlist *temp;
    for(int i=0; i<total_movies; i++){
        if( head == NULL ){
            head = temp = make_movie(*(ptr + i));
            // printf("\nOnce");
        }else{
            temp->next = make_movie(*(ptr + i));
            temp->next->prev =temp;
            temp = temp->next;
            // printf("\nAlways");
        }
    }
    // printf("\n%s", head->next->next->movie.movie_name);
    return head;
}

void deleteList(Dlist *temp) {
    Dlist *current = temp;
    Dlist *next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}


Dlist* createList(){

}

void display_llmovies_in_detail(Dlist *ptr, bool rev) {

    if(rev) {
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }    
        ptr = ptr->next;
        while(ptr != NULL) {
            printf("ID: %d\nTitle: %s\nActors: ", ptr->movie.movie_id, ptr->movie.movie_name);
            for (int j = 0; j < 3; j++) {
                printf("%s%s", ptr->movie.movie_cast[j], (j == CAST_NO-1)? "": ", ");
            }
            printf("\nRating: %.1f\nWatch duration: %huh %hum\n\n",
                   ptr->movie.movie_rating ,ptr->movie.movie_watch_duration[0],   ptr->movie.movie_watch_duration[1]);
            ptr = ptr -> prev;
        }
    }else {
        while( ptr!=NULL ){
            printf("ID: %d\nTitle: %s\nActors: ", ptr->movie.movie_id, ptr->movie.movie_name);
            for (int j = 0; j < 3; j++) {
                printf("%s%s", ptr->movie.movie_cast[j], (j == CAST_NO-1)? "": ", ");
            }
            printf("\nRating: %.1f\nWatch duration: %huh %hum\n\n",
                   ptr->movie.movie_rating ,ptr->movie.movie_watch_duration[0],   ptr->movie.movie_watch_duration[1]);
            ptr = ptr->next;
        }
    }
    
}

void display_llmovies(Dlist *ptr) {
    while(ptr != NULL){
        printf("\n%d %s", ptr->movie.movie_id, ptr->movie.movie_name);
        ptr = ptr->next;
    }
}