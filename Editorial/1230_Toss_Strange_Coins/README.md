# 1230. Toss Strange Coins

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/toss-strange-coins/)  
`Array` `Math` `Dynamic Programming` `Probability and Statistics`

**Problem Link:** [LeetCode 1230 - Toss Strange Coins](https://leetcode.com/problems/toss-strange-coins/)

## Problem

You have some coins.  The i-th coin has a probability prob[i] of facing heads when tossed.

Return the probability that the number of coins facing heads equals target if you toss every coin exactly once.

### Example 1

```text
Input: prob = [0.4], target = 1
Output: 0.40000
```

### Example 2

```text
Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
Output: 0.03125
```

## Constraints

- 1 <= prob.length <= 1000
- 0 <= prob[i] <= 1
- 0 <= target <= prob.length
- Answers will be accepted as correct if they are within 10^-5 of the correct answer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1230. Toss Strange Coins

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Dynamic Programming | C++, Java, Python3 |
| Iterative Dynamic Programming | C++, Java, Python3 |
| Dynamic Programming with Space Optimization | C++, Java, Python3 |

## Approach 1: Recursive Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double findProbability(int index, int& n, vector<vector<double>>& memo, vector<double>& prob,
                           int target) {
        // Return 0 if the target is less than zero because we have more heads
        // than we need.
        if (target < 0) {
            return 0;
        }
        // After tossing all of the coins, if we get the required number of heads,
        // return 1 to count this case, otherwise return 0.
        if (index == n) {
            return target == 0 ? 1 : 0;
        }

        if (memo[index][target] != -1) {
            return memo[index][target];
        }

        memo[index][target] = findProbability(index + 1, n, memo, prob, target - 1) * prob[index] +
                              findProbability(index + 1, n, memo, prob, target) * (1 - prob[index]);

        return memo[index][target];
    }

    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> memo(n, vector<double>(target + 1, -1));

        return findProbability(0, n, memo, prob, target);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private double findProbability(int index, int n, double[][] memo, double[] prob, int target) {
        // Return 0 if the target is less than zero because we have more heads
        // than we need.
        if (target < 0) {
            return 0;
        }
        // After tossing all of the coins, if we get the required number of heads,
        // return 1 to count this case, otherwise return 0.
        if (index == n) {
            return target == 0 ? 1 : 0;
        }

        if (memo[index][target] != -1) {
            return memo[index][target];
        }

        memo[index][target] = findProbability(index + 1, n, memo, prob, target - 1) * prob[index] +
                              findProbability(index + 1, n, memo, prob, target) * (1 - prob[index]);

        return memo[index][target];
    }

    public double probabilityOfHeads(double[] prob, int target) {
        int n = prob.length;
        double[][] memo = new double[n][target + 1];
        for (double[] row : memo) {
            Arrays.fill(row, -1);
        }

        return findProbability(0, n, memo, prob, target);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        memo = {}

        def findProbability(index, target, n):
            # Return 0 if the target is less than zero because we have more heads
            # than we need.
            if target < 0:
                return 0
            # After tossing all of the coins, if we get the required number of heads,
            # return 1 to count this case, otherwise return 0.
            if index == n:
                if target == 0:
                    return 1
                else:
                    return 0

            if (index, target) in memo:
                return memo[index, target]

            memo[index, target] = findProbability(index + 1, target - 1, n) * prob[index] + \
                                  findProbability(index + 1, target, n) * (1 - prob[index])

            return memo[index, target]

        return findProbability(0, target, len(prob))
```

</details>

<br>

## Approach 2: Iterative Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> dp(n + 1, vector<double>(target + 1));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1]);
            for (int j = 1; j <= target && j <= i; j++) {
                dp[i][j] = dp[i - 1][j - 1] * prob[i - 1] + dp[i - 1][j] * (1 - prob[i - 1]);
            }
        }

        return dp[n][target];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        int n = prob.length;
        double[][] dp = new double[n + 1][target + 1];
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1]);
            for (int j = 1; j <= target && j <= i; j++) {
                dp[i][j] = dp[i - 1][j - 1] * prob[i - 1] + dp[i - 1][j] * (1 - prob[i - 1]);
            }
        }

        return dp[n][target];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        n = len(prob)
        dp = [[0] * (target + 1) for _ in range(n + 1)]
        dp[0][0] = 1

        for i in range(1, n + 1):
            dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1])
            for j in range(1, target + 1):
                if j > i:
                    break
                dp[i][j] = dp[i - 1][j - 1] * prob[i - 1] + dp[i - 1][j] * (1 - prob[i - 1])

        return dp[n][target]
```

</details>

<br>

## Approach 3: Dynamic Programming with Space Optimization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<double> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= 1; j--) {
                dp[j] = dp[j - 1] * prob[i - 1] + dp[j] * (1 - prob[i - 1]);
            }
            dp[0] = dp[0] * (1 - prob[i - 1]);
        }

        return dp[target];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        int n = prob.length;
        double[] dp = new double[target + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= 1; j--) {
                dp[j] = dp[j - 1] * prob[i - 1] + dp[j] * (1 - prob[i - 1]);
            }
            dp[0] = dp[0] * (1 - prob[i - 1]);
        }

        return dp[target];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def probabilityOfHeads(self, prob, target):
        n = len(prob)
        dp = [0] * (target + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            for j in range(target, 0, -1):
                dp[j] = dp[j - 1] * prob[i - 1] + dp[j] * (1 - prob[i - 1])
            dp[0] = dp[0] * (1 - prob[i - 1])

        return dp[target]
```

</details>
