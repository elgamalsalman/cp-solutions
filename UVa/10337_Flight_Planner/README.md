**Memoization Code:** [10337\_memoization.cpp](https://github.com/elgamalsalman/CPSolutions/blob/main/UVa/10337_Flight_Planner/10337_memoization.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(X/100)

**Memory Complexity:** O(X/100)

### General Comments

This is one of the fairly easy non-classical DP problems.

I solved it using memoization (top-down) only though if this is one of your first DP problems ever I encourage you to solve it using tabulation too, just for practice.

### Explanation of DP memoization code

The dp table has 2 dimensions as 2 arguments are needed to uniquely identify a subproblem. The first is the altitude at which the plane starts, and the second argument is the distance at which the plane starts in this subproblem, and the dp table holds the minimum amount of fuel needed for each subproblem.

Note: because all distances are given as multiples of 100 we can divide all distances by 100 and work with a much smaller maximum distance of 1000 miles only as I have done in my implementation instead of 100000 to decrease memory usage.

Now concerning the recursive function getMinFuel(), it first checks for base cases, if the altitude is not in the valid range of 0 to 9 then it returns a huge number so that this route will never be considered as the one with minimum Fuel, and if the starting distance is equal to the total distance then the plane has reached the end, if the altitude isn't 0 it returns the same huge number, else this is a valid route and so it returns 0.

Then we check if the answer wasn't already computed if it was we return the value right away else we calculate it. We do that by setting it to the minimum fuel needed if the plane ascended or if it descended or if it stayed in the same altitude, and we return that minimum fuel needed.

Then we cout the minimum fuel needed by calling the function getMinFuel(0, 0) with these specific arguments to start the plane at the starting point (altitude : 0, distance : 0).
