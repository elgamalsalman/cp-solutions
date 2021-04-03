**Code:** [10600.cpp](./10600.cpp)

# Explanation

**Time Complexity:** O(NM)

**Memory Complexity:** O(M)

**Category:** Graph Theory

### General Comments

This is a Second Minimum Spanning Tree problem, a variation of the traditional Minimum Spanning Tree (MST) problem. A traditional MST problem can be solved using Kruskal's algorithm or Prim's Algorithm; however, using Kruskal's in this variation of the problem can achieve better time complexity as we can sort the list of edges once at the beginning.

### Explanation

We first input all the edges and sort them, then we find the standard MST and add all it's edges to a vector, then we loop on the edges of the MST, turn the current edge off so that it can't be chosen and recalculate the MST again. The MST with the lowest cost among all these MSTs with turned off edges is the second best MST.

> We need to make sure every second best MST we try connects all the vertices together before considering each of them as turning off certain edges can make an MST impossible.

What Kruskal's algorithm does simply is that it sorts an edge list in non-decreasing order, and greedily includes the shortest edge which connects two vertices which aren't already connected. The connection criteria is checked quickly using a UFDS (aka DSU) structure.

See CP3 pages *138* and *139* for a more thorough explanation.
