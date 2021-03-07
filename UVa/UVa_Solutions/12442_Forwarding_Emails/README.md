**Code:** [12442.cpp](./12442.cpp)

# Explanation

**Category:** Graph Traversal

**Time Complexity:** O(TN)

**Memory Complexity:** O(N)

### General Comments

This is graph traversal problem which you can solve fairly easily if you can detect cycles.

### Explanation

The code first saves the reciever of the email from u in rec[u] for all u (1 to N) then the code performs the modified DFS until every martian has been visited, but first all martians are set to UNVISITED in the array dfsNum. We also store the number of martains reachable from the martain u in the array seens index u.

The modified DFS traverses through the graph and numbers every martain that is explored but not yet finished (still exploring its children), after exploring all its children the martain is labelled VISITED.

If the next martain in the graph is UNVISITED we visit it and set seens[u] = seens[v] + 1 only if seens[u] wasn't already set to a number due to its presence in a cycle, but if the next martain is VISITED then we have already calculated its seens so we take seens[u] = seens[v] + 1 right away (note that we don't need to check if it is in a cycle as this isn't possible because if it was, then how is v already VISITED but u is still being explored, this means that u isn't reachable from v and thus it isn't a cycle). And the last case if the next martain is neither VISITED nor UNVISITED, meaning it is still under exploration and this is a cycle and this edge is a back edge, thus we loop on the whole cycle and set the seens of all its martains to the number of martains in the cycle calculated in line 20.

Finally to calculate the answer we loop on the array seens and find the martain with the highest number (highest number of reachable martains from this martain) and we output the number of the martain in the format specified in the problem description.
