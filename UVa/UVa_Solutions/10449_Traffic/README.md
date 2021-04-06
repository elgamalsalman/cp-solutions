**Code:** [10449.cpp](./10449.cpp)

# Explanation

**Time Complexity:** O(nr)

**Memory Complexity:** O(r)

**Category:** Graph Theory

### General Comments

This is a tricky negative cycles detection problem which can easily be done using Bellman Ford's algorithm in O(VE).

The problem statement wasn't fully clear to be honest because it didn't specify that the code should print '?' for unreachable junctions. Anways my code prints '?' if the earnings are less than 3 or if the earnings after running the bellman ford's for the second time changed, which means there is a negative cycle in the path to this junction or if the earnings are extremely high which means that it isn't connected to the source vertex.

See pages *151* and *152* in CP3 for a thorough explanation.
