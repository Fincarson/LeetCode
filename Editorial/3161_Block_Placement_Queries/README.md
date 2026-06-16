# 3161. Block Placement Queries

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/block-placement-queries/)  
`Array` `Binary Search` `Binary Indexed Tree` `Segment Tree` `Ordered Set`

**Problem Link:** [LeetCode 3161 - Block Placement Queries](https://leetcode.com/problems/block-placement-queries/)

## Problem

There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.

You are given a 2D array queries, which contains two types of queries:

Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.

### Example 1

### Example 2

## Constraints

- 1 <= queries.length <= 15 * 104
- 2 <= queries[i].length <= 3
- 1 <= queries[i][0] <= 2
- 1 <= x, sz <= min(5 * 104, 3 * queries.length)
- The input is generated such that for queries of type 1, no obstacle exists at distance x when the query is asked.
- The input is generated such that there is at least one query of type 2.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Building Boxes](https://leetcode.com/problems/building-boxes/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Fruits Into Baskets III](https://leetcode.com/problems/fruits-into-baskets-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3161. Block Placement Queries

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Segment Tree | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Fenwick Tree | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Segment Tree

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* seg;
    int size;
} SegmentTree;

void initSegTree(SegmentTree* st, int size) {
    st->size = size;
    st->seg = (int*)g_malloc0(sizeof(int) * (size << 2));
}

void freeSegTree(SegmentTree* st) { g_free(st->seg); }

