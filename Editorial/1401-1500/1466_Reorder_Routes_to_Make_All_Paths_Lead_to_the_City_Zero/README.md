# 1466. Reorder Routes to Make All Paths Lead to the City Zero

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/)  
`Depth-First Search` `Breadth-First Search` `Graph Theory`

**Problem Link:** [LeetCode 1466 - Reorder Routes to Make All Paths Lead to the City Zero](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/)

## Problem

There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

### Example 1

```text
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
```

### Example 2

```text
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
```

### Example 3

```text
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
```

## Constraints

- 2 <= n <= 5 * 104
- connections.length == n - 1
- connections[i].length == 2
- 0 <= ai, bi <= n - 1
- ai != bi

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Edge Reversals So Every Node Is Reachable](https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1466. Reorder Routes to Make All Paths Lead to the City Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java |
| Breadth First Search | C++, Java |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int count = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        for (auto& [neighbor, sign] : adj[node]) {
            if (neighbor != parent) {
                count += sign;
                dfs(neighbor, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        dfs(0, -1, adj);
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int count = 0;

    public void dfs(int node, int parent, Map<Integer, List<List<Integer>>> adj) {
        if (!adj.containsKey(node)) {
            return;
        }
        for (List<Integer> nei : adj.get(node)) {
            int neighbor = nei.get(0);
            int sign = nei.get(1);
            if (neighbor != parent) {
                count += sign;
                dfs(neighbor, node, adj);
            }
        }
    }

    public int minReorder(int n, int[][] connections) {
        Map<Integer, List<List<Integer>>> adj = new HashMap<>();
        for (int[] connection : connections) {
            adj.computeIfAbsent(connection[0], k -> new ArrayList<List<Integer>>()).add(
                    Arrays.asList(connection[1], 1));
            adj.computeIfAbsent(connection[1], k -> new ArrayList<List<Integer>>()).add(
                    Arrays.asList(connection[0], 0));
        }
        dfs(0, -1, adj);
        return count;
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
    int count = 0;
    void bfs(int node, int n, vector<vector<pair<int, int>>>& adj) {
        queue<int> q;
        vector<bool> visit(n);
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (auto& [neighbor, sign] : adj[node]) {
                if (!visit[neighbor]) {
                    count += sign;
                    visit[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        bfs(0, n, adj);
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int count = 0;

    public void bfs(int node, int n, Map<Integer, List<List<Integer>>> adj) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visit = new boolean[n];
        q.offer(node);
        visit[node] = true;

        while (!q.isEmpty()) {
            node = q.poll();
            if (!adj.containsKey(node)) {
                continue;
            }
            for (List<Integer> nei : adj.get(node)) {
                int neighbor = nei.get(0);
                int sign = nei.get(1);
                if (!visit[neighbor]) {
                    count += sign;
                    visit[neighbor] = true;
                    q.offer(neighbor);
                }
            }
        }
    }

    public int minReorder(int n, int[][] connections) {
        Map<Integer, List<List<Integer>>> adj = new HashMap<>();
        for (int[] connection : connections) {
            adj.computeIfAbsent(connection[0], k -> new ArrayList<List<Integer>>()).add(
                    Arrays.asList(connection[1], 1));
            adj.computeIfAbsent(connection[1], k -> new ArrayList<List<Integer>>()).add(
                    Arrays.asList(connection[0], 0));
        }
        bfs(0, n, adj);
        return count;
    }
}
```

</details>
