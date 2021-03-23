**Code:** [1102E.cpp](./1102E.cpp)

# Explanation

**Time Complexity:** O(nlogn)

**Memory Complexity:** O(n) 

### Explanation

Notice that if a number is repeated multiple times throughout the array a then all values from the first occurrence to the last occurrence of that number in a must be equal in b.

So my code stores the indexes of the last occurrences of each number in a map, and then it loops on the array a again and holds in a variable I named r the index to which the array must be equal, then it loops and updates r whenever it reaches an element in a[i] with its last occurrence index larger than r. Whenever i (the index of the loop in a) exceeds r then the values are no longer bound and can be increased and thus we multiply the answer by 2 as there are two possible routes at this index, either make b<sub>i</sub> = b<sub>i - 1</sub> or b<sub>i</sub> = b<sub>i - 1</sub> + 1, and of course we mod the answer as specified in the problem description.
