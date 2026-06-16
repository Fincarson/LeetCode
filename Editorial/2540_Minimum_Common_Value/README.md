# 2540. Minimum Common Value

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-common-value/)  
`Array` `Hash Table` `Two Pointers` `Binary Search`

**Problem Link:** [LeetCode 2540 - Minimum Common Value](https://leetcode.com/problems/minimum-common-value/)

## Problem

Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

### Example 1

```text
Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
```

### Example 2

```text
Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
```

## Constraints

- 1 <= nums1.length, nums2.length <= 105
- 1 <= nums1[i], nums2[j] <= 109
- Both nums1 and nums2 are sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2540. Minimum Common Value

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Set | C++, Java, Python3 |
| Two Pointers | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Add the elements from nums1 to set1
        unordered_set<int> set1(nums1.begin(), nums1.end());

        // Search for each element of nums2 in set1
        // Return the first common element found
        for (int num : nums2) {
            if (set1.contains(num)) {
                return num;
            }
        }

        // Return -1 if there are no common elements
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();

        // Add the elements from nums1 to set1
        for (int num : nums1) {
            set1.add(num);
        }

        // Search for each element of nums2 in set1
        // Return the first common element found
        for (int num : nums2) {
            if (set1.contains(num)) {
                return num;
            }
        }

        // Return -1 if there are no common elements
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        # Add the elements from nums1 to set1
        set1 = set(nums1)

        # Search for each element of nums2 in set1
        # Return the first common element found
        for num in nums2:
            if num in set1:
                return num

        # Return -1 if there are no common elements
        return -1
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int first = 0;
        int second = 0;

        // Traverse through both arrays with two pointers
        // Increment the pointer with a smaller value at that index
        // Return the first common element found
        while (first < nums1.size() && second < nums2.size()) {
            if (nums1[first] < nums2[second]) {
                first++;
            } else if (nums1[first] > nums2[second]) {
                second++;
            } else {
                return nums1[first];
            }
        }

        // Return -1 if there are no common elements
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int first = 0;
        int second = 0;

        // Traverse through both arrays with two pointers
        // Increment the pointer with a smaller value at that index
        // Return the first common element found
        while (first < nums1.length && second < nums2.length) {
            if (nums1[first] < nums2[second]) {
                first++;
            } else if (nums1[first] > nums2[second]) {
                second++;
            } else {
                return nums1[first];
            }
        }

        // Return -1 if there are no common elements
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getCommon(self, nums1, nums2):
        first = 0
        second = 0

        # Traverse through both arrays with two pointers
        # Increment the pointer with a smaller value at that index
        # Return the first common element found
        while first < len(nums1) and second < len(nums2):
            if nums1[first] < nums2[second]:
                first += 1
            elif nums1[first] > nums2[second]:
                second += 1
            else:
                return nums1[first]

        # Return -1 if there are no common elements
        return -1
```

</details>

<br>

## Approach 3: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Binary search should be done on the larger array
        // If nums1 is longer, call getCommon with the arrays swapped
        if (nums1.size() > nums2.size()) {
            return getCommon(nums2, nums1);
        }

        // Search for each element of nums1 in nums2
        // Return the first common element found
        for (int num : nums1) {
            if (binarySearch(num, nums2)) {
                return num;
            }
        }

        // Return -1 if there are no common elements
        return -1;
    }

private:
    bool binarySearch(int target, vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        // Binary search should be done on the larger array
        // If nums1 is longer, call getCommon with the arrays swapped
        if (nums1.length > nums2.length) {
            return getCommon(nums2, nums1);
        }
        
        // Search for each element of nums1 in nums2
        // Return the first common element found
        for (int num : nums1) {
            if (binarySearch(num, nums2)) {
                return num;
            }
        }

        // Return -1 if there are no common elements
        return -1;
    }

    private boolean binarySearch(int target, int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:

        def binary_search(target, nums):
            left = 0
            right = len(nums) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] > target:
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    return True
            return False 
        
        # Binary search should be done on the larger array
        # If nums1 is longer, call getCommon with the arrays swapped
        if len(nums1) > len(nums2): 
            return self.getCommon(nums2, nums1)

        # Search for each element of nums1 in nums2
        # Return the first common element found
        for num in nums1:
            if binary_search(num, nums2):
                return num

        # Return -1 if there are no common elements
        return -1
```

</details>
