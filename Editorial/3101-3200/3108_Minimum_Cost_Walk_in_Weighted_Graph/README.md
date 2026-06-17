# 3108. Minimum Cost Walk in Weighted Graph

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/)  
`Array` `Bit Manipulation` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 3108 - Minimum Cost Walk in Weighted Graph](https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/)

## Problem

There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

### Example 1

## Constraints

- 2 <= n <= 105
- 0 <= edges.length <= 105
- edges[i].length == 3
- 0 <= ui, vi <= n - 1
- ui != vi
- 0 <= wi <= 105
- 1 <= query.length <= 105
- query[i].length == 2
- 0 <= si, ti <= n - 1
- si != ti

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3108. Minimum Cost Walk in Weighted Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Disjoint-Set (Union-Find) | C++, Java, Python3 |
| Breadth-First Search (BFS) | C++, Java, Python3 |
| Depth-First Search (DFS) | C++, Java, Python3 |

## Approach 1: Disjoint-Set (Union-Find)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> parent;
    vector<int> depth;

    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Initialize the parent array with -1 as initially each node belongs to
        // its own component
        parent.resize(n, -1);
        depth.resize(n, 0);

        // All values are initially set to the number with only 1s in its binary
        // representation
        vector<unsigned int> componentCost(n, -1);

        // Construct the connected components of the graph
        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }

        // Calculate the cost of each component by performing bitwise AND of all
        // edge weights in it
        for (auto& edge : edges) {
            int root = find(edge[0]);
            componentCost[root] &= edge[2];
        }

        vector<int> answer;
        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            // If the two nodes are in different connected components, return -1
            if (find(start) != find(end)) {
                answer.push_back(-1);
            } else {
                // Find the root of the edge's component
                int root = find(start);
                // Return the precomputed cost of the component
                answer.push_back(componentCost[root]);
            }
        }
        return answer;
    }

