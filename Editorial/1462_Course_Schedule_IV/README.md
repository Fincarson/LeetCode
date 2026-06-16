# 1462. Course Schedule IV

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/course-schedule-iv/)  
`Depth-First Search` `Breadth-First Search` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 1462 - Course Schedule IV](https://leetcode.com/problems/course-schedule-iv/)

## Problem

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

- For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.

Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

### Example 1

```text
Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.
```

### Example 2

```text
Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites, and each course is independent.
```

### Example 3

```text
Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
```

## Constraints

- 2 <= numCourses <= 100
- 0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
- prerequisites[i].length == 2
- 0 <= ai, bi <= numCourses - 1
- ai != bi
- All the pairs [ai, bi] are unique.
- The prerequisites graph has no cycles.
- 1 <= queries.length <= 104
- 0 <= ui, vi <= numCourses - 1
- ui != vi

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1462. Course Schedule IV

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Tree Traversal - On Demand | C++, Java, Python3 |
| Tree Traversal - Preprocessed | C++, Java, Python3 |
| Topological Sort - Kahn's Algorithm | C++, Java, Python3 |
| Floyd Warshall Algorithm | C++, Java, Python3 |

## Approach 1: Tree Traversal - On Demand

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Performs DFS and returns true if there's a path between src and target
    // and false otherwise.
    bool isPrerequisite(unordered_map<int, vector<int>>& adjList,
                        vector<bool>& visited, int src, int target) {
        visited[src] = 1;

        if (src == target) {
            return true;
        }

        int answer = false;
        for (auto adj : adjList[src]) {
            if (!visited[adj]) {
                answer =
                    answer || isPrerequisite(adjList, visited, adj, target);
            }
        }
        return answer;
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<bool> answer;
        for (auto q : queries) {
            // Reset the visited array for each query.
            vector<bool> visited(numCourses, false);
            answer.push_back(isPrerequisite(adjList, visited, q[0], q[1]));
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

    // Performs DFS and returns true if there's a path between src and target
    // and false otherwise.
    private boolean isPrerequisite(
        Map<Integer, List<Integer>> adjList,
        boolean[] visited,
        int src,
        int target
    ) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        boolean answer = false;
        List<Integer> neighbors = adjList.getOrDefault(src, new ArrayList<>());
        for (int adj : neighbors) {
            if (!visited[adj]) {
                answer =
                    answer || isPrerequisite(adjList, visited, adj, target);
            }
        }
        return answer;
    }

    public List<Boolean> checkIfPrerequisite(
        int numCourses,
        int[][] prerequisites,
        int[][] queries
    ) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();

        for (int[] edge : prerequisites) {
            adjList
                .computeIfAbsent(edge[0], k -> new ArrayList<>())
                .add(edge[1]);
        }

        List<Boolean> result = new ArrayList<>();
        for (int i = 0; i < queries.length; i++) {
            // Reset the visited array for each query
            boolean[] visited = new boolean[numCourses];
            result.add(
                isPrerequisite(adjList, visited, queries[i][0], queries[i][1])
            );
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
    # Performs DFS and returns true if there's a path between src and target and false otherwise.
    def isPrerequisite(
        self, adjList: dict, visited: List[bool], src: int, target: int
    ) -> bool:
        visited[src] = True

        if src == target:
            return True

        for adj in adjList.get(src, []):
            if not visited[adj]:
                if self.isPrerequisite(adjList, visited, adj, target):
                    return True
        return False

    def checkIfPrerequisite(
        self,
        numCourses: int,
        prerequisites: List[List[int]],
        queries: List[List[int]],
    ) -> List[bool]:
        adjList = {i: [] for i in range(numCourses)}

        for edge in prerequisites:
            adjList[edge[0]].append(edge[1])

        result = []

        for query in queries:
            # Reset the visited array for each query
            visited = [False] * numCourses
            result.append(
                self.isPrerequisite(adjList, visited, query[0], query[1])
            )

        return result
```

</details>

<br>

## Approach 2: Tree Traversal - Preprocessed

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Iterate over each node and perform BFS starting from it.
    // Mark the starting node as a prerequisite to all the nodes in the BFS
    // traversal.
    void preprocess(int numCourses, vector<vector<int>>& prerequisites,
                    unordered_map<int, vector<int>>& adjList,
                    vector<vector<bool>>& isPrerequisite) {
        for (int i = 0; i < numCourses; i++) {
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto adj : adjList[node]) {
                    // If we have marked i as a prerequisite of adj it implies
                    // we have visited it. This is equivalent to using a visited
                    // array.
                    if (!isPrerequisite[i][adj]) {
                        isPrerequisite[i][adj] = true;
                        q.push(adj);
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<vector<bool>> isPrerequisite(numCourses,
                                            vector<bool>(numCourses, false));
        // Store the prerequisite for each node in the array.
        preprocess(numCourses, prerequisites, adjList, isPrerequisite);

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(isPrerequisite[q[0]][q[1]]);
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    // Iterate over each node and perform BFS starting from it.
    // Mark the starting node as a prerequisite to all the nodes in the BFS
    // traversal.
    private void preprocess(
        int numCourses,
        int[][] prerequisites,
        Map<Integer, List<Integer>> adjList,
        boolean[][] isPrerequisite
    ) {
        for (int i = 0; i < numCourses; i++) {
            Queue<Integer> q = new LinkedList<>();
            q.offer(i);

            while (!q.isEmpty()) {
                int node = q.poll();

                for (int adj : adjList.getOrDefault(node, new ArrayList<>())) {
                    // If we have marked i as a prerequisite of adj it implies we
                    // have visited it. This is equivalent to using a visited
                    // array.
                    if (!isPrerequisite[i][adj]) {
                        isPrerequisite[i][adj] = true;
                        q.offer(adj);
                    }
                }
            }
        }
    }

    public List<Boolean> checkIfPrerequisite(
        int numCourses,
        int[][] prerequisites,
        int[][] queries
    ) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        for (int[] edge : prerequisites) {
            adjList
                .computeIfAbsent(edge[0], k -> new ArrayList<>())
                .add(edge[1]);
        }

        boolean[][] isPrerequisite = new boolean[numCourses][numCourses];
        preprocess(numCourses, prerequisites, adjList, isPrerequisite);

        List<Boolean> answer = new ArrayList<>();
        for (int[] query : queries) {
            answer.add(isPrerequisite[query[0]][query[1]]);
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
    # Iterate over each node and perform BFS starting from it.
    # Mark the starting node as a prerequisite to all the nodes in the BFS
    # traversal.
    def preprocess(
        self,
        numCourses: int,
        prerequisites: List[List[int]],
        adjList: dict[int, List[int]],
        isPrerequisite: List[List[bool]],
    ) -> None:
        for i in range(numCourses):
            q = deque([i])

            while q:
                node = q.popleft()

                for adj in adjList.get(node, []):
                    # If we have marked i as a prerequisite of adj it implies we
                    # have visited it. This is equivalent to using a visited
                    # array.
                    if not isPrerequisite[i][adj]:
                        isPrerequisite[i][adj] = True
                        q.append(adj)

    def checkIfPrerequisite(
        self,
        numCourses: int,
        prerequisites: List[List[int]],
        queries: List[List[int]],
    ) -> List[bool]:
        adjList = {}
        for edge in prerequisites:
            if edge[0] not in adjList:
                adjList[edge[0]] = []
            adjList[edge[0]].append(edge[1])

        isPrerequisite = [[False] * numCourses for _ in range(numCourses)]
        self.preprocess(numCourses, prerequisites, adjList, isPrerequisite)

        answer = []
        for query in queries:
            answer.append(isPrerequisite[query[0]][query[1]])

        return answer
```

</details>

<br>

## Approach 3: Topological Sort - Kahn's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        // Map from the node as key to the set of prerequisite nodes.
        unordered_map<int, unordered_set<int>> nodePrerequisites;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adj : adjList[node]) {
                // Add node and prerequisite of node to the prerequisites of adj
                nodePrerequisites[adj].insert(node);
                for (auto prereq : nodePrerequisites[node]) {
                    nodePrerequisites[adj].insert(prereq);
                }

                indegree[adj]--;
                if (!indegree[adj]) {
                    q.push(adj);
                }
            }
        }

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(nodePrerequisites[q[1]].contains(q[0]));
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public List<Boolean> checkIfPrerequisite(
        int numCourses,
        int[][] prerequisites,
        int[][] queries
    ) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        int[] indegree = new int[numCourses];

        for (int[] edge : prerequisites) {
            adjList
                .computeIfAbsent(edge[0], k -> new ArrayList<>())
                .add(edge[1]);
            indegree[edge[1]]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        // Map from the node as key to the set of prerequisite nodes.
        Map<Integer, Set<Integer>> nodePrerequisites = new HashMap<>();

        while (!q.isEmpty()) {
            int node = q.poll();

            for (int adj : adjList.getOrDefault(node, new ArrayList<>())) {
                // Add node and prerequisites of the node to the prerequisites of adj
                nodePrerequisites
                    .computeIfAbsent(adj, k -> new HashSet<>())
                    .add(node);
                for (int prereq : nodePrerequisites.getOrDefault(
                    node,
                    new HashSet<>()
                )) {
                    nodePrerequisites.get(adj).add(prereq);
                }

                indegree[adj]--;
                if (indegree[adj] == 0) {
                    q.offer(adj);
                }
            }
        }

        List<Boolean> answer = new ArrayList<>();
        for (int[] query : queries) {
            answer.add(
                nodePrerequisites
                    .getOrDefault(query[1], new HashSet<>())
                    .contains(query[0])
            );
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
    def checkIfPrerequisite(
        self,
        numCourses: int,
        prerequisites: List[List[int]],
        queries: List[List[int]],
    ) -> List[bool]:
        adjList = defaultdict(list)
        indegree = [0] * numCourses

        for edge in prerequisites:
            adjList[edge[0]].append(edge[1])
            indegree[edge[1]] += 1

        q = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)

        nodePrerequisites = defaultdict(set)

        while q:
            node = q.popleft()

            for adj in adjList[node]:
                # Add node and prerequisite of the node to the prerequisites of adj
                nodePrerequisites[adj].add(node)
                for prereq in nodePrerequisites[node]:
                    nodePrerequisites[adj].add(prereq)

                indegree[adj] -= 1
                if indegree[adj] == 0:
                    q.append(adj)

        answer = []
        for q in queries:
            answer.append(q[0] in nodePrerequisites[q[1]])

        return answer
```

</details>

<br>

## Approach 4: Floyd Warshall Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<bool>> isPrerequisite(numCourses,
                                            vector<bool>(numCourses, false));
        for (auto edge : prerequisites) {
            isPrerequisite[edge[0]][edge[1]] = true;
        }

        for (int intermediate = 0; intermediate < numCourses; intermediate++) {
            for (int src = 0; src < numCourses; src++) {
                for (int target = 0; target < numCourses; target++) {
                    // If src -> intermediate & intermediate -> target exists
                    // then src -> target will also exist.
                    isPrerequisite[src][target] =
                        isPrerequisite[src][target] ||
                        (isPrerequisite[src][intermediate] &&
                         isPrerequisite[intermediate][target]);
                }
            }
        }

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(isPrerequisite[q[0]][q[1]]);
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public List<Boolean> checkIfPrerequisite(
        int numCourses,
        int[][] prerequisites,
        int[][] queries
    ) {
        boolean[][] isPrerequisite = new boolean[numCourses][numCourses];

        for (int[] edge : prerequisites) {
            isPrerequisite[edge[0]][edge[1]] = true;
        }

        for (int intermediate = 0; intermediate < numCourses; intermediate++) {
            for (int src = 0; src < numCourses; src++) {
                for (int target = 0; target < numCourses; target++) {
                    // If there is a path i -> intermediate and intermediate -> j, then i -> j exists as well.
                    isPrerequisite[src][target] =
                        isPrerequisite[src][target] ||
                        (isPrerequisite[src][intermediate] &&
                            isPrerequisite[intermediate][target]);
                }
            }
        }

        List<Boolean> answer = new ArrayList<>();
        for (int[] query : queries) {
            answer.add(isPrerequisite[query[0]][query[1]]);
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
    def checkIfPrerequisite(
        self,
        numCourses: int,
        prerequisites: List[List[int]],
        queries: List[List[int]],
    ) -> List[bool]:
        isPrerequisite = [[False] * numCourses for _ in range(numCourses)]

        for edge in prerequisites:
            isPrerequisite[edge[0]][edge[1]] = True

        for intermediate in range(numCourses):
            for src in range(numCourses):
                for target in range(numCourses):
                    # If there is a path src -> intermediate and intermediate -> target, then src -> target exists as well
                    isPrerequisite[src][target] = isPrerequisite[src][
                        target
                    ] or (
                        isPrerequisite[src][intermediate]
                        and isPrerequisite[intermediate][target]
                    )

        answer = []
        for query in queries:
            answer.append(isPrerequisite[query[0]][query[1]])

        return answer
```

</details>
