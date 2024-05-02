#ifndef _STACK_QUEUE
#define _STACK_QUEUE

typedef struct queue {
    int *arr;
    unsigned int capacity;
    int front, rear, size;
}Queue;


void init_queue(Queue *, int );
int is_full(Queue *);
int is_empty(Queue *);
void enqueue(Queue *, int );
int deqeue(Queue *);
int queue_size(Queue *);
int peek(Queue *);
void display_queue(Queue *);

#endif