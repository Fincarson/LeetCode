# 2369. Check if There is a Valid Partition For The Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 2369 - Check if There is a Valid Partition For The Array](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/)

## Problem

You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

Return true if the array has at least one valid partition. Otherwise, return false.

### Example 1

```text
Input: nums = [4,4,4,5,6]
Output: true
Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.
```

### Example 2

```text
Input: nums = [1,1,1,2]
Output: false
Explanation: There is no valid partition for this array.
```

## Constraints

- 2 <= nums.length <= 105
- 1 <= nums[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count the Number of Good Partitions](https://leetcode.com/problems/count-the-number-of-good-partitions/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2369. Check if There is a Valid Partition For The Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | Java, Python3 |
| Bottom-Up Dynamic Programming | Java, Python3 |
| Space Optimized Bottom-Up Dynamic Programming | Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Map<Integer, Boolean> memo = new HashMap<>();

    // Determine if the prefix array nums[0 ~ i] has a valid partition
    boolean prefixIsValid(int[] nums, int i) {
        if (memo.containsKey(i)) {
            return memo.get(i);
        }
        boolean ans = false;

        // Check 3 possibilities
        if (i > 0 && nums[i] == nums[i - 1]) {
            ans |= prefixIsValid(nums, i - 2);
        }
        if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) {
            ans |= prefixIsValid(nums, i - 3);
        }
        if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) {
            ans |= prefixIsValid(nums, i - 3);
        }
        memo.put(i, ans);
        return ans;
    }

    public boolean validPartition(int[] nums) {
        int n = nums.length;
        memo.put(-1, true);

        return prefixIsValid(nums, n - 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        memo = {-1: True}

        # Determine if the prefix array nums[0 ~ i] has a valid partition
        def prefixIsValid(i):
            if i in memo:
                return memo[i]
            ans = False

            # Check 3 possibilities
            if i > 0 and nums[i] == nums[i - 1]:
                ans |= prefixIsValid(i - 2)
            if i > 1 and nums[i] == nums[i - 1] == nums[i - 2]:
                ans |= prefixIsValid(i - 3)
            if i > 1 and nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2:
                ans |= prefixIsValid(i - 3)
            memo[i] = ans
            return ans

        return prefixIsValid(n - 1)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean validPartition(int[] nums) {
        int n = nums.length;
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;

        // Determine if the prefix array nums[0 ~ i] has a valid partition
        for (int i = 0; i < n; i++) {
            int dpIndex = i + 1;

            // Check 3 possibilities
            if (i > 0 && nums[i] == nums[i - 1]) {
                dp[dpIndex] |= dp[dpIndex - 2];
            }
            if (i > 1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                dp[dpIndex] |= dp[dpIndex - 3];
            }
            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2) {
                dp[dpIndex] |= dp[dpIndex - 3];
            }
        }

        return dp[n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [True] + [False] * n

        # Determine if the prefix array nums[0 ~ i] has a valid partition
        for i in range(n):
            dp_index = i + 1

            # Check 3 possibilities
            if i > 0 and nums[i] == nums[i - 1]:
                dp[dp_index] |= dp[dp_index - 2]
            if i > 1 and nums[i] == nums[i - 1] == nums[i - 2]:
                dp[dp_index] |= dp[dp_index - 3]
            if i > 1 and nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2:
                dp[dp_index] |= dp[dp_index - 3]
 
        return dp[n]
```

</details>

<br>

## Approach 3: Space Optimized Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean validPartition(int[] nums) {
        int n = nums.length;
        boolean[] dp = new boolean[3];
        dp[0] = true;

        // Determine if prefix array nums[0 ~ i] has a valid partition
        for (int i = 0; i < n; i++) {
            int dpIndex = i + 1;
            boolean ans = false;

            // Check 3 possibilities
            if (i > 0 && nums[i] == nums[i - 1]) {
                ans |= dp[(dpIndex - 2) % 3];
            }
            if (i > 1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                ans |= dp[(dpIndex - 3) % 3];
            }
            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2) {
                ans |= dp[(dpIndex - 3) % 3];
            }

            dp[dpIndex % 3] = ans;
        }

        return dp[n % 3];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        
        # Only record the most recent 3 indices
        dp = [True] + [False] * 2

        # Determine if the prefix array nums[0 ~ i] has a valid partition
        for i in range(n):
            dp_index = i + 1
            ans = False
            if i > 0 and nums[i] == nums[i - 1]:
                ans |= dp[(dp_index - 2) % 3]
            if i > 1 and nums[i] == nums[i - 1] == nums[i - 2]:
                ans |= dp[(dp_index - 3) % 3]
            if i > 1 and nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2:
                ans |= dp[(dp_index - 3) % 3]
            dp[dp_index % 3] = ans

        return dp[n % 3]
```

</details>
