#include"arr_stack.h"
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

void init_stack(Stack *s, unsigned int cap) {
    s->arr = (int*) malloc (sizeof(int) * cap);
    s->top = -1;
    s->capacity = cap;
}

bool is_empty(Stack *s) {
    return s->top < 0;
}

bool is_full(Stack *s) {
    // printf("%hu %hu", s->top, s->capacity);
    return s->top == s->capacity-1;
}

void push(Stack *s, int num) {
    if(is_full(s)) {
        fprintf(stderr, "\nStack is full. %d", num);
        return;
    }
    s->arr[++s->top] = num;
}

void pop(Stack *s) {
    if(is_empty(s)) {
        fprintf(stderr, "\nStack is empty.");
        return;
    }
    s->top--;
}

/**
 * @todo
 * if pop removes the last elemet and peek is done after that
 * A random values gets printed out.
 * Fix this
*/
int peek(Stack *s) {
    if(is_empty(s)) {
        printf("\nStack is empty.");
        return -1;
    }else{
        printf("\n##%d",s->arr[s->top]);
        return s->arr[s->top];
    }
}

int stack_size(Stack *s) {
    return s->top  + 1;
}



