# 2737. Find the Closest Marked Node

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-closest-marked-node/)  
`Array` `Graph Theory` `Heap (Priority Queue)` `Shortest Path`

**Problem Link:** [LeetCode 2737 - Find the Closest Marked Node](https://leetcode.com/problems/find-the-closest-marked-node/)

## Problem

You are given a positive integer n which is the number of nodes of a 0-indexed directed weighted graph and a 0-indexed 2D array edges where edges[i] = [ui, vi, wi] indicates that there is an edge from node ui to node vi with weight wi.

You are also given a node s and a node array marked; your task is to find the minimum distance from s to any of the nodes in marked.

Return an integer denoting the minimum distance from s to any node in marked or -1 if there are no paths from s to any of the marked nodes.

### Example 1

```text
Input: n = 4, edges = [[0,1,1],[1,2,3],[2,3,2],[0,3,4]], s = 0, marked = [2,3]
Output: 4
Explanation: There is one path from node 0 (the green node) to node 2 (a red node), which is 0->1->2, and has a distance of 1 + 3 = 4.
There are two paths from node 0 to node 3 (a red node), which are 0->1->2->3 and 0->3, the first one has a distance of 1 + 3 + 2 = 6 and the second one has a distance of 4.
The minimum of them is 4.
```

### Example 2

```text
Input: n = 5, edges = [[0,1,2],[0,2,4],[1,3,1],[2,3,3],[3,4,2]], s = 1, marked = [0,4]
Output: 3
Explanation: There are no paths from node 1 (the green node) to node 0 (a red node).
There is one path from node 1 to node 4 (a red node), which is 1->3->4, and has a distance of 1 + 2 = 3.
So the answer is 3.
```

### Example 3

```text
Input: n = 4, edges = [[0,1,1],[1,2,3],[2,3,2]], s = 3, marked = [0,1]
Output: -1
Explanation: There are no paths from node 3 (the green node) to any of the marked nodes (the red nodes), so the answer is -1.
```

## Constraints

- 2 <= n <= 500
- 1 <= edges.length <= 104
- edges[i].length = 3
- 0 <= edges[i][0], edges[i][1] <= n - 1
- 1 <= edges[i][2] <= 106
- 1 <= marked.length <= n - 1
- 0 <= s, marked[i] <= n - 1
- s != marked[i]
- marked[i] != marked[j] for every i != j
- The graph might have repeated edges.
- The graph is generated such that it has no self-loops.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2737. Find the Closest Marked Node

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dijkstra's Algorithm | C++, Java, Python3 |
| BellmanÃ¢â‚¬â€œFord Algorithm | C++, Java, Python3 |
| Shortest Path Faster Algorithm (SPFA) | C++, Java, Python3 |

## Approach 1: Dijkstra's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s,
                        vector<int>& marked) {
        // Convert marked array to set for O(1) lookups
        unordered_set<int> markSet(marked.begin(), marked.end());

        // Build adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }

        // Initialize distance array with infinity values
        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        // Min heap prioritized by distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minHeap;
        minHeap.emplace(0, s);

        // Dijkstra's algorithm
        while (!minHeap.empty()) {
            auto [distance, node] = minHeap.top();
            minHeap.pop();

            // Found a marked node, return its distance
            if (markSet.count(node)) {
                return dist[node];
            }

            // Explore neighbors
            for (const auto& [nextNode, weight] : adj[node]) {
                int newDist = distance + weight;

                // If we found a shorter path, update and add to the priority
                // queue
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    minHeap.emplace(newDist, nextNode);
                }
            }
        }

        // No path found to any marked node
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDistance(
        int n,
        List<List<Integer>> edges,
        int s,
        int[] marked
    ) {
        // Convert marked array to set for O(1) lookups
        Set<Integer> markSet = new HashSet<>();
        for (int node : marked) {
            markSet.add(node);
        }

        // Build adjacency list representation of the graph
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (List<Integer> edge : edges) {
            adj.get(edge.get(0)).add(new int[] { edge.get(1), edge.get(2) });
        }

        // Initialize distance array with infinity values
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[s] = 0;

        // Min heap prioritized by distance
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );
        minHeap.offer(new int[] { 0, s });

        // Dijkstra's algorithm
        while (!minHeap.isEmpty()) {
            int[] current = minHeap.poll();
            int node = current[1];
            int distance = current[0];

            // Found a marked node, return its distance
            if (markSet.contains(node)) {
                return dist[node];
            }

            // Explore neighbors
            for (int[] edge : adj.get(node)) {
                int nextNode = edge[0];
                int weight = edge[1];
                int newDist = distance + weight;

                // If we found a shorter path, update and add to the priority queue
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    minHeap.offer(new int[] { newDist, nextNode });
                }
            }
        }

        // No path found to any marked node
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDistance(
        self, n: int, edges: list[list[int]], s: int, marked: list[int]
    ) -> int:
        # Convert marked array to set for O(1) lookups
        mark_set = set(marked)

        # Build adjacency list representation of the graph
        adj = defaultdict(list)
        for u, v, w in edges:
            adj[u].append((v, w))

        # Distance dictionary initialized only for `s`
        dist = {s: 0}

        # Min heap prioritized by distance
        min_heap = [(0, s)]

        # Dijkstra's algorithm
        while min_heap:
            distance, node = heapq.heappop(min_heap)

            # Found a marked node, return its distance
            if node in mark_set:
                return dist[node]

            # Explore neighbors
            for next_node, weight in adj[node]:
                new_dist = distance + weight

                # If we found a shorter path, update and add to the priority queue
                if new_dist < dist.get(next_node, float("inf")):
                    dist[next_node] = new_dist
                    heapq.heappush(min_heap, (new_dist, next_node))

        # No path found to any marked node
        return -1
