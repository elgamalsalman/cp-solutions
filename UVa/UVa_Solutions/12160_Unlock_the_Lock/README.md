**Code:** [12160.cpp](./12160.cpp)

# Explanation

**Time Complexity:** O(numOfPossibleCombinations)

**Memory Complexity:** O(numOfPossibleCombinations)

**Category:** Graph Theory

### General Comments

This is a Single Pair Shortest Path (SPSP) problem on an unweighted graph, which makes BFS our best option.

### Explanation

Each combination is a vertex and changing one combination to another using the press of any of the buttons is represented as an edge between them. After that a simple BFS is what we need to solve the problem.
