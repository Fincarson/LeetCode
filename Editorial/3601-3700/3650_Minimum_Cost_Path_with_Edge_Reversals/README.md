# 3650. Minimum Cost Path with Edge Reversals

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/)  
`Graph Theory` `Heap (Priority Queue)` `Shortest Path`

**Problem Link:** [LeetCode 3650 - Minimum Cost Path with Edge Reversals](https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/)

## Problem

You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.

Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi Ã¢â€ â€™ ui reverse that edge to ui Ã¢â€ â€™ vi and immediately traverse it.

The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.

Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

### Example 1

### Example 2

## Constraints

- 2 <= n <= 5 * 104
- 1 <= edges.length <= 105
- edges[i] = [ui, vi, wi]
- 0 <= ui, vi <= n - 1
- 1 <= wi <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost to Reach Destination in Time](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3650. Minimum Cost Path with Edge Reversals

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dijkstra | C, C++, C#, Java, JavaScript, Python3, TypeScript |

## Approach: Dijkstra

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MIN_QUEUE_SIZE 64

typedef struct Element {
    int data[2];
} Element;

typedef bool (*compare)(const void*, const void*);

typedef struct PriorityQueue {
    Element* arr;
    int capacity;
    int queueSize;
    compare lessFunc;
} PriorityQueue;

Element* createElement(int x, int y) {
    Element* obj = (Element*)malloc(sizeof(Element));
    obj->data[0] = x;
    obj->data[1] = y;
    return obj;
}

static bool less(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    return e1->data[0] > e2->data[0];
}

static bool greater(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    return e1->data[0] < e2->data[0];
}

static void memswap(void* m1, void* m2, size_t size) {
    unsigned char* a = (unsigned char*)m1;
    unsigned char* b = (unsigned char*)m2;
    while (size--) {
        *b ^= *a ^= *b ^= *a;
        a++;
        b++;
    }
}

static void swap(Element* arr, int i, int j) {
    memswap(&arr[i], &arr[j], sizeof(Element));
}

static void down(Element* arr, int size, int i, compare cmpFunc) {
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        if (k + 1 < size && cmpFunc(&arr[k], &arr[k + 1])) {
            k++;
        }
        if (cmpFunc(&arr[k], &arr[(k - 1) / 2])) {
            break;
        }
        swap(arr, k, (k - 1) / 2);
    }
}

PriorityQueue* createPriorityQueue(compare cmpFunc) {
    PriorityQueue* obj = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    obj->capacity = MIN_QUEUE_SIZE;
    obj->arr = (Element*)malloc(sizeof(Element) * obj->capacity);
    obj->queueSize = 0;
    obj->lessFunc = cmpFunc;
    return obj;
}

void heapfiy(PriorityQueue* obj) {
    for (int i = obj->queueSize / 2 - 1; i >= 0; i--) {
        down(obj->arr, obj->queueSize, i, obj->lessFunc);
    }
}

void enQueue(PriorityQueue* obj, Element* e) {
    // we need to alloc more space, just twice space size
    if (obj->queueSize == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = realloc(obj->arr, sizeof(Element) * obj->capacity);
    }
    memcpy(&obj->arr[obj->queueSize], e, sizeof(Element));
    for (int i = obj->queueSize;
         i > 0 && obj->lessFunc(&obj->arr[(i - 1) / 2], &obj->arr[i]);
         i = (i - 1) / 2) {
        swap(obj->arr, i, (i - 1) / 2);
    }
    obj->queueSize++;
}

Element* deQueue(PriorityQueue* obj) {
    swap(obj->arr, 0, obj->queueSize - 1);
    down(obj->arr, obj->queueSize - 1, 0, obj->lessFunc);
    Element* e = &obj->arr[obj->queueSize - 1];
    obj->queueSize--;
    return e;
}

bool isEmpty(const PriorityQueue* obj) { return obj->queueSize == 0; }

