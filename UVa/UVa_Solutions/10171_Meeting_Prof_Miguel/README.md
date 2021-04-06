**Code:** [10171.cpp](./10171.cpp)

# Explanation

**Time Complexity:** O(v<sup>3</sup>)

**Memory Complexity:** O(v<sup>2</sup>)

Where v is the number of places.

**Category:** Graph Theory

### General Comments

This is a straight forward Single Source Shortest Paths (SSSP) problem on a small graph and thus can easily be solved using Floyd Warshall's algorithm.

### Explanation

> Because 2 roads of different energies can have the exact same starting and ending places, while inputting the information into the distances array make sure you choose the minimum energy edge.

The code runs Floyd Warshall's algorithm on both maps of Y and M roads and then loops on every place adds the places with the minimum total energy needed to a vector to cout at the end.

See pages *155* to *157* in CP3 for a thorough explanation.
