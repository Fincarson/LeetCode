# 2093. Minimum Cost to Reach City With Discounts

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/)  
`Graph Theory` `Heap (Priority Queue)` `Shortest Path`

**Problem Link:** [LeetCode 2093 - Minimum Cost to Reach City With Discounts](https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/)

## Problem

A series of highways connect n cities numbered from 0 to n - 1. You are given a 2D integer array highways where highways[i] = [city1i, city2i, tolli] indicates that there is a highway that connects city1i and city2i, allowing a car to go from city1i to city2i and vice versa for a cost of tolli.

You are also given an integer discounts which represents the number of discounts you have. You can use a discount to travel across the ith highway for a cost of tolli / 2 (integer division). Each discount may only be used once, and you can only use at most one discount per highway.

Return the minimum total cost to go from city 0 to city n - 1, or -1 if it is not possible to go from city 0 to city n - 1.

### Example 1

```text
Input: n = 5, highways = [[0,1,4],[2,1,3],[1,4,11],[3,2,3],[3,4,2]], discounts = 1
Output: 9
Explanation:
Go from 0 to 1 for a cost of 4.
Go from 1 to 4 and use a discount for a cost of 11 / 2 = 5.
The minimum cost to go from 0 to 4 is 4 + 5 = 9.
```

### Example 2

```text
Input: n = 4, highways = [[1,3,17],[1,2,7],[3,2,5],[0,1,6],[3,0,20]], discounts = 20
Output: 8
Explanation:
Go from 0 to 1 and use a discount for a cost of 6 / 2 = 3.
Go from 1 to 2 and use a discount for a cost of 7 / 2 = 3.
Go from 2 to 3 and use a discount for a cost of 5 / 2 = 2.
The minimum cost to go from 0 to 3 is 3 + 3 + 2 = 8.
```

### Example 3

```text
Input: n = 4, highways = [[0,1,3],[2,3,2]], discounts = 0
Output: -1
Explanation:
It is impossible to go from 0 to 3 so return -1.
```

## Constraints

