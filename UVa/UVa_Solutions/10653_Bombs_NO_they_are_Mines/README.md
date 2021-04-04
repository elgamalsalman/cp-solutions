**Code:** [10653.cpp](./10653.cpp)

# Explanation

**Time Complexity:** O(RC)

**Memory Complexity:** O(RC)

**Category:** Graph Theory

### General Comments

This is a Single Pair Shortest Path (SPSP) problem on an unweighted graph, which makes BFS our best option.

### Explanation

My code performs a simple BFS after taking all the input, the only catch is that you need to make sure the BFS never goes beyond the borders of the grid and make sure it never goes to a tile containing a mine.
