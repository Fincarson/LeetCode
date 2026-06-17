# 1060. Missing Element in Sorted Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/missing-element-in-sorted-array/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 1060 - Missing Element in Sorted Array](https://leetcode.com/problems/missing-element-in-sorted-array/)

## Problem

Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an integer k, return the kth missing number starting from the leftmost number of the array.

### Example 1

```text
Input: nums = [4,7,9,10], k = 1
Output: 5
Explanation: The first missing number is 5.
```

### Example 2

```text
Input: nums = [4,7,9,10], k = 3
Output: 8
Explanation: The missing numbers are [5,6,8,...], hence the third missing number is 8.
```

### Example 3

```text
Input: nums = [1,2,4], k = 3
Output: 6
Explanation: The missing numbers are [3,5,6,7,...], hence the third missing number is 6.
```

## Constraints

- 1 <= nums.length <= 5 * 104
- 1 <= nums[i] <= 107
- nums is sorted in ascending order, and all the elements are unique.
- 1 <= k <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1060. Missing Element in Sorted Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iteration | C++, Java, Python3 |
| Binary Search | C++, Java, Python |

## Approach 1: Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        
        for (int i = 1; i < n; ++i) {
            int missedInGap = nums[i] - nums[i - 1] - 1;
            if (missedInGap >= k) {
                return nums[i - 1] + k;
            }
            k -= missedInGap;
        }
        
        return nums[n - 1] + k;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        
        for (int i = 1; i < n; ++i) {
            int missedInGap = nums[i] - nums[i - 1] - 1;
            if (missedInGap >= k) {
                return nums[i - 1] + k;
            }
            k -= missedInGap;
        }
        
        return nums[n - 1] + k;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        n = len(nums)

        for i in range(1, n):
            missed_in_gap = nums[i] - nums[i - 1] - 1
            if missed_in_gap >= k:
                return nums[i - 1] + k
            k -= missed_in_gap
        
        return nums[n - 1] + k
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (nums[mid] - nums[0] - mid < k) {
                left = mid;
            } else{
                right = mid - 1;
            }
        }
        
        return nums[0] + k + left;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        int left = 0, right = n - 1;
        
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (nums[mid] - nums[0] - mid < k) {
                left = mid;
            } else{
                right = mid - 1;
            }
        }
        
        return nums[0] + k + left;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left, right = 0, n - 1
        
        while left < right:
            mid = right - (right - left) // 2
            if (nums[mid] - nums[0]) - mid < k:
                left = mid
            else:
                right = mid - 1

        return nums[0] + k + left
```

</details>
