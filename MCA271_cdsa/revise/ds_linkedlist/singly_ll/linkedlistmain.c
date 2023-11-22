#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

int main() {   
    int pos;
    list* head = createList(); 
    displayList(head);
    // insertBeginning(&head);
    // displayList(head);
    // appendNode(head);
    // displayList(head);
    printf("\nSize of linked list: %d", listLength(head));
    printf("\nEnter position to enter the node: ");
    scanf("%d", &pos);
    addAtPost(&head, pos);
    displayList(head);
    deleteList(head);
    // free(head);
    return 0;
}



