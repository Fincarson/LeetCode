# 871. Minimum Number of Refueling Stops

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-number-of-refueling-stops/)  
`Array` `Dynamic Programming` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 871 - Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/)

## Problem

A car travels from a starting position to a destination which is target miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

### Example 1

```text
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
```

### Example 2

```text
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can not reach the target (or even the first gas station).
```

### Example 3

```text
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
```

## Constraints

- 1 <= target, startFuel <= 109
- 0 <= stations.length <= 500
- 1 <= positioni < positioni+1 < target
- 1 <= fueli < 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 871. Minimum Number of Refueling Stops

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | Java, Python |
| Heap | Java, Python |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int N = stations.length;
        long[] dp = new long[N + 1];
        dp[0] = startFuel;
        for (int i = 0; i < N; ++i)
            for (int t = i; t >= 0; --t)
                if (dp[t] >= stations[i][0])
                    dp[t+1] = Math.max(dp[t+1], dp[t] + (long) stations[i][1]);

        for (int i = 0; i <= N; ++i)
            if (dp[i] >= target) return i;
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minRefuelStops(self, target, startFuel, stations):
        dp = [startFuel] + [0] * len(stations)
        for i, (location, capacity) in enumerate(stations):
            for t in xrange(i, -1, -1):
                if dp[t] >= location:
                    dp[t+1] = max(dp[t+1], dp[t] + capacity)

        for i, d in enumerate(dp):
            if d >= target: return i
        return -1
```

</details>

<br>

## Approach 2: Heap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minRefuelStops(int target, int tank, int[][] stations) {
        // pq is a maxheap of gas station capacities
        PriorityQueue<Integer> pq = new PriorityQueue(Collections.reverseOrder());
        int ans = 0, prev = 0;
        for (int[] station: stations) {
            int location = station[0];
            int capacity = station[1];
            tank -= location - prev;
            while (!pq.isEmpty() && tank < 0) {  // must refuel in past
                tank += pq.poll();
                ans++;
            }

            if (tank < 0) return -1;
            pq.offer(capacity);
            prev = location;
        }

        // Repeat body for station = (target, inf)
        {
            tank -= target - prev;
            while (!pq.isEmpty() && tank < 0) {
                tank += pq.poll();
                ans++;
            }
            if (tank < 0) return -1;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minRefuelStops(self, target, tank, stations):
        pq = []  # A maxheap is simulated using negative values
        stations.append((target, float('inf')))

        ans = prev = 0
        for location, capacity in stations:
            tank -= location - prev
            while pq and tank < 0:  # must refuel in past
                tank += -heapq.heappop(pq)
                ans += 1
            if tank < 0: return -1
            heapq.heappush(pq, -capacity)
            prev = location

        return ans
```

</details>
