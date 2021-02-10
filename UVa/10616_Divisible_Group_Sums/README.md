**Memoization Code:** [10616\_memoization.cpp](https://github.com/elgamalsalman/CPSolutions/blob/main/UVa/10616_Divisible_Group_Sums/10616_memoization.cpp)

**Tabulation Code:** [10616\_tabulation.cpp](https://github.com/elgamalsalman/CPSolutions/blob/main/UVa/10616_Divisible_Group_Sums/10616_tabulation.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(NQDM * numSets) : (Worst Case) => O(200 * 10 * 20 * 10 * 10) = O(4000000) < O(10 ^ 8), so it is just fine

**Memory Complexity:** O(NDM), and O(DM) with the space saving trick in tabulation, both of which do not exceed 10 ^ 6 in the worst case.

### General Comments

This is a 0-1 Knapsack (Subset Sum) problem which is one of the so called classical DP problems as they no longer appear as stand-alone problems in programming contests. I have solved this problem in both DP methods, memoization (top-down) and tabulation (bottom-up) to practice both methods. After solving it using one method I encourage you to do the same and solve it again using the other one as each method has its pros and cons (check CP3 by Steven and Felix Halim page 102 for reference). 

Regarding the tabulation solution, despite not facing any memory limit problems, just for practice I have implemented what the authors of CP3 call the memory saving trick (see CP3 page 101 and the top of 119), I also encourage you to do the same for practice.

### Explanation

The dp table has 3 dimensions as 3 arguments are needed to uniquely identify a subproblem. The first is the index of the last number we are considering in the array nums in this subproblem, the second is the sum of the taken nums so far mod D while making sure the result isn't negative by adding D to it if it is < 0, and the third and last argument is the number of used numbers so far. Note that the order doesn't really matter, but I've done it this way to decrease cache misses in tabulation.

##### Memoization

We establish the base cases of the recursion, if the numUsedNums is M and the sumModD is 0 then this is a way and the func returns 1, else if the index is N or the numUsedNums is M we return 0, else we recur. I used a reference variable called currDpCell to avoid rewritting the reference to the dp index we are accessing or changing. If the cell contains -1 then it wasn't reached before so we calculate it by adding the number of ways if we added or ignored the current index from the set of numbers and we store the answer in the cell and return it. else if the cell isn't -1 then we have already calculated it and we return the number right away, notice that we fill the dp table each query with -1 using memset();

##### Tabulation

It is quite similar to memoization but we first fill the base cases in the dp table (dp\[0\]\[0\]\[0\] = 1, and dp\[0\]\[nums\[0\] mod D and making sure it is positive as outlined before\]\[1\] = 1) and run all subproblems with a certain index (from 1 to n - 1) which rely on the subproblems of the previous index, so the result of the subproblems which have indexes lower than the current index by 2 and more are no more needed, allowing us to shrink the first dimension to 2. This is the idea behind the memory saving trick.
