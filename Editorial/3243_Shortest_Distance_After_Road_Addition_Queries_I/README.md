# 3243. Shortest Distance After Road Addition Queries I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/)  
`Array` `Breadth-First Search` `Graph Theory`

**Problem Link:** [LeetCode 3243 - Shortest Distance After Road Addition Queries I](https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/)

## Problem

You are given an integer n and a 2D integer array queries.

There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.

Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

### Example 1

### Example 2

## Constraints

- 3 <= n <= 500
- 1 <= queries.length <= 500
- queries[i].length == 2
- 0 <= queries[i][0] < queries[i][1] < n
- 1 < queries[i][1] - queries[i][0]
- There are no repeated roads among the queries.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3243. Shortest Distance After Road Addition Queries I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search (BFS) | C++, Java, Python3 |
| Recursive Dynamic Programming (Top-Down) | C++, Java, Python3 |
| Iterative Dynamic Programming (Bottom-Up) | C++, Java, Python3 |

## Approach 1: Breadth First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Helper function to perform BFS and find the number of edges in the
    // shortest path from node 0 to node n-1
    int bfs(int n, vector<vector<int>>& adjList) {
        vector<bool> visited(n, false);
        queue<int> nodeQueue;
        // Start BFS from node 0
        nodeQueue.push(0);
        visited[0] = true;

        // Track the number of nodes in the current layer and the next layer
        int currentLayerNodeCount = 1;
        int nextLayerNodeCount = 0;
        // Initialize layers explored count
        int layersExplored = 0;

        // Perform BFS until the queue is empty
        while (!nodeQueue.empty()) {
            // Process nodes in the current layer
            for (int i = 0; i < currentLayerNodeCount; ++i) {
                int currentNode = nodeQueue.front();
                nodeQueue.pop();

                // Check if we reached the destination node
                if (currentNode == n - 1) {
                    return layersExplored;  // Return the number of edges in the
                                            // shortest path
                }

                // Explore all adjacent nodes
                for (auto neighbor : adjList[currentNode]) {
                    if (visited[neighbor]) continue;
                    nodeQueue.push(
                        neighbor);  // Add neighbor to the queue for exploration
                    nextLayerNodeCount++;  // Increment the count of nodes in
                                           // the next layer
                    visited[neighbor] = true;
                }
            }

            // Move to the next layer
            currentLayerNodeCount = nextLayerNodeCount;
            nextLayerNodeCount = 0;  // Reset next layer count
            layersExplored++;  // Increment the layer count after processing the
                               // current layer
        }

        return -1;  // Algorithm will never this point
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> adjList(n, vector<int>(0));

        // Initialize the graph with edges between consecutive nodes
        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }

        // Process each query to add new roads
        for (auto& road : queries) {
            int u = road[0];
            int v = road[1];
            adjList[u].push_back(v);  // Add road from u to v
            // Perform BFS to find the shortest path after adding the new road
            answer.push_back(bfs(n, adjList));
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Helper function to perform BFS and find the number of edges in the shortest path from node 0 to node n-1
    private int bfs(int n, List<List<Integer>> adjList) {
        boolean[] visited = new boolean[n];
        Queue<Integer> nodeQueue = new LinkedList<>();

        // Start BFS from node 0
        nodeQueue.add(0);
        visited[0] = true;

        // Track the number of nodes in the current layer and the next layer
        int currentLayerNodeCount = 1;
        int nextLayerNodeCount = 0;
        // Initialize layers explored count
        int layersExplored = 0;

        // Perform BFS until the queue is empty
        while (!nodeQueue.isEmpty()) {
            // Process nodes in the current layer
            for (int i = 0; i < currentLayerNodeCount; i++) {
                int currentNode = nodeQueue.poll();

                // Check if we reached the destination node
                if (currentNode == n - 1) {
                    return layersExplored; // Return the number of edges in the shortest path
                }

                // Explore all adjacent nodes
                for (int neighbor : adjList.get(currentNode)) {
                    if (visited[neighbor]) continue;
                    nodeQueue.add(neighbor); // Add neighbor to the queue for exploration
                    nextLayerNodeCount++; // Increment the count of nodes in the next layer
                    visited[neighbor] = true;
                }
            }

            // Move to the next layer
            currentLayerNodeCount = nextLayerNodeCount;
            nextLayerNodeCount = 0; // Reset next layer count
            layersExplored++; // Increment the layer count after processing the current layer
        }

        return -1; // Algorithm will never reach this point
    }

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        List<Integer> answer = new ArrayList<>();
        List<List<Integer>> adjList = new ArrayList<>(n);

        // Initialize the adjacency list for the graph
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }

        // Initialize the graph with edges between consecutive nodes
        for (int i = 0; i < n - 1; i++) {
            adjList.get(i).add(i + 1);
        }

        // Process each query to add new roads
        for (int[] road : queries) {
            int u = road[0];
            int v = road[1];
            adjList.get(u).add(v); // Add road from u to v
            // Perform BFS to find the shortest path after adding the new road
            answer.add(bfs(n, adjList));
        }

        // Convert List<Integer> to int[]
        return answer.stream().mapToInt(i -> i).toArray();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    # Helper function to perform BFS and find the number of edges in the shortest path from node 0 to node n-1
    def bfs(self, n: int, adj_list: List[List[int]]) -> int:
        visited = [False] * n
        node_queue = deque()

        # Start BFS from node 0
        node_queue.append(0)
        visited[0] = True

        # Track the number of nodes in the current layer and the next layer
        current_layer_node_count = 1
        next_layer_node_count = 0
        # Initialize layers explored count
        layers_explored = 0

        # Perform BFS until the queue is empty
        while node_queue:
            # Process nodes in the current layer
            for _ in range(current_layer_node_count):
                current_node = node_queue.popleft()

                # Check if we reached the destination node
                if current_node == n - 1:
                    return layers_explored  # Return the number of edges in the shortest path

                # Explore all adjacent nodes
                for neighbor in adj_list[current_node]:
                    if visited[neighbor]:
                        continue
                    node_queue.append(
                        neighbor
                    )  # Add neighbor to the queue for exploration
                    next_layer_node_count += (
                        1  # Increment the count of nodes in the next layer
                    )
                    visited[neighbor] = True

            # Move to the next layer
            current_layer_node_count = next_layer_node_count
            next_layer_node_count = 0  # Reset next layer count
            layers_explored += 1  # Increment the layer count after processing the current layer

        return -1  # Algorithm will never reach this point

    def shortestDistanceAfterQueries(
        self, n: int, queries: List[List[int]]
    ) -> List[int]:
        answer = []
        adj_list = [[] for _ in range(n)]

        # Initialize the graph with edges between consecutive nodes
        for i in range(n - 1):
            adj_list[i].append(i + 1)

        # Process each query to add new roads
        for road in queries:
            u, v = road
            adj_list[u].append(v)  # Add road from u to v
            # Perform BFS to find the shortest path after adding the new road
            answer.append(self.bfs(n, adj_list))

        return answer
