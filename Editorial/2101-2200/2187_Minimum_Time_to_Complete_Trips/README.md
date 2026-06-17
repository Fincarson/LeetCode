# 2187. Minimum Time to Complete Trips

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-time-to-complete-trips/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 2187 - Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips/)

## Problem

You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

### Example 1

```text
Input: time = [1,2,3], totalTrips = 5
Output: 3
Explanation:
- At time t = 1, the number of trips completed by each bus are [1,0,0].
  The total number of trips completed is 1 + 0 + 0 = 1.
- At time t = 2, the number of trips completed by each bus are [2,1,0].
  The total number of trips completed is 2 + 1 + 0 = 3.
- At time t = 3, the number of trips completed by each bus are [3,1,1].
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.
```

### Example 2

```text
Input: time = [2], totalTrips = 1
Output: 2
Explanation:
There is only one bus, and it will complete its first trip at t = 2.
So the minimum time needed to complete 1 trip is 2.
```

## Constraints

- 1 <= time.length <= 105
- 1 <= time[i], totalTrips <= 107

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Speed to Arrive on Time](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimize Maximum of Array](https://leetcode.com/problems/minimize-maximum-of-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Amount of Damage Dealt to Bob](https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2187. Minimum Time to Complete Trips

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search | C++, Java, Python3 |

## Approach: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Can these buses finish 'totalTrips' of trips in 'givenTime'?
    bool timeEnough(vector<int>& time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        for (int t : time) {
            actualTrips += givenTime / t;
        }
        return actualTrips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // Initialize the left and right boundaries.
        long long left = 1, right = 1LL * *max_element(time.begin(), time.end()) * totalTrips;

        // Binary search to find the minimum time to finish the task.
        while (left < right) {
            long long mid = (left + right) / 2;
            if (timeEnough(time, mid, totalTrips)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Can these buses finish 'totalTrips' of trips in 'givenTime'? 
    public boolean timeEnough(int[] time, long givenTime, int totalTrips) {
        long actualTrips = 0;
        for (int t : time) 
            actualTrips += givenTime / t;
        return actualTrips >= totalTrips;
    }
    
    public long minimumTime(int[] time, int totalTrips) {
        // Initialize the left and right boundaries.
        int max_time = 0;
        for (int t : time) {
            max_time = Math.max(max_time, t);
        }
        long left = 1, right = (long) max_time * totalTrips;

        // Binary search to find the minimum time to finish the task.
        while (left < right) {
            long mid = (left + right) / 2;
            if (timeEnough(time, mid, totalTrips)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        # Initialize the left and right boundaries.
        left, right = 1, max(time) * totalTrips

        # Can these buses finish 'totalTrips' of trips in 'given_time'?
        def timeEnough(given_time):
            actual_trips = 0
            for t in time:
                actual_trips += given_time // t
            return actual_trips >= totalTrips
        
        # Binary search to find the minimum time to finish the task.
        while left < right:
            mid = (left + right) // 2
            if timeEnough(mid):
                right = mid
            else:
                left = mid + 1
        return left
```

</details>
