# 625. Minimum Factorization

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-factorization/)  
`Math` `Greedy`

**Problem Link:** [LeetCode 625 - Minimum Factorization](https://leetcode.com/problems/minimum-factorization/)

## Problem

Given a positive integer num, return the smallest positive integer x whose multiplication of each digit equals num. If there is no answer or the answer is not fit in 32-bit signed integer, return 0.

### Example 1

```text
Input: num = 48
Output: 68
```

### Example 2

```text
Input: num = 15
Output: 35
```

## Constraints

- 1 <= num <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 625. Minimum Factorization

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Better Brute Force [Time Limit Exceeded] | Java |
| Approach #3  Using Factorization[Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int smallestFactorization(int a) {
        for (int i = 1; i < 999999999; i++) {
            long mul = 1, t = i;
            while (t != 0) {
                mul *= t % 10;
                t /= 10;
            }
            if (mul == a && mul <= Integer.MAX_VALUE)
                return i;
        }
        return 0;
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
    long ans;
    public int smallestFactorization(int a) {
        if(a < 2)
            return a;
        int[] dig=new int[]{9, 8, 7, 6, 5, 4, 3, 2};
        if (search(dig, 0, a, 1, "") && ans <= Integer.MAX_VALUE)
            return (int)ans;
        return 0;
    }
    public boolean search(int[] dig, int i, int a, long mul, String res) {
        if (mul > a || i == dig.length )
            return false;
        if (mul == a) {
            ans = Long.parseLong(res);
            return true;
        }
        return search(dig, i, a, mul * dig[i], dig[i] + res) || search(dig, i + 1, a, mul, res);
    }
}
```

</details>

<br>

## Approach #3  Using Factorization[Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int smallestFactorization(int a) {
        if (a < 2)
            return a;
        long res = 0, mul = 1;
        for (int i = 9; i >= 2; i--) {
            while (a % i == 0) {
                a /= i;
                res = mul * i + res;
                mul *= 10;
            }
        }
        return a < 2 && res <= Integer.MAX_VALUE ? (int)res : 0;
    }
}
```

</details>
