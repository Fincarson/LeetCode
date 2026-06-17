# 990. Satisfiability of Equality Equations

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/satisfiability-of-equality-equations/)  
`Array` `String` `Union-Find` `Graph Theory`

**Problem Link:** [LeetCode 990 - Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)

## Problem

You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

### Example 1

```text
Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
```

### Example 2

```text
Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
```

## Constraints

- 1 <= equations.length <= 500
- equations[i].length == 4
- equations[i][0] is a lowercase letter.
- equations[i][1] is either '=' or '!'.
- equations[i][2] is '='.
- equations[i][3] is a lowercase letter.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 990. Satisfiability of Equality Equations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-first Search (DFS) | C++, Java, Python3 |
| Union-find | C++, Java, Python3 |

## Approach 1: Depth-first Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        constexpr int SIZE = 26;
        vector<vector<int>> graph(SIZE);
        vector<int> color(SIZE, -1);

        for (string& eqn : equations) {
            if (eqn[1] == '=') {
                int x = eqn[0] - 'a';
                int y = eqn[3] - 'a';
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }

        // mark the color of `node` as `c`
        function<void(int, int)> dfs = [&](int node, int c) {
            if (color[node] == -1) {
                color[node] = c;
                for (int nei : graph[node]) {
                    dfs(nei, c);
                }
            }
        };

        for (int i = 0; i < SIZE; i++) {
            dfs(i, i);
        }

        for (string& eqn : equations) {
            if (eqn[1] == '!') {
                int x = eqn[0] - 'a';
                int y = eqn[3] - 'a';
                if (color[x] == color[y]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean equationsPossible(String[] equations) {
        List<Integer>[] graph = new ArrayList[26];
        for (int i = 0; i < 26; ++i)
            graph[i] = new ArrayList();

        for (String eqn : equations) {
            if (eqn.charAt(1) == '=') {
                int x = eqn.charAt(0) - 'a';
                int y = eqn.charAt(3) - 'a';
                graph[x].add(y);
                graph[y].add(x);
            }
        }

        int[] color = new int[26];
        Arrays.fill(color, -1);

        for (int i = 0; i < 26; i++) {
            if (color[i] == -1) {
                dfs(i, i, color, graph);
            }
        }

        for (String eqn : equations) {
            if (eqn.charAt(1) == '!') {
                int x = eqn.charAt(0) - 'a';
                int y = eqn.charAt(3) - 'a';
                if (color[x] == color[y])
                    return false;
            }
        }

        return true;
    }

    // mark the color of `node` as `c`
    private static void dfs(int node, int c, int[] color, List<Integer>[] graph) {
        if (color[node] == -1) {
            color[node] = c;
            for (int nei : graph[node])
                dfs(nei, c, color, graph);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        graph = [[] for _ in range(26)]

        for eqn in equations:
            if eqn[1] == '=':
                x = ord(eqn[0]) - ord('a')
                y = ord(eqn[3]) - ord('a')
                graph[x].append(y)
                graph[y].append(x)

        color = [-1] * 26

        # mark the color of node as c
        def dfs(node, c):
            if color[node] == -1:
                color[node] = c
                for nei in graph[node]:
                    dfs(nei, c)

        for i in range(26):
            if color[i] == -1:
                dfs(i, i)

        for eqn in equations:
            if eqn[1] == '!':
                x = ord(eqn[0]) - ord('a')
                y = ord(eqn[3]) - ord('a')
                if color[x] == color[y]:
                    return False
        return True
```

</details>

<br>

## Approach 2: Union-find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        constexpr int SIZE = 26;
        vector<int> root(SIZE);
        iota(root.begin(), root.end(), 0);

        function<int(int)> find = [&](int x) {
            if (root[x] != x) {
                root[x] = find(root[x]);
            }
            return root[x];
        };

        auto unionSet = [&](int x, int y) {
            int rx = find(x), ry = find(y);
            root[rx] = ry;
        };

        for (string& eqn : equations) {
            if (eqn[1] == '=') {
                int x = eqn[0] - 'a';
                int y = eqn[3] - 'a';
                unionSet(x, y);
            }
        }

        for (string& eqn : equations) {
            if (eqn[1] == '!') {
                int x = eqn[0] - 'a';
                int y = eqn[3] - 'a';
                if (find(x) == find(y)) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean equationsPossible(String[] equations) {
        int root[] = new int[26];
        for (int i = 0; i < 26; i++) {
            root[i] = i;
        }

        for (String eqn : equations) {
            if (eqn.charAt(1) == '=') {
                int x = eqn.charAt(0) - 'a';
                int y = eqn.charAt(3) - 'a';
                union(root, x, y);
            }
        }

        for (String eqn : equations) {
            if (eqn.charAt(1) == '!') {
                int x = eqn.charAt(0) - 'a';
                int y = eqn.charAt(3) - 'a';
                if (find(root, x) == find(root, y))
                    return false;
            }
        }

        return true;
    }

    private static int find(int[] root, int x) {
        if (root[x] != x)
            root[x] = find(root, root[x]);
        return root[x];
    }

    private static void union(int[] root, int x, int y) {
        x = find(root, x);
        y = find(root, y);
        if (x != y)
            root[x] = y;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        root = list(range(26))

        def find(x):
            if x != root[x]:
                root[x] = find(root[x])
            return root[x]

        def union(x, y):
            x, y = find(x), find(y)
            root[x] = y

        for eqn in equations:
            if eqn[1] == '=':
                x, y = ord(eqn[0])-ord('a'), ord(eqn[3])-ord('a')
                union(x, y)

        for eqn in equations:
            if eqn[1] == '!':
                x, y = ord(eqn[0])-ord('a'), ord(eqn[3])-ord('a')
                if find(x) == find(y):
                    return False
        return True
```

</details>
