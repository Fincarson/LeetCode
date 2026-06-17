# 2642. Design Graph With Shortest Path Calculator

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/design-graph-with-shortest-path-calculator/)  
`Graph Theory` `Design` `Heap (Priority Queue)` `Shortest Path`

**Problem Link:** [LeetCode 2642 - Design Graph With Shortest Path Calculator](https://leetcode.com/problems/design-graph-with-shortest-path-calculator/)

## Problem

There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

Implement the Graph class:

- Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
- addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
- int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.

### Example 1

```text
Input
["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
Output
[null, 6, -1, null, 6]

Explanation
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the second diagram above.
g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.
```

## Constraints

- 1 <= n <= 100
- 0 <= edges.length <= n * (n - 1)
- edges[i].length == edge.length == 3
- 0 <= fromi, toi, from, to, node1, node2 <= n - 1
- 1 <= edgeCosti, edgeCost <= 106
- There are no repeated edges and no self-loops in the graph at any point.
- At most 100 calls will be made for addEdge.
- At most 100 calls will be made for shortestPath.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Restricted Paths From First to Last Node](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Closest Node to Path in Tree](https://leetcode.com/problems/closest-node-to-path-in-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2642. Design Graph With Shortest Path Calculator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dijkstra's Algorithm | C++, Java, Python3 |
| FloydÃ¢â‚¬â€œWarshall algorithm | C++, Java, Python3 |

## Approach 1: Dijkstra's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Graph {
public:
    vector<vector<pair<int, int>>> adjList;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for (auto& e: edges)
            adjList[e[0]].push_back(make_pair(e[1], e[2]));
    }

    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }

    int shortestPath(int node1, int node2) {
        int n = adjList.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> costForNode(n, INT_MAX);
        costForNode[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty()) {
            int currCost = pq.top()[0];
            int currNode = pq.top()[1];
            pq.pop();

            if (currCost > costForNode[currNode]) {
                continue;
            }
            if (currNode == node2) {
                return currCost;
            }
            for (auto& neighbor : adjList[currNode]) {
                int neighborNode = neighbor.first;
                int cost = neighbor.second;
                int newCost = currCost + cost;

                if (newCost < costForNode[neighborNode]) {
                    costForNode[neighborNode] = newCost;
                    pq.push({newCost, neighborNode});
                }
            }
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Graph {
    List<List<Pair<Integer, Integer>>> adjList;
    public Graph(int n, int[][] edges) {
        adjList = new ArrayList<>();
        for (int i = 0; i < n; i++)
            adjList.add(new ArrayList<>());
        for (int[] e : edges)
            adjList.get(e[0]).add(new Pair<>(e[1], e[2]));
    }

    public void addEdge(int[] edge) {
        adjList.get(edge[0]).add(new Pair<>(edge[1], edge[2]));
    }

    public int shortestPath(int node1, int node2) {
        int n = adjList.size();
        var pq = new PriorityQueue<List<Integer>>(Comparator.comparingInt(list -> list.get(0)));
        int[] costForNode = new int[n];
        Arrays.fill(costForNode, Integer.MAX_VALUE);
        costForNode[node1] = 0;
        pq.offer(Arrays.asList(0, node1));

        while (!pq.isEmpty()) {
            var curr = pq.poll();
            int currCost = curr.get(0);
            int currNode = curr.get(1);

            if (currCost > costForNode[currNode]) {
                continue;
            }
            if (currNode == node2) {
                return currCost;
            }
            for (var neighbor : adjList.get(currNode)) {
                int neighborNode = neighbor.getKey();
                int cost = neighbor.getValue();
                int newCost = currCost + cost;

                if (newCost < costForNode[neighborNode]) {
                    costForNode[neighborNode] = newCost;
                    pq.offer(Arrays.asList(newCost, neighborNode));
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.adj_list = [[] for _ in range(n)]
        for from_node, to_node, cost in edges:
            self.adj_list[from_node].append((to_node, cost))

    def addEdge(self, edge: List[int]) -> None:
        from_node, to_node, cost = edge
        self.adj_list[from_node].append((to_node, cost))

    def shortestPath(self, node1: int, node2: int) -> int:
        n = len(self.adj_list)
        pq = [(0, node1)]
        cost_for_node = [inf] * (n)
        cost_for_node[node1] = 0

        while pq:
            curr_cost, curr_node = heappop(pq)
            if curr_cost > cost_for_node[curr_node]:
                continue
            if curr_node == node2:
                return curr_cost
            for neighbor, cost in self.adj_list[curr_node]:
                new_cost = curr_cost + cost
                if new_cost < cost_for_node[neighbor]:
                    cost_for_node[neighbor] = new_cost
                    heappush(pq, (new_cost, neighbor))
        return -1
```

</details>

<br>

## Approach 2: FloydÃ¢â‚¬â€œWarshall algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Graph {
public:
    vector<vector<int>> adjMatrix;
    Graph(int n, vector<vector<int>>& edges) {
        adjMatrix = vector<vector<int>>(n, vector<int>(n, 1e9));
        for (auto &e : edges)
            adjMatrix[e[0]][e[1]] = e[2];
        for (int i = 0; i < n; ++i)
            adjMatrix[i][i] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    adjMatrix[j][k] = min(adjMatrix[j][k],
                                           adjMatrix[j][i] + adjMatrix[i][k]);
    }
    
    void addEdge(vector<int> edge) {
        int n = adjMatrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMatrix[i][j] = min(adjMatrix[i][j], 
                                       adjMatrix[i][edge[0]] +
                                       adjMatrix[edge[1]][j] +
                                       edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        if (adjMatrix[node1][node2] == 1e9) 
            return -1;
        return adjMatrix[node1][node2];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Graph {
    private int[][] adjMatrix;

    public Graph(int n, int[][] edges) {
        adjMatrix = new int[n][n];
        Arrays.stream(adjMatrix).forEach(row -> Arrays.fill(row, (int)1e9));
        for (int[] e : edges) {
            adjMatrix[e[0]][e[1]] = e[2];
        }
        for (int i = 0; i < n; i++) {
            adjMatrix[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    adjMatrix[j][k] = Math.min(adjMatrix[j][k], 
                                               adjMatrix[j][i] +
                                               adjMatrix[i][k]);
                }
            }
        }
    }

    public void addEdge(int[] edge) {
        int n = adjMatrix.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = Math.min(adjMatrix[i][j],
                                           adjMatrix[i][edge[0]] +
                                           adjMatrix[edge[1]][j] +
                                           edge[2]);
            }
        }
    }

    public int shortestPath(int node1, int node2) {
        if (adjMatrix[node1][node2] == (int)1e9)
            return -1;
        return adjMatrix[node1][node2];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Graph:

    def __init__(self, n, edges):
        self.adj_matrix = [[inf] * n for _ in range(n)]
        for from_node, to_node, cost in edges:
            self.adj_matrix[from_node][to_node] = cost
        for i in range(n):
            self.adj_matrix[i][i] = 0
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    self.adj_matrix[j][k] = min(self.adj_matrix[j][k],
                                                self.adj_matrix[j][i] + 
                                                self.adj_matrix[i][k])

    def addEdge(self, edge: List[int]) -> None:
        from_node, to_node, cost = edge
        n = len(self.adj_matrix)
        for i in range(n):
            for j in range(n):
                self.adj_matrix[i][j] = min(self.adj_matrix[i][j],
                                            self.adj_matrix[i][from_node] + 
                                            self.adj_matrix[to_node][j] +
                                            cost)

    def shortestPath(self, node1, node2):
        if self.adj_matrix[node1][node2] == inf: return -1
        return self.adj_matrix[node1][node2]
```

</details>
