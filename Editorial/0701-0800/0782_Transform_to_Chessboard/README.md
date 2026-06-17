# 782. Transform to Chessboard

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/transform-to-chessboard/)  
`Array` `Math` `Bit Manipulation` `Matrix`

**Problem Link:** [LeetCode 782 - Transform to Chessboard](https://leetcode.com/problems/transform-to-chessboard/)

## Problem

You are given an n x n binary grid board. In each move, you can swap any two rows with each other, or any two columns with each other.

Return the minimum number of moves to transform the board into a chessboard board. If the task is impossible, return -1.

A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.

### Example 1

```text
Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
Output: 2
Explanation: One potential sequence of moves is shown.
The first move swaps the first and second column.
The second move swaps the second and third row.
```

### Example 2

```text
Input: board = [[0,1],[1,0]]
Output: 0
Explanation: Also note that the board with 0 in the top left corner, is also a valid chessboard.
```

### Example 3

```text
Input: board = [[1,0],[1,0]]
Output: -1
Explanation: No matter what sequence of moves you make, you cannot end with a valid chessboard.
```

## Constraints

- n == board.length
- n == board[i].length
- 2 <= n <= 30
- board[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Moves to Get a Peaceful Board](https://leetcode.com/problems/minimum-moves-to-get-a-peaceful-board/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 782. Transform to Chessboard

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Dimension Independence [Accepted] | Java, Python |

## Approach #1: Dimension Independence [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int movesToChessboard(int[][] board) {
        int N = board.length;

        // count[code] = v, where code is an integer
        // that represents the row in binary, and v
        // is the number of occurrences of that row
        Map<Integer, Integer> count = new HashMap();
        for (int[] row: board) {
            int code = 0;
            for (int x: row)
                code = 2 * code + x;
            count.put(code, count.getOrDefault(code, 0) + 1);
        }

        int k1 = analyzeCount(count, N);
        if (k1 == -1) return -1;

        // count[code], as before except with columns
        count = new HashMap();
        for (int c = 0; c < N; ++c) {
            int code = 0;
            for (int r = 0; r < N; ++r)
                code = 2 * code + board[r][c];
            count.put(code, count.getOrDefault(code, 0) + 1);
        }

        int k2 = analyzeCount(count, N);
        return k2 >= 0 ? k1 + k2 : -1;
    }

    public int analyzeCount(Map<Integer, Integer> count, int N) {
        // Return -1 if count is invalid
        // Otherwise, return number of swaps required
        if (count.size() != 2) return -1;

        List<Integer> keys = new ArrayList(count.keySet());
        int k1 = keys.get(0), k2 = keys.get(1);

        // If lines aren't in the right quantity
        if (!(count.get(k1) == N/2 && count.get(k2) == (N+1)/2) &&
                !(count.get(k2) == N/2 && count.get(k1) == (N+1)/2))
            return -1;
        // If lines aren't opposite
        if ((k1 ^ k2) != (1<<N) - 1)
            return -1;

        int Nones = (1 << N) - 1;
        int ones = Integer.bitCount(k1 & Nones);
        int cand = Integer.MAX_VALUE;
        if (N%2 == 0 || ones * 2 < N) // zero start
            cand = Math.min(cand, Integer.bitCount(k1 ^ 0xAAAAAAAA & Nones) / 2);

        if (N%2 == 0 || ones * 2 > N) // ones start
            cand = Math.min(cand, Integer.bitCount(k1 ^ 0x55555555 & Nones) / 2);

        return cand;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def movesToChessboard(self, board):
        N = len(board)
        ans = 0
        # For each count of lines from {rows, columns}...
        for count in (collections.Counter(map(tuple, board)),
                      collections.Counter(zip(*board))):

            # If there are more than 2 kinds of lines,
            # or if the number of kinds is not appropriate ...
            if len(count) != 2 or sorted(count.values()) != [N/2, (N+1)/2]:
                return -1

            # If the lines are not opposite each other, impossible
            line1, line2 = count
            if not all(x ^ y for x, y in zip(line1, line2)):
                return -1

            # starts = what could be the starting value of line1
            # If N is odd, then we have to start with the more
            # frequent element
            starts = [+(line1.count(1) * 2 > N)] if N%2 else [0, 1]

            # To transform line1 into the ideal line [i%2 for i ...],
            # we take the number of differences and divide by two
            ans += min(sum((i-x) % 2 for i, x in enumerate(line1, start))
                       for start in starts) / 2

        return ans
```

</details>
