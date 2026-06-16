# 1232. Check If It Is a Straight Line

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/check-if-it-is-a-straight-line/)  
`Array` `Math` `Geometry`

**Problem Link:** [LeetCode 1232 - Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/)

## Problem

You are given an integer array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

### Example 1

```text
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
```

### Example 2

```text
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
```

## Constraints

- 2 <= coordinates.length <= 1000
- coordinates[i].length == 2
- -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
- coordinates contains no duplicate point.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1232. Check If It Is a Straight Line

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Slope Property | C++, Java |

## Approach: Slope Property

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Returns the delta Y.
    int getYDiff(vector<int>& a, vector<int>& b) {
        return a[1] - b[1];
    }
    
    // Returns the delta X.
    int getXDiff(vector<int>& a, vector<int>& b) {
        return a[0] - b[0];
    }
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int deltaY = getYDiff(coordinates[1], coordinates[0]);
        int deltaX = getXDiff(coordinates[1], coordinates[0]);
        
        for (int i = 2; i < coordinates.size(); i++) {
            // Check if the slope between points 0 and i, is the same as between 0 and 1.
            if (deltaY * getXDiff(coordinates[i], coordinates[0])
                != deltaX * getYDiff(coordinates[i], coordinates[0])) {
                return false;
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns the delta Y.
    int getYDiff(int[] a, int[] b) {
        return a[1] - b[1];
    }
    
    // Returns the delta X.
    int getXDiff(int[] a, int[] b) {
        return a[0] - b[0];
    }
    
    public boolean checkStraightLine(int[][] coordinates) {
        int deltaY = getYDiff(coordinates[1], coordinates[0]);
        int deltaX = getXDiff(coordinates[1], coordinates[0]);
        
        for (int i = 2; i < coordinates.length; i++) {
            // Check if the slope between points 0 and i, is the same as between 0 and 1.
            if (deltaY * getXDiff(coordinates[i], coordinates[0])
                != deltaX * getYDiff(coordinates[i], coordinates[0])) {
                return false;
            }
        }
        return true;
    }
}
```

</details>
