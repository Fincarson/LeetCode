# 54. Spiral Matrix

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/spiral-matrix/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 54 - Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

## Problem

Given an m x n matrix, return all elements of the matrix in spiral order.

### Example 1

```text
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

### Example 2

```text
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

## Constraints

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 10
- -100 <= matrix[i][j] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Spiral Matrix IV](https://leetcode.com/problems/spiral-matrix-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 54. Spiral Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Set Up Boundaries | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Mark Visited Elements | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Set Up Boundaries

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize,
                 int* returnSize) {
    *returnSize = matrixSize * (*matrixColSize);
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    int idx = 0;
    int rows = matrixSize;
    int columns = *matrixColSize;
    int up = 0;
    int left = 0;
    int right = columns - 1;
    int down = rows - 1;
    while (idx < *returnSize) {
        // Traverse from left to right.
        for (int col = left; col <= right; col++) {
            result[idx++] = matrix[up][col];
        }
        // Traverse downwards.
        for (int row = up + 1; row <= down; row++) {
            result[idx++] = matrix[row][right];
        }
        // Make sure we are now on a different row.
        if (up != down) {
            // Traverse from right to left.
            for (int col = right - 1; col >= left; col--) {
                result[idx++] = matrix[down][col];
            }
        }
        // Make sure we are now on a different column.
        if (left != right) {
            // Traverse upwards.
            for (int row = down - 1; row > up; row--) {
                result[idx++] = matrix[row][left];
            }
        }
        left++;
        right--;
        up++;
        down--;
    }
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int up = 0;
        int left = 0;
        int right = columns - 1;
        int down = rows - 1;
        while (result.size() < rows * columns) {
            // Traverse from left to right.
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[up][col]);
            }
            // Traverse downwards.
            for (int row = up + 1; row <= down; row++) {
                result.push_back(matrix[row][right]);
            }
            // Make sure we are now on a different row.
            if (up != down) {
                // Traverse from right to left.
                for (int col = right - 1; col >= left; col--) {
                    result.push_back(matrix[down][col]);
                }
            }
            // Make sure we are now on a different column.
            if (left != right) {
                // Traverse upwards.
                for (int row = down - 1; row > up; row--) {
                    result.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            up++;
            down--;
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        IList<int> result = new List<int>();
        int rows = matrix.Length;
        int columns = matrix[0].Length;
        int up = 0;
        int left = 0;
        int right = columns - 1;
        int down = rows - 1;
        while (result.Count < rows * columns) {
            // Traverse from left to right.
            for (int col = left; col <= right; col++) {
                result.Add(matrix[up][col]);
            }

            // Traverse downwards.
            for (int row = up + 1; row <= down; row++) {
                result.Add(matrix[row][right]);
            }

            // Make sure we are now on a different row.
            if (up != down) {
                // Traverse from right to left.
                for (int col = right - 1; col >= left; col--) {
                    result.Add(matrix[down][col]);
                }
            }

            // Make sure we are now on a different column.
            if (left != right) {
                // Traverse upwards.
                for (int row = down - 1; row > up; row--) {
                    result.Add(matrix[row][left]);
                }
            }

            left++;
            right--;
            up++;
            down--;
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func spiralOrder(matrix [][]int) []int {
    var result []int
    rows := len(matrix)
    columns := len(matrix[0])
    up := 0
    left := 0
    right := columns - 1
    down := rows - 1
    for len(result) < rows*columns {
        // Traverse from left to right.
        for col := left; col <= right; col++ {
            result = append(result, matrix[up][col])
        }
        // Traverse downwards.
        for row := up + 1; row <= down; row++ {
            result = append(result, matrix[row][right])
        }
        // Make sure we are now on a different row.
        if up != down {
            // Traverse from right to left.
            for col := right - 1; col >= left; col-- {
                result = append(result, matrix[down][col])
            }
        }
        // Make sure we are now on a different column.
        if left != right {
            // Traverse upwards.
            for row := down - 1; row > up; row-- {
                result = append(result, matrix[row][left])
            }
        }
        left++
        right--
        up++
        down--
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        int rows = matrix.length;
        int columns = matrix[0].length;
        int up = 0;
        int left = 0;
        int right = columns - 1;
        int down = rows - 1;

        while (result.size() < rows * columns) {
            // Traverse from left to right.
            for (int col = left; col <= right; col++) {
                result.add(matrix[up][col]);
            }
            // Traverse downwards.
            for (int row = up + 1; row <= down; row++) {
                result.add(matrix[row][right]);
            }
            // Make sure we are now on a different row.
            if (up != down) {
                // Traverse from right to left.
                for (int col = right - 1; col >= left; col--) {
                    result.add(matrix[down][col]);
                }
            }
            // Make sure we are now on a different column.
            if (left != right) {
                // Traverse upwards.
                for (int row = down - 1; row > up; row--) {
                    result.add(matrix[row][left]);
                }
            }
            left++;
            right--;
            up++;
            down--;
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var spiralOrder = function (matrix) {
    let result = [];
    let rows = matrix.length;
    let columns = matrix[0].length;
    let up = 0;
    let left = 0;
    let right = columns - 1;
    let down = rows - 1;
    while (result.length < rows * columns) {
        // Traverse from left to right.
        for (let col = left; col <= right; col++) {
            result.push(matrix[up][col]);
        }
        // Traverse downwards.
        for (let row = up + 1; row <= down; row++) {
            result.push(matrix[row][right]);
        }
        // Make sure we are now on a different row.
        if (up != down) {
            // Traverse from right to left.
            for (let col = right - 1; col >= left; col--) {
                result.push(matrix[down][col]);
            }
        }
        // Make sure we are now on a different column.
        if (left != right) {
            // Traverse upwards.
            for (let row = down - 1; row > up; row--) {
                result.push(matrix[row][left]);
            }
        }
        left++;
        right--;
        up++;
        down--;
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        rows, columns = len(matrix), len(matrix[0])
        up = left = 0
        right = columns - 1
        down = rows - 1

        while len(result) < rows * columns:
            # Traverse from left to right.
            for col in range(left, right + 1):
                result.append(matrix[up][col])

            # Traverse downwards.
            for row in range(up + 1, down + 1):
                result.append(matrix[row][right])

            # Make sure we are now on a different row.
            if up != down:
                # Traverse from right to left.
                for col in range(right - 1, left - 1, -1):
                    result.append(matrix[down][col])

            # Make sure we are now on a different column.
            if left != right:
                # Traverse upwards.
                for row in range(down - 1, up, -1):
                    result.append(matrix[row][left])

            left += 1
            right -= 1
            up += 1
            down -= 1

        return result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function spiralOrder(matrix: number[][]): number[] {
    let result = [];
    let rows = matrix.length;
    let columns = matrix[0].length;
    let up = 0;
    let left = 0;
    let right = columns - 1;
    let down = rows - 1;
    while (result.length < rows * columns) {
        // Traverse from left to right.
        for (let col = left; col <= right; col++) {
            result.push(matrix[up][col]);
        }
        // Traverse downwards.
        for (let row = up + 1; row <= down; row++) {
            result.push(matrix[row][right]);
        }
        // Make sure we are now on a different row.
        if (up != down) {
            // Traverse from right to left.
            for (let col = right - 1; col >= left; col--) {
                result.push(matrix[down][col]);
            }
        }
        // Make sure we are now on a different column.
        if (left != right) {
            // Traverse upwards.
            for (let row = down - 1; row > up; row--) {
                result.push(matrix[row][left]);
            }
        }
        left++;
        right--;
        up++;
        down--;
    }
    return result;
}
```

</details>

<br>

## Approach 2: Mark Visited Elements

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int x, y;
} Direction;
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize,
                 int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    const int VISITED = 101;
    int rows = matrixSize, columns = matrixColSize[0];
    Direction directions[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int currentDirection = 0;
    int row = 0, col = 0;
    *returnSize = rows * columns;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    result[0] = matrix[0][0];
    matrix[0][0] = VISITED;
    for (int i = 1; i < *returnSize;) {
        while (row + directions[currentDirection].x >= 0 &&
               row + directions[currentDirection].x < rows &&
               col + directions[currentDirection].y >= 0 &&
               col + directions[currentDirection].y < columns &&
               matrix[row + directions[currentDirection].x]
                     [col + directions[currentDirection].y] != VISITED) {
            row = row + directions[currentDirection].x;
            col = col + directions[currentDirection].y;
            result[i++] = matrix[row][col];
            matrix[row][col] = VISITED;
        }
        currentDirection = (currentDirection + 1) % 4;
    }
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int VISITED = 101;
        int rows = matrix.size(), columns = matrix[0].size();
        // Four directions that we will move: right, down, left, up.
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // Initial direction: moving right.
        int currentDirection = 0;
        // The number of times we change the direction.
        int changeDirection = 0;
        // Current place that we are at is (row, col).
        // row is the row index; col is the column index.
        int row = 0, col = 0;
        // Store the first element and mark it as visited.
        vector<int> result = {matrix[0][0]};
        matrix[0][0] = VISITED;
        while (changeDirection < 2) {
            while (0 <= row + directions[currentDirection][0] &&
                   row + directions[currentDirection][0] < rows &&
                   0 <= col + directions[currentDirection][1] &&
                   col + directions[currentDirection][1] < columns &&
                   matrix[row + directions[currentDirection][0]]
                         [col + directions[currentDirection][1]] != VISITED) {
                // Reset this to 0 since we did not break and change the
                // direction.
                changeDirection = 0;
                // Calculate the next place that we will move to.
                row += directions[currentDirection][0];
                col += directions[currentDirection][1];
                result.push_back(matrix[row][col]);
                matrix[row][col] = VISITED;
            }
            // Change our direction.
            currentDirection = (currentDirection + 1) % 4;
            // Increment change_direction because we changed our direction.
            changeDirection++;
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        int VISITED = 101;
        int rows = matrix.Length, columns = matrix[0].Length;
        // Four directions that we will move: right, down, left, up.
        int[][] directions =
            new int [4][] { new int[] { 0, 1 }, new int[] { 1, 0 },
                            new int[] { 0, -1 }, new int[] { -1, 0 } };
        // Initial direction: moving right.
        int currentDirection = 0;
        // The number of times we change the direction.
        int changeDirection = 0;
        // Current place that we are at is (row, col).
        // row is the row index; col is the column index.
        int row = 0, col = 0;
        // Store the first element and mark it as visited.
        List<int> result = new List<int> { matrix[0][0] };
        matrix[0][0] = VISITED;
        while (changeDirection < 2) {
            while (0 <= row + directions[currentDirection][0] &&
                   row + directions[currentDirection][0] < rows &&
                   0 <= col + directions[currentDirection][1] &&
                   col + directions[currentDirection][1] < columns &&
                   matrix[row + directions[currentDirection][0]]
                         [col + directions[currentDirection][1]] != VISITED) {
                // Reset this to 0 since we did not break and change the
                // direction.
                changeDirection = 0;
                // Calculate the next place that we will move to.
                row += directions[currentDirection][0];
                col += directions[currentDirection][1];
                result.Add(matrix[row][col]);
                matrix[row][col] = VISITED;
            }

            // Change our direction.
            currentDirection = (currentDirection + 1) % 4;
            // Increment changeDirection because we changed our direction.
            changeDirection++;
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func spiralOrder(matrix [][]int) []int {
    const VISITED = 101
    rows, cols := len(matrix), len(matrix[0])
    result := []int{matrix[0][0]}
    matrix[0][0] = VISITED
    // Four directions that we will move: right, down, left, up.
    directions := [4][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
    // Initial direction: moving right.
    currentDirection := 0
    // The number of times we change the direction.
    changeDirection := 0
    row, col := 0, 0
    for changeDirection < 2 {
        for row+directions[currentDirection][0] >= 0 &&
            row+directions[currentDirection][0] < rows &&
            col+directions[currentDirection][1] >= 0 &&
            col+directions[currentDirection][1] < cols &&
            matrix[row+directions[currentDirection][0]][col+directions[currentDirection][1]] != VISITED {
            // Reset this to 0 since we did not break and change the direction.
            changeDirection = 0
            // Calculate the next place that we will move to.
            row += directions[currentDirection][0]
            col += directions[currentDirection][1]
            result = append(result, matrix[row][col])
            matrix[row][col] = VISITED
        }
        // Change our direction.
        currentDirection = (currentDirection + 1) % 4
        // Increment changeDirection because we changed our direction.
        changeDirection++
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int VISITED = 101;
        int rows = matrix.length;
        int columns = matrix[0].length;
        // Four directions that we will move: right, down, left, up.
        int[][] directions = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        // Initial direction: moving right.
        int currentDirection = 0;
        // The number of times we change the direction.
        int changeDirection = 0;
        // Current place that we are at is (row, col).
        // row is the row index; col is the column index.
        int row = 0;
        int col = 0;
        // Store the first element and mark it as visited.
        List<Integer> result = new ArrayList<>();
        result.add(matrix[0][0]);
        matrix[0][0] = VISITED;
        while (changeDirection < 2) {
            while (
                row + directions[currentDirection][0] >= 0 &&
                row + directions[currentDirection][0] < rows &&
                col + directions[currentDirection][1] >= 0 &&
                col + directions[currentDirection][1] < columns &&
                matrix[row + directions[currentDirection][0]][col +
                        directions[currentDirection][1]] !=
                    VISITED
            ) {
                // Reset this to 0 since we did not break and change the direction.
                changeDirection = 0;
                // Calculate the next place that we will move to.
                row = row + directions[currentDirection][0];
                col = col + directions[currentDirection][1];
                result.add(matrix[row][col]);
                matrix[row][col] = VISITED;
            }
            // Change our direction.
            currentDirection = (currentDirection + 1) % 4;
            // Increment change_direction because we changed our direction.
            changeDirection++;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var spiralOrder = function (matrix) {
    const VISITED = 101;
    let rows = matrix.length,
        cols = matrix[0].length;
    let result = [matrix[0][0]];
    matrix[0][0] = VISITED;
    // Four directions that we will move: right, down, left, up
    let directions = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0],
    ];
    // Initial direction: moving right
    let currentDirection = 0;
    // The number of times we change the direction
    let changeDirection = 0;
    let row = 0,
        col = 0;
    while (changeDirection < 2) {
        while (
            row + directions[currentDirection][0] >= 0 &&
            row + directions[currentDirection][0] < rows &&
            col + directions[currentDirection][1] >= 0 &&
            col + directions[currentDirection][1] < cols &&
            matrix[row + directions[currentDirection][0]][
                col + directions[currentDirection][1]
            ] != VISITED
        ) {
            // Reset this to 0 since we did not break and change the direction
            changeDirection = 0;
            // Calculate the next place that we will move to
            row += directions[currentDirection][0];
            col += directions[currentDirection][1];
            result.push(matrix[row][col]);
            matrix[row][col] = VISITED;
        }
        // Change our direction
        currentDirection = (currentDirection + 1) % 4;
        // Increment change_direction because we changed our direction
        changeDirection++;
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        VISITED = 101
        rows, columns = len(matrix), len(matrix[0])
        # Four directions that we will move: right, down, left, up.
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        # Initial direction: moving right.
        current_direction = 0
        # The number of times we change the direction.
        change_direction = 0
        # Current place that we are at is (row, col).
        # row is the row index; col is the column index.
        row = col = 0
        # Store the first element and mark it as visited.
        result = [matrix[0][0]]
        matrix[0][0] = VISITED

        while change_direction < 2:

            while True:
                # Calculate the next place that we will move to.
                next_row = row + directions[current_direction][0]
                next_col = col + directions[current_direction][1]

                # Break if the next step is out of bounds.
                if not (0 <= next_row < rows and 0 <= next_col < columns):
                    break
                # Break if the next step is on a visited cell.
                if matrix[next_row][next_col] == VISITED:
                    break

                # Reset this to 0 since we did not break and change the direction.
                change_direction = 0
                # Update our current position to the next step.
                row, col = next_row, next_col
                result.append(matrix[row][col])
                matrix[row][col] = VISITED

            # Change our direction.
            current_direction = (current_direction + 1) % 4
            # Increment change_direction because we changed our direction.
            change_direction += 1

        return result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function spiralOrder(matrix: number[][]): number[] {
    const VISITED = 101;
    let rows = matrix.length,
        cols = matrix[0].length;
    let result: number[] = [matrix[0][0]];
    matrix[0][0] = VISITED;
    // Four directions that we will move: right, down, left, up.
    let directions: number[][] = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0],
    ];
    // Initial direction: moving right.
    let currentDirection = 0;
    // The number of times we change the direction.
    let changeDirection = 0;
    let row = 0,
        col = 0;
    while (changeDirection < 2) {
        while (
            row + directions[currentDirection][0] >= 0 &&
            row + directions[currentDirection][0] < rows &&
            col + directions[currentDirection][1] >= 0 &&
            col + directions[currentDirection][1] < cols &&
            matrix[row + directions[currentDirection][0]][
                col + directions[currentDirection][1]
            ] != VISITED
        ) {
            // Reset this to 0 since we did not break and change the direction.
            changeDirection = 0;
            // Calculate the next place that we will move to.
            row += directions[currentDirection][0];
            col += directions[currentDirection][1];
            result.push(matrix[row][col]);
            matrix[row][col] = VISITED;
        }
        // Change our direction.
        currentDirection = (currentDirection + 1) % 4;
        // Increment changeDirection because we changed our direction.
        changeDirection++;
    }
    return result;
}
```

</details>
