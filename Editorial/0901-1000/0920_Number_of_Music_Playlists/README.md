# 920. Number of Music Playlists

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/number-of-music-playlists/)  
`Math` `Dynamic Programming` `Combinatorics`

**Problem Link:** [LeetCode 920 - Number of Music Playlists](https://leetcode.com/problems/number-of-music-playlists/)

## Problem

Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:

- Every song is played at least once.
- A song can only be played again only if k other songs have been played.

Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 109 + 7.

### Example 1

```text
Input: n = 3, goal = 3, k = 1
Output: 6
Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].
```

### Example 2

```text
Input: n = 2, goal = 3, k = 0
Output: 6
Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], and [1, 2, 2].
```

### Example 3

```text
Input: n = 2, goal = 3, k = 1
Output: 2
Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].
```

## Constraints

- 0 <= k < n <= goal <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count the Number of Good Subsequences](https://leetcode.com/problems/count-the-number-of-good-subsequences/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 920. Number of Music Playlists

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bottom-up Dynamic Programming | C++, Java, Python3 |
| Top-down Dynamic Programming (Memoization) | C++, Java, Python3 |
| Combinatorics | C++, Java, Python3 |

## Approach 1: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int MOD = 1e9 + 7;

        // Initialize the DP table
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= min(i, n); j++) {
                // The i-th song is a new song
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) % MOD;
                // The i-th song is a song we have played before
                if (j > k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
                }
            }
        }

        return dp[goal][n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numMusicPlaylists(int n, int goal, int k) {
        int MOD = 1_000_000_007;

        // Initialize the DP table
        long[][] dp = new long[goal + 1][n + 1];
        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= Math.min(i, n); j++) {
                // The i-th song is a new song
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) % MOD;
                // The i-th song is a song we have played before
                if (j > k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
                }
            }
        }

        return (int) dp[goal][n];
    }

}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        MOD = 10**9 + 7

        # Initialize the DP table
        dp = [[0 for _ in range(n + 1)] for _ in range(goal + 1)]
        dp[0][0] = 1

        for i in range(1, goal + 1):
            for j in range(1, min(i, n) + 1):
                # The i-th song is a new song
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) % MOD
                # The i-th song is a song we have played before
                if j > k:
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD

        return dp[goal][n]
```

</details>

<br>

## Approach 2: Top-down Dynamic Programming (Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int MOD = 1e9 + 7;
        vector dp(goal + 1, vector<long>(n + 1, -1));

        function<long(int, int)> numberOfPlaylists = [&](int i, int j) -> long {
            // Base cases
            if (i == 0 && j == 0) {
                return 1LL;
            }
            if (i == 0 || j == 0) {
                return 0LL;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            // DP transition: add a new song or replay an old one
            dp[i][j] = (numberOfPlaylists(i - 1, j - 1) * (n - j + 1)) % MOD;
            if (j > k) {
                dp[i][j] += (numberOfPlaylists(i - 1, j) * (j - k)) % MOD;
                dp[i][j] %= MOD;
            }
            return dp[i][j];
        };

        return numberOfPlaylists(goal, n);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    private final int MOD = 1_000_000_007;
    private Long[][] dp;

    public int numMusicPlaylists(int n, int goal, int k) {
        dp = new Long[goal + 1][n + 1];
        for(Long[] row : dp) {
            Arrays.fill(row, -1L);
        }
        return (int) (numberOfPlaylists(goal, n, k, n));
    }

    private long numberOfPlaylists(int i, int j, int k, int n) {
        // Base cases
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i == 0 || j == 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // DP transition: add a new song or replay an old one
        dp[i][j] = (numberOfPlaylists(i - 1, j - 1, k, n) * (n - j + 1)) % MOD;
        if (j > k) {
            dp[i][j] += (numberOfPlaylists(i - 1, j, k, n) * (j - k)) % MOD;
            dp[i][j] %= MOD;
        }
        return dp[i][j];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        MOD = 1_000_000_007
        dp = [[-1 for _ in range(n + 1)] for _ in range(goal + 1)]

        def number_of_playlists(i, j):
            # Base cases
            if i == 0 and j == 0:
                return 1
            if i == 0 or j == 0:
                return 0
            if dp[i][j] != -1:
                return dp[i][j]
            # DP transition: add a new song or replay an old one
            dp[i][j] = (number_of_playlists(i - 1, j - 1) * (n - j + 1)) % MOD
            if j > k:
                dp[i][j] += (number_of_playlists(i - 1, j) * (j - k)) % MOD
                dp[i][j] %= MOD
            return dp[i][j]

        return number_of_playlists(goal, n)
```

</details>

<br>

## Approach 3: Combinatorics

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
#include <vector>

class Solution {
private:
    static const long long MOD = 1e9 + 7;
    vector<long long> factorial;
    vector<long long> invFactorial;

