# 2009. Minimum Number of Operations to Make Array Continuous

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/)  
`Array` `Hash Table` `Binary Search` `Sliding Window`

**Problem Link:** [LeetCode 2009 - Minimum Number of Operations to Make Array Continuous](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/)

## Problem

You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

- All elements in nums are unique.
- The difference between the maximum element and the minimum element in nums equals nums.length - 1.

For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

### Example 1

```text
Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
```

### Example 2

```text
Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
```

### Example 3

```text
Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Moving Stones Until Consecutive II](https://leetcode.com/problems/moving-stones-until-consecutive-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum One Bit Operations to Make Integers Zero](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Adjacent Swaps for K Consecutive Ones](https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2009. Minimum Number of Operations to Make Array Continuous

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        
        // std::set automatically sorts
        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums;
        for (int num : unique) {
            newNums.push_back(num);
        }
        
        for (int i = 0; i < newNums.size(); i++) {
            int left = newNums[i];
            int right = left + n - 1;
            int j = upper_bound(newNums.begin(), newNums.end(), right) - newNums.begin();
            int count = j - i;
            ans = min(ans, n - count);
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int ans = n;
        
        HashSet<Integer> unique = new HashSet<>();
        for (int num : nums) {
            unique.add(num);
        }
        
        int[] newNums = new int[unique.size()];
        int index = 0;
        
        for (int num : unique) {
            newNums[index++] = num;
        }
            
        Arrays.sort(newNums);
        
        for (int i = 0; i < newNums.length; i++) {
            int left = newNums[i];
            int right = left + n - 1;
            int j = binarySearch(newNums, right);
            int count = j - i;
            ans = Math.min(ans, n - count);
        }
        
        return ans;
    }
    
    public int binarySearch(int[] newNums, int target) {
        int left = 0;
        int right = newNums.length;
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (target < newNums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
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
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        ans = n
        new_nums = sorted(set(nums))
        
        for i in range(len(new_nums)):
            left = new_nums[i]
            right = left + n - 1
            j = bisect_right(new_nums, right)
            count = j - i
            ans = min(ans, n - count)

        return ans
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        
        // std::set automatically sorts
        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums;
        for (int num : unique) {
            newNums.push_back(num);
        }
        
        int j = 0;
        for (int i = 0; i < newNums.size(); i++) {
            while (j < newNums.size() && newNums[j] < newNums[i] + n) {
                j++;
            }
            
            int count = j - i;
            ans = min(ans, n - count);
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int ans = n;
        
        HashSet<Integer> unique = new HashSet<>();
        for (int num : nums) {
            unique.add(num);
        }
        
        int[] newNums = new int[unique.size()];
        int index = 0;
        
        for (int num : unique) {
            newNums[index++] = num;
        }
            
        Arrays.sort(newNums);
        
        int j = 0;
        for (int i = 0; i < newNums.length; i++) {
            while (j < newNums.length && newNums[j] < newNums[i] + n) {
                j++;
            }

            int count = j - i;
            ans = Math.min(ans, n - count);
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        ans = n
        new_nums = sorted(set(nums))
        j = 0
        
        for i in range(len(new_nums)):
            while j < len(new_nums) and new_nums[j] < new_nums[i] + n:
                j += 1
            
            count = j - i
            ans = min(ans, n - count)

        return ans
```

</details>
