# 547. Number of Provinces

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/number-of-provinces/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 547 - Number of Provinces](https://leetcode.com/problems/number-of-provinces/)

## Problem

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

### Example 1

```text
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
```

### Example 2

```text
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
```

## Constraints

- 1 <= n <= 200
- n == isConnected.length
- n == isConnected[i].length
- isConnected[i][j] is 1 or 0.
- isConnected[i][i] == 1
- isConnected[i][j] == isConnected[j][i]

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sentence Similarity](https://leetcode.com/problems/sentence-similarity/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sentence Similarity II](https://leetcode.com/problems/sentence-similarity-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [The Earliest Moment When Everyone Become Friends](https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 547. Number of Provinces

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java, Python3 |
| Breadth First Search | C++, Java, Python3 |
| Union-find | C++, Java, Python3 |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visit[i]) {
                dfs(i, isConnected, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                dfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public void dfs(int node, int[][] isConnected, boolean[] visit) {
        visit[node] = true;
        for (int i = 0; i < isConnected.length; i++) {
            if (isConnected[node][i] == 1 && !visit[i]) {
                dfs(i, isConnected, visit);
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int numberOfComponents = 0;
        boolean[] visit = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                dfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dfs(self, node, isConnected, visit):
        visit[node] = True
        for i in range(len(isConnected)):
            if isConnected[node][i] and not visit[i]:
                self.dfs(i, isConnected, visit)

    def findCircleNum(self, isConnected):
        size = len(isConnected)
        numberOfComponents = 0
        visit = [False] * size

        for i in range(size):
            if not visit[i]:
                numberOfComponents += 1
                self.dfs(i, isConnected, visit)

        return numberOfComponents
```

</details>

<br>

## Approach 2: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();

            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[node][i] && !visit[i]) {
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                bfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public void bfs(int node, int[][] isConnected, boolean[] visit) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(node);
        visit[node] = true;

        while (!q.isEmpty()) {
            node = q.poll();

            for (int i = 0; i < isConnected.length; i++) {
                if (isConnected[node][i] == 1 && !visit[i]) {
                    q.offer(i);
                    visit[i] = true;
                }
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int numberOfComponents = 0;
        boolean[] visit = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                bfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bfs(self, node, isConnected, visited):
        from collections import deque

        queue = deque([node])
        visited[node] = True

        while queue:
            node = queue.popleft()

            for i in range(len(isConnected)):
                if isConnected[node][i] == 1 and not visited[i]:
                    queue.append(i)
                    visited[i] = True

    def findCircleNum(self, isConnected):
        n = len(isConnected)
        numberOfComponents = 0
        visited = [False] * n

        for i in range(n):
            if not visited[i]:
                numberOfComponents += 1
                self.bfs(i, isConnected, visited)

        return numberOfComponents
```

</details>

<br>

## Approach 3: Union-find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {
private:
    vector<int> parent, rank;
    int count;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        count = size;
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind dsu(n);
        int numberOfComponents = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] && dsu.find(i) != dsu.find(j)) {
                    numberOfComponents--;
                    dsu.union_set(i, j);
                }
            }
        }

        return numberOfComponents;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class UnionFind {

    int[] parent;
    int[] rank;

    public UnionFind(int size) {
        parent = new int[size];
        for (int i = 0; i < size; i++) parent[i] = i;
        rank = new int[size];
    }

    public int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    public void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
}

class Solution {

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        UnionFind dsu = new UnionFind(n);
        int numberOfComponents = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1 && dsu.find(i) != dsu.find(j)) {
                    numberOfComponents--;
                    dsu.union_set(i, j);
                }
            }
        }

        return numberOfComponents;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union_set(self, x, y):
        xset = self.find(x)
        yset = self.find(y)
        if self.rank[xset] < self.rank[yset]:
            self.parent[xset] = yset
        elif self.rank[xset] > self.rank[yset]:
            self.parent[yset] = xset
        else:
            self.parent[yset] = xset
            self.rank[xset] += 1


class Solution:
    def findCircleNum(self, isConnected):
        n = len(isConnected)
        uf = UnionFind(n)
        numberOfComponents = n

        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j] == 1 and uf.find(i) != uf.find(j):
                    numberOfComponents -= 1
                    uf.union_set(i, j)

        return numberOfComponents
```

</details>
