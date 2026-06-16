# 1564. Put Boxes Into the Warehouse I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/put-boxes-into-the-warehouse-i/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1564 - Put Boxes Into the Warehouse I](https://leetcode.com/problems/put-boxes-into-the-warehouse-i/)

## Problem

You are given two arrays of positive integers, boxes and warehouse, representing the heights of some boxes of unit width and the heights of n rooms in a warehouse respectively. The warehouse's rooms are labelled from 0 to n - 1 from left to right where warehouse[i] (0-indexed) is the height of the ith room.

Boxes are put into the warehouse by the following rules:

- Boxes cannot be stacked.
- You can rearrange the insertion order of the boxes.
- Boxes can only be pushed into the warehouse from left to right only.
- If the height of some room in the warehouse is less than the height of a box, then that box and all other boxes behind it will be stopped before that room.

Return the maximum number of boxes you can put into the warehouse.

### Example 1

```text
Input: boxes = [4,3,4,1], warehouse = [5,3,3,4,1]
Output: 3
Explanation:

We can first put the box of height 1 in room 4. Then we can put the box of height 3 in either of the 3 rooms 1, 2, or 3. Lastly, we can put one box of height 4 in room 0.
There is no way we can fit all 4 boxes in the warehouse.
```

### Example 2

```text
Input: boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
Output: 3
Explanation:

Notice that it's not possible to put the box of height 4 into the warehouse since it cannot pass the first room of height 3.
Also, for the last two rooms, 2 and 3, only boxes of height 1 can fit.
We can fit 3 boxes maximum as shown above. The yellow box can also be put in room 2 instead.
Swapping the orange and green boxes is also valid, or swapping one of them with the red box.
```

### Example 3

```text
Input: boxes = [1,2,3], warehouse = [1,2,3,4]
Output: 1
Explanation: Since the first room in the warehouse is of height 1, we can only put boxes of height 1.
```

## Constraints

- n == warehouse.length
- 1 <= boxes.length, warehouse.length <= 105
- 1 <= boxes[i], warehouse[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Put Boxes Into the Warehouse II](https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1564. Put Boxes Into the Warehouse I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Add Smallest Boxes to the Rightmost Warehouse Rooms | Java, Python3 |
| Add Largest Possible Boxes from Left to Right | Java, Python3 |

## Approach 1: Add Smallest Boxes to the Rightmost Warehouse Rooms

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
        // Preprocess the height of the warehouse rooms to get usable heights
        for (int i = 1; i < warehouse.length; i++) {
            warehouse[i] = Math.min(warehouse[i - 1], warehouse[i]);
        }

        // Iterate through boxes from smallest to largest
        Arrays.sort(boxes);

        int count = 0;

        for (int i = warehouse.length - 1; i >= 0; i--) {
            // Count the boxes that can fit in the current warehouse room
            if (count < boxes.length && boxes[count] <= warehouse[i]) {
                count++;
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
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:
        # Preprocess the height of the warehouse rooms to get usable heights
        for i in range(1, len(warehouse)):
            warehouse[i] = min(warehouse[i - 1], warehouse[i])

        # Iterate through boxes from the smallest to the largest
        boxes.sort()

        count = 0

        for room in reversed(warehouse):
            # Count the boxes that can fit in the current warehouse room
            if count < len(boxes) and boxes[count] <= room:
                count += 1

        return count
```

</details>

<br>

## Approach 2: Add Largest Possible Boxes from Left to Right

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {

        int i = boxes.length - 1;
        int count = 0;
        Arrays.sort(boxes);

        for (int room : warehouse) {
            // Iterate through boxes from largest to smallest
            // Discard boxes that doesn't fit in the current warehouse
            while (i >= 0 && boxes[i] > room) {
                i--;
            }

            if (i == -1) return count;
            count++;
            i--;
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
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:

        i = 0
        count = 0
        boxes.sort(reverse = True)

        for room in warehouse:
            # Iterate through boxes from largest to smallest
            # Discard boxes that doesn't fit in the current warehouse
            while i < len(boxes) and boxes[i] > room:
                i += 1
            if i == len(boxes):
                return count
            count += 1
            i += 1

        return count
```

</details>
