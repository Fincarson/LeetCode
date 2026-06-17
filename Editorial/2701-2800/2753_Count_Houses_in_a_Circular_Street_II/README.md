# 2753. Count Houses in a Circular Street II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/count-houses-in-a-circular-street-ii/)  

**Problem Link:** [LeetCode 2753 - Count Houses in a Circular Street II](https://leetcode.com/problems/count-houses-in-a-circular-street-ii/)

## Problem

You are given an object street of class Street that represents a circular street and a positive integer k which represents a maximum bound for the number of houses in that street (in other words, the number of houses is less than or equal to k). Houses' doors could be open or closed initially (at least one is open).

Initially, you are standing in front of a door to a house on this street. Your task is to count the number of houses in the street.

The class Street contains the following functions which may help you:

- void closeDoor(): Close the door of the house you are in front of.
- boolean isDoorOpen(): Returns true if the door of the current house is open and false otherwise.
- void moveRight(): Move to the right house.

Note that by circular street, we mean if you number the houses from 1 to n, then the right house of housei is housei+1 for i < n, and the right house of housen is house1.

Return ans which represents the number of houses on this street.

### Example 1

```text
Input: street = [1,1,1,1], k = 10
Output: 4
Explanation: There are 4 houses, and all their doors are open.
The number of houses is less than k, which is 10.
```

### Example 2

```text
Input: street = [1,0,1,1,0], k = 5
Output: 5
Explanation: There are 5 houses, and the doors of the 1st, 3rd, and 4th house (moving in the right direction) are open, and the rest are closed.
The number of houses is equal to k, which is 5.
```

## Constraints

- n == number of houses
- 1 <= n <= k <= 105
- street is circular by definition provided in the statement.
- The input is generated such that at least one of the doors is open.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2753. Count Houses in a Circular Street II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Skip the First Open Door | Java, Python3 |

## Approach: Skip the First Open Door

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a street.
 * class Street {
 *     public Street(int[] doors);
 *     public void closeDoor();
 *     public boolean isDoorOpen();
 *     public void moveRight();
 * }
 */
class Solution {
    public int houseCount(Street street, int k) {
        // No. of steps to reach the first open door
        int xFirst = 0;

        // No. of steps from the current open door to the first open door.
        int distFromFirst = 0;

        // No. of steps in our traversal.
        int x = 0;

        // If we have found (and skipped) the first open door
        boolean findFirst = false;

        while (x <= 2 * k) {
            // If the door is open
            if (street.isDoorOpen()) {
                // If we have skipped the first door, update distFromFirst
                // and close the open door.
                if (findFirst) {
                    distFromFirst = x - xFirst;
                    street.closeDoor();
                }
                // Otherwise, we skip this open door and record its index as xFirst = x.
                else {
                    xFirst = x;
                    findFirst = true;
                }
            }

            // Move to the next house on the right, and increase x by 1.
            street.moveRight();
            x++;
        }

        return distFromFirst;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a street.
# class Street:
#     def closeDoor(self):
#         pass
#     def isDoorOpen(self):
#         pass
#     def moveRight(self):
#         pass
class Solution:
    def houseCount(self, street: Optional['Street'], k: int) -> int:
        # No. of steps to reach the first open door
        x_first = 0

        # No. of steps from the current open door to the first open door.
        dist_from_first = 0

        # No. of steps in our traversal.
        x = 0

        # If we have found (and skipped) the first open door
        find_first = False

        while x <= 2 * k:
            # If the door is open
            if street.isDoorOpen(): 
                # If we have skipped the first door, update dist_from_first
                # and close the open door.
                if find_first:
                    dist_from_first = x - x_first
                    street.closeDoor()

                # Otherwise, we skip this open door and record its index as x_first = x.
                else:
                    x_first = x
                    find_first = True

            # Move to the next house on the right, and increase x by 1.
            street.moveRight()
            x += 1
        
        return dist_from_first
```

</details>
