# 1976. Number of Ways to Arrive at Destination

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/)  
`Dynamic Programming` `Graph Theory` `Topological Sort` `Shortest Path`

**Problem Link:** [LeetCode 1976 - Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/)

## Problem

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

### Example 1

```text
Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 Ã¢Å¾Â 6
- 0 Ã¢Å¾Â 4 Ã¢Å¾Â 6
- 0 Ã¢Å¾Â 1 Ã¢Å¾Â 2 Ã¢Å¾Â 5 Ã¢Å¾Â 6
- 0 Ã¢Å¾Â 1 Ã¢Å¾Â 3 Ã¢Å¾Â 5 Ã¢Å¾Â 6
```

### Example 2

```text
Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
```

## Constraints

- 1 <= n <= 200
- n - 1 <= roads.length <= n * (n - 1) / 2
- roads[i].length == 3
- 0 <= ui, vi <= n - 1
- 1 <= timei <= 109
- ui != vi
- There is at most one road connecting any two intersections.
- You can reach any intersection from any other intersection.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Second Minimum Time to Reach Destination](https://leetcode.com/problems/second-minimum-time-to-reach-destination/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1976. Number of Ways to Arrive at Destination

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dijkstra's Algorithm | C++, Java, Python3 |
| Floyd-Warshall algorithm | C++, Java, Python3 |

## Approach 1: Dijkstra's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Build adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int startNode = road[0], endNode = road[1], travelTime = road[2];
            graph[startNode].emplace_back(endNode, travelTime);
            graph[endNode].emplace_back(startNode, travelTime);
        }

        // Min-Heap (priority queue) for Dijkstra
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            minHeap;

        // Store shortest time to each node
        vector<long long> shortestTime(n, LLONG_MAX);
        // Number of ways to reach each node in shortest time
        vector<int> pathCount(n, 0);

        shortestTime[0] = 0;  // Distance to source is 0
        pathCount[0] = 1;     // 1 way to reach node 0

        minHeap.emplace(0, 0);  // {time, node}

        while (!minHeap.empty()) {
            long long currTime = minHeap.top().first;  // Current shortest time
            int currNode = minHeap.top().second;
            minHeap.pop();

            // Skip outdated distances
            if (currTime > shortestTime[currNode]) continue;

            for (auto& [neighborNode, roadTime] : graph[currNode]) {
                // Found a new shortest path Ã¢â€ â€™ Update shortest time and reset
                // path count
                if (currTime + roadTime < shortestTime[neighborNode]) {
                    shortestTime[neighborNode] = currTime + roadTime;
                    pathCount[neighborNode] = pathCount[currNode];
                    minHeap.emplace(shortestTime[neighborNode], neighborNode);
                }
                // Found another way with the same shortest time Ã¢â€ â€™ Add to path
                // count
                else if (currTime + roadTime == shortestTime[neighborNode]) {
                    pathCount[neighborNode] =
                        (pathCount[neighborNode] + pathCount[currNode]) % MOD;
                }
            }
        }

        return pathCount[n - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countPaths(int n, int[][] roads) {
        final int MOD = 1_000_000_007;

        // Build adjacency list
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] road : roads) {
            int startNode = road[0], endNode = road[1], travelTime = road[2];
            graph.get(startNode).add(new int[] { endNode, travelTime });
            graph.get(endNode).add(new int[] { startNode, travelTime });
        }

        // Min-Heap (priority queue) for Dijkstra
        PriorityQueue<long[]> minHeap = new PriorityQueue<>(
            Comparator.comparingLong(a -> a[0])
        );

        // Store shortest time to each node
        long[] shortestTime = new long[n];
        Arrays.fill(shortestTime, Long.MAX_VALUE);
        // Number of ways to reach each node in shortest time
        int[] pathCount = new int[n];

        shortestTime[0] = 0; // Distance to source is 0
        pathCount[0] = 1; // 1 way to reach node 0

        minHeap.offer(new long[] { 0, 0 }); // {time, node}

        while (!minHeap.isEmpty()) {
            long[] top = minHeap.poll();
            long currTime = top[0]; // Current shortest time
            int currNode = (int) top[1];

            // Skip outdated distances
            if (currTime > shortestTime[currNode]) {
                continue;
            }

            for (int[] neighbor : graph.get(currNode)) {
                int neighborNode = neighbor[0], roadTime = neighbor[1];

                // Found a new shortest path Ã¢â€ â€™ Update shortest time and reset path count
                if (currTime + roadTime < shortestTime[neighborNode]) {
                    shortestTime[neighborNode] = currTime + roadTime;
                    pathCount[neighborNode] = pathCount[currNode];
                    minHeap.offer(
                        new long[] { shortestTime[neighborNode], neighborNode }
                    );
                }
                // Found another way with the same shortest time Ã¢â€ â€™ Add to path count
                else if (currTime + roadTime == shortestTime[neighborNode]) {
                    pathCount[neighborNode] =
                        (pathCount[neighborNode] + pathCount[currNode]) % MOD;
                }
            }
        }

        return pathCount[n - 1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countPaths(self, n: int, roads: list[list[int]]) -> int:
        MOD = 1_000_000_007

        # Build adjacency list
        graph = [[] for _ in range(n)]
        for start_node, end_node, travel_time in roads:
            graph[start_node].append((end_node, travel_time))
            graph[end_node].append((start_node, travel_time))

        # Min-Heap (priority queue) for Dijkstra
        min_heap = [(0, 0)]  # (time, node)
        # Store shortest time to each node
        shortest_time = [float("inf")] * n
        # Number of ways to reach each node in shortest time
        path_count = [0] * n

        shortest_time[0] = 0  # Distance to source is 0
        path_count[0] = 1  # 1 way to reach node 0

        while min_heap:
            curr_time, curr_node = heapq.heappop(min_heap)
            # Skip outdated distances
            if curr_time > shortest_time[curr_node]:
                continue

            for neighbor_node, road_time in graph[curr_node]:
                # Found a new shortest path Ã¢â€ â€™ Update shortest time and reset path count
                if curr_time + road_time < shortest_time[neighbor_node]:
                    shortest_time[neighbor_node] = curr_time + road_time
                    path_count[neighbor_node] = path_count[curr_node]
                    heapq.heappush(
                        min_heap, (shortest_time[neighbor_node], neighbor_node)
                    )

                # Found another way with the same shortest time Ã¢â€ â€™ Add to path count
                elif curr_time + road_time == shortest_time[neighbor_node]:
                    path_count[neighbor_node] = (
                        path_count[neighbor_node] + path_count[curr_node]
                    ) % MOD

        return path_count[n - 1]
```

</details>

<br>

## Approach 2: Floyd-Warshall algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
#define ll long long int
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ll dp[n][n][2];
        // dp[src][dest][0] stores the minimum time between src and dest
        // dp[src][dest][1] stores the number of ways to reach dest from src
        // with the minimum time

        // Initialize the dp table
        for (ll src = 0; src < n; src++) {
            for (ll dest = 0; dest < n; dest++) {
                if (src != dest) {
                    // Set a large initial time
                    dp[src][dest][0] = 1e12;
                    // No paths yet
                    dp[src][dest][1] = 0;
                } else {
                    // Distance from a node to itself is 0
                    dp[src][dest][0] = 0;
                    // Only one trivial way (staying at the node)
                    dp[src][dest][1] = 1;
                }
            }
        }

        // Initialize direct roads from the input
        for (auto& road : roads) {
            ll startNode = road[0], endNode = road[1], travelTime = road[2];
            dp[startNode][endNode][0] = travelTime;
            dp[endNode][startNode][0] = travelTime;
            // There is one direct path
            dp[startNode][endNode][1] = 1;
            // Since the roads are bidirectional
            dp[endNode][startNode][1] = 1;
        }

        // Apply the Floyd-Warshall algorithm to compute shortest paths
        // Intermediate node
        for (ll mid = 0; mid < n; mid++) {
            // Starting node
            for (ll src = 0; src < n; src++) {
                // Destination node
                for (ll dest = 0; dest < n; dest++) {
                    // Avoid self-loops
                    if (src != mid && dest != mid) {
                        ll newTime = dp[src][mid][0] + dp[mid][dest][0];

                        if (newTime < dp[src][dest][0]) {
                            // Found a shorter path
                            dp[src][dest][0] = newTime;
                            dp[src][dest][1] =
                                (dp[src][mid][1] * dp[mid][dest][1]) % MOD;
                        } else if (newTime == dp[src][dest][0]) {
                            // Another way to achieve the same shortest time
                            dp[src][dest][1] =
                                (dp[src][dest][1] +
                                 dp[src][mid][1] * dp[mid][dest][1]) %
                                MOD;
                        }
                    }
                }
            }
        }

        // Return the number of shortest paths from node (n-1) to node 0
        return dp[n - 1][0][1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = 1_000_000_007;

    public int countPaths(int n, int[][] roads) {
        long[][][] dp = new long[n][n][2];

        // dp[src][dest][0] stores the minimum time between src and dest
        // dp[src][dest][1] stores the number of ways to reach dest from src
        // with the minimum time

        // Initialize the dp table
        for (int src = 0; src < n; src++) {
            for (int dest = 0; dest < n; dest++) {
                if (src != dest) {
                    // Set a large initial time
                    dp[src][dest][0] = (long) 1e12;
                    // No paths yet
                    dp[src][dest][1] = 0;
                } else {
                    // Distance from a node to itself is 0
                    dp[src][dest][0] = 0;
                    // Only one trivial way (staying at the node)
                    dp[src][dest][1] = 1;
                }
            }
        }

        // Initialize direct roads from the input
        for (int[] road : roads) {
            int startNode = road[0], endNode = road[1], travelTime = road[2];
            dp[startNode][endNode][0] = travelTime;
            dp[endNode][startNode][0] = travelTime;
            // There is one direct path
            dp[startNode][endNode][1] = 1;
            // Since the roads are bidirectional
            dp[endNode][startNode][1] = 1;
        }

        // Apply the Floyd-Warshall algorithm to compute shortest paths
        // Intermediate node
        for (int mid = 0; mid < n; mid++) {
            // Starting node
            for (int src = 0; src < n; src++) {
                // Destination node
                for (int dest = 0; dest < n; dest++) {
                    // Avoid self-loops
                    if (src != mid && dest != mid) {
                        long newTime = dp[src][mid][0] + dp[mid][dest][0];

                        if (newTime < dp[src][dest][0]) {
                            // Found a shorter path
                            dp[src][dest][0] = newTime;
                            dp[src][dest][1] =
                                (dp[src][mid][1] * dp[mid][dest][1]) % MOD;
                        } else if (newTime == dp[src][dest][0]) {
                            // Another way to achieve the same shortest time
                            dp[src][dest][1] =
                                (dp[src][dest][1] +
                                    dp[src][mid][1] * dp[mid][dest][1]) %
                                MOD;
                        }
                    }
                }
            }
        }

        // Return the number of shortest paths from node (n-1) to node 0
        return (int) dp[n - 1][0][1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    MOD = 1_000_000_007

    def countPaths(self, n: int, roads: list[list[int]]) -> int:
        # dp[src][dest][0] stores the minimum time between src and dest
        # dp[src][dest][1] stores the number of ways to reach dest from src
        # with the minimum time
        dp = [[[0, 0] for _ in range(n)] for _ in range(n)]

        # Initialize the dp table
        for src in range(n):
            for dest in range(n):
                if src != dest:
                    # Set a large initial time
                    dp[src][dest][0] = int(1e12)
                    # No paths yet
                    dp[src][dest][1] = 0
                else:
                    # Distance from a node to itself is 0
                    dp[src][dest][0] = 0
                    # Only one trivial way (staying at the node)
                    dp[src][dest][1] = 1

        # Initialize direct roads from the input
        for start_node, end_node, travel_time in roads:
            dp[start_node][end_node][0] = travel_time
            dp[end_node][start_node][0] = travel_time
            # There is one direct path
            dp[start_node][end_node][1] = 1
            # Since the roads are bidirectional
            dp[end_node][start_node][1] = 1

        # Apply the Floyd-Warshall algorithm to compute shortest paths
        # Intermediate node
        for mid in range(n):
            # Starting node
            for src in range(n):
                # Destination node
                for dest in range(n):
                    # Avoid self-loops
                    if src != mid and dest != mid:
                        new_time = dp[src][mid][0] + dp[mid][dest][0]

                        if new_time < dp[src][dest][0]:
                            # Found a shorter path
                            dp[src][dest][0] = new_time
                            dp[src][dest][1] = (
                                dp[src][mid][1] * dp[mid][dest][1]
                            ) % self.MOD
                        elif new_time == dp[src][dest][0]:

                            # Another way to achieve the same shortest time
                            dp[src][dest][1] = (
                                dp[src][dest][1]
                                + dp[src][mid][1] * dp[mid][dest][1]
                            ) % self.MOD

        # Return the number of shortest paths from node (n-1) to node 0
        return dp[n - 1][0][1]
```

</details>
