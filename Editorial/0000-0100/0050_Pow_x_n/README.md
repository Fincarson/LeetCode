# 50. Pow(x, n)

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/powx-n/)  
`Math` `Recursion`

**Problem Link:** [LeetCode 50 - Pow(x, n)](https://leetcode.com/problems/powx-n/)

## Problem

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

### Example 1

```text
Input: x = 2.00000, n = 10
Output: 1024.00000
```

### Example 2

```text
Input: x = 2.10000, n = 3
Output: 9.26100
```

### Example 3

```text
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

## Constraints

- -100.0 < x < 100.0
- -231 <= n <= 231-1
- n is an integer.
- Either x is not zero or n > 0.
- -104 <= xn <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Super Pow](https://leetcode.com/problems/super-pow/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Collisions of Monkeys on a Polygon](https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 50. Pow(x, n)

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Exponentiation (Recursive) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary Exponentiation (Iterative) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Binary Exponentiation (Recursive)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
double binaryExp(double x, long long n) {
    // Base case, to stop recursive calls.
    if (n == 0) {
        return 1;
    }
    // Handle case where, n < 0.
    if (n < 0) {
        return 1.0 / binaryExp(x, -1 * n);
    }
    // Perform Binary Exponentiation.
    // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and multiply
    // result with 'x'.
    if (n % 2 == 1) {
        return x * binaryExp(x * x, (n - 1) / 2);
    }
    // Otherwise we calculate result by performing Binary Exponentiation on 'n'.
    else {
        return binaryExp(x * x, n / 2);
    }
}
double myPow(double x, int n) {
    // Call recursive function with correct types.
    return binaryExp(x, (long long)n);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double binaryExp(double x, long long n) {
        // Base case, to stop recursive calls.
        if (n == 0) {
            return 1;
        }
       
        // Handle case where, n < 0.
        if (n < 0) {
            return 1.0 / binaryExp(x, -1 * n);
        }
       
        // Perform Binary Exponentiation.
        // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and multiply result with 'x'.
        if (n % 2 == 1) {
            return x * binaryExp(x * x, (n - 1) / 2);
        }
        // Otherwise we calculate result by performing Binary Exponentiation on 'n'.
        else {
            return binaryExp(x * x, n / 2);
        }
    }

    double myPow(double x, int n) {
        return binaryExp(x, (long long) n);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private double BinaryExp(double x, long n) {
        // Base case, to stop recursive calls.
        if (n == 0) {
            return 1;
        }

        // Handle case where, n < 0.
        if (n < 0) {
            return 1.0 / BinaryExp(x, -1 * n);
        }

        // Perform Binary Exponentiation.
        // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and
        // multiply result with 'x'.
        if (n % 2 == 1) {
            return x * BinaryExp(x * x, (n - 1) / 2);
        }
        // Otherwise we calculate result by performing Binary Exponentiation on
        // 'n'.
        else {
            return BinaryExp(x * x, n / 2);
        }
    }

    public double MyPow(double x, int n) {
        // Call recursive function with correct types.
        return BinaryExp(x, (long)n);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func binaryExp(x float64, n int64) float64 {
    // Base case, to stop recursive calls.
    if n == 0 {
        return 1
    }
    // Handle case where, n < 0.
    if n < 0 {
        return 1 / binaryExp(x, -1*n)
    }
    // Perform Binary Exponentiation.
    // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and multiply result with 'x'.
    if n%2 == 1 {
        return x * binaryExp(x*x, (n-1)/2)
    }
    // Otherwise we calculate result by performing Binary Exponentiation on 'n'.
    return binaryExp(x*x, n/2)
}

func myPow(x float64, n int) float64 {
    return binaryExp(x, int64(n))
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private double binaryExp(double x, long n) {
        // Base case, to stop recursive calls.
        if (n == 0) {
            return 1;
        }

        // Handle case where, n < 0.
        if (n < 0) {
            return 1.0 / binaryExp(x, -1 * n);
        }

        // Perform Binary Exponentiation.
        // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and multiply result with 'x'.
        if (n % 2 == 1) {
            return x * binaryExp(x * x, (n - 1) / 2);
        }
        // Otherwise we calculate result by performing Binary Exponentiation on 'n'.
        else {
            return binaryExp(x * x, n / 2);
        }
    }

    public double myPow(double x, int n) {
        return binaryExp(x, (long) n);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function binaryExp(x, n) {
    // Base case, to stop recursive calls.
    if (n === 0) {
        return 1;
    }

    // Handle case where, n < 0.
    if (n < 0) {
        return 1 / binaryExp(x, -1 * n);
    }

    // Perform Binary Exponentiation.
    // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and multiply result with 'x'.
    if (n % 2 === 1) {
        return x * binaryExp(x * x, (n - 1) / 2);
    }
    // Otherwise we calculate result by performing Binary Exponentiation on 'n'.
    else {
        return binaryExp(x * x, n / 2);
    }
}

var myPow = function (x, n) {
    return binaryExp(x, n);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def binaryExp(self, x: float, n: int) -> float:
        # Base case, to stop recursive calls.
        if n == 0:
            return 1

        # Handle case where, n < 0.
        if n < 0:
            return 1.0 / self.binaryExp(x, -1 * n)

        # Perform Binary Exponentiation.
        # If 'n' is odd we perform Binary Exponentiation on 'n - 1' and multiply result with 'x'.
        if n % 2 == 1:
            return x * self.binaryExp(x * x, (n - 1) // 2)
        # Otherwise we calculate result by performing Binary Exponentiation on 'n'.
        else:
            return self.binaryExp(x * x, n // 2)

    def myPow(self, x: float, n: int) -> float:
        return self.binaryExp(x, n)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function binaryExp(x: number, n: number): number {
    // Base case, to stop recursive calls.
    if (n === 0) {
        return 1;
    }
    // Handle case where, n < 0.
    if (n < 0) {
        return 1 / binaryExp(x, -1 * n);
    }
    // Perform Binary Exponentiation.
    // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and multiply result with 'x'.
    if (n % 2 === 1) {
        return x * binaryExp(x * x, (n - 1) / 2);
    }
    // Otherwise we calculate result by performing Binary Exponentiation on 'n'.
    else {
        return binaryExp(x * x, n / 2);
    }
}
function myPow(x: number, n: number): number {
    return binaryExp(x, n);
}
```

</details>

<br>

## Approach 2: Binary Exponentiation (Iterative)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
double binaryExp(double x, long n) {
    if (n == 0) return 1.0;
    // Handle case where, n < 0
    if (n < 0) {
        n = -n;
        x = 1.0 / x;
    }
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
            n--;
        }
        // We square x and reduce n by half, x^n => (x^2)^(n/2)
        x = x * x;
        n = n / 2;
    }
    return result;
}
double myPow(double x, int n) { return binaryExp(x, (long)n); }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double binaryExp(double x, long long n) {
        if (n == 0) {
            return 1;
        }

        // Handle case where, n < 0.
        if (n < 0) {
            n = -1 * n;
            x = 1.0 / x;
        }

        // Perform Binary Exponentiation.
        double result = 1;
        while (n) {
            // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
            if (n % 2 == 1) {
                result = result * x;
                n -= 1;
            }
            // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
            x = x * x;
            n = n / 2;
        }
        return result;
    }

    double myPow(double x, int n) { return binaryExp(x, (long long)n); }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private double BinaryExp(double x, long n) {
        if (n == 0) {
            return 1;
        }

        // Handle case where, n < 0.
        if (n < 0) {
            n = -1 * n;
            x = 1.0 / x;
        }

        // Perform Binary Exponentiation.
        double result = 1;
        while (n != 0) {
            // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
            if (n % 2 == 1) {
                result *= x;
                n -= 1;
            }

            // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
            x *= x;
            n /= 2;
        }

        return result;
    }

    public double MyPow(double x, int n) {
        return BinaryExp(x, (long)n);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func binaryExp(x float64, n int) float64 {
    if n == 0 {
        return 1
    }
    // Handle case where, n < 0.
    if n < 0 {
        n = -1 * n
        x = 1.0 / x
    }
    // Perform Binary Exponentiation.
    var result float64 = 1
    for n != 0 {
        // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
        if n%2 == 1 {
            result = result * x
            n -= 1
        }
        // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
        x = x * x
        n = n / 2
    }
    return result
}

func myPow(x float64, n int) float64 {
    return binaryExp(x, n)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private double binaryExp(double x, long n) {
        if (n == 0) {
            return 1;
        }

        // Handle case where, n < 0.
        if (n < 0) {
            n = -1 * n;
            x = 1.0 / x;
        }

        // Perform Binary Exponentiation.
        double result = 1;
        while (n != 0) {
            // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
            if (n % 2 == 1) {
                result = result * x;
                n -= 1;
            }
            // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
            x = x * x;
            n = n / 2;
        }
        return result;
    }

    public double myPow(double x, int n) {
        return binaryExp(x, (long) n);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function binaryExp(x, n) {
    if (n === 0) {
        return 1;
    }

    // Handle case where, n < 0.
    if (n < 0) {
        n = -1 * n;
        x = 1.0 / x;
    }

    // Perform Binary Exponentiation.
    let result = 1;
    while (n !== 0) {
        // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
        if (n % 2 === 1) {
            result *= x;
            n -= 1;
        }
        // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
        x *= x;
        n = Math.floor(n / 2);
    }
    return result;
}

var myPow = function (x, n) {
    return binaryExp(x, n);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def binaryExp(self, x: float, n: int) -> float:
        if n == 0:
            return 1

        # Handle case where, n < 0.
        if n < 0:
            n = -1 * n
            x = 1.0 / x

        # Perform Binary Exponentiation.
        result = 1
        while n != 0:
            # If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
            if n % 2 == 1:
                result *= x
                n -= 1
            # We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
            x *= x
            n //= 2
        return result

    def myPow(self, x: float, n: int) -> float:
        return self.binaryExp(x, n)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function binaryExp(x: number, n: number): number {
    if (n === 0) {
        return 1;
    }
    // Handle case where, n < 0.
    if (n < 0) {
        n = -1 * n;
        x = 1.0 / x;
    }
    // Perform Binary Exponentiation.
    let result = 1;
    while (n !== 0) {
        // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
        if (n % 2 === 1) {
            result *= x;
            n -= 1;
        }
        // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
        x *= x;
        n = Math.floor(n / 2);
    }
    return result;
}
function myPow(x: number, n: number): number {
    return binaryExp(x, n);
}
```

</details>
