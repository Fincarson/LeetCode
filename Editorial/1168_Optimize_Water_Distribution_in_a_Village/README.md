# 1168. Optimize Water Distribution in a Village

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/optimize-water-distribution-in-a-village/)  
`Union-Find` `Graph Theory` `Heap (Priority Queue)` `Minimum Spanning Tree`

**Problem Link:** [LeetCode 1168 - Optimize Water Distribution in a Village](https://leetcode.com/problems/optimize-water-distribution-in-a-village/)

## Problem

There are n houses in a village. We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i - 1] (note the -1 due to 0-indexing), or pipe in water from another well to it. The costs to lay pipes between houses are given by the array pipes where each pipes[j] = [house1j, house2j, costj] represents the cost to connect house1j and house2j together using a pipe. Connections are bidirectional, and there could be multiple valid connections between the same two houses with different costs.

Return the minimum total cost to supply water to all houses.

### Example 1

```text
Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation: The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so the total cost is 3.
```

### Example 2

```text
Input: n = 2, wells = [1,1], pipes = [[1,2,1],[1,2,2]]
Output: 2
Explanation: We can supply water with cost two using one of the three options:
Option 1:
  - Build a well inside house 1 with cost 1.
  - Build a well inside house 2 with cost 1.
The total cost will be 2.
Option 2:
  - Build a well inside house 1 with cost 1.
  - Connect house 2 with house 1 with cost 1.
The total cost will be 2.
Option 3:
  - Build a well inside house 2 with cost 1.
  - Connect house 1 with house 2 with cost 1.
The total cost will be 2.
Note that we can connect houses 1 and 2 with cost 1 or with cost 2 but we will always choose the cheapest option.
```

## Constraints

- 2 <= n <= 104
- wells.length == n
- 0 <= wells[i] <= 105
- 1 <= pipes.length <= 104
- pipes[j].length == 3
- 1 <= house1j, house2j <= n
- 0 <= costj <= 105
- house1j != house2j

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1168. Optimize Water Distribution in a Village

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prim's Algorithm with Heap | Java, Python3 |
| Kruskal's Algorithm with Union-Find | Java, Python3 |

## Approach 1: Prim's Algorithm with Heap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCostToSupplyWater(int n, int[] wells, int[][] pipes) {
        // min heap to maintain the order of edges to be visited.
        PriorityQueue<Pair<Integer, Integer>> edgesHeap =
                new PriorityQueue<>(n, (a, b) -> (a.getKey() - b.getKey()));

        // representation of graph in adjacency list
        List<List<Pair<Integer, Integer>>> graph = new ArrayList<>(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            graph.add(new ArrayList<Pair<Integer, Integer>>());
        }

        // add a virtual vertex indexed with 0,
        //   then add an edge to each of the house weighted by the cost
        for (int i = 0; i < wells.length; ++i) {
            Pair<Integer, Integer> virtualEdge = new Pair<>(wells[i], i + 1);
            graph.get(0).add(virtualEdge);
            // initialize the heap with the edges from the virtual vertex.
            edgesHeap.add(virtualEdge);
        }

        // add the bidirectional edges to the graph
        for (int i = 0; i < pipes.length; ++i) {
            int house1 = pipes[i][0];
            int house2 = pipes[i][1];
            int cost = pipes[i][2];
            graph.get(house1).add(new Pair<Integer, Integer>(cost, house2));
            graph.get(house2).add(new Pair<Integer, Integer>(cost, house1));
        }

        // kick off the exploration from the virtual vertex 0
        Set<Integer> mstSet = new HashSet<>();
        mstSet.add(0);

        int totalCost = 0;
        while (mstSet.size() < n + 1) {
            Pair<Integer, Integer> edge = edgesHeap.poll();
            int cost = edge.getKey();
            int nextHouse = edge.getValue();
            if (mstSet.contains(nextHouse)) {
                continue;
            }

            // adding the new vertex into the set
            mstSet.add(nextHouse);
            totalCost += cost;

            // expanding the candidates of edge to choose from in the next round
            for (Pair<Integer, Integer> neighborEdge : graph.get(nextHouse)) {
                if (!mstSet.contains(neighborEdge.getValue())) {
                    edgesHeap.add(neighborEdge);
                }
            }
        }

        return totalCost;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:

        # bidirectional graph represented in adjacency list
        graph = defaultdict(list)

        # add a virtual vertex indexed with 0.
        #   then add an edge to each of the house weighted by the cost
        for index, cost in enumerate(wells):
            graph[0].append((cost, index + 1))

        # add the bidirectional edges to the graph
        for house_1, house_2, cost in pipes:
            graph[house_1].append((cost, house_2))
            graph[house_2].append((cost, house_1))

        # A set to maintain all the vertex that has been added to
        #   the final MST (Minimum Spanning Tree),
        #   starting from the vertex 0.
        mst_set = set([0])

        # heap to maitain the order of edges to be visited,
        #   starting from the edges originated from the vertex 0.
        # Note: we can start arbitrarily from any node.
        heapq.heapify(graph[0])
        edges_heap = graph[0]

        total_cost = 0
        while len(mst_set) < n + 1:
            cost, next_house = heapq.heappop(edges_heap)
            if next_house not in mst_set:
                # adding the new vertex into the set
                mst_set.add(next_house)
                total_cost += cost
                # expanding the candidates of edge to choose from
                #   in the next round
                for new_cost, neighbor_house in graph[next_house]:
                    if neighbor_house not in mst_set:
                        heapq.heappush(edges_heap, (new_cost, neighbor_house))

        return total_cost
