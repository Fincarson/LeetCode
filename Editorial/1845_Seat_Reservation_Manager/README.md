# 1845. Seat Reservation Manager

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/seat-reservation-manager/)  
`Design` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1845 - Seat Reservation Manager](https://leetcode.com/problems/seat-reservation-manager/)

## Problem

Design a system that manages the reservation state of n seats that are numbered from 1 to n.

Implement the SeatManager class:

- SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. All seats are initially available.
- int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
- void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.

### Example 1

```text
Input
["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]
[[5], [], [], [2], [], [], [], [], [5]]
Output
[null, 1, 2, null, 2, 3, 4, 5, null]

Explanation
SeatManager seatManager = new SeatManager(5); // Initializes a SeatManager with 5 seats.
seatManager.reserve();    // All seats are available, so return the lowest numbered seat, which is 1.
seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
seatManager.unreserve(2); // Unreserve seat 2, so now the available seats are [2,3,4,5].
seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
seatManager.reserve();    // The available seats are [3,4,5], so return the lowest of them, which is 3.
seatManager.reserve();    // The available seats are [4,5], so return the lowest of them, which is 4.
seatManager.reserve();    // The only available seat is seat 5, so return 5.
seatManager.unreserve(5); // Unreserve seat 5, so now the available seats are [5].
```

## Constraints

- 1 <= n <= 105
- 1 <= seatNumber <= n
- For each call to reserve, it is guaranteed that there will be at least one unreserved seat.
- For each call to unreserve, it is guaranteed that seatNumber will be reserved.
- At most 105 calls in total will be made to reserve and unreserve.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Design Phone Directory](https://leetcode.com/problems/design-phone-directory/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Design a Number Container System](https://leetcode.com/problems/design-a-number-container-system/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1845. Seat Reservation Manager

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Min Heap | C++, Java, Python3 |
| Min Heap (without pre-initialization) | C++, Java, Python3 |
| Sorted/Ordered Set | C++, Java, Python3 |

## Approach 1: Min Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class SeatManager {
    // Min heap to store all unreserved seats.
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager(int n) {
        // Initially all seats are unreserved.
        for (int seatNumber = 1; seatNumber <= n; ++seatNumber) {
            availableSeats.push(seatNumber);
        }
    }

    int reserve() {
        // Get the smallest-numbered unreserved seat from the min heap.
        int seatNumber = availableSeats.top();
        availableSeats.pop();
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        // Push the unreserved seat in the min heap.
        availableSeats.push(seatNumber);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class SeatManager {
    // Min heap to store all unreserved seats.
    private PriorityQueue<Integer> availableSeats;

    public SeatManager(int n) {
        // Initially all seats are unreserved.
        availableSeats = new PriorityQueue<>();
        for (int seatNumber = 1; seatNumber <= n; ++seatNumber) {
            availableSeats.offer(seatNumber);
        }
    }

    public int reserve() {
        // Get the smallest-numbered unreserved seat from the min heap.
        int seatNumber = availableSeats.poll();
        return seatNumber;
    }

    public void unreserve(int seatNumber) {
        // Push the unreserved seat back into the min heap.
        availableSeats.offer(seatNumber);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class SeatManager:
    def __init__(self, n):
        # Min heap to store all unreserved seats.
        self.available_seats = [i for i in range(1, n + 1)]

    def reserve(self):
        # Get the smallest-numbered unreserved seat from the min heap.
        seat_number = heapq.heappop(self.available_seats)
        return seat_number

    def unreserve(self, seat_number):
        # Push the unreserved seat back into the min heap.
        heapq.heappush(self.available_seats, seat_number)
```

</details>

<br>

## Approach 2: Min Heap (without pre-initialization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class SeatManager {
    // Marker to point to unreserved seats.
    int marker;

    // Min heap to store all unreserved seats.
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager(int n) {
        // Set marker to the first unreserved seat.
        marker = 1;
    }

    int reserve() {
        // If min-heap has any element in it, then,
        // get the smallest-numbered unreserved seat from the min heap.
        if (!availableSeats.empty()) {
            int seatNumber = availableSeats.top();
            availableSeats.pop();
            return seatNumber;
        }

        // Otherwise, the marker points to the smallest-numbered seat.
        int seatNumber = marker;
        marker++;
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        // Push unreserved seat in the min heap.
        availableSeats.push(seatNumber);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class SeatManager {
    // Marker to point to unreserved seats.
    int marker;

    // Min heap to store all unreserved seats.
    PriorityQueue<Integer> availableSeats;

    public SeatManager(int n) {
        // Set marker to the first unreserved seat.
        marker = 1;
        // Initialize the min heap.
        availableSeats = new PriorityQueue<>();
    }

    public int reserve() {
        // If min-heap has any element in it, then,
        // get the smallest-numbered unreserved seat from the min heap.
        if (!availableSeats.isEmpty()) {
            int seatNumber = availableSeats.poll();
            return seatNumber;
        }

        // Otherwise, the marker points to the smallest-numbered seat.
        int seatNumber = marker;
        marker++;
        return seatNumber;
    }

    public void unreserve(int seatNumber) {
        // Push unreserved seat in the min heap.
        availableSeats.offer(seatNumber);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class SeatManager:
    def __init__(self, n):
        # Set marker to the first unreserved seat.
        self.marker = 1

        # Min heap to store all unreserved seats.
        self.available_seats = []

    def reserve(self):
        # If min-heap has any element in it, then,
        # get the smallest-numbered unreserved seat from the min heap.
        if self.available_seats:
            seat_number = heapq.heappop(self.available_seats)
            return seat_number

        # Otherwise, the marker points to the smallest-numbered seat.
        seat_number = self.marker
        self.marker += 1
        return seat_number

    def unreserve(self, seat_number):
        # Push unreserved seat in the min heap.
        heapq.heappush(self.available_seats, seat_number)
```

</details>

<br>

## Approach 3: Sorted/Ordered Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class SeatManager {
    // Marker to point to unreserved seats.
    int marker;

    // Sorted set to store all unreserved seats.
    set<int> availableSeats;

public:
    SeatManager(int n) {
        // Set marker to the first unreserved seat.
        marker = 1;
    }

    int reserve() {
        // If the sorted set has any element in it, then,
        // get the smallest-numbered unreserved seat from it.
        if (!availableSeats.empty()) {
            int seatNumber = *availableSeats.begin();
            availableSeats.erase(availableSeats.begin());
            return seatNumber;
        }

        // Otherwise, the marker points to the smallest-numbered seat.
        int seatNumber = marker;
        marker++;
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        // Push unreserved seat in the sorted set.
        availableSeats.insert(seatNumber);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class SeatManager {
    // Marker to point to unreserved seats.
    int marker;

    // Sorted set to store all unreserved seats.
    TreeSet<Integer> availableSeats;

    public SeatManager(int n) {
        // Set marker to the first unreserved seat.
        marker = 1;
        // Initialize the sorted set.
        availableSeats = new TreeSet<>();
    }

    public int reserve() {
        // If the sorted set has any element in it, then,
        // get the smallest-numbered unreserved seat from it.
        if (!availableSeats.isEmpty()) {
            int seatNumber = availableSeats.first();
            availableSeats.remove(seatNumber);
            return seatNumber;
        }

        // Otherwise, the marker points to the smallest-numbered seat.
        int seatNumber = marker;
        marker++;
        return seatNumber;
    }

    public void unreserve(int seatNumber) {
        // Push the unreserved seat in the sorted set.
        availableSeats.add(seatNumber);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedSet

class SeatManager:
    def __init__(self, n):
        # Set marker to the first unreserved seat.
        self.marker = 1

        # Sorted set to store all unreserved seats.
        self.available_seats = SortedSet()

    def reserve(self):
        # If the sorted set has any element in it, then,
        # get the smallest-numbered unreserved seat from it.
        if self.available_seats:
            seat_number = self.available_seats.pop(0)
            return seat_number

        # Otherwise, the marker points to the smallest-numbered seat.
        seat_number = self.marker
        self.marker += 1
        return seat_number
        

    def unreserve(self, seat_number):
        # Push the unreserved seat in the sorted set.
        self.available_seats.add(seat_number)
```

</details>
