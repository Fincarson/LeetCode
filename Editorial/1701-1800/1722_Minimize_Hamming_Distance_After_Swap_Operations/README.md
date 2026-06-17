# 1722. Minimize Hamming Distance After Swap Operations

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/)  
`Array` `Depth-First Search` `Union-Find`

**Problem Link:** [LeetCode 1722 - Minimize Hamming Distance After Swap Operations](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/)

## Problem

You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

### Example 1

```text
Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
Output: 1
Explanation: source can be transformed the following way:
- Swap indices 0 and 1: source = [2,1,3,4]
- Swap indices 2 and 3: source = [2,1,4,3]
The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
```

### Example 2

```text
Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
Output: 2
Explanation: There are no allowed swaps.
The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.
```

### Example 3

```text
Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
Output: 0
```

## Constraints

- n == source.length == target.length
- 1 <= n <= 105
- 1 <= source[i], target[i] <= 105
- 0 <= allowedSwaps.length <= 105
- allowedSwaps[i].length == 2
- 0 <= ai, bi <= n - 1
- ai != bi

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Smallest String With Swaps](https://leetcode.com/problems/smallest-string-with-swaps/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Make Lexicographically Smallest Array by Swapping Elements](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1722. Minimize Hamming Distance After Swap Operations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Table + Union-Find Set | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash Table + Union-Find Set

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} HashItem;

typedef struct {
    int* fa;
    int* rank;
    int size;
} UnionFind;

