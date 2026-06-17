# 1551. Minimum Operations to Make Array Equal

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-operations-to-make-array-equal/)  
`Math`

**Problem Link:** [LeetCode 1551 - Minimum Operations to Make Array Equal](https://leetcode.com/problems/minimum-operations-to-make-array-equal/)

## Problem

You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i (i.e., 0 <= i < n).

In one operation, you can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x] and add 1 to arr[y] (i.e., perform arr[x] -=1 and arr[y] += 1). The goal is to make all the elements of the array equal. It is guaranteed that all the elements of the array can be made equal using some operations.

Given an integer n, the length of the array, return the minimum number of operations needed to make all the elements of arr equal.

### Example 1

```text
Input: n = 3
Output: 2
Explanation: arr = [1, 3, 5]
First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
```

### Example 2

```text
Input: n = 6
Output: 9
```

## Constraints

- 1 <= n <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Operations to Make Arrays Similar](https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Operations to Make Array Equal II](https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1551. Minimum Operations to Make Array Equal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python3 |
| Math | Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minOperations(int n) {
        int res = 0;
        // compute the sum:
        // (n - 1) + (n - 3) + (n - 5) + ... + 1 (or 0) 
        while (n > 0) {
            res += n - 1;
            n -= 2;    
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, n: int) -> int:
        res = 0
        # compute the sum:
        # (n - 1) + (n - 3) + (n - 5) + ... + 1 (or 0) 
        while n > 0:
            res += n - 1
            n -= 2
```

</details>

<br>

## Approach 2: Math

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minOperations(int n) {
        return n % 2 == 0 ? n * n / 4 : (n * n - 1) / 4;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, n: int) -> int:
        return n**2 // 4 if n % 2 == 0 else (n**2 - 1) // 4
```

</details>
