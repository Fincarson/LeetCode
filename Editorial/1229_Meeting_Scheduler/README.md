# 1229. Meeting Scheduler

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/meeting-scheduler/)  
`Array` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 1229 - Meeting Scheduler](https://leetcode.com/problems/meeting-scheduler/)

## Problem

Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

### Example 1

```text
Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
Output: [60,68]
```

### Example 2

```text
Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
Output: []
```

## Constraints

- 1 <= slots1.length, slots2.length <= 104
- slots1[i].length, slots2[i].length == 2
- slots1[i][0] < slots1[i][1]
- slots2[i][0] < slots2[i][1]
- 0 <= slots1[i][j], slots2[i][j] <= 109
- 1 <= duration <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Two 2D Arrays by Summing Values](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Reschedule Meetings for Maximum Free Time I](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1229. Meeting Scheduler

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two pointers | Java, Python3 |
| Heap | Java, Python3 |

## Approach 1: Two pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        Arrays.sort(slots1, (a, b) -> a[0] - b[0]);
        Arrays.sort(slots2, (a, b) -> a[0] - b[0]);

        int pointer1 = 0, pointer2 = 0;

        while (pointer1 < slots1.length && pointer2 < slots2.length) {
            // find the boundaries of the intersection, or the common slot
            int intersectLeft = Math.max(slots1[pointer1][0], slots2[pointer2][0]);
            int intersectRight = Math.min(slots1[pointer1][1], slots2[pointer2][1]);
            if (intersectRight - intersectLeft >= duration) {
                return new ArrayList<Integer>(Arrays.asList(intersectLeft, intersectLeft + duration));
            }
            // always move the one that ends earlier
            if (slots1[pointer1][1] < slots2[pointer2][1]) {
                pointer1++;
            } else {
                pointer2++;
            }
        }
        return new ArrayList<Integer>();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:

        slots1.sort()
        slots2.sort()
        pointer1 = pointer2 = 0

        while pointer1 < len(slots1) and pointer2 < len(slots2):
            # find the boundaries of the intersection, or the common slot
            intersect_right = min(slots1[pointer1][1], slots2[pointer2][1])
            intersect_left = max(slots1[pointer1][0],slots2[pointer2][0])
            if intersect_right - intersect_left >= duration:
                return [intersect_left, intersect_left + duration]
            # always move the one that ends earlier
            if slots1[pointer1][1]< slots2[pointer2][1]:
                pointer1 += 1
            else:
                pointer2 += 1
        return []
```

</details>

<br>

## Approach 2: Heap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        PriorityQueue<int[]> timeslots = new PriorityQueue<>((slot1, slot2) -> slot1[0] - slot2[0]);

        for (int[] slot: slots1) {
            if (slot[1] - slot[0] >= duration) timeslots.offer(slot);
        }
        for (int[] slot: slots2) {
            if (slot[1] - slot[0] >= duration) timeslots.offer(slot);
        }

        while (timeslots.size() > 1) {
            int[] slot1 = timeslots.poll();
            int[] slot2 = timeslots.peek();
            if (slot1[1] >= slot2[0] + duration) {
                return new ArrayList<Integer>(Arrays.asList(slot2[0], slot2[0] + duration));
            }
        }
        return new ArrayList<Integer>();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        # build up a heap containing time slots last longer than duration
        timeslots = list(filter(lambda x: x[1] - x[0] >= duration, slots1 + slots2))
        heapq.heapify(timeslots)

        while len(timeslots) > 1:
            start1, end1 = heapq.heappop(timeslots)
            start2, end2 = timeslots[0]
            if end1 >= start2 + duration:
                return [start2, start2 + duration]
        return []
```

</details>
