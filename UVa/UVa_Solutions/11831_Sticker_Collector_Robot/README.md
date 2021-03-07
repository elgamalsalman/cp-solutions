**Code:** [11831.cpp](./11831.cpp)

# Explanation

**Category:** Graph Theory

**Time Complexity:** O(NM + S)

**Memory Complexity:** O(NM)

### General Comments

This is an implicit graph problem, it is fairly easy and just needs you to simulate the process.

### Explanation

The code is pretty straight forward, one trick I have used is the use of the arrays dy and dx to specify the movement in the y and x directions if the robot moved forward at a certain direction, the direction is the index and I have coded north to be 0, east is 1, south 2, west 3.

Also, after decreasing or increasing the variable dir (which holds the current direction of the robot) according to whether the instruction is an E or D, in line 44 I have added 4 and then performed a modulo 4 operation on dir, this is to map -1 to 3 and 4 to 0 to allow for full rotations.
