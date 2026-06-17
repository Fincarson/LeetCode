# 1878. Get Biggest Three Rhombus Sums in a Grid

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/)  
`Array` `Math` `Sorting` `Heap (Priority Queue)` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 1878 - Get Biggest Three Rhombus Sums in a Grid](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/)

## Problem

You are given an m x n integer matrix gridÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in gridÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:

Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

### Example 1

```text
Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
```

### Example 2

```text
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)
```

### Example 3

```text
Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 50
- 1 <= grid[i][j] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Fertile Pyramids in a Land](https://leetcode.com/problems/count-fertile-pyramids-in-a-land/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1878. Get Biggest Three Rhombus Sums in a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumerate All Rhombuses | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumerate All Rhombuses

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int ans[3];
} Answer;

void answerPut(Answer* a, int x) {
    if (x > a->ans[0]) {
        a->ans[2] = a->ans[1];
        a->ans[1] = a->ans[0];
        a->ans[0] = x;
    } else if (x != a->ans[0] && x > a->ans[1]) {
        a->ans[2] = a->ans[1];
        a->ans[1] = x;
    } else if (x != a->ans[0] && x != a->ans[1] && x > a->ans[2]) {
        a->ans[2] = x;
    }
}

int* answerGet(Answer* a, int* returnSize) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (a->ans[i] != 0) {
            count++;
        }
    }

    int* ret = (int*)malloc(count * sizeof(int));
    *returnSize = count;
    int idx = 0;
    for (int i = 0; i < 3; i++) {
        if (a->ans[i] != 0) {
            ret[idx++] = a->ans[i];
        }
    }

    return ret;
}

int* getBiggestThree(int** grid, int gridSize, int* gridColSize,
                     int* returnSize) {
    int m = gridSize, n = gridColSize[0];
    int** sum1 = (int**)malloc((m + 1) * sizeof(int*));
    int** sum2 = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        sum1[i] = (int*)calloc(n + 2, sizeof(int));
        sum2[i] = (int*)calloc(n + 2, sizeof(int));
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1];
            sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1];
        }
    }

    Answer ans = {{0}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // a single cell is also a rhombus
            answerPut(&ans, grid[i][j]);
            for (int k = i + 2; k < m; k += 2) {
                int ux = i, uy = j;
                int dx = k, dy = j;
                int lx = (i + k) / 2, ly = j - (k - i) / 2;
                int rx = (i + k) / 2, ry = j + (k - i) / 2;
                if (ly < 0 || ry >= n) {
                    break;
                }
                int sum =
                    (sum2[lx + 1][ly + 1] - sum2[ux][uy + 2]) +
                    (sum1[rx + 1][ry + 1] - sum1[ux][uy]) +
                    (sum1[dx + 1][dy + 1] - sum1[lx][ly]) +
                    (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) -
                    (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] + grid[rx][ry]);
                answerPut(&ans, sum);
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        free(sum1[i]);
        free(sum2[i]);
    }
    free(sum1);
    free(sum2);

    return answerGet(&ans, returnSize);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
struct Answer {
    array<int, 3> ans{};

    void put(int x) {
        if (x > ans[0]) {
            tie(ans[0], ans[1], ans[2]) = tuple{x, ans[0], ans[1]};
        } else if (x != ans[0] && x > ans[1]) {
            tie(ans[1], ans[2]) = tuple{x, ans[1]};
        } else if (x != ans[0] && x != ans[1] && x > ans[2]) {
            ans[2] = x;
        }
    }

    vector<int> get() const {
        vector<int> ret;
        for (int num : ans) {
            if (num) {
                ret.push_back(num);
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum1(m + 1, vector<int>(n + 2));
        vector<vector<int>> sum2(m + 1, vector<int>(n + 2));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1];
                sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        Answer ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // a single cell is also a rhombus
                ans.put(grid[i][j]);
                for (int k = i + 2; k < m; k += 2) {
                    int ux = i, uy = j;
                    int dx = k, dy = j;
                    int lx = (i + k) / 2, ly = j - (k - i) / 2;
                    int rx = (i + k) / 2, ry = j + (k - i) / 2;
                    if (ly < 0 || ry >= n) {
                        break;
                    }
                    ans.put((sum2[lx + 1][ly + 1] - sum2[ux][uy + 2]) +
                            (sum1[rx + 1][ry + 1] - sum1[ux][uy]) +
                            (sum1[dx + 1][dy + 1] - sum1[lx][ly]) +
                            (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) -
                            (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] +
                             grid[rx][ry]));
                }
            }
        }
        return ans.get();
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Answer {
    private int[] ans;

    public Answer() {
        ans = new int[3];
    }

    public void Put(int x) {
        if (x > ans[0]) {
            ans[2] = ans[1];
            ans[1] = ans[0];
            ans[0] = x;
        } else if (x != ans[0] && x > ans[1]) {
            ans[2] = ans[1];
            ans[1] = x;
        } else if (x != ans[0] && x != ans[1] && x > ans[2]) {
            ans[2] = x;
        }
    }

    public List<int> Get() {
        List<int> ret = new List<int>();
        foreach (int num in ans) {
            if (num != 0) {
                ret.Add(num);
            }
        }
        return ret;
    }
}

public class Solution {
    public int[] GetBiggestThree(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int[,] sum1 = new int[m + 1, n + 2];
        int[,] sum2 = new int[m + 1, n + 2];

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum1[i, j] = sum1[i - 1, j - 1] + grid[i - 1][j - 1];
                sum2[i, j] = sum2[i - 1, j + 1] + grid[i - 1][j - 1];
            }
        }

        Answer ans = new Answer();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // a single cell is also a rhombus
                ans.Put(grid[i][j]);
                for (int k = i + 2; k < m; k += 2) {
                    int ux = i, uy = j;
                    int dx = k, dy = j;
                    int lx = (i + k) / 2, ly = j - (k - i) / 2;
                    int rx = (i + k) / 2, ry = j + (k - i) / 2;
                    if (ly < 0 || ry >= n) {
                        break;
                    }
                    int sum = (sum2[lx + 1, ly + 1] - sum2[ux, uy + 2]) +
                              (sum1[rx + 1, ry + 1] - sum1[ux, uy]) +
                              (sum1[dx + 1, dy + 1] - sum1[lx, ly]) +
                              (sum2[dx + 1, dy + 1] - sum2[rx, ry + 2]) -
                              (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] +
                               grid[rx][ry]);
                    ans.Put(sum);
                }
            }
        }

        List<int> resultList = ans.Get();
        return resultList.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Answer struct {
	ans [3]int
}

func (this *Answer) put(x int) {
	if x > this.ans[0] {
		this.ans[2] = this.ans[1]
		this.ans[1] = this.ans[0]
		this.ans[0] = x
	} else if x != this.ans[0] && x > this.ans[1] {
		this.ans[2] = this.ans[1]
		this.ans[1] = x
	} else if x != this.ans[0] && x != this.ans[1] && x > this.ans[2] {
		this.ans[2] = x
	}
}

func (this *Answer) get() []int {
	var ret []int
	for _, num := range this.ans {
		if num != 0 {
			ret = append(ret, num)
		}
	}
	return ret
}

func getBiggestThree(grid [][]int) []int {
	m, n := len(grid), len(grid[0])
	sum1 := make([][]int, m+1)
	sum2 := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		sum1[i] = make([]int, n+2)
		sum2[i] = make([]int, n+2)
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			sum1[i][j] = sum1[i-1][j-1] + grid[i-1][j-1]
			sum2[i][j] = sum2[i-1][j+1] + grid[i-1][j-1]
		}
	}

	ans := Answer{}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			// a single cell is also a rhombus
			ans.put(grid[i][j])
			for k := i + 2; k < m; k += 2 {
				ux, uy := i, j
				dx, dy := k, j
				lx, ly := (i+k)/2, j-(k-i)/2
				rx, ry := (i+k)/2, j+(k-i)/2
				if ly < 0 || ry >= n {
					break
				}
				sum := (sum2[lx+1][ly+1] - sum2[ux][uy+2]) +
					(sum1[rx+1][ry+1] - sum1[ux][uy]) +
					(sum1[dx+1][dy+1] - sum1[lx][ly]) +
					(sum2[dx+1][dy+1] - sum2[rx][ry+2]) -
					(grid[ux][uy] + grid[dx][dy] + grid[lx][ly] + grid[rx][ry])

				ans.put(sum)
			}
		}
	}

	return ans.get()
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Answer {

    int[] ans;

    public Answer() {
        ans = new int[3];
    }

    void put(int x) {
        if (x > ans[0]) {
            ans[2] = ans[1];
            ans[1] = ans[0];
            ans[0] = x;
        } else if (x != ans[0] && x > ans[1]) {
            ans[2] = ans[1];
            ans[1] = x;
        } else if (x != ans[0] && x != ans[1] && x > ans[2]) {
            ans[2] = x;
        }
    }

    List<Integer> get() {
        List<Integer> ret = new ArrayList<>();
        for (int num : ans) {
            if (num != 0) {
                ret.add(num);
            }
        }
        return ret;
    }
}

class Solution {

    public int[] getBiggestThree(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] sum1 = new int[m + 1][n + 2];
        int[][] sum2 = new int[m + 1][n + 2];

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1];
                sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }

        Answer ans = new Answer();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // a single cell is also a rhombus
                ans.put(grid[i][j]);
                for (int k = i + 2; k < m; k += 2) {
                    int ux = i;
                    int uy = j;
                    int dx = k;
                    int dy = j;
                    int lx = (i + k) / 2;
                    int ly = j - (k - i) / 2;
                    int rx = (i + k) / 2;
                    int ry = j + (k - i) / 2;
                    if (ly < 0 || ry >= n) {
                        break;
                    }
                    int sum =
                        (sum2[lx + 1][ly + 1] - sum2[ux][uy + 2]) +
                        (sum1[rx + 1][ry + 1] - sum1[ux][uy]) +
                        (sum1[dx + 1][dy + 1] - sum1[lx][ly]) +
                        (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) -
                        (grid[ux][uy] +
                            grid[dx][dy] +
                            grid[lx][ly] +
                            grid[rx][ry]);
                    ans.put(sum);
                }
            }
        }

        List<Integer> resultList = ans.get();
        int[] result = new int[resultList.size()];
        for (int i = 0; i < resultList.size(); i++) {
            result[i] = resultList.get(i);
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class Answer {
    constructor() {
        this.ans = [0, 0, 0];
    }

    put(x) {
        if (x > this.ans[0]) {
            this.ans[2] = this.ans[1];
            this.ans[1] = this.ans[0];
            this.ans[0] = x;
        } else if (x !== this.ans[0] && x > this.ans[1]) {
            this.ans[2] = this.ans[1];
            this.ans[1] = x;
        } else if (x !== this.ans[0] && x !== this.ans[1] && x > this.ans[2]) {
            this.ans[2] = x;
        }
    }

    get() {
        const ret = [];
        for (const num of this.ans) {
            if (num !== 0) {
                ret.push(num);
            }
        }
        return ret;
    }
}

var getBiggestThree = function (grid) {
    const m = grid.length,
        n = grid[0].length;
    const sum1 = Array.from({ length: m + 1 }, () => new Array(n + 2).fill(0));
    const sum2 = Array.from({ length: m + 1 }, () => new Array(n + 2).fill(0));

    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1];
            sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1];
        }
    }

    const ans = new Answer();
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            // a single cell is also a rhombus
            ans.put(grid[i][j]);
            for (let k = i + 2; k < m; k += 2) {
                const ux = i,
                    uy = j;
                const dx = k,
                    dy = j;
                const lx = Math.floor((i + k) / 2),
                    ly = j - Math.floor((k - i) / 2);
                const rx = Math.floor((i + k) / 2),
                    ry = j + Math.floor((k - i) / 2);
                if (ly < 0 || ry >= n) {
                    break;
                }
                const sum =
                    sum2[lx + 1][ly + 1] -
                    sum2[ux][uy + 2] +
                    (sum1[rx + 1][ry + 1] - sum1[ux][uy]) +
                    (sum1[dx + 1][dy + 1] - sum1[lx][ly]) +
                    (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) -
                    (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] + grid[rx][ry]);
                ans.put(sum);
            }
        }
    }

    return ans.get();
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Answer:
    def __init__(self):
        self.ans = [0, 0, 0]

    def put(self, x: int):
        _ans = self.ans

        if x > _ans[0]:
            _ans[0], _ans[1], _ans[2] = x, _ans[0], _ans[1]
        elif x != _ans[0] and x > _ans[1]:
            _ans[1], _ans[2] = x, _ans[1]
        elif x != _ans[0] and x != _ans[1] and x > _ans[2]:
            _ans[2] = x

    def get(self) -> List[int]:
        _ans = self.ans

        return [num for num in _ans if num != 0]


class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        sum1 = [[0] * (n + 2) for _ in range(m + 1)]
        sum2 = [[0] * (n + 2) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1]
                sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1]

        ans = Answer()
        for i in range(m):
            for j in range(n):
                # a single cell is also a rhombus
                ans.put(grid[i][j])
                for k in range(i + 2, m, 2):
                    ux, uy = i, j
                    dx, dy = k, j
                    lx, ly = (i + k) // 2, j - (k - i) // 2
                    rx, ry = (i + k) // 2, j + (k - i) // 2

                    if ly < 0 or ry >= n:
                        break

                    ans.put(
                        (sum2[lx + 1][ly + 1] - sum2[ux][uy + 2])
                        + (sum1[rx + 1][ry + 1] - sum1[ux][uy])
                        + (sum1[dx + 1][dy + 1] - sum1[lx][ly])
                        + (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2])
                        - (
                            grid[ux][uy]
                            + grid[dx][dy]
                            + grid[lx][ly]
                            + grid[rx][ry]
                        )
                    )

        return ans.get()
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class Answer {
    private ans: number[];

    constructor() {
        this.ans = [0, 0, 0];
    }

    put(x: number): void {
        if (x > this.ans[0]) {
            this.ans[2] = this.ans[1];
            this.ans[1] = this.ans[0];
            this.ans[0] = x;
        } else if (x !== this.ans[0] && x > this.ans[1]) {
            this.ans[2] = this.ans[1];
            this.ans[1] = x;
        } else if (x !== this.ans[0] && x !== this.ans[1] && x > this.ans[2]) {
            this.ans[2] = x;
        }
    }

    get(): number[] {
        const ret: number[] = [];
        for (const num of this.ans) {
            if (num !== 0) {
                ret.push(num);
            }
        }
        return ret;
    }
}

function getBiggestThree(grid: number[][]): number[] {
    const m = grid.length,
        n = grid[0].length;
    const sum1: number[][] = Array.from({ length: m + 1 }, () =>
        new Array(n + 2).fill(0),
    );
    const sum2: number[][] = Array.from({ length: m + 1 }, () =>
        new Array(n + 2).fill(0),
    );

    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1];
            sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1];
        }
    }

    const ans = new Answer();
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            // a single cell is also a rhombus
            ans.put(grid[i][j]);
            for (let k = i + 2; k < m; k += 2) {
                const ux = i,
                    uy = j;
                const dx = k,
                    dy = j;
                const lx = Math.floor((i + k) / 2),
                    ly = j - Math.floor((k - i) / 2);
                const rx = Math.floor((i + k) / 2),
                    ry = j + Math.floor((k - i) / 2);
                if (ly < 0 || ry >= n) {
                    break;
                }
                const sum =
                    sum2[lx + 1][ly + 1] -
                    sum2[ux][uy + 2] +
                    (sum1[rx + 1][ry + 1] - sum1[ux][uy]) +
                    (sum1[dx + 1][dy + 1] - sum1[lx][ly]) +
                    (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) -
                    (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] + grid[rx][ry]);

                ans.put(sum);
            }
        }
    }

    return ans.get();
}
```

</details>
