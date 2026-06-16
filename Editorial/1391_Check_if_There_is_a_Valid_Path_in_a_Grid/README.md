# 1391. Check if There is a Valid Path in a Grid

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/)  
`Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 1391 - Check if There is a Valid Path in a Grid](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/)

## Problem

You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

- 1 which means a street connecting the left cell and the right cell.
- 2 which means a street connecting the upper cell and the lower cell.
- 3 which means a street connecting the left cell and the lower cell.
- 4 which means a street connecting the right cell and the lower cell.
- 5 which means a street connecting the left cell and the upper cell.
- 6 which means a street connecting the right cell and the upper cell.

You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

### Example 1

```text
Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
```

### Example 2

```text
Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
```

### Example 3

```text
Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 300
- 1 <= grid[i][j] <= 6

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [ Check if There Is a Valid Parentheses String Path](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1391. Check if There is a Valid Path in a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Constructing a Graph Based on Adjacent Relationships | C++, Java, Python3 |
| Constructing a Graph Based on Cell Property | C++, Java, Python3 |

## Approach 1: Constructing a Graph Based on Adjacent Relationships

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    static constexpr int MAX_N = 300 * 300 + 5;

    struct DisjointSet {
        int f[MAX_N];

        DisjointSet() {
            for (int i = 0; i < MAX_N; ++i) {
                f[i] = i;
            }
        }

        int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

        void merge(int x, int y) { f[find(x)] = find(y); }
    } ds;

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto getId = [&](int x, int y) { return x * n + y; };

        auto detectL = [&](int x, int y) {
            if (y - 1 >= 0 && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 ||
                               grid[x][y - 1] == 1)) {
                ds.merge(getId(x, y), getId(x, y - 1));
            }
        };

        auto detectR = [&](int x, int y) {
            if (y + 1 < n && (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 ||
                              grid[x][y + 1] == 1)) {
                ds.merge(getId(x, y), getId(x, y + 1));
            }
        };

        auto detectU = [&](int x, int y) {
            if (x - 1 >= 0 && (grid[x - 1][y] == 3 || grid[x - 1][y] == 4 ||
                               grid[x - 1][y] == 2)) {
                ds.merge(getId(x, y), getId(x - 1, y));
            }
        };

        auto detectD = [&](int x, int y) {
            if (x + 1 < m && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 ||
                              grid[x + 1][y] == 2)) {
                ds.merge(getId(x, y), getId(x + 1, y));
            }
        };

        auto handler = [&](int x, int y) {
            switch (grid[x][y]) {
                case 1: {
                    detectL(x, y);
                    detectR(x, y);
                } break;
                case 2: {
                    detectU(x, y);
                    detectD(x, y);
                } break;
                case 3: {
                    detectL(x, y);
                    detectD(x, y);
                } break;
                case 4: {
                    detectR(x, y);
                    detectD(x, y);
                } break;
                case 5: {
                    detectL(x, y);
                    detectU(x, y);
                } break;
                case 6: {
                    detectR(x, y);
                    detectU(x, y);
                }
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                handler(i, j);
            }
        }

        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    class DisjointSet {

        int[] f;

        public DisjointSet(int m, int n) {
            f = new int[m * n];
            for (int i = 0; i < m * n; ++i) {
                f[i] = i;
            }
        }

        public int find(int x) {
            return x == f[x] ? x : (f[x] = find(f[x]));
        }

        public void merge(int x, int y) {
            f[find(x)] = find(y);
        }
    }

    int[][] grid;
    int m;
    int n;
    DisjointSet ds;

    public boolean hasValidPath(int[][] grid) {
        this.grid = grid;
        m = grid.length;
        n = grid[0].length;
        ds = new DisjointSet(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                handler(i, j);
            }
        }
        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }

    public int getId(int x, int y) {
        return x * n + y;
    }

    public void detectL(int x, int y) {
        if (
            y - 1 >= 0 &&
            (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 || grid[x][y - 1] == 1)
        ) {
            ds.merge(getId(x, y), getId(x, y - 1));
        }
    }

    public void detectR(int x, int y) {
        if (
            y + 1 < n &&
            (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 || grid[x][y + 1] == 1)
        ) {
            ds.merge(getId(x, y), getId(x, y + 1));
        }
    }

    public void detectU(int x, int y) {
        if (
            x - 1 >= 0 &&
            (grid[x - 1][y] == 3 || grid[x - 1][y] == 4 || grid[x - 1][y] == 2)
        ) {
            ds.merge(getId(x, y), getId(x - 1, y));
        }
    }

    public void detectD(int x, int y) {
        if (
            x + 1 < m &&
            (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 || grid[x + 1][y] == 2)
        ) {
            ds.merge(getId(x, y), getId(x + 1, y));
        }
    }

    public void handler(int x, int y) {
        switch (grid[x][y]) {
            case 1:
                detectL(x, y);
                detectR(x, y);
                break;
            case 2:
                detectU(x, y);
                detectD(x, y);
                break;
            case 3:
                detectL(x, y);
                detectD(x, y);
                break;
            case 4:
                detectR(x, y);
                detectD(x, y);
                break;
            case 5:
                detectL(x, y);
                detectU(x, y);
                break;
            case 6:
                detectR(x, y);
                detectU(x, y);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    class DisjointSet:
        def __init__(self, n):
            self.f = list(range(n))

        def find(self, x):
            if x == self.f[x]:
                return x
            self.f[x] = self.find(self.f[x])
            return self.f[x]

        def merge(self, x, y):
            self.f[self.find(x)] = self.find(y)

    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        ds = Solution.DisjointSet(m * n)

        def getId(x, y):
            return x * n + y

        def detectL(x, y):
            if y - 1 >= 0 and grid[x][y - 1] in [1, 4, 6]:
                ds.merge(getId(x, y), getId(x, y - 1))

        def detectR(x, y):
            if y + 1 < n and grid[x][y + 1] in [1, 3, 5]:
                ds.merge(getId(x, y), getId(x, y + 1))

        def detectU(x, y):
            if x - 1 >= 0 and grid[x - 1][y] in [2, 3, 4]:
                ds.merge(getId(x, y), getId(x - 1, y))

        def detectD(x, y):
            if x + 1 < m and grid[x + 1][y] in [2, 5, 6]:
                ds.merge(getId(x, y), getId(x + 1, y))

        def handler(x, y):
            if grid[x][y] == 1:
                detectL(x, y)
                detectR(x, y)
            elif grid[x][y] == 2:
                detectU(x, y)
                detectD(x, y)
            elif grid[x][y] == 3:
                detectL(x, y)
                detectD(x, y)
            elif grid[x][y] == 4:
                detectR(x, y)
                detectD(x, y)
            elif grid[x][y] == 5:
                detectL(x, y)
                detectU(x, y)
            else:
                detectR(x, y)
                detectU(x, y)

        for i in range(m):
            for j in range(n):
                handler(i, j)

        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1))
