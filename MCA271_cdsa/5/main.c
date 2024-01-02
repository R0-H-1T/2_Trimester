// Implementation of Linear and Binary Search
// Include the following::
// 1. Implement Linear, sentinel and binary search. 
// 2. Search for any two data types.
// 3. implement bubble and insertion sort before using binary search. Compute the total number of comparisons, data transfer operations for each sort.
// 4. calculate the element comparisons, index comparisons for linear search, sentinel and binary search. 
// -------------------------------------------------------------------------------------------------------------
// 
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

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int lomotu_partition(int *arr, int left, int right) {
    int pivot = arr[right];
    for (int i=left; i<right; i++) {
        if (arr[i] <= pivot) {
            swap(&arr[i], &(arr[left]));
            left++;
        }
    }
    swap(&arr[left], &(arr[right]));

    return left;
}

void quicksort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = lomotu_partition(arr, left, right);
        // pivot = left + (right - left) / 2;
        quicksort(arr, left, pivot-1);
        quicksort(arr, pivot+1, right);
    }
}



int main(int argc, char *argv[]) {
    int *arr = getArray(argc-1, argv);
    int n;
    // printf("\nEnter value to be searched: ");
    // display(arr, argc-1);
    // scanf("%d", &n);

    // printf("\n%d found at index: %d", n, linear_search(arr, argc-1, n));
    // printf("\n%d found at index: %d", n, sentinel_search(arr, argc-1, n));
    // printf("\n%d found at index: %d", n, binary_search(arr, argc-1, n));
    // printf("\nPivot position: %d\n", lomotu_partition(arr, 0, argc-2));
    quicksort(arr, 0, argc-2);
    display(arr, argc-1);

    free(arr);
    
    return 0;
}
