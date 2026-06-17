# 947. Most Stones Removed with Same Row or Column

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)  
`Hash Table` `Depth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 947 - Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)

## Problem

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

### Example 1

```text
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
```

### Example 2

```text
Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
```

### Example 3

```text
Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
```

## Constraints

- 1 <= stones.length <= 1000
- 0 <= xi, yi <= 104
- No two stones are at the same coordinate point.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Moves to Get a Peaceful Board](https://leetcode.com/problems/minimum-moves-to-get-a-peaceful-board/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 947. Most Stones Removed with Same Row or Column

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java, Python3 |
| Disjoint Set Union | C++, Java, Python3 |
| Disjoint Set Union (Optimized) | C++, Java, Python3 |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        // Adjacency list to store graph connections
        vector<vector<int>> adjacencyList(n);

        // Build the graph: Connect stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }

        int numOfConnectedComponents = 0;
        vector<bool> visited(n, false);

        // Traverse all stones using DFS to count connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                depthFirstSearch(adjacencyList, visited, i);
                numOfConnectedComponents++;
            }
        }

        // Maximum stones that can be removed is total stones minus number of
        // connected components
        return n - numOfConnectedComponents;
    }

private:
    // DFS to visit all stones in a connected component
    void depthFirstSearch(vector<vector<int>>& adjacencyList,
                          vector<bool>& visited, int stone) {
        visited[stone] = true;

        for (int neighbor : adjacencyList[stone]) {
            if (!visited[neighbor]) {
                depthFirstSearch(adjacencyList, visited, neighbor);
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int removeStones(int[][] stones) {
        int n = stones.length;

        // Adjacency list to store graph connections
        List<Integer>[] adjacencyList = new List[n];
        for (int i = 0; i < n; i++) {
            adjacencyList[i] = new ArrayList<>();
        }

        // Build the graph: Connect stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (
                    stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]
                ) {
                    adjacencyList[i].add(j);
                    adjacencyList[j].add(i);
                }
            }
        }

        int numOfConnectedComponents = 0;
        boolean[] visited = new boolean[n];

        // Traverse all stones using DFS to count connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                depthFirstSearch(adjacencyList, visited, i);
                numOfConnectedComponents++;
            }
        }

        // Maximum stones that can be removed is total stones minus number of connected components
        return n - numOfConnectedComponents;
    }

    // DFS to visit all stones in a connected component
    private void depthFirstSearch(
        List<Integer>[] adjacencyList,
        boolean[] visited,
        int stone
    ) {
        visited[stone] = true;

        for (int neighbor : adjacencyList[stone]) {
            if (!visited[neighbor]) {
                depthFirstSearch(adjacencyList, visited, neighbor);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        n = len(stones)

        # Adjacency list to store graph connections
        adjacency_list = [[] for _ in range(n)]

        # Build the graph: Connect stones that share the same row or column
        for i in range(n):
            for j in range(i + 1, n):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    adjacency_list[i].append(j)
                    adjacency_list[j].append(i)

        num_of_connected_components = 0
        visited = [False] * n

        # DFS to visit all stones in a connected component
        def _depth_first_search(stone):
            visited[stone] = True
            for neighbor in adjacency_list[stone]:
                if not visited[neighbor]:
                    _depth_first_search(neighbor)

        # Traverse all stones using DFS to count connected components
        for i in range(n):
            if not visited[i]:
                _depth_first_search(i)
                num_of_connected_components += 1

        # Maximum stones that can be removed is total stones minus number of connected components
        return n - num_of_connected_components
```

</details>

<br>

## Approach 2: Disjoint Set Union

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);

        // Populate uf by connecting stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    uf.unionNodes(i, j);
                }
            }
        }

        return n - uf.count;
    }

