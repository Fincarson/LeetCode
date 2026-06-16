# 873. Length of Longest Fibonacci Subsequence

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/)  
`Array` `Hash Table` `Dynamic Programming`

**Problem Link:** [LeetCode 873 - Length of Longest Fibonacci Subsequence](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/)

## Problem

A sequence x1, x2, ..., xn is Fibonacci-like if:

- n >= 3
- xi + xi+1 == xi+2 for all i + 2 <= n

Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

### Example 1

```text
Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
```

### Example 2

```text
Input: arr = [1,3,7,11,12,14,18]
Output: 3
Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
```

## Constraints

- 3 <= arr.length <= 1000
- 1 <= arr[i] < arr[i + 1] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Fibonacci Number](https://leetcode.com/problems/fibonacci-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 873. Length of Longest Fibonacci Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |
| Optimized Dynamic Programming | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // Store array elements in set for O(1) lookup
        unordered_set<int> numSet(arr.begin(), arr.end());

        int maxLen = 0;
        // Try all possible first two numbers of sequence
        for (int start = 0; start < n; ++start) {
            for (int next = start + 1; next < n; ++next) {
                // Start with first two numbers
                int prev = arr[next];
                int curr = arr[start] + arr[next];
                int len = 2;

                // Keep finding next Fibonacci number
                while (numSet.find(curr) != numSet.end()) {
                    // Update values for next iteration
                    int temp = curr;
                    curr += prev;
                    prev = temp;
                    maxLen = max(maxLen, ++len);
                }
            }
        }

        return maxLen;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        // Store array elements in set for O(1) lookup
        Set<Integer> numSet = new HashSet<>();
        for (int num : arr) {
            numSet.add(num);
        }

        int maxLen = 0;
        // Try all possible first two numbers of sequence
        for (int start = 0; start < n; ++start) {
            for (int next = start + 1; next < n; ++next) {
                // Start with first two numbers
                int prev = arr[next];
                int curr = arr[start] + arr[next];
                int len = 2;

                // Keep finding next Fibonacci number
                while (numSet.contains(curr)) {
                    // Update values for next iteration
                    int temp = curr;
                    curr += prev;
                    prev = temp;
                    maxLen = Math.max(maxLen, ++len);
                }
            }
        }

        return maxLen;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lenLongestFibSubseq(self, arr: list[int]) -> int:
        # Store array elements in set for O(1) lookup
        num_set = set(arr)
        max_len = 0
        n = len(arr)

        # Try all possible first two numbers of sequence
        for start in range(n):
            for next in range(start + 1, n):
                # Start with first two numbers
                prev = arr[next]
                curr = arr[start] + arr[next]
                curr_len = 2

                # Keep finding next Fibonacci number
                while curr in num_set:
                    prev, curr = curr, curr + prev
                    curr_len += 1
                    max_len = max(max_len, curr_len)

        return max_len
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
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLen = 0;
        // dp[prev][curr] stores length of Fibonacci sequence ending at indexes
        // prev,curr
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        // Map each value to its index for O(1) lookup
        unordered_map<int, int> valToIdx;

        // Fill dp array
        for (int curr = 0; curr < arr.size(); curr++) {
            valToIdx[arr[curr]] = curr;

            for (int prev = 0; prev < curr; prev++) {
                // Find if there exists a previous number to form Fibonacci
                // sequence
                int diff = arr[curr] - arr[prev];
                int prevIdx = (valToIdx.find(diff) != valToIdx.end())
                                  ? valToIdx[diff]
                                  : -1;

                // Update dp if valid Fibonacci sequence possible
                // diff < arr[prev] ensures strictly increasing sequence
                if (diff < arr[prev] && prevIdx >= 0) {
                    dp[prev][curr] = dp[prevIdx][prev] + 1;
                } else {
                    dp[prev][curr] = 2;
                }

                maxLen = max(maxLen, dp[prev][curr]);
            }
        }

        // Return 0 if no sequence of length > 2 found
        return maxLen > 2 ? maxLen : 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int lenLongestFibSubseq(int[] arr) {
        int maxLen = 0;
        // dp[prev][curr] stores length of Fibonacci sequence ending at indexes prev,curr
        int[][] dp = new int[arr.length][arr.length];

        // Map each value to its index for O(1) lookup
        Map<Integer, Integer> valToIdx = new HashMap<>();

        // Fill dp array
        for (int curr = 0; curr < arr.length; curr++) {
            valToIdx.put(arr[curr], curr);

            for (int prev = 0; prev < curr; prev++) {
                // Find if there exists a previous number to form Fibonacci sequence
                int diff = arr[curr] - arr[prev];
                int prevIdx = valToIdx.getOrDefault(diff, -1);

                // Update dp if valid Fibonacci sequence possible
                // diff < arr[prev] ensures strictly increasing sequence
                if (diff < arr[prev] && prevIdx >= 0) {
                    dp[prev][curr] = dp[prevIdx][prev] + 1;
                } else {
                    dp[prev][curr] = 2;
                }

                maxLen = Math.max(maxLen, dp[prev][curr]);
            }
        }

        // Return 0 if no sequence of length > 2 found
        return maxLen > 2 ? maxLen : 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lenLongestFibSubseq(self, arr: list[int]) -> int:
        n = len(arr)
        max_len = 0
        # dp[prev][curr] stores length of Fibonacci sequence ending at indexes prev,curr
        dp = [[0] * n for _ in range(n)]

        # Map each value to its index for O(1) lookup
        val_to_idx = {num: idx for idx, num in enumerate(arr)}

        # Fill dp array
        for curr in range(n):
            for prev in range(curr):
                # Find if there exists a previous number to form Fibonacci sequence
                diff = arr[curr] - arr[prev]
                prev_idx = val_to_idx.get(diff, -1)

                # Update dp if valid Fibonacci sequence possible
                # diff < arr[prev] ensures strictly increasing sequence
                dp[prev][curr] = (
                    dp[prev_idx][prev] + 1
                    if diff < arr[prev] and prev_idx >= 0
                    else 2
                )
                max_len = max(max_len, dp[prev][curr])

        # Return 0 if no sequence of length > 2 found
        return max_len if max_len > 2 else 0
```

</details>

<br>

## Approach 3: Optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // dp[prev][curr] stores length of Fibonacci sequence ending at indexes
        // prev,curr
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 0;

        // Find all possible pairs that sum to arr[curr]
        for (int curr = 2; curr < n; curr++) {
            // Use two pointers to find pairs that sum to arr[curr]
            int start = 0;
            int end = curr - 1;

            while (start < end) {
                int pairSum = arr[start] + arr[end];

                if (pairSum > arr[curr]) {
                    end--;
                } else if (pairSum < arr[curr]) {
                    start++;
                } else {
                    // Found a valid pair, update dp
                    dp[end][curr] = dp[start][end] + 1;
                    maxLen = max(dp[end][curr], maxLen);
                    end--;
                    start++;
                }
            }
        }

        // Add 2 to include first two numbers, or return 0 if no sequence found
        return maxLen == 0 ? 0 : maxLen + 2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        // dp[prev][curr] stores length of Fibonacci sequence ending at indexes prev,curr
        int[][] dp = new int[n][n];
        int maxLen = 0;

        // Find all possible pairs that sum to arr[curr]
        for (int curr = 2; curr < n; curr++) {
            // Use two pointers to find pairs that sum to arr[curr]
            int start = 0;
            int end = curr - 1;

            while (start < end) {
                int pairSum = arr[start] + arr[end];

                if (pairSum > arr[curr]) {
                    end--;
                } else if (pairSum < arr[curr]) {
                    start++;
                } else {
                    // Found a valid pair, update dp
                    dp[end][curr] = dp[start][end] + 1;
                    maxLen = Math.max(dp[end][curr], maxLen);
                    end--;
                    start++;
                }
            }
        }

        // Add 2 to include first two numbers, or return 0 if no sequence found
        return maxLen == 0 ? 0 : maxLen + 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lenLongestFibSubseq(self, arr: list[int]) -> int:
        n = len(arr)
        # dp[prev][curr] stores length of Fibonacci sequence ending at indexes prev,curr
        dp = [[0] * n for _ in range(n)]
        max_len = 0

        # Find all possible pairs that sum to arr[curr]
        for curr in range(2, n):
            # Use two pointers to find pairs that sum to arr[curr]
            start = 0
            end = curr - 1

            while start < end:
                pair_sum = arr[start] + arr[end]

                if pair_sum > arr[curr]:
                    end -= 1
                elif pair_sum < arr[curr]:
                    start += 1
                else:
                    # Found a valid pair, update dp
                    dp[end][curr] = dp[start][end] + 1
                    max_len = max(dp[end][curr], max_len)
                    end -= 1
                    start += 1

        # Add 2 to include first two numbers, or return 0 if no sequence found
        return max_len + 2 if max_len else 0
```

</details>
