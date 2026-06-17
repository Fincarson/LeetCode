# 1557. Minimum Number of Vertices to Reach All Nodes

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/)  
`Graph Theory`

**Problem Link:** [LeetCode 1557 - Minimum Number of Vertices to Reach All Nodes](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/)

## Problem

Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.

### Example 1

```text
Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].
```

### Example 2

```text
Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
Output: [0,2,3]
Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.
```

## Constraints

- 2 <= n <= 10^5
- 1 <= edges.length <= min(10^5, n * (n - 1) / 2)
- edges[i].length == 2
- 0 <= fromi, toi < n
- All pairs (fromi, toi) are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1557. Minimum Number of Vertices to Reach All Nodes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: In-Degree Count | C++, Java, Python3 |

## Approach: In-Degree Count

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // List to signify if the vertex has an incoming edge or not.
        vector<bool> isIncomingEdgeExists(n, false);
        for (vector<int>& edge : edges) {
            isIncomingEdgeExists[edge[1]] = true;
        }
        
        vector<int> requiredNodes;
        for (int i = 0; i < n; i++) {
            // Store all the nodes that don't have an incoming edge.
            if (!isIncomingEdgeExists[i]) {
                requiredNodes.push_back(i);
            }
        }
        
        return requiredNodes;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
    // List to signify if the vertex has an incoming edge or not.
    boolean[] isIncomingEdgeExists = new boolean[n];
    for (List<Integer> edge : edges) {
      isIncomingEdgeExists[edge.get(1)] = true;
    }

    List<Integer> requiredNodes = new ArrayList();
    for (int i = 0; i < n; i++) {
      // Store all the nodes that don't have an incoming edge.
      if (!isIncomingEdgeExists[i]) {
        requiredNodes.add(i);
      }
    }

    return requiredNodes;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        in_degree = [False] * n
        for _, node2 in edges:
            in_degree[node2] = True

        return [node for node in range(n) if not in_degree[node]]
```

</details>
