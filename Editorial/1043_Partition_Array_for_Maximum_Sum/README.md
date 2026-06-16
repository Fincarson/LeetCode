# 1043. Partition Array for Maximum Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/partition-array-for-maximum-sum/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1043 - Partition Array for Maximum Sum](https://leetcode.com/problems/partition-array-for-maximum-sum/)

## Problem

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

### Example 1

```text
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
```

### Example 2

```text
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
```

### Example 3

```text
Input: arr = [1], k = 1
Output: 1
```

## Constraints

- 1 <= arr.length <= 500
- 0 <= arr[i] <= 109
- 1 <= k <= arr.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subsequence of Size K With the Largest Even Sum](https://leetcode.com/problems/subsequence-of-size-k-with-the-largest-even-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Partition String Into Minimum Beautiful Substrings](https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Substring Partition of Equal Character Frequency](https://leetcode.com/problems/minimum-substring-partition-of-equal-character-frequency/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1043. Partition Array for Maximum Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java |
| Bottom-Up Dynamic Programming | C++, Java |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSum(vector<int>& arr, int k, int dp[], int start) {
        int N = arr.size();
        
        if (start >= N) {
            return 0;
        }
        
        // Return the already calculated answer.
        if (dp[start] != -1) {
            return dp[start];
        }
        
        int currMax = 0, ans = 0;
        int end = min(N, start + k);
        for (int i = start; i < end; i++) {
            currMax = max(currMax, arr[i]);
            // Store the maximum of all options for the current subarray.
            ans = max(ans, currMax * (i - start + 1) + maxSum(arr, k, dp, i + 1));
        }

        // Store the answer to be reused.
        return dp[start] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int dp[arr.size()];
        memset(dp, -1, sizeof(dp));
        
        return maxSum(arr, k, dp, 0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int maxSum(int[] arr, int k, int[] dp, int start) {
        int N = arr.length;

        if (start >= N) {
            return 0;
        }

        // Return the already calculated answer.
        if (dp[start] != -1) {
            return dp[start];
        }

        int currMax = 0, ans = 0;
        int end = Math.min(N, start + k);
        for (int i = start; i < end; i++) {
            currMax = Math.max(currMax, arr[i]);
            // Store the maximum of all options for the current subarray.
            ans = Math.max(ans, currMax * (i - start + 1) + maxSum(arr, k, dp, i + 1));
        }

        // Store the answer to be reused.
        return dp[start] = ans;
    }

    public int maxSumAfterPartitioning(int[] arr, int k) {
        int[] dp = new int[arr.length];
        Arrays.fill(dp, -1);

        return maxSum(arr, k, dp, 0);
    }
}
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
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();

        int dp[N + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int start = N - 1; start >= 0; start--) {
            int currMax = 0;
            int end = min(N, start + k);

            for (int i = start; i < end; i++) {
                currMax = max(currMax, arr[i]);
                // Store the maximum of all options for the current subarray.
                dp[start] = max(dp[start], dp[i + 1] + currMax * (i - start + 1));
            }
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
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int N = arr.length;

        int[] dp = new int[N + 1];
        Arrays.fill(dp, 0);

        for (int start = N - 1; start >= 0; start--) {
            int currMax = 0;
            int end = Math.min(N, start + k);

            for (int i = start; i < end; i++) {
                currMax = Math.max(currMax, arr[i]);
                // Store the maximum of all options for the current subarray.
                dp[start] = Math.max(dp[start], dp[i + 1] + currMax * (i - start + 1));
            }
        }
        return dp[0];
    }
}
```

</details>
