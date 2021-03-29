**Code:** [11631.cpp](./11631.cpp)

# Explanation

**Time Complexity:** O(nlogm)

**Memory Complexity:** O(n)

**Category:** Graph Theory

### General Comments

This is a Minimum Spanning Tree (MST) problem which can be solved using either Kruskal's algorithm or Prim's algorithm. I used Prim's but Kruskal's would have worked fine. However, Prim's is muuch shorter to code, as I needed to write the UFDS (aka DSU) structure from scratch for kruskal's to work. Anyways, if you would like to see a Kruskal's algorithm explanation see the solution to the problem [11228 - Transportation system](../11228_Transportation_system).

### Explanation

Prims simply uses a priority queue to choose on each step greedily the shortest edge from an already reached vertex to an unreached vertex, we keep track of whether a vertex was reached before or not using a bitset called taken.

See CP3 pages *139* and *140* for a more thorough explanation.
