#include<stdio.h>
#include<stdlib.h>

// void read_arr(int *ptr, int n) {
    
//     for(int i=0; i<n; i++) {
//         // printf("%d ", arr[i]);
//     }
// }

int main() {
    int arr[] = {12,34, 12,43};
    // read_arr( arr, sizeof(arr)/ sizeof(int) );
    // int *ptr = arr;
    // int *ptr1 = arr;
    printf("arr: %p\n", arr );
    printf("arr: %p\n", arr+1 );
    printf("arr: %p\n", arr+2 );
    // printf("arr: %p\n", &arr);
    // printf("arr: %p\n", arr + 1);
    // printf("arr: %p\n", &arr + 1);
    // printf("arr: %zu", ptr1+1);
    // printf("%p\t", *(&arr+1));
    // printf("%p", ptr+1);
    return 0;
}
