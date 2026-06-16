# 263. Ugly Number

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/ugly-number/)  
`Math`

**Problem Link:** [LeetCode 263 - Ugly Number](https://leetcode.com/problems/ugly-number/)

## Problem

An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.

Given an integer n, return true if n is an ugly number.

### Example 1

```text
Input: n = 6
Output: true
Explanation: 6 = 2 × 3
```

### Example 2

```text
Input: n = 1
Output: true
Explanation: 1 has no prime factors.
```

### Example 3

```text
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
```

## Constraints

- -231 <= n <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Happy Number](https://leetcode.com/problems/happy-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count Primes](https://leetcode.com/problems/count-primes/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 263. Ugly Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Definition | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Definition

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isUgly(int n) {   
    // A non-positive integer cannot be ugly
    if (n <= 0) {
        return false;
    }

    // Factorize by dividing with permitted factors.
    int factors[] = {2, 3, 5};
    for (int i = 0; i < 3; i++) {
        n = keepDividingWhenDivisible(n, factors[i]);
    }

    // Check if the integer is reduced to 1 or not.
    return n == 1;
}

// Keep dividing dividend by divisor when division is possible.
int keepDividingWhenDivisible(int dividend, int divisor) {
    while (dividend % divisor == 0) {
        dividend /= divisor;
    }
    return dividend;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isUgly(int n) {
        // A non-positive integer cannot be ugly
        if (n <= 0) {
            return false;
        }

        // Factorize by dividing with permitted factors.
        for (auto factor : {2, 3, 5}) {
            n = keepDividingWhenDivisible(n, factor);
        }

        // Check if the integer is reduced to 1 or not.
        return n == 1;
    }

    // Keep dividing dividend by divisor when division is possible.
    int keepDividingWhenDivisible(int dividend, int divisor) {
        while (dividend % divisor == 0) {
            dividend /= divisor;
        }
        return dividend;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsUgly(int n) {        
        // A non-positive integer cannot be ugly
        if (n <= 0) {
            return false;
        }
        
        // Factorize by dividing with permitted factors.
        foreach (int factor in new int[] {2, 3, 5}) {
            n = KeepDividingWhenDivisible(n, factor);
        }

        // Check if the integer is reduced to 1 or not.
        return n == 1;
    }
    
    // Keep dividing dividend by divisor when division is possible.
    int KeepDividingWhenDivisible(int dividend, int divisor) {
        while (dividend % divisor == 0) {
            dividend /= divisor;
        }
        return dividend;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isUgly(n int) bool {    
    // A non-positive integer cannot be ugly
    if n <= 0 {
        return false
    }

    // Factorize by dividing with permitted factors.
    for _, factor := range []int{2, 3, 5} {
        n = keepDividingWhenDivisible(n, factor)
    }

    // Check if the integer is reduced to 1 or not.
    return n == 1
}

// Keep dividing dividend by divisor when division is possible.
func keepDividingWhenDivisible(dividend, divisor int) int {
    for dividend % divisor == 0 {
        dividend /= divisor;
    }
    return dividend
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isUgly(int n) {
        // A non-positive integer cannot be ugly
        if (n <= 0) {
            return false;
        }

        // Factorize by dividing with permitted factors
        for (int factor : new int[] { 2, 3, 5 }) {
            n = keepDividingWhenDivisible(n, factor);
        }

        // Check if the integer is reduced to 1 or not.
        return n == 1;
    }

    // Keep dividing dividend by divisor when division is possible.
    private int keepDividingWhenDivisible(int dividend, int divisor) {
        while (dividend % divisor == 0) {
            dividend /= divisor;
        }
        return dividend;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isUgly = function(n) {    
    // A non-positive integer cannot be ugly
    if (n <= 0) {
        return false;
    }
    
    // Keep dividing dividend by divisor when division is possible.
    const keepDividingWhenDivisible = (dividend, divisor) => {
        while (dividend % divisor == 0) {
            dividend /= divisor;
        }
        return dividend;
    }

    // Factorize by dividing with permitted factors.
    for (const factor of [2, 3, 5]) {
        n = keepDividingWhenDivisible(n, factor);
    }

    // Check if the integer is reduced to 1 or not.
    return n == 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isUgly(self, n: int) -> bool:
        # A non-positive integer cannot be ugly
        if n <= 0:
            return False

        # Keep dividing dividend by divisor when division is possible
        def keep_dividing_when_divisible(dividend, divisor):
            while dividend % divisor == 0:
                dividend //= divisor
            return dividend

        # Factorize by dividing with permitted factors
        for factor in [2, 3, 5]:
            n = keep_dividing_when_divisible(n, factor)

        # Check if the integer is reduced to 1 or not.
        return n == 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isUgly(n: number): boolean {    
    // A non-positive integer cannot be ugly
    if (n <= 0) {
        return false;
    }
    
    // Keep dividing dividend by divisor when division is possible.
    const keepDividingWhenDivisible = (dividend: number, divisor: number): number => {
        while (dividend % divisor == 0) {
            dividend /= divisor;
        }
        return dividend;
    }

    // Factorize by dividing with permitted factors.
    for (const factor of [2, 3, 5]) {
        n = keepDividingWhenDivisible(n, factor);
    }

    // Check if the integer is reduced to 1 or not.
    return n == 1;
};
```

</details>
