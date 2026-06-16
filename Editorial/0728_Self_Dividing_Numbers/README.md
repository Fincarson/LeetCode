# 728. Self Dividing Numbers

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/self-dividing-numbers/)  
`Math`

**Problem Link:** [LeetCode 728 - Self Dividing Numbers](https://leetcode.com/problems/self-dividing-numbers/)

## Problem

A self-dividing number is a number that is divisible by every digit it contains.

- For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

A self-dividing number is not allowed to contain the digit zero.

Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right] (both inclusive).

### Example 1

```text
Input: left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
```

### Example 2

```text
Input: left = 47, right = 85
Output: [48,55,66,77]
```

## Constraints

- 1 <= left <= right <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Perfect Number](https://leetcode.com/problems/perfect-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Check if Number Has Equal Digit Count and Digit Value](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count the Digits That Divide a Number](https://leetcode.com/problems/count-the-digits-that-divide-a-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 728. Self Dividing Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach : Brute Force [Accepted] | Java, Python3 |

## Approach : Brute Force [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ans = new ArrayList();
        for (int n = left; n <= right; ++n) {
            if (selfDividing(n)) {
                ans.add(n);
            }
        }
        return ans;
    }
    public boolean selfDividing(int n) {
        for (char c: String.valueOf(n).toCharArray()) {
            if (c == '0' || (n % (c - '0') > 0)) {
                return false;
            }
        }
        return true;
    }
    /*
    Alternate implementation of selfDividing:
    public boolean selfDividing(int n) {
        int x = n;
        while (x > 0) {
            int d = x % 10;
            if (d == 0 || (n % d) > 0) {
                return false;
            }
            x /= 10;
        }
        return true;
    */
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        # Helper function to check if a number is self-dividing
        def self_dividing(n: int) -> bool:
            for d in str(n):
                if d == "0" or n % int(d) > 0:
                    return False
            return True

        """
        def self_dividing(n: int) -> bool:
            x = n
            while x > 0:
                d = x % 10
                if d == 0 or (n % d) > 0:
                    return False
                x //= 10
            return True
        """

        # List to store self-dividing numbers
        ans = []

        # Iterate over the range and find self-dividing numbers
        for n in range(left, right + 1):
            if self_dividing(n):
                ans.append(n)

        # Alternatively: return list(filter(self_dividing, range(left, right + 1)))
        return ans
```

</details>
