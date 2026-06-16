# 1536. Minimum Swaps to Arrange a Binary Grid

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/)  
`Array` `Greedy` `Matrix`

**Problem Link:** [LeetCode 1536 - Minimum Swaps to Arrange a Binary Grid](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/)

## Problem

Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

### Example 1

```text
Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3
```

### Example 2

```text
Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.
```

### Example 3

```text
Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0
```

## Constraints

- n == grid.length == grid[i].length
- 1 <= n <= 200
- grid[i][j] is either 0 or 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1536. Minimum Swaps to Arrange a Binary Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int* pos = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        pos[i] = -1;
        for (int j = n - 1; j >= 0; --j) {
            if (grid[i][j] == 1) {
                pos[i] = j;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = -1;
        for (int j = i; j < n; ++j) {
            if (pos[j] <= i) {
                ans += j - i;
                k = j;
                break;
            }
        }

        if (k != -1) {
            for (int j = k; j > i; --j) {
                int temp = pos[j];
                pos[j] = pos[j - 1];
                pos[j - 1] = temp;
            }
        } else {
            free(pos);
            return -1;
        }
    }

    free(pos);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> pos(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    pos[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = i; j < n; ++j) {
                if (pos[j] <= i) {
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if (~k) {
                for (int j = k; j > i; --j) {
                    swap(pos[j], pos[j - 1]);
                }
            } else {
                return -1;
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
    public int MinSwaps(int[][] grid) {
        int n = grid.Length;
        int[] pos = new int[n];
        Array.Fill(pos, -1);

        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    pos[i] = j;
                    break;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = i; j < n; ++j) {
                if (pos[j] <= i) {
                    ans += j - i;
                    k = j;
                    break;
                }
            }

            if (k != -1) {
                for (int j = k; j > i; --j) {
                    (pos[j], pos[j - 1]) = (pos[j - 1], pos[j]);
                }
            } else {
                return -1;
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
func minSwaps(grid [][]int) int {
	n := len(grid)
	pos := make([]int, n)
	for i := range pos {
		pos[i] = -1
	}

	for i := 0; i < n; i++ {
		for j := n - 1; j >= 0; j-- {
			if grid[i][j] == 1 {
				pos[i] = j
				break
			}
		}
	}

	ans := 0
	for i := 0; i < n; i++ {
		k := -1
		for j := i; j < n; j++ {
			if pos[j] <= i {
				ans += j - i
				k = j
				break
			}
		}

		if k != -1 {
			for j := k; j > i; j-- {
				pos[j], pos[j-1] = pos[j-1], pos[j]
			}
		} else {
			return -1
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

    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int[] pos = new int[n];
        Arrays.fill(pos, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    pos[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = i; j < n; ++j) {
                if (pos[j] <= i) {
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if (k >= 0) {
                for (int j = k; j > i; --j) {
                    int temp = pos[j];
                    pos[j] = pos[j - 1];
                    pos[j - 1] = temp;
                }
            } else {
                return -1;
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
var minSwaps = function (grid) {
    const n = grid.length;
    const pos = new Array(n).fill(-1);
    for (let i = 0; i < n; ++i) {
        for (let j = n - 1; j >= 0; --j) {
            if (grid[i][j] == 1) {
                pos[i] = j;
                break;
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let k = -1;
        for (let j = i; j < n; ++j) {
            if (pos[j] <= i) {
                ans += j - i;
                k = j;
                break;
            }
        }
        if (~k) {
            for (let j = k; j > i; --j) {
                const temp = pos[j];
                pos[j] = pos[j - 1];
                pos[j - 1] = temp;
            }
        } else {
            return -1;
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
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        pos = [-1] * n
        for i in range(n):
            for j in range(n - 1, -1, -1):
                if grid[i][j] == 1:
                    pos[i] = j
                    break

        ans = 0
        for i in range(n):
            k = -1
            for j in range(i, n):
                if pos[j] <= i:
                    ans += j - i
                    k = j
                    break

            if k != -1:
                for j in range(k, i, -1):
                    pos[j], pos[j - 1] = pos[j - 1], pos[j]
            else:
                return -1

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minSwaps(grid: number[][]): number {
    const n: number = grid.length;
    const pos: number[] = new Array(n).fill(-1);

    for (let i = 0; i < n; ++i) {
        for (let j = n - 1; j >= 0; --j) {
            if (grid[i][j] === 1) {
                pos[i] = j;
                break;
            }
        }
    }

    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let k = -1;
        for (let j = i; j < n; ++j) {
            if (pos[j] <= i) {
                ans += j - i;
                k = j;
                break;
            }
        }

        if (k !== -1) {
            for (let j = k; j > i; --j) {
                [pos[j], pos[j - 1]] = [pos[j - 1], pos[j]];
            }
        } else {
            return -1;
        }
    }
    return ans;
}
```

</details>
