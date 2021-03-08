**Code:** [1066C.cpp](./1066C.cpp)

# Explanation

**Time Complexity:** O(q)

**Memory Complexity:** O(q)

### General Comments

This is a fairly straight-forward problem, the first thing to notice is that q can reach 2 * 10<sup>5</sup> which without even coding it tells us that the complete search problem with the time complexity of O(q<sup>2</sup>) will yield a TLE verdict as (2 * 10<sup>5</sup>)<sup>2</sup> is 4 * 10<sup>10</sup>, and as a rule of thumb we can take any number larger than 10<sup>8</sup> as too large.

### Explanation

My code solves it in linear time by storing the position of each book relative to the first book in the array pos with the index as the qID so O(1) fetching of the position of each book is achieved.

At first the code inputs q, the first book and leaves its value in pos as 0 (the book in the center) then the variables l and w keep track of the number of books to the left and to the right of the first book respectively. Meanwhile, every book inserted after the first one is given a positive position if it is on the right and a negative one if it is on the left. Therefore we can calculate the number of books to the right and to the left of any book using the formula l + pos[qID] for the number of books to the left and r - pos[qID] for the number of books to the right.

Then we cout the answer.
