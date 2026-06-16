# 1608. Special Array With X Elements Greater Than or Equal X

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/)  
`Array` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 1608 - Special Array With X Elements Greater Than or Equal X](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/)

## Problem

You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

### Example 1

```text
Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
```

### Example 2

```text
Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.
```

### Example 3

```text
Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.
```

## Constraints

- 1 <= nums.length <= 100
- 0 <= nums[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1608. Special Array With X Elements Greater Than or Equal X

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, Python3 |
| Counting Sort + Prefix Sum | C++, Java, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    
    int getFirstGreaterOrEqual(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size() - 1;

        int index = nums.size();
        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] >= val) {
                index = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return index;
    }
    
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int N = nums.size();
        for (int i = 1; i <= N; i++) {
            int k = getFirstGreaterOrEqual(nums, i);
            
            if (N - k == i) {
                return i;
            }
        }
        
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int getFirstGreaterOrEqual(int[] nums, int val) {
        int start = 0;
        int end = nums.length - 1;

        int index = nums.length;
        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] >= val) {
                index = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return index;
    }

    public int specialArray(int[] nums) {
        Arrays.sort(nums);

        int N = nums.length;
        for (int i = 1; i <= N; i++) {
            int k = getFirstGreaterOrEqual(nums, i);

            if (N - k == i) {
                return i;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def get_first_greater_or_equal(self, nums, val):
        start = 0
        end = len(nums) - 1

        index = len(nums)
        while start <= end:
            mid = (start + end) // 2

            if nums[mid] >= val:
                index = mid
                end = mid - 1
            else:
                start = mid + 1

        return index
    
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        
        N = len(nums)
        for i in range(1, N + 1):
            k = self.get_first_greater_or_equal(nums, i)
            
            if N - k == i:
                return i
        
        return -1
```

</details>

<br>

## Approach 2: Counting Sort + Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int N = nums.size();
        
        vector<int> freq(N + 1, 0);
        for (int i = 0; i < N; i++) {
            freq[min(N, nums[i])]++;
        }
        
        int numGreaterThanOrEqual = 0;
        for (int i = N; i >= 1; i--) {
            numGreaterThanOrEqual += freq[i];
            if (i == numGreaterThanOrEqual) {
                return i;
            }
        }
        
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int specialArray(int[] nums) {
        int N = nums.length;
        int[] freq = new int[N + 1];

        for (int i = 0; i < N; i++) {
            freq[Math.min(N, nums[i])]++;
        }
        
        int numGreaterThanOrEqual = 0;
        for (int i = N; i >= 1; i--) {
            numGreaterThanOrEqual += freq[i];
            if (i == numGreaterThanOrEqual) {
                return i;
            }
        }
        
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        N = len(nums)
        
        freq = [0] * (N + 1)
        for num in nums:
            freq[min(N, num)] += 1
        
        num_greater_than_or_equal = 0
        for i in range(N, 0, -1):
            num_greater_than_or_equal += freq[i]
            if i == num_greater_than_or_equal:
                return i
        
        return -1
```

</details>
