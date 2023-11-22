#include<stdio.h>
#include"linkedlist.h"
#include<stdlib.h>


int main() {
    int pos;
    
    dlist *head;
    head = createList();
    displayList(head, false);

    printf("\nNodes in linked list: %d", listSize(head));
    printf("\nEnter the position for deleting the node: ");
    scanf("%d", &pos);
    deleteAtPos(&head, pos);
    displayList(head, false);
    // insertAtEnd(head);
    // displayList(head, false);
    // displayList(head, true);

    deleteList(head);


    return 0;
}