```

</details>

<br>

## Approach 2: Constructing a Graph Based on Cell Property

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    static constexpr int MAX_N = 300 * 300 + 5;
    static constexpr int patterns[7] = {0,      0b1010, 0b0101, 0b1100,
                                        0b0110, 0b1001, 0b0011};
    static constexpr int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    struct DisjointSet {
        int f[MAX_N];

        DisjointSet() {
            for (int i = 0; i < MAX_N; ++i) f[i] = i;
        }

        int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

        void merge(int x, int y) { f[find(x)] = find(y); }
    } ds;

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto getId = [&](int x, int y) { return x * n + y; };

        auto handler = [&](int x, int y) {
            int pattern = patterns[grid[x][y]];
            for (int i = 0; i < 4; ++i) {
                if (pattern & (1 << i)) {
                    int sx = x + dirs[i][0];
                    int sy = y + dirs[i][1];
                    if (sx >= 0 && sx < m && sy >= 0 && sy < n and
                        (patterns[grid[sx][sy]] & (1 << ((i + 2) % 4)))) {
                        ds.merge(getId(x, y), getId(sx, sy));
                    }
                }
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                handler(i, j);
            }
        }

        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    class DisjointSet {

        int[] f;

        public DisjointSet(int m, int n) {
            f = new int[m * n];
            for (int i = 0; i < m * n; ++i) {
                f[i] = i;
            }
        }

        public int find(int x) {
            return x == f[x] ? x : (f[x] = find(f[x]));
        }

        public void merge(int x, int y) {
            f[find(x)] = find(y);
        }
    }

    int[] patterns = { 0, 0b1010, 0b0101, 0b1100, 0b0110, 0b1001, 0b0011 };
    int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    int[][] grid;
    int m;
    int n;
    DisjointSet ds;

    public boolean hasValidPath(int[][] grid) {
        this.grid = grid;
        m = grid.length;
        n = grid[0].length;
        ds = new DisjointSet(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                handler(i, j);
            }
        }
        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }

    public int getId(int x, int y) {
        return x * n + y;
    }

    public void handler(int x, int y) {
        int pattern = patterns[grid[x][y]];
        for (int i = 0; i < 4; ++i) {
            if ((pattern & (1 << i)) != 0) {
                int sx = x + dirs[i][0];
                int sy = y + dirs[i][1];
                if (
                    sx >= 0 &&
                    sx < m &&
                    sy >= 0 &&
                    sy < n &&
                    (patterns[grid[sx][sy]] & (1 << ((i + 2) % 4))) != 0
                ) {
                    ds.merge(getId(x, y), getId(sx, sy));
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    class DisjointSet:
        def __init__(self, n):
            self.f = list(range(n))

        def find(self, x):
            if x == self.f[x]:
                return x
            self.f[x] = self.find(self.f[x])
            return self.f[x]

        def merge(self, x, y):
            self.f[self.find(x)] = self.find(y)

    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        patterns = [0, 0b1010, 0b0101, 0b1100, 0b0110, 0b1001, 0b0011]
        dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        ds = Solution.DisjointSet(m * n)

        def getId(x, y):
            return x * n + y

        def handler(x, y):
            pattern = patterns[grid[x][y]]
            for i, (dx, dy) in enumerate(dirs):
                if (pattern & (1 << i)) > 0:
                    sx, sy = x + dx, y + dy
                    if (
                        0 <= sx < m
                        and 0 <= sy < n
                        and (patterns[grid[sx][sy]] & (1 << ((i + 2) % 4))) > 0
                    ):
                        ds.merge(getId(x, y), getId(sx, sy))

        for i in range(m):
            for j in range(n):
                handler(i, j)

        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1))
```

</details>
