**Code:** [0414A.cpp](./0414A.cpp)

# Explanation

**Time Complexity:** O(n)

**Memory Complexity:** O(1)

### General Comments

This problem had a few edge cases that I didn't notice right away because I didn't give much attention to the ranges of each input, this was a big mistake and it costed me some precious time.

### Explanation

What I did in this problem was to cout the first two numbers with their gcd is equal to k - the number of remaining pairs, so that the remaining pairs each need to have a gcd of 1 and thus we can just cout consecutive numbers (as any 2 consecutive numbers have a gcd of 1).

The code first calculates the gcd needed of the first pair and stores it in the variable num. Of course if that gcd turned out to be less than 1 then it isn't possible, neither is it if n was 1 (no pairs at all) and k wasn't zero.

If it isn't possible -1 printed else the following is done. The code prints the first number as num, then it loop on numbers from num * 2 and up until n numbers are printed. So if n == 1 nothing except num is printed which is right, else the first pair is num and num * 2 which gave a gcd of num which is what we want and the rest are consecutive numbers which is also what we planned for.

Just a final note is that num * 2 can't exceed 2 * 10<sup>8</sup> and this leaves room for 10<sup>9</sup> - 2 * 10<sup>8</sup> consecutive numbers to print without any of the numbers ever exceeding 10<sup>9</sup>. The largest possible value of n is 10<sup>5</sup> which is way smaller than 10<sup>9</sup> - 2 * 10<sup>8</sup> so we can be confident that the numbers printed will never exceed 10<sup>9</sup>.
