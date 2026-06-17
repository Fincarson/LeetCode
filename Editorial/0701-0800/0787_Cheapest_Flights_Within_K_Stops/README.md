# 787. Cheapest Flights Within K Stops

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/cheapest-flights-within-k-stops/)  
`Dynamic Programming` `Depth-First Search` `Breadth-First Search` `Graph Theory` `Heap (Priority Queue)` `Shortest Path`

**Problem Link:** [LeetCode 787 - Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

## Problem

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

### Example 1

```text
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
```

### Example 2

```text
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
```

### Example 3

```text
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
```

## Constraints

- 2 <= n <= 100
- 0 <= flights.length <= (n * (n - 1) / 2)
- flights[i].length == 3
- 0 <= fromi, toi < n
- fromi != toi
- 1 <= pricei <= 104
- There will not be any multiple flights between two cities.
- 0 <= src, dst, k < n
- src != dst

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Vacation Days](https://leetcode.com/problems/maximum-vacation-days/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Cost to Reach City With Discounts](https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 787. Cheapest Flights Within K Stops

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search | C++, Java |
| Bellman Ford | C++, Java |
| Dijkstra | C++, Java |

## Approach 1: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n, numeric_limits<int>::max());
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (stops <= k && !q.empty()) {
            int sz = q.size();
            // Iterate on current level.
            while (sz--) {
                auto [node, distance] = q.front();
                q.pop();
                // Iterate over neighbors of popped node.
                for (auto& [neighbour, price] : adj[node]) {
                    if (price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        Map<Integer, List<int[]>> adj = new HashMap<>();
        for (int[] i : flights)
            adj.computeIfAbsent(i[0], value -> new ArrayList<>()).add(new int[] { i[1], i[2] });

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] { src, 0 });
        int stops = 0;

        while (stops <= k && !q.isEmpty()) {
            int sz = q.size();
            // Iterate on current level.
            while (sz-- > 0) {
                int[] temp = q.poll();
                int node = temp[0];
                int distance = temp[1];

                if (!adj.containsKey(node))
                    continue;
                // Loop over neighbors of popped node.
                for (int[] e : adj.get(node)) {
                    int neighbour = e[0];
                    int price = e[1];
                    if (price + distance >= dist[neighbour])
                        continue;
                    dist[neighbour] = price + distance;
                    q.offer(new int[] { neighbour, dist[neighbour] });
                }
            }
            stops++;
        }
        return dist[dst] == Integer.MAX_VALUE ? -1 : dist[dst];
    }
}
```

</details>

<br>

## Approach 2: Bellman Ford

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Distance from source to all other nodes.
        vector<int> dist(n, numeric_limits<int>::max());
        dist[src] = 0;

        // Run only K+1 times since we want shortest distance in K hops.
        for (int i = 0; i <= k; i++) {
            // Create a copy of dist vector.
            vector<int> temp(dist);
            for (auto& flight : flights) {
                if (dist[flight[0]] != numeric_limits<int>::max()) {
                    temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            // Copy the temp vector into dist.
            dist = temp;
        }
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        // Distance from source to all other nodes.
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        // Run only K+1 times since we want shortest distance in K hops
        for (int i = 0; i <= k; i++) {
            // Create a copy of dist vector.
            int[] temp = Arrays.copyOf(dist, n);
            for (int[] flight : flights) {
                if (dist[flight[0]] != Integer.MAX_VALUE) {
                    temp[flight[1]] = Math.min(temp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            // Copy the temp vector into dist.
            dist = temp;
        }
        return dist[dst] == Integer.MAX_VALUE ? -1 : dist[dst];
    }
};
```

</details>

<br>

## Approach 3: Dijkstra

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> stops(n, numeric_limits<int>::max());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {dist_from_src_node, node, number_of_stops_from_src_node}
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int dist = temp[0];
            int node = temp[1];
            int steps = temp[2];
            // We have already encountered a path with a lower cost and fewer stops,
            // or the number of stops exceeds the limit.
            if (steps >= stops[node] || steps > k + 1) continue;
            stops[node] = steps;
            if (node == dst) return dist;
            for (auto& [neighbor, price] : adj[node]) {
                pq.push({dist + price, neighbor, steps + 1});
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
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        Map<Integer, List<int[]>> adj = new HashMap<>();
        for (int[] i : flights)
            adj.computeIfAbsent(i[0], value -> new ArrayList<>()).add(new int[] { i[1], i[2] });

        int[] stops = new int[n];
        Arrays.fill(stops, Integer.MAX_VALUE);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        // {dist_from_src_node, node, number_of_stops_from_src_node}
        pq.offer(new int[] { 0, src, 0 });

        while (!pq.isEmpty()) {
            int[] temp = pq.poll();
            int dist = temp[0];
            int node = temp[1];
            int steps = temp[2];
            // We have already encountered a path with a lower cost and fewer stops,
            // or the number of stops exceeds the limit.
            if (steps >= stops[node] || steps > k + 1)
                continue;
            stops[node] = steps;
            if (node == dst)
                return dist;
            if (!adj.containsKey(node))
                continue;
            for (int[] a : adj.get(node)) {
                pq.offer(new int[] { dist + a[1], a[0], steps + 1 });
            }
        }
        return -1;
    }
}
```

</details>
