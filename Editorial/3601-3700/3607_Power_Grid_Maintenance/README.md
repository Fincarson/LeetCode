# 3607. Power Grid Maintenance

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/power-grid-maintenance/)  
`Array` `Hash Table` `Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory` `Heap (Priority Queue)` `Ordered Set`

**Problem Link:** [LeetCode 3607 - Power Grid Maintenance](https://leetcode.com/problems/power-grid-maintenance/)

## Problem

You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1Ã¢â‚¬â€˜based indexing).

These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.

Initially, all stations are online (operational).

You are also given a 2D array queries, where each query is one of the following two types:

- [1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid as x. If no operational station exists in that grid, return -1.
- [2, x]: Station x goes offline (i.e., it becomes non-operational).

Return an array of integers representing the results of each query of type [1, x] in the order they appear.

Note: The power grid preserves its structure; an offline (nonÃ¢â‚¬â€˜operational) node remains part of its grid and taking it offline does not alter connectivity.

### Example 1

### Example 2

## Constraints

- 1 <= c <= 105
- 0 <= n == connections.length <= min(105, c * (c - 1) / 2)
- connections[i].length == 2
- 1 <= ui, vi <= c
- ui != vi
- 1 <= queries.length <= 2 * 105
- queries[i].length == 2
- queries[i][0] is either 1 or 2.
- 1 <= queries[i][1] <= c

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3607. Power Grid Maintenance

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Union-Find + Reverse Processing Query | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| DFS/BFS + Priority Queue | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Union-Find + Reverse Processing Query

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* parent;
    int size;
} DSU;

DSU* dsuCreate(int size) {
    DSU* obj = (DSU*)malloc(sizeof(DSU));
    obj->size = size;
    obj->parent = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        obj->parent[i] = i;
    }
    return obj;
}

int dsuFind(DSU* obj, int x) {
    if (obj->parent[x] != x) {
        obj->parent[x] = dsuFind(obj, obj->parent[x]);
    }
    return obj->parent[x];
}

void dsuJoin(DSU* obj, int u, int v) {
    obj->parent[dsuFind(obj, v)] = dsuFind(obj, u);
}

