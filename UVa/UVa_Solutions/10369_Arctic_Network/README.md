**Code:** [10369.cpp](./10369.cpp)

# Explanation

**Time Complexity:** O(P^2^logP)

**Memory Complexity:** O(P^2^)

**Category:** Graph Theory

### General Comments

This is a Minimum Spanning Forest problem, a variation of the traditional Minimum Spanning Tree (MST) problem. This problem is way simpler to code using Kruskal's algorithm compared to Prim's algorithm, as Prim's finishes every MST one by one while Kruskal's builds the forest all at once and thus I can stop it when the forest has k number of trees.

### Explanation

In order to find the minimum possible K, we want to connect all outposts with a MST and have the satellite connections take care of the longest edges in the MST while the radio is used for the rest, this guarantees minimum edges used in radio communication. To do that my code stops Kruskal's when the number of disjoint trees in the Minimum Spanning Forest is equal to S, and thus we can leave one satellite channel in each tree and establish the network, while having the communication inside each tree using radio.

Note : if S is 0 we change it to 1 as having no satellite channels is like having one, they won't be used in both cases.

What Kruskal's algorithm does simply is that it sorts an edge list in non-decreasing order, and greedily includes the shortest edge which connects two vertices which aren't already connected. The connection criteria is checked quickly using a UFDS (aka DSU) structure.

See CP3 pages *138* and *139* for a more thorough explanation.
