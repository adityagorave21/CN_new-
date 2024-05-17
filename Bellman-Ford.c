#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000
#define V 8

void bellmanFord(int graph[V][V], int src) {
    int dist[V];
    int i, j, k;

    // Initialize distances to INF and source distance to 0
    for (i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // Relax edges V-1 times
    for (k = 0; k < V-1; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (graph[i][j] != 0) {
                    if (dist[i] + graph[i][j] < dist[j]) {
                        dist[j] = dist[i] + graph[i][j];
                    }
                }
            }
        }
    }

    // Print distances
    for (i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("not Reachable ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");
}

int main() {
    int graph[V][V];
    memset(graph, 0, sizeof(graph));

    graph[1][2] = 6;
    graph[1][3] = 5;
    graph[1][4] = 5;
    graph[3][2] = -2;
    graph[4][3] = -2;
    graph[2][5] = -1;
    graph[3][5] = -1;
    graph[5][7] = 3;
    graph[6][7] = 3;
    graph[4][6] = -1;

    bellmanFord(graph, 1);

    return 0;
}