- 2 <= n <= 1000
- 1 <= highways.length <= 1000
- highways[i].length == 3
- 0 <= city1i, city2i <= n - 1
- city1i != city2i
- 0 <= tolli <= 105
- 0 <= discounts <= 500
- There are no duplicate highways.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Cost of Trip With K Highways](https://leetcode.com/problems/maximum-cost-of-trip-with-k-highways/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Cost to Reach Destination in Time](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2093. Minimum Cost to Reach City With Discounts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dijkstra's Algorithm using Priority Queue | C++, Java, Python3 |
| Space Optimized Dijkstra's Algorithm | C++, Java, Python3 |

## Approach 1: Dijkstra's Algorithm using Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        // construct the graph from the given highways array
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < highways.size(); ++i) {
            int u = highways[i][0], v = highways[i][1], toll = highways[i][2];
            graph[u].push_back({v, toll});
            graph[v].push_back({u, toll});
        }

        // Min-heap priority queue to store tuples of (cost, city,
        // discountsUsed)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.push(make_tuple(
            0, 0, 0));  // Start from city 0 with cost 0 and 0 discounts used

        // 2D array to track minimum distance to each city with a given number
        // of discounts used
        vector<vector<int>> dist(n, vector<int>(discounts + 1, INT_MAX));
        dist[0][0] = 0;

        vector<vector<bool>> visited(n, vector<bool>(discounts + 1, false));

        while (!pq.empty()) {
            int currentCost, city, discountsUsed;
            tie(currentCost, city, discountsUsed) = pq.top();
            pq.pop();

            // Skip processing if already visited with the same number of
            // discounts used
            if (visited[city][discountsUsed]) {
                continue;
            }
            visited[city][discountsUsed] = true;

            // Explore all neighbors of the current city
            for (int i = 0; i < graph[city].size(); ++i) {
                int neighbor = graph[city][i].first;
                int toll = graph[city][i].second;

                // Case 1: Move to the neighbor without using a discount
                if (currentCost + toll < dist[neighbor][discountsUsed]) {
                    dist[neighbor][discountsUsed] = currentCost + toll;
                    pq.push(make_tuple(dist[neighbor][discountsUsed], neighbor,
                                       discountsUsed));
                }

                // Case 2: Move to the neighbor using a discount if available
                if (discountsUsed < discounts) {
                    int newCostWithDiscount = currentCost + toll / 2;
                    if (newCostWithDiscount <
                        dist[neighbor][discountsUsed + 1]) {
                        dist[neighbor][discountsUsed + 1] = newCostWithDiscount;
                        pq.push(make_tuple(newCostWithDiscount, neighbor,
                                           discountsUsed + 1));
                    }
                }
            }
        }

        // Find the minimum cost to reach city n-1 with any number of discounts
        // used
        int minCost = *min_element(dist[n - 1].begin(), dist[n - 1].end());
        return minCost == INT_MAX ? -1 : minCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumCost(int n, int[][] highways, int discounts) {
        // Construct the graph from the given highways array
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            graph.add(new ArrayList<>());
        }
        for (int[] highway : highways) {
            int u = highway[0], v = highway[1], toll = highway[2];
            graph.get(u).add(new int[] { v, toll });
            graph.get(v).add(new int[] { u, toll });
        }

        // Min-heap priority queue to store tuples of (cost, city, discounts used)
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            Comparator.comparingInt(a -> a[0])
        );
        pq.offer(new int[] { 0, 0, 0 }); // Start from city 0 with cost 0 and 0 discounts used

        // 2D array to track minimum distance to each city with a given number of discounts used
        int[][] dist = new int[n][discounts + 1];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = 0;

        boolean[][] visited = new boolean[n][discounts + 1];

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int currentCost = current[0], city = current[1], discountsUsed =
                current[2];

            // Skip processing if already visited with the same number of discounts used
            if (visited[city][discountsUsed]) {
                continue;
            }
            visited[city][discountsUsed] = true;

            // Explore all neighbors of the current city
            for (int[] neighbor : graph.get(city)) {
                int nextCity = neighbor[0], toll = neighbor[1];

                // Case 1: Move to the neighbor without using a discount
                if (currentCost + toll < dist[nextCity][discountsUsed]) {
                    dist[nextCity][discountsUsed] = currentCost + toll;
                    pq.offer(
                        new int[] {
                            dist[nextCity][discountsUsed],
                            nextCity,
                            discountsUsed,
                        }
                    );
                }

                // Case 2: Move to the neighbor using a discount if available
                if (discountsUsed < discounts) {
                    int newCostWithDiscount = currentCost + toll / 2;
                    if (
                        newCostWithDiscount < dist[nextCity][discountsUsed + 1]
                    ) {
                        dist[nextCity][discountsUsed + 1] = newCostWithDiscount;
                        pq.offer(
                            new int[] {
                                newCostWithDiscount,
                                nextCity,
                                discountsUsed + 1,
                            }
                        );
                    }
                }
            }
        }

        // Find the minimum cost to reach city n-1 with any number of discounts used
        int minCost = Integer.MAX_VALUE;
        for (int d = 0; d <= discounts; ++d) {
            minCost = Math.min(minCost, dist[n - 1][d]);
        }
        return minCost == Integer.MAX_VALUE ? -1 : minCost;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumCost(
        self, n: int, highways: List[List[int]], discounts: int
    ) -> int:
        # Construct the graph from the given highways array
        graph = [[] for _ in range(n)]
        for highway in highways:
            u, v, toll = highway
            graph[u].append((v, toll))
            graph[v].append((u, toll))

        # Min-heap priority queue to store tuples of (cost, city, discounts used)
        pq = [(0, 0, 0)]  # Start from city 0 with cost 0 and 0 discounts used

        # 2D array to track minimum distance to each city with a given number of discounts used
        dist = [[float("inf")] * (discounts + 1) for _ in range(n)]
        dist[0][0] = 0

        visited = [[False] * (discounts + 1) for _ in range(n)]

        while pq:
            current_cost, city, discounts_used = heapq.heappop(pq)

            # Skip processing if already visited with the same number of discounts used
            if visited[city][discounts_used]:
                continue
            visited[city][discounts_used] = True

            # Explore all neighbors of the current city
            for neighbor, toll in graph[city]:

                # Case 1: Move to the neighbor without using a discount
                if current_cost + toll < dist[neighbor][discounts_used]:
                    dist[neighbor][discounts_used] = current_cost + toll
                    heapq.heappush(
                        pq,
                        (
                            dist[neighbor][discounts_used],
                            neighbor,
                            discounts_used,
                        ),
                    )

                # Case 2: Move to the neighbor using a discount if available
                if discounts_used < discounts:
                    new_cost_with_discount = current_cost + toll // 2
                    if (
                        new_cost_with_discount
                        < dist[neighbor][discounts_used + 1]
                    ):
                        dist[neighbor][
                            discounts_used + 1
                        ] = new_cost_with_discount
                        heapq.heappush(
                            pq,
                            (
                                new_cost_with_discount,
                                neighbor,
                                discounts_used + 1,
                            ),
                        )

        # Find the minimum cost to reach city n-1 with any number of discounts used
        min_cost = min(dist[n - 1])
        return -1 if min_cost == float("inf") else min_cost
