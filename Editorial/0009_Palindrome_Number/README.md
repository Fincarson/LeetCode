# 9. Palindrome Number

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/palindrome-number/)  
`Math`

**Problem Link:** [LeetCode 9 - Palindrome Number](https://leetcode.com/problems/palindrome-number/)

## Problem

Given an integer x, return true if x is a palindrome, and false otherwise.

### Example 1

```text
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

### Example 2

```text
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

### Example 3

```text
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

## Constraints

- -231 <= x <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find Palindrome With Fixed Length](https://leetcode.com/problems/find-palindrome-with-fixed-length/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Strictly Palindromic Number](https://leetcode.com/problems/strictly-palindromic-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [  Count Symmetric Integers](https://leetcode.com/problems/count-symmetric-integers/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the Count of Good Integers](https://leetcode.com/problems/find-the-count-of-good-integers/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find the Largest Palindrome Divisible by K](https://leetcode.com/problems/find-the-largest-palindrome-divisible-by-k/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 9. Palindrome Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Revert half of the number | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Revert half of the number

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isPalindrome(int x) {
    // Special cases:
    // As discussed above, when x < 0, x is not a palindrome.
    // Also if the last digit of the number is 0, in order to be a palindrome,
    // the first digit of the number also needs to be 0.
    // Only 0 satisfy this property.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // When the length is an odd number, we can get rid of the middle digit by
    // revertedNumber/10 For example when the input is 12321, at the end of the
    // while loop we get x = 12, revertedNumber = 123, since the middle digit
    // doesn't matter in palidrome(it will always equal to itself), we can
    // simply get rid of it.
    return x == revertedNumber || x == revertedNumber / 10;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a
        // palindrome, the first digit of the number also needs to be 0. Only 0
        // satisfy this property.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit
        // by revertedNumber/10 For example when the input is 12321, at the end
        // of the while loop we get x = 12, revertedNumber = 123, since the
        // middle digit doesn't matter in palidrome(it will always equal to
        // itself), we can simply get rid of it.
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsPalindrome(int x) {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a
        // palindrome, the first digit of the number also needs to be 0. Only 0
        // satisfy this property.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit
        // by revertedNumber/10 For example when the input is 12321, at the end
        // of the while loop we get x = 12, revertedNumber = 123, since the
        // middle digit doesn't matter in palidrome(it will always equal to
        // itself), we can simply get rid of it.
        return x == revertedNumber || x == revertedNumber / 10;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isPalindrome(x int) bool {
    // Special cases:
    // As discussed above, when x < 0, x is not a palindrome.
    // Also if the last digit of the number is 0, in order to be a palindrome,
    // the first digit of the number also needs to be 0.
    // Only 0 satisfy this property.
    if x < 0 || (x%10 == 0 && x != 0) {
        return false
    }

    revertedNumber := 0
    for x > revertedNumber {
        revertedNumber = revertedNumber*10 + x%10
        x = x / 10
    }

    // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
    // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
    // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
    return x == revertedNumber || x == revertedNumber/10
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean isPalindrome(int x) {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + (x % 10);
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12,
        // revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we
        // can simply get rid of it.
        return x == revertedNumber || x == revertedNumber / 10;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isPalindrome = function (x) {
    // Special cases:
    // As discussed above, when x < 0, x is not a palindrome.
    // Also if the last digit of the number is 0, in order to be a palindrome,
    // the first digit of the number also needs to be 0.
    // Only 0 satisfy this property.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    let revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + (x % 10);
        x = Math.floor(x / 10);
    }

    // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
    // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
    // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
    return x == revertedNumber || x == Math.floor(revertedNumber / 10);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Special cases:
        # As discussed above, when x < 0, x is not a palindrome.
        # Also if the last digit of the number is 0, in order to be a palindrome,
        # the first digit of the number also needs to be 0.
        # Only 0 satisfy this property.
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        revertedNumber = 0
        while x > revertedNumber:
            revertedNumber = revertedNumber * 10 + x % 10
            x //= 10

        # When the length is an odd number, we can get rid of the middle digit by revertedNumber//10
        # For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        # since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return x == revertedNumber or x == revertedNumber // 10
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isPalindrome(x: number): boolean {
    // Special cases:
    // As discussed above, when x < 0, x is not a palindrome.
    // Also if the last digit of the number is 0, in order to be a palindrome,
    // the first digit of the number also needs to be 0.
    // Only 0 satisfy this property.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    let revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + (x % 10);
        x = Math.floor(x / 10);
    }

    // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
    // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
    // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
    return x == revertedNumber || x == Math.floor(revertedNumber / 10);
}
```

</details>
