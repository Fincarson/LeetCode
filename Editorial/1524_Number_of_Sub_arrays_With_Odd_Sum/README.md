# 1524. Number of Sub-arrays With Odd Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/)  
`Array` `Math` `Dynamic Programming` `Prefix Sum`

**Problem Link:** [LeetCode 1524 - Number of Sub-arrays With Odd Sum](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/)

## Problem

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

### Example 1

```text
Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
```

### Example 2

```text
Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
```

### Example 3

```text
Input: arr = [1,2,3,4,5,6,7]
Output: 16
```

## Constraints

- 1 <= arr.length <= 105
- 1 <= arr[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subsequence of Size K With the Largest Even Sum](https://leetcode.com/problems/subsequence-of-size-k-with-the-largest-even-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1524. Number of Sub-arrays With Odd Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (TLE) | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |
| Prefix Sum with Odd-Even Counting | C++, Java, Python3 |

## Approach 1: Brute Force (TLE)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int count = 0;

        // Generate all possible subarrays
        for (int startIndex = 0; startIndex < n; startIndex++) {
            int currentSum = 0;
            // Iterate through each subarray starting at startIndex
            for (int endIndex = startIndex; endIndex < n; endIndex++) {
                currentSum += arr[endIndex];
                // Check if the sum is odd
                if (currentSum % 2 != 0) {
                    count++;
                }
            }
        }

        return count % MOD;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numOfSubarrays(int[] arr) {
        final int MOD = (int) (1e9 + 7);
        int n = arr.length;
        int count = 0;

        // Generate all possible subarrays
        for (int startIndex = 0; startIndex < n; startIndex++) {
            int currentSum = 0;
            // Iterate through each subarray starting at startIndex
            for (int endIndex = startIndex; endIndex < n; endIndex++) {
                currentSum += arr[endIndex];
                // Check if the sum is odd
                if (currentSum % 2 != 0) {
                    count++;
                }
            }
        }

        return count % MOD;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 1e9 + 7
        n = len(arr)
        count = 0

        # Generate all possible subarrays
        for start_index in range(n):
            current_sum = 0
            # Iterate through each subarray starting at start_index
            for end_index in range(start_index, n):
                current_sum += arr[end_index]
                # Check if the sum is odd
                if current_sum % 2 != 0:
                    count += 1

        return int(count % MOD)
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        
        // dp to track counts for even and odd sum subarrays
        vector<vector<int>> dp(2, vector<int>(2, 0));
        
        // Stores the final count of subarrays with an odd sum
        int count = dp[1][0]; 
        for (int i = 0; i < n; i++) {
            // Alternates between 0 and 1 for even/odd index tracking
            unsigned char idx = i & 1; 
            // Determines if the current element is odd (1) or even (0)
            unsigned char parity = arr[i] & 1; 
            
            // If the current element is odd, it contributes to odd subarrays
            // If the current element is even, it contributes to even subarrays
            dp[parity][idx] = (1 + dp[0][!idx]) % MOD;
            dp[!parity][idx] = dp[1][!idx] % MOD;
            
            // Accumulate the count of odd subarrays
            count = (count + dp[1][idx]) % MOD;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numOfSubarrays(int[] arr) {
        final int MOD = 1_000_000_007;
        int n = arr.length;
        
        // dp to track counts for even and odd sum subarrays
        int[][] dp = new int[2][2];
        
        // Stores the final count of subarrays with an odd sum
        int count = dp[1][0];
        
        for (int i = 0; i < n; i++) {
            // Alternates between 0 and 1 for even/odd index tracking
            int idx = i & 1;
            // Determines if the current element is odd (1) or even (0)
            int parity = arr[i] & 1;
            
            // If the current element is odd, it contributes to odd subarrays
            // If the current element is even, it contributes to even subarrays
            dp[parity][idx] = (1 + dp[0][1 - idx]) % MOD;
            dp[1 - parity][idx] = dp[1][1 - idx] % MOD;
            
            // Accumulate the count of odd subarrays
            count = (count + dp[1][idx]) % MOD;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(arr)

        # dp to track counts for even and odd sum subarrays
        dp = [[0, 0], [0, 0]]

        # Stores the final count of subarrays with an odd sum
        count = dp[1][0]

        for i in range(n):
            # Alternates between 0 and 1 for even/odd index tracking
            idx = i & 1
            # Determines if the current element is odd (1) or even (0)
            parity = arr[i] & 1
            
            # If the current element is odd, it contributes to odd subarrays
            # If the current element is even, it contributes to even subarrays
            dp[parity][idx] = (1 + dp[0][1 - idx]) % MOD
            dp[1 - parity][idx] = dp[1][1 - idx] % MOD
            
            # Accumulate the count of odd subarrays
            count = (count + dp[1][idx]) % MOD

        return count
```

</details>

<br>

## Approach 3: Prefix Sum with Odd-Even Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int count = 0, prefixSum = 0;
        // evenCount starts as 1 since the initial sum (0) is even
        int oddCount = 0, evenCount = 1;

        for (int num : arr) {
            prefixSum += num;
            // If current prefix sum is even, add the number of odd subarrays
            if (prefixSum % 2 == 0) {
                count += oddCount;
                evenCount++;
            } else {
                // If current prefix sum is odd, add the number of even
                // subarrays
                count += evenCount;
                oddCount++;
            }

            count %= MOD;  // To handle large results
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numOfSubarrays(int[] arr) {
        final int MOD = 1_000_000_007;
        int count = 0, prefixSum = 0;
        // evenCount starts as one since the initial sum (0) is even
        int oddCount = 0, evenCount = 1;

        for (int num : arr) {
            prefixSum += num;
            // If current prefix sum is even, add the number of odd subarrays
            if (prefixSum % 2 == 0) {
                count += oddCount;
                evenCount++;
            } else {
                // If current prefix sum is odd, add the number of even
                // subarrays
                count += evenCount;
                oddCount++;
            }

            count %= MOD; // To handle large results
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 10**9 + 7
        count = prefix_sum = 0
        # even_count starts as 1 since the initial sum (0) is even
        odd_count = 0
        even_count = 1

        for num in arr:
            prefix_sum += num
            # If current prefix sum is even, add the number of odd subarrays
            if prefix_sum % 2 == 0:
                count += odd_count
                even_count += 1
            else:
                # If current prefix sum is odd, add the number of even
                # subarrays
                count += even_count
                odd_count += 1

            count %= MOD  # To handle large results

        return count
```

</details>
