# 2096. Step-By-Step Directions From a Binary Tree Node to Another

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)  
`String` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 2096 - Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)

## Problem

You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

- 'L' means to go from a node to its left child node.
- 'R' means to go from a node to its right child node.
- 'U' means to go from a node to its parent node.

Return the step-by-step directions of the shortest path from node s to node t.

### Example 1

```text
Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 Ã¢â€ â€™ 1 Ã¢â€ â€™ 5 Ã¢â€ â€™ 2 Ã¢â€ â€™ 6.
```

### Example 2

```text
Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 Ã¢â€ â€™ 1.
```

## Constraints

- The number of nodes in the tree is n.
- 2 <= n <= 105
- 1 <= Node.val <= n
- All the values in the tree are unique.
- 1 <= startValue, destValue <= n
- startValue != destValue

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Path Sum II](https://leetcode.com/problems/path-sum-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find Distance in a Binary Tree](https://leetcode.com/problems/find-distance-in-a-binary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2096. Step-By-Step Directions From a Binary Tree Node to Another

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| BFS + DFS | C++, Java, Python3 |
| LCA + DFS | C++, Java, Python3 |
| LCA + DFS (Optimized) | C++, Java, Python3 |

## Approach 1: BFS + DFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Map to store parent nodes
        unordered_map<int, TreeNode*> parentMap;

        // Find the start node and populate parent map
        TreeNode* startNode = findStartNode(root, startValue);
        populateParentMap(root, parentMap);

        // Perform BFS to find the path
        queue<TreeNode*> q;
        q.push(startNode);
        unordered_set<TreeNode*> visitedNodes;
        // Key: next node, Value: <current node, direction>
        unordered_map<TreeNode*, pair<TreeNode*, string>> pathTracker;
        visitedNodes.insert(startNode);

        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();

            // If destination is reached, return the path
            if (currentNode->val == destValue) {
                return backtrackPath(currentNode, pathTracker);
            }

            // Check and add parent node
            if (parentMap.find(currentNode->val) != parentMap.end()) {
                TreeNode* parentNode = parentMap[currentNode->val];
                if (visitedNodes.find(parentNode) == visitedNodes.end()) {
                    q.push(parentNode);
                    pathTracker[parentNode] = {currentNode, "U"};
                    visitedNodes.insert(parentNode);
                }
            }

            // Check and add left child
            if (currentNode->left != nullptr &&
                visitedNodes.find(currentNode->left) == visitedNodes.end()) {
                q.push(currentNode->left);
                pathTracker[currentNode->left] = {currentNode, "L"};
                visitedNodes.insert(currentNode->left);
            }

            // Check and add right child
            if (currentNode->right != nullptr &&
                visitedNodes.find(currentNode->right) == visitedNodes.end()) {
                q.push(currentNode->right);
                pathTracker[currentNode->right] = {currentNode, "R"};
                visitedNodes.insert(currentNode->right);
            }
        }

        // This line should never be reached if the tree is valid
        return "";
    }

