# 3559. Number of Ways to Assign Edge Weights II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/)  
`Array` `Math` `Dynamic Programming` `Bit Manipulation` `Tree` `Depth-First Search`

**Problem Link:** [LeetCode 3559 - Number of Ways to Assign Edge Weights II](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/)

## Problem

There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.

Return an array answer, where answer[i] is the number of valid assignments for queries[i].

Since the answer may be large, apply modulo 109 + 7 to each answer[i].

Note: For each query, disregard all edges not in the path between node ui and vi.

### Example 1

### Example 2

## Constraints

- 2 <= n <= 105
- edges.length == n - 1
- edges[i] == [ui, vi]
- 1 <= queries.length <= 105
- queries[i] == [ui, vi]
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

# Editorial - 3559. Number of Ways to Assign Edge Weights II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Lowest Common Ancestor $\text{LCA}$ + Mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Lowest Common Ancestor $\text{LCA}$ + Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007
#define N 100010

typedef struct {
    int n;
    int m;
    int* d;
    int** e;
    int* e_size;
    int* e_cap;
    int** f;
} LCA;

int p2[N];

void init_p2() {
    p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = (int)((long long)p2[i - 1] * 2 % MOD);
    }
}

void add_edge(LCA* lca, int u, int v) {
    if (lca->e_size[u] >= lca->e_cap[u]) {
        lca->e_cap[u] *= 2;
        lca->e[u] = (int*)realloc(lca->e[u], lca->e_cap[u] * sizeof(int));
    }
    lca->e[u][lca->e_size[u]++] = v;
}

void dfs(LCA* lca, int x, int fa) {
    lca->f[x][0] = fa;
    for (int i = 0; i < lca->e_size[x]; i++) {
        int y = lca->e[x][i];
        if (y == fa) {
            continue;
        }
        lca->d[y] = lca->d[x] + 1;
        dfs(lca, y, x);
    }
}

LCA* create_lca(int** edges, int edges_size, int root) {
    LCA* lca = (LCA*)malloc(sizeof(LCA));
    lca->n = edges_size + 1;
    lca->m = (int)(log(lca->n) / log(2)) + 1;

    lca->d = (int*)calloc(lca->n + 1, sizeof(int));
    lca->e = (int**)malloc((lca->n + 1) * sizeof(int*));
    lca->e_size = (int*)calloc(lca->n + 1, sizeof(int));
    lca->e_cap = (int*)malloc((lca->n + 1) * sizeof(int));
    lca->f = (int**)malloc((lca->n + 1) * sizeof(int*));

    for (int i = 0; i <= lca->n; i++) {
        lca->e[i] = (int*)malloc(10 * sizeof(int));
        lca->e_cap[i] = 10;
        lca->f[i] = (int*)calloc(lca->m, sizeof(int));
    }

    for (int i = 0; i < edges_size; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        add_edge(lca, u, v);
        add_edge(lca, v, u);
    }

    dfs(lca, root, 0);

    for (int i = 1; i < lca->m; i++) {
        for (int x = 1; x <= lca->n; x++) {
            lca->f[x][i] = lca->f[lca->f[x][i - 1]][i - 1];
        }
    }

    return lca;
}

int lca_query(LCA* lca, int x, int y) {
    if (lca->d[x] > lca->d[y]) {
        int temp = x;
        x = y;
        y = temp;
    }

    for (int i = lca->m - 1; i >= 0; i--) {
        if (lca->d[x] <= lca->d[lca->f[y][i]]) {
            y = lca->f[y][i];
        }
    }

    if (x == y) {
        return x;
    }

    for (int i = lca->m - 1; i >= 0; i--) {
        if (lca->f[y][i] != lca->f[x][i]) {
            x = lca->f[x][i];
            y = lca->f[y][i];
        }
    }

    return lca->f[x][0];
}

int dis(LCA* lca, int x, int y) {
    return lca->d[x] + lca->d[y] - lca->d[lca_query(lca, x, y)] * 2;
}

