# 435. Non-overlapping Intervals

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/non-overlapping-intervals/)  
`Array` `Dynamic Programming` `Greedy` `Sorting`

**Problem Link:** [LeetCode 435 - Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)

## Problem

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

### Example 1

```text
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
```

### Example 2

```text
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
```

### Example 3

```text
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
```

## Constraints

- 1 <= intervals.length <= 105
- intervals[i].length == 2
- -5 * 104 <= starti < endi <= 5 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Determine if Two Events Have Conflict](https://leetcode.com/problems/determine-if-two-events-have-conflict/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 435. Non-overlapping Intervals

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C++, Java, Python3 |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
bool compareSecondElement(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareSecondElement);
        int ans = 0;
        int k = INT_MIN;
        
        for (int i = 0; i < intervals.size(); i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];
            
            if (x >= k) {
                // Case 1
                k = y;
            } else {
                // Case 2
                ans++;
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
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));
        int ans = 0;
        int k = Integer.MIN_VALUE;
        
        for (int i = 0; i < intervals.length; i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];
            
            if (x >= k) {
                // Case 1
                k = y;
            } else {
                // Case 2
                ans++;
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
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x: x[1])
        ans = 0
        k = -inf
        
        for x, y in intervals:
            if x >= k:
                # Case 1
                k = y
            else:
                # Case 2
                ans += 1
        
        return ans
```

</details>
