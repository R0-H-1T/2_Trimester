#include<stdio.h>
#include"queue.h"

int main() {
    Queue q;
    int size;
    printf("\nEnter size of Queue: ");
    scanf("%d", &size);
    getchar(); // eat the trailing new line
    init_queue(&q, size); 
    enqueue(&q, 12);
    enqueue(&q, 2);
    enqueue(&q, 56);
    enqueue(&q, 56);
    enqueue(&q, 56);
    enqueue(&q, 56);
    display_queue(&q);

    printf("\nElement deqeued: %d", deqeue(&q));
    printf("\nPEEK: %d", peek(&q));

    display_queue(&q);
    return 0;
}
