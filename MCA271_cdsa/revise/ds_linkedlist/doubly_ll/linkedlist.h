#ifndef _DOUBLY_LL
#define _DOUBLY_LL

#include<stdbool.h>

typedef struct doublylinkedlist {
    struct doublylinkedlist *prev;
    int data;
    struct doublylinkedlist *next;
}dlist;

dlist* createNode();
void displayList(dlist *, bool);
void deleteList(dlist* );
dlist* createList();

#endif