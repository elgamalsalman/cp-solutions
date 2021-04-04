**Code:** [00924.cpp](./00924.cpp)

# Explanation

**Time Complexity:** O(T(E + EN)) = O(TEN)

**Memory Complexity:** O(EN)

**Category:** Graph Theory

### General Comments

This is a Single Source Shortest Paths (SSSP) problem on an unweighted graph, which makes BFS our best option.

### Explanation

We just need a normal BFS to find the shortest distance to every vertex while counting the number of vertices (people) at each distance (day the news reached them), then a simple call of the max\_element() function on the number of people informed in each day gets us an iterator to the first maximum value, which is exactly what we need to calculate the two pieces of information needed.

> Of course, if the iterator returned by max\_element() was the element at index zero, this means no one was told and thus 0 is printed out.
