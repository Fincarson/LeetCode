# 3548. Equal Sum Grid Partition II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/equal-sum-grid-partition-ii/)  
`Array` `Hash Table` `Matrix` `Enumeration` `Prefix Sum`

**Problem Link:** [LeetCode 3548 - Equal Sum Grid Partition II](https://leetcode.com/problems/equal-sum-grid-partition-ii/)

## Problem

You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

- Each of the two resulting sections formed by the cut is non-empty.
- The sum of elements in both sections is equal, or can be made equal by discounting at most one single cell in total (from either section).
- If a cell is discounted, the rest of the section must remain connected.

Return true if such a partition exists; otherwise, return false.

Note: A section is connected if every cell in it can be reached from any other cell by moving up, down, left, or right through other cells in the section.

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- 1 <= m == grid.length <= 105
- 1 <= n == grid[i].length <= 105
- 2 <= m * n <= 105
- 1 <= grid[i][j] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3548. Equal Sum Grid Partition II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Rotation Matrix + Hash Table + Enumeration of the Upper Matrix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Rotation Matrix + Hash Table + Enumeration of the Upper Matrix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    long long key;
    UT_hash_handle hh;
} HashItem;

static inline HashItem* hashFindItem(HashItem** obj, long long key) {
    HashItem* pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(key), pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, long long key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = malloc(sizeof(HashItem));
    if (!pEntry) return false;
    pEntry->key = key;
    HASH_ADD(hh, *obj, key, sizeof(key), pEntry);
    return true;
}

void hashFree(HashItem** obj) {
    HashItem *curr, *tmp;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
    *obj = NULL;
}

int** rotation(int** grid, int m, int n, int* newM, int* newN) {
    *newM = n;
    *newN = m;
    int** tmp = malloc(n * sizeof(int*));
    int* data = malloc(n * m * sizeof(int));
    if (!tmp || !data) {
        free(tmp);
        free(data);
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        tmp[i] = data + i * m;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp[j][m - 1 - i] = grid[i][j];
        }
    }
    return tmp;
}

void freeGrid(int** grid, int rows) {
    if (grid && grid[0]) {
        free(grid[0]);
    }
    free(grid);
}

static inline bool checkAndReturnTrue(HashItem** exist, int** currentGrid,
                                      int currentM, int** originalGrid) {
    hashFree(exist);
    if (currentGrid != originalGrid) {
        freeGrid(currentGrid, currentM);
    }
    return true;
}

