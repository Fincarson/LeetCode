# 48. Rotate Image

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/rotate-image/)  
`Array` `Math` `Matrix`

**Problem Link:** [LeetCode 48 - Rotate Image](https://leetcode.com/problems/rotate-image/)

## Problem

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

### Example 1

```text
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

### Example 2

```text
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

## Constraints

- n == matrix.length == matrix[i].length
- 1 <= n <= 20
- -1000 <= matrix[i][j] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 48. Rotate Image

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Rotate Groups of Four Cells | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Reverse on the Diagonal and then Reverse Left to Right | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Rotate Groups of Four Cells

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
            matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public void Rotate(int[][] matrix) {
        int n = matrix.Length;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func rotate(matrix [][]int) {
    n := len(matrix)
    for i := 0; i < (n+1)/2; i++ {
        for j := 0; j < n/2; j++ {
            temp := matrix[n-1-j][i]
            matrix[n-1-j][i] = matrix[n-1-i][n-j-1]
            matrix[n-1-i][n-j-1] = matrix[j][n-1-i]
            matrix[j][n-1-i] = matrix[i][j]
            matrix[i][j] = temp
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var rotate = function (matrix) {
    var n = matrix.length;
    for (var i = 0; i < Math.floor((n + 1) / 2); i++) {
        for (var j = 0; j < Math.floor(n / 2); j++) {
            var temp = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
            matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix[0])
        for i in range(n // 2 + n % 2):
            for j in range(n // 2):
                tmp = matrix[n - 1 - j][i]
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1]
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i]
                matrix[j][n - 1 - i] = matrix[i][j]
                matrix[i][j] = tmp
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function rotate(matrix: number[][]): void {
    let n = matrix.length;
    for (let i = 0; i < Math.floor((n + 1) / 2); i++) {
        for (let j = 0; j < Math.floor(n / 2); j++) {
            let temp = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
            matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}
```

</details>

<br>

## Approach 2: Reverse on the Diagonal and then Reverse Left to Right

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int temp, n = matrixSize;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reflect(matrix);
    }

private:
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }
    }
    void reflect(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public void Rotate(int[][] matrix) {
        int n = matrix.Length;
        Transpose(matrix, n);
        Reflect(matrix, n);
    }

    private void Transpose(int[][] matrix, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }

    private void Reflect(int[][] matrix, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func rotate(matrix [][]int) {
    n := len(matrix)
    // Transpose
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        }
    }
    // Reflect
    for i := 0; i < n; i++ {
        for j := 0; j < n/2; j++ {
            matrix[i][j], matrix[i][n-j-1] = matrix[i][n-j-1], matrix[i][j]
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void rotate(int[][] matrix) {
        transpose(matrix);
        reflect(matrix);
    }

    public void transpose(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }

    public void reflect(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var rotate = function (matrix) {
    const n = matrix.length;
    // Transpose
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
        }
    }
    // Reflect
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n / 2; j++) {
            [matrix[i][j], matrix[i][n - 1 - j]] = [
                matrix[i][n - 1 - j],
                matrix[i][j],
            ];
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        self.transpose(matrix)
        self.reflect(matrix)

    def transpose(self, matrix):
        n = len(matrix)
        for i in range(n):
            for j in range(i + 1, n):
                matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]

    def reflect(self, matrix):
        n = len(matrix)
        for i in range(n):
            for j in range(n // 2):
                matrix[i][j], matrix[i][-j - 1] = (
                    matrix[i][-j - 1],
                    matrix[i][j],
                )
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function rotate(matrix: number[][]): void {
    const n = matrix.length;
    // Transpose
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
        }
    }
    // Reflect
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n / 2; j++) {
            [matrix[i][j], matrix[i][n - 1 - j]] = [
                matrix[i][n - 1 - j],
                matrix[i][j],
            ];
        }
    }
}
```

</details>
