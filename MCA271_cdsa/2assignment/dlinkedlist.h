#ifndef _DOUBLY_LIST
#define _DOUBLY_LIST

#include"cinema.h"
#include"stdbool.h"


typedef struct dlist {
    struct dlist *next;
    Movie movie;
    struct dlist *prev;
}Dlist;


Dlist* makeMovie(Movie m) ;
int lengthList(Dlist* temp) ;
Dlist* getAMovieNode() ;
Dlist* convertToDlinkedlist(Movie *ptr, int total_movies) ;


// INSERTION
void addEnd(Dlist *head) ;
void insertAtPos(Dlist** head, int pos) ;
void delAtPos(Dlist** head, int pos) ;
Dlist* insertInBeginning(Dlist **head) ;


// DELETION
void deleteList(Dlist *temp) ;
void displayMovieInDetail(Dlist *ptr, bool rev) ;
void displayMovieTitle(Dlist *ptr) ;

// @todo
// Dlist* createList() ;

#endif  