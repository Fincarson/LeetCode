# 1637. Widest Vertical Area Between Two Points Containing No Points

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 1637 - Widest Vertical Area Between Two Points Containing No Points](https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/)

## Problem

Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.

### Example 1

```text
Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.
```

### Example 2

```text
Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
Output: 3
```

## Constraints

- n == points.length
- 2 <= n <= 105
- points[i].length == 2
- 0 <= xi, yi <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Gap](https://leetcode.com/problems/maximum-gap/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Consecutive Floors Without Special Floors](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1637. Widest Vertical Area Between Two Points Containing No Points

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting | C++, Java |

## Approach: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int ans = 0;
        for (int i = 1; i < points.size(); i++) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        
        int ans = 0;
        for (int i = 1; i < points.length; i++) {
            ans = Math.max(ans, points[i][0] - points[i - 1][0]);
        }
        
        return ans;
    }
}
```

</details>
