# 2196. Create Binary Tree From Descriptions

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/create-binary-tree-from-descriptions/)  
`Array` `Hash Table` `Tree` `Binary Tree`

**Problem Link:** [LeetCode 2196 - Create Binary Tree From Descriptions](https://leetcode.com/problems/create-binary-tree-from-descriptions/)

## Problem

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

- If isLefti == 1, then childi is the left child of parenti.
- If isLefti == 0, then childi is the right child of parenti.

Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

### Example 1

```text
Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
```

### Example 2

```text
Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
```

## Constraints

- 1 <= descriptions.length <= 104
- descriptions[i].length == 3
- 1 <= parenti, childi <= 105
- 0 <= isLefti <= 1
- The binary tree described by descriptions is valid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number Of Ways To Reconstruct A Tree](https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2196. Create Binary Tree From Descriptions

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Convert to Graph with Breadth First Search | C++, Java, Python3 |
| Convert to Graph with Depth First Search | C++, Java, Python3 |
| Constructing Tree From Directly Map and TreeNode Object | C++, Java, Python3 |

## Approach 1: Convert to Graph with Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Sets to track unique children and parents
        unordered_set<int> children, parents;
        // Map to store parent to children relationships
        unordered_map<int, vector<pair<int, int>>> parentToChildren;

        // Build graph from parent to child, and add nodes to HashSets
        for (auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            parents.insert(parent);
            parents.insert(child);
            children.insert(child);
            parentToChildren[parent].emplace_back(child, isLeft);
        }

        // Find the root node by checking which node is in parents but not in
        // children
        for (auto it = parents.begin(); it != parents.end();) {
            if (children.find(*it) != children.end()) {
                it = parents.erase(it);
            } else {
                ++it;
            }
        }
        TreeNode* root = new TreeNode(*parents.begin());

        // Starting from root, use BFS to construct binary tree
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* parent = queue.front();
            queue.pop();
            // Iterate over children of current parent
            for (auto& childInfo : parentToChildren[parent->val]) {
                int childValue = childInfo.first, isLeft = childInfo.second;
                TreeNode* child = new TreeNode(childValue);
                queue.push(child);
                // Attach child node to its parent based on isLeft flag
                if (isLeft == 1) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }
        }

        return root;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode createBinaryTree(int[][] descriptions) {
        // Sets to track unique children and parents
        Set<Integer> children = new HashSet<>(), parents = new HashSet<>();
        // Map to store parent to children relationships
        Map<Integer, List<int[]>> parentToChildren = new HashMap<>();

        // Build graph from parent to child, and add nodes to HashSets
        for (int[] d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            parents.add(parent);
            parents.add(child);
            children.add(child);
            parentToChildren
                .computeIfAbsent(parent, l -> new ArrayList<>())
                .add(new int[] { child, isLeft });
        }

        // Find the root node by checking which node is in parents but not in children
        parents.removeAll(children);
        TreeNode root = new TreeNode(parents.iterator().next());

        // Starting from root, use BFS to construct binary tree
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode parent = queue.poll();
            // Iterate over children of current parent
            for (int[] childInfo : parentToChildren.getOrDefault(
                parent.val,
                Collections.emptyList()
            )) {
                int childValue = childInfo[0], isLeft = childInfo[1];
                TreeNode child = new TreeNode(childValue);
                queue.offer(child);
                // Attach child node to its parent based on isLeft flag
                if (isLeft == 1) {
                    parent.left = child;
                } else {
                    parent.right = child;
                }
            }
        }

        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def createBinaryTree(
        self, descriptions: List[List[int]]
    ) -> Optional[TreeNode]:
        # Sets to track unique children and parents
        children = set()
        parents = set()
        # Dictionary to store parent to children relationships
        parentToChildren = {}

        # Build graph from parent to child, and add nodes to sets
        for d in descriptions:
            parent, child, isLeft = d
            parents.add(parent)
            parents.add(child)
            children.add(child)
            if parent not in parentToChildren:
                parentToChildren[parent] = []
            parentToChildren[parent].append((child, isLeft))

        # Find the root node by checking which node is
        # in parents but not in children
        for parent in parents.copy():
            if parent in children:
                parents.remove(parent)

        root = TreeNode(next(iter(parents)))

        # Starting from root, use BFS to construct binary tree
        queue = deque([root])

        while queue:
            parent = queue.popleft()
            # Iterate over children of current parent
            for childValue, isLeft in parentToChildren.get(parent.val, []):
                child = TreeNode(childValue)
                queue.append(child)
                # Attach child node to its parent based on isLeft flag
                if isLeft == 1:
                    parent.left = child
                else:
                    parent.right = child

        return root
