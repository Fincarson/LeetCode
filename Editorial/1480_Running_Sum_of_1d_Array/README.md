# 1480. Running Sum of 1d Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/running-sum-of-1d-array/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 1480 - Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)

## Problem

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

### Example 1

```text
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```

### Example 2

```text
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```

### Example 3

```text
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
```

## Constraints

- 1 <= nums.length <= 1000
- -10^6 <= nums[i] <= 10^6

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1480. Running Sum of 1d Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Separate Space | C++, Java |
| Using Input Array for Output | C++, Java |

## Approach 1: Using Separate Space

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        // Initialize result array with first element in nums.
        vector<int> result = {nums[0]};

        for (int i = 1; i < nums.size(); i++) {
            // Result at index `i` is sum of result at `i-1` and element at `i`.
            result.push_back(result.back() + nums[i]);
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
public int[] runningSum(int[] nums) {
        int[] result = new int[nums.length];

        // Initialize first element of result array with first element in nums.
        result[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            // Result at index `i` is sum of result at `i-1` and element at `i`.
            result[i] = result[i - 1] + nums[i];
        }
        return result;
    }
}
```

</details>

<br>

## Approach 2: Using Input Array for Output

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            // Result at index `i` is sum of result at `i-1` and element at `i`.
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
public int[] runningSum(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            // Result at index `i` is sum of result at `i-1` and element at `i`.
            nums[i] += nums[i - 1];
        }
        return nums;
    }
}
```

</details>
