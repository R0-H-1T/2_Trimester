#include<stdio.h>
#include"linkedlist.h"
#include<stdlib.h>


int main() {
    
    dlist *head;
    head = createList();
    
    displayList(head, false);
    deleteList(head);


    return 0;
}