# 3341. Find Minimum Time to Reach Last Room I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/)  
`Array` `Graph Theory` `Heap (Priority Queue)` `Matrix` `Shortest Path`

**Problem Link:** [LeetCode 3341 - Find Minimum Time to Reach Last Room I](https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/)

## Problem

There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds after which the room opens and can be moved to. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

### Example 1

### Example 2

### Example 3

## Constraints

- 2 <= n == moveTime.length <= 50
- 2 <= m == moveTime[i].length <= 50
- 0 <= moveTime[i][j] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost to Reach Destination in Time](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Time to Visit a Cell In a Grid](https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3341. Find Minimum Time to Reach Last Room I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Shortest Path + Dijkstra | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Shortest Path + Dijkstra

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MIN_QUEUE_SIZE 64

typedef struct Element {
    int x;
    int y;
    int dist;
} Element;

typedef bool (*compare)(const void *, const void *);

typedef struct PriorityQueue {
    Element *arr;
    int capacity;
    int queueSize;
    compare lessFunc;
} PriorityQueue;

static bool greater(const void *a, const void *b) {
    Element *e1 = (Element *)a;
    Element *e2 = (Element *)b;
    return e1->dist > e2->dist;
}

static void memswap(void *m1, void *m2, size_t size) {
    unsigned char *a = (unsigned char *)m1;
    unsigned char *b = (unsigned char *)m2;
    while (size--) {
        *b ^= *a ^= *b ^= *a;
        a++;
        b++;
    }
}

static void swap(Element *arr, int i, int j) {
    memswap(&arr[i], &arr[j], sizeof(Element));
}

static void down(Element *arr, int size, int i, compare cmpFunc) {
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

PriorityQueue *createPriorityQueue(compare cmpFunc) {
    PriorityQueue *obj = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    obj->capacity = MIN_QUEUE_SIZE;
    obj->arr = (Element *)malloc(sizeof(Element) * obj->capacity);
    obj->queueSize = 0;
    obj->lessFunc = cmpFunc;
    return obj;
}

void heapfiy(PriorityQueue *obj) {
    for (int i = obj->queueSize / 2 - 1; i >= 0; i--) {
        down(obj->arr, obj->queueSize, i, obj->lessFunc);
    }
}

void enQueue(PriorityQueue *obj, Element *e) {
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

Element *deQueue(PriorityQueue *obj) {
    swap(obj->arr, 0, obj->queueSize - 1);
    down(obj->arr, obj->queueSize - 1, 0, obj->lessFunc);
    Element *e = &obj->arr[obj->queueSize - 1];
    obj->queueSize--;
    return e;
}

bool isEmpty(const PriorityQueue *obj) { return obj->queueSize == 0; }

Element *front(const PriorityQueue *obj) {
    if (obj->queueSize == 0) {
        return NULL;
    } else {
        return &obj->arr[0];
    }
}

void clear(PriorityQueue *obj) { obj->queueSize = 0; }

int size(const PriorityQueue *obj) { return obj->queueSize; }

void freeQueue(PriorityQueue *obj) {
    free(obj->arr);
    free(obj);
}

const int inf = 0x3f3f3f3f;

int minTimeToReach(int **moveTime, int moveTimeSize, int *moveTimeColSize) {
    int n = moveTimeSize, m = moveTimeColSize[0];
    int d[n][m], v[n][m];
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    d[0][0] = 0;
    PriorityQueue *q = createPriorityQueue(greater);
    Element e = {0, 0, 0};
    enQueue(q, &e);

    while (!isEmpty(q)) {
        Element *p = front(q);
        Element s = {p->x, p->y, p->dist};
        deQueue(q);
        if (v[s.x][s.y]) {
            continue;
        }
        v[s.x][s.y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dirs[i][0];
            int ny = s.y + dirs[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            int dist = fmax(d[s.x][s.y], moveTime[nx][ny]) + 1;
            if (d[nx][ny] > dist) {
                d[nx][ny] = dist;
                e.x = nx;
                e.y = ny;
                e.dist = dist;
                enQueue(q, &e);
            }
        }
    }
    freeQueue(q);
    return d[n - 1][m - 1];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class State {
public:
    int x;
    int y;
    int dis;
    State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int inf = 0x3f3f3f3f;
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<int>> v(n, vector<int>(m, 0));

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0] = 0;

        auto cmp = [](const State& a, const State& b) { return a.dis > b.dis; };

        priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
        q.push(State(0, 0, 0));

        while (!q.empty()) {
            State s = q.top();
            q.pop();
            if (v[s.x][s.y]) continue;
            v[s.x][s.y] = 1;

            for (int i = 0; i < 4; i++) {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;
                if (d[nx][ny] > dist) {
                    d[nx][ny] = dist;
                    q.push(State(nx, ny, dist));
                }
            }
        }

        return d[n - 1][m - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const int INF = 0x3f3f3f3f;

    private class State : IComparable<State> {
        public int x;
        public int y;
        public int dis;

        public State(int x, int y, int dis) {
            this.x = x;
            this.y = y;
            this.dis = dis;
        }

        public int CompareTo(State other) {
            return this.dis.CompareTo(other.dis);
        }
    }

    public int MinTimeToReach(int[][] moveTime) {
        int n = moveTime.Length;
        int m = moveTime[0].Length;
        int[,] d = new int[n, m];
        bool[,] v = new bool[n, m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[i, j] = INF;
            }
        }

        int[][] dirs = new int[][] { new int[] { 1, 0 }, new int[] { -1, 0 },
                                     new int[] { 0, 1 }, new int[] { 0, -1 } };

        d[0, 0] = 0;
        var pq = new PriorityQueue<State, int>();
        pq.Enqueue(new State(0, 0, 0), 0);

        while (pq.Count > 0) {
            State s = pq.Dequeue();
            if (v[s.x, s.y]) {
                continue;
            }
            v[s.x, s.y] = true;
            foreach (var dir in dirs) {
                int nx = s.x + dir[0];
                int ny = s.y + dir[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                int dist = Math.Max(d[s.x, s.y], moveTime[nx][ny]) + 1;
                if (d[nx, ny] > dist) {
                    d[nx, ny] = dist;
                    pq.Enqueue(new State(nx, ny, dist), dist);
                }
            }
        }

        return d[n - 1, m - 1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minTimeToReach(moveTime [][]int) int {
	n, m := len(moveTime), len(moveTime[0])
	d := make([][]int, n)
	v := make([][]bool, n)
	for i := range d {
		d[i] = make([]int, m)
		v[i] = make([]bool, m)
		for j := range d[i] {
			d[i][j] = math.MaxInt32
		}
	}

	dirs := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	d[0][0] = 0
	q := &PriorityQueue{}
	heap.Push(q, State{0, 0, 0})

	for q.Len() > 0 {
		s := heap.Pop(q).(State)
		if v[s.x][s.y] {
			continue
		}
		v[s.x][s.y] = true
		for _, dir := range dirs {
			nx, ny := s.x+dir[0], s.y+dir[1]
			if nx < 0 || nx >= n || ny < 0 || ny >= m {
				continue
			}
			dist := max(d[s.x][s.y], moveTime[nx][ny]) + 1
			if d[nx][ny] > dist {
				d[nx][ny] = dist
				heap.Push(q, State{nx, ny, dist})
			}
		}
	}

	return d[n-1][m-1]
}

type State struct {
	x, y, dis int
}

type PriorityQueue []State

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].dis < pq[j].dis
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(State))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[:n-1]
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int INF = 0x3f3f3f3f;

    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length, m = moveTime[0].length;
        int[][] d = new int[n][m];
        boolean[][] v = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(d[i], INF);
        }

        int[][] dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        d[0][0] = 0;
        PriorityQueue<State> q = new PriorityQueue<>();
        q.offer(new State(0, 0, 0));

        while (!q.isEmpty()) {
            State s = q.poll();
            if (v[s.x][s.y]) {
                continue;
            }
            v[s.x][s.y] = true;
            for (int[] dir : dirs) {
                int nx = s.x + dir[0];
                int ny = s.y + dir[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                int dist = Math.max(d[s.x][s.y], moveTime[nx][ny]) + 1;
                if (d[nx][ny] > dist) {
                    d[nx][ny] = dist;
                    q.offer(new State(nx, ny, dist));
                }
            }
        }
        return d[n - 1][m - 1];
    }

    static class State implements Comparable<State> {

        int x, y, dis;

        State(int x, int y, int dis) {
            this.x = x;
            this.y = y;
            this.dis = dis;
        }

        @Override
        public int compareTo(State other) {
            return Integer.compare(this.dis, other.dis);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minTimeToReach = function (moveTime) {
    const n = moveTime.length,
        m = moveTime[0].length;
    const d = Array.from({ length: n }, () => Array(m).fill(Infinity));
    const v = Array.from({ length: n }, () => Array(m).fill(false));
    const dirs = [
        [1, 0],
        [-1, 0],
        [0, 1],
        [0, -1],
    ];
    const q = new PriorityQueue((a, b) => {
        return a.dist < b.dist ? -1 : 1;
    });

    d[0][0] = 0;
    q.enqueue({ x: 0, y: 0, dist: 0 });
    while (!q.isEmpty()) {
        const s = q.dequeue();
        if (v[s.x][s.y]) {
            continue;
        }
        v[s.x][s.y] = true;
        for (const [dx, dy] of dirs) {
            const nx = s.x + dx,
                ny = s.y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            const dist = Math.max(d[s.x][s.y], moveTime[nx][ny]) + 1;
            if (d[nx][ny] > dist) {
                d[nx][ny] = dist;
                q.enqueue({ x: nx, y: ny, dist: dist });
            }
        }
    }

    return d[n - 1][m - 1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class State:
    def __init__(self, x, y, dis):
        self.x = x
        self.y = y
        self.dis = dis

    def __lt__(self, other):
        return self.dis < other.dis


class Solution:
    def minTimeToReach(self, moveTime):
        n = len(moveTime)
        m = len(moveTime[0])
        inf = float("inf")
        d = [[inf] * m for _ in range(n)]
        v = [[0] * m for _ in range(n)]

        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        d[0][0] = 0
        q = []
        heapq.heappush(q, State(0, 0, 0))

        while q:
            s = heapq.heappop(q)
            if v[s.x][s.y]:
                continue
            v[s.x][s.y] = 1
            for dx, dy in dirs:
                nx, ny = s.x + dx, s.y + dy
                if not (0 <= nx < n and 0 <= ny < m):
                    continue
                dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1
                if d[nx][ny] > dist:
                    d[nx][ny] = dist
                    heapq.heappush(q, State(nx, ny, dist))

        return d[n - 1][m - 1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
interface State {
    x: number;
    y: number;
    dist: number;
}

function minTimeToReach(moveTime: number[][]): number {
    const n = moveTime.length;
    const m = moveTime[0].length;
    const d: number[][] = Array.from({ length: n }, () =>
        Array(m).fill(Infinity),
    );
    const v: boolean[][] = Array.from({ length: n }, () =>
        Array(m).fill(false),
    );
    const dirs: [number, number][] = [
        [1, 0],
        [-1, 0],
        [0, 1],
        [0, -1],
    ];
    const q = new PriorityQueue<State>((a, b) => a.dist - b.dist);

    d[0][0] = 0;
    q.enqueue({ x: 0, y: 0, dist: 0 });
    while (!q.isEmpty()) {
        const s = q.dequeue();
        if (v[s.x][s.y]) {
            continue;
        }
        v[s.x][s.y] = true;
        for (const [dx, dy] of dirs) {
            const nx = s.x + dx;
            const ny = s.y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            const dist = Math.max(d[s.x][s.y], moveTime[nx][ny]) + 1;
            if (d[nx][ny] > dist) {
                d[nx][ny] = dist;
                q.enqueue({ x: nx, y: ny, dist });
            }
        }
    }

    return d[n - 1][m - 1];
}
```

</details>
