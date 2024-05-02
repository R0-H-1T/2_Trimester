#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 5


int min_edged_vertex (int key[V], bool visited[V]) {
    int min_vertex;
    int min = INT_MAX;
    for (int i=0; i<V; i++) {
        if (visited[i]==false && key[i] < min) {
            min = key[i];
            min_vertex = i;
        }
    }

    return min_vertex;
}

void primMST (int graph[V][V]) {    
    int parent[V];
    int key[V];
    bool visited[V];

    for (int i=0; i<V; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }   

    key[0] = 0;
    visited[0] = true;

    int min_edged_vertex = minKey (key, visited);


    for (int i=0; i<V; i++) {
        if (graph[min_edged_vertex][i] && )
    }

}


int main () {
    
    int graph[V][V] = 
                      { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
                    
    primMST(graph);

    return 0;
}
