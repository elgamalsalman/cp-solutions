**Code:** [1320B.cpp](./1320B.cpp)

# Explanation

**Time Complexity:** O(n + m)

**Memory Complexity:** O(n + m) 

**Category:** Graph Theory

### Explanation

We can calculate sssp (single source shortest path) using bfs quickly because all edges have the same weight. Thus we can calculate the shortest paths from any vertex to the destination by doing a bfs on a transposed (all edges inverted) graph starting from the destination.

While doing the bfs we store all possible parents of each vertex which is a part of a possible shortest path to that vertex in the 2D vector parents. Then, the code iterates through the path taken by Polycarp, if the following vertex is not listed in the parents of the vertex before it, then this isn't a shortest path and a rebuild is inevitable, else if there is more than one parent and the one in the path taken is one of the parents then we can increase the number of maximum rebuilds only, as it is possible for the navigation system to chose it and it is possible for it not to as it is not the only parent.
