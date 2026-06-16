# 2061. Number of Spaces Cleaning Robot Cleaned

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-spaces-cleaning-robot-cleaned/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 2061 - Number of Spaces Cleaning Robot Cleaned](https://leetcode.com/problems/number-of-spaces-cleaning-robot-cleaned/)

## Problem

A room is represented by a 0-indexed 2D binary matrix room where a 0 represents an empty space and a 1 represents a space with an object. The top left corner of the room will be empty in all test cases.

A cleaning robot starts at the top left corner of the room and is facing right. The robot will continue heading straight until it reaches the edge of the room or it hits an object, after which it will turn 90 degrees clockwise and repeat this process. The starting space and all spaces that the robot visits are cleaned by it.

Return the number of clean spaces in the room if the robot runs indefinitely.

### Example 1

### Example 2

### Example 3

## Constraints

- m == room.length
- n == room[r].length
- 1 <= m, n <= 300
- room[r][c] is either 0 or 1.
- room[0][0] == 0

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Robot Room Cleaner](https://leetcode.com/problems/robot-room-cleaner/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2061. Number of Spaces Cleaning Robot Cleaned

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Simulation | C++, Java, Python3 |
| Iterative Simulation | C++, Java, Python3 |

## Approach 1: Recursive Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int rows = room.size();
        int cols = room[0].size();
        unordered_set<string> visited;
        unordered_set<string> cleaned;
        return clean(room, rows, cols, 0, 0, 0, visited, cleaned);
    }

