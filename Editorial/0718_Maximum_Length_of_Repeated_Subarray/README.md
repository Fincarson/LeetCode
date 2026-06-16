# 718. Maximum Length of Repeated Subarray

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)  
`Array` `Binary Search` `Dynamic Programming` `Sliding Window` `Rolling Hash` `Hash Function`

**Problem Link:** [LeetCode 718 - Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

## Problem

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

### Example 1

```text
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
```

### Example 2

```text
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
```

## Constraints

- 1 <= nums1.length, nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Common Subpath](https://leetcode.com/problems/longest-common-subpath/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find the Maximum Length of a Good Subsequence II](https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find the Maximum Length of a Good Subsequence I](https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 718. Maximum Length of Repeated Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force with Initial Character Map [Time Limit Exceeded] | Python3 |
| Approach #2: Binary Search with Naive Check [Time Limit Exceeded] | Python3 |
| Approach #3: Dynamic Programming [Accepted] | Python3 |
| Approach #4: Binary Search with Rolling Hash [Accepted] | Python3 |

## Approach #1: Brute Force with Initial Character Map [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
ans = 0
for i in [0 .. A.length - 1]:
    for j in [0 .. B.length - 1]:
        k = 0
        while (A[i + k] == B[j + k]): k += 1 #and i + k < A.length etc.
        ans = max(ans, k)
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def findLength(self, A, B):
        ans = 0
        Bstarts = collections.defaultdict(list)
        for j, y in enumerate(B):
            Bstarts[y].append(j)

        for i, x in enumerate(A):
            for j in Bstarts[x]:
                k = 0
                while i + k < len(A) and j + k < len(B) and A[i + k] == B[j + k]:
                    k += 1
                ans = max(ans, k)
        return ans
```

</details>

<br>

## Approach #2: Binary Search with Naive Check [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def findLength(self, A, B):
        def check(length):
            seen = set(tuple(A[i:i+length]) 
                       for i in range(len(A) - length + 1))
            return any(tuple(B[j:j+length]) in seen 
                       for j in range(len(B) - length + 1))

        lo, hi = 0, min(len(A), len(B)) + 1
        while lo < hi:
            mi = (lo + hi) // 2
            if check(mi):
                lo = mi + 1
            else:
                hi = mi
        return lo - 1
```

</details>

<br>

## Approach #3: Dynamic Programming [Accepted]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def findLength(self, A, B):
        memo = [[0] * (len(B) + 1) for _ in range(len(A) + 1)]
        for i in range(len(A) - 1, -1, -1):
            for j in range(len(B) - 1, -1, -1):
                if A[i] == B[j]:
                    memo[i][j] = memo[i + 1][j + 1] + 1
        return max(max(row) for row in memo)
```

</details>

<br>

## Approach #4: Binary Search with Rolling Hash [Accepted]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def findLength(self, A, B):
        P, MOD = 113, 10**9 + 7
        Pinv = pow(P, MOD - 2, MOD)
        def check(guess):
            def rolling(A, length):
                if length == 0:
                    yield 0, 0
                    return

                h, power = 0, 1
                for i, x in enumerate(A):
                    h = (h + x * power) % MOD
                    if i < length - 1:
                        power = (power * P) % MOD
                    else:
                        yield h, i - (length - 1)
                        h = (h - A[i - (length - 1)]) * Pinv % MOD

            hashes = collections.defaultdict(list)
            for ha, start in rolling(A, guess):
                hashes[ha].append(start)
            for ha, start in rolling(B, guess):
                iarr = hashes.get(ha, [])
                if any(A[i: i + guess] == B[start: start + guess] for i in iarr):
                    return True
            return False

        lo, hi = 0, min(len(A), len(B)) + 1
        while lo < hi:
            mi = (lo + hi) // 2
            if check(mi):
                lo = mi + 1
            else:
                hi = mi
        return lo - 1
```

</details>
