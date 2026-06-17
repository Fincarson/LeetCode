# 2163. Minimum Difference in Sums After Removal of Elements

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/)  
`Array` `Dynamic Programming` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 2163 - Minimum Difference in Sums After Removal of Elements](https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/)

## Problem

You are given a 0-indexed integer array nums consisting of 3 * n elements.

You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:

- The first n elements belonging to the first part and their sum is sumfirst.
- The next n elements belonging to the second part and their sum is sumsecond.

The difference in sums of the two parts is denoted as sumfirst - sumsecond.

- For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
- Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.

Return the minimum difference possible between the sums of the two parts after the removal of n elements.

### Example 1

```text
Input: nums = [3,1,2]
Output: -1
Explanation: Here, nums has 3 elements, so n = 1.
Thus we have to remove 1 element from nums and divide the array into two equal parts.
- If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
- If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
- If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
The minimum difference between sums of the two parts is min(-1,1,2) = -1.
```

### Example 2

```text
Input: nums = [7,9,5,8,1,3]
Output: 1
Explanation: Here n = 2. So we must remove 2 elements and divide the remaining array into two parts containing two elements each.
If we remove nums[2] = 5 and nums[3] = 8, the resultant array will be [7,9,1,3]. The difference in sums will be (7+9) - (1+3) = 12.
To obtain the minimum difference, we should remove nums[1] = 9 and nums[4] = 1. The resultant array becomes [7,5,8,3]. The difference in sums of the two parts is (7+5) - (8+3) = 1.
It can be shown that it is not possible to obtain a difference smaller than 1.
```

## Constraints

