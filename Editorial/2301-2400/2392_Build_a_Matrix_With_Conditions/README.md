# 2392. Build a Matrix With Conditions

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/build-a-matrix-with-conditions/)  
`Array` `Graph Theory` `Topological Sort` `Matrix`

**Problem Link:** [LeetCode 2392 - Build a Matrix With Conditions](https://leetcode.com/problems/build-a-matrix-with-conditions/)

## Problem

You are given a positive integer k. You are also given:

- a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
- a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].

The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

- The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
- The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.

Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

### Example 1

```text
Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.
```

### Example 2

```text
Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.
```

## Constraints

- 2 <= k <= 400
- 1 <= rowConditions.length, colConditions.length <= 104
- rowConditions[i].length == colConditions[i].length == 2
- 1 <= abovei, belowi, lefti, righti <= k
- abovei != belowi
- lefti != righti

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Course Schedule](https://leetcode.com/problems/course-schedule/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Loud and Rich](https://leetcode.com/problems/loud-and-rich/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2392. Build a Matrix With Conditions

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search | C++, Java, Python3 |
| Kahn's Algorithm | C++, Java, Python3 |

## Approach 1: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        // Store the topologically sorted sequences.
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        // If no topological sort exists, return empty array.
        if (orderRows.empty() or orderColumns.empty()) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }

