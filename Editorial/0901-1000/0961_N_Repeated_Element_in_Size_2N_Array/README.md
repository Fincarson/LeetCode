# 961. N-Repeated Element in Size 2N Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 961 - N-Repeated Element in Size 2N Array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)

## Problem

You are given an integer array nums with the following properties:

- nums.length == 2 * n.
- nums contains n + 1 unique values, n of which occur exactly once in the array.
- Exactly one element of nums is repeated n times.

Return the element that is repeated n times.

### Example 1

```text
Input: nums = [1,2,3,3]
Output: 3
```

### Example 2

```text
Input: nums = [2,1,2,5,3,2]
Output: 2
```

### Example 3

```text
Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
```

## Constraints

- 2 <= n <= 5000
- nums.length == 2 * n
- 0 <= nums[i] <= 104
- nums contains n + 1 unique elements and one of them is repeated exactly n times.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 961. N-Repeated Element in Size 2N Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count | Java, Python |
| Compare | Java, Python |

## Approach 1: Count

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        Map<Integer, Integer> count = new HashMap();
        for (int x: A) {
            count.put(x, count.getOrDefault(x, 0) + 1);
        }

        for (int k: count.keySet())
            if (count.get(k) > 1)
                return k;

        throw null;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def repeatedNTimes(self, A):
        count = collections.Counter(A)
        for k in count:
            if count[k] > 1:
                return k
```

</details>

<br>

## Approach 2: Compare

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        for (int k = 1; k <= 3; ++k)
            for (int i = 0; i < A.length - k; ++i)
                if (A[i] == A[i+k])
                    return A[i];

        throw null;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def repeatedNTimes(self, A):
        for k in xrange(1, 4):
            for i in xrange(len(A) - k):
                if A[i] == A[i+k]:
                    return A[i]
```

</details>
