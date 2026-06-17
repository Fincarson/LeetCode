# 507. Perfect Number

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/perfect-number/)  
`Math`

**Problem Link:** [LeetCode 507 - Perfect Number](https://leetcode.com/problems/perfect-number/)

## Problem

A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

### Example 1

```text
Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
```

### Example 2

```text
Input: num = 7
Output: false
```

## Constraints

- 1 <= num <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Self Dividing Numbers](https://leetcode.com/problems/self-dividing-numbers/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 507. Perfect Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Better Brute Force [Time Limit Exceeded] | Java |
| Approach #3 Optimal Solution [Accepted] | Java |
| Approach #4 Euclid-Euler Theorem [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public boolean checkPerfectNumber(int num) {
        if (num <= 0) {
            return false;
        }
        int sum = 0;
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                sum += i;
            }

        }
        return sum == num;
    }
}
```

</details>

<br>

## Approach #2 Better Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public boolean checkPerfectNumber(int num) {
        if (num <= 0) {
            return false;
        }
        int sum = 0;
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                sum += i;
            }
            if(sum>num) {
                return false;
            }
        }
        return sum == num;
    }
}
```

</details>

<br>

## Approach #3 Optimal Solution [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

    public boolean checkPerfectNumber(int num) {
        if (num <= 0) {
            return false;
        }
        int sum = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) {
                    sum += num / i;
                }

            }
        }
        return sum - num == num;
    }
}
```

</details>

<br>

## Approach #4 Euclid-Euler Theorem [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int pn(int p) {
        return (1 << (p - 1)) * ((1 << p) - 1);
    }
    public boolean checkPerfectNumber(int num) {
        int[] primes=new int[]{2,3,5,7,13,17,19,31};
        for (int prime: primes) {
            if (pn(prime) == num)
                return true;
        }
        return false;
    }
}
```

</details>
