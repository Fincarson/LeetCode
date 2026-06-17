# 431. Encode N-ary Tree to Binary Tree

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Design` `Binary Tree`

**Problem Link:** [LeetCode 431 - Encode N-ary Tree to Binary Tree](https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/)

## Problem

Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get the original N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. Similarly, a binary tree is a rooted tree in which each node has no more than 2 children. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be decoded to the original N-nary tree structure.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See following example).

For example, you may encode the following 3-ary tree to a binary tree in this way:

```text
Input: root = [1,null,3,2,4,null,5,6]
```

Note that the above is just an example which might or might not work. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

### Example 1

```text
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]
```

### Example 2

```text
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
```

### Example 3

```text
Input: root = []
Output: []
```

## Constraints

- The number of nodes in the tree is in the range [0, 104].
- 0 <= Node.val <= 104
- The height of the n-ary tree is less than or equal to 1000
- Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Serialize and Deserialize N-ary Tree](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 431. Encode N-ary Tree to Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| BFS (Breadth-First Search) Traversal | Java, Python |
| DFS (Depth-First Search) Traversal | Java, Python |

## Approach 1: BFS (Breadth-First Search) Traversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*
// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
   TreeNode(int x) { val = x; }
}
*/

class Pair<U, V> {
  public U first;
  public V second;

  public Pair(U first, V second) {
    this.first = first;
    this.second = second;
  }
}

class Codec {

  // Encodes an n-ary tree to a binary tree.
  public TreeNode encode(Node root) {
    if (root == null) {
      return null;
    }
    TreeNode newRoot = new TreeNode(root.val);
    Pair<TreeNode, Node> head = new Pair<TreeNode, Node>(newRoot, root);

    // Add the first element to kickoff the loop
    Queue<Pair<TreeNode, Node>> queue = new ArrayDeque<Pair<TreeNode, Node>>();
    queue.add(head);

    while (queue.size() > 0) {
      Pair<TreeNode, Node> pair = queue.remove();
      TreeNode bNode = pair.first;
      Node nNode = pair.second;

      // Encoding the children nodes into a list of TreeNode.
      TreeNode prevBNode = null, headBNode = null;
      for (Node nChild : nNode.children) {
        TreeNode newBNode = new TreeNode(nChild.val);
        if (prevBNode == null) {
          headBNode = newBNode;
        } else {
          prevBNode.right = newBNode;
        }
        prevBNode = newBNode;

        Pair<TreeNode, Node> nextEntry = new Pair<TreeNode, Node>(newBNode, nChild);
        queue.add(nextEntry);
      }

      // Attach the list of children to the left node.
      bNode.left = headBNode;
    }

    return newRoot;
  }

  // Decodes your binary tree to an n-ary tree.
  public Node decode(TreeNode root) {
    if (root == null) {
      return null;
    }
    Node newRoot = new Node(root.val, new ArrayList<Node>());

    // adding the first element to kickoff the loop
    Queue<Pair<Node, TreeNode>> queue = new ArrayDeque<Pair<Node, TreeNode>>();
    Pair<Node, TreeNode> head = new Pair<Node, TreeNode>(newRoot, root);
    queue.add(head);

    while (queue.size() > 0) {
      Pair<Node, TreeNode> entry = queue.remove();
      Node nNode = entry.first;
      TreeNode bNode = entry.second;

      // Decoding the children list
      TreeNode firstChild = bNode.left;
      TreeNode sibling = firstChild;
      while (sibling != null) {
        Node nChild = new Node(sibling.val, new ArrayList<Node>());
        nNode.children.add(nChild);

        // prepare the decoding the children of the child, by standing in the queue.
        Pair<Node, TreeNode> nextEntry = new Pair<Node, TreeNode>(nChild, sibling);
        queue.add(nextEntry);

        sibling = sibling.right;
      }
    }

    return newRoot;
  }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(root));
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
"""
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""
class Codec:
    def encode(self, root):
        """Encodes an n-ary tree to a binary tree.
        :type root: Node
        :rtype: TreeNode
        """
        if not root:
            return None

        rootNode = TreeNode(root.val)
        queue = deque([(rootNode, root)])

        while queue:
            parent, curr = queue.popleft()
            prevBNode = None
            headBNode = None
            # traverse each child one by one
            for child in curr.children:
                newBNode = TreeNode(child.val)
                if prevBNode:
                    prevBNode.right = newBNode
                else:
                    headBNode = newBNode
                prevBNode = newBNode
                queue.append((newBNode, child))

            # use the first child in the left node of parent
            parent.left = headBNode

        return rootNode


    def decode(self, data):
        """Decodes your binary tree to an n-ary tree.
        :type data: TreeNode
        :rtype: Node
        """
        if not data:
            return None

        # should set the default value to [] rather than None,
        # otherwise it wont pass the test cases.
        rootNode = Node(data.val, [])

        queue = deque([(rootNode, data)])

        while queue:
            parent, curr = queue.popleft()

            firstChild = curr.left
            sibling = firstChild

            while sibling:
                # Note: the initial value of the children list should not be None, which is assumed by the online judge.
                newNode = Node(sibling.val, [])
                parent.children.append(newNode)
                queue.append((newNode, sibling))
                sibling = sibling.right

        return rootNode
```

</details>

<br>

## Approach 2: DFS (Depth-First Search) Traversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Codec {

  // Encodes an n-ary tree to a binary tree.
  public TreeNode encode(Node root) {
    if (root == null) {
      return null;
    }

    TreeNode newRoot = new TreeNode(root.val);

    // Encode the first child of n-ary node to the left node of binary tree.
    if (root.children.size() > 0) {
      Node firstChild = root.children.get(0);
      newRoot.left = this.encode(firstChild);
    }

    // Encoding the rest of the sibling nodes.
    TreeNode sibling = newRoot.left;
    for (int i = 1; i < root.children.size(); ++i) {
      sibling.right = this.encode(root.children.get(i));
      sibling = sibling.right;
    }

    return newRoot;
  }

  // Decodes your binary tree to an n-ary tree.
  public Node decode(TreeNode root) {
    if (root == null) {
      return null;
    }

    Node newRoot = new Node(root.val, new ArrayList<Node>());

    // Decoding all the children nodes
    TreeNode sibling = root.left;
    while (sibling != null) {
      newRoot.children.add(this.decode(sibling));
      sibling = sibling.right;
    }

    return newRoot;
  }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(root));
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
"""
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""
class Codec:

    def encode(self, root):
        """Encodes an n-ary tree to a binary tree.
        :type root: Node
        :rtype: TreeNode
        """
        if not root:
            return None

        rootNode = TreeNode(root.val)
        if len(root.children) > 0:
            firstChild = root.children[0]
            rootNode.left = self.encode(firstChild)

        # the parent for the rest of the children
        curr = rootNode.left

        # encode the rest of the children
        for i in range(1, len(root.children)):
            curr.right = self.encode(root.children[i])
            curr = curr.right

        return rootNode


    def decode(self, data):
        """Decodes your binary tree to an n-ary tree.
        :type data: TreeNode
        :rtype: Node
        """
        if not data:
            return None

        rootNode = Node(data.val, [])

        curr = data.left
        while curr:
            rootNode.children.append(self.decode(curr))
            curr = curr.right

        return rootNode
```

</details>
