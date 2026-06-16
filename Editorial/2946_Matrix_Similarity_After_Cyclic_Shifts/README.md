# 2946. Matrix Similarity After Cyclic Shifts

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/)  
`Array` `Math` `Matrix` `Simulation`

**Problem Link:** [LeetCode 2946 - Matrix Similarity After Cyclic Shifts](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/)

## Problem

You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.

The following proccess happens k times:

- Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.

- Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.

Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= mat.length <= 25
- 1 <= mat[i].length <= 25
- 1 <= mat[i][j] <= 25
- 1 <= k <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2946. Matrix Similarity After Cyclic Shifts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int m = matSize;
    int n = matColSize[0];
    k %= n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != mat[i][(j + k) % n]) {
                return false;
            }
        }
    }
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool AreSimilar(int[][] mat, int k) {
        int m = mat.Length;
        int n = mat[0].Length;
        k %= n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != mat[i][(j + k) % n]) {
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
func areSimilar(mat [][]int, k int) bool {
	m := len(mat)
	n := len(mat[0])
	k %= n

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if mat[i][j] != mat[i][(j+k)%n] {
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

    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        k %= n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != mat[i][(j + k) % n]) {
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
var areSimilar = function (mat, k) {
    const m = mat.length;
    const n = mat[0].length;
    k %= n;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j] !== mat[i][(j + k) % n]) {
                return false;
            }
        }
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        m, n = len(mat), len(mat[0])
        k %= n

        for i in range(m):
            for j in range(n):
                if mat[i][j] != mat[i][(j + k) % n]:
                    return False
        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function areSimilar(mat: number[][], k: number): boolean {
    const m: number = mat.length;
    const n: number = mat[0].length;
    k %= n;

    for (let i: number = 0; i < m; i++) {
        for (let j: number = 0; j < n; j++) {
            if (mat[i][j] !== mat[i][(j + k) % n]) {
                return false;
            }
        }
    }
    return true;
}
```

</details>
