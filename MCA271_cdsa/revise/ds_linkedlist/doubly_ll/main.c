#include<stdio.h>
#include"linkedlist.h"
#include<stdlib.h>


int main() {
    int pos;
    
    dlist *head;
    head = createList();
    displayList(head, false);

    insertInBeginning(&head);
    displayList(head, false);

    printf("\nEnter position for insertion of node: ");
    scanf("%d", &pos);
    printf("\n");
    insertAtPos(&head, pos);
    displayList(head, false);
    displayList(head, true);


    // insertAtEnd(head);
    // displayList(head, false);
    // displayList(head, true);

    deleteList(head);


    return 0;
}