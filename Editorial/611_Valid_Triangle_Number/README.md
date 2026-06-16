# 611. Valid Triangle Number

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/valid-triangle-number/)  
`Array` `Two Pointers` `Binary Search` `Greedy` `Sorting`

**Problem Link:** [LeetCode 611 - Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/)

## Problem

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

### Example 1

```text
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
```

### Example 2

```text
Input: nums = [4,2,3,4]
Output: 4
```

## Constraints

- 1 <= nums.length <= 1000
- 0 <= nums[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [3Sum Smaller](https://leetcode.com/problems/3sum-smaller/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Polygon With the Largest Perimeter](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 611. Valid Triangle Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Using Binary Search | Java |
| Linear Scan | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int triangleNumber(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            for (int j = i + 1; j < nums.length - 1; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    if (nums[i] + nums[j] > nums[k] && 
                        nums[i] + nums[k] > nums[j] && 
                        nums[j] + nums[k] > nums[i]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}
```

</details>

<br>

## Approach 2: Using Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    int binarySearch(int nums[], int l, int r, int x) {
        while (r >= l && r < nums.length) {
            int mid = (l + r) / 2;
            if (nums[mid] >= x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    public int triangleNumber(int[] nums) {
        int count = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.length - 1 && nums[i] != 0; j++) {
                k = binarySearch(nums, k, nums.length - 1, nums[i] + nums[j]);
                count += k - j - 1;
            }
        }
        return count;
    }
}
```

</details>

<br>

## Approach 3: Linear Scan

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int triangleNumber(int[] nums) {
        int count = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.length - 1 && nums[i] != 0; j++) {
                while (k < nums.length && nums[i] + nums[j] > nums[k])
                    k++;
                count += k - j - 1;
            }
        }
        return count;
    }
}
```

</details>
