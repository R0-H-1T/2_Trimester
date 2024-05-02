#include<stdio.h>


int camparator (const void *p1, const void *p2) {
    // u are getting and entire edge(u,v,w).
    // create and array of size 3 int and store p1 and p2
    // return their comparision
    const int(*x)[3] = p1;
    const int(*y)[3] = p2;

    return (*x)[3] - (*y)[3];
}

void unionSet (int u, int v, int parent[], int rank[], int n) {
    u = findParent (parent, u);
    v = findParent (parent, v);


    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        // rand increases if the ranks of two sets are the same
        parent[v]++;
        rank[u]++;  
    }
}

void init (int parent[], int rank[], int n) {
    for (int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent (int parent[], int vertex) {
    if (parent[vertex] == vertex) {
        return vertex;
    }

    return parent[vertex] = findParent (parent, parent[vertex]);
}

void kruskals_algo (int n, int edges[n][3]) {

    //sorting the edges based on their weights
    qsort (edges, n, sizeof(edges[0]), camparator);

    int parent[n];
    int rank[n];
    init (parent, rank, n);

    int min_cost = 0;
    printf ("Following are the edges in the constructed MST");

    for (int i=0; i<n; i++) {
        int v1 = findParent (parent, edges[i][0]);
        int v2 = findParent (parent, edges[i][1]);
        int w = edges[i][2];

        if (v1 != v2) {
            unionSet (v1, v2, parent, rank, n);
            min_cost += w;
            printf("%d %d %d", edges[i][0], edges[i][2], w);
        }

    }

    printf ("Min cost of spanning tree is: %d", min_cost);
}

int main() {
    int n = 5;
    int edges[][3] = {
        {},
        {},
        {},
        {},
        {}
    };

    kruskals_algo (edges, n);

    return 0;
}
