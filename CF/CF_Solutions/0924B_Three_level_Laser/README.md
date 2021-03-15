**Code:** [0924B.cpp](./0924B.cpp)

# Explanation

**Time Complexity:** O(n)

**Memory Complexity:** O(n) 

### Explanation

For a given i and k the lower the j is the higher the efficiency so we always take j as the number right after i. Also, for a given i efficiency is the highest if k is the largest number that doesn't make E[k] - E[i] larger than U.

Therefore, the code first sets i to 0 and k to 2 then loops and in every iteration sets the maximum efficiency (maxEff) to be the maximum between it and the current efficiency only if E[k] - E[i] isn't larger than U. Then it increments k if E[k + 1] - E[i] isn't larger than U and k + 1 won't exceed n + 1 (the largest possible index in an array of length n), if this isn't true then we increment i instead, and we increment j if i - j is less than 2 (in order to make sure we are dealing with 3 distinct energies). The loop iterates as long as i doesn't reach n - 2.

At last, the code couts maxEff while setting the precision to 10 decimal places in order to make sure the answer is accurate enough.
