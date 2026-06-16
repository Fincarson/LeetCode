# 2583. Kth Largest Sum in a Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/)  
`Tree` `Breadth-First Search` `Sorting` `Binary Tree`

**Problem Link:** [LeetCode 2583 - Kth Largest Sum in a Binary Tree](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/)

## Problem

You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.

### Example 1

```text
Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
```

### Example 2

```text
Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.
```

## Constraints

- The number of nodes in the tree is n.
- 2 <= n <= 105
- 1 <= Node.val <= 106
- 1 <= k <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Level of Tree with Minimum Sum](https://leetcode.com/problems/find-the-level-of-tree-with-minimum-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2583. Kth Largest Sum in a Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Level Order Traversal + Max Heap | C++, Java, Python3 |
| Level Order Traversal + Min Heap | C++, Java, Python3 |

## Approach 1: Level Order Traversal + Max Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long kthLargestLevelSum(TreeNode* root, int k) {
        // max heap
        priority_queue<long> pq;

        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        while (!bfsQueue.empty()) {
            // level order traversal
            long size = bfsQueue.size();
            long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* poppedNode = bfsQueue.front();
                bfsQueue.pop();
                sum += poppedNode->val;
                if (poppedNode->left != nullptr) {
                    // add left child
                    bfsQueue.push(poppedNode->left);
                }
                if (poppedNode->right != nullptr) {
                    // add right child
                    bfsQueue.push(poppedNode->right);
                }
            }
            pq.push(sum);
        }
        if (pq.size() < k) return -1;
        for (int i = 0; i < k - 1; i++) pq.pop();
        return pq.top();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long kthLargestLevelSum(TreeNode root, int k) {
        // max heap
        PriorityQueue<Long> pq = new PriorityQueue<>(
            Collections.reverseOrder()
        );

        Queue<TreeNode> bfsQueue = new LinkedList<>();
        bfsQueue.add(root);
        while (!bfsQueue.isEmpty()) {
            //level order traversal
            int size = bfsQueue.size();
            long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode poppedNode = bfsQueue.remove();
                sum += poppedNode.val;
                if (poppedNode.left != null) {
                    //add left child
                    bfsQueue.add(poppedNode.left);
                }
                if (poppedNode.right != null) {
                    // add right child
                    bfsQueue.add(poppedNode.right);
                }
            }
            pq.add(sum);
        }
        if (pq.size() < k) return -1;
        for (int i = 0; i < k - 1; i++) pq.remove();
        return pq.peek();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthLargestLevelSum(self, root: TreeNode, k: int) -> int:
        # max heap
        pq = []
        bfs_queue = deque()
        bfs_queue.append(root)

        while bfs_queue:
            # level order traversal
            size = len(bfs_queue)
            level_sum = 0
            for _ in range(size):
                node = bfs_queue.popleft()
                level_sum += node.val
                if node.left:
                    # add left child
                    bfs_queue.append(node.left)
                if node.right:
                    # add right child
                    bfs_queue.append(node.right)

            # Make sum negative to maintain a max heap
            heapq.heappush(pq, -level_sum)

        if len(pq) < k:
            return -1

        for _ in range(k - 1):
            heapq.heappop(pq)

        # Convert sum back to positive
        return -heapq.heappop(pq)
```

</details>

<br>

## Approach 2: Level Order Traversal + Min Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long kthLargestLevelSum(TreeNode* root, int k) {
        // min heap of size k
        // at the end, top element is kth largest
        priority_queue<long, vector<long>, greater<long> > pq;

        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        while (!bfsQueue.empty()) {
            // level order traversal
            int size = bfsQueue.size();
            long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* poppedNode = bfsQueue.front();
                bfsQueue.pop();
                sum += poppedNode->val;
                if (poppedNode->left != NULL) {
                    // add left child
                    bfsQueue.push(poppedNode->left);
                }
                if (poppedNode->right != NULL) {
                    // add right child
                    bfsQueue.push(poppedNode->right);
                }
            }
            pq.push(sum);
            if (pq.size() > k) {
                // evict top element
                pq.pop();
            }
        }
        if (pq.size() < k) return -1;
        return pq.top();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long kthLargestLevelSum(TreeNode root, int k) {
        // min heap of size k
        // at the end, top element is kth largest
        PriorityQueue<Long> pq = new PriorityQueue<>();

        Queue<TreeNode> bfsQueue = new LinkedList<>();
        bfsQueue.add(root);
        while (!bfsQueue.isEmpty()) {
            //level order traversal
            int size = bfsQueue.size();
            long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode poppedNode = bfsQueue.remove();
                sum += poppedNode.val;
                if (poppedNode.left != null) {
                    //add left child
                    bfsQueue.add(poppedNode.left);
                }
                if (poppedNode.right != null) {
                    // add right child
                    bfsQueue.add(poppedNode.right);
                }
            }
            pq.add(sum);
            if (pq.size() > k) {
                // evict top element
                pq.remove();
            }
        }
        if (pq.size() < k) return -1;
        return pq.peek();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthLargestLevelSum(self, root, k):
        # min heap of size k
        # at the end, top element is kth largest
        pq = []
        bfs_queue = deque()
        bfs_queue.append(root)

        while bfs_queue:
            # level order traversal
            size = len(bfs_queue)
            sum_val = 0
            for _ in range(size):
                popped_node = bfs_queue.popleft()
                sum_val += popped_node.val
                if popped_node.left is not None:
                    # add left child
                    bfs_queue.append(popped_node.left)
                if popped_node.right is not None:
                    # add right child
                    bfs_queue.append(popped_node.right)

            heapq.heappush(pq, sum_val)
            if len(pq) > k:
                # evict top element
                heapq.heappop(pq)
        if len(pq) < k:
            return -1
        return pq[0]
```

</details>
