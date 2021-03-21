**Code:** [0546D.cpp](./0546D.cpp)

# Explanation

**Time Complexity:** O(n * log(log(n)))

**Memory Complexity:** O(n) 

**Category:** Number Theory

### Explanation

First notice that the best strategy that the second soldier should use is to choose the prime factors of n. Then notice that a!/b! = (a + 1) * (a + 2) * ... * b and that the prime factors of a!/b! are the same as the prime factors of (a + 1) and (a + 2) and ... and b combined. We don't need to list the prime factors, we only need to cout their number so we need to calculate the number of prime factors of each number from 2 to 5000000.

First my code uses the Sieve of Eratosthenes to find one factor of each number, then it uses dynamic programming to find the number of prime factors using the recursive function coutPFactors(), and lastly it does a partial sum on the array so that we can achieve O(1) range sum queries, to fit in the time limit.
