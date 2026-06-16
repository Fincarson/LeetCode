# 886. Possible Bipartition

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/possible-bipartition/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 886 - Possible Bipartition](https://leetcode.com/problems/possible-bipartition/)

## Problem

We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

### Example 1

```text
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
```

### Example 2

```text
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
```

## Constraints

- 1 <= n <= 2000
- 0 <= dislikes.length <= 104
- dislikes[i].length == 2
- 1 <= ai < bi <= n
- All the pairs of dislikes are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 886. Possible Bipartition

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search | C++, Java, Python3 |
| Depth First Search | C++, Java, Python3 |
| Union-Find | C++, Java, Python3 |

## Approach 1: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool bfs(int source, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        q.push(source);
        color[source] = 0;  // Start with marking source as `RED`.

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& neighbor : adj[node]) {
                // If there is a conflict, return false.
                if (color[neighbor] == color[node]) return false;
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& dislike : dislikes) {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }

        vector<int> color(n + 1, -1); // 0 stands for red and 1 stands for blue.
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                // For each pending component, run BFS.
                if (!bfs(i, adj, color))
                    // Return false, if there is conflict in the component.
                    return false;
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean bfs(int source, Map<Integer, List<Integer>> adj, int[] color) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(source);
        color[source] = 0; // Start with marking source as `RED`.

        while (!q.isEmpty()) {
            int node = q.poll();
            if (!adj.containsKey(node))
                continue;
            for (int neighbor : adj.get(node)) {
                if (color[neighbor] == color[node])
                    return false;
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.add(neighbor);
                }
            }
        }
        return true;
    }

    public boolean possibleBipartition(int n, int[][] dislikes) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : dislikes) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }

        int[] color = new int[n + 1];
        Arrays.fill(color, -1); // 0 stands for red and 1 stands for blue.

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                // For each pending component, run BFS.
                if (!bfs(i, adj, color))
                    // Return false, if there is conflict in the component.
                    return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def bfs(source):
            q = deque([source])
            color[source] = 0 # Start with marking source as 'RED'
            while q:
                node = q.popleft()
                for neighbor in adj[node]:
                    # If there is a conflict, return false.
                    if color[neighbor] == color[node]: return False
                    if color[neighbor] == -1:
                        color[neighbor] = 1 - color[node]
                        q.append(neighbor)
            
            return True
        
        adj = [[] for _ in range(n + 1)]
        for dislike in dislikes:
            adj[dislike[0]].append(dislike[1])
            adj[dislike[1]].append(dislike[0])
        
        color = [-1] * (n + 1) # 0 stands for red and 1 stands for blue.
        for i in range(1, n + 1):
            if color[i] == -1:
                # For each pending component, run BFS.
                if not bfs(i):
                    # Return false, if there is conflict in the component.
                    return False
        
        return True
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
    bool dfs(int node, int nodeColor, vector<vector<int>>& adj, vector<int>& color) {
        color[node] = nodeColor;
        for (auto& neighbor : adj[node]) {
            if (color[neighbor] == color[node]) return false;
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - color[node], adj, color)) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& dislike : dislikes) {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }
        vector<int> color(n + 1, -1); // 0 stands for red and 1 stands for blue.
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                // For each pending component, run DFS.
                if (!dfs(i, 0, adj, color))
                    // Return false, if there is conflict in the component.
                    return false;
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean dfs(int node, int nodeColor, Map<Integer, List<Integer>> adj, int[] color) {
        color[node] = nodeColor;
        if (!adj.containsKey(node))
            return true;
        for (int neighbor : adj.get(node)) {
            if (color[neighbor] == color[node])
                return false;
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - nodeColor, adj, color))
                    return false;
            }
        }
        return true;
    }

    public boolean possibleBipartition(int n, int[][] dislikes) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : dislikes) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }
        int[] color = new int[n + 1];
        Arrays.fill(color, -1); // 0 stands for red and 1 stands for blue.

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                // For each pending component, run DFS.
                if (!dfs(i, 0, adj, color))
                    // Return false, if there is conflict in the component.
                    return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def dfs(node, node_color):
            color[node] = node_color
            for neighbor in adj[node]:
                if color[neighbor] == color[node]: return False
                if color[neighbor] == -1:
                    if not dfs(neighbor, 1 - node_color):
                        return False

            return True
        
        adj = [[] for _ in range(n + 1)]
        for dislike in dislikes:
            adj[dislike[0]].append(dislike[1])
            adj[dislike[1]].append(dislike[0])
        
        color = [-1] * (n + 1) # 0 stands for red and 1 stands for blue.
        for i in range(1, n + 1):
            if color[i] == -1:
                # For each pending component, run DFS.
                if not dfs(i, 0):
                    # Return false, if there is conflict in the component.
                    return False
        
        return True
```

</details>

<br>

## Approach 3: Union-Find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);

        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& dislike : dislikes) {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }

        UnionFind dsu(n + 1);
        for (int node = 1; node <= n; node++) {
            for (int neighbor : adj[node]) {
                // Check if the node and its neighbor is in the same set.
                if (dsu.find(node) == dsu.find(neighbor)) return false;
                // Move all the neighbours into same set as the first neighbour.
                dsu.union_set(adj[node][0], neighbor);
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class UnionFind {
    int[] parent;
    int[] rank;

    public UnionFind(int size) {
        parent = new int[size];
        for (int i = 0; i < size; i++)
            parent[i] = i;
        rank = new int[size];
    }

    public int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    public void union(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
}

class Solution {
    public boolean possibleBipartition(int n, int[][] dislikes) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : dislikes) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }

        UnionFind dsu = new UnionFind(n + 1);
        for (int node = 1; node <= n; node++) {
            if (!adj.containsKey(node))
                continue;
            for (int neighbor : adj.get(node)) {
                // Check if the node and its neighbor is in the same set.
                if (dsu.find(node) == dsu.find(neighbor))
                    return false;
                // Move all the neighbours into same set as the first neighbour.
                dsu.union(adj.get(node).get(0), neighbor);
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        
        return self.parent[x]
    
    def union_set(self, x, y):
        xset = self.find(x)
        yset = self.find(y)
        if xset == yset:
            return
        
        if self.rank[xset] < self.rank[yset]:
            self.parent[xset] = yset
        elif self.rank[xset] > self.rank[yset]:
            self.parent[yset] = xset
        else:
            self.parent[yset] = xset
            self.rank[xset] += 1
        
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        adj = [[] for _ in range(n + 1)]
        for dislike in dislikes:
            adj[dislike[0]].append(dislike[1])
            adj[dislike[1]].append(dislike[0])
        
        dsu = UnionFind(n + 1)
        for node in range(1, n + 1):
            for neighbor in adj[node]:
                # Check if the node and its neighbor is in the same set.
                if dsu.find(node) == dsu.find(neighbor): return False
                # Move all the neighbours into same set as the first neighbour.
                dsu.union_set(adj[node][0], neighbor)
        
        return True
```

</details>
