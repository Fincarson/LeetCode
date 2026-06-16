# 1791. Find Center of Star Graph

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-center-of-star-graph/)  
`Graph Theory`

**Problem Link:** [LeetCode 1791 - Find Center of Star Graph](https://leetcode.com/problems/find-center-of-star-graph/)

## Problem

There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

### Example 1

```text
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
```

### Example 2

```text
Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
```

## Constraints

- 3 <= n <= 105
- edges.length == n - 1
- edges[i].length == 2
- 1 <= ui, vi <= n
- ui != vi
- The given edges represent a valid star graph.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Star Sum of a Graph](https://leetcode.com/problems/maximum-star-sum-of-a-graph/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1791. Find Center of Star Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Degree Count | C++, Java, Python3 |
| Greedy | C++, Java, Python3 |

## Approach 1: Degree Count

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degree;

        for (vector<int> edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for (pair<int, int> nodes : degree) {
            int node = nodes.first;
            int nodeDegree = nodes.second;

            if (nodeDegree == edges.size()) {
                return node;
            }
        }

        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findCenter(int[][] edges) {
        Map<Integer, Integer> degree = new HashMap<>();

        for (int[] edge : edges) {
            degree.put(edge[0], degree.getOrDefault(edge[0], 0) + 1);
            degree.put(edge[1], degree.getOrDefault(edge[1], 0) + 1);
        }

        for (int node : degree.keySet()) {
            if (degree.get(node) == edges.length) {
                return node;
            }
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
    def findCenter(self, edges: List[List[int]]) -> int:
        degree = {}

        for edge in edges:
            degree[edge[0]] = degree.get(edge[0], 0) + 1
            degree[edge[1]] = degree.get(edge[1], 0) + 1

        for node, count in degree.items():
            if count == len(edges):
                return node

        return -1
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> firstEdge = edges[0];
        vector<int> secondEdge = edges[1];

        return (firstEdge[0] == secondEdge[0] || firstEdge[0] == secondEdge[1])
                   ? firstEdge[0]
                   : firstEdge[1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findCenter(int[][] edges) {
        int[] firstEdge = edges[0];
        int[] secondEdge = edges[1];

        return (firstEdge[0] == secondEdge[0] || firstEdge[0] == secondEdge[1])
            ? firstEdge[0]
            : firstEdge[1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        first_edge, second_edge = edges[0], edges[1]

        return first_edge[0] if first_edge[0] in second_edge else first_edge[1]
```

</details>
