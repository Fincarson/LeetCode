# 2050. Parallel Courses III

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/parallel-courses-iii/)  
`Array` `Dynamic Programming` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 2050 - Parallel Courses III](https://leetcode.com/problems/parallel-courses-iii/)

## Problem

You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses following these rules:

- You may start taking a course at any time if the prerequisites are met.
- Any number of courses can be taken at the same time.

Return the minimum number of months needed to complete all the courses.

Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).

### Example 1

```text
Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
Output: 8
Explanation: The figure above represents the given graph and the time required to complete each course.
We start course 1 and course 2 simultaneously at month 0.
Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
Thus, the earliest time we can start course 3 is at month 3, and the total time required is 3 + 5 = 8 months.
```

### Example 2

```text
Input: n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
Output: 12
Explanation: The figure above represents the given graph and the time required to complete each course.
You can start courses 1, 2, and 3 at month 0.
You can complete them after 1, 2, and 3 months respectively.
Course 4 can be taken only after course 3 is completed, i.e., after 3 months. It is completed after 3 + 4 = 7 months.
Course 5 can be taken only after courses 1, 2, 3, and 4 have been completed, i.e., after max(1,2,3,7) = 7 months.
Thus, the minimum time needed to complete all the courses is 7 + 5 = 12 months.
```

## Constraints

- 1 <= n <= 5 * 104
- 0 <= relations.length <= min(n * (n - 1) / 2, 5 * 104)
- relations[j].length == 2
- 1 <= prevCoursej, nextCoursej <= n
- prevCoursej != nextCoursej
- All the pairs [prevCoursej, nextCoursej] are unique.
- time.length == n
- 1 <= time[i] <= 104
- The given graph is a directed acyclic graph.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Course Schedule III](https://leetcode.com/problems/course-schedule-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Parallel Courses](https://leetcode.com/problems/parallel-courses/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Process Tasks Using Servers](https://leetcode.com/problems/process-tasks-using-servers/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Employees to Be Invited to a Meeting](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2050. Parallel Courses III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Topological Sort, Kahn's Algorithm | C++, Java, Python3 |
| DFS + Memoization (Top-Down DP) | C++, Java, Python3 |

## Approach 1: Topological Sort, Kahn's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) { 
        unordered_map<int, vector<int>> graph;
        vector<int> indegree = vector(n, 0);

        for (vector<int>& edge: relations) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph[x].push_back(y);
            indegree[y]++;
        }
        
        queue<int> queue;
        vector<int> maxTime = vector(n, 0);
        
        for (int node = 0; node < n; node++) {
            if (indegree[node] == 0) {
                queue.push(node);
                maxTime[node] = time[node];
            }
        }
        
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            for (int neighbor: graph[node]) {
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[node] + time[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }
        
        int ans = 0;
        for (int node = 0; node < n; node++) {
            ans = max(ans, maxTime[node]);
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
    public int minimumTime(int n, int[][] relations, int[] time) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.put(i, new ArrayList<>());
        }
        
        int[] indegree = new int[n];
        for (int[] edge: relations) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph.get(x).add(y);
            indegree[y]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        int[] maxTime = new int[n];
        
        for (int node = 0; node < n; node++) {
            if (indegree[node] == 0) {
                queue.add(node);
                maxTime[node] = time[node];
            }
        }
        
        while (!queue.isEmpty()) {
            int node = queue.remove();
            for (int neighbor: graph.get(node)) {
                maxTime[neighbor] = Math.max(maxTime[neighbor], maxTime[node] + time[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }
        
        int ans = 0;
        for (int node = 0; node < n; node++) {
            ans = Math.max(ans, maxTime[node]);
        }

        return ans;
    }
    
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        graph = defaultdict(list)
        indegree = [0] * n
        
        for (x, y) in relations:
            graph[x - 1].append(y - 1)
            indegree[y - 1] += 1
        
        queue = deque()
        max_time = [0] * n
        for node in range(n):
            if indegree[node] == 0:
                queue.append(node)
                max_time[node] = time[node]

        while queue:
            node = queue.popleft()
            for neighbor in graph[node]:
                max_time[neighbor] = max(max_time[neighbor], max_time[node] + time[neighbor])
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        return max(max_time)
```

</details>

<br>

## Approach 2: DFS + Memoization (Top-Down DP)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> memo;
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) { 
        for (vector<int>& edge: relations) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph[x].push_back(y);
        }
        
        memo = vector(n, -1);
        int ans = 0;
        for (int node = 0; node < n; node++) {
            ans = max(ans, dfs(node, time));
        }
        
        return ans;
    }
    
    int dfs(int node, vector<int>& time) {
        if (memo[node] != -1) {
            return memo[node];
        }
        
        if (graph[node].size() == 0) {
            return time[node];
        }
        
        int ans = 0;
        for (int neighbor: graph[node]) {
            ans = max(ans, dfs(neighbor, time));
        }
        
        memo[node] = time[node] + ans;
        return time[node] + ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Map<Integer, List<Integer>> graph = new HashMap<>();
    Map<Integer, Integer> memo = new HashMap<>();
    
    public int minimumTime(int n, int[][] relations, int[] time) {
        for (int i = 0; i < n; i++) {
            graph.put(i, new ArrayList<>());
        }
        
        for (int[] edge: relations) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph.get(x).add(y);
        }
        
        int ans = 0;
        for (int node = 0; node < n; node++) {
            ans = Math.max(ans, dfs(node, time));
        }

        return ans;
    }
    
    public int dfs(int node, int[] time) {
        if (memo.containsKey(node)) {
            return memo.get(node);
        }
        
        if (graph.get(node).size() == 0) {
            return time[node];
        }
        
        int ans = 0;
        for (int neighbor: graph.get(node)) {
            ans = Math.max(ans, dfs(neighbor, time));
        }
        
        memo.put(node, time[node] + ans);
        return time[node] + ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        @cache
        def dfs(node):
            if not graph[node]:
                return time[node]
            
            ans = 0
            for neighbor in graph[node]:
                ans = max(ans, dfs(neighbor))

            return time[node] + ans
        
        graph = defaultdict(list)
        for (x, y) in relations:
            graph[x - 1].append(y - 1)
        
        ans = 0
        for node in range(n):
            ans = max(ans, dfs(node))

        return ans
```

</details>
