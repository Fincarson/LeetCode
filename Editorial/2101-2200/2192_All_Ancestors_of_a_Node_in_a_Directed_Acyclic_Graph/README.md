# 2192. All Ancestors of a Node in a Directed Acyclic Graph

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/)  
`Depth-First Search` `Breadth-First Search` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 2192 - All Ancestors of a Node in a Directed Acyclic Graph](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/)

## Problem

You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.

### Example 1

```text
Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.
```

### Example 2

```text
Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Node 0 does not have any ancestor.
- Node 1 has one ancestor 0.
- Node 2 has two ancestors 0 and 1.
- Node 3 has three ancestors 0, 1, and 2.
- Node 4 has four ancestors 0, 1, 2, and 3.
```

## Constraints

- 1 <= n <= 1000
- 0 <= edges.length <= min(2000, n * (n - 1) / 2)
- edges[i].length == 2
- 0 <= fromi, toi <= n - 1
- fromi != toi
- There are no duplicate edges.
- The graph is directed and acyclic.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Restricted Paths From First to Last Node](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2192. All Ancestors of a Node in a Directed Acyclic Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search (Reversed Graph) | C++, Java, Python3 |
| Depth First Search (Optimized) | C++, Java, Python3 |
| Topological Sort (BFS) | C++, Java, Python3 |

## Approach 1: Depth First Search (Reversed Graph)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Initialize adjacency list for the graph
        vector<vector<int>> adjacencyList(n);

        // Populate the adjacency list with reversed edges
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[to].push_back(from);
        }

        vector<vector<int>> ancestorsList;

        // For each node, find all its ancestors (children in reversed graph)
        for (int i = 0; i < n; i++) {
            vector<int> ancestors;
            unordered_set<int> visited;
            findChildren(i, adjacencyList, visited);
            // Add visited nodes to the current nodes' ancestor list
            for (int node = 0; node < n; node++) {
                if (node == i) continue;
                if (visited.find(node) != visited.end())
                    ancestors.push_back(node);
            }
            ancestorsList.push_back(ancestors);
        }

        return ancestorsList;
    }

