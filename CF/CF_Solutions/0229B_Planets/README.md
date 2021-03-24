**Code:** [0229B.cpp](./0229B.cpp)

# Explanation

**Time Complexity:** O(n + m + k), but I believe my solution isn't optimal as I think it may lead to O(n<sup>2</sup>) if the right test case was given to it.

**Memory Complexity:** O(n + m + k) 

**Category:** Graph Theory

### General Comments

This problem should be solved using Dijkstra's algorithm for SSSP (Single Source Shortest Paths), however as of this moment I still haven't learnt much about this algorithm so my best bet was a modified BFS (which I believe could have resulted in a TLE, but it didn't).

### Explanation

My modified BFS solution uses BFS to traverse the graph and calculate the delay at each planet using a linear scan in the arrivals to that planet, then the BFS checks all the connected planets to this planet and checks if that connected planet wasn't reached before or if going to it directly using the star gate including the delay will result in a lower sssp value to this planet, if any of the two conditions is true we change the sssp value to this planet and all the other sssp values depending on this sssp by pushing the planet to the back of the queue again (which is why I think my solution isn't efficient).

Then the code couts sssp[n].
