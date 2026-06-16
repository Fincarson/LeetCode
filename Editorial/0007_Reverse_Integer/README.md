# 7. Reverse Integer

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/reverse-integer/)  
`Math`

**Problem Link:** [LeetCode 7 - Reverse Integer](https://leetcode.com/problems/reverse-integer/)

## Problem

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

### Example 1

```text
Input: x = 123
Output: 321
```

### Example 2

```text
Input: x = -123
Output: -321
```

### Example 3

```text
Input: x = 120
Output: 21
```

## Constraints

- -231 <= x <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Reverse Bits](https://leetcode.com/problems/reverse-bits/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [A Number After a Double Reversal](https://leetcode.com/problems/a-number-after-a-double-reversal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count Number of Distinct Integers After Reverse Operations](https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 7. Reverse Integer

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Pop and Push Digits & Check before Overflow | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Pop and Push Digits & Check before Overflow

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int Reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > int.MaxValue / 10 ||
                (rev == int.MaxValue / 10 && pop > 7))
                return 0;
            if (rev < int.MinValue / 10 ||
                (rev == int.MinValue / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }

        return rev;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverse(x int) int {
    rev := 0
    for x != 0 {
        pop := x % 10
        x /= 10
        if rev > 214748364 || (rev == 214748364 && pop > 7) {
            return 0
        }
        if rev < -214748364 || (rev == -214748364 && pop < -8) {
            return 0
        }
        rev = rev*10 + pop
    }
    return rev
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (
                rev > Integer.MAX_VALUE / 10 ||
                (rev == Integer.MAX_VALUE / 10 && pop > 7)
            ) return 0;
            if (
                rev < Integer.MIN_VALUE / 10 ||
                (rev == Integer.MIN_VALUE / 10 && pop < -8)
            ) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reverse = function (x) {
    let rev = 0;
    while (x !== 0) {
        let pop = x % 10;
        x = (x - pop) / 10;
        if (
            rev > Math.pow(2, 31) / 10 ||
            (rev == Math.pow(2, 31) / 10 && pop > 7)
        )
            return 0;
        if (
            rev < Math.pow(-2, 31) / 10 ||
            (rev == Math.pow(-2, 31) / 10 && pop < -8)
        )
            return 0;
        rev = rev * 10 + pop;
    }
    return rev;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverse(self, x: int) -> int:
        sign = [1, -1][x < 0]
        rev, x = 0, abs(x)
        while x:
            x, mod = divmod(x, 10)
            rev = rev * 10 + mod
            if rev > 2**31 - 1:
                return 0
        return sign * rev
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function reverse(x: number): number {
    let rev: number = 0;
    while (x !== 0) {
        let pop: number = x % 10;
        x = (x - pop) / 10;
        if (
            rev > Math.pow(2, 31) / 10 ||
            (rev === Math.pow(2, 31) / 10 && pop > 7)
        )
            return 0;
        if (
            rev < Math.pow(-2, 31) / 10 ||
            (rev === Math.pow(-2, 31) / 10 && pop < -8)
        )
            return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}
```

</details>
