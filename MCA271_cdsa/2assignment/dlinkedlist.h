#ifndef _DOUBLY_LIST
#define _DOUBLY_LIST

#include"cinema.h"

typedef struct dlist {
    struct dlist *next;
    Movie movie;
    struct dlist *prev;
}Dlist;


#endif
