**Memoization Code:** [10496\_memoization.cpp](https://github.com/elgamalsalman/CPSolutions/blob/main/UVa/UVa_Solutions/10496_Collecting_Beepers/10496_memoization.cpp)

# Explanation

**Category:** Dynamic Programming (DP)

**Time Complexity:** O(n<sup>2</sup> * 2<sup>n</sup>)

**Memory Complexity:** O(n * 2<sup>n</sup>)

### General Comments

This is a Traveling Salesman Optimization Problem (TSP-OPT) problem which is a very infamous problem for being NP-Hard, it is one of the so called classical DP problems as they no longer appear as stand-alone problems in programming contests. 

I have solved this problem using DP, specifically memoization. The brute force implementation might have worked in the time limits specified, but I didn't try it because I solved this problem to practice DP. If you would like to see a brute force solution for a similar TSP problem you will find one in problem [00216 - Getting in Line](https://github.com/elgamalsalman/CPSolutions/blob/main/UVa/UVa_Solutions/00216_Getting_in_Line/); however, even if the brute force solution did get an ACC verdict for practice I encourage you not to stop right there and try to implement the faster dynamic programming solution which I have an explanation for down below.

I chose memoization (top-down) because I found it more intuitive and because the traversal of the dp table in the tabulation problem must follow a route that covers all the small subproblems of a bigger subproblem before calculating the value for the bigger subproblem, this would be hard to implement as the smaller subproblems are scattered all around the table.

### Explanation of the fast DP memoization code

First of all, I have added the starting position of the robot to the array of beepers and increased the variable holding the number of beepers (beepersNum) by one in order to make sure the cycle the robot is following passes through the starting position.

The dp table has 2 dimensions as 2 arguments are needed to uniquely identify a subproblem. The first is a bitmask of all the beepers this subproblem will cover, and the second argument is the last beeper the route must end at in this subproblem.

We first fill the edge matrix with the weights of each edge, calculated by adding the absolute value of the differences in x and y directions as the robot can only move in these directions. Then we call the recursive function getMinDis((1 << BeepersNum) - 1, 0), the bitmask passed includes all beepers (including the starting position) and the lastBeeper is the starting position to make sure the route includes the robot returning to the starting position at the end.

Now concerning the recursive function getMinDis(), it first checks if this is a base case by counting the number of ones in the binary representation of the number using the function \_\_builtin\_popcount() and checking if it is one (if there is only one beeper to collect) then we return the distance between the starting position and the lastBeeper.

Then we check if the answer wasn't already computed if it was we return the value right away else we calculate it. We do that by first generating the bitmask of the smaller subproblems needed to calculate the answer to this subproblem by setting the bit corresponding to the lastBeeper to 0 and we store this new smaller bitmask in the variable subBitmask, then we loop on all possible ending beepers and run their corresponding subproblems using the recursive funciton and we add the result of each function to the edge between the ending beeper of the small subproblem and the last beeper in the bigger subproblem we are calculating and we find the minimum, then we return that minimum distance.

Then we cout the distance of the minimum route in the format outlined in the problem description.

This isn't an easy problem to get the hang of, so this is a [link](https://www.youtube.com/watch?v=-JjA4BLQyqE&lc=UgzakVzoESzZfe-zJwl4AaABAg) to a youtube video (I didn't make it myself but I think it is pretty helpful) which goes through how this dp algorithm works, however the code presented at the end of the video is written in java so you can use my code instead for reference. Also please take care while searching for the right code on the internet, some websites publish, I assume by mistake, Minimum Spanning Tree (MST) code as the solution for TSP, those codes won't work as these are different problems, I have tested mine and it got an ACC verdict so use that for reference.
