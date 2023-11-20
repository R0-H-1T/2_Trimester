#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"linkedlist.h"

//Heap and stack memory
void insertBeginning(list** head){
    if( *head == NULL ){
        printf("\nLinked List does not exist.");
    }else{
        printf("\nInserting in the beginning\n");
        list* new_node = createNode();
        new_node->link = *head;
        *head = new_node;
    }
}


void appendNode(list* head){
    if( head == NULL ){
        printf("\nLinked list does not exit.\n");
    }else{
        printf("\nAppending node at end\n");
        list* temp = head;
        while( temp->link != NULL ){
            temp = temp->link;
        }
        temp->link = createNode();
    }
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
        fprintf(stderr, "\nFailed to create new node");
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
}



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

//        23 45 90 19 76
void addAtPost(list **head, int pos){
    int listsize = listLength(*head);
    if( pos > 0 && pos <= listsize){
        if( pos == 1 ){
            insertBeginning(head);
        }else if( pos == listsize){
            appendNode(*head);
        }else{
            int counter = 1;
            list *temp = *head;
            while(counter != pos-1){
                temp = temp->link;
                counter++;
            }
            list* next = temp->link;
            temp->link = createNode();
            temp->link->link = next;
        }
    }else{
        printf("\nInvalid position entered");
    }
}





