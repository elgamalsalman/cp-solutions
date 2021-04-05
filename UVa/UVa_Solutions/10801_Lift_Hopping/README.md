**Code:** [10801.cpp](./10801.cpp)

# Explanation

**Time Complexity:** O(f<sup>2</sup>logf)

**Memory Complexity:** O(f<sup>2</sup>)

Where f is the number of floors all elevators stop at combined.
**Category:** Graph Theory

### General Comments

This is a Single Pair Shortest Path (SPSP) problem on a weighted graph, and thus dijkstra's algorithm can solve it in O((E + V)logV) time complexity.

### Explanation

The vertices here are the floors and an edge is between any two floors which are connected by an elevator, the weight of that edge is number of floors between the two floors multiplied by the time taken for that elevator to move one floor.

Additionally the code should add 60 seconds after each edge as specified in the problem description except at floor zero where the person starts.

The rest of the solution is a straight forward dijkstra's algorithm implementation. See pages *148* and *149* in CP3.
