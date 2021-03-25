**Code:** [11094.cpp](./11094.cpp)

# Explanation

**Time Complexity:** O(NM)

**Memory Complexity:** O(NM)

**Category:** Graph Theory

### General Comments

This is a flood fill problem which is one of the classic variants of dfs. I really recommend re-reading the problem statement if you get a WA verdict and you don't know why before starting to come up with tricky testcases, as after my first read I missed the part of "filled with at most two different letters denoting land an water regions", thus they are not necessarily labelled using the letters l and w, and thus you need to find out the letter for the land from the original position of the king.

### Explanation

In this flood fill problem we have a simple implicit graph which we need to loop through and find every land region and label it and recursively label all its land neighbors and count the number of regions in each continent and output the maximum number.

But as specified in the problem description the left most column is considered to be adjacent to the right most column so what my code does is that at the beginning of each call of the recursive function if the row is less than zero it is changed to N - 1 and if it is greater than or equal to N it is changed to zero, this does the trick.
