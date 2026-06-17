# 2087. Minimum Cost Homecoming of a Robot in a Grid

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)  
`Array` `Greedy`

**Problem Link:** [LeetCode 2087 - Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)

## Problem

There is an m x n grid, where (0, 0) is the top-left cell and (m - 1, n - 1) is the bottom-right cell. You are given an integer array startPos where startPos = [startrow, startcol] indicates that initially, a robot is at the cell (startrow, startcol). You are also given an integer array homePos where homePos = [homerow, homecol] indicates that its home is at the cell (homerow, homecol).

The robot needs to go to its home. It can move one cell in four directions: left, right, up, or down, and it can not move outside the boundary. Every move incurs some cost. You are further given two 0-indexed integer arrays: rowCosts of length m and colCosts of length n.

- If the robot moves up or down into a cell whose row is r, then this move costs rowCosts[r].
- If the robot moves left or right into a cell whose column is c, then this move costs colCosts[c].

Return the minimum total cost for this robot to return home.

### Example 1

```text
Input: startPos = [1, 0], homePos = [2, 3], rowCosts = [5, 4, 3], colCosts = [8, 2, 6, 7]
Output: 18
Explanation: One optimal path is that:
Starting from (1, 0)
-> It goes down to (2, 0). This move costs rowCosts[2] = 3.
-> It goes right to (2, 1). This move costs colCosts[1] = 2.
-> It goes right to (2, 2). This move costs colCosts[2] = 6.
-> It goes right to (2, 3). This move costs colCosts[3] = 7.
The total cost is 3 + 2 + 6 + 7 = 18
```

### Example 2

```text
Input: startPos = [0, 0], homePos = [0, 0], rowCosts = [5], colCosts = [26]
Output: 0
Explanation: The robot is already at its home. Since no moves occur, the total cost is 0.
```

## Constraints

