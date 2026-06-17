# 986. Interval List Intersections

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/interval-list-intersections/)  
`Array` `Two Pointers` `Sweep Line`

**Problem Link:** [LeetCode 986 - Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/)

## Problem

You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

### Example 1

```text
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
```

### Example 2

```text
Input: firstList = [[1,3],[5,9]], secondList = []
Output: []
```

## Constraints

- 0 <= firstList.length, secondList.length <= 1000
- firstList.length + secondList.length >= 1
- 0 <= starti < endi <= 109
- endi < starti+1
- 0 <= startj < endj <= 109
- endj < startj+1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Employee Free Time](https://leetcode.com/problems/employee-free-time/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Matching of Players With Trainers](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 986. Interval List Intersections

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Merge Intervals | Java, Python |

## Approach 1: Merge Intervals

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int[][] intervalIntersection(int[][] A, int[][] B) {
    List<int[]> ans = new ArrayList();
    int i = 0, j = 0;

    while (i < A.length && j < B.length) {
      // Let's check if A[i] intersects B[j].
      // lo - the startpoint of the intersection
      // hi - the endpoint of the intersection
      int lo = Math.max(A[i][0], B[j][0]);
      int hi = Math.min(A[i][1], B[j][1]);
      if (lo <= hi)
        ans.add(new int[]{lo, hi});

      // Remove the interval with the smallest endpoint
      if (A[i][1] < B[j][1])
        i++;
      else
        j++;
    }

    return ans.toArray(new int[ans.size()][]);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        ans = []
        i = j = 0

        while i < len(A) and j < len(B):
            # Let's check if A[i] intersects B[j].
            # lo - the startpoint of the intersection
            # hi - the endpoint of the intersection
            lo = max(A[i][0], B[j][0])
            hi = min(A[i][1], B[j][1])
            if lo <= hi:
                ans.append([lo, hi])

            # Remove the interval with the smallest endpoint
            if A[i][1] < B[j][1]:
                i += 1
            else:
                j += 1

        return ans
```

</details>
