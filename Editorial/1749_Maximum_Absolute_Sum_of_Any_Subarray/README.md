# 1749. Maximum Absolute Sum of Any Subarray

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1749 - Maximum Absolute Sum of Any Subarray](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/)

## Problem

You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

- If x is a negative integer, then abs(x) = -x.
- If x is a non-negative integer, then abs(x) = x.

### Example 1

```text
Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
```

### Example 2

```text
Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
```

## Constraints

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1749. Maximum Absolute Sum of Any Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy - Prefix Sum | C++, Java, Python3 |
| Greedy - Prefix Sum - Shorter | C++, Java, Python3 |
| Bidirectional Kadane's Algorithm | C++, Java, Python3 |

## Approach 1: Greedy - Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPrefixSum = INT_MAX, maxPrefixSum = INT_MIN;
        int prefixSum = 0, maxAbsSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Prefix sum from index 0 to i
            prefixSum += nums[i];

            // Minimum & Maximum prefix sum we have seen so far
            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);

            if (prefixSum >= 0) {
                // If the prefixSum is positive, we will get the difference
                // between prefixSum & minPrefixSum
                maxAbsSum =
                    max(maxAbsSum, max(prefixSum, prefixSum - minPrefixSum));
            } else if (prefixSum <= 0) {
                // If the prefixSum is negative, we will get the absolute
                // difference between prefixSum & maxPrefixSum
                maxAbsSum = max(maxAbsSum, max(abs(prefixSum),
                                               abs(prefixSum - maxPrefixSum)));
            }
        }

        return maxAbsSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxAbsoluteSum(int[] nums) {
        int minPrefixSum = Integer.MAX_VALUE, maxPrefixSum = Integer.MIN_VALUE;
        int prefixSum = 0, maxAbsSum = 0;

        for (int i = 0; i < nums.length; i++) {
            // Prefix sum from index 0 to i
            prefixSum += nums[i];

            // Minimum & Maximum prefix sum we have seen so far
            minPrefixSum = Math.min(minPrefixSum, prefixSum);
            maxPrefixSum = Math.max(maxPrefixSum, prefixSum);

            if (prefixSum >= 0) {
                // If the prefixSum is positive, we will get the difference between prefixSum &
                // minPrefixSum
                maxAbsSum = Math.max(
                    maxAbsSum,
                    Math.max(prefixSum, prefixSum - minPrefixSum)
                );
            } else if (prefixSum <= 0) {
                // If the prefixSum is negative, we will get the absolute difference between
                // prefixSum & maxPrefixSum
                maxAbsSum = Math.max(
                    maxAbsSum,
                    Math.max(
                        Math.abs(prefixSum),
                        Math.abs(prefixSum - maxPrefixSum)
                    )
                );
            }
        }

        return maxAbsSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxAbsoluteSum(self, nums):
        min_prefix_sum = float("inf")
        max_prefix_sum = float("-inf")
        prefix_sum = 0
        max_abs_sum = 0

        for num in nums:
            # Prefix sum from index 0 to i
            prefix_sum += num

            # Minimum & Maximum prefix sum we have seen so far
            min_prefix_sum = min(min_prefix_sum, prefix_sum)
            max_prefix_sum = max(max_prefix_sum, prefix_sum)

            if prefix_sum >= 0:
                # If the prefix_sum is positive, we will get the difference
                # between prefix_sum & min_prefix_sum
                max_abs_sum = max(
                    max_abs_sum, max(prefix_sum, prefix_sum - min_prefix_sum)
                )
            elif prefix_sum <= 0:
                # If the prefix_sum is negative, we will get the absolute difference
                # between prefix_sum & max_prefix_sum
                max_abs_sum = max(
                    max_abs_sum,
                    max(abs(prefix_sum), abs(prefix_sum - max_prefix_sum)),
                )

        return max_abs_sum
```

</details>

<br>

## Approach 2: Greedy - Prefix Sum - Shorter

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPrefixSum = 0, maxPrefixSum = 0;

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);
        }

        return maxPrefixSum - minPrefixSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxAbsoluteSum(int[] nums) {
        int minPrefixSum = 0, maxPrefixSum = 0;
        int prefixSum = 0;

        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];

            minPrefixSum = Math.min(minPrefixSum, prefixSum);
            maxPrefixSum = Math.max(maxPrefixSum, prefixSum);
        }

        return maxPrefixSum - minPrefixSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxAbsoluteSum(self, nums):
        min_prefix_sum = 0
        max_prefix_sum = 0
        prefix_sum = 0

        for num in nums:
            prefix_sum += num

            min_prefix_sum = min(min_prefix_sum, prefix_sum)
            max_prefix_sum = max(max_prefix_sum, prefix_sum)

        return max_prefix_sum - min_prefix_sum
```

</details>

<br>

## Approach 3: Bidirectional Kadane's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int positiveSum = 0, negativeSum = 0, ans = 0;
        for (int num : nums) {
            positiveSum = max(0, positiveSum + num);
            negativeSum = min(0, negativeSum + num);
            ans = max({ans, positiveSum, abs(negativeSum)});
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

    public int maxAbsoluteSum(int[] nums) {
        int positiveSum = 0, negativeSum = 0, ans = 0;
        for (int num : nums) {
            positiveSum = Math.max(0, positiveSum + num);
            negativeSum = Math.min(0, negativeSum + num);
            ans = Math.max(ans, Math.max(positiveSum, Math.abs(negativeSum)));
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
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        positive_sum = negative_sum = ans = 0
        for num in nums:
            positive_sum = max(0, positive_sum + num)
            negative_sum = min(0, negative_sum + num)
            ans = max(ans, positive_sum, abs(negative_sum))
        return ans
```

</details>
