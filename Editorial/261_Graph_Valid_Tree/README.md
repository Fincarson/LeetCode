# 261. Graph Valid Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/graph-valid-tree/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 261 - Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)

## Problem

You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

### Example 1

```text
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
```

### Example 2

```text
Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
```

## Constraints

- 1 <= n <= 2000
- 0 <= edges.length <= 5000
- edges[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- There are no self-loops or repeated edges.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Course Schedule](https://leetcode.com/problems/course-schedule/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 261. Graph Valid Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Graph Theory + Iterative Depth-First Search | Java |
| Advanced Graph Theory + Iterative Depth-First Search | Java, Python3 |
| Advanced Graph Theory + Union Find | Java, Python3 |

## Approach 1: Graph Theory + Iterative Depth-First Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
// Create a new list of lists.
List<List<Integer>> adjacencyList = new ArrayList<>();
// Initialise an empty list for each node.
for (int i = 0; i < n; i++) {
    adjacencyList.add(new ArrayList<>());
}
// Go through the edge list, populating the adjacency list.
for (int[] edge : edges) {
    adjacencyList.get(edge[0]).add(edge[1]);
    adjacencyList.get(edge[1]).add(edge[0]);
}
```

</details>

<br>

## Approach 2: Advanced Graph Theory + Iterative Depth-First Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean validTree(int n, int[][] edges) {
        
    if (edges.length != n - 1) return false;
    
    // Make the adjacency list.
    List<List<Integer>> adjacencyList = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        adjacencyList.add(new ArrayList<>());
    }
    for (int[] edge : edges) {
        adjacencyList.get(edge[0]).add(edge[1]);
        adjacencyList.get(edge[1]).add(edge[0]);
    }
    
    Stack<Integer> stack = new Stack<>();
    Set<Integer> seen = new HashSet<>();
    stack.push(0);
    seen.add(0);
    
    while (!stack.isEmpty()) {
        int node = stack.pop();
        for (int neighbour : adjacencyList.get(node)) {
            if (seen.contains(neighbour)) continue;
            seen.add(neighbour);
            stack.push(neighbour);
        }
    }
    
    return seen.size() == n;   
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        
        if len(edges) != n - 1: return False
        
        # Create an adjacency list.
        adj_list = [[] for _ in range(n)]
        for A, B in edges:
            adj_list[A].append(B)
            adj_list[B].append(A)
        
        # We still need a seen set to prevent our code from infinite
        # looping if there *is* cycles (and on the trivial cycles!)
        seen = {0}
        stack = [0]
        
        while stack:
            node = stack.pop()
            for neighbour in adj_list[node]:
                if neighbour in seen:
                    continue
                seen.add(neighbour)
                stack.append(neighbour)
        
        return len(seen) == n
```

</details>

<br>

## Approach 3:  Advanced Graph Theory + Union Find

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class UnionFind {
    
    private int[] parent;
    
    // For efficiency, we aren't using makeset, but instead initialising
    // all the sets at the same time in the constructor.
    public UnionFind(int n) {
        parent = new int[n];
        for (int node = 0; node < n; node++) {
            parent[node] = node;
        }
    }
    
    // The find method, without any optimizations. It traces up the parent
    // links until it finds the root node for A, and returns that root.
    public int find(int A) {
        while (parent[A] != A) {
            A = parent[A];
        }
        return A;
    }

    // The union method, without any optimizations. It returns True if a
    // merge happened, False if otherwise.
    public boolean union(int A, int B) {
        // Find the roots for A and B.
        int rootA = find(A);
        int rootB = find(B);
        // Check if A and B are already in the same set.
        if (rootA == rootB) {
            return false;
        }
        // Merge the sets containing A and B.
        parent[rootA] = rootB;
        return true;
    } 
}

class Solution {
    
    public boolean validTree(int n, int[][] edges) {
        
        // Condition 1: The graph must contain n - 1 edges.
        if (edges.length != n - 1) return false;
        
        // Condition 2: The graph must contain a single connected component.
        // Create a new UnionFind object with n nodes. 
        UnionFind unionFind = new UnionFind(n);
        // Add each edge. Check if a merge happened, because if it 
        // didn't, there must be a cycle.
        for (int[] edge : edges) {
            int A = edge[0];
            int B = edge[1];
            if (!unionFind.union(A, B)) {
                return false;
            }
        }
        
        // If we got this far, there's no cycles!
        return true;
    }
    
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class UnionFind:
    
    # For efficiency, we aren't using makeset, but instead initialising
    # all the sets at the same time in the constructor.
    def __init__(self, n):
        self.parent = [node for node in range(n)]
        
    # The find method, without any optimizations. It traces up the parent
    # links until it finds the root node for A, and returns that root.
    def find(self, A):
        while A != self.parent[A]:
            A = self.parent[A]
        return A
        
    # The union method, without any optimizations. It returns True if a
    # merge happened, False if otherwise.
    def union(self, A, B):
        # Find the roots for A and B.
        root_A = self.find(A)
        root_B = self.find(B)
        # Check if A and B are already in the same set.
        if root_A == root_B:
            return False
        # Merge the sets containing A and B.
        self.parent[root_A] = root_B
        return True

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # Condition 1: The graph must contain n - 1 edges.
        if len(edges) != n - 1: return False
        
        # Condition 2: The graph must contain a single connected component.
        # Create a new UnionFind object with n nodes. 
        unionFind = UnionFind(n)
        # Add each edge. Check if a merge happened, because if it 
        # didn't, there must be a cycle.
        for A, B in edges:
            if not unionFind.union(A, B):
                return False
        # If we got this far, there's no cycles!
        return True
```

</details>
