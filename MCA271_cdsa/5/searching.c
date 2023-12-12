#include"searching.h"
#include<stdio.h>
#include<stdlib.h>



int* getArray(int argc, char * argv[]) {
    int *arr = (int*) calloc (argc, sizeof(int));

    for(int i=0; i<argc; i++) {
        arr[i] = atoi(argv[i+1]);
    }
    return arr;
}