private:
    string backtrackPath(
        TreeNode* node,
        unordered_map<TreeNode*, pair<TreeNode*, string>> pathTracker) {
        string path;
        // Construct the path
        while (pathTracker.count(node)) {
            // Add the directions in reverse order and
            // move on to the previous node
            path += pathTracker[node].second;
            node = pathTracker[node].first;
        }
        reverse(path.begin(), path.end());
        return path;
    }

    void populateParentMap(TreeNode* node,
                           unordered_map<int, TreeNode*>& parentMap) {
        if (node == nullptr) return;

        // Add children to the map and recurse further
        if (node->left != nullptr) {
            parentMap[node->left->val] = node;
            populateParentMap(node->left, parentMap);
        }

        if (node->right != nullptr) {
            parentMap[node->right->val] = node;
            populateParentMap(node->right, parentMap);
        }
    }

    TreeNode* findStartNode(TreeNode* node, int startValue) {
        if (node == nullptr) return nullptr;

        if (node->val == startValue) return node;

        TreeNode* leftResult = findStartNode(node->left, startValue);

        // If left subtree returns a node, it must be StartNode. Return it
        // Otherwise, return whatever is returned by right subtree.
        if (leftResult != nullptr) return leftResult;
        return findStartNode(node->right, startValue);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String getDirections(TreeNode root, int startValue, int destValue) {
        // Map to store parent nodes
        Map<Integer, TreeNode> parentMap = new HashMap<>();

        // Find the start node and populate parent map
        TreeNode startNode = findStartNode(root, startValue);
        populateParentMap(root, parentMap);

        // Perform BFS to find the path
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(startNode);
        Set<TreeNode> visitedNodes = new HashSet<>();
        // Key: next node, Value: <current node, direction>
        Map<TreeNode, Pair<TreeNode, String>> pathTracker = new HashMap<>();
        visitedNodes.add(startNode);

        while (!queue.isEmpty()) {
            TreeNode currentNode = queue.poll();

            // If destination is reached, return the path
            if (currentNode.val == destValue) {
                return backtrackPath(currentNode, pathTracker);
            }

            // Check and add parent node
            if (parentMap.containsKey(currentNode.val)) {
                TreeNode parentNode = parentMap.get(currentNode.val);
                if (!visitedNodes.contains(parentNode)) {
                    queue.add(parentNode);
                    pathTracker.put(parentNode, new Pair(currentNode, "U"));
                    visitedNodes.add(parentNode);
                }
            }

            // Check and add left child
            if (
                currentNode.left != null &&
                !visitedNodes.contains(currentNode.left)
            ) {
                queue.add(currentNode.left);
                pathTracker.put(currentNode.left, new Pair(currentNode, "L"));
                visitedNodes.add(currentNode.left);
            }

            // Check and add right child
            if (
                currentNode.right != null &&
                !visitedNodes.contains(currentNode.right)
            ) {
                queue.add(currentNode.right);
                pathTracker.put(currentNode.right, new Pair(currentNode, "R"));
                visitedNodes.add(currentNode.right);
            }
        }

        // This line should never be reached if the tree is valid
        return "";
    }

    private String backtrackPath(
        TreeNode node,
        Map<TreeNode, Pair<TreeNode, String>> pathTracker
    ) {
        StringBuilder path = new StringBuilder();

        // Construct the path
        while (pathTracker.containsKey(node)) {
            // Add the directions in reverse order and move on to the previous node
            path.append(pathTracker.get(node).getValue());
            node = pathTracker.get(node).getKey();
        }

        // Reverse the path
        path.reverse();

        return path.toString();
    }

    private void populateParentMap(
        TreeNode node,
        Map<Integer, TreeNode> parentMap
    ) {
        if (node == null) return;

        // Add children to the map and recurse further
        if (node.left != null) {
            parentMap.put(node.left.val, node);
            populateParentMap(node.left, parentMap);
        }

        if (node.right != null) {
            parentMap.put(node.right.val, node);
            populateParentMap(node.right, parentMap);
        }
    }

    private TreeNode findStartNode(TreeNode node, int startValue) {
        if (node == null) return null;

        if (node.val == startValue) return node;

        TreeNode leftResult = findStartNode(node.left, startValue);

        // If left subtree returns a node, it must be StartNode. Return it
        // Otherwise, return whatever is returned by right subtree.
        if (leftResult != null) return leftResult;
        return findStartNode(node.right, startValue);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getDirections(
        self, root: TreeNode, startValue: int, destValue: int
    ) -> str:
        # Map to store parent nodes
        parent_map = {}

        # Find the start node and populate parent map
        start_node = self._find_start_node(root, startValue)
        self._populate_parent_map(root, parent_map)

        # Perform BFS to find the path
        q = deque([start_node])
        visited_nodes = set()
        # Key: next node, Value: <current node, direction>
        path_tracker = {}
        visited_nodes.add(start_node)

        while q:
            current_element = q.popleft()

            # If destination is reached, return the path
            if current_element.val == destValue:
                return self._backtrack_path(current_element, path_tracker)

            # Check and add parent node
            if current_element.val in parent_map:
                parent_node = parent_map[current_element.val]
                if parent_node not in visited_nodes:
                    q.append(parent_node)
                    path_tracker[parent_node] = (current_element, "U")
                    visited_nodes.add(parent_node)

            # Check and add left child
            if (
                current_element.left
                and current_element.left not in visited_nodes
            ):
                q.append(current_element.left)
                path_tracker[current_element.left] = (current_element, "L")
                visited_nodes.add(current_element.left)

            # Check and add right child
            if (
                current_element.right
                and current_element.right not in visited_nodes
            ):
                q.append(current_element.right)
                path_tracker[current_element.right] = (current_element, "R")
                visited_nodes.add(current_element.right)

        # This line should never be reached if the tree is valid
        return ""

    def _backtrack_path(self, node, path_tracker):
        path = []
        # Construct the path
        while node in path_tracker:
            # Add the directions in reverse order and move on to the previous node
            path.append(path_tracker[node][1])
            node = path_tracker[node][0]
        path.reverse()
        return "".join(path)

    def _populate_parent_map(self, node, parent_map):
        if not node:
            return

        # Add children to the map and recurse further
        if node.left:
            parent_map[node.left.val] = node
            self._populate_parent_map(node.left, parent_map)

        if node.right:
            parent_map[node.right.val] = node
            self._populate_parent_map(node.right, parent_map)

    def _find_start_node(self, node, start_value):
        if not node:
            return None

        if node.val == start_value:
            return node

        left_result = self._find_start_node(node.left, start_value)

        # If left subtree returns a node, it must be StartNode. Return it
        # Otherwise, return whatever is returned by right subtree.
        if left_result:
            return left_result
        return self._find_start_node(node.right, start_value)
```

</details>

<br>

## Approach 2: LCA + DFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Find the Lowest Common Ancestor (LCA) of start and destination nodes
        TreeNode* lowestCommonAncestor =
            findLowestCommonAncestor(root, startValue, destValue);

        string pathToStart;
        string pathToDest;

        // Find paths from LCA to start and destination nodes
        findPath(lowestCommonAncestor, startValue, pathToStart);
        findPath(lowestCommonAncestor, destValue, pathToDest);

        string directions;

        // Add "U" for each step to go up from start to LCA
        directions.append(pathToStart.length(), 'U');

        // Append the path from LCA to destination
        directions.append(pathToDest);

        return directions;
    }

private:
    TreeNode* findLowestCommonAncestor(TreeNode* node, int value1, int value2) {
        if (node == nullptr) return nullptr;

        if (node->val == value1 || node->val == value2) return node;

        TreeNode* leftLCA =
            findLowestCommonAncestor(node->left, value1, value2);
        TreeNode* rightLCA =
            findLowestCommonAncestor(node->right, value1, value2);

        if (leftLCA == nullptr)
            return rightLCA;
        else if (rightLCA == nullptr)
            return leftLCA;
        else
            return node;  // Both values found, this is the LCA
    }

    bool findPath(TreeNode* node, int targetValue, string& path) {
        if (node == nullptr) return false;

        if (node->val == targetValue) return true;

        // Try left subtree
        path.push_back('L');
        if (findPath(node->left, targetValue, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        // Try right subtree
        path.push_back('R');
        if (findPath(node->right, targetValue, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String getDirections(TreeNode root, int startValue, int destValue) {
        // Find the Lowest Common Ancestor (LCA) of start and destination nodes
        TreeNode lowestCommonAncestor = findLowestCommonAncestor(
            root,
            startValue,
            destValue
        );

        StringBuilder pathToStart = new StringBuilder();
        StringBuilder pathToDest = new StringBuilder();

        // Find paths from LCA to start and destination nodes
        findPath(lowestCommonAncestor, startValue, pathToStart);
        findPath(lowestCommonAncestor, destValue, pathToDest);

        StringBuilder directions = new StringBuilder();

        // Add "U" for each step to go up from start to LCA
        directions.append("U".repeat(pathToStart.length()));

        // Append the path from LCA to destination
        directions.append(pathToDest);

        return directions.toString();
    }

    private TreeNode findLowestCommonAncestor(
        TreeNode node,
        int value1,
        int value2
    ) {
        if (node == null) return null;

        if (node.val == value1 || node.val == value2) return node;

        TreeNode leftLCA = findLowestCommonAncestor(node.left, value1, value2);
        TreeNode rightLCA = findLowestCommonAncestor(
            node.right,
            value1,
            value2
        );

        if (leftLCA == null) return rightLCA;
        else if (rightLCA == null) return leftLCA;
        else return node; // Both values found, this is the LCA
    }

    private boolean findPath(
        TreeNode node,
        int targetValue,
        StringBuilder path
    ) {
        if (node == null) return false;

        if (node.val == targetValue) return true;

        // Try left subtree
        path.append("L");
        if (findPath(node.left, targetValue, path)) {
            return true;
        }
        path.setLength(path.length() - 1); // Remove last character

        // Try right subtree
        path.append("R");
        if (findPath(node.right, targetValue, path)) {
            return true;
        }
        path.setLength(path.length() - 1); // Remove last character

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getDirections(
        self, root: TreeNode, startValue: int, destValue: int
    ) -> str:
        # Find the Lowest Common Ancestor (LCA) of start and destination nodes
        lowest_common_ancestor = self._find_lowest_common_ancestor(
            root, startValue, destValue
        )

        path_to_start = []
        path_to_dest = []

        # Find paths from LCA to start and destination nodes
        self._find_path(lowest_common_ancestor, startValue, path_to_start)
        self._find_path(lowest_common_ancestor, destValue, path_to_dest)

        directions = []

        # Add "U" for each step to go up from start to LCA
        directions.extend("U" * len(path_to_start))

        # Append the path from LCA to destination
        directions.extend(path_to_dest)

        return "".join(directions)

    def _find_lowest_common_ancestor(
        self, node: TreeNode, value1: int, value2: int
    ) -> TreeNode:
        if node is None:
            return None

        if node.val == value1 or node.val == value2:
            return node

        left_lca = self._find_lowest_common_ancestor(node.left, value1, value2)
        right_lca = self._find_lowest_common_ancestor(
            node.right, value1, value2
        )

        if left_lca is None:
            return right_lca
        elif right_lca is None:
            return left_lca
        else:
            return node  # Both values found, this is the LCA

    def _find_path(
        self, node: TreeNode, target_value: int, path: List[str]
    ) -> bool:
        if node is None:
            return False

        if node.val == target_value:
            return True

        # Try left subtree
        path.append("L")
        if self._find_path(node.left, target_value, path):
            return True
        path.pop()  # Remove last character

        # Try right subtree
        path.append("R")
        if self._find_path(node.right, target_value, path):
            return True
        path.pop()  # Remove last character

        return False
```

</details>

<br>

## Approach 3: LCA + DFS (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;

        // Find paths from root to start and destination nodes
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        string directions;
        int commonPathLength = 0;

        // Find the length of the common path
        while (commonPathLength < startPath.length() &&
               commonPathLength < destPath.length() &&
               startPath[commonPathLength] == destPath[commonPathLength]) {
            commonPathLength++;
        }

        // Add "U" for each step to go up from start to common ancestor
        for (int i = 0; i < startPath.length() - commonPathLength; i++) {
            directions += "U";
        }

        // Add directions from common ancestor to destination
        for (int i = commonPathLength; i < destPath.length(); i++) {
            directions += destPath[i];
        }

        return directions;
    }

private:
    bool findPath(TreeNode* node, int target, string& path) {
        if (node == nullptr) {
            return false;
        }

        if (node->val == target) {
            return true;
        }

        // Try left subtree
        path += "L";
        if (findPath(node->left, target, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        // Try right subtree
        path += "R";
        if (findPath(node->right, target, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder startPath = new StringBuilder();
        StringBuilder destPath = new StringBuilder();

        // Find paths from root to start and destination nodes
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        StringBuilder directions = new StringBuilder();
        int commonPathLength = 0;

        // Find the length of the common path
        while (
            commonPathLength < startPath.length() &&
            commonPathLength < destPath.length() &&
            startPath.charAt(commonPathLength) ==
            destPath.charAt(commonPathLength)
        ) {
            commonPathLength++;
        }

        // Add "U" for each step to go up from start to common ancestor
        for (int i = 0; i < startPath.length() - commonPathLength; i++) {
            directions.append("U");
        }

        // Add directions from common ancestor to destination
        for (int i = commonPathLength; i < destPath.length(); i++) {
            directions.append(destPath.charAt(i));
        }

        return directions.toString();
    }

    private boolean findPath(TreeNode node, int target, StringBuilder path) {
        if (node == null) {
            return false;
        }

        if (node.val == target) {
            return true;
        }

        // Try left subtree
        path.append("L");
        if (findPath(node.left, target, path)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1); // Remove last character

        // Try right subtree
        path.append("R");
        if (findPath(node.right, target, path)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1); // Remove last character

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getDirections(
        self, root: TreeNode, startValue: int, destValue: int
    ) -> str:
        start_path = []
        dest_path = []

        # Find paths from root to start and destination nodes
        self._find_path(root, startValue, start_path)
        self._find_path(root, destValue, dest_path)

        directions = []
        common_path_length = 0

        # Find the length of the common path
        while (
            common_path_length < len(start_path)
            and common_path_length < len(dest_path)
            and start_path[common_path_length] == dest_path[common_path_length]
        ):
            common_path_length += 1

        # Add "U" for each step to go up from start to common ancestor
        directions.extend("U" * (len(start_path) - common_path_length))

        # Add directions from common ancestor to destination
        directions.extend(dest_path[common_path_length:])

        return "".join(directions)

    def _find_path(self, node: TreeNode, target: int, path: List[str]) -> bool:
        if node is None:
            return False

        if node.val == target:
            return True

        # Try left subtree
        path.append("L")
        if self._find_path(node.left, target, path):
            return True
        path.pop()  # Remove last character

        # Try right subtree
        path.append("R")
        if self._find_path(node.right, target, path):
            return True
        path.pop()  # Remove last character

        return False
```

</details>
