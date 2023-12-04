#include"circular_q.h"
#include<stdio.h>
#include<stdlib.h>


void queue_init(CircularQ *ptr, int size) {
    ptr->arr = (int*) calloc (size, sizeof(int));
    ptr->size = 0;
    ptr->front = ptr->rear = -1;
    ptr->capacity = size;
}

int is_full(CircularQ *ptr) {
    // return ((ptr->rear+1) % ptr->capacity == ptr->front);
    return ((ptr->front == ptr->rear + 1) || (ptr->front == 0 && ptr->rear == ptr->capacity - 1));
}

int is_empty(CircularQ *ptr) {
    return (ptr->rear == -1);
}

void enqueue(CircularQ *ptr, int data) {
    if(is_full(ptr)) {
        printf("Queue is full");
        return;
    }
    if(ptr->front == -1) {
        ptr->front = 0;
    }   
    ptr->size++;
    ptr->rear = (ptr->rear + 1) % ptr->capacity;
    ptr->arr[ptr->rear] = data;
}

int dequeue(CircularQ *ptr) {
    if(is_empty(ptr)) {
        printf("Queue is empty.");
        return -1;
    }
    int num = ptr->arr[ptr->front];
    if( ptr->front == ptr->rear ) 
        ptr->front = ptr->rear = -1;
    else
        ptr->front = (ptr->front+1) % ptr->capacity;
    ptr->size--;
    return num;
}
// 67 9 45 -8 
void display(CircularQ *ptr) {
    int i;
    if (is_empty(ptr))
        printf(" \n Empty Queue\n");
    else {
        for (i = ptr->front; i != ptr->rear; i = (i + 1) % ptr->capacity) {
            printf("%d ", ptr->arr[i]);
        }
        printf("%d ", ptr->arr[i]);
    }
}

void status(CircularQ *ptr) {
    printf("\n\n#### STATUS ####");
    printf("\nCapacity: %d", ptr->capacity);
    printf("\nSize: %u", ptr->size);
    printf("\nSpace available : %d", ptr->capacity - ptr->size);
    printf("\nFront: %d", ptr->arr[ptr->front]);
    printf("\nRear: %d", ptr->arr[ptr->rear]);
    printf("\nDisplaying the queue: ");
    display(ptr);
}