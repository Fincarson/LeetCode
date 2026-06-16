# 673. Number of Longest Increasing Subsequence

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)  
`Array` `Dynamic Programming` `Binary Indexed Tree` `Segment Tree`

**Problem Link:** [LeetCode 673 - Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

## Problem

Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

### Example 1

```text
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
```

### Example 2

```text
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
```

## Constraints

- 1 <= nums.length <= 2000
- -106 <= nums[i] <= 106
- The answer is guaranteed to fit inside a 32-bit integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Longest Increasing Subsequence II](https://leetcode.com/problems/longest-increasing-subsequence-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 673. Number of Longest Increasing Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bottom-up Dynamic Programming | C++, Java, Python3 |
| Top-down Dynamic Programming (Memoization) | C++, Java, Python3 |

## Approach 1: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1);
        vector<int> count(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }
                    if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int maxLength = *max_element(length.begin(), length.end());
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength) {
                result += count[i];
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
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int[] length = new int[n];
        int[] count = new int[n];
        
        Arrays.fill(length, 1);
        Arrays.fill(count, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }
                    if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }
        
        int maxLength = 0;
        int result = 0;

        for (int len : length) {
            maxLength = Math.max(maxLength, len);
        }

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength) {
                result += count[i];
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
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        length = [1] * n
        count = [1] * n
        
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    if length[j] + 1 > length[i]:
                        length[i] = length[j] + 1
                        count[i] = 0
                    if length[j] + 1 == length[i]:
                        count[i] += count[j]
        
        max_length = max(length)
        result = 0
        
        for i in range(n):
            if length[i] == max_length:
                result += count[i]
        
        return result
```

</details>

<br>

## Approach 2: Top-down Dynamic Programming (Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 0);
        vector<int> count(n, 0);

        function<void(int)> calculateDP = [&](int i) {
            if (length[i] != 0)
                return;

            length[i] = 1;
            count[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    calculateDP(j);
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }
                    if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
        };

	int maxLength = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            calculateDP(i);
            if (length[i] > maxLength)
                maxLength = length[i];
        }

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength)
                result += count[i];
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
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int[] length = new int[n];
        int[] count = new int[n];
        int maxLength = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            calculateDP(i, nums, length, count);
            maxLength = Math.max(maxLength, length[i]);
        }

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength) {
                result += count[i];
            }
        }

        return result;
    }

    private void calculateDP(int i, int[] nums, int[] length, int[] count) {
        if (length[i] != 0) {
            return;
        }

        length[i] = 1;
        count[i] = 1;

        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                calculateDP(j, nums, length, count);
                if (length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    count[i] = 0;
                }
                if (length[j] + 1 == length[i]) {
                    count[i] += count[j];
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findNumberOfLIS(self, nums):
        n = len(nums)
        length = [0] * n
        count = [0] * n

        def calculate_dp(i):
            if length[i] != 0:
                return

            length[i] = 1
            count[i] = 1

            for j in range(i):
                if nums[j] < nums[i]:
                    calculate_dp(j)
                    if length[j] + 1 > length[i]:
                        length[i] = length[j] + 1
                        count[i] = 0
                    if length[j] + 1 == length[i]:
                        count[i] += count[j]

        max_length = 0
        result = 0
        for i in range(n):
            calculate_dp(i)
            max_length = max(max_length, length[i])

        for i in range(n):
            if length[i] == max_length:
                result += count[i]

        return result
```

</details>
