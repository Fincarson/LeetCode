# 2406. Divide Intervals Into Minimum Number of Groups

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/)  
`Array` `Two Pointers` `Greedy` `Sorting` `Heap (Priority Queue)` `Prefix Sum`

**Problem Link:** [LeetCode 2406 - Divide Intervals Into Minimum Number of Groups](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/)

## Problem

You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.

### Example 1

```text
Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
```

### Example 2

```text
Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.
```

## Constraints

- 1 <= intervals.length <= 105
- intervals[i].length == 2
- 1 <= lefti <= righti <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Number of Frogs Croaking](https://leetcode.com/problems/minimum-number-of-frogs-croaking/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Average Height of Buildings in Each Segment](https://leetcode.com/problems/average-height-of-buildings-in-each-segment/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2406. Divide Intervals Into Minimum Number of Groups

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting or Priority Queue | C++, Java, Python3 |
| Line Sweep Algorithm With Ordered Container | C++, Java, Python3 |
| Line Sweep Algorithm Without Ordered Container | C++, Java, Python3 |

## Approach 1: Sorting or Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Convert the intervals to two events
        // start as {start, 1} and end as {end, -1}
        vector<pair<int, int>> intervalsWithEnd;
        for (vector<int> interval : intervals) {
            intervalsWithEnd.push_back({interval[0], 1});
            intervalsWithEnd.push_back({interval[1] + 1, -1});
        }

        // Sort the events according to the number and then by the value (1/-1).
        sort(intervalsWithEnd.begin(), intervalsWithEnd.end());

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        for (auto p : intervalsWithEnd) {
            // Keep track of currently active intersecting intervals.
            concurrentIntervals += p.second;
            // Update the maximum number of active intervals.
            maxConcurrentIntervals =
                max(maxConcurrentIntervals, concurrentIntervals);
        }

        return maxConcurrentIntervals;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minGroups(int[][] intervals) {
        // Convert the intervals to two events
        // start as {start, 1} and end as {end + 1, -1}
        List<int[]> events = new ArrayList<>();

        for (int[] interval : intervals) {
            events.add(new int[] { interval[0], 1 }); // Start event
            events.add(new int[] { interval[1] + 1, -1 }); // End event (interval[1] + 1)
        }

        // Sort the events first by time, and then by type (1 for start, -1 for end).
        Collections.sort(events, (a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]); // Sort by type (1 before -1)
            } else {
                return Integer.compare(a[0], b[0]); // Sort by time
            }
        });

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;

        // Sweep through the events
        for (int[] event : events) {
            concurrentIntervals += event[1]; // Track currently active intervals
            maxConcurrentIntervals = Math.max(
                maxConcurrentIntervals,
                concurrentIntervals
            ); // Update max
        }

        return maxConcurrentIntervals;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        # Convert the intervals to two events
        # start as (start, 1) and end as (end + 1, -1)
        events = []

        for interval in intervals:
            events.append((interval[0], 1))  # Start event
            events.append((interval[1] + 1, -1))  # End event (interval[1] + 1)

        # Sort the events first by time, and then by type (1 for start, -1 for end).
        events.sort(key=lambda x: (x[0], x[1]))

        concurrent_intervals = 0
        max_concurrent_intervals = 0

        # Sweep through the events
        for event in events:
            concurrent_intervals += event[1]  # Track currently active intervals
            max_concurrent_intervals = max(
                max_concurrent_intervals, concurrent_intervals
            )  # Update max

        return max_concurrent_intervals
