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


int sentinel_search(int *arr, int len, int num) {
    int *new_arr = add_sentinel(arr, len, num);
    for(int i=0; i<len; i++) {
        if(new_arr[i] == new_arr[len]) {
            int index = i;
            free(new_arr);
            return index;
        }
    }
    free(new_arr);
    return -1;
}

// Copying the array and adding value to be searched at the end of the array
// Returning that array
int* add_sentinel(int *arr, int len, int num) {
    int *copy_arr = (int*) calloc (len, sizeof(int));
    for(int i=0; i<len; i++) {
        copy_arr[i] = arr[i];
    }
    copy_arr[len] = num;
    return copy_arr;
}

int linear_search(int *arr, int len, int num) {
    for(int i=0; i<len; i++) {
        if(num == arr[i]) {
            return i;
        }   
    }
}

