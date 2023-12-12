#include<stdio.h>
#include<stdlib.h>
#include"searching.h"

void display(int *arr, int n) {
    printf("[");
    for(int i=0; i<n; i++) {
        printf("%d%s", arr[i], (i == n-1) ? "" : " ");
    }
    printf("]");
}

int main(int argc, char *argv[]) {

    int *arr = getArray(argc-1, argv);
    

    display(arr, argc-1);
    
    return 0;
}