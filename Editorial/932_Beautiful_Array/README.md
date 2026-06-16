# 932. Beautiful Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/beautiful-array/)  
`Array` `Math` `Divide and Conquer`

**Problem Link:** [LeetCode 932 - Beautiful Array](https://leetcode.com/problems/beautiful-array/)

## Problem

An array nums of length n is beautiful if:

- nums is a permutation of the integers in the range [1, n].
- For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].

Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.

### Example 1

```text
Input: n = 4
Output: [2,1,4,3]
```

### Example 2

```text
Input: n = 5
Output: [3,1,2,5,4]
```

## Constraints

- 1 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 932. Beautiful Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Divide and Conquer | Java, Python |

## Approach 1: Divide and Conquer

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Map<Integer, int[]> memo;
    public int[] beautifulArray(int N) {
        memo = new HashMap();
        return f(N);
    }

    public int[] f(int N) {
        if (memo.containsKey(N))
            return memo.get(N);

        int[] ans = new int[N];
        if (N == 1) {
            ans[0] = 1;
        } else {
            int t = 0;
            for (int x: f((N+1)/2))  // odds
                ans[t++] = 2*x - 1;
            for (int x: f(N/2))  // evens
                ans[t++] = 2*x;
        }
        memo.put(N, ans);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def beautifulArray(self, N):
        memo = {1: [1]}
        def f(N):
            if N not in memo:
                odds = f((N+1)/2)
                evens = f(N/2)
                memo[N] = [2*x-1 for x in odds] + [2*x for x in evens]
            return memo[N]
        return f(N)
```

</details>
