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
    int n;
    printf("\nEnter value to be searched: ");
    scanf("%d", &n);
    display(arr, argc-1);

    printf("\n%d found at index: %d", n, linear_search(arr, argc-1, n));
    printf("\n%d found at index: %d", n, sentinel_search(arr, argc-1, n));

    

    free(arr);
    
    return 0;
}