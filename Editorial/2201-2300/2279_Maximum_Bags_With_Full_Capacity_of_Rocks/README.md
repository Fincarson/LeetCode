# 2279. Maximum Bags With Full Capacity of Rocks

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 2279 - Maximum Bags With Full Capacity of Rocks](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/)

## Problem

You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. The ith bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.

Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.

### Example 1

```text
Input: capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
Output: 3
Explanation:
Place 1 rock in bag 0 and 1 rock in bag 1.
The number of rocks in each bag are now [2,3,4,4].
Bags 0, 1, and 2 have full capacity.
There are 3 bags at full capacity, so we return 3.
It can be shown that it is not possible to have more than 3 bags at full capacity.
Note that there may be other ways of placing the rocks that result in an answer of 3.
```

### Example 2

```text
Input: capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
Output: 3
Explanation:
Place 8 rocks in bag 0 and 2 rocks in bag 2.
The number of rocks in each bag are now [10,2,2].
Bags 0, 1, and 2 have full capacity.
There are 3 bags at full capacity, so we return 3.
It can be shown that it is not possible to have more than 3 bags at full capacity.
Note that we did not use all of the additional rocks.
```

## Constraints

- n == capacity.length == rocks.length
- 1 <= n <= 5 * 104
- 1 <= capacity[i] <= 109
- 0 <= rocks[i] <= capacity[i]
- 1 <= additionalRocks <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2279. Maximum Bags With Full Capacity of Rocks

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | C++, Java, Python3 |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = int(capacity.size()), fullBags = 0;

        
        // Sort bags by the remaining capacity.
        vector<int> remainingCapacity(n);

        for (int i = 0; i < n; ++i)
            remainingCapacity[i] = capacity[i] - rocks[i];
        sort(remainingCapacity.begin(), remainingCapacity.end());

        // Iterate over sorted bags and fill them using additional rocks.
        for (int i = 0; i < n; ++i) {
            // If we can fill the current one, fill it and move on.
            // Otherwise, stop the iteration.
            if (additionalRocks >= remainingCapacity[i]) {
                additionalRocks -= remainingCapacity[i];
                fullBags++;
            }
            else {
                break;
            }
        }
        
        // Return `fullBags` after the iteration stops.
        return fullBags;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n = capacity.length, fullBags = 0;
        
        // Sort bags by the remaining capacity.
        int[] remainingCapacity = new int[n];
        for (int i = 0; i < n; ++i)
            remainingCapacity[i] = capacity[i] - rocks[i];
        Arrays.sort(remainingCapacity);
    
        // Iterate over sorted bags and fill them using additional rocks.
        for (int i = 0; i < n; ++i) {
            // If we can fill the current one, fill it and move on.
            // Otherwise, stop the iteration.
            if (additionalRocks >= remainingCapacity[i]) {
                additionalRocks -= remainingCapacity[i];
                fullBags++;
            }
            else
                break;
        }
        
        // Return `fullBags` after the iteration stops.
        return fullBags;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        # Sort bags by the remaining capacity.
        remaining_capacity = [cap - rock for cap, rock in zip(capacity, rocks)]
        remaining_capacity.sort()
        full_bags = 0
        
        # Iterate over sorted bags and fill them using additional rocks.
        for curr_capacity in remaining_capacity:
            # If we can fill the current one, fill it and move on.
            # Otherwise, stop the iteration.
            if additionalRocks >= curr_capacity:
                additionalRocks -= curr_capacity
                full_bags += 1
            else:
                break
        
        # Return `full_bags` after the iteration stops.
        return full_bags
```

</details>
