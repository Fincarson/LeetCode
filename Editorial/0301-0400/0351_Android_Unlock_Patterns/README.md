# 351. Android Unlock Patterns

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/android-unlock-patterns/)  
`Dynamic Programming` `Backtracking` `Bit Manipulation` `Bitmask`

**Problem Link:** [LeetCode 351 - Android Unlock Patterns](https://leetcode.com/problems/android-unlock-patterns/)

## Problem

Android devices have a special lock screen with a 3 x 3 grid of dots. Users can set an "unlock pattern" by connecting the dots in a specific sequence, forming a series of joined line segments where each segment's endpoints are two consecutive dots in the sequence. A sequence of k dots is a valid unlock pattern if both of the following are true:

- All the dots in the sequence are distinct.
- If the line segment connecting two consecutive dots in the sequence passes through the center of any other dot, the other dot must have previously appeared in the sequence. No jumps through the center non-selected dots are allowed.

		For example, connecting dots 2 and 9 without dots 5 or 6 appearing beforehand is valid because the line from dot 2 to dot 9 does not pass through the center of either dot 5 or 6.
		However, connecting dots 1 and 3 without dot 2 appearing beforehand is invalid because the line from dot 1 to dot 3 passes through the center of dot 2.

Here are some example valid and invalid unlock patterns:

- The 1st pattern [4,1,3,6] is invalid because the line connecting dots 1 and 3 pass through dot 2, but dot 2 did not previously appear in the sequence.
- The 2nd pattern [4,1,9,2] is invalid because the line connecting dots 1 and 9 pass through dot 5, but dot 5 did not previously appear in the sequence.
- The 3rd pattern [2,4,1,3,6] is valid because it follows the conditions. The line connecting dots 1 and 3 meets the condition because dot 2 previously appeared in the sequence.
- The 4th pattern [6,5,4,1,9,2] is valid because it follows the conditions. The line connecting dots 1 and 9 meets the condition because dot 5 previously appeared in the sequence.

Given two integers m and n, return the number of unique and valid unlock patterns of the Android grid lock screen that consist of at least m keys and at most n keys.

Two unlock patterns are considered unique if there is a dot in one sequence that is not in the other, or the order of the dots is different.

### Example 1

```text
Input: m = 1, n = 1
Output: 9
```

### Example 2

```text
Input: m = 1, n = 2
Output: 65
```

## Constraints

- 1 <= m, n <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 351. Android Unlock Patterns

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C++, Java, Python3 |
| Backtracking (Optimized) | C++, Java, Python3 |
| Memoization | C++, Java, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int totalPatterns = 0;
        // Start from each of the 9 dots on the grid
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                vector<vector<bool>> visitedDots(3, vector<bool>(3, false));
                // Count patterns starting from this dot
                totalPatterns +=
                    countPatternsFromDot(m, n, 1, row, col, visitedDots);
            }
        }
        return totalPatterns;
    }

