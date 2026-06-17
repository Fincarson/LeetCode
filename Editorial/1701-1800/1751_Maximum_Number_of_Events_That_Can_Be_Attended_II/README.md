# 1751. Maximum Number of Events That Can Be Attended II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)  
`Array` `Binary Search` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 1751 - Maximum Number of Events That Can Be Attended II](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)

## Problem

You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

### Example 1

```text
Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
```

### Example 2

```text
Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
```

### Example 3

```text
Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
```

## Constraints

- 1 <= k <= events.length
- 1 <= k * events.length <= 106
- 1 <= startDayi <= endDayi <= 109
- 1 <= valuei <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Earnings From Taxi](https://leetcode.com/problems/maximum-earnings-from-taxi/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Two Best Non-Overlapping Events](https://leetcode.com/problems/two-best-non-overlapping-events/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1751. Maximum Number of Events That Can Be Attended II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-down Dynamic Programming + Binary Search | Java, Python |
| Bottom-up Dynamic Programming + Binary Search | Java, Python |
| Top-down Dynamic Programming + Cached Binary Search | Java, Python |
| Bottom-up Dynamic Programming + Optimized Binary Search | Java, Python |
| Top-down Dynamic Programming Without Binary Search (Time Limit Exceed) | Java, Python |

## Approach 1: Top-down Dynamic Programming + Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxValue(int[][] events, int k) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int n = events.length;
        
        dp = new int[k + 1][n];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        
        return dfs(0, k, events);
    }    
    
    private int[][] dp;
    private int dfs(int curIndex, int count, int[][] events) {
        if (count == 0 || curIndex == events.length) {
            return 0;
        }
        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }
        int nextIndex = bisectRight(events, events[curIndex][1]);
        dp[count][curIndex] = Math.max(dfs(curIndex + 1, count, events), events[curIndex][2] + dfs(nextIndex, count - 1, events));
        return dp[count][curIndex];
    }
    
    public static int bisectRight(int[][] events, int target) {
        int left = 0, right = events.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }   
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:        
        events.sort()
        n = len(events)
        starts = [start for start, end, value in events]
        dp = [[-1] * n for _ in range(k + 1)]
        
        def dfs(cur_index, count):
            if count == 0 or cur_index == n:
                return 0
            if dp[count][cur_index] != -1:
                return dp[count][cur_index]

            # Find the nearest available event after attending event 0.

            next_index = bisect_right(starts, events[cur_index][1])
            dp[count][cur_index] = max(dfs(cur_index + 1, count), events[cur_index][2] + dfs(next_index, count - 1))
            return dp[count][cur_index]
        
        return dfs(0, k)
```

</details>

<br>

## Approach 2: Bottom-up Dynamic Programming + Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public static int bisectRight(int[][] events, int target) {
        int left = 0, right = events.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    } 
    
    public int maxValue(int[][] events, int k) {
        int n = events.length;
        int[][] dp = new int[k + 1][n + 1];
        Arrays.sort(events, (a, b) -> a[0] - b[0]);

        for (int curIndex = n - 1; curIndex >= 0; --curIndex) {
            for (int count = 1; count <= k; count++) {
                int nextIndex = bisectRight(events, events[curIndex][1]);
                dp[count][curIndex] = Math.max(dp[count][curIndex + 1], events[curIndex][2] + dp[count - 1][nextIndex]);
            }
        }
        return dp[k][0];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:        
        n = len(events)
        dp = [[0] * (n + 1) for _ in range(k + 1)]
        events.sort()
        starts = [start for start, end, value in events]

        for cur_index in range(n - 1, -1, -1):
            for count in range(1, k + 1):
                next_index = bisect_right(starts, events[cur_index][1])
                dp[count][cur_index] = max(dp[count][cur_index + 1], events[cur_index][2] + dp[count - 1][next_index])
        
        return dp[k][0]
```

</details>

<br>

