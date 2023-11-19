#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"linkedlist.h"

//D:\dev\test\DS and ALGO\doubleLL.c
//

list* insertBeginning(list* head){
    printf("\nInserting node at beginning\n");
    if(head == NULL){
        printf("\nList is not created.\nCreating new list...\n");
        head = createNode();
    }else{
        list* firstNode = createNode();
        firstNode->link = head;
        head = firstNode;
    }
    return head;
}

list* appendNode(list* head){
    printf("\nAppending node at end");
    if( head == NULL ){
        printf("List Not created.\nCreating new list...\n");
        head = createNode();
    }else{
        list* temp = head;
        while( temp->link != NULL ){
            temp = temp->link;
        }
        temp->link = createNode();
    }
    return head;
}

int listLength(list* head){
    int count = 0;
    while( head != NULL ){
        head = head -> link;
        count++;
    }
    return count;
}

list* createNode() {
    printf("Enter data for the node: ");
    list* newNode = (list*)malloc(sizeof(list));
    if( newNode == NULL ){
        fprintf(stderr, "New Node create not possible");
        exit(EXIT_FAILURE);
    }
    scanf("%d", &newNode->data);
    newNode->link = NULL;
    return newNode;
}


list* createList() {
    list* newNode = createNode();

    char ch;
    printf("Add another node: ");
    getchar();
    scanf("%c", &ch);
    if( ch == 'y' ) {
        newNode->link = createList();
    }

    return newNode;
}

void displayList(list* temp) {
    while( temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("NULL");
}

// Difference between heap and stack memory :

void deleteList(list* head){
    list * current = head;
    list *next;
    while(current != NULL){
        next = current->link;
        free(current);
        current = next;
    }
    free(next);
    free(current);
}    