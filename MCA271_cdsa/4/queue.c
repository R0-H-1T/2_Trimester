#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void init_queue(Queue *ptr, int size) {
    ptr->arr = (int* ) malloc (sizeof(int) * size);
    ptr->capacity = size-1; 
    ptr->front = ptr->rear = -1;
    ptr->size = 0;
}

int is_full(Queue *ptr) {
    return (ptr->rear == ptr->capacity-1);
}

int is_empty(Queue *ptr) {
    return (ptr->front == -1);
}

void enqueue(Queue *ptr, int data) {
    if( !ptr->capacity ){
        fprintf(stderr, "Queue not initialized.");
        exit(EXIT_FAILURE);
    }

    if(is_full(ptr)) {
        printf("Queue is full.");
    } else {
        ptr->arr[++ptr->rear] = data;
        ++ptr->front;
        ++ptr->size;
    }
}

int deqeue(Queue *ptr) {
    if(is_empty(ptr)) {
        printf("Queue is empty.");
        return 0;
    }   
    int num = ptr->arr[ptr->front--];
    --ptr->size;
    return num;
}

int queue_size(Queue *ptr) {
    return ptr->size;
}

int peek(Queue *ptr) {
    return ptr->arr[ptr->front];
}

void display_queue(Queue *ptr) {
    printf("\nDisplaying queue: ");
    for(int i=0; i<ptr->size; i++) {
        printf("%d ", ptr->arr[i]);
    }
}


