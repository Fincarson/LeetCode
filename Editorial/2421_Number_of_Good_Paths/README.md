# 2421. Number of Good Paths

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/number-of-good-paths/)  
`Array` `Hash Table` `Tree` `Union-Find` `Graph Theory` `Sorting`

**Problem Link:** [LeetCode 2421 - Number of Good Paths](https://leetcode.com/problems/number-of-good-paths/)

## Problem

There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

### Example 1

```text
Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].
```

### Example 2

```text
Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
Output: 7
Explanation: There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -> 1 and 2 -> 3.
```

### Example 3

```text
Input: vals = [1], edges = []
Output: 1
Explanation: The tree consists of only one node, so there is one good path.
```

## Constraints

- n == vals.length
- 1 <= n <= 3 * 104
- 0 <= vals[i] <= 105
- edges.length == n - 1
- edges[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- edges represents a valid tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Checking Existence of Edge Length Limited Paths](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Checking Existence of Edge Length Limited Paths II](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Longest Nice Substring](https://leetcode.com/problems/longest-nice-substring/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Pairs Of Similar Strings](https://leetcode.com/problems/count-pairs-of-similar-strings/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2421. Number of Good Paths

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Union-Find | C++, Java |

## Approach: Union-Find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // Mapping from value to all the nodes having the same value in non-descending order of values.
        map<int, vector<int>> valuesToNodes;
        for (int node = 0; node < n; node++) {
            valuesToNodes[vals[node]].push_back(node);
        }

        UnionFind dsu(n);
        int goodPaths = 0;

        // Iterate over all the nodes with the same value in sorted order, starting from the lowest
        // value.
        for (auto& [value, nodes] : valuesToNodes) {
            // For every node in nodes, combine the sets of the node and its neighbors into one set.
            for (int node : nodes) {
                for (int neighbor : adj[node]) {
                    // Only choose neighbors with a smaller value, as there is no point in
                    // traversing to other neighbors.
                    if (vals[node] >= vals[neighbor]) {
                        dsu.union_set(node, neighbor);
                    }
                }
            }
            // Map to compute the number of nodes under observation (with the same values) in each
            // of the sets.
            unordered_map<int, int> group;
            // Iterate over all the nodes. Get the set of each node and increase the count of the
            // set by 1.
            for (int u : nodes) {
                group[dsu.find(u)]++;
            }
            // For each set of "size", add size * (size + 1) / 2 to the number of goodPaths.
            for (auto& [_, size] : group) {
                goodPaths += (size * (size + 1) / 2);
            }
        }
        return goodPaths;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class UnionFind {
    int[] parent;
    int[] rank;

    public UnionFind(int size) {
        parent = new int[size];
        for (int i = 0; i < size; i++)
            parent[i] = i;
        rank = new int[size];
    }

    public int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    public void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
}

class Solution {
    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }

        int n = vals.length;
        // Mapping from value to all the nodes having the same value in sorted order of
        // values.
        TreeMap<Integer, List<Integer>> valuesToNodes = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            valuesToNodes.computeIfAbsent(vals[i], value -> new ArrayList<Integer>()).add(i);
        }

        UnionFind dsu = new UnionFind(n);
        int goodPaths = 0;

        // Iterate over all the nodes with the same value in sorted order, starting from
        // the lowest value.
        for (int value : valuesToNodes.keySet()) {
            // For every node in nodes, combine the sets of the node and its neighbors into
            // one set.
            for (int node : valuesToNodes.get(value)) {
                if (!adj.containsKey(node))
                    continue;
                for (int neighbor : adj.get(node)) {
                    // Only choose neighbors with a smaller value, as there is no point in
                    // traversing to other neighbors.
                    if (vals[node] >= vals[neighbor]) {
                        dsu.union_set(node, neighbor);
                    }
                }
            }
            // Map to compute the number of nodes under observation (with the same values)
            // in each of the sets.
            Map<Integer, Integer> group = new HashMap<>();
            // Iterate over all the nodes. Get the set of each node and increase the count
            // of the set by 1.
            for (int u : valuesToNodes.get(value)) {
                group.put(dsu.find(u), group.getOrDefault(dsu.find(u), 0) + 1);
            }
            // For each set of "size", add size * (size + 1) / 2 to the number of goodPaths.
            for (int key : group.keySet()) {
                int size = group.get(key);
                goodPaths += size * (size + 1) / 2;
            }
        }
        return goodPaths;
    }
}
```

</details>
