#include"dlinkedlist.h"
#include<stdio.h>
#include<stdlib.h>
#include"cinema.h"


Dlist* make_movie(Movie m) {
    Dlist *newnode = (Dlist*) malloc (sizeof(Dlist));
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->movie = m;

    return newnode;
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
            temp->prev = temp;
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
    free(current);
    free(next);
}

Dlist* createNode(){

}

Dlist* createList(){

}



void display_llmovies(Dlist *ptr) {
    while(ptr != NULL){
        printf("\n%d %s", ptr->movie.movie_id, ptr->movie.movie_name);
        ptr = ptr->next;
    }
}