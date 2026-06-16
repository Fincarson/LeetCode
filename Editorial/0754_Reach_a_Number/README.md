# 754. Reach a Number

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/reach-a-number/)  
`Math` `Binary Search`

**Problem Link:** [LeetCode 754 - Reach a Number](https://leetcode.com/problems/reach-a-number/)

## Problem

You are standing at position 0 on an infinite number line. There is a destination at position target.

You can make some number of moves numMoves so that:

- On each move, you can either go left or right.
- During the ith move (starting from i == 1 to i == numMoves), you take i steps in the chosen direction.

Given the integer target, return the minimum number of moves required (i.e., the minimum numMoves) to reach the destination.

### Example 1

```text
Input: target = 2
Output: 3
Explanation:
On the 1st move, we step from 0 to 1 (1 step).
On the 2nd move, we step from 1 to -1 (2 steps).
On the 3rd move, we step from -1 to 2 (3 steps).
```

### Example 2

```text
Input: target = 3
Output: 2
Explanation:
On the 1st move, we step from 0 to 1 (1 step).
On the 2nd move, we step from 1 to 3 (2 steps).
```

## Constraints

- -109 <= target <= 109
- target != 0

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Ways to Reach a Position After Exactly k Steps](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 754. Reach a Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Mathematical [Accepted] | Java, Python |

## Approach #1: Mathematical [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int reachNumber(int target) {
        target = Math.abs(target);
        int k = 0;
        while (target > 0)
            target -= ++k;
        return target % 2 == 0 ? k : k + 1 + k%2;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def reachNumber(self, target):
        target = abs(target)
        k = 0
        while target > 0:
            k += 1
            target -= k

        return k if target % 2 == 0 else k + 1 + k%2
```

</details>
