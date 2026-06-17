# 666. Path Sum IV

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/path-sum-iv/)  
`Array` `Hash Table` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 666 - Path Sum IV](https://leetcode.com/problems/path-sum-iv/)

## Problem

If the depth of a tree is smaller than 5, then this tree can be represented by an array of three-digit integers. You are given an ascending array nums consisting of three-digit integers representing a binary tree with a depth smaller than 5, where for each integer:

- The hundreds digit represents the depth d of this node, where 1 <= d <= 4.
- The tens digit represents the position p of this node within its level, where 1 <= p <= 8, corresponding to its position in a full binary tree.
- The units digit represents the value v of this node, where 0 <= v <= 9.

Return the sum of all paths from the root towards the leaves.

It is guaranteed that the given array represents a valid connected binary tree.

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 15
- 110 <= nums[i] <= 489
- nums represents a valid binary tree with depth less than 5.
- nums is sorted in ascending order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Path Sum](https://leetcode.com/problems/path-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Path Sum II](https://leetcode.com/problems/path-sum-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Path Sum III](https://leetcode.com/problems/path-sum-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 666. Path Sum IV

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java, Python3 |
| Breadth First Search | C++, Java, Python3 |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int pathSum(vector<int>& nums) {
        // Store the data in a hashmap, with the coordinates as the key and the
        // node value as the value
        unordered_map<int, int> map;
        for (int element : nums) {
            int coordinates = element / 10;
            int value = element % 10;
            map[coordinates] = value;
        }

        // Initialize sum with 0 and pass it by reference in the sum function.
        int sum = 0;
        dfs(nums[0] / 10, 0, sum, map);

        return sum;
    }

    void dfs(int rootCoordinates, int preSum, int& sum,
             unordered_map<int, int>& map) {
        // Find the level and position values from the coordinates.
        int level = rootCoordinates / 10;
        int position = rootCoordinates % 10;

        // Find out the left child and right child positions of the tree.
        int left = (level + 1) * 10 + position * 2 - 1;
        int right = (level + 1) * 10 + position * 2;
        int currSum = preSum + map[rootCoordinates];

        // If left child and right child does not exist, return.
        if (!map.count(left) and !map.count(right)) {
            sum += currSum;
            return;
        }
        // Otherwise iterate through the left and right children recursively
        // using depth first search.
        if (map.count(left)) {
            dfs(left, currSum, sum, map);
        }
        if (map.count(right)) {
            dfs(right, currSum, sum, map);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    Map<Integer, Integer> map = new HashMap<>();

    public int pathSum(int[] nums) {
        // Store the data in a hashmap, with the coordinates as the key and the
        // node value as the value
        for (int num : nums) {
            int key = num / 10;
            int value = num % 10;
            map.put(key, value);
        }

        return dfs(nums[0] / 10, 0);
    }

    private int dfs(int root, int preSum) {
        // Find the level and position values from the coordinates
        int level = root / 10;
        int pos = root % 10;

        //the left child and right child position in the tree
        int left = (level + 1) * 10 + pos * 2 - 1;
        int right = (level + 1) * 10 + pos * 2;
        int currSum = preSum + map.get(root);

        // If the node is a leaf node, return its root to leaf path sum.
        if (!map.containsKey(left) && !map.containsKey(right)) {
            return currSum;
        }

        // Otherwise iterate through the left and right children recursively
        // using depth first search
        int leftSum = map.containsKey(left) ? dfs(left, currSum) : 0;
        int rightSum = map.containsKey(right) ? dfs(right, currSum) : 0;

        //return the total path sum of the tree rooted at the current node
        return leftSum + rightSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pathSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Store the data in a hashmap, with the coordinates as the key and the node value as the value
        coord_map = {}
        for element in nums:
            coordinates = element // 10
            value = element % 10
            coord_map[coordinates] = value

        # Pass the initial sum value in the sum function.
        return self.dfs(nums[0] // 10, 0, coord_map)

    def dfs(self, root_coordinates, pre_sum, coord_map):
        # Find the level and position values from the coordinates.
        level = root_coordinates // 10
        position = root_coordinates % 10

        # Find out the left child and right child positions of the tree.
        left = (level + 1) * 10 + position * 2 - 1
        right = (level + 1) * 10 + position * 2
        curr_sum = pre_sum + coord_map[root_coordinates]

        # If left child and right child do not exist, return.
        if not left in coord_map and not right in coord_map:
            return curr_sum

        # Otherwise iterate through the left and right children recursively using depth first search.
        left_sum = (
            self.dfs(left, curr_sum, coord_map) if left in coord_map else 0
        )
        right_sum = (
            self.dfs(right, curr_sum, coord_map) if right in coord_map else 0
        )
        return left_sum + right_sum
```

</details>

<br>

## Approach 2: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int pathSum(vector<int>& nums) {
        // Store the node values in a hashmap, using coordinates as the key.
        unordered_map<int, int> map;
        for (int element : nums) {
            int coordinates = element / 10;
            int value = element % 10;
            map[coordinates] = value;
        }

        // Initialize the BFS queue and start with the root node.
        queue<pair<int, int>> q;
        int totalSum = 0;

        int rootCoordinates = nums[0] / 10;
        q.push({rootCoordinates, map[rootCoordinates]});

        while (!q.empty()) {
            auto [coordinates, currentSum] = q.front();
            q.pop();

            int level = coordinates / 10;
            int position = coordinates % 10;

            // Find the left and right child coordinates.
            int left = (level + 1) * 10 + position * 2 - 1;
            int right = (level + 1) * 10 + position * 2;

            // If it's a leaf node (no left and right children), add currentSum
            // to totalSum.
            if (!map.count(left) && !map.count(right)) {
                totalSum += currentSum;
            }

            // Add the left child to the queue if it exists.
            if (map.count(left)) {
                q.push({left, currentSum + map[left]});
            }

            // Add the right child to the queue if it exists.
            if (map.count(right)) {
                q.push({right, currentSum + map[right]});
            }
        }

        return totalSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int pathSum(int[] nums) {
        // Store the node values in a hashmap, using coordinates as the key.
        Map<Integer, Integer> map = new HashMap<>();
        for (int element : nums) {
            int coordinates = element / 10;
            int value = element % 10;
            map.put(coordinates, value);
        }

        // Initialize the BFS queue and start with the root node.
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        int totalSum = 0;

        int rootCoordinates = nums[0] / 10;
        q.add(
            new Pair<Integer, Integer>(
                rootCoordinates,
                map.get(rootCoordinates)
            )
        );

        while (!q.isEmpty()) {
            Pair<Integer, Integer> current = q.poll();
            int coordinates = current.getKey();
            int currentSum = current.getValue();
            int level = coordinates / 10;
            int position = coordinates % 10;

            // Find the left and right child coordinates.
            int left = (level + 1) * 10 + position * 2 - 1;
            int right = (level + 1) * 10 + position * 2;

            // If it's a leaf node (no left and right children), add currentSum to totalSum.
            if (!map.containsKey(left) && !map.containsKey(right)) {
                totalSum += currentSum;
            }

            // Add the left child to the queue if it exists.
            if (map.containsKey(left)) {
                q.add(
                    new Pair<Integer, Integer>(left, currentSum + map.get(left))
                );
            }

            // Add the right child to the queue if it exists.
            if (map.containsKey(right)) {
                q.add(
                    new Pair<Integer, Integer>(
                        right,
                        currentSum + map.get(right)
                    )
                );
            }
        }

        return totalSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pathSum(self, nums: List[int]) -> int:
        map = (
            {}
        )  # Store the node values in a hashmap, using coordinates as the key.

        # Iterate over given nums
        for element in nums:
            coordinates = element // 10
            value = element % 10
            map[coordinates] = value

        total_sum = 0  # Initialize the total sum
        q = [
            (nums[0] // 10, map[nums[0] // 10])
        ]  # Initialize the BFS queue and start with the root node.

        # Continue till queue is not empty
        while q:
            coordinates, current_sum = q.pop(0)  # Dequeue
            level = coordinates // 10
            position = coordinates % 10

            left = (level + 1) * 10 + position * 2 - 1
            right = (level + 1) * 10 + position * 2

            # If it's a leaf node (no left and right children), add currentSum to totalSum.
            if not (left in map or right in map):
                total_sum += current_sum

            # Add the left child to the queue if it exists.
            if left in map:
                q.append((left, current_sum + map[left]))

            # Add the right child to the queue if it exists.
            if right in map:
                q.append((right, current_sum + map[right]))

        return total_sum
```

</details>
