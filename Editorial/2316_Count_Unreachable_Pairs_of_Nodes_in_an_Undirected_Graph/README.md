# 2316. Count Unreachable Pairs of Nodes in an Undirected Graph

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 2316 - Count Unreachable Pairs of Nodes in an Undirected Graph](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/)

## Problem

You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

### Example 1

```text
Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
```

### Example 2

```text
Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.
```

## Constraints

- 1 <= n <= 105
- 0 <= edges.length <= 2 * 105
- edges[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- There are no repeated edges.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Islands](https://leetcode.com/problems/number-of-islands/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2316. Count Unreachable Pairs of Nodes in an Undirected Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java |
| Breadth First Search | C++, Java |
| Union-find | C++, Java |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        int count = 1;
        visit[node] = true;
        for (int neighbor : adj[node]) {
            if (!visit[neighbor]) {
                count += dfs(neighbor, adj, visit);
            }
        }
        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        long long numberOfPairs = 0;
        long long sizeOfComponent = 0;
        long long remainingNodes = n;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                sizeOfComponent = dfs(i, adj, visit);
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }
        return numberOfPairs;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int dfs(int node, Map<Integer, List<Integer>> adj, boolean[] visit) {
        int count = 1;
        visit[node] = true;
        if (!adj.containsKey(node)) {
            return count;
        }
        for (int neighbor : adj.get(node)) {
            if (!visit[neighbor]) {
                count += dfs(neighbor, adj, visit);
            }
        }
        return count;
    }

    public long countPairs(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], k -> new ArrayList<Integer>()).add(edge[1]);
            adj.computeIfAbsent(edge[1], k -> new ArrayList<Integer>()).add(edge[0]);
        }

        long numberOfPairs = 0;
        long sizeOfComponent = 0;
        long remainingNodes = n;
        boolean[] visit = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                sizeOfComponent = dfs(i, adj, visit);
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }
        return numberOfPairs;
    }
}
```

</details>

<br>

## Approach 2: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int bfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        int count = 1;
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    count++;
                    q.push(neighbor);
                }
            }
        }
        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        long long numberOfPairs = 0;
        long long sizeOfComponent = 0;
        long long remainingNodes = n;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                sizeOfComponent = bfs(i, adj, visit);
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }
        return numberOfPairs;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int bfs(int node, Map<Integer, List<Integer>> adj, boolean[] visit) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(node);
        int count = 1;
        visit[node] = true;

        while (!q.isEmpty()) {
            node = q.poll();
            if (!adj.containsKey(node)) {
                continue;
            }
            for (int neighbor : adj.get(node)) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    count++;
                    q.offer(neighbor);
                }
            }
        }
        return count;
    }

    public long countPairs(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], k -> new ArrayList<Integer>()).add(edge[1]);
            adj.computeIfAbsent(edge[1], k -> new ArrayList<Integer>()).add(edge[0]);
        }

        long numberOfPairs = 0;
        long sizeOfComponent = 0;
        long remainingNodes = n;
        boolean[] visit = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                sizeOfComponent = bfs(i, adj, visit);
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }
        return numberOfPairs;
    }
}
```

</details>

<br>

## Approach 3: Union-find

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
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind dsu(n);
        for (auto edge : edges) {
            dsu.union_set(edge[0], edge[1]);
        }
        unordered_map<int, int> componentSize;
        for (int i = 0; i < n; i++) {
            componentSize[dsu.find(i)]++;
        }

        long long numberOfPaths = 0;
        long long remainingNodes = n;
        for (auto component : componentSize) {
            int componentSize = component.second;
            numberOfPaths += componentSize * (remainingNodes - componentSize);
            remainingNodes -= componentSize;
        }
        return numberOfPaths;
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
    public void union_set(int x, int y) {
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
    public long countPairs(int n, int[][] edges) {
        UnionFind dsu = new UnionFind(n);
        for(int[] edge: edges) {
            dsu.union_set(edge[0], edge[1]);
        }

        Map<Integer, Integer> componentSize = new HashMap<>();
        for(int i= 0; i<n; i++) {
            int parent = dsu.find(i);
            if(componentSize.containsKey(parent)) {
                componentSize.put(parent, componentSize.get(parent) + 1);
            } else {
                componentSize.put(parent, 1);
            }
        }
        
        long numberOfPaths = 0;
        long remainingNodes = n;
        for (int size : componentSize.values()) {
            numberOfPaths += size * (remainingNodes - size);
            remainingNodes -= size;
        }
        return numberOfPaths;
    }
}
```

</details>
