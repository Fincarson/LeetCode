# 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1465 - Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/)

## Problem

You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

- horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
- verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.

### Example 1

```text
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
```

### Example 2

```text
Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
```

### Example 3

```text
Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9
```

## Constraints

- 2 <= h, w <= 109
- 1 <= horizontalCuts.length <= min(h - 1, 105)
- 1 <= verticalCuts.length <= min(w - 1, 105)
- 1 <= horizontalCuts[i] < h
- 1 <= verticalCuts[i] < w
- All the elements in horizontalCuts are distinct.
- All the elements in verticalCuts are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sort | Java, Python3 |

## Approach: Sort

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // We will use long instead of int to prevent overflow
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        // Start by sorting the inputs
        Arrays.sort(horizontalCuts);
        Arrays.sort(verticalCuts);
        int n = horizontalCuts.length;
        int m = verticalCuts.length;
        
        // Consider the edges first
        long maxHeight = Math.max(horizontalCuts[0], h - horizontalCuts[n - 1]);
        for (int i = 1; i < n; i++) {
            // horizontalCuts[i] - horizontalCuts[i - 1] represents the distance between
            // two adjacent edges, and thus a possible height
            maxHeight = Math.max(maxHeight, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        
        // Consider the edges first
        long maxWidth = Math.max(verticalCuts[0], w - verticalCuts[m - 1]);
        for (int i = 1; i < m; i++){
            // verticalCuts[i] - verticalCuts[i - 1] represents the distance between
            // two adjacent edges, and thus a possible width
            maxWidth = Math.max(maxWidth, verticalCuts[i] - verticalCuts[i - 1]);
        }

        // Be careful of overflow, and don't forget the modulo!
        return (int) ((maxWidth * maxHeight) % (1000000007));
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        # Start by sorting the inputs
        horizontalCuts.sort()
        verticalCuts.sort()
        
        # Consider the edges first
        max_height = max(horizontalCuts[0], h - horizontalCuts[-1])
        for i in range(1, len(horizontalCuts)):
            # horizontalCuts[i] - horizontalCuts[i - 1] represents the distance between
            # two adjacent edges, and thus a possible height
            max_height = max(max_height, horizontalCuts[i] - horizontalCuts[i - 1])
        
        # Consider the edges first
        max_width = max(verticalCuts[0], w - verticalCuts[-1])
        for i in range(1, len(verticalCuts)):
            # verticalCuts[i] - verticalCuts[i - 1] represents the distance between
            # two adjacent edges, and thus a possible width
            max_width = max(max_width, verticalCuts[i] - verticalCuts[i - 1])
        
        # Python doesn't need to worry about overflow - don't forget the modulo though!
        return (max_height * max_width) % (10**9 + 7)
```

</details>
