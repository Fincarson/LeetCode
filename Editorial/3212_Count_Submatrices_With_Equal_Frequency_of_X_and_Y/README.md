# 3212. Count Submatrices With Equal Frequency of X and Y

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/)  
`Array` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 3212 - Count Submatrices With Equal Frequency of X and Y](https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/)

## Problem

Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:

- grid[0][0]
- an equal frequency of 'X' and 'Y'.
- at least one 'X'.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= grid.length, grid[i].length <= 1000
- grid[i][j] is either 'X', 'Y', or '.'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Equal Frequency](https://leetcode.com/problems/maximum-equal-frequency/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Submatrices With All Ones](https://leetcode.com/problems/count-submatrices-with-all-ones/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3212. Count Submatrices With Equal Frequency of X and Y

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: 2D Prefix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: 2D Prefix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = gridColSize[0];
    int ans = 0;
    int sum[n + 1][m + 1][2];

    memset(sum, 0, sizeof(sum));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1;
                sum[i + 1][j + 1][1] = 1;
            } else if (grid[i][j] == 'Y') {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1;
                sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
            } else {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
            }
            if (sum[i + 1][j + 1][0] == 0 && sum[i + 1][j + 1][1] == 1) {
                ans++;
            }
        }
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<array<int, 2>>> sum(n + 1, vector<array<int, 2>>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    sum[i + 1][j + 1][0] =
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1;
                    sum[i + 1][j + 1][1] = 1;
                } else if (grid[i][j] == 'Y') {
                    sum[i + 1][j + 1][0] =
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1;
                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
                } else {
                    sum[i + 1][j + 1][0] =
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
                }
                ans += (!sum[i + 1][j + 1][0] && sum[i + 1][j + 1][1]) ? 1 : 0;
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
    public int NumberOfSubmatrices(char[][] grid) {
        int n = grid.Length, m = grid[0].Length;
        int ans = 0;
        int[,,] sum = new int[n + 1, m + 1, 2];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    sum[i + 1, j + 1, 0] =
                        sum[i + 1, j, 0] + sum[i, j + 1, 0] - sum[i, j, 0] + 1;
                    sum[i + 1, j + 1, 1] = 1;
                } else if (grid[i][j] == 'Y') {
                    sum[i + 1, j + 1, 0] =
                        sum[i + 1, j, 0] + sum[i, j + 1, 0] - sum[i, j, 0] - 1;
                    sum[i + 1, j + 1, 1] =
                        (sum[i + 1, j, 1] | sum[i, j + 1, 1]) == 1 ? 1 : 0;
                } else {
                    sum[i + 1, j + 1, 0] =
                        sum[i + 1, j, 0] + sum[i, j + 1, 0] - sum[i, j, 0];
                    sum[i + 1, j + 1, 1] =
                        (sum[i + 1, j, 1] | sum[i, j + 1, 1]) == 1 ? 1 : 0;
                }

                if (sum[i + 1, j + 1, 0] == 0 && sum[i + 1, j + 1, 1] == 1) {
                    ans++;
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
func numberOfSubmatrices(grid [][]byte) int {
    n := len(grid)
    m := len(grid[0])
    ans := 0

    sum := make([][][]int, n+1)
    for i := range sum {
        sum[i] = make([][]int, m+1)
        for j := range sum[i] {
            sum[i][j] = make([]int, 2)
        }
    }

    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if grid[i][j] == 'X' {
                sum[i+1][j+1][0] = sum[i+1][j][0] + sum[i][j+1][0] - sum[i][j][0] + 1
                sum[i+1][j+1][1] = 1
            } else if grid[i][j] == 'Y' {
                sum[i+1][j+1][0] = sum[i+1][j][0] + sum[i][j+1][0] - sum[i][j][0] - 1
                if sum[i+1][j][1] == 1 || sum[i][j+1][1] == 1 {
                    sum[i+1][j+1][1] = 1
                } else {
                    sum[i+1][j+1][1] = 0
                }
            } else {
                sum[i+1][j+1][0] = sum[i+1][j][0] + sum[i][j+1][0] - sum[i][j][0]
                if sum[i+1][j][1] == 1 || sum[i][j+1][1] == 1 {
                    sum[i+1][j+1][1] = 1
                } else {
                    sum[i+1][j+1][1] = 0
                }
            }

            if sum[i+1][j+1][0] == 0 && sum[i+1][j+1][1] == 1 {
                ans++
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

    public int numberOfSubmatrices(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int ans = 0;
        int[][][] sum = new int[n + 1][m + 1][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    sum[i + 1][j + 1][0] =
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1;
                    sum[i + 1][j + 1][1] = 1;
                } else if (grid[i][j] == 'Y') {
                    sum[i + 1][j + 1][0] =
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1;
                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
                } else {
                    sum[i + 1][j + 1][0] =
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
                }
                ans += (sum[i + 1][j + 1][0] == 0 && sum[i + 1][j + 1][1] == 1)
                    ? 1
                    : 0;
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
var numberOfSubmatrices = function (grid) {
    const n = grid.length,
        m = grid[0].length;
    let ans = 0;
    const sum = new Array(n + 1)
        .fill(0)
        .map(() => new Array(m + 1).fill(0).map(() => [0, 0]));

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (grid[i][j] === "X") {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1;
                sum[i + 1][j + 1][1] = 1;
            } else if (grid[i][j] === "Y") {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1;
                sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
            } else {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
            }
            if (sum[i + 1][j + 1][0] === 0 && sum[i + 1][j + 1][1] === 1) {
                ans++;
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
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        n, m = len(grid), len(grid[0])
        ans = 0
        sum = [[[0, 0] for _ in range(m + 1)] for _ in range(n + 1)]

        for i in range(n):
            for j in range(m):
                if grid[i][j] == "X":
                    sum[i + 1][j + 1][0] = (
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1
                    )
                    sum[i + 1][j + 1][1] = 1
                elif grid[i][j] == "Y":
                    sum[i + 1][j + 1][0] = (
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1
                    )
                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1]
                else:
                    sum[i + 1][j + 1][0] = (
                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0]
                    )
                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1]
                if sum[i + 1][j + 1][0] == 0 and sum[i + 1][j + 1][1] == 1:
                    ans += 1

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfSubmatrices(grid: string[][]): number {
    const n = grid.length;
    const m = grid[0].length;
    let ans = 0;

    const sum: number[][][] = Array(n + 1)
        .fill(null)
        .map(() =>
            Array(m + 1)
                .fill(null)
                .map(() => [0, 0]),
        );

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (grid[i][j] === "X") {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1;
                sum[i + 1][j + 1][1] = 1;
            } else if (grid[i][j] === "Y") {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1;
                sum[i + 1][j + 1][1] =
                    sum[i + 1][j][1] | sum[i][j + 1][1] ? 1 : 0;
            } else {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                sum[i + 1][j + 1][1] =
                    sum[i + 1][j][1] | sum[i][j + 1][1] ? 1 : 0;
            }

            if (sum[i + 1][j + 1][0] === 0 && sum[i + 1][j + 1][1] === 1) {
                ans++;
            }
        }
    }
    return ans;
}
```

</details>
