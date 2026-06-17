# 1615. Maximal Network Rank

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximal-network-rank/)  
`Graph Theory`

**Problem Link:** [LeetCode 1615 - Maximal Network Rank](https://leetcode.com/problems/maximal-network-rank/)

## Problem

There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

### Example 1

```text
Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
Output: 4
Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.
```

### Example 2

```text
Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
Output: 5
Explanation: There are 5 roads that are connected to cities 1 or 2.
```

### Example 3

```text
Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
Output: 5
Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do not have to be connected.
```

## Constraints

- 2 <= n <= 100
- 0 <= roads.length <= n * (n - 1) / 2
- roads[i].length == 2
- 0 <= ai, bi <= n-1
- ai != bi
- Each pair of cities has at most one road connecting them.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1615. Maximal Network Rank

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Finding the in-degree of nodes | C++, Java, JavaScript, Python3, TypeScript |

## Approach: Finding the in-degree of nodes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank = 0;
        unordered_map<int, unordered_set<int>> adj;
        // Construct adjency list 'adj', where adj[node] stores all nodes connected to 'node'.
        for (auto& road : roads) {
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }

        // Iterate on each possible pair of nodes.
        for (int node1 = 0; node1 < n; ++node1) {
            for (int node2 = node1 + 1; node2 < n; ++node2) {
                int currentRank = adj[node1].size() + adj[node2].size();
                if (adj[node1].find(node2) != adj[node1].end()) {
                    --currentRank;
                }
                // Find the current pair's respective network rank and store if it's maximum till now.
                maxRank = max(maxRank, currentRank);
            }
        }
        // Return the maximum network rank.
        return maxRank;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        int maxRank = 0;
        Map<Integer, Set<Integer>> adj = new HashMap<>();
        // Construct adjency list 'adj', where adj[node] stores all nodes connected to 'node'.
        for (int[] road : roads) {
            adj.computeIfAbsent(road[0], k -> new HashSet<>()).add(road[1]);
            adj.computeIfAbsent(road[1], k -> new HashSet<>()).add(road[0]);
        }

        // Iterate on each possible pair of nodes.
        for (int node1 = 0; node1 < n; ++node1) {
            for (int node2 = node1 + 1; node2 < n; ++node2) {
                int currentRank = adj.getOrDefault(node1, Collections.emptySet()).size() +
                                  adj.getOrDefault(node2, Collections.emptySet()).size();

                // Find the current pair's respective network rank and store if it's maximum till now.
                if (adj.getOrDefault(node1, Collections.emptySet()).contains(node2)) {
                    --currentRank;
                }
                maxRank = Math.max(maxRank, currentRank);
            }
        }
        // Return the maximum network rank.
        return maxRank;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximalNetworkRank = function(n, roads) {
    let maxRank = 0;
    let adj = new Map();
    // Construct adjency list 'adj', where adj[node] stores all nodes connected to 'node'.
    for (let road of roads) {
        if (!adj.has(road[0])) {
            adj.set(road[0], new Set());
        }
        if (!adj.has(road[1])) {
            adj.set(road[1], new Set());
        }
        adj.get(road[0]).add(road[1]);
        adj.get(road[1]).add(road[0]);
    }

    // Iterate on each possible pair of nodes.
    for (let node1 = 0; node1 < n; ++node1) {
        for (let node2 = node1 + 1; node2 < n; ++node2) {
            let currentRank = (adj.get(node1) || new Set()).size +
                              (adj.get(node2) || new Set()).size;
            if ((adj.get(node1) || new Set()).has(node2)) {
                --currentRank;
            }
            // Find the current pair's respective network rank and store if it's maximum till now.
            maxRank = Math.max(maxRank, currentRank);
        }
    }
    // Return the maximum network rank.
    return maxRank;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        maxRank = 0
        adj = defaultdict(set)
        # Construct adjency list 'adj', where adj[node] stores all nodes connected to 'node'.
        for road in roads:
            adj[road[0]].add(road[1])
            adj[road[1]].add(road[0])

        # Iterate on each possible pair of nodes.
        for node1 in range(n):
            for node2 in range(node1 + 1, n):
                currentRank = len(adj[node1]) + len(adj[node2])
                if node2 in adj[node1]:
                    currentRank -= 1
                # Find the current pair's respective network rank and store if it's maximum till now.
                maxRank = max(maxRank, currentRank)
        # Return the maximum network rank.
        return maxRank
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximalNetworkRank(n: number, roads: number[][]): number {
    let maxRank = 0;
    const adj = new Map<number, Set<number>>();
    // Construct adjency list 'adj', where adj[node] stores all nodes connected to 'node'.
    for (const [a, b] of roads) {
        adj.set(a, (adj.get(a) || new Set<number>()).add(b));
        adj.set(b, (adj.get(b) || new Set<number>()).add(a));
    }

    // Iterate on each possible pair of nodes.
    for (let node1 = 0; node1 < n; ++node1) {
        for (let node2 = node1 + 1; node2 < n; ++node2) {
            let currentRank = (adj.get(node1)?.size ?? 0) + (adj.get(node2)?.size ?? 0);
            if (adj.get(node1)?.has(node2)) {
                --currentRank;
            }
            // Find the current pair's respective network rank and store if it's maximum till now.
            maxRank = Math.max(maxRank, currentRank);
        }
    }
    // Return the maximum network rank.
    return maxRank;
};
```

</details>
