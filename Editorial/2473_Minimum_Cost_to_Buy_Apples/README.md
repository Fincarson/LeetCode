# 2473. Minimum Cost to Buy Apples

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-cost-to-buy-apples/)  
`Array` `Graph Theory` `Heap (Priority Queue)` `Shortest Path`

**Problem Link:** [LeetCode 2473 - Minimum Cost to Buy Apples](https://leetcode.com/problems/minimum-cost-to-buy-apples/)

## Problem

You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads, where roads[i] = [ai, bi, costi] indicates that there is a bidirectional road between cities ai and bi with a cost of traveling equal to costi.

You can buy apples in any city you want, but some cities have different costs to buy apples. You are given the 1-based array appleCost where appleCost[i] is the cost of buying one apple from city i.

You start at some city, traverse through various roads, and eventually buy exactly one apple from any city. After you buy that apple, you have to return back to the city you started at, but now the cost of all the roads will be multiplied by a given factor k.

Given the integer k, return a 1-based array answer of size n where answer[i] is the minimum total cost to buy an apple if you start at city i.

### Example 1

```text
Input: n = 4, roads = [[1,2,4],[2,3,2],[2,4,5],[3,4,1],[1,3,4]], appleCost = [56,42,102,301], k = 2
Output: [54,42,48,51]
Explanation: The minimum cost for each starting city is the following:
- Starting at city 1: You take the path 1 -> 2, buy an apple at city 2, and finally take the path 2 -> 1. The total cost is 4 + 42 + 4 * 2 = 54.
- Starting at city 2: You directly buy an apple at city 2. The total cost is 42.
- Starting at city 3: You take the path 3 -> 2, buy an apple at city 2, and finally take the path 2 -> 3. The total cost is 2 + 42 + 2 * 2 = 48.
- Starting at city 4: You take the path 4 -> 3 -> 2 then you buy at city 2, and finally take the path 2 -> 3 -> 4. The total cost is 1 + 2 + 42 + 1 * 2 + 2 * 2 = 51.
```

### Example 2

```text
Input: n = 3, roads = [[1,2,5],[2,3,1],[3,1,2]], appleCost = [2,3,1], k = 3
Output: [2,3,1]
Explanation: It is always optimal to buy the apple in the starting city.
```

## Constraints

- 2 <= n <= 1000
- 1 <= roads.length <= 2000
- 1 <= ai, bi <= n
- ai != bi
- 1 <= costi <= 105
- appleCost.length == n
- 1 <= appleCost[i] <= 105
- 1 <= k <= 100
- There are no repeated edges.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2473. Minimum Cost to Buy Apples

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Shortest Path | C++, Java, Python3 |
| One Pass Shortest Path | C++, Java, Python3 |

## Approach 1: Shortest Path

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        // Store the graph as a list of lists
        // The rows represent the cities (vertices)
        // The columns store an adjacency list of road, cost pairs (edge, weight)
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());

        // Add each road to the graph using adjacency lists
        // Store each city at graph[city - 1]
        for (auto& road : roads) {
            int city_a = road[0] - 1, city_b = road[1] - 1, cost = road[2];
            graph[city_a].push_back({city_b, cost});
            graph[city_b].push_back({city_a, cost});
        }

        // Find the minimum cost to buy an apple starting in each city
        vector<long long> result(n);
        for (int startCity = 0; startCity < n; startCity++) {
            result[startCity] = shortestPath(startCity, graph, appleCost, k, n);
        }

        return result;
    }