static inline void rotateAndUpdate(int*** currentGrid, int* currentM,
                                   int* currentN, int** originalGrid) {
    int newM, newN;
    int** newGrid = rotation(*currentGrid, *currentM, *currentN, &newM, &newN);
    if (*currentGrid != originalGrid) {
        freeGrid(*currentGrid, *currentM);
    }
    *currentGrid = newGrid;
    *currentM = newM;
    *currentN = newN;
}

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    const int m = gridSize;
    const int n = gridColSize[0];
    long long total = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }
    int currentM = m, currentN = n;
    int** currentGrid = grid;

    for (int k = 0; k < 4; k++) {
        HashItem* exist = NULL;
        hashAddItem(&exist, 0LL);
        long long sum = 0;
        if (currentM < 2 || currentN == 1) {
            if (currentN == 1 && currentM >= 2) {
                for (int i = 0; i < currentM - 1; i++) {
                    sum += currentGrid[i][0];
                    long long tag = sum * 2 - total;
                    if (tag == 0 || tag == currentGrid[0][0] ||
                        tag == currentGrid[i][0]) {
                        return checkAndReturnTrue(&exist, currentGrid, currentM,
                                                  grid);
                    }
                }
            }
            rotateAndUpdate(&currentGrid, &currentM, &currentN, grid);
            hashFree(&exist);
            continue;
        }

        for (int i = 0; i < currentM - 1; i++) {
            for (int j = 0; j < currentN; j++) {
                hashAddItem(&exist, (long long)currentGrid[i][j]);
                sum += currentGrid[i][j];
            }
            long long tag = sum * 2 - total;
            if (i == 0) {
                if (tag == 0 || tag == currentGrid[0][0] ||
                    tag == currentGrid[0][currentN - 1]) {
                    return checkAndReturnTrue(&exist, currentGrid, currentM,
                                              grid);
                }
                continue;
            }
            if (hashFindItem(&exist, tag)) {
                return checkAndReturnTrue(&exist, currentGrid, currentM, grid);
            }
        }

        rotateAndUpdate(&currentGrid, &currentM, &currentN, grid);
        hashFree(&exist);
    }

    if (currentGrid != grid) {
        freeGrid(currentGrid, currentM);
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
    vector<vector<int>> rotation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector tmp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        long long sum;
        long long tag;
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<long long> exist;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 4; k++) {
            exist.clear();
            exist.insert(0);
            sum = 0;
            m = grid.size();
            n = grid[0].size();
            if (m < 2) {
                grid = rotation(grid);
                continue;
            }
            if (n == 1) {
                for (int i = 0; i < m - 1; i++) {
                    sum += grid[i][0];
                    tag = sum * 2 - total;
                    if (tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                        return true;
                    }
                }
                grid = rotation(grid);
                continue;
            }
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    exist.insert(grid[i][j]);
                    sum += grid[i][j];
                }
                tag = sum * 2 - total;
                if (i == 0) {
                    if (tag == 0 || tag == grid[0][0] ||
                        tag == grid[0][n - 1]) {
                        return true;
                    }
                    continue;
                }
                if (exist.contains(tag)) {
                    return true;
                }
            }
            grid = rotation(grid);
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
    public bool CanPartitionGrid(int[][] grid) {
        long total = 0;
        int m = grid.Length;
        int n = grid[0].Length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 4; k++) {
            HashSet<long> exist = new HashSet<long>();
            exist.Add(0);
            long sum = 0;
            m = grid.Length;
            n = grid[0].Length;
            if (m < 2) {
                grid = Rotation(grid);
                continue;
            }
            if (n == 1) {
                for (int i = 0; i < m - 1; i++) {
                    sum += grid[i][0];
                    long tag = sum * 2 - total;
                    if (tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                        return true;
                    }
                }
                grid = Rotation(grid);
                continue;
            }
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    exist.Add(grid[i][j]);
                    sum += grid[i][j];
                }
                long tag = sum * 2 - total;
                if (i == 0) {
                    if (tag == 0 || tag == grid[0][0] ||
                        tag == grid[0][n - 1]) {
                        return true;
                    }
                    continue;
                }
                if (exist.Contains(tag)) {
                    return true;
                }
            }
            grid = Rotation(grid);
        }
        return false;
    }

    public int[][] Rotation(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int[][] tmp = new int [n][];
        for (int i = 0; i < n; i++) {
            tmp[i] = new int[m];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func canPartitionGrid(grid [][]int) bool {
    var total int64 = 0
    m, n := len(grid), len(grid[0])
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            total += int64(grid[i][j])
        }
    }
    for k := 0; k < 4; k++ {
        exist := make(map[int64]bool)
        exist[0] = true
        var sum int64 = 0
        m, n = len(grid), len(grid[0])
        if m < 2 {
            grid = rotation(grid)
            continue
        }
        if n == 1 {
            for i := 0; i < m-1; i++ {
                sum += int64(grid[i][0])
                tag := sum*2 - total
                if tag == 0 || tag == int64(grid[0][0]) || tag == int64(grid[i][0]) {
                    return true
                }
            }
            grid = rotation(grid)
            continue
        }
        for i := 0; i < m-1; i++ {
            for j := 0; j < n; j++ {
                exist[int64(grid[i][j])] = true
                sum += int64(grid[i][j])
            }
            tag := sum*2 - total
            if i == 0 {
                if tag == 0 || tag == int64(grid[0][0]) || tag == int64(grid[0][n-1]) {
                    return true
                }
                continue
            }
            if exist[tag] {
                return true
            }
        }
        grid = rotation(grid)
    }
    return false
}

