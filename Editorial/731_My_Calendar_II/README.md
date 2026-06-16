# 731. My Calendar II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/my-calendar-ii/)  
`Array` `Binary Search` `Design` `Segment Tree` `Prefix Sum` `Ordered Set`

**Problem Link:** [LeetCode 731 - My Calendar II](https://leetcode.com/problems/my-calendar-ii/)

## Problem

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers startTime and endTime that represents a booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.

Implement the MyCalendarTwo class:

- MyCalendarTwo() Initializes the calendar object.
- boolean book(int startTime, int endTime) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

### Example 1

```text
Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]

Explanation
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked.
myCalendarTwo.book(50, 60); // return True, The event can be booked.
myCalendarTwo.book(10, 40); // return True, The event can be double booked.
myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
```

## Constraints

- 0 <= start < end <= 109
- At most 1000 calls will be made to book.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [My Calendar I](https://leetcode.com/problems/my-calendar-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [My Calendar III](https://leetcode.com/problems/my-calendar-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 731. My Calendar II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Overlapped Intervals | C++, Java, Python3 |
| Line Sweep | C++, Java, Python3 |

## Approach 1: Using Overlapped Intervals

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlapBookings;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Returns false if the new booking overlaps with the existing
        // double-booked bookings.
        for (pair<int, int> booking : overlapBookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                return false;
            }
        }

        // Add the double overlapping if any with the new booking.
        for (pair<int, int> booking : bookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                overlapBookings.push_back(
                    getOverlapped(booking.first, booking.second, start, end));
            }
        }

        // Add the booking to the list of bookings.
        bookings.push_back({start, end});
        return true;
    }

