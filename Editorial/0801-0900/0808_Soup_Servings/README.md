# 808. Soup Servings

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/soup-servings/)  
`Math` `Dynamic Programming` `Probability and Statistics`

**Problem Link:** [LeetCode 808 - Soup Servings](https://leetcode.com/problems/soup-servings/)

## Problem

You have two soups, A and B, each starting with n mL. On every turn, one of the following four serving operations is chosen at random, each with probability 0.25 independent of all previous turns:

- pour 100 mL from type A and 0 mL from type B
- pour 75 mL from type A and 25 mL from type B
- pour 50 mL from type A and 50 mL from type B
- pour 25 mL from type A and 75 mL from type B

Note:

- There is no operation that pours 0 mL from A and 100 mL from B.
- The amounts from A and B are poured simultaneously during the turn.
- If an operation asks you to pour more than you have left of a soup, pour all that remains of that soup.

The process stops immediately after any turn in which one of the soups is used up.

Return the probability that A is used up before B, plus half the probability that both soups are used up in the same turn. Answers within 10-5 of the actual answer will be accepted.

### Example 1

```text
Input: n = 50
Output: 0.62500
Explanation:
If we perform either of the first two serving operations, soup A will become empty first.
If we perform the third operation, A and B will become empty at the same time.
If we perform the fourth operation, B will become empty first.
So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.
```

### Example 2

```text
Input: n = 100
Output: 0.71875
Explanation:
If we perform the first serving operation, soup A will become empty first.
If we perform the second serving operations, A will become empty on performing operation [1, 2, 3], and both A and B become empty on performing operation 4.
If we perform the third operation, A will become empty on performing operation [1, 2], and both A and B become empty on performing operation 3.
If we perform the fourth operation, A will become empty on performing operation 1, and both A and B become empty on performing operation 2.
So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.71875.
```

## Constraints

- 0 <= n <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 808. Soup Servings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Top-Down Dynamic Programming (Memoization) | C++, Java, Python3 |

## Approach 1: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double soupServings(int n) {
        int m = ceil(n / 25.0);
        unordered_map<int, unordered_map<int, double>> dp;

        function<double(int, int)> calculateDP = [&](int i, int j) -> double {
            return (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][j - 1] +
                    dp[max(0, i - 2)][max(0, j - 2)] + dp[i - 1][max(0, j - 3)]) /
                   4;
        };

        dp[0][0] = 0.5;
        for (int k = 1; k <= m; k++) {
            dp[0][k] = 1;
            dp[k][0] = 0;
            for (int j = 1; j <= k; j++) {
                dp[j][k] = calculateDP(j, k);
                dp[k][j] = calculateDP(k, j);
            }
            if (dp[k][k] > 1 - 1e-5) {
                return 1;
            }
        }
        return dp[m][m];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double soupServings(int n) {
        int m = (int)Math.ceil(n / 25.0);
        Map<Integer, Map<Integer, Double>> dp = new HashMap<>();
        dp.put(0, new HashMap<>());
        dp.get(0).put(0, 0.5);

        for (int k = 1; k <= m; k++) {
            dp.put(k, new HashMap<>());
            dp.get(0).put(k, 1.0);
            dp.get(k).put(0, 0.0);
            for (int j = 1; j <= k; j++) {
                dp.get(j).put(k, calculateDP(j, k, dp));
                dp.get(k).put(j, calculateDP(k, j, dp));
            }
            if (dp.get(k).get(k) > 1 - 1e-5) {
                return 1;
            }
        }

        return dp.get(m).get(m);
    }

    private double calculateDP(int i, int j, Map<Integer, Map<Integer, Double>> dp) {
        return (dp.get(Math.max(0, i - 4)).get(j)
                + dp.get(Math.max(0, i - 3)).get(j - 1)
                + dp.get(Math.max(0, i - 2)).get(Math.max(0, j - 2))
                + dp.get(i - 1).get(Math.max(0, j - 3))) / 4;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def soupServings(self, n: int) -> float:
        m = ceil(n / 25)
        dp = {}

        def calculate_dp(i, j):
            return (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][j - 1] +
                    dp[max(0, i - 2)][max(0, j - 2)]
                    + dp[i - 1][max(0, j - 3)]) / 4

        dp[0] = {0: 0.5}
        for k in range(1, m + 1):
            dp[0][k] = 1
            dp[k] = {0: 0}
            for j in range(1, k + 1):
                dp[j][k] = calculate_dp(j, k)
                dp[k][j] = calculate_dp(k, j)
            if dp[k][k] > 1 - 1e-5:
                return 1
        return dp[m][m]
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming (Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double soupServings(int n) {
        int m = ceil(n / 25.0);
        unordered_map<int, unordered_map<int, double>> dp;

        function<double(int, int)> calculateDP = [&](int i, int j) -> double {
            if (i <= 0 && j <= 0) {
                return 0.5;
            }
            if (i <= 0) {
                return 1;
            }
            if (j <= 0) {
                return 0;
            }
            if (dp[i].count(j)) {
                return dp[i][j];
            }
            return dp[i][j] = (calculateDP(i - 4, j) + calculateDP(i - 3, j - 1) +
                               calculateDP(i - 2, j - 2) + calculateDP(i - 1, j - 3)) /
                              4;
        };

        for (int k = 1; k <= m; k++) {
            if (calculateDP(k, k) > 1 - 1e-5) {
                return 1;
            }
        }
        return calculateDP(m, m);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double soupServings(int n) {
        int m = (int)Math.ceil(n / 25.0);
        Map<Integer, Map<Integer, Double>> dp = new HashMap<>();

        for (int k = 1; k <= m; k++) {
            if (calculateDP(k, k, dp) > 1 - 1e-5) {
                return 1.0;
            }
        }
        return calculateDP(m, m, dp);
    }

    private double calculateDP(int i, int j, Map<Integer, Map<Integer, Double>> dp) {
        if (i <= 0 && j <= 0) {
            return 0.5;
        }
        if (i <= 0) {
            return 1.0;
        }
        if (j <= 0) {
            return 0.0;
        }
        if (dp.containsKey(i) && dp.get(i).containsKey(j)) {
            return dp.get(i).get(j);
        }
        double result = (calculateDP(i - 4, j, dp) + calculateDP(i - 3, j - 1, dp) +
                calculateDP(i - 2, j - 2, dp) + calculateDP(i - 1, j - 3, dp)) / 4.0;
        dp.computeIfAbsent(i, k -> new HashMap<>()).put(j, result);
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def soupServings(self, n: int) -> float:
        m = ceil(n / 25)
        dp = collections.defaultdict(dict)

        def calculate_dp(i: int, j: int) -> float:
            if i <= 0 and j <= 0:
                return 0.5
            if i <= 0:
                return 1.0
            if j <= 0:
                return 0.0
            if i in dp and j in dp[i]:
                return dp[i][j]

            dp[i][j] = (
                calculate_dp(i - 4, j)
                + calculate_dp(i - 3, j - 1)
                + calculate_dp(i - 2, j - 2)
                + calculate_dp(i - 1, j - 3)
            ) / 4.0
            return dp[i][j]

        for k in range(1, m + 1):
            if calculate_dp(k, k) > 1 - 1e-5:
                return 1.0
        return calculate_dp(m, m)
```

</details>
