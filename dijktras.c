#include <stdio.h>
#include <limits.h>

#define V 4

// Find the vertex with the minimum distance value
int minDis(int dist[], int visited[]) {
    int min = INT_MAX;
    int minIdx = 0;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIdx = v;
        }
    }
    return minIdx;
}

void algo(int g[V][V], int src) {
    int dist[V];    // Shortest distances from source
    int visited[V]; // Visited vertices

    // Initialize distances to infinity and visited to false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0; // Distance to the source is 0

    // Dijkstra's main loop
    for (int cnt = 0; cnt < V - 1; cnt++) {
        int u = minDis(dist, visited); // Find the vertex with the minimum distance
        visited[u] = 1; // Mark it as visited

        // Update the distances of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && g[u][v] && dist[u] != INT_MAX && dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }

    // Print the final distances
    printf("Vertex\tDistance from Source (%d)\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    // Example graph as an adjacency matrix
    int g[V][V] = {
        {0, 4, 0, 0},
        {4, 0, 8, 0},
        {0, 8, 0, 7},
        {0, 0, 7, 0}
    };

    int src = 0; // Starting vertex
    printf("Dijkstra's Algorithm starting from vertex %d\n", src);
    algo(g, src);

    return 0;
}