func rotation(grid [][]int) [][]int {
    m, n := len(grid), len(grid[0])
    tmp := make([][]int, n)
    for i := range tmp {
        tmp[i] = make([]int, m)
    }
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            tmp[j][m-1-i] = grid[i][j]
        }
    }
    return tmp
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canPartitionGrid(int[][] grid) {
        long total = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 4; k++) {
            Set<Long> exist = new HashSet<>();
            exist.add(0L);
            long sum = 0;
            m = grid.length;
            n = grid[0].length;
            if (m < 2) {
                grid = rotation(grid);
                continue;
            }
            if (n == 1) {
                for (int i = 0; i < m - 1; i++) {
                    sum += grid[i][0];
                    long tag = sum * 2 - total;
                    if (tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                        return true;
                    }
                }
                grid = rotation(grid);
                continue;
            }
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    exist.add((long) grid[i][j]);
                    sum += grid[i][j];
                }
                long tag = sum * 2 - total;
                if (i == 0) {
                    if (
                        tag == 0 || tag == grid[0][0] || tag == grid[0][n - 1]
                    ) {
                        return true;
                    }
                    continue;
                }
                if (exist.contains(tag)) {
                    return true;
                }
            }
            grid = rotation(grid);
        }
        return false;
    }

    public int[][] rotation(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] tmp = new int[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var canPartitionGrid = function (grid) {
    let total = 0;
    let m = grid.length;
    let n = grid[0].length;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }
    for (let k = 0; k < 4; k++) {
        const exist = new Set();
        exist.add(0);
        let sum = 0;
        m = grid.length;
        n = grid[0].length;
        if (m < 2) {
            grid = rotation(grid);
            continue;
        }
        if (n == 1) {
            for (let i = 0; i < m - 1; i++) {
                sum += grid[i][0];
                let tag = sum * 2 - total;
                if (tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                    return true;
                }
            }
            grid = rotation(grid);
            continue;
        }
        for (let i = 0; i < m - 1; i++) {
            for (let j = 0; j < n; j++) {
                exist.add(grid[i][j]);
                sum += grid[i][j];
            }
            let tag = sum * 2 - total;
            if (i == 0) {
                if (tag == 0 || tag == grid[0][0] || tag == grid[0][n - 1]) {
                    return true;
                }
                continue;
            }
            if (exist.has(tag)) {
                return true;
            }
        }
        grid = rotation(grid);
    }
    return false;
};

function rotation(grid) {
    const m = grid.length,
        n = grid[0].length;
    const tmp = Array.from({ length: n }, () => Array(m).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            tmp[j][m - 1 - i] = grid[i][j];
        }
    }
    return tmp;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                total += grid[i][j]
        for _ in range(4):
            exist = set()
            exist.add(0)
            sum_val = 0
            m = len(grid)
            n = len(grid[0])
            if m < 2:
                grid = self.rotation(grid)
                continue
            if n == 1:
                for i in range(m - 1):
                    sum_val += grid[i][0]
                    tag = sum_val * 2 - total
                    if tag == 0 or tag == grid[0][0] or tag == grid[i][0]:
                        return True
                grid = self.rotation(grid)
                continue
            for i in range(m - 1):
                for j in range(n):
                    exist.add(grid[i][j])
                    sum_val += grid[i][j]
                tag = sum_val * 2 - total
                if i == 0:
                    if tag == 0 or tag == grid[0][0] or tag == grid[0][n - 1]:
                        return True
                    continue
                if tag in exist:
                    return True
            grid = self.rotation(grid)
        return False

    def rotation(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        tmp = [[0] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                tmp[j][m - 1 - i] = grid[i][j]
        return tmp
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function canPartitionGrid(grid: number[][]): boolean {
    let total = 0;
    let m = grid.length;
    let n = grid[0].length;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }
    for (let k = 0; k < 4; k++) {
        const exist = new Set<number>();
        exist.add(0);
        let sum = 0;
        m = grid.length;
        n = grid[0].length;
        if (m < 2) {
            grid = rotation(grid);
            continue;
        }
        if (n == 1) {
            for (let i = 0; i < m - 1; i++) {
                sum += grid[i][0];
                let tag = sum * 2 - total;
                if (tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                    return true;
                }
            }
            grid = rotation(grid);
            continue;
        }
        for (let i = 0; i < m - 1; i++) {
            for (let j = 0; j < n; j++) {
                exist.add(grid[i][j]);
                sum += grid[i][j];
            }
            let tag = sum * 2 - total;
            if (i == 0) {
                if (tag == 0 || tag == grid[0][0] || tag == grid[0][n - 1]) {
                    return true;
                }
                continue;
            }
            if (exist.has(tag)) {
                return true;
            }
        }
        grid = rotation(grid);
    }
    return false;
}

function rotation(grid: number[][]): number[][] {
    const m = grid.length,
        n = grid[0].length;
    const tmp: number[][] = Array.from({ length: n }, () => Array(m).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            tmp[j][m - 1 - i] = grid[i][j];
        }
    }
    return tmp;
}
```

</details>
