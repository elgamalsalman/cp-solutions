**Code:** [11747.cpp](./11747.cpp)

# Explanation

**Time Complexity:** O(mlogn)

**Memory Complexity:** O(m)

**Category:** Graph Theory

### General Comments

This is a Minimum Spanning Tree (MST) problem which can be solved using either Kruskal's algorithm or Prim's algorithm. I used Prim's but Kruskal's would have worked fine. However, Prim's is much shorter to code, as I need to write the UFDS (aka DSU) structure from scratch for kruskal's to work. Anyways, if you would like to see a Kruskal's algorithm explanation see my solution to the problem [11228 - Transportation system](../11228_Transportation_system).

### Explanation

What we need to do here is print out all the edges not included in the MST in increasing order. This is because any additional edge not in the MST will create a cycle with one part the additional edge itself and the other the MST route. The additional edge must be the largest edge in that cycle because if it wasn't it would have been included as an MST edge.

Prim's simply uses a priority queue to choose on each step greedily the shortest edge from an already reached vertex to an unreached vertex, we keep track of whether a vertex was reached before or not using a bitset called taken.

See CP3 pages *139* and *140* for a more thorough explanation.
