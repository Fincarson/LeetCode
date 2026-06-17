# 684. Redundant Connection

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/redundant-connection/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 684 - Redundant Connection](https://leetcode.com/problems/redundant-connection/)

## Problem

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

### Example 1

```text
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
```

### Example 2

```text
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
```

## Constraints

- n == edges.length
- 3 <= n <= 1000
- edges[i].length == 2
- 1 <= ai < bi <= edges.length
- ai != bi
- There are no repeated edges.
- The given graph is connected.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Redundant Connection II](https://leetcode.com/problems/redundant-connection-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Accounts Merge](https://leetcode.com/problems/accounts-merge/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Employees to Be Invited to a Meeting](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Shortest Cycle in a Graph](https://leetcode.com/problems/shortest-cycle-in-a-graph/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 684. Redundant Connection

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search - Brute Force | C++, Java, Python3 |
| Depth-First Search - Single Traversal | C++, Java, Python3 |
| Disjoint Set Union (DSU) | C++, Java, Python3 |

## Approach 1: Depth-First Search - Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Performs DFS and returns true if there's a path between src and target.
    bool isConnected(int src, int target, vector<bool>& visited,
                     vector<int> adjList[]) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        int isFound = false;
        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                isFound = isFound || isConnected(adj, target, visited, adjList);
            }
        }

        return isFound;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        vector<int> adjList[N];
        for (auto edge : edges) {
            vector<bool> visited(N, false);

            // If DFS returns true, we will return the edge.
            if (isConnected(edge[0] - 1, edge[1] - 1, visited, adjList)) {
                return edge;
            }

            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        return {};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Performs DFS and returns true if there's a path between src and target.
    private boolean isConnected(
        int src,
        int target,
        boolean[] visited,
        List<Integer>[] adjList
    ) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        boolean isFound = false;
        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                isFound = isFound || isConnected(adj, target, visited, adjList);
            }
        }

        return isFound;
    }

    public int[] findRedundantConnection(int[][] edges) {
        int N = edges.length;

        List<Integer>[] adjList = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adjList[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            boolean[] visited = new boolean[N];

            // If DFS returns true, we will return the edge.
            if (isConnected(edge[0] - 1, edge[1] - 1, visited, adjList)) {
                return new int[] { edge[0], edge[1] };
            }

            adjList[edge[0] - 1].add(edge[1] - 1);
            adjList[edge[1] - 1].add(edge[0] - 1);
        }

        return new int[] {};
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Performs DFS and returns True if there's a path between src and target.
    def _is_connected(self, src, target, visited, adj_list):
        visited[src] = True

        if src == target:
            return True

        is_found = False
        for adj in adj_list[src]:
            if not visited[adj]:
                is_found = is_found or self._is_connected(
                    adj, target, visited, adj_list
                )

        return is_found

    def findRedundantConnection(self, edges):
        N = len(edges)

        adj_list = [[] for _ in range(N)]

        for edge in edges:
            visited = [False] * N

            # If DFS returns True, we will return the edge.
            if self._is_connected(edge[0] - 1, edge[1] - 1, visited, adj_list):
                return edge

            adj_list[edge[0] - 1].append(edge[1] - 1)
            adj_list[edge[1] - 1].append(edge[0] - 1)

        return []
```

</details>

<br>

## Approach 2: Depth-First Search - Single Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int cycleStart = -1;

    // Peform the DFS and store a node in the cycle as cycleStart.
    void DFS(int src, vector<bool> &visited, vector<int> adjList[],
             vector<int> &parent) {
        visited[src] = true;

        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                parent[adj] = src;
                DFS(adj, visited, adjList, parent);
                // If the node is visited and the parent is different then the
                // node is part of the cycle.
            } else if (adj != parent[src] && cycleStart == -1) {
                cycleStart = adj;
                parent[adj] = src;
            }
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int N = edges.size();

        vector<bool> visited(N, false);
        vector<int> parent(N, -1);

        vector<int> adjList[N];
        for (auto edge : edges) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        DFS(0, visited, adjList, parent);

        unordered_map<int, int> cycleNodes;
        int node = cycleStart;
        // Start from the cycleStart node and backtrack to get all the nodes in
        // the cycle. Mark them all in the map.
        do {
            cycleNodes[node] = 1;
            node = parent[node];
        } while (node != cycleStart);

        // If both nodes of the edge were marked as cycle nodes then this edge
        // can be removed.
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (cycleNodes[edges[i][0] - 1] && cycleNodes[edges[i][1] - 1]) {
                return edges[i];
            }
        }

        return {};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    int cycleStart = -1;

    // Perform the DFS and store a node in the cycle as cycleStart.
    private void DFS(
        int src,
        boolean[] visited,
        List<Integer>[] adjList,
        int[] parent
    ) {
        visited[src] = true;

        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                parent[adj] = src;
                DFS(adj, visited, adjList, parent);
                // If the node is visited and the parent is different then the
                // node is part of the cycle.
            } else if (adj != parent[src] && cycleStart == -1) {
                cycleStart = adj;
                parent[adj] = src;
            }
        }
    }

    public int[] findRedundantConnection(int[][] edges) {
        int N = edges.length;

        boolean[] visited = new boolean[N];
        int[] parent = new int[N];
        Arrays.fill(parent, -1);

        List<Integer>[] adjList = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adjList[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            adjList[edge[0] - 1].add(edge[1] - 1);
            adjList[edge[1] - 1].add(edge[0] - 1);
        }

        DFS(0, visited, adjList, parent);

        Map<Integer, Integer> cycleNodes = new HashMap<>();
        int node = cycleStart;
        // Start from the cycleStart node and backtrack to get all the nodes in
        // the cycle. Mark them all in the map.
        do {
            cycleNodes.put(node, 1);
            node = parent[node];
        } while (node != cycleStart);

        // If both nodes of the edge were marked as cycle nodes then this edge
        // can be removed.
        for (int i = edges.length - 1; i >= 0; i--) {
            if (
                cycleNodes.containsKey(edges[i][0] - 1) &&
                cycleNodes.containsKey(edges[i][1] - 1)
            ) {
                return edges[i];
            }
        }

        return new int[] {}; // This line should theoretically never be reached
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    cycle_start = -1

    # Perform the DFS and store a node in the cycle as cycleStart.
    def _DFS(self, src, visited, adj_list, parent):
        visited[src] = True

        for adj in adj_list[src]:
            if not visited[adj]:
                parent[adj] = src
                self._DFS(adj, visited, adj_list, parent)
                # If the node is visited and the parent is different then the
                # node is part of the cycle.
            elif adj != parent[src] and self.cycle_start == -1:
                self.cycle_start = adj
                parent[adj] = src

    def findRedundantConnection(self, edges):
        N = len(edges)

        visited = [False] * N
        parent = [-1] * N

        adj_list = [[] for _ in range(N)]
        for edge in edges:
            adj_list[edge[0] - 1].append(edge[1] - 1)
            adj_list[edge[1] - 1].append(edge[0] - 1)

        self._DFS(0, visited, adj_list, parent)

        cycle_nodes = {}
        node = self.cycle_start
        # Start from the cycleStart node and backtrack to get all the nodes in
        # the cycle. Mark them all in the map.
        while True:
            cycle_nodes[node] = 1
            node = parent[node]
            if node == self.cycle_start:
                break

        # If both nodes of the edge were marked as cycle nodes then this edge
        # can be removed.
        for i in range(len(edges) - 1, -1, -1):
            if (edges[i][0] - 1) in cycle_nodes and (
                edges[i][1] - 1
            ) in cycle_nodes:
                return edges[i]

        return []  # This line should theoretically never be reached
```

</details>

<br>

## Approach 3: Disjoint Set Union (DSU)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    class DSU {
    private:
        int N;
        vector<int> size;
        vector<int> representative;

    public:
        // Initialize DSU class, size of each component will be one and each
        // node will be representative of it's own.
        DSU(int N) {
            this->N = N;

            for (int node = 0; node < N; node++) {
                size.push_back(1);
                representative.push_back(node);
            }
        }

        // Returns the ultimate representative of the node.
        int find(int node) {
            if (representative[node] == node) {
                return node;
            }

            return representative[node] = find(representative[node]);
        }

        // Returns true if nodeOne and nodeTwo belong to different component and
        // update the representatives accordingly, otherwise returns false.
        bool doUnion(int nodeOne, int nodeTwo) {
            nodeOne = find(nodeOne);
            nodeTwo = find(nodeTwo);

            if (nodeOne == nodeTwo) {
                return 0;
            } else {
                if (size[nodeOne] > size[nodeTwo]) {
                    representative[nodeTwo] = nodeOne;
                    size[nodeOne] += size[nodeTwo];
                } else {
                    representative[nodeOne] = nodeTwo;
                    size[nodeTwo] += size[nodeOne];
                }
                return 1;
            }
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        DSU dsu(N);
        for (auto edge : edges) {
            // If union returns false, we know the nodes are already connected
            // and hence we can return this edge.
            if (!dsu.doUnion(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return {};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    class DSU {

        private int N;
        private int[] size;
        private int[] representative;

        // Initialize DSU class, size of each component will be one and each node
        // will be representative of it's own.
        public DSU(int N) {
            this.N = N;
            size = new int[N];
            representative = new int[N];

            for (int node = 0; node < N; node++) {
                size[node] = 1;
                representative[node] = node;
            }
        }

        // Returns the ultimate representative of the node.
        public int find(int node) {
            if (representative[node] == node) {
                return node;
            }

            return representative[node] = find(representative[node]);
        }

        // Returns true if node nodeOne and nodeTwo belong to different component and update the
        // representatives accordingly, otherwise returns false.
        public boolean doUnion(int nodeOne, int nodeTwo) {
            nodeOne = find(nodeOne);
            nodeTwo = find(nodeTwo);

            if (nodeOne == nodeTwo) {
                return false;
            } else {
                if (size[nodeOne] > size[nodeTwo]) {
                    representative[nodeTwo] = nodeOne;
                    size[nodeOne] += size[nodeTwo];
                } else {
                    representative[nodeOne] = nodeTwo;
                    size[nodeTwo] += size[nodeOne];
                }
                return true;
            }
        }
    }

    public int[] findRedundantConnection(int[][] edges) {
        int N = edges.length;

        DSU dsu = new DSU(N);
        for (int[] edge : edges) {
            // If union returns false, we know the nodes are already connected
            // and hence we can return this edge.
            if (!dsu.doUnion(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return new int[] {}; // This line should theoretically never be reached
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class DSU:
    def __init__(self, N):
        # Initialize DSU class, size of each component will be one and each node
        # will be representative of its own.
        self.N = N
        self.size = [1] * N
        self.representative = list(range(N))

    def _find(self, node):
        # Returns the ultimate representative of the node.
        if self.representative[node] == node:
            return node
        self.representative[node] = self._find(self.representative[node])
        return self.representative[node]

    def _do_union(self, nodeOne, nodeTwo):
        # Returns true if node nodeOne and nodeTwo belong to different component and update the
        # representatives accordingly, otherwise returns false.
        nodeOne = self._find(nodeOne)
        nodeTwo = self._find(nodeTwo)

        if nodeOne == nodeTwo:
            return False
        else:
            if self.size[nodeOne] > self.size[nodeTwo]:
                self.representative[nodeTwo] = nodeOne
                self.size[nodeOne] += self.size[nodeTwo]
            else:
                self.representative[nodeOne] = nodeTwo
                self.size[nodeTwo] += self.size[nodeOne]
            return True


class Solution:
    def findRedundantConnection(self, edges):
        N = len(edges)

        dsu = DSU(N)
        for edge in edges:
            # If union returns false, we know the nodes are already connected
            # and hence we can return this edge.
            if not dsu._do_union(edge[0] - 1, edge[1] - 1):
                return edge

        return []
```

</details>
