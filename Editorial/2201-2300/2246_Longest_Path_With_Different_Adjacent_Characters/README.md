# 2246. Longest Path With Different Adjacent Characters

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/)  
`Array` `String` `Tree` `Depth-First Search` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 2246 - Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/)

## Problem

You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.

### Example 1

```text
Input: parent = [-1,0,0,1,1,2], s = "abacbe"
Output: 3
Explanation: The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, so 3 is returned.
It can be proven that there is no longer path that satisfies the conditions.
```

### Example 2

```text
Input: parent = [-1,0,0,0], s = "aabc"
Output: 3
Explanation: The longest path where each two adjacent nodes have different characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is returned.
```

## Constraints

- n == parent.length == s.length
- 1 <= n <= 105
- 0 <= parent[i] <= n - 1 for all i >= 1
- parent[0] == -1
- parent represents a valid tree.
- s consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Choose Edges to Maximize Score in a Tree](https://leetcode.com/problems/choose-edges-to-maximize-score-in-a-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2246. Longest Path With Different Adjacent Characters

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
    int dfs(int currentNode, vector<vector<int>>& children, string& s, int& longestPath) {
        // Longest and second longest chains starting from currentNode (does not count the
        // currentNode itself).
        int longestChain = 0, secondLongestChain = 0;
        for (int child : children[currentNode]) {
            // Get the number of nodes in the longest path in the subtree of child,
            // including the child.
            int longestChainStartingFromChild = dfs(child, children, s, longestPath);
            // We won't move to the child if it has the same character as the currentNode.
            if (s[currentNode] == s[child]) {
                continue;
            }
            // Modify the longestChain and secondLongestChain if longestChainStartingFromChild
            // is bigger.
            if (longestChainStartingFromChild > longestChain) {
                secondLongestChain = longestChain;
                longestChain = longestChainStartingFromChild;
            } else if (longestChainStartingFromChild > secondLongestChain) {
                secondLongestChain = longestChainStartingFromChild;
            }
        }

        // Add "1" for the node itself.
        longestPath = max(longestPath, longestChain + secondLongestChain + 1);
        return longestChain + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        // Start from node 1, since root node 0 does not have a parent.
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        int longestPath = 1;
        dfs(0, children, s, longestPath);

        return longestPath;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int longestPath = 1;

    public int dfs(int currentNode, Map<Integer, List<Integer>> children, String s) {
        // If the node is the only child, return 1 for the currentNode itself.
        if (!children.containsKey(currentNode)) {
            return 1;
        }

        // Longest and second longest path starting from currentNode (does not count the
        // currentNode itself).
        int longestChain = 0, secondLongestChain = 0;
        for (int child : children.get(currentNode)) {
            // Get the number of nodes in the longest chain starting from the child,
            // including the child.
            int longestChainStartingFromChild = dfs(child, children, s);
            // We won't move to the child if it has the same character as the currentNode.
            if (s.charAt(currentNode) == s.charAt(child)) {
                continue;
            }
            // Modify the longestChain and secondLongestChain if longestChainStartingFromChild
            // is bigger.
            if (longestChainStartingFromChild > longestChain) {
                secondLongestChain = longestChain;
                longestChain = longestChainStartingFromChild;
            } else if (longestChainStartingFromChild > secondLongestChain) {
                secondLongestChain = longestChainStartingFromChild;
            }
        }

        // Add "1" for the node itself.
        longestPath = Math.max(longestPath, longestChain + secondLongestChain + 1);
        return longestChain + 1;
    }

    public int longestPath(int[] parent, String s) {
        int n = parent.length;
        Map<Integer, List<Integer>> children = new HashMap<>();
        // Start from node 1, since root node 0 does not have a parent.
        for (int i = 1; i < n; i++) {
            children.computeIfAbsent(parent[i], value -> new ArrayList<Integer>()).add(i);
        }

        dfs(0, children, s);

        return longestPath;
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
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> childrenCount(n);
        // Start from 1, since the root node does not have a parent.
        for (int node = 1; node < n; node++) {
            childrenCount[parent[node]]++;
        }

        vector<vector<int>> longestChains(n);
        queue<int> q;
        int longestPath = 1;

        for (int node = 0; node < n; node++) {
            longestChains[node] = vector<int>(2);
            // Push all leaf nodes in the queue.
            if (childrenCount[node] == 0 && node != 0) {
                q.push(node);
                longestChains[node][0] = 1;
            }
        }

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            int par = parent[currentNode];

            // Get the number of nodes in the longest chain starting from the currentNode,
            // including the currentNode.
            int longestChainStartingFromCurrNode = longestChains[currentNode][0];
            if (s[currentNode] != s[par]) {
                // Modify the longest chain and second longest chain if
                // longestChainStartingFromCurrNode is bigger.
                int longestChainStartingFromCurrNode = longestChains[currentNode][0];
                if (longestChainStartingFromCurrNode > longestChains[par][0]) {
                    longestChains[par][1] = longestChains[par][0];
                    longestChains[par][0] = longestChainStartingFromCurrNode;
                } else if (longestChainStartingFromCurrNode > longestChains[par][1]) {
                    longestChains[par][1] = longestChainStartingFromCurrNode;
                }
            }

            longestPath = max(longestPath, longestChains[par][0] + longestChains[par][1] + 1);
            childrenCount[par]--;

            if (childrenCount[par] == 0 && par != 0) {
                longestChains[par][0]++;
                q.push(par);
            }
        }

        return longestPath;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestPath(int[] parent, String s) {
        int n = parent.length;
        int[] childrenCount = new int[n];
        // Start from node 1, since the root node does not have a parent.
        for (int node = 1; node < n; node++) {
            childrenCount[parent[node]]++;
        }

        Queue<Integer> q = new LinkedList<>();
        int longestPath = 1;
        int[][] longestChains = new int[n][2];

        for (int node = 1; node < n; node++) {
            // Push all the leaf nodes in the queue.
            if (childrenCount[node] == 0) {
                longestChains[node][0] = 1;
                q.offer(node);
            }
        }

        while (!q.isEmpty()) {
            int currentNode = q.poll();
            int par = parent[currentNode];
            // Get the number of nodes in the longest chain starting from the currentNode,
            // including the currentNode.
            int longestChainStartingFromCurrNode = longestChains[currentNode][0];
            if (s.charAt(currentNode) != s.charAt(par)) {
                // Modify the longest chain and second longest chain if
                // longestChainStartingFromCurrNode is bigger.
                if (longestChainStartingFromCurrNode > longestChains[par][0]) {
                    longestChains[par][1] = longestChains[par][0];
                    longestChains[par][0] = longestChainStartingFromCurrNode;
                } else if (longestChainStartingFromCurrNode > longestChains[par][1]) {
                    longestChains[par][1] = longestChainStartingFromCurrNode;
                }
            }

            longestPath = Math.max(longestPath, longestChains[par][0] + longestChains[par][1] + 1);
            childrenCount[par]--;

            if (childrenCount[par] == 0 && par != 0) {
                longestChains[par][0]++;
                q.offer(par);
            }
        }

        return longestPath;
    }
}
```

</details>
