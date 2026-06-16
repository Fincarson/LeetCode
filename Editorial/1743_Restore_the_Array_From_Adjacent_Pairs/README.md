# 1743. Restore the Array From Adjacent Pairs

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/)  
`Array` `Hash Table` `Depth-First Search`

**Problem Link:** [LeetCode 1743 - Restore the Array From Adjacent Pairs](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/)

## Problem

There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.

### Example 1

```text
Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
```

### Example 2

```text
Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
```

### Example 3

```text
Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]
```

## Constraints

- nums.length == n
- adjacentPairs.length == n - 1
- adjacentPairs[i].length == 2
- 2 <= n <= 105
- -105 <= nums[i], ui, vi <= 105
- There exists some nums that has adjacentPairs as its pairs.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1743. Restore the Array From Adjacent Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C++, Java, Python3 |
| Iterative, Follow the Path | C++, Java, Python3 |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for (auto& edge : adjacentPairs) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int root = 0;
        for (auto& pair : graph) {
            if (pair.second.size() == 1) {
                root = pair.first;
                break;
            }
        }
        
        vector<int> ans;
        dfs(root, INT_MAX, ans);
        return ans;
    }
    
    void dfs(int node, int prev, vector<int>& ans) {
        ans.push_back(node);
        for (int neighbor : graph[node]) {
            if (neighbor != prev) {
                dfs(neighbor, node, ans);
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Map<Integer, List<Integer>> graph = new HashMap();
    
    public int[] restoreArray(int[][] adjacentPairs) {
        for (int[] edge : adjacentPairs) {
            int x = edge[0];
            int y = edge[1];
            
            if (!graph.containsKey(x)) {
                graph.put(x, new ArrayList());
            }
            
            if (!graph.containsKey(y)) {
                graph.put(y, new ArrayList());
            }
            
            graph.get(x).add(y);
            graph.get(y).add(x);
        }
        
        int root = 0;
        for (int num : graph.keySet()) {
            if (graph.get(num).size() == 1) {
                root = num;
                break;
            }
        }
        
        int[] ans = new int[graph.size()];
        dfs(root, Integer.MAX_VALUE, ans, 0);
        return ans;
    }
    
    private void dfs(int node, int prev, int[] ans, int i) {
        ans[i] = node;
        for (int neighbor : graph.get(node)) {
            if (neighbor != prev) {
                dfs(neighbor, node, ans, i + 1);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        
        for x, y in adjacentPairs:
            graph[x].append(y)
            graph[y].append(x)
        
        root = None
        for num in graph:
            if len(graph[num]) == 1:
                root = num
                break
        
        def dfs(node, prev, ans):
            ans.append(node)
            for neighbor in graph[node]:
                if neighbor != prev:
                    dfs(neighbor, node, ans)

        ans = []
        dfs(root, None, ans)
        return ans
```

</details>

<br>

## Approach 2: Iterative, Follow the Path

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;

        for (auto& edge : adjacentPairs) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int root = 0;
        for (auto& pair : graph) {
            if (pair.second.size() == 1) {
                root = pair.first;
                break;
            }
        }
        
        int curr = root;
        vector<int> ans = {root};
        int prev = INT_MAX;
        
        while (ans.size() < graph.size()) {
            for (int neighbor : graph[curr]) {
                if (neighbor != prev) {
                    ans.push_back(neighbor);
                    prev = curr;
                    curr = neighbor;
                    break;
                }
            }
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
    public int[] restoreArray(int[][] adjacentPairs) {
        Map<Integer, List<Integer>> graph = new HashMap();
        
        for (int[] edge : adjacentPairs) {
            int x = edge[0];
            int y = edge[1];
            
            if (!graph.containsKey(x)) {
                graph.put(x, new ArrayList());
            }
            
            if (!graph.containsKey(y)) {
                graph.put(y, new ArrayList());
            }
            
            graph.get(x).add(y);
            graph.get(y).add(x);
        }
        
        int root = 0;
        for (int num : graph.keySet()) {
            if (graph.get(num).size() == 1) {
                root = num;
                break;
            }
        }
        
        int curr = root;
        int[] ans = new int[graph.size()];
        ans[0] = root;
        int i = 1;
        int prev = Integer.MAX_VALUE;
        
        while (i < graph.size()) {
            for (int neighbor : graph.get(curr)) {
                if (neighbor != prev) {
                    ans[i] = neighbor;
                    i++;
                    prev = curr;
                    curr = neighbor;
                    break;
                }
            }
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
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        
        for x, y in adjacentPairs:
            graph[x].append(y)
            graph[y].append(x)
        
        root = None
        for num in graph:
            if len(graph[num]) == 1:
                root = num
                break
        
        curr = root
        ans = [root]
        prev = None

        while len(ans) < len(graph):
            for neighbor in graph[curr]:
                if neighbor != prev:
                    ans.append(neighbor)
                    prev = curr
                    curr = neighbor
                    break

        return ans
```

</details>
