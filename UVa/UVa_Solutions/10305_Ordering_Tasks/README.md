**Code:** [10305.cpp](./10305.cpp)

# Explanation

**Time Complexity:** O(n + m)

**Memory Complexity:** O(n + m)

**Category:** Graph Theory

### General Comments

This is a topological sort problem which needs only one possible sort printed out, and thus I used the simple dfs based algorithm. However there is another algorithm for topological sorting based on bfs which would have worked just fine, you can find an explanation for the bfs based algorithm in the solution to problem [00872 - Ordering](../00872_Ordering).

### Explanation

This code uses dfs by first picking vertices with indegree 0 and then recursively calling topoSort on all their children so that the code makes sure that all the tasks that depend on this task were already added before adding the current task, and dfsState is used to prevent adding a vertex twice.

The code used push\_back() so the result is actually stored in the vector the other way around, therefore the loop that prints the result iterates from the end to the beginning.
