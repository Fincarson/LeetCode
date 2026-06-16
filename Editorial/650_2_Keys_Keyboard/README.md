# 650. 2 Keys Keyboard

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/2-keys-keyboard/)  
`Math` `Dynamic Programming`

**Problem Link:** [LeetCode 650 - 2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/)

## Problem

There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

- Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
- Paste: You can paste the characters which are copied last time.

Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

### Example 1

```text
Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
```

### Example 2

```text
Input: n = 1
Output: 0
```

## Constraints

- 1 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [4 Keys Keyboard](https://leetcode.com/problems/4-keys-keyboard/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Broken Calculator](https://leetcode.com/problems/broken-calculator/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Smallest Value After Replacing With Sum of Prime Factors](https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Distinct Prime Factors of Product of Array](https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 650. 2 Keys Keyboard

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion / Backtracking | C++, Java, Python3 |
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Prime Factorization | C++, Java, Python3 |

## Approach 1: Recursion / Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    int n;

public:
    int minSteps(int n) {
        if (n == 1) return 0;
        this->n = n;
        // first step is always a Copy All operation
        return 1 + minStepsHelper(1, 1);
    }

private:
    int minStepsHelper(int currLen, int pasteLen) {
        // base case: reached n A's, don't need more operations
        if (currLen == n) return 0;
        // base case: exceeded n `A`s, not a valid sequence, so
        // return max value
        if (currLen > n) return 1000;

        // copy all + paste
        int opt1 = 2 + minStepsHelper(currLen * 2, currLen);
        // paste
        int opt2 = 1 + minStepsHelper(currLen + pasteLen, pasteLen);

        return min(opt1, opt2);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    int n;

    public int minSteps(int n) {
        if (n == 1) return 0;
        this.n = n;
        // first step is always a Copy All operation
        return 1 + minStepsHelper(1, 1);
    }

    private int minStepsHelper(int currLen, int pasteLen) {
        // base case: reached n A's, don't need more operations
        if (currLen == n) return 0;
        // base case: exceeded n `A`s, not a valid sequence, so
        // return max value
        if (currLen > n) return 1000;

        // copy all + paste
        int opt1 = 2 + minStepsHelper(currLen * 2, currLen);
        // paste
        int opt2 = 1 + minStepsHelper(currLen + pasteLen, pasteLen);

        return Math.min(opt1, opt2);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def __init__(self):
        self.n = 0

    def _min_steps_helper(self, curr_len, paste_len):
        # base case: reached n A's, don't need more operations
        if curr_len == self.n:
            return 0
        # base case: exceeded n `A`s, not a valid sequence, so
        # return max value
        if curr_len > self.n:
            return 1000

        # copy all + paste
        opt1 = 2 + self._min_steps_helper(curr_len * 2, curr_len)
        # paste
        opt2 = 1 + self._min_steps_helper(curr_len + paste_len, paste_len)

        return min(opt1, opt2)

    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0
        self.n = n
        # first step is always a Copy All operation
        return 1 + self._min_steps_helper(1, 1)
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int minSteps(int n) {
        if (n == 1) return 0;
        this->n = n;

        memo = vector<vector<int>>(n + 1, vector<int>(n / 2 + 1, 0));
        return 1 + minStepsHelper(1, 1);
    }

    int minStepsHelper(int currLen, int pasteLen) {
        if (currLen == n) return 0;
        if (currLen > n) return 1000;

        // return result if it has been calculated already
        if (memo[currLen][pasteLen] != 0) return memo[currLen][pasteLen];

        int opt1 = 1 + minStepsHelper(currLen + pasteLen, pasteLen);
        int opt2 = 2 + minStepsHelper(currLen * 2, currLen);
        memo[currLen][pasteLen] = min(opt1, opt2);
        return memo[currLen][pasteLen];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    int n;

    public int minSteps(int n) {
        if (n == 1) return 0;
        this.n = n;

        int[][] memo = new int[n + 1][n / 2 + 1];
        return 1 + minStepsHelper(1, 1, memo);
    }

    private int minStepsHelper(int currLen, int pasteLen, int[][] memo) {
        if (currLen == n) return 0;
        if (currLen > n) return 1000;

        // return result if it has been calculated already
        if (memo[currLen][pasteLen] != 0) return memo[currLen][pasteLen];

        int opt1 = 1 + minStepsHelper(currLen + pasteLen, pasteLen, memo);
        int opt2 = 2 + minStepsHelper(currLen * 2, currLen, memo);
        memo[currLen][pasteLen] = Math.min(opt1, opt2);
        return memo[currLen][pasteLen];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0
        self.n = n

        self.memo = [[0] * (n // 2 + 1) for _ in range(n + 1)]
        return 1 + self._min_steps_helper(1, 1)

    def _min_steps_helper(self, curr_len: int, paste_len: int) -> int:
        if curr_len == self.n:
            return 0
        if curr_len > self.n:
            return 1000

        # return result if it has been calculated already
        if self.memo[curr_len][paste_len] != 0:
            return self.memo[curr_len][paste_len]

        opt1 = 1 + self._min_steps_helper(curr_len + paste_len, paste_len)
        opt2 = 2 + self._min_steps_helper(curr_len * 2, curr_len)
        self.memo[curr_len][paste_len] = min(opt1, opt2)
        return self.memo[curr_len][paste_len]
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 1000);

        // Base case
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                // Copy All and Paste (i-j) / j times
                // for all valid j's
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + i / j);
                }
            }
        }

        return dp[n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minSteps(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 1000);

        // Base case
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                // Copy All and Paste (i-j) / j times
                // for all valid j's
                if (i % j == 0) {
                    dp[i] = Math.min(dp[i], dp[j] + i / j);
                }
            }
        }

        return dp[n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSteps(self, n: int) -> int:
        dp = [1000] * (n + 1)

        # Base case
        dp[1] = 0
        for i in range(2, n + 1):
            for j in range(1, i // 2 + 1):
                # Copy All and Paste (i-j) / j times
                # for all valid j's
                if i % j == 0:
                    dp[i] = min(dp[i], dp[j] + i // j)

        return dp[n]
```

</details>

<br>

## Approach 4: Prime Factorization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int d = 2;
        while (n > 1) {
            // If d is prime factor, keep dividing
            // n by d until is no longer divisible
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minSteps(int n) {
        int ans = 0;
        int d = 2;
        while (n > 1) {
            // If d is prime factor, keep dividing
            // n by d until is no longer divisible
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSteps(self, n: int) -> int:
        ans = 0
        d = 2
        while n > 1:
            # If d is prime factor, keep dividing
            # n by d until is no longer divisible
            while n % d == 0:
                ans += d
                n //= d
            d += 1
        return ans
```

</details>
