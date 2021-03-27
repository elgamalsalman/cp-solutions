**Code:** [10004.cpp](./10004.cpp)

# Explanation

**Time Complexity:** O(n + l)

**Memory Complexity:** O(n + l)

**Category:** Graph Theory

### General Comments

This is a bipartite problem which can be solved with a simple dfs or bfs, I used dfs as it is just a tiny bit faster to code.

### Explanation

The code first colours the vertex 0 with the colour 0 and then using hte dfs it colours every vertex adjacent to it with the opposite colour if that vertex isn't coloured already, else it sets isBipartite to false if the colour of that adjacent vertex is the same as the original vertex.

The code then recursively calls dfs on the vertices which weren't coloured.
