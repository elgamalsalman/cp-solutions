**Code:** [11396.cpp](./11396.cpp)

# Explanation

**Time Complexity:** O(V + E)

**Memory Complexity:** O(V + E)

Where E is the number of edges in the graph.

**Category:** Graph Theory

### General Comments

This is a bipartite problem which can be solved with a simple dfs or bfs, I used dfs as it is just a tiny bit faster to code.

### Explanation

Notice that if there is any odd cycle in any graph the answer would be NO, and thus we can check for that using a simple bipartite algorithm.

The code first colours the vertex 0 with the colour 0 and then using dfs it colours every vertex adjacent to it with the opposite colour if that vertex isn't coloured already, else it sets isBipartite to false if the colour of that adjacent vertex is the same as the original vertex.

The code then recursively calls dfs on the vertices which weren't coloured.
