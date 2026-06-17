# 52. N-Queens II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/n-queens-ii/)  
`Backtracking`

**Problem Link:** [LeetCode 52 - N-Queens II](https://leetcode.com/problems/n-queens-ii/)

## Problem

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

### Example 1

```text
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
```

### Example 2

```text
Input: n = 1
Output: 1
```

## Constraints

- 1 <= n <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [N-Queens](https://leetcode.com/problems/n-queens/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 52. N-Queens II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// In C language "set" data structure is not available hence we are using
// "hashMap" to mimic the set operations.
struct hash_set {
    int id;
    UT_hash_handle hh;
};
int hash_set_exist(struct hash_set *head, int id) {
    struct hash_set *tmp;
    HASH_FIND_INT(head, &id, tmp);
    return tmp != NULL;
}
void hash_set_add(struct hash_set **head, int id) {
    struct hash_set *tmp = (struct hash_set *)malloc(sizeof(struct hash_set));
    tmp->id = id;
    HASH_ADD_INT(*head, id, tmp);
}
void hash_set_delete(struct hash_set **head, int id) {
    struct hash_set *tmp;
    HASH_FIND_INT(*head, &id, tmp);
    HASH_DEL(*head, tmp);
}
int size;
int backtrack(int row, struct hash_set *diagonals,
              struct hash_set *antiDiagonals, struct hash_set *cols) {
    if (row == size) {
        return 1;
    }
    int solutions = 0;
    for (int col = 0; col < size; col++) {
        int currDiagonal = row - col;
        int currAntiDiagonal = row + col;
        if (hash_set_exist(cols, col) ||
            hash_set_exist(diagonals, currDiagonal) ||
            hash_set_exist(antiDiagonals, currAntiDiagonal)) {
            continue;
        }
        hash_set_add(&cols, col);
        hash_set_add(&diagonals, currDiagonal);
        hash_set_add(&antiDiagonals, currAntiDiagonal);
        solutions += backtrack(row + 1, diagonals, antiDiagonals, cols);
        hash_set_delete(&cols, col);
        hash_set_delete(&diagonals, currDiagonal);
        hash_set_delete(&antiDiagonals, currAntiDiagonal);
    }
    return solutions;
}
int totalNQueens(int n) {
    size = n;
    struct hash_set *cols = NULL, *diagonals = NULL, *antiDiagonals = NULL;
    return backtrack(0, diagonals, antiDiagonals, cols);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int size;

public:
    int totalNQueens(int n) {
        // declaring unordered sets
        unordered_set<int> diagonals, antiDiagonals, cols;
        size = n;
        return backtrack(0, diagonals, antiDiagonals, cols);
    }

private:
    int backtrack(int row, unordered_set<int>& diagonals,
                  unordered_set<int>& antiDiagonals, unordered_set<int>& cols) {
        // Base case - N queens have been placed
        if (row == size) {
            return 1;
        }
        int solutions = 0;
        for (int col = 0; col < size; col++) {
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (cols.find(col) != cols.end() ||
                diagonals.find(currDiagonal) != diagonals.end() ||
                antiDiagonals.find(currAntiDiagonal) != antiDiagonals.end()) {
                continue;
            }
            // "Add" the queen to the board
            cols.insert(col);
            diagonals.insert(currDiagonal);
            antiDiagonals.insert(currAntiDiagonal);
            // Move on to the next row with the updated board state
            solutions += backtrack(row + 1, diagonals, antiDiagonals, cols);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.erase(col);
            diagonals.erase(currDiagonal);
            antiDiagonals.erase(currAntiDiagonal);
        }
        return solutions;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int size;

    public int TotalNQueens(int n) {
        size = n;
        return Backtrack(0, new HashSet<int>(), new HashSet<int>(),
                         new HashSet<int>());
    }

    private int Backtrack(int row, HashSet<int> diagonals,
                          HashSet<int> antiDiagonals, HashSet<int> cols) {
        // Base case - N queens have been placed
        if (row == size) {
            return 1;
        }

        int solutions = 0;
        for (int col = 0; col < size; col++) {
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (cols.Contains(col) || diagonals.Contains(currDiagonal) ||
                antiDiagonals.Contains(currAntiDiagonal)) {
                continue;
            }

            // "Add" the queen to the board
            cols.Add(col);
            diagonals.Add(currDiagonal);
            antiDiagonals.Add(currAntiDiagonal);
            // Move on to the next row with the updated board state
            solutions += Backtrack(row + 1, diagonals, antiDiagonals, cols);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.Remove(col);
            diagonals.Remove(currDiagonal);
            antiDiagonals.Remove(currAntiDiagonal);
        }

        return solutions;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func totalNQueens(n int) int {
    size := n
    var backtrack func(int, map[int]bool, map[int]bool, map[int]bool) int
    backtrack = func(row int, diagonals, antiDiagonal, cols map[int]bool) int {
        if row == size {
            return 1
        }
        solutions := 0
        for col := 0; col < size; col++ {
            currDiagonal := row - col
            currAntiDiagonal := row + col
            // If the queen is not placeable
            if cols[col] || diagonals[currDiagonal] ||
                antiDiagonal[currAntiDiagonal] {
                continue
            }
            cols[col] = true
            diagonals[currDiagonal] = true
            antiDiagonal[currAntiDiagonal] = true
            // Move on to the next row with the updated board state
            solutions += backtrack(row+1, diagonals, antiDiagonal, cols)
            delete(cols, col)
            delete(diagonals, currDiagonal)
            delete(antiDiagonal, currAntiDiagonal)
        }
        return solutions
    }
    return backtrack(
        0,
        make(map[int]bool),
        make(map[int]bool),
        make(map[int]bool),
    )
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int size;

    public int totalNQueens(int n) {
        size = n;
        return backtrack(0, new HashSet<>(), new HashSet<>(), new HashSet<>());
    }

    private int backtrack(
        int row,
        Set<Integer> diagonals,
        Set<Integer> antiDiagonals,
        Set<Integer> cols
    ) {
        // Base case - N queens have been placed
        if (row == size) {
            return 1;
        }

        int solutions = 0;
        for (int col = 0; col < size; col++) {
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (
                cols.contains(col) ||
                diagonals.contains(currDiagonal) ||
                antiDiagonals.contains(currAntiDiagonal)
            ) {
                continue;
            }

            // "Add" the queen to the board
            cols.add(col);
            diagonals.add(currDiagonal);
            antiDiagonals.add(currAntiDiagonal);

            // Move on to the next row with the updated board state
            solutions += backtrack(row + 1, diagonals, antiDiagonals, cols);

            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.remove(col);
            diagonals.remove(currDiagonal);
            antiDiagonals.remove(currAntiDiagonal);
        }

        return solutions;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var totalNQueens = function (n) {
    function backtrack(row, diagonals, anti_diagonals, cols) {
        if (row == n) {
            return 1;
        }
        let solutions = 0;
        for (let col = 0; col < n; col++) {
            let curr_diagonal = row - col;
            let curr_anti_diagonal = row + col;
            // If the queen is not placeable
            if (
                cols.has(col) ||
                diagonals.has(curr_diagonal) ||
                anti_diagonals.has(curr_anti_diagonal)
            ) {
                continue;
            }
            cols.add(col);
            diagonals.add(curr_diagonal);
            anti_diagonals.add(curr_anti_diagonal);
            solutions += backtrack(row + 1, diagonals, anti_diagonals, cols);
            cols.delete(col);
            diagonals.delete(curr_diagonal);
            anti_diagonals.delete(curr_anti_diagonal);
        }
        return solutions;
    }
    return backtrack(0, new Set(), new Set(), new Set());
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def totalNQueens(self, n):
        def backtrack(row, diagonals, anti_diagonals, cols):
            # Base case - N queens have been placed
            if row == n:
                return 1

            solutions = 0
            for col in range(n):
                curr_diagonal = row - col
                curr_anti_diagonal = row + col
                # If the queen is not placeable
                if (
                    col in cols
                    or curr_diagonal in diagonals
                    or curr_anti_diagonal in anti_diagonals
                ):
                    continue

                # "Add" the queen to the board
                cols.add(col)
                diagonals.add(curr_diagonal)
                anti_diagonals.add(curr_anti_diagonal)

                # Move on to the next row with the updated board state
                solutions += backtrack(row + 1, diagonals, anti_diagonals, cols)

                # "Remove" the queen from the board since we have already
                # explored all valid paths using the above function call
                cols.remove(col)
                diagonals.remove(curr_diagonal)
                anti_diagonals.remove(curr_anti_diagonal)

            return solutions

        return backtrack(0, set(), set(), set())
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function totalNQueens(n: number): number {
    let size = n;
    function backtrack(
        row: number,
        diagonals: Set<number>,
        antiDiagonals: Set<number>,
        cols: Set<number>,
    ): number {
        if (row == size) {
            return 1;
        }
        let solutions = 0;
        for (let col = 0; col < size; col++) {
            let currDiagonal = row - col;
            let currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (
                cols.has(col) ||
                diagonals.has(currDiagonal) ||
                antiDiagonals.has(currAntiDiagonal)
            ) {
                continue;
            }
            // "Add" the queen to the board
            cols.add(col);
            diagonals.add(currDiagonal);
            antiDiagonals.add(currAntiDiagonal);
            // Move on to the next row with the updated board state
            solutions += backtrack(row + 1, diagonals, antiDiagonals, cols);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.delete(col);
            diagonals.delete(currDiagonal);
            antiDiagonals.delete(currAntiDiagonal);
        }
        return solutions;
    }
    return backtrack(0, new Set(), new Set(), new Set());
}
```

</details>
