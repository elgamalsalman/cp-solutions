**Tabulation Code:** [11566\_tabulation.cpp](./11566_tabulation.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(KxN<sup>2</sup>) : (Worst Case) => O(100 * 100 * 10<sup>2</sup>) = O(10<sup>6</sup>) < O(10<sup>8</sup>), so it is just fine

**Memory Complexity:** O(KxN<sup>2</sup>) and O(xN<sup>2</sup>) with the space saving trick in tabulation, both of which do not exceed the memory limit.

### General Comments

This is a 0-1 Knapsack (Subset Sum) problem which is one of the so called classical DP problems as they no longer appear as stand-alone problems in programming contests. I have solved this problem using tabulation (bottom-up) for practice because I generally start with memoization as I find it more intuitive. If this is your first 0-1 Knapsack (subset Sum) problem I encourage you to solve it in both DP methods, this wasn't my first so I skipped memoization to save time.

Despite not facing any memory limit problems, just for practice I have implemented what the authors of CP3 call the memory saving trick (see CP3 page 101 and the top of 119), I also encourage you to do the same for practice.

### Explanation

To calculate the average favour we first calculate the total and divide it by N + 1 at the end. Because we can take each dim sum twice I have duplicated each dim sum price and total favour in the arrays p and f respectively.

The dp table has 3 dimensions as 3 arguments are needed to uniquely identify a subproblem. The first is the index of the last dim sum we are considering in the arrays p and f in this subproblem, the second is amount of money used, and the third and last argument is the number of used dishes so far. Note that the order doesn't really matter, but I've done it this way to decrease cache misses.

We set availableMoney to x * (K + 1) which is all the money the friends have. We then fill the base cases in the dp table (dp\[0\]\[0\]\[0\] = 0, and dp\[0\]\[p\[0\]\]\[1\] = f\[0\] only if p\[0\] <= availableMoney) and find the solutions to all subproblems with a certain index (from 1 to 2 * K - 1) which rely on the subproblems of the previous index. We calculate the solutions by calculating the maximum favour if we buy or don't buy the current dim sum, but we only consider buying the current dimsum if the number of dishes didn't reach the maximum and if buying the current dim sum won't cause the usedMoney to exceed availableMoney (which is our budget).

Then at the end we find the subproblem with maximum favour between all subproblems with index 2 * K - 1 and which don't exceed availableMoney after adding the price of the tea and the 10% service fee and have usedDishes between 0 and 2 * (N + 1) inclusive.

We add the 10% by multiplying by 1.1, but this may cause rounding errors because computers represent numbers in binary but we do in decimal, so sometimes computers' floating point representation may not be exact, this may cause a problem as we are ceiling the result, if this tiny error was enough to change the result to a different integer value ceiling will result in a different value, thus we compensate for it either by subtracting a very small value which is still larger than the small error (in my code I subtracted 1e-6 or 0.000001) or by substituting the 1.1 to 1.1L so that it is a long double so the value is more exact and the size of the error becomes very insignificant so that it won't change the integer value, this is very important because getting it all right and missing this will result in a WA verdict!

Because the result of the subproblems which have indexes lower than the current index by 2 and more are no more needed, allowing us to shrink the first dimension to 2. This is the idea behind the memory saving trick.
