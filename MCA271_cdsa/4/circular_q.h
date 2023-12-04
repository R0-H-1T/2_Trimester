#ifndef _CIRCULAR_Q
#define _CIRCULAR_Q


typedef struct circular_q{
    int *arr;
    int front, rear;
    int capacity;
    unsigned int size;
}CircularQ;

void queue_init(CircularQ *, int);

void enqueue(CircularQ *, int);

int is_full(CircularQ *);

void status(CircularQ *);

int dequeue(CircularQ *);

void display(CircularQ *);

int is_empty(CircularQ *);

#endif