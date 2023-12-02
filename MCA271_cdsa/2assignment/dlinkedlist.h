#ifndef _DOUBLY_LIST
#define _DOUBLY_LIST

#include"cinema.h"
#include"stdbool.h"
typedef struct dlist {
    struct dlist *next;
    Movie movie;
    struct dlist *prev;
}Dlist;

Dlist* convert_to_dlinkedlist(Movie *, int );
Dlist* make_movie(Movie ); 
Dlist* createList();
void display_llmovies(Dlist *);
void display_llmovies_in_detail(Dlist *, bool );
void deleteList(Dlist* );
Dlist* createNode();
int lengthList(Dlist* );
Dlist* insertInBeginning(Dlist **);
Dlist* getAMovieNode(); 
void addEnd(Dlist *);
void delAtPos(Dlist** , int);
void insertAtPos(Dlist**, int);

#endif  