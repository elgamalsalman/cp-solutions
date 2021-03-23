**Code:** [0698B.cpp](./0698B.cpp)

# Explanation

**Time Complexity:** O(nlogn) but it can reach O(n<sup>2</sup>) if the tree was a continuous line of vertices, which could be prevented using a height vector but this worked anyways.

**Memory Complexity:** O(n) 

**Category:** Graph Theory

### General Comments

I solved this problem using the UFDS (aka DSU) structure, but it could have been solved using dfs to search for cycles but I think the UFDS is simpler to code and does the trick perfectly.

### Explanation

What the code does basicly is that it searches for any cycles using a UFDS (aka DSU) structure, counts them and labels the vertices at the end of each cycle so that we can change them later (self-loops are also considered cycles).

The goal then is to replace all cycles with one self-loop. If a self-loop is already one of the cycles then we can leave this as it is and connect all other loops to it, this decreases the number of changes by one. However, if a self-loop isn't present then we choose any loop and turn it into a self loop and connect all other loops to it.
