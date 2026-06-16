# 1658. Minimum Operations to Reduce X to Zero

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)  
`Array` `Hash Table` `Binary Search` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 1658 - Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

## Problem

You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

### Example 1

```text
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
```

### Example 2

```text
Input: nums = [5,6,7,8,9], x = 4
Output: -1
```

### Example 3

```text
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 104
- 1 <= x <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Convert Number](https://leetcode.com/problems/minimum-operations-to-convert-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Removing Minimum Number of Magic Beans](https://leetcode.com/problems/removing-minimum-number-of-magic-beans/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Make the Integer Zero](https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1658. Minimum Operations to Reduce X to Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers (Indirectly) | C++, Java, Python3 |

## Approach 1: Two Pointers (Indirectly)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        int n = nums.size();
        int maxi = -1;
        int left = 0;
        int current = 0;

        for (int right = 0; right < n; right++) {
            // sum([left ,..., right]) = total - x
            current += nums[right];
            // if larger, move `left` to left
            while (current > total - x && left <= right) {
                current -= nums[left];
                left += 1;
            }
            // check if equal
            if (current == total - x) {
                maxi = max(maxi, right - left + 1);
            }
        }
        return maxi != -1 ? n - maxi : -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minOperations(int[] nums, int x) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        int n = nums.length;
        int maxi = -1;
        int left = 0;
        int current = 0;

        for (int right = 0; right < n; right++) {
            // sum([left ,..., right]) = total - x
            current += nums[right];
            // if larger, move `left` to left
            while (current > total - x && left <= right) {
                current -= nums[left];
                left += 1;
            }
            // check if equal
            if (current == total - x) {
                maxi = Math.max(maxi, right - left + 1);
            }
        }
        return maxi != -1 ? n - maxi : -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        total = sum(nums)
        n = len(nums)
        maxi = -1
        left = 0
        current = 0

        for right in range(n):
            # sum([left ,..., right]) = total - x
            current += nums[right]
            # if larger, move `left` to left
            while current > total-x and left <= right:
                current -= nums[left]
                left += 1
            # check if equal
            if current == total-x:
                maxi = max(maxi, right-left+1)

        return n-maxi if maxi != -1 else -1
```

</details>
