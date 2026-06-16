# 1274. Number of Ships in a Rectangle

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/number-of-ships-in-a-rectangle/)  
`Array` `Divide and Conquer` `Interactive`

**Problem Link:** [LeetCode 1274 - Number of Ships in a Rectangle](https://leetcode.com/problems/number-of-ships-in-a-rectangle/)

## Problem

(This problem is an interactive problem.)

Each ship is located at an integer point on the sea represented by a cartesian plane, and each integer point may contain at most 1 ship.

You have a function Sea.hasShips(topRight, bottomLeft) which takes two points as arguments and returns true If there is at least one ship in the rectangle represented by the two points, including on the boundary.

Given two points: the top right and bottom left corners of a rectangle, return the number of ships present in that rectangle. It is guaranteed that there are at most 10 ships in that rectangle.

Submissions making more than 400 calls to hasShips will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

Example :

```text
Input:
ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
Output: 3
Explanation: From [0,0] to [4,4] we can count 3 ships within the range.
```

### Example 2

```text
Input: ans = [[1,1],[2,2],[3,3]], topRight = [1000,1000], bottomLeft = [0,0]
Output: 3
```

## Constraints

- On the input ships is only given to initialize the map internally. You must solve this problem "blindfolded". In other words, you must find the answer using the given hasShips API, without knowing the ships position.
- 0 <= bottomLeft[0] <= topRight[0] <= 1000
- 0 <= bottomLeft[1] <= topRight[1] <= 1000
- topRight != bottomLeft

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1274. Number of Ships in a Rectangle

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Divide And Conquer | C++, Java, Python3 |

## Approach 1: Divide And Conquer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        // If the current rectangle does not contain any ships, return 0.         
        if (bottomLeft[0] > topRight[0] || bottomLeft[1] > topRight[1])
            return 0;
        if (!sea.hasShips(topRight, bottomLeft))
            return 0;

        // If the rectangle represents a single point, a ship is located
        if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1])
            return 1;

        // Recursively check each of the 4 sub-rectangles for ships
        int midX = (topRight[0] + bottomLeft[0]) / 2;
        int midY = (topRight[1] + bottomLeft[1]) / 2;
        return countShips(sea, {midX, midY}, bottomLeft) +
               countShips(sea, topRight, {midX + 1, midY + 1}) +
               countShips(sea, {midX, topRight[1]}, {bottomLeft[0], midY + 1}) +
               countShips(sea, {topRight[0], midY}, {midX + 1, bottomLeft[1]});
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countShips(Sea sea, int[] topRight, int[] bottomLeft) {
        // If the current rectangle does not contain any ships, return 0.         
        if (bottomLeft[0] > topRight[0] || bottomLeft[1] > topRight[1])
            return 0;
        if (!sea.hasShips(topRight, bottomLeft))
            return 0;

        // If the rectangle represents a single point, a ship is located
        if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1])
            return 1;

        // Recursively check each of the 4 sub-rectangles for ships
        int midX = (topRight[0] + bottomLeft[0]) / 2;
        int midY = (topRight[1] + bottomLeft[1]) / 2;
        return countShips(sea, new int[]{midX, midY}, bottomLeft) +
               countShips(sea, topRight, new int[]{midX + 1, midY + 1}) +
               countShips(sea, new int[]{midX, topRight[1]}, new int[]{bottomLeft[0], midY + 1}) +
               countShips(sea, new int[]{topRight[0], midY}, new int[]{midX + 1, bottomLeft[1]});
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point') -> int:
        # If the current rectangle does not contain any ships, return 0.         
        if (bottomLeft.x > topRight.x) or (bottomLeft.y > topRight.y):
            return 0
        if not sea.hasShips(topRight, bottomLeft):
            return 0

        # If the rectangle represents a single point, a ship is located.
        if (topRight.x == bottomLeft.x) and (topRight.y == bottomLeft.y):
            return 1

        # Recursively check each of the 4 sub-rectangles for ships.
        mid_x = (topRight.x + bottomLeft.x) // 2
        mid_y = (topRight.y + bottomLeft.y) // 2
        return self.countShips(sea, Point(mid_x, mid_y), bottomLeft) + \
               self.countShips(sea, topRight, Point(mid_x + 1, mid_y + 1)) + \
               self.countShips(sea, Point(mid_x, topRight.y), Point(bottomLeft.x, mid_y + 1)) + \
               self.countShips(sea, Point(topRight.x, mid_y), Point(mid_x + 1, bottomLeft.y))
```

</details>
