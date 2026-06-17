# 863. All Nodes Distance K in Binary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 863 - All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

## Problem

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

### Example 1

```text
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
```

### Example 2

```text
Input: root = [1], target = 1, k = 3
Output: []
```

## Constraints

- The number of nodes in the tree is in the range [1, 500].
- 0 <= Node.val <= 500
- All the values Node.val are unique.
- target is the value of one of the nodes in the tree.
- 0 <= k <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Amount of Time for Binary Tree to Be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 863. All Nodes Distance K in Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Implementing Parent Pointers | C++, Java, Python3 |
| Depth-First Search on Equivalent Graph | C++, Java, Python3 |
| Breadth-First Search on Equivalent Graph | C++, Java, Python3 |

## Approach 1: Implementing Parent Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Recursively add a parent pointer to each node.
        add_parent(root, nullptr);

        vector<int> answer;
        unordered_set<TreeNode*> visited;
        dfs(target, k, answer, visited);

        return answer;
    }

private:
    unordered_map<TreeNode*, TreeNode*> parent;

    void add_parent(TreeNode* cur, TreeNode* parent) {
        if (cur) {
            this->parent[cur] = parent;
            add_parent(cur->left, cur);
            add_parent(cur->right, cur);
        }
    }

    void dfs(TreeNode* cur, int distance, vector<int>& answer,
             unordered_set<TreeNode*>& visited) {
        if (!cur || visited.count(cur)) return;

        visited.insert(cur);
        if (distance == 0) {
            answer.push_back(cur->val);
            return;
        }

        dfs(parent[cur], distance - 1, answer, visited);
        dfs(cur->left, distance - 1, answer, visited);
        dfs(cur->right, distance - 1, answer, visited);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    Map<TreeNode, TreeNode> parent;

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        parent = new HashMap<>();
        addParent(root, null);

        List<Integer> answer = new ArrayList<>();
        Set<TreeNode> visited = new HashSet<>();
        dfs(target, k, answer, visited);

        return answer;
    }

    private void addParent(TreeNode cur, TreeNode parent) {
        if (cur != null) {
            this.parent.put(cur, parent);
            addParent(cur.left, cur);
            addParent(cur.right, cur);
        }
    }

    private void dfs(
        TreeNode cur,
        int distance,
        List<Integer> answer,
        Set<TreeNode> visited
    ) {
        if (cur == null || visited.contains(cur)) {
            return;
        }

        visited.add(cur);
        if (distance == 0) {
            answer.add(cur.val);
            return;
        }

        dfs(parent.get(cur), distance - 1, answer, visited);
        dfs(cur.left, distance - 1, answer, visited);
        dfs(cur.right, distance - 1, answer, visited);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        # Recursively add a parent pointer to each node.
        def add_parent(cur, parent):
            if cur:
                cur.parent = parent
                add_parent(cur.left, cur)
                add_parent(cur.right, cur)

        add_parent(root, None)

        answer = []
        visited = set()

        def dfs(cur, distance):
            if not cur or cur in visited:
                return
            visited.add(cur)
            if distance == 0:
                answer.append(cur.val)
                return
            dfs(cur.parent, distance - 1)
            dfs(cur.left, distance - 1)
            dfs(cur.right, distance - 1)

        dfs(target, k)

        return answer
```

</details>

<br>

## Approach 2: Depth-First Search on Equivalent Graph

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> result;
    unordered_set<int> visited;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(root, nullptr);

        visited.insert(target->val);
        dfs(target->val, 0, K);

        return result;
    }

    // Recursively build the undirected graph from the given binary tree.
    void buildGraph(TreeNode* current, TreeNode* parent) {
        if (current != nullptr && parent != nullptr) {
            graph[current->val].push_back(parent->val);
            graph[parent->val].push_back(current->val);
        }
        if (current->left != nullptr) {
            buildGraph(current->left, current);
        }
        if (current->right != nullptr) {
            buildGraph(current->right, current);
        }
    }

    void dfs(int current, int distance, int K) {
        if (distance == K) {
            result.push_back(current);
            return;
        }

        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                dfs(neighbor, distance + 1, K);
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

    Map<Integer, List<Integer>> graph;
    List<Integer> answer;
    Set<Integer> visited;

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        graph = new HashMap<>();
        buildGraph(root, null);

        answer = new ArrayList<>();
        visited = new HashSet<>();
        visited.add(target.val);

        dfs(target.val, 0, k);

        return answer;
    }

    // Recursively build the undirected graph from the given binary tree.
    private void buildGraph(TreeNode cur, TreeNode parent) {
        if (cur != null && parent != null) {
            graph
                .computeIfAbsent(cur.val, k -> new ArrayList<>())
                .add(parent.val);
            graph
                .computeIfAbsent(parent.val, k -> new ArrayList<>())
                .add(cur.val);
        }
        if (cur.left != null) {
            buildGraph(cur.left, cur);
        }
        if (cur.right != null) {
            buildGraph(cur.right, cur);
        }
    }

    private void dfs(int cur, int distance, int k) {
        if (distance == k) {
            answer.add(cur);
            return;
        }
        for (int neighbor : graph.getOrDefault(cur, new ArrayList<>())) {
            if (!visited.contains(neighbor)) {
                visited.add(neighbor);
                dfs(neighbor, distance + 1, k);
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
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        graph = collections.defaultdict(list)

        # Recursively build the undirected graph from the given binary tree.
        def build_graph(cur, parent):
            if cur and parent:
                graph[cur.val].append(parent.val)
                graph[parent.val].append(cur.val)
            if cur.left:
                build_graph(cur.left, cur)
            if cur.right:
                build_graph(cur.right, cur)

        build_graph(root, None)

        answer = []
        visited = set([target.val])

        def dfs(cur, distance):
            if distance == k:
                answer.append(cur)
                return
            for neighbor in graph[cur]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    dfs(neighbor, distance + 1)

        dfs(target.val, 0)

        return answer
```

</details>

<br>

## Approach 3: Breadth-First Search on Equivalent Graph

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph;

        // start building graph
        dfsBuild(root, nullptr, graph);

        vector<int> answer;
        unordered_set<int> visited;

        // start building queue for BFS, starting from target node
        queue<pair<int, int>> bfs_queue;
        bfs_queue.push({target->val, 0});
        visited.insert(target->val);

        while (!bfs_queue.empty()) {
            pair<int, int> current_node = bfs_queue.front();
            bfs_queue.pop();

            int node_val = current_node.first;
            int dist = current_node.second;

            if (dist == k) {
                answer.push_back(node_val);
                continue;
            }
            for (auto& neighbor : graph[node_val]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    bfs_queue.push({neighbor, dist + 1});
                }
            }
        }
        return answer;
    }

