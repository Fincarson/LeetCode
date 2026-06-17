# 3203. Find Minimum Diameter After Merging Two Trees

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Graph Theory`

**Problem Link:** [LeetCode 3203 - Find Minimum Diameter After Merging Two Trees](https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/)

## Problem

There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

You must connect one node from the first tree with another node from the second tree with an edge.

Return the minimum possible diameter of the resulting tree.

The diameter of a tree is the length of the longest path between any two nodes in the tree.

### Example 1

### Example 2

## Constraints

- 1 <= n, m <= 105
- edges1.length == n - 1
- edges2.length == m - 1
- edges1[i].length == edges2[i].length == 2
- edges1[i] = [ai, bi]
- 0 <= ai, bi < n
- edges2[i] = [ui, vi]
- 0 <= ui, vi < m
- The input is generated such that edges1 and edges2 represent valid trees.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Tree Diameter](https://leetcode.com/problems/tree-diameter/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximize the Number of Target Nodes After Connecting Trees I](https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximize the Number of Target Nodes After Connecting Trees II](https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximize Sum of Weights after Edge Removals](https://leetcode.com/problems/maximize-sum-of-weights-after-edge-removals/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3203. Find Minimum Diameter After Merging Two Trees

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Farthest of Farthest (BFS) | C++, Java, Python3 |
| Depth First Search | C++, Java, Python3 |
| Topological Sorting | C++, Java, Python3 |

## Approach 1: Farthest of Farthest (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameters of both trees
        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        // Calculate the longest path that spans across both trees
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        // Return the maximum of the three possibilities
        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }

    // Function to find the diameter of a tree using two BFS calls
    int findDiameter(int n, vector<vector<int>>& adjList) {
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        auto [farthestNode, _] = findFarthestNode(n, adjList, 0);

        // Second BFS from the farthest node to determine the diameter
        auto [_, diameter] = findFarthestNode(n, adjList, farthestNode);
        return diameter;
    }

    // BFS helper function to find the farthest node and its distance from the
    // source
    pair<int, int> findFarthestNode(int n, vector<vector<int>>& adjList,
                                    int sourceNode) {
        queue<int> nodesQueue;
        vector<bool> visited(n, false);
        // Push source node into the queue
        nodesQueue.push(sourceNode);
        visited[sourceNode] = true;

        int maximumDistance = 0, farthestNode = sourceNode;

        // Explore neighbors
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                // Update farthest node
                // The farthest node is the last one that was popped out of the
                // queue.
                farthestNode = currentNode;

                for (int neighbor : adjList[currentNode]) {
                    // Explore neighbors
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nodesQueue.push(neighbor);
                    }
                }
            }
            if (!nodesQueue.empty()) maximumDistance++;
        }
        return {farthestNode, maximumDistance};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        // Calculate the number of nodes for each tree
        int n = edges1.length + 1;
        int m = edges2.length + 1;

        // Build adjacency lists for both trees
        List<List<Integer>> adjList1 = buildAdjList(n, edges1);
        List<List<Integer>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameters of both trees
        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        // Calculate the longest path that spans across both trees
        int combinedDiameter =
            (int) Math.ceil(diameter1 / 2.0) +
            (int) Math.ceil(diameter2 / 2.0) +
            1;

        // Return the maximum of the three possibilities
        return Math.max(Math.max(diameter1, diameter2), combinedDiameter);
    }

    private List<List<Integer>> buildAdjList(int size, int[][] edges) {
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }
        return adjList;
    }

    private int findDiameter(int n, List<List<Integer>> adjList) {
        // First BFS to find the farthest node from an arbitrary node (e.g., 0)
        Pair firstBFS = findFarthestNode(n, adjList, 0);
        int farthestNode = firstBFS.getFirst();

        // Second BFS to find the diameter starting from the farthest node
        Pair secondBFS = findFarthestNode(n, adjList, farthestNode);
        return secondBFS.getSecond();
    }

    private Pair findFarthestNode(
        int n,
        List<List<Integer>> adjList,
        int sourceNode
    ) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];
        // Push source node into the queue
        queue.add(sourceNode);
        visited[sourceNode] = true;

        int maximumDistance = 0, farthestNode = sourceNode;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int currentNode = queue.poll();
                // Update farthest node
                // The farthest node is the last one that was popped out of the
                // queue.
                farthestNode = currentNode;

                // Explore neighbors
                for (int neighbor : adjList.get(currentNode)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        queue.add(neighbor);
                    }
                }
            }
            if (!queue.isEmpty()) maximumDistance++;
        }
        return new Pair(farthestNode, maximumDistance);
    }

    // Simple Pair class for storing results of findFarthestNode function
    class Pair {

        private int first;
        private int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int getFirst() {
            return first;
        }

        public int getSecond() {
            return second;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDiameterAfterMerge(self, edges1, edges2):
        # Calculate the number of nodes for each tree
        n = len(edges1) + 1
        m = len(edges2) + 1

        # Build adjacency lists for both trees
        adj_list1 = self.build_adj_list(n, edges1)
        adj_list2 = self.build_adj_list(m, edges2)

        # Calculate the diameters of both trees
        diameter1 = self.find_diameter(n, adj_list1)
        diameter2 = self.find_diameter(m, adj_list2)

        # Calculate the longest path that spans across both trees
        combined_diameter = ceil(diameter1 / 2) + ceil(diameter2 / 2) + 1

        # Return the maximum of the three possibilities
        return max(diameter1, diameter2, combined_diameter)

    def build_adj_list(self, size, edges):
        adj_list = [[] for _ in range(size)]
        for edge in edges:
            adj_list[edge[0]].append(edge[1])
            adj_list[edge[1]].append(edge[0])
        return adj_list

    def find_diameter(self, n, adj_list):
        # First BFS to find the farthest node from an arbitrary node (e.g., 0)
        farthest_node, _ = self.find_farthest_node(n, adj_list, 0)

        # Second BFS to find the diameter starting from the farthest node
        _, diameter = self.find_farthest_node(n, adj_list, farthest_node)
        return diameter

    def find_farthest_node(self, n, adj_list, source_node):
        queue = deque([source_node])
        visited = [False] * n
        visited[source_node] = True

        maximum_distance = 0
        farthest_node = source_node

        while queue:
            for _ in range(len(queue)):
                current_node = queue.popleft()
                farthest_node = current_node

                for neighbor in adj_list[current_node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        queue.append(neighbor)

            if queue:
                maximum_distance += 1

        return farthest_node, maximum_distance
```

