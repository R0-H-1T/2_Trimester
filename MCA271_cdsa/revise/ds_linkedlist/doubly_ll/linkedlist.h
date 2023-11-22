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
int listSize(dlist* );
void insertInBeginning(dlist **);
//insertInBeginning
//InsertEnd
//InsertAtPos
//DeleteEnd
//DeleteFirst
//DeleteAtPos

#endif