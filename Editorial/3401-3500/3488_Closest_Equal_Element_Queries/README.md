# 3488. Closest Equal Element Queries

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/closest-equal-element-queries/)  
`Array` `Hash Table` `Binary Search`

**Problem Link:** [LeetCode 3488 - Closest Equal Element Queries](https://leetcode.com/problems/closest-equal-element-queries/)

## Problem

You are given a circular array nums and an array queries.

For each query i, you have to find the following:

- The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.

Return an array answer of the same size as queries, where answer[i] represents the result for query i.

### Example 1

### Example 2

## Constraints

- 1 <= queries.length <= nums.length <= 105
- 1 <= nums[i] <= 106
- 0 <= queries[i] < nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3488. Closest Equal Element Queries

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Table + Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Preprocessing Nearest Left and Right Positions + Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Hash Table + Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int* pos;
    int size;
    int capacity;
    UT_hash_handle hh;
} PosEntry;

PosEntry* findOrCreate(PosEntry** map, int key) {
    PosEntry* entry = NULL;
    HASH_FIND_INT(*map, &key, entry);
    if (entry == NULL) {
        entry = (PosEntry*)malloc(sizeof(PosEntry));
        entry->key = key;
        entry->pos = (int*)malloc(16 * sizeof(int));
        entry->size = 0;
        entry->capacity = 16;
        HASH_ADD_INT(*map, key, entry);
    }
    return entry;
}

void addPos(PosEntry* entry, int val) {
    if (entry->size >= entry->capacity) {
        entry->capacity *= 2;
        entry->pos = (int*)realloc(entry->pos, entry->capacity * sizeof(int));
    }
    entry->pos[entry->size++] = val;
}

void insertFront(PosEntry* entry, int val) {
    if (entry->size >= entry->capacity) {
        entry->capacity *= 2;
        entry->pos = (int*)realloc(entry->pos, entry->capacity * sizeof(int));
    }
    memmove(entry->pos + 1, entry->pos, entry->size * sizeof(int));
    entry->pos[0] = val;
    entry->size++;
}

