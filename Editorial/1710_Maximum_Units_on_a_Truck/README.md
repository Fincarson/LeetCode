# 1710. Maximum Units on a Truck

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/maximum-units-on-a-truck/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1710 - Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/)

## Problem

You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

- numberOfBoxesi is the number of boxes of type i.
- numberOfUnitsPerBoxi is the number of units in each box of the type i.

You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

### Example 1

```text
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
```

### Example 2

```text
Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
```

## Constraints

- 1 <= boxTypes.length <= 1000
- 1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
- 1 <= truckSize <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Bags With Full Capacity of Rocks](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1710. Maximum Units on a Truck

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int unitCount = 0;
        int remainingTruckSize = truckSize;
        while (remainingTruckSize > 0) {
            int maxUnitBoxIndex = findMaxUnitBox(boxTypes);
            // check if all boxes are used
            if (maxUnitBoxIndex == -1) break;
            // find the box count that can be put in truck
            int boxCount =
                min(remainingTruckSize, boxTypes[maxUnitBoxIndex][0]);
            unitCount += boxCount * boxTypes[maxUnitBoxIndex][1];
            remainingTruckSize -= boxCount;
            // mark box with index maxUnitBoxIndex as used
            boxTypes[maxUnitBoxIndex][1] = -1;
        }
        return unitCount;
    }

    int findMaxUnitBox(vector<vector<int>>& boxTypes) {
        int maxUnitBoxIndex = -1;
        int maxUnits = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            if (boxTypes[i][1] > maxUnits) {
                maxUnits = boxTypes[i][1];
                maxUnitBoxIndex = i;
            }
        }
        return maxUnitBoxIndex;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumUnits(int[][] boxTypes, int truckSize) {
        int unitCount = 0;
        int remainingTruckSize = truckSize;
        while (remainingTruckSize > 0) {
            int maxUnitBoxIndex = findMaxUnitBox(boxTypes);
            // check if all boxes are used
            if (maxUnitBoxIndex == -1) break;
            // find the box count that can be put in truck
            int boxCount = Math.min(
                remainingTruckSize,
                boxTypes[maxUnitBoxIndex][0]
            );
            unitCount += boxCount * boxTypes[maxUnitBoxIndex][1];
            remainingTruckSize -= boxCount;
            // mark box with index maxUnitBoxIndex as used
            boxTypes[maxUnitBoxIndex][1] = -1;
        }
        return unitCount;
    }

    public int findMaxUnitBox(int[][] boxTypes) {
        int maxUnitBoxIndex = -1;
        int maxUnits = 0;
        for (int i = 0; i < boxTypes.length; i++) {
            if (boxTypes[i][1] > maxUnits) {
                maxUnits = boxTypes[i][1];
                maxUnitBoxIndex = i;
            }
        }
        return maxUnitBoxIndex;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumUnits(self, boxTypes, truckSize):
        unitCount = 0
        remainingTruckSize = truckSize
        while remainingTruckSize > 0:
            maxUnitBoxIndex = self.findMaxUnitBox(boxTypes)
            if maxUnitBoxIndex == -1:  # all boxes are used
                break
            boxCount = min(remainingTruckSize, boxTypes[maxUnitBoxIndex][0])
            unitCount += boxCount * boxTypes[maxUnitBoxIndex][1]
            remainingTruckSize -= boxCount
            boxTypes[maxUnitBoxIndex][1] = -1  # mark box as used
        return unitCount

    def findMaxUnitBox(self, boxTypes):
        maxUnitBoxIndex = -1
        maxUnits = 0
        for i in range(len(boxTypes)):
            if boxTypes[i][1] > maxUnits:
                maxUnits = boxTypes[i][1]
                maxUnitBoxIndex = i
        return maxUnitBoxIndex
```

</details>
