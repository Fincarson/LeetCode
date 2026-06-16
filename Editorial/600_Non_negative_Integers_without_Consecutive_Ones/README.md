# 600. Non-negative Integers without Consecutive Ones

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 600 - Non-negative Integers without Consecutive Ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)

## Problem

Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.

### Example 1

```text
Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule.
```

### Example 2

```text
Input: n = 1
Output: 2
```

### Example 3

```text
Input: n = 2
Output: 3
```

## Constraints

- 1 <= n <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [House Robber](https://leetcode.com/problems/house-robber/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [House Robber II](https://leetcode.com/problems/house-robber-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Generate Binary Strings Without Adjacent Zeros](https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 600. Non-negative Integers without Consecutive Ones

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Better Brute Force [Time Limit Exceeded] | Java |
| Approach #3 Using Bit Manipulation [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findIntegers(int num) {
        int count = 0;
        for (int i = 0; i <= num; i++)
            if (check(i))
                count++;
        return count;
    }
    public boolean check(int n) {
        int i = 31;
        while (i > 0) {
            if ((n & (1 << i)) != 0 && (n & (1 << (i - 1))) != 0)
                return false;
            i--;
        }
        return true;
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
    public int findIntegers(int num) {
        return find(0, 0, num, false);
    }
    public int find(int i, int sum, int num, boolean prev) {
        if (sum > num)
            return 0;
        if (1<<i > num)
            return 1;
        if (prev)
            return find(i + 1, sum, num, false);
        return find(i + 1, sum, num, false) + find(i + 1, sum + (1 << i), num, true);
    }
}
```

</details>

<br>

## Approach #3 Using Bit Manipulation [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findIntegers(int num) {
        int[] f = new int[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < f.length; i++)
            f[i] = f[i - 1] + f[i - 2];
        int i = 30, sum = 0, prev_bit = 0;
        while (i >= 0) {
            if ((num & (1 << i)) != 0) {
                sum += f[i];
                if (prev_bit == 1) {
                    sum--;
                    break;
                }
                prev_bit = 1;
            } else
                prev_bit = 0;
            i--;
        }
        return sum + 1;
    }
}
```

</details>