private:
    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n + 1);
        vector<int> order;
        // 0: not visited, 1: visiting, 2: visited
        vector<int> visited(n + 1, 0);
        bool hasCycle = false;

        // Build adjacency list
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
        }

        // Perform DFS for each node
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, order, hasCycle);
                // Return empty if cycle detected
                if (hasCycle) return {};
            }
        }
        // Reverse to get the correct order
        reverse(order.begin(), order.end());
        return order;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited,
             vector<int>& order, bool& hasCycle) {
        visited[node] = 1;  // Mark node as visiting
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, adj, visited, order, hasCycle);
                // Early exit if a cycle is detected
                if (hasCycle) return;
            } else if (visited[neighbor] == 1) {
                // Cycle detected
                hasCycle = true;
                return;
            }
        }
        // Mark node as visited
        visited[node] = 2;
        // Add node to the order
        order.push_back(node);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] buildMatrix(
        int k,
        int[][] rowConditions,
        int[][] colConditions
    ) {
        // Store the topologically sorted sequences.
        List<Integer> orderRows = topoSort(rowConditions, k);
        List<Integer> orderColumns = topoSort(colConditions, k);

        // If no topological sort exists, return empty array.
        if (orderRows.isEmpty() || orderColumns.isEmpty()) return new int[0][0];

        int[][] matrix = new int[k][k];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows.get(i).equals(orderColumns.get(j))) {
                    matrix[i][j] = orderRows.get(i);
                }
            }
        }
        return matrix;
    }

    private List<Integer> topoSort(int[][] edges, int n) {
        // Build adjacency list
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
        }

        List<Integer> order = new ArrayList<>();
        // 0: not visited, 1: visiting, 2: visited
        int[] visited = new int[n + 1];
        boolean hasCycle = false;

        // Perform DFS for each node
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                hasCycle = dfs(i, adj, visited, order);
                // Return empty if cycle detected
                if (hasCycle) return new ArrayList<>();
            }
        }

        // Reverse to get the correct order
        Collections.reverse(order);
        return order;
    }

    private boolean dfs(
        int node,
        List<List<Integer>> adj,
        int[] visited,
        List<Integer> order
    ) {
        visited[node] = 1; // Mark node as visiting
        for (int neighbor : adj.get(node)) {
            if (visited[neighbor] == 0) {
                if (dfs(neighbor, adj, visited, order)) {
                    return true; // Cycle detected
                }
            } else if (visited[neighbor] == 1) {
                return true; // Cycle detected
            }
        }
        // Mark node as visited
        visited[node] = 2;
        // Add node to the order
        order.add(node);
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buildMatrix(
        self,
        k: int,
        row_conditions: List[List[int]],
        col_conditions: List[List[int]],
    ) -> List[List[int]]:
        # Get the topologically sorted sequences.
        order_rows = self.topo_sort(row_conditions, k)
        order_columns = self.topo_sort(col_conditions, k)

        # If no topological sort exists, return an empty matrix.
        if not order_rows or not order_columns:
            return []

        # Map elements to their respective indices in the column order.
        position = {val: i for i, val in enumerate(order_columns)}

        # Initialize the matrix.
        matrix = [[0] * k for _ in range(k)]
        for i, row_val in enumerate(order_rows):
            if row_val in position:
                col_index = position[row_val]
                matrix[i][col_index] = row_val

        return matrix

    def topo_sort(self, edges: List[List[int]], n: int) -> List[int]:
        # Build adjacency list.
        adj = [[] for _ in range(n + 1)]
        for u, v in edges:
            adj[u].append(v)

        # 0: not visited, 1: visiting, 2: visited
        visited = [0] * (n + 1)
        order = []
        self.has_cycle = False

        # Perform DFS for each node.
        for i in range(1, n + 1):
            if visited[i] == 0:
                self.dfs(i, adj, visited, order)
                if self.has_cycle:
                    return []

        # Reverse to get the correct order.
        return order[::-1]

    def dfs(
        self,
        node: int,
        adj: List[List[int]],
        visited: List[int],
        order: List[int]
    ):
        visited[node] = 1  # Mark node as visiting.
        for neighbor in adj[node]:
            if visited[neighbor] == 0:  # Not visited.
                self.dfs(neighbor, adj, visited, order)
                if self.has_cycle:
                    return
            elif visited[neighbor] == 1:  # Cycle detected.
                self.has_cycle = True
                return

        visited[node] = 2  # Mark node as visited.
        order.append(node)
```

</details>

<br>

## Approach 2: Kahn's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        // Store the topologically sorted sequences.
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        // If no topological sort exists, return empty array.
        if (orderRows.empty() or orderColumns.empty()) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }

private:
    // Code to find the topologically sorted sequence using Kahn's algorithm.
    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        // Create an adjacency list to store the edges.
        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1), order;
        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            deg[x[1]]++;
        }
        queue<int> q;
        // Push all integers with in-degree 0 in the queue.
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            order.push_back(f);
            n--;
            for (auto v : adj[f]) {
                if (--deg[v] == 0) q.push(v);
            }
        }
        // If we have not visited all integers, return empty array.
        if (n != 0) return {};
        return order;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[][] buildMatrix(
        int k,
        int[][] rowConditions,
        int[][] colConditions
    ) {
        int[] orderRows = topoSort(rowConditions, k);
        int[] orderColumns = topoSort(colConditions, k);
        if (
            orderRows.length == 0 || orderColumns.length == 0
        ) return new int[0][0];
        int[][] matrix = new int[k][k];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }

    private int[] topoSort(int[][] edges, int n) {
        List<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        int[] deg = new int[n + 1], order = new int[n];
        int idx = 0;
        for (int[] x : edges) {
            adj[x[0]].add(x[1]);
            deg[x[1]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) q.offer(i);
        }
        while (!q.isEmpty()) {
            int f = q.poll();
            order[idx++] = f;
            n--;
            for (int v : adj[f]) {
                if (--deg[v] == 0) q.offer(v);
            }
        }
        if (n != 0) return new int[0];
        return order;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buildMatrix(
        self,
        k: int,
        row_conditions: List[List[int]],
        col_conditions: List[List[int]],
    ) -> List[List[int]]:
        order_rows = self.__topo_sort(row_conditions, k)
        order_columns = self.__topo_sort(col_conditions, k)
        if not order_rows or not order_columns:
            return []
        matrix = [[0] * k for _ in range(k)]
        for i in range(k):
            for j in range(k):
                if order_rows[i] == order_columns[j]:
                    matrix[i][j] = order_rows[i]
        return matrix

    def __topo_sort(self, edges, n):
        adj = [[] for _ in range(n + 1)]
        deg = [0] * (n + 1)
        order = []
        for x in edges:
            adj[x[0]].append(x[1])
            deg[x[1]] += 1
        q = deque()
        for i in range(1, n + 1):
            if deg[i] == 0:
                q.append(i)
        while q:
            f = q.popleft()
            order.append(f)
            n -= 1
            for v in adj[f]:
                deg[v] -= 1
                if deg[v] == 0:
                    q.append(v)
        if n != 0:
            return []
        return order
```

</details>
