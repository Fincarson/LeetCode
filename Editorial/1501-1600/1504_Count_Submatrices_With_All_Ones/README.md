# 1504. Count Submatrices With All Ones

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-submatrices-with-all-ones/)  
`Array` `Dynamic Programming` `Stack` `Matrix` `Monotonic Stack`

**Problem Link:** [LeetCode 1504 - Count Submatrices With All Ones](https://leetcode.com/problems/count-submatrices-with-all-ones/)

## Problem

Given an m x n binary matrix mat, return the number of submatrices that have all ones.

### Example 1

```text
Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2.
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
```

### Example 2

```text
Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3.
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2.
There are 2 rectangles of side 3x1.
There is 1 rectangle of side 3x2.
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
```

## Constraints

- 1 <= m, n <= 150
- mat[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Submatrices With Equal Frequency of X and Y](https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1504. Count Submatrices With All Ones

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Monotonic Stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numSubmat(int** mat, int matSize, int* matColSize) {
    int m = matSize, n = matColSize[0];
    int res = 0;
    int** row = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        row[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                row[i][j] = mat[i][j];
            } else {
                row[i][j] = mat[i][j] == 0 ? 0 : row[i][j - 1] + 1;
            }
            int cur = row[i][j];
            for (int k = i; k >= 0; k--) {
                cur = cur < row[k][j] ? cur : row[k][j];
                if (cur == 0) {
                    break;
                }
                res += cur;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        free(row[i]);
    }
    free(row);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        vector<vector<int>> row(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    row[i][j] = mat[i][j];
                } else {
                    row[i][j] = (mat[i][j] == 0) ? 0 : row[i][j - 1] + 1;
                }
                int cur = row[i][j];
                for (int k = i; k >= 0; --k) {
                    cur = min(cur, row[k][j]);
                    if (cur == 0) {
                        break;
                    }
                    res += cur;
                }
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumSubmat(int[][] mat) {
        int m = mat.Length, n = mat[0].Length;
        int res = 0;
        int[][] row = new int [m][];
        for (int i = 0; i < m; i++) {
            row[i] = new int[n];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    row[i][j] = mat[i][j];
                } else {
                    row[i][j] = mat[i][j] == 0 ? 0 : row[i][j - 1] + 1;
                }
                int cur = row[i][j];
                for (int k = i; k >= 0; k--) {
                    cur = Math.Min(cur, row[k][j]);
                    if (cur == 0) {
                        break;
                    }
                    res += cur;
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numSubmat(mat [][]int) int {
	m, n := len(mat), len(mat[0])
	res := 0
	row := make([][]int, m)
	for i := range row {
		row[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if j == 0 {
				row[i][j] = mat[i][j]
			} else {
				if mat[i][j] == 0 {
					row[i][j] = 0
				} else {
					row[i][j] = row[i][j-1] + 1
				}
			}
			cur := row[i][j]
			for k := i; k >= 0; k-- {
				if row[k][j] < cur {
					cur = row[k][j]
				}
				if cur == 0 {
					break
				}
				res += cur
			}
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numSubmat(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int res = 0;
        int[][] row = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    row[i][j] = mat[i][j];
                } else {
                    row[i][j] = mat[i][j] == 0 ? 0 : row[i][j - 1] + 1;
                }
                int cur = row[i][j];
                for (int k = i; k >= 0; k--) {
                    cur = Math.min(cur, row[k][j]);
                    if (cur == 0) {
                        break;
                    }
                    res += cur;
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numSubmat = function (mat) {
    const m = mat.length,
        n = mat[0].length;
    let res = 0;
    const row = new Array(m);
    for (let i = 0; i < m; i++) {
        row[i] = new Array(n).fill(0);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (j === 0) {
                row[i][j] = mat[i][j];
            } else {
                row[i][j] = mat[i][j] === 0 ? 0 : row[i][j - 1] + 1;
            }
            let cur = row[i][j];
            for (let k = i; k >= 0; k--) {
                cur = Math.min(cur, row[k][j]);
                if (cur === 0) {
                    break;
                }
                res += cur;
            }
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        res = 0
        row = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if j == 0:
                    row[i][j] = mat[i][j]
                else:
                    row[i][j] = 0 if mat[i][j] == 0 else row[i][j - 1] + 1
                cur = row[i][j]
                for k in range(i, -1, -1):
                    cur = min(cur, row[k][j])
                    if cur == 0:
                        break
                    res += cur
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numSubmat(mat: number[][]): number {
    const m = mat.length,
        n = mat[0].length;
    let res = 0;
    const row: number[][] = new Array(m);
    for (let i = 0; i < m; i++) {
        row[i] = new Array(n).fill(0);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (j === 0) {
                row[i][j] = mat[i][j];
            } else {
                row[i][j] = mat[i][j] === 0 ? 0 : row[i][j - 1] + 1;
            }
            let cur = row[i][j];
            for (let k = i; k >= 0; k--) {
                cur = Math.min(cur, row[k][j]);
                if (cur === 0) {
                    break;
                }
                res += cur;
            }
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: Monotonic Stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numSubmat(int** mat, int matSize, int* matColSize) {
    int n = matColSize[0];
    int heights[n];
    int res = 0;
    memset(heights, 0, sizeof(heights));

    int stack[n + 1][3];
    int top = 0;
    for (int r = 0; r < matSize; r++) {
        for (int i = 0; i < n; i++) {
            heights[i] = mat[r][i] == 0 ? 0 : heights[i] + 1;
        }
        top = 0;
        stack[top][0] = -1;
        stack[top][1] = 0;
        stack[top][2] = -1;
        top++;
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            while (top > 0 && stack[top - 1][2] >= h) {
                top--;
            }
            int j = stack[top - 1][0];
            int prev = stack[top - 1][1];
            int cur = prev + (i - j) * h;
            stack[top][0] = i;
            stack[top][1] = cur;
            stack[top][2] = h;
            top++;
            res += cur;
        }
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat[0].size();
        vector<int> heights(n, 0);
        int res = 0;
        for (const auto& row : mat) {
            for (int i = 0; i < n; ++i) {
                heights[i] = (row[i] == 0) ? 0 : heights[i] + 1;
            }
            stack<vector<int>> st;
            st.push({-1, 0, -1});
            for (int i = 0; i < n; ++i) {
                int h = heights[i];
                while (st.top()[2] >= h) {
                    st.pop();
                }
                auto& top = st.top();
                int j = top[0];
                int prev = top[1];
                int cur = prev + (i - j) * h;
                st.push({i, cur, h});
                res += cur;
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumSubmat(int[][] mat) {
        int n = mat[0].Length;
        int[] heights = new int[n];
        int res = 0;
        foreach (var row in mat) {
            for (int i = 0; i < n; i++) {
                heights[i] = row[i] == 0 ? 0 : heights[i] + 1;
            }
            var stack = new Stack<int[]>();
            stack.Push(new int[] { -1, 0, -1 });
            for (int i = 0; i < n; i++) {
                int h = heights[i];
                while (stack.Peek()[2] >= h) {
                    stack.Pop();
                }
                var top = stack.Peek();
                int j = top[0];
                int prev = top[1];
                int cur = prev + (i - j) * h;
                stack.Push(new int[] { i, cur, h });
                res += cur;
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numSubmat(mat [][]int) int {
	n := len(mat[0])
	heights := make([]int, n)
	res := 0
	for _, row := range mat {
		for i := 0; i < n; i++ {
			if row[i] == 0 {
				heights[i] = 0
			} else {
				heights[i]++
			}
		}
		stack := [][3]int{{-1, 0, -1}}
		for i, h := range heights {
			for len(stack) > 1 && stack[len(stack)-1][2] >= h {
				stack = stack[:len(stack)-1]
			}
			top := stack[len(stack)-1]
			j, prev := top[0], top[1]
			cur := prev + (i-j)*h
			stack = append(stack, [3]int{i, cur, h})
			res += cur
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numSubmat(int[][] mat) {
        int n = mat[0].length;
        int[] heights = new int[n];
        int res = 0;
        for (int[] row : mat) {
            for (int i = 0; i < n; i++) {
                heights[i] = row[i] == 0 ? 0 : heights[i] + 1;
            }
            Stack<int[]> stack = new Stack<>();
            stack.push(new int[] { -1, 0, -1 });
            for (int i = 0; i < n; i++) {
                int h = heights[i];
                while (stack.peek()[2] >= h) {
                    stack.pop();
                }
                int[] top = stack.peek();
                int j = top[0];
                int prev = top[1];
                int cur = prev + (i - j) * h;
                stack.push(new int[] { i, cur, h });
                res += cur;
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numSubmat = function (mat) {
    const n = mat[0].length;
    const heights = new Array(n).fill(0);
    let res = 0;
    for (const row of mat) {
        for (let i = 0; i < n; i++) {
            heights[i] = row[i] === 0 ? 0 : heights[i] + 1;
        }
        const stack = [[-1, 0, -1]];
        for (let i = 0; i < n; i++) {
            const h = heights[i];
            while (stack[stack.length - 1][2] >= h) {
                stack.pop();
            }
            const [j, prev] = stack[stack.length - 1];
            const cur = prev + (i - j) * h;
            stack.push([i, cur, h]);
            res += cur;
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        heights = [0] * len(mat[0])
        res = 0
        for row in mat:
            for i, x in enumerate(row):
                heights[i] = 0 if x == 0 else heights[i] + 1
            stack = [[-1, 0, -1]]
            for i, h in enumerate(heights):
                while stack[-1][2] >= h:
                    stack.pop()
                j, prev, _ = stack[-1]
                cur = prev + (i - j) * h
                stack.append([i, cur, h])
                res += cur
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numSubmat(mat: number[][]): number {
    const n = mat[0].length;
    const heights: number[] = new Array(n).fill(0);
    let res = 0;
    for (const row of mat) {
        for (let i = 0; i < n; i++) {
            heights[i] = row[i] === 0 ? 0 : heights[i] + 1;
        }
        const stack: [number, number, number][] = [[-1, 0, -1]];
        for (let i = 0; i < n; i++) {
            const h = heights[i];
            while (stack[stack.length - 1][2] >= h) {
                stack.pop();
            }
            const [j, prev] = stack[stack.length - 1];
            const cur = prev + (i - j) * h;
            stack.push([i, cur, h]);
            res += cur;
        }
    }
    return res;
}
```

</details>
