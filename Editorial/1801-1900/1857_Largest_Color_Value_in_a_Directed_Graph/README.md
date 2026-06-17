# 1857. Largest Color Value in a Directed Graph

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/)  
`Hash Table` `String` `Dynamic Programming` `Graph Theory` `Topological Sort` `Memoization` `Counting`

**Problem Link:** [LeetCode 1857 - Largest Color Value in a Directed Graph](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/)

## Problem

There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

### Example 1

```text
Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
```

### Example 2

```text
Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.
```

## Constraints

- n == colors.length
- m == edges.length
- 1 <= n <= 105
- 0 <= m <= 105
- colors consists of lowercase English letters.
- 0 <= aj, bj < n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1857. Largest Color Value in a Directed Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Topological Sort Using Kahn's Algorithm | C++, Java, Python3 |
| Depth First Search | C++, Java, Python3 |

## Approach 1: Topological Sort Using Kahn's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<int>> count(n, vector<int>(26));
        queue<int> q;

        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int answer = 0, nodesSeen = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            answer = max(answer, ++count[node][colors[node] - 'a']);
            nodesSeen++;

            for (auto& neighbor : adj[node]) {
                for (int i = 0; i < 26; i++) {
                    // Try to update the frequency of colors for neighbor to
                    // include paths that use node->neighbor edge.
                    count[neighbor][i] =
                        max(count[neighbor][i], count[node][i]);
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return nodesSeen < n ? -1 : answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[n];

        for (int[] edge : edges) {
            adj
                .computeIfAbsent(edge[0], k -> new ArrayList<Integer>())
                .add(edge[1]);
            indegree[edge[1]]++;
        }

        int[][] count = new int[n][26];
        Queue<Integer> q = new LinkedList<>();

        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        int answer = 1, nodesSeen = 0;
        while (!q.isEmpty()) {
            int node = q.poll();
            answer = Math.max(answer, ++count[node][colors.charAt(node) - 'a']);
            nodesSeen++;

            if (!adj.containsKey(node)) {
                continue;
            }

            for (int neighbor : adj.get(node)) {
                for (int i = 0; i < 26; i++) {
                    // Try to update the frequency of colors for the neighbor to include paths
                    // that use node->neighbor edge.
                    count[neighbor][i] = Math.max(
                        count[neighbor][i],
                        count[node][i]
                    );
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }

        return nodesSeen < n ? -1 : answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        adj = [[] for _ in range(n)]
        indegree = [0] * n

        for edge in edges:
            adj[edge[0]].append(edge[1])
            indegree[edge[1]] += 1

        count = [[0] * 26 for _ in range(n)]
        q = []

        # Push all the nodes with indegree zero in the queue.
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)

        answer = 0
        nodesSeen = 0
        while q:
            node = q.pop(0)
            answer = max(answer, count[node][ord(colors[node]) - ord("a")] + 1)
            count[node][ord(colors[node]) - ord("a")] += 1
            nodesSeen += 1

            for neighbor in adj[node]:
                for i in range(26):
                    # Try to update the frequency of colors for the neighbor to include paths
                    # that use node->neighbor edge.
                    count[neighbor][i] = max(count[neighbor][i], count[node][i])

                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)

        return answer if nodesSeen == n else -1
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
    int dfs(int node, string& colors, vector<vector<int>>& adj,
            vector<vector<int>>& count, vector<bool>& visit,
            vector<bool>& inStack) {
        // If the node is already in the stack, we have a cycle.
        if (inStack[node]) {
            return INT_MAX;
        }
        if (visit[node]) {
            return count[node][colors[node] - 'a'];
        }
        // Mark the current node as visited and part of current recursion stack.
        visit[node] = true;
        inStack[node] = true;

        for (auto& neighbor : adj[node]) {
            if (dfs(neighbor, colors, adj, count, visit, inStack) == INT_MAX) {
                return INT_MAX;
            }
            for (int i = 0; i < 26; i++) {
                count[node][i] = max(count[node][i], count[neighbor][i]);
            }
        }

        // After all the incoming edges to the node are processed,
        // we count the color on the node itself.
        count[node][colors[node] - 'a']++;
        // Remove the node from the stack.
        inStack[node] = false;
        return count[node][colors[node] - 'a'];
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> count(n, vector<int>(26));
        vector<bool> visit(n), inStack(n);
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = max(answer, dfs(i, colors, adj, count, visit, inStack));
        }

        return answer == INT_MAX ? -1 : answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int dfs(
        int node,
        String colors,
        Map<Integer, List<Integer>> adj,
        int[][] count,
        boolean[] visit,
        boolean[] inStack
    ) {
        // If the node is already in the stack, we have a cycle.
        if (inStack[node]) {
            return Integer.MAX_VALUE;
        }
        if (visit[node]) {
            return count[node][colors.charAt(node) - 'a'];
        }
        // Mark the current node as visited and part of current recursion stack.
        visit[node] = true;
        inStack[node] = true;

        if (adj.containsKey(node)) {
            for (int neighbor : adj.get(node)) {
                if (
                    dfs(neighbor, colors, adj, count, visit, inStack) ==
                    Integer.MAX_VALUE
                ) {
                    return Integer.MAX_VALUE;
                }
                for (int i = 0; i < 26; i++) {
                    count[node][i] = Math.max(
                        count[node][i],
                        count[neighbor][i]
                    );
                }
            }
        }

        // After all the incoming edges to the node are processed,
        // we count the color on the node itself.
        count[node][colors.charAt(node) - 'a']++;
        // Remove the node from the stack.
        inStack[node] = false;
        return count[node][colors.charAt(node) - 'a'];
    }

    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            adj
                .computeIfAbsent(edge[0], k -> new ArrayList<Integer>())
                .add(edge[1]);
        }

        int[][] count = new int[n][26];
        boolean[] visit = new boolean[n];
        boolean[] inStack = new boolean[n];
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = Math.max(
                answer,
                dfs(i, colors, adj, count, visit, inStack)
            );
        }

        return answer == Integer.MAX_VALUE ? -1 : answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dfs(self, node, colors, adj, count, visit, inStack):
        # If the node is already in the stack, we have a cycle.
        if inStack[node]:
            return float("inf")
        if visit[node]:
            return count[node][ord(colors[node]) - ord("a")]
        # Mark the current node as visited and part of current recursion stack.
        visit[node] = True
        inStack[node] = True

        if node in adj:
            for neighbor in adj[node]:
                if self.dfs(
                    neighbor, colors, adj, count, visit, inStack
                ) == float("inf"):
                    return float("inf")
                for i in range(26):
                    count[node][i] = max(count[node][i], count[neighbor][i])

        # After all the incoming edges to the node are processed,
        # we count the color on the node itself.
        count[node][ord(colors[node]) - ord("a")] += 1
        # Remove the node from the stack.
        inStack[node] = False
        return count[node][ord(colors[node]) - ord("a")]

    def largestPathValue(self, colors, edges):
        n = len(colors)
        adj = {}
        for edge in edges:
            if edge[0] not in adj:
                adj[edge[0]] = []
            adj[edge[0]].append(edge[1])

        count = [[0] * 26 for _ in range(n)]
        visit = [False] * n
        inStack = [False] * n
        answer = 0
        for i in range(n):
            answer = max(
                answer, self.dfs(i, colors, adj, count, visit, inStack)
            )

        return -1 if answer == float("inf") else answer
```

</details>
