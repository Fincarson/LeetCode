# 3691. Maximum Total Subarray Value II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximum-total-subarray-value-ii/)  
`Array` `Greedy` `Segment Tree` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 3691 - Maximum Total Subarray Value II](https://leetcode.com/problems/maximum-total-subarray-value-ii/)

## Problem

You are given an integer array nums of length n and an integer k.

You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.

The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

The total value is the sum of the values of all chosen subarrays.

Return the maximum possible total value you can achieve.

### Example 1

### Example 2

## Constraints

- 1 <= n == nums.length <= 5 * 10​​​​​​​4
- 0 <= nums[i] <= 109
- 1 <= k <= min(105, n * (n + 1) / 2)

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3691. Maximum Total Subarray Value II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sparse Table + Max Heap | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Segment Tree + Max Heap | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sparse Table + Max Heap

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int val, l, r;
} Tuple;

typedef struct {
    Tuple* data;
    int size;
} MaxHeap;

void heapPush(MaxHeap* h, Tuple t) {
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) >> 1;
        if (h->data[p].val >= t.val) {
            break;
        }
        h->data[i] = h->data[p];
        i = p;
    }
    h->data[i] = t;
}

Tuple heapPop(MaxHeap* h) {
    Tuple top = h->data[0];
    Tuple last = h->data[--h->size];
    if (h->size > 0) {
        h->data[0] = last;
        int i = 0;
        while (1) {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < h->size && h->data[l].val > h->data[largest].val) {
                largest = l;
            }
            if (r < h->size && h->data[r].val > h->data[largest].val) {
                largest = r;
            }
            if (largest == i) {
                break;
            }
            Tuple tmp = h->data[i];
            h->data[i] = h->data[largest];
            h->data[largest] = tmp;
            i = largest;
        }
    }
    return top;
}

