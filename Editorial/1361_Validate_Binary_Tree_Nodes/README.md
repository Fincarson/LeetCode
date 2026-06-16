# 1361. Validate Binary Tree Nodes

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/validate-binary-tree-nodes/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory` `Binary Tree`

**Problem Link:** [LeetCode 1361 - Validate Binary Tree Nodes](https://leetcode.com/problems/validate-binary-tree-nodes/)

## Problem

You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

### Example 1

```text
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
```

### Example 2

```text
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false
```

### Example 3

```text
Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false
```

## Constraints

- n == leftChild.length == rightChild.length
- 1 <= n <= 104
- -1 <= leftChild[i], rightChild[i] <= n - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1361. Validate Binary Tree Nodes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search (DFS) | C++, Java, Python3 |
| Breadth First Search (BFS) | C++, Java, Python3 |
| Union Find | C++, Java, Python3 |

## Approach 1: Depth First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int findRoot(int n, vector<int>& left, vector<int>& right) {
    unordered_set<int> children;
    children.insert(left.begin(), left.end());
    children.insert(right.begin(), right.end());
    
    for (int i = 0; i < n; i++) {
        if (children.find(i) == children.end()) {
            return i;
        }
    }
    
    return -1;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public int findRoot(int n, int[] left, int[] right) {
    Set<Integer> children = new HashSet<>();
    for (int node : left) {
        children.add(node);
    }
    
    for (int node : right) {
        children.add(node);
    }
    
    for (int i = 0; i < n; i++) {
        if (!children.contains(i)) {
            return i;
        }
    }
    
    return -1;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def find_root():
    children = set(leftChild) | set(rightChild)
    
    for i in range(n):
        if i not in children:
            return i
        
    return -1
```

</details>

<br>

## Approach 2: Breadth First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1) {
            return false;
        }
        
        unordered_set<int> seen;
        queue<int> queue;
        seen.insert(root);
        queue.push(root);
        
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            
            int children[] = {leftChild[node], rightChild[node]};
            for (int child : children) {
                if (child != -1) {
                    if (seen.find(child) != seen.end()) {
                        return false;
                    }
                    
                    queue.push(child);
                    seen.insert(child);
                }
            }
        }
        
        return seen.size() == n;
    }
    
    int findRoot(int n, vector<int>& left, vector<int>& right) {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());
        
        for (int i = 0; i < n; i++) {
            if (children.find(i) == children.end()) {
                return i;
            }
        }
        
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1) {
            return false;
        }
        
        Set<Integer> seen = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        seen.add(root);
        queue.add(root);
        
        while (!queue.isEmpty()) {
            int node = queue.remove();
            int[] children = {leftChild[node], rightChild[node]};
            
            for (int child : children) {
                if (child != -1) {
                    if (seen.contains(child)) {
                        return false;
                    }
                    
                    queue.add(child);
                    seen.add(child);
                }
            }
            
        }
        
        return seen.size() == n;
    }
    
    public int findRoot(int n, int[] left, int[] right) {
        Set<Integer> children = new HashSet<>();
        for (int node : left) {
            children.add(node);
        }
        
        for (int node : right) {
            children.add(node);
        }
        
        for (int i = 0; i < n; i++) {
            if (!children.contains(i)) {
                return i;
            }
        }
        
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        def find_root():
            children = set(leftChild) | set(rightChild)
            
            for i in range(n):
                if i not in children:
                    return i
                
            return -1
        
        root = find_root()
        if root == -1:
            return False
        
        seen = {root}
        queue = deque([root])
        while queue:
            node = queue.popleft()
            for child in [leftChild[node], rightChild[node]]:
                if child != -1:
                    if child in seen:
                        return False
                    
                    queue.append(child)
                    seen.add(child)
        
        return len(seen) == n
```

</details>

<br>

## Approach 3: Union Find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {   
public:
    int components;
    int n;
    vector<int> parents;
    vector<int> ranks;

    UnionFind(int n) {
        this->n = n;
        parents = vector(n, 0);
        components = n;
        
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }
    
    bool join(int parent, int child) {
        int parentParent = find(parent);
        int childParent = find(child);
        
        if (childParent != child || parentParent == childParent) {
            return false;
        }
        
        components--;
        parents[childParent] = parentParent;

        return true;
    }
    
    int find(int node) {
        if (parents[node] != node) {
            parents[node] = find(parents[node]);
        }
        
        return parents[node];
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        UnionFind uf(n);
        for (int node = 0; node < n; node++) {
            int children[] = {leftChild[node], rightChild[node]};
            for (int child : children) {
                if (child == -1) {
                    continue;
                }
                
                if (!uf.join(node, child)) {
                    return false;
                }
            }
        }
        
        return uf.components == 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class UnionFind {
    private final int n;
    private final int[] parents;
    public int components;
    
    UnionFind(int n) {
        this.n = n;
        parents = new int[n];
        components = n;
        
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }
    
    public boolean union(int parent, int child) {
        int parentParent = find(parent);
        int childParent = find(child);
        
        if (childParent != child || parentParent == childParent) {
            return false;
        }
        
        components--;
        parents[childParent] = parentParent;

        return true;
    }
    
    private int find(int node) {
        if (parents[node] != node) {
            parents[node] = find(parents[node]);
        }
        
        return parents[node];
    }
}

class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        UnionFind uf = new UnionFind(n);
        for (int node = 0; node < n; node++) {
            int[] children = {leftChild[node], rightChild[node]};
            for (int child : children) {
                if (child == -1) {
                    continue;
                }
                
                if (!uf.union(node, child)) {
                    return false;
                }
            }
        }
        
        return uf.components == 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class UnionFind:
    def __init__(self, n):
        self.components = n
        self.parents = list(range(n))
        
    def union(self, parent, child):
        parent_parent = self.find(parent)
        child_parent = self.find(child)
        
        if child_parent != child or parent_parent == child_parent:
            return False
        
        self.components -= 1
        self.parents[child_parent] = parent_parent
            
        return True

    def find(self, node):
        if self.parents[node] != node:
            self.parents[node] = self.find(self.parents[node])
        
        return self.parents[node]
        

class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        uf = UnionFind(n)
        for node in range(n):
            for child in [leftChild[node], rightChild[node]]:
                if child == -1:
                    continue

                if not uf.union(node, child):
                    return False
                
        return uf.components == 1
```

</details>
