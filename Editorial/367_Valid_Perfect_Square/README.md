# 367. Valid Perfect Square

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/valid-perfect-square/)  
`Math` `Binary Search`

**Problem Link:** [LeetCode 367 - Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/)

## Problem

Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

### Example 1

```text
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
```

### Example 2

```text
Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
```

## Constraints

- 1 <= num <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 367. Valid Perfect Square

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | Java, Python |
| Newton's Method | Java, Python |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public boolean isPerfectSquare(int num) {
    if (num < 2) {
      return true;
    }

    long left = 2, right = num / 2, x, guessSquared;
    while (left <= right) {
      x = left + (right - left) / 2;
      guessSquared = x * x;
      if (guessSquared == num) {
        return true;
      }
      if (guessSquared > num) {
        right = x - 1;
      } else {
        left = x + 1;
      }
    }
    return false;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num < 2:
            return True
        
        left, right = 2, num // 2
        
        while left <= right:
            x = left + (right - left) // 2
            guess_squared = x * x
            if guess_squared == num:
                return True
            if guess_squared > num:
                right = x - 1
            else:
                left = x + 1
        
        return False
```

</details>

<br>

## Approach 2: Newton's Method

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public boolean isPerfectSquare(int num) {
    if (num < 2) return true;

    long x = num / 2;
    while (x * x > num) {
      x = (x + num / x) / 2;
    }
    return (x * x == num);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num < 2:
            return True
        
        x = num // 2
        while x * x > num:
            x = (x + num // x) // 2
        return x * x == num
```

</details>
