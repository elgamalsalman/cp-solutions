**Memoization Code:** [10819\_memoization.cpp](./10819_memoization.cpp)

**Tabulation Code:** [10819\_tabulation.cpp](./10819_tabulation.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(nm * numOfTestCases)

**Memory Complexity:** O(nm) but with the space saving trick in tabulation it is O(m)

### General Comments

I didn't really like the way the problem statement was written as I didn't realize that the visa card would allow her to have a negative account balance and then pay her debt with the bonus afterwards, this should have been stated clearly (Retry solving the problem if you have just learnt about that)

This is a 0-1 Knapsack (Subset Sum) problem which is one of the so called classical DP problems as they no longer appear as stand-alone problems in programming contests. I have solved this problem in both DP methods, memoization (top-down) and tabulation (bottom-up) to practice both methods. After solving it using one method I encourage you to do the same and solve it again using the other one as each method has its pros and cons (check CP3 by Steven and Felix Halim page 102 for reference). 

Regarding the tabulation solution, despite not facing any memory limit problems, just for practice I have implemented what the authors of CP3 call the memory saving trick (see CP3 page 101 and the top of 119), I also encourage you to do the same for practice.

### Explanation

The dp table has 2 dimensions as 2 arguments are needed to uniquely identify a subproblem. The first is the index of the last dress we are considering in the array dresses in this subproblem, the second is the used money so far. Note that the order doesn't really matter, but I've done it this way to decrease cache misses.

##### Memoization

We establish the base cases of the recursion, if the index i exceeds n then we have passed over all dresses and thus we check if the usedMoney is below m (the budget) or if the usedMoney has exceeded 2000 and the usedMoney is below the m + 200 due to the bonus outlined in the problem description then we return 0, else we return a very large negative number (-1000) so that the total series of taken dresses ending here will never end up with a total positive favour so it will never be considered, this is what we want as this series of dresses is above our m so we can't take it. We also return a large negative number (-1000) if it ever happens that the used money exceeds the m + 200 even if the index isn't equal to n, as this is a dead end because even with the bonus we won't afford this path anyway, no need to continue. If non of the above cases were triggered we continue.

I used a reference variable called currDpCell to avoid rewritting the reference to the dp index we are accessing or changing. If the cell contains -1 then it wasn't reached before so we calculate it by finding the maximum total favour if we baught or left the current dress and we store the answer in the cell and return it. else if the cell isn't -1 then we have already calculated it and we return the number right away, notice that we fill the dp table each test case with -1 using memset();

##### Tabulation

It is quite similar to memoization but we first fill the base cases in the dp table (dp\[0\]\[0\] = 0, and dp\[0\]\[dresses\[0\].price\] = dresses\[0\].favour) and run all subproblems with certain indexes from 1 to n - 1 which rely on the subproblems of the previous index, so the result of the subproblems which have indexes lower than the current index by 2 and more are no more needed, allowing us to shrink the first dimension to 2. This is the idea behind the memory saving trick.
