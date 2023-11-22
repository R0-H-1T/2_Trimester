#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

dlist* createNode() {
    printf("Enter data for new node: ");
    dlist *newnode = (dlist*) malloc (sizeof(dlist));
    if(newnode == NULL) {
        fprintf(stderr, "Failed to create new node");
        exit(EXIT_FAILURE);
    }
    newnode->prev = NULL;
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

int listSize(dlist *temp){
    int count = 0;
    while( temp!= NULL ){
        temp = temp->next;
        count++;
    }
    return count;
}

void insertInBeginning(dlist **head){
    if( *head == NULL ){
        char ch;
        printf("\nLinked List does not exist.\nMake one?(y/n):");
        getchar();
        scanf("%c", &ch);
        if( ch == 'y'|| ch == 'Y'){
            *head = createList();
        }
    }else{
        dlist* newnode = createNode();
        newnode->next = (*head);
        (*head)->prev = newnode;
        *head = newnode;
    }
}

void insertAtEnd(dlist *head){
    if( head == NULL ){
        char ch;
        printf("\nLinked List does not exist.\nMake one?(y/n):");
        getchar();
        scanf("%c", &ch);
        if( ch == 'y'|| ch == 'Y'){
            head = createList();
        }
    }else{
        dlist* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode();
        temp->next->prev = temp;
    }
}

void displayList(dlist* temp, bool rev) {
    printf("\nDisplaying list:");
    if(rev){
        while(temp->next->next != NULL){
            temp = temp->next;
        }    
        temp = temp->next;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp -> prev;
        }
    }else {
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp -> next;
        }
    }
}

void insertAtPos(dlist** head, int pos){
    int list_length = listSize(*head);
    dlist* temp = *head;
    dlist* newnode = createNode();

    if( pos <= list_length && pos > 0) {
        if(pos == 1) {
            insertInBeginning(head);
        }else if( pos == list_length ) {
            while( temp->next->next != NULL){
                temp = temp->next;
            }
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->next->prev = newnode;
            // inserting at last doesn not mean appending
            // fix this in singly linked list 
        }else {
            int counter = 1;
            while( counter != pos-1 ){
                temp = temp->next;
                counter++;
            }
            temp->next->prev = newnode;
            newnode->next = temp->next;
            temp->next = newnode;
            temp->next->prev = temp;
            
            // newnode->next->prev = newnode;
        }
    }else{
        printf("\nInvalid position entered\n");
    }
}
// 12 34 56 78 90 11

void deleteAtPos(dlist** head, int pos) {
    dlist *temp = *head;
    int list_size = listSize(*head);
    if ( pos <= list_size && pos > 0 ) {
        if( pos == list_size ) {
            while( temp->next->next != NULL ){
                temp = temp -> next;
            }
            free(temp->next->next);
            temp->next = NULL;
        }else if ( pos == 1 ) {
            *head = temp->next;
            free(temp);
        }else {
            int counter = 1;
            while( counter != pos-1 ) {
                temp = temp -> next;
                counter++;
            }
            dlist* nextnode = temp->next->next;
            nextnode->prev = temp;
            free(temp->next);
            temp->next = nextnode;
        }
    }
}

dlist* createList() {
    dlist *newnode = createNode();
    char ch;
    printf("Add another node(y/n): ");
    getchar();
    scanf("%c", &ch);
    if( ch=='y' || ch=='Y') {
        newnode->next = createList();
        newnode->next->prev = newnode;
    }
    return newnode;
}

void deleteList(dlist *temp) {
    dlist *current = temp;
    dlist *next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    free(current);  
    free(next);
}