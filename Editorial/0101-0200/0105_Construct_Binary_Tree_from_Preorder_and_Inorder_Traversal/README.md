# 105. Construct Binary Tree from Preorder and Inorder Traversal

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)  
`Array` `Hash Table` `Divide and Conquer` `Tree` `Binary Tree`

**Problem Link:** [LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

## Problem

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

### Example 1

```text
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```

### Example 2

```text
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

## Constraints

- 1 <= preorder.length <= 3000
- inorder.length == preorder.length
- -3000 <= preorder[i], inorder[i] <= 3000
- preorder and inorder consist of unique values.
- Each value of inorder also appears in preorder.
- preorder is guaranteed to be the preorder traversal of the tree.
- inorder is guaranteed to be the inorder traversal of the tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 105. Construct Binary Tree from Preorder and Inorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct HASHMAP_ENTRY {
    int key;
    int value;
    UT_hash_handle hh;
};
struct TreeNode* arrayToTree(int* preorder, int* inorder,
                             struct HASHMAP_ENTRY** index_map,
                             int* preorderIndex, int left, int right) {
    if (left > right) return NULL;
    int rootValue = preorder[(*preorderIndex)++];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootValue;
    struct HASHMAP_ENTRY* entry;
    HASH_FIND_INT(*index_map, &rootValue, entry);
    root->left = arrayToTree(preorder, inorder, index_map, preorderIndex, left,
                             entry->value - 1);
    root->right = arrayToTree(preorder, inorder, index_map, preorderIndex,
                              entry->value + 1, right);
    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder,
                           int inorderSize) {
    struct HASHMAP_ENTRY* index_map = NULL;
    for (int i = 0; i < inorderSize; i++) {
        struct HASHMAP_ENTRY* entry =
            (struct HASHMAP_ENTRY*)malloc(sizeof(struct HASHMAP_ENTRY));
        entry->key = inorder[i];
        entry->value = i;
        HASH_ADD_INT(index_map, key, entry);
    }
    int preorderIndex = 0;
    return arrayToTree(preorder, inorder, &index_map, &preorderIndex, 0,
                       inorderSize - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndexMap;
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        // if there are no elements to construct the tree
        if (left > right) return nullptr;
        // select the preorder_index element as the root and increment it
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root->left =
            arrayToTree(preorder, left, inorderIndexMap[rootValue] - 1);
        root->right =
            arrayToTree(preorder, inorderIndexMap[rootValue] + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        // build a hashmap to store value -> its index relations
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int preorderIndex;
    private Dictionary<int, int> inorderIndexMap;

    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        preorderIndex = 0;
        inorderIndexMap = new Dictionary<int, int>();
        for (int i = 0; i < inorder.Length; i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        return ArrayToTree(preorder, 0, preorder.Length - 1);
    }

    private TreeNode ArrayToTree(int[] preorder, int left, int right) {
        if (left > right)
            return null;
        int rootValue = preorder[preorderIndex++];
        TreeNode root = new TreeNode(rootValue);
        root.left = ArrayToTree(preorder, left, inorderIndexMap[rootValue] - 1);
        root.right =
            ArrayToTree(preorder, inorderIndexMap[rootValue] + 1, right);
        return root;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func buildTree(preorder []int, inorder []int) *TreeNode {
    preorderIndex := 0
    inorderIndexMap := make(map[int]int)
    for i := 0; i < len(inorder); i++ {
        inorderIndexMap[inorder[i]] = i
    }
    var arrayToTree func(left int, right int) *TreeNode
    arrayToTree = func(left int, right int) *TreeNode {
        // if there are no elements to construct the tree
        if left > right {
            return nil
        }
        // select the preorder_index element as the root and increment it
        rootValue := preorder[preorderIndex]
        preorderIndex++
        root := &TreeNode{Val: rootValue}
        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root.Left = arrayToTree(left, inorderIndexMap[rootValue]-1)
        root.Right = arrayToTree(inorderIndexMap[rootValue]+1, right)
        return root
    }
    return arrayToTree(0, len(preorder)-1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int preorderIndex;
    Map<Integer, Integer> inorderIndexMap;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        preorderIndex = 0;
        // build a hashmap to store value -> its index relations
        inorderIndexMap = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderIndexMap.put(inorder[i], i);
        }

        return arrayToTree(preorder, 0, preorder.length - 1);
    }

    private TreeNode arrayToTree(int[] preorder, int left, int right) {
        // if there are no elements to construct the tree
        if (left > right) return null;

        // select the preorder_index element as the root and increment it
        int rootValue = preorder[preorderIndex++];
        TreeNode root = new TreeNode(rootValue);

        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root.left = arrayToTree(
            preorder,
            left,
            inorderIndexMap.get(rootValue) - 1
        );
        root.right = arrayToTree(
            preorder,
            inorderIndexMap.get(rootValue) + 1,
            right
        );
        return root;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var buildTree = function (preorder, inorder) {
    let preorderIndex = 0;
    let inorderIndexMap = new Map();
    for (let i = 0; i < inorder.length; i++) {
        inorderIndexMap.set(inorder[i], i);
    }
    function arrayToTree(left, right) {
        // if there are no elements to construct the tree
        if (left > right) return null;
        // select the preorder_index element as the root and increment it
        let rootValue = preorder[preorderIndex++];
        let root = new TreeNode(rootValue);
        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root.left = arrayToTree(left, inorderIndexMap.get(rootValue) - 1);
        root.right = arrayToTree(inorderIndexMap.get(rootValue) + 1, right);
        return root;
    }
    return arrayToTree(0, preorder.length - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:

        def array_to_tree(left, right):
            nonlocal preorder_index
            # if there are no elements to construct the tree
            if left > right:
                return None

            # select the preorder_index element as the root and increment it
            root_value = preorder[preorder_index]
            root = TreeNode(root_value)

            preorder_index += 1

            # build left and right subtree
            # excluding inorder_index_map[root_value] element because it's the root
            root.left = array_to_tree(left, inorder_index_map[root_value] - 1)
            root.right = array_to_tree(inorder_index_map[root_value] + 1, right)

            return root

        preorder_index = 0

        # build a hashmap to store value -> its index relations
        inorder_index_map = {}
        for index, value in enumerate(inorder):
            inorder_index_map[value] = index

        return array_to_tree(0, len(preorder) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function buildTree(preorder: number[], inorder: number[]): TreeNode | null {
    let preorderIndex = 0;
    let inorderIndexMap = new Map();
    for (let i = 0; i < inorder.length; i++) {
        inorderIndexMap.set(inorder[i], i);
    }
    function arrayToTree(left: number, right: number): TreeNode | null {
        // if there are no elements to construct the tree
        if (left > right) return null;
        // select the preorder_index element as the root and increment it
        let rootValue = preorder[preorderIndex++];
        let root = new TreeNode(rootValue);
        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root.left = arrayToTree(left, inorderIndexMap.get(rootValue) - 1);
        root.right = arrayToTree(inorderIndexMap.get(rootValue) + 1, right);
        return root;
    }
    return arrayToTree(0, preorder.length - 1);
}
```

</details>
