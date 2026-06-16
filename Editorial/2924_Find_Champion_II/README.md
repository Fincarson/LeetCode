# 2924. Find Champion II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-champion-ii/)  
`Graph Theory`

**Problem Link:** [LeetCode 2924 - Find Champion II](https://leetcode.com/problems/find-champion-ii/)

## Problem

There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG.

You are given the integer n and a 0-indexed 2D integer array edges of length m representing the DAG, where edges[i] = [ui, vi] indicates that there is a directed edge from team ui to team vi in the graph.

A directed edge from a to b in the graph means that team a is stronger than team b and team b is weaker than team a.

Team a will be the champion of the tournament if there is no team b that is stronger than team a.

Return the team that will be the champion of the tournament if there is a unique champion, otherwise, return -1.

Notes

- A cycle is a series of nodes a1, a2, ..., an, an+1 such that node a1 is the same node as node an+1, the nodes a1, a2, ..., an are distinct, and there is a directed edge from the node ai to node ai+1 for every i in the range [1, n].
- A DAG is a directed graph that does not have any cycle.

### Example 1

```text
Input: n = 3, edges = [[0,1],[1,2]]
Output: 0
Explanation: Team 1 is weaker than team 0. Team 2 is weaker than team 1. So the champion is team 0.
```

### Example 2

```text
Input: n = 4, edges = [[0,2],[1,3],[1,2]]
Output: -1
Explanation: Team 2 is weaker than team 0 and team 1. Team 3 is weaker than team 1. But team 1 and team 0 are not weaker than any other teams. So the answer is -1.
```

## Constraints

- 1 <= n <= 100
- m == edges.length
- 0 <= m <= n * (n - 1) / 2
- edges[i].length == 2
- 0 <= edge[i][j] <= n - 1
- edges[i][0] != edges[i][1]
- The input is generated such that if team a is stronger than team b, team b is not stronger than team a.
- The input is generated such that if team a is stronger than team b and team b is stronger than team c, then team a is stronger than team c.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2924. Find Champion II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: In-degree Count | C++, Java, Python3 |

## Approach: In-degree Count

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // Initialize the indegree array to track the number of incoming edges
        // for each team
        vector<int> indegree(n, 0);
        // Store the indegree of each team.
        for (auto edge : edges) {
            indegree[edge[1]]++;
        }

        int champ = -1, champCount = 0;
        for (int i = 0; i < n; i++) {
            // If the team can be champion, store the number and count of such
            // teams.
            if (indegree[i] == 0) {
                champCount++;
                champ = i;
            }
        }

        // If more than one team can be a champion, return -1, otherwise return
        // the champion team number
        return champCount > 1 ? -1 : champ;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int findChampion(int n, int[][] edges) {
        // Initialize the indegree array to track the number of incoming edges for each team
        int[] indegree = new int[n];

        // Store the indegree of each team
        for (int[] edge : edges) {
            indegree[edge[1]]++;
        }

        int champ = -1;
        int champCount = 0;

        // Iterate through all teams to find those with an indegree of 0
        for (int i = 0; i < n; i++) {
            // If the team can be a champion, store the team number and increment the count
            if (indegree[i] == 0) {
                champCount++;
                champ = i;
            }
        }

        // If more than one team can be a champion, return -1, otherwise return the champion team number
        return champCount > 1 ? -1 : champ;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findChampion(self, n: int, edges: list[list[int]]) -> int:
        # Initialize the indegree array to track the number of incoming edges for each team
        indegree = [0] * n

        # Store the indegree of each team
        for edge in edges:
            indegree[edge[1]] += 1

        champ = -1
        champ_count = 0

        # Iterate through all teams to find those with an indegree of 0
        for i in range(n):
            # If the team can be a champion, store the team number and increment the count
            if indegree[i] == 0:
                champ_count += 1
                champ = i

        # If more than one team can be a champion, return -1, otherwise return the champion team number
        return champ if champ_count == 1 else -1
```

</details>