```

</details>

<br>

## Approach 2: Convert to Graph with Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Step 1: Organize data
        unordered_map<int, vector<pair<int, bool>>> parentToChildren;
        unordered_set<int> allNodes;
        unordered_set<int> children;

        for (auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2];

            parentToChildren[parent].push_back({child, isLeft});
            allNodes.insert(parent);
            allNodes.insert(child);
            children.insert(child);
        }

        // Step 2: Find the root
        int rootVal = 0;
        for (int node : allNodes) {
            if (!children.contains(node)) {
                rootVal = node;
                break;
            }
        }

        // Step 3 & 4: Build the tree using DFS
        return dfs(parentToChildren, rootVal);
    }

private:
    TreeNode* dfs(unordered_map<int, vector<pair<int, bool>>>& parentToChildren,
                  int val) {
        // Create new TreeNode for current value
        TreeNode* node = new TreeNode(val);

        // If current node has children, recursively build them
        if (parentToChildren.find(val) != parentToChildren.end()) {
            for (auto& child_info : parentToChildren[val]) {
                int child = child_info.first;
                bool isLeft = child_info.second;

                // Attach child node based on isLeft flag
                if (isLeft) {
                    node->left = dfs(parentToChildren, child);
                } else {
                    node->right = dfs(parentToChildren, child);
                }
            }
        }

        return node;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode createBinaryTree(int[][] descriptions) {
        // Step 1: Organize data
        Map<Integer, List<int[]>> parentToChildren = new HashMap<>();
        Set<Integer> allNodes = new HashSet<>();
        Set<Integer> children = new HashSet<>();

        for (int[] desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            // Store child information under parent node
            if (!parentToChildren.containsKey(parent)) {
                parentToChildren.put(parent, new ArrayList<>());
            }
            parentToChildren.get(parent).add(new int[] { child, isLeft });
            allNodes.add(parent);
            allNodes.add(child);
            children.add(child);
        }

        // Step 2: Find the root
        int rootVal = 0;
        for (int node : allNodes) {
            if (!children.contains(node)) {
                rootVal = node;
                break;
            }
        }

        // Step 3 & 4: Build the tree using DFS
        return dfs(parentToChildren, rootVal);
    }

    // DFS function to recursively build binary tree
    private TreeNode dfs(Map<Integer, List<int[]>> parentToChildren, int val) {
        // Create new TreeNode for current value
        TreeNode node = new TreeNode(val);

        // If current node has children, recursively build them
        if (parentToChildren.containsKey(val)) {
            for (int[] childInfo : parentToChildren.get(val)) {
                int child = childInfo[0];
                int isLeft = childInfo[1];

                // Attach child node based on isLeft flag
                if (isLeft == 1) {
                    node.left = dfs(parentToChildren, child);
                } else {
                    node.right = dfs(parentToChildren, child);
                }
            }
        }

        return node;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def createBinaryTree(
        self, descriptions: List[List[int]]
    ) -> Optional[TreeNode]:
        # Step 1: Organize data
        parent_to_children = {}
        all_nodes = set()
        children = set()

        for parent, child, is_left in descriptions:
            # Store child information under parent node
            if parent not in parent_to_children:
                parent_to_children[parent] = []
            parent_to_children[parent].append((child, is_left))
            all_nodes.add(parent)
            all_nodes.add(child)
            children.add(child)

        # Step 2: Find the root
        root_val = (all_nodes - children).pop()

        # Step 3 & 4: Build the tree using DFS
        def _dfs(val):
            # Create new TreeNode for current value
            node = TreeNode(val)

            # If current node has children, recursively build them
            if val in parent_to_children:
                for child, is_left in parent_to_children[val]:
                    # Attach child node based on is_left flag
                    if is_left:
                        node.left = _dfs(child)
                    else:
                        node.right = _dfs(child)
            return node

        return _dfs(root_val)
```

