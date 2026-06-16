# 3013. Divide an Array Into Subarrays With Minimum Cost II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/)  
`Array` `Hash Table` `Sliding Window` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 3013 - Divide an Array Into Subarrays With Minimum Cost II](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/)

## Problem

You are given a 0-indexed array of integers nums of length n, and two positive integers k and dist.

The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

You need to divide nums into k disjoint contiguous subarrays, such that the difference between the starting index of the second subarray and the starting index of the kth subarray should be less than or equal to dist. In other words, if you divide nums into the subarrays nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)], then ik-1 - i1 <= dist.

Return the minimum possible sum of the cost of these subarrays.

### Example 1

```text
Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
Output: 5
Explanation: The best possible way to divide nums into 3 subarrays is: [1,3], [2,6,4], and [2]. This choice is valid because ik-1 - i1 is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + nums[2] + nums[5] which is 1 + 2 + 2 = 5.
It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 5.
```

### Example 2

```text
Input: nums = [10,1,2,2,2,1], k = 4, dist = 3
Output: 15
Explanation: The best possible way to divide nums into 4 subarrays is: [10], [1], [2], and [2,2,1]. This choice is valid because ik-1 - i1 is 3 - 1 = 2 which is less than dist. The total cost is nums[0] + nums[1] + nums[2] + nums[3] which is 10 + 1 + 2 + 2 = 15.
The division [10], [1], [2,2,2], and [1] is not valid, because the difference between ik-1 and i1 is 5 - 1 = 4, which is greater than dist.
It can be shown that there is no possible way to divide nums into 4 subarrays at a cost lower than 15.
```

### Example 3

```text
Input: nums = [10,8,18,9], k = 3, dist = 1
Output: 36
Explanation: The best possible way to divide nums into 3 subarrays is: [10], [8], and [18,9]. This choice is valid because ik-1 - i1 is 2 - 1 = 1 which is equal to dist.The total cost is nums[0] + nums[1] + nums[2] which is 10 + 8 + 18 = 36.
The division [10], [8,18], and [9] is not valid, because the difference between ik-1 and i1 is 3 - 1 = 2, which is greater than dist.
It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 36.
```

## Constraints

- 3 <= n <= 105
- 1 <= nums[i] <= 109
- 3 <= k <= n
- k - 2 <= dist <= n - 2

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Cost to Split an Array](https://leetcode.com/problems/minimum-cost-to-split-an-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3013. Divide an Array Into Subarrays With Minimum Cost II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Ordered Set | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Ordered Set

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
    compare cmpFunc;
} PriorityQueue;