private:
    // All possible single-step moves on the lock pattern grid
    // Each array represents a move as {row change, column change}
    const vector<vector<int>> SINGLE_STEP_MOVES = {
        {0, 1},  {0, -1},
        {1, 0},  {-1, 0},  // Adjacent moves (right, left, down, up)
        {1, 1},  {-1, 1},
        {1, -1}, {-1, -1},  // Diagonal moves
        {-2, 1}, {-2, -1},
        {2, 1},  {2, -1},  // Extended moves (knight-like moves)
        {1, -2}, {-1, -2},
        {1, 2},  {-1, 2}};

    // Moves that require a dot to be visited in between
    // These moves "jump" over a dot, which must have been previously visited
    const vector<vector<int>> SKIP_DOT_MOVES = {
        {0, 2},   {0, -2},
        {2, 0},   {-2, 0},  // Straight skip moves (e.g., 1 to 3, 4 to 6)
        {-2, -2}, {2, 2},
        {2, -2},  {-2, 2}  // Diagonal skip moves (e.g., 1 to 9, 3 to 7)
    };

    int countPatternsFromDot(int m, int n, int currentLength, int currentRow,
                             int currentCol,
                             vector<vector<bool>>& visitedDots) {
        // Base case: if current pattern length exceeds n, stop exploring
        if (currentLength > n) {
            return 0;
        }

        int validPatterns = 0;
        // If current pattern length is within the valid range, count it
        if (currentLength >= m) validPatterns++;

        // Mark current dot as visited
        visitedDots[currentRow][currentCol] = true;

        // Explore all single-step moves
        for (auto& move : SINGLE_STEP_MOVES) {
            int newRow = currentRow + move[0];
            int newCol = currentCol + move[1];
            if (isValidMove(newRow, newCol, visitedDots)) {
                // Recursively count patterns from the new position
                validPatterns += countPatternsFromDot(
                    m, n, currentLength + 1, newRow, newCol, visitedDots);
            }
        }

        // Explore all skip-dot moves
        for (auto& move : SKIP_DOT_MOVES) {
            int newRow = currentRow + move[0];
            int newCol = currentCol + move[1];
            if (isValidMove(newRow, newCol, visitedDots)) {
                // Check if the middle dot has been visited
                int middleRow = currentRow + move[0] / 2;
                int middleCol = currentCol + move[1] / 2;
                if (visitedDots[middleRow][middleCol]) {
                    // If middle dot is visited, this move is valid
                    validPatterns += countPatternsFromDot(
                        m, n, currentLength + 1, newRow, newCol, visitedDots);
                }
            }
        }

        // Backtrack: unmark the current dot before returning
        visitedDots[currentRow][currentCol] = false;
        return validPatterns;
    }

    // Helper method to check if a move is valid
    bool isValidMove(int row, int col, vector<vector<bool>>& visitedDots) {
        // A move is valid if it's within the grid and the dot hasn't been
        // visited
        return row >= 0 && col >= 0 && row < 3 && col < 3 &&
               !visitedDots[row][col];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // All possible single-step moves on the lock pattern grid
    // Each array represents a move as {row change, column change}
    private static final int[][] SINGLE_STEP_MOVES = {
        { 0, 1 },
        { 0, -1 },
        { 1, 0 },
        { -1, 0 }, // Adjacent moves (right, left, down, up)
        { 1, 1 },
        { -1, 1 },
        { 1, -1 },
        { -1, -1 }, // Diagonal moves
        { -2, 1 },
        { -2, -1 },
        { 2, 1 },
        { 2, -1 }, // Extended moves (knight-like moves)
        { 1, -2 },
        { -1, -2 },
        { 1, 2 },
        { -1, 2 },
    };

    // Moves that require a dot to be visited in between
    // These moves "jump" over a dot, which must have been previously visited
    private static final int[][] SKIP_DOT_MOVES = {
        { 0, 2 },
        { 0, -2 },
        { 2, 0 },
        { -2, 0 }, // Straight skip moves (e.g., 1 to 3, 4 to 6)
        { -2, -2 },
        { 2, 2 },
        { 2, -2 },
        { -2, 2 }, // Diagonal skip moves (e.g., 1 to 9, 3 to 7)
    };

    public int numberOfPatterns(int m, int n) {
        int totalPatterns = 0;
        // Start from each of the 9 dots on the grid
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                boolean[][] visitedDots = new boolean[3][3];
                // Count patterns starting from this dot
                totalPatterns +=
                countPatternsFromDot(m, n, 1, row, col, visitedDots);
            }
        }
        return totalPatterns;
    }

    private int countPatternsFromDot(
        int m,
        int n,
        int currentLength,
        int currentRow,
        int currentCol,
        boolean[][] visitedDots
    ) {
        // Base case: if current pattern length exceeds n, stop exploring
        if (currentLength > n) {
            return 0;
        }

        int validPatterns = 0;
        // If current pattern length is within the valid range, count it
        if (currentLength >= m) validPatterns++;

        // Mark current dot as visited
        visitedDots[currentRow][currentCol] = true;

        // Explore all single-step moves
        for (int[] move : SINGLE_STEP_MOVES) {
            int newRow = currentRow + move[0];
            int newCol = currentCol + move[1];
            if (isValidMove(newRow, newCol, visitedDots)) {
                // Recursively count patterns from the new position
                validPatterns +=
                countPatternsFromDot(
                    m,
                    n,
                    currentLength + 1,
                    newRow,
                    newCol,
                    visitedDots
                );
            }
        }

        // Explore all skip-dot moves
        for (int[] move : SKIP_DOT_MOVES) {
            int newRow = currentRow + move[0];
            int newCol = currentCol + move[1];
            if (isValidMove(newRow, newCol, visitedDots)) {
                // Check if the middle dot has been visited
                int middleRow = currentRow + move[0] / 2;
                int middleCol = currentCol + move[1] / 2;
                if (visitedDots[middleRow][middleCol]) {
                    // If middle dot is visited, this move is valid
                    validPatterns +=
                    countPatternsFromDot(
                        m,
                        n,
                        currentLength + 1,
                        newRow,
                        newCol,
                        visitedDots
                    );
                }
            }
        }

        // Backtrack: unmark the current dot before returning
        visitedDots[currentRow][currentCol] = false;
        return validPatterns;
    }

    // Helper method to check if a move is valid
    private boolean isValidMove(int row, int col, boolean[][] visitedDots) {
        // A move is valid if it's within the grid and the dot hasn't been visited
        return (
            row >= 0 && col >= 0 && row < 3 && col < 3 && !visitedDots[row][col]
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # All possible single-step moves on the lock pattern grid
    # Each tuple represents a move as (row change, column change)
    SINGLE_STEP_MOVES = [
        (0, 1),
        (0, -1),
        (1, 0),
        (-1, 0),  # Adjacent moves (right, left, down, up)
        (1, 1),
        (-1, 1),
        (1, -1),
        (-1, -1),  # Diagonal moves
        (-2, 1),
        (-2, -1),
        (2, 1),
        (2, -1),  # Extended moves (knight-like moves)
        (1, -2),
        (-1, -2),
        (1, 2),
        (-1, 2),
    ]

    # Moves that require a dot to be visited in between
    # These moves "jump" over a dot, which must have been previously visited
    SKIP_DOT_MOVES = [
        (0, 2),
        (0, -2),
        (2, 0),
        (-2, 0),  # Straight skip moves (e.g., 1 to 3, 4 to 6)
        (-2, -2),
        (2, 2),
        (2, -2),
        (-2, 2),  # Diagonal skip moves (e.g., 1 to 9, 3 to 7)
    ]

    def numberOfPatterns(self, m: int, n: int) -> int:
        total_patterns = 0
        # Start from each of the 9 dots on the grid
        for row in range(3):
            for col in range(3):
                visited_dots = [[False for _ in range(3)] for _ in range(3)]
                # Count patterns starting from this dot
                total_patterns += self._count_patterns_from_dot(
                    m, n, 1, row, col, visited_dots
                )
        return total_patterns

    def _count_patterns_from_dot(
        self, m, n, current_length, current_row, current_col, visited_dots
    ):
        # Base case: if current pattern length exceeds n, stop exploring
        if current_length > n:
            return 0

        valid_patterns = 0
        # If current pattern length is within the valid range, count it
        if current_length >= m:
            valid_patterns += 1

        # Mark current dot as visited
        visited_dots[current_row][current_col] = True

        # Explore all single-step moves
        for move in self.SINGLE_STEP_MOVES:
            new_row = current_row + move[0]
            new_col = current_col + move[1]
            if self._is_valid_move(new_row, new_col, visited_dots):
                # Recursively count patterns from the new position
                valid_patterns += self._count_patterns_from_dot(
                    m, n, current_length + 1, new_row, new_col, visited_dots
                )

        # Explore all skip-dot moves
        for move in self.SKIP_DOT_MOVES:
            new_row = current_row + move[0]
            new_col = current_col + move[1]
            if self._is_valid_move(new_row, new_col, visited_dots):
                # Check if the middle dot has been visited
                middle_row = current_row + move[0] // 2
                middle_col = current_col + move[1] // 2
                if visited_dots[middle_row][middle_col]:
                    # If middle dot is visited, this move is valid
                    valid_patterns += self._count_patterns_from_dot(
                        m, n, current_length + 1, new_row, new_col, visited_dots
                    )

        # Backtrack: unmark the current dot before returning
        visited_dots[current_row][current_col] = False
        return valid_patterns

    def _is_valid_move(self, row, col, visited_dots):
        # A move is valid if it's within the grid and the dot hasn't been visited
        return 0 <= row < 3 and 0 <= col < 3 and not visited_dots[row][col]
```

</details>

<br>

## Approach 2: Backtracking (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> jump(10, vector<int>(10, 0));

        // Initialize the jump over numbers for all valid jumps
        jump[1][3] = jump[3][1] = 2;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        jump[1][7] = jump[7][1] = 4;
        jump[2][8] = jump[8][2] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;

        vector<bool> visitedNumbers(10, false);
        int totalPatterns = 0;

        // Count patterns starting from corner numbers (1, 3, 7, 9) and multiply
        // by 4 due to symmetry
        totalPatterns +=
            countPatternsFromNumber(1, 1, m, n, jump, visitedNumbers) * 4;

        // Count patterns starting from edge numbers (2, 4, 6, 8) and multiply
        // by 4 due to symmetry
        totalPatterns +=
            countPatternsFromNumber(2, 1, m, n, jump, visitedNumbers) * 4;

        // Count patterns starting from the center number (5)
        totalPatterns +=
            countPatternsFromNumber(5, 1, m, n, jump, visitedNumbers);

        return totalPatterns;
    }

private:
    int countPatternsFromNumber(int currentNumber, int currentLength,
                                int minLength, int maxLength,
                                vector<vector<int>>& jump,
                                vector<bool>& visitedNumbers) {
        // Base case: if current pattern length exceeds maxLength, stop
        // exploring
        if (currentLength > maxLength) return 0;

        int validPatterns = 0;
        // If current pattern length is within the valid range, count it
        if (currentLength >= minLength) {
            validPatterns++;
        }

        visitedNumbers[currentNumber] = true;

        // Explore all possible next numbers
        for (int nextNumber = 1; nextNumber <= 9; nextNumber++) {
            int jumpOverNumber = jump[currentNumber][nextNumber];
            // Check if the next number is unvisited and either:
            // 1. There's no number to jump over, or
            // 2. The number to jump over has been visited
            if (!visitedNumbers[nextNumber] &&
                (jumpOverNumber == 0 || visitedNumbers[jumpOverNumber])) {
                validPatterns += countPatternsFromNumber(
                    nextNumber, currentLength + 1, minLength, maxLength, jump,
                    visitedNumbers);
            }
        }

        // Backtrack: unmark the current number before returning
        visitedNumbers[currentNumber] = false;

        return validPatterns;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfPatterns(int m, int n) {
        int[][] jump = new int[10][10];

        // Initialize the jump over numbers for all valid jumps
        jump[1][3] = jump[3][1] = 2;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        jump[1][7] = jump[7][1] = 4;
        jump[2][8] = jump[8][2] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;

        boolean[] visitedNumbers = new boolean[10];
        int totalPatterns = 0;

        // Count patterns starting from corner numbers (1, 3, 7, 9) and multiply by 4 due to symmetry
        totalPatterns +=
        countPatternsFromNumber(1, 1, m, n, jump, visitedNumbers) * 4;

        // Count patterns starting from edge numbers (2, 4, 6, 8) and multiply by 4 due to symmetry
        totalPatterns +=
        countPatternsFromNumber(2, 1, m, n, jump, visitedNumbers) * 4;

        // Count patterns starting from the center number (5)
        totalPatterns +=
        countPatternsFromNumber(5, 1, m, n, jump, visitedNumbers);

        return totalPatterns;
    }

    private int countPatternsFromNumber(
        int currentNumber,
        int currentLength,
        int minLength,
        int maxLength,
        int[][] jump,
        boolean[] visitedNumbers
    ) {
        // Base case: if current pattern length exceeds maxLength, stop exploring
        if (currentLength > maxLength) return 0;

        int validPatterns = 0;
        // If current pattern length is within the valid range, count it
        if (currentLength >= minLength) {
            validPatterns++;
        }

        visitedNumbers[currentNumber] = true;

        // Explore all possible next numbers
        for (int nextNumber = 1; nextNumber <= 9; nextNumber++) {
            int jumpOverNumber = jump[currentNumber][nextNumber];
            // Check if the next number is unvisited and either:
            // 1. There's no number to jump over, or
            // 2. The number to jump over has been visited
            if (
                !visitedNumbers[nextNumber] &&
                (jumpOverNumber == 0 || visitedNumbers[jumpOverNumber])
            ) {
                validPatterns +=
                countPatternsFromNumber(
                    nextNumber,
                    currentLength + 1,
                    minLength,
                    maxLength,
                    jump,
                    visitedNumbers
                );
            }
        }

        // Backtrack: unmark the current number before returning
        visitedNumbers[currentNumber] = false;

        return validPatterns;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:
        jump = [[0 for _ in range(10)] for _ in range(10)]

        # Initialize the jump over numbers for all valid jumps
        jump[1][3] = jump[3][1] = 2
        jump[4][6] = jump[6][4] = 5
        jump[7][9] = jump[9][7] = 8
        jump[1][7] = jump[7][1] = 4
        jump[2][8] = jump[8][2] = 5
        jump[3][9] = jump[9][3] = 6
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5

        visited_numbers = [False] * 10
        total_patterns = 0

        # Count patterns starting from corner numbers (1, 3, 7, 9) and multiply by 4 due to symmetry
        total_patterns += (
            self._count_patterns_from_number(1, 1, m, n, jump, visited_numbers)
            * 4
        )

        # Count patterns starting from edge numbers (2, 4, 6, 8) and multiply by 4 due to symmetry
        total_patterns += (
            self._count_patterns_from_number(2, 1, m, n, jump, visited_numbers)
            * 4
        )

        # Count patterns starting from the center number (5)
        total_patterns += self._count_patterns_from_number(
            5, 1, m, n, jump, visited_numbers
        )

        return total_patterns

    def _count_patterns_from_number(
        self,
        current_number: int,
        current_length: int,
        min_length: int,
        max_length: int,
        jump: list,
        visited_numbers: list,
    ) -> int:
        # Base case: if current pattern length exceeds max_length, stop exploring
        if current_length > max_length:
            return 0

        valid_patterns = 0
        # If current pattern length is within the valid range, count it
        if current_length >= min_length:
            valid_patterns += 1

        visited_numbers[current_number] = True

        # Explore all possible next numbers
        for next_number in range(1, 10):
            jump_over_number = jump[current_number][next_number]
            # Check if the next number is unvisited and either:
            # 1. There's no number to jump over, or
            # 2. The number to jump over has been visited
            if not visited_numbers[next_number] and (
                jump_over_number == 0 or visited_numbers[jump_over_number]
            ):
                valid_patterns += self._count_patterns_from_number(
                    next_number,
                    current_length + 1,
                    min_length,
                    max_length,
                    jump,
                    visited_numbers,
                )

        # Backtrack: unmark the current number before returning
        visited_numbers[current_number] = False

        return valid_patterns
```

</details>

<br>

## Approach 3: Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int jump[10][10] = {0};

        // Initialize the jump over numbers for all valid jumps
        jump[1][3] = jump[3][1] = 2;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        jump[1][7] = jump[7][1] = 4;
        jump[2][8] = jump[8][2] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;

        int visitedNumbers = 0;
        int totalPatterns = 0;
        int dp[10][1 << 10] = {0};
        memset(dp, -1, sizeof(dp));

        // Count patterns starting from corner numbers (1, 3, 7, 9) and multiply
        // by 4 due to symmetry
        totalPatterns +=
            countPatternsFromNumber(1, 1, m, n, jump, visitedNumbers, dp) * 4;

        // Count patterns starting from edge numbers (2, 4, 6, 8) and multiply
        // by 4 due to symmetry
        totalPatterns +=
            countPatternsFromNumber(2, 1, m, n, jump, visitedNumbers, dp) * 4;

        // Count patterns starting from the center number (5)
        totalPatterns +=
            countPatternsFromNumber(5, 1, m, n, jump, visitedNumbers, dp);

        return totalPatterns;
    }

private:
    int countPatternsFromNumber(int currentNumber, int currentLength,
                                int minLength, int maxLength, int jump[10][10],
                                int visitedNumbers, int dp[10][1 << 10]) {
        // Base case: if current pattern length exceeds maxLength, stop
        // exploring
        if (currentLength > maxLength) return 0;

        if (dp[currentNumber][visitedNumbers] != -1)
            return dp[currentNumber][visitedNumbers];

        int validPatterns = 0;
        // If current pattern length is within the valid range, count it
        if (currentLength >= minLength) {
            validPatterns++;
        }

        visitedNumbers = setBit(visitedNumbers, currentNumber);

        // Explore all possible next numbers
        for (int nextNumber = 1; nextNumber <= 9; nextNumber++) {
            int jumpOverNumber = jump[currentNumber][nextNumber];
            // Check if the next number is unvisited and either:
            // 1. There's no number to jump over, or
            // 2. The number to jump over has been visited
            if (!isSet(visitedNumbers, nextNumber) &&
                (jumpOverNumber == 0 ||
                 isSet(visitedNumbers, jumpOverNumber))) {
                validPatterns += countPatternsFromNumber(
                    nextNumber, currentLength + 1, minLength, maxLength, jump,
                    visitedNumbers, dp);
            }
        }

        // Backtrack: unmark the current number before returning
        visitedNumbers = clearBit(visitedNumbers, currentNumber);

        return dp[currentNumber][visitedNumbers] = validPatterns;
    }

    int setBit(int num, int position) {
        num |= 1 << (position - 1);
        return num;
    }

    int clearBit(int num, int position) {
        num ^= 1 << (position - 1);
        return num;
    }

    bool isSet(int num, int position) {
        int bitAtPosition = (num >> (position - 1)) & 1;
        return bitAtPosition == 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfPatterns(int m, int n) {
        int[][] jump = new int[10][10];

        // Initialize the jump over numbers for all valid jumps
        jump[1][3] = jump[3][1] = 2;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        jump[1][7] = jump[7][1] = 4;
        jump[2][8] = jump[8][2] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;

        int visitedNumbers = 0;
        int totalPatterns = 0;
        Integer[][] dp = new Integer[10][1 << 10];

        // Count patterns starting from corner numbers (1, 3, 7, 9) and multiply by 4 due to symmetry
        totalPatterns +=
        countPatternsFromNumber(1, 1, m, n, jump, visitedNumbers, dp) * 4;

        // Count patterns starting from edge numbers (2, 4, 6, 8) and multiply by 4 due to symmetry
        totalPatterns +=
        countPatternsFromNumber(2, 1, m, n, jump, visitedNumbers, dp) * 4;

        // Count patterns starting from the center number (5)
        totalPatterns +=
        countPatternsFromNumber(5, 1, m, n, jump, visitedNumbers, dp);

        return totalPatterns;
    }

    private int countPatternsFromNumber(
        int currentNumber,
        int currentLength,
        int minLength,
        int maxLength,
        int[][] jump,
        int visitedNumbers,
        Integer[][] dp
    ) {
        // Base case: if current pattern length exceeds maxLength, stop exploring
        if (currentLength > maxLength) return 0;

        if (
            dp[currentNumber][visitedNumbers] != null
        ) return dp[currentNumber][visitedNumbers];

        int validPatterns = 0;
        // If current pattern length is within the valid range, count it
        if (currentLength >= minLength) {
            validPatterns++;
        }

        visitedNumbers = setBit(visitedNumbers, currentNumber);

        // Explore all possible next numbers
        for (int nextNumber = 1; nextNumber <= 9; nextNumber++) {
            int jumpOverNumber = jump[currentNumber][nextNumber];
            // Check if the next number is unvisited and either:
            // 1. There's no number to jump over, or
            // 2. The number to jump over has been visited
            if (
                !isSet(visitedNumbers, nextNumber) &&
                (jumpOverNumber == 0 || isSet(visitedNumbers, jumpOverNumber))
            ) {
                validPatterns +=
                countPatternsFromNumber(
                    nextNumber,
                    currentLength + 1,
                    minLength,
                    maxLength,
                    jump,
                    visitedNumbers,
                    dp
                );
            }
        }

        // Backtrack: unmark the current number before returning
        visitedNumbers = clearBit(visitedNumbers, currentNumber);

        return dp[currentNumber][visitedNumbers] = validPatterns;
    }

    private int setBit(int num, int position) {
        num |= 1 << (position - 1);
        return num;
    }

    private int clearBit(int num, int position) {
        num ^= 1 << (position - 1);
        return num;
    }

    private boolean isSet(int num, int position) {
        int bitAtPosition = (num >> (position - 1)) & 1;
        return bitAtPosition == 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:
        jump = [[0] * 10 for _ in range(10)]

        # Initialize the jump over numbers for all valid jumps
        jump[1][3] = jump[3][1] = 2
        jump[4][6] = jump[6][4] = 5
        jump[7][9] = jump[9][7] = 8
        jump[1][7] = jump[7][1] = 4
        jump[2][8] = jump[8][2] = 5
        jump[3][9] = jump[9][3] = 6
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5

        visited_numbers = 0
        total_patterns = 0
        dp = [[-1] * (1 << 10) for _ in range(10)]

        # Count patterns starting from corner numbers (1, 3, 7, 9) and multiply by 4 due to symmetry
        total_patterns += (
            self._count_patterns_from_number(
                1, 1, m, n, jump, visited_numbers, dp
            )
            * 4
        )

        # Count patterns starting from edge numbers (2, 4, 6, 8) and multiply by 4 due to symmetry
        total_patterns += (
            self._count_patterns_from_number(
                2, 1, m, n, jump, visited_numbers, dp
            )
            * 4
        )

        # Count patterns starting from the center number (5)
        total_patterns += self._count_patterns_from_number(
            5, 1, m, n, jump, visited_numbers, dp
        )

        return total_patterns

    def _count_patterns_from_number(
        self,
        current_number: int,
        current_length: int,
        min_length: int,
        max_length: int,
        jump: list,
        visited_numbers: int,
        dp: list,
    ) -> int:
        # Base case: if current pattern length exceeds max_length, stop exploring
        if current_length > max_length:
            return 0

        if dp[current_number][visited_numbers] != -1:
            return dp[current_number][visited_numbers]

        valid_patterns = 0
        # If current pattern length is within the valid range, count it
        if current_length >= min_length:
            valid_patterns += 1

        visited_numbers = self._set_bit(visited_numbers, current_number)

        # Explore all possible next numbers
        for next_number in range(1, 10):
            jump_over_number = jump[current_number][next_number]
            # Check if the next number is unvisited and either:
            # 1. There's no number to jump over, or
            # 2. The number to jump over has been visited
            if not self._is_set(visited_numbers, next_number) and (
                jump_over_number == 0
                or self._is_set(visited_numbers, jump_over_number)
            ):
                valid_patterns += self._count_patterns_from_number(
                    next_number,
                    current_length + 1,
                    min_length,
                    max_length,
                    jump,
                    visited_numbers,
                    dp,
                )

        # Backtrack: unmark the current number before returning
        visited_numbers = self._clear_bit(visited_numbers, current_number)

        dp[current_number][visited_numbers] = valid_patterns
        return valid_patterns

    def _set_bit(self, num: int, position: int) -> int:
        num |= 1 << (position - 1)
        return num

    def _clear_bit(self, num: int, position: int) -> int:
        num ^= 1 << (position - 1)
        return num

    def _is_set(self, num: int, position: int) -> bool:
        bit_at_position = (num >> (position - 1)) & 1
        return bit_at_position == 1
```

</details>