private:
    // Helper method to perform DFS and find all children of a given node
    void findChildren(int currentNode, vector<vector<int>>& adjacencyList,
                      unordered_set<int>& visitedNodes) {
        // Mark current node as visited
        visitedNodes.insert(currentNode);

        // Recursively traverse all neighbors
        for (int neighbour : adjacencyList[currentNode]) {
            if (visitedNodes.find(neighbour) == visitedNodes.end()) {
                findChildren(neighbour, adjacencyList, visitedNodes);
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

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        // Initialize adjacency list for the graph
        List<Integer>[] adjacencyList = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adjacencyList[i] = new ArrayList<>();
        }

        // Populate the adjacency list with reversed edges
        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[to].add(from);
        }

        List<List<Integer>> ancestorsList = new ArrayList<>();

        // For each node, find all its ancestors (children in reversed graph)
        for (int i = 0; i < n; i++) {
            List<Integer> ancestors = new ArrayList<>();
            Set<Integer> visited = new HashSet<>();
            findChildren(i, adjacencyList, visited);
            // Add visited nodes to the current nodes' ancestor list
            for (int node = 0; node < n; node++) {
                if (node == i) continue;
                if (visited.contains(node)) ancestors.add(node);
            }
            ancestorsList.add(ancestors);
        }

        return ancestorsList;
    }

    // Helper method to perform DFS and find all children of a given node
    private void findChildren(
        int currentNode,
        List<Integer>[] adjacencyList,
        Set<Integer> visitedNodes
    ) {
        // Mark current node as visited
        visitedNodes.add(currentNode);

        // Recursively traverse all neighbors
        for (int neighbour : adjacencyList[currentNode]) {
            if (!visitedNodes.contains(neighbour)) {
                findChildren(neighbour, adjacencyList, visitedNodes);
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
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        # Initialize adjacency list for the graph
        adjacency_list = [[] for _ in range(n)]

        # Populate the adjacency list with reversed edges
        for from_node, to_node in edges:
            adjacency_list[to_node].append(from_node)

        ancestors_list = []

        # For each node, find all its ancestors (children in reversed graph)
        for i in range(n):
            ancestors = []
            visited = set()
            self.find_children(i, adjacency_list, visited)
            # Add visited nodes to the current nodes' ancestor list
            for node in range(n):
                if node == i:
                    continue
                if node in visited:
                    ancestors.append(node)
            ancestors_list.append(ancestors)

        return ancestors_list

    # Helper method to perform DFS and find all children of a given node
    def find_children(self, current_node, adjacency_list, visited_nodes):
        # Mark current node as visited
        visited_nodes.add(current_node)

        # Recursively traverse all neighbors
        for neighbour in adjacency_list[current_node]:
            if neighbour not in visited_nodes:
                self.find_children(neighbour, adjacency_list, visited_nodes)
```

</details>

<br>

## Approach 2: Depth First Search (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Initialize adjacency list for each node and ancestors list
        vector<vector<int>> adjacencyList(n);
        vector<vector<int>> ancestors(n);

        // Populate the adjacency list with edges
        for (vector<int> edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
        }

        // Perform DFS for each node to find all its ancestors
        for (int i = 0; i < n; i++) {
            findAncestorsDFS(i, adjacencyList, i, ancestors);
        }

        return ancestors;
    }

private:
    // Helper method to perform DFS and find ancestors
    void findAncestorsDFS(int ancestor, vector<vector<int>>& adjacencyList,
                          int currentNode, vector<vector<int>>& ancestors) {
        for (int childNode : adjacencyList[currentNode]) {
            // Check if the ancestor is already added to avoid duplicates
            if (ancestors[childNode].empty() ||
                ancestors[childNode].back() != ancestor) {
                ancestors[childNode].push_back(ancestor);
                findAncestorsDFS(ancestor, adjacencyList, childNode, ancestors);
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

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        // Initialize adjacency list for each node and ancestors list
        List<Integer>[] adjacencyList = new ArrayList[n];
        List<List<Integer>> ancestors = new ArrayList<>();

        // Initialize adjacency list and ancestors list for each node
        for (int i = 0; i < n; i++) {
            adjacencyList[i] = new ArrayList<>();
            ancestors.add(new ArrayList<>());
        }

        // Populate the adjacency list with edges
        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].add(to);
        }

        // Perform DFS for each node to find all its ancestors
        for (int i = 0; i < n; i++) {
            findAncestorsDFS(i, adjacencyList, i, ancestors);
        }

        return ancestors;
    }

    // Helper method to perform DFS and find ancestors
    private void findAncestorsDFS(
        int ancestor,
        List<Integer>[] adjacencyList,
        int currentNode,
        List<List<Integer>> ancestors
    ) {
        for (int childNode : adjacencyList[currentNode]) {
            // Check if the ancestor is already added to avoid duplicates
            if (
                ancestors.get(childNode).isEmpty() ||
                ancestors
                        .get(childNode)
                        .get(ancestors.get(childNode).size() - 1) !=
                    ancestor
            ) {
                ancestors.get(childNode).add(ancestor);
                findAncestorsDFS(ancestor, adjacencyList, childNode, ancestors);
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
    def getAncestors(self, n, edges):
        # Initialize adjacency list for each node and ancestors list
        adjacency_list = [[] for _ in range(n)]
        ancestors = [[] for _ in range(n)]

        # Populate the adjacency list with edges
        for from_node, to_node in edges:
            adjacency_list[from_node].append(to_node)

        # Perform DFS for each node to find all its ancestors
        for i in range(n):
            self.find_ancestors_DFS(i, adjacency_list, i, ancestors)

        return ancestors

    # Helper method to perform DFS and find ancestors
    def find_ancestors_DFS(
        self, ancestor, adjacency_list, current_node, ancestors
    ):
        for child_node in adjacency_list[current_node]:
            # Check if the ancestor is already added to avoid duplicates
            if (
                not ancestors[child_node]
                or ancestors[child_node][-1] != ancestor
            ):
                ancestors[child_node].append(ancestor)
                self.find_ancestors_DFS(
                    ancestor, adjacency_list, child_node, ancestors
                )
```

</details>

<br>

## Approach 3: Topological Sort (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Create adjacency list
        vector<vector<int>> adjacencyList(n);

        // Fill the adjacency list and indegree array based on the edges
        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
            indegree[to]++;
        }

        queue<int> nodesWithZeroIndegree;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                nodesWithZeroIndegree.push(i);
            }
        }

        // List to store the topological order of nodes
        vector<int> topologicalOrder;
        while (!nodesWithZeroIndegree.empty()) {
            int currentNode = nodesWithZeroIndegree.front();
            nodesWithZeroIndegree.pop();
            topologicalOrder.push_back(currentNode);

            // Reduce indegree of neighboring nodes and add them to the queue
            // if they have no more incoming edges
            for (int neighbor : adjacencyList[currentNode]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    nodesWithZeroIndegree.push(neighbor);
                }
            }
        }

        // Initialize the result list and set list for storing ancestors
        vector<vector<int>> ancestorsList(n);
        vector<unordered_set<int>> ancestorsSetList(n);

        // Fill the set list with ancestors using the topological order
        for (int node : topologicalOrder) {
            for (int neighbor : adjacencyList[node]) {
                // Add immediate parent, and other ancestors
                ancestorsSetList[neighbor].insert(node);
                ancestorsSetList[neighbor].insert(
                    ancestorsSetList[node].begin(),
                    ancestorsSetList[node].end());
            }
        }

        // Convert sets to lists and sort them
        for (int i = 0; i < ancestorsList.size(); i++) {
            for (int node = 0; node < n; node++) {
                if (node == i) continue;
                if (ancestorsSetList[i].find(node) !=
                    ancestorsSetList[i].end()) {
                    ancestorsList[i].push_back(node);
                }
            }
        }

        return ancestorsList;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        // Create adjacency list
        List<Integer>[] adjacencyList = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adjacencyList[i] = new ArrayList<>();
        }

        // Fill the adjacency list and indegree array based on the edges
        int[] indegree = new int[n];
        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].add(to);
            indegree[to]++;
        }

        // Queue for nodes with no incoming edges (starting points for topological sort)
        Queue<Integer> nodesWithZeroIndegree = new LinkedList<>();
        for (int i = 0; i < indegree.length; i++) {
            if (indegree[i] == 0) {
                nodesWithZeroIndegree.add(i);
            }
        }

        // List to store the topological order of nodes
        List<Integer> topologicalOrder = new ArrayList<>();
        while (!nodesWithZeroIndegree.isEmpty()) {
            int currentNode = nodesWithZeroIndegree.poll();
            topologicalOrder.add(currentNode);

            // Reduce indegree of neighboring nodes and add them to the queue
            // if they have no more incoming edges
            for (int neighbor : adjacencyList[currentNode]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    nodesWithZeroIndegree.add(neighbor);
                }
            }
        }

        // Initialize the result list and set list for storing ancestors
        List<List<Integer>> ancestorsList = new ArrayList<>();
        List<Set<Integer>> ancestorsSetList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ancestorsList.add(new ArrayList<>());
            ancestorsSetList.add(new HashSet<>());
        }

        // Fill the set list with ancestors using the topological order
        for (int node : topologicalOrder) {
            for (int neighbor : adjacencyList[node]) {
                // Add immediate parent, and other ancestors.
                ancestorsSetList.get(neighbor).add(node);
                ancestorsSetList
                    .get(neighbor)
                    .addAll(ancestorsSetList.get(node));
            }
        }

        // Convert sets to lists
        for (int i = 0; i < n; i++) {
            for (int node = 0; node < n; node++) {
                if (node == i) continue;
                if (ancestorsSetList.get(i).contains(node)) {
                    ancestorsList.get(i).add(node);
                }
            }
        }

        return ancestorsList;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getAncestors(self, n, edges):
        # Create adjacency list
        adjacency_list = [[] for _ in range(n)]

        # Fill the adjacency list and indegree array based on the edges
        indegree = [0 for _ in range(n)]
        for from_node, to_node in edges:
            adjacency_list[from_node].append(to_node)
            indegree[to_node] += 1

        # Queue for nodes with no incoming edges (starting points for topological sort)
        nodes_with_zero_indegree = [i for i in range(n) if indegree[i] == 0]

        # List to store the topological order of nodes
        topological_order = []
        while nodes_with_zero_indegree:
            current_node = nodes_with_zero_indegree.pop(0)
            topological_order.append(current_node)

            # Reduce indegree of neighboring nodes and add them to the queue
            # if they have no more incoming edges
            for neighbor in adjacency_list[current_node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    nodes_with_zero_indegree.append(neighbor)

        # Initialize the result list and set list for storing ancestors
        ancestors_list = [[] for _ in range(n)]
        ancestors_set_list = [set() for _ in range(n)]

        # Fill the set list with ancestors using the topological order
        for node in topological_order:
            for neighbor in adjacency_list[node]:
                # Add immediate parent, and other ancestors.
                ancestors_set_list[neighbor].add(node)
                ancestors_set_list[neighbor].update(ancestors_set_list[node])

        # Convert sets to lists and sort them
        for i in range(n):
            for node in range(n):
                if node == i:
                    continue
                if node in ancestors_set_list[i]:
                    ancestors_list[i].append(node)

        return ancestors_list
```

</details>
