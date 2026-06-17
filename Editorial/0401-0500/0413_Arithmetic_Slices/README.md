# 413. Arithmetic Slices

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/arithmetic-slices/)  
`Array` `Dynamic Programming` `Sliding Window`

**Problem Link:** [LeetCode 413 - Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/)

## Problem

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

- For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.

Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

### Example 1

```text
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
```

### Example 2

```text
Input: nums = [1]
Output: 0
```

## Constraints

- 1 <= nums.length <= 5000
- -1000 <= nums[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Arithmetic Subarrays](https://leetcode.com/problems/arithmetic-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Zero-Filled Subarrays](https://leetcode.com/problems/number-of-zero-filled-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Length of the Longest Alphabetical Continuous Substring](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 413. Arithmetic Slices

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Better Brute Force | Java |
| Using Recursion | Java |
| Dynamic Programming | Java |
| Constant Space Dynamic Programming | Java |
| Using Formula | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int count = 0;
        for (int s = 0; s < A.length - 2; s++) {
            int d = A[s + 1] - A[s];
            for (int e = s + 2; e < A.length; e++) {
                int i = 0;
                for (i = s + 1; i <= e; i++)
                    if (A[i] - A[i - 1] != d)
                        break;
                if (i > e)
                    count++;
            }
        }
        return count;
    }
}
```

</details>

<br>

## Approach 2: Better Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int count = 0;
        for (int s = 0; s < A.length - 2; s++) {
            int d = A[s + 1] - A[s];
            for (int e = s + 2; e < A.length; e++) {
                if (A[e] - A[e - 1] == d)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
}
```

</details>

<br>

## Approach 3: Using Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    int sum = 0;
    public int numberOfArithmeticSlices(int[] A) {
        slices(A, A.length - 1);
        return sum;
    }
    public int slices(int[] A, int i) {
        if (i < 2)
            return 0;
        int ap = 0;
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            ap = 1 + slices(A, i - 1);
            sum += ap;
        } else
            slices(A, i - 1);
        return ap;
    }
}
```

</details>

<br>

## Approach 4: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int[] dp = new int[A.length];
        int sum = 0;
        for (int i = 2; i < dp.length; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = 1 + dp[i - 1];
                sum += dp[i];
            }
        }
        return sum;
    }
}
```

</details>

<br>

## Approach 5: Constant Space Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int dp = 0;
        int sum = 0;
        for (int i = 2; i < A.length; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp = 1 + dp;
                sum += dp;
            } else
                dp = 0;
        }
        return sum;
    }
}
```

</details>

<br>

## Approach 6: Using Formula

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int count = 0;
        int sum = 0;
        for (int i = 2; i < A.length; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                count++;
            } else {
                sum += (count + 1) * (count) / 2;
                count = 0;
            }
        }
        return sum += count * (count + 1) / 2;
    }
}
```

</details>
