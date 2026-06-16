# 3600. Maximize Spanning Tree Stability with Upgrades

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/)  
`Binary Search` `Greedy` `Union-Find` `Graph Theory` `Minimum Spanning Tree`

**Problem Link:** [LeetCode 3600 - Maximize Spanning Tree Stability with Upgrades](https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/)

## Problem

You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of edges, where edges[i] = [ui, vi, si, musti]:

- ui and vi indicates an undirected edge between nodes ui and vi.
- si is the strength of the edge.
- musti is an integer (0 or 1). If musti == 1, the edge must be included in the spanning tree. These edges cannot be upgraded.

You are also given an integer k, the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with musti == 0) can be upgraded at most once.

The stability of a spanning tree is defined as the minimum strength score among all edges included in it.

Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1.

Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly n - 1 edges.

### Example 1

### Example 2

### Example 3

## Constraints

- 2 <= n <= 105
- 1 <= edges.length <= 105
- edges[i] = [ui, vi, si, musti]
- 0 <= ui, vi < n
- ui != vi
- 1 <= si <= 105
- musti is either 0 or 1.
- 0 <= k <= n
- There are no duplicate edges.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3600. Maximize Spanning Tree Stability with Upgrades

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Answer + Minimum Spanning Tree | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Binary Answer + Minimum Spanning Tree

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX_STABILITY 200000

typedef struct {
    int* parent;
} DSU;

DSU* dsu_create(int* parent, int n) {
    DSU* d = (DSU*)malloc(sizeof(DSU));
    d->parent = (int*)malloc(n * sizeof(int));
    memcpy(d->parent, parent, n * sizeof(int));
    return d;
}

void dsu_free(DSU* d) {
    free(d->parent);
    free(d);
}

int dsu_find(DSU* d, int x) {
    if (d->parent[x] != x) {
        d->parent[x] = dsu_find(d, d->parent[x]);
    }
    return d->parent[x];
}

void dsu_join(DSU* d, int x, int y) {
    int px = dsu_find(d, x);
    int py = dsu_find(d, y);
    d->parent[px] = py;
}

int cmp_desc(const void* a, const void* b) {
    int* edgeA = (int*)a;
    int* edgeB = (int*)b;
    return edgeB[2] - edgeA[2];
}

int maxStability(int n, int** edges, int edgesSize, int* edgesColSize, int k) {
    int ans = -1;
    if (edgesSize < n - 1) {
        return -1;
    }

    int (*mustEdges)[4] = (int (*)[4])malloc(edgesSize * sizeof(int[4]));
    int (*optionalEdges)[4] = (int (*)[4])malloc(edgesSize * sizeof(int[4]));
    int mustCnt = 0, optCnt = 0;
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 1) {
            mustEdges[mustCnt][0] = edges[i][0];
            mustEdges[mustCnt][1] = edges[i][1];
            mustEdges[mustCnt][2] = edges[i][2];
            mustCnt++;
        } else {
            optionalEdges[optCnt][0] = edges[i][0];
            optionalEdges[optCnt][1] = edges[i][1];
            optionalEdges[optCnt][2] = edges[i][2];
            optCnt++;
        }
    }

    if (mustCnt > n - 1) {
        free(mustEdges);
        free(optionalEdges);
        return -1;
    }

    qsort(optionalEdges, optCnt, sizeof(int[4]), cmp_desc);
    int selectedInit = 0;
    int mustMinStability = MAX_STABILITY;
    int* initParent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        initParent[i] = i;
    }
    DSU* dsuInit = dsu_create(initParent, n);
    free(initParent);

    for (int i = 0; i < mustCnt; i++) {
        int u = mustEdges[i][0], v = mustEdges[i][1], s = mustEdges[i][2];
        if (dsu_find(dsuInit, u) == dsu_find(dsuInit, v) ||
            selectedInit == n - 1) {
            dsu_free(dsuInit);
            free(mustEdges);
            free(optionalEdges);
            return -1;
        }
        dsu_join(dsuInit, u, v);
        selectedInit++;
        if (s < mustMinStability) {
            mustMinStability = s;
        }
    }

    int l = 0, r = mustMinStability;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;

        int* currentParent = (int*)malloc(n * sizeof(int));
        memcpy(currentParent, dsuInit->parent, n * sizeof(int));
        DSU* dsu = dsu_create(currentParent, n);
        free(currentParent);

        int selected = selectedInit;
        int doubledCount = 0;

        for (int i = 0; i < optCnt; i++) {
            int u = optionalEdges[i][0], v = optionalEdges[i][1],
                s = optionalEdges[i][2];
            if (dsu_find(dsu, u) == dsu_find(dsu, v)) {
                continue;
            }
            if (s >= mid) {
                dsu_join(dsu, u, v);
                selected++;
            } else if (doubledCount < k && s * 2 >= mid) {
                doubledCount++;
                dsu_join(dsu, u, v);
                selected++;
            } else {
                break;
            }

            if (selected == n - 1) {
                break;
            }
        }

        dsu_free(dsu);
        if (selected != n - 1) {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid;
        }
    }

    dsu_free(dsuInit);
    free(mustEdges);
    free(optionalEdges);

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
struct Edge {
    int u, v, w, type;
};

