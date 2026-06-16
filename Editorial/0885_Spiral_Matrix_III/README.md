# 885. Spiral Matrix III

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/spiral-matrix-iii/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 885 - Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii/)

## Problem

You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

### Example 1

```text
Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
```

### Example 2

```text
Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
```

## Constraints

- 1 <= rows, cols <= 100
- 0 <= rStart < rows
- 0 <= cStart < cols

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Spiral Matrix IV](https://leetcode.com/problems/spiral-matrix-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 885. Spiral Matrix III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C++, Java, Python3 |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        // Store all possible directions in an array.
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> traversed;

        // Initial step size is 1, value of d represents the current direction.
        for (int step = 1, direction = 0; traversed.size() < rows * cols;) {
            // direction = 0 -> East, direction = 1 -> South
            // direction = 2 -> West, direction = 3 -> North
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < step; ++j) {
                    // Validate the current position
                    if (rStart >= 0 && rStart < rows && cStart >= 0 &&
                        cStart < cols) {
                        traversed.push_back({rStart, cStart});
                    }
                    // Make changes to the current position.
                    rStart += dir[direction][0];
                    cStart += dir[direction][1];
                }

                direction = (direction + 1) % 4;
            }
            ++step;
        }
        return traversed;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // Store all possible directions in an array.
        int[][] dir = new int[][] { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int[][] traversed = new int[rows * cols][2];
        int idx = 0;

        // Initial step size is 1, value of d represents the current direction.
        for (int step = 1, direction = 0; idx < rows * cols;) {
            // direction = 0 -> East, direction = 1 -> South
            // direction = 2 -> West, direction = 3 -> North
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < step; ++j) {
                    // Validate the current position
                    if (
                        rStart >= 0 &&
                        rStart < rows &&
                        cStart >= 0 &&
                        cStart < cols
                    ) {
                        traversed[idx][0] = rStart;
                        traversed[idx][1] = cStart;
                        ++idx;
                    }
                    // Make changes to the current position.
                    rStart += dir[direction][0];
                    cStart += dir[direction][1];
                }

                direction = (direction + 1) % 4;
            }
            ++step;
        }
        return traversed;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def spiralMatrixIII(
        self, rows: int, cols: int, rStart: int, cStart: int
    ) -> List[List[int]]:
        # Store all possible directions in an array.
        dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        traversed = []

        # Initial step size is 1, value of d represents the current direction.
        step = 1
        direction = 0
        while len(traversed) < rows * cols:
            # direction = 0 -> East, direction = 1 -> South
            # direction = 2 -> West, direction = 3 -> North
            for _ in range(2):
                for _ in range(step):
                    # Validate the current position
                    if (
                        rStart >= 0
                        and rStart < rows
                        and cStart >= 0
                        and cStart < cols
                    ):
                        traversed.append([rStart, cStart])
                    # Make changes to the current position.
                    rStart += dir[direction][0]
                    cStart += dir[direction][1]

                direction = (direction + 1) % 4
            step += 1
        return traversed
```

</details>
