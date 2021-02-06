# Explanation

### Category		: Dynamic Programming
### Time Complexity	: O(nlogn) though O(n ^ 2) would have worked fine
### Memory Complexity	: O(n)

## General Comments

This was my first weighted LIS (Longest Increasing Subsequence) + LDS (Longest Decreasing Subsequence) problem, this problem could have been solved using a simpler O(n ^ 2) algorithm but as a challenge I wanted to come up with an O(nlogn) one.

## Explanation

LIS is initially empty, then the algorithm constantly searches for the first element with height <= the height of the next building to the right, and then binary searches for the first building in LIS with accumulated weight (total width of the LIS till this building) greater than the totatl weight of the current building LIS. Basically, all the buildings in the range [it1, it2) don't make any sense to choose as they are shorter and have a total weight <= current building total weight, so we replace their values with the current building. and thus the height in LIS will always be in a non-increasing order and the total weights in LIS will be in non-decreasing order allowing us to binary search it again the next iteration.

I could have duplicated the code and changed it slightely to get the LDS but instead I went for a neater version instead, I chose to reuse the above code and just flip the buildings vector using a stack. This approach may not be ideal in a competition environment as it would take more time.