UnionFind* createUnionFind(int n) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->fa = (int*)malloc(n * sizeof(int));
    uf->rank = (int*)malloc(n * sizeof(int));
    uf->size = n;
    for (int i = 0; i < n; i++) {
        uf->fa[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

int find(UnionFind* uf, int x) {
    if (uf->fa[x] != x) {
        uf->fa[x] = find(uf, uf->fa[x]);
    }
    return uf->fa[x];
}

void unionSet(UnionFind* uf, int x, int y) {
    x = find(uf, x);
    y = find(uf, y);
    if (x == y) return;
    if (uf->rank[x] < uf->rank[y]) {
        int temp = x;
        x = y;
        y = temp;
    }
    uf->fa[y] = x;
    if (uf->rank[x] == uf->rank[y]) {
        uf->rank[x]++;
    }
}

void freeUnionFind(UnionFind* uf) {
    free(uf->fa);
    free(uf->rank);
    free(uf);
}

int minimumHammingDistance(int* source, int sourceSize, int* target,
                           int targetSize, int** allowedSwaps,
                           int allowedSwapsSize, int* allowedSwapsColSize) {
    int n = sourceSize;
    UnionFind* uf = createUnionFind(n);

    for (int i = 0; i < allowedSwapsSize; i++) {
        unionSet(uf, allowedSwaps[i][0], allowedSwaps[i][1]);
    }

    HashItem** sets = (HashItem**)calloc(n, sizeof(HashItem*));
    for (int i = 0; i < n; i++) {
        int f = find(uf, i);
        HashItem* entry = NULL;
        HASH_FIND_INT(sets[f], &source[i], entry);
        if (entry == NULL) {
            entry = (HashItem*)malloc(sizeof(HashItem));
            entry->key = source[i];
            entry->value = 1;
            HASH_ADD_INT(sets[f], key, entry);
        } else {
            entry->value++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int f = find(uf, i);
        HashItem* entry = NULL;
        HASH_FIND_INT(sets[f], &target[i], entry);
        if (entry != NULL && entry->value > 0) {
            entry->value--;
        } else {
            ans++;
        }
    }

    for (int i = 0; i < n; i++) {
        HashItem *current, *tmp;
        HASH_ITER(hh, sets[i], current, tmp) {
            HASH_DEL(sets[i], current);
            free(current);
        }
    }
    free(sets);
    freeUnionFind(uf);

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    vector<int> fa;
    vector<int> rank;
    // path compression
    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        // merge by rank
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        fa[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        fa.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
        for (auto& pair : allowedSwaps) {
            Union(pair[0], pair[1]);
        }
        unordered_map<int, unordered_map<int, int>> sets;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            sets[f][source[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            if (sets[f][target[i]] > 0) {
                sets[f][target[i]]--;
            } else {
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
    private int[] fa;
    private int[] rank;

    private int Find(int x) {
        if (fa[x] != x) {
            fa[x] = Find(fa[x]);
        }
        return fa[x];
    }

    private void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        fa[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }

    public int MinimumHammingDistance(int[] source, int[] target,
                                      int[][] allowedSwaps) {
        int n = source.Length;
        fa = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }

        foreach (int[] pair in allowedSwaps) {
            Union(pair[0], pair[1]);
        }

        Dictionary<int, Dictionary<int, int>> sets =
            new Dictionary<int, Dictionary<int, int>>();
        for (int i = 0; i < n; i++) {
            int f = Find(i);
            if (!sets.ContainsKey(f)) {
                sets[f] = new Dictionary<int, int>();
            }
            if (!sets[f].ContainsKey(source[i])) {
                sets[f][source[i]] = 0;
            }
            sets[f][source[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = Find(i);
            if (sets[f].ContainsKey(target[i]) && sets[f][target[i]] > 0) {
                sets[f][target[i]]--;
            } else {
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
type UnionFind struct {
    fa   []int
    rank []int
}

func NewUnionFind(n int) *UnionFind {
    fa := make([]int, n)
    rank := make([]int, n)
    for i := 0; i < n; i++ {
        fa[i] = i
    }
    return &UnionFind{fa: fa, rank: rank}
}

func (uf *UnionFind) find(x int) int {
    if uf.fa[x] != x {
        uf.fa[x] = uf.find(uf.fa[x])
    }
    return uf.fa[x]
}

func (uf *UnionFind) union(x, y int) {
    x = uf.find(x)
    y = uf.find(y)
    if x == y {
        return
    }
    if uf.rank[x] < uf.rank[y] {
        x, y = y, x
    }
    uf.fa[y] = x
    if uf.rank[x] == uf.rank[y] {
        uf.rank[x]++
    }
}

func minimumHammingDistance(source []int, target []int, allowedSwaps [][]int) int {
    n := len(source)
    uf := NewUnionFind(n)
    for _, pair := range allowedSwaps {
        uf.union(pair[0], pair[1])
    }
    
    sets := make(map[int]map[int]int)
    for i := 0; i < n; i++ {
        f := uf.find(i)
        if sets[f] == nil {
            sets[f] = make(map[int]int)
        }
        sets[f][source[i]]++
    }
    
    ans := 0
    for i := 0; i < n; i++ {
        f := uf.find(i)
        if sets[f][target[i]] > 0 {
            sets[f][target[i]]--
        } else {
            ans++
        }
    }
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int[] fa;
    private int[] rank;

    private int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    private void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        fa[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }

    public int minimumHammingDistance(
        int[] source,
        int[] target,
        int[][] allowedSwaps
    ) {
        int n = source.length;
        fa = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }

        for (int[] pair : allowedSwaps) {
            union(pair[0], pair[1]);
        }

        Map<Integer, Map<Integer, Integer>> sets = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int f = find(i);
            sets.putIfAbsent(f, new HashMap<>());
            Map<Integer, Integer> cnt = sets.get(f);
            cnt.put(source[i], cnt.getOrDefault(source[i], 0) + 1);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            Map<Integer, Integer> cnt = sets.get(f);
            if (cnt.getOrDefault(target[i], 0) > 0) {
                cnt.put(target[i], cnt.get(target[i]) - 1);
            } else {
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
class UnionFind {
    constructor(n) {
        this.fa = new Array(n);
        this.rank = new Array(n).fill(0);
        for (let i = 0; i < n; i++) {
            this.fa[i] = i;
        }
    }

    find(x) {
        if (this.fa[x] !== x) {
            this.fa[x] = this.find(this.fa[x]);
        }
        return this.fa[x];
    }

    union(x, y) {
        x = this.find(x);
        y = this.find(y);
        if (x === y) return;
        if (this.rank[x] < this.rank[y]) {
            [x, y] = [y, x];
        }
        this.fa[y] = x;
        if (this.rank[x] === this.rank[y]) {
            this.rank[x]++;
        }
    }
}

var minimumHammingDistance = function (source, target, allowedSwaps) {
    const n = source.length;
    const uf = new UnionFind(n);

    for (const [a, b] of allowedSwaps) {
        uf.union(a, b);
    }

    const sets = new Map();
    for (let i = 0; i < n; i++) {
        const f = uf.find(i);
        if (!sets.has(f)) {
            sets.set(f, new Map());
        }
        const cnt = sets.get(f);
        cnt.set(source[i], (cnt.get(source[i]) || 0) + 1);
    }

    let ans = 0;
    for (let i = 0; i < n; i++) {
        const f = uf.find(i);
        const cnt = sets.get(f);
        const count = cnt.get(target[i]) || 0;
        if (count > 0) {
            cnt.set(target[i], count - 1);
        } else {
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
class UnionFind:
    def __init__(self, n):
        self.fa = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.fa[x] != x:
            self.fa[x] = self.find(self.fa[x])
        return self.fa[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            x, y = y, x
        self.fa[y] = x
        if self.rank[x] == self.rank[y]:
            self.rank[x] += 1


class Solution:
    def minimumHammingDistance(
        self,
        source: List[int],
        target: List[int],
        allowedSwaps: List[List[int]],
    ) -> int:
        n = len(source)
        uf = UnionFind(n)
        for a, b in allowedSwaps:
            uf.union(a, b)

        sets = defaultdict(lambda: defaultdict(int))
        for i in range(n):
            f = uf.find(i)
            sets[f][source[i]] += 1

        ans = 0
        for i in range(n):
            f = uf.find(i)
            if sets[f][target[i]] > 0:
                sets[f][target[i]] -= 1
            else:
                ans += 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class UnionFind {
    fa: number[];
    rank: number[];

    constructor(n: number) {
        this.fa = new Array(n);
        this.rank = new Array(n).fill(0);
        for (let i = 0; i < n; i++) {
            this.fa[i] = i;
        }
    }

    find(x: number): number {
        if (this.fa[x] !== x) {
            this.fa[x] = this.find(this.fa[x]);
        }
        return this.fa[x];
    }

    union(x: number, y: number): void {
        x = this.find(x);
        y = this.find(y);
        if (x === y) return;
        if (this.rank[x] < this.rank[y]) {
            [x, y] = [y, x];
        }
        this.fa[y] = x;
        if (this.rank[x] === this.rank[y]) {
            this.rank[x]++;
        }
    }
}

function minimumHammingDistance(
    source: number[],
    target: number[],
    allowedSwaps: number[][],
): number {
    const n = source.length;
    const uf = new UnionFind(n);

    for (const [a, b] of allowedSwaps) {
        uf.union(a, b);
    }

    const sets = new Map<number, Map<number, number>>();
    for (let i = 0; i < n; i++) {
        const f = uf.find(i);
        if (!sets.has(f)) {
            sets.set(f, new Map());
        }
        const cnt = sets.get(f)!;
        cnt.set(source[i], (cnt.get(source[i]) || 0) + 1);
    }

    let ans = 0;
    for (let i = 0; i < n; i++) {
        const f = uf.find(i);
        const cnt = sets.get(f)!;
        const count = cnt.get(target[i]) || 0;
        if (count > 0) {
            cnt.set(target[i], count - 1);
        } else {
            ans++;
        }
    }
    return ans;
}
```

</details>
