#ifndef _DOUBLY_LIST
#define _DOUBLY_LIST

#include"cinema.h"

typedef struct dlist {
    struct dlist *next;
    Movie movie;
    struct dlist *prev;
}Dlist;

Dlist* convert_to_dlinkedlist(Movie *, int );
Dlist* make_movie(Movie ); 
Dlist* createList();
void display_llmovies(Dlist *);
void deleteList(Dlist* );
Dlist* createNode();
#endif
