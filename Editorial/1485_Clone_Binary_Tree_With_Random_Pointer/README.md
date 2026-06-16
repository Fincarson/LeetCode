# 1485. Clone Binary Tree With Random Pointer

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/clone-binary-tree-with-random-pointer/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1485 - Clone Binary Tree With Random Pointer](https://leetcode.com/problems/clone-binary-tree-with-random-pointer/)

## Problem

A binary tree is given such that each node contains an additional random pointer which could point to any node in the tree or null.

Return a deep copy of the tree.

The tree is represented in the same input/output way as normal binary trees where each node is represented as a pair of [val, random_index] where:

- val: an integer representing Node.val
- random_index: the index of the node (in the input) where the random pointer points to, or null if it does not point to any node.

You will be given the tree in class Node and you should return the cloned tree in class NodeCopy. NodeCopy class is just a clone of Node class with the same attributes and constructors.

### Example 1

```text
Input: root = [[1,null],null,[4,3],[7,0]]
Output: [[1,null],null,[4,3],[7,0]]
Explanation: The original binary tree is [1,null,4,7].
The random pointer of node one is null, so it is represented as [1, null].
The random pointer of node 4 is node 7, so it is represented as [4, 3] where 3 is the index of node 7 in the array representing the tree.
The random pointer of node 7 is node 1, so it is represented as [7, 0] where 0 is the index of node 1 in the array representing the tree.
```

### Example 2

```text
Input: root = [[1,4],null,[1,0],null,[1,5],[1,5]]
Output: [[1,4],null,[1,0],null,[1,5],[1,5]]
Explanation: The random pointer of a node can be the node itself.
```

### Example 3

```text
Input: root = [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
Output: [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
```

## Constraints

- The number of nodes in the tree is in the range [0, 1000].
- 1 <= Node.val <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Clone Graph](https://leetcode.com/problems/clone-graph/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Clone N-ary Tree](https://leetcode.com/problems/clone-n-ary-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1485. Clone Binary Tree With Random Pointer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search On Binary Tree (2 Passes) | C++, Java, Python3 |
| Depth-First Search On Graph (1 Pass) | C++, Java, Python3 |
| Breadth-First Search on Graph | C++, Java, Python3 |

## Approach 1: Depth-First Search On Binary Tree (2 Passes)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Hashmap to map old tree's nodes with new tree's nodes.
    unordered_map<Node*, NodeCopy*> newOldPairs;
public:
    NodeCopy* deepCopy(Node* root) {
        if (!root) {
            return NULL;
        }
        NodeCopy* newRoot = new NodeCopy(root->val);
        // Deep copy left subtree and attach it on new node's left.
        newRoot->left = deepCopy(root->left);
        // Deep copy right subtree and attach it on new node's right.
        newRoot->right = deepCopy(root->right);
        // Store the new node and old node's pair in hash map.
        newOldPairs[root] = newRoot;
        return newRoot;
    }

    void mapRandomPointers(Node* oldNode) {
        if (!oldNode) {
            return;
        }
        NodeCopy* newNode = newOldPairs[oldNode];
        Node* oldNodeRandom = oldNode->random;
        NodeCopy* newNodeRandom = newOldPairs[oldNodeRandom];
        // Map newNode with it's respective random node.
        newNode->random = newNodeRandom;
        // Traverse on rest nodes to map their respective new node's random pointers.
        mapRandomPointers(oldNode->left);
        mapRandomPointers(oldNode->right);
    }

    NodeCopy* copyRandomBinaryTree(Node* root) {
        // Create a new tree for each node of old tree and map new node with old respective node.
        NodeCopy* newRoot = deepCopy(root);
        // We will assign random pointers of new tree to respective correct new nodes.
        mapRandomPointers(root);
        return newRoot;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Hashmap to map old tree's nodes with new tree's nodes.
    private HashMap<Node, NodeCopy> newOldPairs = new HashMap<>();

    private  NodeCopy deepCopy(Node root) {
        if (root == null) {
            return null;
        }
        NodeCopy newRoot = new NodeCopy(root.val);
        // Deep copy left subtree and attach it on new node's left.
        newRoot.left = deepCopy(root.left);
        // Deep copy right subtree and attach it on new node's right.
        newRoot.right = deepCopy(root.right);
        // Store the new node and old node's pair in hash map.
        newOldPairs.put(root, newRoot);
        return newRoot;
    }

    private void mapRandomPointers(Node oldNode) {
        if (oldNode == null) {
            return;
        }
        NodeCopy newNode = newOldPairs.get(oldNode);
        Node oldNodeRandom = oldNode.random;
        NodeCopy newNodeRandom = newOldPairs.get(oldNodeRandom);
        // Map newNode with it's respective random node.
        newNode.random = newNodeRandom;
        // Traverse on rest nodes to map their respective new node's random pointers.
        mapRandomPointers(oldNode.left);
        mapRandomPointers(oldNode.right);
    }

    public NodeCopy copyRandomBinaryTree(Node root) {
        // Create a new tree for each node of old tree and map new node with old respective node.
        NodeCopy newRoot = deepCopy(root);
        // We will assign random pointers of new tree to respective correct new nodes.
        mapRandomPointers(root);
        return newRoot;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        # Hashmap to map old tree's nodes with new tree's nodes.
        self.new_old_pairs: dict[str, int] = {None: None}

    def deep_copy(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        if not root:
            return None
        new_root = NodeCopy(root.val)
        # Deep copy left subtree and attach it on new node's left.
        new_root.left = self.deep_copy(root.left)
        # Deep copy right subtree and attach it on new node's right.
        new_root.right = self.deep_copy(root.right)
        # Store the new node and old node's pair in hash map.
        self.new_old_pairs[root] = new_root
        return new_root

    def map_random_pointers(self, old_node: 'Optional[Node]') -> None:
        if not old_node:
            return
        new_node = self.new_old_pairs[old_node]
        old_node_random = old_node.random
        new_node_random = self.new_old_pairs[old_node_random]
        # Map newNode with it's respective random node.
        new_node.random = new_node_random
        # Traverse on rest nodes to map their respective new node's random pointers.
        self.map_random_pointers(old_node.left)
        self.map_random_pointers(old_node.right)

    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        # Create a new tree for each node of old tree and map new node with old respective node.
        new_root = self.deep_copy(root)
        # We will assign random pointers of new tree to respective correct new nodes.
        self.map_random_pointers(root)
        return new_root
```

</details>

<br>

## Approach 2: Depth-First Search On Graph (1 Pass)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Hashmap to map old tree's nodes with new tree's nodes.
    unordered_map<Node*, NodeCopy*> seen;
  
    // Function to traverse on the sub graph of 'root'.
    NodeCopy* dfs(Node* root) {
        if (!root) {
            return NULL;
        }
        if (seen.find(root) != seen.end()) {
            return seen[root];
        }

        NodeCopy* newRoot = new NodeCopy(root->val);
        // Mark old root as seen and store its respective new node.
        seen[root] = newRoot;
        
        // Traverse on all 3 edges of root and attach respective new node
        // to the newRoot.
        newRoot->left = dfs(root->left);
        newRoot->right = dfs(root->right);
        newRoot->random = dfs(root->random);
        return newRoot;
    }

public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        // Traverse on each node of the given tree.
        NodeCopy* newRoot = dfs(root);
        return newRoot;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Hashmap to map old tree's nodes with new tree's nodes.
    private HashMap<Node, NodeCopy> seen = new HashMap<>();

    private  NodeCopy dfs(Node root) {
        if (root == null) {
            return null;
        }
        if (seen.containsKey(root)) {
            return seen.get(root);
        }

        NodeCopy newRoot = new NodeCopy(root.val);
        // Mark old root as seen and store its respective new node.
        seen.put(root, newRoot);
        
        // Traverse on all 3 edges of root and attach respective new node
        // to the newRoot.
        newRoot.left = dfs(root.left);
        newRoot.right = dfs(root.right);
        newRoot.random = dfs(root.random);
        return newRoot;
    }

    public NodeCopy copyRandomBinaryTree(Node root) {
        // Traverse on each node of the given tree.
        NodeCopy newRoot = dfs(root);
        return newRoot;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        # Hashmap to map old tree's nodes with new tree's nodes.
        self.seen: dict[str, int] = {None: None}
            
    # Function to traverse on the sub graph of 'root'.
    def dfs(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        if not root:
            return None

        if self.seen.get(root) is not None:
            return self.seen.get(root)

        new_root = NodeCopy(root.val)
        # Mark old root as seen and store its respective new node.
        self.seen[root] = new_root
        
        # Traverse on all 3 edges of root and attach respective new node
        # to the newRoot.
        new_root.left = self.dfs(root.left)
        new_root.right = self.dfs(root.right)
        new_root.random = self.dfs(root.random)
        return new_root

    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        # Traverse on each node of the given tree.
        new_root = self.dfs(root)
        return new_root
```

</details>

<br>

## Approach 3: Breadth-First Search on Graph

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Hashmap to map old tree's nodes with new tree's nodes.
    unordered_map<Node*, NodeCopy*> seen;
  
    // Function to traverse on the sub graph of 'root'.
    NodeCopy* bfs(Node* root) {
        if (!root) {
            return NULL;
        }
        queue<Node*> pending;
        // Push root in queue, mark it as seen and, 
        // store its respective new node.
        pending.push(root);
        seen[root] = new NodeCopy(root->val);
        
        while (pending.size()) {
            Node* oldNode = pending.front();
            pending.pop();
            NodeCopy* newNode = seen[oldNode];
            
            // Traverse on left, right and random edges one-by-one, if nodes exist and, 
            // not already seen then we push it in queue, create a copy and attach it to new node.
            if (oldNode->left) {
                if (seen.find(oldNode->left) == seen.end()) {
                    pending.push(oldNode->left);
                    seen[oldNode->left] = new NodeCopy(oldNode->left->val);
                }
                newNode->left = seen[oldNode->left];
            }
            if (oldNode->right) {
                if (seen.find(oldNode->right) == seen.end()) {
                    pending.push(oldNode->right);
                    seen[oldNode->right] = new NodeCopy(oldNode->right->val);
                }
                newNode->right = seen[oldNode->right];
            }
            if (oldNode->random) {
                if (seen.find(oldNode->random) == seen.end()) {
                    pending.push(oldNode->random);
                    seen[oldNode->random] = new NodeCopy(oldNode->random->val);
                }
                newNode->random = seen[oldNode->random];
            }
        }
        
        return seen[root];
    }

public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        // Traverse on each node of the given tree.
        NodeCopy* newRoot = bfs(root);
        return newRoot;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Hashmap to map old tree's nodes with new tree's nodes.
    private HashMap<Node, NodeCopy> seen = new HashMap<>();

    private  NodeCopy bfs(Node root) {
        if (root == null) {
            return null;
        }
        Queue<Node> pending = new LinkedList<>();
        // Push root in queue, mark it as seen and, 
        // store its respective new node.
        pending.add(root);
        seen.put(root, new NodeCopy(root.val));
        
        while (!pending.isEmpty()) {
            Node oldNode = pending.poll();
            NodeCopy newNode = seen.get(oldNode);
            
            // Traverse on left, right and random edges one-by-one, if nodes exist and, 
            // not already seen then we push it in queue, create a copy and attach it to new node.
            if (oldNode.left != null) {
                if (!seen.containsKey(oldNode.left)) {
                    pending.add(oldNode.left);
                    seen.put(oldNode.left, new NodeCopy(oldNode.left.val));
                }
                newNode.left = seen.get(oldNode.left);
            }
            if (oldNode.right != null) {
                if (!seen.containsKey(oldNode.right)) {
                    pending.add(oldNode.right);
                    seen.put(oldNode.right, new NodeCopy(oldNode.right.val));
                }
                newNode.right = seen.get(oldNode.right);
            }
            if (oldNode.random != null) {
                if (!seen.containsKey(oldNode.random)) {
                    pending.add(oldNode.random);
                    seen.put(oldNode.random, new NodeCopy(oldNode.random.val));
                }
                newNode.random = seen.get(oldNode.random);
            }
        }
        return seen.get(root);
    }

    public NodeCopy copyRandomBinaryTree(Node root) {
        // Traverse on each node of the given tree.
        NodeCopy newRoot = bfs(root);
        return newRoot;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        # Hashmap to map old tree's nodes with new tree's nodes.
        self.seen: dict = {None: None}
            
    # Function to traverse on the sub graph of 'root'.
    def bfs(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        if not root:
            return None

        pending = deque()
        # Push root in queue, mark it as seen and, 
        # store its respective new node.
        pending.append(root)
        self.seen[root] = NodeCopy(root.val)
        
        while pending:
            old_node = pending.popleft()
            new_node = self.seen[old_node]
            
            # Traverse on left, right and random edges one-by-one, if nodes exist and, 
            # not already seen then we push it in queue, create a copy and attach it to new node.
            if old_node.left:
                if not old_node.left in self.seen:
                    pending.append(old_node.left)
                    self.seen[old_node.left] = NodeCopy(old_node.left.val)
                new_node.left = self.seen[old_node.left]

            if old_node.right:
                if not old_node.right in self.seen:
                    pending.append(old_node.right)
                    self.seen[old_node.right] = NodeCopy(old_node.right.val)
                new_node.right = self.seen[old_node.right]

            if old_node.random:
                if not old_node.random in self.seen:
                    pending.append(old_node.random)
                    self.seen[old_node.random] = NodeCopy(old_node.random.val)
                new_node.random = self.seen[old_node.random]

        return self.seen[root]

    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        # Traverse on each node of the given tree.
        new_root = self.bfs(root)
        return new_root
```

</details>
