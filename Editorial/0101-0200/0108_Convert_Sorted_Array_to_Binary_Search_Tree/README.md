# 108. Convert Sorted Array to Binary Search Tree

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)  
`Array` `Divide and Conquer` `Tree` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 108 - Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

## Problem

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

### Example 1

```text
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
```

### Example 2

```text
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
```

## Constraints

- 1 <= nums.length <= 104
- -104 <= nums[i] <= 104
- nums is sorted in a strictly increasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 108. Convert Sorted Array to Binary Search Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Preorder Traversal: Always Choose Left Middle Node as a Root | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Preorder Traversal: Always Choose Right Middle Node as a Root | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Preorder Traversal: Choose a Random Middle Node as a Root | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Preorder Traversal: Always Choose Left Middle Node as a Root

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct TreeNode* helper(int* nums, int left, int right) {
    if (left > right) return NULL;
    // always choose left middle node as a root
    int p = (left + right) / 2;
    // preorder traversal: node -> left -> right
    struct TreeNode* root = createNode(nums[p]);
    root->left = helper(nums, left, p - 1);
    root->right = helper(nums, p + 1, right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    // The 0 here is the position of the first element in the array. numsSize -
    // 1 is the position of the last element in the array.
    return helper(nums, 0, numsSize - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int p = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(nums, left, p - 1);
        root->right = helper(nums, p + 1, right);
        return root;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public TreeNode SortedArrayToBST(int[] nums) {
        return helper(nums, 0, nums.Length - 1);
    }

    public TreeNode helper(int[] nums, int left, int right) {
        if (left > right) {
            return null;
        }

        int p = (left + right) / 2;
        TreeNode root = new TreeNode(nums[p]);
        root.left = helper(nums, left, p - 1);
        root.right = helper(nums, p + 1, right);
        return root;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sortedArrayToBST(nums []int) *TreeNode {
    return helper(nums, 0, len(nums)-1)
}

func helper(nums []int, left int, right int) *TreeNode {
    if left > right {
        return nil
    }
    p := (left + right) / 2
    root := &TreeNode{Val: nums[p]}
    root.Left = helper(nums, left, p-1)
    root.Right = helper(nums, p+1, right)
    return root
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[] nums;

    public TreeNode helper(int left, int right) {
        if (left > right) return null;

        // always choose left middle node as a root
        int p = (left + right) / 2;

        // preorder traversal: node -> left -> right
        TreeNode root = new TreeNode(nums[p]);
        root.left = helper(left, p - 1);
        root.right = helper(p + 1, right);
        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        this.nums = nums;
        return helper(0, nums.length - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortedArrayToBST = function (nums) {
    return helper(nums, 0, nums.length - 1);
};
var helper = function (nums, left, right) {
    if (left > right) {
        return null;
    }
    var p = Math.floor((left + right) / 2);
    var root = new TreeNode(nums[p], null, null);
    root.left = helper(nums, left, p - 1);
    root.right = helper(nums, p + 1, right);
    return root;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def helper(left, right):
            if left > right:
                return None

            # always choose left middle node as a root
            p = (left + right) // 2

            # preorder traversal: node -> left -> right
            root = TreeNode(nums[p])
            root.left = helper(left, p - 1)
            root.right = helper(p + 1, right)
            return root

        return helper(0, len(nums) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sortedArrayToBST(nums: number[]): TreeNode | null {
    return helper(nums, 0, nums.length - 1);
}
function helper(nums: number[], left: number, right: number): TreeNode | null {
    if (left > right) {
        return null;
    }
    var p = Math.floor((left + right) / 2);
    var root = new TreeNode(nums[p], null, null);
    root.left = helper(nums, left, p - 1);
    root.right = helper(nums, p + 1, right);
    return root;
}
```

</details>

<br>

## Approach 2: Preorder Traversal: Always Choose Right Middle Node as a Root

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// TreeNode structure is already defined by Leetcode
// helping function
struct TreeNode* helper(int* nums, int left, int right) {
    if (left > right) return NULL;
    // always choose right middle node as a root
    int p = (left + right) / 2;
    if ((left + right) % 2 == 1) ++p;
    // preorder traversal: node -> left -> right
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[p];
    root->left = helper(nums, left, p - 1);
    root->right = helper(nums, p + 1, right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return helper(nums, 0, numsSize - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        // always choose right middle node as a root
        int p = (left + right) / 2;
        if ((left + right) % 2 == 1) ++p;
        // preorder traversal: node -> left -> right
        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(nums, left, p - 1);
        root->right = helper(nums, p + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int[] nums;

    private TreeNode Helper(int left, int right) {
        if (left > right)
            return null;
        // always choose right middle node as a root
        int p = (left + right) / 2;
        if ((left + right) % 2 == 1)
            ++p;
        // preorder traversal: node -> left -> right
        TreeNode root = new TreeNode(nums[p]);
        root.left = Helper(left, p - 1);
        root.right = Helper(p + 1, right);
        return root;
    }

    public TreeNode SortedArrayToBST(int[] nums) {
        this.nums = nums;
        return Helper(0, nums.Length - 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sortedArrayToBST(nums []int) *TreeNode {
    return helper(nums, 0, len(nums)-1)
}

func helper(nums []int, left int, right int) *TreeNode {
    if left > right {
        return nil
    }
    // always choose right middle node as a root
    p := (left + right) / 2
    if (left+right)%2 == 1 {
        p++
    }
    // preorder traversal: node -> left -> right
    root := &TreeNode{Val: nums[p]}
    root.Left = helper(nums, left, p-1)
    root.Right = helper(nums, p+1, right)
    return root
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[] nums;

    public TreeNode helper(int left, int right) {
        if (left > right) return null;

        // always choose right middle node as a root
        int p = (left + right) / 2;
        if ((left + right) % 2 == 1) ++p;

        // preorder traversal: node -> left -> right
        TreeNode root = new TreeNode(nums[p]);
        root.left = helper(left, p - 1);
        root.right = helper(p + 1, right);
        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        this.nums = nums;
        return helper(0, nums.length - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortedArrayToBST = function (nums) {
    function helper(left, right) {
        if (left > right) return null;
        // always choose right middle node as a root
        let p = Math.floor((left + right) / 2);
        if ((left + right) % 2 === 1) ++p;
        // preorder traversal: node -> left -> right
        const root = new TreeNode(nums[p]);
        root.left = helper(left, p - 1);
        root.right = helper(p + 1, right);
        return root;
    }
    return helper(0, nums.length - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def helper(left, right):
            if left > right:
                return None

            # always choose right middle node as a root
            p = (left + right) // 2
            if (left + right) % 2:
                p += 1

            # preorder traversal: node -> left -> right
            root = TreeNode(nums[p])
            root.left = helper(left, p - 1)
            root.right = helper(p + 1, right)
            return root

        return helper(0, len(nums) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sortedArrayToBST(nums: number[]): TreeNode | null {
    function helper(left: number, right: number): TreeNode | null {
        if (left > right) return null;
        // always choose right middle node as a root
        let p = Math.floor((left + right) / 2);
        if ((left + right) % 2 === 1) ++p;
        // preorder traversal: node -> left -> right
        const root = new TreeNode(nums[p]);
        root.left = helper(left, p - 1);
        root.right = helper(p + 1, right);
        return root;
    }
    return helper(0, nums.length - 1);
}
```

</details>

<br>

## Approach 3: Preorder Traversal: Choose a Random Middle Node as a Root

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct TreeNode* helper(int* nums, int left, int right) {
    if (left > right) return NULL;
    int p = (left + right) / 2;
    if ((left + right) % 2 == 1) p += rand() % 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[p];
    root->left = helper(nums, left, p - 1);
    root->right = helper(nums, p + 1, right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return helper(nums, 0, numsSize - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        // choose random middle node as a root
        int p = (left + right) / 2;
        if ((left + right) % 2 == 1) p += rand() % 2;
        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(nums, left, p - 1);
        root->right = helper(nums, p + 1, right);
        return root;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    Random rand = new Random();

    public TreeNode SortedArrayToBST(int[] nums) {
        return Helper(nums, 0, nums.Length - 1);
    }

    private TreeNode Helper(int[] nums, int left, int right) {
        if (left > right)
            return null;
        int p = (left + right) / 2;
        if ((left + right) % 2 == 1)
            p += rand.Next(2);
        TreeNode root = new TreeNode(nums[p]);
        root.left = Helper(nums, left, p - 1);
        root.right = Helper(nums, p + 1, right);
        return root;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sortedArrayToBST(nums []int) *TreeNode {
    return helper(nums, 0, len(nums)-1)
}

func helper(nums []int, left int, right int) *TreeNode {
    if left > right {
        return nil
    }
    p := (left + right) / 2
    if (left+right)%2 == 1 {
        p += rand.Intn(2)
    }
    root := &TreeNode{Val: nums[p]}
    root.Left = helper(nums, left, p-1)
    root.Right = helper(nums, p+1, right)
    return root
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[] nums;
    Random rand = new Random();

    public TreeNode helper(int left, int right) {
        if (left > right) return null;

        // choose random middle node as a root
        int p = (left + right) / 2;
        if ((left + right) % 2 == 1) p += rand.nextInt(2);

        // preorder traversal: node -> left -> right
        TreeNode root = new TreeNode(nums[p]);
        root.left = helper(left, p - 1);
        root.right = helper(p + 1, right);
        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        this.nums = nums;
        return helper(0, nums.length - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortedArrayToBST = function (nums) {
    let helper = function (left, right) {
        if (left > right) return null;
        let p = Math.floor((left + right) / 2);
        if ((left + right) % 2 == 1) p += Math.floor(Math.random() * 2);
        let root = new TreeNode(nums[p]);
        root.left = helper(left, p - 1);
        root.right = helper(p + 1, right);
        return root;
    };
    return helper(0, nums.length - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from random import randint


class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def helper(left, right):
            if left > right:
                return None

            # choose random middle node as a root
            p = (left + right) // 2
            if (left + right) % 2:
                p += randint(0, 1)

            # preorder traversal: node -> left -> right
            root = TreeNode(nums[p])
            root.left = helper(left, p - 1)
            root.right = helper(p + 1, right)
            return root

        return helper(0, len(nums) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sortedArrayToBST(nums: number[]): TreeNode | null {
    let helper = function (left: number, right: number): TreeNode | null {
        if (left > right) return null;
        let p = Math.floor((left + right) / 2);
        if ((left + right) % 2 == 1) p += Math.floor(Math.random() * 2);
        let root = new TreeNode(nums[p]);
        root.left = helper(left, p - 1);
        root.right = helper(p + 1, right);
        return root;
    };
    return helper(0, nums.length - 1);
}
```

</details>
