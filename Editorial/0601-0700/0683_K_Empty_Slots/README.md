# 683. K Empty Slots

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/k-empty-slots/)  
`Array` `Binary Indexed Tree` `Segment Tree` `Queue` `Sliding Window` `Heap (Priority Queue)` `Ordered Set` `Monotonic Queue`

**Problem Link:** [LeetCode 683 - K Empty Slots](https://leetcode.com/problems/k-empty-slots/)

## Problem

You have n bulbs in a row numbered from 1 to n. Initially, all the bulbs are turned off. We turn on exactly one bulb every day until all bulbs are on after n days.

You are given an array bulbs of length n where bulbs[i] = x means that on the (i+1)th day, we will turn on the bulb at position x where i is 0-indexed and x is 1-indexed.

Given an integer k, return the minimum day number such that there exists two turned on bulbs that have exactly k bulbs between them that are all turned off. If there isn't such day, return -1.

### Example 1

```text
Input: bulbs = [1,3,2], k = 1
Output: 2
Explanation:
On the first day: bulbs[0] = 1, first bulb is turned on: [1,0,0]
On the second day: bulbs[1] = 3, third bulb is turned on: [1,0,1]
On the third day: bulbs[2] = 2, second bulb is turned on: [1,1,1]
We return 2 because on the second day, there were two on bulbs with one off bulb between them.
```

### Example 2

```text
Input: bulbs = [1,2,3], k = 1
Output: -1
```

## Constraints

- n == bulbs.length
- 1 <= n <= 2 * 104
- 1 <= bulbs[i] <= n
- bulbs is a permutation of numbers from 1 to n.
- 0 <= k <= 2 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 683. K Empty Slots

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Insert Into Sorted Structure [Accepted] | Java, Python |
| Approach #2: Min Queue [Accepted] | Java, Python3 |
| Approach #3: Sliding Window [Accepted] | Java, Python |

## Approach #1: Insert Into Sorted Structure [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int kEmptySlots(int[] flowers, int k) {
        TreeSet<Integer> active = new TreeSet();
        int day = 0;
        for (int flower: flowers) {
            day++;
            active.add(flower);
            Integer lower = active.lower(flower)
            Integer higher = active.higher(flower);
            if (lower != null && flower - lower - 1 == k ||
                    higher != null && higher - flower - 1 == k)
                return day;
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def kEmptySlots(self, flowers, k):
        active = []
        for day, flower in enumerate(flowers, 1):
            i = bisect.bisect(active, flower)
            for neighbor in active[i-(i>0):i+1]:
                if abs(neighbor - flower) - 1 == k:
                    return day
            active.insert(i, flower)
        return -1
```

</details>

<br>

## Approach #2: Min Queue [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int kEmptySlots(int[] flowers, int k) {
        int[] days = new int[flowers.length];
        for (int i = 0; i < flowers.length; i++) {
            days[flowers[i] - 1] = i + 1;
        }

        MinQueue<Integer> window = new MinQueue();
        int ans = days.length;

        for (int i = 0; i < days.length; i++) {
            int day = days[i];
            window.addLast(day);
            if (k <= i && i < days.length - 1) {
                window.pollFirst();
                if (k == 0 || days[i-k] < window.min() && days[i+1] < window.min()) {
                    ans = Math.min(ans, Math.max(days[i-k], days[i+1]));
                }
            }
        }

        return ans < days.length ? ans : -1;
    }
}

class MinQueue<E extends Comparable<E>> extends ArrayDeque<E> {
    Deque<E> mins;

    public MinQueue() {
        mins = new ArrayDeque<E>();
    }

    @Override
    public void addLast(E x) {
        super.addLast(x);
        while (mins.peekLast() != null &&
                x.compareTo(mins.peekLast()) < 0) {
            mins.pollLast();
        }
        mins.addLast(x);
    }

    @Override
    public E pollFirst() {
        E x = super.pollFirst();
        if (x == mins.peekFirst()) {
            mins.pollFirst();
        }
        return x;
    }

    public E min() {
        return mins.peekFirst();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque
class MinQueue(deque):
    def __init__(self):
        deque.__init__(self)
        self.mins = deque()

    def append(self, x):
        deque.append(self, x)
        while self.mins and x < self.mins[-1]:
            self.mins.pop()
        self.mins.append(x)

    def popleft(self):
        x = deque.popleft(self)
        if self.mins[0] == x:
            self.mins.popleft()
        return x

    def min(self):
        return self.mins[0]

class Solution(object):
    def kEmptySlots(self, flowers, k):
        days = [0] * len(flowers)
        for day, position in enumerate(flowers, 1):
            days[position - 1] = day

        window = MinQueue()
        ans = len(days)

        for i, day in enumerate(days):
            window.append(day)
            if k <= i < len(days) - 1:
                window.popleft()
                if k == 0 or days[i-k] < window.min() > days[i+1]:
                    ans = min(ans, max(days[i-k], days[i+1]))

        return ans if ans < len(days) else -1
```

</details>

<br>

## Approach #3: Sliding Window [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int kEmptySlots(int[] flowers, int k) {
        int[] days = new int[flowers.length];
        for (int i = 0; i < flowers.length; i++) {
            days[flowers[i] - 1] = i + 1;
        }

        int ans = Integer.MAX_VALUE;
        int left = 0, right = k+1;

        search: while (right < days.length) {
            for (int i = left+1; i < right; ++i) {
                if (days[i] < days[left] || days[i] < days[right]) {
                    left = i;
                    right = i + k + 1;
                    continue search;
                }
            }
            ans = Math.min(ans, Math.max(days[left], days[right]));
            left = right;
            right = left + k + 1;
        }

        return ans < Integer.MAX_VALUE ? ans : -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def kEmptySlots(self, flowers, k):
        days = [0] * len(flowers)
        for day, position in enumerate(flowers, 1):
            days[position - 1] = day

        ans = float('inf')
        left, right = 0, k+1
        while right < len(days):
            for i in xrange(left + 1, right):
                if days[i] < days[left] or days[i] < days[right]:
                    left, right = i, i+k+1
                    break
            else:
                ans = min(ans, max(days[left], days[right]))
                left, right = right, right+k+1

        return ans if ans < float('inf') else -1
```

</details>
