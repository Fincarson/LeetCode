# 572. Subtree of Another Tree

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/subtree-of-another-tree/)  
`Tree` `Depth-First Search` `String Matching` `Binary Tree` `Hash Function`

**Problem Link:** [LeetCode 572 - Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)

## Problem

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

### Example 1

```text
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
```

### Example 2

```text
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
```

## Constraints

- The number of nodes in the root tree is in the range [1, 2000].
- The number of nodes in the subRoot tree is in the range [1, 1000].
- -104 <= root.val <= 104
- -104 <= subRoot.val <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Univalue Subtrees](https://leetcode.com/problems/count-univalue-subtrees/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 572. Subtree of Another Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java, Python3 |
| String Matching | C++, Java, Python3 |
| Tree Hash | C++, Java, Python3 |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // If this node is Empty, then no tree is rooted at this Node
        // Hence, "tree rooted at node" cannot be equal to "tree rooted at subRoot"
        // "tree rooted at subRoot" will always be non-empty, as per constraints
        if (root == nullptr) {
            return false;
        }

        // Check if the "tree rooted at root" is identical to "tree roooted at subRoot"
        if (isIdentical(root, subRoot)) {
            return true;
        }

        // If not, check for "tree rooted at root.left" and "tree rooted at root.right"
        // If either of them returns true, return true
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* node1, TreeNode* node2) {

        // If any of the nodes is null, then both must be null
        if (node1 == nullptr || node2 == nullptr) {
            return node1 == nullptr && node2 == nullptr;
        }

        // If both nodes are non-empty, then they are identical only if
        // 1. Their values are equal
        // 2. Their left subtrees are identical
        // 3. Their right subtrees are identical
        return node1->val == node2->val && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {

        // If this node is Empty, then no tree is rooted at this Node
        // Hence, "tree rooted at node" cannot be equal to "tree rooted at subRoot"
        // "tree rooted at subRoot" will always be non-empty, as per constraints
        if (root == null) {
            return false;
        }

        // Check if the "tree rooted at root" is identical to "tree roooted at subRoot"
        if (isIdentical(root, subRoot)) {
            return true;
        }

        // If not, check for "tree rooted at root.left" and "tree rooted at root.right"
        // If either of them returns true, return true
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }

    private boolean isIdentical(TreeNode node1, TreeNode node2) {

        // If any of the nodes is null, then both must be null
        if (node1 == null || node2 == null) {
            return node1 == null && node2 == null;
        }

        // If both nodes are non-empty, then they are identical only if
        // 1. Their values are equal
        // 2. Their left subtrees are identical
        // 3. Their right subtrees are identical
        return node1.val == node2.val && isIdentical(node1.left, node2.left) && isIdentical(node1.right, node2.right);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        # Check for all subtree rooted at all nodes of tree "root"
        def dfs(node):

            # If this node is Empty, then no tree is rooted at this Node
            # Thus "tree rooted at node" cannot be same as "rooted at subRoot"
            # "tree rooted at subRoot" will always be non-empty (constraints)
            if node is None:
                return False

            # If "tree rooted at node" is identical to "tree at subRoot"
            elif is_identical(node, subRoot):
                return True

            # If "tree rooted at node" was not identical.
            # Check for tree rooted at children
            return dfs(node.left) or dfs(node.right)

        def is_identical(node1, node2):

            # If any one Node is Empty, both should be Empty
            if node1 is None or node2 is None:
                return node1 is None and node2 is None

            # Both Nodes Value should be Equal
            # And their respective left and right subtree should be identical
            return (node1.val == node2.val and
                    is_identical(node1.left, node2.left) and
                    is_identical(node1.right, node2.right))

        # Check for node rooted at "root"
        return dfs(root)
```

</details>

<br>

## Approach 2: String Matching

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         // Serialize given Nodes
        string r = "";
        serialize(root, r);
        string s = "";
        serialize(subRoot, s);
                 
         // Check if s is in r
         return kmp(s, r);
     }
    
    // Function to serialize Tree
    void serialize(TreeNode* node, string& treeStr) {
        if (node == nullptr){
            treeStr += "#";
            return;
        }

        treeStr += "^";
        treeStr += to_string(node->val);
        serialize(node->left, treeStr);
        serialize(node->right, treeStr);
    }

    // Knuth-Morris-Pratt algorithm to check if `needle` is in `haystack` or not
    bool kmp(string needle, string haystack) {
        int m = needle.length();
        int n = haystack.length();
        
        if (n < m)
            return false;
        
        // longest proper prefix which is also suffix
        vector<int> lps(m);
        // Length of Longest Border for prefix before it.
        int prev = 0;
        // Iterating from index-1. lps[0] will always be 0
        int i = 1;
        
        while (i < m) {
            if (needle[i] == needle[prev]) {
                // Length of Longest Border Increased
                prev += 1;
                lps[i] = prev;
                i += 1;
            } else {
                // Only empty border exist
                if (prev == 0) {
                    lps[i] = 0;
                    i += 1;
                } else {
                    // Try finding longest border for this i with reduced prev
                    prev = lps[prev-1];
                }
            }
        }
        
        // Pointer for haystack
        int haystackPointer = 0;
        // Pointer for needle.
        // Also indicates number of characters matched in current window.
        int needlePointer = 0;
        
        while (haystackPointer < n) {
            if (haystack[haystackPointer] == needle[needlePointer]) {
                // Matched Increment Both
                needlePointer += 1;
                haystackPointer += 1;
                // All characters matched
                if (needlePointer == m)
                    return true;                
            } else {                
                if (needlePointer == 0) {
                    // Zero Matched
                    haystackPointer += 1;                    
                } else {
                    // Optimally shift left needlePointer. Don't change haystackPointer
                    needlePointer = lps[needlePointer-1];
                }
            }
        }
        
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        // Serialize given Nodes
        StringBuilder rootList = new StringBuilder();
        serialize(root, rootList);
        String r = rootList.toString();

        StringBuilder subRootList = new StringBuilder();
        serialize(subRoot, subRootList);
        String s = subRootList.toString();

        // Check if s is in r
        return kmp(s, r);
    }

    // Function to serialize Tree
    private void serialize(TreeNode node, StringBuilder treeStr) {
        if (node == null) {
            treeStr.append("#");
            return;
        }

        treeStr.append("^");
        treeStr.append(node.val);
        serialize(node.left, treeStr);
        serialize(node.right, treeStr);
    }

    // Knuth-Morris-Pratt algorithm to check if `needle` is in `haystack` or not
    private boolean kmp(String needle, String haystack) {
        int m = needle.length();
        int n = haystack.length();

        if (n < m)
            return false;

        // longest proper prefix which is also suffix
        int[] lps = new int[m];
        // Length of Longest Border for prefix before it.
        int prev = 0;
        // Iterating from index-1. lps[0] will always be 0
        int i = 1;

        while (i < m) {
            if (needle.charAt(i) == needle.charAt(prev)) {
                // Length of Longest Border Increased
                prev += 1;
                lps[i] = prev;
                i += 1;
            } else {
                // Only empty border exist
                if (prev == 0) {
                    lps[i] = 0;
                    i += 1;
                } else {
                    // Try finding longest border for this i with reduced prev
                    prev = lps[prev - 1];
                }
            }
        }

        // Pointer for haystack
        int haystackPointer = 0;
        // Pointer for needle.
        // Also indicates number of characters matched in current window.
        int needlePointer = 0;

        while (haystackPointer < n) {
            if (haystack.charAt(haystackPointer) == needle.charAt(needlePointer)) {
                // Matched Increment Both
                needlePointer += 1;
                haystackPointer += 1;
                // All characters matched
                if (needlePointer == m)
                    return true;
            } else {
                if (needlePointer == 0) {
                    // Zero Matched
                    haystackPointer += 1;
                } else {
                    // Optimally shift left needlePointer. Don't change haystackPointer
                    needlePointer = lps[needlePointer - 1];
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
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        # Function to serialize Tree
        def serialize(node, tree_str):
            if node is None:
                tree_str.append('#')
                return

            tree_str.append("^")
            tree_str.append(str(node.val))
            serialize(node.left, tree_str)
            serialize(node.right, tree_str)

        # Knuth-Morris-Pratt algorithm to check if `needle` is in `haystack`
        def kmp(needle, haystack):
            m = len(needle)
            n = len(haystack)

            if n < m:
                return False

            # longest proper prefix which is also suffix
            lps = [0]*m
            # Length of Longest Border for prefix before it.
            prev = 0
            # Iterating from index-1. lps[0] will always be 0
            i = 1

            while i < m:
                if needle[i] == needle[prev]:
                    # Length of Longest Border Increased
                    prev += 1
                    lps[i] = prev
                    i += 1
                else:
                    # Only empty border exist
                    if prev == 0:
                        lps[i] = 0
                        i += 1
                    # Try finding longest border for this i with reduced prev
                    else:
                        prev = lps[prev-1]

            # Pointer for haystack
            haystack_pointer = 0
            # Pointer for needle.
            # Also indicates number of characters matched in current window.
            needle_pointer = 0

            while haystack_pointer < n:
                if haystack[haystack_pointer] == needle[needle_pointer]:
                    # Matched Increment Both
                    needle_pointer += 1
                    haystack_pointer += 1
                    # All characters matched
                    if needle_pointer == m:
                        return True
                else:
                    if needle_pointer == 0:
                        # Zero Matched
                        haystack_pointer += 1
                    else:
                        # Optimally shift left needle_pointer. 
                        # Don't change haystack_pointer
                        needle_pointer = lps[needle_pointer-1]
            
            return False

        # Serialize given Nodes
        root_list = []
        serialize(root, root_list)
        r = "".join(root_list)

        subroot_list = []
        serialize(subRoot, subroot_list)
        s = "".join(subroot_list)

        # Check if s is in r
        return kmp(s, r)
```

</details>

<br>

## Approach 3: Tree Hash

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
   public:
    // CONSTANTS
    const int MOD_1 = 1000000007;
    const int MOD_2 = 2147483647;

    // Hashing a Node
    pair<unsigned long long, unsigned long long> hashSubtreeAtNode(TreeNode* node, bool needToAdd) {
        if (node == nullptr) return {3, 7};

        auto left = hashSubtreeAtNode(node->left, needToAdd);
        auto right = hashSubtreeAtNode(node->right, needToAdd);

        auto left1 = (left.first << 5) % MOD_1;
        auto right1 = (right.first << 1) % MOD_1;
        auto left2 = (left.second << 7) % MOD_2;
        auto right2 = (right.second << 1) % MOD_2;

        pair hashpair = {(left1 + right1 + node->val) % MOD_1,
                         (left2 + right2 + node->val) % MOD_2};

        if (needToAdd) memo.push_back(hashpair);

        return hashpair;
    }

    // Vector to store hashed value of each node.
    vector<pair<unsigned long long, unsigned long long>> memo;

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Calling and adding hash to vector
        hashSubtreeAtNode(root, true);

        // Storing hashed value of subRoot for comparison
        pair<unsigned long long, unsigned long long> s = hashSubtreeAtNode(subRoot, false);

        // Check if hash of subRoot is present in memo
        return find(memo.begin(), memo.end(), s) != memo.end();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // CONSTANTS
    final int MOD_1 = 1000000007;
    final int MOD_2 = 2147483647;

    // Hashing a Node
    long[] hashSubtreeAtNode(TreeNode node, boolean needToAdd) {

        if (node == null)
            return new long[] { 3, 7 };

        long[] left = hashSubtreeAtNode(node.left, needToAdd);
        long[] right = hashSubtreeAtNode(node.right, needToAdd);

        long left1 = (left[0] << 5) % MOD_1;
        long right1 = (right[0] << 1) % MOD_1;
        long left2 = (left[1] << 7) % MOD_2;
        long right2 = (right[1] << 1) % MOD_2;

        long[] hashpair = { (left1 + right1 + node.val) % MOD_1,
                (left2 + right2 + node.val) % MOD_2 };

        if (needToAdd)
            memo.add(hashpair);

        return hashpair;
    }

    // Vector to store hashed value of each node.
    List<long[]> memo = new ArrayList<>();

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {

        // Calling and adding hash to List
        hashSubtreeAtNode(root, true);

        // Storing hashed value of subRoot for comparison
        long[] s = hashSubtreeAtNode(subRoot, false);

        // Check if hash of subRoot is present in memo
        for (long[] m : memo) {
            if (m[0] == s[0] && m[1] == s[1])
                return true;
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSubtree(self, root: TreeNode, subRoot: TreeNode) -> bool:

        MOD_1 = 1_000_000_007
        MOD_2 = 2_147_483_647

        def hash_subtree_at_node(node, need_to_add):
            if node is None:
                return (3, 7)

            left = hash_subtree_at_node(node.left, need_to_add)
            right = hash_subtree_at_node(node.right, need_to_add)

            left_1 = (left[0] << 5) % MOD_1
            right_1 = (right[0] << 1) % MOD_1
            left_2 = (left[1] << 7) % MOD_2
            right_2 = (right[1] << 1) % MOD_2

            hashpair = ((left_1 + right_1 + node.val) % MOD_1,
                        (left_2 + right_2 + node.val) % MOD_2)

            if need_to_add:
                memo.add(hashpair)

            return hashpair

        # List to store hashed value of each node.
        memo = set()

        # Calling and adding hash to List
        hash_subtree_at_node(root, True)

        # Storing hashed value of subRoot for comparison
        s = hash_subtree_at_node(subRoot, False)

        # Check if hash of subRoot is present in memo
        return s in memo
```

</details>
