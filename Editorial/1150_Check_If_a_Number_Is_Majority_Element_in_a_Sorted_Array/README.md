# 1150. Check If a Number Is Majority Element in a Sorted Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 1150 - Check If a Number Is Majority Element in a Sorted Array](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/)

## Problem

Given an integer array nums sorted in non-decreasing order and an integer target, return true if target is a majority element, or false otherwise.

A majority element in an array nums is an element that appears more than nums.length / 2 times in the array.

### Example 1

```text
Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.
```

### Example 2

```text
Input: nums = [10,100,101,101], target = 101
Output: false
Explanation: The value 101 appears 2 times and the length of the array is 4.
Thus, 101 is not a majority element because 2 > 4/2 is false.
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i], target <= 109
- nums is sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Majority Element](https://leetcode.com/problems/majority-element/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Majority Element II](https://leetcode.com/problems/majority-element-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1150. Check If a Number Is Majority Element in a Sorted Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Frequency Count | C++, Java |
| Binary Search (Two Pass) | C++, Java |
| Binary Search (One Pass) | C++, Java |

## Approach 1: Frequency Count

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int count = 0;
        for (int num : nums) {
            count = num == target ? count + 1 : count;
        }
        
        return count > nums.size() / 2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        int count = 0;
        for (int num : nums) {
            count = num == target ? count + 1 : count;
        }
        
        return count > nums.length / 2;
    }
}
```

</details>

<br>

## Approach 2: Binary Search (Two Pass)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Returns the index of the first element equal to or greater than the target.
    // If there is no instance of the target in the list, it returns the length of the list.
    int lower_bound(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int index = nums.size();
            
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] >= target) {
                end = mid - 1;
                index = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return index;
    }
    
    // Returns the index of the first element greater than the target.
    // If there is no instance of the target in the list, it returns the length of the list.
    int upper_bound(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int index = nums.size();
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] > target) {
                end = mid - 1;
                index = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return index;
    }
    
    bool isMajorityElement(vector<int>& nums, int target) {
        int firstIndex = lower_bound(nums, target);
        int nextToLastIndex = upper_bound(nums, target);
        
        return nextToLastIndex - firstIndex > nums.size() / 2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns the index of the first element equal to or greater than the target.
    // If there is no instance of the target in the list, it returns the length of the list.
    int lower_bound(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int index = nums.length;
            
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] >= target) {
                end = mid - 1;
                index = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return index;
    }
    
    // Returns the index of the first element greater than the target.
    // If there is no instance of the target in the list, it returns the length of the list.
    int upper_bound(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int index = nums.length;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] > target) {
                end = mid - 1;
                index = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return index;
    }
    
    public boolean isMajorityElement(int[] nums, int target) {
        int firstIndex = lower_bound(nums, target);
        int nextToLastIndex = upper_bound(nums, target);
        
        return nextToLastIndex - firstIndex > nums.length / 2;
    }
}
```

</details>

<br>

## Approach 3: Binary Search (One Pass)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Returns the index of the first element equal to or greater than the target.
    // If there is no instance of the target in the list, it returns the length of the list.
    int lower_bound(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int index = nums.size();
            
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] >= target) {
                end = mid - 1;
                index = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return index;
    }
    
    bool isMajorityElement(vector<int>& nums, int target) {
        int firstIndex = lower_bound(nums, target);
        
        return firstIndex + nums.size() / 2 < nums.size() && nums[firstIndex + nums.size() / 2] == target;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
// Returns the index of the first element that is equal to or greater than the target.
// If there is no instance of the target in the list, it returns the length of the list.
class Solution {
    int lower_bound(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int index = nums.length;
            
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] >= target) {
                end = mid - 1;
                index = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return index;
    }
    
    public boolean isMajorityElement(int[] nums, int target) {
        int firstIndex = lower_bound(nums, target);
        
        return firstIndex + nums.length / 2 < nums.length && nums[firstIndex + nums.length / 2] == target;
    }
}
```

</details>
