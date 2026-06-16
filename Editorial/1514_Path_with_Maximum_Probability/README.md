# 1514. Path with Maximum Probability

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/path-with-maximum-probability/)  
`Array` `Graph Theory` `Heap (Priority Queue)` `Shortest Path`

**Problem Link:** [LeetCode 1514 - Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/)

## Problem

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

### Example 1

```text
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
```

### Example 2

```text
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
```

### Example 3

```text
Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
```

## Constraints

- 2 <= n <= 10^4
- 0 <= start, end < n
- start != end
- 0 <= a, b < n
- a != b
- 0 <= succProb.length == edges.length <= 2*10^4
- 0 <= succProb[i] <= 1
- There is at most one edge between every two nodes.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1514. Path with Maximum Probability

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bellman-Ford Algorithm | C++, Java, Python3 |
| Shortest Path Faster Algorithm | C++, Java, Python3 |
| Dijkstra's Algorithm | C++, Java, Python3 |

## Approach 1: Bellman-Ford Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        vector<double> maxProb(n, 0);
        maxProb[start] = 1.0;

        for (int i = 0; i < n - 1; i++) {
            bool hasUpdate = false;
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double pathProb = succProb[j];
                if (maxProb[u] * pathProb > maxProb[v]) {
                    maxProb[v] = maxProb[u] * pathProb;
                    hasUpdate = true;
                }
                if (maxProb[v] * pathProb > maxProb[u]) {
                    maxProb[u] = maxProb[v] * pathProb;
                    hasUpdate = true;
                }
            }
            if (!hasUpdate) {
                break;
            }
        }

        return maxProb[end];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public double maxProbability(
        int n,
        int[][] edges,
        double[] succProb,
        int start,
        int end
    ) {
        double[] maxProb = new double[n];
        maxProb[start] = 1.0;

        for (int i = 0; i < n - 1; i++) {
            boolean hasUpdate = false;
            for (int j = 0; j < edges.length; j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double pathProb = succProb[j];
                if (maxProb[u] * pathProb > maxProb[v]) {
                    maxProb[v] = maxProb[u] * pathProb;
                    hasUpdate = true;
                }
                if (maxProb[v] * pathProb > maxProb[u]) {
                    maxProb[u] = maxProb[v] * pathProb;
                    hasUpdate = true;
                }
            }
            if (!hasUpdate) {
                break;
            }
        }

        return maxProb[end];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProbability(
        self,
        n: int,
        edges: List[List[int]],
        succProb: List[float],
        start: int,
        end: int,
    ) -> float:
        max_prob = [0] * n
        max_prob[start] = 1

        for i in range(n - 1):
            # If there is no larger probability found during an entire round of updates,
            # stop the update process.
            has_update = 0
            for j in range(len(edges)):
                u, v = edges[j]
                path_prob = succProb[j]
                if max_prob[u] * path_prob > max_prob[v]:
                    max_prob[v] = max_prob[u] * path_prob
                    has_update = 1
                if max_prob[v] * path_prob > max_prob[u]:
                    max_prob[u] = max_prob[v] * path_prob
                    has_update = 1
            if not has_update:
                break

        return max_prob[end]
```

</details>

<br>

## Approach 2: Shortest Path Faster Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];
            graph[u].push_back({v, pathProb});
            graph[v].push_back({u, pathProb});
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        queue<int> queue;
        queue.push(start);
        while (!queue.empty()) {
            int curNode = queue.front();
            queue.pop();
            for (const pair<int, double>& neighbor : graph[curNode]) {
                int nxtNode = neighbor.first;
                double pathProb = neighbor.second;

                // Only update maxProb[nxtNode] if the current path increases
                // the probability of reach nxtNode.
                if (maxProb[curNode] * pathProb > maxProb[nxtNode]) {
                    maxProb[nxtNode] = maxProb[curNode] * pathProb;
                    queue.push(nxtNode);
                }
            }
        }

        return maxProb[end];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public double maxProbability(
        int n,
        int[][] edges,
        double[] succProb,
        int start,
        int end
    ) {
        Map<Integer, List<Pair<Integer, Double>>> graph = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];
            graph
                .computeIfAbsent(u, k -> new ArrayList<>())
                .add(new Pair<>(v, pathProb));
            graph
                .computeIfAbsent(v, k -> new ArrayList<>())
                .add(new Pair<>(u, pathProb));
        }

        double[] maxProb = new double[n];
        maxProb[start] = 1d;

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        while (!queue.isEmpty()) {
            int curNode = queue.poll();
            for (Pair<Integer, Double> neighbor : graph.getOrDefault(
                curNode,
                new ArrayList<>()
            )) {
                int nxtNode = neighbor.getKey();
                double pathProb = neighbor.getValue();

                // Only update maxProb[nxtNode] if the current path increases
                // the probability of reach nxtNode.
                if (maxProb[curNode] * pathProb > maxProb[nxtNode]) {
                    maxProb[nxtNode] = maxProb[curNode] * pathProb;
                    queue.offer(nxtNode);
                }
            }
        }

        return maxProb[end];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProbability(
        self,
        n: int,
        edges: List[List[int]],
        succProb: List[float],
        start: int,
        end: int,
    ) -> float:
        graph = defaultdict(list)
        for i, (a, b) in enumerate(edges):
            graph[a].append([b, succProb[i]])
            graph[b].append([a, succProb[i]])

        max_prob = [0.0] * n
        max_prob[start] = 1.0

        queue = deque([start])
        while queue:
            cur_node = queue.popleft()
            for nxt_node, path_prob in graph[cur_node]:

                # Only update max_prob[nxt_node] if the current path increases
                # the probability of reach nxt_node.
                if max_prob[cur_node] * path_prob > max_prob[nxt_node]:
                    max_prob[nxt_node] = max_prob[cur_node] * path_prob
                    queue.append(nxt_node)

        return max_prob[end]
```

</details>

<br>

## Approach 3: Dijkstra's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<double, int>>> graph;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];
            graph[u].push_back({pathProb, v});
            graph[v].push_back({pathProb, u});
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        // please note that the priority queue in c++ is a max heap by default
        // and the sorting is decided by the first element of the pair.
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        while (!pq.empty()) {
            double curProb = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
            if (curNode == end) {
                return curProb;
            }
            if (!graph[curNode]
                     .empty()) {  // Check if the node has been processed
                for (auto& nxt : graph[curNode]) {
                    int nxtNode = nxt.second;
                    double pathProb = nxt.first;
                    if (curProb * pathProb > maxProb[nxtNode]) {
                        maxProb[nxtNode] = curProb * pathProb;
                        pq.push({maxProb[nxtNode], nxtNode});
                    }
                }
                graph[curNode]
                    .clear();  // Clear the adjacency list by removing the entry
            }
        }

        return 0.0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public double maxProbability(
        int n,
        int[][] edges,
        double[] succProb,
        int start,
        int end
    ) {
        Map<Integer, List<Pair<Integer, Double>>> graph = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];
            graph
                .computeIfAbsent(u, k -> new ArrayList<>())
                .add(new Pair<>(v, pathProb));
            graph
                .computeIfAbsent(v, k -> new ArrayList<>())
                .add(new Pair<>(u, pathProb));
        }

        double[] maxProb = new double[n];
        maxProb[start] = 1d;

        PriorityQueue<Pair<Double, Integer>> pq = new PriorityQueue<>((a, b) ->
            -Double.compare(a.getKey(), b.getKey())
        );
        pq.add(new Pair<>(1.0, start));
        while (!pq.isEmpty()) {
            Pair<Double, Integer> cur = pq.poll();
            double curProb = cur.getKey();
            int curNode = cur.getValue();
            if (curNode == end) {
                return curProb;
            }
            if (graph.containsKey(curNode)) { // Check if the node has been processed
                for (Pair<Integer, Double> nxt : graph.getOrDefault(
                    curNode,
                    new ArrayList<>()
                )) {
                    int nxtNode = nxt.getKey();
                    double pathProb = nxt.getValue();
                    if (curProb * pathProb > maxProb[nxtNode]) {
                        maxProb[nxtNode] = curProb * pathProb;
                        pq.add(new Pair<>(maxProb[nxtNode], nxtNode));
                    }
                }
                graph.remove(curNode); // Clear the adjacency list by removing the entry
            }
        }

        return 0d;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProbability(
        self,
        n: int,
        edges: List[List[int]],
        succProb: List[float],
        start: int,
        end: int,
    ) -> float:
        graph = defaultdict(list)
        for i, (u, v) in enumerate(edges):
            graph[u].append((v, succProb[i]))
            graph[v].append((u, succProb[i]))

        max_prob = [0.0] * n
        max_prob[start] = 1.0

        pq = [(-1.0, start)]
        while pq:
            cur_prob, cur_node = heapq.heappop(pq)
            if cur_node == end:
                return -cur_prob

            # Mark the node as processed by clearing its adjacency list
            if graph[cur_node]:  # Only clear if the list is not already empty
                for nxt_node, path_prob in graph[cur_node]:
                    if -cur_prob * path_prob > max_prob[nxt_node]:
                        max_prob[nxt_node] = -cur_prob * path_prob
                        heapq.heappush(pq, (-max_prob[nxt_node], nxt_node))
                graph[
                    cur_node
                ].clear()  # Clear the adjacency list after processing

        return 0.0
```

</details>
