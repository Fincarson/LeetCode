# 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)  
`Array` `Binary Search` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 1292 - Maximum Side Length of a Square with Sum Less than or Equal to Threshold](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)

## Problem

Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

### Example 1

```text
Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than or equal to 4 is 2 as shown.
```

### Example 2

```text
Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0
```

## Constraints

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 300
- 0 <= mat[i][j] <= 104
- 0 <= threshold <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Enumeration + Optimization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize, n = matColSize[0];
    int** P = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        P[i] = (int*)calloc(n + 1, sizeof(int));
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            P[i][j] =
                P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    int l = 1, r = (m < n ? m : n), ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int find = 0;
        for (int i = 1; i <= m - mid + 1; i++) {
            for (int j = 1; j <= n - mid + 1; j++) {
                int sum = P[i + mid - 1][j + mid - 1] - P[i - 1][j + mid - 1] -
                          P[i + mid - 1][j - 1] + P[i - 1][j - 1];
                if (sum <= threshold) {
                    find = 1;
                    break;
                }
            }
            if (find) break;
        }
        if (find) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    for (int i = 0; i <= m; i++) {
        free(P[i]);
    }
    free(P);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getRect(const vector<vector<int>>& P, int x1, int y1, int x2, int y2) {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> P(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] +
                          mat[i - 1][j - 1];
            }
        }

        int l = 1, r = min(m, n), ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool find = false;
            for (int i = 1; i <= m - mid + 1; ++i) {
                for (int j = 1; j <= n - mid + 1; ++j) {
                    if (getRect(P, i, j, i + mid - 1, j + mid - 1) <=
                        threshold) {
                        find = true;
                    }
                }
            }
            if (find) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxSideLength(int[][] mat, int threshold) {
        int m = mat.Length, n = mat[0].Length;
        int[,] P = new int[m + 1, n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                P[i, j] = P[i - 1, j] + P[i, j - 1] - P[i - 1, j - 1] +
                          mat[i - 1][j - 1];
            }
        }

        int l = 1, r = Math.Min(m, n), ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool find = false;
            for (int i = 1; i <= m - mid + 1; i++) {
                for (int j = 1; j <= n - mid + 1; j++) {
                    int sum = P[i + mid - 1, j + mid - 1] -
                              P[i - 1, j + mid - 1] - P[i + mid - 1, j - 1] +
                              P[i - 1, j - 1];
                    if (sum <= threshold) {
                        find = true;
                        break;
                    }
                }
                if (find)
                    break;
            }
            if (find) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxSideLength(mat [][]int, threshold int) int {
    m, n := len(mat), len(mat[0])
    P := make([][]int, m+1)
    for i := range P {
        P[i] = make([]int, n+1)
    }
    
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + mat[i-1][j-1]
        }
    }
    
    l, r, ans := 1, min(m, n), 0
    for l <= r {
        mid := (l + r) / 2
        find := false
        for i := 1; i <= m-mid+1; i++ {
            for j := 1; j <= n-mid+1; j++ {
                sum := P[i+mid-1][j+mid-1] - P[i-1][j+mid-1] - P[i+mid-1][j-1] + P[i-1][j-1]
                if sum <= threshold {
                    find = true
                    break
                }
            }
            if find {
                break
            }
        }
        if find {
            ans = mid
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] P = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                P[i][j] =
                    P[i - 1][j] +
                    P[i][j - 1] -
                    P[i - 1][j - 1] +
                    mat[i - 1][j - 1];
            }
        }

        int l = 1;
        int r = Math.min(m, n);
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            boolean find = false;
            for (int i = 1; i <= m - mid + 1; i++) {
                for (int j = 1; j <= n - mid + 1; j++) {
                    int sum =
                        P[i + mid - 1][j + mid - 1] -
                        P[i - 1][j + mid - 1] -
                        P[i + mid - 1][j - 1] +
                        P[i - 1][j - 1];
                    if (sum <= threshold) {
                        find = true;
                        break;
                    }
                }
                if (find) break;
            }
            if (find) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSideLength = function (mat, threshold) {
    const m = mat.length,
        n = mat[0].length;
    const P = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            P[i][j] =
                P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    let l = 1,
        r = Math.min(m, n),
        ans = 0;
    while (l <= r) {
        const mid = Math.floor((l + r) / 2);
        let find = false;
        for (let i = 1; i <= m - mid + 1; i++) {
            for (let j = 1; j <= n - mid + 1; j++) {
                const sum =
                    P[i + mid - 1][j + mid - 1] -
                    P[i - 1][j + mid - 1] -
                    P[i + mid - 1][j - 1] +
                    P[i - 1][j - 1];
                if (sum <= threshold) {
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        if (find) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        P = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                P[i][j] = (
                    P[i - 1][j]
                    + P[i][j - 1]
                    - P[i - 1][j - 1]
                    + mat[i - 1][j - 1]
                )

        def getRect(x1, y1, x2, y2):
            return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1]

        l, r, ans = 1, min(m, n), 0
        while l <= r:
            mid = (l + r) // 2
            find = any(
                getRect(i, j, i + mid - 1, j + mid - 1) <= threshold
                for i in range(1, m - mid + 2)
                for j in range(1, n - mid + 2)
            )
            if find:
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxSideLength(mat: number[][], threshold: number): number {
    const m = mat.length,
        n = mat[0].length;
    const P: number[][] = Array.from({ length: m + 1 }, () =>
        new Array(n + 1).fill(0),
    );

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            P[i][j] =
                P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    let l = 1,
        r = Math.min(m, n),
        ans = 0;
    while (l <= r) {
        const mid = Math.floor((l + r) / 2);
        let find = false;
        for (let i = 1; i <= m - mid + 1; i++) {
            for (let j = 1; j <= n - mid + 1; j++) {
                const sum =
                    P[i + mid - 1][j + mid - 1] -
                    P[i - 1][j + mid - 1] -
                    P[i + mid - 1][j - 1] +
                    P[i - 1][j - 1];
                if (sum <= threshold) {
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        if (find) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Enumeration + Optimization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int getRect(int** P, int x1, int y1, int x2, int y2) {
    return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
}

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize, n = matColSize[0];
    int** P = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        P[i] = (int*)calloc(n + 1, sizeof(int));
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            P[i][j] =
                P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    int r = (m < n ? m : n);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int c = ans + 1; c <= r; c++) {
                if (i + c - 1 <= m && j + c - 1 <= n &&
                    getRect(P, i, j, i + c - 1, j + c - 1) <= threshold) {
                    ans = c;
                } else {
                    break;
                }
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        free(P[i]);
    }
    free(P);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getRect(const vector<vector<int>>& P, int x1, int y1, int x2, int y2) {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> P(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] +
                          mat[i - 1][j - 1];
            }
        }

        int r = min(m, n), ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int c = ans + 1; c <= r; ++c) {
                    if (i + c - 1 <= m && j + c - 1 <= n &&
                        getRect(P, i, j, i + c - 1, j + c - 1) <= threshold) {
                        ++ans;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int GetRect(int[,] P, int x1, int y1, int x2, int y2) {
        return P[x2, y2] - P[x1 - 1, y2] - P[x2, y1 - 1] + P[x1 - 1, y1 - 1];
    }

    public int MaxSideLength(int[][] mat, int threshold) {
        int m = mat.Length, n = mat[0].Length;
        int[,] P = new int[m + 1, n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i, j] = P[i - 1, j] + P[i, j - 1] - P[i - 1, j - 1] +
                          mat[i - 1][j - 1];
            }
        }

        int r = Math.Min(m, n), ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int c = ans + 1; c <= r; ++c) {
                    if (i + c - 1 <= m && j + c - 1 <= n &&
                        GetRect(P, i, j, i + c - 1, j + c - 1) <= threshold) {
                        ++ans;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxSideLength(mat [][]int, threshold int) int {
    m, n := len(mat), len(mat[0])
    P := make([][]int, m+1)
    for i := range P {
        P[i] = make([]int, n+1)
    }
    
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + mat[i-1][j-1]
        }
    }
    
    getRect := func(x1, y1, x2, y2 int) int {
        return P[x2][y2] - P[x1-1][y2] - P[x2][y1-1] + P[x1-1][y1-1]
    }
    
    r := min(m, n)
    ans := 0
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            for c := ans + 1; c <= r; c++ {
                if i+c-1 <= m && j+c-1 <= n && getRect(i, j, i+c-1, j+c-1) <= threshold {
                    ans = c
                } else {
                    break
                }
            }
        }
    }
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int getRect(int[][] P, int x1, int y1, int x2, int y2) {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    }

    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] P = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] =
                    P[i - 1][j] +
                    P[i][j - 1] -
                    P[i - 1][j - 1] +
                    mat[i - 1][j - 1];
            }
        }

        int r = Math.min(m, n);
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int c = ans + 1; c <= r; ++c) {
                    if (
                        i + c - 1 <= m &&
                        j + c - 1 <= n &&
                        getRect(P, i, j, i + c - 1, j + c - 1) <= threshold
                    ) {
                        ++ans;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSideLength = function (mat, threshold) {
    const m = mat.length,
        n = mat[0].length;
    const P = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            P[i][j] =
                P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    const getRect = (x1, y1, x2, y2) => {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    };

    const r = Math.min(m, n);
    let ans = 0;
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            for (let c = ans + 1; c <= r; c++) {
                if (
                    i + c - 1 <= m &&
                    j + c - 1 <= n &&
                    getRect(i, j, i + c - 1, j + c - 1) <= threshold
                ) {
                    ans = c;
                } else {
                    break;
                }
            }
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        P = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                P[i][j] = (
                    P[i - 1][j]
                    + P[i][j - 1]
                    - P[i - 1][j - 1]
                    + mat[i - 1][j - 1]
                )

        def getRect(x1, y1, x2, y2):
            return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1]

        r, ans = min(m, n), 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                for c in range(ans + 1, r + 1):
                    if (
                        i + c - 1 <= m
                        and j + c - 1 <= n
                        and getRect(i, j, i + c - 1, j + c - 1) <= threshold
                    ):
                        ans += 1
                    else:
                        break
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxSideLength(mat: number[][], threshold: number): number {
    const m = mat.length,
        n = mat[0].length;
    const P: number[][] = Array.from({ length: m + 1 }, () =>
        new Array(n + 1).fill(0),
    );

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            P[i][j] =
                P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    const getRect = (
        x1: number,
        y1: number,
        x2: number,
        y2: number,
    ): number => {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    };

    const r = Math.min(m, n);
    let ans = 0;
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            for (let c = ans + 1; c <= r; c++) {
                if (
                    i + c - 1 <= m &&
                    j + c - 1 <= n &&
                    getRect(i, j, i + c - 1, j + c - 1) <= threshold
                ) {
                    ans = c;
                } else {
                    break;
                }
            }
        }
    }
    return ans;
}
```

</details>
