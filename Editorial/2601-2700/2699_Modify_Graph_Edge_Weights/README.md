# 2699. Modify Graph Edge Weights

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/modify-graph-edge-weights/)  
`Graph Theory` `Heap (Priority Queue)` `Shortest Path`

**Problem Link:** [LeetCode 2699 - Modify Graph Edge Weights](https://leetcode.com/problems/modify-graph-edge-weights/)

## Problem

You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive weights.

### Example 1

```text
Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
Explanation: The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
```

### Example 2

```text
Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
Output: []
Explanation: The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.
```

### Example 3

```text
Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
Explanation: The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.
```

## Constraints

- 1 <= n <= 100
- 1 <= edges.length <= n * (n - 1) / 2
- edges[i].length == 3
- 0 <= ai, bi < n
- wi = -1 or 1 <= wi <= 107
- ai != bi
- 0 <= source, destination < n
- source != destination
- 1 <= target <= 109
- The graph is connected, and there are no self-loops or repeated edges

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2699. Modify Graph Edge Weights

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Traditional Dijkstra's algorithm | C++, Java, Python3 |
| Dijkstra's Algorithm with Min-Heap | C++, Java, Python3 |

## Approach 1: Traditional Dijkstra's algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    const int INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int nodeCount,
                                           vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        // Step 1: Compute the initial shortest distance from source to
        // destination
        long long currentShortestDistance =
            runDijkstra(edges, nodeCount, source, destination);

        // If the current shortest distance is less than the target, return an
        // empty result
        if (currentShortestDistance < target) return {};

        bool matchesTarget = (currentShortestDistance == target);

        // Step 2: Iterate through each edge to adjust its weight if necessary
        for (vector<int>& edge : edges) {
            // Skip edges that already have a positive weight
            if (edge[2] > 0) continue;

            // Set edge weight to a large value if current distance matches
            // target else set to 1
            edge[2] = matchesTarget ? INF : 1;

            // Step 3: If current shortest distance does not match target
            if (!matchesTarget) {
                // Compute the new shortest distance with the updated edge
                // weight
                long long newDistance =
                    runDijkstra(edges, nodeCount, source, destination);
                // If the new distance is within the target range, update edge
                // weight to match target
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        // Return modified edges if the target distance is achieved, otherwise
        // return an empty result
        return matchesTarget ? edges : vector<vector<int>>{};
    }

    // Dijkstra's algorithm to find the shortest path distance
    long long runDijkstra(const vector<vector<int>>& edges, int nodeCount,
                          int sourceNode, int destinationNode) {
        // Step 1: Initialize adjacency matrix and distance arrays
        vector<vector<long long>> adjMatrix(nodeCount,
                                            vector<long long>(nodeCount, INF));
        vector<long long> minDistance(nodeCount, INF);
        vector<bool> visited(nodeCount, false);

        // Set the distance to the source node as 0
        minDistance[sourceNode] = 0;

        // Step 2: Fill the adjacency matrix with edge weights
        for (const vector<int>& edge : edges) {
            if (edge[2] != -1) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }

        // Step 3: Perform Dijkstra's algorithm
        for (int i = 0; i < nodeCount; ++i) {
            // Find the nearest unvisited node
            int nearestUnvisitedNode = -1;
            for (int j = 0; j < nodeCount; ++j) {
                if (!visited[j] &&
                    (nearestUnvisitedNode == -1 ||
                     minDistance[j] < minDistance[nearestUnvisitedNode])) {
                    nearestUnvisitedNode = j;
                }
            }
            // Mark the nearest node as visited
            visited[nearestUnvisitedNode] = true;

            // Update the minimum distance for each adjacent node
            for (int v = 0; v < nodeCount; ++v) {
                minDistance[v] =
                    min(minDistance[v], minDistance[nearestUnvisitedNode] +
                                            adjMatrix[nearestUnvisitedNode][v]);
            }
        }

        // Return the shortest distance to the destination node
        return minDistance[destinationNode];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int INF = (int) 2e9;

    public int[][] modifiedGraphEdges(
        int n,
        int[][] edges,
        int source,
        int destination,
        int target
    ) {
        // Step 1: Compute the initial shortest distance from source to destination
        long currentShortestDistance = runDijkstra(
            edges,
            n,
            source,
            destination
        );

        // If the current shortest distance is less than the target, return an empty result
        if (currentShortestDistance < target) return new int[0][0];

        boolean matchesTarget = (currentShortestDistance == target);

        // Step 2: Iterate through each edge to adjust its weight if necessary
        for (int[] edge : edges) {
            // Skip edges that already have a positive weight
            if (edge[2] > 0) continue;

            // Set edge weight to a large value if current distance matches target, else set to 1
            edge[2] = matchesTarget ? INF : 1;

            // Step 3: If current shortest distance does not match target
            if (!matchesTarget) {
                // Compute the new shortest distance with the updated edge weight
                long newDistance = runDijkstra(edges, n, source, destination);
                // If the new distance is within the target range, update edge weight to match target
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        // Return modified edges if the target distance is achieved, otherwise return an empty result
        return matchesTarget ? edges : new int[0][0];
    }

    // Dijkstra's algorithm to find the shortest path distance
    private long runDijkstra(
        int[][] edges,
        int n,
        int source,
        int destination
    ) {
        // Step 1: Initialize adjacency matrix and distance arrays
        long[][] adjMatrix = new long[n][n];
        long[] minDistance = new long[n];
        boolean[] visited = new boolean[n];

        Arrays.fill(minDistance, INF);
        for (long[] row : adjMatrix) {
            Arrays.fill(row, INF);
        }

        // Set the distance to the source node as 0
        minDistance[source] = 0;

        // Step 2: Fill the adjacency matrix with edge weights
        for (int[] edge : edges) {
            if (edge[2] != -1) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }

        // Step 3: Perform Dijkstra's algorithm
        for (int i = 0; i < n; ++i) {
            // Find the nearest unvisited node
            int nearestUnvisitedNode = -1;
            for (int j = 0; j < n; ++j) {
                if (
                    !visited[j] &&
                    (nearestUnvisitedNode == -1 ||
                        minDistance[j] < minDistance[nearestUnvisitedNode])
                ) {
                    nearestUnvisitedNode = j;
                }
            }
            // Mark the nearest node as visited
            visited[nearestUnvisitedNode] = true;

            // Update the minimum distance for each adjacent node
            for (int v = 0; v < n; ++v) {
                minDistance[v] = Math.min(
                    minDistance[v],
                    minDistance[nearestUnvisitedNode] +
                    adjMatrix[nearestUnvisitedNode][v]
                );
            }
        }

        // Return the shortest distance to the destination node
        return minDistance[destination];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from typing import List


class Solution:
    INF = int(2e9)

    def modifiedGraphEdges(
        self,
        n: int,
        edges: List[List[int]],
        source: int,
        destination: int,
        target: int,
    ) -> List[List[int]]:
        # Step 1: Compute the initial shortest distance from source to destination
        current_shortest_distance = self.run_dijkstra(
            edges, n, source, destination
        )

        # If the current shortest distance is less than the target, return an empty result
        if current_shortest_distance < target:
            return []
        matches_target = current_shortest_distance == target

        # Step 2: Iterate through each edge to adjust its weight if necessary
        for edge in edges:
            # Skip edges that already have a positive weight
            if edge[2] > 0:
                continue

            # Set edge weight to a large value if current distance matches target, else set to 1
            edge[2] = self.INF if matches_target else 1

            # Step 3: If current shortest distance does not match target
            if not matches_target:
                # Compute the new shortest distance with the updated edge weight
                new_distance = self.run_dijkstra(edges, n, source, destination)
                # If the new distance is within the target range, update edge weight to match target
                if new_distance <= target:
                    matches_target = True
                    edge[2] += target - new_distance

        # Return modified edges if the target distance is achieved, otherwise return an empty result
        return edges if matches_target else []

    def run_dijkstra(
        self, edges: List[List[int]], n: int, source: int, destination: int
    ) -> int:
        # Step 1: Initialize adjacency matrix and distance arrays
        adj_matrix = [[self.INF] * n for _ in range(n)]
        min_distance = [self.INF] * n
        visited = [False] * n

        # Set the distance to the source node as 0
        min_distance[source] = 0

        # Step 2: Fill the adjacency matrix with edge weights
        for nodeA, nodeB, weight in edges:
            if weight != -1:
                adj_matrix[nodeA][nodeB] = weight
                adj_matrix[nodeB][nodeA] = weight

        # Step 3: Perform Dijkstra's algorithm
        for _ in range(n):
            # Find the nearest unvisited node
            nearest_unvisited_node = -1
            for i in range(n):
                if not visited[i] and (
                    nearest_unvisited_node == -1
                    or min_distance[i] < min_distance[nearest_unvisited_node]
                ):
                    nearest_unvisited_node = i

            # Mark the nearest node as visited
            visited[nearest_unvisited_node] = True

            # Update the minimum distance for each adjacent node
            for v in range(n):
                min_distance[v] = min(
                    min_distance[v],
                    min_distance[nearest_unvisited_node]
                    + adj_matrix[nearest_unvisited_node][v],
                )
        # Return the shortest distance to the destination node
        return min_distance[destination]
```

</details>

<br>

## Approach 2: Dijkstra's Algorithm with Min-Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    const int INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        vector<vector<pair<int, int>>> graph(n);

        // Step 1: Build the graph, excluding edges with -1 weights
        for (const auto& edge : edges) {
            if (edge[2] != -1) {
                graph[edge[0]].emplace_back(edge[1], edge[2]);
                graph[edge[1]].emplace_back(edge[0], edge[2]);
            }
        }

        // Step 2: Compute the initial shortest distance from source to
        // destination
        int currentShortestDistance =
            runDijkstra(n, source, destination, graph);
        if (currentShortestDistance < target) {
            return vector<vector<int>>();
        }

        bool matchesTarget = (currentShortestDistance == target);

        // Step 3: Iterate through each edge to adjust its weight if necessary
        for (auto& edge : edges) {
            if (edge[2] != -1)
                continue;  // Skip edges with already known weights

            // Set edge weight to a large value if current distance matches
            // target, else set to 1
            edge[2] = matchesTarget ? INF : 1;
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);

            // Step 4: If current shortest distance does not match target
            if (!matchesTarget) {
                // Compute the new shortest distance with the updated edge
                // weight
                int newDistance = runDijkstra(n, source, destination, graph);
                // If the new distance is within the target range, update edge
                // weight to match target
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        // Return modified edges if the target distance is achieved, otherwise
        // return an empty result
        return matchesTarget ? edges : vector<vector<int>>();
    }

private:
    int runDijkstra(int n, int source, int destination,
                    const vector<vector<pair<int, int>>>& graph) {
        vector<int> minDistance(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minHeap;

        minDistance[source] = 0;
        minHeap.emplace(0, source);

        while (!minHeap.empty()) {
            auto [d, u] = minHeap.top();
            minHeap.pop();

            if (d > minDistance[u]) continue;

            for (const auto& [v, weight] : graph[u]) {
                if (d + weight < minDistance[v]) {
                    minDistance[v] = d + weight;
                    minHeap.emplace(minDistance[v], v);
                }
            }
        }

        return minDistance[destination];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    List<int[]>[] graph;
    private static final int INF = (int) 2e9;

    public int[][] modifiedGraphEdges(
        int n,
        int[][] edges,
        int source,
        int destination,
        int target
    ) {
        // Step 1: Build the graph, excluding edges with -1 weights
        graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            if (edge[2] != -1) {
                graph[edge[0]].add(new int[] { edge[1], edge[2] });
                graph[edge[1]].add(new int[] { edge[0], edge[2] });
            }
        }

        // Step 2: Compute the initial shortest distance from source to destination
        int currentShortestDistance = runDijkstra(n, source, destination);
        if (currentShortestDistance < target) {
            return new int[0][0];
        }

        boolean matchesTarget = (currentShortestDistance == target);

        // Step 3: Iterate through each edge to adjust its weight if necessary
        for (int[] edge : edges) {
            if (edge[2] != -1) continue; // Skip edges with already known weights

            // Set edge weight to a large value if current distance matches target, else set
            // to 1
            edge[2] = matchesTarget ? INF : 1;
            graph[edge[0]].add(new int[] { edge[1], edge[2] });
            graph[edge[1]].add(new int[] { edge[0], edge[2] });

            // Step 4: If current shortest distance does not match target
            if (!matchesTarget) {
                // Compute the new shortest distance with the updated edge weight
                int newDistance = runDijkstra(n, source, destination);
                // If the new distance is within the target range, update edge weight to match
                // target
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        // Return modified edges if the target distance is achieved, otherwise return an
        // empty result
        return matchesTarget ? edges : new int[0][0];
    }

    // Dijkstra's algorithm to find the shortest path distance
    private int runDijkstra(int n, int source, int destination) {
        int[] minDistance = new int[n];
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
            (a, b) -> a[1] - b[1]
        );

        Arrays.fill(minDistance, INF);
        minDistance[source] = 0;
        minHeap.add(new int[] { source, 0 });

        while (!minHeap.isEmpty()) {
            int[] curr = minHeap.poll();
            int u = curr[0];
            int d = curr[1];

            if (d > minDistance[u]) continue;

            for (int[] neighbor : graph[u]) {
                int v = neighbor[0];
                int weight = neighbor[1];

                if (d + weight < minDistance[v]) {
                    minDistance[v] = d + weight;
                    minHeap.add(new int[] { v, minDistance[v] });
                }
            }
        }

        return minDistance[destination];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def modifiedGraphEdges(
        self,
        n: int,
        edges: List[List[int]],
        source: int,
        destination: int,
        target: int,
    ) -> List[List[int]]:
        INF = int(2e9)
        graph = [[] for _ in range(n)]

        # Build the graph with known weights
        for u, v, w in edges:
            if w != -1:
                graph[u].append((v, w))
                graph[v].append((u, w))

        # Compute the initial shortest distance
        current_shortest_distance = self._dijkstra(graph, source, destination)
        if current_shortest_distance < target:
            return []

        if current_shortest_distance == target:
            # Update edges with -1 weight to an impossible value
            for edge in edges:
                if edge[2] == -1:
                    edge[2] = INF
            return edges

        # Adjust edges with unknown weights
        for i, (u, v, w) in enumerate(edges):
            if w != -1:
                continue

            # Set edge weight to 1 initially
            edges[i][2] = 1
            graph[u].append((v, 1))
            graph[v].append((u, 1))

            # Recompute shortest distance with updated edge weight
            new_distance = self._dijkstra(graph, source, destination)

            if new_distance <= target:
                edges[i][2] += target - new_distance

                # Update remaining edges with -1 weight to an impossible value
                for j in range(i + 1, len(edges)):
                    if edges[j][2] == -1:
                        edges[j][2] = INF
                return edges
        return []

    def _dijkstra(
        self, graph: List[List[Tuple[int, int]]], src: int, destination: int
    ) -> int:
        min_distance = [math.inf] * len(graph)
        min_distance[src] = 0
        min_heap = [(0, src)]  # (distance, node)

        while min_heap:
            d, u = heapq.heappop(min_heap)
            if d > min_distance[u]:
                continue
            for v, w in graph[u]:
                if d + w < min_distance[v]:
                    min_distance[v] = d + w
                    heapq.heappush(min_heap, (min_distance[v], v))
        return min_distance[destination]
```

</details>
