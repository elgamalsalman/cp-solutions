**Code:** [0605A.cpp](./0605A.cpp)

# Explanation

**Time Complexity:** O(n)

**Memory Complexity:** O(n) 

### Explanation

the cars that don't need to be moved are a sequence of numbers that must be increasing by a difference of 1 each time and thus searching for the longest increasing subsequence with an increase of 1 between each 2 consecutive elements and subtracting its length from n will get you the smallest possible number of cars needed to be moved.

I did that by storing the indexes of each number from 1 to n in an array I called pos and then I looped on each number and checked if its index is larger than the one of the previous number, if it is I increase the current lis length (currLis), if it isn't currLis is reseted to 1, and at the end of each iteration if currLis is larger than the maximum lis length (stored in the variable called lis) we set it to be the maximum one.

At the end we cout n - lis.