void free_lca(LCA* lca) {
    for (int i = 0; i <= lca->n; i++) {
        free(lca->e[i]);
        free(lca->f[i]);
    }
    free(lca->d);
    free(lca->e);
    free(lca->e_size);
    free(lca->e_cap);
    free(lca->f);
    free(lca);
}

int* assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize,
                       int** queries, int queriesSize, int* queriesColSize,
                       int* returnSize) {
    init_p2();
    LCA* lca = create_lca(edges, edgesSize, 1);
    *returnSize = queriesSize;
    int* res = (int*)calloc(queriesSize, sizeof(int));

    for (int i = 0; i < queriesSize; i++) {
        int x = queries[i][0];
        int y = queries[i][1];
        if (x != y) {
            res[i] = p2[dis(lca, x, y) - 1];
        }
    }

    free_lca(lca);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class LCA {
public:
    LCA(const vector<vector<int>>& edges, const int root = 1) {
        n = edges.size() + 1;
        m = (log(n) / log(2)) + 1;
        e.resize(n + 1);
        d.resize(n + 1);
        f.resize(n + 1, vector<int>(m, 0));
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(root, 0);
        for (int i = 1; i < m; i++) {
            for (int x = 1; x <= n; x++) {
                f[x][i] = f[f[x][i - 1]][i - 1];
            }
        }
    }
    void dfs(int x, int fa) {
        f[x][0] = fa;
        for (auto& y : e[x]) {
            if (y == fa) {
                continue;
            }
            d[y] = d[x] + 1;
            dfs(y, x);
        }
    }

    int lca(int x, int y) {
        if (d[x] > d[y]) {
            swap(x, y);
        }
        for (int i = m - 1; i >= 0; i--) {
            if (d[x] <= d[f[y][i]]) {
                y = f[y][i];
            }
        }
        if (x == y) {
            return x;
        }
        for (int i = m - 1; i >= 0; i--) {
            if (f[y][i] != f[x][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    }

    int dis(int x, int y) { return d[x] + d[y] - d[lca(x, y)] * 2; }

private:
    int n;
    int m;
    vector<int> d;
    vector<vector<int>> e;
    vector<vector<int>> f;
};

const int MOD = 1e9 + 7;
const int N = 100010;
int p2[N];
auto init = [] {
    p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }
    return 0;
}();

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        LCA lca(edges, 1);
        int m = queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (x != y) {
                res[i] = p2[lca.dis(x, y) - 1];
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
public class LCA {
    private int n;
    private int m;
    private int[] d;
    private List<int>[] e;
    private int[][] f;

    public LCA(int[][] edges, int root = 1) {
        n = edges.Length + 1;
        m = (int)(Math.Log(n) / Math.Log(2)) + 1;
        e = new List<int>[n + 1];
        d = new int[n + 1];
        f = new int [n + 1][];

        for (int i = 0; i <= n; i++) {
            e[i] = new List<int>();
            f[i] = new int[m];
        }

        foreach (var edge in edges) {
            int u = edge[0];
            int v = edge[1];
            e[u].Add(v);
            e[v].Add(u);
        }

        Dfs(root, 0);

        for (int i = 1; i < m; i++) {
            for (int x = 1; x <= n; x++) {
                f[x][i] = f[f[x][i - 1]][i - 1];
            }
        }
    }

    private void Dfs(int x, int fa) {
        f[x][0] = fa;
        foreach (int y in e[x]) {
            if (y == fa) {
                continue;
            }
            d[y] = d[x] + 1;
            Dfs(y, x);
        }
    }

    public int Lca(int x, int y) {
        if (d[x] > d[y]) {
            int temp = x;
            x = y;
            y = temp;
        }

        for (int i = m - 1; i >= 0; i--) {
            if (d[x] <= d[f[y][i]]) {
                y = f[y][i];
            }
        }

        if (x == y) {
            return x;
        }

        for (int i = m - 1; i >= 0; i--) {
            if (f[y][i] != f[x][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }

        return f[x][0];
    }

    public int Dis(int x, int y) {
        return d[x] + d[y] - d[Lca(x, y)] * 2;
    }
}

public class Solution {
    private const int MOD = 1000000007;
    private const int N = 100010;
    private static int[] p2 = new int[N];

    static Solution() {
        p2[0] = 1;
        for (int i = 1; i < N; i++) {
            p2[i] = (int)((long)p2[i - 1] * 2 % MOD);
        }
    }

    public int[] AssignEdgeWeights(int[][] edges, int[][] queries) {
        LCA lca = new LCA(edges, 1);
        int m = queries.Length;
        int[] res = new int[m];

        for (int i = 0; i < m; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (x != y) {
                res[i] = p2[lca.Dis(x, y) - 1];
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
type LCA struct {
	n int
	m int
	d []int
	e [][]int
	f [][]int
}

func NewLCA(edges [][]int, root int) *LCA {
	lca := &LCA{}
	lca.n = len(edges) + 1
	lca.m = int(math.Log2(float64(lca.n))) + 1

	lca.e = make([][]int, lca.n+1)
	lca.d = make([]int, lca.n+1)
	lca.f = make([][]int, lca.n+1)
	for i := 0; i <= lca.n; i++ {
		lca.e[i] = make([]int, 0)
		lca.f[i] = make([]int, lca.m)
	}

	for _, edge := range edges {
		u := edge[0]
		v := edge[1]
		lca.e[u] = append(lca.e[u], v)
		lca.e[v] = append(lca.e[v], u)
	}

	lca.dfs(root, 0)

	for i := 1; i < lca.m; i++ {
		for x := 1; x <= lca.n; x++ {
			lca.f[x][i] = lca.f[lca.f[x][i-1]][i-1]
		}
	}

	return lca
}

func (lca *LCA) dfs(x int, fa int) {
	lca.f[x][0] = fa
	for _, y := range lca.e[x] {
		if y == fa {
			continue
		}
		lca.d[y] = lca.d[x] + 1
		lca.dfs(y, x)
	}
}

func (lca *LCA) Lca(x int, y int) int {
	if lca.d[x] > lca.d[y] {
		x, y = y, x
	}

	for i := lca.m - 1; i >= 0; i-- {
		if lca.d[x] <= lca.d[lca.f[y][i]] {
			y = lca.f[y][i]
		}
	}

	if x == y {
		return x
	}

	for i := lca.m - 1; i >= 0; i-- {
		if lca.f[y][i] != lca.f[x][i] {
			x = lca.f[x][i]
			y = lca.f[y][i]
		}
	}

	return lca.f[x][0]
}

func (lca *LCA) Dis(x int, y int) int {
	return lca.d[x] + lca.d[y] - lca.d[lca.Lca(x, y)]*2
}

const (
	MOD = 1000000007
	N   = 100010
)

var p2 [N]int

func init() {
	p2[0] = 1
	for i := 1; i < N; i++ {
		p2[i] = p2[i-1] * 2 % MOD
	}
}

func assignEdgeWeights(edges [][]int, queries [][]int) []int {
	lca := NewLCA(edges, 1)
	m := len(queries)
	res := make([]int, m)

	for i := 0; i < m; i++ {
		x := queries[i][0]
		y := queries[i][1]
		if x != y {
			res[i] = p2[lca.Dis(x, y)-1]
		}
	}

	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class LCA {

    private int n;
    private int m;
    private int[] d;
    private List<Integer>[] e;
    private int[][] f;

    public LCA(int[][] edges, int root) {
        n = edges.length + 1;
        m = (int) (Math.log(n) / Math.log(2)) + 1;
        e = new ArrayList[n + 1];
        d = new int[n + 1];
        f = new int[n + 1][m];

        for (int i = 0; i <= n; i++) {
            e[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            e[u].add(v);
            e[v].add(u);
        }

        dfs(root, 0);

        for (int i = 1; i < m; i++) {
            for (int x = 1; x <= n; x++) {
                f[x][i] = f[f[x][i - 1]][i - 1];
            }
        }
    }

    private void dfs(int x, int fa) {
        f[x][0] = fa;
        for (int y : e[x]) {
            if (y == fa) {
                continue;
            }
            d[y] = d[x] + 1;
            dfs(y, x);
        }
    }

    public int lca(int x, int y) {
        if (d[x] > d[y]) {
            int temp = x;
            x = y;
            y = temp;
        }

        for (int i = m - 1; i >= 0; i--) {
            if (d[x] <= d[f[y][i]]) {
                y = f[y][i];
            }
        }

        if (x == y) {
            return x;
        }

        for (int i = m - 1; i >= 0; i--) {
            if (f[y][i] != f[x][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }

        return f[x][0];
    }

    public int dis(int x, int y) {
        return d[x] + d[y] - d[lca(x, y)] * 2;
    }
}

class Solution {

    private static final int MOD = 1000000007;
    private static final int N = 100010;
    private static int[] p2 = new int[N];

    static {
        p2[0] = 1;
        for (int i = 1; i < N; i++) {
            p2[i] = (int) (((long) p2[i - 1] * 2) % MOD);
        }
    }

    public int[] assignEdgeWeights(int[][] edges, int[][] queries) {
        LCA lca = new LCA(edges, 1);
        int m = queries.length;
        int[] res = new int[m];

        for (int i = 0; i < m; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (x != y) {
                res[i] = p2[lca.dis(x, y) - 1];
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
class LCA {
    constructor(edges, root = 1) {
        this.n = edges.length + 1;
        this.m = Math.floor(Math.log(this.n) / Math.log(2)) + 1;
        this.d = new Array(this.n + 1).fill(0);
        this.e = new Array(this.n + 1);
        this.f = new Array(this.n + 1);

        for (let i = 0; i <= this.n; i++) {
            this.e[i] = [];
            this.f[i] = new Array(this.m).fill(0);
        }

        for (let edge of edges) {
            const u = edge[0];
            const v = edge[1];
            this.e[u].push(v);
            this.e[v].push(u);
        }

        this.dfs(root, 0);

        for (let i = 1; i < this.m; i++) {
            for (let x = 1; x <= this.n; x++) {
                this.f[x][i] = this.f[this.f[x][i - 1]][i - 1];
            }
        }
    }

    dfs(x, fa) {
        this.f[x][0] = fa;
        for (let y of this.e[x]) {
            if (y === fa) {
                continue;
            }
            this.d[y] = this.d[x] + 1;
            this.dfs(y, x);
        }
    }

    lca(x, y) {
        if (this.d[x] > this.d[y]) {
            [x, y] = [y, x];
        }

        for (let i = this.m - 1; i >= 0; i--) {
            if (this.d[x] <= this.d[this.f[y][i]]) {
                y = this.f[y][i];
            }
        }

        if (x === y) {
            return x;
        }

        for (let i = this.m - 1; i >= 0; i--) {
            if (this.f[y][i] !== this.f[x][i]) {
                x = this.f[x][i];
                y = this.f[y][i];
            }
        }

        return this.f[x][0];
    }

    dis(x, y) {
        return this.d[x] + this.d[y] - this.d[this.lca(x, y)] * 2;
    }
}

const MOD = 1000000007;
const N = 100010;
const p2 = new Array(N);

(function init() {
    p2[0] = 1;
    for (let i = 1; i < N; i++) {
        p2[i] = (p2[i - 1] * 2) % MOD;
    }
})();

function assignEdgeWeights(edges, queries) {
    const lca = new LCA(edges, 1);
    const m = queries.length;
    const res = new Array(m).fill(0);

    for (let i = 0; i < m; i++) {
        const x = queries[i][0];
        const y = queries[i][1];
        if (x !== y) {
            res[i] = p2[lca.dis(x, y) - 1];
        }
    }

    return res;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import math
from typing import List


class LCA:
    def __init__(self, edges: List[List[int]], root: int = 1):
        self.n = len(edges) + 1
        self.m = int(math.log2(self.n)) + 2
        self.e = [[] for _ in range(self.n + 1)]
        self.d = [0] * (self.n + 1)
        self.f = [[0] * self.m for _ in range(self.n + 1)]

        for u, v in edges:
            self.e[u].append(v)
            self.e[v].append(u)

        self.dfs(root, 0)

        for i in range(1, self.m):
            for x in range(1, self.n + 1):
                self.f[x][i] = self.f[self.f[x][i - 1]][i - 1]

    def dfs(self, x: int, fa: int):
        self.f[x][0] = fa
        for y in self.e[x]:
            if y == fa:
                continue
            self.d[y] = self.d[x] + 1
            self.dfs(y, x)

    def lca(self, x: int, y: int) -> int:
        if self.d[x] > self.d[y]:
            x, y = y, x

        # raise y to the same depth as x
        diff = self.d[y] - self.d[x]
        for i in range(self.m - 1, -1, -1):
            if diff & (1 << i):
                y = self.f[y][i]

        if x == y:
            return x

        for i in range(self.m - 1, -1, -1):
            if self.f[x][i] != self.f[y][i]:
                x = self.f[x][i]
                y = self.f[y][i]

        return self.f[x][0]

    def dis(self, x: int, y: int) -> int:
        return self.d[x] + self.d[y] - self.d[self.lca(x, y)] * 2


MOD = 10**9 + 7
N = 100010
p2 = [0] * N


def init():
    p2[0] = 1
    for i in range(1, N):
        p2[i] = p2[i - 1] * 2 % MOD


init()


class Solution:
    def assignEdgeWeights(
        self, edges: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        lca = LCA(edges, 1)
        m = len(queries)
        res = [0] * m

        for i in range(m):
            x, y = queries[i][0], queries[i][1]
            if x != y:
                res[i] = p2[lca.dis(x, y) - 1]

        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class LCA {
    private n: number;
    private m: number;
    private d: number[];
    private e: number[][];
    private f: number[][];

    constructor(edges: number[][], root: number = 1) {
        this.n = edges.length + 1;
        this.m = Math.floor(Math.log(this.n) / Math.log(2)) + 1;
        this.d = new Array(this.n + 1).fill(0);
        this.e = new Array(this.n + 1);
        this.f = new Array(this.n + 1);

        for (let i = 0; i <= this.n; i++) {
            this.e[i] = [];
            this.f[i] = new Array(this.m).fill(0);
        }

        for (const edge of edges) {
            const u = edge[0];
            const v = edge[1];
            this.e[u].push(v);
            this.e[v].push(u);
        }

        this.dfs(root, 0);

        for (let i = 1; i < this.m; i++) {
            for (let x = 1; x <= this.n; x++) {
                this.f[x][i] = this.f[this.f[x][i - 1]][i - 1];
            }
        }
    }

    private dfs(x: number, fa: number): void {
        this.f[x][0] = fa;
        for (const y of this.e[x]) {
            if (y === fa) {
                continue;
            }
            this.d[y] = this.d[x] + 1;
            this.dfs(y, x);
        }
    }

    public lca(x: number, y: number): number {
        if (this.d[x] > this.d[y]) {
            [x, y] = [y, x];
        }

        for (let i = this.m - 1; i >= 0; i--) {
            if (this.d[x] <= this.d[this.f[y][i]]) {
                y = this.f[y][i];
            }
        }

        if (x === y) {
            return x;
        }

        for (let i = this.m - 1; i >= 0; i--) {
            if (this.f[y][i] !== this.f[x][i]) {
                x = this.f[x][i];
                y = this.f[y][i];
            }
        }

        return this.f[x][0];
    }

    public dis(x: number, y: number): number {
        return this.d[x] + this.d[y] - this.d[this.lca(x, y)] * 2;
    }
}

const MOD: number = 1000000007;
const N: number = 100010;
const p2: number[] = new Array(N);

(function init(): void {
    p2[0] = 1;
    for (let i = 1; i < N; i++) {
        p2[i] = (p2[i - 1] * 2) % MOD;
    }
})();

function assignEdgeWeights(edges: number[][], queries: number[][]): number[] {
    const lca = new LCA(edges, 1);
    const m = queries.length;
    const res: number[] = new Array(m).fill(0);

    for (let i = 0; i < m; i++) {
        const x = queries[i][0];
        const y = queries[i][1];
        if (x !== y) {
            res[i] = p2[lca.dis(x, y) - 1];
        }
    }

    return res;
}
```

</details>
