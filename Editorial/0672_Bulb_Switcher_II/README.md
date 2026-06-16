# 672. Bulb Switcher II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/bulb-switcher-ii/)  
`Math` `Bit Manipulation` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 672 - Bulb Switcher II](https://leetcode.com/problems/bulb-switcher-ii/)

## Problem

There is a room with n bulbs labeled from 1 to n that all are turned on initially, and four buttons on the wall. Each of the four buttons has a different functionality where:

- Button 1: Flips the status of all the bulbs.
- Button 2: Flips the status of all the bulbs with even labels (i.e., 2, 4, ...).
- Button 3: Flips the status of all the bulbs with odd labels (i.e., 1, 3, ...).
- Button 4: Flips the status of all the bulbs with a label j = 3k + 1 where k = 0, 1, 2, ... (i.e., 1, 4, 7, 10, ...).

You must make exactly presses button presses in total. For each press, you may pick any of the four buttons to press.

Given the two integers n and presses, return the number of different possible statuses after performing all presses button presses.

### Example 1

```text
Input: n = 1, presses = 1
Output: 2
Explanation: Status can be:
- [off] by pressing button 1
- [on] by pressing button 2
```

### Example 2

```text
Input: n = 2, presses = 1
Output: 3
Explanation: Status can be:
- [off, off] by pressing button 1
- [on, off] by pressing button 2
- [off, on] by pressing button 3
```

### Example 3

```text
Input: n = 3, presses = 1
Output: 4
Explanation: Status can be:
- [off, off, off] by pressing button 1
- [on, off, on] by pressing button 2
- [off, on, off] by pressing button 3
- [off, on, on] by pressing button 4
```

## Constraints

- 1 <= n <= 1000
- 0 <= presses <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Bulb Switcher](https://leetcode.com/problems/bulb-switcher/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of Times Binary String Is Prefix-Aligned](https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 672. Bulb Switcher II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Reduce Search Space [Accepted] | Java, Python3 |
| Mathematical [Accepted] | Java, Python3 |

## Approach 1: Reduce Search Space [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int flipLights(int n, int m) {
        Set<Integer> seen = new HashSet();
        n = Math.min(n, 6);
        int shift = Math.max(0, 6-n);
        for (int cand = 0; cand < 16; ++cand) {
            int bcount = Integer.bitCount(cand);
            if (bcount % 2 == m % 2 && bcount <= m) {
                int lights = 0;
                if (((cand >> 0) & 1) > 0) lights ^= 0b111111 >> shift;
                if (((cand >> 1) & 1) > 0) lights ^= 0b010101 >> shift;
                if (((cand >> 2) & 1) > 0) lights ^= 0b101010 >> shift;
                if (((cand >> 3) & 1) > 0) lights ^= 0b100100 >> shift;
                seen.add(lights);
            }
        }
        return seen.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def flipLights(self, n: int, presses: int) -> int:
        seen = set()
        for cand in itertools.product((0, 1), repeat = 4):
            if sum(cand) % 2 == presses % 2 and sum(cand) <= presses:
                A = []
                for i in range(min(n, 3)):
                    light = 1
                    light ^= cand[0]
                    light ^= cand[1] and i % 2
                    light ^= cand[2] and i % 2 == 0
                    light ^= cand[3] and i % 3 == 0
                    A.append(light)
                seen.add(tuple(A))

        return len(seen)
```

</details>

<br>

## Approach 2: Mathematical [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int flipLights(int n, int m) {
        n = Math.min(n, 3);
        if (m == 0) return 1;
        if (m == 1) return n == 1 ? 2 : n == 2 ? 3 : 4;
        if (m == 2) return n == 1 ? 2 : n == 2 ? 4 : 7;
        return n == 1 ? 2 : n == 2 ? 4 : 8;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def flipLights(self, n, m):
        n = min(n, 3)
        if m == 0: return 1
        if m == 1: return [2, 3, 4][n-1]
        if m == 2: return [2, 4, 7][n-1]
        return [2, 4, 8][n-1]
```

</details>
