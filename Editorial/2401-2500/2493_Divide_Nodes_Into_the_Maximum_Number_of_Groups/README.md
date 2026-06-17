# 2493. Divide Nodes Into the Maximum Number of Groups

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 2493 - Divide Nodes Into the Maximum Number of Groups](https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/)

## Problem

You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

Divide the nodes of the graph into m groups (1-indexed) such that:

- Each node in the graph belongs to exactly one group.
- For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.

Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

### Example 1

```text
Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
Output: 4
Explanation: As shown in the image we:
- Add node 5 to the first group.
- Add node 1 to the second group.
- Add nodes 2 and 4 to the third group.
- Add nodes 3 and 6 to the fourth group.
We can see that every edge is satisfied.
It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.
```

### Example 2

```text
Input: n = 3, edges = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
It can be shown that no grouping is possible.
```

## Constraints

- 1 <= n <= 500
- 1 <= edges.length <= 104
- edges[i].length == 2
- 1 <= ai, bi <= n
- ai != bi
- There is at most one edge between any pair of vertices.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Shortest Cycle in a Graph](https://leetcode.com/problems/shortest-cycle-in-a-graph/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2493. Divide Nodes Into the Maximum Number of Groups

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Graph Coloring + Longest Shortest Path | C++, Java, Python3 |
| BFS + Union-Find | C++, Java, Python3 |

## Approach 1: Graph Coloring + Longest Shortest Path

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Main function to calculate the maximum number of magnificent sets
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            // Transition to 0-index
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] != -1) continue;
            // Start coloring from uncolored nodes
            colors[node] = 0;
            // If the graph is not bipartite, return -1
            if (!isBipartite(adjList, node, colors)) return -1;
        }

        // Calculate the longest shortest path for each node
        vector<int> distances(n);
        for (int node = 0; node < n; node++) {
            distances[node] = getLongestShortestPath(adjList, node, n);
        }

        // Calculate the total maximum number of groups across all components
        int maxNumberOfGroups = 0;
        vector<bool> visited(n, false);
        for (int node = 0; node < n; node++) {
            if (visited[node]) continue;
            // Add the number of groups for this component to the total
            maxNumberOfGroups += getNumberOfGroupsForComponent(
                adjList, node, distances, visited);
        }

        return maxNumberOfGroups;
    }

