# 797. All Paths From Source to Target

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/all-paths-from-source-to-target/)  
`Backtracking` `Depth-First Search` `Breadth-First Search` `Graph Theory`

**Problem Link:** [LeetCode 797 - All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/)

## Problem

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

### Example 1

```text
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
```

### Example 2

```text
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
```

## Constraints

- n == graph.length
- 2 <= n <= 15
- 0 <= graph[i][j] < n
- graph[i][j] != i (i.e., there will be no self-loops).
- All the elements of graph[i] are unique.
- The input graph is guaranteed to be a DAG.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of Increasing Paths in a Grid](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 797. All Paths From Source to Target

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C++, Java, Python3 |
| Top-Down Dynamic Programming | C++, Java, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = int(graph.size()) - 1;
        vector<int> path{0};
        vector<vector<int>> results;

        function<void(int, vector<int>&)> backtrack = [&](int currNode, vector<int>& path) {
            if (currNode == target) {
                results.push_back(vector(path));
                return;
            }
            for (int nextNode : graph[currNode]) {
                path.push_back(nextNode);
                backtrack(nextNode, path);
                path.pop_back();
            }
        };

        backtrack(0, path);
        return results;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int target;
    private int[][] graph;
    private List<List<Integer>> results;

    protected void backtrack(int currNode, LinkedList<Integer> path) {
        if (currNode == this.target) {
            // Note: one should make a deep copy of the path
            this.results.add(new ArrayList<Integer>(path));
            return;
        }
        // explore the neighbor nodes one after another.
        for (int nextNode : this.graph[currNode]) {
            // mark the choice, before backtracking.
            path.addLast(nextNode);
            this.backtrack(nextNode, path);
            // remove the previous choice, to try the next choice
            path.removeLast();
        }
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {

        this.target = graph.length - 1;
        this.graph = graph;
        this.results = new ArrayList<List<Integer>>();
        // adopt the LinkedList for fast access to the tail element.
        LinkedList<Integer> path = new LinkedList<Integer>();
        path.addLast(0);
        // kick of the backtracking, starting from the source (node 0)
        this.backtrack(0, path);
        return this.results;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:

        target = len(graph) - 1
        results = []

        def backtrack(curr_node, path):
            # if we reach the target, no need to explore further.
            if curr_node == target:
                results.append(list(path))
                return
            # explore the neighbor nodes one after another.
            for next_node in graph[curr_node]:
                path.append(next_node)
                backtrack(next_node, path)
                path.pop()
        # kick of the backtracking, starting from the source node (0).
        path = [0]
        backtrack(0, path)

        return results
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = int(graph.size()) - 1;
        map<int, vector<vector<int>>> memo;
        function<vector<vector<int>>(int)> allPathsToTarget = [&](int currNode) {
            if (memo.count(currNode)) return memo[currNode];
            vector<vector<int>> results;
            if (currNode == target) {
                results.push_back(vector<int>{target});
            } else {
                for (int nextNode : graph[currNode]) {
                    for (vector<int>& path : allPathsToTarget(nextNode)) {
                        vector<int> newPath{currNode};
                        newPath.insert(newPath.end(), path.begin(), path.end());
                        results.push_back(newPath);
                    }
                }
            }
            memo[currNode] = results;
            return results;
        };
        return allPathsToTarget(0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int target;
    private int[][] graph;
    private HashMap<Integer, List<List<Integer>>> memo;

    protected List<List<Integer>> allPathsToTarget(int currNode) {
        // memoization. check the result in the cache first
        if (memo.containsKey(currNode))
            return memo.get(currNode);

        List<List<Integer>> results = new ArrayList<>();
        // base case
        if (currNode == this.target) {
            ArrayList<Integer> path = new ArrayList<>();
            path.add(target);
            results.add(path);
            return results;
        }

        // iterate through the paths starting from each neighbor.
        for (int nextNode : this.graph[currNode]) {
            for (List<Integer> path : allPathsToTarget(nextNode)) {
                ArrayList<Integer> newPath = new ArrayList<>();
                newPath.add(currNode);
                newPath.addAll(path);
                results.add(newPath);
            }
        }
        memo.put(currNode, results);
        return results;
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {

        this.target = graph.length - 1;
        this.graph = graph;
        this.memo = new HashMap<>();

        return this.allPathsToTarget(0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:

        target = len(graph) - 1

        # apply the memoization
        @lru_cache(maxsize=None)
        def all_paths_to_target(curr_node):
            if curr_node == target:
                return [[target]]

            results = []
            for next_node in graph[curr_node]:
                for path in all_paths_to_target(next_node):
                    results.append([curr_node] + path)

            return results

        return all_paths_to_target(0)
```

</details>
