**Code:** [12047.cpp](./12047.cpp)

# Explanation

**Time Complexity:** O((N + M)logN)

**Memory Complexity:** O(M)

**Category:** Graph Theory

### General Comments

This is a Single Source Shortest Path (SSSP) problem on a weighted graph, and thus dijkstra's algorithm can solve it in O((E + V)logV) time complexity.

### Explanation

First we run dijkstra's algorithm from s and once again from t (transposing the graph for t) to get two different arrays of distances. Then we loop on all the edges (u, v), if the combined weight of the edge + the shortest path from s to u + the shortest path from v to t is less than p we consider the current edge as one of the candidate edges to be the answer. Then we choose the maximum weight of all condidate edges.

I passed the adjacency list and the array of shortest distances both by reference to dijkstra's algorithm function so that the algorithm uses the proper adjacency list and stores the information in the proper array in each call.

The rest of the solution is a straight forward dijkstra's algorithm implementation. See pages *148* and *149* in CP3.
