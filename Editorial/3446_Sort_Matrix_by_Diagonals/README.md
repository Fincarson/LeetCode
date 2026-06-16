# 3446. Sort Matrix by Diagonals

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/sort-matrix-by-diagonals/)  
`Array` `Sorting` `Matrix`

**Problem Link:** [LeetCode 3446 - Sort Matrix by Diagonals](https://leetcode.com/problems/sort-matrix-by-diagonals/)

## Problem

You are given an n x n square matrix of integers grid. Return the matrix such that:

- The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
- The diagonals in the top-right triangle are sorted in non-decreasing order.

### Example 1

### Example 2

### Example 3

## Constraints

- grid.length == grid[i].length == n
- 1 <= n <= 10
- -105 <= grid[i][j] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort the Matrix Diagonally](https://leetcode.com/problems/sort-the-matrix-diagonally/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3446. Sort Matrix by Diagonals

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp_desc(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int cmp_asc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize,
                 int** returnColumnSizes) {
    int n = gridSize;

    int** res = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        res[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            res[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int tmp[15], len = 0;
        for (int j = 0; i + j < n; j++) {
            tmp[len++] = res[i + j][j];
        }
        qsort(tmp, len, sizeof(int), cmp_desc);
        for (int j = 0; i + j < n; j++) {
            res[i + j][j] = tmp[j];
        }
    }

    for (int j = 1; j < n; j++) {
        int tmp[15], len = 0;
        for (int i = 0; j + i < n; i++) {
            tmp[len++] = res[i][j + i];
        }
        qsort(tmp, len, sizeof(int), cmp_asc);
        for (int i = 0; j + i < n; i++) {
            res[i][j + i] = tmp[i];
        }
    }

    *returnSize = n;
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; i + j < n; j++) {
                tmp.push_back(grid[i + j][j]);
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = tmp[j];
            }
        }
        for (int j = 1; j < n; j++) {
            vector<int> tmp;
            for (int i = 0; j + i < n; i++) {
                tmp.push_back(grid[i][j + i]);
            }
            sort(tmp.begin(), tmp.end());
            for (int i = 0; j + i < n; i++) {
                grid[i][j + i] = tmp[i];
            }
        }
        return grid;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] SortMatrix(int[][] grid) {
        int n = grid.Length;

        for (int i = 0; i < n; i++) {
            List<int> tmp = new List<int>();
            for (int j = 0; i + j < n; j++) {
                tmp.Add(grid[i + j][j]);
            }
            tmp.Sort((a, b) => b.CompareTo(a));
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = tmp[j];
            }
        }

        for (int j = 1; j < n; j++) {
            List<int> tmp = new List<int>();
            for (int i = 0; j + i < n; i++) {
                tmp.Add(grid[i][j + i]);
            }
            tmp.Sort();
            for (int i = 0; j + i < n; i++) {
                grid[i][j + i] = tmp[i];
            }
        }

        return grid;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sortMatrix(grid [][]int) [][]int {
	n := len(grid)

	for i := 0; i < n; i++ {
		tmp := []int{}
		for j := 0; i+j < n; j++ {
			tmp = append(tmp, grid[i+j][j])
		}
		sort.Sort(sort.Reverse(sort.IntSlice(tmp)))
		for j := 0; i+j < n; j++ {
			grid[i+j][j] = tmp[j]
		}
	}

	for j := 1; j < n; j++ {
		tmp := []int{}
		for i := 0; j+i < n; i++ {
			tmp = append(tmp, grid[i][j+i])
		}
		sort.Ints(tmp)
		for i := 0; j+i < n; i++ {
			grid[i][j+i] = tmp[i]
		}
	}

	return grid
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;

        for (int i = 0; i < n; i++) {
            List<Integer> tmp = new ArrayList<>();
            for (int j = 0; i + j < n; j++) {
                tmp.add(grid[i + j][j]);
            }
            tmp.sort(Collections.reverseOrder());
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = tmp.get(j);
            }
        }

        for (int j = 1; j < n; j++) {
            List<Integer> tmp = new ArrayList<>();
            for (int i = 0; j + i < n; i++) {
                tmp.add(grid[i][j + i]);
            }
            Collections.sort(tmp);
            for (int i = 0; j + i < n; i++) {
                grid[i][j + i] = tmp.get(i);
            }
        }

        return grid;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortMatrix = function (grid) {
    const n = grid.length;

    for (let i = 0; i < n; i++) {
        let tmp = [];
        for (let j = 0; i + j < n; j++) {
            tmp.push(grid[i + j][j]);
        }
        tmp.sort((a, b) => b - a);
        for (let j = 0; i + j < n; j++) {
            grid[i + j][j] = tmp[j];
        }
    }

    for (let j = 1; j < n; j++) {
        let tmp = [];
        for (let i = 0; j + i < n; i++) {
            tmp.push(grid[i][j + i]);
        }
        tmp.sort((a, b) => a - b);
        for (let i = 0; j + i < n; i++) {
            grid[i][j + i] = tmp[i];
        }
    }

    return grid;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)

        for i in range(n):
            tmp = [grid[i + j][j] for j in range(n - i)]
            tmp.sort(reverse=True)
            for j in range(n - i):
                grid[i + j][j] = tmp[j]

        for j in range(1, n):
            tmp = [grid[i][j + i] for i in range(n - j)]
            tmp.sort()
            for i in range(n - j):
                grid[i][j + i] = tmp[i]

        return grid
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sortMatrix(grid: number[][]): number[][] {
    const n = grid.length;

    for (let i = 0; i < n; i++) {
        let tmp: number[] = [];
        for (let j = 0; i + j < n; j++) {
            tmp.push(grid[i + j][j]);
        }
        tmp.sort((a, b) => b - a);
        for (let j = 0; i + j < n; j++) {
            grid[i + j][j] = tmp[j];
        }
    }

    for (let j = 1; j < n; j++) {
        let tmp: number[] = [];
        for (let i = 0; j + i < n; i++) {
            tmp.push(grid[i][j + i]);
        }
        tmp.sort((a, b) => a - b);
        for (let i = 0; j + i < n; i++) {
            grid[i][j + i] = tmp[i];
        }
    }

    return grid;
}
```

</details>
