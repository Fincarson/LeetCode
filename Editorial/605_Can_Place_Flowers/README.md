# 605. Can Place Flowers

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/can-place-flowers/)  
`Array` `Greedy`

**Problem Link:** [LeetCode 605 - Can Place Flowers](https://leetcode.com/problems/can-place-flowers/)

## Problem

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

### Example 1

```text
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
```

### Example 2

```text
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

## Constraints

- 1 <= flowerbed.length <= 2 * 104
- flowerbed[i] is 0 or 1.
- There are no two adjacent flowers in flowerbed.
- 0 <= n <= flowerbed.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Teemo Attacking](https://leetcode.com/problems/teemo-attacking/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Asteroid Collision](https://leetcode.com/problems/asteroid-collision/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 605. Can Place Flowers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Single Scan [Accepted] | C++, Java, Python3 |
| Approach #2 Optimized [Accepted] | C++, Java, Python3 |

## Approach #1 Single Scan [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if the current plot is empty.
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty.
                bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                // If both plots are empty, we can plant a flower here.
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return count >= n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.length; i++) {
            // Check if the current plot is empty.
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty.
                boolean emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
                boolean emptyRightPlot = (i == flowerbed.length - 1) || (flowerbed[i + 1] == 0);
                
                // If both plots are empty, we can plant a flower here.
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return count >= n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0
        for i in range(len(flowerbed)):
            # Check if the current plot is empty.
            if flowerbed[i] == 0:
                # Check if the left and right plots are empty.
                empty_left_plot = (i == 0) or (flowerbed[i - 1] == 0)
                empty_right_lot = (i == len(flowerbed) - 1) or (flowerbed[i + 1] == 0)
                
                # If both plots are empty, we can plant a flower here.
                if empty_left_plot and empty_right_lot:
                    flowerbed[i] = 1
                    count += 1
                    
        return count >= n
```

</details>

<br>

## Approach #2 Optimized [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if the current plot is empty.
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty.
                bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                // If both plots are empty, we can plant a flower here.
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    count++;
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        return count >= n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.length; i++) {
            // Check if the current plot is empty.
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty.
                boolean emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
                boolean emptyRightPlot = (i == flowerbed.length - 1) || (flowerbed[i + 1] == 0);
                
                // If both plots are empty, we can plant a flower here.
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    count++;
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        return count >= n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0
        for i in range(len(flowerbed)):
            # Check if the current plot is empty.
            if flowerbed[i] == 0:
                # Check if the left and right plots are empty.
                empty_left_plot = (i == 0) or (flowerbed[i - 1] == 0)
                empty_right_lot = (i == len(flowerbed) - 1) or (flowerbed[i + 1] == 0)
                
                # If both plots are empty, we can plant a flower here.
                if empty_left_plot and empty_right_lot:
                    flowerbed[i] = 1
                    count += 1
                    if count >= n:
                        return True
                    
        return count >= n
```

</details>