```

</details>

<br>

## Approach 2: Line Sweep Algorithm With Ordered Container

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> pointToCount;

        // Mark the starting and ending points in the map
        for (vector<int> interval : intervals) {
            pointToCount[interval[0]]++;
            pointToCount[interval[1] + 1]--;
        }

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        // Iterate over the numbers in ascending order
        for (pair<int, int> p : pointToCount) {
            // Add the currently active intervals
            concurrentIntervals += p.second;

            // Update the maximum active intervals at any time
            maxConcurrentIntervals =
                max(maxConcurrentIntervals, concurrentIntervals);
        }

        return maxConcurrentIntervals;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minGroups(int[][] intervals) {
        // Use a TreeMap to store the points and their counts
        TreeMap<Integer, Integer> pointToCount = new TreeMap<>();

        // Mark the starting and ending points in the TreeMap
        for (int[] interval : intervals) {
            pointToCount.put(
                interval[0],
                pointToCount.getOrDefault(interval[0], 0) + 1
            );
            pointToCount.put(
                interval[1] + 1,
                pointToCount.getOrDefault(interval[1] + 1, 0) - 1
            );
        }

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;

        // Iterate over the entries of the TreeMap in ascending order of keys
        for (Map.Entry<Integer, Integer> entry : pointToCount.entrySet()) {
            concurrentIntervals += entry.getValue(); // Update currently active intervals
            maxConcurrentIntervals = Math.max(
                maxConcurrentIntervals,
                concurrentIntervals
            ); // Update max intervals
        }

        return maxConcurrentIntervals;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        # Use a dictionary to store the points and their counts
        point_to_count = defaultdict(int)

        # Mark the starting and ending points in the dictionary
        for interval in intervals:
            point_to_count[interval[0]] += 1  # Start of an interval
            point_to_count[
                interval[1] + 1
            ] -= 1  # End of an interval (interval[1] + 1)

        concurrent_intervals = 0
        max_concurrent_intervals = 0

        # Iterate over the sorted keys of the dictionary
        for point in sorted(point_to_count.keys()):
            concurrent_intervals += point_to_count[
                point
            ]  # Update currently active intervals
            max_concurrent_intervals = max(
                max_concurrent_intervals, concurrent_intervals
            )  # Update max intervals

        return max_concurrent_intervals
```

</details>

<br>

## Approach 3: Line Sweep Algorithm Without Ordered Container

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Find the minimum and maximum value in the interval
        int rangeStart = INT_MAX;
        int rangeEnd = INT_MIN;
        for (vector<int> interval : intervals) {
            rangeStart = min(rangeStart, interval[0]);
            rangeEnd = max(rangeEnd, interval[1]);
        }

        // Initialize the list with all zeroes
        vector<int> pointToCount(rangeEnd + 2, 0);
        for (vector<int> interval : intervals) {
            pointToCount[interval[0]]++;
            pointToCount[interval[1] + 1]--;
        }

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        for (int i = rangeStart; i <= rangeEnd; i++) {
            // Update currently active intervals
            concurrentIntervals += pointToCount[i];
            maxConcurrentIntervals =
                max(maxConcurrentIntervals, concurrentIntervals);
        }

        return maxConcurrentIntervals;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minGroups(int[][] intervals) {
        // Find the minimum and maximum value in the intervals
        int rangeStart = Integer.MAX_VALUE;
        int rangeEnd = Integer.MIN_VALUE;
        for (int[] interval : intervals) {
            rangeStart = Math.min(rangeStart, interval[0]);
            rangeEnd = Math.max(rangeEnd, interval[1]);
        }

        // Initialize the array with all zeroes
        int[] pointToCount = new int[rangeEnd + 2];
        for (int[] interval : intervals) {
            pointToCount[interval[0]]++; // Increment at the start of the interval
            pointToCount[interval[1] + 1]--; // Decrement right after the end of the interval
        }

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        for (int i = rangeStart; i <= rangeEnd; i++) {
            // Update currently active intervals
            concurrentIntervals += pointToCount[i];
            maxConcurrentIntervals = Math.max(
                maxConcurrentIntervals,
                concurrentIntervals
            );
        }

        return maxConcurrentIntervals;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        # Find the minimum and maximum value in the intervals
        range_start = float("inf")
        range_end = float("-inf")
        for interval in intervals:
            range_start = min(range_start, interval[0])
            range_end = max(range_end, interval[1])

        # Initialize the list with all zeroes
        point_to_count = [0] * (range_end + 2)
        for interval in intervals:
            point_to_count[
                interval[0]
            ] += 1  # Increment at the start of the interval
            point_to_count[
                interval[1] + 1
            ] -= 1  # Decrement right after the end of the interval

        concurrent_intervals = 0
        max_concurrent_intervals = 0
        for i in range(range_start, range_end + 1):
            # Update currently active intervals
            concurrent_intervals += point_to_count[i]
            max_concurrent_intervals = max(
                max_concurrent_intervals, concurrent_intervals
            )

        return max_concurrent_intervals
```

</details>
