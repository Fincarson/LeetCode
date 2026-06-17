# 715. Range Module

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/range-module/)  
`Design` `Segment Tree` `Ordered Set`

**Problem Link:** [LeetCode 715 - Range Module](https://leetcode.com/problems/range-module/)

## Problem

A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as half-open intervals and query about them.

A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

Implement the RangeModule class:

- RangeModule() Initializes the object of the data structure.
- void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
- boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently being tracked, and false otherwise.
- void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open interval [left, right).

### Example 1

```text
Input
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
Output
[null, null, null, true, false, true]

Explanation
RangeModule rangeModule = new RangeModule();
rangeModule.addRange(10, 20);
rangeModule.removeRange(14, 16);
rangeModule.queryRange(10, 14); // return True,(Every number in [10, 14) is being tracked)
rangeModule.queryRange(13, 15); // return False,(Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
rangeModule.queryRange(16, 17); // return True, (The number 16 in [16, 17) is still being tracked, despite the remove operation)
```

## Constraints

- 1 <= left < right <= 109
- At most 104 calls will be made to addRange, queryRange, and removeRange.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Insert Interval](https://leetcode.com/problems/insert-interval/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 715. Range Module

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Maintain Sorted Disjoint Intervals [Accepted] | C++, Java, Python3 |

## Approach #1: Maintain Sorted Disjoint Intervals [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class RangeModule {
    struct Interval {
        int start, end;
        Interval(int start, int end) : start(start), end(end) {}
    };
    vector<Interval> intervals;

public:
    RangeModule() {}

    void addRange(int left, int right) {
        vector<Interval> result, temp;
        int n = intervals.size(), cur = 0, i = 0;
        while (i < n) {
            if (intervals[i].end < left) {
                result.push_back(intervals[i]);
            } else if (intervals[i].start > right) {
                temp.push_back(Interval(left, right));
                break;
            } else {
                left = min(left, intervals[i].start);
                right = max(right, intervals[i].end);
            }
            i++;
        }
        if (i == n) {
            temp.push_back(Interval(left, right));
        }
        result.insert(result.end(), temp.begin(), temp.end());
        while (i < n) result.push_back(intervals[i++]);
        intervals = result;
    }

    bool queryRange(int left, int right) {
        int l = 0, r = intervals.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid].start >= right) {
                r = mid - 1;
            } else if (intervals[mid].end <= left) {
                l = mid + 1;
            } else {
                return intervals[mid].start <= left &&
                       intervals[mid].end >= right;
            }
        }
        return false;
    }

    void removeRange(int left, int right) {
        vector<Interval> result;
        int n = intervals.size(), i = 0;
        while (i < n) {
            if (intervals[i].end <= left) {
                result.push_back(intervals[i]);
            } else if (intervals[i].start >= right) {
                result.push_back(intervals[i]);
            } else {
                if (intervals[i].start < left)
                    result.push_back(Interval(intervals[i].start, left));
                if (intervals[i].end > right)
                    result.push_back(Interval(right, intervals[i].end));
            }
            i++;
        }
        intervals = result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class RangeModule {

    class Interval {

        int start;
        int end;

        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    private List<Interval> intervals;

    public RangeModule() {
        intervals = new ArrayList<>();
    }

    public void addRange(int left, int right) {
        List<Interval> result = new ArrayList<>();
        int n = intervals.size(), cur = 0;
        for (; cur < n; cur++) {
            Interval interval = intervals.get(cur);
            if (interval.end < left) {
                result.add(interval);
            } else if (interval.start > right) {
                result.add(new Interval(left, right));
                break;
            } else {
                left = Math.min(left, interval.start);
                right = Math.max(right, interval.end);
            }
        }
        if (cur == n) {
            result.add(new Interval(left, right));
        }
        while (cur < n) result.add(intervals.get(cur++));
        intervals = result;
    }

    public boolean queryRange(int left, int right) {
        int l = 0, r = intervals.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            Interval interval = intervals.get(mid);
            if (interval.start >= right) {
                r = mid - 1;
            } else if (interval.end <= left) {
                l = mid + 1;
            } else {
                return interval.start <= left && interval.end >= right;
            }
        }
        return false;
    }

    public void removeRange(int left, int right) {
        List<Interval> result = new ArrayList<>();
        int n = intervals.size(), cur = 0;
        for (; cur < n; cur++) {
            Interval interval = intervals.get(cur);
            if (interval.end <= left) {
                result.add(interval);
            } else if (interval.start >= right) {
                result.add(interval);
            } else {
                if (interval.start < left) result.add(
                    new Interval(interval.start, left)
                );
                if (interval.end > right) result.add(
                    new Interval(right, interval.end)
                );
            }
        }
        intervals = result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class RangeModule(object):
    def __init__(self):
        self.ranges = []

    def _bounds(self, left, right):
        i, j = 0, len(self.ranges) - 1
        for d in (100, 10, 1):
            while i + d - 1 < len(self.ranges) and self.ranges[i+d-1][1] < left:
                i += d
            while j >= d - 1 and self.ranges[j-d+1][0] > right:
                j -= d
        return i, j

    def addRange(self, left, right):
        i, j = self._bounds(left, right)
        if i <= j:
            left = min(left, self.ranges[i][0])
            right = max(right, self.ranges[j][1])
        self.ranges[i:j+1] = [(left, right)]

    def queryRange(self, left, right):
        i = bisect.bisect_left(self.ranges, (left, float('inf')))
        if i: i -= 1
        return (bool(self.ranges) and
                self.ranges[i][0] <= left and
                right <= self.ranges[i][1])

    def removeRange(self, left, right):
        i, j = self._bounds(left, right)
        merge = []
        for k in xrange(i, j+1):
            if self.ranges[k][0] < left:
                merge.append((self.ranges[k][0], left))
            if right < self.ranges[k][1]:
                merge.append((right, self.ranges[k][1]))
        self.ranges[i:j+1] = merge
```

</details>
