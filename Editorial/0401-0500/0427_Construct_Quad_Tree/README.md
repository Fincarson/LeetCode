# 427. Construct Quad Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/construct-quad-tree/)  
`Array` `Divide and Conquer` `Tree` `Matrix`

**Problem Link:** [LeetCode 427 - Construct Quad Tree](https://leetcode.com/problems/construct-quad-tree/)

## Problem

Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

- val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
- isLeaf: True if the node is a leaf node on the tree or False if the node has four children.

```text
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
```

We can construct a Quad-Tree from a two-dimensional area using the following steps:

If you want to know more about the Quad-Tree, you can refer to the wiki.

Quad-Tree format:

You don't need to read this section for solving the problem. This is only if you want to understand the output format here. The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].

If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.

### Example 1

```text
Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represents False and 1 represents True in the photo representing the Quad-Tree.
```

### Example 2

```text
Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below:
```

## Constraints

- n == grid.length == grid[i].length
- n == 2x where 0 <= x <= 6

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 427. Construct Quad Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C++, Java |
| Optimized Recursion | C++, Java |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Returns true if all the values in the matrix are the same; otherwise, false.
    bool sameValue(vector<vector<int>>& grid, int x1, int y1, int length) {
        for (int i = x1; i < x1 + length; i++) {
            for (int j = y1; j < y1 + length; j++)
                if (grid[i][j] != grid[x1][y1])
                    return false;
        }
        return true;
    }
    
    Node* solve(vector<vector<int>>& grid, int x1, int y1, int length) {
        // Return a leaf node if all values are the same.
        if (sameValue(grid, x1, y1, length)) {
            return new Node(grid[x1][y1], true);
        } else {
            Node* root = new Node(false, false);

            // Recursive call for the four sub-matrices.
            root -> topLeft = solve(grid, x1, y1, length / 2);
            root -> topRight = solve(grid, x1, y1 + length / 2, length / 2);
            root -> bottomLeft = solve(grid, x1 + length / 2, y1, length / 2);
            root -> bottomRight = solve(grid, x1 + length / 2, y1 + length / 2, length / 2);

            return root;
        }
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns true if all the values in the matrix are the same; otherwise, false.
    boolean sameValue(int[][] grid, int x1, int y1, int length) {
        for (int i = x1; i < x1 + length; i++) {
            for (int j = y1; j < y1 + length; j++)
                if (grid[i][j] != grid[x1][y1])
                    return false;
        }
        return true;
    }

    Node solve(int[][] grid, int x1, int y1, int length) {
        // Return a leaf node if all values are the same.
        if (sameValue(grid, x1, y1, length)) {
            return new Node(grid[x1][y1] == 1, true);
        } else {
            Node root = new Node(false, false);

            // Recursive call for the four sub-matrices.
            root.topLeft = solve(grid, x1, y1, length / 2);
            root.topRight = solve(grid, x1, y1 + length / 2, length / 2);
            root.bottomLeft = solve(grid, x1 + length / 2, y1, length / 2);
            root.bottomRight = solve(grid, x1 + length / 2, y1 + length / 2, length / 2);

            return root;
        }
    }

    public Node construct(int[][] grid) {
        return solve(grid, 0, 0, grid.length);
    }
}
```

</details>

<br>

## Approach 2: Optimized Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    Node* solve(vector<vector<int>>& grid, int x1, int y1, int length) {
        // Return a leaf node if the matrix size is one.
        if (length == 1) {
            return new Node(grid[x1][y1], true);
        }
        
        // Recursive calls to the four sub-matrices.
        Node* topLeft = solve(grid, x1, y1, length / 2);
        Node* topRight = solve(grid, x1, y1 + length / 2, length / 2);
        Node* bottomLeft = solve(grid, x1 + length / 2, y1, length / 2);
        Node* bottomRight = solve(grid, x1 + length / 2, y1 + length / 2, length / 2);
            
        // If the four returned nodes are leaf and have the same values
        // Return a leaf node with the same value.
        if (topLeft -> isLeaf && topRight -> isLeaf && bottomLeft -> isLeaf && bottomRight -> isLeaf
           && topLeft -> val == topRight -> val && topRight -> val == bottomLeft -> val 
           && bottomLeft -> val == bottomRight -> val) {
            return new Node(topLeft -> val, true);
        }
        
        // If the four nodes aren't identical, return non-leaf node with corresponding child pointers.
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Node solve(int[][] grid, int x1, int y1, int length) {
        // Return a leaf node if the matrix size is one.
        if (length == 1) {
            return new Node(grid[x1][y1] == 1, true);
        }

        // Recursive calls to the four sub-matrices.
        Node topLeft = solve(grid, x1, y1, length / 2);
        Node topRight = solve(grid, x1, y1 + length / 2, length / 2);
        Node bottomLeft = solve(grid, x1 + length / 2, y1, length / 2);
        Node bottomRight = solve(grid, x1 + length / 2, y1 + length / 2, length / 2);

        // If the four returned nodes are leaf and have the same values
        // Return a leaf node with the same value.
        if (topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf
                && topLeft.val == topRight.val && topRight.val == bottomLeft.val
                && bottomLeft.val == bottomRight.val) {
            return new Node(topLeft.val, true);
        }

        // If the four nodes aren't identical, return a non-leaf node with corresponding child pointers.
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    public Node construct(int[][] grid) {
        return solve(grid, 0, 0, grid.length);
    }
}
```

</details>
