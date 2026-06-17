# 1272. Remove Interval

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/remove-interval/)  
`Array`

**Problem Link:** [LeetCode 1272 - Remove Interval](https://leetcode.com/problems/remove-interval/)

## Problem

A set of real numbers can be represented as the union of several disjoint intervals, where each interval is in the form [a, b). A real number x is in the set if one of its intervals [a, b) contains x (i.e. a <= x < b).

You are given a sorted list of disjoint intervals intervals representing a set of real numbers as described above, where intervals[i] = [ai, bi] represents the interval [ai, bi). You are also given another interval toBeRemoved.

Return the set of real numbers with the interval toBeRemoved removed from intervals. In other words, return the set of real numbers such that every x in the set is in intervals but not in toBeRemoved. Your answer should be a sorted list of disjoint intervals as described above.

### Example 1

```text
Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
Output: [[0,1],[6,7]]
```

### Example 2

```text
Input: intervals = [[0,5]], toBeRemoved = [2,3]
Output: [[0,2],[3,5]]
```

### Example 3

```text
Input: intervals = [[-5,-4],[-3,-2],[1,2],[3,5],[8,9]], toBeRemoved = [-1,4]
Output: [[-5,-4],[-3,-2],[4,5],[8,9]]
```

## Constraints

- 1 <= intervals.length <= 104
- -109 <= ai < bi <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1272. Remove Interval

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sweep Line, One Pass. | Java, Python3 |

## Approach 1: Sweep Line, One Pass.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        List<List<Integer>> result = new ArrayList<>();
        for (int[] interval : intervals) {
            // If there are no overlaps, add the interval to the list as is.
            if (interval[0] > toBeRemoved[1] || interval[1] < toBeRemoved[0]) {
                result.add(Arrays.asList(interval[0], interval[1]));
            } else {
                // Is there a left interval we need to keep?
                if (interval[0] < toBeRemoved[0]) {
                    result.add(Arrays.asList(interval[0], toBeRemoved[0]));
                }
                // Is there a right interval we need to keep?
                if (interval[1] > toBeRemoved[1]) {
                    result.add(Arrays.asList(toBeRemoved[1], interval[1]));
                }
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:

        remove_start, remove_end = toBeRemoved
        output = []

        for start, end in intervals:
            # If there are no overlaps, add the interval to the list as is.
            if start > remove_end or end < remove_start:
                output.append([start, end])
            else:
                # Is there a left interval we need to keep?
                if start < remove_start:
                    output.append([start, remove_start])
                # Is there a right interval we need to keep?
                if end > remove_end:
                    output.append([remove_end, end])

        return output
```

</details>
