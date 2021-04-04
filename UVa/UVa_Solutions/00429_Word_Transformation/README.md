**Code:** [00429.cpp](./00429.cpp)

# Explanation

**Time Complexity:** O(mn<sup>2</sup>)

**Memory Complexity:** O(n<sup>2</sup>)

Where n is the number of words and m is the number of queries.

**Category:** Graph Theory

### General Comments

This is a Single Pair Shortest Path (SPSP) problem on an unweighted graph, which makes BFS our best option.

### Explanation

We first map every word to an index so that we can work with the easier to manage integers. Then we calculate all the edges by looping on all possible pairs of words, if they are of the same length and only have a one-letter difference then we create an edge between them. Finally we use BFS to find the shortest path for each query.