private:
    // Checks if the graph is bipartite starting from the given node
    bool isBipartite(vector<vector<int>> &adjList, int node,
                     vector<int> &colors) {
        for (int neighbor : adjList[node]) {
            // If a neighbor has the same color as the current node, the graph
            // is not bipartite
            if (colors[neighbor] == colors[node]) return false;

            // If the neighbor is already colored, skip it
            if (colors[neighbor] != -1) continue;

            // Assign the opposite color to the neighbor
            colors[neighbor] = (colors[node] + 1) % 2;

            // Recursively check bipartiteness for the neighbor; return false if
            // it fails
            if (!isBipartite(adjList, neighbor, colors)) return false;
        }
        // If all neighbors are properly colored, return true
        return true;
    }

    // Computes the longest shortest path (height) in the graph starting from
    // the source node
    int getLongestShortestPath(vector<vector<int>> &adjList, int srcNode,
                               int n) {
        // Initialize a queue for BFS and a visited array
        queue<int> nodesQueue;
        vector<bool> visited(n, false);

        nodesQueue.push(srcNode);
        visited[srcNode] = true;
        int distance = 0;

        // Perform BFS layer by layer
        while (!nodesQueue.empty()) {
            // Process all nodes in the current layer
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();

                // Visit all unvisited neighbors of the current node
                for (int neighbor : adjList[currentNode]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    nodesQueue.push(neighbor);
                }
            }
            // Increment the distance for each layer
            distance++;
        }
        // Return the total distance (longest shortest path)
        return distance;
    }

    // Calculates the maximum number of groups for a connected component
    int getNumberOfGroupsForComponent(vector<vector<int>> &adjList, int node,
                                      vector<int> &distances,
                                      vector<bool> &visited) {
        // Start with the distance of the current node as the maximum
        int maxNumberOfGroups = distances[node];
        visited[node] = true;

        // Recursively calculate the maximum for all unvisited neighbors
        for (int neighbor : adjList[node]) {
            if (visited[neighbor]) continue;
            maxNumberOfGroups = max(maxNumberOfGroups,
                                    getNumberOfGroupsForComponent(
                                        adjList, neighbor, distances, visited));
        }
        return maxNumberOfGroups;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Main function to calculate the maximum number of magnificent sets
    public int magnificentSets(int n, int[][] edges) {
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<
            ArrayList<Integer>
        >(n);
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<Integer>());
        }
        for (int[] edge : edges) {
            // Transition to 0-index
            adjList.get(edge[0] - 1).add(edge[1] - 1);
            adjList.get(edge[1] - 1).add(edge[0] - 1);
        }

        int[] colors = new int[n];
        Arrays.fill(colors, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] != -1) continue;
            // Start coloring from uncolored nodes
            colors[node] = 0;
            // If the graph is not bipartite, return -1
            if (!isBipartite(adjList, node, colors)) return -1;
        }

        // Calculate the longest shortest path for each node
        int[] distances = new int[n];
        for (int node = 0; node < n; node++) {
            distances[node] = getLongestShortestPath(adjList, node, n);
        }

        // Calculate the total maximum number of groups across all components
        int maxNumberOfGroups = 0;
        boolean[] visited = new boolean[n];
        for (int node = 0; node < n; node++) {
            if (visited[node]) continue;
            // Add the number of groups for this component to the total
            maxNumberOfGroups += getNumberOfGroupsForComponent(
                adjList,
                node,
                distances,
                visited
            );
        }

        return maxNumberOfGroups;
    }

    // Checks if the graph is bipartite starting from the given node
    private boolean isBipartite(
        ArrayList<ArrayList<Integer>> adjList,
        int node,
        int[] colors
    ) {
        for (int neighbor : adjList.get(node)) {
            // If a neighbor has the same color as the current node, the graph is not bipartite
            if (colors[neighbor] == colors[node]) return false;

            // If the neighbor is already colored, skip it
            if (colors[neighbor] != -1) continue;

            // Assign the opposite color to the neighbor
            colors[neighbor] = (colors[node] + 1) % 2;

            // Recursively check bipartiteness for the neighbor; return false if it fails
            if (!isBipartite(adjList, neighbor, colors)) return false;
        }
        // If all neighbors are properly colored, return true
        return true;
    }

    // Computes the longest shortest path (height) in the graph starting from the source node
    private int getLongestShortestPath(
        ArrayList<ArrayList<Integer>> adjList,
        int srcNode,
        int n
    ) {
        // Initialize a queue for BFS and a visited array
        Queue<Integer> nodesQueue = new LinkedList<Integer>();
        boolean[] visited = new boolean[n];

        nodesQueue.add(srcNode);
        visited[srcNode] = true;
        int distance = 0;

        // Perform BFS layer by layer
        while (!nodesQueue.isEmpty()) {
            // Process all nodes in the current layer
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodesQueue.poll();

                // Visit all unvisited neighbors of the current node
                for (int neighbor : adjList.get(currentNode)) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    nodesQueue.add(neighbor);
                }
            }
            // Increment the distance for each layer
            distance++;
        }
        // Return the total distance (longest shortest path)
        return distance;
    }

    // Calculates the maximum number of groups for a connected component
    private int getNumberOfGroupsForComponent(
        ArrayList<ArrayList<Integer>> adjList,
        int node,
        int[] distances,
        boolean[] visited
    ) {
        // Start with the distance of the current node as the maximum
        int maxNumberOfGroups = distances[node];
        visited[node] = true;

        // Recursively calculate the maximum for all unvisited neighbors
        for (int neighbor : adjList.get(node)) {
            if (visited[neighbor]) continue;
            maxNumberOfGroups = Math.max(
                maxNumberOfGroups,
                getNumberOfGroupsForComponent(
                    adjList,
                    neighbor,
                    distances,
                    visited
                )
            );
        }
        return maxNumberOfGroups;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    # Main function to calculate the maximum number of magnificent sets
    def magnificentSets(self, n, edges):
        # Create adjacency list for the graph
        adj_list = [[] for _ in range(n)]
        for edge in edges:
            # Transition to 0-index
            adj_list[edge[0] - 1].append(edge[1] - 1)
            adj_list[edge[1] - 1].append(edge[0] - 1)

        # Initialize color array to -1
        colors = [-1] * n

        # Check if the graph is bipartite
        for node in range(n):
            if colors[node] != -1:
                continue
            # Start coloring from uncolored nodes
            colors[node] = 0
            if not self._is_bipartite(adj_list, node, colors):
                return -1

        # Calculate the longest shortest path for each node
        distances = [
            self._get_longest_shortest_path(adj_list, node, n)
            for node in range(n)
        ]

        # Calculate the total maximum number of groups across all components
        max_number_of_groups = 0
        visited = [False] * n
        for node in range(n):
            if visited[node]:
                continue
            # Add the number of groups for this component to the total
            max_number_of_groups += self._get_number_of_groups_for_component(
                adj_list, node, distances, visited
            )

        return max_number_of_groups

    # Checks if the graph is bipartite starting from the given node
    def _is_bipartite(self, adj_list, node, colors):
        for neighbor in adj_list[node]:
            # If a neighbor has the same color as the current node, the graph is not bipartite
            if colors[neighbor] == colors[node]:
                return False
            # If the neighbor is already colored, skip it
            if colors[neighbor] != -1:
                continue
            # Assign the opposite color to the neighbor
            colors[neighbor] = (colors[node] + 1) % 2
            # Recursively check bipartiteness for the neighbor; return false if it fails
            if not self._is_bipartite(adj_list, neighbor, colors):
                return False
        # If all neighbors are properly colored, return true
        return True

    # Computes the longest shortest path (height) in the graph starting from the source node
    def _get_longest_shortest_path(self, adj_list, src_node, n):
        # Initialize a queue for BFS and a visited array
        nodes_queue = deque([src_node])
        visited = [False] * n
        visited[src_node] = True
        distance = 0

        # Perform BFS layer by layer
        while nodes_queue:
            # Process all nodes in the current layer
            for _ in range(len(nodes_queue)):
                current_node = nodes_queue.popleft()
                # Visit all unvisited neighbors of the current node
                for neighbor in adj_list[current_node]:
                    if visited[neighbor]:
                        continue
                    visited[neighbor] = True
                    nodes_queue.append(neighbor)
            # Increment the distance for each layer
            distance += 1

        # Return the total distance (longest shortest path)
        return distance

    # Calculates the maximum number of groups for a connected component
    def _get_number_of_groups_for_component(
        self, adj_list, node, distances, visited
    ):
        # Start with the distance of the current node as the maximum
        max_number_of_groups = distances[node]
        visited[node] = True

        # Recursively calculate the maximum for all unvisited neighbors
        for neighbor in adj_list[node]:
            if visited[neighbor]:
                continue
            max_number_of_groups = max(
                max_number_of_groups,
                self._get_number_of_groups_for_component(
                    adj_list, neighbor, distances, visited
                ),
            )
        return max_number_of_groups
```

</details>

<br>

## Approach 2: BFS + Union-Find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Main function to calculate the maximum number of groups for the entire
    // graph
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n);
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);

        // Build the adjacency list and apply Union-Find for each edge
        for (auto edge : edges) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
            Union(edge[0] - 1, edge[1] - 1, parent, depth);
        }

        unordered_map<int, int> numOfGroupsForComponent;

        // For each node, calculate the maximum number of groups for its
        // component
        for (int node = 0; node < n; node++) {
            int numberOfGroups = getNumberOfGroups(adjList, node, n);
            if (numberOfGroups == -1) return -1;  // If invalid split, return -1
            int rootNode = find(node, parent);
            numOfGroupsForComponent[rootNode] =
                max(numOfGroupsForComponent[rootNode], numberOfGroups);
        }

        // Calculate the total number of groups across all components
        int totalNumberOfGroups = 0;
        for (auto [rootNode, numberOfGroups] : numOfGroupsForComponent) {
            totalNumberOfGroups += numberOfGroups;
        }
        return totalNumberOfGroups;
    }

private:
    // Find the root of the given node in the Union-Find structure
    int find(int node, vector<int> &parent) {
        while (parent[node] != -1) node = parent[node];
        return node;
    }

    // Union operation to merge two sets
    void Union(int node1, int node2, vector<int> &parent, vector<int> &depth) {
        node1 = find(node1, parent);
        node2 = find(node2, parent);

        // If both nodes already belong to the same set, no action needed
        if (node1 == node2) return;

        // Union by rank (depth) to keep the tree balanced
        if (depth[node1] < depth[node2]) swap(node1, node2);
        parent[node2] = node1;

        // If the depths are equal, increment the depth of the new root
        if (depth[node1] == depth[node2]) depth[node1]++;
    }

    // Function to calculate the number of groups for a given component starting
    // from srcNode
    int getNumberOfGroups(vector<vector<int>> &adjList, int srcNode, int n) {
        queue<int> nodesQueue;
        vector<int> layerSeen(n, -1);
        nodesQueue.push(srcNode);
        layerSeen[srcNode] = 0;
        int deepestLayer = 0;

        // Perform BFS to calculate the number of layers (groups)
        while (!nodesQueue.empty()) {
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                for (int neighbor : adjList[currentNode]) {
                    // If neighbor hasn't been visited, assign it to the next
                    // layer
                    if (layerSeen[neighbor] == -1) {
                        layerSeen[neighbor] = deepestLayer + 1;
                        nodesQueue.push(neighbor);
                    } else {
                        // If the neighbor is already in the same layer, return
                        // -1 (invalid partition)
                        if (layerSeen[neighbor] == deepestLayer) {
                            return -1;
                        }
                    }
                }
            }
            deepestLayer++;
        }
        return deepestLayer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Main function to calculate the maximum number of groups for the entire graph
    public int magnificentSets(int n, int[][] edges) {
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        int[] parent = new int[n];
        int[] depth = new int[n];
        Arrays.fill(parent, -1);

        // Build the adjacency list and apply Union-Find for each edge
        for (int[] edge : edges) {
            adjList.get(edge[0] - 1).add(edge[1] - 1);
            adjList.get(edge[1] - 1).add(edge[0] - 1);
            union(edge[0] - 1, edge[1] - 1, parent, depth);
        }

        Map<Integer, Integer> numOfGroupsForComponent = new HashMap<>();

        // For each node, calculate the maximum number of groups for its component
        for (int node = 0; node < n; node++) {
            int numberOfGroups = getNumberOfGroups(adjList, node, n);
            if (numberOfGroups == -1) return -1; // If invalid split, return -1
            int rootNode = find(node, parent);
            numOfGroupsForComponent.put(
                rootNode,
                Math.max(
                    numOfGroupsForComponent.getOrDefault(rootNode, 0),
                    numberOfGroups
                )
            );
        }

        // Calculate the total number of groups across all components
        int totalNumberOfGroups = 0;
        for (int numberOfGroups : numOfGroupsForComponent.values()) {
            totalNumberOfGroups += numberOfGroups;
        }
        return totalNumberOfGroups;
    }

    // Function to calculate the number of groups for a given component starting from srcNode
    private int getNumberOfGroups(
        List<List<Integer>> adjList,
        int srcNode,
        int n
    ) {
        Queue<Integer> nodesQueue = new LinkedList<>();
        int[] layerSeen = new int[n];
        Arrays.fill(layerSeen, -1);
        nodesQueue.offer(srcNode);
        layerSeen[srcNode] = 0;
        int deepestLayer = 0;

        // Perform BFS to calculate the number of layers (groups)
        while (!nodesQueue.isEmpty()) {
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodesQueue.poll();
                for (int neighbor : adjList.get(currentNode)) {
                    // If neighbor hasn't been visited, assign it to the next layer
                    if (layerSeen[neighbor] == -1) {
                        layerSeen[neighbor] = deepestLayer + 1;
                        nodesQueue.offer(neighbor);
                    } else {
                        // If the neighbor is already in the same layer, return -1 (invalid partition)
                        if (layerSeen[neighbor] == deepestLayer) {
                            return -1;
                        }
                    }
                }
            }
            deepestLayer++;
        }
        return deepestLayer;
    }

    // Find the root of the given node in the Union-Find structure
    private int find(int node, int[] parent) {
        while (parent[node] != -1) node = parent[node];
        return node;
    }

    // Union operation to merge two sets
    private void union(int node1, int node2, int[] parent, int[] depth) {
        node1 = find(node1, parent);
        node2 = find(node2, parent);

        // If both nodes already belong to the same set, no action needed
        if (node1 == node2) return;

        // Union by rank (depth) to keep the tree balanced
        if (depth[node1] < depth[node2]) {
            int temp = node1;
            node1 = node2;
            node2 = temp;
        }
        parent[node2] = node1;

        // If the depths are equal, increment the depth of the new root
        if (depth[node1] == depth[node2]) depth[node1]++;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Main function to calculate the maximum number of groups for the entire graph
    def magnificentSets(self, n, edges):
        adj_list = [[] for _ in range(n)]
        parent = [-1] * n
        depth = [0] * n

        # Build the adjacency list and apply Union-Find for each edge
        for edge in edges:
            adj_list[edge[0] - 1].append(edge[1] - 1)
            adj_list[edge[1] - 1].append(edge[0] - 1)
            self._union(edge[0] - 1, edge[1] - 1, parent, depth)

        num_of_groups_for_component = {}

        # For each node, calculate the maximum number of groups for its component
        for node in range(n):
            number_of_groups = self._get_number_of_groups(adj_list, node, n)
            if number_of_groups == -1:
                return -1  # If invalid split, return -1
            root_node = self._find(node, parent)
            num_of_groups_for_component[root_node] = max(
                num_of_groups_for_component.get(root_node, 0), number_of_groups
            )

        # Calculate the total number of groups across all components
        total_number_of_groups = sum(num_of_groups_for_component.values())
        return total_number_of_groups

    # Function to calculate the number of groups for a given component starting from srcNode
    def _get_number_of_groups(self, adj_list, src_node, n):
        nodes_queue = deque()
        layer_seen = [-1] * n
        nodes_queue.append(src_node)
        layer_seen[src_node] = 0
        deepest_layer = 0

        # Perform BFS to calculate the number of layers (groups)
        while nodes_queue:
            num_of_nodes_in_layer = len(nodes_queue)
            for _ in range(num_of_nodes_in_layer):
                current_node = nodes_queue.popleft()
                for neighbor in adj_list[current_node]:
                    # If neighbor hasn't been visited, assign it to the next layer
                    if layer_seen[neighbor] == -1:
                        layer_seen[neighbor] = deepest_layer + 1
                        nodes_queue.append(neighbor)
                    else:
                        # If the neighbor is already in the same layer, return -1 (invalid partition)
                        if layer_seen[neighbor] == deepest_layer:
                            return -1
            deepest_layer += 1
        return deepest_layer

    # Find the root of the given node in the Union-Find structure
    def _find(self, node, parent):
        while parent[node] != -1:
            node = parent[node]
        return node

    # Union operation to merge two sets
    def _union(self, node1, node2, parent, depth):
        node1 = self._find(node1, parent)
        node2 = self._find(node2, parent)

        # If both nodes already belong to the same set, no action needed
        if node1 == node2:
            return

        # Union by rank (depth) to keep the tree balanced
        if depth[node1] < depth[node2]:
            node1, node2 = node2, node1
        parent[node2] = node1

        # If the depths are equal, increment the depth of the new root
        if depth[node1] == depth[node2]:
            depth[node1] += 1
```

</details>
