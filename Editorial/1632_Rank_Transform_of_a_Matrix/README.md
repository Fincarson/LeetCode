# 1632. Rank Transform of a Matrix

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/rank-transform-of-a-matrix/)  
`Array` `Union-Find` `Graph Theory` `Topological Sort` `Sorting` `Matrix`

**Problem Link:** [LeetCode 1632 - Rank Transform of a Matrix](https://leetcode.com/problems/rank-transform-of-a-matrix/)

## Problem

Given an m x n matrix, return a new matrix answer where answer[row][col] is the rank of matrix[row][col].

The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:

- The rank is an integer starting from 1.
- If two elements p and q are in the same row or column, then:

		If p < q then rank(p) < rank(q)
		If p == q then rank(p) == rank(q)
		If p > q then rank(p) > rank(q)
- The rank should be as small as possible.

The test cases are generated so that answer is unique under the given rules.

### Example 1

```text
Input: matrix = [[1,2],[3,4]]
Output: [[1,2],[2,3]]
Explanation:
The rank of matrix[0][0] is 1 because it is the smallest integer in its row and column.
The rank of matrix[0][1] is 2 because matrix[0][1] > matrix[0][0] and matrix[0][0] is rank 1.
The rank of matrix[1][0] is 2 because matrix[1][0] > matrix[0][0] and matrix[0][0] is rank 1.
The rank of matrix[1][1] is 3 because matrix[1][1] > matrix[0][1], matrix[1][1] > matrix[1][0], and both matrix[0][1] and matrix[1][0] are rank 2.
```

### Example 2

```text
Input: matrix = [[7,7],[7,7]]
Output: [[1,1],[1,1]]
```

### Example 3

```text
Input: matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
Output: [[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
```

## Constraints

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 500
- -109 <= matrix[row][col] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rank Transform of an Array](https://leetcode.com/problems/rank-transform-of-an-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [GCD Sort of an Array](https://leetcode.com/problems/gcd-sort-of-an-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1632. Rank Transform of a Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting + BFS | C++, Java, Python3 |

## Approach 1: Sorting + BFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // link row to col, and link col to row
        unordered_map<int, unordered_map<int, vector<int>>> graphs;
        // graphs[v]: the connection graph of value v
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = matrix[i][j];
                auto& graph = graphs[v];
                // link i to j, and link j to i
                graph[i].push_back(~j);
                graph[~j].push_back(i);
            }
        }

        // put points into `value2index` dict, grouped by connection
        // use ordered map to help us sort the key automatically
        map<int, vector<vector<pair<int, int>>>> value2index;
        // mark whether put into `value2index` or not
        vector<vector<int>> seen(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (seen[i][j] == 1) {
                    continue;
                }
                seen[i][j] = 1;
                int v = matrix[i][j];
                auto graph = graphs[v];
                // store visited row and col
                unordered_set<int> rowcols{i, ~j};
                // start bfs
                queue<int> q;
                q.push(i);
                q.push(~j);
                while (!q.empty()) {
                    auto node = q.front();
                    q.pop();
                    for (int rowcol : graph[node]) {
                        if (rowcols.count(rowcol) == 0) {
                            rowcols.insert(rowcol);
                            q.push(rowcol);
                        }
                    }
                }
                // transform rowcols into points
                vector<pair<int, int>> points;
                for (auto rowcol : rowcols) {
                    for (auto k : graph[rowcol]) {
                        if (k >= 0) {
                            points.push_back({k, ~rowcol});
                            seen[k][~rowcol] = 1;
                        } else {
                            points.push_back({rowcol, ~k});
                            seen[rowcol][~k] = 1;
                        }
                    }
                }
                value2index[v].push_back(points);
            }
        }

        // the required rank matrix
        vector<vector<int>> answer(m, vector<int>(n));
        vector<int> rowMax(m);  // rowMax[i]: the max rank in i row
        vector<int> colMax(n);  // colMax[j]: the max rank in j col
        for (auto v : value2index) {
            // update by connected points with same value
            for (auto points : v.second) {
                int rank = 1;
                for (auto point : points) {
                    rank =
                        max(rank,
                            max(rowMax[point.first], colMax[point.second]) + 1);
                }
                for (auto point : points) {
                    answer[point.first][point.second] = rank;
                    // update rowMax and colMax
                    rowMax[point.first] = max(rowMax[point.first], rank);
                    colMax[point.second] = max(colMax[point.second], rank);
                }
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] matrixRankTransform(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        // link row to col, and link col to row
        Map<Integer, Map<Integer, List<Integer>>> graphs = new HashMap<>();
        // graphs.get(v): the connection graph of value v
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = matrix[i][j];
                // if not initialized, initial it
                if (!graphs.containsKey(v)) {
                    graphs.put(v, new HashMap<Integer, List<Integer>>());
                }
                Map<Integer, List<Integer>> graph = graphs.get(v);
                if (!graph.containsKey(i)) {
                    graph.put(i, new ArrayList<Integer>());
                }
                if (!graph.containsKey(~j)) {
                    graph.put(~j, new ArrayList<Integer>());
                }
                // link i to j, and link j to i
                graph.get(i).add(~j);
                graph.get(~j).add(i);
            }
        }

        // put points into `value2index` dict, grouped by connection
        // use TreeMap to help us sort the key automatically
        SortedMap<Integer, List<List<int[]>>> value2index = new TreeMap<>();
        int[][] seen = new int[m][n]; // mark whether put into `value2index` or not
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (seen[i][j] == 1) {
                    continue;
                }
                seen[i][j] = 1;
                int v = matrix[i][j];
                Map<Integer, List<Integer>> graph = graphs.get(v);
                // store visited row and col
                Set<Integer> rowcols = new HashSet<Integer>();
                rowcols.add(i);
                rowcols.add(~j);
                // start bfs
                Queue<Integer> q = new LinkedList<>();
                q.offer(i);
                q.offer(~j);
                while (!q.isEmpty()) {
                    int node = q.poll();
                    for (int rowcol : graph.get(node)) {
                        if (!rowcols.contains(rowcol)) {
                            rowcols.add(rowcol);
                            q.offer(rowcol);
                        }
                    }
                }
                // transform rowcols into points
                List<int[]> points = new ArrayList<>();
                for (int rowcol : rowcols) {
                    for (int k : graph.get(rowcol)) {
                        if (k >= 0) {
                            points.add(new int[] { k, ~rowcol });
                            seen[k][~rowcol] = 1;
                        } else {
                            points.add(new int[] { rowcol, ~k });
                            seen[rowcol][~k] = 1;
                        }
                    }
                }
                if (!value2index.containsKey(v)) {
                    value2index.put(v, new ArrayList<List<int[]>>());
                }
                value2index.get(v).add(points);
            }
        }
        int[][] answer = new int[m][n]; // the required rank matrix
        int[] rowMax = new int[m]; // rowMax[i]: the max rank in i row
        int[] colMax = new int[n]; // colMax[j]: the max rank in j col
        for (int v : value2index.keySet()) {
            // update by connected points with same value
            for (List<int[]> points : value2index.get(v)) {
                int rank = 1;
                for (int[] point : points) {
                    rank = Math.max(rank, Math.max(rowMax[point[0]], colMax[point[1]]) + 1);
                }
                for (int[] point : points) {
                    answer[point[0]][point[1]] = rank;
                    // update rowMax and colMax
                    rowMax[point[0]] = Math.max(rowMax[point[0]], rank);
                    colMax[point[1]] = Math.max(colMax[point[1]], rank);
                }
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])

        # link row to col, and link col to row
        graphs = {}  # graphs[v]: the connection graph of value v
        for i in range(m):
            for j in range(n):
                v = matrix[i][j]
                # if not initialized, initial it
                if v not in graphs:
                    graphs[v] = {}
                if i not in graphs[v]:
                    graphs[v][i] = []
                if ~j not in graphs[v]:
                    graphs[v][~j] = []
                # link i to j, and link j to i
                graphs[v][i].append(~j)
                graphs[v][~j].append(i)

        # put points into `value2index` dict, grouped by connection
        value2index = {}  # {v: [[points1], [points2], ...], ...}
        seen = set()  # mark whether put into `value2index` or not
        for i in range(m):
            for j in range(n):
                if (i, j) in seen:
                    continue
                seen.add((i, j))
                v = matrix[i][j]
                graph = graphs[v]
                # start bfs
                q = [i, ~j]
                rowcols = {i, ~j}  # store visited row and col
                while q:
                    node = q.pop(0)
                    for rowcol in graph[node]:
                        if rowcol not in rowcols:
                            q.append(rowcol)
                            rowcols.add(rowcol)
                # transform rowcols into points
                points = set()
                for rowcol in rowcols:
                    for k in graph[rowcol]:
                        if k >= 0:
                            points.add((k, ~rowcol))
                            seen.add((k, ~rowcol))
                        else:
                            points.add((rowcol, ~k))
                            seen.add((rowcol, ~k))
                if v not in value2index:
                    value2index[v] = []
                value2index[v].append(points)

        answer = [[0]*n for _ in range(m)]  # the required rank matrix
        rowmax = [0] * m  # rowmax[i]: the max rank in i row
        colmax = [0] * n  # colmax[j]: the max rank in j col
        for v in sorted(value2index.keys()):
            # update by connected points with same value
            for points in value2index[v]:
                rank = 1
                for i, j in points:
                    rank = max(rank, max(rowmax[i], colmax[j]) + 1)
                for i, j in points:
                    answer[i][j] = rank
                    # update rowmax and colmax
                    rowmax[i] = max(rowmax[i], rank)
                    colmax[j] = max(colmax[j], rank)

        return answer
```

</details>
