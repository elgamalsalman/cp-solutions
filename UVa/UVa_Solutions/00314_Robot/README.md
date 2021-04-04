**Code:** [00314.cpp](./00314.cpp)

# Explanation

**Time Complexity:** O(MN)

**Memory Complexity:** O(MN)

**Category:** Graph Theory

### General Comments

This is a tricky Single Pair Shortest Path (SPSP) problem on an unweighted graph, which makes BFS our best option.

### Explanation

First notice that the robot moves through the edges and the vertices of each box and thus we can forget about the boxes and work with the vertices and the edges, there are N + 1 sets of vertices horizontally and M + 1 vertically.

Also notice that if a box at position (r, c) is blocked, all the vertices around the box are blocked too, namely, vertices (r, c), (r + 1, c), (r, c + 1), (r + 1, c + 1).

Additionally the state of this graph isn't just the position of the robot but also the direction it is facing. Therefore, number of vertices jumps to 4 * M * N, and after that a BFS on the graph is then possible.

> Notice that you need to make sure the BFS never reaches the borders of the grid as the robot has some thickness to it. Also, make sure the robot never goes to a blocked vertex.
