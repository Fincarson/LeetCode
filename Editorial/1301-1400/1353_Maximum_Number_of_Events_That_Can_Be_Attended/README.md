# 1353. Maximum Number of Events That Can Be Attended

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)  
`Array` `Greedy` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1353 - Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)

## Problem

You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startDayi <= d <= endDayi. You can only attend one event at any time d.

Return the maximum number of events you can attend.

### Example 1

```text
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
```

### Example 2

```text
Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
```

## Constraints

- 1 <= events.length <= 105
- events[i].length == 2
- 1 <= startDayi <= endDayi <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Number of Events That Can Be Attended II](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Earnings From Taxi](https://leetcode.com/problems/maximum-earnings-from-taxi/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1353. Maximum Number of Events That Can Be Attended

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MIN_QUEUE_SIZE 64

typedef struct Element {
    int data;
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
    return e1->data > e2->data;
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

int cmp(const void *a, const void *b) {
    return (*(int **)a)[0] - (*(int **)b)[0];
};

int maxEvents(int **events, int eventsSize, int *eventsColSize) {
    int n = eventsSize;
    int maxDay = 0;
    for (int i = 0; i < eventsSize; i++) {
        maxDay = fmax(maxDay, events[i][1]);
    }

    PriorityQueue *pq = createPriorityQueue(greater);
    qsort(events, eventsSize, sizeof(events[0]), cmp);
    int ans = 0;
    for (int i = 1, j = 0; i <= maxDay; i++) {
        while (j < n && events[j][0] <= i) {
            Element e = {events[j][1]};
            enQueue(pq, &e);
            j++;
        }
        while (!isEmpty(pq) && front(pq)->data < i) {
            deQueue(pq);
        }
        if (!isEmpty(pq)) {
            deQueue(pq);
            ans++;
        }
    }

    freeQueue(pq);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxDay = 0;
        for (int i = 0; i < events.size(); i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<>> pq;
        sort(events.begin(), events.end());
        int ans = 0;
        for (int i = 0, j = 0; i <= maxDay; i++) {
            while (j < n && events[j][0] <= i) {
                pq.emplace(events[j][1]);
                j++;
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
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
public class Solution {
    public int MaxEvents(int[][] events) {
        int n = events.Length;
        int maxDay = 0;
        foreach (var e in events) {
            maxDay = Math.Max(maxDay, e[1]);
        }

        var pq = new PriorityQueue<int, int>();
        Array.Sort(events, (a, b) => a[0] - b[0]);
        int ans = 0;
        for (int i = 1, j = 0; i <= maxDay; i++) {
            while (j < n && events[j][0] <= i) {
                pq.Enqueue(events[j][1], events[j][1]);
                j++;
            }
            while (pq.Count > 0 && pq.Peek() < i) {
                pq.Dequeue();
            }
            if (pq.Count > 0) {
                pq.Dequeue();
                ans++;
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
func maxEvents(events [][]int) int {
	n := len(events)
	maxDay := 0
	for _, event := range events {
		if event[1] > maxDay {
			maxDay = event[1]
		}
	}
	sort.Slice(events, func(i, j int) bool {
		return events[i][0] < events[j][0]
	})
	pq := &IntHeap{}
	heap.Init(pq)
	ans := 0
	for i, j := 1, 0; i <= maxDay; i++ {
		for j < n && events[j][0] <= i {
			heap.Push(pq, events[j][1])
			j++
		}
		for pq.Len() > 0 && (*pq)[0] < i {
			heap.Pop(pq)
		}
		if pq.Len() > 0 {
			heap.Pop(pq)
			ans++
		}
	}
	return ans
}

type IntHeap []int

func (h IntHeap) Len() int {
	return len(h)
}

func (h IntHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxEvents(int[][] events) {
        int n = events.length;
        int maxDay = 0;
        for (int[] event : events) {
            maxDay = Math.max(maxDay, event[1]);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int ans = 0;
        for (int i = 1, j = 0; i <= maxDay; i++) {
            while (j < n && events[j][0] <= i) {
                pq.offer(events[j][1]);
                j++;
            }
            while (!pq.isEmpty() && pq.peek() < i) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
                pq.poll();
                ans++;
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
var maxEvents = function (events) {
    const n = events.length;
    let maxDay = 0;
    for (const e of events) {
        maxDay = Math.max(maxDay, e[1]);
    }
    events.sort((a, b) => a[0] - b[0]);
    const pq = new MinPriorityQueue();
    let ans = 0;
    for (let i = 1, j = 0; i <= maxDay; i++) {
        while (j < n && events[j][0] <= i) {
            pq.enqueue(events[j][1]);
            j++;
        }
        while (!pq.isEmpty() && pq.front() < i) {
            pq.dequeue();
        }
        if (!pq.isEmpty()) {
            pq.dequeue();
            ans++;
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        n = len(events)
        max_day = max(event[1] for event in events)
        events.sort()
        pq = []
        ans, j = 0, 0
        for i in range(1, max_day + 1):
            while j < n and events[j][0] <= i:
                heapq.heappush(pq, events[j][1])
                j += 1
            while pq and pq[0] < i:
                heapq.heappop(pq)
            if pq:
                heapq.heappop(pq)
                ans += 1

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxEvents(events: number[][]): number {
    const n = events.length;
    let maxDay = 0;
    for (const e of events) {
        maxDay = Math.max(maxDay, e[1]);
    }
    events.sort((a, b) => a[0] - b[0]);
    const pq = new MinPriorityQueue<number>();
    let ans = 0;
    for (let i = 1, j = 0; i <= maxDay; i++) {
        while (j < n && events[j][0] <= i) {
            pq.enqueue(events[j][1]);
            j++;
        }
        while (!pq.isEmpty() && pq.front() < i) {
            pq.dequeue();
        }
        if (!pq.isEmpty()) {
            pq.dequeue();
            ans++;
        }
    }
    return ans;
}
```

</details>
