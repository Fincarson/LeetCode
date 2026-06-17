# 3373. Maximize the Number of Target Nodes After Connecting Trees II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/)  
`Tree` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 3373 - Maximize the Number of Target Nodes After Connecting Trees II](https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/)

## Problem

There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

### Example 1

### Example 2

## Constraints

- 2 <= n, m <= 105
- edges1.length == n - 1
- edges2.length == m - 1
- edges1[i].length == edges2[i].length == 2
- edges1[i] = [ai, bi]
- 0 <= ai, bi < n
- edges2[i] = [ui, vi]
- 0 <= ui, vi < m
- The input is generated such that edges1 and edges2 represent valid trees.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Minimum Diameter After Merging Two Trees](https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3373. Maximize the Number of Target Nodes After Connecting Trees II

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
int dfs(int node, int parent, int depth, int** children, int* childrenColSize,
        int* color) {
    int res = 1 - depth % 2;
    color[node] = depth % 2;
    for (int i = 0; i < childrenColSize[node]; i++) {
        int child = children[node][i];
        if (child == parent) continue;
        res += dfs(child, node, depth + 1, children, childrenColSize, color);
    }
    return res;
}

int* build(int** edges, int edgesSize, int* color) {
    int n = edgesSize + 1;
    int** children = (int**)malloc(n * sizeof(int*));
    int* childrenColSize = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        childrenColSize[edges[i][0]]++;
        childrenColSize[edges[i][1]]++;
    }
    for (int i = 0; i < n; i++) {
        children[i] = (int*)malloc(childrenColSize[i] * sizeof(int));
        childrenColSize[i] = 0;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        children[u][childrenColSize[u]++] = v;
        children[v][childrenColSize[v]++] = u;
    }
    int res = dfs(0, -1, 0, children, childrenColSize, color);
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = res;
    result[1] = n - res;
    for (int i = 0; i < n; i++) {
        free(children[i]);
    }
    free(children);
    free(childrenColSize);
    return result;
}

