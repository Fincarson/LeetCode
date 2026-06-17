# 1548. The Most Similar Path in a Graph

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/the-most-similar-path-in-a-graph/)  
`Array` `String` `Dynamic Programming` `Graph Theory`

**Problem Link:** [LeetCode 1548 - The Most Similar Path in a Graph](https://leetcode.com/problems/the-most-similar-path-in-a-graph/)

## Problem

We have n cities and m bi-directional roads where roads[i] = [ai, bi] connects city ai with city bi. Each city has a name consisting of exactly three upper-case English letters given in the string array names. Starting at any city x, you can reach any city y where y != x (i.e., the cities and the roads are forming an undirected connected graph).

You will be given a string array targetPath. You should find a path in the graph of the same length and with the minimum edit distance to targetPath.

You need to return the order of the nodes in the path with the minimum edit distance. The path should be of the same length of targetPath and should be valid (i.e., there should be a direct road between ans[i] and ans[i + 1]). If there are multiple answers return any one of them.

The edit distance is defined as follows:

### Example 1

```text
Input: n = 5, roads = [[0,2],[0,3],[1,2],[1,3],[1,4],[2,4]], names = ["ATL","PEK","LAX","DXB","HND"], targetPath = ["ATL","DXB","HND","LAX"]
Output: [0,2,4,2]
Explanation: [0,2,4,2], [0,3,0,2] and [0,3,1,2] are accepted answers.
[0,2,4,2] is equivalent to ["ATL","LAX","HND","LAX"] which has edit distance = 1 with targetPath.
[0,3,0,2] is equivalent to ["ATL","DXB","ATL","LAX"] which has edit distance = 1 with targetPath.
[0,3,1,2] is equivalent to ["ATL","DXB","PEK","LAX"] which has edit distance = 1 with targetPath.
```

### Example 2

```text
Input: n = 4, roads = [[1,0],[2,0],[3,0],[2,1],[3,1],[3,2]], names = ["ATL","PEK","LAX","DXB"], targetPath = ["ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"]
Output: [0,1,0,1,0,1,0,1]
Explanation: Any path in this graph has edit distance = 8 with targetPath.
```

### Example 3

```text
Input: n = 6, roads = [[0,1],[1,2],[2,3],[3,4],[4,5]], names = ["ATL","PEK","LAX","ATL","DXB","HND"], targetPath = ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
Output: [3,4,5,4,3,2,1]
Explanation: [3,4,5,4,3,2,1] is the only path with edit distance = 0 with targetPath.
It's equivalent to ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
```

## Constraints

- 2 <= n <= 100
- m == roads.length
- n - 1 <= m <= (n * (n - 1) / 2)
- 0 <= ai, bi <= n - 1
- ai != bi
- The graph is guaranteed to be connected and each pair of nodes may have at most one direct road.
- names.length == n
- names[i].length == 3
- names[i] consists of upper-case English letters.
- There can be two cities with the same name.
- 1 <= targetPath.length <= 100
- targetPath[i].length == 3
- targetPath[i] consists of upper-case English letters.

Follow up: If each node can be visited only once in the path, What should you change in your solution?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1548. The Most Similar Path in a Graph

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | C++, Java, Python3 |

## Solution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names,
                            vector<string>& targetPath) {
        vector dp(targetPath.size(), vector<int>(n, targetPath.size() + 1));
        vector p(targetPath.size(), vector<int>(n));
        // initialize DP
        for (int i = 0; i < n; i++) {
            dp[0][i] = names[i] != targetPath[0];
        }
        // calculate DP
        for (int i = 1; i < (int)targetPath.size(); i++) {
            for (auto road : roads) {
                // consider both edges (u, v) and (v, u)
                for (int j = 0; j < 2; j++) {
                    int u = road[j], v = road[j ^ 1],
                        cur = dp[i - 1][u] + (names[v] != targetPath[i]);
                    if (cur < dp[i][v]) {
                        dp[i][v] = cur;
                        p[i][v] = u;
                    }
                }
            }
        }
        // the last vertex in the path
        int v = min_element(dp.back().begin(), dp.back().end()) - dp.back().begin();
        vector<int> ans{v};
        for (int i = targetPath.size() - 1; i > 0; i--) {
            // the previous vertex in the path
            v = p[i][v];
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> mostSimilar(int n, int[][] roads, String[] names,
            String[] targetPath) {
        Integer[][] dp = new Integer[targetPath.length][n];
        int[][] p = new int[targetPath.length][n];
        // initialize DP
        for (int i = 0; i < n; i++) {
            dp[0][i] = names[i].equals(targetPath[0]) ? 0 : 1;
        }
        // calculate DP
        for (int i = 1; i < targetPath.length; i++) {
            Arrays.fill(dp[i], targetPath.length + 1);
            for (int[] road : roads) {
                // consider both edges (u, v) and (v, u)
                for (int j = 0; j < 2; j++) {
                    int u = road[j], v = road[j ^ 1],
                            cur = dp[i - 1][u] + (names[v].equals(targetPath[i]) ? 0 : 1);
                    if (cur < dp[i][v]) {
                        dp[i][v] = cur;
                        p[i][v] = u;
                    }
                }
            }
        }
        List<Integer> lastDP = Arrays.asList(dp[targetPath.length - 1]);
        // the last vertex in the path
        int v = lastDP.indexOf(Collections.min(lastDP));
        List<Integer> ans = new ArrayList<Integer>();
        ans.add(v);
        for (int i = targetPath.length - 1; i > 0; i--) {
            // the previous vertex in the path
            v = p[i][v];
            ans.add(v);
        }
        Collections.reverse(ans);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mostSimilar(self, n: int, roads: List[List[int]], names: List[str],
                    targetPath: List[str]) -> List[int]:
        dp = [[len(targetPath) + 1] * n for i in range(len(targetPath))]
        p = [[None] * n for i in range(len(targetPath))]
        # initialize DP
        dp[0] = [names[i] != targetPath[0] for i in range(n)]
        # calculate DP
        for i in range(1, len(targetPath)):
            for road in roads:
                # consider both edges (u, v) and (v, u)
                for j in range(2):
                    u = road[j]
                    v = road[j ^ 1]
                    cur = dp[i - 1][u] + (names[v] != targetPath[i])
                    if cur < dp[i][v]:
                        dp[i][v] = cur
                        p[i][v] = u
        # the last vertex in the path
        v = dp[-1].index(min(dp[-1]))
        ans = [v]
        for i in range(len(targetPath) - 1, 0, -1):
            # the previous vertex in the path
            v = p[i][v]
            ans.append(v)
        return reversed(ans)
```

</details>
