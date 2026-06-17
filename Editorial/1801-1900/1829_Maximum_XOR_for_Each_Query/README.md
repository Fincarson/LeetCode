# 1829. Maximum XOR for Each Query

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-xor-for-each-query/)  
`Array` `Bit Manipulation` `Prefix Sum`

**Problem Link:** [LeetCode 1829 - Maximum XOR for Each Query](https://leetcode.com/problems/maximum-xor-for-each-query/)

## Problem

You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:

Return an array answer, where answer[i] is the answer to the ith query.

### Example 1

```text
Input: nums = [0,1,1,3], maximumBit = 2
Output: [0,3,2,3]
Explanation: The queries are answered as follows:
1st query: nums = [0,1,1,3], k = 0 since 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3.
2nd query: nums = [0,1,1], k = 3 since 0 XOR 1 XOR 1 XOR 3 = 3.
3rd query: nums = [0,1], k = 2 since 0 XOR 1 XOR 2 = 3.
4th query: nums = [0], k = 3 since 0 XOR 3 = 3.
```

### Example 2

```text
Input: nums = [2,3,4,7], maximumBit = 3
Output: [5,2,6,5]
Explanation: The queries are answered as follows:
1st query: nums = [2,3,4,7], k = 5 since 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7.
2nd query: nums = [2,3,4], k = 2 since 2 XOR 3 XOR 4 XOR 2 = 7.
3rd query: nums = [2,3], k = 6 since 2 XOR 3 XOR 6 = 7.
4th query: nums = [2], k = 5 since 2 XOR 5 = 7.
```

### Example 3

```text
Input: nums = [0,1,2,2,5,7], maximumBit = 3
Output: [4,3,6,4,6,7]
```

## Constraints

- nums.length == n
- 1 <= n <= 105
- 1 <= maximumBit <= 20
- 0 <= nums[i] < 2maximumBit
- numsÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ is sorted in ascending order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count the Number of Beautiful Subarrays](https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1829. Maximum XOR for Each Query

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Array + Bit Masking | C++, Java, Python3 |
| Optimized Calculation + Bit Masking | C++, Java, Python3 |

## Approach 1: Prefix Array + Bit Masking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> prefixXOR(n);
        prefixXOR[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
        }

        vector<int> ans(n);
        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < n; i++) {
            // find k to maximize value
            int currentXOR = prefixXOR[n - 1 - i];
            ans[i] = currentXOR ^ mask;
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

    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int[] prefixXOR = new int[nums.length];
        prefixXOR[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
        }
        int[] ans = new int[nums.length];

        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < nums.length; i++) {
            // find k to maximize value
            int currentXOR = prefixXOR[prefixXOR.length - 1 - i];
            ans[i] = currentXOR ^ mask;
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
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        prefix_xor = [0] * len(nums)
        prefix_xor[0] = nums[0]
        for i in range(1, len(nums)):
            prefix_xor[i] = prefix_xor[i - 1] ^ nums[i]
        ans = [0] * len(nums)

        mask = (1 << maximumBit) - 1

        for i in range(len(nums)):
            # find k to maximize value
            current_xor = prefix_xor[len(prefix_xor) - 1 - i]
            ans[i] = current_xor ^ mask

        return ans
```

</details>

<br>

## Approach 2: Optimized Calculation + Bit Masking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorProduct = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorProduct = xorProduct ^ nums[i];
        }
        vector<int> ans(nums.size());

        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = xorProduct ^ mask;
            // remove last element
            xorProduct = xorProduct ^ nums[nums.size() - 1 - i];
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

    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int xorProduct = 0;
        for (int i = 0; i < nums.length; i++) {
            xorProduct = xorProduct ^ nums[i];
        }
        int[] ans = new int[nums.length];

        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < nums.length; i++) {
            ans[i] = xorProduct ^ mask;
            // remove last element
            xorProduct = xorProduct ^ nums[nums.length - 1 - i];
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
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        xor_product = 0
        for i in range(len(nums)):
            xor_product = xor_product ^ nums[i]
        ans = [0] * len(nums)

        mask = (1 << maximumBit) - 1

        for i in range(len(nums)):
            ans[i] = xor_product ^ mask
            # remove last element
            xor_product = xor_product ^ nums[len(nums) - 1 - i]

        return ans
```

</details>
