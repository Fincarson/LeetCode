# 3189. Minimum Moves to Get a Peaceful Board

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-moves-to-get-a-peaceful-board/)  
`Array` `Greedy` `Sorting` `Counting Sort`

**Problem Link:** [LeetCode 3189 - Minimum Moves to Get a Peaceful Board](https://leetcode.com/problems/minimum-moves-to-get-a-peaceful-board/)

## Problem

Given a 2D array rooks of length n, where rooks[i] = [xi, yi] indicates the position of a rook on an n x n chess board. Your task is to move the rooks 1 cell at a time vertically or horizontally (to an adjacent cell) such that the board becomes peaceful.

A board is peaceful if there is exactly one rook in each row and each column.

Return the minimum number of moves required to get a peaceful board.

Note that at no point can there be two rooks in the same cell.

### Example 1

### Example 2

## Constraints

- 1 <= n == rooks.length <= 500
- 0 <= xi, yi <= n - 1
- The input is generated such that there are no 2 rooks in the same cell.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Transform to Chessboard](https://leetcode.com/problems/transform-to-chessboard/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3189. Minimum Moves to Get a Peaceful Board

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, Python3 |
| Counting Sort | C++, Java, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Return true if in arrangement (a, b), b has a higher column number.
    static bool compare(vector<int>& a, vector<int>& b) {
        return b[1] - a[1] > 0;
    }

    int minMoves(vector<vector<int>>& rooks) {
        int minMoves = 0;

        // Moves required to place rooks in each row.
        sort(rooks.begin(), rooks.end());
        for (int i = 0; i < rooks.size(); i++) {
            minMoves += abs(i - rooks[i][0]);
        }

        // Moves required to place rooks in each column.
        sort(rooks.begin(), rooks.end(), compare);
        for (int i = 0; i < rooks.size(); i++) {
            minMoves += abs(i - rooks[i][1]);
        }

        return minMoves;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minMoves(int[][] rooks) {
        int minMoves = 0;

        Arrays.sort(rooks, (a, b) -> a[0] - b[0]);
        // Moves required to place rooks in each row
        for (int i = 0; i < rooks.length; i++) {
            minMoves += Math.abs(i - rooks[i][0]);
        }

        Arrays.sort(rooks, (a, b) -> a[1] - b[1]);
        // Moves required to place rooks in each column
        for (int i = 0; i < rooks.length; i++) {
            minMoves += Math.abs(i - rooks[i][1]);
        }

        return minMoves;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMoves(self, rooks):
        min_moves = 0

        rooks.sort(key=lambda x: x[0])
        # Moves required to place rooks in each row
        for i in range(len(rooks)):
            min_moves += abs(i - rooks[i][0])

        rooks.sort(key=lambda x: x[1])
        # Moves required to place rooks in each column
        for i in range(len(rooks)):
            min_moves += abs(i - rooks[i][1])

        return min_moves
```

</details>

<br>

## Approach 2: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int minMoves = 0;

        // Store the count of rooks in each row and column.
        vector<int> row(rooks.size(), 0);
        vector<int> col(rooks.size(), 0);
        for (int i = 0; i < rooks.size(); i++) {
            row[rooks[i][0]]++;
            col[rooks[i][1]]++;
        }

        int rowMinMoves = 0, colMinMoves = 0;
        for (int i = 0; i < rooks.size(); i++) {
            // Difference between the rooks count at row and column and one.
            rowMinMoves += row[i] - 1;
            colMinMoves += col[i] - 1;

            // Moves required for row and column constraints.
            minMoves += abs(rowMinMoves) + abs(colMinMoves);
        }

        return minMoves;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minMoves(int[][] rooks) {
        int minMoves = 0;

        // Store the count of rooks in each row and column.
        int[] row = new int[rooks.length];
        int[] col = new int[rooks.length];
        for (int i = 0; i < rooks.length; i++) {
            row[rooks[i][0]]++;
            col[rooks[i][1]]++;
        }

        int rowMinMoves = 0, colMinMoves = 0;
        for (int i = 0; i < rooks.length; i++) {
            // Difference between the rooks count at row and column and one.
            rowMinMoves += row[i] - 1;
            colMinMoves += col[i] - 1;

            // Moves required for row and column constraints.
            minMoves += Math.abs(rowMinMoves) + Math.abs(colMinMoves);
        }

        return minMoves;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMoves(self, rooks):
        min_moves = 0

        # Store the count of rooks in each row and column.
        row = [0] * len(rooks)
        col = [0] * len(rooks)
        for r in rooks:
            row[r[0]] += 1
            col[r[1]] += 1

        row_min_moves = 0
        col_min_moves = 0
        for i in range(len(rooks)):
            # Difference between the rooks count at row and column and one.
            row_min_moves += row[i] - 1
            col_min_moves += col[i] - 1

            # Moves required for row and column constraints.
            min_moves += abs(row_min_moves) + abs(col_min_moves)

        return min_moves
```

</details>
