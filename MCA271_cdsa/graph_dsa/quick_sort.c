#include <stdio.h>


void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getPivot (int *arr, int left, int right) {
    int pivot = arr[right];
    int high = right;

    while (left < right) {
        while (arr[left] <= pivot && left < right) {
            left ++;
        }
        while (arr[right] >= pivot && left < right) {
            right --;
        }
        swap (&arr[left], &arr[right]);
    }
    swap (&arr[left], &arr[high]);

    return left;
}

void quick_sort (int *arr, int left, int right) {
    if (left < right) {
        int pivot = getPivot (arr, left, right);
        quick_sort (arr, left, pivot-1);
        quick_sort (arr, pivot+1, right);
    }
}

int main () {
    int arr[] = {23, 12 -45, 3, -90};

//    quick_sort (arr, 0, (sizeof(arr) / sizeof(int)) - 1);
    merge_sort (arr, size);    

    printf("\n");
   for(int i=0; i<sizeof(arr)/ sizeof(int); i++) {
         printf("%d ", arr[i]);
    }
    return 0;
}
