**Code:** [11101.cpp](./11101.cpp)

# Explanation

**Time Complexity:** O(RC)

**Memory Complexity:** O(RC)

Where R is the number of rows and C is the number of columns.

**Category:** Graph Theory

### General Comments

This is a Multi Source Shortest Paths (MSSP) problem on an unweighted graph, which makes BFS our best option.

### Explanation

The code is just a modified BFS in order to accomodate for the multiple sources. At the start of the BFS all the intersections contained in the first mall are added and given a distance of 0. The intersections of the second mall are given a distance of -2 in order to be able to detect the BFS arrival at one of the destinations and terminate the BFS. The rest of the intersections are given a value of -1 in order to keep track of the visited intersections and the unvisited ones.
