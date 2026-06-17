# 1444. Number of Ways of Cutting a Pizza

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/)  
`Array` `Dynamic Programming` `Memoization` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 1444 - Number of Ways of Cutting a Pizza](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/)

## Problem

Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts.

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

### Example 1

```text
Input: pizza = ["A..","AAA","..."], k = 3
Output: 3
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
```

### Example 2

```text
Input: pizza = ["A..","AA.","..."], k = 3
Output: 1
```

### Example 3

```text
Input: pizza = ["A..","A..","..."], k = 1
Output: 1
```

## Constraints

- 1 <= rows, cols <= 50
- rows == pizza.length
- cols == pizza[i].length
- 1 <= k <= 10
- pizza consists of characters 'A' and '.' only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Selling Pieces of Wood](https://leetcode.com/problems/selling-pieces-of-wood/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1444. Number of Ways of Cutting a Pizza

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, Python3 |
| Dynamic Programming with Optimized Space Complexity | C++, Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].size();
        vector apples(rows + 1, vector<int>(cols + 1));
        vector dp(k, vector(rows, vector<int>(cols)));
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                apples[row][col] = (pizza[row][col] == 'A') + apples[row + 1][col] +
                                   apples[row][col + 1] - apples[row + 1][col + 1];
                dp[0][row][col] = apples[row][col] > 0;
            }
        }
        const int mod = 1000000007;
        for (int remain = 1; remain < k; remain++) {
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    for (int next_row = row + 1; next_row < rows; next_row++) {
                        if (apples[row][col] - apples[next_row][col] > 0) {
                            (dp[remain][row][col] += dp[remain - 1][next_row][col]) %= mod;
                        }
                    }
                    for (int next_col = col + 1; next_col < cols; next_col++) {
                        if (apples[row][col] - apples[row][next_col] > 0) {
                            (dp[remain][row][col] += dp[remain - 1][row][next_col]) %= mod;
                        }
                    }
                }
            }
        }
        return dp[k - 1][0][0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int ways(String[] pizza, int k) {
        int rows = pizza.length, cols = pizza[0].length();
        int apples[][] = new int[rows + 1][cols + 1];
        int dp[][][] = new int[k][rows][cols];
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                apples[row][col] = (pizza[row].charAt(col) == 'A' ? 1 : 0) + apples[row + 1][col] + apples[row][col + 1]
                        - apples[row + 1][col + 1];
                dp[0][row][col] = apples[row][col] > 0 ? 1 : 0;
            }
        }
        int mod = 1000000007;
        for (int remain = 1; remain < k; remain++) {
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    for (int next_row = row + 1; next_row < rows; next_row++) {
                        if (apples[row][col] - apples[next_row][col] > 0) {
                            dp[remain][row][col] += dp[remain - 1][next_row][col];
                            dp[remain][row][col] %= mod;
                        }
                    }
                    for (int next_col = col + 1; next_col < cols; next_col++) {
                        if (apples[row][col] - apples[row][next_col] > 0) {
                            dp[remain][row][col] += dp[remain - 1][row][next_col];
                            dp[remain][row][col] %= mod;
                        }
                    }
                }
            }
        }
        return dp[k - 1][0][0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        rows = len(pizza)
        cols = len(pizza[0])
        apples = [[0] * (cols + 1) for row in range(rows + 1)]
        for row in range(rows - 1, -1, -1):
            for col in range(cols - 1, -1, -1):
                apples[row][col] = ((pizza[row][col] == 'A')
                                    + apples[row + 1][col]
                                    + apples[row][col + 1]
                                    - apples[row + 1][col + 1])
        dp = [[[0 for col in range(cols)] for row in range(rows)] for remain in range(k)]
        dp[0] = [[int(apples[row][col] > 0) for col in range(cols)]
             for row in range(rows)]
        mod = 1000000007
        for remain in range(1, k):
            for row in range(rows):
                for col in range(cols):
                    val = 0
                    for next_row in range(row + 1, rows):
                        if apples[row][col] - apples[next_row][col] > 0:
                            val += dp[remain - 1][next_row][col]
                    for next_col in range(col + 1, cols):
                        if apples[row][col] - apples[row][next_col] > 0:
                            val += dp[remain - 1][row][next_col]
                    dp[remain][row][col] = val % mod
        return dp[k - 1][0][0]
```

</details>

<br>

## Approach 2: Dynamic Programming with Optimized Space Complexity

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].size();
        vector apples(rows + 1, vector<int>(cols + 1));
        vector f(rows, vector<int>(cols));
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                apples[row][col] = (pizza[row][col] == 'A') + apples[row + 1][col] +
                                   apples[row][col + 1] - apples[row + 1][col + 1];
                f[row][col] = apples[row][col] > 0;
            }
        }
        const int mod = 1000000007;
        for (int remain = 1; remain < k; remain++) {
            vector g(rows, vector<int>(cols));
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    for (int next_row = row + 1; next_row < rows; next_row++) {
                        if (apples[row][col] - apples[next_row][col] > 0) {
                            (g[row][col] += f[next_row][col]) %= mod;
                        }
                    }
                    for (int next_col = col + 1; next_col < cols; next_col++) {
                        if (apples[row][col] - apples[row][next_col] > 0) {
                            (g[row][col] += f[row][next_col]) %= mod;
                        }
                    }
                }
            }
            f = g;
        }
        return f[0][0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int ways(String[] pizza, int k) {
        int rows = pizza.length, cols = pizza[0].length();
        int apples[][] = new int[rows + 1][cols + 1];
        int f[][] = new int[rows][cols];
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                apples[row][col] = (pizza[row].charAt(col) == 'A' ? 1 : 0) + apples[row + 1][col] + apples[row][col + 1]
                        - apples[row + 1][col + 1];
                f[row][col] = apples[row][col] > 0 ? 1 : 0;
            }
        }
        int mod = 1000000007;
        for (int remain = 1; remain < k; remain++) {
            int g[][] = new int[rows][cols];
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    for (int next_row = row + 1; next_row < rows; next_row++) {
                        if (apples[row][col] - apples[next_row][col] > 0) {
                            g[row][col] += f[next_row][col];
                            g[row][col] %= mod;
                        }
                    }
                    for (int next_col = col + 1; next_col < cols; next_col++) {
                        if (apples[row][col] - apples[row][next_col] > 0) {
                            g[row][col] += f[row][next_col];
                            g[row][col] %= mod;
                        }
                    }
                }
            }
            // copy g to f
            f = Arrays.stream(g).map(int[]::clone).toArray(int[][]::new);
        }
        return f[0][0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        rows = len(pizza)
        cols = len(pizza[0])
        apples = [[0] * (cols + 1) for row in range(rows + 1)]
        for row in range(rows - 1, -1, -1):
            for col in range(cols - 1, -1, -1):
                apples[row][col] = ((pizza[row][col] == 'A')
                                    + apples[row + 1][col]
                                    + apples[row][col + 1]
                                    - apples[row + 1][col + 1])
        f = [[int(apples[row][col] > 0) for col in range(cols)]
             for row in range(rows)]
        mod = 1000000007
        for remain in range(1, k):
            g = [[0 for col in range(cols)] for row in range(rows)]
            for row in range(rows):
                for col in range(cols):
                    for next_row in range(row + 1, rows):
                        if apples[row][col] - apples[next_row][col] > 0:
                            g[row][col] += f[next_row][col]
                    for next_col in range(col + 1, cols):
                        if apples[row][col] - apples[row][next_col] > 0:
                            g[row][col] += f[row][next_col]
                    g[row][col] %= mod
            f = g
        return f[0][0]
```

</details>
