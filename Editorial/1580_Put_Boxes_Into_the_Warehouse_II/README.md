# 1580. Put Boxes Into the Warehouse II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1580 - Put Boxes Into the Warehouse II](https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/)

## Problem

You are given two arrays of positive integers, boxes and warehouse, representing the heights of some boxes of unit width and the heights of n rooms in a warehouse respectively. The warehouse's rooms are labeled from 0 to n - 1 from left to right where warehouse[i] (0-indexed) is the height of the ith room.

Boxes are put into the warehouse by the following rules:

- Boxes cannot be stacked.
- You can rearrange the insertion order of the boxes.
- Boxes can be pushed into the warehouse from either side (left or right)
- If the height of some room in the warehouse is less than the height of a box, then that box and all other boxes behind it will be stopped before that room.

Return the maximum number of boxes you can put into the warehouse.

### Example 1

```text
Input: boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
Output: 4
Explanation:

We can store the boxes in the following order:
1- Put the yellow box in room 2 from either the left or right side.
2- Put the orange box in room 3 from the right side.
3- Put the green box in room 1 from the left side.
4- Put the red box in room 0 from the left side.
Notice that there are other valid ways to put 4 boxes such as swapping the red and green boxes or the red and orange boxes.
```

### Example 2

```text
Input: boxes = [3,5,5,2], warehouse = [2,1,3,4,5]
Output: 3
Explanation:

It is not possible to put the two boxes of height 5 in the warehouse since there's only 1 room of height >= 5.
Other valid solutions are to put the green box in room 2 or to put the orange box first in room 2 before putting the green and red boxes.
```

## Constraints

