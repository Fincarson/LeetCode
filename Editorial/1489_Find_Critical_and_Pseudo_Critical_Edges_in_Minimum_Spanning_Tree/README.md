# 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)  
`Union-Find` `Graph Theory` `Sorting` `Minimum Spanning Tree` `Strongly Connected Component`

**Problem Link:** [LeetCode 1489 - Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)

## Problem

Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

### Example 1

```text
Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:

Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
```

### Example 2

```text
Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
```

## Constraints

- 2 <= n <= 100
- 1 <= edges.length <= min(200, n * (n - 1) / 2)
- edges[i].length == 3
- 0 <= ai < bi < n
- 1 <= weighti <= 1000
- All pairs (ai, bi) are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Kruskal's Algorithm | C++, Java, Python3 |

## Approach 1: Kruskal's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;
        int maxSize;

        UnionFind(int n) {
            parent.resize(n);
            size.resize(n, 1);
            maxSize = 1;
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            // Finds the root of x
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int x, int y) {
            // Connects x and y
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (size[rootX] < size[rootY]) {
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                maxSize = max(maxSize, size[rootX]);
                return true;
            }
            return false;
        }
    };

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        auto newEdges = edges;
        // Add index to edges for tracking
        int m = newEdges.size();
        for (int i = 0; i < m; i++) {
            newEdges[i].push_back(i);
        }

        // Sort edges based on weight
        sort(newEdges.begin(), newEdges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        // Find MST weight using union-find
        UnionFind ufStd(n);
        int stdWeight = 0;
        for (const auto& edge : newEdges) {
            if (ufStd.unite(edge[0], edge[1])) {
                stdWeight += edge[2];
            }
        }

        vector<vector<int>> results(2);
        // Check each edge for critical and pseudo-critical
        for (int i = 0; i < m; i++) {
            UnionFind ufIgnore(n);
            int ignoreWeight = 0;
            for (int j = 0; j < m; j++) {
                if (i != j && ufIgnore.unite(newEdges[j][0], newEdges[j][1])) {
                    ignoreWeight += newEdges[j][2];
                }
            }

            // If the graph is disconnected or the total weight is greater, 
            // the edge is critical
            if (ufIgnore.maxSize < n || ignoreWeight > stdWeight) {
                results[0].push_back(newEdges[i][3]);
            } else {
                // Force this edge and calculate MST weight
                UnionFind ufForce(n);
                ufForce.unite(newEdges[i][0], newEdges[i][1]);
                int forceWeight = newEdges[i][2];
                for (int j = 0; j < m; j++) {
                    if (i != j && ufForce.unite(newEdges[j][0], newEdges[j][1])) {
                        forceWeight += newEdges[j][2];
                    }
                }

                // If total weight is the same, the edge is pseudo-critical
                if (forceWeight == stdWeight) {
                    results[1].push_back(newEdges[i][3]);
                }
            }
        }

        return results;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        // Add index to edges for tracking
        int m = edges.length;
        int[][] newEdges = new int[m][4];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                newEdges[i][j] = edges[i][j];
            }
            newEdges[i][3] = i;
        }

        // Sort edges based on weight
        Arrays.sort(newEdges, Comparator.comparingInt(edge -> edge[2]));

        // Find MST weight using union-find
        UnionFind ufStd = new UnionFind(n);
        int stdWeight = 0;
        for (int[] edge : newEdges) {
            if (ufStd.union(edge[0], edge[1])) {
                stdWeight += edge[2];
            }
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < 2; i++) {
            result.add(new ArrayList<>());
        }

        // Check each edge for critical and pseudo-critical
        for (int i = 0; i < m; i++) {
            // Ignore this edge and calculate MST weight
            UnionFind ufIgnore = new UnionFind(n);
            int ignoreWeight = 0;
            for (int j = 0; j < m; j++) {
                if (i != j && ufIgnore.union(newEdges[j][0], newEdges[j][1])) {
                    ignoreWeight += newEdges[j][2];
                }
            }
            // If the graph is disconnected or the total weight is greater, 
            // the edge is critical
            if (ufIgnore.maxSize < n || ignoreWeight > stdWeight) {
                result.get(0).add(newEdges[i][3]);
            } else {
                // Force this edge and calculate MST weight
                UnionFind ufForce = new UnionFind(n);
                ufForce.union(newEdges[i][0], newEdges[i][1]);
                int forceWeight = newEdges[i][2];
                for (int j = 0; j < m; j++) {
                    if (i != j && ufForce.union(newEdges[j][0], newEdges[j][1])) {
                        forceWeight += newEdges[j][2];
                    }
                }
                // If total weight is the same, the edge is pseudo-critical
                if (forceWeight == stdWeight) {
                    result.get(1).add(newEdges[i][3]);
                }
            }
        }

        return result;
    }

    class UnionFind {
        int[] parent;
        int[] size;
        int maxSize;

        public UnionFind(int n) {
            parent = new int[n];
            size = new int[n];
            maxSize = 1;
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        public int find(int x) {
            // Finds the root of x
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        public boolean union(int x, int y) {
            // Connects x and y
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (size[rootX] < size[rootY]) {
                    int temp = rootX;
                    rootX = rootY;
                    rootY = temp;
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                maxSize = Math.max(maxSize, size[rootX]);
                return true;
            }
            return false;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    class UnionFind:
        def __init__(self, n):
            self.parent = list(range(n))
            self.size = [1] * n
            self.max_size = 1

        def find(self, x):
            # Finds the root of x
            if x != self.parent[x]:
                self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

        def union(self, x, y):
            # Connects x and y
            root_x = self.find(x)
            root_y = self.find(y)
            if root_x != root_y:
                if self.size[root_x] < self.size[root_y]:
                    root_x, root_y = root_y, root_x
                self.parent[root_y] = root_x
                self.size[root_x] += self.size[root_y]
                self.max_size = max(self.max_size, self.size[root_x])
                return True
            return False

    def findCriticalAndPseudoCriticalEdges(self, n, edges):
        new_edges = [edge.copy() for edge in edges]
        # Add index to edges for tracking
        for i, edge in enumerate(new_edges):
            edge.append(i)
        # Sort edges based on weight
        new_edges.sort(key=lambda x: x[2])

        # Find MST weight using union-find
        uf_std = self.UnionFind(n)
        std_weight = 0
        for u, v, w, _ in new_edges:
            if uf_std.union(u, v):
                std_weight += w

        # Check each edge for critical and pseudo-critical
        critical = []
        pseudo_critical = []
        for (u, v, w, i) in new_edges:
            # Ignore this edge and calculate MST weight
            uf_ignore = self.UnionFind(n)
            ignore_weight = 0
            for (x, y, w_ignore, j) in new_edges:
                if i != j and uf_ignore.union(x, y):
                    ignore_weight += w_ignore
            # If the graph is disconnected or the total weight is greater,
            # the edge is critical
            if uf_ignore.max_size < n or ignore_weight > std_weight:
                critical.append(i)
                continue

            # Force this edge and calculate MST weight
            uf_force = self.UnionFind(n)
            force_weight = w
            uf_force.union(u, v)
            for (x, y, w_force, j) in new_edges:
                if i != j and uf_force.union(x, y):
                    force_weight += w_force
            # If total weight is the same, the edge is pseudo-critical
            if force_weight == std_weight:
                pseudo_critical.append(i)

        return [critical, pseudo_critical]
```

</details>
