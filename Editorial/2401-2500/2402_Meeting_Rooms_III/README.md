# 2402. Meeting Rooms III

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/meeting-rooms-iii/)  
`Array` `Hash Table` `Sorting` `Heap (Priority Queue)` `Simulation`

**Problem Link:** [LeetCode 2402 - Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii/)

## Problem

You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

### Example 1

```text
Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0.
```

### Example 2

```text
Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1.
```

## Constraints

- 1 <= n <= 100
- 1 <= meetings.length <= 105
- meetings[i].length == 2
- 0 <= starti < endi <= 5 * 105
- All the values of starti are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Servers That Handled Most Number of Requests](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Number of Events That Can Be Attended II](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2402. Meeting Rooms III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting and Counting | C++, Java, Python3 |
| Sorting, Counting using Priority Queues | C++, Java, Python3 |

## Approach 1: Sorting and Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> roomAvailabilityTime(n, 0);
        vector<int> meetingCount(n, 0);
        sort(meetings.begin(), meetings.end());

        for (auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            long long minRoomAvailabilityTime = LLONG_MAX;
            int minAvailableTimeRoom = 0;
            bool foundUnusedRoom = false;

            for (int i = 0; i < n; i++) {
                if (roomAvailabilityTime[i] <= start) {
                    foundUnusedRoom = true;
                    meetingCount[i]++;
                    roomAvailabilityTime[i] = end;
                    break;
                }

                if (minRoomAvailabilityTime > roomAvailabilityTime[i]) {
                    minRoomAvailabilityTime = roomAvailabilityTime[i];
                    minAvailableTimeRoom = i;
                }
            }

            if (!foundUnusedRoom) {
                roomAvailabilityTime[minAvailableTimeRoom] += end - start;
                meetingCount[minAvailableTimeRoom]++;
            }
        }
        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int mostBooked(int n, int[][] meetings) {
        long[] roomAvailabilityTime = new long[n];
        int[] meetingCount = new int[n];
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));

        for (int[] meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            long minRoomAvailabilityTime = Long.MAX_VALUE;
            int minAvailableTimeRoom = 0;
            boolean foundUnusedRoom = false;

            for (int i = 0; i < n; i++) {
                if (roomAvailabilityTime[i] <= start) {
                    foundUnusedRoom = true;
                    meetingCount[i]++;
                    roomAvailabilityTime[i] = end;
                    break;
                }

                if (minRoomAvailabilityTime > roomAvailabilityTime[i]) {
                    minRoomAvailabilityTime = roomAvailabilityTime[i];
                    minAvailableTimeRoom = i;
                }
            }

            if (!foundUnusedRoom) {
                roomAvailabilityTime[minAvailableTimeRoom] += end - start;
                meetingCount[minAvailableTimeRoom]++;
            }
        }

        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }

        return maxMeetingCountRoom;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        room_availability_time = [0] * n
        meeting_count = [0] * n
        for start, end in sorted(meetings):
            min_room_availability_time = inf
            min_available_time_room = 0
            found_unused_room = False
            for i in range(n):
                if room_availability_time[i] <= start:
                    found_unused_room = True
                    meeting_count[i] += 1
                    room_availability_time[i] = end
                    break
                if min_room_availability_time > room_availability_time[i]:
                    min_room_availability_time = room_availability_time[i]
                    min_available_time_room = i
            if not found_unused_room:
                room_availability_time[min_available_time_room] += end - start
                meeting_count[min_available_time_room] += 1

        return meeting_count.index(max(meeting_count))
```

</details>

<br>

## Approach 2: Sorting, Counting using Priority Queues

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meetingCount(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        for (int i = 0; i < n; i++) {
            unusedRooms.push(i);
        }
        sort(meetings.begin(), meetings.end());

        for (auto meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }
            if (!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, room});
                meetingCount[room]++;
            } else {
                auto [roomAvailabilityTime, room] = usedRooms.top();
                usedRooms.pop();
                usedRooms.push({roomAvailabilityTime + end - start, room});
                meetingCount[room]++;
            }
        }

        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int mostBooked(int n, int[][] meetings) {
        var meetingCount = new int[n];
        var usedRooms = new PriorityQueue<long[]>((a, b) -> a[0] != b[0] ? Long.compare(a[0], b[0]) : Long.compare(a[1], b[1]));
        var unusedRooms = new PriorityQueue<Integer>();

        for (int i = 0; i < n; i++) {
            unusedRooms.offer(i);
        }

        Arrays.sort(meetings, (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1]));

        for (int[] meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!usedRooms.isEmpty() && usedRooms.peek()[0] <= start) {
                int room = (int) usedRooms.poll()[1];
                unusedRooms.offer(room);
            }

            if (!unusedRooms.isEmpty()) {
                int room = unusedRooms.poll();
                usedRooms.offer(new long[]{end, room});
                meetingCount[room]++;
            } else {
                long roomAvailabilityTime = usedRooms.peek()[0];
                int room = (int) usedRooms.poll()[1];
                usedRooms.offer(new long[]{roomAvailabilityTime + end - start, room});
                meetingCount[room]++;
            }
        }

        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }

        return maxMeetingCountRoom;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        unused_rooms, used_rooms = list(range(n)), []
        heapify(unused_rooms)
        meeting_count = [0] * n
        for start, end in sorted(meetings):
            while used_rooms and used_rooms[0][0] <= start:
                _, room = heappop(used_rooms)
                heappush(unused_rooms, room)
            if unused_rooms:
                room = heappop(unused_rooms)
                heappush(used_rooms, [end, room])
            else:
                room_availability_time, room = heappop(used_rooms)
                heappush(
                    used_rooms,
                    [room_availability_time + end - start, room]
                )
            meeting_count[room] += 1
        return meeting_count.index(max(meeting_count))
```

</details>