private:
    void dfsBuild(TreeNode* cur_node, TreeNode* parent_node,
                  unordered_map<int, vector<int>>& graph) {
        if (cur_node != nullptr && parent_node != nullptr) {
            graph[cur_node->val].push_back(parent_node->val);
            graph[parent_node->val].push_back(cur_node->val);
        }

        if (cur_node != nullptr && cur_node->left != nullptr) {
            dfsBuild(cur_node->left, cur_node, graph);
        }

        if (cur_node != nullptr && cur_node->right != nullptr) {
            dfsBuild(cur_node->right, cur_node, graph);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        dfsBuild(root, null, graph);

        List<Integer> answer = new ArrayList<>();
        Set<Integer> visited = new HashSet<>();
        Queue<int[]> queue = new LinkedList<>();

        // Add the target node to the queue with a distance of 0
        queue.add(new int[] { target.val, 0 });
        visited.add(target.val);

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int node = cur[0], distance = cur[1];

            // If the current node is at distance k from target,
            // add it to the answer list and continue to the next node.
            if (distance == k) {
                answer.add(node);
                continue;
            }

            // Add all unvisited neighbors of the current node to the queue.
            for (int neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.add(new int[] { neighbor, distance + 1 });
                }
            }
        }

        return answer;
    }

    // Recursively build the undirected graph from the given binary tree.
    private void dfsBuild(
        TreeNode cur,
        TreeNode parent,
        Map<Integer, List<Integer>> graph
    ) {
        if (cur != null && parent != null) {
            int curVal = cur.val, parentVal = parent.val;
            graph.putIfAbsent(curVal, new ArrayList<>());
            graph.putIfAbsent(parentVal, new ArrayList<>());
            graph.get(curVal).add(parentVal);
            graph.get(parentVal).add(curVal);
        }

        if (cur != null && cur.left != null) {
            dfsBuild(cur.left, cur, graph);
        }

        if (cur != null && cur.right != null) {
            dfsBuild(cur.right, cur, graph);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        graph = collections.defaultdict(list)

        # Recursively build the undirected graph from the given binary tree.
        def build_graph(cur, parent):
            if cur and parent:
                graph[cur.val].append(parent.val)
                graph[parent.val].append(cur.val)
            if cur.left:
                build_graph(cur.left, cur)
            if cur.right:
                build_graph(cur.right, cur)

        build_graph(root, None)

        answer = []
        visited = set([target.val])

        # Add the target node to the queue with a distance of 0
        queue = collections.deque([(target.val, 0)])
        while queue:
            cur, distance = queue.popleft()

            # If the current node is at distance k from target,
            # add it to the answer list and continue to the next node.
            if distance == k:
                answer.append(cur)
                continue

            # Add all unvisited neighbors of the current node to the queue.
            for neighbor in graph[cur]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, distance + 1))

        return answer
```

</details>