- n == warehouse.length
- 1 <= boxes.length, warehouse.length <= 105
- 1 <= boxes[i], warehouse[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Put Boxes Into the Warehouse I](https://leetcode.com/problems/put-boxes-into-the-warehouse-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1580. Put Boxes Into the Warehouse II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Add Smallest Boxes to the Rightmost Warehouse Rooms from Both Ends | C++, Java, Python3 |
| Add Largest Possible Boxes from Both Ends | C++, Java, Python3 |

## Approach 1: Add Smallest Boxes to the Rightmost Warehouse Rooms from Both Ends

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        int minHeight = INT_MAX;
        vector<int> effectiveHeights(n);

        // Preprocess the height of the warehouse rooms to
        // get usable heights from the left end
        for (int i = 0; i < n; ++i) {
            minHeight = min(minHeight, warehouse[i]);
            effectiveHeights[i] = minHeight;
        }

        minHeight = INT_MAX;
        // Update the effective heights considering the right end
        for (int i = n - 1; i >= 0; --i) {
            minHeight = min(minHeight, warehouse[i]);
            effectiveHeights[i] = max(effectiveHeights[i], minHeight);
        }

        // Sort the effective heights of the warehouse rooms
        sort(effectiveHeights.begin(), effectiveHeights.end());

        // Sort the boxes by height
        sort(boxes.begin(), boxes.end());

        int count = 0;
        int boxIndex = 0;
        // Try to place each box in the warehouse
        // from the smallest room to the largest
        for (int i = 0; i < n; ++i) {
            if (boxIndex < boxes.size() &&
                boxes[boxIndex] <= effectiveHeights[i]) {
                // Place the box and move to the next one
                ++count;
                ++boxIndex;
            }
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
        int n = warehouse.length;
        int minHeight = Integer.MAX_VALUE;
        int[] effectiveHeights = new int[n];

        // Preprocess the height of the warehouse rooms to
        // get usable heights from the left end
        for (int i = 0; i < n; ++i) {
            minHeight = Math.min(minHeight, warehouse[i]);
            effectiveHeights[i] = minHeight;
        }

        minHeight = Integer.MAX_VALUE;
        // Update the effective heights considering the right end
        for (int i = n - 1; i >= 0; --i) {
            minHeight = Math.min(minHeight, warehouse[i]);
            effectiveHeights[i] = Math.max(effectiveHeights[i], minHeight);
        }

        // Sort the effective heights of the warehouse rooms
        Arrays.sort(effectiveHeights);
        // Sort the boxes by height
        Arrays.sort(boxes);

        int count = 0;
        int boxIndex = 0;
        // Try to place each box in the warehouse from
        // the smallest room to the largest
        for (int i = 0; i < n; ++i) {
            if (
                boxIndex < boxes.length &&
                boxes[boxIndex] <= effectiveHeights[i]
            ) {
                // Place the box and move to the next one
                ++count;
                ++boxIndex;
            }
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxBoxesInWarehouse(
        self, boxes: List[int], warehouse: List[int]
    ) -> int:
        n = len(warehouse)
        minHeight = float("inf")
        effectiveHeights = [0] * n

        # Preprocess the height of the warehouse rooms to
        # get usable heights from the left end

        for i in range(n):
            minHeight = min(minHeight, warehouse[i])
            effectiveHeights[i] = minHeight
        minHeight = float("inf")
        # Update the effective heights considering the right end

        for i in range(n - 1, -1, -1):
            minHeight = min(minHeight, warehouse[i])
            effectiveHeights[i] = max(effectiveHeights[i], minHeight)
        # Sort the effective heights of the warehouse rooms

        effectiveHeights.sort()

        # Sort the boxes by height

        boxes.sort()

        count = 0
        boxIndex = 0
        # Try to place each box in the warehouse from
        # the smallest room to the largest

        for i in range(n):
            if boxIndex < len(boxes) and boxes[boxIndex] <= effectiveHeights[i]:
                # Place the box and move to the next one

                count += 1
                boxIndex += 1
        return count
```

</details>

<br>

## Approach 2: Add Largest Possible Boxes from Both Ends

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int warehouseSize = warehouse.size();

        // Sort the boxes by height
        sort(boxes.begin(), boxes.end());

        int leftIndex = 0;
        int rightIndex = warehouseSize - 1;
        int boxCount = 0;
        int boxIndex = boxes.size() - 1;

        // Iterate through the boxes from largest to smallest
        while (leftIndex <= rightIndex && boxIndex >= 0) {
            // Check if the current box can fit in the
            // leftmost available room
            if (boxes[boxIndex] <= warehouse[leftIndex]) {
                boxCount++;
                leftIndex++;
                // Check if the current box can fit in the
                // rightmost available room
            } else if (boxes[boxIndex] <= warehouse[rightIndex]) {
                boxCount++;
                rightIndex--;
            }
            boxIndex--;
        }

        return boxCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
        int warehouseSize = warehouse.length;

        // Sort the boxes by height
        Arrays.sort(boxes);

        int leftIndex = 0;
        int rightIndex = warehouseSize - 1;
        int boxCount = 0;
        int boxIndex = boxes.length - 1;

        // Iterate through the boxes from largest to smallest
        while (leftIndex <= rightIndex && boxIndex >= 0) {
            // Check if the current box can fit in the leftmost available room
            if (boxes[boxIndex] <= warehouse[leftIndex]) {
                boxCount++;
                leftIndex++;
                // Check if the current box can fit in the rightmost available room
            } else if (boxes[boxIndex] <= warehouse[rightIndex]) {
                boxCount++;
                rightIndex--;
            }
            boxIndex--;
        }

        return boxCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxBoxesInWarehouse(
        self, boxes: List[int], warehouse: List[int]
    ) -> int:
        # Sort the boxes by height

        boxes.sort()

        warehouse_size = len(warehouse)
        left_index = 0
        right_index = warehouse_size - 1
        box_count = 0
        box_index = len(boxes) - 1

        # Iterate through the boxes from largest to smallest

        while left_index <= right_index and box_index >= 0:
            # Check if the current box can fit in the
            # leftmost available room

            if boxes[box_index] <= warehouse[left_index]:
                box_count += 1
                left_index += 1
            # Check if the current box can fit in the
            # rightmost available room

            elif boxes[box_index] <= warehouse[right_index]:
                box_count += 1
                right_index -= 1
            box_index -= 1
        return box_count
```

</details>
