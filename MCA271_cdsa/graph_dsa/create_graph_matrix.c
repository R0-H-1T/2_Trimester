#include<stdio.h>
#include<stdbool.h>
// directed matrix and weighted matrix is not taken into account.
// use adjacency matric only when the edges between the vertices are more
// else use list for sparse edges between vertices.


// bfs and dfs of matrix is included ->


// uses stack (Recursion)
void dfs (int vertices, int graph[vertices][vertices], int start, bool visited[vertices]) {
    printf ("%d", start);

    visited[start] = true;

    for (int i=0; i<vertices; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs (vertices, graph, i, visited);
        }
    }
}

// uses queue
void bfs(int vertices, int graph[vertices][vertices], int start) {
    bool visited[vertices];
    for (int i=0; i<vertices; i++) {
        visited[i] = false;
    }

    int queue[vertices];
    int front = -1, rear = -1;

    // Enqueue the start vertex and mark it as visited
    queue[++rear] = start;
    visited[start] = true;

    while (front != rear) {
        // Dequeue a vertex and process it
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // Enqueue all adjacent vertices of the dequeued vertex that have not been visited
        for (int i = 0; i < vertices; ++i) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}


void initializeVertices (int vertices, int graph[vertices][vertices]) {
    for (int i=0; i<vertices; i++) {
        for (int j=0; j<vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void printGraph (int n, int graph[n][n]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf ("%d ", graph[i][j]);
        }
        printf ("\n");
    }
}

void addEdge (int source, int destination, int vertices, int graph[vertices][vertices]) {
    if (source >= 0 && source <vertices && destination >= 0 && destination < vertices){
        graph[source][destination] = 1;
        graph[destination][source] = 1;
    } else {
        printf ("Invalid vertices");
    }
}


// this is for undirected graph.
int main () {
    int vertices;
    int edges;

    printf("Enter total vertices: ");
    scanf("%d", &vertices);

    printf("Enter total edges: ");
    scanf("%d", &edges);

    int graph[vertices][vertices];

    initializeVertices (vertices, graph);
    
    printf ("Enter edges in form -> (v1, v2): \n");
    int source, destination;
    for (int i=0; i<edges; i++) {
        scanf ("%d %d", &source, &destination);
        addEdge(source, destination, vertices, graph);
    }

    // printf ();
    printGraph (vertices, graph);

    return 0;
}