int* maxTargetNodes(int** edges1, int edges1Size, int* edges1ColSize,
                    int** edges2, int edges2Size, int* edges2ColSize,
                    int* returnSize) {
    int n = edges1Size + 1;
    int m = edges2Size + 1;
    int* color1 = (int*)calloc(n, sizeof(int));
    int* color2 = (int*)calloc(m, sizeof(int));
    int* count1 = build(edges1, edges1Size, color1);
    int* count2 = build(edges2, edges2Size, color2);
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] =
            count1[color1[i]] + (count2[0] > count2[1] ? count2[0] : count2[1]);
    }
    *returnSize = n;
    free(color1);
    free(color2);
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
    int dfs(int node, int parent, int depth,
            const vector<vector<int>>& children, vector<int>& color) {
        int res = 1 - depth % 2;
        color[node] = depth % 2;
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, depth + 1, children, color);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, vector<int>& color) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const auto& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        int res = dfs(0, -1, 0, children, color);
        return {res, n - res};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> color1(n);
        vector<int> color2(m);
        vector<int> count1 = build(edges1, color1);
        vector<int> count2 = build(edges2, color2);
        vector<int> res(edges1.size() + 1);
        for (int i = 0; i < n; i++) {
            res[i] = count1[color1[i]] + max(count2[0], count2[1]);
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
    public int[] MaxTargetNodes(int[][] edges1, int[][] edges2) {
        int n = edges1.Length + 1, m = edges2.Length + 1;
        int[] color1 = new int[n];
        int[] color2 = new int[m];
        int[] count1 = Build(edges1, color1);
        int[] count2 = Build(edges2, color2);
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = count1[color1[i]] + Math.Max(count2[0], count2[1]);
        }
        return res;
    }

    private int[] Build(int[][] edges, int[] color) {
        int n = edges.Length + 1;
        List<int>[] children = new List<int>[n];
        for (int i = 0; i < n; i++) {
            children[i] = new List<int>();
        }
        foreach (var edge in edges) {
            children[edge[0]].Add(edge[1]);
            children[edge[1]].Add(edge[0]);
        }
        int res = Dfs(0, -1, 0, children, color);
        return new int[] { res, n - res };
    }

    private int Dfs(int node, int parent, int depth, List<int>[] children,
                    int[] color) {
        int res = 1 - depth % 2;
        color[node] = depth % 2;
        foreach (int child in children[node]) {
            if (child == parent) {
                continue;
            }
            res += Dfs(child, node, depth + 1, children, color);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxTargetNodes(edges1 [][]int, edges2 [][]int) []int {
	var dfs func(node, parent, depth int, children [][]int, color []int) int
	dfs = func(node, parent, depth int, children [][]int, color []int) int {
		res := 1 - depth%2
		color[node] = depth % 2
		for _, child := range children[node] {
			if child == parent {
				continue
			}
			res += dfs(child, node, depth+1, children, color)
		}
		return res
	}

	build := func(edges [][]int, color []int) []int {
		n := len(edges) + 1
		children := make([][]int, n)
		for _, edge := range edges {
			u, v := edge[0], edge[1]
			children[u] = append(children[u], v)
			children[v] = append(children[v], u)
		}
		res := dfs(0, -1, 0, children, color)
		return []int{res, n - res}
	}

	n := len(edges1) + 1
	m := len(edges2) + 1
	color1 := make([]int, n)
	color2 := make([]int, m)
	count1 := build(edges1, color1)
	count2 := build(edges2, color2)
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = count1[color1[i]] + max(count2[0], count2[1])
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
        int n = edges1.length + 1, m = edges2.length + 1;
        int[] color1 = new int[n];
        int[] color2 = new int[m];
        int[] count1 = build(edges1, color1);
        int[] count2 = build(edges2, color2);
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = count1[color1[i]] + Math.max(count2[0], count2[1]);
        }
        return res;
    }

    private int[] build(int[][] edges, int[] color) {
        int n = edges.length + 1;
        List<List<Integer>> children = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            children.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            children.get(edge[0]).add(edge[1]);
            children.get(edge[1]).add(edge[0]);
        }
        int res = dfs(0, -1, 0, children, color);
        return new int[] { res, n - res };
    }

    private int dfs(
        int node,
        int parent,
        int depth,
        List<List<Integer>> children,
        int[] color
    ) {
        int res = 1 - (depth % 2);
        color[node] = depth % 2;
        for (int child : children.get(node)) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, depth + 1, children, color);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxTargetNodes = function (edges1, edges2) {
    function dfs(node, parent, depth, children, color) {
        let res = 1 - (depth % 2);
        color[node] = depth % 2;
        for (let child of children[node]) {
            if (child === parent) {
                continue;
            }
            res += dfs(child, node, depth + 1, children, color);
        }
        return res;
    }

    function build(edges, color) {
        const n = edges.length + 1;
        const children = Array.from({ length: n }, () => []);
        for (const [u, v] of edges) {
            children[u].push(v);
            children[v].push(u);
        }
        const res = dfs(0, -1, 0, children, color);
        return [res, n - res];
    }

    const n = edges1.length + 1;
    const m = edges2.length + 1;
    const color1 = new Array(n).fill(0);
    const color2 = new Array(m).fill(0);
    const count1 = build(edges1, color1);
    const count2 = build(edges2, color2);
    const res = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        res[i] = count1[color1[i]] + Math.max(count2[0], count2[1]);
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
        self, edges1: List[List[int]], edges2: List[List[int]]
    ) -> List[int]:
        def dfs(node, parent, depth, children, color):
            res = 1 - depth % 2
            color[node] = depth % 2
            for child in children[node]:
                if child == parent:
                    continue
                res += dfs(child, node, depth + 1, children, color)
            return res

        def build(edges, color):
            n = len(edges) + 1
            children = [[] for _ in range(n)]
            for u, v in edges:
                children[u].append(v)
                children[v].append(u)
            res = dfs(0, -1, 0, children, color)
            return [res, n - res]

        n = len(edges1) + 1
        m = len(edges2) + 1
        color1 = [0] * n
        color2 = [0] * m
        count1 = build(edges1, color1)
        count2 = build(edges2, color2)
        res = [0] * n
        for i in range(n):
            res[i] = count1[color1[i]] + max(count2[0], count2[1])
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxTargetNodes(edges1: number[][], edges2: number[][]): number[] {
    function dfs(
        node: number,
        parent: number,
        depth: number,
        children: number[][],
        color: number[],
    ): number {
        let res = 1 - (depth % 2);
        color[node] = depth % 2;
        for (let child of children[node]) {
            if (child === parent) {
                continue;
            }
            res += dfs(child, node, depth + 1, children, color);
        }
        return res;
    }

    function build(edges: number[][], color: number[]): number[] {
        const n = edges.length + 1;
        const children: number[][] = Array.from({ length: n }, () => []);
        for (const [u, v] of edges) {
            children[u].push(v);
            children[v].push(u);
        }
        const res = dfs(0, -1, 0, children, color);
        return [res, n - res];
    }

    const n = edges1.length + 1;
    const m = edges2.length + 1;
    const color1: number[] = new Array(n).fill(0);
    const color2: number[] = new Array(m).fill(0);
    const count1 = build(edges1, color1);
    const count2 = build(edges2, color2);
    const res: number[] = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        res[i] = count1[color1[i]] + Math.max(count2[0], count2[1]);
    }
    return res;
}
```

</details>
