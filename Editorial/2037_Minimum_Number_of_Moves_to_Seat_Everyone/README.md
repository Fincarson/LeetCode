# 2037. Minimum Number of Moves to Seat Everyone

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/)  
`Array` `Greedy` `Sorting` `Counting Sort`

**Problem Link:** [LeetCode 2037 - Minimum Number of Moves to Seat Everyone](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/)

## Problem

There are n availabe seats and n students standing in a room. You are given an array seats of length n, where seats[i] is the position of the ith seat. You are also given the array students of length n, where students[j] is the position of the jth student.

You may perform the following move any number of times:

- Increase or decrease the position of the ith student by 1 (i.e., moving the ith student from position x to x + 1 or x - 1)

Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.

Note that there may be multiple seats or students in the same position at the beginning.

### Example 1

```text
Input: seats = [3,1,5], students = [2,7,4]
Output: 4
Explanation: The students are moved as follows:
- The first student is moved from position 2 to position 1 using 1 move.
- The second student is moved from position 7 to position 5 using 2 moves.
- The third student is moved from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.
```

### Example 2

```text
Input: seats = [4,1,5,9], students = [1,3,2,6]
Output: 7
Explanation: The students are moved as follows:
- The first student is not moved.
- The second student is moved from position 3 to position 4 using 1 move.
- The third student is moved from position 2 to position 5 using 3 moves.
- The fourth student is moved from position 6 to position 9 using 3 moves.
In total, 0 + 1 + 3 + 3 = 7 moves were used.
```

### Example 3

```text
Input: seats = [2,2,6,6], students = [1,3,2,6]
Output: 4
Explanation: Note that there are two seats at position 2 and two seats at position 6.
The students are moved as follows:
- The first student is moved from position 1 to position 2 using 1 move.
- The second student is moved from position 3 to position 6 using 3 moves.
- The third student is not moved.
- The fourth student is not moved.
In total, 1 + 3 + 0 + 0 = 4 moves were used.
```

## Constraints

- n == seats.length == students.length
- 1 <= n <= 100
- 1 <= seats[i], students[j] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2037. Minimum Number of Moves to Seat Everyone

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting (Greedy) | C++, Java, Python3 |
| Counting Sort | C++, Java, Python3 |

## Approach 1: Sorting (Greedy)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves = 0;
        for (int i = 0; i < seats.size(); i++) {
            // Add the absolute value of the difference
            // between the position of the seat and the student
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int moves = 0;
        for (int i = 0; i < seats.length; i++) {
            // Add the absolute value of the difference
            // between the position of the seat and the student
            moves += Math.abs(seats[i] - students[i]);
        }
        return moves;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        students.sort()
        seats.sort()
        moves = 0
        for i in range(0, len(seats)):
            # Add the absolute value of the difference
            # between the position of the seat and the student
            moves += abs(seats[i] - students[i])
        return moves
```

</details>

<br>

## Approach 2: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Find the maximum position in the arrays
        int maxPosition = max(findMax(seats), findMax(students));

        // Stores difference between number of seats and students at each
        // position
        vector<int> differences(maxPosition, 0);

        // Count the available seats at each position
        for (int position : seats) {
            differences[position - 1]++;
        }

        // Remove a seat for each student at that position
        for (int position : students) {
            differences[position - 1]--;
        }

        // Calculate the number of moves needed to seat the students
        int moves = 0;
        int unmatched = 0;
        for (int difference : differences) {
            moves += abs(unmatched);
            unmatched += difference;
        }

        return moves;
    }

private:
    int findMax(const vector<int>& array) {
        int maximum = 0;
        for (int num : array) {
            if (num > maximum) {
                maximum = num;
            }
        }
        return maximum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minMovesToSeat(int[] seats, int[] students) {
        // Find the maximum position in the arrays
        int maxPosition = Math.max(findMax(seats), findMax(students));

        // Stores difference between number of seats and students at each position
        int[] differences = new int[maxPosition];

        // Count the available seats at each position
        for (int position : seats) {
            differences[position - 1]++;
        }

        // Remove a seat for each student at that position
        for (int position : students) {
            differences[position - 1]--;
        }

        // Calculate the number of moves needed to seat the students
        int moves = 0;
        int unmatched = 0;
        for (int difference : differences) {
            moves += Math.abs(unmatched);
            unmatched += difference;
        }

        return moves;
    }

    private int findMax(int[] array) {
        int maximum = 0;
        for (int num : array) {
            if (num > maximum) {
                maximum = num;
            }
        }
        return maximum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        # Find the maximum position in the arrays
        max_position = max(max(seats), max(students))

        # Stores difference between number of seats and students at each position
        differences = [0] * (max_position)

        # Count the available seats at each position
        for position in seats:
            differences[position - 1] += 1

        # Remove a seat for each student at that position
        for position in students:
            differences[position - 1] -= 1

        # Caculate the number of moves needed to seat the students
        moves = 0
        unmatched = 0
        for difference in differences:
            moves += abs(unmatched)
            unmatched += difference

        return moves
```

</details>
