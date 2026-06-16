# 704. Binary Search

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/binary-search/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 704 - Binary Search](https://leetcode.com/problems/binary-search/)

## Problem

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

### Example 1

```text
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

### Example 2

```text
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

## Constraints

- 1 <= nums.length <= 104
- -104 < nums[i], target < 104
- All the integers in nums are unique.
- nums is sorted in ascending order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Search in a Sorted Array of Unknown Size](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Count of Positive Integer and Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 704. Binary Search

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Find the Exact Value | C++, Java, Python3 |
| Find Upper bound | C++, Java, Python3 |
| Find Lower bound | C++, Java, Python3 |
| Use built-in tools. | C++, Python3 |

## Approach 1: Find the Exact Value

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Set the left and right boundaries
        int left = 0, right = int(nums.size()) - 1;
        
        // Under this condition
        while (left <= right) {
            // Get the middle index and the middle value.
            int mid = left + (right - left) / 2;
            
            // Case 1, return the middle index.
            if (nums[mid] == target) {
                return mid;
            } 
            // Case 2, discard the smaller half.
            else if (nums[mid] < target) {
                left = mid + 1;   
            } 
            // Case 3, discard the larger half.
            else {
                right = mid - 1;
            }
        }
        
        // If we finish the search without finding target, return -1.
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int search(int[] nums, int target) {
        // Set the left and right boundaries
        int left = 0, right = nums.length - 1;
        
        // Under this condition
        while (left <= right) {
            // Get the middle index and the middle value.
            int mid = left + (right - left) / 2;
            
            // Case 1, return the middle index.
            if (nums[mid] == target) {
                return mid;
            } 
            // Case 2, discard the smaller half.
            else if (nums[mid] < target) {
                left = mid + 1;   
            } 
            // Case 3, discard the larger half.
            else {
                right = mid - 1;
            }
        }
        
        // If we finish the search without finding target, return -1.
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Set the left and right boundaries
        left = 0
        right = len(nums) - 1
        
        # Under this condition
        while left <= right:
            # Get the middle index and the middle value.
            mid = (left + right) // 2
            
            # Case 1, return the middle index.
            if nums[mid] == target:
                return mid
            # Case 2, discard the smaller half.
            elif nums[mid] < target:
                left = mid + 1                 
            # Case 3, discard the larger half.         
            else:
                right = mid - 1
        
        # If we finish the search without finding target, return -1.
        return -1
```

</details>

<br>

## Approach 2: Find Upper bound

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Set the left and right boundaries
        int left = 0, right = int(nums.size());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left > 0 and nums[left - 1] == target) {
            return left - 1;
        } else {
            return -1;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int search(int[] nums, int target) {
        // Set the left and right boundaries
        int left = 0, right = nums.length;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left > 0 && nums[left - 1] == target) {
            return left - 1;
        } else {
            return -1;
        } 
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Set the left and right boundaries
        left = 0
        right = len(nums)
        
        while left < right:
            mid = (left + right) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid

        if left > 0 and nums[left - 1] == target:
            return left - 1
        else:
            return -1
```

</details>

<br>

## Approach 3: Find Lower bound

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Set the left and right boundaries
        int left = 0, right = int(nums.size());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if (left < nums.size() and nums[left] == target) {
            return left;
        } else {
            return -1;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int search(int[] nums, int target) {
        // Set the left and right boundaries
        int left = 0, right = nums.length;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if (left < nums.length && nums[left] == target) {
            return left;
        } else {
            return -1;
        } 
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Set the left and right boundaries
        left = 0
        right = len(nums)
        
        while left < right:
            mid = (left + right) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        
        if left < len(nums) and nums[left] == target:
            return left
        else:
            return -1
```

</details>

<br>

## Approach 4: Use built-in tools.

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Find the insertion position `idx`.
        int idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (idx > 0 && nums[idx - 1] == target) {
            return idx - 1;
        } else {
            return -1;
        }    
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Find the insertion position `idx`.
        idx = bisect.bisect_right(nums, target)

        if idx > 0 and nums[idx - 1] == target:
            return idx - 1
        else:
            return -1
```

</details>
