# 1214. Two Sum BSTs

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/two-sum-bsts/)  
`Two Pointers` `Binary Search` `Stack` `Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 1214 - Two Sum BSTs](https://leetcode.com/problems/two-sum-bsts/)

## Problem

Given the roots of two binary search trees, root1 and root2, return true if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

### Example 1

```text
Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.
```

### Example 2

```text
Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false
```

## Constraints

- The number of nodes in each tree is in the range [1, 5000].
- -109 <= Node.val, target <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1214. Two Sum BSTs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python3 |
| Binary Search | Java, Python3 |
| Hash Set | Java, Python |
| Two Pointers | Java, Python |
| Morris Traversal | Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private void dfs(TreeNode currNode, List<Integer> nodeList) {
        if (currNode == null) {
            return;
        }
        node_list.add(currNode.val);
        dfs(currNode.left, nodeList);
        dfs(currNode.right, nodeList);
    }

    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        List<Integer> nodeList1 = new ArrayList<>();
        List<Integer> nodeList2 = new ArrayList<>();
        dfs(root1, nodeList1);
        dfs(root2, nodeList2);

        for (int a : nodeList1) {
            for (int b : nodeList2) {
                if (a + b == target) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        def dfs(curr_node, node_list):
            if not curr_node:
                return
            node_list.append(curr_node.val)
            dfs(curr_node.left, node_list)
            dfs(curr_node.right, node_list)
        
        node_list1, node_list2 = [], []
        dfs(root1, node_list1)
        dfs(root2, node_list2)
        
        for a in node_list1:
            for b in node_list2:
                if a + b == target:
                    return True
        return False
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private boolean binarySearch(TreeNode root2, int target2) {
        if (root2 == null) {
            return false;
        }
        if (root2.val == target2) {
            return true;
        } else if (root2.val > target2) {
            return binarySearch(root2.left, target2);
        } else {
            return binarySearch(root2.right, target2);
        }
    }
    private boolean dfs(TreeNode root1, TreeNode root2, int target) {
        if (root1 == null) {
            return false;
        }
        if (binarySearch(root2, target - root1.val)) {
            return true;
        }
        return dfs(root1.left, root2, target) || dfs(root1.right, root2, target);
    }
    
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        return dfs(root1, root2, target);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        def binarySearch(root2, target2):
            if not root2:
                return False
            if root2.val == target2:
                return True
            elif root2.val > target2:
                return binarySearch(root2.left, target2)
            else:
                return binarySearch(root2.right, target2)

        def dfs(root, target):
            if not root:
                return False
            if binarySearch(root2, target - root.val):
                return True
            return dfs(root.left, target) or dfs(root.right, target)

        return dfs(root1, target)
```

</details>

<br>

## Approach 3: Hash Set

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private void dfs(TreeNode currNode, Set<Integer> nodeSet) {
        if (currNode == null) {
            return;
        }
        dfs(currNode.left, nodeSet);
        nodeSet.add(currNode.val);
        dfs(currNode.right, nodeSet);
    }
    
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        Set<Integer> nodeSet1 = new HashSet<>();
        Set<Integer> nodeSet2 = new HashSet<>();
        dfs(root1, nodeSet1);
        dfs(root2, nodeSet2);

        for (int value1 : nodeSet1) {
            if (nodeSet2.contains(target - value1)) {
                return true;
            }
        }
        
        return false;
    }   
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        def dfs(curr_node, node_set):
            if not curr_node:
                return
            dfs(curr_node.left, node_set)
            node_set.add(curr_node.val)
            dfs(curr_node.right, node_set)
        
        node_set1, node_set2 = set(), set()
        dfs(root1, node_set1)
        dfs(root2, node_set2)
        
        for value1 in node_set1:
            if target - value1 in node_set2:
                return True
        return False
