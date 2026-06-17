# 3629. Minimum Jumps to Reach End via Prime Teleportation

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/)  
`Array` `Hash Table` `Math` `Breadth-First Search` `Number Theory`

**Problem Link:** [LeetCode 3629 - Minimum Jumps to Reach End via Prime Teleportation](https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/)

## Problem

You are given an integer array nums of length n.

You start at index 0, and your goal is to reach index n - 1.

From any index i, you may perform one of the following operations:

- Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
- Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.

Return the minimum number of jumps required to reach index n - 1.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n == nums.length <= 105
- 1 <= nums[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3629. Minimum Jumps to Reach End via Prime Teleportation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Reversed Breadth-First Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Forward Breadth-First Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Reversed Breadth-First Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MX 1000001

// dynamic array structure, simulating vector<int>
typedef struct {
    int* data;
    int size;
    int cap;
} Vector;

void vector_push(Vector* v, int val) {
    if (v->size == v->cap) {
        v->cap = v->cap == 0 ? 2 : v->cap * 2;
        v->data = (int*)realloc(v->data, v->cap * sizeof(int));
    }
    v->data[v->size++] = val;
}

// simple hash table node for edges
typedef struct Node {
    int key;
    Vector values;
    struct Node* next;
} Node;

#define HASH_SIZE 10007
Node* hash_table[HASH_SIZE];

void hash_push(int key, int val) {
    int h = abs(key) % HASH_SIZE;
    Node* cur = hash_table[h];
    while (cur) {
        if (cur->key == key) {
            vector_push(&cur->values, val);
            return;
        }
        cur = cur->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    memset(&new_node->values, 0, sizeof(Vector));
    vector_push(&new_node->values, val);
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
}

Vector* hash_get(int key) {
    int h = abs(key) % HASH_SIZE;
    Node* cur = hash_table[h];
    while (cur) {
        if (cur->key == key) return &cur->values;
        cur = cur->next;
    }
    return NULL;
}

// global prime factor table
Vector factors[MX];
bool precomputed = false;

void precompute() {
    if (precomputed) return;
    for (int i = 2; i < MX; i++) {
        if (factors[i].size == 0) {
            for (int j = i; j < MX; j += i) {
                vector_push(&factors[j], i);
            }
        }
    }
    precomputed = true;
}

void clear_hash() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* cur = hash_table[i];
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            free(tmp->values.data);
            free(tmp);
        }
        hash_table[i] = NULL;
    }
}

