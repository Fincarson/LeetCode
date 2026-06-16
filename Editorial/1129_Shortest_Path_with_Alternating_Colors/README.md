# 1129. Shortest Path with Alternating Colors

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/shortest-path-with-alternating-colors/)  
`Breadth-First Search` `Graph Theory`

**Problem Link:** [LeetCode 1129 - Shortest Path with Alternating Colors](https://leetcode.com/problems/shortest-path-with-alternating-colors/)

## Problem

You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

- redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
- blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.

Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

### Example 1

```text
Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]
```

### Example 2

```text
Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]
```

## Constraints

- 1 <= n <= 100
- 0 <= redEdges.length, blueEdges.length <= 400
- redEdges[i].length == blueEdges[j].length == 2
- 0 <= ai, bi, uj, vj < n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1129. Shortest Path with Alternating Colors

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Breadth First Search | C++, Java |

## Approach: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& redEdge : redEdges) {
            adj[redEdge[0]].push_back({redEdge[1], 0});
        }
        for (auto& blueEdge : blueEdges) {
            adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1));
        }

        vector<int> answer(n, -1);
        vector<vector<bool>> visit(n, vector<bool>(2));
        queue<vector<int>> q;

        // Start with node 0, with number of steps as 0 and undefined color -1.
        q.push({0, 0, -1});
        visit[0][1] = visit[0][0] = true;
        answer[0] = 0;

        while (!q.empty()) {
            auto element = q.front();
            int node = element[0], steps = element[1], prevColor = element[2];
            q.pop();

            for (auto& [neighbor, color] : adj[node]) {
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true;
                    q.push({neighbor, 1 + steps, color});
                    if (answer[neighbor] == -1) answer[neighbor] = 1 + steps;
                }
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
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        Map<Integer, List<List<Integer>>> adj = new HashMap<>();
        for (int[] redEdge : redEdges) {
            adj.computeIfAbsent(redEdge[0], k -> new ArrayList<List<Integer>>()).add(
                    Arrays.asList(redEdge[1], 0));
        }

        for (int[] blueEdge : blueEdges) {
            adj.computeIfAbsent(blueEdge[0], k -> new ArrayList<List<Integer>>()).add(
                    Arrays.asList(blueEdge[1], 1));
        }

        int[] answer = new int[n];
        Arrays.fill(answer, -1);
        boolean[][] visit = new boolean[n][2];
        Queue<int[]> q = new LinkedList<>();

        // Start with node 0, with number of steps as 0 and undefined color -1.
        q.offer(new int[] { 0, 0, -1 });
        answer[0] = 0;
        visit[0][1] = visit[0][0] = true;

        while (!q.isEmpty()) {
            int[] element = q.poll();
            int node = element[0], steps = element[1], prevColor = element[2];

            if (!adj.containsKey(node)) {
                continue;
            }

            for (List<Integer> nei : adj.get(node)) {
                int neighbor = nei.get(0);
                int color = nei.get(1);
                if (!visit[neighbor][color] && color != prevColor) {
                    if (answer[neighbor] == -1)
                        answer[neighbor] = 1 + steps;
                    visit[neighbor][color] = true;
                    q.offer(new int[] { neighbor, 1 + steps, color });
                }
            }
        }
        return answer;
    }
}
```

</details>
