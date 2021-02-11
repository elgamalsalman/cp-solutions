**Tabulation Code:** [11517\_tabulation.cpp](https://github.com/elgamalsalman/CPSolutions/blob/main/UVa/11517_Exact_Change/11517_tabulation.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(pn<sup>2</sup> * numTestCases) where p is the price of the item, and n is the number of coins we have.

**Memory Complexity:** O(pn)

### General Comments

This is a Coin Change (CC) problem which is one of the so called classical DP problems as they no longer appear as stand-alone problems in programming contests. I have solved this problem using tabulation (bottom-up) for practice because I generally start with memoization as I find it more intuitive. If this is your first Coin Change (CC) problem I encourage you to solve it in both DP methods, this wasn't my first so I skipped memoization to save time.

### Explanation

The dp table has 2 dimensions as 2 arguments are needed to uniquely identify a subproblem. The first is the index of the last coin we are considering in the array coins in this subproblem, the second is the price of the item. The dp table holds the minimum number of coins needed to represent this price exactly. Note that the order of dp dimensions doesn't really matter, but I've done it this way to decrease cache misses for better performance.

We set all values in the dp table to a huge value the answer will never reach (in my case 11000). We then fill the base cases in the dp table which are dp\[0\]\[0\] = 0, we could have also added dp\[0\]\[coins\[0\]\] = 1 and checked if this is a possible answer but instead I used a ternary operator in the third nested loop to add this step in the first cell only. 

We then use solutions to subproblems we have already computed to find solutions to bigger subproblems. We do that by checking through the dp table from index 0 to n - 1 for cells with values not equal to 11000 (which means they are valid subproblems) and loop on all the coins starting from the coin directly after this index, adding the value of the coin to the money and calling and storing the result in newMoney. If newMoney is below the price p we just store the lowest number of coins between what is already in the cell and the number of coins of the smaller subproblem + 1 (dp\[i\]\[money\] + 1). Else if newMoney is higher than or equal to the price then we don't need to store it in the dp table as no more coins should be added to it, however, we have to check if it gives a new minimum amount of money to pay or if it provides the same amount of money but with lower number of coins, if yes we store its values as the current best answer. And at the end we cout the overall best answer.
