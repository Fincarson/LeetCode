# 723. Candy Crush

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/candy-crush/)  
`Array` `Two Pointers` `Matrix` `Simulation`

**Problem Link:** [LeetCode 723 - Candy Crush](https://leetcode.com/problems/candy-crush/)

## Problem

This question is about implementing a basic elimination algorithm for Candy Crush.

Given an m x n integer array board representing the grid of candy where board[i][j] represents the type of candy. A value of board[i][j] == 0 represents that the cell is empty.

The given board represents the state of the game following the player's move. Now, you need to restore the board to a stable state by crushing candies according to the following rules:

- If three or more candies of the same type are adjacent vertically or horizontally, crush them all at the same time - these positions become empty.
- After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then these candies will drop until they hit a candy or bottom at the same time. No new candies will drop outside the top boundary.
- After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
- If there does not exist more candies that can be crushed (i.e., the board is stable), then return the current board.

You need to perform the above rules until the board becomes stable, then return the stable board.

### Example 1

```text
Input: board = [[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]
Output: [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]
```

### Example 2

```text
Input: board = [[1,3,5,5,2],[3,4,3,3,1],[3,2,4,5,2],[2,4,4,5,5],[1,4,4,1,1]]
Output: [[1,3,0,0,0],[3,4,0,5,2],[3,2,0,3,1],[2,4,0,5,2],[1,4,3,1,1]]
```

## Constraints

- m == board.length
- n == board[i].length
- 3 <= m, n <= 50
- 1 <= board[i][j] <= 2000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 723. Candy Crush

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Separate Steps: Find, Crush, Drop | Java, Python3 |
| In-place Modification | Java, Python3 |

## Approach 1: Separate Steps: Find, Crush, Drop

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int m, n;

    Set<Pair<Integer, Integer>> find(int[][] board) {
        Set<Pair<Integer, Integer>> crushedSet = new HashSet<>();

        // Check vertically adjacent candies
        for (int r = 1; r < m - 1; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 0) {
                    continue;
                }
                if (board[r][c] == board[r - 1][c] && board[r][c] == board[r + 1][c]) {
                    crushedSet.add(new Pair<>(r, c));
                    crushedSet.add(new Pair<>(r - 1, c));
                    crushedSet.add(new Pair<>(r + 1, c));
                }
            }
        }

        // Check horizontally adjacent candies
        for (int r = 0; r < m; r++) {
            for (int c = 1; c < n - 1; c++) {
                if (board[r][c] == 0) {
                    continue;
                }
                if (board[r][c] == board[r][c - 1] && board[r][c] == board[r][c + 1]) {
                    crushedSet.add(new Pair<>(r, c));
                    crushedSet.add(new Pair<>(r, c - 1));
                    crushedSet.add(new Pair<>(r, c + 1));
                }
            }
        }
        return crushedSet;
    }

    void crush(int[][] board, Set<Pair<Integer, Integer>> crushedSet) {
        for (Pair<Integer, Integer> pair : crushedSet) {
            int r = pair.getKey();
            int c = pair.getValue();
            board[r][c] = 0;
        }
    }

    void drop(int[][] board) {
        for (int c = 0; c < n; c++) {
            int lowestZero = -1;

            // Iterate over each column
            for (int r = m - 1; r >= 0; r--) {
                if (board[r][c] == 0) {
                    lowestZero = Math.max(lowestZero, r);
                } else if (lowestZero >= 0) {
                    int temp = board[r][c];
                    board[r][c] = board[lowestZero][c];
                    board[lowestZero][c] = temp;
                    lowestZero--;
                }
            }
        }
    }

    public int[][] candyCrush(int[][] board) {
        m = board.length;
        n = board[0].length;
        Set<Pair<Integer, Integer>> crushedSet = find(board);
        while (!crushedSet.isEmpty()) {
            crush(board, crushedSet);
            drop(board);
            crushedSet = find(board);
        }

        return board;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def candyCrush(self, board: List[List[int]]) -> List[List[int]]:
        m, n = len(board), len(board[0])

        def find():
            crushed_set = set()

            # Check vertically adjacent candies 
            for r in range(1, m - 1):
                for c in range(n):
                    if board[r][c] == 0:
                        continue
                    if board[r][c] == board[r - 1][c] == board[r + 1][c]: 
                        crushed_set.add((r, c))
                        crushed_set.add((r - 1, c))
                        crushed_set.add((r + 1, c))

            # Check horizontally adjacent candies 
            for r in range(m):
                for c in range(1, n - 1):
                    if board[r][c] == 0:
                        continue
                    if board[r][c] == board[r][c - 1] == board[r][c + 1]:
                        crushed_set.add((r, c))
                        crushed_set.add((r, c - 1))
                        crushed_set.add((r, c + 1))
            return crushed_set
        
        # Set the value of each candies to be crushed as 0
        def crush(crushed_set):
            for (r, c) in crushed_set:
                board[r][c] = 0
        
        def drop():
            for c in range(n):
                lowest_zero = -1

                # Iterate over each column
                for r in range(m - 1, -1, -1):
                    if board[r][c] == 0:
                        lowest_zero = max(lowest_zero, r)

                    # Swap current non-zero candy with the lowest zero.
                    elif lowest_zero >= 0:
                        board[r][c], board[lowest_zero][c] = board[lowest_zero][c], board[r][c]
                        lowest_zero -= 1

        # Continue with the three steps until we can no longer find any crushable candies.
        crushed_set = find()
        while crushed_set:
            crush(crushed_set)
            drop()
            crushed_set = find()

        return board
```

</details>

<br>

## Approach 2: In-place Modification

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int m, n;
    boolean findAndCrush(int[][] board) {
        boolean complete = true;

        // Check vertically adjacent candies
        for (int r = 1; r < m - 1; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 0) {
                    continue;
                }
                if (Math.abs(board[r][c]) == Math.abs(board[r - 1][c]) && Math.abs(board[r][c]) == Math.abs(board[r + 1][c])) {
                    board[r][c] = -Math.abs(board[r][c]);
                    board[r - 1][c] = -Math.abs(board[r - 1][c]);
                    board[r + 1][c] = -Math.abs(board[r + 1][c]);
                    complete = false;
                }
            }
        }

        // Check horizontally adjacent candies
        for (int r = 0; r < m; r++) {
            for (int c = 1; c < n - 1; c++) {
                if (board[r][c] == 0) {
                    continue;
                }
                if (Math.abs(board[r][c]) == Math.abs(board[r][c - 1]) && Math.abs(board[r][c]) == Math.abs(board[r][c + 1])) {
                    board[r][c] = -Math.abs(board[r][c]);
                    board[r][c - 1] = -Math.abs(board[r][c - 1]);
                    board[r][c + 1] = -Math.abs(board[r][c + 1]);
                    complete = false;
                }
            }
        }

        // Set the value of each candy to be crushed as 0
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] < 0) {
                    board[r][c] = 0;
                }
            }
        }

        return complete;
    }

    void drop(int[][] board) {
        for (int c = 0; c < n; c++) {
            int lowestZero = -1;

            // Iterate over each column
            for (int r = m - 1; r >= 0; r--) {
                if (board[r][c] == 0) {
                    lowestZero = Math.max(lowestZero, r);
                } else if (lowestZero >= 0) {
                    int temp = board[r][c];
                    board[r][c] = board[lowestZero][c];
                    board[lowestZero][c] = temp;
                    lowestZero--;
                }
            }
        }
    }

    public int[][] candyCrush(int[][] board) {
        m = board.length;
        n = board[0].length;

        // Continue with the three steps until we can no longer find any crushable candies.
        while (!findAndCrush(board)) {
            drop(board);
        }

        return board;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def candyCrush(self, board: List[List[int]]) -> List[List[int]]:
        m, n = len(board), len(board[0])

        def find_and_crush():
            complete = True

            # Check vertically adjacent candies 
            for r in range(1, m - 1):
                for c in range(n):
                    if board[r][c] == 0:
                        continue
                    if abs(board[r][c]) == abs(board[r - 1][c]) == abs(board[r + 1][c]): 
                        board[r][c] = -abs(board[r][c])
                        board[r - 1][c] = -abs(board[r - 1][c])
                        board[r + 1][c] = -abs(board[r + 1][c])
                        complete = False

            # Check horizontally adjacent candies 
            for r in range(m):
                for c in range(1, n - 1):
                    if board[r][c] == 0:
                        continue
                    if abs(board[r][c]) == abs(board[r][c - 1]) == abs(board[r][c + 1]): 
                        board[r][c] = -abs(board[r][c])
                        board[r][c - 1] = -abs(board[r][c - 1])
                        board[r][c + 1] = -abs(board[r][c + 1])
                        complete = False
            
            # Set the value of each candies to be crushed as 0
            for r in range(m):
                for c in range(n):
                    if board[r][c] < 0:
                        board[r][c] = 0           
            return complete
        
        def drop():
            for c in range(n):
                lowest_zero = -1

                # Iterate over each column
                for r in range(m - 1, -1, -1):
                    if board[r][c] == 0:
                        lowest_zero = max(lowest_zero, r)

                    # Swap current non-zero candy with the lowest zero.
                    elif lowest_zero >= 0:
                        board[r][c], board[lowest_zero][c] = board[lowest_zero][c], board[r][c]
                        lowest_zero -= 1

        # Continue with the three steps until we can no longer find any crushable candies.
        while not find_and_crush():
            drop()

        return board
```

</details>
