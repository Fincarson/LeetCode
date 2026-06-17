# 2563. Count the Number of Fair Pairs

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-the-number-of-fair-pairs/)  
`Array` `Two Pointers` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 2563 - Count the Number of Fair Pairs](https://leetcode.com/problems/count-the-number-of-fair-pairs/)

## Problem

Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

- 0 <= i < j < n, and
- lower <= nums[i] + nums[j] <= upper

### Example 1

```text
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
```

### Example 2

```text
Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
```

## Constraints

- 1 <= nums.length <= 105
- nums.length == n
- -109 <= nums[i] <= 109
- -109 <= lower <= upper <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Finding Pairs With a Certain Sum](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Pairs Whose Sum is Less than Target](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2563. Count the Number of Fair Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Two Pointers | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long lower_bound(vector<int>& nums, int low, int high, int element) {
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (nums[mid] >= element) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            // Assume we have picked nums[i] as the first pair element.

            // `low` indicates the number of possible pairs with sum < lower.
            int low =
                lower_bound(nums, i + 1, nums.size() - 1, lower - nums[i]);

            // `high` indicates the number of possible pairs with sum <= upper.
            int high =
                lower_bound(nums, i + 1, nums.size() - 1, upper - nums[i] + 1);

            // Their difference gives the number of elements with sum in the
            // given range.
            ans += 1LL * (high - low);
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

    long lower_bound(int[] nums, int low, int high, int element) {
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (nums[mid] >= element) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long ans = 0;
        for (int i = 0; i < nums.length; i++) {
            // Assume we have picked nums[i] as the first pair element.

            // `low` indicates the number of possible pairs with sum < lower.
            long low = lower_bound(
                nums,
                i + 1,
                nums.length - 1,
                lower - nums[i]
            );

            // `high` indicates the number of possible pairs with sum <= upper.
            long high = lower_bound(
                nums,
                i + 1,
                nums.length - 1,
                upper - nums[i] + 1
            );

            // Their difference gives the number of elements with sum in the
            // given range.
            ans += 1 * (high - low);
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
    def lower_bound(self, nums, low, high, element):
        while low <= high:
            mid = low + ((high - low) // 2)
            if nums[mid] >= element:
                high = mid - 1
            else:
                low = mid + 1
        return low

    def countFairPairs(self, nums, lower, upper):
        nums.sort()
        ans = 0
        for i in range(len(nums)):
            # Assume we have picked nums[i] as the first pair element.

            # `low` indicates the number of possible pairs with sum < lower.
            low = self.lower_bound(nums, i + 1, len(nums) - 1, lower - nums[i])

            # `high` indicates the number of possible pairs with sum <= upper.
            high = self.lower_bound(
                nums, i + 1, len(nums) - 1, upper - nums[i] + 1
            )

            # Their difference gives the number of elements with sum in the
            # given range.
            ans += high - low

        return ans
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
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
    }

private:
    long long lower_bound(vector<int>& nums, int value) {
        int left = 0, right = nums.size() - 1;
        long long result = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            // If sum is less than value, add the size of window to result and
            // move to the next index.
            if (sum < value) {
                result += (right - left);
                left++;
            } else {
                // Otherwise, shift the right pointer backwards, until we get a
                // valid window.
                right--;
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
    }

    // Calculate the number of pairs with sum less than `value`.
    private long lower_bound(int[] nums, int value) {
        int left = 0, right = nums.length - 1;
        long result = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            // If sum is less than value, add the size of window to result and move to the
            // next index.
            if (sum < value) {
                result += (right - left);
                left++;
            } else {
                // Otherwise, shift the right pointer backwards, until we get a valid window.
                right--;
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        return self.lower_bound(nums, upper + 1) - self.lower_bound(nums, lower)

    # Calculate the number of pairs with sum less than `value`.
    def lower_bound(self, nums: List[int], value: int) -> int:
        left = 0
        right = len(nums) - 1
        result = 0
        while left < right:
            sum = nums[left] + nums[right]
            # If sum is less than value, add the size of window to result and move to the
            # next index.
            if sum < value:
                result += right - left
                left += 1
            else:
                # Otherwise, shift the right pointer backwards, until we get a valid window.
                right -= 1
        return result
```

</details>