class DSU {
public:
    vector<int> parent;

    DSU(const vector<int>& p) : parent(p) {}

    int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    void join(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

const int MAX_STABILITY = 2e5;

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int ans = -1;

        if (edges.size() < n - 1) {
            return -1;
        }

        vector<Edge> mustEdges;
        vector<Edge> optionalEdges;

        for (const auto& edge : edges) {
            if (edge[3] == 1) {
                mustEdges.push_back({edge[0], edge[1], edge[2], edge[3]});
            } else {
                optionalEdges.push_back({edge[0], edge[1], edge[2], edge[3]});
            }
        }

        if (mustEdges.size() > n - 1) {
            return -1;
        }
        sort(optionalEdges.begin(), optionalEdges.end(),
             [](const Edge& a, const Edge& b) { return b.w < a.w; });

        int selectedInit = 0;
        int mustMinStability = MAX_STABILITY;
        vector<int> initialParent(n);
        iota(initialParent.begin(), initialParent.end(), 0);
        DSU dsuInit(initialParent);

        for (const auto& edge : mustEdges) {
            if (dsuInit.find(edge.u) == dsuInit.find(edge.v) ||
                selectedInit == n - 1) {
                return -1;
            }

            dsuInit.join(edge.u, edge.v);
            selectedInit++;
            mustMinStability = std::min(mustMinStability, edge.w);
        }

        int l = 0;
        int r = mustMinStability;

        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);

            DSU dsu(dsuInit.parent);

            int selected = selectedInit;
            int doubledCount = 0;

            for (const auto& edge : optionalEdges) {
                if (dsu.find(edge.u) == dsu.find(edge.v)) {
                    continue;
                }

                if (edge.w >= mid) {
                    dsu.join(edge.u, edge.v);
                    selected++;
                } else if (doubledCount < k && edge.w * 2 >= mid) {
                    doubledCount++;
                    dsu.join(edge.u, edge.v);
                    selected++;
                } else {
                    break;
                }

                if (selected == n - 1) {
                    break;
                }
            }

            if (selected != n - 1) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid;
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
public class DSU {
    public int[] parent;

    public DSU(int[] parent) {
        this.parent = parent;
    }

    public int Find(int x) {
        return this.parent[x] == x
                   ? x
                   : (this.parent[x] = this.Find(this.parent[x]));
    }

    public void Join(int x, int y) {
        int px = this.Find(x);
        int py = this.Find(y);
        this.parent[px] = py;
    }
}

public class Solution {
    const int MAX_STABILITY = 200000;

