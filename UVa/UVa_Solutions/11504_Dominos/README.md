**Code:** [11504.cpp](./11504.cpp)

# Explanation

**Time Complexity:** O(n + m)

**Memory Complexity:** O(n + m)

**Category:** Graph Theory

### General Comments

This is a Strongly Connected Components (SCC) finding problem. I used Tarjan's algorithm because I still haven't read about Kosaraju's algorithm. I have explained down below my code but I left out the explanation for the standard Tarjan's algorithm as Tarjan's algorithm isn't easy to grasp to be honest and thus all what I can do is to refer you to the page number in which it is explained thoroughly in CP3.

You can find the explanation of Tarjan's algorithm in pages *133* and *134* in the book CP3.

### Explanation

Notice that if any domino in a SCC fell all the dominos in this component will fall too. So our goal is to find the number of the SCCs which don't have an edge from an external vertex to any vertex in the SCC.

I did that by first transposing (flipping all edges) my graph in order to change the problem to finding the number of SCCs with no edge going from a vertex inside the SCC to an external vertex, as this is easier to do with the adjacency list.

Next my code uses Tarjan's algorithm to find all SCCs and loops on the vertices of each SCC and checks that the number of vertices in the SCC is equal to the number of vertices connected by outward edges from the SCC, if that is true knocks is increased by one.
