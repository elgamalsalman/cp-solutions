**Code:** [1056D.cpp](./1056D.cpp)

# Explanation

**Time Complexity:** O(nlogn)

**Memory Complexity:** O(n) 

**Category:** Graph Theory

### Explanation

For a junction to be happy we need at least as many colours as there are leaves in the subtree of this junction, so we just store the graph in an adjacency list and store the number of leaves in the subtree at each junction in the array leaves using the recursive function countLeaves().

countLeaves() is a pretty simple recursive function which stores and returns 1 if the junction is a leaf otherwise it stores and returns the sum of the number of leaves in each junction which is a child of the current junction (by recursively calling the function countLeaves()).

Then the code sorts the number of leaves, so that the junctions with lower number of leaves and thus need fewer colours come first, then we cout this array.

Note : to avoid confusion I left the index of the root as 1 and made sure that every indexed loop I made looped upto n not from 0 to n - 1 and I oversized my arrays.
