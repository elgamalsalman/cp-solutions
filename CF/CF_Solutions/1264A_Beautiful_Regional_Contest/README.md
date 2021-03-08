**Code:** [1264A.cpp](./1263A.cpp)

# Explanation

**Time Complexity:** O(tn)

**Memory Complexity:** O(n)

### General Comments

This is a fairly straightforward problem.

### Explanation

My code stores the index of the last winners of each medal in the variables g, s, and b for gold, silver and bronze respectively. It inputs the scores and then loops until the last gold index reaches a valid one (one which has a higher score than the score after it) and it shifts the last index in g, s and b until the first valid gold index is reached. Each time, the code shifts g by one, but s is shifted by 2 to accomodate for the shifting of g and increase its size by one to be bigger than the number of golds, and b is shifted by 3 to accomodate for the shifting of g and b and increase its size by 1 to be also bigger than the number of golds.

Then the code does a similar thing to s but without increasing the size of b to be larger than s as this is not a requirement according to the problem description.

Then the third loop finds the largest possible valid b in order to maximize the number of winners.

All these loops run while taking care that b never exceeds half way through n as the number of winners should never be greater than half.

Lastly if the last index of b has exceeded halfway through n then there is no solution and the code couts three zeros, otherwise it calculated the number of winners in each medal and couts them.