    // Function to calculate power under modulo MOD
    long long power(long long base, int exponent) {
        long long result = 1;
        // Loop until exponent is not zero
        while (exponent > 0) {
            // If exponent is odd, multiply result with base
            if (exponent & 1) {
                result = (result * base) % MOD;
            }
            // Divide the exponent by 2 and square the base
            exponent >>= 1;
            base = (base * base) % MOD;
        }
        return result;
    }

    // Function to pre-calculate factorials and inverse factorials
    void precalculateFactorials(int n) {
        factorial.resize(n + 1);
        invFactorial.resize(n + 1);
        factorial[0] = invFactorial[0] = 1;
        // Calculate factorials and inverse factorials for each number up to 'n'
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
            // Inverse factorial calculated using Fermat's Little Theorem
            invFactorial[i] = power(factorial[i], MOD - 2);
        }
    }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        // Pre-calculate factorials and inverse factorials
        precalculateFactorials(n);
        // Initialize variables for calculation
        int sign = 1;
        long long answer = 0;
        // Loop from 'n' down to 'k'
        for (int i = n; i >= k; i--) {
            // Calculate temporary result for this iteration
            long long temp = power(i - k, goal - k);
            temp = (temp * invFactorial[n - i]) % MOD;
            temp = (temp * invFactorial[i - k]) % MOD;
            // Add or subtract temporary result to/from answer
            answer = (answer + sign * temp + MOD) % MOD;
            // Flip sign for next iteration
            sign *= -1;
        }
        // Final result is n! * answer, all under modulo
        return (factorial[n] * answer) % MOD;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    private static final long MOD = 1_000_000_007;

    // Pre-calculated factorials and inverse factorials
    private long[] factorial;
    private long[] invFactorial;

    // Main method: calculates number of playlists
    public int numMusicPlaylists(int n, int goal, int k) {
        // Pre-calculate factorials and inverse factorials
        precalculateFactorials(n);

        // Initialize variables for calculation
        int sign = 1;
        long answer = 0;

        // Loop from 'n' down to 'k'
        for (int i = n; i >= k; i--) {
            // Calculate temporary result for this iteration
            long temp = power(i - k, goal - k);
            temp = (temp * invFactorial[n - i]) % MOD;
            temp = (temp * invFactorial[i - k]) % MOD;

            // Add or subtract temporary result to/from answer
            answer = (answer + sign * temp + MOD) % MOD;

            // Flip sign for next iteration
            sign *= -1;
        }

        // Final result is n! * answer, all under modulo
        return (int) ((factorial[n] * answer) % MOD);
    }

    // Method to pre-calculate factorials and inverse factorials up to 'n'
    private void precalculateFactorials(int n) {
        factorial = new long[n + 1];
        invFactorial = new long[n + 1];
        factorial[0] = invFactorial[0] = 1;

        // Calculate factorials and inverse factorials for each number up to 'n'
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
            // Inverse factorial calculated using Fermat's Little Theorem
            invFactorial[i] = power(factorial[i], (int) (MOD - 2));
        }
    }

    // Method to calculate power of a number under modulo using binary exponentiation
    private long power(long base, int exponent) {
        long result = 1L;

        // Loop until exponent is not zero
        while (exponent > 0) {
            // If exponent is odd, multiply result with base
            if ((exponent & 1) == 1) {
                result = (result * base) % MOD;
            }
            // Divide the exponent by 2 and square the base
            exponent >>= 1;
            base = (base * base) % MOD;
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    MOD = 1_000_000_007

    def power(self, base, exponent):
        result = 1
        # Loop until exponent is not zero
        while exponent > 0:
            # If exponent is odd, multiply result with base
            if exponent & 1:
                result = (result * base) % self.MOD
            # Divide the exponent by 2 and square the base
            exponent >>= 1
            base = (base * base) % self.MOD
        return result

    def precalculate_factorials(self, n):
        self.factorial = [1] * (n + 1)
        self.inv_factorial = [1] * (n + 1)
        # Calculate factorials and inverse factorials for each number up to 'n'
        for i in range(1, n + 1):
            self.factorial[i] = (self.factorial[i - 1] * i) % self.MOD
            # Inverse factorial calculated using Fermat's Little Theorem
            self.inv_factorial[i] = self.power(self.factorial[i], self.MOD - 2)

    def numMusicPlaylists(self, n, goal, k):
        # Pre-calculate factorials and inverse factorials
        self.precalculate_factorials(n)
        # Initialize variables for calculation
        sign = 1
        answer = 0
        # Loop from 'n' down to 'k'
        for i in range(n, k - 1, -1):
            # Calculate temporary result for this iteration
            temp = self.power(i - k, goal - k)
            temp = (temp * self.inv_factorial[n - i]) % self.MOD
            temp = (temp * self.inv_factorial[i - k]) % self.MOD
            # Add or subtract temporary result to/from answer
            answer = (answer + sign * temp + self.MOD) % self.MOD
            # Flip sign for next iteration
            sign *= -1
        # Final result is n! * answer, all under modulo
        return (self.factorial[n] * answer) % self.MOD
```

</details>