```

</details>

<br>

## Approach 2: Kruskal's Algorithm with Union-Find

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class UnionFind {
    /**
     * Implementation of UnionFind without load-balancing.
     */
    private int[] group;
    private int[] rank;

    public UnionFind(int size) {
        // container to hold the group id for each member
        // Note: the index of member starts from 1,
        //   thus we add one more element to the container.
        group = new int[size + 1];
        rank = new int[size + 1];
        for (int i = 0; i < size + 1; ++i) {
            group[i] = i;
            rank[i] = 0;
        }
    }

    /**
     * return the group id that the person belongs to.
     */
    public int find(int person) {
        if (group[person] != person) {
            group[person] = find(group[person]);
        }
        return group[person];
    }

    /**
     * Join the groups together.
     * return:
     * false when the two persons belong to the same group already,
     * otherwise true
     */
    public boolean union(int person1, int person2) {
        int group1 = find(person1);
        int group2 = find(person2);
        if (group1 == group2) {
            return false;
        }

        // attach the group of lower rank to the one with higher rank
        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }

        return true;
    }
}


class Solution {
    public int minCostToSupplyWater(int n, int[] wells, int[][] pipes) {
        List<int[]> orderedEdges = new ArrayList<>(n + 1 + pipes.length);

        // add the virtual vertex (index with 0) along with the new edges.
        for (int i = 0; i < wells.length; ++i) {
            orderedEdges.add(new int[]{0, i + 1, wells[i]});
        }

        // add the existing edges
        for (int i = 0; i < pipes.length; ++i) {
            int[] edge = pipes[i];
            orderedEdges.add(edge);
        }

        // sort the edges based on their cost
        Collections.sort(orderedEdges, (a, b) -> a[2] - b[2]);

        // iterate through the ordered edges
        UnionFind uf = new UnionFind(n);
        int totalCost = 0;
        for (int[] edge : orderedEdges) {
            int house1 = edge[0];
            int house2 = edge[1];
            int cost = edge[2];
            // determine if we should add the new edge to the final MST
            if (uf.union(house1, house2)) {
                totalCost += cost;
            }
        }

        return totalCost;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class UnionFind:
    """
        Implementation of UnionFind without load-balancing.
    """
    def __init__(self, size) -> None:
        """
        container to hold the group id for each member
        Note: the index of member starts from 1,
            thus we add one more element to the container.
        """
        self.group = [i for i in range(size + 1)]
        # the rank of each node for later rebalancing
        self.rank = [0] * (size + 1)

    def find(self, person: int) -> int:
        """
            return the group id that the person belongs to
        """
        if self.group[person] != person:
            self.group[person] = self.find(self.group[person])
        return self.group[person]

    def union(self, person_1: int, person_2: int) -> bool:
        """
            Join the groups together.
            return:
                false when the two persons belong to the same group already,
                otherwise true
        """
        group_1 = self.find(person_1)
        group_2 = self.find(person_2)
        if group_1 == group_2:
            return False

        # attach the group of lower rank to the group with higher rank
        if self.rank[group_1] > self.rank[group_2]:
            self.group[group_2] = group_1
        elif self.rank[group_1] < self.rank[group_2]:
            self.group[group_1] = group_2
        else:
            self.group[group_1] = group_2
            self.rank[group_2] += 1

        return True


class Solution:
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        ordered_edges = []
        # add the virtual vertex (index with 0) along with the new edges.
        for index, weight in enumerate(wells):
            ordered_edges.append((weight, 0, index+1))

        # add the existing edges
        for house_1, house_2, weight in pipes:
            ordered_edges.append((weight, house_1, house_2))

        # sort the entire edges by their weights
        ordered_edges.sort(key=lambda x: x[0])

        # iterate through the ordered edges
        uf = UnionFind(n)
        total_cost = 0
        for cost, house_1, house_2 in ordered_edges:
            # determine if we should add the new edge to the final MST
            if uf.union(house_1, house_2):
                total_cost += cost

        return total_cost
```

</details>
