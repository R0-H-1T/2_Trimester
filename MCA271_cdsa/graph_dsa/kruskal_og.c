#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

// Structure to represent an edge in the graph
struct Edge {
    int u, v, w; // u and v are the vertices, w is the weight
};

// Structure to represent a disjoint set
struct DisjointSet {
    int *parent, *rank;
    int n;
};

// Function to create a new DisjointSet with 'n' sets
struct DisjointSet *create_set(int n) {
    struct DisjointSet *set = (struct DisjointSet *)malloc(sizeof(struct DisjointSet));
    set->parent = (int *)malloc(n * sizeof(int));
    set->rank = (int *)malloc(n * sizeof(int));
    set->n = n;

    for (int i = 0; i < n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }

    return set;
}

// Function to find the representative of the set to which 'i' belongs
int find(struct DisjointSet *set, int i) {
    if (set->parent[i] != i) {
        set->parent[i] = find(set, set->parent[i]); // Path compression
    }
    return set->parent[i];
}

// Function to perform union of two sets
void union_sets(struct DisjointSet *set, int x, int y) {
    int root_x = find(set, x);
    int root_y = find(set, y);

    if (root_x != root_y) {
        // Union by rank to keep the tree balanced
        if (set->rank[root_x] < set->rank[root_y]) {
            set->parent[root_x] = root_y;
        } else if (set->rank[root_x] > set->rank[root_y]) {
            set->parent[root_y] = root_x;
        } else {
            set->parent[root_y] = root_x;
            set->rank[root_x]++;
        }
    }
}

// Function to compare two edges based on their weights (for sorting)
int compare_edges(const void *a, const void *b) {
    return ((struct Edge *)a)->w - ((struct Edge *)b)->w;
}

// Function to perform Kruskal's algorithm and print the minimum spanning tree
void kruskal(struct Edge edges[], int n, int m) {
    // Sort the edges in non-decreasing order of weight
    qsort(edges, m, sizeof(struct Edge), compare_edges);

    // Create a disjoint set to keep track of connected components
    struct DisjointSet *set = create_set(n);

    printf("Edges   Weight\n");

    int total_cost = 0;

    // Iterate through all edges in sorted order
    for (int i = 0; i < m; i++) {
        int root_u = find(set, edges[i].u);
        int root_v = find(set, edges[i].v);

        // If including this edge does not create a cycle, add it to the MST
        if (root_u != root_v) {
            printf("%d - %d   %d\n", edges[i].u, edges[i].v, edges[i].w);
            total_cost += edges[i].w;
            union_sets(set, root_u, root_v);
        }
    }

    printf("\nTotal Cost of Minimum Spanning Tree: %d\n", total_cost);

    // Free allocated memory
    free(set->parent);
    free(set->rank);
    free(set);
}

int main() {
    int n, m; // n: number of vertices, m: number of edges

    // Taking input from the user
    printf("Enter the total number of vertices: ");
    scanf("%d", &n);

    printf("Enter the total number of edges: ");
    scanf("%d", &m);

    // Array to store the edges of the graph
    struct Edge edges[MAX_EDGES];

    // Taking input for each edge
    printf("Enter edge (u v w) for each edge:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Applying Kruskal's algorithm
    printf("\nMinimum Spanning Tree using Kruskal's algorithm:\n");
    kruskal(edges, n, m);

    return 0;
}

