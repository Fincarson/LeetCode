# 1326. Minimum Number of Taps to Open to Water a Garden

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/)  
`Array` `Dynamic Programming` `Greedy`

**Problem Link:** [LeetCode 1326 - Minimum Number of Taps to Open to Water a Garden](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/)

## Problem

There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e., the length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

### Example 1

```text
Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]
```

### Example 2

```text
Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.
```

## Constraints

- 1 <= n <= 104
- ranges.length == n + 1
- 0 <= ranges[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1326. Minimum Number of Taps to Open to Water a Garden

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, Python3 |
| Greedy | C++, Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Define an infinite value
        const int INF = 1e9;
        // Create a vector to store the minimum number of taps needed for each position
        vector<int> dp(n + 1, INF);

        // Initialize the starting position of the garden
        dp[0] = 0;
        
        for (int i = 0; i <= n; i++) {
            // Calculate the leftmost position reachable by the current tap
            int tapStart = max(0, i - ranges[i]);
            // Calculate the rightmost position reachable by the current tap
            int tapEnd = min(n, i + ranges[i]);
            
            for (int j = tapStart; j <= tapEnd; j++) {
                // Update with the minimum number of taps
                dp[tapEnd] = min(dp[tapEnd], dp[j] + 1);
            }
        }
        
        // Check if the garden can be watered completely
        if (dp[n] == INF) {
            // Garden cannot be watered
            return -1;
        }
        
        // Return the minimum number of taps needed to water the entire garden
        return dp[n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minTaps(int n, int[] ranges) {
        // Define an infinite value
        final int INF = (int) 1e9;
        
        // Create an array to store the minimum number of taps needed for each position
        int[] dp = new int[n + 1];
        Arrays.fill(dp, INF);
        
        // Initialize the starting position of the garden
        dp[0] = 0;
        
        for (int i = 0; i <= n; i++) {
            // Calculate the leftmost position reachable by the current tap
            int tapStart = Math.max(0, i - ranges[i]);
            // Calculate the rightmost position reachable by the current tap
            int tapEnd = Math.min(n, i + ranges[i]);
            
            for (int j = tapStart; j <= tapEnd; j++) {
                // Update with the minimum number of taps
                dp[tapEnd] = Math.min(dp[tapEnd], dp[j] + 1);
            }
        }
        
        // Check if the garden can be watered completely
        if (dp[n] == INF) {
            // Garden cannot be watered
            return -1;
        }
        
        // Return the minimum number of taps needed to water the entire garden
        return dp[n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # Define an infinite value
        INF = int(1e9)
        
        # Create a list to store the minimum number of taps needed for each position
        dp = [INF] * (n + 1)
        
        # Initialize the starting position of the garden
        dp[0] = 0
        
        for i in range(n + 1):
            # Calculate the leftmost position reachable by the current tap
            tap_start = max(0, i - ranges[i])
            # Calculate the rightmost position reachable by the current tap
            tap_end = min(n, i + ranges[i])
            
            for j in range(tap_start, tap_end + 1):
                # Update with the minimum number of taps
                dp[tap_end] = min(dp[tap_end], dp[j] + 1)
        
        # Check if the garden can be watered completely
        if dp[n] == INF:
            # Garden cannot be watered
            return -1
        
        # Return the minimum number of taps needed to water the entire garden
        return dp[n]
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Create a vector to track the maximum reach for each position
        vector<int> maxReach(n + 1);

        // Calculate the maximum reach for each tap
        for (int i = 0; i < ranges.size(); i++) {
            // Calculate the leftmost position the tap can reach
            int start = max(0, i - ranges[i]);
            // Calculate the rightmost position the tap can reach
            int end = min(n, i + ranges[i]);

            // Update the maximum reach for the leftmost position
            maxReach[start] = max(maxReach[start], end);
        }
        
        // Number of taps used
        int taps = 0;
        // Current rightmost position reached
        int currEnd = 0;
        // Next rightmost position that can be reached
        int nextEnd = 0;

        // Iterate through the garden
        for (int i = 0; i <= n; i++) {
            // Current position cannot be reached
            if (i > nextEnd) {
                return -1;
            }

            // Increment taps when moving to a new tap
            if (i > currEnd) {
                taps++;
                // Move to the rightmost position that can be reached
                currEnd = nextEnd;
            }

            // Update the next rightmost position that can be reached
            nextEnd = max(nextEnd, maxReach[i]);
        }

        // Return the minimum number of taps used
        return taps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minTaps(int n, int[] ranges) {
        // Create an array to track the maximum reach for each position
        int[] maxReach = new int[n + 1];

        // Calculate the maximum reach for each tap
        for (int i = 0; i < ranges.length; i++) {
            // Calculate the leftmost position the tap can reach
            int start = Math.max(0, i - ranges[i]);
            // Calculate the rightmost position the tap can reach
            int end = Math.min(n, i + ranges[i]);

            // Update the maximum reach for the leftmost position
            maxReach[start] = Math.max(maxReach[start], end);
        }
        
        // Number of taps used
        int taps = 0;
        // Current rightmost position reached
        int currEnd = 0;
        // Next rightmost position that can be reached
        int nextEnd = 0;

        // Iterate through the garden
        for (int i = 0; i <= n; i++) {
            // Current position cannot be reached
            if (i > nextEnd) {
                return -1;
            }

            // Increment taps when moving to a new tap
            if (i > currEnd) {
                taps++;
                // Move to the rightmost position that can be reached
                currEnd = nextEnd;
            }

            // Update the next rightmost position that can be reached
            nextEnd = Math.max(nextEnd, maxReach[i]);
        }

        // Return the minimum number of taps used
        return taps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # Create a list to track the maximum reach for each position
        max_reach = [0] * (n + 1)

        # Calculate the maximum reach for each tap
        for i in range(len(ranges)):
            # Calculate the leftmost position the tap can reach
            start = max(0, i - ranges[i])
            # Calculate the rightmost position the tap can reach
            end = min(n, i + ranges[i])

            # Update the maximum reach for the leftmost position
            max_reach[start] = max(max_reach[start], end)
        
        # Number of taps used
        taps = 0
        # Current rightmost position reached
        curr_end = 0
        # Next rightmost position that can be reached
        next_end = 0

        # Iterate through the garden
        for i in range(n + 1):
            if i > next_end:
                # Current position cannot be reached
                return -1

            if i > curr_end:
                # Increment taps when moving to a new tap
                taps += 1
                # Move to the rightmost position that can be reached
                curr_end = next_end

            # Update the next rightmost position that can be reached
            next_end = max(next_end, max_reach[i])

        # Return the minimum number of taps used
        return taps
```

</details>
