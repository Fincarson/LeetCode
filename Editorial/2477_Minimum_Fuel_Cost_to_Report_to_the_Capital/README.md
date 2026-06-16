# 2477. Minimum Fuel Cost to Report to the Capital

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Graph Theory`

**Problem Link:** [LeetCode 2477 - Minimum Fuel Cost to Report to the Capital](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/)

## Problem

There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

Return the minimum number of liters of fuel to reach the capital city.

### Example 1

```text
Input: roads = [[0,1],[0,2],[0,3]], seats = 5
Output: 3
Explanation:
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative2 goes directly to the capital with 1 liter of fuel.
- Representative3 goes directly to the capital with 1 liter of fuel.
It costs 3 liters of fuel at minimum.
It can be proven that 3 is the minimum number of liters of fuel needed.
```

### Example 2

```text
Input: roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
Output: 7
Explanation:
- Representative2 goes directly to city 3 with 1 liter of fuel.
- Representative2 and representative3 go together to city 1 with 1 liter of fuel.
- Representative2 and representative3 go together to the capital with 1 liter of fuel.
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative5 goes directly to the capital with 1 liter of fuel.
- Representative6 goes directly to city 4 with 1 liter of fuel.
- Representative4 and representative6 go together to the capital with 1 liter of fuel.
It costs 7 liters of fuel at minimum.
It can be proven that 7 is the minimum number of liters of fuel needed.
```

### Example 3

```text
Input: roads = [], seats = 1
Output: 0
Explanation: No representatives need to travel to the capital city.
```

## Constraints

- 1 <= n <= 105
- roads.length == n - 1
- roads[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- roads represents a valid tree.
- 1 <= seats <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2477. Minimum Fuel Cost to Report to the Capital

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
    long long fuel;

    long long dfs(int node, int parent, vector<vector<int>>& adj, int& seats) {
        // The node itself has one representative.
        int representatives = 1;
        for (auto& child : adj[node]) {
            if (child != parent) {
                // Add count of representatives in each child subtree to the parent subtree.
                representatives += dfs(child, node, adj, seats);
            }
        }

        if (node != 0) {
            // Count the fuel it takes to move to the parent node.
            // Root node does not have any parent so we ignore it.
            fuel += ceil((double)representatives / seats);
        }
        return representatives;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        dfs(0, -1, adj, seats);
        return fuel;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    long fuel;

    public long dfs(int node, int parent, Map<Integer, List<Integer>> adj, int seats) {
        // The node itself has one representative.
        int representatives = 1;
        if (!adj.containsKey(node)) {
            return representatives;
        }
        for (int child : adj.get(node)) {
            if (child != parent) {
                // Add count of representatives in each child subtree to the parent subtree.
                representatives += dfs(child, node, adj, seats);
            }
        }
        if (node != 0) {
            // Count the fuel it takes to move to the parent node.
            // Root node does not have any parent so we ignore it.
            fuel += Math.ceil((double) representatives / seats);
        }
        return representatives;
    }

    public long minimumFuelCost(int[][] roads, int seats) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] road : roads) {
            adj.computeIfAbsent(road[0], k -> new ArrayList<Integer>()).add(road[1]);
            adj.computeIfAbsent(road[1], k -> new ArrayList<Integer>()).add(road[0]);
        }
        dfs(0, -1, adj, seats);
        return fuel;
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
    long long bfs(int n, vector<vector<int>>& adj, vector<int>& degree, int& seats) {
        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> representatives(n, 1);
        long long fuel = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            fuel += ceil((double)representatives[node] / seats);
            for (auto& neighbor : adj[node]) {
                degree[neighbor]--;
                representatives[neighbor] += representatives[node];
                if (degree[neighbor] == 1 && neighbor != 0) {
                    q.push(neighbor);
                }
            }
        }
        return fuel;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        vector<int> degree(n);

        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
            degree[road[0]]++;
            degree[road[1]]++;
        }

        return bfs(n, adj, degree, seats);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long bfs(int n, Map<Integer, List<Integer>> adj, int[] degree, int seats) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i < n; i++) {
            if (degree[i] == 1) {
                q.offer(i);
            }
        }

        int[] representatives = new int[n];
        Arrays.fill(representatives, 1);
        long fuel = 0;

        while (!q.isEmpty()) {
            int node = q.poll();
            fuel += Math.ceil((double) representatives[node] / seats);

            for (int neighbor : adj.get(node)) {
                degree[neighbor]--;
                representatives[neighbor] += representatives[node];
                if (degree[neighbor] == 1 && neighbor != 0) {
                    q.offer(neighbor);
                }
            }
        }
        return fuel;
    }

    public long minimumFuelCost(int[][] roads, int seats) {
        int n = roads.length + 1;
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] degree = new int[n];

        for (int[] road : roads) {
            adj.computeIfAbsent(road[0], k -> new ArrayList<Integer>()).add(road[1]);
            adj.computeIfAbsent(road[1], k -> new ArrayList<Integer>()).add(road[0]);
            degree[road[0]]++;
            degree[road[1]]++;
        }

        return bfs(n, adj, degree, seats);
    }
}
```

</details>
