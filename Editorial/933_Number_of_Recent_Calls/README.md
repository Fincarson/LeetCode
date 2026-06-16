# 933. Number of Recent Calls

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/number-of-recent-calls/)  
`Design` `Queue` `Data Stream`

**Problem Link:** [LeetCode 933 - Number of Recent Calls](https://leetcode.com/problems/number-of-recent-calls/)

## Problem

You have a RecentCounter class which counts the number of recent requests within a certain time frame.

Implement the RecentCounter class:

- RecentCounter() Initializes the counter with zero recent requests.
- int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].

It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

### Example 1

```text
Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]

Explanation
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
```

## Constraints

- 1 <= t <= 109
- Each test case will call ping with strictly increasing values of t.
- At most 104 calls will be made to ping.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 933. Number of Recent Calls

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iteration over Sliding Window | Java, Python3 |

## Approach 1: Iteration over Sliding Window

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class RecentCounter {
    LinkedList<Integer> slideWindow;

    public RecentCounter() {
        this.slideWindow = new LinkedList<Integer>();
    }

    public int ping(int t) {
        // step 1). append the current call
        this.slideWindow.addLast(t);

        // step 2). invalidate the outdated pings
        while (this.slideWindow.getFirst() < t - 3000)
            this.slideWindow.removeFirst();

        return this.slideWindow.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class RecentCounter:

    def __init__(self):
        self.slide_window = deque()

    def ping(self, t: int) -> int:
        # step 1). append the current call
        self.slide_window.append(t)

        # step 2). invalidate the outdated pings
        while self.slide_window[0] < t - 3000:
            self.slide_window.popleft()

        return len(self.slide_window)
```

</details>
