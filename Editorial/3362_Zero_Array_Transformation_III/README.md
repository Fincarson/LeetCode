# 3362. Zero Array Transformation III

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/zero-array-transformation-iii/)  
`Array` `Two Pointers` `Greedy` `Sorting` `Heap (Priority Queue)` `Prefix Sum`

**Problem Link:** [LeetCode 3362 - Zero Array Transformation III](https://leetcode.com/problems/zero-array-transformation-iii/)

## Problem

You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

- Decrement the value at each index in the range [li, ri] in nums by at most 1.
- The amount by which the value is decremented can be chosen independently for each index.

A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 105
- 1 <= queries.length <= 105
- queries[i].length == 2
- 0 <= li <= ri < nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Zero Array Transformation IV](https://leetcode.com/problems/zero-array-transformation-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3362. Zero Array Transformation III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy + Priority Queue | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy + Priority Queue

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

static bool less(const void *a, const void *b) {
    Element *e1 = (Element *)a;
    Element *e2 = (Element *)b;
    return e1->data > e2->data;
}

static bool greater(const void *a, const void *b) {
    Element *e1 = (Element *)a;
    Element *e2 = (Element *)b;
    return e1->data < e2->data;
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
    int *ar = *(int **)a;
    int *br = *(int **)b;
    return ar[0] - br[0];
}

int maxRemoval(int *nums, int numsSize, int **queries, int queriesSize,
               int *queriesColSize) {
    qsort(queries, queriesSize, sizeof(int *), cmp);
    PriorityQueue *heap = createPriorityQueue(greater);
    int *deltaArray = (int *)calloc(numsSize + 1, sizeof(int));
    int operations = 0;

    for (int i = 0, j = 0; i < numsSize; i++) {
        operations += deltaArray[i];
        while (j < queriesSize && queries[j][0] == i) {
            Element e = {queries[j][1]};
            enQueue(heap, &e);
            j++;
        }
        while (operations < nums[i] && !isEmpty(heap) &&
               front(heap)->data >= i) {
            operations += 1;
            int end = front(heap)->data;
            deQueue(heap);
            deltaArray[end + 1] -= 1;
        }

        if (operations < nums[i]) {
            freeQueue(heap);
            free(deltaArray);
            return -1;
        }
    }

    int result = size(heap);
    freeQueue(heap);
    free(deltaArray);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        priority_queue<int> heap;
        vector<int> deltaArray(nums.size() + 1, 0);
        int operations = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            operations += deltaArray[i];
            while (j < queries.size() && queries[j][0] == i) {
                heap.push(queries[j][1]);
                ++j;
            }
            while (operations < nums[i] && !heap.empty() && heap.top() >= i) {
                operations += 1;
                deltaArray[heap.top() + 1] -= 1;
                heap.pop();
            }
            if (operations < nums[i]) {
                return -1;
            }
        }
        return heap.size();
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxRemoval(int[] nums, int[][] queries) {
        Array.Sort(queries, (a, b) => a[0] - b[0]);
        var heap = new PriorityQueue<int, int>(
            Comparer<int>.Create((a, b) => b.CompareTo(a)));
        int[] deltaArray = new int[nums.Length + 1];
        int operations = 0;

        for (int i = 0, j = 0; i < nums.Length; i++) {
            operations += deltaArray[i];
            while (j < queries.Length && queries[j][0] == i) {
                heap.Enqueue(queries[j][1], queries[j][1]);
                j++;
            }
            while (operations < nums[i] && heap.Count > 0 && heap.Peek() >= i) {
                operations += 1;
                deltaArray[heap.Dequeue() + 1] -= 1;
            }
            if (operations < nums[i]) {
                return -1;
            }
        }
        return heap.Count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxRemoval(nums []int, queries [][]int) int {
	sort.Slice(queries, func(i, j int) bool {
		return queries[i][0] < queries[j][0]
	})
	pq := &Heap{}
	heap.Init(pq)
	deltaArray := make([]int, len(nums)+1)
	operations := 0

	for i, j := 0, 0; i < len(nums); i++ {
		operations += deltaArray[i]
		for j < len(queries) && queries[j][0] == i {
			heap.Push(pq, queries[j][1])
			j++
		}
		for operations < nums[i] && pq.Len() > 0 && (*pq)[0] >= i {
			operations += 1
			deltaArray[heap.Pop(pq).(int)+1] -= 1
		}
		if operations < nums[i] {
			return -1
		}
	}
	return pq.Len()
}

type Heap []int

func (h Heap) Len() int {
	return len(h)
}

func (h Heap) Less(i, j int) bool {
	return h[i] > h[j]
}

func (h Heap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *Heap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *Heap) Pop() interface{} {
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

    public int maxRemoval(int[] nums, int[][] queries) {
        Arrays.sort(queries, (a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> heap = new PriorityQueue<>(
            Collections.reverseOrder()
        );
        int[] deltaArray = new int[nums.length + 1];
        int operations = 0;

        for (int i = 0, j = 0; i < nums.length; i++) {
            operations += deltaArray[i];
            while (j < queries.length && queries[j][0] == i) {
                heap.offer(queries[j][1]);
                j++;
            }
            while (
                operations < nums[i] && !heap.isEmpty() && heap.peek() >= i
            ) {
                operations += 1;
                deltaArray[heap.poll() + 1] -= 1;
            }
            if (operations < nums[i]) {
                return -1;
            }
        }
        return heap.size();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxRemoval = function (nums, queries) {
    queries.sort((a, b) => a[0] - b[0]);
    const heap = new MaxPriorityQueue();
    const deltaArray = new Array(nums.length + 1).fill(0);
    let operations = 0;

    for (let i = 0, j = 0; i < nums.length; i++) {
        operations += deltaArray[i];
        while (j < queries.length && queries[j][0] === i) {
            heap.push(queries[j][1]);
            j++;
        }
        while (operations < nums[i] && !heap.isEmpty() && heap.front() >= i) {
            operations += 1;
            deltaArray[heap.pop() + 1] -= 1;
        }
        if (operations < nums[i]) {
            return -1;
        }
    }
    return heap.size();
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        queries.sort(key=lambda x: x[0])
        heap = []
        deltaArray = [0] * (len(nums) + 1)
        operations = 0
        j = 0
        for i, num in enumerate(nums):
            operations += deltaArray[i]
            while j < len(queries) and queries[j][0] == i:
                heappush(heap, -queries[j][1])
                j += 1
            while operations < num and heap and -heap[0] >= i:
                operations += 1
                deltaArray[-heappop(heap) + 1] -= 1
            if operations < num:
                return -1
        return len(heap)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxRemoval(nums: number[], queries: number[][]): number {
    queries.sort((a, b) => a[0] - b[0]);
    const heap = new MaxPriorityQueue<number>();
    const deltaArray: number[] = new Array(nums.length + 1).fill(0);
    let operations = 0;

    for (let i = 0, j = 0; i < nums.length; i++) {
        operations += deltaArray[i];
        while (j < queries.length && queries[j][0] === i) {
            heap.push(queries[j][1]);
            j++;
        }
        while (operations < nums[i] && !heap.isEmpty() && heap.front() >= i) {
            operations += 1;
            deltaArray[heap.pop() + 1] -= 1;
        }
        if (operations < nums[i]) {
            return -1;
        }
    }
    return heap.size();
}
```

</details>
