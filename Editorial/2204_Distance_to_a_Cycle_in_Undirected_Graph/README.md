# 2204. Distance to a Cycle in Undirected Graph

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/distance-to-a-cycle-in-undirected-graph/)  
`Depth-First Search` `Breadth-First Search` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 2204 - Distance to a Cycle in Undirected Graph](https://leetcode.com/problems/distance-to-a-cycle-in-undirected-graph/)

## Problem

You are given a positive integer n representing the number of nodes in a connected undirected graph containing exactly one cycle. The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [node1i, node2i] denotes that there is a bidirectional edge connecting node1i and node2i in the graph.

The distance between two nodes a and b is defined to be the minimum number of edges that are needed to go from a to b.

Return an integer array answer of size n, where answer[i] is the minimum distance between the ith node and any node in the cycle.

### Example 1

```text
Input: n = 7, edges = [[1,2],[2,4],[4,3],[3,1],[0,1],[5,2],[6,5]]
Output: [1,0,0,0,0,1,2]
Explanation:
The nodes 1, 2, 3, and 4 form the cycle.
The distance from 0 to 1 is 1.
The distance from 1 to 1 is 0.
The distance from 2 to 2 is 0.
The distance from 3 to 3 is 0.
The distance from 4 to 4 is 0.
The distance from 5 to 2 is 1.
The distance from 6 to 2 is 2.
```

### Example 2

```text
Input: n = 9, edges = [[0,1],[1,2],[0,2],[2,6],[6,7],[6,8],[0,3],[3,4],[3,5]]
Output: [0,0,0,1,2,2,1,2,2]
Explanation:
The nodes 0, 1, and 2 form the cycle.
The distance from 0 to 0 is 0.
The distance from 1 to 1 is 0.
The distance from 2 to 2 is 0.
The distance from 3 to 1 is 1.
The distance from 4 to 1 is 2.
The distance from 5 to 1 is 2.
The distance from 6 to 2 is 1.
The distance from 7 to 2 is 2.
The distance from 8 to 2 is 2.
```

## Constraints

- 3 <= n <= 105
- edges.length == n
- edges[i].length == 2
- 0 <= node1i, node2i <= n - 1
- node1i != node2i
- The graph is connected.
- The graph has exactly one cycle.
- There is at most one edge between any pair of vertices.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Paths in Maze That Lead to Same Room](https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2204. Distance to a Cycle in Undirected Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C++, Java, Python3 |
| Layer By Layer + Multisource BFS | C++, Java, Python3 |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // DFS to detect cycle nodes and mark them in `isInCycle`
    bool detectCycleNodes(int currentNode, vector<vector<int>> &adjacencyList,
                          vector<bool> &isInCycle, vector<bool> &visited,
                          vector<int> &parent) {
        visited[currentNode] = true;  // Mark current node as visited
        for (auto neighbor : adjacencyList[currentNode]) {
            if (!visited[neighbor]) {
                parent[neighbor] = currentNode;  // Set parent for backtracking
                if (detectCycleNodes(neighbor, adjacencyList, isInCycle,
                                     visited, parent))
                    return true;  // Return true if cycle detected
            } else if (parent[currentNode] != neighbor) {  // Cycle detected
                isInCycle[neighbor] = true;  // Mark the start of the cycle
                int tempNode = currentNode;
                // Backtrack to mark all nodes in the cycle
                while (tempNode != neighbor) {
                    isInCycle[tempNode] = true;
                    tempNode = parent[tempNode];
                }
                return true;
            }
        }
        return false;  // No cycle found in this path
    }

    // DFS to calculate distances from cycle nodes
    void calculateDistances(int currentNode, int currentDistance,
                            vector<vector<int>> &adjacencyList,
                            vector<int> &distances, vector<bool> &visited,
                            vector<bool> &isInCycle) {
        distances[currentNode] =
            currentDistance;          // Set distance for current node
        visited[currentNode] = true;  // Mark node as visited
        for (auto neighbor : adjacencyList[currentNode]) {
            if (visited[neighbor]) continue;  // Skip if already visited
            int newDistance = isInCycle[neighbor]
                                  ? 0
                                  : currentDistance + 1;  // Reset if on cycle
            calculateDistances(neighbor, newDistance, adjacencyList, distances,
                               visited, isInCycle);
        }
    }

    vector<int> distanceToCycle(int n, vector<vector<int>> &edges) {
        vector<bool> isInCycle(n, false), visited(n, false);
        vector<int> parent(n), distances(n);
        vector<vector<int>> adjacencyList(n);

        // Build adjacency list for the graph
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        // Detect and mark cycle nodes
        detectCycleNodes(0, adjacencyList, isInCycle, visited, parent);

        // Reset visited array before distance calculation
        fill(visited.begin(), visited.end(), false);

        // Calculate distances starting from any cycle node
        for (int i = 0; i < n; i++) {
            if (isInCycle[i]) {
                calculateDistances(i, 0, adjacencyList, distances, visited,
                                   isInCycle);
                break;  // Only need to start from one cycle node
            }
        }
        return distances;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // DFS to detect cycle nodes and mark them in `isInCycle`
    public boolean detectCycleNodes(
        int currentNode,
        List<List<Integer>> adjacencyList,
        boolean[] isInCycle,
        boolean[] visited,
        int[] parent
    ) {
        visited[currentNode] = true; // Mark current node as visited
        for (int neighbor : adjacencyList.get(currentNode)) {
            if (!visited[neighbor]) {
                parent[neighbor] = currentNode; // Set parent for backtracking
                if (
                    detectCycleNodes(
                        neighbor,
                        adjacencyList,
                        isInCycle,
                        visited,
                        parent
                    )
                ) return true; // Return true if cycle detected
            } else if (parent[currentNode] != neighbor) { // Cycle detected
                isInCycle[neighbor] = true; // Mark the start of the cycle
                int tempNode = currentNode;
                // Backtrack to mark all nodes in the cycle
                while (tempNode != neighbor) {
                    isInCycle[tempNode] = true;
                    tempNode = parent[tempNode];
                }
                return true;
            }
        }
        return false; // No cycle found in this path
    }

    // DFS to calculate distances from cycle nodes
    public void calculateDistances(
        int currentNode,
        int currentDistance,
        List<List<Integer>> adjacencyList,
        int[] distances,
        boolean[] visited,
        boolean[] isInCycle
    ) {
        distances[currentNode] = currentDistance; // Set distance for current node
        visited[currentNode] = true; // Mark node as visited
        for (int neighbor : adjacencyList.get(currentNode)) {
            if (visited[neighbor]) continue; // Skip if already visited
            int newDistance = isInCycle[neighbor] ? 0 : currentDistance + 1; // Reset if on cycle
            calculateDistances(
                neighbor,
                newDistance,
                adjacencyList,
                distances,
                visited,
                isInCycle
            );
        }
    }

    public int[] distanceToCycle(int n, int[][] edges) {
        boolean[] isInCycle = new boolean[n];
        boolean[] visited = new boolean[n];
        int[] parent = new int[n];
        int[] distances = new int[n];
        List<List<Integer>> adjacencyList = new ArrayList<>();

        // Initialize adjacency list
        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        // Build adjacency list for the graph
        for (int[] edge : edges) {
            adjacencyList.get(edge[0]).add(edge[1]);
            adjacencyList.get(edge[1]).add(edge[0]);
        }

        // Detect and mark cycle nodes
        detectCycleNodes(0, adjacencyList, isInCycle, visited, parent);

        // Reset visited array before distance calculation
        Arrays.fill(visited, false);

        // Calculate distances starting from any cycle node
        for (int i = 0; i < n; i++) {
            if (isInCycle[i]) {
                calculateDistances(
                    i,
                    0,
                    adjacencyList,
                    distances,
                    visited,
                    isInCycle
                );
                break; // Only need to start from one cycle node
            }
        }
        return distances;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # DFS to detect cycle nodes and mark them in `is_in_cycle`
    def detect_cycle_nodes(
        self, current_node, adjacency_list, is_in_cycle, visited, parent
    ):
        visited[current_node] = True  # Mark current node as visited
        for neighbor in adjacency_list[current_node]:
            if not visited[neighbor]:
                parent[neighbor] = current_node  # Set parent for backtracking
                if self.detect_cycle_nodes(
                    neighbor, adjacency_list, is_in_cycle, visited, parent
                ):
                    return True  # Return True if cycle detected
            elif parent[current_node] != neighbor:  # Cycle detected
                is_in_cycle[neighbor] = True  # Mark the start of the cycle
                temp_node = current_node
                # Backtrack to mark all nodes in the cycle
                while temp_node != neighbor:
                    is_in_cycle[temp_node] = True
                    temp_node = parent[temp_node]
                return True
        return False  # No cycle found in this path

    # DFS to calculate distances from cycle nodes
    def calculate_distances(
        self,
        current_node,
        current_distance,
        adjacency_list,
        distances,
        visited,
        is_in_cycle,
    ):
        distances[current_node] = (
            current_distance  # Set distance for current node
        )
        visited[current_node] = True  # Mark node as visited
        for neighbor in adjacency_list[current_node]:
            if visited[neighbor]:
                continue  # Skip if already visited
            new_distance = (
                0 if is_in_cycle[neighbor] else current_distance + 1
            )  # Reset if on cycle
            self.calculate_distances(
                neighbor,
                new_distance,
                adjacency_list,
                distances,
                visited,
                is_in_cycle,
            )

    def distanceToCycle(self, n, edges):
        is_in_cycle = [False] * n
        visited = [False] * n
        parent = [0] * n
        distances = [0] * n
        adjacency_list = [[] for _ in range(n)]

        # Build adjacency list for the graph
        for edge in edges:
            adjacency_list[edge[0]].append(edge[1])
            adjacency_list[edge[1]].append(edge[0])

        # Detect and mark cycle nodes
        self.detect_cycle_nodes(0, adjacency_list, is_in_cycle, visited, parent)

        # Reset visited array before distance calculation
        visited = [False] * n

        # Calculate distances starting from any cycle node
        for i in range(n):
            if is_in_cycle[i]:
                self.calculate_distances(
                    i, 0, adjacency_list, distances, visited, is_in_cycle
                )
                break  # Only need to start from one cycle node
        return distances
```

</details>

<br>

## Approach 2: Layer By Layer + Multisource BFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<bool> isInCycle(n, true),
            visited(n, false);  // 'isInCycle' is initially true for all nodes
        vector<int> degree(n, 0), distances(n);
        vector<vector<int>> adjacencyList(n, vector<int>(0));

        // Build the adjacency list and calculate node degrees
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> nodeQueue;

        // Start by adding all leaf nodes (degree 1) to the queue
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                nodeQueue.push(i);
            }
        }

        // Perform BFS to remove nodes with degree 1, progressively reducing the
        // graph
        while (!nodeQueue.empty()) {
            int currentNode = nodeQueue.front();
            nodeQueue.pop();
            isInCycle[currentNode] =
                false;  // Mark the node as not in the cycle

            // Update the degree of neighbors and add them to the queue if their
            // degree becomes 1
            for (auto neighbor : adjacencyList[currentNode]) {
                degree[neighbor]--;
                if (degree[neighbor] == 1) {
                    nodeQueue.push(neighbor);
                }
            }
        }

        // Add all cycle nodes to the queue and mark them as visited
        for (int currentNode = 0; currentNode < n; currentNode++) {
            if (isInCycle[currentNode]) {
                nodeQueue.push(currentNode);
                visited[currentNode] = true;
            }
        }

        // BFS to calculate distances from cycle nodes
        int currentDistance = 0;
        while (!nodeQueue.empty()) {
            int queueSize = nodeQueue.size();  // Track number of nodes to
                                               // process at this distance level
            for (int i = 0; i < queueSize; i++) {
                int currentNode = nodeQueue.front();
                nodeQueue.pop();

                distances[currentNode] =
                    currentDistance;  // Set the distance for the current node

                // Add unvisited neighbors to the queue
                for (auto neighbor : adjacencyList[currentNode]) {
                    if (visited[neighbor]) continue;
                    nodeQueue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            currentDistance++;  // Increment distance after processing all nodes
                                // at the current level
        }

        return distances;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] distanceToCycle(int n, int[][] edges) {
        boolean[] isInCycle = new boolean[n];
        Arrays.fill(isInCycle, true); // 'isInCycle' is initially true for all nodes
        boolean[] visited = new boolean[n];
        int[] degree = new int[n];
        int[] distances = new int[n];
        List<List<Integer>> adjacencyList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        // Build the adjacency list and calculate node degrees
        for (int[] edge : edges) {
            adjacencyList.get(edge[0]).add(edge[1]);
            adjacencyList.get(edge[1]).add(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        Queue<Integer> nodeQueue = new LinkedList<>();

        // Start by adding all leaf nodes (degree 1) to the queue
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                nodeQueue.add(i);
            }
        }

        // Perform BFS to remove nodes with degree 1, progressively reducing the graph
        while (!nodeQueue.isEmpty()) {
            int currentNode = nodeQueue.poll();
            isInCycle[currentNode] = false; // Mark the node as not in the cycle

            // Update the degree of neighbors and add them to the queue if their degree becomes 1
            for (int neighbor : adjacencyList.get(currentNode)) {
                degree[neighbor]--;
                if (degree[neighbor] == 1) {
                    nodeQueue.add(neighbor);
                }
            }
        }

        // Add all cycle nodes to the queue and mark them as visited
        for (int currentNode = 0; currentNode < n; currentNode++) {
            if (isInCycle[currentNode]) {
                nodeQueue.add(currentNode);
                visited[currentNode] = true;
            }
        }

        // BFS to calculate distances from cycle nodes
        int currentDistance = 0;
        while (!nodeQueue.isEmpty()) {
            int queueSize = nodeQueue.size(); // Track number of nodes to process at this distance level
            for (int i = 0; i < queueSize; i++) {
                int currentNode = nodeQueue.poll();
                distances[currentNode] = currentDistance; // Set the distance for the current node

                // Add unvisited neighbors to the queue
                for (int neighbor : adjacencyList.get(currentNode)) {
                    if (visited[neighbor]) continue;
                    nodeQueue.add(neighbor);
                    visited[neighbor] = true;
                }
            }
            currentDistance++; // Increment distance after processing all nodes at the current level
        }

        return distances;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def distanceToCycle(self, n, edges):
        # 'is_in_cycle' is initially True for all nodes
        is_in_cycle = [True] * n
        visited = [False] * n
        degree = [0] * n
        distances = [0] * n
        adjacency_list = [[] for _ in range(n)]

        # Build the adjacency list and calculate node degrees
        for edge in edges:
            adjacency_list[edge[0]].append(edge[1])
            adjacency_list[edge[1]].append(edge[0])
            degree[edge[0]] += 1
            degree[edge[1]] += 1

        node_queue = deque()

        # Start by adding all leaf nodes (degree 1) to the queue
        for i in range(n):
            if degree[i] == 1:
                node_queue.append(i)

        # Perform BFS to remove nodes with degree 1, progressively reducing the graph
        while node_queue:
            current_node = node_queue.popleft()
            # Mark the node as not in the cycle
            is_in_cycle[current_node] = False

            # Update the degree of neighbors and add them to the queue if their degree becomes 1
            for neighbor in adjacency_list[current_node]:
                degree[neighbor] -= 1
                if degree[neighbor] == 1:
                    node_queue.append(neighbor)

        # Add all cycle nodes to the queue and mark them as visited
        for current_node in range(n):
            if is_in_cycle[current_node]:
                node_queue.append(current_node)
                visited[current_node] = True

        # BFS to calculate distances from cycle nodes
        current_distance = 0
        while node_queue:
            # Track number of nodes to process at this distance level
            queue_size = len(node_queue)
            for _ in range(queue_size):
                current_node = node_queue.popleft()
                # Set the distance for the current node
                distances[current_node] = current_distance

                # Add unvisited neighbors to the queue
                for neighbor in adjacency_list[current_node]:
                    if visited[neighbor]:
                        continue
                    node_queue.append(neighbor)
                    visited[neighbor] = True
            # Increment distance after processing all nodes at the current level
            current_distance += 1

        return distances
```

</details>
