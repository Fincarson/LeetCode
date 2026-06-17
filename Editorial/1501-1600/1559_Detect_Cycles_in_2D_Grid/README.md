# 1559. Detect Cycles in 2D Grid

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/detect-cycles-in-2d-grid/)  
`Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 1559 - Detect Cycles in 2D Grid](https://leetcode.com/problems/detect-cycles-in-2d-grid/)

## Problem

Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.

### Example 1

```text
Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:
```

### Example 2

```text
Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:
```

### Example 3

```text
Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 500
- grid consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1559. Detect Cycles in 2D Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Union-Find Set | C++, Java, Python3 |

## Approach: Union-Find Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    int setCount;

public:
    UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    void unite(int x, int y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
    }

    bool findAndUnite(int x, int y) {
        int parentX = findset(x);
        int parentY = findset(y);
        if (parentX != parentY) {
            unite(parentX, parentY);
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                    if (!uf.findAndUnite(i * n + j, (i - 1) * n + j)) {
                        return true;
                    }
                }
                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    if (!uf.findAndUnite(i * n + j, i * n + j - 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean containsCycle(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        UnionFind uf = new UnionFind(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                    if (!uf.findAndUnite(i * n + j, (i - 1) * n + j)) {
                        return true;
                    }
                }
                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    if (!uf.findAndUnite(i * n + j, i * n + j - 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}

class UnionFind {

    int[] parent;
    int[] size;
    int n;
    int setCount;

    public UnionFind(int n) {
        parent = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        size = new int[n];
        Arrays.fill(size, 1);
        this.n = n;
        setCount = n;
    }

    public int findset(int x) {
        return parent[x] == x ? x : (parent[x] = findset(parent[x]));
    }

    public void unite(int x, int y) {
        if (size[x] < size[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
    }

    public boolean findAndUnite(int x, int y) {
        int parentX = findset(x);
        int parentY = findset(y);
        if (parentX != parentY) {
            unite(parentX, parentY);
            return true;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class UnionFind:
    def __init__(self, n: int):
        self.n = n
        self.setCount = n
        self.parent = list(range(n))
        self.size = [1] * n

    def findset(self, x: int) -> int:
        if self.parent[x] == x:
            return x
        self.parent[x] = self.findset(self.parent[x])
        return self.parent[x]

    def unite(self, x: int, y: int):
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.parent[y] = x
        self.size[x] += self.size[y]
        self.setCount -= 1

    def findAndUnite(self, x: int, y: int) -> bool:
        parentX, parentY = self.findset(x), self.findset(y)
        if parentX != parentY:
            self.unite(parentX, parentY)
            return True
        return False


class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        uf = UnionFind(m * n)
        for i in range(m):
            for j in range(n):
                if i > 0 and grid[i][j] == grid[i - 1][j]:
                    if not uf.findAndUnite(i * n + j, (i - 1) * n + j):
                        return True
                if j > 0 and grid[i][j] == grid[i][j - 1]:
                    if not uf.findAndUnite(i * n + j, i * n + j - 1):
                        return True
        return False
```

</details>
