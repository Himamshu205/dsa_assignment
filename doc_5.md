# Undirected Graph Using Adjacency Matrix (BFS + DFS)

## Data Structure
The graph is stored as an adjacency matrix `g[n][n]`:
- `g[i][j] = 1` means there is an edge between vertex `i` and `j`
- `g[i][j] = 0` means no edge
Because the graph is undirected, both `g[u][v]` and `g[v][u]` are set to 1.

## Functions Implemented
- `initGraph()` : Initializes the matrix to all zeros.
- `addEdge()` : Adds an undirected edge between two vertices.
- `displayMatrix()` : Prints the adjacency matrix.
- `bfs()` : Breadth First Search using a simple array queue.
- `dfs()` / `dfsUtil()` : Depth First Search using recursion.

## main() Overview
The `main()` function:
1. Creates a graph with 6 vertices (0 to 5)
2. Adds example edges
3. Prints the adjacency matrix
4. Runs BFS and DFS starting from node 0

## Sample Output
Adjacency Matrix:
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 0 1
0 1 0 0 0 0
0 1 0 0 0 1
0 0 1 0 1 0
BFS: 0 1 2 3 4 5
DFS: 0 1 3 4 5 2