private:
    const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};
    int clean(vector<vector<int>>& room, int rows, int cols, int row, int col,
              int direction, unordered_set<string> visited,
              unordered_set<string> cleaned) {
        // If the robot already visited this space facing this direction
        // Return the number of spaces cleaned
        if (visited.find(to_string(row) + to_string(col) +
                         to_string(direction)) != visited.end()) {
            return cleaned.size();
        }

        // Mark the space as visited facing this direction and cleaned
        visited.insert(to_string(row) + to_string(col) + to_string(direction));
        cleaned.insert(to_string(row) + to_string(col));

        // Clean the next space straight ahead if it's empty and in the room
        int nextRow = row + DIRECTIONS[direction];
        int nextCol = col + DIRECTIONS[direction + 1];
        if (0 <= nextRow && nextRow < rows && 0 <= nextCol && nextCol < cols &&
            room[nextRow][nextCol] == 0) {
            return clean(room, rows, cols, nextRow, nextCol, direction, visited,
                         cleaned);
        }

        // Otherwise turn right and clean the current space
        return clean(room, rows, cols, row, col, (direction + 1) % 4, visited,
                     cleaned);
    };
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private final int[] DIRECTIONS = { 0, 1, 0, -1, 0 };

    public int numberOfCleanRooms(int[][] room) {
        int rows = room.length;
        int cols = room[0].length;
        Set<String> visited = new HashSet<>();
        Set<String> cleaned = new HashSet<>();
        return clean(room, rows, cols, 0, 0, 0, visited, cleaned);
    }

    private int clean(
        int[][] room,
        int rows,
        int cols,
        int row,
        int col,
        int direction,
        Set<String> visited,
        Set<String> cleaned
    ) {
        // If the robot already visited this space facing this direction
        // Return the number of spaces cleaned
        if (visited.contains(row + "," + col + "," + direction)) {
            return cleaned.size();
        }

        // Mark the space as visited facing this direction and cleaned
        visited.add(row + "," + col + "," + direction);
        cleaned.add(row + "," + col);

        // Clean the next space straight ahead if it's empty and in the room
        int nextRow = row + DIRECTIONS[direction];
        int nextCol = col + DIRECTIONS[direction + 1];
        if (
            0 <= nextRow &&
            nextRow < rows &&
            0 <= nextCol &&
            nextCol < cols &&
            room[nextRow][nextCol] == 0
        ) {
            return clean(
                room,
                rows,
                cols,
                nextRow,
                nextCol,
                direction,
                visited,
                cleaned
            );
        }

        // Otherwise turn right and clean the current space
        return clean(
            room,
            rows,
            cols,
            row,
            col,
            (direction + 1) % 4,
            visited,
            cleaned
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        DIRECTIONS = (0, 1, 0, -1, 0)
        rows, cols = len(room), len(room[0])
        visited = set()
        cleaned = set()

        def clean(row, col, direction):
            # If the robot already visited this space facing this direction
            # Return the number of spaces cleaned
            if (row, col, direction) in visited:
                return len(cleaned)

            # Mark the space as visited facing this direction and cleaned
            visited.add((row, col, direction))
            cleaned.add((row, col))

            # Clean the next space straight ahead if it's empty and in the room
            next_row = row + DIRECTIONS[direction]
            next_col = col + DIRECTIONS[direction + 1]
            if (
                0 <= next_row < rows
                and 0 <= next_col < cols
                and not room[next_row][next_col]
            ):
                return clean(next_row, next_col, direction)

            # Otherwise turn right and clean the current space
            return clean(row, col, (direction + 1) % 4)

        return clean(0, 0, 0)
```

</details>

<br>

## Approach 2: Iterative Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int rows = room.size();
        int cols = room[0].size();
        int cleaned = 0;

        int row = 0, col = 0;
        int direction = 0;

        // Clean until we revisit a space facing the same direction
        while (!(room[row][col] >> (direction + 1) & 1)) {
            // If the robot hasn't cleaned this space yet, increment cleaned
            if (room[row][col] == 0) {
                cleaned += 1;
            }

            // Mark the space as visited facing this direction
            room[row][col] |= 1 << (direction + 1);

            // Clean the next space straight ahead if it's empty and in the room
            int nextRow = row + DIRECTIONS[direction];
            int nextCol = col + DIRECTIONS[direction + 1];
            if (0 <= nextRow && nextRow < rows && 0 <= nextCol &&
                nextCol < cols && room[nextRow][nextCol] != 1) {
                row = nextRow;
                col = nextCol;
            } else {
                // Otherwise turn right and clean the current space
                direction = (direction + 1) % 4;
            }
        }
        return cleaned;
    }

private:
    const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int[] DIRECTIONS = { 0, 1, 0, -1, 0 };

    public int numberOfCleanRooms(int[][] room) {
        int rows = room.length;
        int cols = room[0].length;
        int cleaned = 0;

        int row = 0, col = 0;
        int direction = 0;

        // Clean until we revisit a space facing the same direction
        while (((room[row][col] >> (direction + 1)) & 1) == 0) {
            // If the robot hasn't cleaned this space yet, increment cleaned
            if (room[row][col] == 0) {
                cleaned += 1;
            }

            // Mark the space as visited facing this direction
            room[row][col] |= 1 << (direction + 1);

            // Clean the next space straight ahead if it's empty and in the room
            int nextRow = row + DIRECTIONS[direction];
            int nextCol = col + DIRECTIONS[direction + 1];
            if (
                0 <= nextRow &&
                nextRow < rows &&
                0 <= nextCol &&
                nextCol < cols &&
                room[nextRow][nextCol] != 1
            ) {
                row = nextRow;
                col = nextCol;
            } else {
                // Otherwise turn right and clean the current space
                direction = (direction + 1) % 4;
            }
        }
        return cleaned;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        DIRECTIONS = (0, 1, 0, -1, 0)
        rows, cols = len(room), len(room[0])
        cleaned = 0

        row, col = 0, 0
        direction = 0

        # Clean until we revisit a space facing the same direction
        while not room[row][col] >> (direction + 1) & 1:
            # If the robot hasn't cleaned this space yet, increment cleaned
            if room[row][col] == 0:
                cleaned += 1

            # Mark the space as visited facing this direction
            room[row][col] |= 1 << (direction + 1)

            # Clean the next space straight ahead if it's empty and in the room
            next_row = row + DIRECTIONS[direction]
            next_col = col + DIRECTIONS[direction + 1]
            if (
                0 <= next_row < rows
                and 0 <= next_col < cols
                and room[next_row][next_col] != 1
            ):
                row = next_row
                col = next_col

            # Otherwise turn right and clean the current space
            else:
                direction = (direction + 1) % 4

        return cleaned
```

</details>
