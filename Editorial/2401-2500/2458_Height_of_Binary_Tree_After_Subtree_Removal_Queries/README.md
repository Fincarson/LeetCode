# 2458. Height of Binary Tree After Subtree Removal Queries

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/)  
`Array` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 2458 - Height of Binary Tree After Subtree Removal Queries](https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/)

## Problem

You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:

- Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.

Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

Note:

- The queries are independent, so the tree returns to its initial state after each query.
- The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.

### Example 1

```text
Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
Output: [2]
Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -> 3 -> 2).
```

### Example 2

```text
Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
Output: [3,2,3,2]
Explanation: We have the following queries:
- Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
- Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
- Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
- Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).
```

## Constraints

- The number of nodes in the tree is n.
- 2 <= n <= 105
- 1 <= Node.val <= n
- All the values in the tree are unique.
- m == queries.length
- 1 <= m <= min(n, 104)
- 1 <= queries[i] <= n
- queries[i] != root.val

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2458. Height of Binary Tree After Subtree Removal Queries

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Left and Right Traversal | C++, Java, Python3 |
| Single Traversal | C++, Java, Python3 |
| Subtree Size | C++, Java, Python3 |
| Eulerian Tour | C++, Java, Python3 |
| Two Largest Cousins | C++, Java, Python3 |

## Approach 1: Left and Right Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Array to store the maximum height of the tree after removing each node
    int maxHeightAfterRemoval[100001];
    int currentMaxHeight = 0;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverseLeftToRight(root, 0);
        currentMaxHeight = 0;  // Reset for the second traversal
        traverseRightToLeft(root, 0);

        // Process queries and build the result vector
        int queryCount = queries.size();
        vector<int> queryResults(queryCount);
        for (int i = 0; i < queryCount; i++) {
            queryResults[i] = maxHeightAfterRemoval[queries[i]];
        }

        return queryResults;
    }