```

</details>

<br>

## Approach 2: BellmanÃ¢â‚¬â€œFord Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s,
                        vector<int>& marked) {
        // Initialize distances array with maximum values
        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        // Bellman-Ford algorithm: relax edges n-1 times
        for (int iter = 0; iter < n - 1; iter++) {
            for (const auto& edge : edges) {
                int from = edge[0];
                int to = edge[1];
                int weight = edge[2];

                // Relaxation step: if we can improve the path to 'to' via
                // 'from'
                if (dist[from] != INT_MAX && dist[from] + weight < dist[to]) {
                    dist[to] = dist[from] + weight;
                }
            }
        }

        // Find minimum distance to any marked node
        int minDist = INT_MAX;
        for (int node : marked) {
            if (dist[node] < minDist) {
                minDist = dist[node];
            }
        }

        // Return -1 if no path exists, otherwise return the minimum distance
        return minDist == INT_MAX ? -1 : minDist;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDistance(
        int n,
        List<List<Integer>> edges,
        int s,
        int[] marked
    ) {
        // Initialize distances array with maximum values
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[s] = 0;

        // Bellman-Ford algorithm: relax edges n-1 times
        for (int iter = 0; iter < n - 1; iter++) {
            for (List<Integer> edge : edges) {
                int from = edge.get(0);
                int to = edge.get(1);
                int weight = edge.get(2);

                // Relaxation step: if we can improve the path to 'to' via 'from'
                if (
                    dist[from] != Integer.MAX_VALUE &&
                    dist[from] + weight < dist[to]
                ) {
                    dist[to] = dist[from] + weight;
                }
            }
        }

        // Find minimum distance to any marked node
        int minDist = Integer.MAX_VALUE;
        for (int node : marked) {
            if (dist[node] < minDist) {
                minDist = dist[node];
            }
        }

        // Return -1 if no path exists, otherwise return the minimum distance
        return minDist == Integer.MAX_VALUE ? -1 : minDist;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDistance(
        self, n: int, edges: list[list[int]], s: int, marked: list[int]
    ) -> int:
        # Initialize distances array with maximum values
        dist = [float("inf")] * n
        dist[s] = 0

        # Bellman-Ford algorithm: relax edges n-1 times
        for _ in range(n - 1):
            for from_node, to_node, weight in edges:
                # Relaxation step: if we can improve the path to 'to_node' via 'from_node'
                if (
                    dist[from_node] != float("inf")
                    and dist[from_node] + weight < dist[to_node]
                ):
                    dist[to_node] = dist[from_node] + weight

        # Find minimum distance to any marked node
        min_dist = min((dist[node] for node in marked), default=float("inf"))

        # Return -1 if no path exists, otherwise return the minimum distance
        return -1 if min_dist == float("inf") else min_dist
```