int lowerBound(int* arr, int size, int target) {
    int lo = 0, hi = size;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int minInt(int a, int b) { return a < b ? a : b; }

int* solveQueries(int* nums, int numsSize, int* queries, int queriesSize,
                  int* returnSize) {
    int n = numsSize;
    PosEntry* map = NULL;

    for (int i = 0; i < n; i++) {
        PosEntry* entry = findOrCreate(&map, nums[i]);
        addPos(entry, i);
    }

    PosEntry *entry, *tmp;
    HASH_ITER(hh, map, entry, tmp) {
        int x = entry->pos[0];
        int last = entry->pos[entry->size - 1];
        insertFront(entry, last - n);
        addPos(entry, x + n);
    }

    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int q = queries[i];
        int x = nums[q];
        PosEntry* entry = findOrCreate(&map, x);

        if (entry->size == 3) {
            result[i] = -1;
            continue;
        }

        int idx = lowerBound(entry->pos, entry->size, q);
        result[i] = minInt(entry->pos[idx + 1] - entry->pos[idx],
                           entry->pos[idx] - entry->pos[idx - 1]);
    }

    HASH_ITER(hh, map, entry, tmp) {
        free(entry->pos);
        HASH_DEL(map, entry);
        free(entry);
    }

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> numsPos;
        for (int i = 0; i < n; i++) {
            numsPos[nums[i]].push_back(i);
        }
        for (auto& [_, pos] : numsPos) {
            int x = pos[0];
            pos.insert(pos.begin(), pos.back() - n);
            pos.push_back(x + n);
        }
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            int x = nums[queries[i]];
            if (numsPos[x].size() == 3) {
                queries[i] = -1;
                continue;
            }
            int pos =
                lower_bound(numsPos[x].begin(), numsPos[x].end(), queries[i]) -
                numsPos[x].begin();
            queries[i] = min(numsPos[x][pos + 1] - numsPos[x][pos],
                             numsPos[x][pos] - numsPos[x][pos - 1]);
        }
        return queries;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] SolveQueries(int[] nums, int[] queries) {
        int n = nums.Length;
        Dictionary<int, List<int>> numsPos = new Dictionary<int, List<int>>();

        for (int i = 0; i < n; i++) {
            if (!numsPos.ContainsKey(nums[i])) {
                numsPos[nums[i]] = new List<int>();
            }
            numsPos[nums[i]].Add(i);
        }

        foreach (var pos in numsPos.Values.ToList()) {
            int x = pos[0];
            pos.Insert(0, pos[pos.Count - 1] - n);
            pos.Add(x + n);
        }

        for (int i = 0; i < queries.Length; i++) {
            int x = nums[queries[i]];
            List<int> posList = numsPos[x];
            if (posList.Count == 3) {
                queries[i] = -1;
                continue;
            }
            int pos = posList.BinarySearch(queries[i]);
            if (pos < 0) {
                pos = ~pos;
            }
            queries[i] = Math.Min(posList[pos + 1] - posList[pos],
                                  posList[pos] - posList[pos - 1]);
        }

        return queries;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func solveQueries(nums []int, queries []int) []int {
    n := len(nums)
    numsPos := make(map[int][]int)

    for i := 0; i < n; i++ {
        numsPos[nums[i]] = append(numsPos[nums[i]], i)
    }

    for k, pos := range numsPos {
        x := pos[0]
        pos = append([]int{pos[len(pos)-1] - n}, pos...)
        pos = append(pos, x+n)
        numsPos[k] = pos
    }

    for i := 0; i < len(queries); i++ {
        x := nums[queries[i]]
        posList := numsPos[x]
        if (len(posList) == 3) {
            queries[i] = -1
            continue
        }
        pos := sort.SearchInts(posList, queries[i])
        queries[i] = min(posList[pos+1]-posList[pos], posList[pos]-posList[pos-1])
    }

    return queries
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> solveQueries(int[] nums, int[] queries) {
        int n = nums.length;
        HashMap<Integer, ArrayList<Integer>> numsPos = new HashMap<>();
        for (int i = 0; i < n; i++) {
            numsPos.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        for (ArrayList<Integer> pos : numsPos.values()) {
            int x = pos.get(0);
            int last = pos.get(pos.size() - 1);
            pos.add(0, last - n);
            pos.add(x + n);
        }
        List<Integer> result = new ArrayList<>();
        for (int q : queries) {
            int x = nums[q];
            ArrayList<Integer> posList = numsPos.get(x);

            if (posList.size() == 3) {
                result.add(-1);
                continue;
            }

            int idx = Collections.binarySearch(posList, q);
            if (idx < 0) idx = -idx - 1;

            int dist = Math.min(
                posList.get(idx + 1) - posList.get(idx),
                posList.get(idx) - posList.get(idx - 1)
            );
            result.add(dist);
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function solveQueries(nums, queries) {
    const n = nums.length;
    const numsPos = new Map();

    for (let i = 0; i < n; i++) {
        if (!numsPos.has(nums[i])) {
            numsPos.set(nums[i], []);
        }
        numsPos.get(nums[i]).push(i);
    }

    for (const [key, pos] of numsPos) {
        const x = pos[0];
        pos.unshift(pos[pos.length - 1] - n);
        pos.push(x + n);
    }

    for (let i = 0; i < queries.length; i++) {
        const x = nums[queries[i]];
        const posList = numsPos.get(x);
        if (posList.length === 3) {
            queries[i] = -1;
            continue;
        }
        const pos = binarySearch(posList, queries[i]);
        queries[i] = Math.min(
            posList[pos + 1] - posList[pos],
            posList[pos] - posList[pos - 1],
        );
    }

    return queries;
}

function binarySearch(arr, target) {
    let left = 0,
        right = arr.length;
    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        nums_pos = defaultdict(list)

        for i in range(n):
            nums_pos[nums[i]].append(i)

        for pos in nums_pos.values():
            x = pos[0]
            pos.insert(0, pos[-1] - n)
            pos.append(x + n)

        for i in range(len(queries)):
            x = nums[queries[i]]
            pos_list = nums_pos[x]
            if len(pos_list) == 3:
                queries[i] = -1
                continue
            pos = bisect.bisect_left(pos_list, queries[i])
            queries[i] = min(
                pos_list[pos + 1] - pos_list[pos],
                pos_list[pos] - pos_list[pos - 1],
            )

        return queries
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function solveQueries(nums: number[], queries: number[]): number[] {
    const n = nums.length;
    const numsPos = new Map<number, number[]>();

    for (let i = 0; i < n; i++) {
        if (!numsPos.has(nums[i])) {
            numsPos.set(nums[i], []);
        }
        numsPos.get(nums[i])!.push(i);
    }

    for (const [key, pos] of numsPos) {
        const x = pos[0];
        pos.unshift(pos[pos.length - 1] - n);
        pos.push(x + n);
    }

    for (let i = 0; i < queries.length; i++) {
        const x = nums[queries[i]];
        const posList = numsPos.get(x)!;
        if (posList.length === 3) {
            queries[i] = -1;
            continue;
        }
        const pos = binarySearch(posList, queries[i]);
        queries[i] = Math.min(
            posList[pos + 1] - posList[pos],
            posList[pos] - posList[pos - 1],
        );
    }

    return queries;
}

function binarySearch(arr: number[], target: number): number {
    let left = 0,
        right = arr.length;
    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
```

</details>

<br>

## Approach 2: Preprocessing Nearest Left and Right Positions + Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** table, int key) {
    HashItem* item = NULL;
    HASH_FIND_INT(*table, &key, item);
    return item;
}

void hashAddOrUpdateItem(HashItem** table, int key, int value) {
    HashItem* item = hashFindItem(table, key);
    if (item == NULL) {
        item = (HashItem*)malloc(sizeof(HashItem));
        item->key = key;
        HASH_ADD_INT(*table, key, item);
    }
    item->value = value;
}

int hashGetItem(HashItem** table, int key, int defaultValue) {
    HashItem* item = hashFindItem(table, key);
    return item == NULL ? defaultValue : item->value;
}

int minInt(int a, int b) { return a < b ? a : b; }

int* solveQueries(int* nums, int numsSize, int* queries, int queriesSize,
                  int* returnSize) {
    int n = numsSize;
    int* left = (int*)malloc(sizeof(int) * n);
    int* right = (int*)malloc(sizeof(int) * n);
    HashItem* pos = NULL;

    for (int i = -n; i < n; i++) {
        if (i >= 0) {
            left[i] = hashGetItem(&pos, nums[i], -n);
        }
        hashAddOrUpdateItem(&pos, nums[(i + n) % n], i);
    }

    HashItem *current, *tmp;
    HASH_ITER(hh, pos, current, tmp) {
        HASH_DEL(pos, current);
        free(current);
    }
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (i < n) {
            right[i] = hashGetItem(&pos, nums[i], 2 * n);
        }
        hashAddOrUpdateItem(&pos, nums[i % n], i);
    }

    for (int i = 0; i < queriesSize; i++) {
        int x = queries[i];
        if (x - left[x] == n) {
            queries[i] = -1;
        } else {
            queries[i] = minInt(x - left[x], right[x] - x);
        }
    }

    *returnSize = queriesSize;

    HASH_ITER(hh, pos, current, tmp) {
        HASH_DEL(pos, current);
        free(current);
    }
    free(left);
    free(right);

    return queries;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> left(n), right(n);
        unordered_map<int, int> pos;
        for (int i = -n; i < n; i++) {
            if (i >= 0) {
                left[i] = pos[nums[i]];
            }
            pos[nums[(i + n) % n]] = i;
        }
        pos.clear();
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (i < n) {
                right[i] = pos[nums[i]];
            }
            pos[nums[i % n]] = i;
        }
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            int x = queries[i];
            queries[i] =
                (x - left[x] == n) ? -1 : min(x - left[x], right[x] - x);
        }
        return queries;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] SolveQueries(int[] nums, int[] queries) {
        int n = nums.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        Dictionary<int, int> pos = new Dictionary<int, int>();

        for (int i = -n; i < n; i++) {
            if (i >= 0) {
                left[i] = pos.ContainsKey(nums[i]) ? pos[nums[i]] : -n;
            }
            pos[nums[(i + n) % n]] = i;
        }

        pos.Clear();
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (i < n) {
                right[i] = pos.ContainsKey(nums[i]) ? pos[nums[i]] : 2 * n;
            }
            pos[nums[i % n]] = i;
        }

        for (int i = 0; i < queries.Length; i++) {
            int x = queries[i];
            if (x - left[x] == n) {
                queries[i] = -1;
            } else {
                queries[i] = Math.Min(x - left[x], right[x] - x);
            }
        }

        return queries;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func solveQueries(nums []int, queries []int) []int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	pos := make(map[int]int)

	for i := -n; i < n; i++ {
		if i >= 0 {
			left[i] = pos[nums[i]]
		}
		pos[nums[(i+n)%n]] = i
	}

	pos = make(map[int]int)
	for i := 2*n - 1; i >= 0; i-- {
		if i < n {
			right[i] = pos[nums[i]]
		}
		pos[nums[i%n]] = i
	}

	for i := 0; i < len(queries); i++ {
		x := queries[i]
		if x-left[x] == n {
			queries[i] = -1
		} else {
			queries[i] = min(x-left[x], right[x]-x)
		}
	}

	return queries
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> solveQueries(int[] nums, int[] queries) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];

        HashMap<Integer, Integer> pos = new HashMap<>();
        for (int i = -n; i < n; i++) {
            if (i >= 0) {
                left[i] = pos.getOrDefault(nums[i], i - n);
            }
            pos.put(nums[((i % n) + n) % n], i);
        }

        pos.clear();
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (i < n) {
                right[i] = pos.getOrDefault(nums[i], i + n);
            }
            pos.put(nums[i % n], i);
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < queries.length; i++) {
            int x = queries[i];
            if (x - left[x] == n) {
                result.add(-1);
            } else {
                result.add(Math.min(x - left[x], right[x] - x));
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function solveQueries(nums, queries) {
    const n = nums.length;
    const left = new Array(n);
    const right = new Array(n);
    const pos = new Map();

    for (let i = -n; i < n; i++) {
        if (i >= 0) {
            left[i] = pos.has(nums[i]) ? pos.get(nums[i]) : -n;
        }
        pos.set(nums[(i + n) % n], i);
    }

    pos.clear();
    for (let i = 2 * n - 1; i >= 0; i--) {
        if (i < n) {
            right[i] = pos.has(nums[i]) ? pos.get(nums[i]) : 2 * n;
        }
        pos.set(nums[i % n], i);
    }

    for (let i = 0; i < queries.length; i++) {
        const x = queries[i];
        if (x - left[x] === n) {
            queries[i] = -1;
        } else {
            queries[i] = Math.min(x - left[x], right[x] - x);
        }
    }

    return queries;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        left = [0] * n
        right = [0] * n
        pos = {}

        for i in range(-n, n):
            if i >= 0:
                left[i] = pos.get(nums[i], -n)
            pos[nums[(i + n) % n]] = i

        pos.clear()
        for i in range(2 * n - 1, -1, -1):
            if i < n:
                right[i] = pos.get(nums[i], 2 * n)
            pos[nums[i % n]] = i

        for i in range(len(queries)):
            x = queries[i]
            if x - left[x] == n:
                queries[i] = -1
            else:
                queries[i] = min(x - left[x], right[x] - x)

        return queries
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function solveQueries(nums: number[], queries: number[]): number[] {
    const n = nums.length;
    const left = new Array(n);
    const right = new Array(n);
    const pos = new Map<number, number>();

    for (let i = -n; i < n; i++) {
        if (i >= 0) {
            left[i] = pos.has(nums[i]) ? pos.get(nums[i])! : -n;
        }
        pos.set(nums[(i + n) % n], i);
    }

    pos.clear();
    for (let i = 2 * n - 1; i >= 0; i--) {
        if (i < n) {
            right[i] = pos.has(nums[i]) ? pos.get(nums[i])! : 2 * n;
        }
        pos.set(nums[i % n], i);
    }

    for (let i = 0; i < queries.length; i++) {
        const x = queries[i];
        if (x - left[x] === n) {
            queries[i] = -1;
        } else {
            queries[i] = Math.min(x - left[x], right[x] - x);
        }
    }

    return queries;
}
```

</details>
