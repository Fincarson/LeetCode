# 1059. All Paths from Source Lead to Destination

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/all-paths-from-source-lead-to-destination/)  
`Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 1059 - All Paths from Source Lead to Destination](https://leetcode.com/problems/all-paths-from-source-lead-to-destination/)

## Problem

Given the edges of a directed graph where edges[i] = [ai, bi] indicates there is an edge between nodes ai and bi, and two nodes source and destination of this graph, determine whether or not all paths starting from source eventually, end at destination, that is:

- At least one path exists from the source node to the destination node
- If a path exists from the source node to a node with no outgoing edges, then that node is equal to destination.
- The number of possible paths from source to destination is a finite number.

Return true if and only if all roads from source lead to destination.

### Example 1

```text
Input: n = 3, edges = [[0,1],[0,2]], source = 0, destination = 2
Output: false
Explanation: It is possible to reach and get stuck on both node 1 and node 2.
```

### Example 2

```text
Input: n = 4, edges = [[0,1],[0,3],[1,2],[2,1]], source = 0, destination = 3
Output: false
Explanation: We have two possibilities: to end at node 3, or to loop over node 1 and node 2 indefinitely.
```

### Example 3

```text
Input: n = 4, edges = [[0,1],[0,2],[1,3],[2,3]], source = 0, destination = 3
Output: true
```

## Constraints

- 1 <= n <= 104
- 0 <= edges.length <= 104
- edges.length == 2
- 0 <= ai, bi <= n - 1
- 0 <= source <= n - 1
- 0 <= destination <= n - 1
- The given graph may have self-loops and parallel edges.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1059. All Paths from Source Lead to Destination

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Depth First Search | Java, Python3 |

## Approach: Depth First Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    // We don't use the state WHITE as such anywhere. Instead, the "null" value in the states array below is a substitute for WHITE.
    enum Color { GRAY, BLACK };
    
    public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
        
        List<Integer>[] graph = buildDigraph(n, edges);
        return leadsToDest(graph, source, destination, new Color[n]);
    }
    
    private boolean leadsToDest(List<Integer>[] graph, int node, int dest, Color[] states) {
        
        // If the state is GRAY, this is a backward edge and hence, it creates a loop.
        if (states[node] != null) {
            return states[node] == Color.BLACK;
        }
        
        // If this is a leaf node, it should be equal to the destination.
        if (graph[node].isEmpty()) {
            return node == dest;
        }
        
        // Now, we are processing this node. So we mark it as GRAY
        states[node] = Color.GRAY;
        
        for (int next : graph[node]) {
            
            // If we get a `false` from any recursive call on the neighbors, we short circuit and return from there.
            if (!leadsToDest(graph, next, dest, states)) {
                return false;
            }
        }
        
        // Recursive processing done for the node. We mark it BLACK
        states[node] = Color.BLACK;
        return true;
    }
    
    private List<Integer>[] buildDigraph(int n, int[][] edges) {
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
        }
        
        return graph;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    
    # We don't use the state WHITE as such anywhere. Instead, the "null" value in the states array below is a substitute for WHITE.
    GRAY = 1
    BLACK = 2

    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = self.buildDigraph(n, edges)
        return self.leadsToDest(graph, source, destination, [None] * n)
        
    def leadsToDest(self, graph, node, dest, states):
        
        # If the state is GRAY, this is a backward edge and hence, it creates a Loop.
        if states[node] != None:
            return states[node] == Solution.BLACK
        
        # If this is a leaf node, it should be equal to the destination.
        if len(graph[node]) == 0:
            return node == dest
        
        # Now, we are processing this node. So we mark it as GRAY.
        states[node] = Solution.GRAY
        
        for next_node in graph[node]:
            
            # If we get a `false` from any recursive call on the neighbors, we short circuit and return from there.
            if not self.leadsToDest(graph, next_node, dest, states):
                return False;
        
        # Recursive processing done for the node. We mark it BLACK.
        states[node] = Solution.BLACK
        return True
        
    def buildDigraph(self, n, edges):
        graph = [[] for _ in range(n)]
        
        for edge in edges:
            graph[edge[0]].append(edge[1])
            
        return graph
```

</details>