```

</details>

<br>

## Approach 2: Recursive Dynamic Programming (Top-Down)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Recursive function to find the minimum distance from the current node to
    // the destination node (n-1)
    int findMinDistance(vector<vector<int>> &adjList, int n, int currentNode,
                        vector<int> &dp) {
        // We've reached the destination node
        if (currentNode == n - 1) return 0;

        // If this node has already been computed, return the stored value
        if (dp[currentNode] != -1) return dp[currentNode];

        int minDistance = n;

        for (int neighbor : adjList[currentNode]) {
            // Recursively find the minimum distance from the neighbor to the
            // destination
            minDistance =
                min(minDistance, findMinDistance(adjList, n, neighbor, dp) + 1);
        }

        // Store the computed minimum distance in the dp array and return it
        return dp[currentNode] = minDistance;
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries) {
        vector<int> dp(
            n, -1);  // DP array to store minimum distances from each node
        vector<vector<int>> adjList(n, vector<int>(0));

        // Initialize the graph with edges between consecutive nodes
        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }

        vector<int> answer;

        // Process each query to add new edges
        for (auto &road : queries) {
            int u = road[0];
            int v = road[1];

            // Add the directed edge from u to v
            adjList[u].push_back(v);

            // Find the minimum distance from the starting node (0) to the
            // destination (n-1)
            answer.push_back(findMinDistance(adjList, n, 0, dp));

            // Clear and resize the dp array
            dp.clear();
            dp.resize(n, -1);
        }

        return answer;  // Return the results for each query
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Recursive function to find the minimum distance from the current node to
    // the destination node (n-1)
    private int findMinDistance(
        List<List<Integer>> adjList,
        int n,
        int currentNode,
        int[] dp
    ) {
        // We've reached the destination node
        if (currentNode == n - 1) return 0;

        // If this node has already been computed, return the stored value
        if (dp[currentNode] != -1) return dp[currentNode];

        int minDistance = n;

        for (int neighbor : adjList.get(currentNode)) {
            // Recursively find the minimum distance from the neighbor to the destination
            minDistance = Math.min(
                minDistance,
                findMinDistance(adjList, n, neighbor, dp) + 1
            );
        }

        // Store the computed minimum distance in the dp array and return it
        return dp[currentNode] = minDistance;
    }

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = -1; // DP array to store minimum distances from each node
        }
        List<List<Integer>> adjList = new ArrayList<>(n);

        // Initialize the graph with edges between consecutive nodes
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>()); // Create a new list for each node
        }
        for (int i = 0; i < n - 1; i++) {
            adjList.get(i).add(i + 1);
        }

        List<Integer> answer = new ArrayList<>();

        // Process each query to add new edges
        for (int[] road : queries) {
            int u = road[0];
            int v = road[1];

            // Add the directed edge from u to v
            adjList.get(u).add(v);

            // Find the minimum distance from the starting node (0) to the destination (n-1)
            answer.add(findMinDistance(adjList, n, 0, dp));

            // Clear and reset the dp array
            for (int i = 0; i < n; i++) {
                dp[i] = -1;
            }
        }

        // Convert List<Integer> to int[] before returning
        int[] result = new int[answer.size()];
        for (int i = 0; i < answer.size(); i++) {
            result[i] = answer.get(i);
        }

        return result; // Return the results for each query
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Recursive function to find the minimum distance from the current node to
    # the destination node (n-1)
    def find_min_distance(self, adj_list, n, current_node, dp):
        # We've reached the destination node
        if current_node == n - 1:
            return 0

        # If this node has already been computed, return the stored value
        if dp[current_node] != -1:
            return dp[current_node]

        min_distance = n

        for neighbor in adj_list[current_node]:
            # Recursively find the minimum distance from the neighbor to the destination
            min_distance = min(
                min_distance,
                self.find_min_distance(adj_list, n, neighbor, dp) + 1,
            )

        # Store the computed minimum distance in the dp array and return it
        dp[current_node] = min_distance
        return min_distance

    def shortestDistanceAfterQueries(self, n, queries):
        dp = [-1] * n  # DP array to store minimum distances from each node
        adj_list = [[] for _ in range(n)]

        # Initialize the graph with edges between consecutive nodes
        for i in range(n - 1):
            adj_list[i].append(i + 1)

        answer = []

        # Process each query to add new edges
        for road in queries:
            u = road[0]
            v = road[1]

            # Add the directed edge from u to v
            adj_list[u].append(v)

            # Find the minimum distance from the starting node (0) to the destination (n-1)
            answer.append(self.find_min_distance(adj_list, n, 0, dp))

            # Clear and reset the dp array
            dp = [-1] * n

        return answer  # Return the results for each query
```

