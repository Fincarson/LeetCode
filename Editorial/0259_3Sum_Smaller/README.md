# 259. 3Sum Smaller

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/3sum-smaller/)  
`Array` `Two Pointers` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 259 - 3Sum Smaller](https://leetcode.com/problems/3sum-smaller/)

## Problem

Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

### Example 1

```text
Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]
```

### Example 2

```text
Input: nums = [], target = 0
Output: 0
```

### Example 3

```text
Input: nums = [0], target = 0
Output: 0
```

## Constraints

- n == nums.length
- 0 <= n <= 3500
- -100 <= nums[i] <= 100
- -100 <= target <= 100
- The input is generated such that the answer is less than or equal to 109.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [3Sum](https://leetcode.com/problems/3sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [3Sum Closest](https://leetcode.com/problems/3sum-closest/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximize Greatness of an Array](https://leetcode.com/problems/maximize-greatness-of-an-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Polygon With the Largest Perimeter](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 259. 3Sum Smaller

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | Java |
| Two Pointers | Java |

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        Arrays.sort(nums);
        int sum = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            sum += twoSumSmaller(nums, i + 1, target - nums[i]);
        }
        return sum;
    }

    private int twoSumSmaller(int[] nums, int startIndex, int target) {
        int sum = 0;
        for (int i = startIndex; i < nums.length - 1; i++) {
            int j = binarySearch(nums, i, target - nums[i]);
            sum += j - i;
        }
        return sum;
    }

    private int binarySearch(int[] nums, int startIndex, int target) {
        int left = startIndex;
        int right = nums.length - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] < target) {
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

<br>

## Approach 3: Two Pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        Arrays.sort(nums);
        int sum = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            sum += twoSumSmaller(nums, i + 1, target - nums[i]);
        }
        return sum;
    }

    private int twoSumSmaller(int[] nums, int startIndex, int target) {
        int sum = 0;
        int left = startIndex;
        int right = nums.length - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                sum += right - left;
                left++;
            } else {
                right--;
            }
        }
        return sum;
    }
}
```

</details>
