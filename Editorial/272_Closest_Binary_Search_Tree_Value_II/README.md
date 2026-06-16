# 272. Closest Binary Search Tree Value II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/closest-binary-search-tree-value-ii/)  
`Two Pointers` `Stack` `Tree` `Depth-First Search` `Binary Search Tree` `Heap (Priority Queue)` `Binary Tree`

**Problem Link:** [LeetCode 272 - Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii/)

## Problem

Given the root of a binary search tree, a target value, and an integer k, return the k values in the BST that are closest to the target. You may return the answer in any order.

You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

### Example 1

```text
Input: root = [4,2,5,1,3], target = 3.714286, k = 2
Output: [4,3]
```

### Example 2

```text
Input: root = [1], target = 0.000000, k = 1
Output: [1]
```

## Constraints

- The number of nodes in the tree is n.
- 1 <= k <= n <= 104.
- 0 <= Node.val <= 109
- -109 <= target <= 109

Follow up: Assume that the BST is balanced. Could you solve it in less than O(n) runtime (where n = total nodes)?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Closest Nodes Queries in a Binary Search Tree](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 272. Closest Binary Search Tree Value II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort With Custom Comparator | Java, Python3 |
| Traverse With Heap | Java, Python3 |
| Inorder Traversal + Sliding Window | Java, Python3 |
| Binary Search The Left Bound | Java, Python3 |
| Build The Window With Deque | Java, Python3 |

## Approach 1: Sort With Custom Comparator

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> arr = new ArrayList<>();
        dfs(root, arr);
        
        Collections.sort(arr, (o1, o2) -> Math.abs(o1 - target) <= Math.abs(o2 - target) ? -1 : 1);
        
        return arr.subList(0, k);
        
    }
    
    public void dfs(TreeNode node, List<Integer> arr) {
        if (node == null) {
            return;
        }
        
        arr.add(node.val);
        dfs(node.left, arr);
        dfs(node.right, arr);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def dfs(node, arr):
            if not node:
                return
            
            arr.append(node.val)
            dfs(node.left, arr)
            dfs(node.right, arr)
        
        arr = []
        dfs(root, arr)
        
        arr.sort(key = lambda x: (abs(x - target), x))
        return arr[:k]
```

</details>

<br>

## Approach 2: Traverse With Heap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        Queue<Integer> heap = new PriorityQueue<>((a, b) -> Math.abs(a - target) > Math.abs(b - target) ? -1: 1);
        dfs(root, heap, k);
        
        return new ArrayList<>(heap);
    }
    
    public void dfs(TreeNode node, Queue<Integer> heap, int k) {
        if (node == null) {
            return;
        }
        
        heap.add(node.val);
        if (heap.size() > k) {
            heap.remove();
        }
        
        dfs(node.left, heap, k);
        dfs(node.right, heap, k);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def dfs(node, heap):
            if not node:
                return

            if len(heap) < k:
                heappush(heap, (-abs(node.val - target), node.val))
            else:
                if abs(node.val - target) <= abs(heap[0][0]):
                    heappop(heap)
                    heappush(heap, (-abs(node.val - target), node.val))

            dfs(node.left, heap)
            dfs(node.right, heap)

        heap = []
        dfs(root, heap)
        return [x[1] for x in heap]
```

</details>

<br>

## Approach 3: Inorder Traversal + Sliding Window

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> arr = new ArrayList<>();
        dfs(root, arr);
        
        int start = 0;
        double minDiff = Double.MAX_VALUE;
        
        for (int i = 0; i < arr.size(); i++) {
            if (Math.abs(arr.get(i) - target) < minDiff) {
                minDiff = Math.abs(arr.get(i) - target);
                start = i;
            }
        }
        
        int left = start;
        int right = start + 1;
        
        while (right - left - 1 < k) {
            // Be careful to not go out of bounds
            if (left < 0) {
                right += 1;
                continue;
            }

            if (right == arr.size() || Math.abs(arr.get(left) - target) <= Math.abs(arr.get(right) - target)) {
                left -= 1;
            } else {
                right += 1;
            }
        }
        
        return arr.subList(left + 1, right);
    }
    
    public void dfs(TreeNode node, List<Integer> arr) {
        if (node == null) {
            return;
        }
        
        dfs(node.left, arr);
        arr.add(node.val);
        dfs(node.right, arr);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def dfs(node, arr):
            if not node:
                return
            
            dfs(node.left, arr)
            arr.append(node.val)
            dfs(node.right, arr)
        
        arr = []
        dfs(root, arr)
        
        left = bisect_left(arr, target) - 1
        right = left + 1
        ans = []
        
        while len(ans) < k:
            if right == len(arr) or abs(arr[left] - target) <= abs(arr[right] - target):
                ans.append(arr[left])
                left -= 1
            else:
                ans.append(arr[right])
                right += 1
        
        return ans
```

</details>

<br>

## Approach 4: Binary Search The Left Bound

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> arr = new ArrayList<>();
        dfs(root, arr);
        
        int left = 0;
        int right = arr.size() - k;
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (Math.abs(target - arr.get(mid + k)) < Math.abs(target - arr.get(mid))) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return arr.subList(left, left + k);
    }
    
    public void dfs(TreeNode node, List<Integer> arr) {
        if (node == null) {
            return;
        }
        
        dfs(node.left, arr);
        arr.add(node.val);
        dfs(node.right, arr);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def dfs(node, arr):
            if not node:
                return
            
            dfs(node.left, arr)
            arr.append(node.val)
            dfs(node.right, arr)
        
        arr = []
        dfs(root, arr)
        
        left = 0
        right = len(arr) - k
        
        while left < right:
            mid = (left + right) // 2
            if abs(target - arr[mid + k]) < abs(target - arr[mid]):
                left = mid + 1
            else:
                right = mid

        return arr[left:left + k]
```

</details>

<br>

## Approach 5: Build The Window With Deque

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        Deque<Integer> queue = new LinkedList<>();
        dfs(root, queue, k, target);
        return new ArrayList<>(queue);
    }
    
    public void dfs(TreeNode node, Deque<Integer> queue, int k, double target) {
        if (node == null) {
            return;
        }
        
        dfs(node.left, queue, k, target);
        queue.add(node.val);
        if (queue.size() > k) {
            if (Math.abs(target - queue.peekFirst()) <= Math.abs(target - queue.peekLast())) {
                queue.removeLast();
                return;
            } else {
                queue.removeFirst();
            }
        }

        dfs(node.right, queue, k, target);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def dfs(node, queue):
            if not node:
                return
            
            dfs(node.left, queue)
            queue.append(node.val)
            if len(queue) > k:
                if (abs(target - queue[0]) <= abs(target - queue[-1])):
                    queue.pop()
                    return
                else:
                    queue.popleft()
                    
            dfs(node.right, queue)
        
        queue = deque()
        dfs(root, queue)
        return list(queue)
```

</details>
