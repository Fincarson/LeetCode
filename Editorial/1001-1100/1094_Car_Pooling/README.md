# 1094. Car Pooling

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/car-pooling/)  
`Array` `Sorting` `Heap (Priority Queue)` `Simulation` `Prefix Sum`

**Problem Link:** [LeetCode 1094 - Car Pooling](https://leetcode.com/problems/car-pooling/)

## Problem

There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

### Example 1

```text
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
```

### Example 2

```text
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
```

## Constraints

- 1 <= trips.length <= 1000
- trips[i].length == 3
- 1 <= numPassengersi <= 100
- 0 <= fromi < toi <= 1000
- 1 <= capacity <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1094. Car Pooling

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Time Stamp | Java, Python3 |
| Bucket Sort | Java, Python3 |

## Approach 1: Time Stamp

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        Map<Integer, Integer> timestamp = new TreeMap<>();
        for (int[] trip : trips) {
            int startPassenger = timestamp.getOrDefault(trip[1], 0) + trip[0];
            timestamp.put(trip[1], startPassenger);

            int endPassenger = timestamp.getOrDefault(trip[2], 0) - trip[0];
            timestamp.put(trip[2], endPassenger);
        }
        int usedCapacity = 0;
        for (int passengerChange : timestamp.values()) {
            usedCapacity += passengerChange;
            if (usedCapacity > capacity) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        timestamp = []
        for trip in trips:
            timestamp.append([trip[1], trip[0]])
            timestamp.append([trip[2], -trip[0]])

        timestamp.sort()

        used_capacity = 0
        for time, passenger_change in timestamp:
            used_capacity += passenger_change
            if used_capacity > capacity:
                return False

        return True
```

</details>

<br>

## Approach 2: Bucket Sort

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] timestamp = new int[1001];
        for (int[] trip : trips) {
            timestamp[trip[1]] += trip[0];
            timestamp[trip[2]] -= trip[0];
        }
        int usedCapacity = 0;
        for (int number : timestamp) {
            usedCapacity += number;
            if (usedCapacity > capacity) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        timestamp = [0] * 1001
        for trip in trips:
            timestamp[trip[1]] += trip[0]
            timestamp[trip[2]] -= trip[0]

        used_capacity = 0
        for passenger_change in timestamp:
            used_capacity += passenger_change
            if used_capacity > capacity:
                return False

        return True
```

</details>