    public int MaxStability(int n, int[][] edges, int k) {
        int ans = -1;

        if (edges.Length < n - 1) {
            return -1;
        }

        List<int[]> mustEdges = new List<int[]>();
        List<int[]> optionalEdges = new List<int[]>();

        foreach (var edge in edges) {
            if (edge[3] == 1) {
                mustEdges.Add(edge);
            } else {
                optionalEdges.Add(edge);
            }
        }

        if (mustEdges.Count > n - 1) {
            return -1;
        }
        optionalEdges.Sort((a, b) => b[2].CompareTo(a[2]));

        int selectedInit = 0;
        int mustMinStability = MAX_STABILITY;
        int[] initialParent = Enumerable.Range(0, n).ToArray();
        DSU dsuInit = new DSU(initialParent);

        foreach (var edge in mustEdges) {
            if (dsuInit.Find(edge[0]) == dsuInit.Find(edge[1]) ||
                selectedInit == n - 1) {
                return -1;
            }

            dsuInit.Join(edge[0], edge[1]);
            selectedInit++;
            mustMinStability = Math.Min(mustMinStability, edge[2]);
        }

        int l = 0;
        int r = mustMinStability;

        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);

            DSU dsu = new DSU((int[])dsuInit.parent.Clone());

            int selected = selectedInit;
            int doubledCount = 0;

            foreach (var edge in optionalEdges) {
                if (dsu.Find(edge[0]) == dsu.Find(edge[1])) {
                    continue;
                }

                if (edge[2] >= mid) {
                    dsu.Join(edge[0], edge[1]);
                    selected++;
                } else if (doubledCount < k && edge[2] * 2 >= mid) {
                    doubledCount++;
                    dsu.Join(edge[0], edge[1]);
                    selected++;
                } else {
                    break;
                }

                if (selected == n - 1) {
                    break;
                }
            }

