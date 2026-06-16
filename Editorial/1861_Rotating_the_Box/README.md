# 1861. Rotating the Box

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/rotating-the-box/)  
`Array` `Two Pointers` `Matrix`

**Problem Link:** [LeetCode 1861 - Rotating the Box](https://leetcode.com/problems/rotating-the-box/)

## Problem

You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:

- A stone '#'
- A stationary obstacle '*'
- Empty '.'

The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

### Example 1

```text
Input: boxGrid = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
```

### Example 2

```text
Input: boxGrid = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
```

### Example 3

```text
Input: boxGrid = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
```

## Constraints

- m == boxGrid.length
- n == boxGrid[i].length
- 1 <= m, n <= 500
- boxGrid[i][j] is either '#', '*', or '.'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1861. Rotating the Box

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Row by Row (Brute Force) | C++, Java, Python3 |
| Row By Row (Optimized) | C++, Java, Python3 |
| Combine rotation and gravity operations | C++, Java, Python3 |

## Approach 1: Row by Row (Brute Force)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m));

        // Create the transpose of the input grid in `result`
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        // Reverse each row in the transpose grid to complete the 90° rotation
        for (int i = 0; i < n; i++) {
            reverse(result[i].begin(), result[i].end());
        }

        // Apply gravity to let stones fall to the lowest possible empty cell in
        // each column
        for (int j = 0; j < m; j++) {
            // Process each cell in column `j` from bottom to top
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '.') {  // Found an empty cell; check if a
                                            // stone can fall into it
                    int nextRowWithStone = -1;

                    // Look for a stone directly above the empty cell
                    // `result[i][j]`
                    for (int k = i - 1; k >= 0; k--) {
                        if (result[k][j] == '*')
                            break;  // Obstacle blocks any stones above
                        if (result[k][j] ==
                            '#') {  // Stone found with no obstacles in between
                            nextRowWithStone = k;
                            break;
                        }
                    }

                    // If a stone was found above, let it fall into the empty
                    // cell `result[i][j]`
                    if (nextRowWithStone != -1) {
                        result[nextRowWithStone][j] = '.';
                        result[i][j] = '#';
                    }
                }
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char[][] rotateTheBox(char[][] box) {
        int m = box.length;
        int n = box[0].length;
        char[][] result = new char[n][m];

        // Create the transpose of the input grid in `result`
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        // Reverse each row in the transpose grid to complete the 90° rotation
        for (int i = 0; i < n; i++) {
            reverse(result[i]);
        }

        // Apply gravity to let stones fall to the lowest possible empty cell in each column
        for (int j = 0; j < m; j++) {
            // Process each cell in column `j` from bottom to top
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '.') { // Found an empty cell; check if a stone can fall into it
                    int nextRowWithStone = -1;

                    // Look for a stone directly above the empty cell `result[i][j]`
                    for (int k = i - 1; k >= 0; k--) {
                        if (result[k][j] == '*') break; // Obstacle blocks any stones above
                        if (result[k][j] == '#') { // Stone found with no obstacles in between
                            nextRowWithStone = k;
                            break;
                        }
                    }

                    // If a stone was found above, let it fall into the empty cell `result[i][j]`
                    if (nextRowWithStone != -1) {
                        result[nextRowWithStone][j] = '.';
                        result[i][j] = '#';
                    }
                }
            }
        }
        return result;
    }

    // Helper function to reverse an array
    private void reverse(char[] row) {
        int left = 0;
        int right = row.length - 1;
        while (left < right) {
            char temp = row[left];
            row[left] = row[right];
            row[right] = temp;
            left++;
            right--;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m = len(box)
        n = len(box[0])
        result = [["" for _ in range(m)] for _ in range(n)]

        # Create the transpose of the input grid in `result`
        for i in range(n):
            for j in range(m):
                result[i][j] = box[j][i]

        # Reverse each row in the transpose grid to complete the 90° rotation
        for i in range(n):
            result[i].reverse()

        # Apply gravity to let stones fall to the lowest possible empty cell in each column
        for j in range(m):
            # Process each cell in column `j` from bottom to top
            for i in range(n - 1, -1, -1):
                if (
                    result[i][j] == "."
                ):  # Found an empty cell; check if a stone can fall into it
                    next_row_with_stone = -1

                    # Look for a stone directly above the empty cell `result[i][j]`
                    for k in range(i - 1, -1, -1):
                        if result[k][j] == "*":
                            break  # Obstacle blocks any stones above
                        if (
                            result[k][j] == "#"
                        ):  # Stone found with no obstacles in between
                            next_row_with_stone = k
                            break

                    # If a stone was found above, let it fall into the empty cell `result[i][j]`
                    if next_row_with_stone != -1:
                        result[next_row_with_stone][j] = "."
                        result[i][j] = "#"

        return result
```

</details>

<br>

## Approach 2: Row By Row (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m));

        // Create the transpose of the input grid in `result`
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        // Reverse each row in the transpose grid to complete the 90° rotation
        for (int i = 0; i < n; i++) {
            reverse(result[i].begin(), result[i].end());
        }

        // Apply gravity to let stones fall to the lowest possible empty cell in
        // each column
        for (int j = 0; j < m; j++) {
            int lowestRowWithEmptyCell = n - 1;
            // Process each cell in column `j` from bottom to top
            for (int i = n - 1; i >= 0; i--) {
                // Found a stone - let it fall to the lowest empty cell
                if (result[i][j] == '#') {
                    result[i][j] = '.';
                    result[lowestRowWithEmptyCell][j] = '#';
                    lowestRowWithEmptyCell--;
                }
                // Found an obstacle - reset `lowestRowWithEmptyCell` to the row
                // directly above it
                if (result[i][j] == '*') {
                    lowestRowWithEmptyCell = i - 1;
                }
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char[][] rotateTheBox(char[][] box) {
        int m = box.length;
        int n = box[0].length;
        char[][] result = new char[n][m];

        // Create the transpose of the input grid in `result`
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        // Reverse each row in the transpose grid to complete the 90° rotation
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                char temp = result[i][j];
                result[i][j] = result[i][m - 1 - j];
                result[i][m - 1 - j] = temp;
            }
        }

        // Apply gravity to let stones fall to the lowest possible empty cell in each column
        for (int j = 0; j < m; j++) {
            int lowestRowWithEmptyCell = n - 1;
            // Process each cell in column `j` from bottom to top
            for (int i = n - 1; i >= 0; i--) {
                // Found a stone - let it fall to the lowest empty cell
                if (result[i][j] == '#') {
                    result[i][j] = '.';
                    result[lowestRowWithEmptyCell][j] = '#';
                    lowestRowWithEmptyCell--;
                }
                // Found an obstacle - reset `lowestRowWithEmptyCell` to the row directly above it
                if (result[i][j] == '*') {
                    lowestRowWithEmptyCell = i - 1;
                }
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m = len(box)
        n = len(box[0])
        result = [["" for _ in range(m)] for _ in range(n)]

        # Create the transpose of the input grid in `result`
        for i in range(n):
            for j in range(m):
                result[i][j] = box[j][i]

        # Reverse each row in the transpose grid to complete the 90° rotation
        for i in range(n):
            result[i].reverse()

        # Apply gravity to let stones fall to the lowest possible empty cell in each column
        for j in range(m):
            lowest_row_with_empty_cell = n - 1
            # Process each cell in column `j` from bottom to top
            for i in range(n - 1, -1, -1):
                # Found a stone - let it fall to the lowest empty cell
                if result[i][j] == "#":
                    result[i][j] = "."
                    result[lowest_row_with_empty_cell][j] = "#"
                    lowest_row_with_empty_cell -= 1
                # Found an obstacle - reset `lowest_row_with_empty_cell` to the row directly above it
                if result[i][j] == "*":
                    lowest_row_with_empty_cell = i - 1

        return result
```

</details>

<br>

## Approach 3: Combine rotation and gravity operations

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m, '.'));

        // Apply gravity to let stones fall to the lowest possible empty cell in
        // each column
        for (int i = 0; i < m; i++) {
            int lowestRowWithEmptyCell = n - 1;
            // Process each cell in row `i` in reversed order
            for (int j = n - 1; j >= 0; j--) {
                // Found a stone - let it fall to the lowest empty cell
                if (box[i][j] == '#') {
                    // Place it in the correct position in the rotated grid
                    result[lowestRowWithEmptyCell][m - i - 1] = '#';
                    // (Optional - already initialized to '.') result[j][m - i -
                    // 1] = '.';
                    lowestRowWithEmptyCell--;
                }
                // Found an obstacle - reset `lowestRowWithEmptyCell` to the row
                // directly above it
                if (box[i][j] == '*') {
                    // Place the obstacle in the correct position in the rotated
                    // grid
                    result[j][m - i - 1] = '*';
                    lowestRowWithEmptyCell = j - 1;
                }
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char[][] rotateTheBox(char[][] box) {
        int m = box.length;
        int n = box[0].length;
        char[][] result = new char[n][m];

        // Initialize the result grid with '.'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = '.';
            }
        }

        // Apply gravity to let stones fall to the lowest possible empty cell in each column
        for (int i = 0; i < m; i++) {
            int lowestRowWithEmptyCell = n - 1;
            // Process each cell in row `i` in reversed order
            for (int j = n - 1; j >= 0; j--) {
                // Found a stone - let it fall to the lowest empty cell
                if (box[i][j] == '#') {
                    // Place it in the correct position in the rotated grid
                    result[lowestRowWithEmptyCell][m - i - 1] = '#';
                    lowestRowWithEmptyCell--;
                }
                // Found an obstacle - reset `lowestRowWithEmptyCell` to the row directly above it
                if (box[i][j] == '*') {
                    // Place the obstacle in the correct position in the rotated grid
                    result[j][m - i - 1] = '*';
                    lowestRowWithEmptyCell = j - 1;
                }
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotateTheBox(self, box):
        m = len(box)
        n = len(box[0])
        result = [["." for _ in range(m)] for _ in range(n)]

        # Apply gravity to let stones fall to the lowest possible empty cell in each column
        for i in range(m):
            lowest_row_with_empty_cell = n - 1
            # Process each cell in row `i` in reversed order
            for j in range(n - 1, -1, -1):
                # Found a stone - let it fall to the lowest empty cell
                if box[i][j] == "#":
                    # Place it in the correct position in the rotated grid
                    result[lowest_row_with_empty_cell][m - i - 1] = "#"
                    lowest_row_with_empty_cell -= 1
                # Found an obstacle - reset `lowest_row_with_empty_cell` to the row directly above it
                if box[i][j] == "*":
                    # Place the obstacle in the correct position in the rotated grid
                    result[j][m - i - 1] = "*"
                    lowest_row_with_empty_cell = j - 1

        return result
```

</details>
