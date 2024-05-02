#include "ds_array.h"
#include<stdbool.h>
#include<stdlib.h>

vector* new_vector(vector*v){
    v->arr = (int *)malloc( sizeof(size_t) * INITIAL_CAPACITY );
    v->length = 0;
    v->capacity = INITIAL_CAPACITY;
    return v;
}

void add(vector*v, int num){
    if (v->length == 0){
        v->arr[0] = num;
    }else if ( v->length < v->capacity-1 ){
        v->arr[v->length++] = num;
    }
    else if ( v->length < v->capacity-1 ){
        v->arr[v->length++] = num;
    } 
}

int main(){
    vector *v;
    v = new_vector(v);
}