```

</details>

<br>

## Approach 2: Space Optimized Dijkstra's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        // Construct the graph from the given highways array
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < highways.size(); ++i) {
            int u = highways[i][0], v = highways[i][1], toll = highways[i][2];
            graph[u].push_back({v, toll});
            graph[v].push_back({u, toll});
        }

        // Min-heap priority queue to store tuples of (cost, city, discounts
        // used)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.push(make_tuple(
            0, 0, 0));  // Start from city 0 with cost 0 and 0 discounts used

        // 2D array to track minimum distance to each city with a given number
        // of discounts used
        vector<vector<int>> dist(n, vector<int>(discounts + 1, INT_MAX));
        dist[0][0] = 0;

        while (!pq.empty()) {
            int currentCost, city, discountsUsed;
            tie(currentCost, city, discountsUsed) = pq.top();
            pq.pop();

            // If this cost is already higher than the known minimum, skip it
            if (currentCost > dist[city][discountsUsed]) {
                continue;
            }

            // Explore all neighbors of the current city
            for (int i = 0; i < graph[city].size(); ++i) {
                int neighbor = graph[city][i].first;
                int toll = graph[city][i].second;

                // Case 1: Move to the neighbor without using a discount
                if (currentCost + toll < dist[neighbor][discountsUsed]) {
                    dist[neighbor][discountsUsed] = currentCost + toll;
                    pq.push(make_tuple(dist[neighbor][discountsUsed], neighbor,
                                       discountsUsed));
                }

                // Case 2: Move to the neighbor using a discount if available
                if (discountsUsed < discounts) {
                    int newCostWithDiscount = currentCost + toll / 2;
                    if (newCostWithDiscount <
                        dist[neighbor][discountsUsed + 1]) {
                        dist[neighbor][discountsUsed + 1] = newCostWithDiscount;
                        pq.push(make_tuple(newCostWithDiscount, neighbor,
                                           discountsUsed + 1));
                    }
                }
            }
        }

        // Find the minimum cost to reach city n-1 with any number of discounts
        // used
        int minCost = *min_element(dist[n - 1].begin(), dist[n - 1].end());
        return minCost == INT_MAX ? -1 : minCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumCost(int n, int[][] highways, int discounts) {
        // Construct the graph from the given highways array
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            graph.add(new ArrayList<>());
        }
        for (int[] highway : highways) {
            int u = highway[0], v = highway[1], toll = highway[2];
            graph.get(u).add(new int[] { v, toll });
            graph.get(v).add(new int[] { u, toll });
        }

        // Min-heap priority queue to store tuples of (cost, city, discounts used)
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            Comparator.comparingInt(a -> a[0])
        );
        pq.offer(new int[] { 0, 0, 0 }); // Start from city 0 with cost 0 and 0 discounts used

        // 2D array to track minimum distance to each city with a given number of discounts used
        int[][] dist = new int[n][discounts + 1];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = 0;

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int currentCost = current[0], city = current[1], discountsUsed =
                current[2];

            // If this cost is already higher than the known minimum, skip it
            if (currentCost > dist[city][discountsUsed]) {
                continue;
            }

            // Explore all neighbors of the current city
            for (int[] neighbor : graph.get(city)) {
                int nextCity = neighbor[0], toll = neighbor[1];

                // Case 1: Move to the neighbor without using a discount
                if (currentCost + toll < dist[nextCity][discountsUsed]) {
                    dist[nextCity][discountsUsed] = currentCost + toll;
                    pq.offer(
                        new int[] {
                            dist[nextCity][discountsUsed],
                            nextCity,
                            discountsUsed,
                        }
                    );
                }

                // Case 2: Move to the neighbor using a discount if available
                if (discountsUsed < discounts) {
                    int newCostWithDiscount = currentCost + toll / 2;
                    if (
                        newCostWithDiscount < dist[nextCity][discountsUsed + 1]
                    ) {
                        dist[nextCity][discountsUsed + 1] = newCostWithDiscount;
                        pq.offer(
                            new int[] {
                                newCostWithDiscount,
                                nextCity,
                                discountsUsed + 1,
                            }
                        );
                    }
                }
            }
        }

        // Find the minimum cost to reach city n-1 with any number of discounts used
        int minCost = Integer.MAX_VALUE;
        for (int d = 0; d <= discounts; ++d) {
            minCost = Math.min(minCost, dist[n - 1][d]);
        }
        return minCost == Integer.MAX_VALUE ? -1 : minCost;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumCost(
        self, n: int, highways: List[List[int]], discounts: int
    ) -> int:
        # Construct the graph from the given highways array
        graph = [[] for _ in range(n)]
        for highway in highways:
            u, v, toll = highway
            graph[u].append((v, toll))
            graph[v].append((u, toll))

        # Min-heap priority queue to store tuples of (cost, city, discounts used)
        pq = [(0, 0, 0)]  # Start from city 0 with cost 0 and 0 discounts used

        # 2D array to track minimum distance to each city with a given number of discounts used
        dist = [[float("inf")] * (discounts + 1) for _ in range(n)]
        dist[0][0] = 0

        while pq:
            current_cost, city, discounts_used = heapq.heappop(pq)

            # If this cost is already higher than the known minimum, skip it
            if current_cost > dist[city][discounts_used]:
                continue

            # Explore all neighbors of the current city
            for neighbor, toll in graph[city]:
                # Case 1: Move to the neighbor without using a discount
                if current_cost + toll < dist[neighbor][discounts_used]:
                    dist[neighbor][discounts_used] = current_cost + toll
                    heapq.heappush(
                        pq,
                        (
                            dist[neighbor][discounts_used],
                            neighbor,
                            discounts_used,
                        ),
                    )

                # Case 2: Move to the neighbor using a discount if available
                if discounts_used < discounts:
                    new_cost_with_discount = current_cost + toll // 2
                    if (
                        new_cost_with_discount
                        < dist[neighbor][discounts_used + 1]
                    ):
                        dist[neighbor][
                            discounts_used + 1
                        ] = new_cost_with_discount
                        heapq.heappush(
                            pq,
                            (
                                new_cost_with_discount,
                                neighbor,
                                discounts_used + 1,
                            ),
                        )

        # Find the minimum cost to reach city n-1 with any number of discounts used
        min_cost = min(dist[n - 1])
        return -1 if min_cost == float("inf") else min_cost
```

</details>
