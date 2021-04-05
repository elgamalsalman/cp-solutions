**Code:** [10986.cpp](./10986.cpp)

# Explanation

**Time Complexity:** O((m + n)logn)

**Memory Complexity:** O(m)

**Category:** Graph Theory

### General Comments

This is a Single Pair Shortest Path (SPSP) problem on a weighted graph, and thus dijkstra's algorithm can solve it in O((E + V)logV) time complexity.

The rest of the solution is a straight forward dijkstra's algorithm implementation. See pages *148* and *149* in CP3.