</details>

<br>

## Approach 3: Iterative Dynamic Programming (Bottom-Up)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Function to find the minimum distance from node 0 to node n-1
    int findMinDistance(vector<vector<int>> &adjList, int n) {
        vector<int> dp(n);
        dp[n - 1] = 0;  // Base case: distance to destination (n-1) is 0

        // Iterate from the second last node down to the first node
        for (int currentNode = n - 2; currentNode >= 0; currentNode--) {
            int minDistance = n;
            // Explore neighbors to find the minimum distance
            for (auto neighbor : adjList[currentNode]) {
                minDistance = min(minDistance, dp[neighbor] + 1);
            }
            dp[currentNode] = minDistance;  // Store the calculated distance for
                                            // the current node
        }
        return dp[0];
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries) {
        vector<int> answer;
        vector<vector<int>> adjList(n, vector<int>(0));

        // Initialize edges between consecutive nodes
        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }

        // Process each query to add new edges
        for (auto &road : queries) {
            int u = road[0];
            int v = road[1];
            adjList[u].push_back(v);  // Add the directed edge from u to v

            // Calculate the minimum distance after adding the new edge
            answer.push_back(findMinDistance(adjList, n));
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Function to find the minimum distance from node 0 to node n-1
    public int findMinDistance(List<List<Integer>> adjList, int n) {
        int[] dp = new int[n];
        dp[n - 1] = 0; // Base case: distance to destination (n-1) is 0

        // Iterate from the second last node down to the first node
        for (int currentNode = n - 2; currentNode >= 0; currentNode--) {
            int minDistance = n;
            // Explore neighbors to find the minimum distance
            for (int neighbor : adjList.get(currentNode)) {
                minDistance = Math.min(minDistance, dp[neighbor] + 1);
            }
            dp[currentNode] = minDistance; // Store the calculated distance for the current node
        }
        return dp[0];
    }

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        List<Integer> answer = new ArrayList<>();
        List<List<Integer>> adjList = new ArrayList<>();

        // Initialize adjacency list
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }

        // Initialize edges between consecutive nodes
        for (int i = 0; i < n - 1; i++) {
            adjList.get(i).add(i + 1);
        }

        // Process each query to add new edges
        for (int[] road : queries) {
            int u = road[0];
            int v = road[1];
            adjList.get(u).add(v); // Add the directed edge from u to v

            // Calculate the minimum distance after adding the new edge
            answer.add(findMinDistance(adjList, n));
        }

        // Convert List<Integer> to int[] before returning
        int[] result = new int[answer.size()];
        for (int i = 0; i < answer.size(); i++) {
            result[i] = answer.get(i);
        }

        return result; // Return the results for each query
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Function to find the minimum distance from node 0 to node n-1
    def find_min_distance(self, adj_list, n):
        dp = [0] * n
        dp[n - 1] = 0  # Base case: distance to destination (n-1) is 0

        # Iterate from the second last node down to the first node
        for current_node in range(n - 2, -1, -1):
            min_distance = n
            # Explore neighbors to find the minimum distance
            for neighbor in adj_list[current_node]:
                min_distance = min(min_distance, dp[neighbor] + 1)
            # Store the calculated distance for the current node
            dp[current_node] = min_distance

        return dp[0]

    def shortestDistanceAfterQueries(self, n, queries):
        answer = []
        adj_list = [[] for _ in range(n)]

        # Initialize edges between consecutive nodes
        for i in range(n - 1):
            adj_list[i].append(i + 1)

        # Process each query to add new edges
        for road in queries:
            u, v = road[0], road[1]
            adj_list[u].append(v)  # Add the directed edge from u to v

            # Calculate the minimum distance after adding the new edge
            answer.append(self.find_min_distance(adj_list, n))

        return answer
```

</details>
