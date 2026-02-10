# Dijkstra’s Algorithm (Shortest Path)

## Data Structure
The weighted graph is stored using an adjacency matrix `g[n][n]`:
- `g[i][j]` stores the weight of the edge between `i` and `j`
- `0` means no edge exists
Two arrays are used:
- `dist[]` stores the shortest distance from the source
- `visited[]` marks nodes already finalized

## Functions Implemented
- `minDistance()` : returns the index of the unvisited vertex with the smallest distance.
- `dijkstra()` : computes shortest distance from the source to all vertices using Dijkstra’s algorithm.

## main() Overview
The `main()` function:
1. Creates an example weighted graph (6 vertices)
2. Stores edge weights in an adjacency matrix
3. Calls `dijkstra()` with source node 0
4. Prints distances from source to all nodes

## Sample Output
Source: 0
Vertex Distance
0 0
1 3
2 2
3 8
4 10
5 13