# 2045. Second Minimum Time to Reach Destination

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/second-minimum-time-to-reach-destination/)  
`Breadth-First Search` `Graph Theory` `Shortest Path`

**Problem Link:** [LeetCode 2045 - Second Minimum Time to Reach Destination](https://leetcode.com/problems/second-minimum-time-to-reach-destination/)

## Problem

A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.

Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.

The second minimum value is defined as the smallest value strictly larger than the minimum value.

- For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.

Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.

Notes:

- You can go through any vertex any number of times, including 1 and n.
- You can assume that when the journey starts, all signals have just turned green.

### Example 1

```text
Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
Output: 13
Explanation:
The figure on the left shows the given graph.
The blue path in the figure on the right is the minimum time path.
The time taken is:
- Start at 1, time elapsed=0
- 1 -> 4: 3 minutes, time elapsed=3
- 4 -> 5: 3 minutes, time elapsed=6
Hence the minimum time needed is 6 minutes.

The red path shows the path to get the second minimum time.
- Start at 1, time elapsed=0
- 1 -> 3: 3 minutes, time elapsed=3
- 3 -> 4: 3 minutes, time elapsed=6
- Wait at 4 for 4 minutes, time elapsed=10
- 4 -> 5: 3 minutes, time elapsed=13
Hence the second minimum time is 13 minutes.
```

### Example 2

```text
Input: n = 2, edges = [[1,2]], time = 3, change = 2
Output: 11
Explanation:
The minimum time path is 1 -> 2 with time = 3 minutes.
The second minimum time path is 1 -> 2 -> 1 -> 2 with time = 11 minutes.
```

## Constraints

- 2 <= n <= 104
- n - 1 <= edges.length <= min(2 * 104, n * (n - 1) / 2)
- edges[i].length == 2
- 1 <= ui, vi <= n
- ui != vi
- There are no duplicate edges.
- Each vertex can be reached directly or indirectly from every other vertex.
- 1 <= time, change <= 103

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Network Delay Time](https://leetcode.com/problems/network-delay-time/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2045. Second Minimum Time to Reach Destination

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dijkstra | C++, Java, Python3 |
| Breadth First Search | C++, Java, Python3 |

## Approach 1: Dijkstra

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // dist1[i] stores the minimum time taken to reach node i from node 1.
        // dist2[i] stores the second minimum time taken to reach node from
        // node 1. freq[i] stores the number of times a node is popped out of
        // the heap.
        vector<int> dist1(n + 1, numeric_limits<int>::max()),
            dist2(n + 1, numeric_limits<int>::max()), freq(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            min_heap;
        min_heap.push({0, 1});
        dist1[1] = 0;

        while (!min_heap.empty()) {
            auto [timeTaken, node] = min_heap.top();
            min_heap.pop();

            freq[node]++;
            // If the node is being visited for the second time and is 'n',
            // return the answer.
            if (freq[node] == 2 && node == n) return timeTaken;
            // If the current light is red, wait till the path turns green.
            if ((timeTaken / change) % 2) {
                timeTaken = change * (timeTaken / change + 1) + time;
            } else {
                timeTaken = timeTaken + time;
            }

            for (auto& neighbor : adj[node]) {
                // Ignore nodes that have already popped out twice.
                if (freq[neighbor] == 2) continue;
                // Update dist1 if it's more than the current timeTaken and
                // store its value in dist2 since that becomes the second
                // minimum value now.
                if (dist1[neighbor] > timeTaken) {
                    dist2[neighbor] = dist1[neighbor];
                    dist1[neighbor] = timeTaken;
                    min_heap.push({timeTaken, neighbor});
                } else if (dist2[neighbor] > timeTaken &&
                           dist1[neighbor] != timeTaken) {
                    dist2[neighbor] = timeTaken;
                    min_heap.push({timeTaken, neighbor});
                }
            }
        }
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int secondMinimum(int n, int[][] edges, int time, int change) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }
        int[] dist1 = new int[n + 1], dist2 = new int[n + 1], freq = new int[n +
        1];
        // dist1[i] stores the minimum time taken to reach node i from node 1. dist2[i]
        // stores the second minimum time taken to reach node from node 1. freq[i] stores
        // the number of times a node is popped out of the heap.
        for (int i = 1; i <= n; i++) {
            dist1[i] = dist2[i] = Integer.MAX_VALUE;
            freq[i] = 0;
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (a[1] - b[1]));
        pq.offer(new int[] { 1, 0 });
        dist1[1] = 0;

        while (!pq.isEmpty()) {
            int[] temp = pq.poll();
            int node = temp[0];
            int time_taken = temp[1];

            freq[node]++;

            // If the node is being visited for the second time and is 'n', return the
            // answer.
            if (freq[node] == 2 && node == n) return time_taken;
            // If the current light is red, wait till the path turns green.
            if ((time_taken / change) % 2 == 1) time_taken = change *
                (time_taken / change + 1) +
            time;
            else time_taken = time_taken + time;

            if (!adj.containsKey(node)) continue;
            for (int neighbor : adj.get(node)) {
                // Ignore nodes that have already popped out twice, we are not interested in
                // visiting them again.
                if (freq[neighbor] == 2) continue;

                // Update dist1 if it's more than the current time_taken and store its value in
                // dist2 since that becomes the second minimum value now.
                if (dist1[neighbor] > time_taken) {
                    dist2[neighbor] = dist1[neighbor];
                    dist1[neighbor] = time_taken;
                    pq.offer(new int[] { neighbor, time_taken });
                } else if (
                    dist2[neighbor] > time_taken &&
                    dist1[neighbor] != time_taken
                ) {
                    dist2[neighbor] = time_taken;
                    pq.offer(new int[] { neighbor, time_taken });
                }
            }
        }
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import heapq


class Solution:
    def secondMinimum(
        self, n: int, edges: List[List[int]], time: int, change: int
    ) -> int:
        # prepare the graph adjacency list
        adj = [[] for _ in range(n + 1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        dist1 = [float("inf")] * (n + 1)
        dist2 = [float("inf")] * (n + 1)
        freq = [0] * (n + 1)
        queue = [(0, 1)]
        dist1[1] = 0

        while queue:
            timeTaken, node = heapq.heappop(queue)
            freq[node] += 1

            # If the node is being visited for the second time and is 'n', return the
            # answer.
            if freq[node] == 2 and node == n:
                return timeTaken
            # If the current light is red, wait till the path turns green.
            if (timeTaken // change) % 2:
                timeTaken = change * (timeTaken // change + 1) + time
            else:
                timeTaken = timeTaken + time

            for neighbor in adj[node]:
                # Ignore nodes that have already popped out twice, we are not interested in
                # visiting them again.
                if freq[neighbor] == 2:
                    continue

                # Update dist1 if it's more than the current timeTaken and store its value in
                # dist2 since that becomes the second minimum value now.
                if dist1[neighbor] > timeTaken:
                    dist2[neighbor] = dist1[neighbor]
                    dist1[neighbor] = timeTaken
                    heapq.heappush(queue, (timeTaken, neighbor))
                elif (
                    dist2[neighbor] > timeTaken and dist1[neighbor] != timeTaken
                ):
                    dist2[neighbor] = timeTaken
                    heapq.heappush(queue, (timeTaken, neighbor))
        return 0
```

</details>

<br>

## Approach 2: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        // Build the adjacency list.
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, int>> q;
        vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
        // Start with node 1, with its minimum distance.
        q.push({1, 1});
        dist1[1] = 0;

        while (!q.empty()) {
            auto [node, freq] = q.front();
            q.pop();

            int timeTaken = freq == 1 ? dist1[node] : dist2[node];
            // If the timeTaken falls under the red bracket, wait till the path
            // turns green.
            if ((timeTaken / change) % 2) {
                timeTaken = change * (timeTaken / change + 1) + time;
            } else {
                timeTaken = timeTaken + time;
            }

            for (auto& neighbor : adj[node]) {
                if (dist1[neighbor] == -1) {
                    dist1[neighbor] = timeTaken;
                    q.push({neighbor, 1});
                } else if (dist2[neighbor] == -1 &&
                           dist1[neighbor] != timeTaken) {
                    if (neighbor == n) return timeTaken;
                    dist2[neighbor] = timeTaken;
                    q.push({neighbor, 2});
                }
            }
        }
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int secondMinimum(int n, int[][] edges, int time, int change) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }
        int[] dist1 = new int[n + 1], dist2 = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            dist1[i] = dist2[i] = -1;
        }
        Queue<int[]> queue = new LinkedList<>();
        // Start with node 1, with its minimum distance.
        queue.offer(new int[] { 1, 1 });
        dist1[1] = 0;

        while (!queue.isEmpty()) {
            int[] temp = queue.poll();
            int node = temp[0];
            int freq = temp[1];

            int timeTaken = freq == 1 ? dist1[node] : dist2[node];
            // If the time_taken falls under the red bracket, wait till the path turns
            // green.
            if ((timeTaken / change) % 2 == 1) {
                timeTaken = change * (timeTaken / change + 1) + time;
            } else {
                timeTaken = timeTaken + time;
            }

            for (int neighbor : adj.get(node)) {
                if (dist1[neighbor] == -1) {
                    dist1[neighbor] = timeTaken;
                    queue.offer(new int[] { neighbor, 1 });
                } else if (
                    dist2[neighbor] == -1 && dist1[neighbor] != timeTaken
                ) {
                    if (neighbor == n) return timeTaken;
                    dist2[neighbor] = timeTaken;
                    queue.offer(new int[] { neighbor, 2 });
                }
            }
        }
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def secondMinimum(self, n, edges, time, change):
        from collections import defaultdict
        from collections import deque

        adj = defaultdict(list)
        for edge in edges:
            a, b = edge
            adj[a].append(b)
            adj[b].append(a)

        dist1, dist2 = [-1] * (n + 1), [-1] * (n + 1)
        queue = deque([(1, 1)])
        dist1[1] = 0

        while queue:
            node, freq = queue.popleft()
            timeTaken = dist1[node] if freq == 1 else dist2[node]

            if (timeTaken // change) % 2 == 1:
                timeTaken = change * (timeTaken // change + 1) + time
            else:
                timeTaken = timeTaken + time

            for neighbor in adj[node]:
                if dist1[neighbor] == -1:
                    dist1[neighbor] = timeTaken
                    queue.append((neighbor, 1))
                elif dist2[neighbor] == -1 and dist1[neighbor] != timeTaken:
                    if neighbor == n:
                        return timeTaken
                    dist2[neighbor] = timeTaken
                    queue.append((neighbor, 2))
        return 0
```

</details>
