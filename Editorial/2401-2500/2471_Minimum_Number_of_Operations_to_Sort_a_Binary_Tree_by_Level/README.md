# 2471. Minimum Number of Operations to Sort a Binary Tree by Level

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/)  
`Tree` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 2471 - Minimum Number of Operations to Sort a Binary Tree by Level](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/)

## Problem

You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.

### Example 1

```text
Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
```

### Example 2

```text
Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
```

### Example 3

```text
Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.
```

## Constraints

- The number of nodes in the tree is in the range [1, 105].
- 1 <= Node.val <= 105
- All the values of the tree are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Cycle in a Graph](https://leetcode.com/problems/longest-cycle-in-a-graph/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2471. Minimum Number of Operations to Sort a Binary Tree by Level

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Map | C++, Java, Python3 |
| Bit Manipulation | C++, Java, Python3 |

## Approach 1: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int totalSwaps = 0;

        // Process tree level by level using BFS
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> levelValues(levelSize);

            // Store values of current level and add children to queue
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                levelValues[i] = node->val;

                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }

            // Add minimum swaps needed for current level
            totalSwaps += getMinSwaps(levelValues);
        }
        return totalSwaps;
    }

private:
    // Calculate minimum swaps needed to sort an array
    int getMinSwaps(vector<int>& original) {
        int swaps = 0;
        vector<int> target = original;
        sort(target.begin(), target.end());

        // Map to track current positions of values
        unordered_map<int, int> pos;
        for (int i = 0; i < original.size(); i++) {
            pos[original[i]] = i;
        }

        // For each position, swap until correct value is placed
        for (int i = 0; i < original.size(); i++) {
            if (original[i] != target[i]) {
                swaps++;

                // Update position of swapped values
                int curPos = pos[target[i]];
                pos[original[i]] = curPos;
                swap(original[curPos], original[i]);
            }
        }
        return swaps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int totalSwaps = 0;

        // Process tree level by level using BFS
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            int[] levelValues = new int[levelSize];

            // Store values of current level and add children to queue
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                levelValues[i] = node.val;

                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }

            // Add minimum swaps needed for current level
            totalSwaps += getMinSwaps(levelValues);
        }
        return totalSwaps;
    }

    // Calculate minimum swaps needed to sort an array
    private int getMinSwaps(int[] original) {
        int swaps = 0;
        int[] target = original.clone();
        Arrays.sort(target);

        // Map to track current positions of values
        Map<Integer, Integer> pos = new HashMap<>();
        for (int i = 0; i < original.length; i++) {
            pos.put(original[i], i);
        }

        // For each position, swap until correct value is placed
        for (int i = 0; i < original.length; i++) {
            if (original[i] != target[i]) {
                swaps++;

                // Update position of swapped values
                int curPos = pos.get(target[i]);
                pos.put(original[i], curPos);
                original[curPos] = original[i];
            }
        }
        return swaps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumOperations(self, root: Optional["TreeNode"]) -> int:
        queue = deque([root])
        total_swaps = 0

        # Process tree level by level using BFS
        while queue:
            level_size = len(queue)
            level_values = []

            # Store level values and add children to queue
            for _ in range(level_size):
                node = queue.popleft()
                level_values.append(node.val)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            # Add minimum swaps needed for current level
            total_swaps += self._get_min_swaps(level_values)

        return total_swaps

    # Calculate minimum swaps needed to sort an array
    def _get_min_swaps(self, original: list) -> int:
        swaps = 0
        target = sorted(original)

        # Map to track current positions of values
        pos = {val: idx for idx, val in enumerate(original)}

        # For each position, swap until correct value is placed
        for i in range(len(original)):
            if original[i] != target[i]:
                swaps += 1

                # Update position of swapped values
                cur_pos = pos[target[i]]
                pos[original[i]] = cur_pos
                original[cur_pos] = original[i]

        return swaps
```

</details>

<br>

## Approach 2: Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Constants for bit manipulation
    const int SHIFT = 20;
    const int MASK = 0xFFFFF;

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int swaps = 0;

        // Process tree level by level using BFS
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<long long> nodes(levelSize);

            // Store node values with encoded positions
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                // Encode value and index: high 20 bits = value, low 20 bits =
                // index
                nodes[i] = (static_cast<long long>(node->val) << SHIFT) + i;

                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }

            // Sort nodes by their values (high 20 bits)
            sort(nodes.begin(), nodes.end());

            // Count swaps needed to match indices with original positions
            for (int i = 0; i < levelSize; i++) {
                int origPos = static_cast<int>(nodes[i] & MASK);
                if (origPos != i) {
                    // Swap nodes and decrement i to recheck current position
                    swap(nodes[i], nodes[origPos]);
                    swaps++;
                    i--;
                }
            }
        }
        return swaps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Constants for bit manipulation
    final int SHIFT = 20;
    final int MASK = 0xFFFFF;

    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList();
        queue.add(root);
        int swaps = 0;

        // Process tree level by level using BFS
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            long[] nodes = new long[levelSize];

            // Store node values with encoded positions
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                // Encode value and index: high 20 bits = value, low 20 bits = index
                nodes[i] = ((long) node.val << SHIFT) + i;

                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }

            // Sort nodes by their values (high 20 bits)
            Arrays.sort(nodes);

            // Count swaps needed to match indices with original positions
            for (int i = 0; i < levelSize; i++) {
                int origPos = (int) (nodes[i] & MASK);
                if (origPos != i) {
                    // Swap nodes and decrement i to recheck current position
                    long temp = nodes[i];
                    nodes[i--] = nodes[origPos];
                    nodes[origPos] = temp;
                    swaps++;
                }
            }
        }
        return swaps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Constants for bit manipulation
    _SHIFT = 20
    _MASK = 0xFFFFF

    def minimumOperations(self, root: Optional["TreeNode"]) -> int:
        queue = deque([root])
        swaps = 0

        # Process tree level by level using BFS
        while queue:
            level_size = len(queue)
            nodes = []

            # Store node values with encoded positions
            for i in range(level_size):
                node = queue.popleft()
                # Encode value and index: high 20 bits = value, low 20 bits = index
                nodes.append((node.val << self._SHIFT) + i)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            # Sort nodes by their values (high 20 bits)
            nodes.sort()

            # Count swaps needed to match indices with original positions
            i = 0
            while i < level_size:
                orig_pos = nodes[i] & self._MASK
                if orig_pos != i:
                    # Swap nodes and decrement i to recheck current position
                    nodes[i], nodes[orig_pos] = nodes[orig_pos], nodes[i]
                    swaps += 1
                    i -= 1
                i += 1

        return swaps
```

</details>