long long maxTotalValue(int* nums, int numsSize, int k) {
    int n = numsSize;
    int logn = 32 - __builtin_clz(n);
    int (*stMax)[logn] = malloc(n * logn * sizeof(int));
    int (*stMin)[logn] = malloc(n * logn * sizeof(int));
    for (int i = 0; i < n; i++) {
        stMax[i][0] = stMin[i][0] = nums[i];
    }
    for (int j = 1; j < logn; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            stMax[i][j] =
                (int)fmax(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
            stMin[i][j] =
                (int)fmin(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
        }
    }
    MaxHeap heap;
    heap.data = malloc(n * sizeof(Tuple));
    heap.size = 0;
    for (int l = 0; l < n; l++) {
        int j = 31 - __builtin_clz(n - 1 - l + 1);
        int mx = (int)fmax(stMax[l][j], stMax[n - 1 - (1 << j) + 1][j]);
        int mn = (int)fmin(stMin[l][j], stMin[n - 1 - (1 << j) + 1][j]);
        heapPush(&heap, (Tuple){mx - mn, l, n - 1});
    }
    long long ans = 0;
    while (k--) {
        Tuple t = heapPop(&heap);
        ans += t.val;
        if (t.r > t.l) {
            int j = 31 - __builtin_clz(t.r - 1 - t.l + 1);
            int mx = (int)fmax(stMax[t.l][j], stMax[t.r - 1 - (1 << j) + 1][j]);
            int mn = (int)fmin(stMin[t.l][j], stMin[t.r - 1 - (1 << j) + 1][j]);
            heapPush(&heap, (Tuple){mx - mn, t.l, t.r - 1});
        }
    }
    free(heap.data);
    free(stMax);
    free(stMin);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int logn = 32 - __builtin_clz(n);
        vector<vector<int>> stMax(n, vector<int>(logn));
        vector<vector<int>> stMin(n, vector<int>(logn));
        for (int i = 0; i < n; i++) {
            stMax[i][0] = stMin[i][0] = nums[i];
        }
        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[i][j] =
                    max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] =
                    min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }
        auto queryMax = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
        };
        auto queryMin = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
        };
        priority_queue<tuple<int, int, int>> pq;
        for (int l = 0; l < n; l++) {
            pq.emplace(queryMax(l, n - 1) - queryMin(l, n - 1), l, n - 1);
        }
        long long ans = 0;
        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if (r > l) {
                pq.emplace(queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1);
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
    public long MaxTotalValue(int[] nums, int k) {
        int n = nums.Length;
        int logn = 32 - BitOperations.LeadingZeroCount((uint)n);
        int[][] stMax = new int [n][];
        int[][] stMin = new int [n][];
        for (int i = 0; i < n; i++) {
            stMax[i] = new int[logn];
            stMin[i] = new int[logn];
            stMax[i][0] = stMin[i][0] = nums[i];
        }
        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[i][j] =
                    Math.Max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] =
                    Math.Min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }
        var pq = new PriorityQueue<(int l, int r), int>();
        for (int l = 0; l < n; l++) {
            int j = 31 - BitOperations.LeadingZeroCount((uint)(n - 1 - l + 1));
            int mx = Math.Max(stMax[l][j], stMax[n - 1 - (1 << j) + 1][j]);
            int mn = Math.Min(stMin[l][j], stMin[n - 1 - (1 << j) + 1][j]);
            pq.Enqueue((l, n - 1), -(mx - mn));
        }
        long ans = 0;
        while (k-- > 0) {
            pq.TryDequeue(out var top, out int negVal);
            ans -= negVal;
            int l = top.l, r = top.r;
            if (r > l) {
                int j =
                    31 - BitOperations.LeadingZeroCount((uint)(r - 1 - l + 1));
                int mx = Math.Max(stMax[l][j], stMax[r - 1 - (1 << j) + 1][j]);
                int mn = Math.Min(stMin[l][j], stMin[r - 1 - (1 << j) + 1][j]);
                pq.Enqueue((l, r - 1), -(mx - mn));
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
func maxTotalValue(nums []int, k int) int64 {
    n := len(nums)
    logn := bits.Len(uint(n))
    stMax := make([][]int, n)
    stMin := make([][]int, n)
    for i := range stMax {
        stMax[i] = make([]int, logn)
        stMin[i] = make([]int, logn)
        stMax[i][0] = nums[i]
        stMin[i][0] = nums[i]
    }
    for j := 1; j < logn; j++ {
        for i := 0; i+(1<<j) <= n; i++ {
            stMax[i][j] = max(stMax[i][j-1], stMax[i+(1<<(j-1))][j-1])
            stMin[i][j] = min(stMin[i][j-1], stMin[i+(1<<(j-1))][j-1])
        }
    }
    queryMax := func(l, r int) int {
        j := bits.Len(uint(r-l+1)) - 1
        return max(stMax[l][j], stMax[r-(1<<j)+1][j])
    }
    queryMin := func(l, r int) int {
        j := bits.Len(uint(r-l+1)) - 1
        return min(stMin[l][j], stMin[r-(1<<j)+1][j])
    }
    h := &hp{}
    for l := 0; l < n; l++ {
        heap.Push(h, tuple{queryMax(l, n-1) - queryMin(l, n-1), l, n - 1})
    }
    var ans int64 = 0
    for ; k > 0; k-- {
        t := heap.Pop(h).(tuple)
        ans += int64(t.val)
        if t.r > t.l {
            heap.Push(h, tuple{queryMax(t.l, t.r-1) - queryMin(t.l, t.r-1), t.l, t.r - 1})
        }
    }
    return ans
}

type tuple struct{ val, l, r int }
type hp []tuple
func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].val > h[j].val }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maxTotalValue(int[] nums, int k) {
        int n = nums.length;
        int logn = 32 - Integer.numberOfLeadingZeros(n);
        int[][] stMax = new int[n][logn];
        int[][] stMin = new int[n][logn];
        for (int i = 0; i < n; i++) {
            stMax[i][0] = stMin[i][0] = nums[i];
        }
        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[i][j] = Math.max(
                    stMax[i][j - 1],
                    stMax[i + (1 << (j - 1))][j - 1]
                );
                stMin[i][j] = Math.min(
                    stMin[i][j - 1],
                    stMin[i + (1 << (j - 1))][j - 1]
                );
            }
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int l = 0; l < n; l++) {
            int j = 31 - Integer.numberOfLeadingZeros(n - 1 - l + 1);
            int mx = Math.max(stMax[l][j], stMax[n - 1 - (1 << j) + 1][j]);
            int mn = Math.min(stMin[l][j], stMin[n - 1 - (1 << j) + 1][j]);
            pq.offer(new int[] { mx - mn, l, n - 1 });
        }
        long ans = 0;
        while (k-- > 0) {
            int[] top = pq.poll();
            ans += top[0];
            int l = top[1];
            int r = top[2];
            if (r > l) {
                int j = 31 - Integer.numberOfLeadingZeros(r - 1 - l + 1);
                int mx = Math.max(stMax[l][j], stMax[r - 1 - (1 << j) + 1][j]);
                int mn = Math.min(stMin[l][j], stMin[r - 1 - (1 << j) + 1][j]);
                pq.offer(new int[] { mx - mn, l, r - 1 });
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
var maxTotalValue = function (nums, k) {
    const n = nums.length;
    const logn = 32 - Math.clz32(n);
    const stMax = Array.from({ length: n }, () => Array(logn).fill(0));
    const stMin = Array.from({ length: n }, () => Array(logn).fill(0));
    for (let i = 0; i < n; i++) {
        stMax[i][0] = stMin[i][0] = nums[i];
    }
    for (let j = 1; j < logn; j++) {
        for (let i = 0; i + (1 << j) <= n; i++) {
            stMax[i][j] = Math.max(
                stMax[i][j - 1],
                stMax[i + (1 << (j - 1))][j - 1],
            );
            stMin[i][j] = Math.min(
                stMin[i][j - 1],
                stMin[i + (1 << (j - 1))][j - 1],
            );
        }
    }
    const queryMax = (l, r) => {
        const j = 31 - Math.clz32(r - l + 1);
        return Math.max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
    };
    const queryMin = (l, r) => {
        const j = 31 - Math.clz32(r - l + 1);
        return Math.min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
    };

    const heap = new Heap((a, b) => b[0] - a[0]);
    for (let l = 0; l < n; l++) {
        heap.push([queryMax(l, n - 1) - queryMin(l, n - 1), l, n - 1]);
    }
    let ans = 0;
    while (k--) {
        const [val, l, r] = heap.pop();
        ans += val;
        if (r > l) {
            heap.push([queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1]);
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
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        n = len(nums)
        logn = n.bit_length()
        stMax = [[0] * logn for _ in range(n)]
        stMin = [[0] * logn for _ in range(n)]
        for i in range(n):
            stMax[i][0] = stMin[i][0] = nums[i]
        for j in range(1, logn):
            step = 1 << (j - 1)
            for i in range(n - (1 << j) + 1):
                stMax[i][j] = max(stMax[i][j - 1], stMax[i + step][j - 1])
                stMin[i][j] = min(stMin[i][j - 1], stMin[i + step][j - 1])

        def queryMax(l: int, r: int) -> int:
            j = (r - l + 1).bit_length() - 1
            return max(stMax[l][j], stMax[r - (1 << j) + 1][j])

        def queryMin(l: int, r: int) -> int:
            j = (r - l + 1).bit_length() - 1
            return min(stMin[l][j], stMin[r - (1 << j) + 1][j])

        pq = [
            (-(queryMax(l, n - 1) - queryMin(l, n - 1)), l, n - 1)
            for l in range(n)
        ]
        heapq.heapify(pq)
        ans = 0
        while k:
            negVal, l, r = heapq.heappop(pq)
            ans -= negVal
            k -= 1
            if r > l:
                heapq.heappush(
                    pq, (-(queryMax(l, r - 1) - queryMin(l, r - 1)), l, r - 1)
                )
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxTotalValue(nums: number[], k: number): number {
    const n = nums.length;
    const logn = 32 - Math.clz32(n);
    const stMax: number[][] = Array.from({ length: n }, () =>
        Array(logn).fill(0),
    );
    const stMin: number[][] = Array.from({ length: n }, () =>
        Array(logn).fill(0),
    );
    for (let i = 0; i < n; i++) {
        stMax[i][0] = stMin[i][0] = nums[i];
    }
    for (let j = 1; j < logn; j++) {
        for (let i = 0; i + (1 << j) <= n; i++) {
            stMax[i][j] = Math.max(
                stMax[i][j - 1],
                stMax[i + (1 << (j - 1))][j - 1],
            );
            stMin[i][j] = Math.min(
                stMin[i][j - 1],
                stMin[i + (1 << (j - 1))][j - 1],
            );
        }
    }
    const queryMax = (l: number, r: number): number => {
        const j = 31 - Math.clz32(r - l + 1);
        return Math.max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
    };
    const queryMin = (l: number, r: number): number => {
        const j = 31 - Math.clz32(r - l + 1);
        return Math.min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
    };

    const heap = new Heap(
        (a: [number, number, number], b: [number, number, number]) =>
            b[0] - a[0],
    );
    for (let l = 0; l < n; l++) {
        heap.push([queryMax(l, n - 1) - queryMin(l, n - 1), l, n - 1]);
    }
    let ans = 0;
    while (k--) {
        const [val, l, r] = heap.pop()!;
        ans += val;
        if (r > l) {
            heap.push([queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1]);
        }
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Segment Tree + Max Heap

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* maxv;
    int* minv;
    int n;
} SegTree;

void segBuild(SegTree* seg, int node, int l, int r, int* nums) {
    if (l == r) {
        seg->maxv[node] = seg->minv[node] = nums[l];
        return;
    }
    int m = (l + r) / 2;
    segBuild(seg, node * 2, l, m, nums);
    segBuild(seg, node * 2 + 1, m + 1, r, nums);
    seg->maxv[node] = (int)fmax(seg->maxv[node * 2], seg->maxv[node * 2 + 1]);
    seg->minv[node] = (int)fmin(seg->minv[node * 2], seg->minv[node * 2 + 1]);
}

SegTree* segTreeCreate(int* nums, int n) {
    SegTree* seg = malloc(sizeof(SegTree));
    seg->n = n;
    seg->maxv = calloc(n * 4, sizeof(int));
    seg->minv = calloc(n * 4, sizeof(int));
    segBuild(seg, 1, 0, n - 1, nums);
    return seg;
}

int segQueryMax(SegTree* seg, int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg->maxv[node];
    }
    int m = (l + r) / 2, res = INT_MIN;
    if (ql <= m) {
        res = (int)fmax(res, segQueryMax(seg, node * 2, l, m, ql, qr));
    }
    if (qr > m) {
        res = (int)fmax(res, segQueryMax(seg, node * 2 + 1, m + 1, r, ql, qr));
    }
    return res;
}

int segQueryMin(SegTree* seg, int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg->minv[node];
    }
    int m = (l + r) / 2, res = INT_MAX;
    if (ql <= m) {
        res = (int)fmin(res, segQueryMin(seg, node * 2, l, m, ql, qr));
    }
    if (qr > m) {
        res = (int)fmin(res, segQueryMin(seg, node * 2 + 1, m + 1, r, ql, qr));
    }
    return res;
}

void segTreeFree(SegTree* seg) {
    free(seg->maxv);
    free(seg->minv);
    free(seg);
}

typedef struct {
    int val, l, r;
} Tuple;

typedef struct {
    Tuple* data;
    int size;
} MaxHeap;

void heapPush(MaxHeap* h, Tuple t) {
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) >> 1;
        if (h->data[p].val >= t.val) {
            break;
        }
        h->data[i] = h->data[p];
        i = p;
    }
    h->data[i] = t;
}

Tuple heapPop(MaxHeap* h) {
    Tuple top = h->data[0];
    Tuple last = h->data[--h->size];
    if (h->size > 0) {
        h->data[0] = last;
        int i = 0;
        while (1) {
            int largest = i;
            int lc = 2 * i + 1, rc = 2 * i + 2;
            if (lc < h->size && h->data[lc].val > h->data[largest].val) {
                largest = lc;
            }
            if (rc < h->size && h->data[rc].val > h->data[largest].val) {
                largest = rc;
            }
            if (largest == i) {
                break;
            }
            Tuple tmp = h->data[i];
            h->data[i] = h->data[largest];
            h->data[largest] = tmp;
            i = largest;
        }
    }
    return top;
}

long long maxTotalValue(int* nums, int numsSize, int k) {
    int n = numsSize;
    SegTree* seg = segTreeCreate(nums, n);
    MaxHeap heap;
    heap.data = malloc(n * sizeof(Tuple));
    heap.size = 0;
    for (int l = 0; l < n; l++) {
        int mx = segQueryMax(seg, 1, 0, n - 1, l, n - 1);
        int mn = segQueryMin(seg, 1, 0, n - 1, l, n - 1);
        heapPush(&heap, (Tuple){mx - mn, l, n - 1});
    }
    long long ans = 0;
    while (k--) {
        Tuple t = heapPop(&heap);
        ans += t.val;
        if (t.r > t.l) {
            int mx = segQueryMax(seg, 1, 0, n - 1, t.l, t.r - 1);
            int mn = segQueryMin(seg, 1, 0, n - 1, t.l, t.r - 1);
            heapPush(&heap, (Tuple){mx - mn, t.l, t.r - 1});
        }
    }
    free(heap.data);
    segTreeFree(seg);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class SegTree {
    vector<int> maxv, minv;
    int n;

public:
    SegTree(vector<int>& nums) {
        n = nums.size();
        maxv.resize(n * 4);
        minv.resize(n * 4);
        build(1, 0, n - 1, nums);
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            maxv[node] = minv[node] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        build(node * 2, l, m, nums);
        build(node * 2 + 1, m + 1, r, nums);
        maxv[node] = max(maxv[node * 2], maxv[node * 2 + 1]);
        minv[node] = min(minv[node * 2], minv[node * 2 + 1]);
    }

    int queryMax(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return maxv[node];
        }
        int m = (l + r) / 2, res = INT_MIN;
        if (ql <= m) {
            res = max(res, queryMax(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = max(res, queryMax(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }

    int queryMin(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return minv[node];
        }
        int m = (l + r) / 2, res = INT_MAX;
        if (ql <= m) {
            res = min(res, queryMin(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = min(res, queryMin(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegTree seg(nums);
        priority_queue<tuple<int, int, int>> pq;
        for (int l = 0; l < n; l++) {
            pq.emplace(seg.queryMax(1, 0, n - 1, l, n - 1) -
                           seg.queryMin(1, 0, n - 1, l, n - 1),
                       l, n - 1);
        }
        long long ans = 0;
        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if (r > l) {
                pq.emplace(seg.queryMax(1, 0, n - 1, l, r - 1) -
                               seg.queryMin(1, 0, n - 1, l, r - 1),
                           l, r - 1);
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
public class SegTree {
    int[] maxv, minv;
    int n;

    public SegTree(int[] nums) {
        n = nums.Length;
        maxv = new int[n * 4];
        minv = new int[n * 4];
        Build(1, 0, n - 1, nums);
    }

    void Build(int node, int l, int r, int[] nums) {
        if (l == r) {
            maxv[node] = minv[node] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        Build(node * 2, l, m, nums);
        Build(node * 2 + 1, m + 1, r, nums);
        maxv[node] = Math.Max(maxv[node * 2], maxv[node * 2 + 1]);
        minv[node] = Math.Min(minv[node * 2], minv[node * 2 + 1]);
    }

    public int QueryMax(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return maxv[node];
        }
        int m = (l + r) / 2, res = int.MinValue;
        if (ql <= m) {
            res = Math.Max(res, QueryMax(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = Math.Max(res, QueryMax(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }

    public int QueryMin(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return minv[node];
        }
        int m = (l + r) / 2, res = int.MaxValue;
        if (ql <= m) {
            res = Math.Min(res, QueryMin(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = Math.Min(res, QueryMin(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }
}

public class Solution {
    public long MaxTotalValue(int[] nums, int k) {
        int n = nums.Length;
        var seg = new SegTree(nums);
        var pq = new PriorityQueue<(int l, int r), int>();
        for (int l = 0; l < n; l++) {
            int val = seg.QueryMax(1, 0, n - 1, l, n - 1) -
                      seg.QueryMin(1, 0, n - 1, l, n - 1);
            pq.Enqueue((l, n - 1), -val);
        }
        long ans = 0;
        while (k-- > 0) {
            pq.TryDequeue(out var top, out int negVal);
            ans -= negVal;
            int l = top.l, r = top.r;
            if (r > l) {
                int val = seg.QueryMax(1, 0, n - 1, l, r - 1) -
                          seg.QueryMin(1, 0, n - 1, l, r - 1);
                pq.Enqueue((l, r - 1), -val);
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
type segTree struct {
    maxv, minv []int
    n          int
}

func newSegTree(nums []int) *segTree {
    n := len(nums)
    s := &segTree{
        maxv: make([]int, n*4),
        minv: make([]int, n*4),
        n:    n,
    }
    s.build(1, 0, n-1, nums)
    return s
}

func (s *segTree) build(node, l, r int, nums []int) {
    if l == r {
        s.maxv[node] = nums[l]
        s.minv[node] = nums[l]
        return
    }
    m := (l + r) / 2
    s.build(node*2, l, m, nums)
    s.build(node*2+1, m+1, r, nums)
    s.maxv[node] = max(s.maxv[node*2], s.maxv[node*2+1])
    s.minv[node] = min(s.minv[node*2], s.minv[node*2+1])
}

func (s *segTree) queryMax(node, l, r, ql, qr int) int {
    if ql <= l && r <= qr {
        return s.maxv[node]
    }
    m := (l + r) / 2
    res := math.MinInt
    if ql <= m {
        res = max(res, s.queryMax(node*2, l, m, ql, qr))
    }
    if qr > m {
        res = max(res, s.queryMax(node*2+1, m+1, r, ql, qr))
    }
    return res
}

func (s *segTree) queryMin(node, l, r, ql, qr int) int {
    if ql <= l && r <= qr {
        return s.minv[node]
    }
    m := (l + r) / 2
    res := math.MaxInt
    if ql <= m {
        res = min(res, s.queryMin(node*2, l, m, ql, qr))
    }
    if qr > m {
        res = min(res, s.queryMin(node*2+1, m+1, r, ql, qr))
    }
    return res
}

func maxTotalValue(nums []int, k int) int64 {
    n := len(nums)
    seg := newSegTree(nums)
    h := &hp{}
    for l := 0; l < n; l++ {
        heap.Push(h, tuple{seg.queryMax(1, 0, n-1, l, n-1) - seg.queryMin(1, 0, n-1, l, n-1), l, n - 1})
    }
    var ans int64 = 0
    for ; k > 0; k-- {
        t := heap.Pop(h).(tuple)
        ans += int64(t.val)
        if t.r > t.l {
            heap.Push(h, tuple{seg.queryMax(1, 0, n-1, t.l, t.r-1) - seg.queryMin(1, 0, n-1, t.l, t.r-1), t.l, t.r - 1})
        }
    }
    return ans
}

type tuple struct{ val, l, r int }
type hp []tuple
func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].val > h[j].val }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class SegTree {

    int[] maxv;
    int[] minv;
    int n;

    SegTree(int[] nums) {
        n = nums.length;
        maxv = new int[n * 4];
        minv = new int[n * 4];
        build(1, 0, n - 1, nums);
    }

    void build(int node, int l, int r, int[] nums) {
        if (l == r) {
            maxv[node] = minv[node] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        build(node * 2, l, m, nums);
        build(node * 2 + 1, m + 1, r, nums);
        maxv[node] = Math.max(maxv[node * 2], maxv[node * 2 + 1]);
        minv[node] = Math.min(minv[node * 2], minv[node * 2 + 1]);
    }

    int queryMax(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return maxv[node];
        }
        int m = (l + r) / 2;
        int res = Integer.MIN_VALUE;
        if (ql <= m) {
            res = Math.max(res, queryMax(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = Math.max(res, queryMax(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }

    int queryMin(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return minv[node];
        }
        int m = (l + r) / 2;
        int res = Integer.MAX_VALUE;
        if (ql <= m) {
            res = Math.min(res, queryMin(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = Math.min(res, queryMin(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }
}

class Solution {

    public long maxTotalValue(int[] nums, int k) {
        int n = nums.length;
        SegTree seg = new SegTree(nums);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int l = 0; l < n; l++) {
            pq.offer(
                new int[] {
                    seg.queryMax(1, 0, n - 1, l, n - 1) -
                    seg.queryMin(1, 0, n - 1, l, n - 1),
                    l,
                    n - 1,
                }
            );
        }
        long ans = 0;
        while (k-- > 0) {
            int[] top = pq.poll();
            ans += top[0];
            int l = top[1];
            int r = top[2];
            if (r > l) {
                pq.offer(
                    new int[] {
                        seg.queryMax(1, 0, n - 1, l, r - 1) -
                        seg.queryMin(1, 0, n - 1, l, r - 1),
                        l,
                        r - 1,
                    }
                );
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
class SegTree {
    constructor(nums) {
        this.n = nums.length;
        this.maxv = new Array(this.n * 4).fill(0);
        this.minv = new Array(this.n * 4).fill(0);
        this.build(1, 0, this.n - 1, nums);
    }

    build(node, l, r, nums) {
        if (l === r) {
            this.maxv[node] = this.minv[node] = nums[l];
            return;
        }
        const m = (l + r) >> 1;
        this.build(node * 2, l, m, nums);
        this.build(node * 2 + 1, m + 1, r, nums);
        this.maxv[node] = Math.max(
            this.maxv[node * 2],
            this.maxv[node * 2 + 1],
        );
        this.minv[node] = Math.min(
            this.minv[node * 2],
            this.minv[node * 2 + 1],
        );
    }

    queryMax(node, l, r, ql, qr) {
        if (ql <= l && r <= qr) {
            return this.maxv[node];
        }
        const m = (l + r) >> 1;
        let res = -Infinity;
        if (ql <= m) {
            res = Math.max(res, this.queryMax(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = Math.max(res, this.queryMax(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }

    queryMin(node, l, r, ql, qr) {
        if (ql <= l && r <= qr) {
            return this.minv[node];
        }
        const m = (l + r) >> 1;
        let res = Infinity;
        if (ql <= m) {
            res = Math.min(res, this.queryMin(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = Math.min(res, this.queryMin(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }
}

var maxTotalValue = function (nums, k) {
    const n = nums.length;
    const seg = new SegTree(nums);
    const heap = new Heap((a, b) => b[0] - a[0]);
    for (let l = 0; l < n; l++) {
        heap.push([
            seg.queryMax(1, 0, n - 1, l, n - 1) -
                seg.queryMin(1, 0, n - 1, l, n - 1),
            l,
            n - 1,
        ]);
    }
    let ans = 0;
    while (k--) {
        const [val, l, r] = heap.pop();
        ans += val;
        if (r > l) {
            heap.push([
                seg.queryMax(1, 0, n - 1, l, r - 1) -
                    seg.queryMin(1, 0, n - 1, l, r - 1),
                l,
                r - 1,
            ]);
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class SegTree:
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.maxv = [0] * (4 * self.n)
        self.minv = [0] * (4 * self.n)
        self.build(1, 0, self.n - 1, nums)

    def build(self, node: int, l: int, r: int, nums: List[int]):
        if l == r:
            self.maxv[node] = self.minv[node] = nums[l]
            return
        m = (l + r) // 2
        self.build(node * 2, l, m, nums)
        self.build(node * 2 + 1, m + 1, r, nums)
        self.maxv[node] = max(self.maxv[node * 2], self.maxv[node * 2 + 1])
        self.minv[node] = min(self.minv[node * 2], self.minv[node * 2 + 1])

    def queryMax(self, node: int, l: int, r: int, ql: int, qr: int) -> int:
        if ql <= l and r <= qr:
            return self.maxv[node]
        m = (l + r) // 2
        res = -(10**18)
        if ql <= m:
            res = max(res, self.queryMax(node * 2, l, m, ql, qr))
        if qr > m:
            res = max(res, self.queryMax(node * 2 + 1, m + 1, r, ql, qr))
        return res

    def queryMin(self, node: int, l: int, r: int, ql: int, qr: int) -> int:
        if ql <= l and r <= qr:
            return self.minv[node]
        m = (l + r) // 2
        res = 10**18
        if ql <= m:
            res = min(res, self.queryMin(node * 2, l, m, ql, qr))
        if qr > m:
            res = min(res, self.queryMin(node * 2 + 1, m + 1, r, ql, qr))
        return res


class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        n = len(nums)
        seg = SegTree(nums)
        pq = [
            (
                -(
                    seg.queryMax(1, 0, n - 1, l, n - 1)
                    - seg.queryMin(1, 0, n - 1, l, n - 1)
                ),
                l,
                n - 1,
            )
            for l in range(n)
        ]
        heapq.heapify(pq)
        ans = 0
        while k:
            negVal, l, r = heapq.heappop(pq)
            ans -= negVal
            k -= 1
            if r > l:
                heapq.heappush(
                    pq,
                    (
                        -(
                            seg.queryMax(1, 0, n - 1, l, r - 1)
                            - seg.queryMin(1, 0, n - 1, l, r - 1)
                        ),
                        l,
                        r - 1,
                    ),
                )
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class SegTree {
    maxv: number[];
    minv: number[];
    n: number;
    constructor(nums: number[]) {
        this.n = nums.length;
        this.maxv = new Array(this.n * 4).fill(0);
        this.minv = new Array(this.n * 4).fill(0);
        this.build(1, 0, this.n - 1, nums);
    }

    build(node: number, l: number, r: number, nums: number[]) {
        if (l === r) {
            this.maxv[node] = this.minv[node] = nums[l];
            return;
        }
        const m = (l + r) >> 1;
        this.build(node * 2, l, m, nums);
        this.build(node * 2 + 1, m + 1, r, nums);
        this.maxv[node] = Math.max(
            this.maxv[node * 2],
            this.maxv[node * 2 + 1],
        );
        this.minv[node] = Math.min(
            this.minv[node * 2],
            this.minv[node * 2 + 1],
        );
    }

    queryMax(
        node: number,
        l: number,
        r: number,
        ql: number,
        qr: number,
    ): number {
        if (ql <= l && r <= qr) {
            return this.maxv[node];
        }
        const m = (l + r) >> 1;
        let res = -Infinity;
        if (ql <= m) {
            res = Math.max(res, this.queryMax(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = Math.max(res, this.queryMax(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }

    queryMin(
        node: number,
        l: number,
        r: number,
        ql: number,
        qr: number,
    ): number {
        if (ql <= l && r <= qr) {
            return this.minv[node];
        }
        const m = (l + r) >> 1;
        let res = Infinity;
        if (ql <= m) {
            res = Math.min(res, this.queryMin(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = Math.min(res, this.queryMin(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }
}

function maxTotalValue(nums: number[], k: number): number {
    const n = nums.length;
    const seg = new SegTree(nums);
    const heap = new Heap(
        (a: [number, number, number], b: [number, number, number]) =>
            b[0] - a[0],
    );
    for (let l = 0; l < n; l++) {
        heap.push([
            seg.queryMax(1, 0, n - 1, l, n - 1) -
                seg.queryMin(1, 0, n - 1, l, n - 1),
            l,
            n - 1,
        ]);
    }
    let ans = 0;
    while (k--) {
        const [val, l, r] = heap.pop()!;
        ans += val;
        if (r > l) {
            heap.push([
                seg.queryMax(1, 0, n - 1, l, r - 1) -
                    seg.queryMin(1, 0, n - 1, l, r - 1),
                l,
                r - 1,
            ]);
        }
    }
    return ans;
}
```

</details>
