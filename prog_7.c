#include <stdio.h>

#define MAX 20
#define INF 999999

/* Find the unvisited node with the smallest distance */
int minDistance(int dist[], int visited[], int n) {
    int min = INF, idx = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

/* Dijkstra using adjacency matrix (0 means no edge) */
void dijkstra(int g[MAX][MAX], int n, int src) {
    int dist[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break; /* no reachable nodes left */
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && g[u][v] > 0 && dist[u] != INF) {
                int newDist = dist[u] + g[u][v];
                if (newDist < dist[v])
                    dist[v] = newDist;
            }
        }
    }

    printf("Source: %d\n", src);
    printf("Vertex   Distance\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d        INF\n", i);
        else
            printf("%d        %d\n", i, dist[i]);
    }
}

int main() {
    int n = 6; /* vertices: 0..5 */
    int g[MAX][MAX] = {0};

    /* Example weighted graph (undirected) */
    g[0][1] = g[1][0] = 4;
    g[0][2] = g[2][0] = 2;
    g[1][2] = g[2][1] = 1;
    g[1][3] = g[3][1] = 5;
    g[2][3] = g[3][2] = 8;
    g[2][4] = g[4][2] = 10;
    g[3][4] = g[4][3] = 2;
    g[3][5] = g[5][3] = 6;
    g[4][5] = g[5][4] = 3;

    dijkstra(g, n, 0); /* run from source 0 */

    return 0;
}