int minJumps(int* nums, int numsSize) {
    precompute();
    clear_hash();
    int n = numsSize;

    for (int i = 0; i < n; i++) {
        int a = nums[i];
        if (factors[a].size == 1) {
            hash_push(a, i);
        }
    }

    bool* seen = (bool*)calloc(n, sizeof(bool));
    int* q = (int*)malloc(n * sizeof(int));
    int q_start = 0, q_end = 0;

    seen[n - 1] = true;
    q[q_end++] = n - 1;

    int res = 0;
    while (q_start < q_end) {
        int level_size = q_end - q_start;
        for (int k = 0; k < level_size; k++) {
            int i = q[q_start++];
            if (i == 0) {
                free(seen);
                free(q);
                return res;
            }

            // adjacent movement
            if (i > 0 && !seen[i - 1]) {
                seen[i - 1] = true;
                q[q_end++] = i - 1;
            }
            if (i < n - 1 && !seen[i + 1]) {
                seen[i + 1] = true;
                q[q_end++] = i + 1;
            }

            // prime factor jump
            for (int p_idx = 0; p_idx < factors[nums[i]].size; p_idx++) {
                int p = factors[nums[i]].data[p_idx];
                Vector* v = hash_get(p);
                if (v) {
                    for (int j_idx = 0; j_idx < v->size; j_idx++) {
                        int j = v->data[j_idx];
                        if (!seen[j]) {
                            seen[j] = true;
                            q[q_end++] = j;
                        }
                    }
                    v->size = 0;  // edges[p].clear()
                }
            }
        }
        res++;
    }
    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
const int MX = 1000001;
vector<int> factors[MX];
bool initialized = []() {
    for (int i = 2; i < MX; ++i) {
        if (factors[i].empty()) {
            for (int j = i; j < MX; j += i) {
                factors[j].push_back(i);
            }
        }
    }
    return true;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            if (factors[a].size() == 1) {
                edges[a].push_back(i);
            }
        }
        int res = 0;
        vector<bool> seen(n, false);
        seen[n - 1] = true;
        vector<int> q = {n - 1};
        while (true) {
            vector<int> q2;
            for (int i : q) {
                if (i == 0) return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.push_back(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.push_back(i + 1);
                }
                for (int p : factors[nums[i]]) {
                    if (edges.count(p)) {
                        for (int j : edges[p]) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.push_back(j);
                            }
                        }
                        edges[p].clear();
                    }
                }
            }
            q = move(q2);
            res++;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private static readonly int MX = 1000001;
    private static readonly List<int>[] factors = new List<int>[MX];

    static Solution() {
        for (int i = 0; i < MX; i++) factors[i] = new List<int>();
        for (int i = 2; i < MX; i++) {
            if (factors[i].Count == 0) {
                for (int j = i; j < MX; j += i) factors[j].Add(i);
            }
        }
    }

    public int MinJumps(int[] nums) {
        int n = nums.Length;
        var edges = new Dictionary<int, List<int>>();
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            if (factors[a].Count == 1) {
                if (!edges.ContainsKey(a))
                    edges[a] = new List<int>();
                edges[a].Add(i);
            }
        }
        int res = 0;
        bool[] seen = new bool[n];
        seen[n - 1] = true;
        List<int> q = new List<int> { n - 1 };
        while (true) {
            List<int> q2 = new List<int>();
            foreach (int i in q) {
                if (i == 0)
                    return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.Add(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.Add(i + 1);
                }
                foreach (int p in factors[nums[i]]) {
                    if (edges.TryGetValue(p, out var list)) {
                        foreach (int j in list) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.Add(j);
                            }
                        }
                        list.Clear();
                    }
                }
            }
            q = q2;
            res++;
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const MX = 1000001

var factors [MX][]int

func init() {
	for i := 2; i < MX; i++ {
		if len(factors[i]) == 0 {
			for j := i; j < MX; j += i {
				factors[j] = append(factors[j], i)
			}
		}
	}
}

func minJumps(nums []int) int {
	n := len(nums)
	edges := make(map[int][]int)
	for i, a := range nums {
		if len(factors[a]) == 1 {
			edges[a] = append(edges[a], i)
		}
	}
	res := 0
	seen := make([]bool, n)
	seen[n-1] = true
	q := []int{n - 1}
	for {
		var q2 []int
		for _, i := range q {
			if i == 0 {
				return res
			}
			if i > 0 && !seen[i-1] {
				seen[i-1] = true
				q2 = append(q2, i-1)
			}
			if i < n-1 && !seen[i+1] {
				seen[i+1] = true
				q2 = append(q2, i+1)
			}
			for _, p := range factors[nums[i]] {
				if list, ok := edges[p]; ok {
					for _, j := range list {
						if !seen[j] {
							seen[j] = true
							q2 = append(q2, j)
						}
					}
					delete(edges, p)
				}
			}
		}
		q = q2
		res++
	}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MX = 1000001;
    private static final List<Integer>[] factors = new ArrayList[MX];

    static {
        for (int i = 0; i < MX; i++) factors[i] = new ArrayList<>();
        for (int i = 2; i < MX; i++) {
            if (factors[i].isEmpty()) {
                for (int j = i; j < MX; j += i) factors[j].add(i);
            }
        }
    }

    public int minJumps(int[] nums) {
        int n = nums.length;
        Map<Integer, List<Integer>> edges = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            if (factors[a].size() == 1) {
                edges.computeIfAbsent(a, k -> new ArrayList<>()).add(i);
            }
        }
        int res = 0;
        boolean[] seen = new boolean[n];
        seen[n - 1] = true;
        List<Integer> q = new ArrayList<>();
        q.add(n - 1);
        while (true) {
            List<Integer> q2 = new ArrayList<>();
            for (int i : q) {
                if (i == 0) return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.add(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.add(i + 1);
                }
                for (int p : factors[nums[i]]) {
                    if (edges.containsKey(p)) {
                        for (int j : edges.get(p)) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.add(j);
                            }
                        }
                        edges.get(p).clear();
                    }
                }
            }
            q = q2;
            res++;
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MX = 1000001;
const factors = Array.from({ length: MX }, () => []);
for (let i = 2; i < MX; i++) {
    if (factors[i].length === 0) {
        for (let j = i; j < MX; j += i) {
            factors[j].push(i);
        }
    }
}

