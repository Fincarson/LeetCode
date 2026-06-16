# 1886. Determine Whether Matrix Can Be Obtained By Rotation

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)  
`Array` `Matrix`

**Problem Link:** [LeetCode 1886 - Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)

## Problem

Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

### Example 1

```text
Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
```

### Example 2

```text
Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.
```

### Example 3

```text
Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
```

## Constraints

- n == mat.length == target.length
- n == mat[i].length == target[i].length
- 1 <= n <= 10
- mat[i][j] and target[i][j] are either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rotate Image](https://leetcode.com/problems/rotate-image/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1886. Determine Whether Matrix Can Be Obtained By Rotation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulate Rotation Operation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulate Rotation Operation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isEqual(int** mat, int** target, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != target[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool findRotation(int** mat, int matSize, int* matColSize, int** target,
                  int targetSize, int* targetColSize) {
    int n = matSize;

    // at most 4 rotations
    for (int k = 0; k < 4; k++) {
        // rotation operation
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[n - 1 - j][i];
                mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
                mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
                mat[j][n - 1 - i] = temp;
            }
        }

        if (isEqual(mat, target, n)) {
            return true;
        }
    }
    return false;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int temp;
    bool flag;

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        // at most 4 rotations
        for (int k = 0; k < 4; ++k) {
            // rotation operation
            for (int i = 0; i < n / 2; ++i) {
                for (int j = 0; j < (n + 1) / 2; ++j) {
                    temp = mat[i][j];
                    mat[i][j] = mat[n - 1 - j][i];
                    mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
                    mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
                    mat[j][n - 1 - i] = temp;
                }
            }

            if (mat == target) {
                return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool FindRotation(int[][] mat, int[][] target) {
        int n = mat.Length;
        // at most 4 rotations
        for (int k = 0; k < 4; k++) {
            // rotation operation
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < (n + 1) / 2; j++) {
                    int temp = mat[i][j];
                    mat[i][j] = mat[n - 1 - j][i];
                    mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
                    mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
                    mat[j][n - 1 - i] = temp;
                }
            }

            if (IsEqual(mat, target)) {
                return true;
            }
        }
        return false;
    }

    private bool IsEqual(int[][] mat, int[][] target) {
        int n = mat.Length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findRotation(mat [][]int, target [][]int) bool {
    n := len(mat)
    // at most 4 rotations
    for k := 0; k < 4; k++ {
        // rotation operation
        for i := 0; i < n/2; i++ {
            for j := 0; j < (n+1)/2; j++ {
                mat[i][j], mat[n-1-j][i], mat[n-1-i][n-1-j], mat[j][n-1-i] = 
                    mat[n-1-j][i], mat[n-1-i][n-1-j], mat[j][n-1-i], mat[i][j]
            }
        }
        
        if isEqual(mat, target) {
            return true
        }
    }
    return false
}

func isEqual(mat, target [][]int) bool {
    n := len(mat)
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if mat[i][j] != target[i][j] {
                return false
            }
        }
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;
        // at most 4 rotations
        for (int k = 0; k < 4; k++) {
            // rotation operation
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < (n + 1) / 2; j++) {
                    int temp = mat[i][j];
                    mat[i][j] = mat[n - 1 - j][i];
                    mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
                    mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
                    mat[j][n - 1 - i] = temp;
                }
            }

            if (isEqual(mat, target)) {
                return true;
            }
        }
        return false;
    }

    private boolean isEqual(int[][] mat, int[][] target) {
        int n = mat.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findRotation = function (mat, target) {
    const n = mat.length;
    // at most 4 rotations
    for (let k = 0; k < 4; k++) {
        // rotation operation
        for (let i = 0; i < Math.floor(n / 2); i++) {
            for (let j = 0; j < Math.floor((n + 1) / 2); j++) {
                [
                    mat[i][j],
                    mat[n - 1 - j][i],
                    mat[n - 1 - i][n - 1 - j],
                    mat[j][n - 1 - i],
                ] = [
                    mat[n - 1 - j][i],
                    mat[n - 1 - i][n - 1 - j],
                    mat[j][n - 1 - i],
                    mat[i][j],
                ];
            }
        }

        if (isEqual(mat, target)) {
            return true;
        }
    }
    return false;
};

function isEqual(mat, target) {
    const n = mat.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j] !== target[i][j]) {
                return false;
            }
        }
    }
    return true;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findRotation(
        self, mat: List[List[int]], target: List[List[int]]
    ) -> bool:
        n = len(mat)
        # at most 4 rotations
        for k in range(4):
            # rotation operation
            for i in range(n // 2):
                for j in range((n + 1) // 2):
                    (
                        mat[i][j],
                        mat[n - 1 - j][i],
                        mat[n - 1 - i][n - 1 - j],
                        mat[j][n - 1 - i],
                    ) = (
                        mat[n - 1 - j][i],
                        mat[n - 1 - i][n - 1 - j],
                        mat[j][n - 1 - i],
                        mat[i][j],
                    )

            if mat == target:
                return True
        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findRotation(mat: number[][], target: number[][]): boolean {
    const n = mat.length;
    // at most 4 rotations
    for (let k = 0; k < 4; k++) {
        // rotation operation
        for (let i = 0; i < Math.floor(n / 2); i++) {
            for (let j = 0; j < Math.floor((n + 1) / 2); j++) {
                [
                    mat[i][j],
                    mat[n - 1 - j][i],
                    mat[n - 1 - i][n - 1 - j],
                    mat[j][n - 1 - i],
                ] = [
                    mat[n - 1 - j][i],
                    mat[n - 1 - i][n - 1 - j],
                    mat[j][n - 1 - i],
                    mat[i][j],
                ];
            }
        }

        if (isEqual(mat, target)) {
            return true;
        }
    }
    return false;
}

function isEqual(mat: number[][], target: number[][]): boolean {
    const n = mat.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j] !== target[i][j]) {
                return false;
            }
        }
    }
    return true;
}
```

</details>
