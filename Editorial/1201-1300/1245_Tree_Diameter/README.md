# 1245. Tree Diameter

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/tree-diameter/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 1245 - Tree Diameter](https://leetcode.com/problems/tree-diameter/)

## Problem

The diameter of a tree is the number of edges in the longest path in that tree.

There is an undirected tree of n nodes labeled from 0 to n - 1. You are given a 2D array edges where edges.length == n - 1 and edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the tree.

Return the diameter of the tree.

### Example 1

```text
Input: edges = [[0,1],[0,2]]
Output: 2
Explanation: The longest path of the tree is the path 1 - 0 - 2.
```

### Example 2

```text
Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
Explanation: The longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
```

## Constraints

- n == edges.length + 1
- 1 <= n <= 104
- 0 <= ai, bi < n
- ai != bi

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Subtrees With Max Distance Between Cities](https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find Minimum Diameter After Merging Two Trees](https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1245. Tree Diameter

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Farthest Nodes via BFS | Java, Python3 |
| Centroids of Graph via BFS | Java, Python3 |
| DFS (Depth-First Search) | Java, Python3 |

## Approach 1: Farthest Nodes via BFS

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int treeDiameter(int[][] edges) {

        List<Set<Integer>> graph = new ArrayList<Set<Integer>>();
        for (int i = 0; i < edges.length + 1; ++i) {
            graph.add(new HashSet<Integer>());
        }

        for (int[] edge : edges) {
            Integer u = edge[0], v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        // 1). find one of the farthest nodes
        // farthest_node, distance_1 = bfs(0)
        int[] nodeDistance = bfs(0, graph);
        // 2). find the other farthest node
        // and the distance between two farthest nodes
        // another_farthest_node, distance_2 = bfs(farthest_node)
        nodeDistance = bfs(nodeDistance[0], graph);

        return nodeDistance[1];
    }

    /**
     * return the farthest node from the 'start' node and the distance between them.
     */
    private int[] bfs(int start, List<Set<Integer>> graph) {
        boolean[] visited = new boolean[graph.size()];
        visited[start] = true;

        LinkedList<Integer> queue = new LinkedList<Integer>();
        queue.addLast(start);
        Integer lastNode = start, distance = -1;

        while (queue.size() > 0) {
            LinkedList<Integer> nextQueue = new LinkedList<Integer>();

            while (queue.size() > 0) {
                int nextNode = queue.removeFirst();
                for (Integer neighbor : graph.get(nextNode)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nextQueue.addLast(neighbor);
                        lastNode = neighbor;
                    }
                }
            }
            // increase the distance for each level of BFS traversal.
            distance += 1;
            queue = nextQueue;
        }

        return new int[] {lastNode, distance};
    }

}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:

        # build the adjacency list representation of the graph
        graph = [set() for i in range(len(edges)+1)]
        for edge in edges:
            u, v = edge
            graph[u].add(v)
            graph[v].add(u)

        def bfs(start):
            """
             return the farthest node from the 'start' node
               and the distance between them.
            """
            visited = [False] * len(graph)

            visited[start] = True
            queue = deque([start])
            distance = -1
            last_node = start
            while queue:
                next_queue = deque()
                while queue:
                    next_node = queue.popleft()
                    for neighbor in graph[next_node]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            next_queue.append(neighbor)
                            last_node = neighbor
                distance += 1
                queue = next_queue

            return last_node, distance

        # 1). find one of the farthest nodes
        farthest_node, distance_1 = bfs(0)
        # 2). find the other farthest node
        #  and the distance between two farthest nodes
        another_farthest_node, distance_2 = bfs(farthest_node)

        return distance_2
