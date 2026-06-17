# 1971. Find if Path Exists in Graph

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-if-path-exists-in-graph/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 1971 - Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/)

## Problem

There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

### Example 1

```text
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 Ã¢â€ â€™ 1 Ã¢â€ â€™ 2
- 0 Ã¢â€ â€™ 2
```

### Example 2

```text
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
```

## Constraints

- 1 <= n <= 2 * 105
- 0 <= edges.length <= 2 * 105
- edges[i].length == 2
- 0 <= ui, vi <= n - 1
- ui != vi
- 0 <= source, destination <= n - 1
- There are no duplicate edges.
- There are no self edges.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Arrangement of Pairs](https://leetcode.com/problems/valid-arrangement-of-pairs/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Paths in Maze That Lead to Same Room](https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1971. Find if Path Exists in Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search (BFS) | C++, Java, Python3 |
| Depth First Search (DFS): Recursive | C++, Java, Python3 |
| Depth First Search (DFS): Iterative | C++, Java, Python3 |
| Disjoint Set Union (DSU) | C++, Java, Python3 |

## Approach 1: Breadth First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Store all edges in 'graph'.
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // Store all the nodes to be visited in 'bfsQueue'.
        // NOTE: 'queue' conflicts with the type name std::queue, 
        // so we use 'bfsQueue' instead.
        vector<bool> seen(n);
        seen[source] = true;
        queue<int> bfsQueue;
        bfsQueue.push(source);
        
        while (!bfsQueue.empty()) {
            int currNode = bfsQueue.front();
            bfsQueue.pop();
            if (currNode == destination) {
                return true;
            }

            // For all the neighbors of the current node, if we haven't visit it before,
            // add it to 'bfsQueue' and mark it as visited.
            for (auto& nextNode : graph[currNode]) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    bfsQueue.push(nextNode);
                }
            }
        }
        
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        //Store all edges in 'graph'.
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            graph.computeIfAbsent(a, val -> new ArrayList<Integer>()).add(b);
            graph.computeIfAbsent(b, val -> new ArrayList<Integer>()).add(a);
        }
        
        // Store all the nodes to be visited in 'queue'.
        boolean[] seen = new boolean[n];
        seen[source] = true;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(source);
        
        while (!queue.isEmpty()) {
            int currNode = queue.poll();
            if (currNode == destination) {
                return true; 
            }

            // For all the neighbors of the current node, if we haven't visit it before,            
            // add it to 'queue' and mark it as visited.
            for (int nextNode : graph.get(currNode)) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    queue.offer(nextNode);
                }
            }
        }
        
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        # Store all edges in 'graph'.
        graph = collections.defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        
        # Store all the nodes to be visited in 'queue'.
        seen = [False] * n
        seen[source] = True
        queue = collections.deque([source])
    
        while queue:
            curr_node = queue.popleft()
            if curr_node == destination:
                return True

            # For all the neighbors of the current node, if we haven't visit it before,
            # add it to 'queue' and mark it as visited.
            for next_node in graph[curr_node]:
                if not seen[next_node]:
                    seen[next_node] = True
                    queue.append(next_node)
        
        return False
```

</details>

<br>

## Approach 2: Depth First Search (DFS): Recursive

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, vector<bool>& seen, int currNode, int destination) {
        if (currNode == destination) {
            return true;
        }
        seen[currNode] = true;
        for (int nextNode : graph[currNode]) {
            if (!seen[nextNode]) {  // Only call dfs if not seen
                if (dfs(graph, seen, nextNode, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> seen(n, false);
        return dfs(graph, seen, source, destination);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        boolean[] seen = new boolean[n];

        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            graph.computeIfAbsent(a, val -> new ArrayList<>()).add(b);
            graph.computeIfAbsent(b, val -> new ArrayList<>()).add(a);
        }

        return dfs(graph, seen, source, destination);
    }
    
    private boolean dfs(Map<Integer, List<Integer>> graph, boolean[] seen, int currNode, int destination) {
        if (currNode == destination) {
            return true;
        }
        seen[currNode] = true;
        for (int nextNode : graph.get(currNode)) {
            if (!seen[nextNode]) {  // Only call dfs if not seen
                if (dfs(graph, seen, nextNode, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = collections.defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
            
        seen = [False] * n
        
        def dfs(curr_node):
            if curr_node == destination:
                return True
            seen[curr_node] = True
            for next_node in graph[curr_node]:
                # Only call dfs if not seen
                if not seen[next_node]:
                    if dfs(next_node):
                        return True
            return False

        return dfs(source)
```

