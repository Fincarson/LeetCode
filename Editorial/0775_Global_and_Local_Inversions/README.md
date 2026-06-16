# 775. Global and Local Inversions

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/global-and-local-inversions/)  
`Array` `Math`

**Problem Link:** [LeetCode 775 - Global and Local Inversions](https://leetcode.com/problems/global-and-local-inversions/)

## Problem

You are given an integer array nums of length n which represents a permutation of all the integers in the range [0, n - 1].

The number of global inversions is the number of the different pairs (i, j) where:

- 0 <= i < j < n
- nums[i] > nums[j]

The number of local inversions is the number of indices i where:

- 0 <= i < n - 1
- nums[i] > nums[i + 1]

Return true if the number of global inversions is equal to the number of local inversions.

### Example 1

```text
Input: nums = [1,0,2]
Output: true
Explanation: There is 1 global inversion and 1 local inversion.
```

### Example 2

```text
Input: nums = [1,2,0]
Output: false
Explanation: There are 2 global inversions and 1 local inversion.
```

## Constraints

- n == nums.length
- 1 <= n <= 105
- 0 <= nums[i] < n
- All the integers of nums are unique.
- nums is a permutation of all the numbers in the range [0, n - 1].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 775. Global and Local Inversions

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force [Time Limit Exceeded] | Java, Python |
| Approach #2: Remember Minimum [Accepted] | Java, Python |
| Approach #3: Linear Scan [Accepted] | Java, Python |

## Approach #1: Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isIdealPermutation(int[] A) {
        int N = A.length;
        for (int i = 0; i < N; ++i)
            for (int j = i+2; j < N; ++j)
                if (A[i] > A[j]) return false;
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isIdealPermutation(self, A):
        return all(x < A[j]
                   for i, x in enumerate(A)
                   for j in xrange(i+2, len(A)))
```

</details>

<br>

## Approach #2: Remember Minimum [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isIdealPermutation(int[] A) {
        int N = A.length;
        int floor = N;
        for (int i=N-1; i>=2; --i) {
            floor = Math.min(floor, A[i]);
            if (A[i-2] > floor) return false;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isIdealPermutation(self, A):
        N = len(A)
        floor = N
        for i in xrange(N-1, -1, -1):
            floor = min(floor, A[i])
            if i >= 2 and A[i-2] > floor:
                return False
        return True
```

</details>

<br>

## Approach #3: Linear Scan [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isIdealPermutation(int[] A) {
        for (int i = 0; i < A.length; ++i)
            if (Math.abs(A[i] - i) > 1)
                return false;
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isIdealPermutation(self, A):
        return all(abs(i-x) <= 1 for i,x in enumerate(A))
```

</details>
