#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"



int main() {   
    list* head = NULL; 
    displayList(head);
    head = appendNode(head);
    displayList(head);
    // printf("List length: %d", listLength(head));
    deleteList(head);
    // free(head);
    return 0;
}



