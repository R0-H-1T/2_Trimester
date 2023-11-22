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

void displayList(dlist* temp, bool rev) {
    printf("\nDisplaying list:\n");
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