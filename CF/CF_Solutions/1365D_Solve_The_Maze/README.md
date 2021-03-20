**Code:** [1365D.cpp](./1365D.cpp)

# Explanation

**Time Complexity:** O(nm)

**Memory Complexity:** O(nm) 

**Category:** Graph Theory

### Explanation

First, notice that the best strategy would be to box every bad person, in other words, surround that person by walls from all sides. Then use a DFS (Depth First Search) to make sure all good people are reachable from the end point (n, m). Also while boxing every bad person there must be no good person adjacent to it, if this is true then the answer is definitely No.

My code does that by first storing the maze in a 2 dimensional array of characters, then looping on all cells and boxing them up while making sure no good person is adjacent to a bad person, my code loops on all neighboring cells of a cell using the arrays dx and dy which make it more concise and neat.

Then after that my code does a dfs starting from point (n - 1, m - 1) --not (n, m) as the array is zero indexed-- and marks cells it covered with an asterisk (\*) to make sure we don't recompute paths more than once. It also covers all reachable good people from the end point with asterisks.

Finally we loop on all cells and check that no good person is still present, if none is present the code couts Yes else it couts No.
