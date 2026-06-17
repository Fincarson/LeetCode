# 1011. Capacity To Ship Packages Within D Days

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 1011 - Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

## Problem

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

### Example 1

```text
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
```

### Example 2

```text
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
```

### Example 3

```text
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
```

## Constraints

- 1 <= days <= weights.length <= 5 * 104
- 1 <= weights[i] <= 500

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Divide Chocolate](https://leetcode.com/problems/divide-chocolate/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Cutting Ribbons](https://leetcode.com/problems/cutting-ribbons/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Bags With Full Capacity of Rocks](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Total Distance Traveled](https://leetcode.com/problems/minimum-total-distance-traveled/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1011. Capacity To Ship Packages Within D Days

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search | C++, Java |

## Approach: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Check whether the packages can be shipped in less than "days" days with
    // "c" capacity.
    bool feasible(vector<int>& weights, int c, int days) {
        int daysNeeded = 1, currentLoad = 0;
        for (int weight : weights) {
            currentLoad += weight;
            if (currentLoad > c) {
                daysNeeded++;
                currentLoad = weight;
            }
        }

        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int totalLoad = 0, maxLoad = 0;
        for (int weight : weights) {
            totalLoad += weight;
            maxLoad = max(maxLoad, weight);
        }

        int l = maxLoad, r = totalLoad;

        while (l < r) {
            int mid = (l + r) / 2;
            if (feasible(weights, mid, days)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Check whether the packages can be shipped in less than "days" days with
    // "c" capacity.
    Boolean feasible(int[] weights, int c, int days) {
        int daysNeeded = 1, currentLoad = 0;
        for (int weight : weights) {
            currentLoad += weight;
            if (currentLoad > c) {
                daysNeeded++;
                currentLoad = weight;
            }
        }

        return daysNeeded <= days;
    }

    public int shipWithinDays(int[] weights, int days) {
        int totalLoad = 0, maxLoad = 0;
        for (int weight : weights) {
            totalLoad += weight;
            maxLoad = Math.max(maxLoad, weight);
        }

        int l = maxLoad, r = totalLoad;

        while (l < r) {
            int mid = (l + r) / 2;
            if (feasible(weights, mid, days)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

</details>
