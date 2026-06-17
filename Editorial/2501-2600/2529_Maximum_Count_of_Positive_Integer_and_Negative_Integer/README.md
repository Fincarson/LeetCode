# 2529. Maximum Count of Positive Integer and Negative Integer

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/)  
`Array` `Binary Search` `Counting`

**Problem Link:** [LeetCode 2529 - Maximum Count of Positive Integer and Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/)

## Problem

Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

- In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.

Note that 0 is neither positive nor negative.

### Example 1

```text
Input: nums = [-2,-1,-1,1,2,3]
Output: 3
Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
```

### Example 2

```text
Input: nums = [-3,-2,-1,0,0,1,2]
Output: 3
Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.
```

### Example 3

```text
Input: nums = [5,20,66,1314]
Output: 4
Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.
```

## Constraints

- 1 <= nums.length <= 2000
- -2000 <= nums[i] <= 2000
- nums is sorted in a non-decreasing order.

Follow up: Can you solve the problem in O(log(n)) time complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Search](https://leetcode.com/problems/binary-search/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2529. Maximum Count of Positive Integer and Negative Integer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int positiveCount = 0, negativeCount = 0;

        for (int num : nums) {
            positiveCount += num > 0;
            negativeCount += num < 0;
        }

        return max(positiveCount, negativeCount);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumCount(int[] nums) {
        int positiveCount = 0, negativeCount = 0;

        for (int num : nums) {
            if (num > 0) {
                positiveCount++;
            } else if (num < 0) {
                negativeCount++;
            }
        }

        return Math.max(positiveCount, negativeCount);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumCount(self, nums):
        positive_count = 0
        negative_count = 0

        for num in nums:
            if num > 0:
                positive_count += 1
            elif num < 0:
                negative_count += 1

        return max(positive_count, negative_count)
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Return the first index where the value is equal to or greater than zero.
    int lowerBound(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        int index = nums.size();

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] < 0) {
                start = mid + 1;
            } else if (nums[mid] >= 0) {
                end = mid - 1;
                index = mid;
            }
        }

        return index;
    }

    // Return the first index where the value is greater than zero.
    int upperBound(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        int index = nums.size();

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] <= 0) {
                start = mid + 1;
            } else if (nums[mid] > 0) {
                end = mid - 1;
                index = mid;
            }
        }

        return index;
    }

public:
    int maximumCount(vector<int> &nums) {
        // All integers from the first non-zero to last will be positive
        // integers.
        int positiveCount = nums.size() - upperBound(nums);
        // All integers from the index 0 to index before the first zero index
        // will be negative.
        int negativeCount = lowerBound(nums);

        return max(positiveCount, negativeCount);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Return the first index where the value is equal to or greater than zero.
    private int lowerBound(int[] nums) {
        int start = 0, end = nums.length - 1;
        int index = nums.length;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] < 0) {
                start = mid + 1;
            } else if (nums[mid] >= 0) {
                end = mid - 1;
                index = mid;
            }
        }

        return index;
    }

    // Return the first index where the value is greater than zero.
    private int upperBound(int[] nums) {
        int start = 0, end = nums.length - 1;
        int index = nums.length;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] <= 0) {
                start = mid + 1;
            } else if (nums[mid] > 0) {
                end = mid - 1;
                index = mid;
            }
        }

        return index;
    }

    public int maximumCount(int[] nums) {
        // All integers from the first non-zero to last will be positive
        // integers.
        int positiveCount = nums.length - upperBound(nums);
        // All integers from the index 0 to index before the first zero index
        // will be negative.
        int negativeCount = lowerBound(nums);

        return Math.max(positiveCount, negativeCount);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Return the first index where the value is equal to or greater than zero.
    def lower_bound(self, nums):
        start, end = 0, len(nums) - 1
        index = len(nums)

        while start <= end:
            mid = (start + end) // 2

            if nums[mid] < 0:
                start = mid + 1
            else:
                end = mid - 1
                index = mid

        return index

    # Return the first index where the value is greater than zero.
    def upper_bound(self, nums):
        start, end = 0, len(nums) - 1
        index = len(nums)

        while start <= end:
            mid = (start + end) // 2

            if nums[mid] <= 0:
                start = mid + 1
            else:
                end = mid - 1
                index = mid

        return index

    def maximumCount(self, nums):
        # All integers from the first non-zero to last will be positive
        # integers.
        positiveCount = len(nums) - self.upper_bound(nums)
        # All integers from the index 0 to index before the first zero index
        # will be negative.
        negativeCount = self.lower_bound(nums)

        return max(positiveCount, negativeCount)
```

</details>
