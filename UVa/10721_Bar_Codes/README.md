**Memoization Code:** [10721\_memoization.cpp](https://github.com/elgamalsalman/CPSolutions/blob/main/UVa/10721_Bar_Codes/10721_memoization.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(nmk)

**Memory Complexity:** O(nk)

### General Comments

I honestly didn't find the problem statement very well written because the picture on the right had 4 small black bars and 4 big black and white bars, so I at first got confused with what k meant, if you are confused too, the number k represents the number of big bars (colour doesn't matter).

This is one of the easier non-classical DP problems.

I solved it using memoization (top-down) only, though if this is one of your first DP problems ever I encourage you to solve it using tabulation too, just for practice.

### Explanation of DP memoization code

The dp table has 2 dimensions as 2 arguments are needed to uniquely identify a subproblem. The first is the number of bars, and the second argument is the number of units in the barcode of this subproblem, and the dp table holds the number of different barcodes of each subproblem.

Now concerning the recursive function countCodes(), it first checks for base cases, if the number of units is lessthan the number of bars or if any of the two arguments are below zero this shouldn't be counted and we return 0, else if both number of bars and the number of units remaining are equal to zero then this is a complete barcode and it returns 1.

Then we check if the answer wasn't already computed if it was we return the value right away else we calculate it. We do that by setting it to the sum of all possible barcodes looping on all possible widths of the current bar from 1 to m and we recursively call countCodes(). Then we return that sum.

Then we cout the number of possible barcodes satisfying the conditions by outputing the number returned from calling countCodes(k, n) passing the number of bars and the number of units available to the function.