## Approach 3: Top-down Dynamic Programming + Cached Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxValue(int[][] events, int k) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int n = events.length;
        nextIndices = new int[n];
        for (int curIndex = 0; curIndex < n; ++curIndex) {
            nextIndices[curIndex] = bisectRight(events, events[curIndex][1]);
        }
        
        dp = new int[k + 1][n];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        
        return dfs(0, k, events);
    }    
    
    private int[][] dp;
    private int[] nextIndices;
    private int dfs(int curIndex, int count, int[][] events) {
        if (count == 0 || curIndex == events.length) {
            return 0;
        }
        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }
        int nextIndex = nextIndices[curIndex];
        dp[count][curIndex] = Math.max(dfs(curIndex + 1, count, events), events[curIndex][2] + dfs(nextIndex, count - 1, events));
        return dp[count][curIndex];
    }
    
    public static int bisectRight(int[][] events, int target) {
        int left = 0, right = events.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }   
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:        
        events.sort()
        n = len(events)
        starts = [start for start, end, value in events]
        next_indices = [bisect_right(starts, events[cur_index][1]) for cur_index in range(n)]
        dp = [[-1] * n for _ in range(k)]
        
        def dfs(cur_index, count):
            if count == k or cur_index == n:
                return 0
            if dp[count][cur_index] != -1:
                return dp[count][cur_index]
            next_index = next_indices[cur_index]
            dp[count][cur_index] = max(dfs(cur_index + 1, count), events[cur_index][2] + dfs(next_index, count + 1))
            return dp[count][cur_index]
        
        return dfs(0, 0)
```

</details>

<br>

## Approach 4: Bottom-up Dynamic Programming + Optimized Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public static int bisectRight(int[][] events, int target) {
        int left = 0, right = events.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    } 
    
    public int maxValue(int[][] events, int k) {
        int n = events.length;
        int[][] dp = new int[k + 1][n + 1];
        Arrays.sort(events, (a, b) -> a[0] - b[0]);

        for (int curIndex = n - 1; curIndex >= 0; --curIndex) {
            int nextIndex = bisectRight(events, events[curIndex][1]);
            for (int count = 1; count <= k; count++) {
                dp[count][curIndex] = Math.max(dp[count][curIndex + 1], events[curIndex][2] + dp[count - 1][nextIndex]);
            }
        }
        return dp[k][0];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:        
        n = len(events)
        dp = [[0] * (n + 1) for _ in range(k + 1)]
        events.sort()
        starts = [start for start, end, value in events]

        for cur_index in range(n - 1, -1, -1):
            next_index = bisect_right(starts, events[cur_index][1])
            for count in range(1, k + 1):
                dp[count][cur_index] = max(dp[count][cur_index + 1], events[cur_index][2] + dp[count - 1][next_index])
        
        return dp[k][0]
```

</details>

<br>

## Approach 5: Top-down Dynamic Programming Without Binary Search (Time Limit Exceed)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][] dp;
    public int maxValue(int[][] events, int k) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int n = events.length;
        dp = new int[k + 1][n];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return dfs(0, 0, -1, events, k);
    }
    
    private int dfs(int curIndex, int count, int prevEndingTime, int[][] events, int k) {
        if (curIndex == events.length || count == k) {
            return 0;
        }
        
        if (prevEndingTime >= events[curIndex][0]) {
            return dfs(curIndex + 1, count, prevEndingTime, events, k);
        }
        
        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }
        
        int ans = Math.max(dfs(curIndex + 1, count, prevEndingTime, events, k),
                           dfs(curIndex + 1, count + 1, events[curIndex][1], events, k) + events[curIndex][2]);
        dp[count][curIndex] = ans;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()
        n = len(events)
        dp = [[-1] * n for _ in range(k + 1)]
        
        def dfs(cur_index, count, prev_ending_time):
            if cur_index == n or count == k:
                return 0
            if events[cur_index][0] <= prev_ending_time:            
                return dfs(cur_index + 1, count, prev_ending_time)
            
            if dp[count][cur_index] != -1:
                return dp[count][cur_index]
            
            ans = max(dfs(cur_index + 1, count, prev_ending_time), dfs(cur_index + 1, count + 1, events[cur_index][1]) + events[cur_index][2])
            dp[count][cur_index] = ans
            return ans

        return dfs(0, 0, -1)
```

</details>
