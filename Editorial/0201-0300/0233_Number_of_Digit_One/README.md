# 233. Number of Digit One

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/number-of-digit-one/)  
`Math` `Dynamic Programming` `Recursion`

**Problem Link:** [LeetCode 233 - Number of Digit One](https://leetcode.com/problems/number-of-digit-one/)

## Problem

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

### Example 1

```text
Input: n = 13
Output: 6
```

### Example 2

```text
Input: n = 0
Output: 0
```

## Constraints

- 0 <= n <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Digit Count in Range](https://leetcode.com/problems/digit-count-in-range/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 233. Number of Digit One

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute force [Time Limit Exceeded] | C++ |
| Approach #2 Solve it mathematically [Accepted] | C++ |

## Approach #1 Brute force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int countDigitOne(int n)
{
    int countr = 0;
    for (int i = 1; i <= n; i++) {
        string str = to_string(i);
        countr += count(str.begin(), str.end(), '1');
    }
    return countr;
}
```

</details>

<br>

## Approach #2 Solve it mathematically [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int countDigitOne(int n)
{
    int countr = 0;
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
    }
    return countr;
}
```

</details>
