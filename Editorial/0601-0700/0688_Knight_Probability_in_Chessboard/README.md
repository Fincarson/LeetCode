# 688. Knight Probability in Chessboard

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/knight-probability-in-chessboard/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 688 - Knight Probability in Chessboard](https://leetcode.com/problems/knight-probability-in-chessboard/)

## Problem

On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

### Example 1

```text
Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
```

### Example 2

```text
Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000
```

## Constraints

- 1 <= n <= 25
- 0 <= k <= 100
- 0 <= row, column <= n - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Out of Boundary Paths](https://leetcode.com/problems/out-of-boundary-paths/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Moves to Kill All Pawns](https://leetcode.com/problems/maximum-number-of-moves-to-kill-all-pawns/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 688. Knight Probability in Chessboard

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bottom-up Dynamic Programming | C++, Java, Python3 |
| Bottom-up Dynamic Programming with Optimized Space Complexity | C++, Java, Python3 |
| Top-down Dynamic Programming (Memoization) | C++, Java, Python3 |

## Approach 1: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // Define possible directions for the knight's moves
        vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

        // Initialize the dynamic programming table
        vector dp(k + 1, vector (n, vector<double>(n, 0.0)));
        dp[0][row][column] = 1;

        // Iterate over the number of moves
        for (int moves = 1; moves <= k; moves++) {
            // Iterate over the cells on the chessboard
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Iterate over possible directions
                    for (const auto& direction : directions) {
                        int prevI = i - direction.first;
                        int prevJ = j - direction.second;
                        // Check if the previous cell is within the chessboard
                        if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                            // Add the previous probability divided by 8
                            dp[moves][i][j] += dp[moves - 1][prevI][prevJ] / 8;
                        }
                    }
                }
            }
        }

        // Calculate total probability by summing probabilities for all cells
        double totalProbability = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalProbability += dp[k][i][j];
            }
        }

        return totalProbability;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        // Define possible directions for the knight's moves
        int[][] directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                              {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

        // Initialize the dynamic programming table
        double[][][] dp = new double[k + 1][n][n];
        dp[0][row][column] = 1.0;

        // Iterate over the number of moves
        for (int moves = 1; moves <= k; moves++) {
            // Iterate over the cells on the chessboard
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Iterate over possible directions
                    for (int[] direction : directions) {
                        int prevI = i - direction[0];
                        int prevJ = j - direction[1];
                        // Check if the previous cell is within the chessboard
                        if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                            // Add the previous probability divided by 8
                            dp[moves][i][j] += dp[moves - 1][prevI][prevJ] / 8.0;
                        }
                    }
                }
            }
        }

        // Calculate total probability by summing probabilities for all cells
        double totalProbability = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalProbability += dp[k][i][j];
            }
        }
        return totalProbability;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        # Define possible directions for the knight's moves
        directions = [(1, 2), (1, -2), (-1, 2), (-1, -2),
                      (2, 1), (2, -1), (-2, 1), (-2, -1)]

        # Initialize the dynamic programming table
        dp = [[[0] * n for _ in range(n)] for _ in range(k + 1)]
        dp[0][row][column] = 1

        # Iterate over the number of moves
        for moves in range(1, k + 1):
            # Iterate over the cells on the chessboard
            for i in range(n):
                for j in range(n):
                    # Iterate over possible directions
                    for direction in directions:
                        prev_i, prev_j = i - direction[0], j - direction[1]
                        # Check if the previous cell is within the chessboard
                        if 0 <= prev_i < n and 0 <= prev_j < n:
                            # Add the previous probability
                            dp[moves][i][j] += dp[moves - 1][prev_i][prev_j]
                    # Divide by 8
                    dp[moves][i][j] /= 8

        # Calculate total probability by summing probabilities for all cells
        total_probability = sum(
            dp[k][i][j]
            for i in range(n)
            for j in range(n)
        )
        return total_probability
