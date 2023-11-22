#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct list {
    int data;
    struct list *link;
}list;


void insertBeginning(list**);
list* createNode();
list* createList();
void displayList(list* );
void deleteList(list* );
void appendNode(list*);
int listLength(list* );
void addAtPost(list **, int);


// list* new_node(list* , int );
// list* create_list(list*, int* , int );
// void display_list(list *);
// void insert_beginning(list *);
// void deleteNode(list *);

#endif