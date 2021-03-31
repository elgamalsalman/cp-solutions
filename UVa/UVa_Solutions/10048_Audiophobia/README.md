**Code:** [10048.cpp](./10048.cpp)

# Explanation

**Time Complexity:** O(SlogC)

**Memory Complexity:** O(S)

**Category:** Graph Theory

### General Comments

This is a Minimum Spanning Tree (MST) problem which can be solved using either Kruskal's algorithm or Prim's algorithm. I used Prim's but Kruskal's would have worked fine. However, Prim's is much shorter to code, as I need to write the UFDS (aka DSU) structure from scratch for kruskal's to work. Anyways, if you would like to see a Kruskal's algorithm explanation see my solution to the problem [11228 - Transportation system](../11228_Transportation_system).

### Explanation

We need to find the path with the minimum maximum edge, which is the minimax variant of the MST! So what we need to do is just use either Kruskal's or Prim's algorithms in order to find the MST and then use dfs or bfs to find the path through the MST created that connects the two crossings in each query and output the least weighted edge in this path.

Prim's simply uses a priority queue to choose on each step greedily the shortest edge from an already reached vertex to an unreached vertex, we keep track of whether a vertex was reached before or not using a bitset called taken.

See CP3 pages *139* and *140* for a more thorough explanation.
