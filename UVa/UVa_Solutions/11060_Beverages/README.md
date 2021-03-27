**Code:** [11060.cpp](./11060.cpp)

# Explanation

**Time Complexity:** O(N<sup>2</sup> + M)

**Memory Complexity:** O(N + M)

**Category:** Graph Theory

### General Comments

This is a topological sort porblem which needs printing out the drinks in the order in which they appeared in the input if their alcoholic content wasn't stated to be different. The dfs based algorithm for topological sorting won't be able to do that easily as it sorts every connected sub-graph on its own, and combining them would be hectic, anyways, you can find the explanation of the dfs version in my solution to the problem [10305 - Ordering Tasks](../10305_Ordering_Tasks). Due to the reasons above the bfs based topological sort makes more sense in this particular case.

Because the maximum input is extremely small I didn't bother using a priority queue as the bfs queue which could have decreases the time complexity to O(NlogN + M).

### Explanation

I used a map in order to map the name of every beverage to a number and use that number throughout the algorithm for convenience and at the end I used an array to convert the topologically sorted vector of numbers back to names in O(1) fetch time, though using the map's O(logn) fetch time would have worked fine as well.

After that the code does a regular bfs based topological sort as outlined in my solution to the problem [00872 - Ordering](../00872_Ordering). The only difference is that this code only finds one solution and after operating on a vertex with indegree 0 the code searches back from the beginning to find the new first indegree 0 vertex.
