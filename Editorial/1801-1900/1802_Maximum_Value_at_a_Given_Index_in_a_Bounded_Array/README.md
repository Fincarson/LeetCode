# 1802. Maximum Value at a Given Index in a Bounded Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/)  
`Math` `Binary Search` `Greedy`

**Problem Link:** [LeetCode 1802 - Maximum Value at a Given Index in a Bounded Array](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/)

## Problem

You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

- nums.length == n
- nums[i] is a positive integer where 0 <= i < n.
- abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
- The sum of all the elements of nums does not exceed maxSum.
- nums[index] is maximized.

Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

### Example 1

```text
Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
```

### Example 2

```text
Input: n = 6, index = 1,  maxSum = 10
Output: 3
```

## Constraints

- 1 <= n <= maxSum <= 109
- 0 <= index < n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1802. Maximum Value at a Given Index in a Bounded Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy + Binary Search | Java, Python3 |

## Approach: Greedy + Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private long getSum(int index, int value, int n) {
        long count = 0;
        
        // On index's left:
        // If value > index, there are index + 1 numbers in the arithmetic sequence:
        // [value - index, ..., value - 1, value].
        // Otherwise, there are value numbers in the arithmetic sequence:
        // [1, 2, ..., value - 1, value], plus a sequence of length (index - value + 1) of 1s. 
        if (value > index) {
            count += (long)(value + value - index) * (index + 1) / 2;
        } else {
            count += (long)(value + 1) * value / 2 + index - value + 1;
        };
        // On index's right:
        // If value >= n - index, there are n - index numbers in the arithmetic sequence:
        // [value, value - 1, ..., value - n + 1 + index].
        // Otherwise, there are value numbers in the arithmetic sequence:
        // [value, value - 1, ..., 1], plus a sequence of length (n - index - value) of 1s. 
        if (value >= n - index) {
            count += (long)(value + value - n + 1 + index) * (n - index) / 2;
        } else {
            count += (long)(value + 1) * value / 2 + n - index - value;
        }   
        
        return count - value;
        
    }
    public int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (getSum(index, mid, n) <= maxSum) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getSum(self, index: int, value: int, n: int) -> int:
        count = 0
        
        # On index's left:
        # If value > index, there are index + 1 numbers in the arithmetic sequence:
        # [value - index, ..., value - 1, value].
        # Otherwise, there are value numbers in the arithmetic sequence:
        # [1, 2, ..., value - 1, value], plus a sequence of length (index - value + 1) of 1s. 
        if value > index:
            count += (value + value - index) * (index + 1) // 2
        else:
            count += (value + 1) * value // 2 + index - value + 1
        
        # On index's right:
        # If value >= n - index, there are n - index numbers in the arithmetic sequence:
        # [value, value - 1, ..., value - n + 1 + index].
        # Otherwise, there are value numbers in the arithmetic sequence:
        # [value, value - 1, ..., 1], plus a sequence of length (n - index - value) of 1s. 
        if value >= n - index:
            count += (value + value - n + 1 + index) * (n - index) // 2
        else:
            count += (value + 1) * value // 2 + n - index - value
        
        return count - value
    
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        left, right = 1, maxSum
        while left < right:
            mid = (left + right + 1) // 2
            if self.getSum(index, mid, n) <= maxSum:
                left = mid
            else:
                right = mid - 1
        
        return left
```

</details>
