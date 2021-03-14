**Code:** [0605A.cpp](./0605A.cpp)

# Explanation

**Time Complexity:** O(n)

**Memory Complexity:** O(n) 

### Explanation

the cars that don't need to be moved are a sequence of numbers that must be consecutive (not only increasing) and thus searching for the longest consecutive increasing subsequence and subtracting its length from n will get you the smallest possible number of cars needed to be moved.

I did that by storing the indexes of each number from 1 to n in an array I called pos and then I looped on each number and checked if its index is larger than the previous number, if it is I increase the current lis length (currLis), if it isn't currLis is reseted to 1, and at the end of each iteration if currLis is larger than the maximum lis length (stored in the variable called lis) we set it to be the maximum one.

At the end we cout n - lis.
