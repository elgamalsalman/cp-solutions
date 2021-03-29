**Code:** [11228.cpp](./11228.cpp)

# Explanation

**Time Complexity:** O(n<sup>2</sup>logn)

**Memory Complexity:** O(n<sup>2</sup>)

**Category:** Graph Theory

### General Comments

This is a Minimum Spanning Tree (MST) problem which can be solved using either Kruskal's algorithm or Prim's algorithm. I used Kruskal's but Prim's would have worked fine. In fact, Prim's would have been shorter to code as I had to code the UFDS (aka DSU) structure for Kruskal's, but Prim's doesn't need it.

### Explanation

What Kruskal's algorithm does simply is that it sorts an edges list in non-decreasing order, and greedily includes the shortest edge which connects two vertices which aren't already connected. The connection criteria is checked quickly using a UFDS (aka DSU) structure.

See CP3 pages *138* and *139* for a more thorough explanation.
