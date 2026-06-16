# 3372. Maximize the Number of Target Nodes After Connecting Trees I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/)  
`Tree` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 3372 - Maximize the Number of Target Nodes After Connecting Trees I](https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/)

## Problem

There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.

Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

### Example 1

### Example 2

## Constraints

- 2 <= n, m <= 1000
- edges1.length == n - 1
- edges2.length == m - 1
- edges1[i].length == edges2[i].length == 2
- edges1[i] = [ai, bi]
- 0 <= ai, bi < n
- edges2[i] = [ui, vi]
- 0 <= ui, vi < m
- The input is generated such that edges1 and edges2 represent valid trees.
- 0 <= k <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Minimum Diameter After Merging Two Trees](https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3372. Maximize the Number of Target Nodes After Connecting Trees I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Depth-First Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Depth-First Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int dfs(int node, int parent, int** children, int* childrenColSize, int k) {
    if (k < 0) {
        return 0;
    }
    int res = 1;
    for (int i = 0; i < childrenColSize[node]; i++) {
        int child = children[node][i];
        if (child == parent) {
            continue;
        }
        res += dfs(child, node, children, childrenColSize, k - 1);
    }
    return res;
}

int* build(int** edges, int edgesSize, int k) {
    int n = edgesSize + 1;
    int** children = (int**)malloc(n * sizeof(int*));
    int* childrenColSize = (int*)malloc(n * sizeof(int));
    memset(childrenColSize, 0, n * sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        childrenColSize[edges[i][0]]++;
        childrenColSize[edges[i][1]]++;
    }
    for (int i = 0; i < n; i++) {
        children[i] = (int*)malloc(childrenColSize[i] * sizeof(int));
        childrenColSize[i] = 0;
    }
    for (int i = 0; i < edgesSize; i++) {
        children[edges[i][0]][childrenColSize[edges[i][0]]++] = edges[i][1];
        children[edges[i][1]][childrenColSize[edges[i][1]]++] = edges[i][0];
    }
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = dfs(i, -1, children, childrenColSize, k);
    }
    for (int i = 0; i < n; i++) {
        free(children[i]);
    }
    free(children);
    free(childrenColSize);
    return res;
}

