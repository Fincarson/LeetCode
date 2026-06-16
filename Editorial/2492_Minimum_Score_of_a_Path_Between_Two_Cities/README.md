# 2492. Minimum Score of a Path Between Two Cities

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/)  
`Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 2492 - Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/)

## Problem

You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

- A path is a sequence of roads between two cities.
- It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
- The test cases are generated such that there is at least one path between 1 and n.

### Example 1

```text
Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.
```

### Example 2

```text
Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
```

## Constraints

- 2 <= n <= 105
- 1 <= roads.length <= 105
- roads[i].length == 3
- 1 <= ai, bi <= n
- ai != bi
- 1 <= distancei <= 104
- There are no repeated edges.
- There is at least one path between 1 and n.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Checking Existence of Edge Length Limited Paths](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Checking Existence of Edge Length Limited Paths II](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2492. Minimum Score of a Path Between Two Cities

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search | C++, Java |
| Depth First Search | C++, Java |
| Union-find | C++, Java |

## Approach 1: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int bfs(int& n, vector<vector<pair<int, int>>>& adj) {
        vector<bool> visit(n + 1);
        queue<int> q;
        int answer = numeric_limits<int>::max();

        q.push(1);
        visit[1] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& edge : adj[node]) {
                answer = min(answer, edge.second);
                if (!visit[edge.first]) {
                    visit[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
        return answer;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        return bfs(n, adj);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int bfs(int n, Map<Integer, List<List<Integer>>> adj) {
        boolean[] visit = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        int answer = Integer.MAX_VALUE;

        q.offer(1);
        visit[1] = true;

        while (!q.isEmpty()) {
            int node = q.poll();

            if (!adj.containsKey(node)) {
                continue;
            }
            for (List<Integer> edge : adj.get(node)) {
                answer = Math.min(answer, edge.get(1));
                if (!visit[edge.get(0)]) {
                    visit[edge.get(0)] = true;
                    q.offer(edge.get(0));
                }
            }
        }
        return answer;
    }

    public int minScore(int n, int[][] roads) {
        Map<Integer, List<List<Integer>>> adj = new HashMap<>();
        for (int[] road : roads) {
            adj.computeIfAbsent(road[0], k -> new ArrayList<List<Integer>>()).add(
                    Arrays.asList(road[1], road[2]));
            adj.computeIfAbsent(road[1], k -> new ArrayList<List<Integer>>()).add(
                    Arrays.asList(road[0], road[2]));
        }
        return bfs(n, adj);
    }
}
```

</details>

<br>

## Approach 2: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visit, int& answer) {
        visit[node] = true;
        for (auto& edge : adj[node]) {
            answer = min(answer, edge.second);
            if (!visit[edge.first]) {
                dfs(edge.first, adj, visit, answer);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<bool> visit(n + 1);
        int answer = numeric_limits<int>::max();
        dfs(1, adj, visit, answer);

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int answer = Integer.MAX_VALUE;

    public void dfs(int node, Map<Integer, List<List<Integer>>> adj, boolean[] visit) {
        visit[node] = true;
        if (!adj.containsKey(node)) {
            return;
        }
        for (List<Integer> edge : adj.get(node)) {
            answer = Math.min(answer, edge.get(1));
            if (!visit[edge.get(0)]) {
                dfs(edge.get(0), adj, visit);
            }
        }
    }

    public int minScore(int n, int[][] roads) {
        Map<Integer, List<List<Integer>>> adj = new HashMap<>();
        for (int[] road : roads) {
            adj.computeIfAbsent(road[0], k -> new ArrayList<List<Integer>>()).add(
                    Arrays.asList(road[1], road[2]));
            adj.computeIfAbsent(road[1], k -> new ArrayList<List<Integer>>()).add(
                    Arrays.asList(road[0], road[2]));
        }

        boolean[] visit = new boolean[n + 1];
        dfs(1, adj, visit);

        return answer;
    }
}
```

</details>

<br>

## Approach 3: Union-find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind dsu(n + 1);
        int answer = numeric_limits<int>::max();

        for (auto& road : roads) {
            dsu.union_set(road[0], road[1]);
        }

        for (auto& road : roads) {
            if (dsu.find(1) == dsu.find(road[0])) {
                answer = min(answer, road[2]);
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
class UnionFind {
    int[] parent;
    int[] rank;

    public UnionFind(int size) {
        parent = new int[size];
        for (int i = 0; i < size; i++)
            parent[i] = i;
        rank = new int[size];
    }

    public int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    public void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
}

class Solution {
    public int minScore(int n, int[][] roads) {
        UnionFind dsu = new UnionFind(n + 1);
        int answer = Integer.MAX_VALUE;

        for (int[] road : roads) {
            dsu.union_set(road[0], road[1]);
        }

        for (int[] road : roads) {
            if (dsu.find(1) == dsu.find(road[0])) {
                answer = Math.min(answer, road[2]);
            }
        }

        return answer;
    }
}
```

</details>