private:
    // Left to right traversal
    void traverseLeftToRight(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        // Store the maximum height if this node were removed
        maxHeightAfterRemoval[node->val] = currentMaxHeight;

        // Update the current maximum height
        currentMaxHeight = max(currentMaxHeight, currentHeight);

        // Traverse left subtree first, then right
        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }

    // Right to left traversal
    void traverseRightToLeft(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        // Update the maximum height if this node were removed
        maxHeightAfterRemoval[node->val] =
            max(maxHeightAfterRemoval[node->val], currentMaxHeight);

        // Update the current maximum height
        currentMaxHeight = max(currentHeight, currentMaxHeight);

        // Traverse right subtree first, then left
        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Array to store the maximum height of the tree after removing each node
    static final int[] maxHeightAfterRemoval = new int[100001];

    int currentMaxHeight = 0;

    public int[] treeQueries(TreeNode root, int[] queries) {
        traverseLeftToRight(root, 0);
        currentMaxHeight = 0; // Reset for the second traversal
        traverseRightToLeft(root, 0);

        // Process queries and build the result array
        int queryCount = queries.length;
        int[] queryResults = new int[queryCount];
        for (int i = 0; i < queryCount; i++) {
            queryResults[i] = maxHeightAfterRemoval[queries[i]];
        }

        return queryResults;
    }

    private void traverseLeftToRight(TreeNode node, int currentHeight) {
        if (node == null) return;

        // Store the maximum height if this node were removed
        maxHeightAfterRemoval[node.val] = currentMaxHeight;

        // Update the current maximum height
        currentMaxHeight = Math.max(currentMaxHeight, currentHeight);

        // Traverse left subtree first, then right
        traverseLeftToRight(node.left, currentHeight + 1);
        traverseLeftToRight(node.right, currentHeight + 1);
    }

    private void traverseRightToLeft(TreeNode node, int currentHeight) {
        if (node == null) return;

        // Update the maximum height if this node were removed
        maxHeightAfterRemoval[node.val] = Math.max(
            maxHeightAfterRemoval[node.val],
            currentMaxHeight
        );

        // Update the current maximum height
        currentMaxHeight = Math.max(currentHeight, currentMaxHeight);

        // Traverse right subtree first, then left
        traverseRightToLeft(node.right, currentHeight + 1);
        traverseRightToLeft(node.left, currentHeight + 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def treeQueries(
        self, root: Optional[TreeNode], queries: List[int]
    ) -> List[int]:
        max_height_after_removal = [0] * 100001
        self.current_max_height = 0

        def _traverse_left_to_right(node, current_height):
            if not node:
                return

            # Store the maximum height if this node were removed
            max_height_after_removal[node.val] = self.current_max_height

            # Update the current maximum height
            self.current_max_height = max(
                self.current_max_height, current_height
            )

            # Traverse left subtree first, then right
            _traverse_left_to_right(node.left, current_height + 1)
            _traverse_left_to_right(node.right, current_height + 1)

        def _traverse_right_to_left(node, current_height):
            if not node:
                return

            # Update the maximum height if this node were removed
            max_height_after_removal[node.val] = max(
                max_height_after_removal[node.val], self.current_max_height
            )

            # Update the current maximum height
            self.current_max_height = max(
                current_height, self.current_max_height
            )

            # Traverse right subtree first, then left
            _traverse_right_to_left(node.right, current_height + 1)
            _traverse_right_to_left(node.left, current_height + 1)

        _traverse_left_to_right(root, 0)
        self.current_max_height = 0  # Reset for the second traversal
        _traverse_right_to_left(root, 0)

        # Process queries and build the result list
        return [max_height_after_removal[q] for q in queries]
```

</details>

<br>

## Approach 2: Single Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> resultMap;
        unordered_map<TreeNode*, int> heightCache;

        // Run DFS to fill resultMap with maximum heights after each query
        dfs(root, 0, 0, resultMap, heightCache);

        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            result[i] = resultMap[queries[i]];
        }
        return result;
    }

private:
    // Function to calculate the height of the tree
    int height(TreeNode* node, unordered_map<TreeNode*, int>& heightCache) {
        if (node == nullptr) {
            return -1;
        }

        // Return cached height if already calculated
        if (heightCache.count(node)) {
            return heightCache[node];
        }

        int h = 1 + max(height(node->left, heightCache),
                        height(node->right, heightCache));
        heightCache[node] = h;
        return h;
    }

    // DFS to precompute the maximum values after removing the subtree
    void dfs(TreeNode* node, int depth, int maxVal,
             unordered_map<int, int>& resultMap,
             unordered_map<TreeNode*, int>& heightCache) {
        if (node == nullptr) {
            return;
        }

        resultMap[node->val] = maxVal;

        // Traverse left and right subtrees while updating max values
        dfs(node->left, depth + 1,
            max(maxVal, depth + 1 + height(node->right, heightCache)),
            resultMap, heightCache);
        dfs(node->right, depth + 1,
            max(maxVal, depth + 1 + height(node->left, heightCache)), resultMap,
            heightCache);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] treeQueries(TreeNode root, int[] queries) {
        Map<Integer, Integer> resultMap = new HashMap<>();
        Map<TreeNode, Integer> heightCache = new HashMap<>();

        // Run DFS to fill resultMap with maximum heights after each query
        dfs(root, 0, 0, resultMap, heightCache);

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            result[i] = resultMap.get(queries[i]);
        }
        return result;
    }

    // Function to calculate the height of the tree
    private int height(TreeNode node, Map<TreeNode, Integer> heightCache) {
        if (node == null) {
            return -1;
        }

        // Return cached height if already calculated
        if (heightCache.containsKey(node)) {
            return heightCache.get(node);
        }

        int h =
            1 +
            Math.max(
                height(node.left, heightCache),
                height(node.right, heightCache)
            );
        heightCache.put(node, h);
        return h;
    }

    // DFS to precompute the maximum values after removing the subtree
    private void dfs(
        TreeNode node,
        int depth,
        int maxVal,
        Map<Integer, Integer> resultMap,
        Map<TreeNode, Integer> heightCache
    ) {
        if (node == null) {
            return;
        }

        resultMap.put(node.val, maxVal);

        // Traverse left and right subtrees while updating max values
        dfs(
            node.left,
            depth + 1,
            Math.max(maxVal, depth + 1 + height(node.right, heightCache)),
            resultMap,
            heightCache
        );
        dfs(
            node.right,
            depth + 1,
            Math.max(maxVal, depth + 1 + height(node.left, heightCache)),
            resultMap,
            heightCache
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def treeQueries(
        self, root: Optional[TreeNode], queries: List[int]
    ) -> List[int]:
        result_map = {}
        height_cache = {}

        # Function to calculate the height of the tree
        def _height(node):
            if not node:
                return -1

            # Return cached height if already calculated
            if node in height_cache:
                return height_cache[node]

            h = 1 + max(_height(node.left), _height(node.right))
            height_cache[node] = h
            return h

        # DFS to precompute the maximum values after removing the subtree
        def _dfs(node, depth, max_val):
            if not node:
                return

            result_map[node.val] = max_val

            # Traverse left and right subtrees while updating max values
            _dfs(
                node.left,
                depth + 1,
                max(max_val, depth + 1 + _height(node.right)),
            )
            _dfs(
                node.right,
                depth + 1,
                max(max_val, depth + 1 + _height(node.left)),
            )

        # Run DFS to fill result_map with maximum heights after each query
        _dfs(root, 0, 0)

        # Build the result array based on the queries
        return [result_map[q] for q in queries]
```

</details>

<br>

## Approach 3: Subtree Size

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Map to store the index of each node value
        unordered_map<int, int> nodeIndexMap;

        // Map to store the number of nodes in the subtree for each node
        unordered_map<int, int> subtreeSize;

        // Vectors to store node depths and maximum depths from left and right
        vector<int> nodeDepths;
        vector<int> maxDepthFromLeft;
        vector<int> maxDepthFromRight;

        // Perform DFS to populate nodeIndexMap and nodeDepths
        dfs(root, 0, nodeIndexMap, nodeDepths);

        int totalNodes = nodeDepths.size();

        // Calculate subtree sizes
        calculateSubtreeSize(root, subtreeSize);

        // Calculate maximum depths from left and right
        maxDepthFromLeft.push_back(nodeDepths[0]);
        maxDepthFromRight.push_back(nodeDepths[totalNodes - 1]);

        for (int i = 1; i < totalNodes; i++) {
            maxDepthFromLeft.push_back(
                max(maxDepthFromLeft[i - 1], nodeDepths[i]));
            maxDepthFromRight.push_back(
                max(maxDepthFromRight[i - 1], nodeDepths[totalNodes - i - 1]));
        }
        reverse(maxDepthFromRight.begin(), maxDepthFromRight.end());

        // Process queries
        vector<int> results(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int queryNode = queries[i];
            int startIndex = nodeIndexMap[queryNode] - 1;
            int endIndex = startIndex + 1 + subtreeSize[queryNode];

            int maxDepth = maxDepthFromLeft[startIndex];
            if (endIndex < totalNodes) {
                maxDepth = max(maxDepth, maxDepthFromRight[endIndex]);
            }

            results[i] = maxDepth;
        }

        return results;
    }

private:
    // Depth-first search to populate nodeIndexMap and nodeDepths
    void dfs(TreeNode* root, int depth, unordered_map<int, int>& nodeIndexMap,
             vector<int>& nodeDepths) {
        if (root == nullptr) return;

        nodeIndexMap[root->val] = nodeDepths.size();
        nodeDepths.push_back(depth);

        dfs(root->left, depth + 1, nodeIndexMap, nodeDepths);
        dfs(root->right, depth + 1, nodeIndexMap, nodeDepths);
    }

    // Calculate the size of the subtree for each node
    int calculateSubtreeSize(TreeNode* root,
                             unordered_map<int, int>& subtreeSize) {
        if (root == nullptr) return 0;

        int leftSize = calculateSubtreeSize(root->left, subtreeSize);
        int rightSize = calculateSubtreeSize(root->right, subtreeSize);

        int totalSize = leftSize + rightSize + 1;
        subtreeSize[root->val] = totalSize;

        return totalSize;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] treeQueries(TreeNode root, int[] queries) {
        // Map to store the index of each node value
        Map<Integer, Integer> nodeIndexMap = new HashMap<>();

        // Map to store the number of nodes in subtree for each node
        Map<Integer, Integer> subtreeSize = new HashMap<>();

        // Lists to store node depths and maximum depths from left and right
        List<Integer> nodeDepths = new ArrayList<>();
        List<Integer> maxDepthFromLeft = new ArrayList<>();
        List<Integer> maxDepthFromRight = new ArrayList<>();

        // Perform DFS to populate nodeIndexMap and nodeDepths
        dfs(root, 0, nodeIndexMap, nodeDepths);

        int totalNodes = nodeDepths.size();

        // Calculate subtree sizes
        calculateSubtreeSize(root, subtreeSize);

        // Calculate maximum depths from left and right
        maxDepthFromLeft.add(nodeDepths.get(0));
        maxDepthFromRight.add(nodeDepths.get(totalNodes - 1));

        for (int i = 1; i < totalNodes; i++) {
            maxDepthFromLeft.add(
                Math.max(maxDepthFromLeft.get(i - 1), nodeDepths.get(i))
            );
            maxDepthFromRight.add(
                Math.max(
                    maxDepthFromRight.get(i - 1),
                    nodeDepths.get(totalNodes - i - 1)
                )
            );
        }
        Collections.reverse(maxDepthFromRight);

        // Process queries
        int[] results = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int queryNode = queries[i];
            int startIndex = nodeIndexMap.get(queryNode) - 1;
            int endIndex = startIndex + 1 + subtreeSize.get(queryNode);

            int maxDepth = maxDepthFromLeft.get(startIndex);
            if (endIndex < totalNodes) {
                maxDepth = Math.max(maxDepth, maxDepthFromRight.get(endIndex));
            }

            results[i] = maxDepth;
        }

        return results;
    }

    // Depth-first search to populate nodeIndexMap and nodeDepths
    private void dfs(
        TreeNode root,
        int depth,
        Map<Integer, Integer> nodeIndexMap,
        List<Integer> nodeDepths
    ) {
        if (root == null) return;

        nodeIndexMap.put(root.val, nodeDepths.size());
        nodeDepths.add(depth);

        dfs(root.left, depth + 1, nodeIndexMap, nodeDepths);
        dfs(root.right, depth + 1, nodeIndexMap, nodeDepths);
    }

    // Calculate the size of subtree for each node
    private int calculateSubtreeSize(
        TreeNode root,
        Map<Integer, Integer> subtreeSize
    ) {
        if (root == null) return 0;

        int leftSize = calculateSubtreeSize(root.left, subtreeSize);
        int rightSize = calculateSubtreeSize(root.right, subtreeSize);

        int totalSize = leftSize + rightSize + 1;
        subtreeSize.put(root.val, totalSize);

        return totalSize;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def treeQueries(
        self, root: Optional[TreeNode], queries: List[int]
    ) -> List[int]:
        # Dictionary to store the index of each node value
        node_index_map = {}

        # Dictionary to store the number of nodes in the subtree for each node
        subtree_size = {}

        # Lists to store node depths and maximum depths from left and right
        node_depths = []
        max_depth_from_left = []
        max_depth_from_right = []

        # Perform DFS to populate node_index_map and node_depths
        self._dfs(root, 0, node_index_map, node_depths)

        total_nodes = len(node_depths)

        # Calculate subtree sizes
        self._calculate_subtree_size(root, subtree_size)

        # Calculate maximum depths from left and right
        max_depth_from_left.append(node_depths[0])
        max_depth_from_right.append(node_depths[-1])

        for i in range(1, total_nodes):
            max_depth_from_left.append(
                max(max_depth_from_left[i - 1], node_depths[i])
            )
            max_depth_from_right.append(
                max(
                    max_depth_from_right[i - 1],
                    node_depths[total_nodes - i - 1],
                )
            )

        max_depth_from_right.reverse()

        # Process queries
        results = []
        for query_node in queries:
            start_index = node_index_map[query_node] - 1
            end_index = start_index + 1 + subtree_size[query_node]

            max_depth = max_depth_from_left[start_index]
            if end_index < total_nodes:
                max_depth = max(max_depth, max_depth_from_right[end_index])

            results.append(max_depth)

        return results

    # Depth-first search to populate node_index_map and node_depths
    def _dfs(self, root, depth, node_index_map, node_depths):
        if not root:
            return

        node_index_map[root.val] = len(node_depths)
        node_depths.append(depth)

        self._dfs(root.left, depth + 1, node_index_map, node_depths)
        self._dfs(root.right, depth + 1, node_index_map, node_depths)

    # Calculate the size of the subtree for each node
    def _calculate_subtree_size(self, root, subtree_size):
        if not root:
            return 0

        left_size = self._calculate_subtree_size(root.left, subtree_size)
        right_size = self._calculate_subtree_size(root.right, subtree_size)

        total_size = left_size + right_size + 1
        subtree_size[root.val] = total_size

        return total_size
```

</details>

<br>

## Approach 4: Eulerian Tour

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Vectors and maps to store tree information
        vector<int> eulerTour;
        unordered_map<int, int> nodeHeights, firstOccurrence, lastOccurrence;

        // Perform DFS to build Euler tour and node information
        dfs(root, 0, eulerTour, nodeHeights, firstOccurrence, lastOccurrence);

        int tourSize = eulerTour.size();
        vector<int> maxDepthLeft(tourSize), maxDepthRight(tourSize);

        // Initialize the first and last elements of maxHeight arrays
        maxDepthLeft[0] = maxDepthRight[tourSize - 1] = nodeHeights[root->val];

        // Build maxDepthLeft and maxDepthRight arrays
        for (int i = 1; i < tourSize; i++) {
            maxDepthLeft[i] =
                max(maxDepthLeft[i - 1], nodeHeights[eulerTour[i]]);
        }

        for (int i = tourSize - 2; i >= 0; i--) {
            maxDepthRight[i] =
                max(maxDepthRight[i + 1], nodeHeights[eulerTour[i]]);
        }

        // Process queries
        vector<int> results(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int queryNode = queries[i];
            int leftMax = (firstOccurrence[queryNode] > 0)
                              ? maxDepthLeft[firstOccurrence[queryNode] - 1]
                              : 0;
            int rightMax = (lastOccurrence[queryNode] < tourSize - 1)
                               ? maxDepthRight[lastOccurrence[queryNode] + 1]
                               : 0;
            results[i] = max(leftMax, rightMax);
        }

        return results;
    }

private:
    // Depth-first search to build the Euler tour and store node information
    void dfs(TreeNode* root, int height, vector<int>& eulerTour,
             unordered_map<int, int>& nodeHeights,
             unordered_map<int, int>& firstOccurrence,
             unordered_map<int, int>& lastOccurrence) {
        if (root == nullptr) return;

        nodeHeights[root->val] = height;
        firstOccurrence[root->val] = eulerTour.size();
        eulerTour.push_back(root->val);

        dfs(root->left, height + 1, eulerTour, nodeHeights, firstOccurrence,
            lastOccurrence);
        dfs(root->right, height + 1, eulerTour, nodeHeights, firstOccurrence,
            lastOccurrence);

        lastOccurrence[root->val] = eulerTour.size();
        eulerTour.push_back(root->val);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] treeQueries(TreeNode root, int[] queries) {
        // Lists and maps to store tree information
        List<Integer> eulerTour = new ArrayList<>();
        Map<Integer, Integer> nodeHeights = new HashMap<>();
        Map<Integer, Integer> firstOccurrence = new HashMap<>();
        Map<Integer, Integer> lastOccurrence = new HashMap<>();

        // Perform DFS to build Euler tour and node information
        dfs(root, 0, eulerTour, nodeHeights, firstOccurrence, lastOccurrence);

        int tourSize = eulerTour.size();
        int[] maxDepthLeft = new int[tourSize];
        int[] maxDepthRight = new int[tourSize];

        // Initialize the first and last elements of maxHeight arrays
        maxDepthLeft[0] = maxDepthRight[tourSize - 1] = nodeHeights.get(
            root.val
        );

        // Build maxDepthLeft and maxDepthRight array
        for (int i = 1; i < tourSize; i++) {
            maxDepthLeft[i] = Math.max(
                maxDepthLeft[i - 1],
                nodeHeights.get(eulerTour.get(i))
            );
        }

        for (int i = tourSize - 2; i >= 0; i--) {
            maxDepthRight[i] = Math.max(
                maxDepthRight[i + 1],
                nodeHeights.get(eulerTour.get(i))
            );
        }

        // Process queries
        int[] results = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int queryNode = queries[i];
            int leftMax = (firstOccurrence.get(queryNode) > 0)
                ? maxDepthLeft[firstOccurrence.get(queryNode) - 1]
                : 0;
            int rightMax = (lastOccurrence.get(queryNode) < tourSize - 1)
                ? maxDepthRight[lastOccurrence.get(queryNode) + 1]
                : 0;
            results[i] = Math.max(leftMax, rightMax);
        }

        return results;
    }

    // Depth-first search to build the Euler tour and store node information
    private void dfs(
        TreeNode root,
        int height,
        List<Integer> eulerTour,
        Map<Integer, Integer> nodeHeights,
        Map<Integer, Integer> firstOccurrence,
        Map<Integer, Integer> lastOccurrence
    ) {
        if (root == null) return;

        nodeHeights.put(root.val, height);
        firstOccurrence.put(root.val, eulerTour.size());
        eulerTour.add(root.val);

        dfs(
            root.left,
            height + 1,
            eulerTour,
            nodeHeights,
            firstOccurrence,
            lastOccurrence
        );
        dfs(
            root.right,
            height + 1,
            eulerTour,
            nodeHeights,
            firstOccurrence,
            lastOccurrence
        );

        lastOccurrence.put(root.val, eulerTour.size());
        eulerTour.add(root.val);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def treeQueries(
        self, root: Optional[TreeNode], queries: List[int]
    ) -> List[int]:
        # Lists and dictionaries to store tree information
        euler_tour = []
        node_heights = {}
        first_occurrence = {}
        last_occurrence = {}

        # Depth-first search to build the Euler tour and store node information
        def _dfs(root, height):
            if not root:
                return

            node_heights[root.val] = height
            first_occurrence[root.val] = len(euler_tour)
            euler_tour.append(root.val)

            _dfs(root.left, height + 1)
            _dfs(root.right, height + 1)

            last_occurrence[root.val] = len(euler_tour)
            euler_tour.append(root.val)

        # Perform DFS to build Euler tour and node information
        _dfs(root, 0)

        tour_size = len(euler_tour)
        max_depth_left = [0] * tour_size
        max_depth_right = [0] * tour_size

        # Initialize the first and last elements of max_height arrays
        max_depth_left[0] = max_depth_right[-1] = node_heights[root.val]

        # Build max_depth_left and max_depth_right arrays
        for i in range(1, tour_size):
            max_depth_left[i] = max(
                max_depth_left[i - 1], node_heights[euler_tour[i]]
            )

        for i in range(tour_size - 2, -1, -1):
            max_depth_right[i] = max(
                max_depth_right[i + 1], node_heights[euler_tour[i]]
            )

        # Process queries
        return [
            max(
                (
                    max_depth_left[first_occurrence[q] - 1]
                    if first_occurrence[q] > 0
                    else 0
                ),
                (
                    max_depth_right[last_occurrence[q] + 1]
                    if last_occurrence[q] < tour_size - 1
                    else 0
                ),
            )
            for q in queries
        ]
```

</details>

<br>

## Approach 5: Two Largest Cousins

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = 100000;
        // Vectors to store node depths and heights
        vector<int> nodeDepths(n + 1, 0);
        vector<int> subtreeHeights(n + 1, 0);

        // Vectors to store the first and second largest heights at each level
        vector<int> firstLargestHeight(n + 1, 0);
        vector<int> secondLargestHeight(n + 1, 0);

        // Perform DFS to calculate depths and heights
        dfs(root, 0, nodeDepths, subtreeHeights, firstLargestHeight,
            secondLargestHeight);

        vector<int> results;
        results.reserve(queries.size());

        // Process each query
        for (int queryNode : queries) {
            int nodeLevel = nodeDepths[queryNode];

            // Calculate the height of the tree after removing the query node
            if (subtreeHeights[queryNode] == firstLargestHeight[nodeLevel]) {
                results.push_back(nodeLevel + secondLargestHeight[nodeLevel] -
                                  1);
            } else {
                results.push_back(nodeLevel + firstLargestHeight[nodeLevel] -
                                  1);
            }
        }

        return results;
    }

private:
    // Depth-first search to calculate node depths and subtree heights
    int dfs(TreeNode* node, int level, vector<int>& nodeDepths,
            vector<int>& subtreeHeights, vector<int>& firstLargestHeight,
            vector<int>& secondLargestHeight) {
        if (node == nullptr) return 0;

        nodeDepths[node->val] = level;

        // Calculate the height of the current subtree
        int leftHeight = dfs(node->left, level + 1, nodeDepths, subtreeHeights,
                             firstLargestHeight, secondLargestHeight);
        int rightHeight =
            dfs(node->right, level + 1, nodeDepths, subtreeHeights,
                firstLargestHeight, secondLargestHeight);
        int currentHeight = 1 + max(leftHeight, rightHeight);

        subtreeHeights[node->val] = currentHeight;

        // Update the largest and second largest heights at the current level
        if (currentHeight > firstLargestHeight[level]) {
            secondLargestHeight[level] = firstLargestHeight[level];
            firstLargestHeight[level] = currentHeight;
        } else if (currentHeight > secondLargestHeight[level]) {
            secondLargestHeight[level] = currentHeight;
        }

        return currentHeight;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] treeQueries(TreeNode root, int[] queries) {
        // Maps to store node depths and heights
        Map<Integer, Integer> nodeDepths = new HashMap<>();
        Map<Integer, Integer> subtreeHeights = new HashMap<>();

        // Maps to store the first and second largest heights at each level
        Map<Integer, Integer> firstLargestHeight = new HashMap<>();
        Map<Integer, Integer> secondLargestHeight = new HashMap<>();

        // Perform DFS to calculate depths and heights
        dfs(
            root,
            0,
            nodeDepths,
            subtreeHeights,
            firstLargestHeight,
            secondLargestHeight
        );

        int[] results = new int[queries.length];

        // Process each query
        for (int i = 0; i < queries.length; i++) {
            int queryNode = queries[i];
            int nodeLevel = nodeDepths.get(queryNode);

            // Calculate the height of the tree after removing the query node
            if (
                subtreeHeights
                    .get(queryNode)
                    .equals(firstLargestHeight.get(nodeLevel))
            ) {
                results[i] = nodeLevel +
                secondLargestHeight.getOrDefault(nodeLevel, 0) -
                1;
            } else {
                results[i] = nodeLevel +
                firstLargestHeight.getOrDefault(nodeLevel, 0) -
                1;
            }
        }

        return results;
    }

    // Depth-first search to calculate node depths and subtree heights
    private int dfs(
        TreeNode node,
        int level,
        Map<Integer, Integer> nodeDepths,
        Map<Integer, Integer> subtreeHeights,
        Map<Integer, Integer> firstLargestHeight,
        Map<Integer, Integer> secondLargestHeight
    ) {
        if (node == null) return 0;

        nodeDepths.put(node.val, level);

        // Calculate the height of the current subtree
        int leftHeight = dfs(
            node.left,
            level + 1,
            nodeDepths,
            subtreeHeights,
            firstLargestHeight,
            secondLargestHeight
        );
        int rightHeight = dfs(
            node.right,
            level + 1,
            nodeDepths,
            subtreeHeights,
            firstLargestHeight,
            secondLargestHeight
        );
        int currentHeight = 1 + Math.max(leftHeight, rightHeight);

        subtreeHeights.put(node.val, currentHeight);

        // Update the largest and second largest heights at the current level
        int currentFirstLargest = firstLargestHeight.getOrDefault(level, 0);
        if (currentHeight > currentFirstLargest) {
            secondLargestHeight.put(level, currentFirstLargest);
            firstLargestHeight.put(level, currentHeight);
        } else if (currentHeight > secondLargestHeight.getOrDefault(level, 0)) {
            secondLargestHeight.put(level, currentHeight);
        }

        return currentHeight;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def treeQueries(
        self, root: Optional[TreeNode], queries: List[int]
    ) -> List[int]:
        # Dictionaries to store node depths and heights
        node_depths = {}
        subtree_heights = {}

        # Dictionaries to store the first and second largest heights at each level
        first_largest_height = {}
        second_largest_height = {}

        # Depth-first search to calculate node depths and subtree heights
        def _dfs(node, level):
            if not node:
                return 0

            node_depths[node.val] = level

            # Calculate the height of the current subtree
            left_height = _dfs(node.left, level + 1)
            right_height = _dfs(node.right, level + 1)
            current_height = 1 + max(left_height, right_height)

            subtree_heights[node.val] = current_height

            # Update the largest and second largest heights at the current level
            if current_height > first_largest_height.get(level, 0):
                second_largest_height[level] = first_largest_height.get(
                    level, 0
                )
                first_largest_height[level] = current_height
            elif current_height > second_largest_height.get(level, 0):
                second_largest_height[level] = current_height

            return current_height

        _dfs(root, 0)

        # Process each query
        return [
            node_depths[q]
            + (
                second_largest_height.get(node_depths[q], 0)
                if subtree_heights[q] == first_largest_height[node_depths[q]]
                else first_largest_height.get(node_depths[q], 0)
            )
            - 1
            for q in queries
        ]
```

</details>
