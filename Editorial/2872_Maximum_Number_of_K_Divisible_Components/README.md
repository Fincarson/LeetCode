# 2872. Maximum Number of K-Divisible Components

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximum-number-of-k-divisible-components/)  
`Tree` `Depth-First Search`

**Problem Link:** [LeetCode 2872 - Maximum Number of K-Divisible Components](https://leetcode.com/problems/maximum-number-of-k-divisible-components/)

## Problem

There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.

A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.

Return the maximum number of components in any valid split.

### Example 1

```text
Input: n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
Output: 2
Explanation: We remove the edge connecting node 1 with 2. The resulting split is valid because:
- The value of the component containing nodes 1 and 3 is values[1] + values[3] = 12.
- The value of the component containing nodes 0, 2, and 4 is values[0] + values[2] + values[4] = 6.
It can be shown that no other valid split has more than 2 connected components.
```

### Example 2

```text
Input: n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3
Output: 3
Explanation: We remove the edge connecting node 0 with 2, and the edge connecting node 0 with 1. The resulting split is valid because:
- The value of the component containing node 0 is values[0] = 3.
- The value of the component containing nodes 2, 5, and 6 is values[2] + values[5] + values[6] = 9.
- The value of the component containing nodes 1, 3, and 4 is values[1] + values[3] + values[4] = 6.
It can be shown that no other valid split has more than 3 connected components.
```

## Constraints

- 1 <= n <= 3 * 104
- edges.length == n - 1
- edges[i].length == 2
- 0 <= ai, bi < n
- values.length == n
- 0 <= values[i] <= 109
- 1 <= k <= 109
- Sum of values is divisible by k.
- The input is generated such that edges represents a valid tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Create Components With Same Value](https://leetcode.com/problems/create-components-with-same-value/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2872. Maximum Number of K-Divisible Components

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First-Search (DFS) | C++, Java, Python3 |
| Breadth-First Search (BFS) | C++, Java, Python3 |
| Topological Sort / Onion Sort | C++, Java, Python3 |

## Approach 1: Depth-First-Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {
        // Step 1: Create adjacency list from edges
        vector<int> adjList[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        // Step 2: Initialize component count
        int componentCount = 0;

        // Step 3: Start DFS traversal from node 0
        dfs(0, -1, adjList, values, k, componentCount);

        // Step 4: Return the total number of components
        return componentCount;
    }

private:
    int dfs(int currentNode, int parentNode, vector<int> adjList[],
            vector<int> &nodeValues, int k, int &componentCount) {
        // Step 1: Initialize sum for the current subtree
        int sum = 0;

        // Step 2: Traverse all neighbors
        for (auto neighborNode : adjList[currentNode]) {
            if (neighborNode != parentNode) {
                // Recursive call to process the subtree rooted at the neighbor
                sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
                           componentCount);
                sum %= k;  // Ensure the sum stays within bounds
            }
        }

        // Step 3: Add the value of the current node to the sum
        sum += nodeValues[currentNode];

        // Step 4: Check if the sum is divisible by k
        sum %= k;
        if (sum == 0) componentCount++;

        // Step 5: Return the computed sum for the current subtree
        return sum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxKDivisibleComponents(
        int n,
        int[][] edges,
        int[] values,
        int k
    ) {
        // Step 1: Create adjacency list from edges
        List<Integer>[] adjList = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].add(node2);
            adjList[node2].add(node1);
        }

        // Step 2: Initialize component count
        int[] componentCount = new int[1]; // Use array to pass by reference

        // Step 3: Start DFS traversal from node 0
        dfs(0, -1, adjList, values, k, componentCount);

        // Step 4: Return the total number of components
        return componentCount[0];
    }

    private int dfs(
        int currentNode,
        int parentNode,
        List<Integer>[] adjList,
        int[] nodeValues,
        int k,
        int[] componentCount
    ) {
        // Step 1: Initialize sum for the current subtree
        int sum = 0;

        // Step 2: Traverse all neighbors
        for (int neighborNode : adjList[currentNode]) {
            if (neighborNode != parentNode) {
                // Recursive call to process the subtree rooted at the neighbor
                sum += dfs(
                    neighborNode,
                    currentNode,
                    adjList,
                    nodeValues,
                    k,
                    componentCount
                );
                sum %= k; // Ensure the sum stays within bounds
            }
        }

        // Step 3: Add the value of the current node to the sum
        sum += nodeValues[currentNode];
        sum %= k;

        // Step 4: Check if the sum is divisible by k
        if (sum == 0) {
            componentCount[0]++;
        }

        // Step 5: Return the computed sum for the current subtree
        return sum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxKDivisibleComponents(
        self, n: int, edges: List[List[int]], values: List[int], k: int
    ) -> int:
        # Step 1: Create adjacency list from edges
        adj_list = [[] for _ in range(n)]
        for node1, node2 in edges:
            adj_list[node1].append(node2)
            adj_list[node2].append(node1)

        # Step 2: Initialize component count
        component_count = [0]  # Use a list to pass by reference

        # Step 3: Start DFS traversal from node 0
        self.dfs(0, -1, adj_list, values, k, component_count)

        # Step 4: Return the total number of components
        return component_count[0]

    def dfs(
        self,
        current_node: int,
        parent_node: int,
        adj_list: List[List[int]],
        node_values: List[int],
        k: int,
        component_count: List[int],
    ) -> int:
        # Step 1: Initialize sum for the current subtree
        sum_ = 0

        # Step 2: Traverse all neighbors
        for neighbor_node in adj_list[current_node]:
            if neighbor_node != parent_node:
                # Recursive call to process the subtree rooted at the neighbor
                sum_ += self.dfs(
                    neighbor_node,
                    current_node,
                    adj_list,
                    node_values,
                    k,
                    component_count,
                )
                sum_ %= k  # Ensure the sum stays within bounds

        # Step 3: Add the value of the current node to the sum
        sum_ += node_values[current_node]
        sum_ %= k

        # Step 4: Check if the sum is divisible by k
        if sum_ == 0:
            component_count[0] += 1

        # Step 5: Return the computed sum for the current subtree
        return sum_
```

</details>

<br>

## Approach 2: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        // Base case: if there are less than 2 nodes, return 1
        if (n < 2) return 1;

        int componentCount = 0;
        unordered_map<int, unordered_set<int>> graph;

        // Step 1: Build the graph
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].insert(node2);
            graph[node2].insert(node1);
        }

        // Convert values to long long to prevent overflow
        vector<long long> longValues(values.begin(), values.end());

        // Step 2: Initialize the BFS queue with leaf nodes (nodes with only one
        // connection)
        queue<int> queue;
        for (const auto& [node, neighbors] : graph) {
            if (neighbors.size() == 1) {
                queue.push(node);
            }
        }

        // Step 3: Process nodes in BFS order
        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            // Find the neighbor node
            int neighborNode = -1;
            if (!graph[currentNode].empty()) {
                neighborNode = *graph[currentNode].begin();
            }

            if (neighborNode >= 0) {
                // Remove the edge between current and neighbor
                graph[neighborNode].erase(currentNode);
                graph[currentNode].erase(neighborNode);
            }

            // Check divisibility of the current node's value
            if (longValues[currentNode] % k == 0) {
                componentCount++;
            } else if (neighborNode >= 0) {
                // Add current node's value to the neighbor
                longValues[neighborNode] += longValues[currentNode];
            }

            // If the neighbor becomes a leaf node, add it to the queue
            if (neighborNode >= 0 && graph[neighborNode].size() == 1) {
                queue.push(neighborNode);
            }
        }

        return componentCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxKDivisibleComponents(
        int n,
        int[][] edges,
        int[] values,
        int k
    ) {
        // Base case: if there are less than 2 nodes, return 1
        if (n < 2) return 1;

        int componentCount = 0;
        Map<Integer, Set<Integer>> graph = new HashMap<>();

        // Step 1: Build the graph
        for (int[] edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph.computeIfAbsent(node1, key -> new HashSet<>()).add(node2);
            graph.computeIfAbsent(node2, key -> new HashSet<>()).add(node1);
        }

        // Convert values to long to prevent overflow
        long[] longValues = new long[values.length];
        for (int i = 0; i < values.length; i++) {
            longValues[i] = values[i];
        }

        // Step 2: Initialize the BFS queue with leaf nodes
        // (nodes with only one connection)
        Queue<Integer> queue = new LinkedList<>();
        for (Map.Entry<Integer, Set<Integer>> entry : graph.entrySet()) {
            if (entry.getValue().size() == 1) {
                queue.add(entry.getKey());
            }
        }

        // Step 3: Process nodes in BFS order
        while (!queue.isEmpty()) {
            int currentNode = queue.poll();

            // Find the neighbor node
            int neighborNode = -1;
            if (
                !graph.get(currentNode).isEmpty()
            ) {
                neighborNode = graph.get(currentNode).iterator().next();
            }

            if (neighborNode >= 0) {
                // Remove the edge between current and neighbor
                graph.get(neighborNode).remove(currentNode);
                graph.get(currentNode).remove(neighborNode);
            }

            // Check divisibility of the current node's value
            if (longValues[currentNode] % k == 0) {
                componentCount++;
            } else if (neighborNode >= 0) {
                // Add current node's value to the neighbor
                longValues[neighborNode] += longValues[currentNode];
            }

            // If the neighbor becomes a leaf node, add it to the queue
            if (
                neighborNode >= 0 &&
                graph.get(neighborNode).size() == 1
            ) {
                queue.add(neighborNode);
            }
        }

        return componentCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxKDivisibleComponents(
        self, n: int, edges: List[List[int]], values: List[int], k: int
    ) -> int:
        # Base case: if there are less than 2 nodes, return 1
        if n < 2:
            return 1

        component_count = 0
        graph = defaultdict(set)

        # Step 1: Build the graph
        for node1, node2 in edges:
            graph[node1].add(node2)
            graph[node2].add(node1)

        # Step 2: Initialize the BFS queue with leaf nodes (nodes with only one connection)
        queue = deque(
            node for node, neighbors in graph.items() if len(neighbors) == 1
        )

        # Step 3: Process nodes in BFS order
        while queue:
            current_node = queue.popleft()
            neighbor_node = (
                next(iter(graph[current_node])) if graph[current_node] else -1
            )

            # Remove the edge between current and neighbor
            if neighbor_node >= 0:
                graph[neighbor_node].remove(current_node)

            # Check divisibility of the current node's value
            if values[current_node] % k == 0:
                component_count += 1
            else:
                values[neighbor_node] += values[current_node]

            # If the neighbor becomes a leaf node, add it to the queue
            if neighbor_node >= 0 and len(graph[neighbor_node]) == 1:
                queue.append(neighbor_node)

        return component_count
```

</details>

<br>

## Approach 3: Topological Sort / Onion Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        if (n < 2) return 1;

        int componentCount = 0;
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);

        // Build the graph and calculate in-degrees
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            inDegree[node1]++;
            inDegree[node2]++;
        }

        // Convert values to long long to prevent overflow
        vector<long long> longValues(values.begin(), values.end());

        // Initialize the queue with nodes having in-degree of 1 (leaf nodes)
        queue<int> queue;
        for (int node = 0; node < n; node++) {
            if (inDegree[node] == 1) {
                queue.push(node);
            }
        }

        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();
            inDegree[currentNode]--;

            long long addValue = 0;

            // Check if the current node's value is divisible by k
            if (longValues[currentNode] % k == 0) {
                componentCount++;
            } else {
                addValue = longValues[currentNode];
            }

            // Propagate the value to the neighbor nodes
            for (int neighborNode : graph[currentNode]) {
                if (inDegree[neighborNode] == 0) {
                    continue;
                }

                inDegree[neighborNode]--;
                longValues[neighborNode] += addValue;

                // If the neighbor node's in-degree becomes 1, add it to the
                // queue
                if (inDegree[neighborNode] == 1) {
                    queue.push(neighborNode);
                }
            }
        }

        return componentCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxKDivisibleComponents(
        int n,
        int[][] edges,
        int[] values,
        int k
    ) {
        if (n < 2) return 1; // Handle the base case where the graph has fewer than 2 nodes.

        int componentCount = 0;
        List<List<Integer>> graph = new ArrayList<>();
        int[] inDegree = new int[n];

        // Build the graph and calculate in-degrees
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>()); // Initialize the adjacency list for each node.
        }
        for (int[] edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph.get(node1).add(node2);
            graph.get(node2).add(node1);
            inDegree[node1]++;
            inDegree[node2]++;
        }

        // Convert values to long to prevent overflow
        long[] longValues = new long[n];
        for (int i = 0; i < n; i++) {
            longValues[i] = values[i];
        }

        // Initialize the queue with nodes having in-degree of 1 (leaf nodes)
        Queue<Integer> queue = new LinkedList<>();
        for (int node = 0; node < n; node++) {
            if (inDegree[node] == 1) {
                queue.offer(node);
            }
        }

        while (!queue.isEmpty()) {
            int currentNode = queue.poll();
            inDegree[currentNode]--;

            long addValue = 0;

            // Check if the current node's value is divisible by k
            if (longValues[currentNode] % k == 0) {
                componentCount++;
            } else {
                addValue = longValues[currentNode];
            }

            // Propagate the value to the neighbor nodes
            for (int neighborNode : graph.get(currentNode)) {
                if (inDegree[neighborNode] == 0) {
                    continue;
                }

                inDegree[neighborNode]--;
                longValues[neighborNode] += addValue;

                // If the neighbor node's in-degree becomes 1, add it to the queue
                if (inDegree[neighborNode] == 1) {
                    queue.offer(neighborNode);
                }
            }
        }

        return componentCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxKDivisibleComponents(
        self, n: int, edges: List[List[int]], values: List[int], k: int
    ) -> int:
        if n < 2:
            return 1
        component_count = 0
        graph = defaultdict(list)
        in_degree = [0 for _ in range(n)]

        # Build the graph and calculate in-degrees
        for node1, node2 in edges:
            graph[node1].append(node2)
            graph[node2].append(node1)
            in_degree[node1] += 1
            in_degree[node2] += 1

        # Initialize the queue with nodes having in-degree of 1 (leaf nodes)
        queue = deque(node for node in range(n) if in_degree[node] == 1)

        while queue:
            current_node = queue.popleft()
            in_degree[current_node] -= 1
            add_value = 0

            # Check if the current node's value is divisible by k
            if values[current_node] % k == 0:
                component_count += 1
            else:
                add_value = values[current_node]

            # Propagate the value to the neighbor nodes
            for neighbor_node in graph[current_node]:
                if in_degree[neighbor_node] == 0:
                    continue
                in_degree[neighbor_node] -= 1
                values[neighbor_node] += add_value

                # If the neighbor node's in-degree becomes 1, add it to the queue
                if in_degree[neighbor_node] == 1:
                    queue.append(neighbor_node)

        return component_count
```

</details>