private:
    // Union-Find data structure for tracking connected components
    class UnionFind {
    public:
        vector<int> parent;  // Array to track the parent of each node
        int count;           // Number of connected components

        UnionFind(int n) {
            parent.resize(n, -1);  // Initialize all nodes as their own parent
            count = n;  // Initially, each stone is its own connected component
        }

        // Find the root of a node with path compression
        int find(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union two nodes, reducing the number of connected components
        void unionNodes(int n1, int n2) {
            int root1 = find(n1);
            int root2 = find(n2);

            if (root1 == root2) {
                return;  // If they are already in the same component, do
                         // nothing
            }

            // Merge the components and reduce the count of connected components
            count--;
            parent[root1] = root2;
        }
    };
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int removeStones(int[][] stones) {
        int n = stones.length;
        UnionFind uf = new UnionFind(n);

        // Populate uf by connecting stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (
                    stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]
                ) {
                    uf.union(i, j);
                }
            }
        }

        return n - uf.count;
    }

    // Union-Find data structure for tracking connected components
    private class UnionFind {

        int[] parent; // Array to track the parent of each node
        int count; // Number of connected components

        UnionFind(int n) {
            parent = new int[n];
            Arrays.fill(parent, -1); // Initialize all nodes as their own parent
            count = n; // Initially, each stone is its own connected component
        }

        // Find the root of a node with path compression
        int find(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union two nodes, reducing the number of connected components
        void union(int n1, int n2) {
            int root1 = find(n1);
            int root2 = find(n2);

            if (root1 == root2) {
                return; // If they are already in the same component, do nothing
            }

            // Merge the components and reduce the count of connected components
            count--;
            parent[root1] = root2;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeStones(self, stones):
        n = len(stones)
        uf = self.UnionFind(n)

        # Populate uf by connecting stones that share the same row or column
        for i in range(n):
            for j in range(i + 1, n):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    uf._union(i, j)

        return n - uf.count

    # Union-Find data structure for tracking connected components
    class UnionFind:
        def __init__(self, n):
            self.parent = [-1] * n  # Initialize all nodes as their own parent
            self.count = (
                n  # Initially, each stone is its own connected component
            )

        # Find the root of a node with path compression
        def _find(self, node):
            if self.parent[node] == -1:
                return node
            self.parent[node] = self._find(self.parent[node])
            return self.parent[node]

        # Union two nodes, reducing the number of connected components
        def _union(self, n1, n2):
            root1 = self._find(n1)
            root2 = self._find(n2)

            if root1 == root2:
                return  # If they are already in the same component, do nothing

            # Merge the components and reduce the count of connected components
            self.count -= 1
            self.parent[root1] = root2
```

</details>

<br>

## Approach 3: Disjoint Set Union (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(20002);  // Initialize UnionFind with a large enough range
                              // to handle coordinates

        // Union stones that share the same row or column
        for (int i = 0; i < n; i++) {
            uf.unionNodes(
                stones[i][0],
                stones[i][1] + 10001);  // Offset y-coordinates to avoid
                                        // conflict with x-coordinates
        }

        return n - uf.componentCount;
    }

private:
    // Union-Find data structure for tracking connected components
    class UnionFind {
    public:
        vector<int> parent;  // Array to track the parent of each node
        int componentCount;  // Number of connected components
        unordered_set<int> uniqueNodes;  // Set to track unique nodes

        UnionFind(int n) {
            parent.resize(n, -1);  // Initialize all nodes as their own parent
            componentCount = 0;
        }

        // Find the root of a node with path compression
        int find(int node) {
            // If node is not marked, increase the component count
            if (uniqueNodes.find(node) == uniqueNodes.end()) {
                componentCount++;
                uniqueNodes.insert(node);
            }

            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union two nodes, reducing the number of connected components
        void unionNodes(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return;  // If they are already in the same component, do
                         // nothing
            }

            // Merge the components and reduce the component count
            parent[root1] = root2;
            componentCount--;
        }
    };
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int removeStones(int[][] stones) {
        int n = stones.length;
        UnionFind uf = new UnionFind(20002); // Initialize UnionFind with a large enough range to handle coordinates

        // Union stones that share the same row or column
        for (int i = 0; i < n; i++) {
            uf.union(stones[i][0], stones[i][1] + 10001); // Offset y-coordinates to avoid conflict with x-coordinates
        }

        return n - uf.componentCount;
    }

    // Union-Find data structure for tracking connected components
    class UnionFind {

        int[] parent; // Array to track the parent of each node
        int componentCount; // Number of connected components
        Set<Integer> uniqueNodes; // Set to track unique nodes

        UnionFind(int n) {
            parent = new int[n];
            Arrays.fill(parent, -1); // Initialize all nodes as their own parent
            componentCount = 0;
            uniqueNodes = new HashSet<>();
        }

        // Find the root of a node with path compression
        int find(int node) {
            // If node is not marked, increase the component count
            if (!uniqueNodes.contains(node)) {
                componentCount++;
                uniqueNodes.add(node);
            }

            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union two nodes, reducing the number of connected components
        void union(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return; // If they are already in the same component, do nothing
            }

            // Merge the components and reduce the component count
            parent[root1] = root2;
            componentCount--;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeStones(self, stones):
        uf = self.UnionFind(
            20002
        )  # Initialize UnionFind with a large enough range to handle coordinates

        # Union stones that share the same row or column
        for x, y in stones:
            uf._union_nodes(
                x, y + 10001
            )  # Offset y-coordinates to avoid conflict with x-coordinates

        return len(stones) - uf.component_count

    # Union-Find data structure for tracking connected components
    class UnionFind:
        def __init__(self, n):
            self.parent = [-1] * n  # Initialize all nodes as their own parent
            self.component_count = (
                0  # Initialize the count of connected components
            )
            self.unique_nodes = (
                set()
            )  # Initialize the set to track unique nodes

        # Find the root of a node with path compression
        def _find(self, node):
            # If node is not marked, increase the component count
            if node not in self.unique_nodes:
                self.component_count += 1
                self.unique_nodes.add(node)

            if self.parent[node] == -1:
                return node
            self.parent[node] = self._find(self.parent[node])
            return self.parent[node]

        # Union two nodes, reducing the number of connected components
        def _union_nodes(self, node1, node2):
            root1 = self._find(node1)
            root2 = self._find(node2)

            if root1 == root2:
                return  # If they are already in the same component, do nothing

            # Merge the components and reduce the component count
            self.parent[root1] = root2
            self.component_count -= 1
```

</details>
