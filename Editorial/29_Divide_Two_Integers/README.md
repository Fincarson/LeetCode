# 29. Divide Two Integers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/divide-two-integers/)  
`Math` `Bit Manipulation`

**Problem Link:** [LeetCode 29 - Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)

## Problem

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

### Example 1

```text
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
```

### Example 2

```text
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
```

## Constraints

- -231 <= dividend, divisor <= 231 - 1
- divisor != 0

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 29. Divide Two Integers

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Repeated Subtraction | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Repeated Exponential Searches | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Adding Powers of Two | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Adding Powers of Two with Bit-Shifting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary Long Division | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Repeated Subtraction

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int divide(int dividend, int divisor) {
    // Special case: overflow.
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    /* We need to convert both numbers to negatives
     * for the reasons explained above.
     * Also, we count the number of negatives signs. */
    int negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    /* Count how many times the divisor has to be added
     * to get the dividend. This is the quotient. */
    int quotient = 0;
    while (dividend - divisor <= 0) {
        dividend -= divisor;
        quotient--;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) {
        return -quotient;
    }
    return quotient;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        /* We need to convert both numbers to negatives
         * for the reasons explained above.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* Count how many times the divisor has to be added
         * to get the dividend. This is the quotient. */
        int quotient = 0;
        while (dividend - divisor <= 0) {
            dividend -= divisor;
            quotient--;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int Divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == int.MinValue && divisor == -1) {
            return int.MaxValue;
        }

        /* We need to convert both numbers to negatives
         * for the reasons explained above.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }

        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* Count how many times the divisor has to be added
         * to get the dividend. This is the quotient. */
        int quotient = 0;
        while (dividend - divisor <= 0) {
            quotient--;
            dividend -= divisor;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            quotient = -quotient;
        }

        return quotient;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func divide(dividend int, divisor int) int {
    if dividend == math.MinInt32 && divisor == -1 {
        return math.MaxInt32
    }
    negatives := 2
    if dividend > 0 {
        negatives--
        dividend = -dividend
    }
    if divisor > 0 {
        negatives--
        divisor = -divisor
    }
    quotient := 0
    for dividend-divisor <= 0 {
        dividend -= divisor
        quotient--
    }
    if negatives != 1 {
        return -quotient
    }
    return quotient
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        /* We need to convert both numbers to negatives
         * for the reasons explained above.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* Count how many times the divisor has to be added
         * to get the dividend. This is the quotient. */
        int quotient = 0;
        while (dividend - divisor <= 0) {
            quotient--;
            dividend -= divisor;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            quotient = -quotient;
        }
        return quotient;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var divide = function (dividend, divisor) {
    // Constants.
    var MAX_INT = 2147483647; // 2**31 - 1
    var MIN_INT = -2147483648; // -2**31
    // Special case: overflow.
    if (dividend === MIN_INT && divisor === -1) {
        return MAX_INT;
    }
    // We need to convert both numbers to negatives.
    // Also, we count the number of negatives signs.
    var negatives = 2;
    if (dividend > 0) {
        negatives -= 1;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives -= 1;
        divisor = -divisor;
    }
    // Count how many times the divisor has to be
    // added to get the dividend. This is the quotient.
    var quotient = 0;
    while (dividend - divisor <= 0) {
        quotient -= 1;
        dividend -= divisor;
    }
    // If there was originally one negative sign, then
    // the quotient remains negative. Otherwise, switch
    // it to positive.
    return negatives !== 1 ? -quotient : quotient;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:

        # Constants.
        MAX_INT = 2147483647  # 2**31 - 1
        MIN_INT = -2147483648  # -2**31

        # Special case: overflow.
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT

        # We need to convert both numbers to negatives
        # for the reasons explained above.
        # Also, we count the number of negatives signs.
        negatives = 2
        if dividend > 0:
            negatives -= 1
            dividend = -dividend
        if divisor > 0:
            negatives -= 1
            divisor = -divisor

        # Count how many times the divisor has to be
        # added to get the dividend. This is the quotient.
        quotient = 0
        while dividend - divisor <= 0:
            quotient -= 1
            dividend -= divisor

        # If there was originally one negative sign, then
        # the quotient remains negative. Otherwise, switch
        # it to positive.
        return -quotient if negatives != 1 else quotient
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function divide(dividend: number, divisor: number): number {
    // Constants.
    const MAX_INT = 2147483647; // 2**31 - 1
    const MIN_INT = -2147483648; // -2**31
    // Special case: overflow.
    if (dividend === MIN_INT && divisor === -1) {
        return MAX_INT;
    }
    // We need to convert both numbers to negatives
    // for the reasons explained above.
    // Also, we count the number of negatives signs.
    let negatives = 2;
    if (dividend > 0) {
        negatives -= 1;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives -= 1;
        divisor = -divisor;
    }
    // Count how many times the divisor has to be
    // added to get the dividend. This is the quotient.
    let quotient = 0;
    while (dividend - divisor <= 0) {
        quotient -= 1;
        dividend -= divisor;
    }
    // If there was originally one negative sign, then
    // the quotient remains negative. Otherwise, switch
    // it to positive.
    return negatives != 1 ? -quotient : quotient;
}
```

</details>

<br>

## Approach 2: Repeated Exponential Searches

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Constants for special cases
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define HALF_MIN_INT -1073741824
int divide(int dividend, int divisor) {
    // Special case: overflow.
    if (dividend == MIN_INT && divisor == -1) {
        return MAX_INT;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    int negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    int quotient = 0;
    /* Once the divisor is bigger than the current dividend,
     * we can't fit any more copies of the divisor into it. */
    while (divisor >= dividend) {
        /* We know it'll fit at least once as divivend >= divisor.
         * Note: We use a negative powerOfTwo as it's possible we might have
         * the case divide(INT_MIN, -1). */
        int powerOfTwo = -1;
        int value = divisor;
        /* Check if double the current value is too big. If not, continue
         * doubling. If it is too big, stop doubling and continue with the next
         * step */
        while (value >= HALF_MIN_INT && value + value >= dividend) {
            value += value;
            powerOfTwo += powerOfTwo;
        }
        // We have been able to subtract divisor another powerOfTwo times.
        quotient += powerOfTwo;
        // Remove value so far so that we can continue the process with
        // remainder.
        dividend -= value;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    return negatives != 1 ? -quotient : quotient;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int HALF_INT_MIN = -1073741824;

public:
    int divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        int quotient = 0;
        /* Once the divisor is bigger than the current dividend,
         * we can't fit any more copies of the divisor into it. */
        while (divisor >= dividend) {
            /* We know it'll fit at least once as divivend >= divisor.
             * Note: We use a negative powerOfTwo as it's possible we might have
             * the case divide(INT_MIN, -1). */
            int powerOfTwo = -1;
            int value = divisor;
            /* Check if double the current value is too big. If not, continue
             * doubling. If it is too big, stop doubling and continue with the
             * next step */
            while (value >= HALF_INT_MIN && value + value >= dividend) {
                value += value;
                powerOfTwo += powerOfTwo;
            }
            // We have been able to subtract divisor another powerOfTwo times.
            quotient += powerOfTwo;
            // Remove value so far so that we can continue the process with
            // remainder.
            dividend -= value;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            quotient = -quotient;
        }
        return quotient;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    int HALF_INT_MIN = -1073741824;

    public int Divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == Int32.MinValue && divisor == -1) {
            return Int32.MaxValue;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }

        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        int quotient = 0;
        /* Once the divisor is bigger than the current dividend,
         * we can't fit any more copies of the divisor into it. */
        while (divisor >= dividend) {
            /* We know it'll fit at least once as divivend >= divisor.
             * Note: We use a negative powerOfTwo as it's possible we might have
             * the case divide(Int32.MinValue, -1). */
            int powerOfTwo = -1;
            int value = divisor;
            /* Check if double the current value is too big. If not, continue
             * doubling. If it is too big, stop doubling and continue with the
             * next step */
            while (value >= HALF_INT_MIN && value + value >= dividend) {
                value += value;
                powerOfTwo += powerOfTwo;
            }

            // We have been able to subtract divisor another powerOfTwo times.
            quotient += powerOfTwo;
            // Remove value so far so that we can continue the process with
            // remainder.
            dividend -= value;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        return negatives != 1 ? -quotient : quotient;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const HALF_INT_MIN int = -1073741824

func divide(dividend int, divisor int) int {
    // Special case: overflow.
    if dividend == -2147483648 && divisor == -1 {
        return 2147483647
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    var negatives int = 2
    if dividend > 0 {
        negatives--
        dividend = -dividend
    }
    if divisor > 0 {
        negatives--
        divisor = -divisor
    }
    var quotient int = 0
    /* Once the divisor is bigger than the current dividend,
     * we can't fit any more copies of the divisor into it. */
    for divisor >= dividend {
        /* We know it'll fit at least once as divivend >= divisor.
         * Note: We use a negative powerOfTwo as it's possible we might have
         * the case divide(INT_MIN, -1). */
        var powerOfTwo int = -1
        var value int = divisor
        /* Check if double the current value is too big. If not, continue doubling.
         * If it is too big, stop doubling and continue with the next step */
        for value >= HALF_INT_MIN && value+value >= dividend {
            value += value
            powerOfTwo += powerOfTwo
        }
        // We have been able to subtract divisor another powerOfTwo times.
        quotient += powerOfTwo
        // Remove value so far so that we can continue the process with remainder.
        dividend -= value
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if negatives != 1 {
        return -quotient
    }
    return quotient
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static int HALF_INT_MIN = -1073741824;

    public int divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        int quotient = 0;
        /* Once the divisor is bigger than the current dividend,
         * we can't fit any more copies of the divisor into it. */
        while (divisor >= dividend) {
            /* We know it'll fit at least once as divivend >= divisor.
             * Note: We use a negative powerOfTwo as it's possible we might have
             * the case divide(INT_MIN, -1). */
            int powerOfTwo = -1;
            int value = divisor;
            /* Check if double the current value is too big. If not, continue doubling.
             * If it is too big, stop doubling and continue with the next step */
            while (value >= HALF_INT_MIN && value + value >= dividend) {
                value += value;
                powerOfTwo += powerOfTwo;
            }
            // We have been able to subtract divisor another powerOfTwo times.
            quotient += powerOfTwo;
            // Remove value so far so that we can continue the process with remainder.
            dividend -= value;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let HALF_INT_MIN = -1073741824;
var divide = function (dividend, divisor) {
    // Special case: overflow.
    if (dividend === -2147483648 && divisor === -1) {
        return 2147483647;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    let negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    let quotient = 0;
    /* Once the divisor is bigger than the current dividend,
     * we can't fit any more copies of the divisor into it. */
    while (divisor >= dividend) {
        /* We know it'll fit at least once as divivend >= divisor.
         * Note: We use a negative powerOfTwo as it's possible we might have
         * the case divide(INT_MIN, -1). */
        let powerOfTwo = -1;
        let value = divisor;
        /* Check if double the current value is too big. If not, continue doubling.
         * If it is too big, stop doubling and continue with the next step */
        while (value >= HALF_INT_MIN && value + value >= dividend) {
            value += value;
            powerOfTwo += powerOfTwo;
        }
        // We have been able to subtract divisor another powerOfTwo times.
        quotient += powerOfTwo;
        // Remove value so far so that we can continue the process with remainder.
        dividend -= value;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    return negatives != 1 ? -quotient : quotient;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:

        # Constants.
        MAX_INT = 2147483647  # 2**31 - 1
        MIN_INT = -2147483648  # -2**31
        HALF_MIN_INT = -1073741824  # MIN_INT // 2

        # Special case: overflow.
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT

        # We need to convert both numbers to negatives.
        # Also, we count the number of negatives signs.
        negatives = 2
        if dividend > 0:
            negatives -= 1
            dividend = -dividend
        if divisor > 0:
            negatives -= 1
            divisor = -divisor

        quotient = 0
        # Once the divisor is bigger than the current dividend,
        # we can't fit any more copies of the divisor into it anymore */
        while divisor >= dividend:
            # We know it'll fit at least once as divivend >= divisor.
            # Note: We use a negative powerOfTwo as it's possible we might have
            # the case divide(INT_MIN, -1). */
            powerOfTwo = -1
            value = divisor
            # Check if double the current value is too big. If not, continue doubling.
            # If it is too big, stop doubling and continue with the next step */
            while value >= HALF_MIN_INT and value + value >= dividend:
                value += value
                powerOfTwo += powerOfTwo
            # We have been able to subtract divisor another powerOfTwo times.
            quotient += powerOfTwo
            # Remove value so far so that we can continue the process with remainder.
            dividend -= value

        # If there was originally one negative sign, then
        # the quotient remains negative. Otherwise, switch
        # it to positive.
        return -quotient if negatives != 1 else quotient
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
let HALF_INT_MIN = -1073741824;
function divide(dividend: number, divisor: number): number {
    // Special case: overflow.
    if (dividend === -2147483648 && divisor === -1) {
        return 2147483647;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    let negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    let quotient = 0;
    /* Once the divisor is bigger than the current dividend,
     * we can't fit any more copies of the divisor into it. */
    while (divisor >= dividend) {
        /* We know it'll fit at least once as divivend >= divisor.
         * Note: We use a negative powerOfTwo as it's possible we might have
         * the case divide(INT_MIN, -1). */
        let powerOfTwo = -1;
        let value = divisor;
        /* Check if double the current value is too big. If not, continue doubling.
         * If it is too big, stop doubling and continue with the next step */
        while (value >= HALF_INT_MIN && value + value >= dividend) {
            value += value;
            powerOfTwo += powerOfTwo;
        }
        // We have been able to subtract divisor another powerOfTwo times.
        quotient += powerOfTwo;
        // Remove value so far so that we can continue the process with remainder.
        dividend -= value;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    return negatives != 1 ? -quotient : quotient;
}
```

</details>

<br>

## Approach 3: Adding Powers of Two

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define HALF_INT_MIN -1073741824  // -2^30
int divide(int dividend, int divisor) {
    // Special case: overflow.
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    int negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    int doubles[32];
    int powersOfTwo[32];
    int powersCount = 0;
    /* Nothing too exciting here, we're just making a list of doubles of 1 and
     * the divisor. This is pretty much the same as Approach 2, except we're
     * actually storing the values this time. */
    int powerOfTwo = -1;
    while (divisor >= dividend) {
        doubles[powersCount] = divisor;
        powersOfTwo[powersCount] = powerOfTwo;
        powersCount++;
        // Prevent needless overflows from occurring...
        if (divisor < HALF_INT_MIN) {
            break;
        }
        divisor += divisor;
        powerOfTwo += powerOfTwo;
    }
    int quotient = 0;
    /* Go from largest double to smallest, checking if the current double fits.
     * into the remainder of the dividend. */
    for (int i = powersCount - 1; i >= 0; i--) {
        if (doubles[i] >= dividend) {
            // If it does fit, add the current powerOfTwo to the quotient.
            quotient += powersOfTwo[i];
            // Update dividend to take into account the bit we've now removed.
            dividend -= doubles[i];
        }
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) {
        return -quotient;
    }
    return quotient;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int HALF_INT_MIN = -1073741824;

public:
    int divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        std::vector<int> doubles;
        std::vector<int> powersOfTwo;

        /* Nothing too exciting here, we're just making a list of doubles of 1
         * and the divisor. This is pretty much the same as Approach 2, except
         * we're actually storing the values this time. */
        int powerOfTwo = -1;
        while (divisor >= dividend) {
            doubles.push_back(divisor);
            powersOfTwo.push_back(powerOfTwo);
            // Prevent needless overflows from occurring...
            if (divisor < HALF_INT_MIN) {
                break;
            }
            divisor += divisor;
            powerOfTwo += powerOfTwo;
        }

        int quotient = 0;
        /* Go from largest double to smallest, checking if the current double
         * fits. into the remainder of the dividend */
        for (int i = doubles.size() - 1; i >= 0; i--) {
            if (doubles[i] >= dividend) {
                // If it does fit, add the current powerOfTwo to the quotient.
                quotient += powersOfTwo[i];
                // Update dividend to take into account the bit we've now
                // removed.
                dividend -= doubles[i];
            }
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const int HALF_INT_MIN = -1073741824;  // -2**30;

    public int Divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == int.MinValue && divisor == -1) {
            return int.MaxValue;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }

        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        List<int> doubles = new List<int>();
        List<int> powersOfTwo = new List<int>();
        /* Nothing too exciting here, we're just making a list of doubles of 1
         * and the divisor. This is pretty much the same as Approach 2, except
         * we're actually storing the values this time. */
        int powerOfTwo = -1;
        while (divisor >= dividend) {
            doubles.Add(divisor);
            powersOfTwo.Add(powerOfTwo);
            // Prevent needless overflows from occurring...
            if (divisor < HALF_INT_MIN) {
                break;
            }

            divisor += divisor;
            powerOfTwo += powerOfTwo;
        }

        int quotient = 0;
        /* Go from largest double to smallest, checking if the current double
         * fits. into the remainder of the dividend. */
        for (int i = doubles.Count - 1; i >= 0; i--) {
            if (doubles[i] >= dividend) {
                // If it does fit, add the current powerOfTwo to the quotient.
                quotient += powersOfTwo[i];
                // Update dividend to take into account the bit we've now
                // removed.
                dividend -= doubles[i];
            }
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }

        return quotient;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func divide(dividend int, divisor int) int {
    const HalfIntMin = -1073741824
    // Special case: overflow.
    if dividend == -2147483648 && divisor == -1 {
        return 2147483647
    }
    // We need to convert both numbers to negatives.
    // Also, we count the number of negatives signs.
    negatives := int8(2)
    if dividend > 0 {
        negatives--
        dividend = -dividend
    }
    if divisor > 0 {
        negatives--
        divisor = -divisor
    }
    doubles := make([]int, 0, 32)
    powersOfTwo := make([]int, 0, 32)
    // Nothing too exciting here, we're just making a list of doubles of the divisor
    // and the corresponding power of 2
    powerOfTwo := 1
    for divisor >= dividend {
        doubles = append(doubles, divisor)
        powersOfTwo = append(powersOfTwo, powerOfTwo)
        // prevent needless overflow
        if divisor < HalfIntMin {
            break
        }
        divisor += divisor
        powerOfTwo += powerOfTwo
    }
    quotient := 0
    // Go from largest double to smallest, checking if the current double fits into the remainder of the dividend
    for i := len(doubles) - 1; i >= 0; i-- {
        if doubles[i] >= dividend {
            quotient += powersOfTwo[i]
            dividend -= doubles[i]
        }
    }
    // if there was originally one negative sign, then the quotient remains negative. Otherwise, switch it to positive
    if negatives == 1 {
        return -quotient
    }
    return quotient
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static int HALF_INT_MIN = -1073741824; // -2**30;

    public int divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        ArrayList<Integer> doubles = new ArrayList<>();
        ArrayList<Integer> powersOfTwo = new ArrayList<>();

        /* Nothing too exciting here, we're just making a list of doubles of 1 and
         * the divisor. This is pretty much the same as Approach 2, except we're
         * actually storing the values this time. */
        int powerOfTwo = -1;
        while (divisor >= dividend) {
            doubles.add(divisor);
            powersOfTwo.add(powerOfTwo);
            // Prevent needless overflows from occurring...
            if (divisor < HALF_INT_MIN) {
                break;
            }
            divisor += divisor;
            powerOfTwo += powerOfTwo;
        }

        int quotient = 0;
        /* Go from largest double to smallest, checking if the current double fits.
         * into the remainder of the dividend. */
        for (int i = doubles.size() - 1; i >= 0; i--) {
            if (doubles.get(i) >= dividend) {
                // If it does fit, add the current powerOfTwo to the quotient.
                quotient += powersOfTwo.get(i);
                // Update dividend to take into account the bit we've now removed.
                dividend -= doubles.get(i);
            }
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const HALF_INT_MIN = -1073741824; // -2**30;
var divide = function (dividend, divisor) {
    // Special case: overflow.
    if (dividend === -2147483648 && divisor === -1) {
        return 2147483647;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    let negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    let doubles = [];
    let powersOfTwo = [];
    /* Nothing too exciting here, we're just making a list of doubles of 1 and
     * the divisor. This is pretty much the same as Approach 2, except we're
     * actually storing the values this time. */
    let powerOfTwo = -1;
    while (divisor >= dividend) {
        doubles.push(divisor);
        powersOfTwo.push(powerOfTwo);
        // Prevent needless overflows from occurring...
        if (divisor < HALF_INT_MIN) {
            break;
        }
        divisor += divisor;
        powerOfTwo += powerOfTwo;
    }
    let quotient = 0;
    /* Go from largest double to smallest, checking if the current double fits.
     * into the remainder of the dividend. */
    for (let i = doubles.length - 1; i >= 0; i--) {
        if (doubles[i] >= dividend) {
            // If it does fit, add the current powerOfTwo to the quotient.
            quotient += powersOfTwo[i];
            // Update dividend to take into account the bit we've now removed.
            dividend -= doubles[i];
        }
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives !== 1) {
        return -quotient;
    }
    return quotient;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:

        # Constants.
        MAX_INT = 2147483647  # 2**31 - 1
        MIN_INT = -2147483648  # -2**31
        HALF_MIN_INT = -1073741824  # MIN_INT // 2

        # Special case: overflow.
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT

        # We need to convert both numbers to negatives.
        # Also, we count the number of negatives signs.
        negatives = 2
        if dividend > 0:
            negatives -= 1
            dividend = -dividend
        if divisor > 0:
            negatives -= 1
            divisor = -divisor

        doubles = []
        powersOfTwo = []

        # Nothing too exciting here, we're just making a list of doubles of 1 and
        # the divisor. This is pretty much the same as Approach 2, except we're
        # actually storing the values this time. */
        powerOfTwo = 1
        while divisor >= dividend:
            doubles.append(divisor)
            powersOfTwo.append(powerOfTwo)
            # Prevent needless overflows from occurring...
            if divisor < HALF_MIN_INT:
                break
            divisor += divisor  # Double divisor
            powerOfTwo += powerOfTwo

        # Go from largest double to smallest, checking if the current double fits.
        # into the remainder of the dividend.
        quotient = 0
        for i in reversed(range(len(doubles))):
            if doubles[i] >= dividend:
                # If it does fit, add the current powerOfTwo to the quotient.
                quotient += powersOfTwo[i]
                # Update dividend to take into account the bit we've now removed.
                dividend -= doubles[i]

        # If there was originally one negative sign, then
        # the quotient remains negative. Otherwise, switch
        # it to positive.
        return quotient if negatives != 1 else -quotient
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const HALF_INT_MIN: number = -1073741824; // -2**30;
var divide = function (dividend: number, divisor: number): number {
    // Special case: overflow.
    if (dividend === -2147483648 && divisor === -1) {
        return 2147483647;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    let negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    let doubles: number[] = [];
    let powersOfTwo: number[] = [];
    /* Nothing too exciting here, we're just making a list of doubles of 1 and
     * the divisor. This is pretty much the same as Approach 2, except we're
     * actually storing the values this time. */
    let powerOfTwo = -1;
    while (divisor >= dividend) {
        doubles.push(divisor);
        powersOfTwo.push(powerOfTwo);
        // Prevent needless overflows from occurring...
        if (divisor < HALF_INT_MIN) {
            break;
        }
        divisor += divisor;
        powerOfTwo += powerOfTwo;
    }
    let quotient = 0;
    /* Go from largest double to smallest, checking if the current double fits.
     * into the remainder of the dividend. */
    for (let i = doubles.length - 1; i >= 0; i--) {
        if (doubles[i] >= dividend) {
            // If it does fit, add the current powerOfTwo to the quotient.
            quotient += powersOfTwo[i];
            // Update dividend to take into account the bit we've now removed.
            dividend -= doubles[i];
        }
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives !== 1) {
        return -quotient;
    }
    return quotient;
};
```

</details>

<br>

## Approach 4: Adding Powers of Two with Bit-Shifting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define INT_MIN -2147483648
#define INT_MAX 2147483647
const int HALF_INT_MIN = -1073741824;
int divide(int dividend, int divisor) {
    // Special case: overflow.
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    int negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    /* In the first loop, we simply find the largest double of divisor
     * that fits into the dividend.
     * The >= is because we're working in negatives. In essence, that
     * piece of code is checking that we're still nearer to 0 than we
     * are to INT_MIN. */
    int highestDouble = divisor;
    int highestPowerOfTwo = -1;
    while (highestDouble >= HALF_INT_MIN &&
           dividend <= highestDouble + highestDouble) {
        highestPowerOfTwo += highestPowerOfTwo;
        highestDouble += highestDouble;
    }
    /* In the second loop, we work out which powers of two fit in, by
     * halving highestDouble and highestPowerOfTwo repeatedly.
     * We can do this using bit shifting so that we don't break the
     * rules of the question :-) */
    int quotient = 0;
    while (dividend <= divisor) {
        if (dividend <= highestDouble) {
            quotient += highestPowerOfTwo;
            dividend -= highestDouble;
        }
        /* We know that these are always even, so no need to worry about the
         * annoying "bit-shift-odd-negative-number" case. */
        highestPowerOfTwo >>= 1;
        highestDouble >>= 1;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) {
        return -quotient;
    }
    return quotient;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int HALF_INT_MIN = -1073741824;

public:
    int divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* In the first loop, we simply find the largest double of divisor. This
         * is very similar to the start of what we did in Approach 2. The >= is
         * because we're working in negatives. In essence, that piece of code is
         * checking that we're still nearer to 0 than we are to INT_MIN. */
        int highestDouble = divisor;
        int highestPowerOfTwo = -1;
        while (highestDouble >= HALF_INT_MIN &&
               dividend <= highestDouble + highestDouble) {
            highestPowerOfTwo += highestPowerOfTwo;
            highestDouble += highestDouble;
        }

        /* In the second loop, we work out which powers of two fit in, by
         * halving highestDouble and highestPowerOfTwo repeatedly.
         * We can do this using bit shifting so that we don't break the
         * rules of the question :-) */
        int quotient = 0;
        while (dividend <= divisor) {
            if (dividend <= highestDouble) {
                quotient += highestPowerOfTwo;
                dividend -= highestDouble;
            }
            /* We know that these are always even, so no need to worry about the
             * annoying "bit-shift-odd-negative-number" case. */
            highestPowerOfTwo >>= 1;
            highestDouble >>= 1;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int Divide(int dividend, int divisor) {
        const int INT_MIN = -2147483648;
        const int INT_MAX = 2147483647;
        const int HALF_INT_MIN = -1073741824;
        // Special case: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }

        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        int highestDouble = divisor;
        int highestPowerOfTwo = -1;
        while (highestDouble >= HALF_INT_MIN &&
               dividend <= highestDouble + highestDouble) {
            highestPowerOfTwo += highestPowerOfTwo;
            highestDouble += highestDouble;
        }

        int quotient = 0;
        while (dividend <= divisor) {
            if (dividend <= highestDouble) {
                quotient += highestPowerOfTwo;
                dividend -= highestDouble;
            }

            highestPowerOfTwo >>= 1;
            highestDouble >>= 1;
        }

        if (negatives != 1) {
            return -quotient;
        }

        return quotient;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func divide(dividend int, divisor int) int {
    const HALF_INT_MIN = -1073741824
    // Special case: overflow.
    if dividend == -2147483648 && divisor == -1 {
        return 2147483647
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    negatives := 2
    if dividend > 0 {
        negatives--
        dividend = -dividend
    }
    if divisor > 0 {
        negatives--
        divisor = -divisor
    }
    /* In the first loop, we simply find the largest double of divisor
     * that fits into the dividend.
     * The >= is because we're working in negatives. In essence, that
     * piece of code is checking that we're still nearer to 0 than we
     * are to INT_MIN. */
    highestDouble := divisor
    highestPowerOfTwo := -1
    for highestDouble >= HALF_INT_MIN && dividend <= highestDouble<<1 {
        highestPowerOfTwo <<= 1
        highestDouble <<= 1
    }
    /* In the second loop, we work out which powers of two fit in, by
     * halving highestDouble and highestPowerOfTwo repeatedly.
     * We can do this using bit shifting so that we don't break the
     * rules of the question :-) */
    quotient := 0
    for dividend <= divisor {
        if dividend <= highestDouble {
            quotient += highestPowerOfTwo
            dividend -= highestDouble
        }
        /* We know that these are always even, so no need to worry about the
         * annoying "bit-shift-odd-negative-number" case. */
        highestPowerOfTwo >>= 1
        highestDouble >>= 1
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if negatives != 1 {
        return -quotient
    }
    return quotient
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static int HALF_INT_MIN = -1073741824;

    public int divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* In the first loop, we simply find the largest double of divisor
         * that fits into the dividend.
         * The >= is because we're working in negatives. In essence, that
         * piece of code is checking that we're still nearer to 0 than we
         * are to INT_MIN. */
        int highestDouble = divisor;
        int highestPowerOfTwo = -1;
        while (
            highestDouble >= HALF_INT_MIN &&
            dividend <= highestDouble + highestDouble
        ) {
            highestPowerOfTwo += highestPowerOfTwo;
            highestDouble += highestDouble;
        }

        /* In the second loop, we work out which powers of two fit in, by
         * halving highestDouble and highestPowerOfTwo repeatedly.
         * We can do this using bit shifting so that we don't break the
         * rules of the question :-) */
        int quotient = 0;
        while (dividend <= divisor) {
            if (dividend <= highestDouble) {
                quotient += highestPowerOfTwo;
                dividend -= highestDouble;
            }
            /* We know that these are always even, so no need to worry about the
             * annoying "bit-shift-odd-negative-number" case. */
            highestPowerOfTwo >>= 1;
            highestDouble >>= 1;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var divide = function (dividend, divisor) {
    const HALF_INT_MIN = -1073741824;
    // Special case: overflow.
    if (dividend === -2147483648 && divisor === -1) {
        return 2147483647;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    let negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    /* In the first loop, we simply find the largest double of divisor
     * that fits into the dividend.
     * The >= is because we're working in negatives. In essence, that
     * piece of code is checking that we're still nearer to 0 than we
     * are to INT_MIN. */
    let highestDouble = divisor;
    let highestPowerOfTwo = -1;
    while (
        highestDouble >= HALF_INT_MIN &&
        dividend <= highestDouble + highestDouble
    ) {
        highestPowerOfTwo += highestPowerOfTwo;
        highestDouble += highestDouble;
    }
    /* In the second loop, we work out which powers of two fit in, by
     * halving highestDouble and highestPowerOfTwo repeatedly.
     * We can do this using bit shifting so that we don't break the
     * rules of the question :-) */
    let quotient = 0;
    while (dividend <= divisor) {
        if (dividend <= highestDouble) {
            quotient += highestPowerOfTwo;
            dividend -= highestDouble;
        }
        /* We know that these are always even, so no need to worry about the
         * annoying "bit-shift-odd-negative-number" case. */
        highestPowerOfTwo >>= 1;
        highestDouble >>= 1;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    return negatives != 1 ? -quotient : quotient;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:

        # Constants.
        MAX_INT = 2147483647  # 2**31 - 1
        MIN_INT = -2147483648  # -2**31
        HALF_MIN_INT = -1073741824  # MIN_INT // 2

        # Special case: overflow.
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT

        # We need to convert both numbers to negatives.
        # Also, we count the number of negatives signs.
        negatives = 2
        if dividend > 0:
            negatives -= 1
            dividend = -dividend
        if divisor > 0:
            negatives -= 1
            divisor = -divisor

        # In the first loop, we simply find the largest double of divisor
        # that fits into the dividend.
        # The >= is because we're working in negatives. In essence, that
        # piece of code is checking that we're still nearer to 0 than we
        # are to INT_MIN.
        highest_double = divisor
        highest_power_of_two = -1
        while (
            highest_double >= HALF_MIN_INT
            and dividend <= highest_double + highest_double
        ):
            highest_power_of_two += highest_power_of_two
            highest_double += highest_double

        # In the second loop, we work out which powers of two fit in, by
        # halving highest_double and highest_power_of_two repeatedly.
        # We can do this using bit shifting so that we don't break the
        # rules of the question :-)
        quotient = 0
        while dividend <= divisor:
            if dividend <= highest_double:
                quotient += highest_power_of_two
                dividend -= highest_double
            # We know that these are always even, so no need to worry about the
            # annoying "bit-shift-odd-negative-number" case.
            highest_power_of_two >>= 1
            highest_double >>= 1

        # If there was originally one negative sign, then
        # the quotient remains negative. Otherwise, switch
        # it to positive.
        return quotient if negatives == 1 else -quotient
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function divide(dividend: number, divisor: number): number {
    const HALF_INT_MIN = -1073741824;
    // Special case: overflow.
    if (dividend === -2147483648 && divisor === -1) {
        return 2147483647;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    let negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    /* In the first loop, we simply find the largest double of divisor
     * that fits into the dividend.
     * The >= is because we're working in negatives. In essence, that
     * piece of code is checking that we're still nearer to 0 than we
     * are to INT_MIN. */
    let highestDouble = divisor;
    let highestPowerOfTwo = -1;
    while (
        highestDouble >= HALF_INT_MIN &&
        dividend <= highestDouble + highestDouble
    ) {
        highestPowerOfTwo += highestPowerOfTwo;
        highestDouble += highestDouble;
    }
    /* In the second loop, we work out which powers of two fit in, by
     * halving highestDouble and highestPowerOfTwo repeatedly.
     * We can do this using bit shifting so that we don't break the
     * rules of the question :-) */
    let quotient = 0;
    while (dividend <= divisor) {
        if (dividend <= highestDouble) {
            quotient += highestPowerOfTwo;
            dividend -= highestDouble;
        }
        /* We know that these are always even, so no need to worry about the
         * annoying "bit-shift-odd-negative-number" case. */
        highestPowerOfTwo >>= 1;
        highestDouble >>= 1;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives !== 1) {
        return -quotient;
    }
    return quotient;
}
```

</details>

<br>

## Approach 5: Binary Long Division

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int HALF_INT_MIN = -1073741824;
int divide(int dividend, int divisor) {
    // Special cases: overflow.
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    if (dividend == INT_MIN && divisor == 1) {
        return INT_MIN;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    int negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    /* We want to find the largest doubling of the divisor in the negative
     * 32-bit integer range that could fit into the dividend. Note if it would
     * cause an overflow by being less than HALF_INT_MIN, then we just stop as
     * we know double it would not fit into INT_MIN anyway. */
    int maxBit = 0;
    while (divisor >= HALF_INT_MIN && divisor + divisor >= dividend) {
        maxBit += 1;
        divisor += divisor;
    }
    int quotient = 0;
    /* We start from the biggest bit and shift our divisor to the right
     * until we can't shift it any further */
    for (int bit = maxBit; bit >= 0; bit--) {
        /* If the divisor fits into the dividend, then we should set the current
         * bit to 1. We can do this by subtracting a 1 shifted by the
         * appropriate number of bits. */
        if (divisor >= dividend) {
            quotient -= (1 << bit);
            /* Remove the current divisor from the dividend, as we've now
             * considered this part. */
            dividend -= divisor;
        }
        /* Shift the divisor to the right so that it's in the right place
         * for the next position we're checking at. */
        divisor = (divisor + 1) >> 1;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) {
        quotient = -quotient;
    }
    return quotient;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int HALF_INT_MIN = -1073741824;

public:
    int divide(int dividend, int divisor) {
        // Special cases: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* We want to find the largest doubling of the divisor in the negative
         * 32-bit integer range that could fit into the dividend. Note if it
         * would cause an overflow by being less than HALF_INT_MIN, then we just
         * stop as we know double it would not fit into INT_MIN anyway. */
        int maxBit = 0;
        while (divisor >= HALF_INT_MIN && divisor + divisor >= dividend) {
            maxBit += 1;
            divisor += divisor;
        }

        int quotient = 0;
        /* We start from the biggest bit and shift our divisor to the right
         * until we can't shift it any further */
        for (int bit = maxBit; bit >= 0; bit--) {
            /* If the divisor fits into the dividend, then we should set the
             * current bit to 1. We can do this by subtracting a 1 shifted by
             * the appropriate number of bits. */
            if (divisor >= dividend) {
                quotient -= (1 << bit);
                /* Remove the current divisor from the dividend, as we've now
                 * considered this part. */
                dividend -= divisor;
            }
            /* Shift the divisor to the right so that it's in the right place
             * for the next positon we're checking at. */
            divisor = (divisor + 1) >> 1;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            quotient = -quotient;
        }
        return quotient;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private static int HALF_INT_MIN = -1073741824;

    public int Divide(int dividend, int divisor) {
        // Special cases: overflow.
        if (dividend == int.MinValue && divisor == -1) {
            return int.MaxValue;
        }

        if (dividend == int.MinValue && divisor == 1) {
            return int.MinValue;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }

        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* We want to find the largest doubling of the divisor in the negative
         * 32-bit integer range that could fit into the dividend. Note if it
         * would cause an overflow by being less than HALF_INT_MIN, then we just
         * stop as we know double it would not fit into INT_MIN anyway. */
        int maxBit = 0;
        while (divisor >= HALF_INT_MIN && divisor + divisor >= dividend) {
            maxBit += 1;
            divisor += divisor;
        }

        int quotient = 0;
        /* We start from the biggest bit and shift our divisor to the right
         * until we can't shift it any further */
        for (int bit = maxBit; bit >= 0; bit--) {
            /* If the divisor fits into the dividend, then we should set the
             * current bit to 1. We can do this by subtracting a 1 shifted by
             * the appropriate number of bits. */
            if (divisor >= dividend) {
                quotient -= (1 << bit);
                /* Remove the current divisor from the dividend, as we've now
                 * considered this part. */
                dividend -= divisor;
            }

            /* Shift the divisor to the right so that it's in the right place
             * for the next position we're checking at. */
            divisor = (divisor + 1) >> 1;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            quotient = -quotient;
        }

        return quotient;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func divide(dividend int, divisor int) int {
    HALF_INT_MIN := -1073741824
    // Special cases: overflow.
    if dividend == -2147483648 && divisor == -1 {
        return 2147483647
    }
    if dividend == -2147483648 && divisor == 1 {
        return -2147483648
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    negatives := 2
    if dividend > 0 {
        negatives--
        dividend = -dividend
    }
    if divisor > 0 {
        negatives--
        divisor = -divisor
    }
    /* We want to find the largest doubling of the divisor in the negative 32-bit
     * integer range that could fit into the dividend.
     * Note if it would cause an overflow by being less than HALF_INT_MIN,
     * then we just stop as we know double it would not fit into INT_MIN anyway. */
    maxBit := 0
    for divisor >= HALF_INT_MIN && divisor+divisor >= dividend {
        maxBit++
        divisor += divisor
    }
    quotient := 0
    for bit := maxBit; bit >= 0; bit-- {
        if divisor >= dividend {
            quotient -= 1 << uint(bit)
            dividend -= divisor
        }
        divisor = (divisor + 1) >> 1
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if negatives != 1 {
        quotient = -quotient
    }
    return quotient
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static int HALF_INT_MIN = -1073741824;

    public int divide(int dividend, int divisor) {
        // Special cases: overflow.
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        if (dividend == Integer.MIN_VALUE && divisor == 1) {
            return Integer.MIN_VALUE;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* We want to find the largest doubling of the divisor in the negative 32-bit
         * integer range that could fit into the dividend.
         * Note if it would cause an overflow by being less than HALF_INT_MIN,
         * then we just stop as we know double it would not fit into INT_MIN anyway. */
        int maxBit = 0;
        while (divisor >= HALF_INT_MIN && divisor + divisor >= dividend) {
            maxBit += 1;
            divisor += divisor;
        }

        int quotient = 0;
        /* We start from the biggest bit and shift our divisor to the right
         * until we can't shift it any further */
        for (int bit = maxBit; bit >= 0; bit--) {
            /* If the divisor fits into the dividend, then we should set the current
             * bit to 1. We can do this by subtracting a 1 shifted by the appropriate
             * number of bits. */
            if (divisor >= dividend) {
                quotient -= (1 << bit);
                /* Remove the current divisor from the dividend, as we've now
                 * considered this part. */
                dividend -= divisor;
            }
            /* Shift the divisor to the right so that it's in the right place
             * for the next positon we're checking at. */
            divisor = (divisor + 1) >> 1;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            quotient = -quotient;
        }
        return quotient;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var HALF_INT_MIN = -1073741824;
var divide = function (dividend, divisor) {
    // Special cases: overflow.
    if (dividend === -2147483648 && divisor === -1) {
        return 2147483647;
    }
    if (dividend === -2147483648 && divisor === 1) {
        return -2147483648;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    var negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    /* We want to find the largest doubling of the divisor in the negative 32-bit
     * integer range that could fit into the dividend.
     * Note if it would cause an overflow by being less than HALF_INT_MIN,
     * then we just stop as we know double it would not fit into INT_MIN anyway. */
    var maxBit = 0;
    while (divisor >= HALF_INT_MIN && divisor + divisor >= dividend) {
        maxBit += 1;
        divisor += divisor;
    }
    var quotient = 0;
    /* We start from the biggest bit and shift our divisor to the right
     * until we can't shift it any further */
    for (var bit = maxBit; bit >= 0; bit--) {
        /* If the divisor fits into the dividend, then we should set the current
         * bit to 1. We can do this by subtracting a 1 shifted by the appropriate
         * number of bits. */
        if (divisor >= dividend) {
            quotient -= 1 << bit;
            /* Remove the current divisor from the dividend, as we've now
             * considered this part. */
            dividend -= divisor;
        }
        /* Shift the divisor to the right so that it's in the right place
         * for the next positon we're checking at. */
        divisor = (divisor + 1) >> 1;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) {
        quotient = -quotient;
    }
    return quotient;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:

        # Constants.
        MAX_INT = 2147483647  # 2**31 - 1
        MIN_INT = -2147483648  # -2**31
        HALF_MIN_INT = -1073741824  # MIN_INT // 2

        # Special case: overflow.
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT

        # We need to convert both numbers to negatives.
        # Also, we count the number of negatives signs.
        negatives = 2
        if dividend > 0:
            negatives -= 1
            dividend = -dividend
        if divisor > 0:
            negatives -= 1
            divisor = -divisor

        # We want to find the largest doubling of the divisor in the negative 32-bit
        # integer range that could fit into the dividend.
        # Note if it would cause an overflow by being less than HALF_INT_MIN,
        # then we just stop as we know double it would not fit into INT_MIN anyway.
        max_bit = 0
        while divisor >= HALF_MIN_INT and divisor + divisor >= dividend:
            max_bit += 1
            divisor += divisor

        quotient = 0
        # We start from the biggest bit and shift our divisor to the right
        # until we can't shift it any further.
        for bit in range(max_bit, -1, -1):
            # If the divisor fits into the dividend, then we should set the current
            # bit to 1. We can do this by subtracting a 1 shifted by the appropriate
            # number of bits.
            if divisor >= dividend:
                quotient -= 1 << bit
                # Remove the current divisor from the dividend, as we've now
                # considered this part of it.
                dividend -= divisor
            # Shift the divisor to the right so that it's in the right place
            # for the next positon we're checking at.
            divisor = (divisor + 1) >> 1

        # If there was originally one negative sign, then
        # the quotient remains negative. Otherwise, switch
        # it to positive.
        return -quotient if negatives != 1 else quotient
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
let HALF_INT_MIN = -1073741824;
let divide = function (dividend: number, divisor: number): number {
    // Special cases: overflow.
    if (dividend === -2147483648 && divisor === -1) {
        return 2147483647;
    }
    if (dividend === -2147483648 && divisor === 1) {
        return -2147483648;
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    let negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    /* We want to find the largest doubling of the divisor in the negative 32-bit
     * integer range that could fit into the dividend.
     * Note if it would cause an overflow by being less than HALF_INT_MIN,
     * then we just stop as we know double it would not fit into INT_MIN anyway. */
    let maxBit = 0;
    while (divisor >= HALF_INT_MIN && divisor + divisor >= dividend) {
        maxBit += 1;
        divisor += divisor;
    }
    let quotient = 0;
    /* We start from the biggest bit and shift our divisor to the right
     * until we can't shift it any further */
    for (let bit = maxBit; bit >= 0; bit--) {
        /* If the divisor fits into the dividend, then we should set the current
         * bit to 1. We can do this by subtracting a 1 shifted by the appropriate
         * number of bits. */
        if (divisor >= dividend) {
            quotient -= 1 << bit;
            /* Remove the current divisor from the dividend, as we've now
             * considered this part. */
            dividend -= divisor;
        }
        /* Shift the divisor to the right so that it's in the right place
         * for the next positon we're checking at. */
        divisor = (divisor + 1) >> 1;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) {
        quotient = -quotient;
    }
    return quotient;
};
```

</details>
