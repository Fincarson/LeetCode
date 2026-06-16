# 882. Reachable Nodes In Subdivided Graph

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/)  
`Graph Theory` `Heap (Priority Queue)` `Shortest Path`

**Problem Link:** [LeetCode 882 - Reachable Nodes In Subdivided Graph](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/)

## Problem

You are given an undirected graph (the "original graph") with n nodes labeled from 0 to n - 1. You decide to subdivide each edge in the graph into a chain of nodes, with the number of new nodes varying between each edge.

The graph is given as a 2D array of edges where edges[i] = [ui, vi, cnti] indicates that there is an edge between nodes ui and vi in the original graph, and cnti is the total number of new nodes that you will subdivide the edge into. Note that cnti == 0 means you will not subdivide the edge.

To subdivide the edge [ui, vi], replace it with (cnti + 1) new edges and cnti new nodes. The new nodes are x1, x2, ..., xcnti, and the new edges are [ui, x1], [x1, x2], [x2, x3], ..., [xcnti-1, xcnti], [xcnti, vi].

In this new graph, you want to know how many nodes are reachable from the node 0, where a node is reachable if the distance is maxMoves or less.

Given the original graph and maxMoves, return the number of nodes that are reachable from node 0 in the new graph.

### Example 1

```text
Input: edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
Output: 13
Explanation: The edge subdivisions are shown in the image above.
The nodes that are reachable are highlighted in yellow.
```

### Example 2

```text
Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
Output: 23
```

### Example 3

```text
Input: edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
Output: 1
Explanation: Node 0 is disconnected from the rest of the graph, so only node 0 is reachable.
```

## Constraints

- 0 <= edges.length <= min(n * (n - 1) / 2, 104)
- edges[i].length == 3
- 0 <= ui < vi < n
- There are no multiple edges in the graph.
- 0 <= cnti <= 104
- 0 <= maxMoves <= 109
- 1 <= n <= 3000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find All People With Secret](https://leetcode.com/problems/find-all-people-with-secret/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Paths in Maze That Lead to Same Room](https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 882. Reachable Nodes In Subdivided Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dijkstra's | C++, Java, Python |

## Approach 1: Dijkstra's

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
#define pii pair<int, int>

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<vector<pii>> graph(N);
        for (vector<int> edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        map<int, int> dist;
        dist[0] = 0;
        for (int i = 1; i < N; ++i)
            dist[i] = M+1;

        map<pii, int> used;
        int ans = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();
            int d = top.first, node = top.second;
            if (d > dist[node]) continue;

            // Each node is only visited once.  We've reached
            // a node in our original graph.
            ans++;

            for (auto pair: graph[node]) {
                // M - d is how much further we can walk from this node;
                // weight is how many new nodes there are on this edge.
                // v is the maximum utilization of this edge.
                int nei = pair.first;
                int weight = pair.second;
                used[{node, nei}] = min(weight, M - d);

                // d2 is the total distance to reach 'nei' (neighbor) node
                // in the original graph.
                int d2 = d + weight + 1;
                if (d2 < min(dist[nei], M+1)) {
                    pq.push({d2, nei});
                    dist[nei] = d2;
                }
            }
        }

        // At the end, each edge (u, v, w) can be used with a maximum
        // of w new nodes: a max of used[u, v] nodes from one side,
        // and used[v, u] nodes from the other.
        for (vector<int> edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            ans += min(w, used[{u, v}] + used[{v, u}]);
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int reachableNodes(int[][] edges, int M, int N) {
        Map<Integer, Map<Integer, Integer>> graph = new HashMap();
        for (int[] edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph.computeIfAbsent(u, x->new HashMap()).put(v, w);
            graph.computeIfAbsent(v, x->new HashMap()).put(u, w);
        }

        PriorityQueue<ANode> pq = new PriorityQueue<ANode>(
            (a, b) -> Integer.compare(a.dist, b.dist));
        pq.offer(new ANode(0, 0));

        Map<Integer, Integer> dist = new HashMap();
        dist.put(0, 0);
        Map<Integer, Integer> used = new HashMap();
        int ans = 0;

        while (!pq.isEmpty()) {
            ANode anode = pq.poll();
            int node = anode.node;
            int d = anode.dist;

            if (d > dist.getOrDefault(node, 0)) continue;
            // Each node is only visited once.  We've reached
            // a node in our original graph.
            ans++;

            if (!graph.containsKey(node)) continue;
            for (int nei: graph.get(node).keySet()) {
                // M - d is how much further we can walk from this node;
                // weight is how many new nodes there are on this edge.
                // v is the maximum utilization of this edge.
                int weight = graph.get(node).get(nei);
                int v = Math.min(weight, M - d);
                used.put(N * node + nei, v);

                // d2 is the total distance to reach 'nei' (neighbor) node
                // in the original graph.
                int d2 = d + weight + 1;
                if (d2 < dist.getOrDefault(nei, M+1)) {
                    pq.offer(new ANode(nei, d2));
                    dist.put(nei, d2);
                }
            }
        }

        // At the end, each edge (u, v, w) can be used with a maximum
        // of w new nodes: a max of used[u, v] nodes from one side,
        // and used[v, u] nodes from the other.
        // [We use the encoding (u, v) = u * N + v.]
        for (int[] edge: edges) {
            ans += Math.min(edge[2], used.getOrDefault(edge[0] * N + edge[1], 0) +
                                     used.getOrDefault(edge[1] * N + edge[0], 0) );
        }

        return ans;
    }
}

class ANode {
    int node, dist;
    ANode(int n, int d) {
        node = n;
        dist = d;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def reachableNodes(self, edges, M, N):
        graph = collections.defaultdict(dict)
        for u, v, w in edges:
            graph[u][v] = graph[v][u] = w

        pq = [(0, 0)]
        dist = {0: 0}
        used = {}
        ans = 0

        while pq:
            d, node = heapq.heappop(pq)
            if d > dist[node]: continue
            # Each node is only visited once.  We've reached
            # a node in our original graph.
            ans += 1

            for nei, weight in graph[node].iteritems():
                # M - d is how much further we can walk from this node;
                # weight is how many new nodes there are on this edge.
                # v is the maximum utilization of this edge.
                v = min(weight, M - d)
                used[node, nei] = v

                # d2 is the total distance to reach 'nei' (neighbor) node
                # in the original graph.
                d2 = d + weight + 1
                if d2 < dist.get(nei, M+1):
                    heapq.heappush(pq, (d2, nei))
                    dist[nei] = d2

        # At the end, each edge (u, v, w) can be used with a maximum
        # of w new nodes: a max of used[u, v] nodes from one side,
        # and used[v, u] nodes from the other.
        for u, v, w in edges:
            ans += min(w, used.get((u, v), 0) + used.get((v, u), 0))

        return ans
```

</details>
