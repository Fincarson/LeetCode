# 1458. Max Dot Product of Two Subsequences

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/max-dot-product-of-two-subsequences/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1458 - Max Dot Product of Two Subsequences](https://leetcode.com/problems/max-dot-product-of-two-subsequences/)

## Problem

Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of an array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

### Example 1

```text
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
```

### Example 2

```text
Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.
```

### Example 3

```text
Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.
```

## Constraints

- 1 <= nums1.length, nums2.length <= 500
- -1000 <= nums1[i], nums2[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1458. Max Dot Product of Two Subsequences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Space Optimized Dynamic Programming | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> memo;
    
    int dp(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i == nums1.size() || j == nums2.size()) {
            return 0;
        }
        
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        
        int use = nums1[i] * nums2[j] + dp(i + 1, j + 1, nums1, nums2);
        memo[i][j] = max(use, max(dp(i + 1, j, nums1, nums2), dp(i, j + 1, nums1, nums2)));
        return memo[i][j];
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for (int num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        } 

        memo = vector(nums1.size(), vector(nums2.size(), 0));
        return dp(0, 0, nums1, nums2);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][] memo;
    
    public int dp(int i, int j, int[] nums1, int[] nums2) {
        if (i == nums1.length || j == nums2.length) {
            return 0;
        }
        
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        
        int use = nums1[i] * nums2[j] + dp(i + 1, j + 1, nums1, nums2);
        memo[i][j] = Math.max(use, Math.max(dp(i + 1, j, nums1, nums2), dp(i, j + 1, nums1, nums2)));
        return memo[i][j];
    }
    
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int firstMax = Integer.MIN_VALUE;
        int secondMax = Integer.MIN_VALUE;
        int firstMin = Integer.MAX_VALUE;
        int secondMin = Integer.MAX_VALUE;
        
        for (int num: nums1) {
            firstMax = Math.max(firstMax, num);
            firstMin = Math.min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = Math.max(secondMax, num);
            secondMin = Math.min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        }
        
        memo = new int[nums1.length][nums2.length];
        return dp(0, 0, nums1, nums2);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        @cache
        def dp(i, j):
            if i == len(nums1) or j == len(nums2):
                return 0
            
            use = nums1[i] * nums2[j] + dp(i + 1, j + 1)
            return max(use, dp(i + 1, j), dp(i, j + 1))
            
        if max(nums1) < 0 and min(nums2) > 0:
            return max(nums1) * min(nums2)
        
        if min(nums1) > 0 and max(nums2) < 0:
            return min(nums1) * max(nums2)
        
        return dp(0, 0)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for (int num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        } 

        vector<vector<int>> dp = vector(nums1.size() + 1, vector(nums2.size() + 1, 0));
        for (int i = nums1.size() - 1; i >= 0; i--) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                int use = nums1[i] * nums2[j] + dp[i + 1][j + 1];
                dp[i][j] = max(use, max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
        
        return dp[0][0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {    
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int firstMax = Integer.MIN_VALUE;
        int secondMax = Integer.MIN_VALUE;
        int firstMin = Integer.MAX_VALUE;
        int secondMin = Integer.MAX_VALUE;
        
        for (int num: nums1) {
            firstMax = Math.max(firstMax, num);
            firstMin = Math.min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = Math.max(secondMax, num);
            secondMin = Math.min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        }
        
        int[][] dp = new int[nums1.length + 1][nums2.length + 1];
        for (int i = nums1.length - 1; i >= 0; i--) {
            for (int j = nums2.length - 1; j >= 0; j--) {
                int use = nums1[i] * nums2[j] + dp[i + 1][j + 1];
                dp[i][j] = Math.max(use, Math.max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
        
        return dp[0][0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        if max(nums1) < 0 and min(nums2) > 0:
            return max(nums1) * min(nums2)
        
        if min(nums1) > 0 and max(nums2) < 0:
            return min(nums1) * max(nums2)
        
        dp = [[0] * (len(nums2) + 1) for _ in range(len(nums1) + 1)]
        for i in range(len(nums1) - 1, -1, -1):
            for j in range(len(nums2) - 1, -1, -1):
                use = nums1[i] * nums2[j] + dp[i + 1][j + 1]
                dp[i][j] = max(use, dp[i + 1][j], dp[i][j + 1])
        
        return dp[0][0]
```

</details>

<br>

## Approach 3: Space Optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for (int num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        } 

        int m = nums2.size() + 1;
        vector<int> dp(m, 0);
        vector<int> prevDp(m, 0);
        
        for (int i = nums1.size() - 1; i >= 0; i--) {
            dp = vector(m, 0);
            for (int j = nums2.size() - 1; j >= 0; j--) {
                int use = nums1[i] * nums2[j] + prevDp[j + 1];
                dp[j] = max(use, max(prevDp[j], dp[j + 1]));
            }
            
            prevDp = dp;
        }
        
        return dp[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {    
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int firstMax = Integer.MIN_VALUE;
        int secondMax = Integer.MIN_VALUE;
        int firstMin = Integer.MAX_VALUE;
        int secondMin = Integer.MAX_VALUE;
        
        for (int num: nums1) {
            firstMax = Math.max(firstMax, num);
            firstMin = Math.min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = Math.max(secondMax, num);
            secondMin = Math.min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        }
        
        int m = nums2.length + 1;
        int[] dp = new int[m];
        int[] prevDp = new int[m];
        
        for (int i = nums1.length - 1; i >= 0; i--) {
            dp = new int[m];
            for (int j = nums2.length - 1; j >= 0; j--) {
                int use = nums1[i] * nums2[j] + prevDp[j + 1];
                dp[j] = Math.max(use, Math.max(prevDp[j], dp[j + 1]));
            }
            
            prevDp = dp;
        }
        
        return dp[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        if max(nums1) < 0 and min(nums2) > 0:
            return max(nums1) * min(nums2)
        
        if min(nums1) > 0 and max(nums2) < 0:
            return min(nums1) * max(nums2)
        
        m = len(nums2) + 1
        prev_dp = [0] * m
        dp = [0] * m
        
        for i in range(len(nums1) - 1, -1, -1):
            dp = [0] * m
            for j in range(len(nums2) - 1, -1, -1):
                use = nums1[i] * nums2[j] + prev_dp[j + 1]
                dp[j] = max(use, prev_dp[j], dp[j + 1])
            
            prev_dp = dp
        
        return dp[0]
```

</details>
