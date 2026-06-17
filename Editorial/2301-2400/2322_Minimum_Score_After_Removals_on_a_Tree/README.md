# 2322. Minimum Score After Removals on a Tree

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/)  
`Array` `Bit Manipulation` `Tree` `Depth-First Search`

**Problem Link:** [LeetCode 2322 - Minimum Score After Removals on a Tree](https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/)

## Problem

There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Remove two distinct edges of the tree to form three connected components. For a pair of removed edges, the following steps are defined:

- For example, say the three components have the node values: [4,5,7], [1,9], and [3,3,3]. The three XOR values are 4 ^ 5 ^ 7 = 6, 1 ^ 9 = 8, and 3 ^ 3 ^ 3 = 3. The largest XOR value is 8 and the smallest XOR value is 3. The score is then 8 - 3 = 5.

Return the minimum score of any possible pair of edge removals on the given tree.

### Example 1

```text
Input: nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
Output: 9
Explanation: The diagram above shows a way to make a pair of removals.
- The 1st component has nodes [1,3,4] with values [5,4,11]. Its XOR value is 5 ^ 4 ^ 11 = 10.
- The 2nd component has node [0] with value [1]. Its XOR value is 1 = 1.
- The 3rd component has node [2] with value [5]. Its XOR value is 5 = 5.
The score is the difference between the largest and smallest XOR value which is 10 - 1 = 9.
It can be shown that no other pair of removals will obtain a smaller score than 9.
```

### Example 2

```text
Input: nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
Output: 0
Explanation: The diagram above shows a way to make a pair of removals.
- The 1st component has nodes [3,4] with values [4,4]. Its XOR value is 4 ^ 4 = 0.
- The 2nd component has nodes [1,0] with values [5,5]. Its XOR value is 5 ^ 5 = 0.
- The 3rd component has nodes [2,5] with values [2,2]. Its XOR value is 2 ^ 2 = 0.
The score is the difference between the largest and smallest XOR value which is 0 - 0 = 0.
We cannot obtain a smaller score than 0.
```

## Constraints

