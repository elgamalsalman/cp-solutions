**Code:** [0126B.cpp](./1269B.cpp)

# Explanation

**Time Complexity:** O(n)

**Memory Complexity:** O(n) 

Where n is the length of the string s.

**Category:** String Processing

### General Comments

This problem can be solved in multiple ways, one of which is using the KMP preprocess algorithm for finding the longest prefix which is also a suffix up until every character in O(n).

Watch out for cases like fixafixafix, where the longest prefix of the entire string which is also a suffix itself has a prefix which is also a suffix.
