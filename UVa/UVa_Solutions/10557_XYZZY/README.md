**Code:** [10557.cpp](./10557.cpp)

# Explanation

**Time Complexity:** O(nd)

**Memory Complexity:** O(d)

Where d is the number of doorways.

**Category:** Graph Theory

### General Comments

This is a tricky positive cycles detection problem which can be done using Bellman Ford's algorithm in O(VE) with the help DFS or BFS.

### Explanation

The code uses Bellman Ford's to calculate the longest path to every room, while making sure that the energy level never reaches zero. Then we run the Bellman Ford's algorithm for an extra iteration to check for the presence of a positive cycle, if there is we use dfs to check if the destination is reachable from this cycle, if this check is satisfied or if the energy level at the destination was already positive then the answer is winnable else it is hopeless.

See pages *151* and *152* in CP3 for a thorough explanation.
