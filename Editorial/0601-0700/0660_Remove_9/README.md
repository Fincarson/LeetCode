# 660. Remove 9

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/remove-9/)  
`Math`

**Problem Link:** [LeetCode 660 - Remove 9](https://leetcode.com/problems/remove-9/)

## Problem

Start from integer 1, remove any integer that contains 9 such as 9, 19, 29...

Now, you will have a new integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 10, 11, ...].

Given an integer n, return the nth (1-indexed) integer in the new sequence.

### Example 1

```text
Input: n = 9
Output: 10
```

### Example 2

```text
Input: n = 10
Output: 11
```

## Constraints

- 1 <= n <= 8 * 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 660. Remove 9

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Mathematical | Java, Python3 |

## Approach #1: Mathematical

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int newInteger(int n) {
        return Integer.parseInt(Integer.toString(n, 9));
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def newInteger(self, n):
        ans = ''
        while n:
            ans = str(n%9) + ans
            n //= 9

        return int(ans)
```

</details>
