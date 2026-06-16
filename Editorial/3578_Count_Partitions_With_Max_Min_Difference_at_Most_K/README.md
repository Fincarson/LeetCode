# 3578. Count Partitions With Max-Min Difference at Most K

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/)  
`Array` `Dynamic Programming` `Queue` `Sliding Window` `Prefix Sum` `Monotonic Queue`

**Problem Link:** [LeetCode 3578 - Count Partitions With Max-Min Difference at Most K](https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/)

## Problem

You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

Return the total number of ways to partition nums under this condition.

Since the answer may be too large, return it modulo 109 + 7.

### Example 1

### Example 2

## Constraints

- 2 <= nums.length <= 5 * 104
- 1 <= nums[i] <= 109
- 0 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Great Partitions](https://leetcode.com/problems/number-of-great-partitions/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3578. Count Partitions With Max-Min Difference at Most K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window + Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Monotonic Queue Optimization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sliding Window + Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MIN_QUEUE_SIZE 64

typedef struct Element {
    int data[1];
} Element;

typedef bool (*compare)(const void*, const void*);

typedef struct PriorityQueue {
    Element* arr;
    int capacity;
    int queueSize;
    compare lessFunc;
} PriorityQueue;

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

int countPartitions(int* nums, int numsSize, int k) {
    if (numsSize == 0) {
        return 0;
    }
    long long* dp = (long long*)malloc((numsSize + 1) * sizeof(long long));
    long long* prefix = (long long*)malloc((numsSize + 1) * sizeof(long long));
    long long mod = 1e9 + 7;
    PriorityQueue* minHeap = createPriorityQueue(less);
    PriorityQueue* maxHeap = createPriorityQueue(greater);
    HashItem* freq = NULL;

    dp[0] = 1;
    prefix[0] = 1;
    Element e;
    for (int i = 0, j = 0; i < numsSize; i++) {
        e.data[0] = nums[i];
        enQueue(minHeap, &e);
        enQueue(maxHeap, &e);
        hashSetItem(&freq, nums[i], hashGetItem(&freq, nums[i], 0) + 1);
        // adjust window
        while (j <= i &&
               (front(maxHeap)->data[0] - front(minHeap)->data[0]) > k) {
            hashSetItem(&freq, nums[j], hashGetItem(&freq, nums[j], 0) - 1);
            while (!isEmpty(minHeap) &&
                   hashGetItem(&freq, front(minHeap)->data[0], 0) == 0) {
                deQueue(minHeap);
            }
            while (!isEmpty(maxHeap) &&
                   hashGetItem(&freq, front(maxHeap)->data[0], 0) == 0) {
                deQueue(maxHeap);
            }
            j++;
        }
        if (j > 0) {
            dp[i + 1] = (prefix[i] - prefix[j - 1] + mod) % mod;
        } else {
            dp[i + 1] = prefix[i] % mod;
        }
        prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
    }

    int result = (int)dp[numsSize];
    free(dp);
    free(prefix);
    freeQueue(maxHeap);
    freeQueue(minHeap);
    hashFree(&freq);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        vector<long long> prefix(n + 1);
        multiset<int> cnt;
        dp[0] = 1;
        prefix[0] = 1;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            cnt.emplace(nums[i]);
            // adjust window
            while (j <= i && *cnt.rbegin() - *cnt.begin() > k) {
                cnt.erase(cnt.find(nums[j]));
                j++;
            }
            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }
        return dp[n];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CountPartitions(int[] nums, int k) {
        int n = nums.Length;
        long mod = 1_000_000_007L;
        long[] dp = new long[n + 1];
        long[] prefix = new long[n + 1];

        SortedSet<int> cnt = new SortedSet<int>();
        Dictionary<int, int> freq = new Dictionary<int, int>();
        dp[0] = 1;
        prefix[0] = 1;

        for (int i = 0, j = 0; i < n; i++) {
            int num = nums[i];
            cnt.Add(num);
            freq[num] = freq.GetValueOrDefault(num) + 1;
            // adjust window
            while (j <= i && cnt.Max - cnt.Min > k) {
                int key = nums[j];
                freq[key]--;
                if (freq[key] == 0) {
                    cnt.Remove(key);
                    freq.Remove(key);
                }
                j++;
            }

            dp[i + 1] =
                j > 0 ? (prefix[i] - prefix[j - 1] + mod) % mod : prefix[i];
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }

        return (int)dp[n];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
import (
	"github.com/emirpasic/gods/v2/trees/redblacktree"
)

func countPartitions(nums []int, k int) int {
	n := len(nums)
	mod := int64(1e9 + 7)
	dp := make([]int64, n+1)
	prefix := make([]int64, n+1)

	tree := redblacktree.NewWith[int, int](func(a, b int) int {
		if a < b {
			return -1
		} else if a > b {
			return 1
		}
		return 0
	})

	dp[0] = 1
	prefix[0] = 1

	for i, j := 0, 0; i < n; i++ {
		addTree(tree, nums[i])
		// adjust window
		for j <= i && tree.Right().Key-tree.Left().Key > k {
			removeTree(tree, nums[j])
			j++
		}
		if j > 0 {
			dp[i+1] = (prefix[i] - prefix[j-1] + mod) % mod
		} else {
			dp[i+1] = prefix[i] % mod
		}
		prefix[i+1] = (prefix[i] + dp[i+1]) % mod
	}

	return int(dp[n])
}

func addTree(tree *redblacktree.Tree[int, int], val int) {
	if count, found := tree.Get(val); found {
		tree.Put(val, count+1)
	} else {
		tree.Put(val, 1)
	}
}

func removeTree(tree *redblacktree.Tree[int, int], val int) {
	if count, found := tree.Get(val); found {
		if count > 1 {
			tree.Put(val, count-1)
		} else {
			tree.Remove(val)
		}
	}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countPartitions(int[] nums, int k) {
        int n = nums.length;
        long mod = (long) 1e9 + 7;
        long[] dp = new long[n + 1];
        long[] prefix = new long[n + 1];
        TreeMap<Integer, Integer> cnt = new TreeMap<>();

        dp[0] = 1;
        prefix[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            cnt.put(nums[i], cnt.getOrDefault(nums[i], 0) + 1);
            // adjust window
            while (j <= i && cnt.lastKey() - cnt.firstKey() > k) {
                cnt.put(nums[j], cnt.get(nums[j]) - 1);
                if (cnt.get(nums[j]) == 0) {
                    cnt.remove(nums[j]);
                }
                j++;
            }

            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }

        return (int) dp[n];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const { AvlTree } = require("datastructures-js");

var countPartitions = function (nums, k) {
    const n = nums.length;
    const mod = 1e9 + 7;
    const dp = new Array(n + 1).fill(0);
    const prefix = new Array(n + 1).fill(0);
    const cnt = new AvlTree();
    const freq = new Map();

    dp[0] = 1;
    prefix[0] = 1;

    for (let i = 0, j = 0; i < nums.length; i++) {
        const currentFreq = freq.get(nums[i]) || 0;
        freq.set(nums[i], currentFreq + 1);
        if (currentFreq === 0) {
            cnt.insert(nums[i]);
        }
        // adjust window
        while (j <= i && cnt.max().getValue() - cnt.min().getValue() > k) {
            const leftFreq = freq.get(nums[j]) || 0;
            freq.set(nums[j], leftFreq - 1);
            if (leftFreq === 1) {
                cnt.remove(nums[j]);
            }
            j++;
        }

        dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
        prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
    }
    return dp[n];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mod = 10**9 + 7
        dp = [0] * (n + 1)
        prefix = [0] * (n + 1)
        cnt = SortedList()

        dp[0] = 1
        prefix[0] = 1

        j = 0
        for i in range(n):
            cnt.add(nums[i])
            # adjust window
            while j <= i and cnt[-1] - cnt[0] > k:
                cnt.remove(nums[j])
                j += 1
            dp[i + 1] = (prefix[i] - (prefix[j - 1] if j > 0 else 0)) % mod
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod

        return dp[n]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
import { AvlTree } from "@datastructures-js/binary-search-tree";

function countPartitions(nums: number[], k: number): number {
    const n = nums.length;
    const mod = 1e9 + 7;
    const dp = new Array<number>(n + 1).fill(0);
    const prefix = new Array<number>(n + 1).fill(0);
    const cnt = new AvlTree<number>();
    const freq = new Map<number, number>();

    dp[0] = 1;
    prefix[0] = 1;
    for (let i = 0, j = 0; i < nums.length; i++) {
        const currentFreq: number = freq.get(nums[i]) || 0;
        freq.set(nums[i], currentFreq + 1);
        if (currentFreq === 0) {
            cnt.insert(nums[i]);
        }
        // adjust window
        while (j <= i && cnt.max().getValue() - cnt.min().getValue() > k) {
            const leftFreq: number = freq.get(nums[j]) || 0;
            freq.set(nums[j], leftFreq - 1);
            if (leftFreq === 1) {
                cnt.remove(nums[j]);
            }
            j++;
        }

        dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
        prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
    }

    return dp[n];
}
```

</details>

<br>

## Approach 2: Monotonic Queue Optimization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007LL

typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Deque;

Deque* createDeque(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(capacity * sizeof(int));
    dq->front = 0;
    dq->rear = -1;
    dq->capacity = capacity;
    return dq;
}

int isEmpty(Deque* dq) { return dq->rear < dq->front; }

void pushBack(Deque* dq, int value) {
    if (dq->rear < dq->capacity - 1) {
        dq->data[++dq->rear] = value;
    }
}

void popBack(Deque* dq) {
    if (!isEmpty(dq)) {
        dq->rear--;
    }
}

void popFront(Deque* dq) {
    if (!isEmpty(dq)) {
        dq->front++;
    }
}

int front(Deque* dq) { return isEmpty(dq) ? -1 : dq->data[dq->front]; }

int back(Deque* dq) { return isEmpty(dq) ? -1 : dq->data[dq->rear]; }

int countPartitions(int* nums, int numsSize, int k) {
    long long* dp = (long long*)malloc((numsSize + 1) * sizeof(long long));
    long long* prefix = (long long*)malloc((numsSize + 1) * sizeof(long long));
    Deque* minQ = createDeque(numsSize);
    Deque* maxQ = createDeque(numsSize);

    dp[0] = 1;
    prefix[0] = 1;
    int j = 0;

    for (int i = 0; i < numsSize; i++) {
        // maintain the maximum value queue
        while (!isEmpty(maxQ) && nums[back(maxQ)] <= nums[i]) {
            popBack(maxQ);
        }
        pushBack(maxQ, i);

        // maintain the minimum value queue
        while (!isEmpty(minQ) && nums[back(minQ)] >= nums[i]) {
            popBack(minQ);
        }
        pushBack(minQ, i);

        // adjust window
        while (!isEmpty(maxQ) && !isEmpty(minQ) &&
               nums[front(maxQ)] - nums[front(minQ)] > k) {
            if (front(maxQ) == j) {
                popFront(maxQ);
            }
            if (front(minQ) == j) {
                popFront(minQ);
            }
            j++;
        }

        if (j > 0) {
            dp[i + 1] = (prefix[i] - prefix[j - 1] + MOD) % MOD;
        } else {
            dp[i + 1] = prefix[i] % MOD;
        }
        prefix[i + 1] = (prefix[i] + dp[i + 1]) % MOD;
    }

    int result = (int)dp[numsSize];

    free(dp);
    free(prefix);
    free(minQ->data);
    free(minQ);
    free(maxQ->data);
    free(maxQ);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        vector<long long> prefix(n + 1);
        deque<int> minQ, maxQ;

        dp[0] = 1;
        prefix[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            // maintain the maximum value queue
            while (!maxQ.empty() && nums[maxQ.back()] <= nums[i]) {
                maxQ.pop_back();
            }
            maxQ.push_back(i);
            // maintain the minimum value queue
            while (!minQ.empty() && nums[minQ.back()] >= nums[i]) {
                minQ.pop_back();
            }
            minQ.push_back(i);
            // adjust window
            while (!maxQ.empty() && !minQ.empty() &&
                   nums[maxQ.front()] - nums[minQ.front()] > k) {
                if (maxQ.front() == j) {
                    maxQ.pop_front();
                }
                if (minQ.front() == j) {
                    minQ.pop_front();
                }
                j++;
            }

            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }

        return dp[n];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CountPartitions(int[] nums, int k) {
        int n = nums.Length;
        long mod = 1000000007L;
        long[] dp = new long[n + 1];
        long[] prefix = new long[n + 1];
        LinkedList<int> minQ = new LinkedList<int>();
        LinkedList<int> maxQ = new LinkedList<int>();

        dp[0] = 1;
        prefix[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            // maintain the maximum value queue
            while (maxQ.Count > 0 && nums[maxQ.Last.Value] <= nums[i]) {
                maxQ.RemoveLast();
            }
            maxQ.AddLast(i);
            // maintain the minimum value queue
            while (minQ.Count > 0 && nums[minQ.Last.Value] >= nums[i]) {
                minQ.RemoveLast();
            }
            minQ.AddLast(i);
            // adjust window
            while (maxQ.Count > 0 && minQ.Count > 0 &&
                   nums[maxQ.First.Value] - nums[minQ.First.Value] > k) {
                if (maxQ.First.Value == j) {
                    maxQ.RemoveFirst();
                }
                if (minQ.First.Value == j) {
                    minQ.RemoveFirst();
                }
                j++;
            }

            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }

        return (int)dp[n];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countPartitions(nums []int, k int) int {
	n := len(nums)
	mod := int64(1e9 + 7)
	dp := make([]int64, n+1)
	prefix := make([]int64, n+1)
	minQ := make([]int, 0)
	maxQ := make([]int, 0)

	dp[0] = 1
	prefix[0] = 1

	for i, j := 0, 0; i < n; i++ {
		// maintain the maximum value queue
		for len(maxQ) > 0 && nums[maxQ[len(maxQ)-1]] <= nums[i] {
			maxQ = maxQ[:len(maxQ)-1]
		}
		maxQ = append(maxQ, i)
		// maintain the minimum value queue
		for len(minQ) > 0 && nums[minQ[len(minQ)-1]] >= nums[i] {
			minQ = minQ[:len(minQ)-1]
		}
		minQ = append(minQ, i)

		// adjust window
		for len(maxQ) > 0 && len(minQ) > 0 &&
			nums[maxQ[0]]-nums[minQ[0]] > k {
			if maxQ[0] == j {
				maxQ = maxQ[1:]
			}
			if minQ[0] == j {
				minQ = minQ[1:]
			}
			j++
		}

		if j > 0 {
			dp[i+1] = (prefix[i] - prefix[j-1] + mod) % mod
		} else {
			dp[i+1] = prefix[i] % mod
		}
		prefix[i+1] = (prefix[i] + dp[i+1]) % mod
	}

	return int(dp[n])
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countPartitions(int[] nums, int k) {
        int n = nums.length;
        long mod = (long) 1e9 + 7;
        long[] dp = new long[n + 1];
        long[] prefix = new long[n + 1];
        Deque<Integer> minQ = new LinkedList<>();
        Deque<Integer> maxQ = new LinkedList<>();

        dp[0] = 1;
        prefix[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            // maintain the maximum value queue
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] <= nums[i]) {
                maxQ.pollLast();
            }
            maxQ.offerLast(i);
            // maintain the minimum value queue
            while (!minQ.isEmpty() && nums[minQ.peekLast()] >= nums[i]) {
                minQ.pollLast();
            }
            minQ.offerLast(i);
            // adjust window
            while (
                !maxQ.isEmpty() &&
                !minQ.isEmpty() &&
                nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] > k
            ) {
                if (maxQ.peekFirst() == j) {
                    maxQ.pollFirst();
                }
                if (minQ.peekFirst() == j) {
                    minQ.pollFirst();
                }
                j++;
            }

            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }

        return (int) dp[n];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countPartitions = function (nums, k) {
    const n = nums.length;
    const mod = 1e9 + 7;
    const dp = new Array(n + 1).fill(0);
    const prefix = new Array(n + 1).fill(0);
    const minQ = [];
    const maxQ = [];

    dp[0] = 1;
    prefix[0] = 1;

    for (let i = 0, j = 0; i < n; i++) {
        // maintain the maximum value queue
        while (maxQ.length > 0 && nums[maxQ[maxQ.length - 1]] <= nums[i]) {
            maxQ.pop();
        }
        maxQ.push(i);
        // maintain the minimum value queue
        while (minQ.length > 0 && nums[minQ[minQ.length - 1]] >= nums[i]) {
            minQ.pop();
        }
        minQ.push(i);

        // adjust window
        while (
            maxQ.length > 0 &&
            minQ.length > 0 &&
            nums[maxQ[0]] - nums[minQ[0]] > k
        ) {
            if (maxQ[0] === j) {
                maxQ.shift();
            }
            if (minQ[0] === j) {
                minQ.shift();
            }
            j++;
        }

        const val = j > 0 ? prefix[j - 1] : 0;
        dp[i + 1] = (prefix[i] - val + mod) % mod;
        prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
    }

    return dp[n];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mod = 10**9 + 7
        dp = [0] * (n + 1)
        prefix = [0] * (n + 1)
        min_q = deque()
        max_q = deque()

        dp[0] = 1
        prefix[0] = 1
        j = 0

        for i in range(n):
            # maintain the maximum value queue
            while max_q and nums[max_q[-1]] <= nums[i]:
                max_q.pop()
            max_q.append(i)

            # maintain the minimum value queue
            while min_q and nums[min_q[-1]] >= nums[i]:
                min_q.pop()
            min_q.append(i)

            # adjust window
            while max_q and min_q and nums[max_q[0]] - nums[min_q[0]] > k:
                if max_q[0] == j:
                    max_q.popleft()
                if min_q[0] == j:
                    min_q.popleft()
                j += 1

            if j > 0:
                dp[i + 1] = (prefix[i] - prefix[j - 1] + mod) % mod
            else:
                dp[i + 1] = prefix[i] % mod
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod

        return dp[n]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countPartitions(nums: number[], k: number): number {
    const n = nums.length;
    const mod = 1e9 + 7;
    const dp = new Array<number>(n + 1).fill(0);
    const prefix = new Array<number>(n + 1).fill(0);
    const minQ: number[] = [];
    const maxQ: number[] = [];

    dp[0] = 1;
    prefix[0] = 1;

    for (let i = 0, j = 0; i < n; i++) {
        // maintain the maximum value queue
        while (maxQ.length > 0 && nums[maxQ.at(-1)!] <= nums[i]) {
            maxQ.pop();
        }
        maxQ.push(i);

        // maintain the minimum value queue
        while (minQ.length > 0 && nums[minQ.at(-1)!] >= nums[i]) {
            minQ.pop();
        }
        minQ.push(i);

        // adjust window
        while (
            maxQ.length > 0 &&
            minQ.length > 0 &&
            nums[maxQ[0]] - nums[minQ[0]] > k
        ) {
            if (maxQ[0] === j) {
                maxQ.shift();
            }
            if (minQ[0] === j) {
                minQ.shift();
            }
            j++;
        }

        dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
        prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
    }

    return dp[n];
}
```

</details>