</details>

<br>

## Approach 3: Constructing Tree From Directly Map and TreeNode Object

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Maps values to TreeNode pointers
        unordered_map<int, TreeNode*> nodeMap;
        // Stores values which are children in the descriptions
        unordered_set<int> children;

        // Iterate through descriptions to create nodes and set up tree
        // structure
        for (const auto& description : descriptions) {
            // Extract parent value, child value, and whether it is a
            // left child (1) or right child (0)
            int parentValue = description[0];
            int childValue = description[1];
            bool isLeft = description[2];

            // Create parent and child nodes if not already created
            if (nodeMap.count(parentValue) == 0) {
                nodeMap[parentValue] = new TreeNode(parentValue);
            }
            if (nodeMap.count(childValue) == 0) {
                nodeMap[childValue] = new TreeNode(childValue);
            }

            // Attach child node to parent's left or right branch
            if (isLeft) {
                nodeMap[parentValue]->left = nodeMap[childValue];
            } else {
                nodeMap[parentValue]->right = nodeMap[childValue];
            }

            // Mark child as a child in the set
            children.insert(childValue);
        }

        // Find and return the root node
        for (auto& entry : nodeMap) {
            auto& value = entry.first;
            auto& node = entry.second;
            // Root node found
            if (children.find(value) == children.end()) {
                return node;
            }
        }

        // Should not occur according to problem statement
        return nullptr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode createBinaryTree(int[][] descriptions) {
        // Maps values to TreeNode pointers
        Map<Integer, TreeNode> nodeMap = new HashMap<>();

        // Stores values which are children in the descriptions
        Set<Integer> children = new HashSet<>();

        // Iterate through descriptions to create nodes and set up tree structure
        for (int[] description : descriptions) {
            // Extract parent value, child value, and whether it is a
            // left child (1) or right child (0)
            int parentValue = description[0];
            int childValue = description[1];
            boolean isLeft = description[2] == 1;

            // Create parent and child nodes if not already created
            if (!nodeMap.containsKey(parentValue)) {
                nodeMap.put(parentValue, new TreeNode(parentValue));
            }
            if (!nodeMap.containsKey(childValue)) {
                nodeMap.put(childValue, new TreeNode(childValue));
            }

            // Attach child node to parent's left or right branch
            if (isLeft) {
                nodeMap.get(parentValue).left = nodeMap.get(childValue);
            } else {
                nodeMap.get(parentValue).right = nodeMap.get(childValue);
            }

            // Mark child as a child in the set
            children.add(childValue);
        }

        // Find and return the root node
        for (TreeNode node : nodeMap.values()) {
            if (!children.contains(node.val)) {
                return node; // Root node found
            }
        }

        return null; // Should not occur according to problem statement
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def createBinaryTree(
        self, descriptions: List[List[int]]
    ) -> Optional[TreeNode]:
        # Maps values to TreeNode pointers
        node_map = {}

        # Stores values which are children in the descriptions
        children = set()

        # Iterate through description to create nodes and set up tree structure
        for description in descriptions:
            # Extract parent value, child value, and whether
            # it is a left child (1) or right child (0)
            parent_value = description[0]
            child_value = description[1]
            is_left = bool(description[2])

            # Create parent and child nodes if not already created
            if parent_value not in node_map:
                node_map[parent_value] = TreeNode(parent_value)
            if child_value not in node_map:
                node_map[child_value] = TreeNode(child_value)

            # Attach child node to parent's left or right branch
            if is_left:
                node_map[parent_value].left = node_map[child_value]
            else:
                node_map[parent_value].right = node_map[child_value]

            # Mark child as a child in the set
            children.add(child_value)

        # Find and return the root node
        for node in node_map.values():
            if node.val not in children:
                return node  # Root node found

        return None  # Should not occur according to problem statement
```

</details>
