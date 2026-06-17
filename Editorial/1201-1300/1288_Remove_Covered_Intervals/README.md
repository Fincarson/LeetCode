# 1288. Remove Covered Intervals

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/remove-covered-intervals/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 1288 - Remove Covered Intervals](https://leetcode.com/problems/remove-covered-intervals/)

## Problem

Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

### Example 1

```text
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
```

### Example 2

```text
Input: intervals = [[1,4],[2,3]]
Output: 1
```

## Constraints

- 1 <= intervals.length <= 1000
- intervals[i].length == 2
- 0 <= li < ri <= 105
- All the given intervals are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1288. Remove Covered Intervals

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy Algorithm | C++, Java, Python |

## Approach 1: Greedy Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    // If two intervals share the same start point,
    // put the longer one to be the first.
    sort(begin(intervals), end(intervals),
      [](const vector<int> &o1, const vector<int> &o2) {
      return o1[0] == o2[0] ? o2[1] < o1[1] : o1[0] < o2[0];
    });

    int count = 0;
    int end, prev_end = 0;
    for (auto curr : intervals) {
      end = curr[1];
      // if current interval is not covered
      // by the previous one
      if (prev_end < end) {
        ++count;
        prev_end = end;
      }
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
  public int removeCoveredIntervals(int[][] intervals) {
    Arrays.sort(intervals, new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        // Sort by start point.
        // If two intervals share the same start point,
        // put the longer one to be the first.
        return o1[0] == o2[0] ? o2[1] - o1[1]: o1[0] - o2[0];
      }
    });

    int count = 0;
    int end, prev_end = 0;
    for (int[] curr : intervals) {
      end = curr[1];
      // if current interval is not covered
      // by the previous one
      if (prev_end < end) {
        ++count;
        prev_end = end;
      }
    }
    return count;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        # Sort by start point.
        # If two intervals share the same start point
        # put the longer one to be the first.
        intervals.sort(key = lambda x: (x[0], -x[1]))
        count = 0
        
        prev_end = 0
        for _, end in intervals:
            # if current interval is not covered
            # by the previous one
            if end > prev_end:
                count += 1    
                prev_end = end
        
        return count
```

</details>
