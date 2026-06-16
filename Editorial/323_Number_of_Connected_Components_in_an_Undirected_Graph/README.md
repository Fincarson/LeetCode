# 323. Number of Connected Components in an Undirected Graph

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 323 - Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)

## Problem

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

### Example 1

```text
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
```

### Example 2

```text
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
```

## Constraints

- 1 <= n <= 2000
- 1 <= edges.length <= 5000
- edges[i] = [ai, bi]
- ai != bi
- There are no repeated edges.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Islands](https://leetcode.com/problems/number-of-islands/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Paths in Maze That Lead to Same Room](https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count the Number of Complete Components](https://leetcode.com/problems/count-the-number-of-complete-components/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 323. Number of Connected Components in an Undirected Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C++, Java |
| Disjoint Set Union (DSU) | C++, Java |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void dfs(vector<int> adjList[], vector<int> &visited, int src) {
        visited[src] = 1;
        
        for (int i = 0; i < adjList[src].size(); i++) {
            if (visited[adjList[src][i]] == 0) {
                dfs(adjList, visited, adjList[src][i]);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0) return 0;
      
        int components = 0;
        vector<int> visited(n, 0);
        vector<int> adjList[n];
    
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                components++;
                dfs(adjList, visited, i);
            }
        }
        return components;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
     private void dfs(List<Integer>[] adjList, int[] visited, int startNode) {
        visited[startNode] = 1;
         
        for (int i = 0; i < adjList[startNode].size(); i++) {
            if (visited[adjList[startNode].get(i)] == 0) {
                dfs(adjList, visited, adjList[startNode].get(i));
            }
        }
    }
    
    public int countComponents(int n, int[][] edges) {
        int components = 0;
        int[] visited = new int[n];
        
        List<Integer>[] adjList = new ArrayList[n]; 
        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<Integer>();
        }
        
        for (int i = 0; i < edges.length; i++) {
            adjList[edges[i][0]].add(edges[i][1]);
            adjList[edges[i][1]].add(edges[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                components++;
                dfs(adjList, visited, i);
            }
        }
        return components;
    }
}
```

</details>

<br>

## Approach 2: Disjoint Set Union (DSU)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int find(vector<int> &representative, int vertex) {
        if (vertex == representative[vertex]) {
            return vertex;
        }
        
        return representative[vertex] = find(representative, representative[vertex]);
    }
    
    int combine(vector<int> &representative, vector<int> &size, int vertex1, int vertex2) {
        vertex1 = find(representative, vertex1);
        vertex2 = find(representative, vertex2);
        
        if (vertex1 == vertex2) {
            return 0;
        } else {
            
            if (size[vertex1] > size[vertex2]) {
                size[vertex1] += size[vertex2];
                representative[vertex2] = vertex1;
            } else {
                size[vertex2] += size[vertex1];
                representative[vertex1] = vertex2;
            }
            return 1;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> representative(n), size(n);
        
        for (int i = 0; i < n; i++) {
            representative[i] = i;
            size[i] = 1;
        }
        
        int components = n;
        for (int i = 0; i < edges.size(); i++) {
            components -= combine(representative, size, edges[i][0], edges[i][1]);
        }

        return components;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    private int find(int[] representative, int vertex) {
        if (vertex == representative[vertex]) {
            return vertex;
        }
        
        return representative[vertex] = find(representative, representative[vertex]);
    }
    
    private int combine(int[] representative, int[] size, int vertex1, int vertex2) {
        vertex1 = find(representative, vertex1);
        vertex2 = find(representative, vertex2);
        
        if (vertex1 == vertex2) {
            return 0;
        } else {
            if (size[vertex1] > size[vertex2]) {
                size[vertex1] += size[vertex2];
                representative[vertex2] = vertex1;
            } else {
                size[vertex2] += size[vertex1];
                representative[vertex1] = vertex2;
            }
            return 1;
        }
    }

    public int countComponents(int n, int[][] edges) {
        int[] representative = new int[n];
        int[] size = new int[n];
        
        for (int i = 0; i < n; i++) {
            representative[i] = i;
            size[i] = 1;
        }
        
        int components = n;
        for (int i = 0; i < edges.length; i++) { 
            components -= combine(representative, size, edges[i][0], edges[i][1]);
        }

        return components;
    }
}
```

</details>
