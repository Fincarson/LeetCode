# 2270. Number of Ways to Split Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-ways-to-split-array/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 2270 - Number of Ways to Split Array](https://leetcode.com/problems/number-of-ways-to-split-array/)

## Problem

You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

- The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
- There is at least one element to the right of i. That is, 0 <= i < n - 1.

Return the number of valid splits in nums.

### Example 1

```text
Input: nums = [10,4,-8,7]
Output: 2
Explanation:
There are three ways of splitting nums into two non-empty parts:
- Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid split.
Thus, the number of valid splits in nums is 2.
```

### Example 2

```text
Input: nums = [2,3,1,0]
Output: 2
Explanation:
There are two valid splits in nums:
- Split nums at index 1. Then, the first part is [2,3], and its sum is 5. The second part is [1,0], and its sum is 1. Since 5 >= 1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [2,3,1], and its sum is 6. The second part is [0], and its sum is 0. Since 6 >= 0, i = 2 is a valid split.
```

## Constraints

- 2 <= nums.length <= 105
- -105 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Ways to Split Array Into Three Subarrays](https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Average Difference](https://leetcode.com/problems/minimum-average-difference/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2270. Number of Ways to Split Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sum Array | C++, Java, Python3 |
| Optimized Prefix and Suffix Sums | C++, Java, Python3 |

## Approach 1: Prefix Sum Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        // Prefix sum array to store cumulative sums
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];

        // Build prefix sum array
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        int count = 0;
        // Check each possible split position
        for (int i = 0; i < n - 1; i++) {
            // Sum of left part (0 to i)
            long long leftSum = prefSum[i];
            // Sum of right part (i+1 to n-1)
            long long rightSum = prefSum[n - 1] - prefSum[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int waysToSplitArray(int[] nums) {
        int n = nums.length;
        // Prefix sum array to store cumulative sums
        long[] prefSum = new long[n];
        prefSum[0] = nums[0];

        // Build prefix sum array
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        int count = 0;
        // Check each possible split position
        for (int i = 0; i < n - 1; i++) {
            // Sum of left part (0 to i)
            long leftSum = prefSum[i];
            // Sum of right part (i+1 to n-1)
            long rightSum = prefSum[n - 1] - prefSum[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def waysToSplitArray(self, nums: list[int]) -> int:
        n = len(nums)
        # Prefix sum array to store cumulative sums
        pref_sum = [0] * n
        pref_sum[0] = nums[0]

        # Build prefix sum array
        for i in range(1, n):
            pref_sum[i] = pref_sum[i - 1] + nums[i]

        # Check each possible split position
        count = sum(
            1 for i in range(n - 1) if pref_sum[i] >= pref_sum[-1] - pref_sum[i]
        )

        return count
```

</details>

<br>

## Approach 2: Optimized Prefix and Suffix Sums

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Keep track of sum of elements on left and right sides
        long long leftSum = 0, rightSum = 0;

        // Initially all elements are on right side
        for (int num : nums) {
            rightSum += num;
        }

        int count = 0;
        // Try each possible split position
        for (int i = 0; i < nums.size() - 1; i++) {
            // Move current element from right to left side
            leftSum += nums[i];
            rightSum -= nums[i];

            // Check if this creates a valid split
            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int waysToSplitArray(int[] nums) {
        // Keep track of sum of elements on left and right sides
        long leftSum = 0, rightSum = 0;

        // Initially all elements are on right side
        for (int num : nums) {
            rightSum += num;
        }

        int count = 0;
        // Try each possible split position
        for (int i = 0; i < nums.length - 1; i++) {
            // Move current element from right to left side
            leftSum += nums[i];
            rightSum -= nums[i];

            // Check if this creates a valid split
            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def waysToSplitArray(self, nums: list[int]) -> int:
        # Keep track of sum of elements on left and right sides
        left_sum = right_sum = 0

        # Initially all elements are on right side
        right_sum = sum(nums)

        # Try each possible split position
        count = 0
        for i in range(len(nums) - 1):
            # Move current element from right to left side
            left_sum += nums[i]
            right_sum -= nums[i]

            # Check if this creates a valid split
            if left_sum >= right_sum:
                count += 1

        return count
```

</details>
