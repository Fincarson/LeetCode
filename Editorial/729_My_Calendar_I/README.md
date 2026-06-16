# 729. My Calendar I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/my-calendar-i/)  
`Array` `Binary Search` `Design` `Segment Tree` `Ordered Set`

**Problem Link:** [LeetCode 729 - My Calendar I](https://leetcode.com/problems/my-calendar-i/)

## Problem

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers startTime and endTime that represents a booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.

Implement the MyCalendar class:

- MyCalendar() Initializes the calendar object.
- boolean book(int startTime, int endTime) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

### Example 1

```text
Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
```

## Constraints

- 0 <= start < end <= 109
- At most 1000 calls will be made to book.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [My Calendar II](https://leetcode.com/problems/my-calendar-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [My Calendar III](https://leetcode.com/problems/my-calendar-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Determine if Two Events Have Conflict](https://leetcode.com/problems/determine-if-two-events-have-conflict/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 729. My Calendar I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force | C++, Java, Python3 |
| Approach #2: Sorted List + Binary Search | C++, Java, Python3 |

## Approach #1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MyCalendar {
private:
    vector<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        for (const auto [s, e] : calendar) {
            if (start < e && s < end) {
                return false;
            }
        }
        calendar.emplace_back(start, end);
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class MyCalendar {
    List<int[]> calendar;

    MyCalendar() {
        calendar = new ArrayList();
    }

    public boolean book(int start, int end) {
        for (int[] iv: calendar) {
            if (iv[0] < end && start < iv[1]) {
                return false;
            }
        }
        calendar.add(new int[]{start, end});
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MyCalendar:

    def __init__(self):
        self.calendar = []

    def book(self, start, end):
        for s, e in self.calendar:
            if s < end and start < e:
                return False
        self.calendar.append((start, end))
        return True
```

</details>

<br>

## Approach #2: Sorted List + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MyCalendar {
private:
    set<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        const pair<int, int> event{start, end};
        const auto nextEvent = calendar.lower_bound(event);
        if (nextEvent != calendar.end() && nextEvent->first < end) {
            return false;
        }

        if (nextEvent != calendar.begin()) {
            const auto prevEvent = prev(nextEvent);
            if (prevEvent->second > start) {
                return false;
            }
        }

        calendar.insert(event);
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MyCalendar {
    TreeMap<Integer, Integer> calendar;

    MyCalendar() {
        calendar = new TreeMap();
    }

    public boolean book(int start, int end) {
        Integer prev = calendar.floorKey(start),
                next = calendar.ceilingKey(start);
        if ((prev == null || calendar.get(prev) <= start) &&
                (next == null || end <= next)) {
            calendar.put(start, end);
            return true;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedList

class MyCalendar:
    def __init__(self):
        self.calendar = SortedList()

    def book(self, start: int, end: int) -> bool:
        idx = self.calendar.bisect_right((start, end))
        if (idx > 0 and self.calendar[idx-1][1] > start) or (idx < len(self.calendar) and self.calendar[idx][0] < end):
            return False
        self.calendar.add((start, end))
        return True
```

</details>
