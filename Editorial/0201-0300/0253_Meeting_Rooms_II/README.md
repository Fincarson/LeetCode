# 253. Meeting Rooms II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/meeting-rooms-ii/)  
`Array` `Two Pointers` `Greedy` `Sorting` `Heap (Priority Queue)` `Prefix Sum`

**Problem Link:** [LeetCode 253 - Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)

## Problem

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

### Example 1

```text
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
```

### Example 2

```text
Input: intervals = [[7,10],[2,4]]
Output: 1
```

## Constraints

- 1 <= intervals.length <= 104
- 0 <= starti < endi <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Car Pooling](https://leetcode.com/problems/car-pooling/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Flowers in Full Bloom](https://leetcode.com/problems/number-of-flowers-in-full-bloom/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Total Cost to Hire K Workers](https://leetcode.com/problems/total-cost-to-hire-k-workers/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Points That Intersect With Cars](https://leetcode.com/problems/points-that-intersect-with-cars/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 253. Meeting Rooms II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Priority Queues | Java, Python3 |
| Chronological Ordering | Java, Python3 |

## Approach 1: Priority Queues

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        
    // Check for the base case. If there are no intervals, return 0
    if (intervals.length == 0) {
      return 0;
    }

    // Min heap
    PriorityQueue<Integer> allocator =
        new PriorityQueue<Integer>(
            intervals.length,
            new Comparator<Integer>() {
              public int compare(Integer a, Integer b) {
                return a - b;
              }
            });

    // Sort the intervals by start time
    Arrays.sort(
        intervals,
        new Comparator<int[]>() {
          public int compare(final int[] a, final int[] b) {
            return a[0] - b[0];
          }
        });

    // Add the first meeting
    allocator.add(intervals[0][1]);

    // Iterate over remaining intervals
    for (int i = 1; i < intervals.length; i++) {

      // If the room due to free up the earliest is free, assign that room to this meeting.
      if (intervals[i][0] >= allocator.peek()) {
        allocator.poll();
      }

      // If a new room is to be assigned, then also we add to the heap,
      // If an old room is allocated, then also we have to add to the heap with updated end time.
      allocator.add(intervals[i][1]);
    }

    // The size of the heap tells us the minimum rooms required for all the meetings.
    return allocator.size();
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        
        # If there is no meeting to schedule then no room needs to be allocated.
        if not intervals:
            return 0

        # The heap initialization
        free_rooms = []

        # Sort the meetings in increasing order of their start time.
        intervals.sort(key= lambda x: x[0])

        # Add the first meeting. We have to give a new room to the first meeting.
        heapq.heappush(free_rooms, intervals[0][1])

        # For all the remaining meeting rooms
        for i in intervals[1:]:

            # If the room due to free up the earliest is free, assign that room to this meeting.
            if free_rooms[0] <= i[0]:
                heapq.heappop(free_rooms)

            # If a new room is to be assigned, then also we add to the heap,
            # If an old room is allocated, then also we have to add to the heap with updated end time.
            heapq.heappush(free_rooms, i[1])

        # The size of the heap tells us the minimum rooms required for all the meetings.
        return len(free_rooms)
```

</details>

<br>

## Approach 2: Chronological Ordering

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        
    // Check for the base case. If there are no intervals, return 0
    if (intervals.length == 0) {
      return 0;
    }

    Integer[] start = new Integer[intervals.length];
    Integer[] end = new Integer[intervals.length];

    for (int i = 0; i < intervals.length; i++) {
      start[i] = intervals[i][0];
      end[i] = intervals[i][1];
    }

    // Sort the intervals by end time
    Arrays.sort(
        end,
        new Comparator<Integer>() {
          public int compare(Integer a, Integer b) {
            return a - b;
          }
        });

    // Sort the intervals by start time
    Arrays.sort(
        start,
        new Comparator<Integer>() {
          public int compare(Integer a, Integer b) {
            return a - b;
          }
        });

    // The two pointers in the algorithm: e_ptr and s_ptr.
    int startPointer = 0, endPointer = 0;

    // Variables to keep track of maximum number of rooms used.
    int usedRooms = 0;

    // Iterate over intervals.
    while (startPointer < intervals.length) {

      // If there is a meeting that has ended by the time the meeting at `start_pointer` starts
      if (start[startPointer] >= end[endPointer]) {
        usedRooms -= 1;
        endPointer += 1;
      }

      // We do this irrespective of whether a room frees up or not.
      // If a room got free, then this used_rooms += 1 wouldn't have any effect. used_rooms would
      // remain the same in that case. If no room was free, then this would increase used_rooms
      usedRooms += 1;
      startPointer += 1;

    }

    return usedRooms;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        
        # If there are no meetings, we don't need any rooms.
        if not intervals:
            return 0

        used_rooms = 0

        # Separate out the start and the end timings and sort them individually.
        start_timings = sorted([i[0] for i in intervals])
        end_timings = sorted(i[1] for i in intervals)
        L = len(intervals)

        # The two pointers in the algorithm: e_ptr and s_ptr.
        end_pointer = 0
        start_pointer = 0

        # Until all the meetings have been processed
        while start_pointer < L:
            # If there is a meeting that has ended by the time the meeting at `start_pointer` starts
            if start_timings[start_pointer] >= end_timings[end_pointer]:
                # Free up a room and increment the end_pointer.
                used_rooms -= 1
                end_pointer += 1

            # We do this irrespective of whether a room frees up or not.
            # If a room got free, then this used_rooms += 1 wouldn't have any effect. used_rooms would
            # remain the same in that case. If no room was free, then this would increase used_rooms
            used_rooms += 1    
            start_pointer += 1   

        return used_rooms
```

</details>
