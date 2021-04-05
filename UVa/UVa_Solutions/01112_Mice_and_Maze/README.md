**Code:** [01112.cpp](./01112.cpp)

# Explanation

**Time Complexity:** O((N + M)logN)

**Memory Complexity:** O(M)

**Category:** Graph Theory

### General Comments

This is a Single Destination Shortest Path (SDSP) problem on a weighted graph, and thus dijkstra's algorithm can solve it in O((E + V)logV) time complexity.

### Explanation

In order to transform it to a normal SSSP problem I just transposed the graph (flipped all the edges) while inputting the edges into the adjacency list, then to find the number of mice which will exit before the timer stops the code just counts the number of cells with the shortest time from the destination to that cell at most T.

The rest of the solution is a straight forward dijkstra's algorithm implementation. See pages *148* and *149* in CP3.