</details>

<br>

## Approach 2: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree (number of edges + 1)
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        int diameter1 =
            findDiameter(adjList1, 0, -1).first;  // Start DFS for Tree 1
        int diameter2 =
            findDiameter(adjList2, 0, -1).first;  // Start DFS for Tree 2

        // Calculate the diameter of the combined tree
        // This accounts for the longest path spanning both trees
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        // Return the maximum diameter among the two trees and the combined tree
        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    // Helper function to build an adjacency list from an edge list
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    };

    // Helper function to find the diameter of a tree
    // Returns the diameter and the depth of the node's subtree
    pair<int, int> findDiameter(vector<vector<int>>& adjList, int node,
                                int parent) {
        int maxDepth1 = 0,
            maxDepth2 =
                0;  // Tracks the two largest depths from the current node
        int diameter = 0;  // Tracks the diameter of the subtree

        for (int neighbor :
             adjList[node]) {  // Iterate through neighbors of the current node
            if (neighbor == parent)
                continue;  // Skip the parent to avoid cycles

            // Recursively calculate the diameter and depth of the neighbor's
            // subtree
            auto [childDiameter, depth] = findDiameter(adjList, neighbor, node);

            // Update the maximum diameter of the subtree
            diameter = max(diameter, childDiameter);

            depth++;  // Increment the depth to include the edge to this
                      // neighbor
            // Update the two largest depths from the current node
            if (depth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth > maxDepth2) {
                maxDepth2 = depth;
            }
        }

        // Update the diameter to include the path through the current node
        diameter = max(diameter, maxDepth1 + maxDepth2);

        return {diameter, maxDepth1};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        // Calculate the number of nodes for each tree (number of edges + 1)
        int n = edges1.length + 1;
        int m = edges2.length + 1;

        // Build adjacency lists for both trees
        List<List<Integer>> adjList1 = buildAdjList(n, edges1);
        List<List<Integer>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameter of both trees
        int diameter1 = findDiameter(adjList1, 0, -1).getFirst(); // Start DFS for Tree 1
        int diameter2 = findDiameter(adjList2, 0, -1).getFirst(); // Start DFS for Tree 2

        // Calculate the diameter of the combined tree
        int combinedDiameter =
            (int) Math.ceil(diameter1 / 2.0) +
            (int) Math.ceil(diameter2 / 2.0) +
            1;

        // Return the maximum diameter among the two trees and the combined tree
        return Math.max(Math.max(diameter1, diameter2), combinedDiameter);
    }

    // Helper function to build an adjacency list from an edge list
    private List<List<Integer>> buildAdjList(int size, int[][] edges) {
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }
        return adjList;
    }

    // Helper function to find the diameter of a tree
    // Returns the diameter and the depth of the node's subtree
    private Pair findDiameter(
        List<List<Integer>> adjList,
        int node,
        int parent
    ) {
        int maxDepth1 = 0, maxDepth2 = 0; // Tracks the two largest depths from the current node
        int diameter = 0; // Tracks the diameter of the subtree

        for (int neighbor : adjList.get(node)) {
            if (neighbor == parent) continue; // Skip the parent to avoid cycles

            // Recursively calculate the diameter and depth of the neighbor's subtree
            Pair result = findDiameter(adjList, neighbor, node);
            int childDiameter = result.getFirst();
            int depth = result.getSecond() + 1; // Increment depth to include edge to neighbor

            // Update the maximum diameter of the subtree
            diameter = Math.max(diameter, childDiameter);

            // Update the two largest depths from the current node
            if (depth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth > maxDepth2) {
                maxDepth2 = depth;
            }
        }

        // Update the diameter to include the path through the current node
        diameter = Math.max(diameter, maxDepth1 + maxDepth2);

        // Return the diameter and the longest depth
        return new Pair(diameter, maxDepth1);
    }

    // Simple Pair class for storing results of the findDiameter function
    class Pair {

        private int first;
        private int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int getFirst() {
            return first;
        }

        public int getSecond() {
            return second;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDiameterAfterMerge(
        self, edges1: list[list[int]], edges2: list[list[int]]
    ) -> int:
        # Calculate the number of nodes for each tree (number of edges + 1)
        n = len(edges1) + 1
        m = len(edges2) + 1

        # Build adjacency lists for both trees
        adj_list1 = self.build_adj_list(n, edges1)
        adj_list2 = self.build_adj_list(m, edges2)

        # Calculate the diameter of both trees
        diameter1, _ = self.find_diameter(
            adj_list1, 0, -1
        )  # Start DFS for Tree 1
        diameter2, _ = self.find_diameter(
            adj_list2, 0, -1
        )  # Start DFS for Tree 2

        # Calculate the diameter of the combined tree
        # This accounts for the longest path spanning both trees
        combined_diameter = ceil(diameter1 / 2) + ceil(diameter2 / 2) + 1

        # Return the maximum diameter among the two trees and the combined tree
        return max(diameter1, diameter2, combined_diameter)

    # Helper function to build an adjacency list from an edge list
    def build_adj_list(
        self, size: int, edges: list[list[int]]
    ) -> list[list[int]]:
        adj_list = [[] for _ in range(size)]
        for edge in edges:
            adj_list[edge[0]].append(edge[1])
            adj_list[edge[1]].append(edge[0])
        return adj_list

    # Helper function to find the diameter of a tree
    # Returns the diameter and the depth of the node's subtree
    def find_diameter(
        self, adj_list: list[list[int]], node: int, parent: int
    ) -> tuple[int, int]:
        max_depth1 = max_depth2 = (
            0  # Tracks the two largest depths from the current node
        )
        diameter = 0  # Tracks the maximum diameter of the subtree

        for neighbor in adj_list[node]:
            if neighbor == parent:
                continue  # Skip the parent to avoid cycles

            # Recursively calculate the diameter and depth of the neighbor's subtree
            child_diameter, depth = self.find_diameter(adj_list, neighbor, node)
            depth += 1  # Increment depth to include edge to neighbor

            # Update the maximum diameter of the subtree
            diameter = max(diameter, child_diameter)

            # Update the two largest depths from the current node
            if depth > max_depth1:
                max_depth2 = max_depth1
                max_depth1 = depth
            elif depth > max_depth2:
                max_depth2 = depth

        # Update the diameter to include the path through the current node
        diameter = max(diameter, max_depth1 + max_depth2)

        # Return the diameter and the longest depth
        return diameter, max_depth1
```

</details>

<br>

## Approach 3: Topological Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree (number of edges + 1)
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameter of both trees
        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        // Output the diameters for debugging (can be removed in production
        // code)
        cout << diameter1 << " " << diameter2 << "\n";

        // Calculate the longest path that spans across both trees.
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    // Helper function to build an adjacency list from an edge list
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    };

    // Function to find the diameter of a tree using topological sorting
    int findDiameter(int n, vector<vector<int>>& adjList) {
        queue<int> leavesQueue;
        vector<int> degrees(n);
        // Initialize the degree of each node and add leaves (nodes with degree
        // 1) to the queue
        for (int node = 0; node < n; node++) {
            degrees[node] =
                adjList[node].size();  // Degree is the number of neighbors
            if (degrees[node] == 1) {
                leavesQueue.push(node);
            }
        }

        int remainingNodes = n;
        int leavesLayersRemoved = 0;

        // Process the leaves until there are 2 or fewer nodes remaining
        while (remainingNodes > 2) {
            int size = leavesQueue.size();  // Get the number of leaves to
                                            // remove in this iteration
            remainingNodes -= size;
            leavesLayersRemoved++;

            // Remove the leaves from the queue and update the degrees of their
            // neighbors
            for (int i = 0; i < size; i++) {
                int currentNode = leavesQueue.front();
                leavesQueue.pop();

                // Process the neighbors of the current leaf
                for (int neighbor : adjList[currentNode]) {
                    degrees[neighbor]--;  // Decrease the degree of the neighbor
                    if (degrees[neighbor] == 1) {
                        leavesQueue.push(
                            neighbor);  // If the neighbor becomes a leaf, add
                                        // it to the queue
                    }
                }
            }
        }

        // If exactly two nodes remain, return the diameter as twice the number
        // of layers of leaves removed + 1 (as the diameter will include the
        // final connecting edge)
        if (remainingNodes == 2) return 2 * leavesLayersRemoved + 1;

        return 2 * leavesLayersRemoved;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        // Calculate the number of nodes for each tree (number of edges + 1)
        int n = edges1.length + 1;
        int m = edges2.length + 1;

        // Build adjacency lists for both trees
        List<List<Integer>> adjList1 = buildAdjList(n, edges1);
        List<List<Integer>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameter of both trees
        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        // Calculate the longest path that spans across both trees
        int combinedDiameter =
            (int) Math.ceil(diameter1 / 2.0) +
            (int) Math.ceil(diameter2 / 2.0) +
            1;

        // Return the maximum of the three possibilities
        return Math.max(Math.max(diameter1, diameter2), combinedDiameter);
    }

    // Function to build an adjacency list from an edge list
    private List<List<Integer>> buildAdjList(int size, int[][] edges) {
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }
        return adjList;
    }

    // Function to find the diameter of a tree
    private int findDiameter(int n, List<List<Integer>> adjList) {
        Queue<Integer> leavesQueue = new LinkedList<>();
        int[] degrees = new int[n];

        // Initialize the degree of each node and add leaves (nodes with degree 1) to the queue
        for (int node = 0; node < n; node++) {
            degrees[node] = adjList.get(node).size();
            if (degrees[node] == 1) {
                leavesQueue.offer(node);
            }
        }

        int remainingNodes = n;
        int leavesLayersRemoved = 0;

        // Process the leaves until there are 2 or fewer nodes remaining
        while (remainingNodes > 2) {
            int size = leavesQueue.size();
            remainingNodes -= size;
            leavesLayersRemoved++;

            // Remove the leaves from the queue and update the degrees of their neighbors
            for (int i = 0; i < size; i++) {
                int currentNode = leavesQueue.poll();

                // Process the neighbors of the current leaf
                for (int neighbor : adjList.get(currentNode)) {
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1) {
                        leavesQueue.offer(neighbor);
                    }
                }
            }
        }

        // If exactly two nodes remain, return the diameter as twice the number of layers of leaves removed + 1
        if (remainingNodes == 2) return 2 * leavesLayersRemoved + 1;

        return 2 * leavesLayersRemoved;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDiameterAfterMerge(self, edges1, edges2):
        # Calculate the number of nodes for each tree (number of edges + 1)
        n = len(edges1) + 1
        m = len(edges2) + 1

        # Build adjacency lists for both trees
        adj_list1 = self.build_adj_list(n, edges1)
        adj_list2 = self.build_adj_list(m, edges2)

        # Calculate the diameter of both trees
        diameter1 = self.find_diameter(n, adj_list1)
        diameter2 = self.find_diameter(m, adj_list2)

        # Calculate the longest path that spans across both trees
        combined_diameter = ceil(diameter1 / 2) + ceil(diameter2 / 2) + 1

        # Return the maximum of the three possibilities
        return max(diameter1, diameter2, combined_diameter)

    # Function to build an adjacency list from an edge list
    def build_adj_list(self, size, edges):
        adj_list = [[] for _ in range(size)]
        for edge in edges:
            adj_list[edge[0]].append(edge[1])
            adj_list[edge[1]].append(edge[0])
        return adj_list

    # Function to find the diameter of a tree
    def find_diameter(self, n, adj_list):
        leaves_queue = deque()
        degrees = [0] * n

        # Initialize the degree of each node and add leaves (nodes with degree 1) to the queue
        for node in range(n):
            degrees[node] = len(adj_list[node])
            if degrees[node] == 1:
                leaves_queue.append(node)

        remaining_nodes = n
        leaves_layers_removed = 0

        # Process the leaves until there are 2 or fewer nodes remaining
        while remaining_nodes > 2:
            size = len(leaves_queue)
            remaining_nodes -= size
            leaves_layers_removed += 1

            # Remove the leaves from the queue and update the degrees of their neighbors
            for _ in range(size):
                current_node = leaves_queue.popleft()

                # Process the neighbors of the current leaf
                for neighbor in adj_list[current_node]:
                    degrees[neighbor] -= 1
                    if degrees[neighbor] == 1:
                        leaves_queue.append(neighbor)

        # If exactly two nodes remain, return the diameter as twice the number of layers of leaves removed + 1
        if remaining_nodes == 2:
            return 2 * leaves_layers_removed + 1

        return 2 * leaves_layers_removed
```

</details>
