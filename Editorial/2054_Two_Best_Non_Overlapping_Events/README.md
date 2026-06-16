# 2054. Two Best Non-Overlapping Events

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/two-best-non-overlapping-events/)  
`Array` `Binary Search` `Dynamic Programming` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 2054 - Two Best Non-Overlapping Events](https://leetcode.com/problems/two-best-non-overlapping-events/)

## Problem

You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

### Example 1

```text
Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
```

### Example 2

```text
Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.
```

### Example 3

```text
Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
```

## Constraints

- 2 <= events.length <= 105
- events[i].length == 3
- 1 <= startTimei <= endTimei <= 109
- 1 <= valuei <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Number of Events That Can Be Attended II](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximize Win From Two Segments](https://leetcode.com/problems/maximize-win-from-two-segments/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Score of Non-overlapping Intervals](https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2054. Two Best Non-Overlapping Events

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-down Dynamic Programming | C++, Java, Python3 |
| Min-heap | C++, Java, Python3 |
| Greedy | C++, Java, Python3 |

## Approach 1: Top-down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(3, -1));
        return findEvents(events, 0, 0, dp);
    }
    // Recursive function to find the greatest sum for the pairs.
    int findEvents(vector<vector<int>>& events, int idx, int cnt,
                   vector<vector<int>>& dp) {
        if (cnt == 2 || idx >= events.size()) return 0;
        if (dp[idx][cnt] == -1) {
            int end = events[idx][1];
            int lo = idx + 1, hi = events.size() - 1;
            while (lo < hi) {
                int mid = lo + ((hi - lo) >> 1);
                if (events[mid][0] > end)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            int include =
                events[idx][2] + (lo < events.size() && events[lo][0] > end
                                      ? findEvents(events, lo, cnt + 1, dp)
                                      : 0);
            int exclude = findEvents(events, idx + 1, cnt, dp);
            dp[idx][cnt] = max(include, exclude);
        }
        return dp[idx][cnt];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int[][] dp = new int[events.length][3];
        for (int[] d : dp) Arrays.fill(d, -1);
        return findEvents(events, 0, 0, dp);
    }

    // Recursive function to find the greatest sum for the pairs.
    int findEvents(int[][] events, int idx, int cnt, int[][] dp) {
        if (cnt == 2 || idx >= events.length) return 0;
        if (dp[idx][cnt] == -1) {
            int end = events[idx][1];
            int lo = idx + 1, hi = events.length - 1;
            while (lo < hi) {
                int mid = lo + ((hi - lo) >> 1);
                if (events[mid][0] > end) hi = mid;
                else lo = mid + 1;
            }
            int include =
                events[idx][2] +
                (lo < events.length && events[lo][0] > end
                        ? findEvents(events, lo, cnt + 1, dp)
                        : 0);
            int exclude = findEvents(events, idx + 1, cnt, dp);
            dp[idx][cnt] = Math.max(include, exclude);
        }
        return dp[idx][cnt];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxTwoEvents(self, events):
        events.sort()
        dp = [[-1] * 3 for _ in range(len(events))]
        return self.find_events(events, 0, 0, dp)

    # Recursive function to find the greatest sum for the pairs.
    def find_events(self, events, idx, cnt, dp):
        if cnt == 2 or idx >= len(events):
            return 0
        if dp[idx][cnt] == -1:
            end = events[idx][1]
            lo, hi = idx + 1, len(events) - 1
            while lo < hi:
                mid = lo + ((hi - lo) >> 1)
                if events[mid][0] > end:
                    hi = mid
                else:
                    lo = mid + 1
            include = events[idx][2] + (
                self.find_events(events, lo, cnt + 1, dp)
                if lo < len(events) and events[lo][0] > end
                else 0
            )
            exclude = self.find_events(events, idx + 1, cnt, dp)
            dp[idx][cnt] = max(include, exclude)
        return dp[idx][cnt]
```

</details>

<br>

## Approach 2: Min-heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Create a min-heap to store the ending time with value.
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        sort(events.begin(), events.end());

        int maxVal = 0, maxSum = 0;

        for (auto& event : events) {
            // Pop all valid events from queue and take their maximum.
            while (pq.size() && pq.top().first < event[0]) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            maxSum = max(maxSum, maxVal + event[2]);
            pq.push({event[1], event[2]});
        }

        return maxSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxTwoEvents(int[][] events) {
        //Create a PriorityQueue to store the pair ending time and value.
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(
            Comparator.comparingInt(Pair::getKey)
        );

        //Sort the array in ascending order
        Arrays.sort(events, (a, b) -> a[0] - b[0]);

        int maxVal = 0, maxSum = 0;

        for (int[] event : events) {
            // Poll all valid events from queue and take their maximum.
            while (!pq.isEmpty() && pq.peek().getKey() < event[0]) {
                maxVal = Math.max(maxVal, pq.peek().getValue());
                pq.poll();
            }

            maxSum = Math.max(maxSum, maxVal + event[2]);
            pq.add(new Pair<>(event[1], event[2]));
        }

        return maxSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        # Create a list to store the pair (end time, value) for events
        pq = []

        # Sort the events by their start time
        events.sort(key=lambda x: x[0])

        max_val = 0
        max_sum = 0

        for event in events:
            # Pop all valid events from the priority queue and take their maximum
            while pq and pq[0][0] < event[0]:
                max_val = max(max_val, pq[0][1])
                heapq.heappop(pq)

            # Calculate the maximum sum by adding the current event's value and the best previous event's value
            max_sum = max(max_sum, max_val + event[2])

            # Push the current event's end time and value into the heap
            heapq.heappush(pq, (event[1], event[2]))

        return max_sum
```

</details>

<br>

## Approach 3: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<array<int, 3>> times;
        for (auto& e : events) {
            // 1 denotes start time.
            times.push_back({e[0], 1, e[2]});
            // 0 denotes end time.
            times.push_back({e[1] + 1, 0, e[2]});
        }
        int ans = 0, maxValue = 0;
        sort(begin(times), end(times));
        for (auto& timeValue : times) {
            // If current time is a start time, find maximum sum of maximum end
            // time till now.
            if (timeValue[1]) {
                ans = max(ans, timeValue[2] + maxValue);
            } else {
                maxValue = max(maxValue, timeValue[2]);
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxTwoEvents(int[][] events) {
        List<int[]> times = new ArrayList<>();

        // Convert events into start and end times with their values
        for (int[] event : events) {
            // 1 denotes start time
            times.add(new int[] { event[0], 1, event[2] });
            // 0 denotes end time
            times.add(new int[] { event[1] + 1, 0, event[2] });
        }

        // Sort the times: first by time, then by type (end before start for same time)
        times.sort((a, b) ->
            a[0] == b[0]
                ? Integer.compare(a[1], b[1])
                : Integer.compare(a[0], b[0])
        );

        int ans = 0, maxValue = 0;

        // Process the sorted times
        for (int[] timeValue : times) {
            if (timeValue[1] == 1) {
                // Start time: Calculate the maximum sum
                ans = Math.max(ans, timeValue[2] + maxValue);
            } else {
                // End time: Update the maximum value seen so far
                maxValue = Math.max(maxValue, timeValue[2]);
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxTwoEvents(self, events):
        times = []
        for e in events:
            # 1 denotes start time.
            times.append([e[0], 1, e[2]])
            # 0 denotes end time.
            times.append([e[1] + 1, 0, e[2]])

        ans, max_value = 0, 0
        times.sort()

        for time_value in times:
            # If current time is a start time, find maximum sum of maximum end
            # time till now.
            if time_value[1]:
                ans = max(ans, time_value[2] + max_value)
            else:
                max_value = max(max_value, time_value[2])

        return ans
```

</details>
