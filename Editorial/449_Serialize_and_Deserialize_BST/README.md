# 449. Serialize and Deserialize BST

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/serialize-and-deserialize-bst/)  
`String` `Tree` `Depth-First Search` `Breadth-First Search` `Design` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 449 - Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/)

## Problem

Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

### Example 1

```text
Input: root = [2,1,3]
Output: [2,1,3]
```

### Example 2

```text
Input: root = []
Output: []
```

## Constraints

- The number of nodes in the tree is in the range [0, 104].
- 0 <= Node.val <= 104
- The input tree is guaranteed to be a binary search tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Serialize and Deserialize N-ary Tree](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 449. Serialize and Deserialize BST

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Postorder traversal to optimize space for the tree structure. | Java, Python |
| Convert int to a 4-byte string to optimize space for node values. | Python |
| Get rid of delimiters. | Java, Python |

## Approach 1: Postorder traversal to optimize space for the tree structure.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Codec {
    public StringBuilder postorder(TreeNode root, StringBuilder sb) {
        if (root == null)
            return sb;
        postorder(root.left, sb);
        postorder(root.right, sb);
        sb.append(root.val);
        sb.append(' ');
        return sb;
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = postorder(root, new StringBuilder());
        if (sb.length() > 0)
            sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    public TreeNode helper(Integer lower, Integer upper, ArrayDeque<Integer> nums) {
        if (nums.isEmpty())
            return null;
        int val = nums.getLast();
        if (val < lower || val > upper)
            return null;

        nums.removeLast();
        TreeNode root = new TreeNode(val);
        root.right = helper(val, upper, nums);
        root.left = helper(lower, val, nums);
        return root;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.isEmpty())
            return null;
        ArrayDeque<Integer> nums = new ArrayDeque<Integer>();
        for (String s : data.split("\\s+"))
            nums.add(Integer.valueOf(s));
        return helper(Integer.MIN_VALUE, Integer.MAX_VALUE, nums);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Codec:
    def serialize(self, root):
        """
        Encodes a tree to a single string.
        """
        def postorder(root):
            return postorder(root.left) + postorder(root.right) + [root.val] if root else []
        return ' '.join(map(str, postorder(root)))

    def deserialize(self, data):
        """
        Decodes your encoded data to tree.
        """
        def helper(lower = float('-inf'), upper = float('inf')):
            if not data or data[-1] < lower or data[-1] > upper:
                return None
            
            val = data.pop()
            root = TreeNode(val)
            root.right = helper(val, upper)
            root.left = helper(lower, val)
            return root
        
        data = [int(x) for x in data.split(' ') if x]
        return helper()
```

</details>

<br>

## Approach 2: Convert int to a 4-byte string to optimize space for node values.

### Implementation

<details>
<summary><strong>Python</strong></summary>

```python
class Codec:
    def postorder(self, root):
        return self.postorder(root.left) + self.postorder(root.right) + [root.val] if root else []
        
    def int_to_str(self, x):
        """
        Encodes integer to bytes string.
        """
        bytes = [chr(x >> (i * 8) & 0xff) for i in range(4)]
        bytes.reverse()
        bytes_str = ''.join(bytes)
        return bytes_str
        
    def serialize(self, root):
        """
        Encodes a tree to a single string.
        """
        lst = self.postorder(root)
        lst = [self.int_to_str(x) for x in lst]
        return 'ç'.join(map(str, lst))
    
    def str_to_int(self, bytes_str):
        """
        Decodes bytes string to integer.
        """
        result = 0
        for ch in bytes_str:
            result = result * 256 + ord(ch)
        return result
        
    def deserialize(self, data):
        """
        Decodes your encoded data to tree.
        """
        def helper(lower = float('-inf'), upper = float('inf')):
            if not data or data[-1] < lower or data[-1] > upper:
                return None
            
            val = data.pop()
            root = TreeNode(val)
            root.right = helper(val, upper)
            root.left = helper(lower, val)
            return root
        
        data = [self.str_to_int(x) for x in data.split('ç') if x]
        return helper()
```

</details>

<br>

## Approach 3: Get rid of delimiters.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Codec {
    // Encodes a tree to a list.
    public void postorder(TreeNode root, StringBuilder sb) {
        if (root == null)
            return;
        postorder(root.left, sb);
        postorder(root.right, sb);
        sb.append(intToString(root.val));
    }

    // Encodes integer to bytes string
    public String intToString(int x) {
        char[] bytes = new char[4];
        for (int i = 3; i > -1; --i) {
            bytes[3 - i] = (char) (x >> (i * 8) & 0xff);
        }
        return new String(bytes);
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        postorder(root, sb);
        return sb.toString();
    }

    // Decodes list to tree.
    public TreeNode helper(Integer lower, Integer upper, ArrayDeque<Integer> nums) {
        if (nums.isEmpty())
            return null;
        int val = nums.getLast();
        if (val < lower || val > upper)
            return null;

        nums.removeLast();
        TreeNode root = new TreeNode(val);
        root.right = helper(val, upper, nums);
        root.left = helper(lower, val, nums);
        return root;
    }

    // Decodes bytes string to integer
    public int stringToInt(String bytesStr) {
        int result = 0;
        for (char b : bytesStr.toCharArray()) {
            result = (result << 8) + (int) b;
        }
        return result;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        ArrayDeque<Integer> nums = new ArrayDeque<Integer>();
        int n = data.length();
        for (int i = 0; i < (int) (n / 4); ++i) {
            nums.add(stringToInt(data.substring(4 * i, 4 * i + 4)));
        }

        return helper(Integer.MIN_VALUE, Integer.MAX_VALUE, nums);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Codec:
    def postorder(self, root):
        return self.postorder(root.left) + self.postorder(root.right) + [root.val] if root else []
        
    def int_to_str(self, x):
        """
        Encodes integer to bytes string
        """
        bytes = [chr(x >> (i * 8) & 0xff) for i in range(4)]
        bytes.reverse()
        bytes_str = ''.join(bytes)
        return bytes_str
        
    def serialize(self, root):
        """
        Encodes a tree to a single string.
        """
        lst = [self.int_to_str(x) for x in self.postorder(root)]
        return ''.join(map(str, lst))
    
    def str_to_int(self, bytes_str):
        """
        Decodes bytes string to integer.
        """
        result = 0
        for ch in bytes_str:
            result = result * 256 + ord(ch)
        return result
        
    def deserialize(self, data):
        """
        Decodes your encoded data to tree.
        """
        def helper(lower = float('-inf'), upper = float('inf')):
            if not data or data[-1] < lower or data[-1] > upper:
                return None
            
            val = data.pop()
            root = TreeNode(val)
            root.right = helper(val, upper)
            root.left = helper(lower, val)
            return root
        
        n = len(data)
        # split data string into chunks of 4 bytes
        # and convert each chunk to int
        data = [self.str_to_int(data[4 * i : 4 * i + 4]) for i in range(n // 4)]
        return helper()
```

</details>
