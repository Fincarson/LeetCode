# 2360. Longest Cycle in a Graph

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/longest-cycle-in-a-graph/)  
`Depth-First Search` `Breadth-First Search` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 2360 - Longest Cycle in a Graph](https://leetcode.com/problems/longest-cycle-in-a-graph/)

## Problem

You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.

### Example 1

```text
Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.
```

### Example 2

```text
Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.
```

## Constraints

- n == edges.length
- 2 <= n <= 105
- -1 <= edges[i] < n
- edges[i] != i

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Strange Printer II](https://leetcode.com/problems/strange-printer-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Number of Operations to Sort a Binary Tree by Level](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Shortest Cycle in a Graph](https://leetcode.com/problems/shortest-cycle-in-a-graph/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2360. Longest Cycle in a Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java |
| Kahn's Algorithm | C++, Java |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int answer = -1;

    void dfs(int node, vector<int>& edges, unordered_map<int, int>& dist, vector<bool>& visit) {
        visit[node] = true;
        int neighbor = edges[node];

        if (neighbor != -1 && !visit[neighbor]) {
            dist[neighbor] = dist[node] + 1;
            dfs(neighbor, edges, dist, visit);
        } else if (neighbor != -1 && dist.count(neighbor)) {
            answer = max(answer, dist[node] - dist[neighbor] + 1);
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(i, edges, dist, visit);
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int answer = -1;

    public void dfs(int node, int[] edges, Map<Integer, Integer> dist, boolean[] visit) {
        visit[node] = true;
        int neighbor = edges[node];

        if (neighbor != -1 && !visit[neighbor]) {
            dist.put(neighbor, dist.get(node) + 1);
            dfs(neighbor, edges, dist, visit);
        } else if (neighbor != -1 && dist.containsKey(neighbor)) {
            answer = Math.max(answer, dist.get(node) - dist.get(neighbor) + 1);
        }
    }

    public int longestCycle(int[] edges) {
        int n = edges.length;
        boolean[] visit = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                Map<Integer, Integer> dist = new HashMap<>();
                dist.put(i, 1);
                dfs(i, edges, dist, visit);
            }
        }
        return answer;
    }
}
```

</details>

<br>

## Approach 2: Kahn's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visit(n);
        vector<int> indegree(n);

        // Count indegree of each node.
        for (int edge : edges) {
            if (edge != -1) {
                indegree[edge]++;
            }
        }

        // Kahn's algorithm starts.
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            visit[node] = true;
            int neighbor = edges[node];
            if (neighbor != -1) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        // Kahn's algorithm ends.

        int answer = -1;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                int neighbor = edges[i];
                int count = 1;
                visit[i] = true;
                // Iterate in the cycle.
                while (neighbor != i) {
                    visit[neighbor] = true;
                    count++;
                    neighbor = edges[neighbor];
                }
                answer = max(answer, count);
            }
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestCycle(int[] edges) {
        int n = edges.length;
        boolean[] visit = new boolean[n];
        int[] indegree = new int[n];

        // Count indegree of each node.
        for (int edge : edges) {
            if (edge != -1) {
                indegree[edge]++;
            }
        }

        // Kahn's algorithm starts.
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        while (!q.isEmpty()) {
            int node = q.poll();
            visit[node] = true;
            int neighbor = edges[node];
            if (neighbor != -1) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }
        // Kahn's algorithm ends.

        int answer = -1;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                int neighbor = edges[i];
                int count = 1;
                visit[i] = true;
                // Iterate in the cycle.
                while (neighbor != i) {
                    visit[neighbor] = true;
                    count++;
                    neighbor = edges[neighbor];
                }
                answer = Math.max(answer, count);
            }
        }
        return answer;
    }
}
```

</details>
