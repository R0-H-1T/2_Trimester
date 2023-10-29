#include<stdio.h>
#include<stdlib.h>

int* getArray(int *ptr, int n){
    printf("Enter %d elements:\n", n);
    for(int i=0; i<n ; i++)     scanf("%d", ptr+i);
    return ptr;
}

void displayArray(int *ptr, int n){
    printf("\nDisplaying array: ");
    for(int i=0; i<n; i++,ptr++)    printf("%d ", *ptr);
}

void displayOddPositioned(int *ptr, int n){
    printf("\nDisplaying odd positioned number: ");
    for(int i=0; i<n; i++, ptr++){
        if(i % 2 != 0) printf("%d ", *ptr);        
    }
}

void displayEvenNumbers(int *ptr, int n){
    printf("\nDisplaying even numbers in array: ");
    for(int i=0; i<n; i++, ptr++){
        if( *ptr %2 == 0) printf("%d ", *ptr);
    }
}

int displayingMaxNumber(int *ptr, int n){
    int max = 0;
    for(int i=0; i<n; i++, ptr++){
        if ( max < *ptr )   max = *ptr;
    }
    return max;
}

int* sumAndAverage(int *ptr, int n, int *res){
    res = (int *)calloc(2, sizeof(2));
    for(int i=0; i<n; i++, ptr++){
        *res += *ptr;
    }
    *(res+1) = *res/n;
    return res;
}


int main(void){
    int n;
    printf("Enter size array: ");
    scanf("%d", &n);

    int *ptr = (int*)calloc(n, sizeof(int)); 
    int *res;
    ptr = getArray(ptr, n);
    displayOddPositioned(ptr, n);
    displayEvenNumbers(ptr, n);
    printf("\nMax number: %d", displayingMaxNumber(ptr, n));
    res = sumAndAverage(ptr, n, res);
    printf("\nSum: %d, Average: %d", *res, *(res+1));
    return 0;
}