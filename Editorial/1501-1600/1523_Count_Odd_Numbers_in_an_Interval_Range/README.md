# 1523. Count Odd Numbers in an Interval Range

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)  
`Math`

**Problem Link:** [LeetCode 1523 - Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)

## Problem

Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

### Example 1

```text
Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].
```

### Example 2

```text
Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].
```

## Constraints

- 0 <= low <= high <= 10^9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Check if Bitwise OR Has Trailing Zeros](https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1523. Count Odd Numbers in an Interval Range

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Maths | C++, Java |

## Approach 1: Maths

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        // If low is even, make it odd.
        if (!(low & 1)) {
            low++;
        }
  
        // low could become greater than high due to incrementation
        // if it is, the answer is 0; otherwise, use the formula.
        return low > high ? 0 : (high - low) / 2 + 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int countOdds(int low, int high) {
    // If low is even, make it odd.
    if ((low & 1) == 0) {
      low++;
    }

    // low could become greater than high due to incrementation
    // if it is, the answer is 0; otherwise, use the formula.
    return low > high ? 0 : (high - low) / 2 + 1;
  }
}
```

</details>
