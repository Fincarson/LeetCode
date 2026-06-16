# 2685. Count the Number of Complete Components

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-the-number-of-complete-components/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 2685 - Count the Number of Complete Components](https://leetcode.com/problems/count-the-number-of-complete-components/)

## Problem

You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

### Example 1

```text
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.
```

### Example 2

```text
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
```

## Constraints

- 1 <= n <= 50
- 0 <= edges.length <= n * (n - 1) / 2
- edges[i].length == 2
- 0 <= ai, bi <= n - 1
- ai != bi
- There are no repeated edges.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2685. Count the Number of Complete Components

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Adjacency List | C++, Java, Python3 |
| Depth-First Search (DFS) | C++, Java, Python3 |
| Breadth-First Search (BFS) | C++, Java, Python3 |
| Disjoint Set Union (Union-Find) | C++, Java, Python3 |

## Approach 1: Adjacency List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // adjacency lists for each vertex
        vector<vector<int>> graph(n);
        // map to store frequency of each unique adjacency list
        unordered_map<string, int> componentFreq;

        // initialize adjacency lists with self-loops
        for (int vertex = 0; vertex < n; vertex++) {
            graph[vertex].push_back(vertex);
        }

        // build adjacency lists from edges
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // count frequency of each unique adjacency pattern
        for (int vertex = 0; vertex < n; vertex++) {
            vector<int> neighbors = graph[vertex];
            sort(neighbors.begin(), neighbors.end());

            // convert vector to string for hashing
            string key;
            for (int num : neighbors) {
                key += to_string(num) + ",";
            }
            componentFreq[key]++;
        }

        // count complete components where size equals frequency
        int completeCount = 0;
        for (const auto& entry : componentFreq) {
            // count commas to get original vector size
            int size = count(entry.first.begin(), entry.first.end(), ',');
            if (size == entry.second) {
                completeCount++;
            }
        }

        return completeCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int countCompleteComponents(int n, int[][] edges) {
        // Adjacency lists for each vertex
        List<Integer>[] graph = new ArrayList[n];
        // Map to store frequency of each unique adjacency list
        Map<List<Integer>, Integer> componentFreq = new HashMap<>();

        // Initialize adjacency lists with self-loops
        for (int vertex = 0; vertex < n; vertex++) {
            graph[vertex] = new ArrayList<>();
            graph[vertex].add(vertex);
        }

        // Build adjacency lists from edges
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        // Count frequency of each unique adjacency pattern
        for (int vertex = 0; vertex < n; vertex++) {
            List<Integer> neighbors = graph[vertex];
            Collections.sort(neighbors);
            componentFreq.put(
                neighbors,
                componentFreq.getOrDefault(neighbors, 0) + 1
            );
        }

        // Count complete components where size equals frequency
        int completeCount = 0;
        for (Map.Entry<
            List<Integer>,
            Integer
        > entry : componentFreq.entrySet()) {
            if (entry.getKey().size() == entry.getValue()) {
                completeCount++;
            }
        }

        return completeCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        # Adjacency lists for each vertex
        graph = [[] for _ in range(n)]
        # Map to store frequency of each unique adjacency list
        component_freq = defaultdict(int)

        # Initialize adjacency lists with self-loops
        for vertex in range(n):
            graph[vertex] = [vertex]

        # Build adjacency lists from edges
        for v1, v2 in edges:
            graph[v1].append(v2)
            graph[v2].append(v1)

        # Count frequency of each unique adjacency pattern
        for vertex in range(n):
            neighbors = tuple(sorted(graph[vertex]))
            component_freq[neighbors] += 1

        # Count complete components where size equals frequency
        return sum(
            1
            for neighbors, freq in component_freq.items()
            if len(neighbors) == freq
        )
```

</details>

<br>

## Approach 2: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Adjacency lists for each vertex
        vector<vector<int>> graph(n);

        // Build adjacency lists from edges
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int completeCount = 0;
        unordered_set<int> visited;

        // Process each unvisited vertex
        for (int vertex = 0; vertex < n; vertex++) {
            if (visited.count(vertex)) continue;

            // arr[0] = vertices count, arr[1] = total edges count
            int componentInfo[2] = {0, 0};
            dfs(vertex, graph, visited, componentInfo);

            // Check if component is complete - edges should be vertices *
            // (vertices-1)
            if (componentInfo[0] * (componentInfo[0] - 1) == componentInfo[1]) {
                completeCount++;
            }
        }
        return completeCount;
    }

private:
    void dfs(int curr, vector<vector<int>>& graph, unordered_set<int>& visited,
             int componentInfo[2]) {
        visited.insert(curr);
        componentInfo[0]++;  // Increment vertex count
        componentInfo[1] +=
            graph[curr].size();  // Add edges from current vertex

        // Explore unvisited neighbors
        for (int next : graph[curr]) {
            if (!visited.count(next)) {
                dfs(next, graph, visited, componentInfo);
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

    public int countCompleteComponents(int n, int[][] edges) {
        // Adjacency lists for each vertex
        List<Integer>[] graph = new ArrayList[n];

        // Initialize empty adjacency lists
        for (int vertex = 0; vertex < n; vertex++) {
            graph[vertex] = new ArrayList<>();
        }

        // Build adjacency lists from edges
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        int completeCount = 0;
        Set<Integer> visited = new HashSet<>();

        // Process each unvisited vertex
        for (int vertex = 0; vertex < n; vertex++) {
            if (visited.contains(vertex)) continue;

            // arr[0] = vertices count, arr[1] = total edges count
            int[] componentInfo = new int[2];
            dfs(vertex, graph, visited, componentInfo);

            // Check if component is complete - edges should be vertices * (vertices-1)
            if (componentInfo[0] * (componentInfo[0] - 1) == componentInfo[1]) {
                completeCount++;
            }
        }
        return completeCount;
    }

    private void dfs(
        int curr,
        List<Integer>[] graph,
        Set<Integer> visited,
        int[] componentInfo
    ) {
        visited.add(curr);
        componentInfo[0]++; // Increment vertex count
        componentInfo[1] += graph[curr].size(); // Add edges from current vertex

        // Explore unvisited neighbors
        for (int next : graph[curr]) {
            if (!visited.contains(next)) {
                dfs(next, graph, visited, componentInfo);
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
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        # Adjacency lists for each vertex
        graph = defaultdict(list)

        # Build adjacency lists from edges
        for v1, v2 in edges:
            graph[v1].append(v2)
            graph[v2].append(v1)

        complete_count = 0
        visited = set()

        def _dfs(curr: int, info: list) -> None:
            visited.add(curr)
            info[0] += 1  # Increment vertex count
            info[1] += len(graph[curr])  # Add edges from current vertex

            # Explore unvisited neighbors
            for next_vertex in graph[curr]:
                if next_vertex not in visited:
                    _dfs(next_vertex, info)

        # Process each unvisited vertex
        for vertex in range(n):
            if vertex in visited:
                continue

            # info[0] = vertices count, info[1] = total edges count
            component_info = [0, 0]
            _dfs(vertex, component_info)

            # Check if component is complete - edges should be vertices * (vertices-1)
            if component_info[0] * (component_info[0] - 1) == component_info[1]:
                complete_count += 1

        return complete_count
```

</details>

<br>

## Approach 3: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Create adjacency list representation of the graph
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        // Process each unvisited vertex
        for (int vertex = 0; vertex < n; vertex++) {
            if (!visited[vertex]) {
                // BFS to find all vertices in the current component
                vector<int> component;
                queue<int> q;
                q.push(vertex);
                visited[vertex] = true;

                while (!q.empty()) {
                    int current = q.front();
                    q.pop();
                    component.push_back(current);

                    // Process neighbors
                    for (int neighbor : graph[current]) {
                        if (!visited[neighbor]) {
                            q.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }

                // Check if component is complete (all vertices have the right
                // number of edges)
                bool isComplete = true;
                for (int node : component) {
                    if (graph[node].size() != component.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int countCompleteComponents(int n, int[][] edges) {
        // Create adjacency list representation of the graph
        List<Integer>[] graph = new ArrayList[n];
        for (int vertex = 0; vertex < n; vertex++) {
            graph[vertex] = new ArrayList<>();
        }

        // Build graph from edges
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].add(v);
            graph[v].add(u);
        }

        boolean[] visited = new boolean[n];
        int completeComponents = 0;

        // Process each unvisited vertex
        for (int vertex = 0; vertex < n; vertex++) {
            if (!visited[vertex]) {
                // BFS to find all vertices in the current component
                List<Integer> component = new ArrayList<>();
                Queue<Integer> queue = new LinkedList<>();
                queue.add(vertex);
                visited[vertex] = true;

                while (!queue.isEmpty()) {
                    int current = queue.poll();
                    component.add(current);

                    // Process neighbors
                    for (int neighbor : graph[current]) {
                        if (!visited[neighbor]) {
                            queue.add(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }

                // Check if component is complete (all vertices have the right number of edges)
                boolean isComplete = true;
                for (int node : component) {
                    if (graph[node].size() != component.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countCompleteComponents(self, n: int, edges: list[list[int]]) -> int:
        # Create adjacency list representation of the graph
        graph = [[] for _ in range(n)]

        # Build graph from edges
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n
        complete_components = 0

        # Process each unvisited vertex
        for vertex in range(n):
            if not visited[vertex]:
                # BFS to find all vertices in the current component
                component = []
                queue = [vertex]
                visited[vertex] = True

                while queue:
                    current = queue.pop(0)
                    component.append(current)

                    # Process neighbors
                    for neighbor in graph[current]:
                        if not visited[neighbor]:
                            queue.append(neighbor)
                            visited[neighbor] = True

                # Check if component is complete (all vertices have the right number of edges)
                is_complete = True
                for node in component:
                    if len(graph[node]) != len(component) - 1:
                        is_complete = False
                        break

                if is_complete:
                    complete_components += 1

        return complete_components
```

</details>

<br>

## Approach 4: Disjoint Set Union (Union-Find)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Initialize Union Find and edge counter
        UnionFind dsu(n);
        unordered_map<int, int> edgeCount;

        // Connect components using edges
        for (const auto& edge : edges) {
            dsu.unionSets(edge[0], edge[1]);
        }

        // Count edges in each component
        for (const auto& edge : edges) {
            int root = dsu.find(edge[0]);
            edgeCount[root]++;
        }

        // Check if each component is complete
        int completeCount = 0;
        for (int vertex = 0; vertex < n; vertex++) {
            if (dsu.find(vertex) == vertex) {  // If vertex is root
                int nodeCount = dsu.size[vertex];
                int expectedEdges = (nodeCount * (nodeCount - 1)) / 2;
                if (edgeCount[vertex] == expectedEdges) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }

private:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;  // Tracks size of each component

        UnionFind(int n) : parent(n, -1), size(n, 1) {}

        // Find root of component with path compression
        int find(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union by size
        void unionSets(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return;
            }

            // Merge smaller component into larger one
            if (size[root1] > size[root2]) {
                parent[root2] = root1;
                size[root1] += size[root2];
            } else {
                parent[root1] = root2;
                size[root2] += size[root1];
            }
        }
    };
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int countCompleteComponents(int n, int[][] edges) {
        // Initialize Union Find and edge counter
        UnionFind dsu = new UnionFind(n);
        Map<Integer, Integer> edgeCount = new HashMap<>();

        // Connect components using edges
        for (int[] edge : edges) {
            dsu.union(edge[0], edge[1]);
        }

        // Count edges in each component
        for (int[] edge : edges) {
            int root = dsu.find(edge[0]);
            edgeCount.put(root, edgeCount.getOrDefault(root, 0) + 1);
        }

        // Check if each component is complete
        int completeCount = 0;
        for (int vertex = 0; vertex < n; vertex++) {
            if (dsu.find(vertex) == vertex) { // If vertex is root
                int nodeCount = dsu.size[vertex];
                int expectedEdges = (nodeCount * (nodeCount - 1)) / 2;
                if (edgeCount.getOrDefault(vertex, 0) == expectedEdges) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }

    class UnionFind {

        int[] parent;
        int[] size; // Tracks size of each component

        UnionFind(int n) {
            parent = new int[n];
            size = new int[n];
            Arrays.fill(parent, -1);
            Arrays.fill(size, 1);
        }

        // Find root of component with path compression
        int find(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union by size
        void union(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return;
            }

            // Merge smaller component into larger one
            if (size[root1] > size[root2]) {
                parent[root2] = root1;
                size[root1] += size[root2];
            } else {
                parent[root1] = root2;
                size[root2] += size[root1];
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n
        self.size = [1] * n

    def _find(self, node):
        # Find root of component with path compression
        if self.parent[node] == -1:
            return node
        self.parent[node] = self._find(self.parent[node])
        return self.parent[node]

    def _union(self, node_1, node_2):
        # Union by size
        root_1 = self._find(node_1)
        root_2 = self._find(node_2)

        if root_1 == root_2:
            return

        # Merge smaller component into larger one
        if self.size[root_1] > self.size[root_2]:
            self.parent[root_2] = root_1
            self.size[root_1] += self.size[root_2]
        else:
            self.parent[root_1] = root_2
            self.size[root_2] += self.size[root_1]


class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        # Initialize Union Find and edge counter
        dsu = UnionFind(n)
        edge_count = {}

        # Connect components using edges
        for edge in edges:
            dsu._union(edge[0], edge[1])

        # Count edges in each component
        for edge in edges:
            root = dsu._find(edge[0])
            edge_count[root] = edge_count.get(root, 0) + 1

        # Check if each component is complete
        complete_count = 0
        for vertex in range(n):
            if dsu._find(vertex) == vertex:  # If vertex is root
                node_count = dsu.size[vertex]
                expected_edges = (node_count * (node_count - 1)) // 2
                if edge_count.get(vertex, 0) == expected_edges:
                    complete_count += 1

        return complete_count
```

</details>
