# 1217. Minimum Cost to Move Chips to The Same Position

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/)  
`Array` `Math` `Greedy`

**Problem Link:** [LeetCode 1217 - Minimum Cost to Move Chips to The Same Position](https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/)

## Problem

We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

- position[i] + 2 or position[i] - 2 with cost = 0.
- position[i] + 1 or position[i] - 1 with cost = 1.

Return the minimum cost needed to move all the chips to the same position.

### Example 1

```text
Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
```

### Example 2

```text
Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at position  3 to position 2. Each move has cost = 1. The total cost = 2.
```

### Example 3

```text
Input: position = [1,1000000000]
Output: 1
```

## Constraints

- 1 <= position.length <= 100
- 1 <= position[i] <= 10^9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Operations to Move All Balls to Each Box](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Split With Minimum Sum](https://leetcode.com/problems/split-with-minimum-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1217. Minimum Cost to Move Chips to The Same Position

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Moving Chips Cleverly | Java, Python3 |

## Approach 1: Moving Chips Cleverly

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCostToMoveChips(int[] position) {
        int even_cnt = 0;
        int odd_cnt = 0;
        for (int i : position) {
            if (i % 2 == 0) {
                even_cnt++;
            } else {
                odd_cnt++;
            }
        }
        return Math.min(odd_cnt, even_cnt);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        even_cnt = 0
        odd_cnt = 0
        for i in position:
            if i % 2 == 0:
                even_cnt += 1
            else:
                odd_cnt += 1
        return min(even_cnt, odd_cnt)
```

</details>