- nums.length == 3 * n
- 1 <= n <= 105
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Subsequence of Length K With the Largest Sum](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find Minimum Cost to Remove Array Elements](https://leetcode.com/problems/find-minimum-cost-to-remove-array-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2163. Minimum Difference in Sums After Removal of Elements

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Priority Queue | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Priority Queue

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MIN_QUEUE_SIZE 64

typedef struct Element {
    int data[1];
} Element;

typedef bool (*compare)(const void *, const void *);

typedef struct PriorityQueue {
    Element *arr;
    int capacity;
    int queueSize;
    compare lessFunc;
} PriorityQueue;

Element *createElement(int x, int y) {
    Element *obj = (Element *)malloc(sizeof(Element));
    obj->data[0] = x;
    obj->data[1] = y;
    return obj;
}

static bool less(const void *a, const void *b) {
    Element *e1 = (Element *)a;
    Element *e2 = (Element *)b;
    return e1->data[0] > e2->data[0];
}

static bool greater(const void *a, const void *b) {
    Element *e1 = (Element *)a;
    Element *e2 = (Element *)b;
    return e1->data[0] < e2->data[0];
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

long long minimumDifference(int *nums, int numsSize) {
    int n3 = numsSize, n = n3 / 3;
    long long part1[n + 1];
    memset(part1, 0, sizeof(part1));
    long long sum = 0;
    // max heap
    PriorityQueue *ql = createPriorityQueue(greater);
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        Element e = {nums[i]};
        enQueue(ql, &e);
    }
    part1[0] = sum;
    for (int i = n; i < n * 2; ++i) {
        sum += nums[i];
        Element e = {nums[i]};
        enQueue(ql, &e);
        sum -= front(ql)->data[0];
        deQueue(ql);
        part1[i - (n - 1)] = sum;
    }

    long long part2 = 0;
    // min heap
    PriorityQueue *qr = createPriorityQueue(less);
    for (int i = n * 3 - 1; i >= n * 2; --i) {
        part2 += nums[i];
        Element e = {nums[i]};
        enQueue(qr, &e);
    }
    long long ans = part1[n] - part2;
    for (int i = n * 2 - 1; i >= n; --i) {
        part2 += nums[i];
        Element e = {nums[i]};
        enQueue(qr, &e);
        part2 -= front(qr)->data[0];
        deQueue(qr);
        ans = fmin(ans, part1[i - n] - part2);
    }
    freeQueue(ql);
    freeQueue(qr);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n3 = nums.size(), n = n3 / 3;
        vector<long long> part1(n + 1);
        long long sum = 0;
        // max heap
        priority_queue<int> ql;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
        }
        part1[0] = sum;
        for (int i = n; i < n * 2; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
            sum -= ql.top();
            ql.pop();
            part1[i - (n - 1)] = sum;
        }

        long long part2 = 0;
        // min heap
        priority_queue<int, vector<int>, greater<int>> qr;
        for (int i = n * 3 - 1; i >= n * 2; --i) {
            part2 += nums[i];
            qr.push(nums[i]);
        }
        long long ans = part1[n] - part2;
        for (int i = n * 2 - 1; i >= n; --i) {
            part2 += nums[i];
            qr.push(nums[i]);
            part2 -= qr.top();
            qr.pop();
            ans = min(ans, part1[i - n] - part2);
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
    public long MinimumDifference(int[] nums) {
        int n3 = nums.Length, n = n3 / 3;
        long[] part1 = new long[n + 1];
        long sum = 0;
        // max heap (simulate with opposite numbers)
        var ql = new PriorityQueue<int, int>(
            Comparer<int>.Create((a, b) => b.CompareTo(a)));
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ql.Enqueue(nums[i], nums[i]);
        }
        part1[0] = sum;
        for (int i = n; i < n * 2; ++i) {
            sum += nums[i];
            ql.Enqueue(nums[i], nums[i]);
            sum -= ql.Dequeue();
            part1[i - (n - 1)] = sum;
        }

        long part2 = 0;
        // min heap
        var qr = new PriorityQueue<int, int>();
        for (int i = n * 3 - 1; i >= n * 2; --i) {
            part2 += nums[i];
            qr.Enqueue(nums[i], nums[i]);
        }
        long ans = part1[n] - part2;
        for (int i = n * 2 - 1; i >= n; --i) {
            part2 += nums[i];
            qr.Enqueue(nums[i], nums[i]);
            part2 -= qr.Dequeue();
            ans = Math.Min(ans, part1[i - n] - part2);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumDifference(nums []int) int64 {
	n3 := len(nums)
	n := n3 / 3
	part1 := make([]int64, n+1)
	var sum int64 = 0
	ql := &MaxHeap{}
	heap.Init(ql)
	for i := 0; i < n; i++ {
		sum += int64(nums[i])
		heap.Push(ql, nums[i])
	}
	part1[0] = sum
	for i := n; i < n*2; i++ {
		sum += int64(nums[i])
		heap.Push(ql, nums[i])
		sum -= int64(heap.Pop(ql).(int))
		part1[i-(n-1)] = sum
	}

	var part2 int64 = 0
	qr := &IntMinHeap{}
	heap.Init(qr)
	for i := n*3 - 1; i >= n*2; i-- {
		part2 += int64(nums[i])
		heap.Push(qr, nums[i])
	}
	ans := part1[n] - part2
	for i := n*2 - 1; i >= n; i-- {
		part2 += int64(nums[i])
		heap.Push(qr, nums[i])
		part2 -= int64(heap.Pop(qr).(int))
		if part1[i-n]-part2 < ans {
			ans = part1[i-n] - part2
		}
	}
	return ans
}

type MaxHeap []int

func (h MaxHeap) Len() int            { return len(h) }
func (h MaxHeap) Less(i, j int) bool  { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *MaxHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type IntMinHeap []int

func (h IntMinHeap) Len() int            { return len(h) }
func (h IntMinHeap) Less(i, j int) bool  { return h[i] < h[j] }
func (h IntMinHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *IntMinHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *IntMinHeap) Pop() interface{} {
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
public class Solution {

    public long minimumDifference(int[] nums) {
        int n3 = nums.length;
        int n = n3 / 3;
        long[] part1 = new long[n + 1];
        long sum = 0;
        // max heap (simulate with opposite numbers)
        PriorityQueue<Integer> ql = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ql.add(nums[i]);
        }
        part1[0] = sum;
        for (int i = n; i < n * 2; ++i) {
            sum += nums[i];
            ql.add(nums[i]);
            sum -= ql.poll();
            part1[i - (n - 1)] = sum;
        }

        long part2 = 0;
        // min heap
        PriorityQueue<Integer> qr = new PriorityQueue<>();
        for (int i = n * 3 - 1; i >= n * 2; --i) {
            part2 += nums[i];
            qr.add(nums[i]);
        }
        long ans = part1[n] - part2;
        for (int i = n * 2 - 1; i >= n; --i) {
            part2 += nums[i];
            qr.add(nums[i]);
            part2 -= qr.poll();
            ans = Math.min(ans, part1[i - n] - part2);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumDifference = function (nums) {
    const n3 = nums.length,
        n = Math.floor(n3 / 3);
    const part1 = new Array(n + 1).fill(0);
    let sum = 0;
    // max heap (simulate with opposite numbers)
    const ql = new MaxPriorityQueue();
    for (let i = 0; i < n; ++i) {
        sum += nums[i];
        ql.enqueue(nums[i]);
    }

    part1[0] = sum;
    for (let i = n; i < n * 2; ++i) {
        sum += nums[i];
        ql.enqueue(nums[i]);
        sum -= ql.dequeue();
        part1[i - (n - 1)] = sum;
    }
    let part2 = 0;
    // min heap
    const qr = new MinPriorityQueue();
    for (let i = n * 3 - 1; i >= n * 2; --i) {
        part2 += nums[i];
        qr.enqueue(nums[i]);
    }

    let ans = part1[n] - part2;
    for (let i = n * 2 - 1; i >= n; --i) {
        part2 += nums[i];
        qr.enqueue(nums[i]);
        part2 -= qr.dequeue();
        ans = Math.min(ans, part1[i - n] - part2);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n3, n = len(nums), len(nums) // 3

        part1 = [0] * (n + 1)
        # max heap
        total = sum(nums[:n])
        ql = [-x for x in nums[:n]]
        heapq.heapify(ql)
        part1[0] = total

        for i in range(n, n * 2):
            total += nums[i]
            heapq.heappush(ql, -nums[i])
            total -= -heapq.heappop(ql)
            part1[i - (n - 1)] = total

        # min heap
        part2 = sum(nums[n * 2 :])
        qr = nums[n * 2 :]
        heapq.heapify(qr)
        ans = part1[n] - part2

        for i in range(n * 2 - 1, n - 1, -1):
            part2 += nums[i]
            heapq.heappush(qr, nums[i])
            part2 -= heapq.heappop(qr)
            ans = min(ans, part1[i - n] - part2)

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumDifference(nums: number[]): number {
    const n3 = nums.length,
        n = Math.floor(n3 / 3);
    const part1: number[] = new Array(n + 1).fill(0);
    let sum = 0;
    // max heap (simulate with opposite numbers)
    const ql = new MaxPriorityQueue<number>();
    for (let i = 0; i < n; ++i) {
        sum += nums[i];
        ql.enqueue(nums[i]);
    }
    part1[0] = sum;
    for (let i = n; i < n * 2; ++i) {
        sum += nums[i];
        ql.enqueue(nums[i]);
        sum -= ql.dequeue();
        part1[i - (n - 1)] = sum;
    }

    let part2 = 0;
    // min heap
    const qr = new MinPriorityQueue<number>();
    for (let i = n * 3 - 1; i >= n * 2; --i) {
        part2 += nums[i];
        qr.enqueue(nums[i]);
    }
    let ans = part1[n] - part2;
    for (let i = n * 2 - 1; i >= n; --i) {
        part2 += nums[i];
        qr.enqueue(nums[i]);
        part2 -= qr.dequeue();
        ans = Math.min(ans, part1[i - n] - part2);
    }
    return ans;
}
```

</details>
