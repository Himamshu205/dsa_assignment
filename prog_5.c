#include <stdio.h>

#define MAX 20

/* ---------------- Graph using Adjacency Matrix ---------------- */
void initGraph(int g[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = 0;
}

void addEdge(int g[MAX][MAX], int u, int v) {
    g[u][v] = 1;
    g[v][u] = 1; /* undirected */
}

void displayMatrix(int g[MAX][MAX], int n) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
}

/* ---------------- BFS (Queue) ---------------- */
void bfs(int g[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int q[MAX], front = 0, rear = 0;

    visited[start] = 1;
    q[rear++] = start;

    printf("BFS: ");
    while (front < rear) {
        int u = q[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (g[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                q[rear++] = v;
            }
        }
    }
    printf("\n");
}

/* ---------------- DFS (Recursion) ---------------- */
void dfsUtil(int g[MAX][MAX], int n, int u, int visited[MAX]) {
    visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < n; v++) {
        if (g[u][v] == 1 && visited[v] == 0) {
            dfsUtil(g, n, v, visited);
        }
    }
}

void dfs(int g[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    printf("DFS: ");
    dfsUtil(g, n, start, visited);
    printf("\n");
}

int main() {
    int n = 6;                  /* vertices: 0..5 */
    int g[MAX][MAX];

    initGraph(g, n);

    /* Example undirected graph edges */
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 5);
    addEdge(g, 4, 5);

    displayMatrix(g, n);

    /* Traverse from node 0 */
    bfs(g, n, 0);
    dfs(g, n, 0);

    return 0;
}
