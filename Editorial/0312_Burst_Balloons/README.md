# 312. Burst Balloons

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/burst-balloons/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 312 - Burst Balloons](https://leetcode.com/problems/burst-balloons/)

## Problem

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

### Example 1

```text
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
```

### Example 2

```text
Input: nums = [1,5]
Output: 10
```

## Constraints

- n == nums.length
- 1 <= n <= 300
- 0 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost to Merge Stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 312. Burst Balloons

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming (Naive) | SQL |
| Dynamic Programming (Top-Down) | C++, Java, Python3 |
| Dynamic Programming (Bottom-Up) | C++, Java, Python3 |

## Approach 1: Dynamic Programming (Naive)

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
function dp(dp_state, memo_dict) {
    // check if we have seen this dp_state
    if dp_state in memo_dict
        return memo_dict[dp_state]

    // base case (a case that we know the answer for already) such as dp_state is empty
    if dp_state is the base cases
        return things like 0 or null
    
    calculate dp(dp_state) from dp(other_state)
    
    save dp_state and the result into memo_dict
}
function answerToProblem(input) {
    return dp(start_state, empty_memo_dict)
}
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
// memo_dict is ignored for readability
// return maximum coins obtainable by optimally bursting all balloons in `nums`.
function dp(nums) {
    // base case
    if nums is empty
        return 0
    calculate dp(nums) from dp(other_state)
}
```

</details>

<br>

## Approach 2: Dynamic Programming (Top-Down)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // add 1 before and after nums
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        // cache the results of dp
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), 0));
        // we can not burst the first one and the last one
        // since they are both fake balloons added by ourselves
        return dp(memo, nums, 1, nums.size() - 2);
    }
	
    int dp(vector<vector<int>>& memo, vector<int>& nums, int left, int right) {
        // return maximum if we burst all nums[left]...nums[right], inclusive
        if (right - left < 0) {
            return 0;
        }

        // we've already seen this, return from cache
        if (memo[left][right] > 0) {
            return memo[left][right];
        }

        // find the last burst one in nums[left]...nums[right]
        int result = 0;
        for (int i = left; i <= right; i++) {
            // nums[i] is the last burst one
            int gain = nums[left - 1] * nums[i] * nums[right + 1];
            // nums[i] is fixed, recursively call left side and right side
            int remaining = dp(memo, nums, left, i - 1) + dp(memo, nums, i + 1, right);
            result = max(result, remaining + gain);
        }
        // add to the cache
        memo[left][right] = result;
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxCoins(int[] nums) {
        // add 1 before and after nums
        int n = nums.length + 2;
        int[] newNums = new int[n];
        System.arraycopy(nums, 0, newNums, 1, n - 2);
        newNums[0] = 1;
        newNums[n - 1] = 1;

        // cache the results of dp
        int[][] memo = new int[n][n];

        // we can not burst the first one and the last one
        // since they are both fake balloons added by ourselves
        return dp(memo, newNums, 1, n - 2);
    }

    public int dp(int[][] memo, int[] nums, int left, int right) {
        // return maximum if we burst all nums[left]...nums[right], inclusive
        if (right - left < 0) {
            return 0;
        }

        // we've already seen this, return from cache
        if (memo[left][right] > 0) {
            return memo[left][right];
        }

        // find the last burst one in nums[left]...nums[right]
        int result = 0;
        for (int i = left; i <= right; i++) {
            // nums[i] is the last burst one
            int gain = nums[left - 1] * nums[i] * nums[right + 1];
            // nums[i] is fixed, recursively call left side and right side
            int remaining = dp(memo, nums, left, i - 1) + dp(memo, nums, i + 1, right);
            result = Math.max(result, remaining + gain);
        }
        // add to the cache
        memo[left][right] = result;
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        # special case
        if len(nums) > 1 and len(set(nums)) == 1:
            return (nums[0] ** 3) * (len(nums) - 2) + nums[0] ** 2 + nums[0]

        # handle edge case
        nums = [1] + nums + [1]

        @lru_cache(None)  # memoization
        def dp(left, right):
            # maximum if we burst all nums[left]...nums[right], inclusive
            if right - left < 0:
                return 0
            result = 0
            # find the last burst one in nums[left]...nums[right]
            for i in range(left, right + 1):
                # nums[i] is the last burst one
                gain = nums[left - 1] * nums[i] * nums[right + 1]
                # nums[i] is fixed, recursively call left side and right side
                remaining = dp(left, i - 1) + dp(i + 1, right)
                # update the result
                result = max(result, remaining + gain)
            return result

        # we can not burst the first one and the last one
        # since they are both fake balloons added by ourselves
        return dp(1, len(nums) - 2)
```

</details>

<br>

## Approach 3: Dynamic Programming (Bottom-Up)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // add 1 before and after nums
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        // dp[i][j] represents
        // maximum if we burst all nums[left]...nums[right], inclusive
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        // do not include the first one and the last one
        // since they are both fake balloons added by ourselves and we can not burst them
        for (int left = nums.size() - 2; left >= 1; left--) {
            for (int right = left; right <= nums.size() - 2; right++) {
                // find the last burst one in nums[left]...nums[right]
                for (int i = left; i <= right; i++) {
                    // nums[i] is the last burst one
                    int gain = nums[left - 1] * nums[i] * nums[right + 1];
                    // recursively call left side and right side
                    int remaining = dp[left][i - 1] + dp[i + 1][right];
                    // update
                    dp[left][right] = max(remaining + gain, dp[left][right]);
                }
            }
        }
        // burst newNums[1]...newNums[n-2], excluding the first one and the last one
        return dp[1][nums.size() - 2];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxCoins(int[] nums) {
        // add 1 before and after nums
        int n = nums.length + 2;
        int[] newNums = new int[n];
        System.arraycopy(nums, 0, newNums, 1, n - 2);
        newNums[0] = 1;
        newNums[n - 1] = 1;
        // dp[i][j] represents
        // maximum if we burst all nums[left]...nums[right], inclusive
        int[][] dp = new int[n][n];
        // do not include the first one and the last one
        // since they are both fake balloons added by ourselves and we can not burst
        // them
        for (int left = n - 2; left >= 1; left--) {
            for (int right = left; right <= n - 2; right++) {
                // find the last burst one in newNums[left]...newNums[right]
                for (int i = left; i <= right; i++) {
                    // newNums[i] is the last burst one
                    int gain = newNums[left - 1] * newNums[i] * newNums[right + 1];
                    // recursively call left side and right side
                    int remaining = dp[left][i - 1] + dp[i + 1][right];
                    // update
                    dp[left][right] = Math.max(remaining + gain, dp[left][right]);
                }
            }
        }
        // burst newNums[1]...newNums[n-2], excluding the first one and the last one
        return dp[1][n - 2];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        # special case
        if len(nums) > 1 and len(set(nums)) == 1:
            return (nums[0] ** 3) * (len(nums) - 2) + nums[0] ** 2 + nums[0]

        # handle edge case
        nums = [1] + nums + [1]
        n = len(nums)
        # dp[i][j] represents
        # maximum if we burst all nums[left]...nums[right], inclusive
        dp = [[0] * n for _ in range(n)]

        # do not include the first one and the last one
        # since they are both fake balloons added by ourselves and we can not
        # burst them
        for left in range(n - 2, 0, -1):
            for right in range(left, n - 1):
                # find the last burst one in nums[left]...nums[right]
                for i in range(left, right + 1):
                    # nums[i] is the last burst one
                    gain = nums[left - 1] * nums[i] * nums[right + 1]
                    # recursively call left side and right side
                    remaining = dp[left][i - 1] + dp[i + 1][right]
                    # update
                    dp[left][right] = max(remaining + gain, dp[left][right])
        # burst nums[1]...nums[n-2], excluding the first one and the last one
        return dp[1][n - 2]
```

</details>