</details>

<br>

## Approach 3: Depth First Search (DFS): Iterative

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Store all edges according to nodes in 'graph'.
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // Start from source node, add it to stack.
        // NOTE: 'stack' conflicts with the type name std::stack, 
        // so we use 'dfsStack' instead.
        vector<bool> seen(n);
        stack<int> dfsStack({source});
        seen[source] = true;
        
        while (!dfsStack.empty()) {
            int currNode = dfsStack.top();
            dfsStack.pop();
            
            if (currNode == destination) {
                return true;
            }
            
            // Add all unvisited neighbors of the current node to 'dfsStack' 
            // and mark them as visited.
            for (auto nextNode : graph[currNode]) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    dfsStack.push(nextNode);
                }
            }
        }
        
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        // Store all edges according to nodes in 'graph'.
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            graph.computeIfAbsent(a, val -> new ArrayList<Integer>()).add(b);
            graph.computeIfAbsent(b, val -> new ArrayList<Integer>()).add(a);
        }
        
        // Start from source node, add it to stack.
        boolean[] seen = new boolean[n];
        seen[source] = true;
        Stack<Integer> stack = new Stack<>();
        stack.push(source);
        
        while (!stack.isEmpty()) {
            int currNode = stack.pop();
            if (currNode == destination) {
                return true;
            }
            // Add all unvisited neighbors of the current node to stack'
            // and mark it as visited.
            for (int nextNode : graph.get(currNode)) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    stack.push(nextNode);
                }
            }
        }
        
        return false; 
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        # Store all edges according to nodes in 'graph'.
        graph = collections.defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        
        # Start from source node, add it to stack.
        seen = [False] * n
        seen[source] = True
        stack = [source]
        
        while stack:
            curr_node = stack.pop()
            # Add all unvisited neighbors of the current node to stack 
            # and mark them as visited.
            for next_node in graph[curr_node]:
                if next_node == destination:
                    return True
                if not seen[next_node]:
                    seen[next_node] = True
                    stack.append(next_node)
        
        return seen[destination]
```

</details>

<br>

## Approach 4: Disjoint Set Union (DSU)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n, 1) {
        iota(root.begin(), root.end(), 0);
    }
    int find(int x) {
        if (x != root[x]) {
            root[x] = find(root[x]);
        }
        return root[x];
    }   
    void join(int x, int y) {
        int rootX = find(x), rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                swap(rootX, rootY);
            }
            // Modify the root of the smaller group as the root of the
            // larger group, also increment the size of the larger group.
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);

        for (auto& edge : edges) {
            uf.join(edge[0], edge[1]);
        }
        
        return uf.find(source) == uf.find(destination);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class UnionFind {
    private int[] root;
    private int[] rank;
    public UnionFind(int n) {
        this.root = new int[n];
        this.rank = new int[n];
        for (int i = 0; i < n; ++i) {
            this.root[i] = i;
            this.rank[i] = 1;
        }
    }   
    public int find(int x) {
        if (this.root[x] != x) {
            this.root[x] = find(this.root[x]);
        }
        return this.root[x];
    }
    public void union(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (this.rank[rootX] > this.rank[rootY]) {
                int tmp = rootX;
                rootX = rootY;
                rootY = tmp;
            }
            // Modify the root of the smaller group as the root of the
            // larger group, also increment the size of the larger group.
            this.root[rootX] = rootY;
            this.rank[rootY] += this.rank[rootX];
        }
    }
}

class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        UnionFind uf = new UnionFind(n);

        for (int[] edge : edges) {
            uf.union(edge[0], edge[1]);
        }

        return uf.find(source) == uf.find(destination);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class UnionFind:
    def __init__(self, n):
        self.root = list(range(n))
        self.rank = [1] * n
    def find(self, x):
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]
    def union(self, x, y):
        root_x, root_y = self.find(x), self.find(y)
        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                root_x, root_y = root_y, root_x
            # Modify the root of the smaller group as the root of the
            # larger group, also increment the size of the larger group.
            self.rank[root_y] += self.rank[root_x]
            self.root[root_x] = root_y

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        uf = UnionFind(n)

        for a, b in edges:
            uf.union(a, b)

        return uf.find(source) == uf.find(destination)
```

</details>