- n == nums.length
- 3 <= n <= 1000
- 1 <= nums[i] <= 108
- edges.length == n - 1
- edges[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- edges represents a valid tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2322. Minimum Score After Removals on a Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Double $\text{DFS}$ to Partition Connected Components | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Enumerate Based on $\text{DFS}$ Order | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Double $\text{DFS}$ to Partition Connected Components

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode *createListNode(int val) {
    struct ListNode *obj = (struct ListNode *)malloc(sizeof(struct ListNode));
    obj->val = val;
    obj->next = NULL;
    return obj;
}

void freeList(struct ListNode *list) {
    while (list) {
        struct ListNode *p = list;
        list = list->next;
        free(p);
    }
}

int calc(int part1, int part2, int part3) {
    return fmax(part1, fmax(part2, part3)) - fmin(part1, fmin(part2, part3));
}

int dfs2(int x, int f, int oth, int anc, int *nums, struct ListNode **adj,
         int sum, int *res) {
    int son = nums[x];
    for (struct ListNode *p = adj[x]; p != NULL; p = p->next) {
        int y = p->val;
        if (y == f) {
            continue;
        }
        son ^= dfs2(y, x, oth, anc, nums, adj, sum, res);
    }
    if (f == anc) {
        return son;
    }

    *res = fmin(*res, calc(oth, son, sum ^ oth ^ son));
    return son;
}

int dfs(int x, int f, int *nums, struct ListNode **adj, int sum, int *res) {
    int son = nums[x];
    for (struct ListNode *p = adj[x]; p != NULL; p = p->next) {
        int y = p->val;
        if (y == f) {
            continue;
        }
        son ^= dfs(y, x, nums, adj, sum, res);
    }
    for (struct ListNode *p = adj[x]; p != NULL; p = p->next) {
        int y = p->val;
        if (y == f) {
            dfs2(y, x, son, x, nums, adj, sum, res);
        }
    }
    return son;
}

int minimumScore(int *nums, int numsSize, int **edges, int edgesSize,
                 int *edgesColSize) {
    struct ListNode *adj[numsSize];
    for (int i = 0; i < numsSize; i++) {
        adj[i] = NULL;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        struct ListNode *nodeu = createListNode(u);
        nodeu->next = adj[v];
        adj[v] = nodeu;
        struct ListNode *nodev = createListNode(v);
        nodev->next = adj[u];
        adj[u] = nodev;
    }
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum ^= nums[i];
    }
    int res = INT_MAX;
    dfs(0, -1, nums, adj, sum, &res);
    for (int i = 0; i < numsSize; i++) {
        freeList(adj[i]);
    }

    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int calc(int part1, int part2, int part3) {
        return max(part1, max(part2, part3)) - min(part1, min(part2, part3));
    }

    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size();
        vector<vector<int>> e(n);
        for (auto &v : edges) {
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }

        int sum = 0;
        for (int x : nums) {
            sum ^= x;
        }

        int res = INT_MAX;
        function<int(int, int, int, int)> dfs2 = [&](int x, int f, int oth,
                                                     int anc) {
            int son = nums[x];
            for (auto &y : e[x]) {
                if (y == f) {
                    continue;
                }
                son ^= dfs2(y, x, oth, anc);
            }
            if (f == anc) {
                return son;
            }
            res = min(res, calc(oth, son, sum ^ oth ^ son));
            return son;
        };

        function<int(int, int)> dfs = [&](int x, int f) {
            int son = nums[x];
            for (auto &y : e[x]) {
                if (y == f) {
                    continue;
                }
                son ^= dfs(y, x);
            }

            for (auto &y : e[x]) {
                if (y == f) {
                    dfs2(y, x, son, x);
                }
            }
            return son;
        };

        dfs(0, -1);
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumScore(int[] nums, int[][] edges) {
        int n = nums.Length;
        List<List<int>> e = new List<List<int>>();
        for (int i = 0; i < n; i++) {
            e.Add(new List<int>());
        }
        foreach (var v in edges) {
            e[v[0]].Add(v[1]);
            e[v[1]].Add(v[0]);
        }

        int sum = 0;
        foreach (int x in nums) {
            sum ^= x;
        }

        int res = int.MaxValue;
        Func<int, int, int> dfs = null;
        Func<int, int, int, int, int> dfs2 = null;

        dfs2 = (x, f, oth, anc) => {
            int son = nums[x];
            foreach (int y in e[x]) {
                if (y == f)
                    continue;
                son ^= dfs2(y, x, oth, anc);
            }
            if (f == anc) {
                return son;
            }
            res = Math.Min(res, Calc(oth, son, sum ^ oth ^ son));
            return son;
        };

        dfs = (x, f) => {
            int son = nums[x];
            foreach (int y in e[x]) {
                if (y == f) {
                    continue;
                }
                son ^= dfs(y, x);
            }

            foreach (int y in e[x]) {
                if (y == f) {
                    dfs2(y, x, son, x);
                }
            }
            return son;
        };

        dfs(0, -1);
        return res;
    }

    public int Calc(int part1, int part2, int part3) {
        return Math.Max(part1, Math.Max(part2, part3)) -
               Math.Min(part1, Math.Min(part2, part3));
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumScore(nums []int, edges [][]int) int {
	n := len(nums)
	e := make([][]int, n)
	for _, v := range edges {
		e[v[0]] = append(e[v[0]], v[1])
		e[v[1]] = append(e[v[1]], v[0])
	}

	sum := 0
	for _, x := range nums {
		sum ^= x
	}

	res := math.MaxInt32
	var dfs2 func(int, int, int, int) int
	dfs2 = func(x, f, oth, anc int) int {
		son := nums[x]
		for _, y := range e[x] {
			if y == f {
				continue
			}
			son ^= dfs2(y, x, oth, anc)
		}
		if f == anc {
			return son
		}

		res = min(res, calc(oth, son, sum^oth^son))
		return son
	}

	var dfs func(int, int) int
	dfs = func(x, f int) int {
		son := nums[x]
		for _, y := range e[x] {
			if y == f {
				continue
			}
			son ^= dfs(y, x)
		}

		for _, y := range e[x] {
			if y == f {
				dfs2(y, x, son, x)
			}
		}
		return son
	}

	dfs(0, -1)
	return res
}

func calc(part1, part2, part3 int) int {
	return max(part1, max(part2, part3)) - min(part1, min(part2, part3))
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    int res = Integer.MAX_VALUE;

    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;
        List<List<Integer>> e = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            e.add(new ArrayList<>());
        }
        for (int[] v : edges) {
            e.get(v[0]).add(v[1]);
            e.get(v[1]).add(v[0]);
        }

        int sum = 0;
        for (int x : nums) {
            sum ^= x;
        }

        dfs(0, -1, nums, e, sum);
        return res;
    }

    private int calc(int part1, int part2, int part3) {
        return (
            Math.max(part1, Math.max(part2, part3)) -
            Math.min(part1, Math.min(part2, part3))
        );
    }

    private int dfs(int x, int f, int[] nums, List<List<Integer>> e, int sum) {
        int son = nums[x];
        for (int y : e.get(x)) {
            if (y == f) {
                continue;
            }
            son ^= dfs(y, x, nums, e, sum);
        }

        for (int y : e.get(x)) {
            if (y == f) {
                dfs2(y, x, son, x, nums, e, sum);
            }
        }
        return son;
    }

    private int dfs2(
        int x,
        int f,
        int oth,
        int anc,
        int[] nums,
        List<List<Integer>> e,
        int sum
    ) {
        int son = nums[x];
        for (int y : e.get(x)) {
            if (y == f) {
                continue;
            }
            son ^= dfs2(y, x, oth, anc, nums, e, sum);
        }
        if (f == anc) {
            return son;
        }
        res = Math.min(res, calc(oth, son, sum ^ oth ^ son));
        return son;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumScore = function (nums, edges) {
    const n = nums.length;
    const e = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        e[u].push(v);
        e[v].push(u);
    }

    let sum = 0;
    for (const x of nums) {
        sum ^= x;
    }
    let res = Infinity;

    function dfs2(x, f, oth, anc) {
        let son = nums[x];
        for (const y of e[x]) {
            if (y === f) {
                continue;
            }
            son ^= dfs2(y, x, oth, anc);
        }
        if (f === anc) {
            return son;
        }
        res = Math.min(res, calc(oth, son, sum ^ oth ^ son));
        return son;
    }

    function dfs(x, f) {
        let son = nums[x];
        for (const y of e[x]) {
            if (y === f) {
                continue;
            }
            son ^= dfs(y, x);
        }

        for (const y of e[x]) {
            if (y === f) {
                dfs2(y, x, son, x);
            }
        }
        return son;
    }

    dfs(0, -1);
    return res;
};

function calc(part1, part2, part3) {
    return (
        Math.max(part1, Math.max(part2, part3)) -
        Math.min(part1, Math.min(part2, part3))
    );
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def calc(self, part1: int, part2: int, part3: int) -> int:
        return max(part1, part2, part3) - min(part1, part2, part3)

    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        e = [[] for _ in range(n)]
        for u, v in edges:
            e[u].append(v)
            e[v].append(u)

        total = 0
        for x in nums:
            total ^= x

        res = float("inf")

        def dfs2(x: int, f: int, oth: int, anc: int) -> int:
            son = nums[x]
            for y in e[x]:
                if y == f:
                    continue
                son ^= dfs2(y, x, oth, anc)
            if f == anc:
                return son
            nonlocal res
            res = min(res, self.calc(oth, son, total ^ oth ^ son))
            return son

        def dfs(x: int, f: int) -> int:
            son = nums[x]
            for y in e[x]:
                if y == f:
                    continue
                son ^= dfs(y, x)
            for y in e[x]:
                if y == f:
                    dfs2(y, x, son, x)
            return son

        dfs(0, -1)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumScore(nums: number[], edges: number[][]): number {
    const n = nums.length;
    const e: number[][] = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        e[u].push(v);
        e[v].push(u);
    }

    let sum = 0;
    for (const x of nums) {
        sum ^= x;
    }
    let res = Infinity;

    const dfs2 = (x: number, f: number, oth: number, anc: number): number => {
        let son = nums[x];
        for (const y of e[x]) {
            if (y === f) {
                continue;
            }
            son ^= dfs2(y, x, oth, anc);
        }
        if (f === anc) {
            return son;
        }
        res = Math.min(res, calc(oth, son, sum ^ oth ^ son));
        return son;
    };

    const dfs = (x: number, f: number): number => {
        let son = nums[x];
        for (const y of e[x]) {
            if (y === f) {
                continue;
            }
            son ^= dfs(y, x);
        }
        for (const y of e[x]) {
            if (y === f) {
                dfs2(y, x, son, x);
            }
        }
        return son;
    };

    dfs(0, -1);
    return res;
}

function calc(part1: number, part2: number, part3: number): number {
    return (
        Math.max(part1, Math.max(part2, part3)) -
        Math.min(part1, Math.min(part2, part3))
    );
}
```

</details>

<br>

## Approach 2: Enumerate Based on $\text{DFS}$ Order

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* createListNode(int val) {
    struct ListNode* obj = (struct ListNode*)malloc(sizeof(struct ListNode));
    obj->val = val;
    obj->next = NULL;
    return obj;
}

void freeList(struct ListNode* list) {
    while (list) {
        struct ListNode* p = list;
        list = list->next;
        free(p);
    }
}

int calc(int part1, int part2, int part3) {
    return fmax(part1, fmax(part2, part3)) - fmin(part1, fmin(part2, part3));
}

void dfs(int x, int fa, int* nums, struct ListNode** adj, int* sum, int* in,
         int* out, int* cnt) {
    in[x] = (*cnt)++;
    sum[x] = nums[x];
    for (struct ListNode* p = adj[x]; p != NULL; p = p->next) {
        int y = p->val;
        if (y == fa) {
            continue;
        }
        dfs(y, x, nums, adj, sum, in, out, cnt);
        sum[x] ^= sum[y];
    }
    out[x] = *cnt;
}

int minimumScore(int* nums, int numsSize, int** edges, int edgesSize,
                 int* edgesColSize) {
    struct ListNode* adj[numsSize];
    for (int i = 0; i < numsSize; i++) {
        adj[i] = NULL;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        struct ListNode* nodeu = createListNode(u);
        nodeu->next = adj[v];
        adj[v] = nodeu;
        struct ListNode* nodev = createListNode(v);
        nodev->next = adj[u];
        adj[u] = nodev;
    }

    int* sum = (int*)calloc(numsSize, sizeof(int));
    int* in = (int*)calloc(numsSize, sizeof(int));
    int* out = (int*)calloc(numsSize, sizeof(int));
    int cnt = 0;

    dfs(0, -1, nums, adj, sum, in, out, &cnt);

    int res = INT_MAX;
    for (int u = 1; u < numsSize; u++) {
        for (int v = u + 1; v < numsSize; v++) {
            if (in[v] > in[u] && in[v] < out[u]) {
                res = fmin(res, calc(sum[0] ^ sum[u], sum[u] ^ sum[v], sum[v]));
            } else if (in[u] > in[v] && in[u] < out[v]) {
                res = fmin(res, calc(sum[0] ^ sum[v], sum[v] ^ sum[u], sum[u]));
            } else {
                res = fmin(res, calc(sum[0] ^ sum[u] ^ sum[v], sum[u], sum[v]));
            }
        }
    }

    for (int i = 0; i < numsSize; i++) {
        freeList(adj[i]);
    }
    free(sum);
    free(in);
    free(out);

    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int calc(int part1, int part2, int part3) {
        return max(part1, max(part2, part3)) - min(part1, min(part2, part3));
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), cnt = 0;
        vector<int> sum(n), in(n), out(n);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        function<void(int, int)> dfs = [&](int x, int fa) {
            in[x] = cnt++;
            sum[x] = nums[x];
            for (auto& y : adj[x]) {
                if (y == fa) {
                    continue;
                }
                dfs(y, x);
                sum[x] ^= sum[y];
            }
            out[x] = cnt;
        };

        dfs(0, -1);
        int res = INT_MAX;
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (in[v] > in[u] && in[v] < out[u]) {
                    res = min(res,
                              calc(sum[0] ^ sum[u], sum[u] ^ sum[v], sum[v]));
                } else if (in[u] > in[v] && in[u] < out[v]) {
                    res = min(res,
                              calc(sum[0] ^ sum[v], sum[v] ^ sum[u], sum[u]));
                } else {
                    res = min(res,
                              calc(sum[0] ^ sum[u] ^ sum[v], sum[u], sum[v]));
                }
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumScore(int[] nums, int[][] edges) {
        int n = nums.Length;
        List<List<int>> adj = new List<List<int>>();
        for (int i = 0; i < n; i++) {
            adj.Add(new List<int>());
        }
        foreach (var e in edges) {
            adj[e[0]].Add(e[1]);
            adj[e[1]].Add(e[0]);
        }

        int[] sum = new int[n];
        int[] in_ = new int[n];
        int[] out_ = new int[n];
        int cnt = 0;
        Dfs(0, -1, nums, adj, sum, in_, out_, ref cnt);

        int res = int.MaxValue;
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (in_[v] > in_[u] && in_[v] < out_[u]) {
                    res = Math.Min(
                        res, Calc(sum[0] ^ sum[u], sum[u] ^ sum[v], sum[v]));
                } else if (in_[u] > in_[v] && in_[u] < out_[v]) {
                    res = Math.Min(
                        res, Calc(sum[0] ^ sum[v], sum[v] ^ sum[u], sum[u]));
                } else {
                    res = Math.Min(
                        res, Calc(sum[0] ^ sum[u] ^ sum[v], sum[u], sum[v]));
                }
            }
        }
        return res;
    }

    private int Calc(int part1, int part2, int part3) {
        return Math.Max(part1, Math.Max(part2, part3)) -
               Math.Min(part1, Math.Min(part2, part3));
    }

    private void Dfs(int x, int fa, int[] nums, List<List<int>> adj, int[] sum,
                     int[] in_, int[] out_, ref int cnt) {
        in_[x] = cnt++;
        sum[x] = nums[x];
        foreach (int y in adj[x]) {
            if (y == fa) {
                continue;
            }
            Dfs(y, x, nums, adj, sum, in_, out_, ref cnt);
            sum[x] ^= sum[y];
        }
        out_[x] = cnt;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumScore(nums []int, edges [][]int) int {
	n := len(nums)
	adj := make([][]int, n)
	for _, e := range edges {
		adj[e[0]] = append(adj[e[0]], e[1])
		adj[e[1]] = append(adj[e[1]], e[0])
	}

	sum := make([]int, n)
	in := make([]int, n)
	out := make([]int, n)
	cnt := 0

	var dfs func(int, int)
	dfs = func(x, fa int) {
		in[x] = cnt
		cnt++
		sum[x] = nums[x]
		for _, y := range adj[x] {
			if y == fa {
				continue
			}
			dfs(y, x)
			sum[x] ^= sum[y]
		}
		out[x] = cnt
	}

	dfs(0, -1)

	res := math.MaxInt32
	for u := 1; u < n; u++ {
		for v := u + 1; v < n; v++ {
			if in[v] > in[u] && in[v] < out[u] {
				res = min(res, calc(sum[0]^sum[u], sum[u]^sum[v], sum[v]))
			} else if in[u] > in[v] && in[u] < out[v] {
				res = min(res, calc(sum[0]^sum[v], sum[v]^sum[u], sum[u]))
			} else {
				res = min(res, calc(sum[0]^sum[u]^sum[v], sum[u], sum[v]))
			}
		}
	}
	return res
}

func calc(part1, part2, part3 int) int {
	return max(part1, max(part2, part3)) - min(part1, min(part2, part3))
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }

        int[] sum = new int[n];
        int[] in = new int[n];
        int[] out = new int[n];
        int[] cnt = { 0 };

        dfs(0, -1, nums, adj, sum, in, out, cnt);
        int res = Integer.MAX_VALUE;
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (in[v] > in[u] && in[v] < out[u]) {
                    res = Math.min(
                        res,
                        calc(sum[0] ^ sum[u], sum[u] ^ sum[v], sum[v])
                    );
                } else if (in[u] > in[v] && in[u] < out[v]) {
                    res = Math.min(
                        res,
                        calc(sum[0] ^ sum[v], sum[v] ^ sum[u], sum[u])
                    );
                } else {
                    res = Math.min(
                        res,
                        calc(sum[0] ^ sum[u] ^ sum[v], sum[u], sum[v])
                    );
                }
            }
        }
        return res;
    }

    private int calc(int part1, int part2, int part3) {
        return (
            Math.max(part1, Math.max(part2, part3)) -
            Math.min(part1, Math.min(part2, part3))
        );
    }

    private void dfs(
        int x,
        int fa,
        int[] nums,
        List<List<Integer>> adj,
        int[] sum,
        int[] in,
        int[] out,
        int[] cnt
    ) {
        in[x] = cnt[0]++;
        sum[x] = nums[x];
        for (int y : adj.get(x)) {
            if (y == fa) {
                continue;
            }
            dfs(y, x, nums, adj, sum, in, out, cnt);
            sum[x] ^= sum[y];
        }
        out[x] = cnt[0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumScore = function (nums, edges) {
    const n = nums.length;
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }

    const sum = new Array(n).fill(0);
    const in_ = new Array(n).fill(0);
    const out = new Array(n).fill(0);
    let cnt = 0;

    function dfs(x, fa) {
        in_[x] = cnt++;
        sum[x] = nums[x];
        for (const y of adj[x]) {
            if (y === fa) continue;
            dfs(y, x);
            sum[x] ^= sum[y];
        }
        out[x] = cnt;
    }

    dfs(0, -1);

    let res = Infinity;
    for (let u = 1; u < n; u++) {
        for (let v = u + 1; v < n; v++) {
            if (in_[v] > in_[u] && in_[v] < out[u]) {
                res = Math.min(
                    res,
                    calc(sum[0] ^ sum[u], sum[u] ^ sum[v], sum[v]),
                );
            } else if (in_[u] > in_[v] && in_[u] < out[v]) {
                res = Math.min(
                    res,
                    calc(sum[0] ^ sum[v], sum[v] ^ sum[u], sum[u]),
                );
            } else {
                res = Math.min(
                    res,
                    calc(sum[0] ^ sum[u] ^ sum[v], sum[u], sum[v]),
                );
            }
        }
    }
    return res;
};

const calc = (part1, part2, part3) => {
    return (
        Math.max(part1, Math.max(part2, part3)) -
        Math.min(part1, Math.min(part2, part3))
    );
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def calc(self, a: int, b: int, c: int) -> int:
        return max(a, b, c) - min(a, b, c)

    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        cnt = 0
        sum_xor = [0] * n
        tin = [0] * n
        tout = [0] * n
        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def dfs(x: int, fa: int):
            nonlocal cnt
            tin[x] = cnt
            cnt += 1
            sum_xor[x] = nums[x]
            for y in adj[x]:
                if y == fa:
                    continue
                dfs(y, x)
                sum_xor[x] ^= sum_xor[y]
            tout[x] = cnt

        dfs(0, -1)

        res = float("inf")
        for u in range(1, n):
            for v in range(u + 1, n):
                if tin[v] > tin[u] and tin[v] < tout[u]:
                    res = min(
                        res,
                        self.calc(
                            sum_xor[0] ^ sum_xor[u],
                            sum_xor[u] ^ sum_xor[v],
                            sum_xor[v],
                        ),
                    )
                elif tin[u] > tin[v] and tin[u] < tout[v]:
                    res = min(
                        res,
                        self.calc(
                            sum_xor[0] ^ sum_xor[v],
                            sum_xor[v] ^ sum_xor[u],
                            sum_xor[u],
                        ),
                    )
                else:
                    res = min(
                        res,
                        self.calc(
                            sum_xor[0] ^ sum_xor[u] ^ sum_xor[v],
                            sum_xor[u],
                            sum_xor[v],
                        ),
                    )
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumScore(nums: number[], edges: number[][]): number {
    const n = nums.length;
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }

    const sum = new Array(n).fill(0);
    const in_ = new Array(n).fill(0);
    const out = new Array(n).fill(0);
    let cnt = 0;

    function dfs(x, fa) {
        in_[x] = cnt++;
        sum[x] = nums[x];
        for (const y of adj[x]) {
            if (y === fa) {
                continue;
            }
            dfs(y, x);
            sum[x] ^= sum[y];
        }
        out[x] = cnt;
    }

    dfs(0, -1);

    let res = Infinity;
    for (let u = 1; u < n; u++) {
        for (let v = u + 1; v < n; v++) {
            if (in_[v] > in_[u] && in_[v] < out[u]) {
                res = Math.min(
                    res,
                    calc(sum[0] ^ sum[u], sum[u] ^ sum[v], sum[v]),
                );
            } else if (in_[u] > in_[v] && in_[u] < out[v]) {
                res = Math.min(
                    res,
                    calc(sum[0] ^ sum[v], sum[v] ^ sum[u], sum[u]),
                );
            } else {
                res = Math.min(
                    res,
                    calc(sum[0] ^ sum[u] ^ sum[v], sum[u], sum[v]),
                );
            }
        }
    }
    return res;
}

function calc(part1, part2, part3) {
    return (
        Math.max(part1, Math.max(part2, part3)) -
        Math.min(part1, Math.min(part2, part3))
    );
}
```

</details>
