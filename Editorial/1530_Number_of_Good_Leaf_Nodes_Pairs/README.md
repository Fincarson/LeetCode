# 1530. Number of Good Leaf Nodes Pairs

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1530 - Number of Good Leaf Nodes Pairs](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/)

## Problem

You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

### Example 1

```text
Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
```

### Example 2

```text
Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
```

### Example 3

```text
Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].
```

## Constraints

- The number of nodes in the tree is in the range [1, 210].
- 1 <= Node.val <= 100
- 1 <= distance <= 10

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1530. Number of Good Leaf Nodes Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Graph Conversion + BFS | C++, Java, Python3 |
| Post-Order Traversal | C++, Java, Python3 |
| Post-Order Traversal With Prefix Sum Counting | C++, Java, Python3 |

## Approach 1: Graph Conversion + BFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    void traverseTree(TreeNode* currNode, TreeNode* prevNode,
                      unordered_map<TreeNode*, vector<TreeNode*>>& graph,
                      unordered_set<TreeNode*>& leafNodes) {
        if (!currNode) {
            return;
        }
        if (!currNode->left && !currNode->right) {
            leafNodes.insert(currNode);
        }
        if (prevNode) {
            graph[prevNode].push_back(currNode);
            graph[currNode].push_back(prevNode);
        }
        traverseTree(currNode->left, currNode, graph, leafNodes);
        traverseTree(currNode->right, currNode, graph, leafNodes);
    }