```

</details>

<br>

## Approach 4: Two Pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private void dfs(TreeNode currNode, List<Integer> nodeList) {
        if (currNode == null) {
            return;
        }
        dfs(currNode.left, nodeList);
        nodeList.add(currNode.val);
        dfs(currNode.right, nodeList);
    }
    
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        List<Integer> nodeList1 = new ArrayList<>();
        List<Integer> nodeList2 = new ArrayList<>();
        dfs(root1, nodeList1);
        dfs(root2, nodeList2);

        int pointer1 = 0, pointer2 = nodeList2.size() - 1;
        while (pointer1 < nodeList1.size() && pointer2 >= 0) {
            if (nodeList1.get(pointer1) + nodeList2.get(pointer2) == target) {
                return true;
            } else if (nodeList1.get(pointer1) + nodeList2.get(pointer2) < target) {
                pointer1++;
            } else {
                pointer2--;
            }
        }
        
        return false;
    }   
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        def dfs(curr_node, node_list):
            if not curr_node:
                return
            dfs(curr_node.left, node_list)
            node_list.append(curr_node.val)
            dfs(curr_node.right, node_list)
        
        node_list1, node_list2 = [], []
        dfs(root1, node_list1)
        dfs(root2, node_list2)
        
        pointer1 = 0
        pointer2 = len(node_list2) - 1
        while pointer1 < len(node_list1) and pointer2 >= 0:
            if node_list1[pointer1] + node_list2[pointer2] == target:
                return True
            elif node_list1[pointer1] + node_list2[pointer2] < target:
                pointer1 += 1
            else:
                pointer2 -= 1
        return False
```

</details>

<br>

## Approach 5: Morris Traversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class MorrisIterator implements Iterator<Integer> {
    private TreeNode current;
    private TreeNode pre;

    public MorrisIterator(TreeNode root) {
        current = root;
        pre = null;
    }

    public boolean hasNext() {
        return current != null;
    }

    public Integer next() {
        Integer val = null;
        while (current != null) {
            if (current.left == null) {
                val = current.val;
                current = current.right;
                break;
            } else {
                pre = current.left;
                while (pre.right != null && pre.right != current) {
                    pre = pre.right;
                }
                if (pre.right == null) {
                    pre.right = current;
                    current = current.left;
                } else {
                    pre.right = null;
                    val = current.val;
                    current = current.right;
                    break;
                }
            }
        }
        return val;
    }
}

class ReversedMorrisIterator implements Iterator<Integer> {
    private TreeNode current;
    private TreeNode pre;

    public ReversedMorrisIterator(TreeNode root) {
        current = root;
        pre = null;
    }

    public boolean hasNext() {
        return current != null;
    }

    public Integer next() {
        Integer val = null;
        while (current != null) {
            if (current.right == null) {
                val = current.val;
                current = current.left;
                break;
            } else {
                pre = current.right;
                while (pre.left != null && pre.left != current) {
                    pre = pre.left;
                }
                if (pre.left == null) {
                    pre.left = current;
                    current = current.right;
                } else {
                    pre.left = null;
                    val = current.val;
                    current = current.left;
                    break;
                }
            }
        }
        return val;
    }
}

class Solution {
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        MorrisIterator iterator1 = new MorrisIterator(root1);
        ReversedMorrisIterator iterator2 = new ReversedMorrisIterator(root2);
        
        int value1 = iterator1.next(), value2 = iterator2.next();
        
        while (value1 != Integer.MIN_VALUE && value2 != Integer.MIN_VALUE) {
            if (value1 + value2 == target) {
                return true;
            } else if (value1 + value2 < target) {
                if (iterator1.hasNext()) {
                    value1 = iterator1.next();
                } else {
                    value1 = Integer.MIN_VALUE;
                }
            } else {
                if (iterator2.hasNext()) {
                    value2 = iterator2.next();
                } else {
                    value2 = Integer.MIN_VALUE;
                }
            }
        }
        
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        def morris_traversal(root):
            current = root
            while current:
                if not current.left:

                    # If you're a little confused about the key word 'yield', 
                    # please see the next paragraph for some explanation.
                    yield current.val
                    current = current.right
                else:
                    pre = current.left
                    while pre.right and pre.right != current:
                        pre = pre.right
                    if not pre.right:
                        pre.right = current
                        current = current.left
                    else:
                        pre.right = None
                        yield current.val
                        current = current.right

        def reversed_morris_traversal(root):
            current = root
            while current:
                if not current.right:
                    yield current.val
                    current = current.left
                else:
                    pre = current.right
                    while pre.left and pre.left != current:
                        pre = pre.left
                    if not pre.left:
                        pre.left = current
                        current = current.right
                    else:
                        pre.left = None
                        yield current.val
                        current = current.left
                        
        iterater1 = morris_traversal(root1)
        iterater2 = reversed_morris_traversal(root2)
        value1 = next(iterater1, None)
        value2 = next(iterater2, None)

        while value1 is not None and value2 is not None:
            if value1 + value2 == target:
                return True
            elif value1 + value2 < target:
                value1 = next(iterater1, None)
            else:
                value2 = next(iterater2, None)
        return False
```

</details>
