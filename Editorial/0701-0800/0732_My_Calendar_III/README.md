# 732. My Calendar III

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/my-calendar-iii/)  
`Binary Search` `Design` `Segment Tree` `Prefix Sum` `Ordered Set`

**Problem Link:** [LeetCode 732 - My Calendar III](https://leetcode.com/problems/my-calendar-iii/)

## Problem

A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

You are given some events [startTime, endTime), after each given event, return an integer k representing the maximum k-booking between all the previous events.

Implement the MyCalendarThree class:

- MyCalendarThree() Initializes the object.
- int book(int startTime, int endTime) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.

### Example 1

```text
Input
["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, 1, 1, 2, 3, 3, 3]

Explanation
MyCalendarThree myCalendarThree = new MyCalendarThree();
myCalendarThree.book(10, 20); // return 1
myCalendarThree.book(50, 60); // return 1
myCalendarThree.book(10, 40); // return 2
myCalendarThree.book(5, 15); // return 3
myCalendarThree.book(5, 10); // return 3
myCalendarThree.book(25, 55); // return 3
```

## Constraints

- 0 <= startTime < endTime <= 109
- At most 400 calls will be made to book.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [My Calendar I](https://leetcode.com/problems/my-calendar-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [My Calendar II](https://leetcode.com/problems/my-calendar-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 732. My Calendar III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sweep-line Algorithm | C++, Java, Python3 |
| Segment Tree | C++, Java, Python3 |
| Balanced Tree | C++, Java, Python3 |

## Approach 1: Sweep-line Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MyCalendarThree {
private:
    map<int, int> diff;

public:
    MyCalendarThree() {}

    int book(int start, int end) {
        int cur = 0, res = 0;
        diff[start]++;
        diff[end]--;
        for (auto& [_, delta] : diff) {
            cur += delta;
            res = max(res, cur);
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MyCalendarThree {
    private Map<Integer, Integer> diff;

    public MyCalendarThree() {
        diff = new TreeMap<>();
    }

    public int book(int start, int end) {
        diff.put(start, diff.getOrDefault(start, 0) + 1);
        diff.put(end, diff.getOrDefault(end, 0) - 1);
        int res = 0, cur = 0;
        for (int delta : diff.values()) {
            cur += delta;
            res = Math.max(res, cur);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedDict


class MyCalendarThree:

    def __init__(self):
        self.diff = SortedDict()

    def book(self, start: int, end: int) -> int:
        self.diff[start] = self.diff.get(start, 0) + 1
        self.diff[end] = self.diff.get(end, 0) - 1
        cur = res = 0
        for delta in self.diff.values():
            cur += delta
            res = max(cur, res)
        return res
```

</details>

<br>

## Approach 2: Segment Tree

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MyCalendarThree {
private:
    unordered_map<int, int> vals;
    unordered_map<int, int> lazy;

public:
    MyCalendarThree() {}

    void update(int start, int end, int left, int right, int idx) {
        if (start > right || end < left) return;
        if (left >= start && right <= end) {
            lazy[idx]++;
            vals[idx]++;
        } else {
            int mid = (left + right) / 2;
            update(start, end, left, mid, idx * 2);
            update(start, end, mid + 1, right, idx * 2 + 1);
            vals[idx] = lazy[idx] + max(vals[idx * 2], vals[idx * 2 + 1]);
        }
    }

    int book(int start, int end) {
        update(start, end - 1, 1, 1000000000, 1);
        return vals[1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MyCalendarThree {
    private Map<Integer, Integer> vals;
    private Map<Integer, Integer> lazy;

    public MyCalendarThree() {
        vals = new HashMap<>();
        lazy = new HashMap<>();
    }

    public void update(int start, int end, int left, int right, int idx) {
        if (start > right || end < left)
            return;
        if (start <= left && right <= end) {
            vals.put(idx, vals.getOrDefault(idx, 0) + 1);
            lazy.put(idx, lazy.getOrDefault(idx, 0) + 1);
        } else {
            int mid = (left + right) / 2;
            update(start, end, left, mid, idx * 2);
            update(start, end, mid + 1, right, idx * 2 + 1);
            vals.put(idx, lazy.getOrDefault(idx, 0)
                    + Math.max(vals.getOrDefault(idx * 2, 0), vals.getOrDefault(idx * 2 + 1, 0)));
        }
    }

    public int book(int start, int end) {
        update(start, end - 1, 0, 1000000000, 1);
        return vals.getOrDefault(1, 0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter


class MyCalendarThree:

    def __init__(self):
        self.vals = Counter()
        self.lazy = Counter()

    def update(self, start: int, end: int, left: int = 0, right: int = 10**9, idx: int = 1) -> None:
        if start > right or end < left:
            return

        if start <= left <= right <= end:
            self.vals[idx] += 1
            self.lazy[idx] += 1
        else:
            mid = (left + right)//2
            self.update(start, end, left, mid, idx*2)
            self.update(start, end, mid+1, right, idx*2 + 1)
            self.vals[idx] = self.lazy[idx] + \
                max(self.vals[2*idx], self.vals[2*idx+1])

    def book(self, start: int, end: int) -> int:
        self.update(start, end-1)
        return self.vals[1]
```

</details>

<br>

## Approach 3: Balanced Tree

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MyCalendarThree {
private:
    map<int, int> starts;
    int res;

public:
    MyCalendarThree() {
        starts[0] = 0, starts[1e9 + 1] = 0;
        res = 0;
    }
    void split(int x) { starts[x] = (--starts.upper_bound(x))->second; }
    int book(int start, int end) {
        split(start), split(end);
        for (auto it = starts.find(start); it->first < end; it++) {
            res = max(res, ++(it->second));
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MyCalendarThree {
    private TreeMap<Integer, Integer> starts;
    private int res;

    public MyCalendarThree() {
        starts = new TreeMap<>();
        starts.put(0, 0);
        res = 0;
    }

    public void split(int x) {
        Integer prev = starts.floorKey(x);
        Integer next = starts.ceilingKey(x);
        if (next != null && next == x)
            return;
        starts.put(x, starts.get(prev));
    }

    public int book(int start, int end) {
        split(start);
        split(end);
        for (var interval : starts.subMap(start, true, end, false).entrySet()) {
            res = Math.max(res, interval.setValue(interval.getValue() + 1) + 1);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedList

class MyCalendarThree:

    def __init__(self):
        # only store the starting point and count of events
        self.starts = SortedList([[0,0]])
        self.res = 0

    def split(self, x: int) -> None:
        idx = self.starts.bisect_left([x,0])
        if idx < len(self.starts) and self.starts[idx][0] == x:
            return idx
        self.starts.add([x,self.starts[idx-1][1]])

    def book(self, start: int, end: int) -> int:
        self.split(start)
        self.split(end)
        for interval in self.starts.irange([start,0], [end,0], (True,False)):
            interval[1] += 1
            self.res = max(self.res, interval[1])
        return self.res
```

</details>
