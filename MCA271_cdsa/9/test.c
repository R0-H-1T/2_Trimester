#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int V; // Number of vertices
    struct Node** adjacencyList; // Array of pointers to adjacency lists
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of pointers to adjacency lists
    graph->adjacencyList = (struct Node**)malloc(V * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < V; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* current = graph->adjacencyList[i];
        printf("Adjacency list of vertex %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Function to free the allocated memory for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjacencyList);
    free(graph);
}

int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(4);

    addEdge(graph, 3, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency list representation of the graph
    printGraph(graph);

    // Free the allocated memory for the graph
    freeGraph(graph);

    return 0;
}

