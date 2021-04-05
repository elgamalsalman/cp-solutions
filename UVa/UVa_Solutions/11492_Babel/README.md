**Code:** [11492.cpp](./11492.cpp)

# Explanation

**Time Complexity:** O(M<sup>2</sup>logM)

**Memory Complexity:** O(M<sup>2</sup>)

**Category:** Graph Theory

### General Comments

After adding a starting vertex that has an edge of weight zero going to all the words in the starting language, and adding a ending vertex with edges of weight 0 from all words in the ending language, this becomes a Single Pair Shortest Path (SPSP) problem on a weighted graph, and thus dijkstra's algorithm can solve it in a time complexity of O((E + V)logV).

This problem was a bit annoying to implement because the vertices of the graph are given as words.

### Explanation

First I mapped every language and every word to a number so that they can be managed easily.

The vertices in this problem are the words and each 2 words are connected if they are both in the vocabulary of a particular language and if their first letters aren't the same.

The rest of the solution is a straight forward dijkstra's algorithm implementation. See pages *148* and *149* in CP3.
