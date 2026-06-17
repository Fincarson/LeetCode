# 847. Shortest Path Visiting All Nodes

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)  
`Dynamic Programming` `Bit Manipulation` `Breadth-First Search` `Graph Theory` `Bitmask`

**Problem Link:** [LeetCode 847 - Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)

## Problem

You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

### Example 1

```text
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
```

### Example 2

```text
Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
```

## Constraints

- n == graph.length
- 1 <= n <= 12
- 0 <= graph[i].length < n
- graph[i] does not contain i.
- If graph[a] contains b, then graph[b] contains a.
- The input graph is always connected.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find the Minimum Cost Array Permutation](https://leetcode.com/problems/find-the-minimum-cost-array-permutation/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 847. Shortest Path Visiting All Nodes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DFS + Memoization (Top-Down DP) | Java, Python3 |
| Breadth-First Search (BFS) | Java, Python3 |

## Approach 1: DFS + Memoization (Top-Down DP)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int[][] cache;
    private int endingMask;
    
    public int dp(int node, int mask, int[][] graph) {
        if (cache[node][mask] != 0) {
            return cache[node][mask];
        }
        if ((mask & (mask - 1)) == 0) {
            // Base case - mask only has a single "1", which means
            // that only one node has been visited (the current node)
            return 0;
        }
        
        cache[node][mask] = Integer.MAX_VALUE - 1; // Avoid infinite loop in recursion
        for (int neighbor: graph[node]) {
            if ((mask & (1 << neighbor)) != 0) {
                int alreadyVisited = dp(neighbor, mask, graph);
                int notVisited = dp(neighbor, mask ^ (1 << node), graph);
                int betterOption = Math.min(alreadyVisited, notVisited);
                cache[node][mask] = Math.min(cache[node][mask], 1 + betterOption);
            }
        }
        
        return cache[node][mask];
    }
    
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        endingMask = (1 << n) - 1;
        cache = new int[n + 1][endingMask + 1];
        
        int best = Integer.MAX_VALUE;
        for (int node = 0; node < n; node++) {
            best = Math.min(best, dp(node, endingMask, graph));
        }
        
        return best;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPathLength(self, graph):
        def dp(node, mask):
            state = (node, mask)
            if state in cache:
                return cache[state]
            if mask & (mask - 1) == 0:
                # Base case - mask only has a single "1", which means
                # that only one node has been visited (the current node)
                return 0

            cache[state] = float("inf") # Avoid infinite loop in recursion
            for neighbor in graph[node]:
                if mask & (1 << neighbor):
                    already_visited = 1 + dp(neighbor, mask)
                    not_visited = 1 + dp(neighbor, mask ^ (1 << node))
                    cache[state] = min(cache[state], already_visited, not_visited)

            return cache[state]

        n = len(graph)
        ending_mask = (1 << n) - 1
        cache = {}

        return min(dp(node, ending_mask) for node in range(n))
```

</details>

<br>

## Approach 2: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestPathLength(int[][] graph) {
        if (graph.length == 1) {
            return 0;
        }
        
        int n = graph.length;
        int endingMask = (1 << n) - 1;
        boolean[][] seen = new boolean[n][endingMask];
        ArrayList<int[]> queue = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            queue.add(new int[] {i, 1 << i});
            seen[i][1 << i] = true;
        }
        
        int steps = 0;
        while (!queue.isEmpty()) {
            ArrayList<int[]> nextQueue = new ArrayList<>();
            for (int i = 0; i < queue.size(); i++) {
                int[] currentPair = queue.get(i);
                int node = currentPair[0];
                int mask = currentPair[1];
                for (int neighbor : graph[node]) {
                    int nextMask = mask | (1 << neighbor);
                    if (nextMask == endingMask) {
                        return 1 + steps;
                    }
                    
                    if (!seen[neighbor][nextMask]) {
                        seen[neighbor][nextMask] = true;
                        nextQueue.add(new int[] {neighbor, nextMask});
                    }
                }
            }
            steps++;
            queue = nextQueue;
        }
        
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        if len(graph) == 1:
            return 0
        
        n = len(graph)
        ending_mask = (1 << n) - 1
        queue = [(node, 1 << node) for node in range(n)]
        seen = set(queue)

        steps = 0
        while queue:
            next_queue = []
            for i in range(len(queue)):
                node, mask = queue[i]
                for neighbor in graph[node]:
                    next_mask = mask | (1 << neighbor)
                    if next_mask == ending_mask:
                        return 1 + steps
                    
                    if (neighbor, next_mask) not in seen:
                        seen.add((neighbor, next_mask))
                        next_queue.append((neighbor, next_mask))
            
            steps += 1
            queue = next_queue
```

</details>