private:
    // Find function to return the root (representative) of a node's component
    int find(int node) {
        // If the node is its own parent, it is the root of the component
        if (parent[node] == -1) return node;
        // Otherwise, recursively find the root and apply path compression
        return parent[node] = find(parent[node]);
    }

    // Union function to merge the components of two nodes
    void Union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        // If the two nodes are already in the same component, do nothing
        if (root1 == root2) return;

        // Union by depth: ensure the root of the deeper tree becomes the parent
        if (depth[root1] < depth[root2]) swap(root1, root2);

        // Merge the two components by making root1 the parent of root2
        parent[root2] = root1;

        // If both components had the same depth, increase the depth of the new
        // root
        if (depth[root1] == depth[root2]) depth[root1]++;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    int[] parent;
    int[] depth;

    public int[] minimumCost(int n, int[][] edges, int[][] queries) {
        // Initialize the parent array with -1 as initially each node belongs to its own component
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = -1;

        depth = new int[n];

        // All values are initially set to the number with only 1s in its binary representation
        int[] componentCost = new int[n];
        for (int i = 0; i < n; i++) {
            componentCost[i] = Integer.MAX_VALUE;
        }

        // Construct the connected components of the graph
        for (int[] edge : edges) {
            union(edge[0], edge[1]);
        }

        // Calculate the cost of each component by performing bitwise AND of all edge weights in it
        for (int[] edge : edges) {
            int root = find(edge[0]);
            componentCost[root] &= edge[2];
        }

        int[] answer = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            // If the two nodes are in different connected components, return -1
            if (find(start) != find(end)) {
                answer[i] = -1;
            } else {
                // Find the root of the edge's component
                int root = find(start);
                // Return the precomputed cost of the component
                answer[i] = componentCost[root];
            }
        }
        return answer;
    }

    // Find function to return the root (representative) of a node's component
    private int find(int node) {
        // If the node is its own parent, it is the root of the component
        if (parent[node] == -1) return node;
        // Otherwise, recursively find the root and apply path compression
        return parent[node] = find(parent[node]);
    }

    // Union function to merge the components of two nodes
    private void union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        // If the two nodes are already in the same component, do nothing
        if (root1 == root2) return;

        // Union by depth: ensure the root of the deeper tree becomes the parent
        if (depth[root1] < depth[root2]) {
            int temp = root1;
            root1 = root2;
            root2 = temp;
        }

        // Merge the two components by making root1 the parent of root2
        parent[root2] = root1;

        // If both components had the same depth, increase the depth of the new root
        if (depth[root1] == depth[root2]) {
            depth[root1]++;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumCost(self, n, edges, queries):
        # Initialize the parent array with -1 as initially each node belongs to its own component
        self.parent = [-1] * n
        self.depth = [0] * n

        # All values are initially set to the number with only 1s in its binary representation
        component_cost = [-1] * n

        # Construct the connected components of the graph
        for edge in edges:
            self._union(edge[0], edge[1])

        # Calculate the cost of each component by performing bitwise AND of all edge weights in it
        for edge in edges:
            root = self._find(edge[0])
            component_cost[root] &= edge[2]

        answer = []
        for query in queries:
            start, end = query

            # If the two nodes are in different connected components, return -1
            if self._find(start) != self._find(end):
                answer.append(-1)
            else:
                # Find the root of the edge's component
                root = self._find(start)
                # Return the precomputed cost of the component
                answer.append(component_cost[root])

        return answer

    # Find function to return the root (representative) of a node's component
    def _find(self, node):
        # If the node is its own parent, it is the root of the component
        if self.parent[node] == -1:
            return node
        # Otherwise, recursively find the root and apply path compression
        self.parent[node] = self._find(self.parent[node])
        return self.parent[node]

    # Union function to merge the components of two nodes
    def _union(self, node1, node2):
        root1 = self._find(node1)
        root2 = self._find(node2)

        # If the two nodes are already in the same component, do nothing
        if root1 == root2:
            return

        # Union by depth: ensure the root of the deeper tree becomes the parent
        if self.depth[root1] < self.depth[root2]:
            root1, root2 = root2, root1

        # Merge the two components by making root1 the parent of root2
        self.parent[root2] = root1

        # If both components had the same depth, increase the depth of the new root
        if self.depth[root1] == self.depth[root2]:
            self.depth[root1] += 1
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Create the adjacency list of the graph
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        // Array to store the component ID of each node
        vector<int> components(n);
        vector<int> componentCost;

        int componentId = 0;

        // Perform BFS for each unvisited node to identify components and
        // calculate their costs
        for (int node = 0; node < n; node++) {
            // If the node hasn't been visited, it's a new component
            if (!visited[node]) {
                // Get the component cost and mark all nodes in the component
                componentCost.push_back(getComponentCost(
                    node, adjList, visited, components, componentId));
                // Increment the component ID for the next component
                componentId++;
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            if (components[start] == components[end]) {
                // If they are in the same component, return the precomputed
                // cost for the component
                answer.push_back(componentCost[components[start]]);
            } else {
                // If they are in different components, return -1
                answer.push_back(-1);
            }
        }

        return answer;
    }

private:
    // Helper function to calculate the cost of a component using BFS
    int getComponentCost(int source, vector<vector<pair<int, int>>>& adjList,
                         vector<bool>& visited, vector<int>& components,
                         int componentId) {
        queue<int> nodesQueue;

        // Initialize the component cost to the number that has only 1s in its
        // binary representation
        int componentCost = INT_MAX;

        nodesQueue.push(source);
        visited[source] = true;

        // Perform BFS to explore the component and calculate the cost
        while (!nodesQueue.empty()) {
            int node = nodesQueue.front();
            nodesQueue.pop();

            // Mark the node as part of the current component
            components[node] = componentId;

            // Explore all neighbors of the current node
            for (auto& [neighbor, weight] : adjList[node]) {
                // Update the component cost by performing a bitwise AND of the
                // edge weights
                componentCost &= weight;

                // If the neighbor hasn't been visited, mark it as visited and
                // add it to the queue
                if (visited[neighbor]) continue;
                visited[neighbor] = true;
                nodesQueue.push(neighbor);
            }
        }

        return componentCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] minimumCost(int n, int[][] edges, int[][] queries) {
        // Create the adjacency list of the graph
        List<List<int[]>> adjList = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>(2));
        }
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(new int[] { edge[1], edge[2] });
            adjList.get(edge[1]).add(new int[] { edge[0], edge[2] });
        }

        boolean[] visited = new boolean[n];

        // Array to store the component ID of each node
        int[] components = new int[n];
        List<Integer> componentCost = new ArrayList<>(n);

        int componentId = 0;

        // Perform BFS for each unvisited node to identify components and calculate their costs
        for (int node = 0; node < n; node++) {
            // If the node hasn't been visited, it's a new component
            if (!visited[node]) {
                // Get the component cost and mark all nodes in the component
                componentCost.add(
                    getComponentCost(
                        node,
                        adjList,
                        visited,
                        components,
                        componentId
                    )
                );
                // Increment the component ID for the next component
                componentId++;
            }
        }

        int[] answer = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if (components[start] == components[end]) {
                // If they are in the same component, return the precomputed cost for the component
                answer[i] = componentCost.get(components[start]);
            } else {
                // If they are in different components, return -1
                answer[i] = -1;
            }
        }

        return answer;
    }

    // Helper function to calculate the cost of a component using BFS
    private int getComponentCost(
        int source,
        List<List<int[]>> adjList,
        boolean[] visited,
        int[] components,
        int componentId
    ) {
        Queue<Integer> nodesQueue = new LinkedList<>();

        // Initialize the component cost to the number that has only 1s in its binary representation
        int componentCost = Integer.MAX_VALUE;

        nodesQueue.offer(source);
        visited[source] = true;

        // Perform BFS to explore the component and calculate the cost
        while (!nodesQueue.isEmpty()) {
            int node = nodesQueue.poll();

            // Mark the node as part of the current component
            components[node] = componentId;

            // Explore all neighbors of the current node
            for (int[] neighbor : adjList.get(node)) {
                int weight = neighbor[1];
                // Update the component cost by performing a bitwise AND of the edge weights
                componentCost &= weight;

                // If the neighbor hasn't been visited, mark it as visited and add it to the queue
                if (visited[neighbor[0]]) continue;
                visited[neighbor[0]] = true;
                nodesQueue.offer(neighbor[0]);
            }
        }

        return componentCost;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumCost(self, n, edges, queries):
        # Create the adjacency list of the graph
        adj_list = [[] for _ in range(n)]
        for edge in edges:
            adj_list[edge[0]].append((edge[1], edge[2]))
            adj_list[edge[1]].append((edge[0], edge[2]))

        visited = [False] * n

        # Array to store the component ID of each node
        components = [0] * n
        component_cost = []

        component_id = 0

        # Perform BFS for each unvisited node to identify components and calculate their costs
        for node in range(n):
            if not visited[node]:
                # Get the component cost and mark all nodes in the component
                component_cost.append(
                    self._get_component_cost(
                        node, adj_list, visited, components, component_id
                    )
                )
                component_id += 1

        result = []
        for query in queries:
            start, end = query

            if components[start] == components[end]:
                # If they are in the same component, return the precomputed cost for the component
                result.append(component_cost[components[start]])
            else:
                # If they are in different components, return -1
                result.append(-1)

        return result

    # Helper function to calculate the cost of a component using BFS
    def _get_component_cost(
        self, source, adj_list, visited, components, component_id
    ):
        nodes_queue = deque()

        # Initialize the component cost to the number that has only 1s in its binary representation
        component_cost = -1

        nodes_queue.append(source)
        visited[source] = True

        # Perform BFS to explore the component and calculate the cost
        while nodes_queue:
            node = nodes_queue.popleft()

            # Mark the node as part of the current component
            components[node] = component_id

            # Explore all neighbors of the current node
            for neighbor, weight in adj_list[node]:
                # Update the component cost by performing a bitwise AND of the edge weights
                component_cost &= weight

                # If the neighbor hasn't been visited, mark it as visited and add it to the queue
                if visited[neighbor]:
                    continue
                visited[neighbor] = True
                nodes_queue.append(neighbor)

        return component_cost
```

</details>

<br>

## Approach 3: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Create the adjacency list of the graph
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        // Array to store the component ID of each node
        vector<int> components(n);
        vector<int> componentCost;

        int componentId = 0;

        // Perform DFS for each unvisited node to identify components and
        // calculate their costs
        for (int node = 0; node < n; node++) {
            // If the node hasn't been visited, it's a new component
            if (!visited[node]) {
                // Get the component cost and mark all nodes in the component
                componentCost.push_back(getComponentCost(
                    node, adjList, visited, components, componentId));
                // Increment the component ID for the next component
                componentId++;
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            if (components[start] == components[end]) {
                // If they are in the same component, return the precomputed
                // cost for the component
                answer.push_back(componentCost[components[start]]);
            } else {
                // If they are in different components, return -1
                answer.push_back(-1);
            }
        }

        return answer;
    }

private:
    // Helper function to calculate the cost of a component using DFS
    int getComponentCost(int node, vector<vector<pair<int, int>>>& adjList,
                         vector<bool>& visited, vector<int>& components,
                         int componentId) {
        // Initialize the cost to the number that has only 1s in its
        // binary representation
        int currentCost = INT_MAX;

        // Mark the node as part of the current component
        components[node] = componentId;
        visited[node] = true;

        // Explore all neighbors of the current node
        for (auto& [neighbor, weight] : adjList[node]) {
            // Update the cost by performing a bitwise AND of the edge
            // weights
            currentCost &= weight;

            if (!visited[neighbor]) {
                // Recursively calculate the cost of the rest of the component
                // and accumulate it into currentCost
                currentCost &= getComponentCost(neighbor, adjList, visited,
                                                components, componentId);
            }
        }

        return currentCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] minimumCost(int n, int[][] edges, int[][] queries) {
        // Create the adjacency list of the graph
        List<List<int[]>> adjList = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>(2));
        }
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(new int[] { edge[1], edge[2] });
            adjList.get(edge[1]).add(new int[] { edge[0], edge[2] });
        }

        boolean[] visited = new boolean[n];

        // Array to store the component ID of each node
        int[] components = new int[n];
        List<Integer> componentCost = new ArrayList<>(n);

        int componentId = 0;

        // Perform DFS for each unvisited node to identify components and calculate their costs
        for (int node = 0; node < n; node++) {
            // If the node hasn't been visited, it's a new component
            if (!visited[node]) {
                // Get the component cost and mark all nodes in the component
                componentCost.add(
                    getComponentCost(
                        node,
                        adjList,
                        visited,
                        components,
                        componentId
                    )
                );
                // Increment the component ID for the next component
                componentId++;
            }
        }

        int[] answer = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if (components[start] == components[end]) {
                // If they are in the same component, return the precomputed cost for the component
                answer[i] = componentCost.get(components[start]);
            } else {
                // If they are in different components, return -1
                answer[i] = -1;
            }
        }

        return answer;
    }

    // Helper function to calculate the cost of a component using BFS
    private int getComponentCost(
        int node,
        List<List<int[]>> adjList,
        boolean[] visited,
        int[] components,
        int componentId
    ) {
        // Initialize the cost to the number that has only 1s in its
        // binary representation
        int currentCost = Integer.MAX_VALUE;

        // Mark the node as part of the current component
        components[node] = componentId;
        visited[node] = true;

        // Explore all neighbors of the current node
        for (int[] neighbor : adjList.get(node)) {
            int weight = neighbor[1];

            // Update the cost by performing a bitwise AND of the edge
            // weights
            currentCost &= weight;

            if (!visited[neighbor[0]]) {
                // Recursively calculate the cost of the rest of the component
                // and accumulate it into currentCost
                currentCost &= getComponentCost(
                    neighbor[0],
                    adjList,
                    visited,
                    components,
                    componentId
                );
            }
        }

        return currentCost;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumCost(self, n, edges, queries):
        # Create the adjacency list of the graph
        adj_list = [[] for _ in range(n)]
        for edge in edges:
            adj_list[edge[0]].append((edge[1], edge[2]))
            adj_list[edge[1]].append((edge[0], edge[2]))

        visited = [False] * n

        # Array to store the component ID of each node
        components = [0] * n
        component_cost = []

        component_id = 0

        # Perform DFS for each unvisited node to identify components and calculate their costs
        for node in range(n):
            if not visited[node]:
                # Get the component cost and mark all nodes in the component
                component_cost.append(
                    self._get_component_cost(
                        node, adj_list, visited, components, component_id
                    )
                )
                component_id += 1

        result = []
        for query in queries:
            start, end = query

            if components[start] == components[end]:
                # If they are in the same component, return the precomputed cost for the component
                result.append(component_cost[components[start]])
            else:
                # If they are in different components, return -1
                result.append(-1)

        return result

    # Helper function to calculate the cost of a component using BFS
    def _get_component_cost(
        self, node, adj_list, visited, components, component_id
    ):

        # Initialize the cost to the number that has only 1s in its binary representation
        current_cost = -1

        # Mark the node as part of the current component
        components[node] = component_id
        visited[node] = True

        # Explore all neighbors of the current node
        for neighbor, weight in adj_list[node]:
            # Update the component cost by performing a bitwise AND of the edge weights
            current_cost &= weight
            if not visited[neighbor]:
                # Recursively calculate the cost of the rest of the component
                # and accumulate it into currentCost
                current_cost &= self._get_component_cost(
                    neighbor, adj_list, visited, components, component_id
                )

        return current_cost
```

</details>
