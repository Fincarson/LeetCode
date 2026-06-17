# 552. Student Attendance Record II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/student-attendance-record-ii/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 552 - Student Attendance Record II](https://leetcode.com/problems/student-attendance-record-ii/)

## Problem

An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

- 'A': Absent.
- 'L': Late.
- 'P': Present.

Any student is eligible for an attendance award if they meet both of the following criteria:

- The student was absent ('A') for strictly fewer than 2 days total.
- The student was never late ('L') for 3 or more consecutive days.

Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

### Example 1

```text
Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
```

### Example 2

```text
Input: n = 1
Output: 3
```

### Example 3

```text
Input: n = 10101
Output: 183236316
```

## Constraints

- 1 <= n <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Student Attendance Record I](https://leetcode.com/problems/student-attendance-record-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 552. Student Attendance Record II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming with Memoization | C++, Java, JavaScript, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, JavaScript, Python3 |
| Bottom-Up Dynamic Programming, Space Optimized | C++, Java, JavaScript, Python3 |

## Approach 1: Top-Down Dynamic Programming with Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    int MOD = 1000000007;
    // Cache to store sub-problem results.
    vector<vector<vector<int>>> memo;

public:
    // Recursive function to return the count of combinations of length 'n'
    // eligible for the award.
    int eligibleCombinations(int n, int totalAbsences, int consecutiveLates) {
        // If the combination has become not eligible for the award,
        // then we will not count any combinations that can be made using it.
        if (totalAbsences >= 2 or consecutiveLates >= 3) {
            return 0;
        }
        // If we have generated a combination of length 'n' we will count it.
        if (n == 0) {
            return 1;
        }
        // If we have already seen this sub-problem earlier, we return the
        // stored result.
        if (memo[n][totalAbsences][consecutiveLates] != -1) {
            return memo[n][totalAbsences][consecutiveLates];
        }

        int count = 0;
        // We choose 'P' for the current position.
        count = eligibleCombinations(n - 1, totalAbsences, 0);
        // We choose 'A' for the current position.
        count =
            (count + eligibleCombinations(n - 1, totalAbsences + 1, 0)) % MOD;
        // We choose 'L' for the current position.
        count = (count + eligibleCombinations(n - 1, totalAbsences,
                                              consecutiveLates + 1)) %
                MOD;

        // Return and store the current sub-problem result in the cache.
        return memo[n][totalAbsences][consecutiveLates] = count;
    }

    int checkRecord(int n) {
        // Initialize the cache.
        memo = vector<vector<vector<int>>>(
            n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        // Return count of combinations of length 'n' eligible for the award.
        return eligibleCombinations(n, 0, 0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private final int MOD = 1000000007;
    // Cache to store sub-problem results.
    private int[][][] memo;

    // Recursive function to return the count of combinations of length 'n' eligible for the award.
    private int eligibleCombinations(
        int n,
        int totalAbsences,
        int consecutiveLates
    ) {
        // If the combination has become not eligible for the award,
        // then we will not count any combinations that can be made using it.
        if (totalAbsences >= 2 || consecutiveLates >= 3) {
            return 0;
        }
        // If we have generated a combination of length 'n' we will count it.
        if (n == 0) {
            return 1;
        }
        // If we have already seen this sub-problem earlier, we return the stored result.
        if (memo[n][totalAbsences][consecutiveLates] != -1) {
            return memo[n][totalAbsences][consecutiveLates];
        }

        int count = 0;
        // We choose 'P' for the current position.
        count = eligibleCombinations(n - 1, totalAbsences, 0) % MOD;
        // We choose 'A' for the current position.
        count = (count + eligibleCombinations(n - 1, totalAbsences + 1, 0)) %
        MOD;
        // We choose 'L' for the current position.
        count = (count +
            eligibleCombinations(n - 1, totalAbsences, consecutiveLates + 1)) %
        MOD;

        // Return and store the current sub-problem result in the cache.
        return memo[n][totalAbsences][consecutiveLates] = count;
    }

    public int checkRecord(int n) {
        // Initialize the cache.
        memo = new int[n + 1][2][3];
        for (int[][] array2D : memo) {
            for (int[] array1D : array2D) {
                Arrays.fill(array1D, -1);
            }
        }
        // Return count of combinations of length 'n' eligible for the award.
        return eligibleCombinations(n, 0, 0);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var checkRecord = function (n) {
    let MOD = 1000000007;
    // Initialize the cache to store sub-problem results.
    let memo = new Array(n + 1)
        .fill(null)
        .map(() => new Array(2).fill(null).map(() => new Array(3).fill(-1)));

    // Recursive function to return the count of combinations of length 'n' eligible for the award.
    let eligibleCombinations = (n, totalAbsences, consecutiveLates) => {
        // If the combination has become not eligible for the award,
        // then we will not count any combinations that can be made using it.
        if (totalAbsences >= 2 || consecutiveLates >= 3) {
            return 0;
        }
        // If we have generated a combination of length 'n' we will count it.
        if (n === 0) {
            return 1;
        }
        // If we have already seen this sub-problem earlier, we return the stored result.
        if (memo[n][totalAbsences][consecutiveLates] !== -1) {
            return memo[n][totalAbsences][consecutiveLates];
        }

        let count = 0;
        // We choose 'P' for the current position.
        count = eligibleCombinations(n - 1, totalAbsences, 0);
        // We choose 'A' for the current position.
        count =
            (count + eligibleCombinations(n - 1, totalAbsences + 1, 0)) % MOD;
        // We choose 'L' for the current position.
        count =
            (count +
                eligibleCombinations(
                    n - 1,
                    totalAbsences,
                    consecutiveLates + 1,
                )) %
            MOD;

        // Return and store the current sub-problem result in the cache.
        memo[n][totalAbsences][consecutiveLates] = count;
        return count;
    };

    // Return count of combinations of length 'n' eligible for the award.
    return eligibleCombinations(n, 0, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 1000000007
        # Initialize the cache to store sub-problem results.
        memo = [[[-1] * 3 for _ in range(2)] for _ in range(n + 1)]

        # Recursive function to return the count of combinations
        # of length 'n' eligible for the award.
        def eligible_combinations(n, total_absences, consecutive_lates):
            # If the combination has become not eligible for the award,
            # then we will not count any combinations that can be made using it.
            if total_absences >= 2 or consecutive_lates >= 3:
                return 0
            # If we have generated a combination of length 'n' we will count it.
            if n == 0:
                return 1
            # If we have already seen this sub-problem earlier,
            # we return the stored result.
            if memo[n][total_absences][consecutive_lates] != -1:
                return memo[n][total_absences][consecutive_lates]

            # We choose 'P' for the current position.
            count = eligible_combinations(n - 1, total_absences, 0)
            # We choose 'A' for the current position.
            count = (
                count + eligible_combinations(n - 1, total_absences + 1, 0)
            ) % MOD
            # We choose 'L' for the current position.
            count = (
                count
                + eligible_combinations(
                    n - 1, total_absences, consecutive_lates + 1
                )
            ) % MOD

            # Return and store the current sub-problem result in the cache.
            memo[n][total_absences][consecutive_lates] = count
            return count

        # Return count of combinations of length 'n' eligible for the award.
        return eligible_combinations(n, 0, 0)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int checkRecord(int n) {
        int MOD = 1000000007;
        // Cache to store sub-problem results.
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dp[0][0][0] = 1;

        // Iterate on smaller sub-problems and use the current smaller
        // sub-problem to generate results for bigger sub-problems.
        for (int len = 0; len < n; ++len) {
            for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
                for (int consecutiveLates = 0; consecutiveLates <= 2;
                     ++consecutiveLates) {
                    // Store the count when 'P' is chosen.
                    dp[len + 1][totalAbsences][0] =
                        (dp[len + 1][totalAbsences][0] +
                         dp[len][totalAbsences][consecutiveLates]) %
                        MOD;
                    // Store the count when 'A' is chosen.
                    if (totalAbsences < 1) {
                        dp[len + 1][totalAbsences + 1][0] =
                            (dp[len + 1][totalAbsences + 1][0] +
                             dp[len][totalAbsences][consecutiveLates]) %
                            MOD;
                    }
                    // Store the count when 'L' is chosen.
                    if (consecutiveLates < 2) {
                        dp[len + 1][totalAbsences][consecutiveLates + 1] =
                            (dp[len + 1][totalAbsences][consecutiveLates + 1] +
                             dp[len][totalAbsences][consecutiveLates]) %
                            MOD;
                    }
                }
            }
        }

        // Sum up the counts for all combinations of length 'n' with different
        // absent and late counts.
        int count = 0;
        for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (int consecutiveLates = 0; consecutiveLates <= 2;
                 ++consecutiveLates) {
                count = (count + dp[n][totalAbsences][consecutiveLates]) % MOD;
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int checkRecord(int n) {
        int MOD = 1000000007;
        // Cache to store sub-problem results.
        int[][][] dp = new int[n + 1][2][3];

        // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dp[0][0][0] = 1;

        // Iterate on smaller sub-problems and use the current smaller sub-problem
        // to generate results for bigger sub-problems.
        for (int len = 0; len < n; ++len) {
            for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
                for (
                    int consecutiveLates = 0;
                    consecutiveLates <= 2;
                    ++consecutiveLates
                ) {
                    // Store the count when 'P' is chosen.
                    dp[len + 1][totalAbsences][0] = (dp[len +
                            1][totalAbsences][0] +
                        dp[len][totalAbsences][consecutiveLates]) %
                    MOD;
                    // Store the count when 'A' is chosen.
                    if (totalAbsences < 1) {
                        dp[len + 1][totalAbsences + 1][0] = (dp[len +
                                1][totalAbsences + 1][0] +
                            dp[len][totalAbsences][consecutiveLates]) %
                        MOD;
                    }
                    // Store the count when 'L' is chosen.
                    if (consecutiveLates < 2) {
                        dp[len + 1][totalAbsences][consecutiveLates + 1] =
                            (dp[len + 1][totalAbsences][consecutiveLates + 1] +
                                dp[len][totalAbsences][consecutiveLates]) %
                            MOD;
                    }
                }
            }
        }

        // Sum up the counts for all combinations of length 'n' with different absent and late counts.
        int count = 0;
        for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (
                int consecutiveLates = 0;
                consecutiveLates <= 2;
                ++consecutiveLates
            ) {
                count = (count + dp[n][totalAbsences][consecutiveLates]) % MOD;
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var checkRecord = function (n) {
    const MOD = 1000000007;
    // Cache to store sub-problem results.
    const dp = new Array(n + 1)
        .fill(null)
        .map(() => new Array(2).fill(null).map(() => new Array(3).fill(0)));

    // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
    dp[0][0][0] = 1;

    // Iterate on smaller sub-problems and use the current smaller sub-problem
    // to generate results for bigger sub-problems.
    for (let len = 0; len < n; ++len) {
        for (let totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (
                let consecutiveLates = 0;
                consecutiveLates <= 2;
                ++consecutiveLates
            ) {
                // Store the count when 'P' is chosen.
                dp[len + 1][totalAbsences][0] =
                    (dp[len + 1][totalAbsences][0] +
                        dp[len][totalAbsences][consecutiveLates]) %
                    MOD;
                // Store the count when 'A' is chosen.
                if (totalAbsences < 1) {
                    dp[len + 1][totalAbsences + 1][0] =
                        (dp[len + 1][totalAbsences + 1][0] +
                            dp[len][totalAbsences][consecutiveLates]) %
                        MOD;
                }
                // Store the count when 'L' is chosen.
                if (consecutiveLates < 2) {
                    dp[len + 1][totalAbsences][consecutiveLates + 1] =
                        (dp[len + 1][totalAbsences][consecutiveLates + 1] +
                            dp[len][totalAbsences][consecutiveLates]) %
                        MOD;
                }
            }
        }
    }

    // Sum up the counts for all combinations of length 'n' with different absent and late counts.
    let count = 0;
    for (let totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
        for (
            let consecutiveLates = 0;
            consecutiveLates <= 2;
            ++consecutiveLates
        ) {
            count = (count + dp[n][totalAbsences][consecutiveLates]) % MOD;
        }
    }
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 1000000007
        # Cache to store sub-problem results.
        dp = [[[0] * 3 for _ in range(2)] for _ in range(n + 1)]

        # Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dp[0][0][0] = 1

        # Iterate on smaller sub-problems and use the current smaller sub-problem
        # to generate results for bigger sub-problems.
        for length in range(n):
            for total_absences in range(2):
                for consecutive_lates in range(3):
                    # Store the count when 'P' is chosen.
                    dp[length + 1][total_absences][0] = (
                        dp[length + 1][total_absences][0]
                        + dp[length][total_absences][consecutive_lates]
                    ) % MOD
                    # Store the count when 'A' is chosen.
                    if total_absences < 1:
                        dp[length + 1][total_absences + 1][0] = (
                            dp[length + 1][total_absences + 1][0]
                            + dp[length][total_absences][consecutive_lates]
                        ) % MOD
                    # Store the count when 'L' is chosen.
                    if consecutive_lates < 2:
                        dp[length + 1][total_absences][
                            consecutive_lates + 1
                        ] = (
                            dp[length + 1][total_absences][
                                consecutive_lates + 1
                            ]
                            + dp[length][total_absences][consecutive_lates]
                        ) % MOD

        # Sum up the counts for all combinations of length 'n' with different absent and late counts.
        count = 0
        for total_absences in range(2):
            for consecutive_lates in range(3):
                count = (count + dp[n][total_absences][consecutive_lates]) % MOD

        return count
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming, Space Optimized

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int checkRecord(int n) {
        int MOD = 1000000007;
        // Cache to store current sub-problem results.
        vector<vector<int>> dpCurrState =
            vector<vector<int>>(2, vector<int>(3, 0));
        // Cache to store next sub-problem results.
        vector<vector<int>> dpNextState =
            vector<vector<int>>(2, vector<int>(3, 0));

        // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dpCurrState[0][0] = 1;

        // Iterate on smaller sub-problems and use the current smaller
        // sub-problem to generate results for bigger sub-problems.
        for (int len = 0; len < n; ++len) {
            for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
                for (int consecutiveLates = 0; consecutiveLates <= 2;
                     ++consecutiveLates) {
                    // Store the count when 'P' is chosen.
                    dpNextState[totalAbsences][0] =
                        (dpNextState[totalAbsences][0] +
                         dpCurrState[totalAbsences][consecutiveLates]) %
                        MOD;
                    // Store the count when 'A' is chosen.
                    if (totalAbsences < 1) {
                        dpNextState[totalAbsences + 1][0] =
                            (dpNextState[totalAbsences + 1][0] +
                             dpCurrState[totalAbsences][consecutiveLates]) %
                            MOD;
                    }
                    // Store the count when 'L' is chosen.
                    if (consecutiveLates < 2) {
                        dpNextState[totalAbsences][consecutiveLates + 1] =
                            (dpNextState[totalAbsences][consecutiveLates + 1] +
                             dpCurrState[totalAbsences][consecutiveLates]) %
                            MOD;
                    }
                }
            }

            // Next state sub-problems will become current state sub-problems in
            // next iteration.
            dpCurrState = dpNextState;
            // Next state sub-problem results will reset to zero.
            dpNextState = vector<vector<int>>(2, vector<int>(3, 0));
        }

        // Sum up the counts for all combinations of length 'n' with different
        // absent and late counts.
        int count = 0;
        for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (int consecutiveLates = 0; consecutiveLates <= 2;
                 ++consecutiveLates) {
                count = (count + dpCurrState[totalAbsences][consecutiveLates]) %
                        MOD;
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int checkRecord(int n) {
        int MOD = 1000000007;
        // Cache to store current sub-problem results.
        int[][] dpCurrState = new int[2][3];
        // Cache to store next sub-problem results.
        int[][] dpNextState = new int[2][3];

        // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dpCurrState[0][0] = 1;

        // Iterate on smaller sub-problems and use the current smaller sub-problem
        // to generate results for bigger sub-problems.
        for (int len = 0; len < n; ++len) {
            for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
                for (
                    int consecutiveLates = 0;
                    consecutiveLates <= 2;
                    ++consecutiveLates
                ) {
                    // Store the count when 'P' is chosen.
                    dpNextState[totalAbsences][0] =
                        (dpNextState[totalAbsences][0] +
                            dpCurrState[totalAbsences][consecutiveLates]) %
                        MOD;
                    // Store the count when 'A' is chosen.
                    if (totalAbsences < 1) {
                        dpNextState[totalAbsences + 1][0] =
                            (dpNextState[totalAbsences + 1][0] +
                                dpCurrState[totalAbsences][consecutiveLates]) %
                            MOD;
                    }
                    // Store the count when 'L' is chosen.
                    if (consecutiveLates < 2) {
                        dpNextState[totalAbsences][consecutiveLates + 1] =
                            (dpNextState[totalAbsences][consecutiveLates + 1] +
                                dpCurrState[totalAbsences][consecutiveLates]) %
                            MOD;
                    }
                }
            }

            // Next state sub-problems will become current state sub-problems in the next iteration.
            System.arraycopy(
                dpNextState,
                0,
                dpCurrState,
                0,
                dpCurrState.length
            );
            // Next state sub-problem results will reset to zero.
            dpNextState = new int[2][3];
        }

        // Sum up the counts for all combinations of length 'n' with different absent and late counts.
        int count = 0;
        for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (
                int consecutiveLates = 0;
                consecutiveLates <= 2;
                ++consecutiveLates
            ) {
                count = (count + dpCurrState[totalAbsences][consecutiveLates]) %
                MOD;
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var checkRecord = function (n) {
    const MOD = 1000000007;
    // Cache to store current sub-problem results.
    let dpCurrState = Array.from({ length: 2 }, () => Array(3).fill(0));
    // Cache to store next sub-problem results.
    let dpNextState = Array.from({ length: 2 }, () => Array(3).fill(0));

    // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
    dpCurrState[0][0] = 1;

    // Iterate on smaller sub-problems and use the current smaller sub-problem
    // to generate results for bigger sub-problems.
    for (let len = 0; len < n; ++len) {
        for (let totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (
                let consecutiveLates = 0;
                consecutiveLates <= 2;
                ++consecutiveLates
            ) {
                // Store the count when 'P' is chosen.
                dpNextState[totalAbsences][0] =
                    (dpNextState[totalAbsences][0] +
                        dpCurrState[totalAbsences][consecutiveLates]) %
                    MOD;
                // Store the count when 'A' is chosen.
                if (totalAbsences < 1) {
                    dpNextState[totalAbsences + 1][0] =
                        (dpNextState[totalAbsences + 1][0] +
                            dpCurrState[totalAbsences][consecutiveLates]) %
                        MOD;
                }
                // Store the count when 'L' is chosen.
                if (consecutiveLates < 2) {
                    dpNextState[totalAbsences][consecutiveLates + 1] =
                        (dpNextState[totalAbsences][consecutiveLates + 1] +
                            dpCurrState[totalAbsences][consecutiveLates]) %
                        MOD;
                }
            }
        }

        // Next state sub-problems will become current state sub-problems in the next iteration.
        dpCurrState = dpNextState.map((row) => row.slice());
        // Next state sub-problem results will reset to zero.
        dpNextState = Array.from({ length: 2 }, () => Array(3).fill(0));
    }

    // Sum up the counts for all combinations of length 'n' with different absent and late counts.
    let count = dpCurrState.flat().reduce((acc, val) => (acc + val) % MOD, 0);
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 1000000007
        # Cache to store current sub-problem results.
        dp_curr_state = [[0] * 3 for _ in range(2)]
        # Cache to store next sub-problem results.
        dp_next_state = [[0] * 3 for _ in range(2)]

        # Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dp_curr_state[0][0] = 1

        # Iterate on smaller sub-problems and use the current smaller sub-problem
        # to generate results for bigger sub-problems.
        for _ in range(n):
            for total_absences in range(2):
                for consecutive_lates in range(3):
                    # Store the count when 'P' is chosen.
                    dp_next_state[total_absences][0] = (
                        dp_next_state[total_absences][0]
                        + dp_curr_state[total_absences][consecutive_lates]
                    ) % MOD
                    # Store the count when 'A' is chosen.
                    if total_absences < 1:
                        dp_next_state[total_absences + 1][0] = (
                            dp_next_state[total_absences + 1][0]
                            + dp_curr_state[total_absences][consecutive_lates]
                        ) % MOD
                    # Store the count when 'L' is chosen.
                    if consecutive_lates < 2:
                        dp_next_state[total_absences][consecutive_lates + 1] = (
                            dp_next_state[total_absences][consecutive_lates + 1]
                            + dp_curr_state[total_absences][consecutive_lates]
                        ) % MOD

            # Next state sub-problems will become current state sub-problems in the next iteration.
            dp_curr_state = [row[:] for row in dp_next_state]
            # Next state sub-problem results will reset to zero.
            dp_next_state = [[0] * 3 for _ in range(2)]

        # Sum up the counts for all combinations of length 'n' with different absent and late counts.
        count = (
            sum(
                dp_curr_state[total_absences][consecutive_lates]
                for total_absences in range(2)
                for consecutive_lates in range(3)
            )
            % MOD
        )
        return count
```

</details>
