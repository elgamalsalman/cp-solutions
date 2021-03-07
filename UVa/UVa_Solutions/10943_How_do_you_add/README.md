**Memoization Code:** [10943\_memoization.cpp](./10943_memoization.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(NK<sup>2</sup>)

**Memory Complexity:** O(NK)

### General Comments

This is one of the easier non-classical DP problems.

I solved it using memoization (top-down) only, though if this is one of your first DP problems ever I encourage you to solve it using tabulation too, just for practice.

### Explanation of DP memoization code

The dp table has 2 dimensions as 2 arguments are needed to uniquely identify a subproblem. The first is the number of numbers to sum, and the second argument is the sum needed for this subproblem, and the dp table holds the number of different ways the sum can be achieved.

Now concerning the recursive function countWays(), it first checks for base cases, if the number of numbers to add (numDigits) is 0 and the sum is 0 then this is is a valid sum the function return 1, else if the numDigits is 0 but sum isn't then this isn't valid and the function returns 0.

Then we check if the answer wasn't already computed if it was we return the value right away else we calculate it. We do that by looping on all possible numbers to add from 0 till sum (as numbers larger than sum will definitely yield an invalid sequence of numbers) then we subtract the sum by that number and recurse calling countWays() with the first argument as numberDigits - 1 and the second as the new sum, the value returned is added to the currCell and then returned at the end after summing all possible ways yielded from all possible first number choices.

Then in the main function we cout the answer by outputing the number returned from calling countWays(K, N), passing the number of numbers to add (K) and the sum (N) to the function.
