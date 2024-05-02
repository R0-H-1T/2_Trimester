#include"dlinkedlist.h"
#include<stdio.h>
#include<stdlib.h>
#include"cinema.h"
#include<stdbool.h>


Dlist* makeMovie(Movie m) {
    Dlist *newnode = (Dlist*) malloc (sizeof(Dlist));
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->movie = m;

    return newnode;
}

int lengthList(Dlist* temp) {
    int count = 0;
    while( temp!= NULL ){
        temp = temp->next;
        count++;
    }
    return count;
}

void addEnd(Dlist *head) {
    Dlist *temp = head;
    
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = getAMovieNode();
    temp->next->prev = temp;
}

void insertAtPos(Dlist** head, int pos) {
    int list_length = lengthList(*head);
    Dlist* temp = *head;
    Dlist* newnode = getAMovieNode();

    if( pos <= list_length && pos > 0) {
        if(pos == 1) {    
            newnode->next = *head;
            (*head)->prev = newnode;
            *head = newnode;
        }else if( pos == list_length ) {
            while( temp->next->next != NULL){
                temp = temp->next;
            }
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->next->prev = newnode;
            // inserting at last doesn not mean appending
            // fix this in singly linked list 
        }else {
            int counter = 1;
            while( counter != pos-1 ){
                temp = temp->next;
                counter++;
            }
            temp->next->prev = newnode;
            newnode->next = temp->next;
            temp->next = newnode;
            temp->next->prev = temp;
            
            // newnode->next->prev = newnode;
        }
    }else{
        printf("\nInvalid position entered\n");
    }
}

Dlist* getAMovieNode() {
    Movie *m = getMovie();
    Dlist* newnode = (Dlist*) malloc (sizeof(Dlist));    
    newnode->prev  = NULL;
    newnode->movie = *m;
    newnode->next = NULL;

    return newnode;
}

void delAtPos(Dlist** head, int pos) {
    Dlist *temp = *head;
    int list_size = lengthList(*head);
    if ( pos <= list_size && pos > 0 ) {
        if( pos == list_size ) {
            while( temp->next->next != NULL ){
                temp = temp -> next;
            }
            free(temp->next->next);
            temp->next = NULL;
        }else if ( pos == 1 ) {
            *head = temp->next;
            // *head->prev = NULL; 
            free(temp);
        }else {
            int counter = 1;
            while( counter != pos-1 ) {
                temp = temp -> next;
                counter++;
            }
            Dlist* nextnode = temp->next->next;
            nextnode->prev = temp;
            free(temp->next);
            temp->next = nextnode;
        }
    }
}

Dlist* insertInBeginning(Dlist **head) {
    Dlist* newnode = getAMovieNode();
    
    newnode->next = *head;
    (*head)->prev = newnode;
    *head = newnode;

}

Dlist* convertToDlinkedlist(Movie *ptr, int total_movies) {
    Dlist *head = NULL;
    Dlist *temp;
    for(int i=0; i<total_movies; i++){
        if( head == NULL ){
            head = temp = makeMovie(*(ptr + i));
            // printf("\nOnce");
        }else{
            temp->next = makeMovie(*(ptr + i));
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

void displayMovieInDetail(Dlist *ptr, bool rev) {

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

void displayMovieTitle(Dlist *ptr) {
    while(ptr != NULL){
        printf("\n%d %s", ptr->movie.movie_id, ptr->movie.movie_name);
        ptr = ptr->next;
    }
}

// Create List
// Dlist* createList() {
// }

// Test to print a movie -> movie pointer
// void test3(Movie *ptr) {
//     printf("ID: %d\nTitle: %s\nActors: ", ptr->movie_id, ptr->movie_name);
//             for (int j = 0; j < 3; j++) {
//                 printf("%s", ptr->movie_cast[j]);
//             }//m2.movie_cast[i], (i < actorCount - 1) ? "," : ""
//             printf("\nRating: %.1f\nWatch duration: %huh %hum\n\n",
//                    ptr->movie_rating ,ptr->movie_watch_duration[0],   ptr->movie_watch_duration[1]);
// }
