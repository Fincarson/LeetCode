# 1319. Number of Operations to Make Network Connected

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 1319 - Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)

## Problem

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

### Example 1

```text
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
```

### Example 2

```text
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
```

### Example 3

```text
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
```

## Constraints

- 1 <= n <= 105
- 1 <= connections.length <= min(n * (n - 1) / 2, 105)
- connections[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- There are no repeated connections.
- No two computers are connected by more than one cable.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1319. Number of Operations to Make Network Connected

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
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        visit[node] = true;
        for (int neighbor : adj[node]) {
            if (!visit[neighbor]) {
                dfs(neighbor, adj, visit);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<vector<int>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        int numberOfConnectedComponents = 0;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfConnectedComponents++;
                dfs(i, adj, visit);
            }
        }

        return numberOfConnectedComponents - 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void dfs(int node, Map<Integer, List<Integer>> adj, boolean[] visit) {
        visit[node] = true;
        if (!adj.containsKey(node)) {
            return;
        }
        for (int neighbor : adj.get(node)) {
            if (!visit[neighbor]) {
                visit[neighbor] = true;
                dfs(neighbor, adj, visit);
            }
        }
    }

    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) {
            return -1;
        }

        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] connection : connections) {
            adj.computeIfAbsent(connection[0], k -> new ArrayList<Integer>()).add(connection[1]);
            adj.computeIfAbsent(connection[1], k -> new ArrayList<Integer>()).add(connection[0]);
        }

        int numberOfConnectedComponents = 0;
        boolean[] visit = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfConnectedComponents++;
                dfs(i, adj, visit);
            }
        }

        return numberOfConnectedComponents - 1;
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
    void bfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<vector<int>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        int numberOfConnectedComponents = 0;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfConnectedComponents++;
                bfs(i, adj, visit);
            }
        }

        return numberOfConnectedComponents - 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void bfs(int node, Map<Integer, List<Integer>> adj, boolean[] visit) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(node);
        visit[node] = true;

        while (!q.isEmpty()) {
            node = q.poll();
            if (!adj.containsKey(node)) {
                continue;
            }
            for (int neighbor : adj.get(node)) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    q.offer(neighbor);
                }
            }
        }
    }

    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) {
            return -1;
        }

        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] connection : connections) {
            adj.computeIfAbsent(connection[0], k -> new ArrayList<Integer>()).add(connection[1]);
            adj.computeIfAbsent(connection[1], k -> new ArrayList<Integer>()).add(connection[0]);
        }

        int numberOfConnectedComponents = 0;
        boolean[] visit = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfConnectedComponents++;
                bfs(i, adj, visit);
            }
        }

        return numberOfConnectedComponents - 1;
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
        if (rank[xset] < rank[yset]) {
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        UnionFind dsu(n);
        int numberOfConnectedComponents = n;
        for (auto& connection : connections) {
            if (dsu.find(connection[0]) != dsu.find(connection[1])) {
                numberOfConnectedComponents--;
                dsu.union_set(connection[0], connection[1]);
            }
        }

        return numberOfConnectedComponents - 1;
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
    public int makeConnected(int n, int[][] connections) {
        if(connections.length < n-1) {
            return -1;
        }

       UnionFind dsu = new UnionFind(n);
        int numberOfConnectedComponents = n;
        for (int[] connection : connections) {
            if (dsu.find(connection[0]) != dsu.find(connection[1])) {
                numberOfConnectedComponents--;
                dsu.union_set(connection[0], connection[1]);
            }
        }

        return numberOfConnectedComponents - 1;
    }
}
```

</details>
