# 416. Partition Equal Subset Sum

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/partition-equal-subset-sum/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 416 - Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)

## Problem

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

### Example 1

```text
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

### Example 2

```text
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```

## Constraints

- 1 <= nums.length <= 200
- 1 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimize the Difference Between Target and Chosen Elements](https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Ways to Partition an Array](https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find Subarrays With Equal Sum](https://leetcode.com/problems/find-subarrays-with-equal-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Number of Great Partitions](https://leetcode.com/problems/number-of-great-partitions/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Split With Minimum Sum](https://leetcode.com/problems/split-with-minimum-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 416. Partition Equal Subset Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Top Down Dynamic Programming - Memoization | C++, Java, Python3 |
| Bottom Up Dynamic Programming | C++, Java, Python3 |
| Optimised Dynamic Programming - Using 1D Array | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd,it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.size();
        return dfs(nums, n - 1, subSetSum);
    }

    bool dfs(vector<int> &nums, int n, int subSetSum) {
        // Base Cases
        if (subSetSum == 0)
            return true;
        if (n == 0 || subSetSum < 0)
            return false;
        bool result = dfs(nums, n - 1, subSetSum - nums[n - 1]) || dfs(nums, n - 1, subSetSum);
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canPartition(int[] nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd,it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.length;
        return dfs(nums, n - 1, subSetSum);
    }

    public boolean dfs(int[] nums, int n, int subSetSum) {
        // Base Cases
        if (subSetSum == 0)
            return true;
        if (n == 0 || subSetSum < 0)
            return false;
        return dfs(nums, n - 1, subSetSum - nums[n - 1]) || dfs(nums, n - 1, subSetSum);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        def dfs(nums: List[int], n: int, subset_sum: int) -> bool:
            # Base cases
            if subset_sum == 0:
                return True
            if n == 0 or subset_sum < 0:
                return False
            result = (dfs(nums, n - 1, subset_sum - nums[n - 1])
                    or dfs(nums, n - 1, subset_sum))
            return result

        # find sum of array elements
        total_sum = sum(nums)

        # if total_sum is odd, it cannot be partitioned into equal sum subsets
        if total_sum % 2 != 0:
            return False

        subset_sum = total_sum // 2
        n = len(nums)
        return dfs(nums, n - 1, subset_sum)
```

</details>

<br>

## Approach 2: Top Down Dynamic Programming - Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.size();
        vector<vector<optional<bool>>> memo(n + 1, vector<optional<bool>>(subSetSum + 1, nullopt));
        return dfs(nums, n - 1, subSetSum, memo);
    }

    bool dfs(vector<int> &nums, int n, int subSetSum, vector<vector<optional<bool>>> &memo) {
        // Base Cases
        if (subSetSum == 0)
            return true;
        if (n == 0 || subSetSum < 0)
            return false;
        // check if subSetSum for given n is already computed and stored in memo
        if (memo[n][subSetSum] != nullopt) {
            return (memo[n][subSetSum] == true);
        }
        bool result = dfs(nums, n - 1, subSetSum - nums[n - 1], memo) ||
                dfs(nums, n - 1, subSetSum, memo);
        memo[n][subSetSum] = result;
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canPartition(int[] nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.length;
        Boolean[][] memo = new Boolean[n + 1][subSetSum + 1];
        return dfs(nums, n - 1, subSetSum, memo);
    }

    public boolean dfs(int[] nums, int n, int subSetSum, Boolean[][] memo) {
        // Base Cases
        if (subSetSum == 0)
            return true;
        if (n == 0 || subSetSum < 0)
            return false;
        // check if subSetSum for given n is already computed and stored in memo
        if (memo[n][subSetSum] != null)
            return memo[n][subSetSum];
        boolean result = dfs(nums, n - 1, subSetSum - nums[n - 1], memo) ||
                dfs(nums, n - 1, subSetSum, memo);
        // store the result in memo
        memo[n][subSetSum] = result;
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        @lru_cache(maxsize=None)
        def dfs(nums: Tuple[int], n: int, subset_sum: int) -> bool:
            # Base cases
            if subset_sum == 0:
                return True
            if n == 0 or subset_sum < 0:
                return False
            result = (dfs(nums, n - 1, subset_sum - nums[n - 1])
                    or dfs(nums, n - 1, subset_sum))
            return result

        # find sum of array elements
        total_sum = sum(nums)

        # if total_sum is odd, it cannot be partitioned into equal sum subsets
        if total_sum % 2 != 0:
            return False

        subset_sum = total_sum // 2
        n = len(nums)
        return dfs(tuple(nums), n - 1, subset_sum)
```

</details>

<br>

## Approach 3: Bottom Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.size();
        bool dp[n + 1][subSetSum + 1];
        memset(dp, 0, (n + 1) * (subSetSum + 1) * sizeof(bool));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            int curr = nums[i - 1];
            for (int j = 0; j <= subSetSum; j++) {
                if (j < curr)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || (dp[i - 1][j - curr]);
            }
        }
        return dp[n][subSetSum];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canPartition(int[] nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.length;
        boolean dp[][] = new boolean[n + 1][subSetSum + 1];
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            int curr = nums[i - 1];
            for (int j = 0; j <= subSetSum; j++) {
                if (j < curr)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || (dp[i - 1][j - curr]);
            }
        }
        return dp[n][subSetSum];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # find sum of array elements
        total_sum = sum(nums)

        # if total_sum is odd, it cannot be partitioned into equal sum subsets
        if total_sum % 2 != 0:
            return False
        subset_sum = total_sum // 2
        n = len(nums)

        # construct a dp table of size (n+1) x (subset_sum + 1)
        dp = [[False] * (subset_sum + 1) for _ in range(n + 1)]
        dp[0][0] = True
        for i in range(1, n + 1):
            curr = nums[i - 1]
            for j in range(subset_sum + 1):
                if j < curr:
                    dp[i][j] = dp[i - 1][j]
                else:
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - curr]
        return dp[n][subset_sum]
```

</details>

<br>

## Approach 4: Optimised Dynamic Programming - Using 1D Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.size();
        vector<bool> dp(subSetSum + 1, false);
        dp[0] = true;
        for (int curr : nums) {
            for (int j = subSetSum; j >= curr; j--) {
                dp[j] = dp[j] || dp[j - curr];
            }
        }
        return dp[subSetSum];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canPartition(int[] nums) {
        if (nums.length == 0)
            return false;
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        boolean dp[] = new boolean[subSetSum + 1];
        dp[0] = true;
        for (int curr : nums) {
            for (int j = subSetSum; j >= curr; j--) {
                dp[j] |= dp[j - curr];
            }
        }
        return dp[subSetSum];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # find sum of array elements
        total_sum = sum(nums)

        # if total_sum is odd, it cannot be partitioned into equal sum subsets
        if total_sum % 2 != 0:
            return False
        subset_sum = total_sum // 2

        # construct a dp table of size (subset_sum + 1)
        dp = [False] * (subset_sum + 1)
        dp[0] = True
        for curr in nums:
            for j in range(subset_sum, curr - 1, -1):
                dp[j] = dp[j] or dp[j - curr]

        return dp[subset_sum]
```

</details>