</details>

<br>

## Approach 3: Shortest Path Faster Algorithm (SPFA)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s,
                        vector<int>& marked) {
        // Adjacency list representation
        vector<vector<pair<int, int>>> graph(n);

        // Build the graph
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            graph[from].emplace_back(to, weight);
        }

        // Distance array
        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        queue<int> queue;
        queue.push(s);

        // Track nodes in queue
        vector<bool> inQueue(n, false);
        inQueue[s] = true;

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            inQueue[current] = false;

            // Explore neighbors
            for (const auto& [nextNode, weight] : graph[current]) {
                // Relaxation step
                if (dist[nextNode] > dist[current] + weight) {
                    dist[nextNode] = dist[current] + weight;

                    // Add to queue if not already in queue
                    if (!inQueue[nextNode]) {
                        queue.push(nextNode);
                        inQueue[nextNode] = true;
                    }
                }
            }
        }

        // Find minimum distance to any marked node
        int minDist = INT_MAX;
        for (int node : marked) {
            minDist = min(minDist, dist[node]);
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDistance(
        int n,
        List<List<Integer>> edges,
        int s,
        int[] marked
    ) {
        // Adjacency list representation
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        // Build the graph
        for (List<Integer> edge : edges) {
            int from = edge.get(0);
            int to = edge.get(1);
            int weight = edge.get(2);
            graph.get(from).add(new int[] { to, weight });
        }

        // Distance array
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[s] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(s);

        // Track nodes in queue
        boolean[] inQueue = new boolean[n];
        inQueue[s] = true;

        while (!queue.isEmpty()) {
            int current = queue.poll();
            inQueue[current] = false;

            // Explore neighbors
            for (int[] next : graph.get(current)) {
                int nextNode = next[0];
                int weight = next[1];

                // Relaxation step
                if (dist[nextNode] > dist[current] + weight) {
                    dist[nextNode] = dist[current] + weight;

                    // Add to queue if not already in queue
                    if (!inQueue[nextNode]) {
                        queue.offer(nextNode);
                        inQueue[nextNode] = true;
                    }
                }
            }
        }

        // Find minimum distance to any marked node
        int minDist = Integer.MAX_VALUE;
        for (int node : marked) {
            minDist = Math.min(minDist, dist[node]);
        }

        return minDist == Integer.MAX_VALUE ? -1 : minDist;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDistance(
        self, n: int, edges: list[list[int]], s: int, marked: list[int]
    ) -> int:
        # Adjacency list representation
        graph = defaultdict(list)

        # Build the graph
        for from_node, to_node, weight in edges:
            graph[from_node].append((to_node, weight))

        # Distance array
        dist = [float("inf")] * n
        dist[s] = 0

        queue = deque([s])

        # Track nodes in queue
        in_queue = [False] * n
        in_queue[s] = True

        while queue:
            current = queue.popleft()
            in_queue[current] = False

            # Explore neighbors
            for next_node, weight in graph[current]:
                # Relaxation step
                if dist[next_node] > dist[current] + weight:
                    dist[next_node] = dist[current] + weight

                    # Add to queue if not already in queue
                    if not in_queue[next_node]:
                        queue.append(next_node)
                        in_queue[next_node] = True

        # Find minimum distance to any marked node
        min_dist = min((dist[node] for node in marked), default=float("inf"))

        return -1 if min_dist == float("inf") else min_dist
```

</details>
