#ifndef _ARR_STACK
#define _ARR_STACK

#include<stdbool.h>

typedef struct arr_stack {
    int *arr;
    int top;
    unsigned int capacity;
} Stack;

void init_stack(Stack *, unsigned int ); 
bool is_empty(Stack *);
bool is_full(Stack *);
void push(Stack *, int );
void pop(Stack *);
int peek(Stack *); 
int stack_size(Stack *);

#endif

