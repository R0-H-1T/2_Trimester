#include <stdio.h>


void merge (int *arr, int start, int mid, int end) {
    
}

void merge_sort (int *arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort (arr, start, mid);
        merge_sort (arr, mid+1, end);
        merge (arr, start, mid, end);
    }
}

int main () {
    int arr[] = {2,43, -45, 12, 4};
    merge_sort (arr, 0, (sizeof(arr)/sizeof(int)) - 1);
}