typedef struct HashItem {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

// comparison function: min-heap
static bool minHeapCmp(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    return e1->data[0] > e2->data[0];
}

// comparison function: max-heap
static bool maxHeapCmp(const void* a, const void* b) {
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
    obj->cmpFunc = cmpFunc;
    return obj;
}

void heapify(PriorityQueue* obj) {
    for (int i = obj->queueSize / 2 - 1; i >= 0; i--) {
        down(obj->arr, obj->queueSize, i, obj->cmpFunc);
    }
}

void enQueue(PriorityQueue* obj, Element* e) {
    if (obj->queueSize == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = realloc(obj->arr, sizeof(Element) * obj->capacity);
    }
    memcpy(&obj->arr[obj->queueSize], e, sizeof(Element));
    for (int i = obj->queueSize;
         i > 0 && obj->cmpFunc(&obj->arr[(i - 1) / 2], &obj->arr[i]);
         i = (i - 1) / 2) {
        swap(obj->arr, i, (i - 1) / 2);
    }
    obj->queueSize++;
}

Element* deQueue(PriorityQueue* obj) {
    if (obj->queueSize == 0) return NULL;
    swap(obj->arr, 0, obj->queueSize - 1);
    down(obj->arr, obj->queueSize - 1, 0, obj->cmpFunc);
    Element* e = &obj->arr[obj->queueSize - 1];
    obj->queueSize--;
    return e;
}

bool isEmpty(const PriorityQueue* obj) { return obj->queueSize == 0; }

Element* top(const PriorityQueue* obj) {
    if (obj->queueSize == 0) {
        return NULL;
    } else {
        return &obj->arr[0];
    }
}

int size(const PriorityQueue* obj) { return obj->queueSize; }

void clear(PriorityQueue* obj) { obj->queueSize = 0; }

void freeQueue(PriorityQueue* obj) {
    free(obj->arr);
    free(obj);
}

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

void hashEraseItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if (pEntry) {
        HASH_DEL(*obj, pEntry);
        free(pEntry);
    }
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

typedef struct {
    int k;
    HashItem* st1;
    HashItem* st2;
    PriorityQueue* tree1;
    PriorityQueue* tree2;
    int st1Size;
    int st2Size;
    long long sm;
} Container;

Container* createContainer(int k) {
    Container* cnt = (Container*)malloc(sizeof(Container));
    cnt->k = k;
    cnt->st1 = NULL;
    cnt->st2 = NULL;
    cnt->tree1 = createPriorityQueue(maxHeapCmp);
    cnt->tree2 = createPriorityQueue(minHeapCmp);
    cnt->st1Size = 0;
    cnt->st2Size = 0;
    cnt->sm = 0;
    return cnt;
}

void addOne(HashItem** map, PriorityQueue* heap, int key) {
    int count = hashGetItem(map, key, 0);
    hashSetItem(map, key, count + 1);

    if (count == 0) {
        Element e;
        e.data[0] = key;
        e.data[1] = 0;
        enQueue(heap, &e);
    }
}

void removeOne(HashItem** map, PriorityQueue* heap, int key) {
    HashItem* entry = hashFindItem(map, key);
    if (!entry) {
        return;
    }
    entry->val--;
    if (entry->val == 0) {
        hashEraseItem(map, key);
    }
}

void adjust(Container* cnt) {
    while (cnt->st1Size < cnt->k && cnt->st2Size > 0) {
        while (!isEmpty(cnt->tree2)) {
            Element* topElem = top(cnt->tree2);
            if (!topElem || hashGetItem(&cnt->st2, topElem->data[0], 0) == 0) {
                deQueue(cnt->tree2);
            } else {
                break;
            }
        }

        if (isEmpty(cnt->tree2)) {
            break;
        }

        int x = top(cnt->tree2)->data[0];
        removeOne(&cnt->st2, cnt->tree2, x);
        cnt->st2Size--;
        addOne(&cnt->st1, cnt->tree1, x);
        cnt->st1Size++;
        cnt->sm += x;
    }

    while (cnt->st1Size > cnt->k) {
        while (!isEmpty(cnt->tree1)) {
            Element* topElem = top(cnt->tree1);
            if (!topElem || hashGetItem(&cnt->st1, topElem->data[0], 0) == 0) {
                deQueue(cnt->tree1);
            } else {
                break;
            }
        }

        if (isEmpty(cnt->tree1)) {
            break;
        }
        int x = top(cnt->tree1)->data[0];
        removeOne(&cnt->st1, cnt->tree1, x);
        cnt->st1Size--;
        cnt->sm -= x;

        addOne(&cnt->st2, cnt->tree2, x);
        cnt->st2Size++;
    }
}

void containerAdd(Container* cnt, int x) {
    while (!isEmpty(cnt->tree2)) {
        Element* topElem = top(cnt->tree2);
        if (!topElem || hashGetItem(&cnt->st2, topElem->data[0], 0) == 0) {
            deQueue(cnt->tree2);
        } else {
            break;
        }
    }

    if (cnt->st2Size > 0 && !isEmpty(cnt->tree2) &&
        x >= top(cnt->tree2)->data[0]) {
        addOne(&cnt->st2, cnt->tree2, x);
        cnt->st2Size++;
    } else {
        addOne(&cnt->st1, cnt->tree1, x);
        cnt->st1Size++;
        cnt->sm += x;
    }
    adjust(cnt);
}

void containerErase(Container* cnt, int x) {
    if (hashGetItem(&cnt->st1, x, 0) > 0) {
        removeOne(&cnt->st1, cnt->tree1, x);
        cnt->st1Size--;
        cnt->sm -= x;
    } else if (hashGetItem(&cnt->st2, x, 0) > 0) {
        removeOne(&cnt->st2, cnt->tree2, x);
        cnt->st2Size--;
    }
    adjust(cnt);
}

long long containerSum(Container* cnt) { return cnt->sm; }

void freeContainer(Container* cnt) {
    hashFree(&cnt->st1);
    hashFree(&cnt->st2);
    freeQueue(cnt->tree1);
    freeQueue(cnt->tree2);
    free(cnt);
}

long long minimumCost(int* nums, int numsSize, int k, int dist) {
    Container* cnt = createContainer(k - 2);
    for (int i = 1; i < k - 1; i++) {
        containerAdd(cnt, nums[i]);
    }

    long long ans = containerSum(cnt) + nums[k - 1];
    for (int i = k; i < numsSize; i++) {
        int j = i - dist - 1;
        if (j > 0) {
            containerErase(cnt, nums[j]);
        }
        containerAdd(cnt, nums[i - 1]);
        long long current = containerSum(cnt) + nums[i];
        if (current < ans) {
            ans = current;
        }
    }

    long long result = ans + nums[0];
    freeContainer(cnt);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// two multisets maintain the first k smallest values
class Container {
public:
    Container(int k) : k(k), sm(0) {}

    // adjust the size of the ordered set to ensure that the first k smallest
    // values are all in st1
    void adjust() {
        while (st1.size() < k && st2.size() > 0) {
            int x = *(st2.begin());
            st1.emplace(x);
            sm += x;
            st2.erase(st2.begin());
        }
        while (st1.size() > k) {
            int x = *prev(st1.end());
            st2.emplace(x);
            st1.erase(prev(st1.end()));
            sm -= x;
        }
    }

    // insert element x
    void add(int x) {
        if (!st2.empty() && x >= *(st2.begin())) {
            st2.emplace(x);
        } else {
            st1.emplace(x);
            sm += x;
        }
        adjust();
    }

    // delete element x
    void erase(int x) {
        auto it = st1.find(x);
        if (it != st1.end()) {
            st1.erase(it), sm -= x;
        } else {
            st2.erase(st2.find(x));
        }
        adjust();
    }

    // sum of the first k smallest elements
    long long sum() { return sm; }

private:
    int k;
    // st1 saves the k smallest values, st2 saves the other values
    multiset<int> st1, st2;
    // sm represents the sum of the first k smallest elements
    long long sm;
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        // sliding window initialization
        Container cnt(k - 2);
        for (int i = 1; i < k - 1; i++) {
            cnt.add(nums[i]);
        }

        long long ans = cnt.sum() + nums[k - 1];
        // enumerate the beginning of the last array
        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            if (j > 0) {
                cnt.erase(nums[j]);
            }
            cnt.add(nums[i - 1]);
            ans = min(ans, cnt.sum() + nums[i]);
        }

        return ans + nums[0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Container {
    private int k;
    private PriorityQueue<int, int> st1;
    private PriorityQueue<int, int> st2;
    private Dictionary<int, int> cnt1;
    private Dictionary<int, int> cnt2;
    private Dictionary<int, int> del1;
    private Dictionary<int, int> del2;
    private int st1Size;
    private int st2Size;
    private long sm;

    public Container(int k) {
        this.k = k;
        this.st1 = new PriorityQueue<int, int>();
        this.st2 = new PriorityQueue<int, int>();
        this.cnt1 = new Dictionary<int, int>();
        this.cnt2 = new Dictionary<int, int>();
        this.del1 = new Dictionary<int, int>();
        this.del2 = new Dictionary<int, int>();
        this.st1Size = 0;
        this.st2Size = 0;
        this.sm = 0;
    }

    private static void Inc(Dictionary<int, int> dict, int key) {
        if (dict.TryGetValue(key, out int v))
            dict[key] = v + 1;
        else
            dict[key] = 1;
    }

    private static void Dec(Dictionary<int, int> dict, int key) {
        int v = dict[key] - 1;
        if (v == 0)
            dict.Remove(key);
        else
            dict[key] = v;
    }

    private void Prune1() {
        while (st1.Count > 0) {
            int x = st1.Peek();
            if (del1.TryGetValue(x, out int d) && d > 0) {
                st1.Dequeue();
                if (d == 1)
                    del1.Remove(x);
                else
                    del1[x] = d - 1;
            } else {
                break;
            }
        }
    }

    private void Prune2() {
        while (st2.Count > 0) {
            int x = st2.Peek();
            if (del2.TryGetValue(x, out int d) && d > 0) {
                st2.Dequeue();
                if (d == 1)
                    del2.Remove(x);
                else
                    del2[x] = d - 1;
            } else {
                break;
            }
        }
    }

    private int ExtractMax1() {
        Prune1();
        int x = st1.Dequeue();
        Dec(cnt1, x);
        st1Size--;
        sm -= x;
        return x;
    }

    private int ExtractMin2() {
        Prune2();
        int x = st2.Dequeue();
        Dec(cnt2, x);
        st2Size--;
        return x;
    }

    private int Min2() {
        Prune2();
        return st2.Peek();
    }

    private void Insert1(int x) {
        st1.Enqueue(x, -x);
        Inc(cnt1, x);
        st1Size++;
        sm += x;
    }

    private void Insert2(int x) {
        st2.Enqueue(x, x);
        Inc(cnt2, x);
        st2Size++;
    }

    private void Adjust() {
        while (st1Size < k && st2Size > 0) {
            int x = ExtractMin2();
            Insert1(x);
        }
        while (st1Size > k) {
            int x = ExtractMax1();
            Insert2(x);
        }
    }

    // insert element x
    public void Add(int x) {
        if (st2Size > 0) {
            int mn = Min2();
            if (x >= mn)
                Insert2(x);
            else
                Insert1(x);
        } else {
            Insert1(x);
        }
        Adjust();
    }

    // delete element x
    public void Erase(int x) {
        if (cnt1.TryGetValue(x, out int c1) && c1 > 0) {
            Dec(cnt1, x);
            st1Size--;
            sm -= x;
            Inc(del1, x);
        } else {
            Dec(cnt2, x);
            st2Size--;
            Inc(del2, x);
        }
        Adjust();
    }

    // sum of the first k smallest elements
    public long Sum() {
        return sm;
    }
}

public class Solution {
    public long MinimumCost(int[] nums, int k, int dist) {
        int n = nums.Length;
        Container cnt = new Container(k - 2);
        for (int i = 1; i < k - 1; i++) {
            cnt.Add(nums[i]);
        }

        long ans = cnt.Sum() + nums[k - 1];
        // sliding window
        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            if (j > 0) {
                cnt.Erase(nums[j]);
            }
            cnt.Add(nums[i - 1]);
            ans = Math.Min(ans, cnt.Sum() + nums[i]);
        }

        return ans + nums[0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type MultiSet struct {
	tree    *redblacktree.Tree
	counter map[int]int
	size    int
}

func NewMultiSet() *MultiSet {
	return &MultiSet{
		tree:    redblacktree.NewWithIntComparator(),
		counter: make(map[int]int),
		size:    0,
	}
}

func (ms *MultiSet) Add(x int) {
	if count, exists := ms.counter[x]; exists {
		ms.counter[x] = count + 1
	} else {
		ms.counter[x] = 1
		ms.tree.Put(x, struct{}{})
	}
	ms.size++
}

func (ms *MultiSet) Remove(x int) bool {
	if count, exists := ms.counter[x]; exists {
		if count == 1 {
			delete(ms.counter, x)
			ms.tree.Remove(x)
		} else {
			ms.counter[x] = count - 1
		}
		ms.size--
		return true
	}
	return false
}

func (ms *MultiSet) Size() int {
	return ms.size
}

func (ms *MultiSet) IsEmpty() bool {
	return ms.size == 0
}

func (ms *MultiSet) First() (int, bool) {
	if ms.tree.Empty() {
		return 0, false
	}
	return ms.tree.Left().Key.(int), true
}

func (ms *MultiSet) Last() (int, bool) {
	if ms.tree.Empty() {
		return 0, false
	}
	return ms.tree.Right().Key.(int), true
}

func (ms *MultiSet) Contains(x int) bool {
	_, exists := ms.counter[x]
	return exists
}

type Container struct {
	k   int
	st1 *MultiSet
	st2 *MultiSet
	sm  int64
}

func NewContainer(k int) *Container {
	return &Container{
		k:   k,
		st1: NewMultiSet(),
		st2: NewMultiSet(),
		sm:  0,
	}
}

func (m *Container) adjust() {
	for m.st1.Size() < m.k && !m.st2.IsEmpty() {
		if x, ok := m.st2.First(); ok {
			m.st2.Remove(x)
			m.st1.Add(x)
			m.sm += int64(x)
		}
	}
	for m.st1.Size() > m.k {
		if x, ok := m.st1.Last(); ok {
			m.st1.Remove(x)
			m.st2.Add(x)
			m.sm -= int64(x)
		}
	}
}

// insert element x
func (m *Container) add(x int) {
	if !m.st2.IsEmpty() {
		if first, ok := m.st2.First(); ok && x >= first {
			m.st2.Add(x)
		} else {
			m.st1.Add(x)
			m.sm += int64(x)
		}
	} else {
		m.st1.Add(x)
		m.sm += int64(x)
	}
	m.adjust()
}

// delete element x
func (m *Container) erase(x int) {
	if m.st1.Contains(x) {
		m.st1.Remove(x)
		m.sm -= int64(x)
	} else if m.st2.Contains(x) {
		m.st2.Remove(x)
	}
	m.adjust()
}

// sum of the first k smallest elements
func (m *Container) sum() int64 {
	return m.sm
}

func minimumCost(nums []int, k int, dist int) int64 {
	n := len(nums)
	cnt := NewContainer(k - 2)

	for i := 1; i < k-1; i++ {
		cnt.add(nums[i])
	}

	ans := cnt.sum() + int64(nums[k-1])
	for i := k; i < n; i++ {
		j := i - dist - 1
		if j > 0 {
			cnt.erase(nums[j])
		}
		cnt.add(nums[i-1])
		current := cnt.sum() + int64(nums[i])
		if current < ans {
			ans = current
		}
	}

	return ans + int64(nums[0])
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Container {

    private int k;
    private int st1Size;
    private int st2Size;
    // st1 saves the k smallest values, st2 saves the other values
    private TreeMap<Integer, Integer> st1;
    private TreeMap<Integer, Integer> st2;
    // sm represents the sum of the first k smallest elements
    private long sm;

    public Container(int k) {
        this.k = k;
        this.st1 = new TreeMap<>();
        this.st2 = new TreeMap<>();
        this.sm = 0;
        this.st1Size = 0;
        this.st2Size = 0;
    }

    private void removeOne(TreeMap<Integer, Integer> map, int key) {
        int count = map.get(key);
        if (count == 1) {
            map.remove(key);
        } else {
            map.put(key, count - 1);
        }
    }

    private void addOne(TreeMap<Integer, Integer> map, int key) {
        map.put(key, map.getOrDefault(key, 0) + 1);
    }

    private void adjust() {
        while (st1Size < k && !st2.isEmpty()) {
            int x = st2.firstKey();
            addOne(st1, x);
            st1Size++;
            sm += x;
            removeOne(st2, x);
            st2Size--;
        }
        while (st1Size > k) {
            int x = st1.lastKey();
            addOne(st2, x);
            st2Size++;
            removeOne(st1, x);
            st1Size--;
            sm -= x;
        }
    }

    // insert element x
    public void add(int x) {
        if (!st2.isEmpty() && x >= st2.firstKey()) {
            addOne(st2, x);
            st2Size++;
        } else {
            addOne(st1, x);
            st1Size++;
            sm += x;
        }
        adjust();
    }

    // delete element x
    public void erase(int x) {
        if (st1.containsKey(x)) {
            removeOne(st1, x);
            st1Size--;
            sm -= x;
        } else if (st2.containsKey(x)) {
            removeOne(st2, x);
            st2Size--;
        }
        adjust();
    }

    // sum of the first k smallest elements
    public long sum() {
        return sm;
    }
}

class Solution {

    public long minimumCost(int[] nums, int k, int dist) {
        int n = nums.length;
        Container cnt = new Container(k - 2);
        for (int i = 1; i < k - 1; i++) {
            cnt.add(nums[i]);
        }

        long ans = cnt.sum() + nums[k - 1];
        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            if (j > 0) {
                cnt.erase(nums[j]);
            }
            cnt.add(nums[i - 1]);
            ans = Math.min(ans, cnt.sum() + nums[i]);
        }

        return ans + nums[0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const {
    BinarySearchTree,
    BinarySearchTreeNode,
    AvlTree,
    AvlTreeNode,
} = require("@datastructures-js/binary-search-tree");

class Container {
    constructor(k) {
        this.k = k;
        this.st1 = new Map();
        this.st2 = new Map();
        this.st1Size = 0;
        this.st2Size = 0;
        this.tree1 = new AvlTree((a, b) => a - b);
        this.tree2 = new AvlTree((a, b) => a - b);
        this.sm = 0;
    }

    add(x) {
        if (this.st2Size > 0 && x >= this.tree2.min().getValue()) {
            this.tree2.insert(x);
            this.st2.set(x, (this.st2.get(x) || 0) + 1);
            this.st2Size++;
        } else {
            this.tree1.insert(x);
            this.st1.set(x, (this.st1.get(x) || 0) + 1);
            this.sm += x;
            this.st1Size++;
        }
        this.adjust();
    }

    erase(x) {
        if (this.st1.has(x) && this.st1.get(x) > 0) {
            this.st1.set(x, this.st1.get(x) - 1);
            this.st1Size--;
            if (this.st1.get(x) === 0) {
                this.st1.delete(x);
                this.tree1.remove(x);
            }
            this.sm -= x;
        } else if (this.st2.has(x) && this.st2.get(x) > 0) {
            this.st2.set(x, this.st2.get(x) - 1);
            this.st2Size--;
            if (this.st2.get(x) === 0) {
                this.st2.delete(x);
                this.tree2.remove(x);
            }
        }
        this.adjust();
    }

    adjust() {
        while (this.st1Size < this.k && this.st2Size > 0) {
            const x = this.tree2.min().getValue();
            this.st1Size++;
            this.st2Size--;
            this.st2.set(x, this.st2.get(x) - 1);
            if (this.st2.get(x) === 0) {
                this.tree2.remove(x);
                this.st2.delete(x);
            }
            this.st1.set(x, (this.st1.get(x) || 0) + 1);
            this.tree1.insert(x);
            this.sm += x;
        }

        while (this.st1Size > this.k) {
            const x = this.tree1.max().getValue();
            this.st1Size--;
            this.st2Size++;
            this.st1.set(x, this.st1.get(x) - 1);
            if (this.st1.get(x) === 0) {
                this.st1.delete(x);
                this.tree1.remove(x);
            }
            this.st2.set(x, (this.st2.get(x) || 0) + 1);
            this.tree2.insert(x);
            this.sm -= x;
        }
    }

    sum() {
        return this.sm;
    }
}

var minimumCost = function (nums, k, dist) {
    const n = nums.length;
    const cnt = new Container(k - 2);
    for (let i = 1; i < k - 1; i++) {
        cnt.add(nums[i]);
    }

    let ans = cnt.sum() + nums[k - 1];
    for (let i = k; i < n; i++) {
        const j = i - dist - 1;
        if (j > 0) {
            cnt.erase(nums[j]);
        }
        cnt.add(nums[i - 1]);
        ans = Math.min(ans, cnt.sum() + nums[i]);
    }

    return ans + nums[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Container:
    def __init__(self, k: int):
        self.k = k
        self.st1 = SortedList()
        self.st2 = SortedList()
        self.sm = 0

    def adjust(self):
        while len(self.st1) < self.k and len(self.st2) > 0:
            x = self.st2[0]
            self.st1.add(x)
            self.st2.remove(x)
            self.sm += x

        while len(self.st1) > self.k:
            x = self.st1[-1]
            self.st2.add(x)
            self.st1.remove(x)
            self.sm -= x

    # insert element x
    def add(self, x: int):
        if len(self.st2) > 0 and x >= self.st2[0]:
            self.st2.add(x)
        else:
            self.st1.add(x)
            self.sm += x
        self.adjust()

    # delete element x
    def erase(self, x: int):
        if x in self.st1:
            self.st1.remove(x)
            self.sm -= x
        elif x in self.st2:
            self.st2.remove(x)
        self.adjust()

    # sum of the first k smallest elements
    def sum(self) -> int:
        return self.sm


class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        n = len(nums)
        cnt = Container(k - 2)
        for i in range(1, k - 1):
            cnt.add(nums[i])

        ans = cnt.sum() + nums[k - 1]
        for i in range(k, n):
            j = i - dist - 1
            if j > 0:
                cnt.erase(nums[j])
            cnt.add(nums[i - 1])
            ans = min(ans, cnt.sum() + nums[i])

        return ans + nums[0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
import {
    AvlTree,
    BinarySearchTree,
    BinarySearchTreeNode,
    AvlTreeNode,
} from "@datastructures-js/binary-search-tree";

class Container {
    private k: number;
    private st1: Map<number, number>;
    private st2: Map<number, number>;
    private st1Size: number;
    private st2Size: number;
    private tree1: AvlTree<number>;
    private tree2: AvlTree<number>;
    private sm: number;

    constructor(k: number) {
        this.k = k;
        this.st1 = new Map<number, number>();
        this.st2 = new Map<number, number>();
        this.st1Size = 0;
        this.st2Size = 0;
        this.tree1 = new AvlTree<number>((a: number, b: number) => a - b);
        this.tree2 = new AvlTree<number>((a: number, b: number) => a - b);
        this.sm = 0;
    }

    add(x: number): void {
        if (this.st2Size > 0 && x >= this.tree2.min().getValue()) {
            this.tree2.insert(x);
            this.st2.set(x, (this.st2.get(x) || 0) + 1);
            this.st2Size++;
        } else {
            this.tree1.insert(x);
            this.st1.set(x, (this.st1.get(x) || 0) + 1);
            this.sm += x;
            this.st1Size++;
        }
        this.adjust();
    }

    erase(x: number): void {
        if (this.st1.has(x) && this.st1.get(x)! > 0) {
            this.st1.set(x, this.st1.get(x)! - 1);
            this.st1Size--;
            if (this.st1.get(x)! === 0) {
                this.st1.delete(x);
                this.tree1.remove(x);
            }
            this.sm -= x;
        } else if (this.st2.has(x) && this.st2.get(x)! > 0) {
            this.st2.set(x, this.st2.get(x)! - 1);
            this.st2Size--;
            if (this.st2.get(x)! === 0) {
                this.st2.delete(x);
                this.tree2.remove(x);
            }
        }
        this.adjust();
    }

    private adjust(): void {
        while (this.st1Size < this.k && this.st2Size > 0) {
            const x = this.tree2.min().getValue();
            this.st1Size++;
            this.st2Size--;
            this.st2.set(x, this.st2.get(x)! - 1);
            if (this.st2.get(x)! === 0) {
                this.tree2.remove(x);
                this.st2.delete(x);
            }
            this.st1.set(x, (this.st1.get(x) || 0) + 1);
            this.tree1.insert(x);
            this.sm += x;
        }

        while (this.st1Size > this.k) {
            const x = this.tree1.max().getValue();
            this.st1Size--;
            this.st2Size++;
            this.st1.set(x, this.st1.get(x)! - 1);
            if (this.st1.get(x)! === 0) {
                this.tree1.remove(x);
                this.st1.delete(x);
            }
            this.st2.set(x, (this.st2.get(x) || 0) + 1);
            this.tree2.insert(x);
            this.sm -= x;
        }
    }

    sum(): number {
        return this.sm;
    }
}

function minimumCost(nums: number[], k: number, dist: number): number {
    const n = nums.length;
    const cnt = new Container(k - 2);
    for (let i = 1; i < k - 1; i++) {
        cnt.add(nums[i]);
    }

    let ans = cnt.sum() + nums[k - 1];
    for (let i = k; i < n; i++) {
        const j = i - dist - 1;
        if (j > 0) {
            cnt.erase(nums[j]);
        }
        cnt.add(nums[i - 1]);
        ans = Math.min(ans, cnt.sum() + nums[i]);
    }

    return ans + nums[0];
}
```

</details>
