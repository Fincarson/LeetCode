# 106. Construct Binary Tree from Inorder and Postorder Traversal

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)  
`Array` `Hash Table` `Divide and Conquer` `Tree` `Binary Tree`

**Problem Link:** [LeetCode 106 - Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

## Problem

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

### Example 1

```text
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
```

### Example 2

```text
Input: inorder = [-1], postorder = [-1]
Output: [-1]
```

## Constraints

- 1 <= inorder.length <= 3000
- postorder.length == inorder.length
- -3000 <= inorder[i], postorder[i] <= 3000
- inorder and postorder consist of unique values.
- Each value of postorder also appears in inorder.
- inorder is guaranteed to be the inorder traversal of the tree.
- postorder is guaranteed to be the postorder traversal of the tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 106. Construct Binary Tree from Inorder and Postorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder,
                           int postorderSize) {
    if (inorderSize == 0) {
        return NULL;
    }
    int i;
    for (i = 0; i < inorderSize; i++) {
        if (inorder[i] == postorder[postorderSize - 1]) {
            break;
        }
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    root->left = buildTree(inorder, i, postorder, i);
    root->right = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i,
                            postorderSize - i - 1);
    return root;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    int post_idx;
    vector<int> postorder;
    vector<int> inorder;
    unordered_map<int, int> idx_map;

public:
    TreeNode* helper(int in_left, int in_right) {
        // if there are no elements to construct subtrees
        if (in_left > in_right) return NULL;
        // pick up post_idx element as a root
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);
        // root splits inorder list
        // into left and right subtrees
        int index = idx_map[root_val];
        // recursion
        post_idx--;
        // build the right subtree
        root->right = helper(index + 1, in_right);
        // build the left subtree
        root->left = helper(in_left, index - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder = postorder;
        this->inorder = inorder;
        // start from the last postorder element
        post_idx = postorder.size() - 1;
        // build a hashmap value -> its index
        int idx = 0;
        for (int val : inorder) idx_map[val] = idx++;
        return helper(0, inorder.size() - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    int post_idx;
    int[] postorder;
    int[] inorder;
    Dictionary<int, int> idx_map = new Dictionary<int, int>();

    public TreeNode Helper(int in_left, int in_right) {
        if (in_left > in_right)
            return null;
        int root_val = postorder[post_idx];
        TreeNode root = new TreeNode(root_val);
        int index = idx_map[root_val];
        post_idx--;
        root.right = Helper(index + 1, in_right);
        root.left = Helper(in_left, index - 1);
        return root;
    }

    public TreeNode BuildTree(int[] inorder, int[] postorder) {
        this.postorder = postorder;
        this.inorder = inorder;
        post_idx = postorder.Length - 1;
        for (int idx = 0; idx < inorder.Length; idx++)
            idx_map[inorder[idx]] = idx;
        return Helper(0, inorder.Length - 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func buildTree(inorder []int, postorder []int) *TreeNode {
    idx_map := map[int]int{}
    post_idx := len(postorder) - 1
    var helper func(in_left int, in_right int) *TreeNode
    helper = func(in_left int, in_right int) *TreeNode {
        if in_left > in_right {
            return nil
        }
        root_val := postorder[post_idx]
        root := &TreeNode{Val: root_val}
        index := idx_map[root_val]
        post_idx--
        root.Right = helper(index+1, in_right)
        root.Left = helper(in_left, index-1)
        return root
    }
    for i := 0; i < len(inorder); i++ {
        idx_map[inorder[i]] = i
    }
    return helper(0, len(inorder)-1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int post_idx;
    int[] postorder;
    int[] inorder;
    HashMap<Integer, Integer> idx_map = new HashMap<Integer, Integer>();

    public TreeNode helper(int in_left, int in_right) {
        // if there are no elements to construct subtrees
        if (in_left > in_right) return null;

        // pick up post_idx element as a root
        int root_val = postorder[post_idx];
        TreeNode root = new TreeNode(root_val);

        // root splits inorder list
        // into left and right subtrees
        int index = idx_map.get(root_val);

        // recursion
        post_idx--;
        // build the right subtree
        root.right = helper(index + 1, in_right);
        // build the left subtree
        root.left = helper(in_left, index - 1);
        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        this.postorder = postorder;
        this.inorder = inorder;
        // start from the last postorder element
        post_idx = postorder.length - 1;

        // build a hashmap value -> its index
        int idx = 0;
        for (Integer val : inorder) idx_map.put(val, idx++);
        return helper(0, inorder.length - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var buildTree = function (inorder, postorder) {
    var idx_map = {};
    var post_idx = postorder.length - 1;
    var helper = function (in_left, in_right) {
        if (in_left > in_right) return null;
        var root_val = postorder[post_idx];
        var root = new TreeNode(root_val);
        var index = idx_map[root_val];
        post_idx--;
        root.right = helper(index + 1, in_right);
        root.left = helper(in_left, index - 1);
        return root;
    };
    for (var i = 0; i < inorder.length; i++) idx_map[inorder[i]] = i;
    return helper(0, inorder.length - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def helper(in_left: int, in_right: int) -> TreeNode:
            # if there are no elements to construct subtrees
            if in_left > in_right:
                return None

            # pick up the last element as a root
            val = postorder.pop()
            root = TreeNode(val)

            # root splits inorder list
            # into left and right subtrees
            index = idx_map[val]

            # build the right subtree
            root.right = helper(index + 1, in_right)
            # build the left subtree
            root.left = helper(in_left, index - 1)
            return root

        # build a hashmap value -> its index
        idx_map = {val: idx for idx, val in enumerate(inorder)}
        return helper(0, len(inorder) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function buildTree(inorder: number[], postorder: number[]): TreeNode | null {
    let idx_map = new Map<number, number>();
    let post_idx = postorder.length - 1;
    let helper = (in_left: number, in_right: number): TreeNode | null => {
        if (in_left > in_right) return null;
        let root_val = postorder[post_idx];
        let root = new TreeNode(root_val);
        let index = idx_map.get(root_val);
        post_idx--;
        root.right = helper(index + 1, in_right);
        root.left = helper(in_left, index - 1);
        return root;
    };
    for (let i = 0; i < inorder.length; i++) idx_map.set(inorder[i], i);
    return helper(0, inorder.length - 1);
}
```

</details>
