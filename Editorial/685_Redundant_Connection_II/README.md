# 685. Redundant Connection II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/redundant-connection-ii/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 685 - Redundant Connection II](https://leetcode.com/problems/redundant-connection-ii/)

## Problem

In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

### Example 1

```text
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
```

### Example 2

```text
Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
Output: [4,1]
```

## Constraints

- n == edges.length
- 3 <= n <= 1000
- edges[i].length == 2
- 1 <= ui, vi <= n
- ui != vi

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Redundant Connection](https://leetcode.com/problems/redundant-connection/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 685. Redundant Connection II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Depth-First Search [Accepted] | Java, Python |

## Approach #1: Depth-First Search [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int N = edges.length;
        Map<Integer, Integer> parent = new HashMap();
        List<int[]> candidates = new ArrayList();
        for (int[] edge: edges) {
            if (parent.containsKey(edge[1])) {
                candidates.add(new int[]{parent.get(edge[1]), edge[1]});
                candidates.add(edge);
            } else {
                parent.put(edge[1], edge[0]);
            }
        }

        int root = orbit(1, parent).node;
        if (candidates.isEmpty()) {
            Set<Integer> cycle = orbit(root, parent).seen;
            int[] ans = new int[]{0, 0};
            for (int[] edge: edges) {
                if (cycle.contains(edge[0]) && cycle.contains(edge[1])) {
                    ans = edge;
                }
            }
            return ans;
        }

        Map<Integer, List<Integer>> children = new HashMap();
        for (int v: parent.keySet()) {
            int pv = parent.get(v);
            if (!children.containsKey(pv)) {
                children.put(pv, new ArrayList<Integer>());
            }
            children.get(pv).add(v);
        }

        boolean[] seen = new boolean[N+1];
        seen[0] = true;
        Stack<Integer> stack = new Stack();
        stack.add(root);
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (!seen[node]) {
                seen[node] = true;
                if (children.containsKey(node)) {
                    for (int c: children.get(node)) {
                        stack.push(c);
                    }
                }
            }
        }
        for (boolean b: seen) {
            if (!b) {
                return candidates.get(0);
            }
        }
        return candidates.get(1);
    }

    public OrbitResult orbit(int node, Map<Integer, Integer> parent) {
        Set<Integer> seen = new HashSet();
        while (parent.containsKey(node) && !seen.contains(node)) {
            seen.add(node);
            node = parent.get(node);
        }
        return new OrbitResult(node, seen);
    }

}
class OrbitResult {
    int node;
    Set<Integer> seen;
    OrbitResult(int n, Set<Integer> s) {
        node = n;
        seen = s;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findRedundantDirectedConnection(self, edges):
        N = len(edges)
        parent = {}
        candidates = []
        for u, v in edges:
            if v in parent:
                candidates.append((parent[v], v))
                candidates.append((u, v))
            else:
                parent[v] = u

        def orbit(node):
            seen = set()
            while node in parent and node not in seen:
                seen.add(node)
                node = parent[node]
            return node, seen

        root = orbit(1)[0]

        if not candidates:
            cycle = orbit(root)[1]
            for u, v in edges:
                if u in cycle and v in cycle:
                    ans = u, v
            return ans

        children = collections.defaultdict(list)
        for v in parent:
            children[parent[v]].append(v)

        seen = [True] + [False] * N
        stack = [root]
        while stack:
            node = stack.pop()
            if not seen[node]:
                seen[node] = True
                stack.extend(children[node])

        return candidates[all(seen)]
```

</details>
