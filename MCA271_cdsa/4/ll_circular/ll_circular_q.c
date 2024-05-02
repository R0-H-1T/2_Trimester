#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for the circular queue
typedef struct {
    Node* front;
    Node* rear;
} CircularQueue;

// Function to initialize the circular queue
void initializeQueue(CircularQueue* cq) {
    cq->front = cq->rear = NULL;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue* cq) {    
    return cq->front == NULL;
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue* cq, int item) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    // If the queue is empty, set both front and rear to the new node
    if (isEmpty(cq)) {
        cq->front = cq->rear = newNode;
    } else               {
        // Otherwise, update the rear and link the new node
        cq->rear->next = newNode;
        cq->rear = newNode;
    }

    printf("Ticket for Movie %d added to the queue.\n", item);
}

// Function to dequeue an element from the circular queue
void dequeue(CircularQueue* cq) {
    // If the queue is empty, display a message and return
    if (isEmpty(cq)) {
        printf("Queue is empty. No tickets to dequeue.\n");
        return;
    }

    // Store the data of the front node
    int frontData = cq->front->data;

    // If there's only one node in the queue, set both front and rear to NULL
    if (cq->front == cq->rear) {
        free(cq->front);
        cq->front = cq->rear = NULL;
    } else {
        // Otherwise, move the front pointer to the next node
        Node* temp = cq->front;
        cq->front = cq->front->next;
        free(temp);
    }

    printf("Ticket for Movie %d dequeued.\n", frontData);
}

// Function to display the elements in the circular queue
void display(CircularQueue* cq) {
    // If the queue is empty, display a message and return
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }

    // Display the elements in the queue
    printf("Current Movie Queue: ");
    Node* current = cq->front;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != cq->front);

    printf("\n");
}

// Function to free memory allocated for the circular queue
void freeQueue(CircularQueue* cq) {
    // Traverse the queue and free each node
    while (cq->front != NULL) {
        Node* temp = cq->front;
        cq->front = cq->front->next;
        free(temp);
    }
}

int main() {
    CircularQueue cinemaQueue;
    initializeQueue(&cinemaQueue);

    enqueue(&cinemaQueue, 101);
    enqueue(&cinemaQueue, 102);
    enqueue(&cinemaQueue, 103);
    display(&cinemaQueue);

    dequeue(&cinemaQueue);
    display(&cinemaQueue);

    enqueue(&cinemaQueue, 104);
    enqueue(&cinemaQueue, 105);
    enqueue(&cinemaQueue, 106);
    display(&cinemaQueue);

    freeQueue(&cinemaQueue);

    return 0;
}