            if (selected != n - 1) {
                r = mid - 1;
            } else {
                ans = l = mid;
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
const MAX_STABILITY = 200000

type DSU struct {
	parent []int
}

func NewDSU(parent []int) *DSU {
	p := make([]int, len(parent))
	copy(p, parent)
	return &DSU{parent: p}
}

func (d *DSU) find(x int) int {
	if d.parent[x] != x {
		d.parent[x] = d.find(d.parent[x])
	}
	return d.parent[x]
}

func (d *DSU) join(x, y int) {
	px := d.find(x)
	py := d.find(y)
	d.parent[px] = py
}

func maxStability(n int, edges [][]int, k int) int {
	ans := -1

	if len(edges) < n-1 {
		return -1
	}
	mustEdges := [][]int{}
	optionalEdges := [][]int{}

	for _, e := range edges {
		if e[3] == 1 {
			mustEdges = append(mustEdges, e)
		} else {
			optionalEdges = append(optionalEdges, e)
		}
	}

	if len(mustEdges) > n-1 {
		return -1
	}

	sort.Slice(optionalEdges, func(i, j int) bool {
		return optionalEdges[i][2] > optionalEdges[j][2]
	})

	selectedInit := 0
	mustMinStability := MAX_STABILITY

	initParent := make([]int, n)
	for i := 0; i < n; i++ {
		initParent[i] = i
	}
	dsuInit := NewDSU(initParent)

	for _, e := range mustEdges {
		u, v, s := e[0], e[1], e[2]
		if dsuInit.find(u) == dsuInit.find(v) || selectedInit == n-1 {
			return -1
		}
		dsuInit.join(u, v)
		selectedInit++
		if s < mustMinStability {
			mustMinStability = s
		}
	}

	l, r := 0, mustMinStability
	for l < r {
		mid := l + (r-l+1)/2

		dsu := NewDSU(dsuInit.parent)
		selected := selectedInit
		doubledCount := 0

		for _, e := range optionalEdges {
			u, v, s := e[0], e[1], e[2]
			if dsu.find(u) == dsu.find(v) {
				continue
			}

			if s >= mid {
				dsu.join(u, v)
				selected++
			} else if doubledCount < k && s*2 >= mid {
				doubledCount++
				dsu.join(u, v)
				selected++
			} else {
				break
			}

			if selected == n-1 {
				break
			}
		}

		if selected != n-1 {
			r = mid - 1
		} else {
			ans = mid
			l = mid
		}
	}

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class DSU {

    int[] parent;

    DSU(int[] parent) {
        this.parent = parent.clone();
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void join(int x, int y) {
        int px = find(x);
        int py = find(y);
        parent[px] = py;
    }
}

public class Solution {

    private static final int MAX_STABILITY = 200000;

    public int maxStability(int n, int[][] edges, int k) {
        int ans = -1;
        if (edges.length < n - 1) {
            return -1;
        }
        List<int[]> mustEdges = new ArrayList<>();
        List<int[]> optionalEdges = new ArrayList<>();

        for (int[] edge : edges) {
            if (edge[3] == 1) {
                mustEdges.add(edge);
            } else {
                optionalEdges.add(edge);
            }
        }

        if (mustEdges.size() > n - 1) {
            return -1;
        }

        optionalEdges.sort((a, b) -> b[2] - a[2]);
        int selectedInit = 0;
        int mustMinStability = MAX_STABILITY;

        int[] initParent = new int[n];
        for (int i = 0; i < n; i++) {
            initParent[i] = i;
        }
        DSU dsuInit = new DSU(initParent);

        for (int[] e : mustEdges) {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            if (dsuInit.find(u) == dsuInit.find(v) || selectedInit == n - 1) {
                return -1;
            }
            dsuInit.join(u, v);
            selectedInit++;
            mustMinStability = Math.min(mustMinStability, s);
        }

        int l = 0;
        int r = mustMinStability;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;

            DSU dsu = new DSU(dsuInit.parent);
            int selected = selectedInit;
            int doubledCount = 0;

            for (int[] e : optionalEdges) {
                int u = e[0];
                int v = e[1];
                int s = e[2];
                if (dsu.find(u) == dsu.find(v)) {
                    continue;
                }
                if (s >= mid) {
                    dsu.join(u, v);
                    selected++;
                } else if (doubledCount < k && s * 2 >= mid) {
                    doubledCount++;
                    dsu.join(u, v);
                    selected++;
                } else {
                    break;
                }
                if (selected == n - 1) {
                    break;
                }
            }

            if (selected != n - 1) {
                r = mid - 1;
            } else {
                ans = l = mid;
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
class DSU {
    constructor(parent) {
        this.parent = parent;
    }

    find(x) {
        return this.parent[x] === x
            ? x
            : (this.parent[x] = this.find(this.parent[x]));
    }

    join(x, y) {
        const px = this.find(x);
        const py = this.find(y);
        this.parent[px] = py;
    }
}

const MAX_STABILITY = 2e5;

var maxStability = function (n, edges, k) {
    let ans = -1;

    if (edges.length < n - 1) {
        return -1;
    }

    const mustEdges = edges.filter(([, , , must]) => must === 1);
    const optionalEdges = edges.filter(([, , , must]) => must !== 1);

    if (mustEdges.length > n - 1) {
        return -1;
    }
    optionalEdges.sort((a, b) => b[2] - a[2]);

    let selectedInit = 0;
    let mustMinStability = MAX_STABILITY;
    const dsuInit = new DSU(Array.from({ length: n }, (_, i) => i));

    for (const [u, v, s] of mustEdges) {
        if (dsuInit.find(u) === dsuInit.find(v) || selectedInit === n - 1) {
            return -1;
        }

        dsuInit.join(u, v);
        selectedInit++;
        mustMinStability = Math.min(mustMinStability, s);
    }

    let l = 0;
    let r = mustMinStability;

    while (l < r) {
        const mid = l + ((r - l + 1) >>> 1);

        const dsu = new DSU(dsuInit.parent.slice());

        let selected = selectedInit;
        let doubledCount = 0;

        for (const [u, v, s] of optionalEdges) {
            if (dsu.find(u) === dsu.find(v)) {
                continue;
            }

            if (s >= mid) {
                dsu.join(u, v);
                selected++;
            } else if (doubledCount < k && s * 2 >= mid) {
                doubledCount++;
                dsu.join(u, v);
                selected++;
            } else {
                break;
            }

            if (selected === n - 1) {
                break;
            }
        }

        if (selected !== n - 1) {
            r = mid - 1;
        } else {
            ans = l = mid;
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class DSU:
    def __init__(self, parent):
        self.parent = parent

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def join(self, x, y):
        px = self.find(x)
        py = self.find(y)
        self.parent[px] = py


MAX_STABILITY = 200000


class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        ans = -1

        if len(edges) < n - 1:
            return -1

        mustEdges = [e for e in edges if e[3] == 1]
        optionalEdges = [e for e in edges if e[3] != 1]

        if len(mustEdges) > n - 1:
            return -1

        optionalEdges.sort(key=lambda x: x[2], reverse=True)

        selectedInit = 0
        mustMinStability = MAX_STABILITY
        dsuInit = DSU(list(range(n)))

        for u, v, s, must in mustEdges:
            if dsuInit.find(u) == dsuInit.find(v) or selectedInit == n - 1:
                return -1
            dsuInit.join(u, v)
            selectedInit += 1
            mustMinStability = min(mustMinStability, s)

        l = 0
        r = mustMinStability

        while l < r:
            mid = l + ((r - l + 1) >> 1)
            dsu = DSU(dsuInit.parent[:])
            selected = selectedInit
            doubledCount = 0

            for u, v, s, must in optionalEdges:
                if dsu.find(u) == dsu.find(v):
                    continue

                if s >= mid:
                    dsu.join(u, v)
                    selected += 1
                elif doubledCount < k and s * 2 >= mid:
                    doubledCount += 1
                    dsu.join(u, v)
                    selected += 1
                else:
                    break

                if selected == n - 1:
                    break

            if selected != n - 1:
                r = mid - 1
            else:
                ans = l = mid

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class DSU {
    constructor(public parent: number[]) {}

    find(x: number): number {
        return this.parent[x] === x
            ? x
            : (this.parent[x] = this.find(this.parent[x]));
    }

    join(x: number, y: number) {
        const px = this.find(x);
        const py = this.find(y);
        this.parent[px] = py;
    }
}

const MAX_STABILITY = 2e5;

function maxStability(n: number, edges: number[][], k: number): number {
    let ans = -1;

    if (edges.length < n - 1) {
        return -1;
    }

    const mustEdges = edges.filter(([, , , must]) => must === 1);
    const optionalEdges = edges.filter(([, , , must]) => must !== 1);

    if (mustEdges.length > n - 1) {
        return -1;
    }
    optionalEdges.sort((a, b) => b[2] - a[2]);

    let selectedInit = 0;
    let mustMinStability = MAX_STABILITY;
    const dsuInit = new DSU(Array.from({ length: n }, (_, i) => i));

    for (const [u, v, s] of mustEdges) {
        if (dsuInit.find(u) === dsuInit.find(v) || selectedInit === n - 1) {
            return -1;
        }

        dsuInit.join(u, v);
        selectedInit++;
        mustMinStability = Math.min(mustMinStability, s);
    }

    let l = 0;
    let r = mustMinStability;

    while (l < r) {
        const mid = l + ((r - l + 1) >>> 1);

        const dsu = new DSU(dsuInit.parent.slice());

        let selected = selectedInit;
        let doubledCount = 0;

        for (const [u, v, s] of optionalEdges) {
            if (dsu.find(u) === dsu.find(v)) {
                continue;
            }

            if (s >= mid) {
                dsu.join(u, v);
                selected++;
            } else if (doubledCount < k && s * 2 >= mid) {
                doubledCount++;
                dsu.join(u, v);
                selected++;
            } else {
                break;
            }

            if (selected === n - 1) {
                break;
            }
        }

        if (selected !== n - 1) {
            r = mid - 1;
        } else {
            ans = l = mid;
        }
    }

    return ans;
}
```

</details>