- m == rowCosts.length
- n == colCosts.length
- 1 <= m, n <= 105
- 0 <= rowCosts[r], colCosts[c] <= 104
- startPos.length == 2
- homePos.length == 2
- 0 <= startrow, homerow < m
- 0 <= startcol, homecol < n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Unique Paths](https://leetcode.com/problems/unique-paths/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Bomb Enemy](https://leetcode.com/problems/bomb-enemy/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Paths in Matrix Whose Sum Is Divisible by K](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Check if There is a Path With Equal Number of 0's And 1's](https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2087. Minimum Cost Homecoming of a Robot in a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minCost(int* startPos, int startPosSize, int* homePos, int homePosSize,
            int* rowCosts, int rowCostsSize, int* colCosts, int colCostsSize) {
    int r1 = startPos[0], c1 = startPos[1];
    int r2 = homePos[0], c2 = homePos[1];
    int res = 0;  // total cost

    // move to the row where the home is located, determine the direction of
    // movement between rows, and calculate the corresponding cost
    if (r2 >= r1) {
        for (int i = r1 + 1; i <= r2; i++) {
            res += rowCosts[i];
        }
    } else {
        for (int i = r2; i < r1; i++) {
            res += rowCosts[i];
        }
    }

    // move to the location of the house, determine the direction of movement
    // between columns, and calculate the corresponding cost
    if (c2 >= c1) {
        for (int i = c1 + 1; i <= c2; i++) {
            res += colCosts[i];
        }
    } else {
        for (int i = c2; i < c1; i++) {
            res += colCosts[i];
        }
    }

    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int r1 = startPos[0], c1 = startPos[1];
        int r2 = homePos[0], c2 = homePos[1];
        int res = 0;  // total cost
        // move to the row where the home is located, determine the direction of
        // movement between rows, and calculate the corresponding cost
        if (r2 >= r1) {
            res += accumulate(rowCosts.begin() + r1 + 1,
                              rowCosts.begin() + r2 + 1, 0);
        } else {
            res += accumulate(rowCosts.begin() + r2, rowCosts.begin() + r1, 0);
        }
        // move to the location of the house, determine the direction of
        // movement between columns, and calculate the corresponding cost
        if (c2 >= c1) {
            res += accumulate(colCosts.begin() + c1 + 1,
                              colCosts.begin() + c2 + 1, 0);
        } else {
            res += accumulate(colCosts.begin() + c2, colCosts.begin() + c1, 0);
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinCost(int[] startPos, int[] homePos, int[] rowCosts,
                       int[] colCosts) {
        int r1 = startPos[0], c1 = startPos[1];
        int r2 = homePos[0], c2 = homePos[1];
        int res = 0;  // total cost

        // move to the row where the home is located, determine the direction of
        // movement between rows, and calculate the corresponding cost
        if (r2 >= r1) {
            for (int i = r1 + 1; i <= r2; i++) {
                res += rowCosts[i];
            }
        } else {
            for (int i = r2; i < r1; i++) {
                res += rowCosts[i];
            }
        }

        // move to the location of the house, determine the direction of
        // movement between columns, and calculate the corresponding cost
        if (c2 >= c1) {
            for (int i = c1 + 1; i <= c2; i++) {
                res += colCosts[i];
            }
        } else {
            for (int i = c2; i < c1; i++) {
                res += colCosts[i];
            }
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minCost(startPos []int, homePos []int, rowCosts []int, colCosts []int) int {
    r1, c1 := startPos[0], startPos[1]
    r2, c2 := homePos[0], homePos[1]
    res := 0 // total cost
    
    // move to the row where the home is located, determine the direction of movement between rows, and calculate the corresponding cost
    if r2 >= r1 {
        for i := r1 + 1; i <= r2; i++ {
            res += rowCosts[i]
        }
    } else {
        for i := r2; i < r1; i++ {
            res += rowCosts[i]
        }
    }
    
    // move to the location of the house, determine the direction of movement between columns, and calculate the corresponding cost
    if c2 >= c1 {
        for i := c1 + 1; i <= c2; i++ {
            res += colCosts[i]
        }
    } else {
        for i := c2; i < c1; i++ {
            res += colCosts[i]
        }
    }
    
    return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minCost(
        int[] startPos,
        int[] homePos,
        int[] rowCosts,
        int[] colCosts
    ) {
        int r1 = startPos[0];
        int c1 = startPos[1];
        int r2 = homePos[0];
        int c2 = homePos[1];
        int res = 0; // total cost

        // move to the row where the home is located, determine the direction of movement between rows, and calculate the corresponding cost
        if (r2 >= r1) {
            for (int i = r1 + 1; i <= r2; i++) {
                res += rowCosts[i];
            }
        } else {
            for (int i = r2; i < r1; i++) {
                res += rowCosts[i];
            }
        }

        // move to the location of the house, determine the direction of movement between columns, and calculate the corresponding cost
        if (c2 >= c1) {
            for (int i = c1 + 1; i <= c2; i++) {
                res += colCosts[i];
            }
        } else {
            for (int i = c2; i < c1; i++) {
                res += colCosts[i];
            }
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minCost = function (startPos, homePos, rowCosts, colCosts) {
    const r1 = startPos[0],
        c1 = startPos[1];
    const r2 = homePos[0],
        c2 = homePos[1];
    let res = 0; // total cost

    // move to the row where the home is located, determine the direction of movement between rows, and calculate the corresponding cost
    if (r2 >= r1) {
        for (let i = r1 + 1; i <= r2; i++) {
            res += rowCosts[i];
        }
    } else {
        for (let i = r2; i < r1; i++) {
            res += rowCosts[i];
        }
    }

    // move to the location of the house, determine the direction of movement between columns, and calculate the corresponding cost
    if (c2 >= c1) {
        for (let i = c1 + 1; i <= c2; i++) {
            res += colCosts[i];
        }
    } else {
        for (let i = c2; i < c1; i++) {
            res += colCosts[i];
        }
    }

    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(
        self,
        startPos: List[int],
        homePos: List[int],
        rowCosts: List[int],
        colCosts: List[int],
    ) -> int:
        r1, c1 = startPos[0], startPos[1]
        r2, c2 = homePos[0], homePos[1]
        res = 0  # total cost
        # move to the row where the home is located, determine the direction of movement between rows, and calculate the corresponding cost
        if r2 >= r1:
            for i in range(r1 + 1, r2 + 1):
                res += rowCosts[i]
        else:
            for i in range(r2, r1):
                res += rowCosts[i]
        # move to the location of the house, determine the direction of movement between columns, and calculate the corresponding cost
        if c2 >= c1:
            for i in range(c1 + 1, c2 + 1):
                res += colCosts[i]
        else:
            for i in range(c2, c1):
                res += colCosts[i]
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minCost(
    startPos: number[],
    homePos: number[],
    rowCosts: number[],
    colCosts: number[],
): number {
    const r1 = startPos[0],
        c1 = startPos[1];
    const r2 = homePos[0],
        c2 = homePos[1];
    let res = 0; // total cost

    // move to the row where the home is located, determine the direction of movement between rows, and calculate the corresponding cost
    if (r2 >= r1) {
        for (let i = r1 + 1; i <= r2; i++) {
            res += rowCosts[i];
        }
    } else {
        for (let i = r2; i < r1; i++) {
            res += rowCosts[i];
        }
    }

    // move to the location of the house, determine the direction of movement between columns, and calculate the corresponding cost
    if (c2 >= c1) {
        for (let i = c1 + 1; i <= c2; i++) {
            res += colCosts[i];
        }
    } else {
        for (let i = c2; i < c1; i++) {
            res += colCosts[i];
        }
    }

    return res;
}
```

</details>
