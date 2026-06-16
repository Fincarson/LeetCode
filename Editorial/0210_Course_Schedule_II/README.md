# 210. Course Schedule II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/course-schedule-ii/)  
`Depth-First Search` `Breadth-First Search` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 210 - Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)

## Problem

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

- For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

### Example 1

```text
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
```

### Example 2

```text
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
```

### Example 3

```text
Input: numCourses = 1, prerequisites = []
Output: [0]
```

## Constraints

- 1 <= numCourses <= 2000
- 0 <= prerequisites.length <= numCourses * (numCourses - 1)
- prerequisites[i].length == 2
- 0 <= ai, bi < numCourses
- ai != bi
- All the pairs [ai, bi] are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Course Schedule](https://leetcode.com/problems/course-schedule/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Alien Dictionary](https://leetcode.com/problems/alien-dictionary/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Course Schedule III](https://leetcode.com/problems/course-schedule-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Parallel Courses](https://leetcode.com/problems/parallel-courses/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Build a Matrix With Conditions](https://leetcode.com/problems/build-a-matrix-with-conditions/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Sort Array by Moving Items to Empty Space](https://leetcode.com/problems/sort-array-by-moving-items-to-empty-space/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 210. Course Schedule II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Depth First Search | C++, Java, Python3 |
| Using Node Indegree | C++, Java, Python3 |

## Approach 1: Using Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int WHITE = 1;
    int GRAY = 2;
    int BLACK = 3;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool isPossible = true;
        map<int, int> color;
        map<int, vector<int>> adjList;
        vector<int> topologicalOrder;

        // By default all vertices are WHITE.
        for (int i = 0; i < numCourses; i++) color[i] = WHITE;

        // Create the adjacency list representation of the graph.
        for (vector<int> relation : prerequisites) {
            int dest = relation[0];
            int src = relation[1];
            // if the key doesn't exist in the adjList, std::map will
            // automatically create a pair (key, vector()) and add it to the
            // map.
            adjList[src].push_back(dest);
        }

        // If the node is unprocessed, then call dfs on it.
        for (int i = 0; i < numCourses && isPossible; i++) {
            if (color[i] == WHITE) {
                dfs(i, color, adjList, isPossible, topologicalOrder);
            }
        }

        vector<int> order;
        if (isPossible) {
            order.resize(numCourses);
            for (int i = 0; i < numCourses; i++) {
                order[i] = topologicalOrder[numCourses - i - 1];
            }
        }
        return order;
    }

    void dfs(int node, map<int, int>& color, map<int, vector<int>>& adjList,
             bool& isPossible, vector<int>& topologicalOrder) {
        // Don't recurse further if we found a cycle already.
        if (!isPossible) return;

        // Start the recursion.
        color[node] = GRAY;

        // Traverse on neighboring vertices.
        for (int neighbor : adjList[node]) {
            if (color[neighbor] == WHITE) {
                dfs(neighbor, color, adjList, isPossible, topologicalOrder);
            } else if (color[neighbor] == GRAY) {
                // An edge to a GRAY vertex represents a cycle.
                isPossible = false;
            }
        }

        // Recursion ends. We mark it as black.
        color[node] = BLACK;
        topologicalOrder.push_back(node);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    static int WHITE = 1;
    static int GRAY = 2;
    static int BLACK = 3;

    boolean isPossible;
    Map<Integer, Integer> color;
    Map<Integer, List<Integer>> adjList;
    List<Integer> topologicalOrder;

    private void init(int numCourses) {
        this.isPossible = true;
        this.color = new HashMap<Integer, Integer>();
        this.adjList = new HashMap<Integer, List<Integer>>();
        this.topologicalOrder = new ArrayList<Integer>();

        // By default all vertces are WHITE
        for (int i = 0; i < numCourses; i++) {
            this.color.put(i, WHITE);
        }
    }

    private void dfs(int node) {
        // Don't recurse further if we found a cycle already
        if (!this.isPossible) {
            return;
        }

        // Start the recursion
        this.color.put(node, GRAY);

        // Traverse on neighboring vertices
        for (Integer neighbor : this.adjList.getOrDefault(
                node,
                new ArrayList<Integer>()
            )) {
            if (this.color.get(neighbor) == WHITE) {
                this.dfs(neighbor);
            } else if (this.color.get(neighbor) == GRAY) {
                // An edge to a GRAY vertex represents a cycle
                this.isPossible = false;
            }
        }

        // Recursion ends. We mark it as black
        this.color.put(node, BLACK);
        this.topologicalOrder.add(node);
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        this.init(numCourses);

        // Create the adjacency list representation of the graph
        for (int i = 0; i < prerequisites.length; i++) {
            int dest = prerequisites[i][0];
            int src = prerequisites[i][1];
            List<Integer> lst = adjList.getOrDefault(
                src,
                new ArrayList<Integer>()
            );
            lst.add(dest);
            adjList.put(src, lst);
        }

        // If the node is unprocessed, then call dfs on it.
        for (int i = 0; i < numCourses; i++) {
            if (this.color.get(i) == WHITE) {
                this.dfs(i);
            }
        }

        int[] order;
        if (this.isPossible) {
            order = new int[numCourses];
            for (int i = 0; i < numCourses; i++) {
                order[i] = this.topologicalOrder.get(numCourses - i - 1);
            }
        } else {
            order = new int[0];
        }

        return order;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import defaultdict


class Solution:

    WHITE = 1
    GRAY = 2
    BLACK = 3

    def findOrder(
        self, numCourses: int, prerequisites: List[List[int]]
    ) -> List[int]:

        # Create the adjacency list representation of the graph
        adj_list = defaultdict(list)

        # A pair [a, b] in the input represents edge from b --> a
        for dest, src in prerequisites:
            adj_list[src].append(dest)

        topological_sorted_order = []
        is_possible = True

        # By default all vertces are WHITE
        color = {k: Solution.WHITE for k in range(numCourses)}

        def dfs(node: int) -> None:
            nonlocal is_possible

            # Don't recurse further if we found a cycle already
            if not is_possible:
                return

            # Start the recursion
            color[node] = Solution.GRAY

            # Traverse on neighboring vertices
            if node in adj_list:
                for neighbor in adj_list[node]:
                    if color[neighbor] == Solution.WHITE:
                        dfs(neighbor)
                    elif color[neighbor] == Solution.GRAY:
                        # An edge to a GRAY vertex represents a cycle
                        is_possible = False

            # Recursion ends. We mark it as black
            color[node] = Solution.BLACK
            topological_sorted_order.append(node)

        for vertex in range(numCourses):
            # If the node is unprocessed, then call dfs on it.
            if color[vertex] == Solution.WHITE:
                dfs(vertex)

        return topological_sorted_order[::-1] if is_possible else []
```

</details>

<br>

## Approach 2: Using Node Indegree

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, list<int>> adjList;
        vector<int> indegree(numCourses, 0);
        vector<int> topologicalOrder;

        // Create the adjacency list representation of the graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int dest = prerequisites[i][0];
            int src = prerequisites[i][1];
            adjList[src].push_back(dest);

            // Record in-degree of each vertex
            indegree[dest]++;
        }

        // Add all vertices with 0 in-degree to the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process until the queue becomes empty
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topologicalOrder.push_back(node);

            // Reduce the in-degree of each neighbor by 1
            if (adjList.count(node)) {
                for (auto neighbor : adjList[node]) {
                    indegree[neighbor]--;

                    // If in-degree of a neighbor becomes 0, add it to the queue
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Check to see if topological sort is possible or not
        if (topologicalOrder.size() == numCourses) {
            return topologicalOrder;
        }

        return vector<int>();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> adjList = new HashMap<
            Integer,
            List<Integer>
        >();
        int[] indegree = new int[numCourses];
        int[] topologicalOrder = new int[numCourses];

        // Create the adjacency list representation of the graph
        for (int i = 0; i < prerequisites.length; i++) {
            int dest = prerequisites[i][0];
            int src = prerequisites[i][1];
            List<Integer> lst = adjList.getOrDefault(
                src,
                new ArrayList<Integer>()
            );
            lst.add(dest);
            adjList.put(src, lst);

            // Record in-degree of each vertex
            indegree[dest] += 1;
        }

        // Add all vertices with 0 in-degree to the queue
        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }

        int i = 0;
        // Process until the Q becomes empty
        while (!q.isEmpty()) {
            int node = q.remove();
            topologicalOrder[i++] = node;

            // Reduce the in-degree of each neighbor by 1
            if (adjList.containsKey(node)) {
                for (Integer neighbor : adjList.get(node)) {
                    indegree[neighbor]--;

                    // If in-degree of a neighbor becomes 0, add it to the Q
                    if (indegree[neighbor] == 0) {
                        q.add(neighbor);
                    }
                }
            }
        }

        // Check to see if topological sort is possible or not.
        if (i == numCourses) {
            return topologicalOrder;
        }

        return new int[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import defaultdict, deque


class Solution:

    def findOrder(
        self, numCourses: int, prerequisites: List[List[int]]
    ) -> List[int]:

        # Prepare the graph
        adj_list = defaultdict(list)
        indegree = {}
        for dest, src in prerequisites:
            adj_list[src].append(dest)

            # Record each node's in-degree
            indegree[dest] = indegree.get(dest, 0) + 1

        # Queue for maintainig list of nodes that have 0 in-degree
        zero_indegree_queue = deque(
            [k for k in range(numCourses) if k not in indegree]
        )

        topological_sorted_order = []

        # Until there are nodes in the Q
        while zero_indegree_queue:

            # Pop one node with 0 in-degree
            vertex = zero_indegree_queue.popleft()
            topological_sorted_order.append(vertex)

            # Reduce in-degree for all the neighbors
            if vertex in adj_list:
                for neighbor in adj_list[vertex]:
                    indegree[neighbor] -= 1

                    # Add neighbor to Q if in-degree becomes 0
                    if indegree[neighbor] == 0:
                        zero_indegree_queue.append(neighbor)

        return (
            topological_sorted_order
            if len(topological_sorted_order) == numCourses
            else []
        )
```

</details>
