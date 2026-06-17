# 813. Largest Sum of Averages

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/largest-sum-of-averages/)  
`Array` `Dynamic Programming` `Prefix Sum`

**Problem Link:** [LeetCode 813 - Largest Sum of Averages](https://leetcode.com/problems/largest-sum-of-averages/)

## Problem

You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.

Note that the partition must use every integer in nums, and that the score is not necessarily an integer.

Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.

### Example 1

```text
Input: nums = [9,1,2,3,9], k = 3
Output: 20.00000
Explanation:
The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
```

### Example 2

```text
Input: nums = [1,2,3,4,5,6,7], k = 4
Output: 20.50000
```

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 104
- 1 <= k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 813. Largest Sum of Averages

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Dynamic Programming [Accepted] | Java, Python |

## Approach #1: Dynamic Programming [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int N = A.length;
        double[] P = new double[N+1];
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + A[i];

        double[] dp = new double[N];
        for (int i = 0; i < N; ++i)
            dp[i] = (P[N] - P[i]) / (N - i);

        for (int k = 0; k < K-1; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = i+1; j < N; ++j)
                    dp[i] = Math.max(dp[i], (P[j]-P[i]) / (j-i) + dp[j]);

        return dp[0];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def largestSumOfAverages(self, A, K):
        P = [0]
        for x in A: P.append(P[-1] + x)
        def average(i, j):
            return (P[j] - P[i]) / float(j - i)

        N = len(A)
        dp = [average(i, N) for i in xrange(N)]
        for k in xrange(K-1):
            for i in xrange(N):
                for j in xrange(i+1, N):
                    dp[i] = max(dp[i], average(i, j) + dp[j])

        return dp[0]
```

</details>
