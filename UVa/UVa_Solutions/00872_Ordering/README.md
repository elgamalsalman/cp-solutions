**Code:** [00872.cpp](./00872.cpp)

# Explanation

**Time Complexity:** O(V + E)

**Memory Complexity:** O(V + E)

Where E is the number of constraints and V is the number of variables.

**Category:** Graph Theory

### General Comments

This is a topological sort problem which needs printing out all possible sorts, and thus it needed backtracking and using the bfs based algorithm not the dfs based topological sort algorithm as that would have gotten all possible sorts for every connected graph seperately and combining them would have been hectic. Down below is an explanation for the bfs bases topological sort algorithm.

### Explanation

This code searches for a vertex with indegree 0 and adds it to the end of the resulting vector and decreases the indegree of every vertex with an edge going to it and coming from the vertex with the indegree 0 by 1. The code recursively repeats this until all vertices were added to the resulting vector and then that vector is printed out. This will generate one possible sort, and in order to generate all of them the code backtracks and chooses a different vertex with indegree 0 out of all available vertices with indegree 0 in every stage.

The code also counts the number of sorts generated, if it is equal to 0 NO is printed out.