void dsuFree(DSU* obj) {
    free(obj->parent);
    free(obj);
}

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int* processQueries(int c, int** connections, int connectionsSize,
                    int* connectionsColSize, int** queries, int queriesSize,
                    int* queriesColSize, int* returnSize) {
    DSU* dsu = dsuCreate(c + 1);
    for (int i = 0; i < connectionsSize; i++) {
        dsuJoin(dsu, connections[i][0], connections[i][1]);
    }

    bool* online = (bool*)malloc((c + 1) * sizeof(bool));
    int* offlineCounts = (int*)calloc(c + 1, sizeof(int));
    for (int i = 0; i <= c; i++) {
        online[i] = true;
    }

    HashItem* minimumOnlineStations = NULL;
    for (int i = 0; i < queriesSize; i++) {
        int op = queries[i][0];
        int x = queries[i][1];
        if (op == 2) {
            online[x] = false;
            offlineCounts[x]++;
        }
    }

    for (int i = 1; i <= c; i++) {
        int root = dsuFind(dsu, i);
        if (!hashFindItem(&minimumOnlineStations, root)) {
            hashAddItem(&minimumOnlineStations, root, -1);
        }
        int station = hashGetItem(&minimumOnlineStations, root, -1);
        if (online[i]) {
            if (station == -1 || station > i) {
                hashSetItem(&minimumOnlineStations, root, i);
            }
        }
    }

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    int ansSize = 0;
    for (int i = queriesSize - 1; i >= 0; i--) {
        int op = queries[i][0];
        int x = queries[i][1];
        int root = dsuFind(dsu, x);
        int station = hashGetItem(&minimumOnlineStations, root, -1);

        if (op == 1) {
            if (online[x]) {
                ans[ansSize++] = x;
            } else {
                ans[ansSize++] = station;
            }
        }

        if (op == 2) {
            if (offlineCounts[x] > 1) {
                offlineCounts[x]--;
            } else {
                online[x] = true;
                if (station == -1 || station > x) {
                    hashSetItem(&minimumOnlineStations, root, x);
                }
            }
        }
    }

    for (int i = 0, j = ansSize - 1; i < j; i++, j--) {
        int temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;
    }

    *returnSize = ansSize;
    dsuFree(dsu);
    free(online);
    free(offlineCounts);
    hashFree(&minimumOnlineStations);

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class DSU {
public:
    vector<int> parent;
    DSU(int size) {
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    void join(int u, int v) { parent[find(v)] = find(u); }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        DSU dsu(c + 1);

        for (auto& p : connections) {
            dsu.join(p[0], p[1]);
        }

        vector<bool> online(c + 1, true);
        vector<int> offlineCounts(c + 1, 0);
        unordered_map<int, int> minimumOnlineStations;

        for (auto& q : queries) {
            int op = q[0], x = q[1];
            if (op == 2) {
                online[x] = false;
                offlineCounts[x]++;
            }
        }

        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            if (!minimumOnlineStations.count(root)) {
                minimumOnlineStations[root] = -1;
            }

            int station = minimumOnlineStations[root];
            if (online[i]) {
                if (station == -1 || station > i) {
                    minimumOnlineStations[root] = i;
                }
            }
        }

        vector<int> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            int op = queries[i][0], x = queries[i][1];
            int root = dsu.find(x);
            int station = minimumOnlineStations[root];

            if (op == 1) {
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    ans.push_back(station);
                }
            }

            if (op == 2) {
                if (offlineCounts[x] > 1) {
                    offlineCounts[x]--;
                } else {
                    online[x] = true;
                    if (station == -1 || station > x) {
                        minimumOnlineStations[root] = x;
                    }
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class DSU {
    private int[] parent;

    public DSU(int size) {
        parent = new int[size];
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    public int Find(int x) {
        return parent[x] == x ? x : (parent[x] = Find(parent[x]));
    }

    public void Join(int u, int v) {
        parent[Find(v)] = Find(u);
    }
}

public class Solution {
    public int[] ProcessQueries(int c, int[][] connections, int[][] queries) {
        DSU dsu = new DSU(c + 1);

        foreach (var p in connections) {
            dsu.Join(p[0], p[1]);
        }

        bool[] online = new bool[c + 1];
        int[] offlineCounts = new int[c + 1];
        Array.Fill(online, true);

        Dictionary<int, int> minimumOnlineStations = new Dictionary<int, int>();
        foreach (var q in queries) {
            int op = q[0], x = q[1];
            if (op == 2) {
                online[x] = false;
                offlineCounts[x]++;
            }
        }

        for (int i = 1; i <= c; i++) {
            int root = dsu.Find(i);
            if (!minimumOnlineStations.ContainsKey(root)) {
                minimumOnlineStations[root] = -1;
            }

            int station = minimumOnlineStations[root];
            if (online[i]) {
                if (station == -1 || station > i) {
                    minimumOnlineStations[root] = i;
                }
            }
        }

        List<int> ans = new List<int>();
        for (int i = queries.Length - 1; i >= 0; i--) {
            int op = queries[i][0], x = queries[i][1];
            int root = dsu.Find(x);
            int station = minimumOnlineStations[root];

            if (op == 1) {
                if (online[x]) {
                    ans.Add(x);
                } else {
                    ans.Add(station);
                }
            }

            if (op == 2) {
                if (offlineCounts[x] > 1) {
                    offlineCounts[x]--;
                } else {
                    online[x] = true;
                    if (station == -1 || station > x) {
                        minimumOnlineStations[root] = x;
                    }
                }
            }
        }

        ans.Reverse();
        return ans.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type DSU struct {
	parent []int
}

func NewDSU(size int) *DSU {
	parent := make([]int, size)
	for i := range parent {
		parent[i] = i
	}
	return &DSU{parent: parent}
}

func (this *DSU) Find(x int) int {
	if this.parent[x] == x {
		return x
	}
	this.parent[x] = this.Find(this.parent[x])
	return this.parent[x]
}

func (this *DSU) Join(u, v int) {
	this.parent[this.Find(v)] = this.Find(u)
}

func processQueries(c int, connections [][]int, queries [][]int) []int {
	dsu := NewDSU(c + 1)

	for _, p := range connections {
		dsu.Join(p[0], p[1])
	}
	online := make([]bool, c+1)
	offlineCounts := make([]int, c+1)
	for i := range online {
		online[i] = true
	}

	minimumOnlineStations := make(map[int]int)
	for _, q := range queries {
		op, x := q[0], q[1]
		if op == 2 {
			online[x] = false
			offlineCounts[x]++
		}
	}

	for i := 1; i <= c; i++ {
		root := dsu.Find(i)
		if _, exists := minimumOnlineStations[root]; !exists {
			minimumOnlineStations[root] = -1
		}
		station := minimumOnlineStations[root]
		if online[i] {
			if station == -1 || station > i {
				minimumOnlineStations[root] = i
			}
		}
	}

	ans := []int{}
	for i := len(queries) - 1; i >= 0; i-- {
		op, x := queries[i][0], queries[i][1]
		root := dsu.Find(x)
		station := minimumOnlineStations[root]
		if op == 1 {
			if online[x] {
				ans = append(ans, x)
			} else {
				ans = append(ans, station)
			}
		}

		if op == 2 {
			if offlineCounts[x] > 1 {
				offlineCounts[x]--
			} else {
				online[x] = true
				if station == -1 || station > x {
					minimumOnlineStations[root] = x
				}
			}
		}
	}

	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class DSU {

    private int[] parent;

    public DSU(int size) {
        parent = new int[size];
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    public int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    public void join(int u, int v) {
        parent[find(v)] = find(u);
    }
}

class Solution {

    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        DSU dsu = new DSU(c + 1);

        for (int[] p : connections) {
            dsu.join(p[0], p[1]);
        }

        boolean[] online = new boolean[c + 1];
        int[] offlineCounts = new int[c + 1];
        Arrays.fill(online, true);
        Map<Integer, Integer> minimumOnlineStations = new HashMap<>();
        for (int[] q : queries) {
            int op = q[0];
            int x = q[1];
            if (op == 2) {
                online[x] = false;
                offlineCounts[x]++;
            }
        }

        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            if (!minimumOnlineStations.containsKey(root)) {
                minimumOnlineStations.put(root, -1);
            }

            int station = minimumOnlineStations.get(root);
            if (online[i]) {
                if (station == -1 || station > i) {
                    minimumOnlineStations.put(root, i);
                }
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = queries.length - 1; i >= 0; i--) {
            int op = queries[i][0];
            int x = queries[i][1];
            int root = dsu.find(x);
            int station = minimumOnlineStations.get(root);

            if (op == 1) {
                if (online[x]) {
                    ans.add(x);
                } else {
                    ans.add(station);
                }
            }

            if (op == 2) {
                if (offlineCounts[x] > 1) {
                    offlineCounts[x]--;
                } else {
                    online[x] = true;
                    if (station == -1 || station > x) {
                        minimumOnlineStations.put(root, x);
                    }
                }
            }
        }

        Collections.reverse(ans);
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class DSU {
    constructor(size) {
        this.size = size;
        this.parent = Array.from({ length: size }).map((_, i) => i);
    }

    join(u, v) {
        this.parent[this.find(v)] = this.find(u);
    }

    find(x) {
        return this.parent[x] === x
            ? x
            : (this.parent[x] = this.find(this.parent[x]));
    }
}

var processQueries = function (c, connections, queries) {
    const dsu = new DSU(c + 1);

    connections.forEach(([u, v]) => {
        dsu.join(u, v);
    });

    const online = Array.from({ length: c + 1 }).fill(true);
    const offlineCounts = Array.from({ length: c + 1 }).fill(0);
    const minimumOnlineStations = new Map();

    for (const [op, x] of queries) {
        if (op === 2) {
            online[x] = false;
            offlineCounts[x] += 1;
        }
    }

    for (let i = 1; i <= c; i++) {
        const root = dsu.find(i);
        if (!minimumOnlineStations.has(root)) {
            minimumOnlineStations.set(root, -1);
        }

        const station = minimumOnlineStations.get(root);
        if (online[i] === true) {
            if (station === -1 || station > i) {
                minimumOnlineStations.set(root, i);
            }
        }
    }

    const ans = [];

    for (const [op, x] of queries.reverse()) {
        const root = dsu.find(x);
        const station = minimumOnlineStations.get(root);

        if (op === 1) {
            if (online[x]) {
                ans.push(x);
            } else {
                ans.push(station);
            }
        }

        if (op === 2) {
            if (offlineCounts[x] > 1) {
                offlineCounts[x] -= 1;
            } else {
                online[x] = true;
                if (station === -1 || station > x) {
                    minimumOnlineStations.set(root, x);
                }
            }
        }
    }

    return ans.reverse();
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class DSU:
    def __init__(self, size):
        self.parent = list(range(size))

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def join(self, u, v):
        self.parent[self.find(v)] = self.find(u)


class Solution:
    def processQueries(
        self, c: int, connections: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        dsu = DSU(c + 1)
        for p in connections:
            dsu.join(p[0], p[1])

        online = [True] * (c + 1)
        offline_counts = [0] * (c + 1)
        minimum_online_stations = {}

        for q in queries:
            op, x = q[0], q[1]
            if op == 2:
                online[x] = False
                offline_counts[x] += 1

        for i in range(1, c + 1):
            root = dsu.find(i)
            if root not in minimum_online_stations:
                minimum_online_stations[root] = -1

            station = minimum_online_stations[root]
            if online[i]:
                if station == -1 or station > i:
                    minimum_online_stations[root] = i

        ans = []
        for i in range(len(queries) - 1, -1, -1):
            op, x = queries[i][0], queries[i][1]
            root = dsu.find(x)
            station = minimum_online_stations[root]

            if op == 1:
                if online[x]:
                    ans.append(x)
                else:
                    ans.append(station)

            if op == 2:
                if offline_counts[x] > 1:
                    offline_counts[x] -= 1
                else:
                    online[x] = True
                    if station == -1 or station > x:
                        minimum_online_stations[root] = x

        return ans[::-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class DSU {
    parent: number[];

    constructor(public size: number) {
        this.parent = Array.from({ length: size }).map((_, i) => i);
    }

    join(u: number, v: number) {
        this.parent[this.find(v)] = this.find(u);
    }

    find(x: number) {
        return this.parent[x] === x
            ? x
            : (this.parent[x] = this.find(this.parent[x]));
    }
}

function processQueries(
    c: number,
    connections: number[][],
    queries: number[][],
): number[] {
    const dsu = new DSU(c + 1);

    connections.forEach(([u, v]) => {
        dsu.join(u, v);
    });

    const online = Array.from<boolean>({ length: c + 1 }).fill(true);
    const offlineCounts = Array.from<number>({ length: c + 1 }).fill(0);
    const minimumOnlineStations = new Map<number, number>();

    for (const [op, x] of queries) {
        if (op === 2) {
            online[x] = false;
            offlineCounts[x] += 1;
        }
    }

    for (let i = 1; i <= c; i++) {
        const root = dsu.find(i);
        if (!minimumOnlineStations.has(root)) {
            minimumOnlineStations.set(root, -1);
        }

        const station = minimumOnlineStations.get(root)!;
        if (online[i] === true) {
            if (station === -1 || station > i) {
                minimumOnlineStations.set(root, i);
            }
        }
    }

    const ans: number[] = [];

    for (const [op, x] of queries.reverse()) {
        const root = dsu.find(x);
        const station = minimumOnlineStations.get(root)!;

        if (op === 1) {
            if (online[x]) {
                ans.push(x);
            } else {
                ans.push(station);
            }
        }

        if (op === 2) {
            if (offlineCounts[x] > 1) {
                offlineCounts[x] -= 1;
            } else {
                online[x] = true;
                if (station === -1 || station > x) {
                    minimumOnlineStations.set(root, x);
                }
            }
        }
    }

    return ans.reverse();
}
```

</details>

<br>

## Approach 2: DFS/BFS + Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Vertex {
public:
    int vertexId;
    bool offline = false;
    int powerGridId = -1;

    Vertex() {}
    Vertex(int id) : vertexId(id) {}
};

using PowerGrid = priority_queue<int, vector<int>, greater<int>>;
using Graph = vector<vector<int>>;

class Solution {
private:
    vector<Vertex> vertices = vector<Vertex>();

    void traverse(Vertex& u, int powerGridId, PowerGrid& powerGrid,
                  Graph& graph) {
        u.powerGridId = powerGridId;
        powerGrid.push(u.vertexId);
        for (int vid : graph[u.vertexId]) {
            Vertex& v = vertices[vid];
            if (v.powerGridId == -1) traverse(v, powerGridId, powerGrid, graph);
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        Graph graph(c + 1);
        vertices.resize(c + 1);

        for (int i = 1; i <= c; i++) {
            vertices[i] = Vertex(i);
        }

        for (auto& conn : connections) {
            graph[conn.at(0)].push_back(conn.at(1));
            graph[conn.at(1)].push_back(conn.at(0));
        }

        vector<PowerGrid> powerGrids;

        for (int i = 1, powerGridId = 0; i <= c; i++) {
            auto& v = vertices[i];
            if (v.powerGridId == -1) {
                PowerGrid powerGrid;
                traverse(v, powerGridId, powerGrid, graph);
                powerGrids.push_back(powerGrid);
                powerGridId++;
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int op = q.at(0), x = q.at(1);
            if (op == 1) {
                if (!vertices[x].offline) {
                    ans.push_back(x);
                } else {
                    auto& powerGrid = powerGrids[vertices[x].powerGridId];
                    while (!powerGrid.empty() &&
                           vertices[powerGrid.top()].offline) {
                        powerGrid.pop();
                    }
                    ans.push_back(!powerGrid.empty() ? powerGrid.top() : -1);
                }
            } else if (op == 2) {
                vertices[x].offline = true;
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
public class Vertex {
    public int vertexId;
    public bool offline = false;
    public int powerGridId = -1;

    public Vertex() {}

    public Vertex(int id) {
        this.vertexId = id;
    }
}

public class Graph {
    private Dictionary<int, List<int>> adj;
    private Dictionary<int, Vertex> vertices;

    public Graph() {
        this.adj = new Dictionary<int, List<int>>();
        this.vertices = new Dictionary<int, Vertex>();
    }

    public void AddVertex(int id, Vertex value) {
        this.vertices[id] = value;
        this.adj[id] = new List<int>();
    }

    public void AddEdge(int u, int v) {
        this.adj[u].Add(v);
        this.adj[v].Add(u);
    }

    public Vertex GetVertexValue(int id) {
        return this.vertices[id];
    }

    public List<int> GetConnectedVertices(int id) {
        return this.adj[id];
    }
}

public class Solution {
    private void Traverse(Vertex u, int powerGridId,
                          PriorityQueue<int, int> powerGrid, Graph graph) {
        u.powerGridId = powerGridId;
        powerGrid.Enqueue(u.vertexId, u.vertexId);
        foreach (int vid in graph.GetConnectedVertices(u.vertexId)) {
            Vertex v = graph.GetVertexValue(vid);
            if (v.powerGridId == -1) {
                Traverse(v, powerGridId, powerGrid, graph);
            }
        }
    }

    public int[] ProcessQueries(int c, int[][] connections, int[][] queries) {
        Graph graph = new Graph();
        for (int i = 0; i < c; i++) {
            Vertex v = new Vertex(i + 1);
            graph.AddVertex(i + 1, v);
        }

        foreach (int[] conn in connections) {
            graph.AddEdge(conn[0], conn[1]);
        }

        List<PriorityQueue<int, int>> powerGrids =
            new List<PriorityQueue<int, int>>();
        for (int i = 1, powerGridId = 0; i <= c; i++) {
            Vertex v = graph.GetVertexValue(i);
            if (v.powerGridId == -1) {
                PriorityQueue<int, int> powerGrid =
                    new PriorityQueue<int, int>();
                Traverse(v, powerGridId, powerGrid, graph);
                powerGrids.Add(powerGrid);
                powerGridId++;
            }
        }

        List<int> ans = new List<int>();
        foreach (int[] q in queries) {
            int op = q[0], x = q[1];
            if (op == 1) {
                Vertex vertex = graph.GetVertexValue(x);
                if (!vertex.offline) {
                    ans.Add(x);
                } else {
                    PriorityQueue<int, int> powerGrid =
                        powerGrids[vertex.powerGridId];
                    while (powerGrid.Count > 0 &&
                           graph.GetVertexValue(powerGrid.Peek()).offline) {
                        powerGrid.Dequeue();
                    }
                    ans.Add(powerGrid.Count > 0 ? powerGrid.Peek() : -1);
                }
            } else if (op == 2) {
                graph.GetVertexValue(x).offline = true;
            }
        }

        return ans.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func traverse(u *Vertex, powerGridId int, powerGrid *IntHeap, graph *Graph) {
	u.powerGridId = powerGridId
	heap.Push(powerGrid, u.vertexId)
	for _, vid := range graph.GetConnectedVertices(u.vertexId) {
		v := graph.GetVertexValue(vid)
		if v.powerGridId == -1 {
			traverse(v, powerGridId, powerGrid, graph)
		}
	}
}

func processQueries(c int, connections [][]int, queries [][]int) []int {
	graph := NewGraph()
	for i := 0; i < c; i++ {
		v := NewVertex(i + 1)
		graph.AddVertex(i + 1, v)
	}

	for _, conn := range connections {
		graph.AddEdge(conn[0], conn[1])
	}

	powerGrids := []*IntHeap{}
	for i, powerGridId := 1, 0; i <= c; i++ {
		v := graph.GetVertexValue(i)
		if v.powerGridId == -1 {
			powerGrid := &IntHeap{}
			heap.Init(powerGrid)
			traverse(v, powerGridId, powerGrid, graph)
			powerGrids = append(powerGrids, powerGrid)
			powerGridId++
		}
	}

	ans := []int{}
	for _, q := range queries {
		op, x := q[0], q[1]
		if op == 1 {
			vertex := graph.GetVertexValue(x)
			if !vertex.offline {
				ans = append(ans, x)
			} else {
				powerGrid := powerGrids[vertex.powerGridId]
				for len(*powerGrid) > 0 && graph.GetVertexValue((*powerGrid)[0]).offline {
					heap.Pop(powerGrid)
				}
				if len(*powerGrid) > 0 {
					ans = append(ans, (*powerGrid)[0])
				} else {
					ans = append(ans, -1)
				}
			}
		} else if op == 2 {
			graph.GetVertexValue(x).offline = true
		}
	}
	return ans
}

type Vertex struct {
	vertexId    int
	offline     bool
	powerGridId int
}

func NewVertex(id int) *Vertex {
	return &Vertex{
		vertexId:    id,
		offline:     false,
		powerGridId: -1,
	}
}

type Graph struct {
	adj      map[int][]int
	vertices map[int]*Vertex
}

func NewGraph() *Graph {
	return &Graph{
		adj:      make(map[int][]int),
		vertices: make(map[int]*Vertex),
	}
}

func (this *Graph) AddVertex(id int, value *Vertex) {
	this.vertices[id] = value
	this.adj[id] = []int{}
}

func (this *Graph) AddEdge(u, v int) {
	this.adj[u] = append(this.adj[u], v)
	this.adj[v] = append(this.adj[v], u)
}

func (this *Graph) GetVertexValue(id int) *Vertex {
	return this.vertices[id]
}

func (this *Graph) GetConnectedVertices(id int) []int {
	return this.adj[id]
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n - 1]
	*h = old[0 : n - 1]
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Vertex {

    public int vertexId;
    public boolean offline = false;
    public int powerGridId = -1;

    public Vertex() {}

    public Vertex(int id) {
        this.vertexId = id;
    }
}

class Graph {

    private Map<Integer, List<Integer>> adj;
    private Map<Integer, Vertex> vertices;

    public Graph() {
        this.adj = new HashMap<>();
        this.vertices = new HashMap<>();
    }

    public void addVertex(int id, Vertex value) {
        this.vertices.put(id, value);
        this.adj.put(id, new ArrayList<>());
    }

    public void addEdge(int u, int v) {
        this.adj.get(u).add(v);
        this.adj.get(v).add(u);
    }

    public Vertex getVertexValue(int id) {
        return this.vertices.get(id);
    }

    public List<Integer> getConnectedVertices(int id) {
        return this.adj.get(id);
    }
}

class Solution {

    private void traverse(
        Vertex u,
        int powerGridId,
        PriorityQueue<Integer> powerGrid,
        Graph graph
    ) {
        u.powerGridId = powerGridId;
        powerGrid.add(u.vertexId);
        for (int vid : graph.getConnectedVertices(u.vertexId)) {
            Vertex v = graph.getVertexValue(vid);
            if (v.powerGridId == -1) {
                traverse(v, powerGridId, powerGrid, graph);
            }
        }
    }

    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        Graph graph = new Graph();
        for (int i = 0; i < c; i++) {
            Vertex v = new Vertex(i + 1);
            graph.addVertex(i + 1, v);
        }

        for (int[] conn : connections) {
            graph.addEdge(conn[0], conn[1]);
        }

        List<PriorityQueue<Integer>> powerGrids = new ArrayList<>();
        for (int i = 1, powerGridId = 0; i <= c; i++) {
            Vertex v = graph.getVertexValue(i);
            if (v.powerGridId == -1) {
                PriorityQueue<Integer> powerGrid = new PriorityQueue<>();
                traverse(v, powerGridId, powerGrid, graph);
                powerGrids.add(powerGrid);
                powerGridId++;
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int[] q : queries) {
            int op = q[0];
            int x = q[1];
            if (op == 1) {
                Vertex vertex = graph.getVertexValue(x);
                if (!vertex.offline) {
                    ans.add(x);
                } else {
                    PriorityQueue<Integer> powerGrid = powerGrids.get(
                        vertex.powerGridId
                    );
                    while (
                        !powerGrid.isEmpty() &&
                        graph.getVertexValue(powerGrid.peek()).offline
                    ) {
                        powerGrid.poll();
                    }
                    ans.add(!powerGrid.isEmpty() ? powerGrid.peek() : -1);
                }
            } else if (op == 2) {
                graph.getVertexValue(x).offline = true;
            }
        }

        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var processQueries = function (c, connections, queries) {
    const graph = Array.from({ length: c + 1 }, () => []);
    const vertices = Array.from({ length: c + 1 });

    for (let i = 0; i < c; i++) {
        vertices[i + 1] = {
            offline: false,
            powerGridId: -1,
            vertexId: i + 1,
        };
    }

    connections.forEach(([u, v]) => {
        graph[u].push(v);
        graph[v].push(u);
    });

    const powerGrids = new Array();

    for (let i = 1, powerGridId = 0; i <= c; i++) {
        if (vertices[i].powerGridId === -1) {
            const powerGrid = new MinPriorityQueue();

            const traverse = (u) => {
                u.powerGridId = powerGridId;

                powerGrid.enqueue(u.vertexId);

                for (const v of graph[u.vertexId].map((i) => vertices[i])) {
                    if (v.powerGridId === -1) {
                        traverse(v);
                    }
                }
            };

            traverse(vertices[i]);
            powerGrids.push(powerGrid);
            powerGridId += 1;
        }
    }

    const ans = [];

    for (const [op, x] of queries) {
        if (op === 1) {
            if (vertices[x].offline === false) {
                ans.push(x);
            } else {
                const powerGrid = powerGrids[vertices[x].powerGridId];
                while (
                    powerGrid.front() !== null &&
                    vertices[powerGrid.front()].offline === true
                ) {
                    powerGrid.dequeue();
                }

                ans.push(powerGrid.front() !== null ? powerGrid.front() : -1);
            }
        } else if (op === 2) {
            vertices[x].offline = true;
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Vertex:
    def __init__(self, vertex_id: int = None):
        self.vertex_id = vertex_id
        self.offline = False
        self.power_grid_id = -1
        if vertex_id is not None:
            self.vertex_id = vertex_id


class Graph:
    def __init__(self):
        self.adj: Dict[int, List[int]] = {}
        self.vertices: Dict[int, Vertex] = {}

    def add_vertex(self, id: int, value: Vertex):
        self.vertices[id] = value
        self.adj[id] = []

    def add_edge(self, u: int, v: int):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def get_vertex_value(self, id: int) -> Vertex:
        return self.vertices[id]

    def get_connected_vertices(self, id: int) -> List[int]:
        return self.adj[id]


class Solution:
    def traverse(
        self, u: Vertex, power_grid_id: int, power_grid: List[int], graph: Graph
    ):
        u.power_grid_id = power_grid_id
        heapq.heappush(power_grid, u.vertex_id)
        for vid in graph.get_connected_vertices(u.vertex_id):
            v = graph.get_vertex_value(vid)
            if v.power_grid_id == -1:
                self.traverse(v, power_grid_id, power_grid, graph)

    def processQueries(
        self, c: int, connections: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        graph = Graph()
        for i in range(c):
            v = Vertex(i + 1)
            graph.add_vertex(i + 1, v)

        for conn in connections:
            graph.add_edge(conn[0], conn[1])

        power_grids = []
        power_grid_id = 0

        for i in range(1, c + 1):
            v = graph.get_vertex_value(i)
            if v.power_grid_id == -1:
                power_grid = []
                self.traverse(v, power_grid_id, power_grid, graph)
                power_grids.append(power_grid)
                power_grid_id += 1

        ans = []
        for q in queries:
            op, x = q[0], q[1]
            if op == 1:
                vertex = graph.get_vertex_value(x)
                if not vertex.offline:
                    ans.append(x)
                else:
                    power_grid = power_grids[vertex.power_grid_id]
                    while (
                        power_grid
                        and graph.get_vertex_value(power_grid[0]).offline
                    ):
                        heapq.heappop(power_grid)
                    ans.append(power_grid[0] if power_grid else -1)
            elif op == 2:
                graph.get_vertex_value(x).offline = True

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
import { Graph } from "@datastructures-js/graph";

interface Vertex {
    offline: boolean;
    powerGridId: number;
    vertexId: number;
}

function processQueries(
    c: number,
    connections: number[][],
    queries: number[][],
): number[] {
    const graph = new Graph<number, Vertex>();

    for (let i = 0; i < c; i++) {
        graph.addVertex(i + 1, {
            offline: false,
            powerGridId: -1,
            vertexId: i + 1,
        });
    }

    connections.forEach(([u, v]) => {
        graph.addEdge(u, v);
    });

    const getv = graph.getVertexValue.bind(graph);
    const powerGrids = new Array<MinPriorityQueue<number>>();

    for (let i = 1, powerGridId = 0; i <= c; i++) {
        const v = getv(i);

        if (v.powerGridId === -1) {
            const powerGrid = new MinPriorityQueue<number>();

            const traverse = (u: Vertex) => {
                u.powerGridId = powerGridId;

                powerGrid.enqueue(u.vertexId);

                for (const v of graph
                    .getConnectedVertices(u.vertexId)
                    .map(getv)) {
                    if (v.powerGridId === -1) {
                        traverse(v);
                    }
                }
            };

            traverse(v);
            powerGrids.push(powerGrid);
            powerGridId += 1;
        }
    }

    const ans: number[] = [];

    for (const [op, x] of queries) {
        if (op === 1) {
            if (getv(x).offline === false) {
                ans.push(x);
            } else {
                const powerGrid = powerGrids[getv(x).powerGridId];
                while (
                    powerGrid.front() !== null &&
                    getv(powerGrid.front()).offline === true
                ) {
                    powerGrid.dequeue();
                }

                ans.push(powerGrid.front() !== null ? powerGrid.front() : -1);
            }
        } else if (op === 2) {
            getv(x).offline = true;
        }
    }

    return ans;
}
```

</details>
