# 839. Similar String Groups

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/similar-string-groups/)  
`Array` `Hash Table` `String` `Depth-First Search` `Breadth-First Search` `Union-Find`

**Problem Link:** [LeetCode 839 - Similar String Groups](https://leetcode.com/problems/similar-string-groups/)

## Problem

Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

### Example 1

```text
Input: strs = ["tars","rats","arts","star"]
Output: 2
```

### Example 2

```text
Input: strs = ["omv","ovm"]
Output: 1
```

## Constraints

- 1 <= strs.length <= 300
- 1 <= strs[i].length <= 300
- strs[i] consists of lowercase letters only.
- All words in strs have the same length and are anagrams of each other.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Groups of Strings](https://leetcode.com/problems/groups-of-strings/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 839. Similar String Groups

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java |
| Breadth First Search | C++, Java |
| Union-find | C++, Java |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        visit[node] = true;
        for (int neighbor : adj[node]) {
            if (!visit[neighbor]) {
                dfs(neighbor, adj, visit);
            }
        }
    }

    bool isSimilar(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        // Form the required graph from the given strings array.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visit(n);
        int count = 0;
        // Count the number of connected components.
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                dfs(i, adj, visit);
                count++;
            }
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void dfs(int node, Map<Integer, List<Integer>> adj, boolean[] visit) {
        visit[node] = true;
        if (!adj.containsKey(node)) {
            return;
        }
        for (int neighbor : adj.get(node)) {
            if (!visit[neighbor]) {
                visit[neighbor] = true;
                dfs(neighbor, adj, visit);
            }
        }
    }

    public boolean isSimilar(String a, String b) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diff++;
            }
        }
        return diff == 0 || diff == 2;
    }

    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        Map<Integer, List<Integer>> adj = new HashMap<>();
        // Form the required graph from the given strings array.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    adj.computeIfAbsent(i, k -> new ArrayList<Integer>()).add(j);
                    adj.computeIfAbsent(j, k -> new ArrayList<Integer>()).add(i);
                }
            }
        }

        boolean[] visit = new boolean[n];
        int count = 0;
        // Count the number of connected components.
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                dfs(i, adj, visit);
                count++;
            }
        }

        return count;
    }
}
```

</details>

<br>

## Approach 2: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    bool isSimilar(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        // Form the required graph from the given strings array.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visit(n);
        int count = 0;
        // Count the number of connected components.
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                bfs(i, adj, visit);
                count++;
            }
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void bfs(int node, Map<Integer, List<Integer>> adj, boolean[] visit) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(node);
        visit[node] = true;
        while (!q.isEmpty()) {
            node = q.poll();
            if (!adj.containsKey(node)) {
                continue;
            }
            for (int neighbor : adj.get(node)) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    q.offer(neighbor);
                }
            }
        }
    }

    public boolean isSimilar(String a, String b) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diff++;
            }
        }
        return diff == 0 || diff == 2;
    }

    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        Map<Integer, List<Integer>> adj = new HashMap<>();
        // Form the required graph from the given strings array.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    adj.computeIfAbsent(i, k -> new ArrayList<Integer>()).add(j);
                    adj.computeIfAbsent(j, k -> new ArrayList<Integer>()).add(i);
                }
            }
        }

        boolean[] visit = new boolean[n];
        int count = 0;
        // Count the number of connected components.
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                bfs(i, adj, visit);
                count++;
            }
        }

        return count;
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
    int count;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        count = size;
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
        if (rank[xset] < rank[yset]) {
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
    bool isSimilar(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind dsu(n);
        int count = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j]) && dsu.find(i) != dsu.find(j)) {
                    count--;
                    dsu.union_set(i, j);
                }
            }
        }

        return count;
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
    public boolean isSimilar(String a, String b) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diff++;
            }
        }
        return diff == 0 || diff == 2;
    }

    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        UnionFind dsu = new UnionFind(n);
        int count = n;
        // Form the required graph from the given strings array.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j]) && dsu.find(i) != dsu.find(j)) {
                    count--;
                    dsu.union_set(i, j);
                }
            }
        }

        return count;
    }
}
```

</details>
