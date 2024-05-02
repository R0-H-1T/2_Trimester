#ifndef _VECTOR_H
#define _VECTOR_H

#include<stdlib.h>
#include<stdbool.h>
#define INITIAL_CAPACITY 64

typedef struct vector{
    size_t length;
    size_t capacity;
    size_t *arr;
}vector;


vector* new_vector(vector*);

void add(vector*, int );

void add_at(vector*, int, int);

void remove_at(vector*, int );

bool is_empty(vector *);

void length(vector*);

void delete_vector(vector*);

#endif
