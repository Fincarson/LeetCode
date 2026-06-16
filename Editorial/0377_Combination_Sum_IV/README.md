# 377. Combination Sum IV

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/combination-sum-iv/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 377 - Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/)

## Problem

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

### Example 1

```text
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
```

### Example 2

```text
Input: nums = [9], target = 3
Output: 0
```

## Constraints

- 1 <= nums.length <= 200
- 1 <= nums[i] <= 1000
- All the elements of nums are unique.
- 1 <= target <= 1000

Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Combination Sum](https://leetcode.com/problems/combination-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Ways to Express an Integer as Sum of Powers](https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 377. Combination Sum IV

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | Java, Python3 |
| Bottom-Up Dynamic Programming | Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private HashMap<Integer, Integer> memo;

    public int combinationSum4(int[] nums, int target) {
        // minor optimization
        // Arrays.sort(nums);
        memo = new HashMap<>();
        return combs(nums, target);
    }

    private int combs(int[] nums, int remain) {
        if (remain == 0)
            return 1;
        if (memo.containsKey(remain))
            return memo.get(remain);

        int result = 0;
        for (int num : nums) {
            if (remain - num >= 0)
                result += combs(nums, remain - num);
            // minor optimizaton, early stopping
            // else
            //     break;
        }
        memo.put(remain, result);
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # potential optimization
        # nums.sort()

        @functools.lru_cache(maxsize = None)
        def combs(remain):
            if remain == 0:
                return 1

            result = 0
            for num in nums:
                if remain - num >= 0:
                    result += combs(remain - num)
                # potential optimization
                # else:
                #     break

            return result

        return combs(target)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int combinationSum4(int[] nums, int target) {
        // minor optimization
        // Arrays.sort(nums);
        int[] dp = new int[target + 1];
        dp[0] = 1;

        for (int combSum = 1; combSum < target + 1; ++combSum) {
            for (int num : nums) {
                if (combSum - num >= 0)
                    dp[combSum] += dp[combSum - num];
                // minor optimizaton, early stopping
                // else
                //     break;
            }
        }
        return dp[target];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # minor optimization
        # nums.sort()
        dp = [0 for i in range(target+1)]
        dp[0] = 1

        for comb_sum in range(target+1):

            for num in nums:
                if comb_sum - num >= 0:
                    dp[comb_sum] += dp[comb_sum-num]
                # minor optimization, early stopping.
                # else:
                #    break
        return dp[target]
```

</details>
