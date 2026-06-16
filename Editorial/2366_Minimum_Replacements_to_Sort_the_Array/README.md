# 2366. Minimum Replacements to Sort the Array

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-replacements-to-sort-the-array/)  
`Array` `Math` `Greedy`

**Problem Link:** [LeetCode 2366 - Minimum Replacements to Sort the Array](https://leetcode.com/problems/minimum-replacements-to-sort-the-array/)

## Problem

You are given a 0-indexed integer array nums. In one operation you can replace any element of the array with any two elements that sum to it.

- For example, consider nums = [5,6,7]. In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].

Return the minimum number of operations to make an array that is sorted in non-decreasing order.

### Example 1

```text
Input: nums = [3,9,3]
Output: 2
Explanation: Here are the steps to sort the array in non-decreasing order:
- From [3,9,3], replace the 9 with 3 and 6 so the array becomes [3,3,6,3]
- From [3,3,6,3], replace the 6 with 3 and 3 so the array becomes [3,3,3,3,3]
There are 2 steps to sort the array in non-decreasing order. Therefore, we return 2.
```

### Example 2

```text
Input: nums = [1,2,3,4,5]
Output: 0
Explanation: The array is already in non-decreasing order. Therefore, we return 0.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Operations to Make the Array Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2366. Minimum Replacements to Sort the Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C++, Java, Python3 |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();

        // Start from the second last element, as the last one is always sorted.
        for (int i = n - 2; i >= 0; i--) {
            // No need to break if they are already in order.
            if (nums[i] <= nums[i + 1]) {
                continue;
            }

            // Count how many elements are made from breaking nums[i].
            long long numElements = ceil((nums[i] + nums[i + 1] - 1LL) / (nums[i + 1]));

            // It requires numElements - 1 replacement operations.
            answer += numElements - 1;

            // Maximize nums[i] after replacement.
            nums[i] = nums[i] / numElements;
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long minimumReplacement(int[] nums) {
        long answer = 0;
        int n = nums.length;

        // Start from the second last element, as the last one is always sorted.
        for (int i = n - 2; i >= 0; i--) {
            // No need to break if they are already in order.
            if (nums[i] <= nums[i + 1]) {
                continue;
            }

            // Count how many elements are made from breaking nums[i].
            long numElements = (long)(nums[i] + nums[i + 1] - 1) / (long)nums[i + 1];

            // It requires numElements - 1 replacement operations.
            answer += numElements - 1;

            // Maximize nums[i] after replacement.
            nums[i] = nums[i] / (int)numElements;
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        answer = 0
        n = len(nums)

        # Start from the second last element, as the last one is always sorted.
        for i in range(n - 2, -1, -1):
            # No need to break if they are already in order.
            if nums[i] <= nums[i + 1]:
                continue
            
            # Count how many elements are made from breaking nums[i].
            num_elements = (nums[i] + nums[i + 1] - 1) // nums[i + 1]
            
            # It requires numElements - 1 replacement operations.
            answer += num_elements - 1

            # Maximize nums[i] after replacement.
            nums[i] = nums[i] // num_elements

        return answer
```

</details>
