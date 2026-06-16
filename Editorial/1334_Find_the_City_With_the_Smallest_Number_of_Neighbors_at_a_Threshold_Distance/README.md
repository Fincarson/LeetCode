# 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)  
`Dynamic Programming` `Graph Theory` `Shortest Path`

**Problem Link:** [LeetCode 1334 - Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)

## Problem

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

### Example 1

```text
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph.
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2]
City 1 -> [City 0, City 2, City 3]
City 2 -> [City 0, City 1, City 3]
City 3 -> [City 1, City 2]
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
```

### Example 2

```text
Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph.
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1]
City 1 -> [City 0, City 4]
City 2 -> [City 3, City 4]
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3]
The city 0 has 1 neighboring city at a distanceThreshold = 2.
```

## Constraints

- 2 <= n <= 100
- 1 <= edges.length <= n * (n - 1) / 2
- edges[i].length == 3
- 0 <= fromi < toi < n
- 1 <= weighti, distanceThreshold <= 10^4
- All pairs (fromi, toi) are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Second Minimum Time to Reach Destination](https://leetcode.com/problems/second-minimum-time-to-reach-destination/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dijkstra Algorithm | C++, Java, Python3 |
| Bellman-Ford Algorithm | C++, Java, Python3 |
| Shortest Path First Algorithm (SPFA) | C++, Java, Python3 |
| Floyd-Warshall Algorithm | C++, Java, Python3 |

## Approach 1: Dijkstra Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Adjacency list to store the graph
        vector<vector<pair<int, int>>> adjacencyList(n);
        // Matrix to store shortest path distances from each city
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        // Initialize adjacency list and shortest path matrix
        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        // Populate the adjacency list with edges
        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adjacencyList[start].emplace_back(end, weight);
            adjacencyList[end].emplace_back(start,
                                            weight);  // For undirected graph
        }

        // Compute shortest paths from each city using Dijkstra's algorithm
        for (int i = 0; i < n; i++) {
            dijkstra(n, adjacencyList, shortestPathMatrix[i], i);
        }

        // Find the city with the fewest number of reachable cities within the
        // distance threshold
        return getCityWithFewestReachable(n, shortestPathMatrix,
                                          distanceThreshold);
    }

    // Dijkstra's algorithm to find shortest paths from a source city
    void dijkstra(int n, const vector<vector<pair<int, int>>>& adjacencyList,
                  vector<int>& shortestPathDistances, int source) {
        // Priority queue to process nodes with the smallest distance first
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            priorityQueue;
        priorityQueue.emplace(0, source);
        fill(shortestPathDistances.begin(), shortestPathDistances.end(),
             INT_MAX);
        shortestPathDistances[source] = 0;  // Distance to source itself is zero

        // Process nodes in priority order
        while (!priorityQueue.empty()) {
            auto [currentDistance, currentCity] = priorityQueue.top();
            priorityQueue.pop();
            if (currentDistance > shortestPathDistances[currentCity]) {
                continue;
            }

            // Update distances to neighboring cities
            for (const auto& [neighborCity, edgeWeight] :
                 adjacencyList[currentCity]) {
                if (shortestPathDistances[neighborCity] >
                    currentDistance + edgeWeight) {
                    shortestPathDistances[neighborCity] =
                        currentDistance + edgeWeight;
                    priorityQueue.emplace(shortestPathDistances[neighborCity],
                                          neighborCity);
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the
    // distance threshold
    int getCityWithFewestReachable(
        int n, const vector<vector<int>>& shortestPathMatrix,
        int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for
        // each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }  // Skip self
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // Adjacency list to store the graph
        List<int[]>[] adjacencyList = new List[n];
        // Matrix to store shortest path distances from each city
        int[][] shortestPathMatrix = new int[n][n];

        // Initialize adjacency list and shortest path matrix
        for (int i = 0; i < n; i++) {
            Arrays.fill(shortestPathMatrix[i], Integer.MAX_VALUE); // Set all distances to infinity
            shortestPathMatrix[i][i] = 0; // Distance to itself is zero
            adjacencyList[i] = new ArrayList<>();
        }

        // Populate the adjacency list with edges
        for (int[] edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adjacencyList[start].add(new int[] { end, weight });
            adjacencyList[end].add(new int[] { start, weight }); // For undirected graph
        }

        // Compute shortest paths from each city using Dijkstra's algorithm
        for (int i = 0; i < n; i++) {
            dijkstra(n, adjacencyList, shortestPathMatrix[i], i);
        }

        // Find the city with the fewest number of reachable cities within the distance threshold
        return getCityWithFewestReachable(
            n,
            shortestPathMatrix,
            distanceThreshold
        );
    }

    // Dijkstra's algorithm to find shortest paths from a source city
    void dijkstra(
        int n,
        List<int[]>[] adjacencyList,
        int[] shortestPathDistances,
        int source
    ) {
        // Priority queue to process nodes with the smallest distance first
        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>((a, b) ->
            (a[1] - b[1])
        );
        priorityQueue.add(new int[] { source, 0 });
        Arrays.fill(shortestPathDistances, Integer.MAX_VALUE); // Set all distances to infinity
        shortestPathDistances[source] = 0; // Distance to source itself is zero

        // Process nodes in priority order
        while (!priorityQueue.isEmpty()) {
            int[] current = priorityQueue.remove();
            int currentCity = current[0];
            int currentDistance = current[1];
            if (currentDistance > shortestPathDistances[currentCity]) {
                continue;
            }

            // Update distances to neighboring cities
            for (int[] neighbor : adjacencyList[currentCity]) {
                int neighborCity = neighbor[0];
                int edgeWeight = neighbor[1];
                if (
                    shortestPathDistances[neighborCity] >
                    currentDistance + edgeWeight
                ) {
                    shortestPathDistances[neighborCity] = currentDistance +
                    edgeWeight;
                    priorityQueue.add(
                        new int[] {
                            neighborCity,
                            shortestPathDistances[neighborCity],
                        }
                    );
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the distance threshold
    int getCityWithFewestReachable(
        int n,
        int[][] shortestPathMatrix,
        int distanceThreshold
    ) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                } // Skip self
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTheCity(
        self, n: int, edges: List[List[int]], distanceThreshold: int
    ) -> int:
        # Adjacency list to store the graph
        adjacency_list = [[] for _ in range(n)]

        # Matrix to store shortest path distances from each city
        shortest_path_matrix = [[float("inf")] * n for _ in range(n)]

        # Initialize adjacency list and shortest path matrix
        for i in range(n):
            shortest_path_matrix[i][i] = 0  # Distance to itself is zero

        # Populate the adjacency list with edges
        for start, end, weight in edges:
            adjacency_list[start].append((end, weight))
            adjacency_list[end].append((start, weight))  # For undirected graph

        # Compute shortest paths from each city using Dijkstra's algorithm
        for i in range(n):
            self.dijkstra(n, adjacency_list, shortest_path_matrix[i], i)

        # Find the city with the fewest number of reachable cities within the distance threshold
        return self.get_city_with_fewest_reachable(
            n, shortest_path_matrix, distanceThreshold
        )

    # Dijkstra's algorithm to find shortest paths from a source city
    def dijkstra(
        self,
        n: int,
        adjacency_list: List[List[tuple]],
        shortest_path_distances: List[int],
        source: int,
    ):
        # Priority queue to process nodes with the smallest distance first
        priority_queue = [(0, source)]
        shortest_path_distances[:] = [float("inf")] * n
        shortest_path_distances[source] = 0  # Distance to itself is zero

        # Process nodes in priority order
        while priority_queue:
            current_distance, current_city = heapq.heappop(priority_queue)
            if current_distance > shortest_path_distances[current_city]:
                continue

            # Update distances to neighboring cities
            for neighbor_city, edge_weight in adjacency_list[current_city]:
                if (
                    shortest_path_distances[neighbor_city]
                    > current_distance + edge_weight
                ):
                    shortest_path_distances[neighbor_city] = (
                        current_distance + edge_weight
                    )
                    heapq.heappush(
                        priority_queue,
                        (shortest_path_distances[neighbor_city], neighbor_city),
                    )

    # Determine the city with the fewest number of reachable cities within the distance threshold
    def get_city_with_fewest_reachable(
        self,
        n: int,
        shortest_path_matrix: List[List[int]],
        distance_threshold: int,
    ) -> int:
        city_with_fewest_reachable = -1
        fewest_reachable_count = n

        # Count number of cities reachable within the distance threshold for each city
        for i in range(n):
            reachable_count = sum(
                1
                for j in range(n)
                if i != j and shortest_path_matrix[i][j] <= distance_threshold
            )

            # Update the city with the fewest reachable cities
            if reachable_count <= fewest_reachable_count:
                fewest_reachable_count = reachable_count
                city_with_fewest_reachable = i
        return city_with_fewest_reachable
```

</details>

<br>

## Approach 2: Bellman-Ford Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Large value to represent infinity
    const int INF = 1e9 + 7;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Matrix to store shortest path distances from each city
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INF));

        // Compute shortest paths from each city using Bellman-Ford algorithm
        for (int i = 0; i < n; i++) {
            bellmanFord(n, edges, shortestPathMatrix[i], i);
        }

        // Find the city with the fewest number of reachable cities within the
        // distance threshold
        return getCityWithFewestReachable(n, shortestPathMatrix,
                                          distanceThreshold);
    }

private:
    // Bellman-Ford algorithm to find shortest paths from a source city
    void bellmanFord(int n, const vector<vector<int>>& edges,
                     vector<int>& shortestPathDistances, int source) {
        // Initialize distances from the source
        fill(shortestPathDistances.begin(), shortestPathDistances.end(), INF);
        shortestPathDistances[source] = 0;  // Distance to source itself is zero

        // Relax edges up to n-1 times
        for (int i = 1; i < n; i++) {
            for (const auto& edge : edges) {
                int start = edge[0];
                int end = edge[1];
                int weight = edge[2];
                // Update shortest path distances if a shorter path is found
                if (shortestPathDistances[start] != INF &&
                    shortestPathDistances[start] + weight <
                        shortestPathDistances[end]) {
                    shortestPathDistances[end] =
                        shortestPathDistances[start] + weight;
                }
                if (shortestPathDistances[end] != INF &&
                    shortestPathDistances[end] + weight <
                        shortestPathDistances[start]) {
                    shortestPathDistances[start] =
                        shortestPathDistances[end] + weight;
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the
    // distance threshold
    int getCityWithFewestReachable(
        int n, const vector<vector<int>>& shortestPathMatrix,
        int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for
        // each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }  // Skip self
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // Large value to represent infinity
        int INF = (int) 1e9 + 7;
        // Matrix to store shortest path distances from each city
        int[][] shortestPathMatrix = new int[n][n];

        // Compute shortest paths from each city using Bellman-Ford algorithm
        for (int i = 0; i < n; i++) {
            bellmanFord(n, edges, shortestPathMatrix[i], i);
        }

        // Find the city with the fewest number of reachable cities within the distance threshold
        return getCityWithFewestReachable(
            n,
            shortestPathMatrix,
            distanceThreshold
        );
    }

    // Bellman-Ford algorithm to find shortest paths from a source city
    void bellmanFord(
        int n,
        int[][] edges,
        int[] shortestPathDistances,
        int source
    ) {
        // Initialize distances from the source
        Arrays.fill(shortestPathDistances, Integer.MAX_VALUE);
        shortestPathDistances[source] = 0; // Distance to source itself is zero

        // Relax edges up to n-1 times
        for (int i = 1; i < n; i++) {
            for (int[] edge : edges) {
                int start = edge[0];
                int end = edge[1];
                int weight = edge[2];
                // Update shortest path distances if a shorter path is found
                if (
                    shortestPathDistances[start] != Integer.MAX_VALUE &&
                    shortestPathDistances[start] + weight <
                    shortestPathDistances[end]
                ) {
                    shortestPathDistances[end] = shortestPathDistances[start] +
                    weight;
                }
                if (
                    shortestPathDistances[end] != Integer.MAX_VALUE &&
                    shortestPathDistances[end] + weight <
                    shortestPathDistances[start]
                ) {
                    shortestPathDistances[start] = shortestPathDistances[end] +
                    weight;
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the distance threshold
    int getCityWithFewestReachable(
        int n,
        int[][] shortestPathMatrix,
        int distanceThreshold
    ) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                } // Skip self
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTheCity(
        self, n: int, edges: List[List[int]], distanceThreshold: int
    ) -> int:
        # Large value to represent infinity
        INF = int(1e9) + 7
        # Matrix to store shortest path distances from each city
        shortestPathMatrix = [[INF] * n for _ in range(n)]

        # Compute shortest paths from each city using Bellman-Ford algorithm
        for i in range(n):
            self.bellmanFord(n, edges, shortestPathMatrix[i], i)

        # Find the city with the fewest number of reachable cities within the distance threshold
        return self.getCityWithFewestReachable(
            n, shortestPathMatrix, distanceThreshold
        )

    # Bellman-Ford algorithm to find shortest paths from a source city
    def bellmanFord(
        self,
        n: int,
        edges: List[List[int]],
        shortestPathDistances: List[int],
        source: int,
    ) -> None:
        # Initialize distances from the source
        shortestPathDistances[:] = [float("inf")] * n
        shortestPathDistances[source] = 0  # Distance to source itself is zero

        # Relax edges up to n-1 times with early stopping
        for _ in range(n - 1):
            updated = False
            for start, end, weight in edges:
                if (
                    shortestPathDistances[start] != float("inf")
                    and shortestPathDistances[start] + weight
                    < shortestPathDistances[end]
                ):
                    shortestPathDistances[end] = (
                        shortestPathDistances[start] + weight
                    )
                    updated = True
                if (
                    shortestPathDistances[end] != float("inf")
                    and shortestPathDistances[end] + weight
                    < shortestPathDistances[start]
                ):
                    shortestPathDistances[start] = (
                        shortestPathDistances[end] + weight
                    )
                    updated = True
            if not updated:
                break  # Stop early if no updates

    # Determine the city with the fewest number of reachable cities within the distance threshold
    def getCityWithFewestReachable(
        self,
        n: int,
        shortestPathMatrix: List[List[int]],
        distanceThreshold: int,
    ) -> int:
        cityWithFewestReachable = -1
        fewestReachableCount = n

        # Count number of cities reachable within the distance threshold for each city
        for i in range(n):
            reachableCount = 0
            for j in range(n):
                if i == j:
                    continue  # Skip self
                if shortestPathMatrix[i][j] <= distanceThreshold:
                    reachableCount += 1

            # Update the city with the fewest reachable cities
            if reachableCount <= fewestReachableCount:
                fewestReachableCount = reachableCount
                cityWithFewestReachable = i
        return cityWithFewestReachable
```

</details>

<br>

## Approach 3: Shortest Path First Algorithm (SPFA)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Adjacency list to store the graph
        vector<vector<pair<int, int>>> adjacencyList(n);
        // Matrix to store shortest path distances from each city
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        // Initialize adjacency list and shortest path matrix
        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        // Populate the adjacency list with edges
        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adjacencyList[start].emplace_back(end, weight);
            adjacencyList[end].emplace_back(start,
                                            weight);  // For undirected graph
        }

        // Compute shortest paths from each city using SPFA algorithm
        for (int i = 0; i < n; i++) {
            spfa(n, adjacencyList, shortestPathMatrix[i], i);
        }

        // Find the city with the fewest number of reachable cities within the
        // distance threshold
        return getCityWithFewestReachable(n, shortestPathMatrix,
                                          distanceThreshold);
    }

    // SPFA algorithm to find shortest paths from a source city
    void spfa(int n, const vector<vector<pair<int, int>>>& adjacencyList,
              vector<int>& shortestPathDistances, int source) {
        // Queue to process nodes with updated shortest path distances
        deque<int> queue;
        vector<int> updateCount(n, 0);
        queue.push_back(source);
        fill(shortestPathDistances.begin(), shortestPathDistances.end(),
             INT_MAX);
        shortestPathDistances[source] = 0;  // Distance to source itself is zero

        // Process nodes in queue
        while (!queue.empty()) {
            int currentCity = queue.front();
            queue.pop_front();
            for (const auto& [neighborCity, edgeWeight] :
                 adjacencyList[currentCity]) {
                if (shortestPathDistances[neighborCity] >
                    shortestPathDistances[currentCity] + edgeWeight) {
                    shortestPathDistances[neighborCity] =
                        shortestPathDistances[currentCity] + edgeWeight;
                    updateCount[neighborCity]++;
                    queue.push_back(neighborCity);

                    // Detect negative weight cycles (not expected in this
                    // problem)
                    if (updateCount[neighborCity] > n) {
                        cerr << "Negative weight cycle detected" << endl;
                    }
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the
    // distance threshold
    int getCityWithFewestReachable(
        int n, const vector<vector<int>>& shortestPathMatrix,
        int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for
        // each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }  // Skip self
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // Adjacency list to store the graph
        List<int[]>[] adjacencyList = new List[n];
        // Matrix to store shortest path distances from each city
        int[][] shortestPathMatrix = new int[n][n];

        // Initialize adjacency list and shortest path matrix
        for (int i = 0; i < n; i++) {
            adjacencyList[i] = new ArrayList<>();
        }

        // Populate the adjacency list with edges
        for (int[] edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adjacencyList[start].add(new int[] { end, weight });
            adjacencyList[end].add(new int[] { start, weight }); // For undirected graph
        }

        // Compute shortest paths from each city using SPFA algorithm
        for (int i = 0; i < n; i++) {
            spfa(n, adjacencyList, shortestPathMatrix[i], i);
        }

        // Find the city with the fewest number of reachable cities within the distance threshold
        return getCityWithFewestReachable(
            n,
            shortestPathMatrix,
            distanceThreshold
        );
    }

    // SPFA algorithm to find shortest paths from a source city
    void spfa(
        int n,
        List<int[]>[] adjacencyList,
        int[] shortestPathDistances,
        int source
    ) {
        // Queue to process nodes with updated shortest path distances
        Deque<Integer> queue = new ArrayDeque<>();
        // Array to track the number of updates for each node
        int[] updateCount = new int[n];
        queue.add(source);
        Arrays.fill(shortestPathDistances, Integer.MAX_VALUE); // Set all distances to infinity
        shortestPathDistances[source] = 0; // Distance to source itself is zero

        // Process nodes in queue
        while (!queue.isEmpty()) {
            int currentCity = queue.removeFirst();
            for (int[] neighbor : adjacencyList[currentCity]) {
                int neighborCity = neighbor[0];
                int edgeWeight = neighbor[1];

                // Update shortest path distance if a shorter path is found
                if (
                    shortestPathDistances[neighborCity] >
                    shortestPathDistances[currentCity] + edgeWeight
                ) {
                    shortestPathDistances[neighborCity] =
                        shortestPathDistances[currentCity] + edgeWeight;
                    updateCount[neighborCity]++;
                    queue.add(neighborCity);

                    // Detect negative weight cycles (not expected in this problem)
                    if (updateCount[neighborCity] > n) {
                        System.out.println("Negative weight cycle detected");
                    }
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the distance threshold
    int getCityWithFewestReachable(
        int n,
        int[][] shortestPathMatrix,
        int distanceThreshold
    ) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                } // Skip self
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTheCity(
        self, n: int, edges: List[List[int]], distanceThreshold: int
    ) -> int:
        # Adjacency list to store the graph
        adjacency_list = [[] for _ in range(n)]
        # Matrix to store shortest path distances from each city
        shortest_path_matrix = [[float("inf")] * n for _ in range(n)]

        # Initialize adjacency list and shortest path matrix
        for i in range(n):
            shortest_path_matrix[i][i] = 0  # Dist to itself is zero

        # Populate the adjacency list with edges
        for start, end, weight in edges:
            adjacency_list[start].append((end, weight))
            adjacency_list[end].append((start, weight))  # For undirected

        # Compute shortest paths from each city using SPFA algorithm
        for i in range(n):
            self.spfa(n, adjacency_list, shortest_path_matrix[i], i)

        # Find the city with the fewest number of reachable cities within the distance threshold
        return self.get_city_with_fewest_reachable(
            n, shortest_path_matrix, distanceThreshold
        )

    # SPFA algorithm to find shortest paths from a source city
    def spfa(
        self,
        n: int,
        adjacency_list: List[List[tuple]],
        shortest_path_distances: List[int],
        source: int,
    ):
        # Queue to process nodes with updated shortest path distances
        queue = deque([source])
        update_count = [0] * n
        shortest_path_distances[:] = [float("inf")] * n
        shortest_path_distances[source] = 0  # Dist to source itself is zero

        # Process nodes in queue
        while queue:
            current_city = queue.popleft()
            for neighbor_city, edge_weight in adjacency_list[current_city]:
                if (
                    shortest_path_distances[neighbor_city]
                    > shortest_path_distances[current_city] + edge_weight
                ):
                    shortest_path_distances[neighbor_city] = (
                        shortest_path_distances[current_city] + edge_weight
                    )
                    update_count[neighbor_city] += 1
                    queue.append(neighbor_city)

                    # Detect negative weight cycles (not expected in this problem)

                    if update_count[neighbor_city] > n:
                        print("Negative weight cycle detected")

    # Determine the city with the fewest number of reachable cities within the distance threshold
    def get_city_with_fewest_reachable(
        self,
        n: int,
        shortest_path_matrix: List[List[int]],
        distance_threshold: int,
    ) -> int:
        city_with_fewest_reachable = -1
        fewest_reachable_count = n
        # Count number of cities reachable within the distance threshold for each city
        for i in range(n):
            reachable_count = sum(
                1
                for j in range(n)
                if i != j and shortest_path_matrix[i][j] <= distance_threshold
            )
            # Update the city with the fewest reachable cities
            if reachable_count <= fewest_reachable_count:
                fewest_reachable_count = reachable_count
                city_with_fewest_reachable = i

        return city_with_fewest_reachable
```

</details>

<br>

## Approach 4: Floyd-Warshall Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Large value to represent infinity
        const int INF = 1e9 + 7;
        // Distance matrix to store shortest paths between all pairs of cities
        vector<vector<int>> distanceMatrix(n, vector<int>(n, INF));

        // Initialize distance matrix
        for (int i = 0; i < n; i++) {
            distanceMatrix[i][i] = 0;  // Distance to itself is zero
        }

        // Populate the distance matrix with initial edge weights
        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            distanceMatrix[start][end] = weight;
            distanceMatrix[end][start] = weight;  // For undirected graph
        }

        // Compute shortest paths using Floyd-Warshall algorithm
        floyd(n, distanceMatrix);

        // Find the city with the fewest number of reachable cities within the
        // distance threshold
        return getCityWithFewestReachable(n, distanceMatrix, distanceThreshold);
    }

    // Floyd-Warshall algorithm to compute shortest paths between all pairs of
    // cities
    void floyd(int n, vector<vector<int>>& distanceMatrix) {
        // Update distances for each intermediate city
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Update shortest path from i to j through k
                    distanceMatrix[i][j] =
                        min(distanceMatrix[i][j],
                            distanceMatrix[i][k] + distanceMatrix[k][j]);
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the
    // distance threshold
    int getCityWithFewestReachable(int n,
                                   const vector<vector<int>>& distanceMatrix,
                                   int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for
        // each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }  // Skip self
                if (distanceMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // Large value to represent infinity
        int INF = (int) 1e9 + 7;
        // Distance matrix to store shortest paths between all pairs of cities
        int[][] distanceMatrix = new int[n][n];

        // Initialize distance matrix
        for (int i = 0; i < n; i++) {
            Arrays.fill(distanceMatrix[i], INF); // Set all distances to infinity
            distanceMatrix[i][i] = 0; // Distance to itself is zero
        }

        // Populate the distance matrix with initial edge weights
        for (int[] edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            distanceMatrix[start][end] = weight;
            distanceMatrix[end][start] = weight; // For undirected graph
        }

        // Compute shortest paths using Floyd-Warshall algorithm
        floyd(n, distanceMatrix);

        // Find the city with the fewest number of reachable cities within the distance threshold
        return getCityWithFewestReachable(n, distanceMatrix, distanceThreshold);
    }

    // Floyd-Warshall algorithm to compute shortest paths between all pairs of cities
    void floyd(int n, int[][] distanceMatrix) {
        // Update distances for each intermediate city
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Update shortest path from i to j through k
                    distanceMatrix[i][j] = Math.min(
                        distanceMatrix[i][j],
                        distanceMatrix[i][k] + distanceMatrix[k][j]
                    );
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the distance threshold
    int getCityWithFewestReachable(
        int n,
        int[][] distanceMatrix,
        int distanceThreshold
    ) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                } // Skip self
                if (distanceMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTheCity(
        self, n: int, edges: List[List[int]], distanceThreshold: int
    ) -> int:
        # Large value to represent infinity
        INF = int(1e9 + 7)
        # Distance matrix to store shortest paths between all pairs of cities
        distance_matrix = [[INF] * n for _ in range(n)]

        # Initialize distance matrix
        for i in range(n):
            distance_matrix[i][i] = 0  # Distance to itself is zero

        # Populate the distance matrix with initial edge weights
        for start, end, weight in edges:
            distance_matrix[start][end] = weight
            distance_matrix[end][start] = weight  # For undirected graph

        # Compute shortest paths using Floyd-Warshall algorithm
        self.floyd(n, distance_matrix)

        # Find the city with the fewest number of reachable cities within the distance threshold
        return self.get_city_with_fewest_reachable(
            n, distance_matrix, distanceThreshold
        )

    # Floyd-Warshall algorithm to compute shortest paths between all pairs of cities
    def floyd(self, n: int, distance_matrix: List[List[int]]):
        # Update distances for each intermediate city

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    # Update shortest path from i to j through k
                    distance_matrix[i][j] = min(
                        distance_matrix[i][j],
                        distance_matrix[i][k] + distance_matrix[k][j],
                    )

    # Determine the city with the fewest number of reachable cities within the distance threshold
    def get_city_with_fewest_reachable(
        self, n: int, distance_matrix: List[List[int]], distance_threshold: int
    ) -> int:
        city_with_fewest_reachable = -1
        fewest_reachable_count = n

        # Count number of cities reachable within the distance threshold for each city
        for i in range(n):
            reachable_count = sum(
                1
                for j in range(n)
                if i != j and distance_matrix[i][j] <= distance_threshold
            )
            # Update the city with the fewest reachable cities
            if reachable_count <= fewest_reachable_count:
                fewest_reachable_count = reachable_count
                city_with_fewest_reachable = i
        return city_with_fewest_reachable
```

</details>