int* maxTargetNodes(int** edges1, int edges1Size, int* edges1ColSize,
                    int** edges2, int edges2Size, int* edges2ColSize, int k,
                    int* returnSize) {
    int n = edges1Size + 1;
    int* count1 = build(edges1, edges1Size, k);
    int* count2 = build(edges2, edges2Size, k - 1);
    int maxCount = 0;
    for (int i = 0; i < edges2Size + 1; i++) {
        if (count2[i] > maxCount) {
            maxCount = count2[i];
        }
    }
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = count1[i] + maxCount;
    }
    *returnSize = n;
    free(count1);
    free(count2);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int dfs(int node, int parent, const vector<vector<int>>& children, int k) {
        if (k < 0) {
            return 0;
        }
        int res = 1;
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, children, k - 1);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const auto& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = dfs(i, -1, children, k);
        }
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> count1 = build(edges1, k);
        vector<int> count2 = build(edges2, k - 1);
        int maxCount2 = *max_element(count2.begin(), count2.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = count1[i] + maxCount2;
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
    public int[] MaxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        int n = edges1.Length + 1, m = edges2.Length + 1;
        int[] count1 = Build(edges1, k);
        int[] count2 = Build(edges2, k - 1);
        int maxCount2 = 0;
        foreach (int c in count2) {
            if (c > maxCount2) {
                maxCount2 = c;
            }
        }
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = count1[i] + maxCount2;
        }
        return res;
    }

    private int[] Build(int[][] edges, int k) {
        int n = edges.Length + 1;
        List<List<int>> children = new List<List<int>>();
        for (int i = 0; i < n; i++) {
            children.Add(new List<int>());
        }
        foreach (var edge in edges) {
            children[edge[0]].Add(edge[1]);
            children[edge[1]].Add(edge[0]);
        }
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = Dfs(i, -1, children, k);
        }
        return res;
    }

    private int Dfs(int node, int parent, List<List<int>> children, int k) {
        if (k < 0) {
            return 0;
        }
        int res = 1;
        foreach (int child in children[node]) {
            if (child == parent) {
                continue;
            }
            res += Dfs(child, node, children, k - 1);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxTargetNodes(edges1 [][]int, edges2 [][]int, k int) []int {
	var dfs func(node, parent int, children [][]int, k int) int
	dfs = func(node, parent int, children [][]int, k int) int {
		if k < 0 {
			return 0
		}
		res := 1
		for _, child := range children[node] {
			if child == parent {
				continue
			}
			res += dfs(child, node, children, k-1)
		}
		return res
	}

	build := func(edges [][]int, k int) []int {
		n := len(edges) + 1
		children := make([][]int, n)
		for _, edge := range edges {
			u, v := edge[0], edge[1]
			children[u] = append(children[u], v)
			children[v] = append(children[v], u)
		}
		res := make([]int, n)
		for i := 0; i < n; i++ {
			res[i] = dfs(i, -1, children, k)
		}
		return res
	}

	n := len(edges1) + 1
	count1 := build(edges1, k)
	count2 := build(edges2, k-1)
	maxCount2 := 0
	for _, c := range count2 {
		if c > maxCount2 {
			maxCount2 = c
		}
	}
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = count1[i] + maxCount2
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        int n = edges1.length + 1, m = edges2.length + 1;
        int[] count1 = build(edges1, k);
        int[] count2 = build(edges2, k - 1);
        int maxCount2 = 0;
        for (int c : count2) {
            if (c > maxCount2) {
                maxCount2 = c;
            }
        }
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = count1[i] + maxCount2;
        }
        return res;
    }

    private int[] build(int[][] edges, int k) {
        int n = edges.length + 1;
        List<List<Integer>> children = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            children.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            children.get(edge[0]).add(edge[1]);
            children.get(edge[1]).add(edge[0]);
        }
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = dfs(i, -1, children, k);
        }
        return res;
    }

    private int dfs(int node, int parent, List<List<Integer>> children, int k) {
        if (k < 0) {
            return 0;
        }
        int res = 1;
        for (int child : children.get(node)) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, children, k - 1);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxTargetNodes = function (edges1, edges2, k) {
    const dfs = (node, parent, children, k) => {
        if (k < 0) {
            return 0;
        }
        let res = 1;
        for (const child of children[node]) {
            if (child === parent) {
                continue;
            }
            res += dfs(child, node, children, k - 1);
        }
        return res;
    };

    const build = (edges, k) => {
        const n = edges.length + 1;
        const children = Array.from({ length: n }, () => []);
        for (const [u, v] of edges) {
            children[u].push(v);
            children[v].push(u);
        }
        const res = Array(n);
        for (let i = 0; i < n; i++) {
            res[i] = dfs(i, -1, children, k);
        }
        return res;
    };

    const n = edges1.length + 1;
    const count1 = build(edges1, k);
    const count2 = build(edges2, k - 1);
    const maxCount2 = Math.max(...count2);
    const res = Array(n);
    for (let i = 0; i < n; i++) {
        res[i] = count1[i] + maxCount2;
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxTargetNodes(
        self, edges1: List[List[int]], edges2: List[List[int]], k: int
    ) -> List[int]:
        def dfs(
            node: int, parent: int, children: List[List[int]], k: int
        ) -> int:
            if k < 0:
                return 0
            res = 1
            for child in children[node]:
                if child == parent:
                    continue
                res += dfs(child, node, children, k - 1)
            return res

        def build(edges: List[List[int]], k: int) -> List[int]:
            n = len(edges) + 1
            children = [[] for _ in range(n)]
            for u, v in edges:
                children[u].append(v)
                children[v].append(u)
            res = [0] * n
            for i in range(n):
                res[i] = dfs(i, -1, children, k)
            return res

        n = len(edges1) + 1
        count1 = build(edges1, k)
        count2 = build(edges2, k - 1)
        maxCount2 = max(count2)
        res = [count1[i] + maxCount2 for i in range(n)]
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxTargetNodes(
    edges1: number[][],
    edges2: number[][],
    k: number,
): number[] {
    function dfs(
        node: number,
        parent: number,
        children: number[][],
        k: number,
    ): number {
        if (k < 0) {
            return 0;
        }
        let res = 1;
        for (const child of children[node]) {
            if (child === parent) {
                continue;
            }
            res += dfs(child, node, children, k - 1);
        }
        return res;
    }

    function build(edges: number[][], k: number): number[] {
        const n = edges.length + 1;
        const children: number[][] = Array.from({ length: n }, () => []);
        for (const [u, v] of edges) {
            children[u].push(v);
            children[v].push(u);
        }
        const res: number[] = Array(n);
        for (let i = 0; i < n; i++) {
            res[i] = dfs(i, -1, children, k);
        }
        return res;
    }

    const n = edges1.length + 1;
    const count1 = build(edges1, k);
    const count2 = build(edges2, k - 1);
    const maxCount2 = Math.max(...count2);
    const res: number[] = Array(n);
    for (let i = 0; i < n; i++) {
        res[i] = count1[i] + maxCount2;
    }
    return res;
}
```

</details>
