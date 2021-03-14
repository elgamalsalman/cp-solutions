**Code:** [1344A.cpp](./1344A.cpp)

# Explanation

**Time Complexity:** O(n)

**Memory Complexity:** O(n) 

**Category:** Number Theory

### General Comments

This is a Number Theory problem, due to the fact that each element in a can be up to 10<sup>9</sup> it is infeasable to iterate through all these rooms and check that no two guests are assigned to one room. Thus a better solution is needed.

### Explanation

At the time of writing this, I didn't read much about number theory, therefore I couldn't solve it mathematically, instead I used a series of observations to get the right answer.

What I realized is that whenever guest is moved from room a to room b, room b's k mod n can be calculated according to room a's k mod n. Additionally, if two rooms gave one room the same k mod n then we can be sure that more than one guest will stay in this room as n repeats forever, and thus we can check if every room is given one guest by checking if all k mod n calculated by moving a guest from the n rooms that connect to this room aren't equal.
