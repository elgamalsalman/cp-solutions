**Code:** [11080.cpp](./11080.cpp)

# Explanation

**Time Complexity:** O(v + e)

**Memory Complexity:** O(v + e)

**Category:** Graph Theory

### General Comments

This is a bipartite problem which can be solved with a simple dfs or bfs, I used dfs as it is just a tiny bit faster to code.

### Explanation

The code first colours the vertex 0 with the colour 0 and then using dfs it colours every vertex adjacent to it with the opposite colour if that vertex isn't coloured already, else it sets isBipartite to false if the colour of that adjacent vertex is the same as the original vertex. The code then recursively calls dfs on the vertices which weren't coloured.

The code also counts all the number of vertices coloured in zeros and in ones, and it adds the minimum of both values to the variable minGuards whenever a subgraph is fully coloured. Note : because all junctions need to be guarded too the code doesn't allow 0 to be the minimum by choosing the maximum between one and the minimum of the variables zeros and ones.

At the end if the graph is a bipartite minGuards is printed else -1 is printed.
