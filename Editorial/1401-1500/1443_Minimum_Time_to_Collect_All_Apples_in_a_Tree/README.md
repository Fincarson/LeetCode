# 1443. Minimum Time to Collect All Apples in a Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 1443 - Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)

## Problem

Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.

### Example 1

```text
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.
```

### Example 2

```text
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.
```

### Example 3

```text
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0
```

## Constraints

- 1 <= n <= 105
- edges.length == n - 1
- edges[i].length == 2
- 0 <= ai < bi <= n - 1
- hasApple.length == n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1443. Minimum Time to Collect All Apples in a Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Depth First Search | C++, Java |

## Approach: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int totalTime = 0, childTime = 0;
        for (auto child : adj[node]) {
            if (child == parent) continue;
            childTime = dfs(child, node, adj, hasApple);
            // childTime > 0 indicates subtree of child has apples. Since the root node of the
            // subtree does not contribute to the time, even if it has an apple, we have to check it
            // independently.
            if (childTime || hasApple[child]) totalTime += childTime + 2;
        }

        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int dfs(int node, int parent, Map<Integer, List<Integer>> adj,
            List<Boolean> hasApple) {
        if (!adj.containsKey(node))
            return 0;

        int totalTime = 0, childTime = 0;
        for (int child : adj.get(node)) {
            if (child == parent)
                continue;
            childTime = dfs(child, node, adj, hasApple);
            // childTime > 0 indicates subtree of child has apples. Since the root node of the
            // subtree does not contribute to the time, even if it has an apple, we have to check it
            // independently.
            if (childTime > 0 || hasApple.get(child))
                totalTime += childTime + 2;
        }
        return totalTime;
    }

    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }
        return dfs(0, -1, adj, hasApple);
    }
}
```

</details>
