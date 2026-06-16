# 346. Moving Average from Data Stream

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/moving-average-from-data-stream/)  
`Array` `Design` `Queue` `Data Stream`

**Problem Link:** [LeetCode 346 - Moving Average from Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/)

## Problem

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

- MovingAverage(int size) Initializes the object with the size of the window size.
- double next(int val) Returns the moving average of the last size values of the stream.

### Example 1

```text
Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
```

## Constraints

- 1 <= size <= 1000
- -105 <= val <= 105
- At most 104 calls will be made to next.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 346. Moving Average from Data Stream

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Array or List | C++, Java, Python3 |
| Double-ended Queue | C++, Java, Python3 |
| Circular Queue with Array | C++, Java, Python3 |

## Approach 1: Array or List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MovingAverage {
private:
    int size;
    vector<int> queue;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) { this->size = size; }

    double next(int val) {
        queue.push_back(val);
        // calculate the sum of the moving window
        int windowSum = 0;
        for (int i = max(0, (int)queue.size() - size); i < queue.size(); ++i)
            windowSum += queue[i];

        return windowSum * 1.0 / min((int)queue.size(), size);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MovingAverage {

    int size;
    List queue = new ArrayList<Integer>();

    public MovingAverage(int size) {
        this.size = size;
    }

    public double next(int val) {
        queue.add(val);
        // calculate the sum of the moving window
        int windowSum = 0;
        for (
            int i = Math.max(0, queue.size() - size);
            i < queue.size();
            ++i
        ) windowSum += (int) queue.get(i);

        return (windowSum * 1.0) / Math.min(queue.size(), size);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MovingAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = []

    def next(self, val: int) -> float:
        size, queue = self.size, self.queue
        queue.append(val)
        # calculate the sum of the moving window
        window_sum = sum(queue[-size:])

        return window_sum / min(len(queue), size)
```

</details>

<br>

## Approach 2: Double-ended Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MovingAverage {
private:
    int size, windowSum = 0, count = 0;
    std::deque<int> queue;

public:
    MovingAverage(int size) { this->size = size; }

    double next(int val) {
        ++count;
        // calculate the new sum by shifting the window
        queue.push_back(val);
        int tail = count > size ? queue.front() : 0;
        if (count > size) queue.pop_front();

        windowSum = windowSum - tail + val;

        return static_cast<double>(windowSum) / std::min(size, count);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MovingAverage {

    int size, windowSum = 0, count = 0;
    Deque queue = new ArrayDeque<Integer>();

    public MovingAverage(int size) {
        this.size = size;
    }

    public double next(int val) {
        ++count;
        // calculate the new sum by shifting the window
        queue.add(val);
        int tail = count > size ? (int) queue.poll() : 0;

        windowSum = windowSum - tail + val;

        return (windowSum * 1.0) / Math.min(size, count);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque


class MovingAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = deque()
        # number of elements seen so far
        self.window_sum = 0
        self.count = 0

    def next(self, val: int) -> float:
        self.count += 1
        # calculate the new sum by shifting the window
        self.queue.append(val)
        tail = self.queue.popleft() if self.count > self.size else 0

        self.window_sum = self.window_sum - tail + val

        return self.window_sum / min(self.size, self.count)
```

</details>

<br>

## Approach 3: Circular Queue with Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MovingAverage {
private:
    int size;
    int head = 0;
    int windowSum = 0;
    int count = 0;
    vector<int> queue;

public:
    MovingAverage(int size) {
        this->size = size;
        queue = vector<int>(size);
    }

    double next(int val) {
        ++count;
        // calculate the new sum by shifting the window
        int tail = (head + 1) % size;
        windowSum = windowSum - queue[tail] + val;
        // move on to the next head
        head = (head + 1) % size;
        queue[head] = val;
        return windowSum * 1.0 / min(size, count);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MovingAverage {

    int size, head = 0, windowSum = 0, count = 0;
    int[] queue;

    public MovingAverage(int size) {
        this.size = size;
        queue = new int[size];
    }

    public double next(int val) {
        ++count;
        // calculate the new sum by shifting the window
        int tail = (head + 1) % size;
        windowSum = windowSum - queue[tail] + val;
        // move on to the next head
        head = (head + 1) % size;
        queue[head] = val;
        return (windowSum * 1.0) / Math.min(size, count);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MovingAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = [0] * self.size
        self.head = self.window_sum = 0
        # number of elements seen so far
        self.count = 0

    def next(self, val: int) -> float:
        self.count += 1
        # calculate the new sum by shifting the window
        tail = (self.head + 1) % self.size
        self.window_sum = self.window_sum - self.queue[tail] + val
        # move on to the next head
        self.head = (self.head + 1) % self.size
        self.queue[self.head] = val
        return self.window_sum / min(self.size, self.count)
```

</details>
