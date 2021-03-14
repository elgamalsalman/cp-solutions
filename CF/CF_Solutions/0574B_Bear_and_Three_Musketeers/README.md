**Code:** [0574B.cpp](./0574B.cpp)

# Explanation

**Time Complexity:** O(n<sup>2</sup> + nm)

**Memory Complexity:** O(n<sup>2</sup>) 

**Category:** Graph Theory

### General Comments

This is a graph problem warriors, are vertices and recognitions are edges.

This problem really caught me off-guard, at first I thought of using dfs or bfs to detect cycles but after many failed attempts and some research I discovered that the general form of this problem is actually NP-Hard. This means that the polynomial time algorithm (like the one I was trying to devise) wasn't discovered yet. Thus the only solution is using complete-search (brute-force) and some pruning in order to solve it, this should have been obvious as the constraints are low.

### Explanation

I stored the graph in an adjacency matrix so that I can achieve O(1) edge fetching in order to achieve the O(n<sup>2</sup> + nm) time complexity. Also the number of recognitions of each warrior is stored in the array called degree to achieve O(1) time complexity of calculating the sum of external recognitions of a cycle of 3 warriors.

My code first loops on all possible edges using an O(n<sup>2</sup>) loop and chooses just the edges which are present and then loops on all possible third vertex and checks if there are edges between that vertex and the 2 vertices outlined by the edge, if there are then we calculate the sum of the degrees of all edges in this cycle - 6 (in order to ignore the edges between the vertices of the cycle and each other) and if it is less than the current lowest recognitions we set the lowest recognitions to this calculated sum.

Then we cout the lowest recognitions.
