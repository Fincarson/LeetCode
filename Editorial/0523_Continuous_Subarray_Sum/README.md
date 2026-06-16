# 523. Continuous Subarray Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/continuous-subarray-sum/)  
`Array` `Hash Table` `Math` `Prefix Sum`

**Problem Link:** [LeetCode 523 - Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/)

## Problem

Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

- its length is at least two, and
- the sum of the elements of the subarray is a multiple of k.

Note that:

- A subarray is a contiguous part of the array.
- An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

### Example 1

```text
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
```

### Example 2

```text
Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
```

### Example 3

```text
Input: nums = [23,2,6,4,7], k = 13
Output: false
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 109
- 0 <= sum(nums[i]) <= 231 - 1
- 1 <= k <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Number of Operations to Make Array Continuous](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Intervals Between Identical Elements](https://leetcode.com/problems/intervals-between-identical-elements/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Apply Operations to Make All Array Elements Equal to Zero](https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 523. Continuous Subarray Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sum and Hashing | C++, Java, Python3 |

## Approach 1: Prefix Sum and Hashing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixMod = 0;
        unordered_map<int, int> modSeen;
        modSeen[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            prefixMod = (prefixMod + nums[i]) % k;

            if (modSeen.find(prefixMod) != modSeen.end()) {
                // ensures that the size of subarray is atleast 2
                if (i - modSeen[prefixMod] > 1) {
                    return 1;
                }
            } else {
                // mark the value of prefixMod with the current index.
                modSeen[prefixMod] = i;
            }
        }

        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.HashMap;

class Solution {

    public boolean checkSubarraySum(int[] nums, int k) {
        int prefixMod = 0;
        HashMap<Integer, Integer> modSeen = new HashMap<>();
        modSeen.put(0, -1);

        for (int i = 0; i < nums.length; i++) {
            prefixMod = (prefixMod + nums[i]) % k;

            if (modSeen.containsKey(prefixMod)) {
                // ensures that the size of subarray is at least 2
                if (i - modSeen.get(prefixMod) > 1) {
                    return true;
                }
            } else {
                // mark the value of prefixMod with the current index.
                modSeen.put(prefixMod, i);
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkSubarraySum(self, nums, k):
        prefix_mod = 0
        mod_seen = {0: -1}

        for i in range(len(nums)):
            prefix_mod = (prefix_mod + nums[i]) % k

            if prefix_mod in mod_seen:
                # ensures that the size of subarray is at least 2
                if i - mod_seen[prefix_mod] > 1:
                    return True
            else:
                # mark the value of prefix_mod with the current index.
                mod_seen[prefix_mod] = i

        return False
```

</details>
