# 362. Design Hit Counter

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/design-hit-counter/)  
`Array` `Binary Search` `Design` `Queue` `Data Stream`

**Problem Link:** [LeetCode 362 - Design Hit Counter](https://leetcode.com/problems/design-hit-counter/)

## Problem

Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).

Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.

Implement the HitCounter class:

- HitCounter() Initializes the object of the hit counter system.
- void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits may happen at the same timestamp.
- int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).

### Example 1

```text
Input
["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
[[], [1], [2], [3], [4], [300], [300], [301]]
Output
[null, null, null, null, 3, null, 4, 3]

Explanation
HitCounter hitCounter = new HitCounter();
hitCounter.hit(1);       // hit at timestamp 1.
hitCounter.hit(2);       // hit at timestamp 2.
hitCounter.hit(3);       // hit at timestamp 3.
hitCounter.getHits(4);   // get hits at timestamp 4, return 3.
hitCounter.hit(300);     // hit at timestamp 300.
hitCounter.getHits(300); // get hits at timestamp 300, return 4.
hitCounter.getHits(301); // get hits at timestamp 301, return 3.
```

## Constraints

- 1 <= timestamp <= 2 * 109
- All the calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing).
- At most 300 calls will be made to hit and getHits.

Follow up: What if the number of hits per second could be huge? Does your design scale?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 362. Design Hit Counter

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Using Queue | C++, Java |
| Approach #2: Using Deque with Pairs | C++, Java |

## Approach #1: Using Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class HitCounter {
private:
    
    queue<int> hits;
    
public:
    
    /** Initialize your data structure here. */
    HitCounter() {
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        this->hits.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!this->hits.empty()) {
            int diff = timestamp - this->hits.front();
            if (diff >= 300) this->hits.pop();
            else break;
        }
        return this->hits.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class HitCounter {
    private Queue<Integer> hits; 

    /** Initialize your data structure here. */
    public HitCounter() {
        this.hits = new LinkedList<Integer>();
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    public void hit(int timestamp) {
        this.hits.add(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    public int getHits(int timestamp) {
        while (!this.hits.isEmpty()) {
            int diff = timestamp - this.hits.peek();
            if (diff >= 300) this.hits.remove();
            else break;
        }
        return this.hits.size();
    }
}
```

</details>

<br>

## Approach #2: Using Deque with Pairs

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class HitCounter {
private:
    
    int total;
    queue<pair<int, int> > hits;
    
public:
    
    /** Initialize your data structure here. */
    HitCounter() {
        this->total = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (this->hits.empty() || this->hits.back().first != timestamp) {
            // Insert the new timestamp with count = 1
            this->hits.push({timestamp, 1});
        } else {
            // Update the count of latest timestamp by incrementing the count by 1
            this->hits.back().second++;
        }
        this->total++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!this->hits.empty()) {
            int diff = timestamp - this->hits.front().first;
            if (diff >= 300) {
                // Decrement total by the count of the oldest timestamp
                this->total -= this->hits.front().second;
                this->hits.pop();
            }
            else break;
        }
        return this->total;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class HitCounter {

    private int total;
    private Deque<Pair<Integer, Integer>> hits; 

    /** Initialize your data structure here. */
    public HitCounter() {
        // Initialize total to 0
        this.total = 0;
        this.hits = new LinkedList<Pair<Integer, Integer>>();
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    public void hit(int timestamp) {
        if (this.hits.isEmpty() || this.hits.getLast().getKey() != timestamp) {
            // Insert the new timestamp with count = 1
            this.hits.add(new Pair<Integer, Integer>(timestamp, 1));
        } else {
            // Update the count of latest timestamp by incrementing the count by 1

            // Obtain the current count of the latest timestamp 
            int prevCount = this.hits.getLast().getValue();
            // Remove the last pair of (timestamp, count) from the deque
            this.hits.removeLast();
            // Insert a new pair of (timestamp, updated count) in the deque
            this.hits.add(new Pair<Integer, Integer>(timestamp, prevCount + 1));
        }
        // Increment total
        this.total++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    public int getHits(int timestamp) {
        while (!this.hits.isEmpty()) {
            int diff = timestamp - this.hits.getFirst().getKey();
            if (diff >= 300) {
                // Decrement total by the count of the oldest timestamp
                this.total -= this.hits.getFirst().getValue();
                this.hits.removeFirst();
            }
            else break;
        }
        return this.total;
    }
}
```

</details>
