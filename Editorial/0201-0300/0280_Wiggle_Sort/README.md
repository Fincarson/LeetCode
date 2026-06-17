# 280. Wiggle Sort

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/wiggle-sort/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 280 - Wiggle Sort](https://leetcode.com/problems/wiggle-sort/)

## Problem

Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

You may assume the input array always has a valid answer.

### Example 1

```text
Input: nums = [3,5,2,1,6,4]
Output: [3,5,1,6,2,4]
Explanation: [1,6,2,5,3,4] is also accepted.
```

### Example 2

```text
Input: nums = [6,6,5,6,3,8]
Output: [6,6,5,6,3,8]
```

## Constraints

- 1 <= nums.length <= 5 * 104
- 0 <= nums[i] <= 104
- It is guaranteed that there will be an answer for the given input nums.

Follow up: Could you solve the problem in O(n) time complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Colors](https://leetcode.com/problems/sort-colors/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Array With Elements Not Equal to Average of Neighbors](https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 280. Wiggle Sort

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java |
| Greedy | C++, Java |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() - 1; i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void wiggleSort(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length - 1; i += 2) {
            swap(nums, i, i + 1);
        }
    }
}
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void wiggleSort(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (((i % 2 == 0) && nums[i] > nums[i + 1]) ||
                ((i % 2 == 1) && nums[i] < nums[i + 1])) {
                swap(nums, i, i + 1);
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void wiggleSort(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (((i % 2 == 0) && nums[i] > nums[i + 1])
                    || ((i % 2 == 1) && nums[i] < nums[i + 1])) {
                swap(nums, i, i + 1);
            }
        }
    }
}
```

</details>
