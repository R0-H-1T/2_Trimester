#include<stdio.h>
#include"circular_q.h"

int main() {
    int size;
    printf("\nEnter the size of the queue: ");
    scanf("%d", &size);

    CircularQ q;
    queue_init(&q, size);

    enqueue(&q, 90);
    enqueue(&q, 12);
    enqueue(&q, -12);
    enqueue(&q, -43);
    status(&q);
    printf("\nDisplaying queued elem: %d ", dequeue(&q));
    printf("\nDisplaying queued elem: %d ", dequeue(&q));
    status(&q);

    return 0;

}
