# 326. Power of Three

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/power-of-three/)  
`Math` `Recursion`

**Problem Link:** [LeetCode 326 - Power of Three](https://leetcode.com/problems/power-of-three/)

## Problem

Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

### Example 1

```text
Input: n = 27
Output: true
Explanation: 27 = 33
```

### Example 2

```text
Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
```

### Example 3

```text
Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).
```

## Constraints

- -231 <= n <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Power of Two](https://leetcode.com/problems/power-of-two/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Power of Four](https://leetcode.com/problems/power-of-four/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Check if Number is a Sum of Powers of Three](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 326. Power of Three

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Loop Iteration | Java |
| Base Conversion | Java |
| Mathematics | Java |
| Integer Limitations | Java |

## Approach 1: Loop Iteration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
}
```

</details>

<br>

## Approach 2: Base Conversion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
String baseChange = Integer.toString(number, base);
```

</details>

<br>

## Approach 3: Mathematics

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean isPowerOfThree(int n) {
        return (Math.log10(n) / Math.log10(3)) % 1 == 0;
    }
}
```

</details>

<br>

## Approach 4: Integer Limitations

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean isPowerOfThree(int n)
```

</details>