Element* front(const PriorityQueue* obj) {
    if (obj->queueSize == 0) {
        return NULL;
    } else {
        return &obj->arr[0];
    }
}

void clear(PriorityQueue* obj) { obj->queueSize = 0; }

int size(const PriorityQueue* obj) { return obj->queueSize; }

void freeQueue(PriorityQueue* obj) {
    free(obj->arr);
    free(obj);
}

typedef struct AdjNode {
    int vertex;
    int weight;
    struct AdjNode* next;
} AdjNode;

typedef struct {
    AdjNode** lists;
    int n;
} Graph;

AdjNode* createAdjNode(int vertex, int weight) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->lists = (AdjNode**)malloc(n * sizeof(AdjNode*));
    for (int i = 0; i < n; i++) {
        graph->lists[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjNode* newNode = createAdjNode(dest, weight);
    newNode->next = graph->lists[src];
    graph->lists[src] = newNode;

    AdjNode* reverseNode = createAdjNode(src, 2 * weight);
    reverseNode->next = graph->lists[dest];
    graph->lists[dest] = reverseNode;
}

void freeGraph(Graph* graph) {
    if (!graph) return;

    for (int i = 0; i < graph->n; i++) {
        AdjNode* current = graph->lists[i];
        while (current) {
            AdjNode* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(graph->lists);
    free(graph);
}

int minCost(int n, int** edges, int edgesSize, int* edgesColSize) {
    Graph* graph = createGraph(n);
    for (int i = 0; i < edgesSize; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        int weight = edges[i][2];
        addEdge(graph, src, dest, weight);
    }

    int* dist = (int*)malloc(n * sizeof(int));
    bool* visited = (bool*)calloc(n, sizeof(bool));
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    PriorityQueue* pq = createPriorityQueue(less);

    Element startElem;
    startElem.data[0] = 0;
    startElem.data[1] = 0;
    enQueue(pq, &startElem);

    while (!isEmpty(pq)) {
        Element* current = front(pq);
        int currentDist = current->data[0];
        int x = current->data[1];
        deQueue(pq);

        if (x == n - 1) {
            int result = currentDist;
            free(dist);
            free(visited);
            freeQueue(pq);
            freeGraph(graph);
            return result;
        }
        if (visited[x]) {
            continue;
        }

        visited[x] = true;
        for (AdjNode* neighbor = graph->lists[x]; neighbor != NULL;
             neighbor = neighbor->next) {
            int y = neighbor->vertex;
            int w = neighbor->weight;
            if (currentDist + w < dist[y]) {
                dist[y] = currentDist + w;

                Element newElem;
                newElem.data[0] = dist[y];
                newElem.data[1] = y;
                enQueue(pq, &newElem);
            }
        }
    }

    free(dist);
    free(visited);
    freeQueue(pq);
    freeGraph(graph);

    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    using PII = pair<int, int>;

public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, 2 * w);
        }

        vector<int> d(n, INT_MAX);
        vector<bool> v(n, false);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        d[0] = 0;
        q.emplace(0, 0);

        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (x == n - 1) {
                return d[x];
            }
            // only the first time unloading requires relaxing other points
            if (v[x]) {
                continue;
            }
            v[x] = 1;

            for (auto& [y, w] : g[x]) {
                if (d[x] + w < d[y]) {
                    d[y] = d[x] + w;
                    q.emplace(d[y], y);
                }
            }
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
using System;
using System.Collections.Generic;

public class Solution {
    public int MinCost(int n, int[][] edges) {
        var g = new List<(int node, int weight)>[n];
        for (int i = 0; i < n; i++) {
            g[i] = new List<(int, int)>();
        }

        foreach (var e in edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].Add((y, w));
            g[y].Add((x, 2 * w));
        }

        int[] dist = new int[n];
        bool[] visited = new bool[n];
        Array.Fill(dist, int.MaxValue);
        dist[0] = 0;

        var pq = new PriorityQueue<(int dist, int node), int>();
        pq.Enqueue((0, 0), 0);

        while (pq.Count > 0) {
            var current = pq.Dequeue();
            int currentDist = current.dist;
            int x = current.node;

            if (x == n - 1) {
                return currentDist;
            }

            if (visited[x]) {
                continue;
            }
            visited[x] = true;
            foreach (var neighbor in g[x]) {
                int y = neighbor.node;
                int w = neighbor.weight;

                if (currentDist + w < dist[y]) {
                    dist[y] = currentDist + w;
                    pq.Enqueue((dist[y], y), dist[y]);
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minCost(int n, int[][] edges) {
        List<int[]>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }

        for (int[] e : edges) {
            int x = e[0];
            int y = e[1];
            int w = e[2];
            g[x].add(new int[] { y, w });
            g[y].add(new int[] { x, 2 * w });
        }

        // Dijkstra
        int[] d = new int[n];
        boolean[] visited = new boolean[n];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[0] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>(
            Comparator.comparingInt(a -> a[0])
        );
        pq.offer(new int[] { 0, 0 }); // [Distance, Node]

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int dist = current[0];
            int x = current[1];

            if (x == n - 1) {
                return dist;
            }

            if (visited[x]) {
                continue;
            }
            visited[x] = true;

            for (int[] neighbor : g[x]) {
                int y = neighbor[0];
                int w = neighbor[1];

                if (dist + w < d[y]) {
                    d[y] = dist + w;
                    pq.offer(new int[] { d[y], y });
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minCost = function (n, edges) {
    const g = Array.from({ length: n }, () => []);
    for (const e of edges) {
        const [x, y, w] = e;
        g[x].push([y, w]);
        g[y].push([x, 2 * w]);
    }

    const dist = Array(n).fill(Infinity);
    const visited = Array(n).fill(false);
    dist[0] = 0;
    const pq = new PriorityQueue((a, b) => {
        return a[0] < b[0] ? -1 : 1;
    });
    pq.enqueue([0, 0]);

    while (!pq.isEmpty()) {
        const [currentDist, x] = pq.dequeue();
        if (x === n - 1) {
            return currentDist;
        }

        if (visited[x]) {
            continue;
        }
        visited[x] = true;

        for (const [y, w] of g[x]) {
            if (currentDist + w < dist[y]) {
                dist[y] = currentDist + w;
                pq.enqueue([dist[y], y]);
            }
        }
    }

    return -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for x, y, w in edges:
            g[x].append((y, w))
            g[y].append((x, 2 * w))

        dist = [inf] * n
        visited = [False] * n
        dist[0] = 0
        heap = [(0, 0)]  # (Distance, Node)

        while heap:
            cur_dist, x = heapq.heappop(heap)

            if x == n - 1:
                return cur_dist

            # already processed
            if visited[x]:
                continue
            visited[x] = True

            # relaxing neighbors
            for y, w in g[x]:
                new_dist = cur_dist + w
                if new_dist < dist[y]:
                    dist[y] = new_dist
                    heapq.heappush(heap, (new_dist, y))

        return -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minCost(n: number, edges: number[][]): number {
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const e of edges) {
        const [x, y, w] = e;
        g[x].push([y, w]);
        g[y].push([x, 2 * w]);
    }

    const dist: number[] = Array(n).fill(Infinity);
    const visited: boolean[] = Array(n).fill(false);
    dist[0] = 0;
    const pq = new PriorityQueue<[number, number]>((a, b) => {
        return a[0] < b[0] ? -1 : 1;
    });
    pq.enqueue([0, 0]);

    while (!pq.isEmpty()) {
        const [currentDist, x] = pq.dequeue()!;
        if (x === n - 1) {
            return currentDist;
        }
        if (visited[x]) {
            continue;
        }
        visited[x] = true;

        for (const [y, w] of g[x]) {
            if (currentDist + w < dist[y]) {
                dist[y] = currentDist + w;
                pq.enqueue([dist[y], y]);
            }
        }
    }

    return -1;
}
```

</details>
