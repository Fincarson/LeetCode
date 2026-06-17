# 113. Path Sum II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/path-sum-ii/)  
`Backtracking` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 113 - Path Sum II](https://leetcode.com/problems/path-sum-ii/)

## Problem

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

### Example 1

```text
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
```

### Example 2

```text
Input: root = [1,2,3], targetSum = 5
Output: []
```

### Example 3

```text
Input: root = [1,2], targetSum = 0
Output: []
```

## Constraints

- The number of nodes in the tree is in the range [0, 5000].
- -1000 <= Node.val <= 1000
- -1000 <= targetSum <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Path Sum](https://leetcode.com/problems/path-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Path Sum III](https://leetcode.com/problems/path-sum-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Path Sum IV](https://leetcode.com/problems/path-sum-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 113. Path Sum II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Depth First Traversal | Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Depth First Traversal | Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void helper(struct TreeNode* root, int sum, int* path, int depth,
            int** columnSizes, int* returnSize, int*** returnArray) {
    if (root == NULL) return;
    path[depth] = root->val;
    if (root->left == NULL && root->right == NULL && sum == root->val) {
        (*returnArray) =
            (int**)realloc((*returnArray), sizeof(int*) * (*returnSize + 1));
        (*returnArray)[*returnSize] = (int*)calloc(depth + 1, sizeof(int));
        memcpy((*returnArray)[*returnSize], path, sizeof(int) * (depth + 1));
        (*columnSizes) =
            (int*)realloc((*columnSizes), sizeof(int) * (*returnSize + 1));
        (*columnSizes)[*returnSize] = depth + 1;
        (*returnSize)++;
    }
    helper(root->left, sum - root->val, path, depth + 1, columnSizes,
           returnSize, returnArray);
    helper(root->right, sum - root->val, path, depth + 1, columnSizes,
           returnSize, returnArray);
}
int** pathSum(struct TreeNode* root, int sum, int* returnSize,
              int** returnColumnSizes) {
    int** returnArray = (int**)calloc(5000, sizeof(int*));
    int* path = (int*)calloc(5000, sizeof(int));
    (*returnSize) = 0;
    (*returnColumnSizes) = (int*)calloc(5000, sizeof(int));
    helper(root, sum, path, 0, returnColumnSizes, returnSize, &returnArray);
    return returnArray;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // The function definition
    void recurseTree(TreeNode* node, int remainingSum, vector<int>& pathNodes,
                     vector<vector<int>>& pathsList) {
        if (node == NULL) {
            return;
        }
        // Add the current node to the path's list
        pathNodes.push_back(node->val);
        // Check if the current node is a leaf and also, if it
        // equals our remaining sum. If it does, we add the path to
        // our list of paths
        if (remainingSum == node->val && node->left == NULL &&
            node->right == NULL) {
            pathsList.push_back(vector<int>(pathNodes));
        } else {
            // Else, we will recurse on the left and the right children
            this->recurseTree(node->left, remainingSum - node->val, pathNodes,
                              pathsList);
            this->recurseTree(node->right, remainingSum - node->val, pathNodes,
                              pathsList);
        }
        // We need to pop the node once we are done processing ALL of it's
        // subtrees.
        pathNodes.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> pathsList;
        vector<int> pathNodes;
        this->recurseTree(root, sum, pathNodes, pathsList);
        return pathsList;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private void RecurseTree(TreeNode node, int remainingSum,
                             List<int> pathNodes, IList<IList<int>> pathsList) {
        if (node == null) {
            return;
        }

        // Add the current node to the path's list
        pathNodes.Add(node.val);
        // Check if the current node is a leaf and also, if it
        // equals our remaining sum. If it does, we add the path to
        // our list of paths
        if (remainingSum == node.val && node.left == null &&
            node.right == null) {
            pathsList.Add(new List<int>(pathNodes));
        } else {
            // Else, we will recurse on the left and the right children
            this.RecurseTree(node.left, remainingSum - node.val, pathNodes,
                             pathsList);
            this.RecurseTree(node.right, remainingSum - node.val, pathNodes,
                             pathsList);
        }

        // We need to pop the node once we are done processing ALL of it's
        // subtrees.
        pathNodes.RemoveAt(pathNodes.Count - 1);
    }

    public IList<IList<int>> PathSum(TreeNode root, int sum) {
        List<IList<int>> pathsList = new List<IList<int>>();
        List<int> pathNodes = new List<int>();
        this.RecurseTree(root, sum, pathNodes, pathsList);
        return pathsList;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func pathSum(root *TreeNode, sum int) [][]int {
    pathsList := [][]int{}
    pathNodes := []int{}
    var recurseTree func(*TreeNode, int, []int, [][]int) [][]int
    recurseTree = func(node *TreeNode, remainingSum int, pathNodes []int, pathsList [][]int) [][]int {
        if node == nil {
            return pathsList
        }
        pathNodes = append(pathNodes, node.Val)
        if remainingSum == node.Val && node.Left == nil && node.Right == nil {
            tmp := make([]int, len(pathNodes))
            copy(tmp, pathNodes)
            pathsList = append(pathsList, tmp)
        } else {
            pathsList = recurseTree(node.Left, remainingSum-node.Val, pathNodes, pathsList)
            pathsList = recurseTree(node.Right, remainingSum-node.Val, pathNodes, pathsList)
        }
        pathNodes = pathNodes[:len(pathNodes)-1]
        return pathsList
    }
    return recurseTree(root, sum, pathNodes, pathsList)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private void recurseTree(
        TreeNode node,
        int remainingSum,
        List<Integer> pathNodes,
        List<List<Integer>> pathsList
    ) {
        if (node == null) {
            return;
        }

        // Add the current node to the path's list
        pathNodes.add(node.val);

        // Check if the current node is a leaf and also, if it
        // equals our remaining sum. If it does, we add the path to
        // our list of paths
        if (
            remainingSum == node.val && node.left == null && node.right == null
        ) {
            pathsList.add(new ArrayList<>(pathNodes));
        } else {
            // Else, we will recurse on the left and the right children
            this.recurseTree(
                    node.left,
                    remainingSum - node.val,
                    pathNodes,
                    pathsList
                );
            this.recurseTree(
                    node.right,
                    remainingSum - node.val,
                    pathNodes,
                    pathsList
                );
        }

        // We need to pop the node once we are done processing ALL of it's
        // subtrees.
        pathNodes.remove(pathNodes.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> pathsList = new ArrayList<List<Integer>>();
        List<Integer> pathNodes = new ArrayList<Integer>();
        this.recurseTree(root, sum, pathNodes, pathsList);
        return pathsList;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var pathSum = function (root, sum) {
    let pathsList = [];
    let pathNodes = [];
    let recurseTree = function (node, remainingSum, pathNodes, pathsList) {
        if (!node) {
            return;
        }
        // Add the current node to the path's list
        pathNodes.push(node.val);
        // Check if the current node is a leaf and also, if it
        // equals our remaining sum. If it does, we add the path to
        // our list of paths
        if (
            remainingSum === node.val &&
            node.left === null &&
            node.right === null
        ) {
            pathsList.push(Array.from(pathNodes));
        } else {
            // Else, we will recurse on the left and the right children
            recurseTree(
                node.left,
                remainingSum - node.val,
                pathNodes,
                pathsList,
            );
            recurseTree(
                node.right,
                remainingSum - node.val,
                pathNodes,
                pathsList,
            );
        }
        // We need to pop the node once we are done processing ALL of it's
        // subtrees.
        pathNodes.pop();
    };
    recurseTree(root, sum, pathNodes, pathsList);
    return pathsList;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x: int) -> None:
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def recurseTree(
        self,
        node: TreeNode,
        remainingSum: int,
        pathNodes: List[int],
        pathsList: List[List[int]],
    ) -> None:

        if not node:
            return

        # Add the current node to the path's list
        pathNodes.append(node.val)

        # Check if the current node is a leaf and also, if it
        # equals our remaining sum. If it does, we add the path to
        # our list of paths
        if remainingSum == node.val and not node.left and not node.right:
            pathsList.append(list(pathNodes))
        else:
            # Else, we will recurse on the left and the right children
            self.recurseTree(
                node.left, remainingSum - node.val, pathNodes, pathsList
            )
            self.recurseTree(
                node.right, remainingSum - node.val, pathNodes, pathsList
            )

        # We need to pop the node once we are done processing ALL of it's
        # subtrees.
        pathNodes.pop()

    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        pathsList = []
        self.recurseTree(root, sum, [], pathsList)
        return pathsList
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function pathSum(root: TreeNode | null, sum: number): number[][] {
    let pathsList: number[][] = [];
    let pathNodes: number[] = [];
    let recurseTree = function (
        node: TreeNode | null,
        remainingSum: number,
        pathNodes: number[],
        pathsList: number[][],
    ) {
        if (!node) {
            return;
        }
        // Add the current node to the path's list
        pathNodes.push(node.val);
        // Check if the current node is a leaf and also, if it
        // equals our remaining sum. If it does, we add the path to
        // our list of paths
        if (
            remainingSum === node.val &&
            node.left === null &&
            node.right === null
        ) {
            pathsList.push([...pathNodes]);
        } else {
            // Else, we will recurse on the left and the right children
            recurseTree(
                node.left,
                remainingSum - node.val,
                pathNodes,
                pathsList,
            );
            recurseTree(
                node.right,
                remainingSum - node.val,
                pathNodes,
                pathsList,
            );
        }
        // We need to pop the node once we are done processing ALL of it's
        // subtrees.
        pathNodes.pop();
    };
    recurseTree(root, sum, pathNodes, pathsList);
    return pathsList;
}
```

</details>