private:
    // Finds the minimum cost to buy an apple from the start city
    long long shortestPath(int startCity, vector<vector<pair<int, int>>> graph,
                           vector<int>& appleCost, int k, int n) {
        // Stores the travel cost reach each city from the start city
        vector<int> travelCosts(n, INT_MAX);
        travelCosts[startCity] = 0;

        // Initialize the heap (priority queue) with the starting city
        // Each element of the heap is an array with the cost and city
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        heap.push({0, startCity});
        long long minCost = INT_MAX;

        while (!heap.empty()) {
            // Remove the city with the minimum cost from the top of the heap
            auto current = heap.top();
            heap.pop();
            int travelCost = current[0];
            int currCity = current[1];

            // Update the min cost if the curr city has a smaller total cost
            minCost = min(minCost, 
                    static_cast<long long>(appleCost[currCity]) + (k + 1) * travelCost);

            // Add each neighboring city to the heap if an apple is cheaper
            for (auto& [neighbor, cost] : graph[currCity]) {
                int nextCost = travelCost + cost;
                if (nextCost < travelCosts[neighbor]) {
                    travelCosts[neighbor] = nextCost;
                    heap.push({nextCost, neighbor});
                }
            }
        }
        return minCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long[] minCost(int n, int[][] roads, int[] appleCost, int k) {
        // Store the graph as a list of lists
        // The rows represent the cities (vertices)
        // The columns store an adjacency list of road, cost pairs (edge, weight)
        List<List<Pair<Integer, Integer>>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        // Add each road to the graph using adjacency lists
        // Store each city at graph[city - 1]
        for (int[] road : roads) {
            int cityA = road[0] - 1, cityB = road[1] - 1, cost = road[2];
            graph.get(cityA).add(new Pair<Integer, Integer>(cityB, cost));
            graph.get(cityB).add(new Pair<Integer, Integer>(cityA, cost));
        }

        // Find the minimum cost to buy an apple starting in each city
        long[] result = new long[n];
        for (int startCity = 0; startCity < n; startCity++) {
            result[startCity] = shortestPath(startCity, graph, appleCost, k, n);
        }

        return result;
    }

    // Finds the minimum cost to buy an apple from the start city
    private long shortestPath(int startCity, List<List<Pair<Integer, Integer>>> graph,
                              int[] appleCost, int k, int n) {
        // Stores the travel cost reach each city from the start city
        int[] travelCosts = new int[n];
        Arrays.fill(travelCosts, Integer.MAX_VALUE);
        travelCosts[startCity] = 0;

        // Initialize the heap (priority queue) with the starting city
        Queue<int[]> heap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        heap.offer(new int[] { 0, startCity });
        long minCost = Integer.MAX_VALUE;

        while (!heap.isEmpty()) {
            // Remove the city with the minimum cost from the top of the heap
            int[] current = heap.poll();
            int travelCost = current[0];
            int currCity = current[1];

            // Update the min cost if the curr city has a smaller total cost
            minCost = Math.min(minCost, 
                               (long) appleCost[currCity] + (k + 1) * travelCost);

            // Add each neighboring city to the heap if an apple is cheaper
            for (Pair<Integer, Integer> next : graph.get(currCity)) {
                int neighbor = next.getKey();
                int nextCost = travelCost + next.getValue();
                if (nextCost < travelCosts[neighbor]) {
                    travelCosts[neighbor] = nextCost;
                    heap.offer(new int[] { nextCost, neighbor });
                }
            }
        }
        return minCost;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(
        self, n: int, roads: List[List[int]], appleCost: List[int], k: int
    ) -> List[int]:
        # Store the graph as a list of lists
        # The rows represent the cities (vertices)
        # The columns store an adjacency list of road, cost pairs (edge, weight)
        graph = [[] for _ in range(n)]

        # Add each road to the graph using adjacency lists
        # Store each city at `graph[city - 1]`
        for city_a, city_b, cost in roads:
            graph[city_a - 1].append((city_b - 1, cost))
            graph[city_b - 1].append((city_a - 1, cost))

        # Finds the minimum cost to buy an apple from the start city
        def shortest_path(start_city, graph):
            # Stores the travel cost reach each city from the start city
            travel_costs = [float("inf") for _ in range(n)]
            travel_costs[start_city] = 0

            # Initialize the heap (priority queue) with the starting city
            # Each element of the heap is a tuple with the cost and city
            heap = [(0, start_city)]
            min_cost = float("inf")

            while heap:
                # Remove the city with the minimum cost from the top of the heap
                travel_cost, curr_city = heapq.heappop(heap)

                # Update the min cost if the curr city has a smaller total cost
                min_cost = min(min_cost, 
                               appleCost[curr_city] + (k + 1) * travel_cost)

                # Add each neighboring city to the heap if an apple is cheaper
                for neighbor, cost in graph[curr_city]:
                    next_cost = travel_cost + cost
                    if next_cost < travel_costs[neighbor]:
                        travel_costs[neighbor] = next_cost
                        heapq.heappush(heap, (next_cost, neighbor))

            return min_cost

        # Find the minimum cost to buy an apple starting in each city
        ans = []
        for start_city in range(0, n):
            ans.append(shortest_path(start_city, graph))

        return ans
```

</details>

<br>

## Approach 2: One Pass Shortest Path

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        // Store the graph as a list of lists
        // The rows represent the cities (vertices)
        // The columns store an adjacency list of road, cost pairs (edge, weight)
        vector<vector<pair<int, int>>> graph(n);
        
        // Add each road to the graph using adjacency lists
        // Store each city at `graph[city - 1]`
        for (auto& road : roads) {
            int city_a = road[0] - 1, city_b = road[1] - 1, cost = road[2];
            graph[city_a].push_back({city_b, cost});
            graph[city_b].push_back({city_a, cost});
        }

        // Store the cost to buy an apple in each city 
        // without traveling in the result
        vector<long long> result(appleCost.begin(), appleCost.end());
        
        // Initialize the heap (priority queue) with each starting city
        // Each element of the heap is a pair with the cost and city
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (int start_city = 0; start_city < appleCost.size(); start_city++) {
            heap.push({appleCost[start_city], start_city});
        }
        
        // Find the minimum cost to buy an apple starting in each city
        while (!heap.empty()) {
            auto [total_cost, curr_city] = heap.top();
            heap.pop();
            
            // If we have already found a path to buy an apple
            // for cheaper than the local apple cost, skip this city
            if (result[curr_city] < total_cost)
                continue;
            
            // Add each neighboring city to the heap if it is cheaper to
            // start there, travel to the current city and buy an apple 
            // than buy in the neighboring city
            for (auto [neighbor, cost] : graph[curr_city]) {
                if (result[neighbor] > result[curr_city] + (k + 1) * cost) {
                    result[neighbor] = result[curr_city] + (k + 1) * cost;
                    heap.push({result[neighbor], neighbor});
                }
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long[] minCost(int n, int[][] roads, int[] appleCost, int k) {
        // Store the graph as a list of lists
        // Each element of the outer list represents a city,
        // and each inner list contains pairs of neighboring city and its cost
        List<List<Pair<Integer, Integer>>> graph = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            graph.add(new ArrayList<>());
        }
        
        // Add each road to the graph using adjacency lists
        // Store each city at `graph[city - 1]`
        for (int[] road : roads) {
            int cityA = road[0] - 1, cityB = road[1] - 1, cost = road[2];
            graph.get(cityA).add(new Pair<Integer, Integer>(cityB, cost));
            graph.get(cityB).add(new Pair<Integer, Integer>(cityA, cost));
        }

        // Store the cost to buy an apple in each city 
        // without traveling in the result
        long[] result = new long[n];
        for (int startCity = 0; startCity < n; startCity++) {
            result[startCity] = appleCost[startCity];
        }
        
        // Initialize the min heap (priority queue) with each starting city
        // Each element of the heap is a pair with the cost and city
        Queue<Pair<Long, Integer>> heap = new PriorityQueue<>((a, b) -> 
                Long.compare(a.getKey(), b.getKey()));
        for (int startCity = 0; startCity < n; startCity++) {
            heap.add(new Pair<>((long)appleCost[startCity], startCity));
        }
        
        // Find the minimum cost to buy an apple starting in each city
        while (!heap.isEmpty()) {
            Pair<Long, Integer> current = heap.poll();
            long totalCost = current.getKey();
            int currCity = current.getValue();
            
            // If we have already found a path to buy an apple
            // for cheaper than the local apple cost, skip this city
            if (result[currCity] < totalCost)
                continue;
            
            // Add each neighboring city to the heap if it is cheaper to
            // start there, travel to the current city and buy an apple 
            // than buy in the neighboring city
            for (Pair<Integer, Integer> next : graph.get(currCity)) {
                int neighbor = next.getKey(), cost = next.getValue();
                if (result[neighbor] > result[currCity] + (k + 1) * cost) {
                    result[neighbor] = result[currCity] + (k + 1) * cost;
                    heap.add(new Pair<Long, Integer>(result[neighbor], neighbor));
                }
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(
        self, n: int, roads: List[List[int]], appleCost: List[int], k: int
    ) -> List[int]:
        # Store the graph as a list of lists
        # The rows represent the cities (vertices)
        # The columns store an adjacency list of road, cost pairs (edge, weight)
        graph = [[] for _ in range(n)]

        # Add each road to the graph using adjacency lists
        # Store each city at `graph[city - 1]`
        for city_a, city_b, cost in roads:
            graph[city_a - 1].append((city_b - 1, cost))
            graph[city_b - 1].append((city_a - 1, cost))

        # Store the cost to buy an apple in each city 
        # without traveling in the result
        result = list(appleCost)

        # Initialize the min heap (priority queue) with each starting city
        # Each element of the heap is a tuple with the cost and city
        heap = [(apple_cost, start_city) 
                 for start_city, apple_cost in enumerate(appleCost)]
        heapify(heap)

        # Find the minimum cost to buy an apple starting in each city
        while heap:
            # Remove the city with the minimum cost from the top of the heap
            total_cost, curr_city = heapq.heappop(heap)

            # If we have already found a path to buy an apple
            # for cheaper than the local apple cost, skip this city
            if result[curr_city] < total_cost:
                continue

            # Add each neighboring city to the heap if it is cheaper to
            # start there, travel to the current city and buy an apple 
            # than buy in the neighboring city
            for neighbor, cost in graph[curr_city]:
                if result[neighbor] > result[curr_city] + (k + 1) * cost:
                    result[neighbor] = result[curr_city] + (k + 1) * cost
                    heapq.heappush(heap, (result[neighbor], neighbor))

        return result
```

</details>