var minJumps = function (nums) {
    const n = nums.length;
    const edges = new Map();
    for (let i = 0; i < n; i++) {
        const a = nums[i];
        if (factors[a].length === 1) {
            if (!edges.has(a)) edges.set(a, []);
            edges.get(a).push(i);
        }
    }
    let res = 0;
    const seen = new Array(n).fill(false);
    seen[n - 1] = true;
    let q = [n - 1];
    while (true) {
        let q2 = [];
        for (const i of q) {
            if (i === 0) return res;
            if (i > 0 && !seen[i - 1]) {
                seen[i - 1] = true;
                q2.push(i - 1);
            }
            if (i < n - 1 && !seen[i + 1]) {
                seen[i + 1] = true;
                q2.push(i + 1);
            }
            for (const p of factors[nums[i]]) {
                const list = edges.get(p);
                if (list) {
                    for (const j of list) {
                        if (!seen[j]) {
                            seen[j] = true;
                            q2.push(j);
                        }
                    }
                    edges.set(p, []);
                }
            }
        }
        q = q2;
        res++;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
MX = 1_000_001
factors = [[] for _ in range(MX)]
for i in range(2, MX):
    if not factors[i]:
        for j in range(i, MX, i):
            factors[j].append(i)


class Solution:
    def minJumps(self, nums: List[int]) -> int:
        n = len(nums)
        edges = defaultdict(list)
        for i, a in enumerate(nums):
            if len(factors[a]) == 1:
                edges[a].append(i)
        res = 0
        seen = [False] * n
        seen[-1] = True
        q = [n - 1]
        while True:
            q2 = []
            for i in q:
                if i == 0:
                    return res
                if i > 0 and not seen[i - 1]:
                    seen[i - 1] = True
                    q2.append(i - 1)
                if i < n - 1 and not seen[i + 1]:
                    seen[i + 1] = True
                    q2.append(i + 1)
                for p in factors[nums[i]]:
                    for j in edges[p]:
                        if not seen[j]:
                            seen[j] = True
                            q2.append(j)
                    edges[p].clear()
            q = q2
            res += 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MX = 1000001;
const factors = Array.from({ length: MX }, () => []);
for (let i = 2; i < MX; i++) {
    if (factors[i].length === 0) {
        for (let j = i; j < MX; j += i) {
            factors[j].push(i);
        }
    }
}

function minJumps(nums: number[]): number {
    const n = nums.length;
    const edges = new Map();
    for (let i = 0; i < n; i++) {
        const a = nums[i];
        if (factors[a].length === 1) {
            if (!edges.has(a)) edges.set(a, []);
            edges.get(a).push(i);
        }
    }
    let res = 0;
    const seen = new Array(n).fill(false);
    seen[n - 1] = true;
    let q = [n - 1];
    while (true) {
        let q2 = [];
        for (const i of q) {
            if (i === 0) return res;
            if (i > 0 && !seen[i - 1]) {
                seen[i - 1] = true;
                q2.push(i - 1);
            }
            if (i < n - 1 && !seen[i + 1]) {
                seen[i + 1] = true;
                q2.push(i + 1);
            }
            for (const p of factors[nums[i]]) {
                const list = edges.get(p);
                if (list) {
                    for (const j of list) {
                        if (!seen[j]) {
                            seen[j] = true;
                            q2.push(j);
                        }
                    }
                    edges.set(p, []);
                }
            }
        }
        q = q2;
        res++;
    }
}
```

</details>

<br>

## Approach 2: Forward Breadth-First Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MX 1000001

// dynamic array structure, simulating vector<int>
typedef struct {
    int* data;
    int size;
    int cap;
} Vector;

void vector_push(Vector* v, int val) {
    if (v->size == v->cap) {
        v->cap = v->cap == 0 ? 2 : v->cap * 2;
        v->data = (int*)realloc(v->data, v->cap * sizeof(int));
    }
    v->data[v->size++] = val;
}

// simple hash table node for edges
typedef struct Node {
    int key;
    Vector values;
    struct Node* next;
} Node;

#define HASH_SIZE 10007
Node* hash_table[HASH_SIZE];

void hash_push(int key, int val) {
    int h = abs(key) % HASH_SIZE;
    Node* cur = hash_table[h];
    while (cur) {
        if (cur->key == key) {
            vector_push(&cur->values, val);
            return;
        }
        cur = cur->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    memset(&new_node->values, 0, sizeof(Vector));
    vector_push(&new_node->values, val);
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
}

Vector* hash_get(int key) {
    int h = abs(key) % HASH_SIZE;
    Node* cur = hash_table[h];
    while (cur) {
        if (cur->key == key) return &cur->values;
        cur = cur->next;
    }
    return NULL;
}

// global prime factor table
Vector factors[MX];
bool precomputed = false;

void precompute() {
    if (precomputed) return;
    for (int i = 2; i < MX; i++) {
        if (factors[i].size == 0) {
            for (int j = i; j < MX; j += i) {
                vector_push(&factors[j], i);
            }
        }
    }
    precomputed = true;
}

void clear_hash() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* cur = hash_table[i];
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            free(tmp->values.data);
            free(tmp);
        }
        hash_table[i] = NULL;
    }
}

int minJumps(int* nums, int numsSize) {
    precompute();
    clear_hash();
    int n = numsSize;

    for (int i = 0; i < n; i++) {
        for (int p_idx = 0; p_idx < factors[nums[i]].size; p_idx++) {
            hash_push(factors[nums[i]].data[p_idx], i);
        }
    }

    bool* seen = (bool*)calloc(n, sizeof(bool));
    int* q = (int*)malloc(n * sizeof(int));
    int q_start = 0, q_end = 0;

    seen[0] = true;
    q[q_end++] = 0;

    int res = 0;
    while (q_start < q_end) {
        int level_size = q_end - q_start;
        for (int k = 0; k < level_size; k++) {
            int i = q[q_start++];
            if (i == n - 1) {
                free(seen);
                free(q);
                return res;
            }

            // adjacent movement
            if (i > 0 && !seen[i - 1]) {
                seen[i - 1] = true;
                q[q_end++] = i - 1;
            }
            if (i < n - 1 && !seen[i + 1]) {
                seen[i + 1] = true;
                q[q_end++] = i + 1;
            }

            // jump trigger: only when len(factors[nums[i]]) == 1
            if (factors[nums[i]].size == 1) {
                int p = nums[i];
                Vector* v = hash_get(p);
                if (v) {
                    for (int j_idx = 0; j_idx < v->size; j_idx++) {
                        int j = v->data[j_idx];
                        if (!seen[j]) {
                            seen[j] = true;
                            q[q_end++] = j;
                        }
                    }
                    v->size = 0;  // edges[p].clear()
                }
            }
        }
        res++;
    }
    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
const int MX = 1000001;
vector<int> factors[MX];
bool initialized = []() {
    for (int i = 2; i < MX; ++i) {
        if (factors[i].empty()) {
            for (int j = i; j < MX; j += i) {
                factors[j].push_back(i);
            }
        }
    }
    return true;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            for (int p : factors[nums[i]]) {
                edges[p].push_back(i);
            }
        }
        int res = 0;
        vector<bool> seen(n, false);
        seen[0] = true;
        vector<int> q = {0};
        while (true) {
            vector<int> q2;
            for (int i : q) {
                if (i == n - 1) return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.push_back(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.push_back(i + 1);
                }
                if (factors[nums[i]].size() == 1) {
                    int p = nums[i];
                    if (edges.count(p)) {
                        for (int j : edges[p]) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.push_back(j);
                            }
                        }
                        edges[p].clear();
                    }
                }
            }
            q = move(q2);
            res++;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private static readonly int MX = 1000001;
    private static readonly List<int>[] factors = new List<int>[MX];

    static Solution() {
        for (int i = 0; i < MX; i++) factors[i] = new List<int>();
        for (int i = 2; i < MX; i++) {
            if (factors[i].Count == 0) {
                for (int j = i; j < MX; j += i) factors[j].Add(i);
            }
        }
    }

    public int MinJumps(int[] nums) {
        int n = nums.Length;
        var edges = new Dictionary<int, List<int>>();
        for (int i = 0; i < n; i++) {
            foreach (int p in factors[nums[i]]) {
                if (!edges.ContainsKey(p))
                    edges[p] = new List<int>();
                edges[p].Add(i);
            }
        }
        int res = 0;
        bool[] seen = new bool[n];
        seen[0] = true;
        List<int> q = new List<int> { 0 };
        while (true) {
            List<int> q2 = new List<int>();
            foreach (int i in q) {
                if (i == n - 1)
                    return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.Add(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.Add(i + 1);
                }
                if (factors[nums[i]].Count == 1) {
                    int p = nums[i];
                    if (edges.TryGetValue(p, out var list)) {
                        foreach (int j in list) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.Add(j);
                            }
                        }
                        list.Clear();
                    }
                }
            }
            q = q2;
            res++;
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const MX = 1000001

var factors [MX][]int

func init() {
	for i := 2; i < MX; i++ {
		if len(factors[i]) == 0 {
			for j := i; j < MX; j += i {
				factors[j] = append(factors[j], i)
			}
		}
	}
}

func minJumps(nums []int) int {
	n := len(nums)
	edges := make(map[int][]int)
	for i, a := range nums {
		for _, p := range factors[a] {
			edges[p] = append(edges[p], i)
		}
	}
	res := 0
	seen := make([]bool, n)
	seen[0] = true
	q := []int{0}
	for {
		var q2 []int
		for _, i := range q {
			if i == n-1 {
				return res
			}
			if i > 0 && !seen[i-1] {
				seen[i-1] = true
				q2 = append(q2, i-1)
			}
			if i < n-1 && !seen[i+1] {
				seen[i+1] = true
				q2 = append(q2, i+1)
			}
			if len(factors[nums[i]]) == 1 {
				p := nums[i]
				if list, ok := edges[p]; ok {
					for _, j := range list {
						if !seen[j] {
							seen[j] = true
							q2 = append(q2, j)
						}
					}
					delete(edges, p)
				}
			}
		}
		q = q2
		res++
	}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MX = 1000001;
    private static final List<Integer>[] factors = new ArrayList[MX];

    static {
        for (int i = 0; i < MX; i++) factors[i] = new ArrayList<>();
        for (int i = 2; i < MX; i++) {
            if (factors[i].isEmpty()) {
                for (int j = i; j < MX; j += i) factors[j].add(i);
            }
        }
    }

    public int minJumps(int[] nums) {
        int n = nums.length;
        Map<Integer, List<Integer>> edges = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int p : factors[nums[i]]) {
                edges.computeIfAbsent(p, k -> new ArrayList<>()).add(i);
            }
        }
        int res = 0;
        boolean[] seen = new boolean[n];
        seen[0] = true;
        List<Integer> q = new ArrayList<>();
        q.add(0);
        while (true) {
            List<Integer> q2 = new ArrayList<>();
            for (int i : q) {
                if (i == n - 1) return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.add(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.add(i + 1);
                }
                if (factors[nums[i]].size() == 1) {
                    int p = nums[i];
                    if (edges.containsKey(p)) {
                        for (int j : edges.get(p)) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.add(j);
                            }
                        }
                        edges.get(p).clear();
                    }
                }
            }
            q = q2;
            res++;
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MX = 1000001;
const factors = Array.from({ length: MX }, () => []);
for (let i = 2; i < MX; i++) {
    if (factors[i].length === 0) {
        for (let j = i; j < MX; j += i) {
            factors[j].push(i);
        }
    }
}

var minJumps = function (nums) {
    const n = nums.length;
    const edges = new Map();
    for (let i = 0; i < n; i++) {
        for (const p of factors[nums[i]]) {
            if (!edges.has(p)) edges.set(p, []);
            edges.get(p).push(i);
        }
    }
    let res = 0;
    const seen = new Array(n).fill(false);
    seen[0] = true;
    let q = [0];
    while (true) {
        let q2 = [];
        for (const i of q) {
            if (i === n - 1) return res;
            if (i > 0 && !seen[i - 1]) {
                seen[i - 1] = true;
                q2.push(i - 1);
            }
            if (i < n - 1 && !seen[i + 1]) {
                seen[i + 1] = true;
                q2.push(i + 1);
            }
            if (factors[nums[i]].length === 1) {
                const p = nums[i];
                const list = edges.get(p);
                if (list) {
                    for (const j of list) {
                        if (!seen[j]) {
                            seen[j] = true;
                            q2.push(j);
                        }
                    }
                    edges.set(p, []);
                }
            }
        }
        q = q2;
        res++;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
MX = 1_000_001
factors = [[] for _ in range(MX)]
for i in range(2, MX):
    if not factors[i]:
        for j in range(i, MX, i):
            factors[j].append(i)


class Solution:
    def minJumps(self, nums: List[int]) -> int:
        n = len(nums)
        edges = defaultdict(list)
        for i, a in enumerate(nums):
            for p in factors[a]:
                edges[p].append(i)
        res = 0
        seen = [False] * n
        seen[0] = True
        q = [0]
        while True:
            q2 = []
            for i in q:
                if i == n - 1:
                    return res
                if i > 0 and not seen[i - 1]:
                    seen[i - 1] = True
                    q2.append(i - 1)
                if i < n - 1 and not seen[i + 1]:
                    seen[i + 1] = True
                    q2.append(i + 1)
                if len(factors[nums[i]]) == 1:
                    p = nums[i]
                    for j in edges[p]:
                        if not seen[j]:
                            seen[j] = True
                            q2.append(j)
                    edges[p].clear()
            q = q2
            res += 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MX = 1000001;
const factors = Array.from({ length: MX }, () => []);
for (let i = 2; i < MX; i++) {
    if (factors[i].length === 0) {
        for (let j = i; j < MX; j += i) {
            factors[j].push(i);
        }
    }
}

function minJumps(nums: number[]): number {
    const n = nums.length;
    const edges = new Map();
    for (let i = 0; i < n; i++) {
        for (const p of factors[nums[i]]) {
            if (!edges.has(p)) edges.set(p, []);
            edges.get(p).push(i);
        }
    }
    let res = 0;
    const seen = new Array(n).fill(false);
    seen[0] = true;
    let q = [0];
    while (true) {
        let q2 = [];
        for (const i of q) {
            if (i === n - 1) return res;
            if (i > 0 && !seen[i - 1]) {
                seen[i - 1] = true;
                q2.push(i - 1);
            }
            if (i < n - 1 && !seen[i + 1]) {
                seen[i + 1] = true;
                q2.push(i + 1);
            }
            if (factors[nums[i]].length === 1) {
                const p = nums[i];
                const list = edges.get(p);
                if (list) {
                    for (const j of list) {
                        if (!seen[j]) {
                            seen[j] = true;
                            q2.push(j);
                        }
                    }
                    edges.set(p, []);
                }
            }
        }
        q = q2;
        res++;
    }
}
```

</details>
