# 3394. Check if Grid can be Cut into Sections

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 3394 - Check if Grid can be Cut into Sections](https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/)

## Problem

You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

- (startx, starty): The bottom-left corner of the rectangle.
- (endx, endy): The top-right corner of the rectangle.

Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

- Each of the three resulting sections formed by the cuts contains at least one rectangle.
- Every rectangle belongs to exactly one section.

Return true if such cuts can be made; otherwise, return false.

### Example 1

### Example 2

### Example 3

## Constraints

- 3 <= n <= 109
- 3 <= rectangles.length <= 105
- 0 <= rectangles[i][0] < rectangles[i][2] <= n
- 0 <= rectangles[i][1] < rectangles[i][3] <= n
- No two rectangles overlap.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3394. Check if Grid can be Cut into Sections

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Line Sweep | C++, Java, Python3 |

## Approach: Line Sweep

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Try both horizontal and vertical cuts
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }

private:
    // Check if valid cuts can be made in a specific dimension
    bool checkCuts(vector<vector<int>>& rectangles, int dim) {
        int gapCount = 0;

        // Sort rectangles by their starting coordinate in the given dimension
        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
             });

        // Track the furthest ending coordinate seen so far
        int furthestEnd = rectangles[0][dim + 2];

        for (size_t i = 1; i < rectangles.size(); i++) {
            vector<int>& rect = rectangles[i];

            // If current rectangle starts after the furthest end we've seen,
            // we found a gap where a cut can be made
            if (furthestEnd <= rect[dim]) {
                gapCount++;
            }

            // Update the furthest ending coordinate
            furthestEnd = max(furthestEnd, rect[dim + 2]);
        }

        // We need at least 2 gaps to create 3 sections
        return gapCount >= 2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean checkValidCuts(int n, int[][] rectangles) {
        // Try both horizontal and vertical cuts
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }

    // Check if valid cuts can be made in a specific dimension
    private boolean checkCuts(int[][] rectangles, int dim) {
        int gapCount = 0;

        // Sort rectangles by their starting coordinate in the given dimension
        Arrays.sort(rectangles, (a, b) -> Integer.compare(a[dim], b[dim]));

        // Track the furthest ending coordinate seen so far
        int furthestEnd = rectangles[0][dim + 2];

        for (int i = 1; i < rectangles.length; i++) {
            int[] rect = rectangles[i];

            // If current rectangle starts after the furthest end we've seen,
            // we found a gap where a cut can be made
            if (furthestEnd <= rect[dim]) {
                gapCount++;
            }

            // Update the furthest ending coordinate
            furthestEnd = Math.max(furthestEnd, rect[dim + 2]);
        }

        // We need at least 2 gaps to create 3 sections
        return gapCount >= 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkValidCuts(self, n: int, rectangles: list[list[int]]) -> bool:
        # Check if valid cuts can be made in a specific dimension
        def _check_cuts(rectangles: list[list[int]], dim: int) -> bool:
            gap_count = 0

            # Sort rectangles by their starting coordinate in the given dimension
            rectangles.sort(key=lambda rect: rect[dim])

            # Track the furthest ending coordinate seen so far
            furthest_end = rectangles[0][dim + 2]

            for i in range(1, len(rectangles)):
                rect = rectangles[i]

                # If current rectangle starts after the furthest end we've seen,
                # we found a gap where a cut can be made
                if furthest_end <= rect[dim]:
                    gap_count += 1

                # Update the furthest ending coordinate
                furthest_end = max(furthest_end, rect[dim + 2])

            # We need at least 2 gaps to create 3 sections
            return gap_count >= 2

        # Try both horizontal and vertical cuts
        return _check_cuts(rectangles, 0) or _check_cuts(rectangles, 1)
```

</details>
