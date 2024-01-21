#include<stdio.h>


void bubble_sort(int *arr, int len) {
    for(int i=0; i<len-1; i++) {
        for(int j=0; j<len-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int *arr, int len) {
    for (int i=0; i<len-1; i++) {
        for (int j=i+1; j<len; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertion_sort(int *arr, int len) {
    for (int i=0; i<len; i++) {
        int key = arr[i];
        
        int j=0;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 =  temp;
}

int partition_algo (int *arr, int left, int right) {
    int pivot = arr[right];
    int high = right;

    while (left < right) {
        while (arr[left] <= pivot && left < right) {
            left ++;
        }
        while (arr[right] >= pivot && left < right) {
            right --;
        }
        printf("left: %d, right: %d", left, right);
        swap(&arr[left], &arr[right]);
    }
    swap(&arr[left], &arr[high]);

    return left;
}

void quick_sort (int *arr, int left, int right) {
    if (left < right) {
        int pivot = partition_algo (arr, left, right);
        quick_sort (arr, left, pivot-1);
        quick_sort (arr, pivot+1, right);
    }
}

void merge (int *arr, int left, int mid, int right) {
    int temp[right - left];
    int i=0, j=0, count=0;
    while (i<=mid &&  j<=right) {
        if (arr[i] <= arr[j]) {
            temp[count++] = arr[i++];            
        } else {
            temp[count++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[count++] = arr[i];
    }
    while (j <= right) {
        temp[count++] = arr[j];
    }


    for(int i=left, j=0; i<=right; i++, j++) {
        arr[i] = temp[j];
    }
}

void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {13, 32, 26, 35, 10};
    // bubble_sort(arr, sizeof(arr)/ sizeof(int));
    // selection_sort(arr, sizeof(arr) / sizeof(int));
    // insertion_sort(arr, sizeof(arr)/ sizeof(int));
    // quick_sort(arr, 0, 4);
    merge_sort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);
    
    
    printf("\n");
    for(int i=0; i<sizeof(arr)/ sizeof(int); i++) {
        printf("%d ", arr[i]);
    }

}