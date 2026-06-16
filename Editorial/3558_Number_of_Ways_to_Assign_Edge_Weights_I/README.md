# 3558. Number of Ways to Assign Edge Weights I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/)  
`Math` `Tree` `Depth-First Search`

**Problem Link:** [LeetCode 3558 - Number of Ways to Assign Edge Weights I](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/)

## Problem

There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.

Since the answer may be large, return it modulo 109 + 7.

Note: Ignore all edges not in the path from node 1 to x.

### Example 1

### Example 2

## Constraints

- 2 <= n <= 105
- edges.length == n - 1
- edges[i] == [ui, vi]
- 1 <= ui, vi <= n
- edges represents a valid tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3558. Number of Ways to Assign Edge Weights I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Depth-First Search + Mathematics | C, C++, C#, Java, JavaScript, Python3, TypeScript |

## Approach: Depth-First Search + Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node** heads;
    int size;
} Graph;

void addEdge(Graph* g, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = v;
    node->next = g->heads[u];
    g->heads[u] = node;
}

int qpow(int x, int y) {
    long long res = 1;
    long long base = x;
    while (y) {
        if (y & 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        y >>= 1;
    }
    return (int)res;
}

int dfs(Graph* g, int x, int f) {
    int maxDep = 0;
    Node* cur = g->heads[x];
    while (cur) {
        int y = cur->val;
        if (y != f) {
            int dep = dfs(g, y, x) + 1;
            if (dep > maxDep) maxDep = dep;
        }
        cur = cur->next;
    }
    return maxDep;
}

int assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize) {
    int n = edgesSize + 1;
    Graph g;
    g.heads = (Node**)calloc(n + 1, sizeof(Node*));
    g.size = n + 1;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(&g, u, v);
        addEdge(&g, v, u);
    }

    int maxDep = dfs(&g, 1, 0);
    int result = qpow(2, maxDep - 1);

    for (int i = 0; i <= n; i++) {
        Node* cur = g.heads[i];
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(g.heads);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    static constexpr int mod = 1e9 + 7;
    int qpow(int x, int y) {
        int res = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                res = 1ll * res * x % mod;
            }
            x = 1ll * x * x % mod;
        }
        return res;
    }
    int dfs(vector<vector<int>>& g, int x, int f) {
        int max_dep = 0;
        for (auto& y : g[x]) {
            if (y == f) {
                continue;
            }
            max_dep = max(max_dep, dfs(g, y, x) + 1);
        }
        return max_dep;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        int max_dep = dfs(g, 1, 0);
        return qpow(2, max_dep - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const int MOD = 1_000_000_007;

    private int QPow(int x, int y) {
        long res = 1;
        long baseVal = x;
        while (y > 0) {
            if ((y & 1) == 1) {
                res = (res * baseVal) % MOD;
            }
            baseVal = (baseVal * baseVal) % MOD;
            y >>= 1;
        }
        return (int)res;
    }

    private int Dfs(List<List<int>> g, int x, int f) {
        int maxDep = 0;
        foreach (int y in g[x]) {
            if (y == f)
                continue;
            maxDep = System.Math.Max(maxDep, Dfs(g, y, x) + 1);
        }
        return maxDep;
    }

    public int AssignEdgeWeights(int[][] edges) {
        int n = edges.Length + 1;
        var g = new List<List<int>>();
        for (int i = 0; i <= n; i++) {
            g.Add(new List<int>());
        }
        foreach (var e in edges) {
            int u = e[0];
            int v = e[1];
            g[u].Add(v);
            g[v].Add(u);
        }
        int maxDep = Dfs(g, 1, 0);
        return QPow(2, maxDep - 1);
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = 1_000_000_007;

    private int qpow(int x, int y) {
        long res = 1;
        long base = x;
        while (y > 0) {
            if ((y & 1) == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            y >>= 1;
        }
        return (int) res;
    }

    private int dfs(List<List<Integer>> g, int x, int f) {
        int maxDep = 0;
        for (int y : g.get(x)) {
            if (y == f) continue;
            maxDep = Math.max(maxDep, dfs(g, y, x) + 1);
        }
        return maxDep;
    }

    public int assignEdgeWeights(int[][] edges) {
        int n = edges.length + 1;
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            g.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            g.get(u).add(v);
            g.get(v).add(u);
        }
        int maxDep = dfs(g, 1, 0);
        return qpow(2, maxDep - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var assignEdgeWeights = function (edges) {
    const MOD = 1000000007n;

    const qpow = (x, y) => {
        let res = 1n;
        let base = BigInt(x);
        let exp = y;
        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return Number(res);
    };

    const dfs = (g, x, f) => {
        let maxDep = 0;
        for (const y of g[x]) {
            if (y === f) continue;
            maxDep = Math.max(maxDep, dfs(g, y, x) + 1);
        }
        return maxDep;
    };

    const n = edges.length + 1;
    const g = Array.from({ length: n + 1 }, () => []);

    for (let i = 0; i < edges.length; i++) {
        const u = edges[i][0];
        const v = edges[i][1];
        g[u].push(v);
        g[v].push(u);
    }

    const maxDep = dfs(g, 1, 0);
    return qpow(2, maxDep - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    MOD = 10**9 + 7

    def dfs(self, g: list, x: int, f: int) -> int:
        max_dep = 0
        for y in g[x]:
            if y == f:
                continue
            max_dep = max(max_dep, self.dfs(g, y, x) + 1)
        return max_dep

    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        g = [[] for _ in range(n + 1)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        max_dep = self.dfs(g, 1, 0)
        return pow(2, max_dep - 1, self.MOD)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var assignEdgeWeights = function (edges: number[][]): number {
    const MOD: bigint = 1000000007n;

    const qpow = (x: number, y: number): number => {
        let res: bigint = 1n;
        let base: bigint = BigInt(x);
        let exp: number = y;

        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return Number(res);
    };

    const dfs = (g: number[][], x: number, f: number): number => {
        let maxDep: number = 0;
        for (const y of g[x]) {
            if (y === f) continue;
            maxDep = Math.max(maxDep, dfs(g, y, x) + 1);
        }
        return maxDep;
    };

    const n: number = edges.length + 1;
    const g: number[][] = Array.from({ length: n + 1 }, () => []);

    for (let i = 0; i < edges.length; i++) {
        const u: number = edges[i][0];
        const v: number = edges[i][1];
        g[u].push(v);
        g[v].push(u);
    }

    const maxDep: number = dfs(g, 1, 0);
    return qpow(2, maxDep - 1);
};
```

</details>
