**Code:** [00929.cpp](./00929.cpp)

# Explanation

**Time Complexity:** O((NM)log(NM))

**Memory Complexity:** O(NM)

**Category:** Graph Theory

### General Comments

This is a Single Pair Shortest Path (SPSP) problem on weighted graph, and thus dijkstra's algorithm can solve it in O((E + V)logV) time complexity.

The problem statement wasn't fully clear if the starting box cost should be included and that costed me a WA verdict. Other than that the solution is a straight forward dijkstra's algorithm implementation. See pages *148* and *149* in CP3.


