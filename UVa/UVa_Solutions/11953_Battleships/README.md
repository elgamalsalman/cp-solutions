**Code:** [11953.cpp](./11953.cpp)

# Explanation

**Time Complexity:** O(N<sup>2</sup>)

**Memory Complexity:** O(N<sup>2</sup>)

**Category:** Graph Theory

### General Comments

This is a flood fill problem which is one of the classic variants of dfs. I really recommend re-reading the problem statement if you get a WA verdict and you don't know why before starting to come up with tricky testcases, as after my first read I missed the part of "none of two ships ... touch", which my code a lot more complicated at first until I noticed that line.

### Explanation

In this flood fill problem we have a simple implicit graph which we need to loop through, find every x, label it and recursively label all its x or @ neighbors and count the number of overall ships we covered.