private:
    // Return true if the booking [start1, end1) & [start2, end2) overlaps.
    bool doesOverlap(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }

    // Return overlapping booking between [start1, end1) & [start2, end2).
    pair<int, int> getOverlapped(int start1, int end1, int start2, int end2) {
        return {max(start1, start2), min(end1, end2)};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MyCalendarTwo {

    private List<int[]> bookings;
    private List<int[]> overlapBookings;

    // Return true if the booking [start1, end1) & [start2, end2) overlaps.
    private boolean doesOverlap(int start1, int end1, int start2, int end2) {
        return Math.max(start1, start2) < Math.min(end1, end2);
    }

    // Return overlapping booking between [start1, end1) & [start2, end2).
    private int[] getOverlapped(int start1, int end1, int start2, int end2) {
        return new int[] { Math.max(start1, start2), Math.min(end1, end2) };
    }

    public MyCalendarTwo() {
        bookings = new ArrayList<>();
        overlapBookings = new ArrayList<>();
    }

    public boolean book(int start, int end) {
        // Returns false if the new booking has an overlap
        // with the existing double-booked bookings.
        for (int[] booking : overlapBookings) {
            if (doesOverlap(booking[0], booking[1], start, end)) {
                return false;
            }
        }

        // Add the double overlapping bookings if any with the new booking.
        for (int[] booking : bookings) {
            if (doesOverlap(booking[0], booking[1], start, end)) {
                overlapBookings.add(
                    getOverlapped(booking[0], booking[1], start, end)
                );
            }
        }

        // Add the new booking to the list of bookings.
        bookings.add(new int[] { start, end });
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MyCalendarTwo:

    def __init__(self):
        self.bookings = []
        self.overlap_bookings = []

    def book(self, start: int, end: int) -> bool:
        # Check if the new booking overlaps with any double-booked booking.
        for booking in self.overlap_bookings:
            if self.does_overlap(booking[0], booking[1], start, end):
                return False

        # Add any new double overlaps that the current booking creates.
        for booking in self.bookings:
            if self.does_overlap(booking[0], booking[1], start, end):
                self.overlap_bookings.append(
                    self.get_overlapped(booking[0], booking[1], start, end)
                )

        # Add the new booking to the list of bookings.
        self.bookings.append((start, end))
        return True

    # Return True if the booking [start1, end1) & [start2, end2) overlaps.
    def does_overlap(
        self, start1: int, end1: int, start2: int, end2: int
    ) -> bool:
        return max(start1, start2) < min(end1, end2)

    # Return the overlapping booking between [start1, end1) & [start2, end2).
    def get_overlapped(
        self, start1: int, end1: int, start2: int, end2: int
    ) -> tuple:
        return max(start1, start2), min(end1, end2)
```

</details>

<br>

## Approach 2: Line Sweep

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MyCalendarTwo {
public:
    // Store the number of bookings at each point.
    map<int, int> bookingCount;
    // The maximum number of overlapped bookings allowed.
    int maxOverlappedBooking;

    MyCalendarTwo() { maxOverlappedBooking = 2; }

    bool book(int start, int end) {
        // Increase and decrease the booking count at the start and end
        // respectively.
        bookingCount[start]++;
        bookingCount[end]--;

        int overlappedBooking = 0;
        // Find the prefix sum.
        for (pair<int, int> bookings : bookingCount) {
            overlappedBooking += bookings.second;

            // If the number of bookings is more than 2, return false.
            // Also roll back the counts for this booking as we won't add it.
            if (overlappedBooking > maxOverlappedBooking) {
                bookingCount[start]--;
                bookingCount[end]++;

                // Remove the entries from the map to avoid unnecessary
                // iteration.
                if (bookingCount[start] == 0) {
                    bookingCount.erase(start);
                }
                if (bookingCount[end] == 0) {
                    bookingCount.erase(end);
                }

                return false;
            }
        }

        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MyCalendarTwo {

    private TreeMap<Integer, Integer> bookingCount;
    private int maxOverlappedBooking;

    public MyCalendarTwo() {
        bookingCount = new TreeMap<>();
        maxOverlappedBooking = 2;
    }

    public boolean book(int start, int end) {
        // Increase the booking count at 'start' and decrease at 'end'.
        bookingCount.put(start, bookingCount.getOrDefault(start, 0) + 1);
        bookingCount.put(end, bookingCount.getOrDefault(end, 0) - 1);

        int overlappedBooking = 0;

        // Calculate the prefix sum of bookings.
        for (Map.Entry<Integer, Integer> entry : bookingCount.entrySet()) {
            overlappedBooking += entry.getValue();

            // If the number of overlaps exceeds the allowed limit, rollback and
            // return false.
            if (overlappedBooking > maxOverlappedBooking) {
                // Rollback changes.
                bookingCount.put(start, bookingCount.get(start) - 1);
                bookingCount.put(end, bookingCount.get(end) + 1);

                // Clean up if the count becomes zero to maintain the map clean.
                if (bookingCount.get(start) == 0) {
                    bookingCount.remove(start);
                }

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
from sortedcontainers import SortedDict


class MyCalendarTwo:

    def __init__(self):
        # Store the number of bookings at each point.
        self.booking_count = SortedDict()
        # The maximum number of overlapped bookings allowed.
        self.max_overlapped_booking = 2

    def book(self, start: int, end: int) -> bool:
        # Increase and decrease the booking count at the start and end respectively.
        self.booking_count[start] = self.booking_count.get(start, 0) + 1
        self.booking_count[end] = self.booking_count.get(end, 0) - 1

        overlapped_booking = 0

        # Calculate the prefix sum of bookings.
        for count in self.booking_count.values():
            overlapped_booking += count
            # If the number of overlaps exceeds the allowed limit
            # rollback and return False.
            if overlapped_booking > self.max_overlapped_booking:
                # Rollback changes.
                self.booking_count[start] -= 1
                self.booking_count[end] += 1

                # Remove entries if their count becomes zero to clean up the SortedDict.
                if self.booking_count[start] == 0:
                    del self.booking_count[start]

                return False

        return True
```

</details>