```

</details>

<br>

## Approach 2: Centroids of Graph via BFS

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int treeDiameter(int[][] edges) {

        // build the adjacency list representation of the graph.
        List<Set<Integer>> graph = new ArrayList<Set<Integer>>();
        for (int i = 0; i < edges.length + 1; ++i) {
            graph.add(new HashSet<Integer>());
        }
        for (int[] edge : edges) {
            Integer u = edge[0], v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        // find the outer most nodes, i.e. leaf nodes
        LinkedList<Integer> leaves = new LinkedList<Integer>();
        for (int vertex = 0; vertex < graph.size(); ++vertex) {
            if (graph.get(vertex).size() == 1)
                leaves.add(vertex);
        }

        // "peel" the graph layer by layer,
        // until we have the centroids left.
        int layers = 0;
        int vertexLeft = edges.length + 1;
        while (vertexLeft > 2) {
            vertexLeft -= leaves.size();

            LinkedList<Integer> nextLeaves = new LinkedList<Integer>();

            for (int leaf : leaves) {
                // the only neighbor left on the leaf node.
                int neighbor = graph.get(leaf).iterator().next();
                graph.get(neighbor).remove(leaf);
                if (graph.get(neighbor).size() == 1)
                    nextLeaves.add(neighbor);
            }

            layers += 1;
            leaves = nextLeaves;
        }

        if (vertexLeft == 1)
            return layers * 2;
        else
            return layers * 2 + 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:

        # build the adjacency list representation of the graph.
        graph = [set() for i in range(len(edges)+1)]
        for edge in edges:
            u, v = edge
            graph[u].add(v)
            graph[v].add(u)

        # find the outer most nodes, _i.e._ leaf nodes
        leaves = []
        for vertex, links in enumerate(graph):
            if len(links) == 1:
                leaves.append(vertex)

        # "peel" the graph layer by layer,
        #   until we have the centroids left.
        layers = 0
        vertex_left = len(edges) + 1
        while vertex_left > 2:
            vertex_left -= len(leaves)
            next_leaves = []
            for leaf in leaves:
                # the only neighbor left on the leaf node.
                neighbor = graph[leaf].pop()
                graph[neighbor].remove(leaf)
                if len(graph[neighbor]) == 1:
                    next_leaves.append(neighbor)
            layers += 1
            leaves = next_leaves

        return layers * 2 + (0 if vertex_left == 1 else 1)
```

</details>

<br>

## Approach 3: DFS (Depth-First Search)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private List<List<Integer>> graph;
    private Integer diameter = 0;

    public int treeDiameter(int[][] edges) {

        // build the adjacency list representation of the graph.
        this.graph = new ArrayList<List<Integer>>();
        boolean[] visited = new boolean[edges.length + 1];
        for (int i = 0; i < edges.length + 1; ++i) {
            this.graph.add(new ArrayList<Integer>());
            visited[i] = false;
        }
        for (int[] edge : edges) {
            Integer u = edge[0], v = edge[1];
            this.graph.get(u).add(v);
            this.graph.get(v).add(u);
        }

        dfs(0, visited);

        return this.diameter;
    }

    /**
     * return the max distance
     *   starting from the 'curr' node to its the leaf nodes
     */
    private int dfs(int curr, boolean[] visited) {
        // the top 2 distance starting from this node
        Integer topDistance1 = 0, topDistance2 = 0;

        visited[curr] = true;
        for (Integer neighbor : graph.get(curr)) {
            int distance = 0;
            if (!visited[neighbor])
                distance = 1 + this.dfs(neighbor, visited);

            if (distance > topDistance1) {
                topDistance2 = topDistance1;
                topDistance1 = distance;
            } else if (distance > topDistance2) {
                topDistance2 = distance;
            }
        }

        // with the top 2 distance, we can update the current diameter
        this.diameter = Math.max(this.diameter, topDistance1 + topDistance2);

        return topDistance1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:

        # build the adjacency list representation of the graph.
        graph = [set() for i in range(len(edges)+1)]
        for edge in edges:
            u, v = edge
            graph[u].add(v)
            graph[v].add(u)

        diameter = 0

        def dfs(curr, visited):
            """
                return the max distance
                  starting from the 'curr' node to its leaf nodes
            """
            nonlocal diameter

            # the top 2 distance starting from this node
            top_1_distance, top_2_distance = 0, 0

            distance = 0
            visited[curr] = True

            for neighbor in graph[curr]:
                if not visited[neighbor]:
                    distance = 1 + dfs(neighbor, visited)

                if distance > top_1_distance:
                    top_1_distance, top_2_distance = distance, top_1_distance
                elif distance > top_2_distance:
                    top_2_distance = distance

            # with the top 2 distance, we can update the current diameter
            diameter = max(diameter, top_1_distance + top_2_distance)

            return top_1_distance

        visited = [False for i in range(len(graph))]
        dfs(0, visited)

        return diameter
```

</details>
