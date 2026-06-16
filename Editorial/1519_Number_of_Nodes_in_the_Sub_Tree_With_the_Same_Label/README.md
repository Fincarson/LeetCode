# 1519. Number of Nodes in the Sub-Tree With the Same Label

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Counting`

**Problem Link:** [LeetCode 1519 - Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/)

## Problem

You are given a tree (i.e. a connected, undirected graph that has no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. The root of the tree is the node 0, and each node of the tree has a label which is a lower-case character given in the string labels (i.e. The node with the number i has the label labels[i]).

The edges array is given on the form edges[i] = [ai, bi], which means there is an edge between nodes ai and bi in the tree.

Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i.

A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.

### Example 1

```text
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
Output: [2,1,1,1,1,1,1]
Explanation: Node 0 has label 'a' and its sub-tree has node 2 with label 'a' as well, thus the answer is 2. Notice that any node is part of its sub-tree.
Node 1 has a label 'b'. The sub-tree of node 1 contains nodes 1,4 and 5, as nodes 4 and 5 have different labels than node 1, the answer is just 1 (the node itself).
```

### Example 2

```text
Input: n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
Output: [4,2,1,1]
Explanation: The sub-tree of node 2 contains only node 2, so the answer is 1.
The sub-tree of node 3 contains only node 3, so the answer is 1.
The sub-tree of node 1 contains nodes 1 and 2, both have label 'b', thus the answer is 2.
The sub-tree of node 0 contains nodes 0, 1, 2 and 3, all with label 'b', thus the answer is 4.
```

### Example 3

```text
Input: n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
Output: [3,2,1,1,1]
```

## Constraints

- 1 <= n <= 105
- edges.length == n - 1
- edges[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- labels.length == n
- labels is consisting of only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1519. Number of Nodes in the Sub-Tree With the Same Label

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java |
| Breadth First Search | C++, Java |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> dfs(int node, int parent, vector<vector<int>>& adj, string& labels,
                    vector<int>& ans) {
        // Store count of all alphabets in the subtree of the node.
        vector<int> nodeCounts(26);
        nodeCounts[labels[node] - 'a'] = 1;

        for (auto& child : adj[node]) {
            if (child == parent) {
                continue;
            }
            vector<int> childCounts = dfs(child, node, adj, labels, ans);
            // Add frequencies of the child node in the parent node's frequency array.
            for (int i = 0; i < 26; i++) {
                nodeCounts[i] += childCounts[i];
            }
        }

        ans[node] = nodeCounts[labels[node] - 'a'];
        return nodeCounts;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> ans(n, 0);
        dfs(0, -1, adj, labels, ans);

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] dfs(int node, int parent, Map<Integer, List<Integer>> adj,
            char[] labels, int[] ans) {
        // Store count of all alphabets in the subtree of the node.
        int[] nodeCounts = new int[26];
        nodeCounts[labels[node] - 'a'] = 1;

        if (!adj.containsKey(node))
            return nodeCounts;
        for (int child : adj.get(node)) {
            if (child == parent) {
                continue;
            }
            int[] childCounts = dfs(child, node, adj, labels, ans);
            // Add frequencies of the child node in the parent node's frequency array.
            for (int i = 0; i < 26; i++) {
                nodeCounts[i] += childCounts[i];
            }
        }

        ans[node] = nodeCounts[labels[node] - 'a'];
        return nodeCounts;
    }

    public int[] countSubTrees(int n, int[][] edges, String labels) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }

        int[] ans = new int[n];
        char[] label = labels.toCharArray();
        dfs(0, -1, adj, label, ans);
        return ans;
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
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        // Store count of all alphabets of subtree of each node.
        vector<vector<int>> counts(n, vector<int>(26));
        queue<int> q;

        for (int node = 0; node < n; ++node) {
            counts[node][labels[node] - 'a'] = 1;
            // Store all leaf nodes in the queue.
            if (node != 0 && adj[node].size() == 1) {
                q.push(node);
            }
        }

        while (q.size()) {
            int curr = q.front();
            q.pop();

            // Each node will have only one element which will be its parent.
            int parent = *adj[curr].begin();
            // Remove current node from adjency list of parent node
            // so current node is not traversed again by parent node.
            // (due to this step, we remove all child nodes from a parent, at end parent node will only have its parent in adjacency list)
            adj[parent].erase(curr);

            // Add counts of current node in parent's frequency array.
            for (int i = 0; i < 26; ++i) {
                counts[parent][i] += counts[curr][i];
            }

            // If parent adj size is 1, it has only it's parent in the adjacency list so,
            // it means current node is last child of parent so we insert it in queue now.
            if (parent != 0 && adj[parent].size() == 1) {
                q.push(parent);
            }
        }

        vector<int> ans(n);
        for (int node = 0; node < n; ++node) {
            ans[node] = counts[node][labels[node] - 'a'];
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
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        Map<Integer, Set<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new HashSet<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new HashSet<Integer>()).add(a);
        }
        // Store count of all alphabets of subtree of each node.
        int[][] counts = new int[n][26];
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            counts[i][labels.charAt(i) - 'a'] = 1;
            if (i != 0 && adj.get(i).size() == 1) {
                q.offer(i);
            }
        }

        while (!q.isEmpty()) {
            int node = q.poll();

            // Each node will have only one element which will be its parent.
            int parent = adj.get(node).stream().findFirst().get();
            // Remove current node from adjency list of parent node
            // so current node is not traversed again by parent node.
            // (due to this step, we remove all child nodes from a parent, at end parent node will only have its parent in adjacency list)
            adj.get(parent).remove(node);

            // Add counts of current node in parent's frequency array.
            for (int i = 0; i < 26; i++) {
                counts[parent][i] += counts[node][i];
            }

            // If parent adj size is 1, it has only it's parent in the adjacency list so,
            // it means current node is last child of parent so we insert it in queue now.
            if (parent != 0 && adj.get(parent).size() == 1) {
                q.offer(parent);
            }
        }

        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = counts[i][labels.charAt(i) - 'a'];
        }
        return ans;
    }
}
```

</details>
