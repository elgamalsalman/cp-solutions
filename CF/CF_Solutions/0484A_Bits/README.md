**Code:** [0484A.cpp](./0484A.cpp)

# Explanation

**Time Complexity:** O(logn)

**Memory Complexity:** O(1) 

### General Comments

This problem needs some bit manipulation knowledge, so if you don't know how to do some basic bit maninpulation, like setting a certain bit in a number to one or what are bit-shifting operators, I recommend first reading some articles about this topic.

### Explanation

To achieve the number in the specified range with largest number of one bits the code should iteratively turn on the zero bits from the least significant bits to the most significant bits in the number l as long as turning this bit doesn't increase the number above r, if it does then we break and cout the current number we have.

Note: What was tricky about this problem is that because the numbers exceed the range of int and need to be stored in long long ints, when we use the bit-shifting operators (<< and >>) with the number 1, it will result in an int and won't let us exceed 32 bit shifts to the left and thus we need to use the literal LL to the right of 1 in order to specify that the number 1 should be a long long int not a normal int and thus the number resulting from the bit-shifting operation will also be a long long int and thus it will allow us to cover all 64 bits as needed.
