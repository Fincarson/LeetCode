# 823. Binary Trees With Factors

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/binary-trees-with-factors/)  
`Array` `Hash Table` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 823 - Binary Trees With Factors](https://leetcode.com/problems/binary-trees-with-factors/)

## Problem

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

### Example 1

```text
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
```

### Example 2

```text
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
```

## Constraints

- 1 <= arr.length <= 1000
- 2 <= arr[i] <= 109
- All the values of arr are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 823. Binary Trees With Factors

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
    public int numFactoredBinaryTrees(int[] A) {
        int MOD = 1_000_000_007;
        int N = A.length;
        Arrays.sort(A);
        long[] dp = new long[N];
        Arrays.fill(dp, 1);

        Map<Integer, Integer> index = new HashMap();
        for (int i = 0; i < N; ++i)
            index.put(A[i], i);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0) { // A[j] is left child
                    int right = A[i] / A[j];
                    if (index.containsKey(right)) {
                        dp[i] = (dp[i] + dp[j] * dp[index.get(right)]) % MOD;
                    }
                }
            }

        long ans = 0;
        for (long x: dp) ans += x;
        return (int) (ans % MOD);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def numFactoredBinaryTrees(self, A):
        MOD = 10 ** 9 + 7
        N = len(A)
        A.sort()
        dp = [1] * N
        index = {x: i for i, x in enumerate(A)}
        for i, x in enumerate(A):
            for j in xrange(i):
                if x % A[j] == 0: #A[j] will be left child
                    right = x / A[j]
                    if right in index:
                        dp[i] += dp[j] * dp[index[right]]
                        dp[i] %= MOD

        return sum(dp) % MOD
```

</details>