```

</details>

<br>

## Approach 2: Bottom-up Dynamic Programming with Optimized Space Complexity

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // Define possible directions for the knight's moves
        vector<pair<int, int>> directions = {
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
        };

        // Initialize the previous and current DP tables
        vector prevDp(n, vector<double>(n, 0));
        vector currDp(n, vector<double>(n, 0));

        // Set the probability of the starting cell to 1
        prevDp[row][column] = 1;

        // Iterate over the number of moves
        for (int moves = 1; moves <= k; moves++) {
            // Iterate over the cells on the chessboard
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    currDp[i][j] = 0;

                    // Iterate over possible directions
                    for (const auto& direction : directions) {
                        int prevI = i - direction.first;
                        int prevJ = j - direction.second;

                        // Check if the previous cell is within the chessboard
                        if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                            // Update the probability by adding the previous probability divided by 8
                            currDp[i][j] += prevDp[prevI][prevJ] / 8;
                        }
                    }
                }
            }

            // Swap the previous and current DP tables
            prevDp.swap(currDp);
        }

        // Calculate the total probability by summing up the probabilities for all cells
        double totalProbability = 0;
        for (const auto& row : prevDp) {
            for (const auto& cell : row) {
                totalProbability += cell;
            }
        }

        // Return the total probability
        return totalProbability;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        // Define possible directions for the knight's moves
        int[][] directions = {
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
        };

        // Initialize the previous and current DP tables
        double[][] prevDp = new double[n][n];
        double[][] currDp = new double[n][n];

        // Set the probability of the starting cell to 1
        prevDp[row][column] = 1;

        // Iterate over the number of moves
        for (int moves = 1; moves <= k; moves++) {
            // Iterate over the cells on the chessboard
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    currDp[i][j] = 0;

                    // Iterate over possible directions
                    for (int[] direction : directions) {
                        int prevI = i - direction[0];
                        int prevJ = j - direction[1];

                        // Check if the previous cell is within the chessboard
                        if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                            // Update the probability by adding the previous probability divided by 8
                            currDp[i][j] += prevDp[prevI][prevJ] / 8;
                        }
                    }
                }
            }

            // Swap the previous and current DP tables
            double[][] temp = prevDp;
            prevDp = currDp;
            currDp = temp;
        }

        // Calculate the total probability by summing up the probabilities for all cells
        double totalProbability = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalProbability += prevDp[i][j];
            }
        }

        // Return the total probability
        return totalProbability;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        # Define possible directions for the knight's moves
        directions = [(1, 2), (1, -2), (-1, 2), (-1, -2),
                      (2, 1), (2, -1), (-2, 1), (-2, -1)]

        # Initialize the previous and current DP arrays
        prev_dp = [[0] * n for _ in range(n)]
        curr_dp = [[0] * n for _ in range(n)]

        # Set the probability of the starting position to 1
        prev_dp[row][column] = 1

        # Iterate over the number of moves
        for moves in range(1, k + 1):
            # Iterate over the cells on the chessboard
            for i in range(n):
                for j in range(n):
                    # Reset the probability for the current cell
                    curr_dp[i][j] = 0

                    # Iterate over possible directions
                    for direction in directions:
                        prev_i, prev_j = i - direction[0], j - direction[1]
                        # Check if the previous cell is within the chessboard
                        if 0 <= prev_i < n and 0 <= prev_j < n:
                            # Update the probability for the current cell
                            curr_dp[i][j] += prev_dp[prev_i][prev_j] / 8

            # Swap the previous and current DP arrays
            prev_dp, curr_dp = curr_dp, prev_dp

        # Calculate the total probability
        total_probability = sum(
            prev_dp[i][j]
            for i in range(n)
            for j in range(n)
        )
        return total_probability
```

</details>

<br>

## Approach 3: Top-down Dynamic Programming (Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        vector dp(k + 1, vector (n, vector<double>(n, -1)));

        function<double(int, int, int)> calculateDP = [&](int moves, int i, int j) -> double {
            // Base case
            if (moves == 0) {
                if (i == row && j == column) {
                    return 1;
                } else {
                    return 0;
                }
            }

            // Check if value has already been calculated
            if (dp[moves][i][j] != -1) {
                return dp[moves][i][j];
            }

            dp[moves][i][j] = 0;

            // Iterate over possible directions
            for (const auto& direction : directions) {
                int prevI = i - direction.first;
                int prevJ = j - direction.second;

                // Boundary check
                if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                    dp[moves][i][j] += calculateDP(moves - 1, prevI, prevJ) / 8.0;
                }
            }

            return dp[moves][i][j];
        };

        // Calculate the total probability by summing up the probabilities for all cells
        double totalProbability = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalProbability += calculateDP(k, i, j);
            }
        }

        return totalProbability;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][] directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    private double calculateDP(double[][][] dp, int moves, int i, int j, int n, int row, int column) {
        // Base case
        if (moves == 0) {
            if (i == row && j == column) {
                return 1;
            } else {
                return 0;
            }
        }

        // Check if the value has already been calculated
        if (dp[moves][i][j] != -1) {
            return dp[moves][i][j];
        }

        dp[moves][i][j] = 0;

        // Iterate over possible directions
        for (int[] direction : directions) {
            int prevI = i - direction[0];
            int prevJ = j - direction[1];

            // Boundary check
            if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                dp[moves][i][j] += calculateDP(dp, moves - 1, prevI, prevJ, n, row, column) / 8.0;
            }
        }

        return dp[moves][i][j];
    }

    public double knightProbability(int n, int k, int row, int column) {
        double[][][] dp = new double[k + 1][n][n];

        // Initialize dp with -1 values
        for (double[][] layer : dp) {
            for (double[] rowArray : layer) {
                Arrays.fill(rowArray, -1);
            }
        }

        // Calculate the total probability by summing up the probabilities for all cells
        double totalProbability = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalProbability += calculateDP(dp, k, i, j, n, row, column);
            }
        }

        return totalProbability;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        directions = [(1, 2), (1, -2), (-1, 2), (-1, -2),
                      (2, 1), (2, -1), (-2, 1), (-2, -1)]
        dp = [[[-1] * n for _ in range(n)] for _ in range(k + 1)]

        def calculate_dp(moves, i, j):
            # Base case
            if moves == 0:
                if i == row and j == column:
                    return 1
                else:
                    return 0

            # Check if the value has already been calculated
            if dp[moves][i][j] != -1:
                return dp[moves][i][j]

            dp[moves][i][j] = 0

            # Iterate over possible directions
            for direction in directions:
                prev_i = i - direction[0]
                prev_j = j - direction[1]

                # Boundary check
                if 0 <= prev_i < n and 0 <= prev_j < n:
                    dp[moves][i][j] += calculate_dp(moves - 1, prev_i, prev_j)
            dp[moves][i][j] /= 8

            return dp[moves][i][j]

        # Calculate the total probability
        total_probability = sum(
            calculate_dp(k, i, j)
            for i in range(n)
            for j in range(n)
        )

        return total_probability
```

</details>
