# 1942. The Number of the Smallest Unoccupied Chair

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/)  
`Array` `Hash Table` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1942 - The Number of the Smallest Unoccupied Chair](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/)

## Problem

There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

- For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.

When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.

### Example 1

```text
Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation:
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.
```

### Example 2

```text
Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation:
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.
```

## Constraints

- n == times.length
- 2 <= n <= 104
- times[i].length == 2
- 1 <= arrivali < leavingi <= 105
- 0 <= targetFriend <= n - 1
- Each arrivali time is distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1942. The Number of the Smallest Unoccupied Chair

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Event-based with Two Priority Queues | C++, Java, Python3 |
| Set with Sorted Insertion | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> targetTime = times[targetFriend];
        sort(times.begin(), times.end());

        int n = times.size();
        vector<int> chairTime(n);

        for (auto time : times) {
            for (int i = 0; i < n; i++) {
                if (chairTime[i] <= time[0]) {
                    chairTime[i] = time[1];
                    if (time == targetTime) return i;
                    break;
                }
            }
        }
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int smallestChair(int[][] times, int targetFriend) {
        int[] targetTime = times[targetFriend];
        Arrays.sort(times, (a, b) -> Integer.compare(a[0], b[0]));

        int n = times.length;
        int[] chairTime = new int[n];

        for (int[] time : times) {
            for (int i = 0; i < n; i++) {
                if (chairTime[i] <= time[0]) {
                    chairTime[i] = time[1];
                    if (Arrays.equals(time, targetTime)) return i;
                    break;
                }
            }
        }
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        target_time = times[targetFriend]
        times.sort()

        n = len(times)
        chair_time = [0] * n

        for time in times:
            for i in range(n):
                if chair_time[i] <= time[0]:
                    chair_time[i] = time[1]
                    if time == target_time:
                        return i
                    break
        return 0
```

</details>

<br>

## Approach 2: Event-based with Two Priority Queues

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>>
            events;  // To store both arrival and leave events

        // Populate events with {arrival, friendIndex} and {leave, -friendIndex}
        for (int i = 0; i < n; i++) {
            events.push_back({times[i][0], i});   // Friend arrives
            events.push_back({times[i][1], ~i});  // Friend leaves
        }

        sort(events.begin(), events.end());  // Sort events by time

        priority_queue<int, vector<int>, greater<int>>
            availableChairs;  // Min-heap for available chairs
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            occupiedChairs;  // Min-heap to track when chairs will be vacated

        for (int i = 0; i < n; i++)
            availableChairs.push(i);  // Initially all chairs are free

        for (auto& event : events) {
            int time = event.first;
            int friendIndex = event.second;

            // Free up chairs when friends leave
            while (!occupiedChairs.empty() &&
                   occupiedChairs.top().first <= time) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            if (friendIndex >= 0) {  // Friend arrives
                int chair = availableChairs.top();
                availableChairs.pop();
                if (friendIndex == targetFriend) return chair;
                occupiedChairs.push(
                    {times[friendIndex][1],
                     chair});  // Mark when the chair will be vacated
            }
        }

        return -1;  // Should never reach here
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int smallestChair(int[][] times, int targetFriend) {
        List<int[]> events = new ArrayList<>(); // To store both arrival and leave events

        // Populate events with {arrival, friendIndex} and {leave, -friendIndex}
        for (int i = 0; i < times.length; i++) {
            events.add(new int[] { times[i][0], i }); // Friend arrives
            events.add(new int[] { times[i][1], ~i }); // Friend leaves
        }

        Collections.sort(events, (a, b) -> a[0] - b[0]); // Sort events by time

        PriorityQueue<Integer> availableChairs = new PriorityQueue<>(); // Min-heap for available chairs
        PriorityQueue<int[]> occupiedChairs = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        ); // Min-heap to track when chairs will be vacated

        for (int i = 0; i < times.length; i++) {
            availableChairs.add(i); // Initially all chairs are free
        }

        for (int[] event : events) {
            int time = event[0];
            int friendIndex = event[1];

            // Free up chairs when friends leave
            while (
                !occupiedChairs.isEmpty() && occupiedChairs.peek()[0] <= time
            ) {
                availableChairs.add(occupiedChairs.poll()[1]);
            }
            if (friendIndex >= 0) { // Friend arrives
                int chair = availableChairs.poll();
                if (friendIndex == targetFriend) {
                    return chair;
                }
                occupiedChairs.add(new int[] { times[friendIndex][1], chair }); // Mark when the chair will be vacated
            }
        }

        return -1; // Should never reach here
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestChair(self, times, targetFriend):
        events = []  # to store both arrival and leave events

        # populate events with arrival and leave times
        for i in range(len(times)):
            events.append([times[i][0], i])  # Arrival
            events.append([times[i][1], ~i])  # Leave

        events.sort()  # Sort events by time

        available_chairs = list(
            range(len(times))
        )  # Tracking chairs that are free

        occupied_chairs = []  # When each chair will be free

        for event in events:
            time, friend = event

            # free up chairs if friends leave
            while occupied_chairs and occupied_chairs[0][0] <= time:
                _, chair = heapq.heappop(
                    occupied_chairs
                )  # Pop chair that becomes empty
                heapq.heappush(available_chairs, chair)  # available chairs

            # If friend arrives
            if friend >= 0:
                chair = heapq.heappop(available_chairs)
                if friend == targetFriend:
                    return chair
                heapq.heappush(
                    occupied_chairs, [times[friend][1], chair]
                )  # chair will be occupied till this time

        return -1  # should not come to this point
```

</details>

<br>

## Approach 3: Set with Sorted Insertion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            leavingQueue;
        int targetArrival = times[targetFriend][0];

        sort(times.begin(), times.end());

        int nextChair = 0;  // Track next available chair number
        set<int> availableChairs;

        for (auto time : times) {
            int arrival = time[0];
            int leave = time[1];

            // Free up chairs based on current time
            while (!leavingQueue.empty() &&
                   leavingQueue.top().first <= arrival) {
                availableChairs.insert(leavingQueue.top().second);
                leavingQueue.pop();
            }

            int currentChair;
            // Assign chair from available set or increment new chair
            if (!availableChairs.empty()) {
                currentChair = *availableChairs.begin();
                availableChairs.erase(availableChairs.begin());
            } else {
                currentChair = nextChair++;
            }

            // Push current leave time and chair
            leavingQueue.push({leave, currentChair});

            // Check if it's the target friend
            if (arrival == targetArrival) return currentChair;
        }

        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int smallestChair(int[][] times, int targetFriend) {
        int targetArrival = times[targetFriend][0];
        Arrays.sort(times, (a, b) -> a[0] - b[0]);

        int nextChair = 0;
        PriorityQueue<int[]> leavingQueue = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );
        TreeSet<Integer> availableChairs = new TreeSet<>();

        for (int[] time : times) {
            int arrival = time[0];
            int leave = time[1];

            // Free up chairs based on current time
            while (
                !leavingQueue.isEmpty() && leavingQueue.peek()[0] <= arrival
            ) {
                availableChairs.add(leavingQueue.poll()[1]);
            }

            int currentChair;
            // Assign chair from available set or increment new chair
            if (!availableChairs.isEmpty()) {
                currentChair = availableChairs.first();
                availableChairs.remove(currentChair);
            } else {
                currentChair = nextChair++;
            }

            // Push current leave time and chair
            leavingQueue.offer(new int[] { leave, currentChair });

            // Check if it's the target friend
            if (arrival == targetArrival) return currentChair;
        }

        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        target_arrival = times[targetFriend][0]
        times = sorted(
            [
                (arrival, leave, index)
                for index, (arrival, leave) in enumerate(times)
            ]
        )

        next_chair = 0
        available_chairs = []
        leaving_queue = []

        for time in times:
            arrival, leave, index = time

            # Free up chairs based on current time
            while leaving_queue and leaving_queue[0][0] <= arrival:
                _, chair = heapq.heappop(leaving_queue)
                heapq.heappush(available_chairs, chair)

            if available_chairs:
                current_chair = heapq.heappop(available_chairs)
            else:
                current_chair = next_chair
                next_chair += 1

            # Push current leave time and chair
            heapq.heappush(leaving_queue, (leave, current_chair))

            # Check if it's the target friend
            if index == targetFriend:
                return current_chair

        return 0
```

</details>
