#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct list {
    int data;
    struct list *link;
}list;


list* insertBeginning(list* );
list* createNode();
list* createList();
void displayList(list* );
void deleteList(list* );
list* appendNode(list* );
int listLength(list* );

// list* new_node(list* , int );
// list* create_list(list*, int* , int );
// void display_list(list *);
// void insert_beginning(list *);
// void deleteNode(list *);

#endif