void update(SegmentTree* st, int idx, int val, int p, int l, int r) {
    if (l == r) {
        st->seg[p] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (idx <= mid) {
        update(st, idx, val, p << 1, l, mid);
    } else {
        update(st, idx, val, p << 1 | 1, mid + 1, r);
    }
    st->seg[p] = fmax(st->seg[p << 1], st->seg[p << 1 | 1]);
}

int query(SegmentTree* st, int L, int R, int p, int l, int r) {
    if (L <= l && r <= R) {
        return st->seg[p];
    }
    int mid = (l + r) >> 1;
    int res = 0;
    if (L <= mid) {
        res = fmax(res, query(st, L, R, p << 1, l, mid));
    }
    if (R > mid) {
        res = fmax(res, query(st, L, R, p << 1 | 1, mid + 1, r));
    }
    return res;
}

gint compare_ints(gconstpointer a, gconstpointer b) {
    int ia = GPOINTER_TO_INT(a);
    int ib = GPOINTER_TO_INT(b);
    return ia - ib;
}

static GTreeNode* tree_floor(GTree* tree, int key) {
    GTreeNode* node = g_tree_lower_bound(tree, GINT_TO_POINTER(key));
    if (!node) {
        return g_tree_node_last(tree);
    }
    int k = GPOINTER_TO_INT(g_tree_node_key(node));
    return k > key ? g_tree_node_previous(node) : node;
}

static GTreeNode* tree_ceil(GTree* tree, int key) {
    GTreeNode* node = g_tree_upper_bound(tree, GINT_TO_POINTER(key));
    if (!node) {
        return NULL;
    }
    int k = GPOINTER_TO_INT(g_tree_node_key(node));
    return k > key ? node : g_tree_node_next(node);
}

bool* getResults(int** queries, int queriesSize, int* queriesColSize,
                 int* returnSize) {
    const int mx = 50000;
    SegmentTree st;
    initSegTree(&st, mx);

    GTree* tree = g_tree_new((GCompareFunc)compare_ints);
    g_tree_insert(tree, GINT_TO_POINTER(0), NULL);
    g_tree_insert(tree, GINT_TO_POINTER(mx), NULL);
    update(&st, mx, mx, 1, 0, mx);

    *returnSize = 0;
    bool* ans = (bool*)g_malloc(sizeof(bool) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        int* q = queries[i];
        if (q[0] == 1) {
            int x = q[1];
            GTreeNode* ceil_node = tree_ceil(tree, x);
            GTreeNode* floor_node = tree_floor(tree, x);
            int r =
                ceil_node ? GPOINTER_TO_INT(g_tree_node_key(ceil_node)) : mx;
            int l =
                floor_node ? GPOINTER_TO_INT(g_tree_node_key(floor_node)) : 0;

            update(&st, x, x - l, 1, 0, mx);
            update(&st, r, r - x, 1, 0, mx);
            g_tree_insert(tree, GINT_TO_POINTER(x), NULL);
        } else {
            int x = q[1], sz = q[2];
            GTreeNode* floor_node = tree_floor(tree, x);
            int pre =
                floor_node ? GPOINTER_TO_INT(g_tree_node_key(floor_node)) : 0;

            int maxSpace = query(&st, 0, pre, 1, 0, mx);
            maxSpace = fmax(maxSpace, x - pre);
            ans[(*returnSize)++] = (maxSpace >= sz);
        }
    }

    freeSegTree(&st);
    g_tree_destroy(tree);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> seg;
    void update(int idx, int val, int p, int l, int r) {
        if (l == r) {
            seg[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) {
            update(idx, val, p << 1, l, mid);
        } else {
            update(idx, val, p << 1 | 1, mid + 1, r);
        }
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    int query(int L, int R, int p, int l, int r) {
        if (L <= l && r <= R) {
            return seg[p];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid) {
            res = max(res, query(L, R, p << 1, l, mid));
        }
        if (R > mid) {
            res = max(res, query(L, R, p << 1 | 1, mid + 1, r));
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000;
        seg.resize(mx << 2);
        set<int> st = {0, mx};
        update(mx, mx, 1, 0, mx);
        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = st.upper_bound(x);
                int r = *it;
                int l = *prev(it);
                update(x, x - l, 1, 0, mx);
                update(r, r - x, 1, 0, mx);
                st.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                --it;
                int pre = *it;
                int max_space = query(0, pre, 1, 0, mx);
                max_space = max(max_space, x - pre);
                ans.push_back(max_space >= sz);
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
    private int[] seg;

    private void Update(int idx, int val, int p, int l, int r) {
        if (l == r) {
            seg[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) {
            Update(idx, val, p << 1, l, mid);
        } else {
            Update(idx, val, p << 1 | 1, mid + 1, r);
        }
        seg[p] = Math.Max(seg[p << 1], seg[p << 1 | 1]);
    }

    private int Query(int L, int R, int p, int l, int r) {
        if (L <= l && r <= R) {
            return seg[p];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid) {
            res = Math.Max(res, Query(L, R, p << 1, l, mid));
        }
        if (R > mid) {
            res = Math.Max(res, Query(L, R, p << 1 | 1, mid + 1, r));
        }
        return res;
    }

    public IList<bool> GetResults(int[][] queries) {
        int mx = 50000;
        seg = new int[mx << 2];
        SortedSet<int> st = new SortedSet<int> { 0, mx };
        Update(mx, mx, 1, 0, mx);
        List<bool> ans = new List<bool>();

        foreach (int[] q in queries) {
            if (q[0] == 1) {
                int x = q[1];
                int r = st.GetViewBetween(x + 1, int.MaxValue).Min;
                int l = st.GetViewBetween(int.MinValue, x - 1).Max;
                Update(x, x - l, 1, 0, mx);
                Update(r, r - x, 1, 0, mx);
                st.Add(x);
            } else {
                int x = q[1];
                int sz = q[2];
                int pre = st.GetViewBetween(int.MinValue, x).Max;
                int max_space = Query(0, pre, 1, 0, mx);
                max_space = Math.Max(max_space, x - pre);
                ans.Add(max_space >= sz);
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
func getResults(queries [][]int) []bool {
	const mx = 50000
	seg := make([]int, mx<<2)

	var update func(idx, val, p, l, r int)
	update = func(idx, val, p, l, r int) {
		if l == r {
			seg[p] = val
			return
		}
		mid := (l + r) >> 1
		if idx <= mid {
			update(idx, val, p<<1, l, mid)
		} else {
			update(idx, val, p<<1|1, mid+1, r)
		}
		if seg[p<<1] > seg[p<<1|1] {
			seg[p] = seg[p<<1]
		} else {
			seg[p] = seg[p<<1|1]
		}
	}

	var query func(L, R, p, l, r int) int
	query = func(L, R, p, l, r int) int {
		if L <= l && r <= R {
			return seg[p]
		}
		mid := (l + r) >> 1
		res := 0
		if L <= mid {
			if val := query(L, R, p<<1, l, mid); val > res {
				res = val
			}
		}
		if R > mid {
			if val := query(L, R, p<<1|1, mid+1, r); val > res {
				res = val
			}
		}
		return res
	}

	tree := redblacktree.NewWithIntComparator()
	tree.Put(0, struct{}{})
	tree.Put(mx, struct{}{})
	update(mx, mx, 1, 0, mx)
	ans := make([]bool, 0, len(queries))

	for _, q := range queries {
		if q[0] == 1 {
			x := q[1]
			r := mx
			if node, ok := tree.Ceiling(x + 1); ok {
				r = node.Key.(int)
			}
			l := 0
			if node, ok := tree.Floor(x - 1); ok {
				l = node.Key.(int)
			}

			update(x, x-l, 1, 0, mx)
			update(r, r-x, 1, 0, mx)
			tree.Put(x, struct{}{})
		} else {
			x, sz := q[1], q[2]
			pre := 0
			if node, ok := tree.Floor(x); ok {
				pre = node.Key.(int)
			}
			maxSpace := query(0, pre, 1, 0, mx)
			if x-pre > maxSpace {
				maxSpace = x - pre
			}
			ans = append(ans, maxSpace >= sz)
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

    private int[] seg;

    private void update(int idx, int val, int p, int l, int r) {
        if (l == r) {
            seg[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) {
            update(idx, val, p << 1, l, mid);
        } else {
            update(idx, val, (p << 1) | 1, mid + 1, r);
        }
        seg[p] = Math.max(seg[p << 1], seg[(p << 1) | 1]);
    }

    private int query(int L, int R, int p, int l, int r) {
        if (L <= l && r <= R) {
            return seg[p];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid) {
            res = Math.max(res, query(L, R, p << 1, l, mid));
        }
        if (R > mid) {
            res = Math.max(res, query(L, R, (p << 1) | 1, mid + 1, r));
        }
        return res;
    }

    public List<Boolean> getResults(int[][] queries) {
        int mx = 50000;
        seg = new int[mx << 2];
        TreeSet<Integer> st = new TreeSet<>();
        st.add(0);
        st.add(mx);
        update(mx, mx, 1, 0, mx);
        List<Boolean> ans = new ArrayList<>();

        for (int[] q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                int r = Optional.ofNullable(st.ceiling(x + 1)).orElse(mx);
                int l = Optional.ofNullable(st.floor(x - 1)).orElse(0);
                update(x, x - l, 1, 0, mx);
                update(r, r - x, 1, 0, mx);
                st.add(x);
            } else {
                int x = q[1];
                int sz = q[2];
                int pre = Optional.ofNullable(st.floor(x)).orElse(0);
                int max_space = query(0, pre, 1, 0, mx);
                max_space = Math.max(max_space, x - pre);
                ans.add(max_space >= sz);
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
const { AvlTree } = require("@datastructures-js/binary-search-tree");

var getResults = function (queries) {
    const mx = 50000;
    const seg = new Array(mx << 2).fill(0);

    const update = (idx, val, p, l, r) => {
        if (l === r) {
            seg[p] = val;
            return;
        }
        const mid = (l + r) >> 1;
        if (idx <= mid) {
            update(idx, val, p << 1, l, mid);
        } else {
            update(idx, val, (p << 1) | 1, mid + 1, r);
        }
        seg[p] = Math.max(seg[p << 1], seg[(p << 1) | 1]);
    };

    const query = (L, R, p, l, r) => {
        if (L <= l && r <= R) {
            return seg[p];
        }
        const mid = (l + r) >> 1;
        let res = 0;
        if (L <= mid) {
            res = Math.max(res, query(L, R, p << 1, l, mid));
        }
        if (R > mid) {
            res = Math.max(res, query(L, R, (p << 1) | 1, mid + 1, r));
        }
        return res;
    };

    const tree = new AvlTree((a, b) => a - b);
    tree.insert(0);
    tree.insert(mx);
    update(mx, mx, 1, 0, mx);
    const ans = [];

    for (const q of queries) {
        if (q[0] === 1) {
            const x = q[1];
            const rightNode = tree.ceil(x, false);
            const leftNode = tree.floor(x, false);
            const r = rightNode ? rightNode.getValue() : mx;
            const l = leftNode ? leftNode.getValue() : 0;

            update(x, x - l, 1, 0, mx);
            update(r, r - x, 1, 0, mx);
            tree.insert(x);
        } else {
            const x = q[1];
            const sz = q[2];
            const preNode = tree.floor(x, true);
            const pre = preNode ? preNode.getValue() : 0;

            let maxSpace = query(0, pre, 1, 0, mx);
            maxSpace = Math.max(maxSpace, x - pre);
            ans.push(maxSpace >= sz);
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
    def __init__(self):
        self.seg = []
        self.st = SortedList()
        self.mx = 50000

    def update(self, idx: int, val: int, p: int, l: int, r: int) -> None:
        if l == r:
            self.seg[p] = val
            return

        mid = (l + r) >> 1
        if idx <= mid:
            self.update(idx, val, p << 1, l, mid)
        else:
            self.update(idx, val, p << 1 | 1, mid + 1, r)

        self.seg[p] = max(self.seg[p << 1], self.seg[p << 1 | 1])

    def query(self, L: int, R: int, p: int, l: int, r: int) -> int:
        if L <= l and r <= R:
            return self.seg[p]

        mid = (l + r) >> 1
        res = 0
        if L <= mid:
            res = max(res, self.query(L, R, p << 1, l, mid))
        if R > mid:
            res = max(res, self.query(L, R, p << 1 | 1, mid + 1, r))

        return res

    def getResults(self, queries: List[List[int]]) -> List[bool]:
        self.mx = 50000
        self.seg = [0] * (self.mx << 2)
        self.st = SortedList([0, self.mx])
        self.update(self.mx, self.mx, 1, 0, self.mx)
        ans = []

        for q in queries:
            if q[0] == 1:
                x = q[1]
                idx = min(len(self.st) - 1, self.st.bisect_right(x))

                r = self.st[idx]
                l = self.st[idx - 1] if idx > 0 else self.st[0]
                self.update(x, x - l, 1, 0, self.mx)
                self.update(r, r - x, 1, 0, self.mx)
                self.st.add(x)
            else:
                x, sz = q[1], q[2]
                idx = min(len(self.st) - 1, self.st.bisect_right(x))
                pre = self.st[0] if idx == 0 else self.st[idx - 1]

                max_space = max(x - pre, self.query(0, pre, 1, 0, self.mx))
                ans.append(max_space >= sz)

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
import { AvlTree } from "@datastructures-js/binary-search-tree";

function getResults(queries: number[][]): boolean[] {
    const mx: number = 50000;
    const seg: number[] = new Array(mx << 2).fill(0);

    const update = (
        idx: number,
        val: number,
        p: number,
        l: number,
        r: number,
    ): void => {
        if (l === r) {
            seg[p] = val;
            return;
        }
        const mid = (l + r) >> 1;
        if (idx <= mid) {
            update(idx, val, p << 1, l, mid);
        } else {
            update(idx, val, (p << 1) | 1, mid + 1, r);
        }
        seg[p] = Math.max(seg[p << 1], seg[(p << 1) | 1]);
    };

    const query = (
        L: number,
        R: number,
        p: number,
        l: number,
        r: number,
    ): number => {
        if (L <= l && r <= R) {
            return seg[p];
        }
        const mid = (l + r) >> 1;
        let res: number = 0;
        if (L <= mid) {
            res = Math.max(res, query(L, R, p << 1, l, mid));
        }
        if (R > mid) {
            res = Math.max(res, query(L, R, (p << 1) | 1, mid + 1, r));
        }
        return res;
    };

    const tree = new AvlTree<number>((a: number, b: number) => a - b);
    tree.insert(0);
    tree.insert(mx);
    update(mx, mx, 1, 0, mx);

    const ans: boolean[] = [];

    for (const q of queries) {
        if (q[0] === 1) {
            const x: number = q[1];
            const rightNode = tree.ceil(x, false);
            const leftNode = tree.floor(x, false);
            const r: number = rightNode?.getValue() ?? mx;
            const l: number = leftNode?.getValue() ?? 0;

            update(x, x - l, 1, 0, mx);
            update(r, r - x, 1, 0, mx);
            tree.insert(x);
        } else {
            const x: number = q[1];
            const sz: number = q[2];
            const preNode = tree.floor(x, true);
            const pre: number = preNode?.getValue() ?? 0;

            let maxSpace: number = query(0, pre, 1, 0, mx);
            maxSpace = Math.max(maxSpace, x - pre);
            ans.push(maxSpace >= sz);
        }
    }

    return ans;
}
```

</details>

<br>

## Approach 2: Fenwick Tree

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
gint int_compare(gconstpointer a, gconstpointer b) {
    int ia = *(int*)a;
    int ib = *(int*)b;
    return ia - ib;
}

void update(int* bt, int mx, int x, int v) {
    for (; x <= mx; x += x & -x) {
        if (v > bt[x]) {
            bt[x] = v;
        }
    }
}

int query(int* bt, int x) {
    int res = 0;
    for (; x > 0; x -= x & -x) {
        if (bt[x] > res) {
            res = bt[x];
        }
    }
    return res;
}

int get_node_key(GTreeNode* node) { return *(int*)g_tree_node_key(node); }

int floor_value(GTree* tree, int x) {
    GTreeNode* node = g_tree_lower_bound(tree, &x);
    if (node == NULL) {
        return 0;
    }

    int key = get_node_key(node);
    return key <= x ? key : get_node_key(g_tree_node_previous(node));
}

int lower_value(GTree* tree, int x) {
    GTreeNode* node = g_tree_lower_bound(tree, &x);
    if (node == NULL) {
        return 0;
    }
    int key = get_node_key(node);
    return key < x ? key : get_node_key(g_tree_node_previous(node));
}

int higher_value(GTree* tree, int x, int mx) {
    GTreeNode* node = g_tree_upper_bound(tree, &x);
    if (node == NULL) {
        return mx;
    }
    int key = get_node_key(node);
    return key > x ? key : get_node_key(g_tree_node_next(node));
}

bool* getResults(int** queries, int queriesSize, int* queriesColSize,
                 int* returnSize) {
    int mx = 50000;
    GTree* st = g_tree_new((GCompareFunc)int_compare);
    int* key0 = g_new(int, 1);
    int* keyMx = g_new(int, 1);
    *key0 = 0;
    *keyMx = mx;
    g_tree_insert(st, key0, key0);
    g_tree_insert(st, keyMx, keyMx);

    for (int i = 0; i < queriesSize; i++) {
        if (queries[i][0] == 1) {
            int* key = g_new(int, 1);
            *key = queries[i][1];
            g_tree_insert(st, key, key);
        }
    }

    int* bt = (int*)calloc(mx + 1, sizeof(int));
    int pre = 0;
    GTreeNode* node = g_tree_node_first(st);
    while (node != NULL) {
        int x = get_node_key(node);
        if (x != 0) {
            update(bt, mx, x, x - pre);
            pre = x;
        }
        node = g_tree_node_next(node);
    }

    bool* ans = (bool*)malloc(queriesSize * sizeof(bool));
    int ansIndex = 0;
    for (int i = queriesSize - 1; i >= 0; i--) {
        int* q = queries[i];
        if (q[0] == 2) {
            int x = q[1];
            int sz = q[2];

            int preVal = floor_value(st, x);
            int maxSpace = query(bt, preVal);
            maxSpace = fmax(maxSpace, x - preVal);
            ans[ansIndex++] = maxSpace >= sz;
        } else {
            int x = q[1];
            int preVal = lower_value(st, x);
            int nxt = higher_value(st, x, mx);

            update(bt, mx, nxt, nxt - preVal);
            g_tree_remove(st, &x);
        }
    }

    for (int i = 0; i < ansIndex / 2; i++) {
        bool temp = ans[i];
        ans[i] = ans[ansIndex - 1 - i];
        ans[ansIndex - 1 - i] = temp;
    }

    *returnSize = ansIndex;
    g_tree_destroy(st);
    free(bt);

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> bt;

    void update(int x, int v) {
        for (; x < bt.size(); x += x & -x) {
            bt[x] = max(bt[x], v);
        }
    }

    int query(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) {
            res = max(res, bt[x]);
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000;

        set<int> st = {0, mx};

        for (auto& q : queries) {
            if (q[0] == 1) {
                st.insert(q[1]);
            }
        }

        bt.resize(mx + 1);

        int pre = 0;

        for (int x : st) {
            if (x == 0) {
                continue;
            }
            update(x, x - pre);
            pre = x;
        }

        reverse(queries.begin(), queries.end());
        vector<bool> ans;
        for (auto& q : queries) {
            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                --it;
                int pre = *it;
                int max_space = query(pre);
                max_space = max(max_space, x - pre);
                ans.push_back(max_space >= sz);
            } else {
                int x = q[1];
                auto it = st.find(x);
                int pre = *prev(it);
                int nxt = *next(it);
                update(nxt, nxt - pre);
                st.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int[] bt;

    private void Update(int x, int v) {
        for (; x < bt.Length; x += x & -x) {
            bt[x] = Math.Max(bt[x], v);
        }
    }

    private int Query(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) {
            res = Math.Max(res, bt[x]);
        }
        return res;
    }

    public IList<bool> GetResults(int[][] queries) {
        int mx = 50000;

        SortedSet<int> st = new SortedSet<int> { 0, mx };
        foreach (int[] q in queries) {
            if (q[0] == 1) {
                st.Add(q[1]);
            }
        }

        List<int> sortedList = new List<int>(st);
        bt = new int[mx + 1];
        int pre = 0;
        for (int i = 0; i < sortedList.Count; i++) {
            int x = sortedList[i];
            if (x == 0) {
                continue;
            }
            Update(x, x - pre);
            pre = x;
        }

        List<bool> ans = new List<bool>();
        for (int i = queries.Length - 1; i >= 0; i--) {
            int[] q = queries[i];
            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                int idx = sortedList.BinarySearch(x);
                if (idx < 0) {
                    idx = ~idx - 1;
                }

                int preVal = sortedList[idx];
                int maxSpace = Query(preVal);
                maxSpace = Math.Max(maxSpace, x - preVal);
                ans.Add(maxSpace >= sz);
            } else {
                int x = q[1];

                int idx = sortedList.BinarySearch(x);
                int preVal = idx > 0 ? sortedList[idx - 1] : 0;
                int nxt = idx < sortedList.Count - 1 ? sortedList[idx + 1] : mx;

                Update(nxt, nxt - preVal);
                sortedList.RemoveAt(idx);
            }
        }

        ans.Reverse();
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getResults(queries [][]int) []bool {
	mx := 50000
	st := redblacktree.NewWithIntComparator()
	st.Put(0, nil)
	st.Put(mx, nil)

	for _, q := range queries {
		if q[0] == 1 {
			st.Put(q[1], nil)
		}
	}

	bt := make([]int, mx+1)
	update := func(x, v int) {
		for ; x < len(bt); x += x & -x {
			bt[x] = max(bt[x], v)
		}
	}

	query := func(x int) int {
		res := 0
		for ; x > 0; x -= x & -x {
			res = max(res, bt[x])
		}
		return res
	}

	pre := 0
	keys := st.Keys()
	for _, key := range keys {
		x := key.(int)
		if x == 0 {
			continue
		}
		update(x, x-pre)
		pre = x
	}

	ans := make([]bool, 0)
	for i := len(queries) - 1; i >= 0; i-- {
		q := queries[i]
		if q[0] == 2 {
			x := q[1]
			sz := q[2]

			floorNode, _ := st.Floor(x)
			preVal := 0
			if floorNode != nil {
				preVal = floorNode.Key.(int)
			}

			maxSpace := query(preVal)
			maxSpace = max(maxSpace, x-preVal)
			ans = append(ans, maxSpace >= sz)
		} else {
			x := q[1]
			lowerNode, _ := st.Floor(x - 1)
			preVal := 0
			if lowerNode != nil {
				preVal = lowerNode.Key.(int)
			}

			higherNode, _ := st.Ceiling(x + 1)
			nxt := mx
			if higherNode != nil {
				nxt = higherNode.Key.(int)
			}

			update(nxt, nxt-preVal)
			st.Remove(x)
		}
	}

	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int[] bt;

    private void update(int x, int v) {
        for (; x < bt.length; x += x & -x) {
            bt[x] = Math.max(bt[x], v);
        }
    }

    private int query(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) {
            res = Math.max(res, bt[x]);
        }
        return res;
    }

    public List<Boolean> getResults(int[][] queries) {
        int mx = 50000;

        TreeSet<Integer> st = new TreeSet<>();
        st.add(0);
        st.add(mx);

        for (int[] q : queries) {
            if (q[0] == 1) {
                st.add(q[1]);
            }
        }

        bt = new int[mx + 1];

        int pre = 0;
        for (int x : st) {
            if (x == 0) continue;
            update(x, x - pre);
            pre = x;
        }

        List<Boolean> ans = new ArrayList<>();
        for (int i = queries.length - 1; i >= 0; i--) {
            int[] q = queries[i];
            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];
                int preVal = Optional.ofNullable(st.floor(x)).orElse(0);
                int maxSpace = query(preVal);
                maxSpace = Math.max(maxSpace, x - preVal);
                ans.add(maxSpace >= sz);
            } else {
                int x = q[1];
                int preVal = Optional.ofNullable(st.lower(x)).orElse(0);
                int nxt = Optional.ofNullable(st.higher(x)).orElse(mx);
                update(nxt, nxt - preVal);
                st.remove(x);
            }
        }

        Collections.reverse(ans);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getResults = function (queries) {
    const mx = 50000;
    const st = [0, mx];

    const bisectLeft = (arr, x) => {
        let lo = 0,
            hi = arr.length;
        while (lo < hi) {
            const mid = (lo + hi) >>> 1;
            if (arr[mid] < x) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    };

    const insort = (arr, x) => {
        const idx = bisectLeft(arr, x);
        arr.splice(idx, 0, x);
    };

    for (const q of queries) {
        if (q[0] === 1) {
            insort(st, q[1]);
        }
    }

    const bt = new Array(mx + 1).fill(0);

    const update = (x, v) => {
        while (x <= mx) {
            if (v > bt[x]) bt[x] = v;
            x += x & -x;
        }
    };

    const query = (x) => {
        let res = 0;
        while (x > 0) {
            if (bt[x] > res) res = bt[x];
            x -= x & -x;
        }
        return res;
    };

    let pre = 0;
    for (const x of st) {
        if (x === 0) {
            continue;
        }
        update(x, x - pre);
        pre = x;
    }

    const ans = [];
    for (let i = queries.length - 1; i >= 0; i--) {
        const q = queries[i];
        if (q[0] === 2) {
            const x = q[1],
                sz = q[2];
            const idx = bisectLeft(st, x);
            let preVal;

            if (idx < st.length && st[idx] === x) {
                preVal = x;
            } else {
                preVal = st[idx - 1];
            }

            let maxSpace = query(preVal);
            maxSpace = Math.max(maxSpace, x - preVal);
            ans.push(maxSpace >= sz);
        } else {
            const x = q[1];
            const idx = bisectLeft(st, x);
            const preVal = st[idx - 1];
            const nxt = st[idx + 1];

            update(nxt, nxt - preVal);
            st.splice(idx, 1);
        }
    }

    return ans.reverse();
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getResults(self, queries: List[List[int]]) -> List[bool]:
        mx = 50000

        st = SortedList([0, mx])
        for q in queries:
            if q[0] == 1:
                st.add(q[1])

        bt = [0] * (mx + 1)

        def update(x: int, v: int) -> None:
            while x < len(bt):
                if v > bt[x]:
                    bt[x] = v
                x += x & -x

        def query(x: int) -> int:
            res = 0
            while x > 0:
                if bt[x] > res:
                    res = bt[x]
                x -= x & -x
            return res

        pre = 0
        for x in st:
            if x == 0:
                continue
            update(x, x - pre)
            pre = x

        ans = []
        for q in reversed(queries):
            if q[0] == 2:
                x, sz = q[1], q[2]
                idx = st.bisect_left(x)
                if idx < len(st) and st[idx] == x:
                    pre_val = x
                else:
                    pre_val = st[idx - 1]
                max_space = query(pre_val)
                max_space = max(max_space, x - pre_val)
                ans.append(max_space >= sz)
            else:
                x = q[1]
                idx = st.bisect_left(x)
                pre_val = st[idx - 1]
                nxt = st[idx + 1]
                update(nxt, nxt - pre_val)
                st.discard(x)

        return ans[::-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getResults(queries: number[][]): boolean[] {
    const mx = 50000;
    const st: number[] = [0, mx];

    const bisectLeft = (arr: number[], x: number): number => {
        let lo = 0,
            hi = arr.length;
        while (lo < hi) {
            const mid = (lo + hi) >>> 1;
            if (arr[mid] < x) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    };

    const insort = (arr: number[], x: number): void => {
        const idx = bisectLeft(arr, x);
        arr.splice(idx, 0, x);
    };

    for (const q of queries) {
        if (q[0] === 1) {
            insort(st, q[1]);
        }
    }

    const bt: number[] = new Array(mx + 1).fill(0);
    const update = (x: number, v: number): void => {
        while (x <= mx) {
            if (v > bt[x]) bt[x] = v;
            x += x & -x;
        }
    };

    const query = (x: number): number => {
        let res = 0;
        while (x > 0) {
            if (bt[x] > res) res = bt[x];
            x -= x & -x;
        }
        return res;
    };

    let pre = 0;
    for (const x of st) {
        if (x === 0) {
            continue;
        }
        update(x, x - pre);
        pre = x;
    }

    const ans: boolean[] = [];
    for (let i = queries.length - 1; i >= 0; i--) {
        const q = queries[i];
        if (q[0] === 2) {
            const x = q[1],
                sz = q[2];
            const idx = bisectLeft(st, x);
            let preVal: number;

            if (idx < st.length && st[idx] === x) {
                preVal = x;
            } else {
                preVal = st[idx - 1];
            }

            let maxSpace = query(preVal);
            maxSpace = Math.max(maxSpace, x - preVal);
            ans.push(maxSpace >= sz);
        } else {
            const x = q[1];
            const idx = bisectLeft(st, x);
            const preVal = st[idx - 1];
            const nxt = st[idx + 1];

            update(nxt, nxt - preVal);
            st.splice(idx, 1);
        }
    }

    return ans.reverse();
}
```

</details>
