**Memoization Code:** [00357\_memoization.cpp](https://github.com/elgamalsalman/CPSolutions/blob/main/UVa/00357_Let_Me_Count_The_Ways/00357_memoization.cpp)

**Tabulation Code:** [00357\_tabulation.cpp](https://github.com/elgamalsalman/CPSolutions/blob/main/UVa/00357_Let_Me_Count_The_Ways/00357_tabulation.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(largestInput) in memoization, and O(1) in tabulation but with an ignored coefficient larger than 30000, however a much faster O(1) can be achieved if you precompute the entire table and just fetch the answer each time.

**Memory Complexity:** O(1) but with the same huge ignored coefficient > 30000

### General Comments

This is a Coin Change (CC) problem which is one of the so called classical DP problems as they no longer appear as stand-alone problems in programming contests. I have solved this problem in both DP methods, memoization (top-down) and tabulation (bottom-up) to practice both methods. After solving it using one method I encourage you to do the same and solve it again using the other one as each method has its pros and cons (check CP3 by Steven and Felix Halim page 102 for reference). 

### Explanation

The dp table has 2 dimensions as 2 arguments are needed to uniquely identify a subproblem. The first is the number of cents to be represented and the second is the last coin allowed for representation of the cents (e.g. if it is coin index 2 then this cell contains the number of ways the cents can be represented using coins of indexes 0, 1 and 2). Note that the order of the dp table dimensions doesn't really matter, but I've done it this way to decrease cache misses.

##### Memoization

We reset the whole dp table to -1, then we establish the base cases of the recursion, if the cents argument is equal to 0 then return 1 but if the cents is less than zero return 0, if the lastCoinAllowed is equal to 0 (we can only use the cents coin) then return 1.

 Now we have to create the recurrence in which we relate the answer of a subproblem to the answers of smaller subproblems. If the value of the currDpCell is equal to -1 (not already calculated, if it is just return the stored value) then set the currDpCell to be the sum of the ways of representing the same amount of cents with the range of coins up to lastCoinAllowed - 1 and the number of ways of representing the amount of cents - coins[lastAllowedCoin] with the same range of allowed coins up to lastCoinAllowed (same range as the current subproblem).

I used a reference variable called currDpCell to avoid rewritting the reference to the dp index we are accessing or changing.

Now we find the answer by calling numWays(cents, 4) including the whole range of coins as allowed to use and including the number of cents to represent as the inputted value. 

##### Tabulation

It uses the same idea as the one in memoization but we first fill the base case in the dp table (dp\[0\]\[0\] = 0) and run all subproblems with a certain indexes from 1 to 30000 which rely on the subproblems of the previous indexes which were already calculated.
