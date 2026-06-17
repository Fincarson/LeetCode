# 906. Super Palindromes

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/super-palindromes/)  
`Math` `String` `Enumeration`

**Problem Link:** [LeetCode 906 - Super Palindromes](https://leetcode.com/problems/super-palindromes/)

## Problem

Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].

### Example 1

```text
Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
```

### Example 2

```text
Input: left = "1", right = "2"
Output: 1
```

## Constraints

- 1 <= left.length, right.length <= 18
- left and right consist of only digits.
- left and right cannot have leading zeros.
- left and right represent integers in the range [1, 1018 - 1].
- left is less than or equal to right.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 906. Super Palindromes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Mathematical | Java, Python |

## Approach 1: Mathematical

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int superpalindromesInRange(String sL, String sR) {
        long L = Long.valueOf(sL);
        long R = Long.valueOf(sR);
        int MAGIC = 100000;
        int ans = 0;

        // count odd length;
        for (int k = 1; k < MAGIC; ++k) {
            StringBuilder sb = new StringBuilder(Integer.toString(k));
            for (int i = sb.length() - 2; i >= 0; --i)
                sb.append(sb.charAt(i));
            long v = Long.valueOf(sb.toString());
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) ans++;
        }

        // count even length;
        for (int k = 1; k < MAGIC; ++k) {
            StringBuilder sb = new StringBuilder(Integer.toString(k));
            for (int i = sb.length() - 1; i >= 0; --i)
                sb.append(sb.charAt(i));
            long v = Long.valueOf(sb.toString());
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) ans++;
        }

        return ans;
    }

    public boolean isPalindrome(long x) {
        return x == reverse(x);
    }

    public long reverse(long x) {
        long ans = 0;
        while (x > 0) {
            ans = 10 * ans + x % 10;
            x /= 10;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def superpalindromesInRange(self, L, R):
        L, R = int(L), int(R)
        MAGIC = 100000

        def reverse(x):
            ans = 0
            while x:
                ans = 10 * ans + x % 10
                x /= 10
            return ans

        def is_palindrome(x):
            return x == reverse(x)

        ans = 0

        # count odd length
        for k in xrange(MAGIC):
            s = str(k)  # Eg. s = '1234'
            t = s + s[-2::-1]  # t = '1234321'
            v = int(t) ** 2
            if v > R: break
            if v >= L and is_palindrome(v):
                ans += 1

        # count even length
        for k in xrange(MAGIC):
            s = str(k)  # Eg. s = '1234'
            t = s + s[::-1]  # t = '12344321'
            v = int(t) ** 2
            if v > R: break
            if v >= L and is_palindrome(v):
                ans += 1

        return ans
```

</details>
