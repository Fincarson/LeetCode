# 258. Add Digits

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/add-digits/)  
`Math` `Simulation` `Number Theory`

**Problem Link:** [LeetCode 258 - Add Digits](https://leetcode.com/problems/add-digits/)

## Problem

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

### Example 1

```text
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
Since 2 has only one digit, return it.
```

### Example 2

```text
Input: num = 0
Output: 0
```

## Constraints

- 0 <= num <= 231 - 1

Follow up: Could you do it without any loop/recursion in O(1) runtime?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Happy Number](https://leetcode.com/problems/happy-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sum of Digits in the Minimum Number](https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Sum of Four Digit Number After Splitting Digits](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Calculate Digit Sum of a String](https://leetcode.com/problems/calculate-digit-sum-of-a-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Difference Between Element Sum and Digit Sum of an Array](https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Alternating Digit Sum](https://leetcode.com/problems/alternating-digit-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 258. Add Digits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Mathematical: Digital Root | C++, Java, Python3 |

## Approach 1: Mathematical: Digital Root

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0:
            return 0
        if num % 9 == 0:
            return 9
        return num % 9
```

</details>
