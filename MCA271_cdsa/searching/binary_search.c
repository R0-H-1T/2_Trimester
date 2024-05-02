#include<stdio.h>


int binary_search (int *arr, int left, int right, int key) {

    if(left <= right){

        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (key < arr[mid]) 
            return binary_search (arr, left, mid-1, key);
        else if(key > arr[mid])
            return binary_search (arr, mid+1, right, key);
        else return -1;
    }

    return -1;
    // if (arr[mid] == key) {
    //     return mid;
    // }else if(left <= right){
    //     if (key < arr[mid]) 
    //         binary_search (arr, left, mid-1, key);
    //     // else if(key > arr[mid])
    //     else 
    //         binary_search (arr, mid+1, right, key);
    // } else return -1;
}

int main() {
    int arr[] = {2, 3, 5, 8, 10, 23, 55};
   
    printf("%d", binary_search(arr, 0, 6, 100));
    printf("%d", binary_search(arr, 0, 6, 10));


    return 0;
}