public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        unordered_set<TreeNode*> leafNodes;

        traverseTree(root, nullptr, graph, leafNodes);

        int ans = 0;

        for (auto leaf : leafNodes) {
            queue<TreeNode*> bfsQueue;
            unordered_set<TreeNode*> seen;
            bfsQueue.push(leaf);
            seen.insert(leaf);

            // Go through all nodes that are within the given distance of
            // the current leaf node
            for (int i = 0; i <= distance; i++) {
                int size = bfsQueue.size();
                for (int j = 0; j < size; j++) {
                    TreeNode* currNode = bfsQueue.front();
                    bfsQueue.pop();
                    if (leafNodes.count(currNode) && currNode != leaf) {
                        ans++;
                    }
                    if (graph.count(currNode)) {
                        for (auto neighbor : graph[currNode]) {
                            if (!seen.count(neighbor)) {
                                bfsQueue.push(neighbor);
                                seen.insert(neighbor);
                            }
                        }
                    }
                }
            }
        }
        return ans / 2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countPairs(TreeNode root, int distance) {
        Map<TreeNode, List<TreeNode>> graph = new HashMap<>();
        Set<TreeNode> leafNodes = new HashSet<>();

        traverseTree(root, null, graph, leafNodes);

        int ans = 0;

        for (TreeNode leaf : leafNodes) {
            Queue<TreeNode> bfsQueue = new LinkedList<>();
            Set<TreeNode> seen = new HashSet<>();
            bfsQueue.add(leaf);
            seen.add(leaf);
            // Go through all nodes that are within the given distance of
            // the current leaf node
            for (int i = 0; i <= distance; i++) {
                // Clear all nodes in the queue (distance i away from leaf node)
                // Add the nodes' neighbors (distance i+1 away from leaf node)
                int size = bfsQueue.size();
                for (int j = 0; j < size; j++) {
                    // If current node is a new leaf node, add the found pair to our count
                    TreeNode currNode = bfsQueue.remove();
                    if (leafNodes.contains(currNode) && currNode != leaf) {
                        ans++;
                    }
                    if (graph.containsKey(currNode)) {
                        for (TreeNode neighbor : graph.get(currNode)) {
                            if (!seen.contains(neighbor)) {
                                bfsQueue.add(neighbor);
                                seen.add(neighbor);
                            }
                        }
                    }
                }
            }
        }
        return ans / 2;
    }

    private void traverseTree(
        TreeNode currNode,
        TreeNode prevNode,
        Map<TreeNode, List<TreeNode>> graph,
        Set<TreeNode> leafNodes
    ) {
        if (currNode == null) {
            return;
        }
        if (currNode.left == null && currNode.right == null) {
            leafNodes.add(currNode);
        }
        if (prevNode != null) {
            graph.computeIfAbsent(prevNode, k -> new ArrayList<TreeNode>());
            graph.get(prevNode).add(currNode);
            graph.computeIfAbsent(currNode, k -> new ArrayList<TreeNode>());
            graph.get(currNode).add(prevNode);
        }
        traverseTree(currNode.left, currNode, graph, leafNodes);
        traverseTree(currNode.right, currNode, graph, leafNodes);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def _traverse_tree(self, curr_node, prev_node, graph, leaf_nodes):
        if curr_node is None:
            return
        if curr_node.left is None and curr_node.right is None:
            leaf_nodes.add(curr_node)
        if prev_node is not None:
            if prev_node not in graph:
                graph[prev_node] = []
            graph[prev_node].append(curr_node)

            if curr_node not in graph:
                graph[curr_node] = []
            graph[curr_node].append(prev_node)

        self._traverse_tree(curr_node.left, curr_node, graph, leaf_nodes)
        self._traverse_tree(curr_node.right, curr_node, graph, leaf_nodes)

    def countPairs(self, root, distance):
        graph = {}
        leaf_nodes = set()

        self._traverse_tree(root, None, graph, leaf_nodes)

        ans = 0

        for leaf in leaf_nodes:
            bfs_queue = []
            seen = set()
            bfs_queue.append(leaf)
            seen.add(leaf)
            for i in range(distance + 1):
                # Clear all nodes in the queue (distance i away from leaf node)
                # Add the nodes' neighbors (distance i+1 away from leaf node)
                size = len(bfs_queue)
                for j in range(size):
                    curr_node = bfs_queue.pop(0)
                    if curr_node in leaf_nodes and curr_node != leaf:
                        ans += 1
                    if curr_node in graph:
                        for neighbor in graph.get(curr_node):
                            if neighbor not in seen:
                                bfs_queue.append(neighbor)
                                seen.add(neighbor)
        return ans // 2
```

</details>

<br>

## Approach 2: Post-Order Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    vector<int> postOrder(TreeNode* currentNode, int distance) {
        if (!currentNode)
            return vector<int>(12);
        else if (!currentNode->left && !currentNode->right) {
            vector<int> current(12);
            // Leaf node's distance from itself is 0
            current[0] = 1;
            return current;
        }

        // Leaf node count for a given distance i
        vector<int> left = postOrder(currentNode->left, distance);
        vector<int> right = postOrder(currentNode->right, distance);

        vector<int> current(12);

        // Combine the counts from the left and right subtree and shift by
        // +1 distance
        for (int i = 0; i < 10; i++) {
            current[i + 1] = left[i] + right[i];
        }

        // Initialize to total number of good leaf nodes pairs from left and
        // right subtrees.
        current[11] += left[11] + right[11];

        // Iterate through possible leaf node distance pairs
        for (int d1 = 0; d1 <= distance; d1++) {
            for (int d2 = 0; d2 <= distance; d2++) {
                if (2 + d1 + d2 <= distance) {
                    // If the total path distance is less than the given
                    // distance limit, then add to the total number of good
                    // pairs.
                    current[11] += left[d1] * right[d2];
                }
            }
        }

        return current;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        return postOrder(root, distance)[11];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countPairs(TreeNode root, int distance) {
        return postOrder(root, distance)[11];
    }

    private int[] postOrder(TreeNode currentNode, int distance) {
        if (currentNode == null) return new int[12];
        else if (currentNode.left == null && currentNode.right == null) {
            int[] current = new int[12];
            // Leaf node's distance from itself is 0
            current[0] = 1;
            return current;
        }

        // Leaf node count for a given distance i
        int[] left = postOrder(currentNode.left, distance);
        int[] right = postOrder(currentNode.right, distance);

        int[] current = new int[12];

        // Combine the counts from the left and right subtree and shift by
        // +1 distance
        for (int i = 0; i < 10; i++) {
            current[i + 1] += left[i] + right[i];
        }

        // Initialize to total number of good leaf nodes pairs from left and right subtrees.
        current[11] += left[11] + right[11];

        // Iterate through possible leaf node distance pairs
        for (int d1 = 0; d1 <= distance; d1++) {
            for (int d2 = 0; d2 <= distance; d2++) {
                if (2 + d1 + d2 <= distance) {
                    // If the total path distance is less than the given distance limit,
                    // then add to the total number of good pairs
                    current[11] += left[d1] * right[d2];
                }
            }
        }

        return current;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def _post_order(self, current_node, distance):
        if current_node is None:
            return [0] * 12
        elif current_node.left is None and current_node.right is None:
            current = [0] * 12
            # Leaf node's distance from itself is 0
            current[0] = 1
            return current

        # Leaf node count for a given distance i
        left = self._post_order(current_node.left, distance)
        right = self._post_order(current_node.right, distance)

        current = [0] * 12

        # Combine the counts from the left and right subtree and shift by
        # +1 distance
        for i in range(10):
            current[i + 1] += left[i] + right[i]

        # Initialize to total number of good leaf nodes pairs from left and right subtrees.
        current[11] = left[11] + right[11]

        # Iterate through possible leaf node distance pairs
        for d1 in range(distance + 1):
            for d2 in range(distance + 1):
                if 2 + d1 + d2 <= distance:
                    # If the total path distance is less than the given distance limit,
                    # then add to he total number of good pairs
                    current[11] += left[d1] * right[d2]

        return current

    def countPairs(self, root: TreeNode, distance: int) -> int:
        return self._post_order(root, distance)[11]
```

</details>

<br>

## Approach 3: Post-Order Traversal With Prefix Sum Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    vector<int> postOrder(TreeNode* currentNode, int distance) {
        if (!currentNode)
            return vector<int>(12);
        else if (!currentNode->left && !currentNode->right) {
            vector<int> current(12);
            // Leaf node's distance from itself is 0
            current[0] = 1;
            return current;
        }

        // Leaf node count for a given distance i
        vector<int> left = postOrder(currentNode->left, distance);
        vector<int> right = postOrder(currentNode->right, distance);

        vector<int> current(12);

        // Combine the counts from the left and right subtree and shift by
        // +1 distance
        for (int i = 0; i < 10; i++) {
            current[i + 1] = left[i] + right[i];
        }

        // Initialize to total number of good leaf nodes pairs from left and
        // right subtrees.
        current[11] += left[11] + right[11];

        // Count all good leaf node distance pairs
        int prefixSum = 0;
        int i = 0;
        for (int d2 = distance - 2; d2 >= 0; d2--) {
            prefixSum += left[i++];
            current[11] += prefixSum * right[d2];
        }

        return current;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        return postOrder(root, distance)[11];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countPairs(TreeNode root, int distance) {
        return postOrder(root, distance)[11];
    }

    private int[] postOrder(TreeNode currentNode, int distance) {
        if (currentNode == null) return new int[12];
        else if (currentNode.left == null && currentNode.right == null) {
            int[] current = new int[12];
            // Leaf node's distance from itself is 0
            current[0] = 1;
            return current;
        }

        // Leaf node count for a given distance i
        int[] left = postOrder(currentNode.left, distance);
        int[] right = postOrder(currentNode.right, distance);

        int[] current = new int[12];

        // Combine the counts from the left and right subtree and shift by
        // +1 distance
        for (int i = 0; i < 10; i++) {
            current[i + 1] += left[i] + right[i];
        }

        // Initialize to total number of good leaf nodes pairs from left and right subtrees.
        current[11] += left[11] + right[11];

        // Count all good leaf node distance pairs
        int prefixSum = 0;
        int i = 0;
        for (int d2 = distance - 2; d2 >= 0; d2--) {
            prefixSum += left[i++];
            current[11] += prefixSum * right[d2];
        }

        return current;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def _post_order(self, current_node, distance):
        if current_node is None:
            return [0] * 12
        elif current_node.left is None and current_node.right is None:
            current = [0] * 12
            # Leaf node's distance from itself is 0
            current[0] = 1
            return current

        # Leaf node count for a given distance i
        left = self._post_order(current_node.left, distance)
        right = self._post_order(current_node.right, distance)

        current = [0] * 12

        # Combine the counts from the left and right subtree and shift by
        # +1 distance
        for i in range(10):
            current[i + 1] += left[i] + right[i]

        # Initialize to total number of good leaf nodes pairs from left and right subtrees.
        current[11] = left[11] + right[11]

        # Count all good leaf node distance pairs
        prefix_sum = 0
        i = 0
        for d2 in range(distance - 2, -1, -1):
            prefix_sum += left[i]
            current[11] += prefix_sum * right[d2]
            i += 1

        return current

    def countPairs(self, root: TreeNode, distance: int) -> int:
        return self._post_order(root, distance)[11]
```

</details>
