# 252. Meeting Rooms

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/meeting-rooms/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 252 - Meeting Rooms](https://leetcode.com/problems/meeting-rooms/)

## Problem

You are given an array of meeting times intervals where intervals[i] = [starti, endi].

A person can attend all meetings if no two meeting intervals overlap. Meetings ending at time t and starting at time t do not overlap.

Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Return true if a person can attend all meetings. Otherwise, return false.

### Example 1

```text
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
```

### Example 2

```text
Input: intervals = [[7,10],[2,4]]
Output: true
```

## Constraints

- 0 <= intervals.length <= 104
- intervals[i].length == 2
- 0 <= starti < endi <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Points That Intersect With Cars](https://leetcode.com/problems/points-that-intersect-with-cars/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 252. Meeting Rooms

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Sorting | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool overlap(vector<int>& interval1, vector<int>& interval2) {
        return interval1[0] >= interval2[0] and interval1[0] < interval2[1]
               or interval2[0] >= interval1[0] and interval2[0] < interval1[1];
    }
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        for (size_t i = 0; i < intervals.size(); i++) {
            for (size_t j = i + 1; j < intervals.size(); j++) {
                if (overlap(intervals[i], intervals[j])) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        for (int i = 0; i < intervals.length; i++) {
            for (int j = i + 1; j < intervals.length; j++) {
                if (overlap(intervals[i], intervals[j])) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean overlap(int[] interval1, int[] interval2) {
        return (interval1[0] >= interval2[0] && interval1[0] < interval2[1])
            || (interval2[0] >= interval1[0] && interval2[0] < interval1[1]);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        def overlap(interval1: List[int], interval2: List[int]) -> bool:
            return (interval1[0] >= interval2[0] and interval1[0] < interval2[1]
                or interval2[0] >= interval1[0] and interval2[0] < interval1[1])

        for i in range(len(intervals)):
            for j in range(i + 1, len(intervals)):
                if overlap(intervals[i], intervals[j]):
                    return False
        return True
```

</details>

<br>

## Approach 2: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return true;
        }

        // Note: C++ sort function automatically sorts a vector first
        // by the 1st element, then by the 2nd element and so on.
        sort(intervals.begin(), intervals.end());
        for (size_t i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        for (int i = 0; i < intervals.length - 1; i++) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort()
        for i in range(len(intervals) - 1):
            if intervals[i][1] > intervals[i + 1][0]:
                return False
        return True
```

</details>
