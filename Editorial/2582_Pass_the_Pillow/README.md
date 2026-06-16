# 2582. Pass the Pillow

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/pass-the-pillow/)  
`Math` `Simulation`

**Problem Link:** [LeetCode 2582 - Pass the Pillow](https://leetcode.com/problems/pass-the-pillow/)

## Problem

There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

- For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.

Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

### Example 1

```text
Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
After five seconds, the 2nd person is holding the pillow.
```

### Example 2

```text
Input: n = 3, time = 2
Output: 3
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
After two seconds, the 3rd person is holding the pillow.
```

## Constraints

- 2 <= n <= 1000
- 1 <= time <= 1000

Note: This question is the same as  3178: Find the Child Who Has the Ball After K Seconds.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find the Student that Will Replace the Chalk](https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2582. Pass the Pillow

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C++, Java, Python3 |
| Math | C++, Java, Python3 |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int passThePillow(int n, int time) {
        int currentPillowPosition = 1;
        int currentTime = 0;
        int direction = 1;
        while (currentTime < time) {
            if (0 < currentPillowPosition + direction &&
                currentPillowPosition + direction <= n) {
                currentPillowPosition += direction;
                currentTime++;
            } else {
                // Reverse the direction if the next position is out of bounds
                direction *= -1;
            }
        }
        return currentPillowPosition;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int passThePillow(int n, int time) {
        int currentPillowPosition = 1;
        int currentTime = 0;
        int direction = 1;
        while (currentTime < time) {
            if (
                0 < currentPillowPosition + direction &&
                currentPillowPosition + direction <= n
            ) {
                currentPillowPosition += direction;
                currentTime++;
            } else {
                // Reverse the direction if the next position is out of bounds
                direction *= -1;
            }
        }
        return currentPillowPosition;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        current_pillow_position = 1
        current_time = 0
        direction = 1
        while current_time < time:
            if 0 < current_pillow_position + direction <= n:
                current_pillow_position += direction
                current_time += 1
            else:
                # Reverse the direction if the next position is out of bounds
                direction *= -1
        return current_pillow_position
```

</details>

<br>

## Approach 2: Math

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int passThePillow(int n, int time) {
        // Calculate the number of complete rounds of pillow passing
        int fullRounds = time / (n - 1);

        // Calculate the remaining time after complete rounds
        int extraTime = time % (n - 1);

        // Determine the position of the person holding the pillow
        // If fullRounds is even, the pillow is moving forward.
        // If fullRounds is odd, the pillow is moving backward.
        if (fullRounds % 2 == 0) {
            return extraTime + 1;  // Position when moving forward
        } else {
            return n - extraTime;  // Position when moving backward
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int passThePillow(int n, int time) {
        // Calculate the number of complete rounds of pillow passing
        int fullRounds = time / (n - 1);

        // Calculate the remaining time after complete rounds
        int extraTime = time % (n - 1);

        // Determine the position of the person holding the pillow
        // If fullRounds is even, the pillow is moving forward.
        // If fullRounds is odd, the pillow is moving backward.
        if (fullRounds % 2 == 0) {
            return extraTime + 1; // Position when moving forward
        } else {
            return n - extraTime; // Position when moving backward
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def passThePillow(self, n, time):
        # Calculate the number of complete rounds of pillow passing
        full_rounds = time // (n - 1)

        # Calculate the remaining time after complete rounds
        extra_time = time % (n - 1)

        # Determine the position of the person holding the pillow
        # If full_rounds is even, the pillow is moving forward.
        # If full_rounds is odd, the pillow is moving backward.
        if full_rounds % 2 == 0:
            return extra_time + 1  # Position when moving forward
        else:
            return n - extra_time  # Position when moving backward
```

</details>
