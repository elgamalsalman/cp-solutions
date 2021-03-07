**Memoization Code:** [10306\_memoization.cpp](./10306_memoization.cpp)

**Tabulation Code:** [10306\_tabulation.cpp](./10306_tabulation.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(nmS<sup>2</sup>) 

**Memory Complexity:** O(S<sup>2</sup>)

### General Comments

This is a Coin Change (CC) problem which is one of the so called classical DP problems as they no longer appear as stand-alone problems in programming contests. I have solved this problem in both DP methods, memoization (top-down) and tabulation (bottom-up) to practice both methods. After solving it using one method I encourage you to do the same and solve it again using the other one as each method has its pros and cons (check CP3 by Steven and Felix Halim page 102 for reference). 

### Explanation

Firstly it is clear that the e-modulus is calculated in the same way as the hypotenuse of a right-angled triangle, and that the sum of the conventional and InfoTechnological values can be seen as the sides of the triangle for better visualization. Thus we can use the function hypot() in the \<cmath\> header which calculate the hypotenuse of a right triangle from its 2 other sides to calculate the e-modulus.

The dp table has 2 dimensions as 2 arguments are needed to uniquely identify a subproblem. The first is the total conventional value to represent (one side of the triangle) and the second is the total InfoTechnological value to represent (the other side of the triangle) but the values the dp table holds differed from one implementation to the other. Regarding tabulation the dp table holds the minimum number of coins needed to represent the e-modulus resulting from the conventional value and the InfoTechnological values represented by both indexes of hte cell. However, concerning my memoization implementation the values in each cell represent the minimum number of coins needed to represent the e-modulus resulting from the answer's conventional value - the dp cell's first index and the answer's InfoTechnological value - the dp cell's second index, so it is basically the other way around, the lower the indexes the closer the e-modulus this cell represents to S. This is why we get the answer by calling numCoins(0, 0) in my memoization code.

##### Memoization

We reset the whole dp table to 1000 (huge number the real value will never reach), then we establish the base cases of the recursion, if the e-modulus value is greater than S then this is a dead end, so we return a huge number that the answer can never reach (500) so that this will never be considered as the min number of coins, this is what we want as this route doesn't lead to an e-modulus of S. 

Note: Take care that I have returned a different value other than the default one in the table, they are both larger than any possible answer but they must be different so that other iterations don't recompute dead ends thinking they were not computed yet as this will lead to a TLE verdict.

The other recursion base case is if the e-modulus was exactly equal to S, this is a possible coin combination so we return 0 so that the number of coins get accumulated and returned as the stack of function calss unwinds.

 Now we have to create the recurrence in which we relate the answer of a subproblem to the answers of smaller subproblems. If the value of the currDpCell is not equal to 1000 (answer already calculated) just return the stored value else set the currDpCell to be the minimum number of used coins + 1 accross all possibilities of the next coin, and return that value.

I used a reference variable called currDpCell to avoid rewritting the reference to the dp index we are accessing or changing.

##### Tabulation

It uses the same idea as the one in memoization but we first fill the table with huge dummy values (1000 in my case) and set the values of the base cases in the dp table (dp\[0\]\[0\] = 0) and run all subproblems with certain conventional and InfoTechnological values from 1 to S which rely on the subproblems of the previous indexes which were already calculated.
