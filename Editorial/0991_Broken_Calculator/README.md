# 991. Broken Calculator

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/broken-calculator/)  
`Math` `Greedy`

**Problem Link:** [LeetCode 991 - Broken Calculator](https://leetcode.com/problems/broken-calculator/)

## Problem

There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:

- multiply the number on display by 2, or
- subtract 1 from the number on display.

Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.

### Example 1

```text
Input: startValue = 2, target = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
```

### Example 2

```text
Input: startValue = 5, target = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.
```

### Example 3

```text
Input: startValue = 3, target = 10
Output: 3
Explanation: Use double, decrement and double {3 -> 6 -> 5 -> 10}.
```

## Constraints

- 1 <= startValue, target <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Make the Integer Zero](https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 991. Broken Calculator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Work Backwards | Java, Python3 |

## Approach 1: Work Backwards

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (target > startValue) {
            ans++;
            if (target % 2 == 1)
                target++;
            else
                target /= 2;
        }

        return ans + startValue - target;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        ans = 0
        while target > startValue:
            ans += 1
            if target % 2: target += 1
            else: target //= 2

        return ans + startValue - target
```

</details>
