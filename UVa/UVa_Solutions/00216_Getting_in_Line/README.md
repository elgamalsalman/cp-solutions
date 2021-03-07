**Brute Force Code:** [00216\_bruteForce.cpp](./00216_bruteForce.cpp)

**Memoization Code:** [00216\_memoization.cpp](./00216_memoization.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(n<sup>2</sup> * 2<sup>n</sup>) for the dp memoization code and a notorious O(n!) for the brute force code.

**Memory Complexity:** O(2<sup>n</sup> * n) for the dp memoization code and a O(n<sup>2</sup>) for the brute force code.

### General Comments

This is a Traveling Salesman Optimization Problem (TSP-OPT) problem which is a very infamous problem for being NP-Hard, it is one of the so called classical DP problems as they no longer appear as stand-alone problems in programming contests. 

I have solved this problem using both brute force and DP, specifically memoization. The brute force implementation is pretty straight forward and thats why I didn't write an explanation for it. Although, this code gets an ACC verdict, just for practice I encourage you not to stop right there and try to implement the faster dynamic programming solution which I have added an explanation for down below.

I chose memoization (top-down) because I found it more intuitive and because the traversal of the dp table in the tabulation problem must follow a route that covers all the small subproblems of a bigger subproblem before calculating the value for the bigger subproblem, this would be hard to implement as the smaller subproblems are scattered all around the table.

### Explanation of the fast DP memoization code

The dp table has 2 dimensions as 2 arguments are needed to uniquely identify a subproblem. The first is a bitmask of all the computers this subproblem will cover, and the second argument is the last computer the route must end at in this subproblem.

We first fill the edge matrix with the weights of each edge, calculated using the hypot() function. Then we call the recursive function getMinDis((1 << (n + 1)) - 1, n) using these arguments. You might have noticed that I passed a bitmask with the number of ones larger than the number of computers by one, I did this so that the function would recurse to all possible ending computers with the bitmask of n (number of computer) ones, but if you will do this too make sure that the edges between the extra computer I have added and all other computers is zero, I did that by memset(dp, 0, sizeof dp). You can instead write that loop manually if you find this approach confusing.

Now concerning the recursive function getMinDis(), it first checks if this is a base case by counting the number of ones in the binary representation of the number using the function \_\_builtin\_popcount() and checking if it is one (if there is only one computer in the network) then we return the pair {0.0, 0}, the first number represents the minimum distance of the cable needed and the second is the parent or the computer before the last computer, this will be used to reconstruct the network at the end but in this base case there is only one computer so this number can be any number whatsoever as it doesn't have any significant value as there is no computer behind the last one anyway.

Then we check if the answer wasn't already computed if it was we return the value right away else we calculate it. We do that by first generating the bitmask of the smaller subproblems needed to calculate the answer to this subproblem by setting the bit corresponding to the lastC to 0 and we store this new smaller bitmask in the variable subBitmask, then we loop on all possible ending computers and run their corresponding subproblems using the recursive funciton and we add the result of each function to the edge between the last computer in the small subproblem and the last computer in the bigger subproblem we are calculating. then we return a pair containing the minimum cable distance and the ending index of the subproblem that resulted in the minimum distance.

Then the main function reconstructs the connection route using the data from the second element in the returned pair (the index of the computer before the last one) and then we cout all the data needed in the format outlined in the problem description.

This isn't an easy problem to get the hang of, so this is a [link](https://www.youtube.com/watch?v=-JjA4BLQyqE&lc=UgzakVzoESzZfe-zJwl4AaABAg) to a youtube video (I didn't make it myself but I think it is pretty helpful) which goes through how this dp algorithm works, however the code presented at the end of the video is written in java so you can use my code instead for reference. Also please take care while searching for the right code on the internet, some websites publish, I assume by mistake, Minimum Spanning Tree (MST) code as the solution for TSP, those codes won't work as these are different problems, I have tested mine and it got an ACC verdict so use that for reference.
