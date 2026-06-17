# 2368. Reachable Nodes With Restrictions

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/reachable-nodes-with-restrictions/)  
`Array` `Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 2368 - Reachable Nodes With Restrictions](https://leetcode.com/problems/reachable-nodes-with-restrictions/)

## Problem

There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.

Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

Note that node 0 will not be a restricted node.

### Example 1

```text
Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
Output: 4
Explanation: The diagram above shows the tree.
We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.
```

### Example 2

```text
Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
Output: 3
Explanation: The diagram above shows the tree.
We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.
```

## Constraints

- 2 <= n <= 105
- edges.length == n - 1
- edges[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- edges represents a valid tree.
- 1 <= restricted.length < n
- 1 <= restricted[i] < n
- All the values of restricted are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Open the Lock](https://leetcode.com/problems/open-the-lock/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Jumps to Reach Home](https://leetcode.com/problems/minimum-jumps-to-reach-home/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2368. Reachable Nodes With Restrictions

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search (BFS) | C++, Java, Python3 |
| Depth First Search (DFS): Recursive | C++, Java, Python3 |
| Depth First Search (DFS): Iterative | C++, Java, Python |
| Disjoint Set Union (DSU) | C++, Java, Python |

## Approach 1: Breadth First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // Store all edges in 'neighbors'.
        vector<vector<int>> neighbors(n);
        for (auto& edge : edges) {
            int nodeA = edge[0], nodeB = edge[1];
            neighbors[nodeA].push_back(nodeB);
            neighbors[nodeB].push_back(nodeA);
        }
        
        // Mark the nodes in 'restricted' as visited.
        vector<bool> seen(n);
        for (int node : restricted) {
            seen[node] = true;
        }
        
        // Store all the nodes to be visited in 'bfsQueue'.
        // NOTE: 'queue' conflicts with the type name std::queue, 
        // so we use 'bfsQueue' instead.
        int ans = 0;
        queue<int> bfsQueue({0});

        seen[0] = true;

        while (!bfsQueue.empty()) {
            int currNode = bfsQueue.front();
            bfsQueue.pop();
            ans++;
            
            // For all the neighbors of the current node, if we haven't visit it before,
            // add it to 'bfsQueue' and mark it as visited.
            for (auto nextNode : neighbors[currNode]) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    bfsQueue.push(nextNode);
                }
            }
        }
        
        return ans;    
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        //Store all edges in 'neighbors'.
        Map<Integer, List<Integer>> neighbors = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            neighbors.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            neighbors.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }
        
        // Mark the nodes in 'restricted' as visited.
        Set<Integer> seen = new HashSet<>();
        for (int node : restricted) {
            seen.add(node);
        }
        
        // Store all the nodes to be visited in 'queue'.
        int ans = 0;
        seen.add(0);
        Queue<Integer> queue = new LinkedList<>(Arrays.asList(0));

        while (!queue.isEmpty()) {
            int currNode = queue.poll();
            ans++;
            
            // For all the neighbors of the current node, if we haven't visit it before,            
            // add it to 'queue' and mark it as visited.
            for (int nextNode : neighbors.get(currNode)) {
                if (!seen.contains(nextNode)) {
                    seen.add(nextNode);
                    queue.offer(nextNode);
                }
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        # Store all edges in 'neighbors'.
        neighbors = collections.defaultdict(list)
        for node_a, node_b in edges:
            neighbors[node_a].append(node_b)
            neighbors[node_b].append(node_a)
        
        # Mark the nodes in 'restricted' as visited.
        seen = [False] * n
        for node in restricted:
            seen[node] = True
        
        # Store all the nodes to be visited in 'queue'.
        ans = 0
        queue = collections.deque([0])
        seen[0] = True
        
        while queue:
            curr_node = queue.popleft()
            ans += 1
            
            # For all the neighbors of the current node, if we haven't visit it before,
            # add it to 'queue' and mark it as visited.
            for next_node in neighbors[curr_node]:
                if not seen[next_node]:
                    seen[next_node] = True
                    queue.append(next_node)
        
        return ans
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
    void dfs(int currNode, int& ans, vector<vector<int>>& neighbors, vector<bool>& seen) {
        // Mark 'currNode' as visited and increment 'ans' by 1.
        ans++;
        seen[currNode] = true;
        
        // Go for unvisited neighbors of 'currNode'.
        for (auto nextNode : neighbors[currNode]) {
            if (!seen[nextNode]) {
                dfs(nextNode, ans, neighbors, seen);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        //Store all edges according to nodes in 'neighbors'.
        vector<vector<int>> neighbors(n);
        for (auto edge : edges) {
            int nodeA = edge[0], nodeB = edge[1];
            neighbors[nodeA].push_back(nodeB);
            neighbors[nodeB].push_back(nodeA);
        }
        
        // Mark the nodes in 'restricted' as visited.
        vector<bool> seen(n, false);
        for (auto node : restricted) {
             seen[node] = true;
        }
        
        int ans = 0;
        dfs(0, ans, neighbors, seen);
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int ans = 0;
    private void dfs(int currNode, Map<Integer, List<Integer>> neighbors, Set<Integer> seen) {
        // Mark 'currNode' as visited and increment 'ans' by 1.
        ans++;
        seen.add(currNode);
        
        // Go for unvisited neighbors of 'currNode'.
        for (int nextNode : neighbors.get(currNode)) {
            if (!seen.contains(nextNode)) {
                dfs(nextNode, neighbors, seen);
            }
        }    
    }
    
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        //Store all edges according to nodes in 'neighbors'.
        Map<Integer, List<Integer>> neighbors = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            neighbors.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            neighbors.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }
        
        // Mark the nodes in 'restricted' as visited.
        Set<Integer> seen = new HashSet<>();
        for (int node : restricted) {
            seen.add(node);
        }
        
        dfs(0, neighbors, seen);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        # Store all edges according to nodes in 'neighbors'.
        neighbors = collections.defaultdict(list)
        for node_a, node_b in edges:
            neighbors[node_a].append(node_b)
            neighbors[node_b].append(node_a)
        
        # Mark the nodes in 'restricted' as visited.
        seen = [False] * n
        for node in restricted:
            seen[node] = True
        
        def dfs(curr_node):
            # Mark 'curr_node' as visited and increment 'ans' by 1.
            self.ans += 1
            seen[curr_node] = True
            
            # Go for unvisited neighbors of 'currNode'.
            for next_node in neighbors[curr_node]:
                if not seen[next_node]:
                    dfs(next_node)
                    
        self.ans = 0
        dfs(0)
        return self.ans
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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // Store all edges according to nodes in 'neighbors'.
        vector<vector<int>> neighbors(n);
        for (auto edge : edges) {
            int nodeA = edge[0], nodeB = edge[1];
            neighbors[nodeA].push_back(nodeB);
            neighbors[nodeB].push_back(nodeA);
        }
        
        // Mark the nodes in 'restricted' as visited.
        vector<bool> seen(n, false);
        for (auto node : restricted) {
            seen[node] = true;
        }
        
        // Use a stack 'stack' to store all the nodes to be visited, start from node 0.
        int ans = 0;
        stack<int> stack({0});

        seen[0] = true;

        while (!stack.empty()) {
            int currNode = stack.top();
            stack.pop();
            ans++;
            
            // Add all unvisited neighbors of the current node to 'stack' 
            // and mark them as visited.
            for (auto nextNode : neighbors[currNode]) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    stack.push(nextNode);
                }
            }
        }
        
        return ans;    
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        //Store all edges according to nodes in 'neighbors'.
        Map<Integer, List<Integer>> neighbors = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            neighbors.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            neighbors.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }
        
        // Mark the nodes in 'restricted' as visited.
        Set<Integer> seen = new HashSet<>();
        for (int node : restricted) {
            seen.add(node);
        }
        
        // Use stack 'stack' to store all nodes to be visited, start from node 0.
        int ans = 0;
        seen.add(0);
        Stack<Integer> stack = new Stack<>();
        stack.add(0);
        
        while (!stack.isEmpty()) {
            int currNode = stack.pop();
            ans++;
            
            // Add all unvisited neighbors of the current node to 'stack' 
            // and mark it as visited.
            for (int nextNode : neighbors.get(currNode)) {
                if (!seen.contains(nextNode)) {
                    seen.add(nextNode);
                    stack.add(nextNode);
                }
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        # Store all edges according to nodes in 'neighbor'.
        neighbors = collections.defaultdict(set)
        for a, b in edges:
            neighbors[a].add(b)
            neighbors[b].add(a)
        
        # Mark the nodes in 'restricted' as visited.
        seen = [False] * n
        for node in restricted:
            seen[node] = True
        
        # Use stack 'stack' to store all nodes to be visited, start from node 0.
        stack = [0]
        ans = 0
        seen[0] = True
        
        while stack:
            curr_node = stack.pop()
            ans += 1

            # Add all unvisited neighbors of the current node to 'stack' 
            # and mark them as visited.
            for next_node in neighbors[curr_node]:
                if not seen[next_node]:
                    seen[next_node] = True
                    stack.append(next_node)
        
        return ans
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
            if (rank[rootX] > root[rootY]) {
                swap(rootX, rootY);
            }
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
    }
    int getSize(int x) {
        return rank[find(x)];
    }
};

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        UnionFind uf(n);
        unordered_set<int> restSet(restricted.begin(), restricted.end());

        for (auto edge : edges) {
            int a = edge[0], b = edge[1];
            if (restSet.find(a) == restSet.end() && restSet.find(b) == restSet.end()) {
                uf.join(a, b);
            }
        }
        
        return uf.getSize(0);
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
            this.root[rootX] = rootY;
            this.rank[rootY] += this.rank[rootX];
        }
    }
    public int getSize(int x) {
        return this.rank[find(x)];
    }
}

class Solution {
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        UnionFind uf = new UnionFind(n);
        Set<Integer> restSet = new HashSet<>();

        for(int node : restricted){
            restSet.add(node);
        }

        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            if (!restSet.contains(a) && !restSet.contains(b)) {
                uf.union(a, b);
            }
        }
        return uf.getSize(0);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

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
            self.rank[root_y] += self.rank[root_x]
            self.root[root_x] = root_y
    def getSize(self, x):
        return self.rank[self.find(x)]

class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        rest_set_ = set(restricted)
        uf = UnionFind(n)

        for a, b in edges:
            if a not in rest_set and b not in rest_set:
                uf.union(a, b)
        
        return uf.getSize(0)
```

</details>
