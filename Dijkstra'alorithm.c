#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define V 8
#define INF INT_MAX

int minDistance(int dist[], bool sptSet[]) {
    int min = INF, min_index;
    for (int v = 1; v < V; v++)
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        if (dist[u] == INF) break;
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    for (int i = 0; i < V; i++) {
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
    graph[3][2] = 2;
    graph[4][3] = 2;
    graph[2][5] = 1;
    graph[3][5] = 1;
    graph[5][7] = 3;
    graph[6][7] = 3;
    graph[4][6] = 1;

    dijkstra(graph, 1);

    return 0;
}
