# 172. Factorial Trailing Zeroes

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/factorial-trailing-zeroes/)  
`Math`

**Problem Link:** [LeetCode 172 - Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/)

## Problem

Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

### Example 1

```text
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
```

### Example 2

```text
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
```

### Example 3

```text
Input: n = 0
Output: 0
```

## Constraints

- 0 <= n <= 104

Follow up: Could you write a solution that works in logarithmic time complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Digit One](https://leetcode.com/problems/number-of-digit-one/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Preimage Size of Factorial Zeroes Function](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Abbreviating the Product of a Range](https://leetcode.com/problems/abbreviating-the-product-of-a-range/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Trailing Zeros in a Cornered Path](https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 172. Factorial Trailing Zeroes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Compute the Factorial | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Counting Factors of 5 | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Counting Factors of 5 Efficiently | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Compute the Factorial

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX_DIGITS 50000  // Adjust as needed based on expected factorial size

typedef struct {
    int digits[MAX_DIGITS];
    int size;
} BigInt;

// Initializes a BigInt from an integer
void BigInt_init(BigInt *bi, int value) {
    memset(bi->digits, 0, sizeof(bi->digits));
    bi->size = 0;
    if (value == 0) {
        bi->digits[0] = 0;
        bi->size = 1;
        return;
    }
    while (value > 0) {
        bi->digits[bi->size++] = value % 10;
        value /= 10;
    }
}

// Multiplies BigInt by an integer
void BigInt_multiply(BigInt *bi, int value) {
    int carry = 0;
    for (int i = 0; i < bi->size; i++) {
        int product = bi->digits[i] * value + carry;
        bi->digits[i] = product % 10;
        carry = product / 10;
    }
    while (carry > 0) {
        bi->digits[bi->size++] = carry % 10;
        carry /= 10;
    }
}

// Divides BigInt by 10 and returns the remainder
int BigInt_divide_by_10(BigInt *bi) {
    int remainder = 0;
    for (int i = bi->size - 1; i >= 0; i--) {
        int current = remainder * 10 + bi->digits[i];
        bi->digits[i] = current / 10;
        remainder = current % 10;
    }
    if (bi->size > 1 && bi->digits[bi->size - 1] == 0) {
        bi->size--;
    }
    return remainder;
}

int trailingZeroes(int n) {
    BigInt factorial;
    BigInt_init(&factorial, 1);
    for (int i = 2; i <= n; i++) {
        BigInt_multiply(&factorial, i);
    }

    int zeroCount = 0;
    while (BigInt_divide_by_10(&factorial) == 0) {
        zeroCount++;
    }
    return zeroCount;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class BigInt {
private:
    vector<int> digits;  // digits are stored in reverse order
    bool isNegative;

public:
    BigInt(long long num = 0) : isNegative(num < 0) {
        num = std::abs(num);
        if (num == 0) digits.push_back(0);
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    // Multiply this BigInt by an integer
    BigInt operator*(int num) const {
        if (num == 0) return BigInt(0);

        vector<int> result(digits.size() + 10, 0);
        int carry = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            long long product = long(digits[i]) * num + carry;
            result[i] = product % 10;
            carry = product / 10;
        }

        for (size_t i = digits.size(); carry != 0; ++i) {
            result[i] = carry % 10;
            carry /= 10;
        }

        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }

        BigInt output;
        output.digits = std::move(result);
        return output;
    }

    // Divide this BigInt by an integer and return the quotient
    BigInt operator/(int divisor) const {
        BigInt result;
        result.digits.clear();
        int idx = digits.size() - 1;
        int rem = 0;
        while (idx >= 0) {
            rem = rem * 10 + digits[idx--];
            if (rem < divisor && !result.digits.empty()) {
                result.digits.push_back(0);
            } else if (rem >= divisor) {
                result.digits.push_back(rem / divisor);
                rem %= divisor;
            }
        }

        std::reverse(result.digits.begin(), result.digits.end());
        if (result.digits.empty()) result.digits.push_back(0);
        return result;
    }

    // Modulo operation with an integer
    int operator%(int divisor) const {
        int remainder = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            remainder = (remainder * 10 + digits[i]) % divisor;
        }
        return remainder;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        BigInt factorial = 1;
        for (int i = 2; i <= n; ++i) {
            factorial = factorial * i;
        }

        int zeroCount = 0;
        while (factorial % 10 == 0) {
            factorial = factorial / 10;
            zeroCount++;
        }

        return zeroCount;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    public int TrailingZeroes(int n) {
        // Calculate n!
        BigInteger nFactorial = BigInteger.One;
        for (int i = 2; i <= n; i++) {
            nFactorial *= i;
        }

        // Count how many 0's are on the end.
        int zeroCount = 0;

        while (nFactorial % 10 == 0) {
            nFactorial /= 10;
            zeroCount++;
        }

        return zeroCount;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
import (
    "math/big"
)

func trailingZeroes(n int) int {
    // Calculate n!
    nFactorial := big.NewInt(1)
    for i := 2; i <= n; i++ {
        nFactorial.Mul(nFactorial, big.NewInt(int64(i)))
    }

    // Count how many 0's are on the end.
    zeroCount := 0
    ten := big.NewInt(10)
    zero := big.NewInt(0)

    // Temp variable to hold the result of the mod operation
    modResult := new(big.Int)

    for {
        modResult.Mod(nFactorial, ten)
        if modResult.Cmp(zero) == 0 {
            nFactorial.Div(nFactorial, ten)
            zeroCount++
        } else {
            break
        }
    }

    return zeroCount
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.math.BigInteger;

class Solution {
    public int trailingZeroes(int n) {
        // Calculate n!
        BigInteger nFactorial = BigInteger.ONE;
        for (int i = 2; i <= n; i++) {
            nFactorial = nFactorial.multiply(BigInteger.valueOf(i));
        }

        // Count how many 0's are on the end.
        int zeroCount = 0;

        while (nFactorial.mod(BigInteger.TEN).equals(BigInteger.ZERO)) {
            nFactorial = nFactorial.divide(BigInteger.TEN);
            zeroCount++;
        }

        return zeroCount;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var trailingZeroes = function (n) {
    let nFactorial = BigInt(1);
    for (let i = 2; i <= n; i++) {
        nFactorial *= BigInt(i);
    }

    let zeroCount = 0;
    const ten = BigInt(10);

    while (nFactorial % ten === BigInt(0)) {
        nFactorial /= ten;
        zeroCount++;
    }

    return zeroCount;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def trailingZeroes(self, n: int) -> int:

        # Calculate n!
        n_factorial = 1
        for i in range(2, n + 1):
            n_factorial *= i

        # Count how many 0's are on the end.
        zero_count = 0
        while n_factorial % 10 == 0:
            zero_count += 1
            n_factorial //= 10

        return zero_count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function trailingZeroes(n: number): number {
    let nFactorial = BigInt(1);
    for (let i = 2; i <= n; i++) {
        nFactorial *= BigInt(i);
    }

    let zeroCount = 0;
    const ten = BigInt(10);

    while (nFactorial % ten === BigInt(0)) {
        nFactorial /= ten;
        zeroCount++;
    }

    return zeroCount;
}
```

</details>

<br>

## Approach 2: Counting Factors of 5

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int trailingZeroes(int n) {
    // Initialize zero count
    int zeroCount = 0;
    // Start from 5 until n with an increment of 5 at each iteration
    for (int i = 5; i <= n; i += 5) {
        // Set current factor as i at each iteration
        int currentFactor = i;
        // Until the current factor is divisible by 5, keep incrementing the
        // zero count
        while (currentFactor % 5 == 0) {
            zeroCount++;
            currentFactor /= 5;
        }
    }

    return zeroCount;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        // Initialize zero count
        int zeroCount = 0;
        // Start from 5 until n with an increment of 5 at each iteration
        for (int i = 5; i <= n; i += 5) {
            // Set current factor as i at each iteration
            int currentFactor = i;
            // Until the current factor is divisible by 5, keep incrementing the
            // zero count
            while (currentFactor % 5 == 0) {
                zeroCount++;
                currentFactor /= 5;
            }
        }
        return zeroCount;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int TrailingZeroes(int n) {
        // Initialize zero count
        int zeroCount = 0;
        // Start from 5 until n with an increment of 5 at each iteration
        for (int i = 5; i <= n; i += 5) {
            // Set current factor as i at each iteration
            int currentFactor = i;
            // Until the current factor is divisible by 5, keep incrementing the zero count
            while (currentFactor % 5 == 0) {
                zeroCount++;
                currentFactor /= 5;
            }
        }

        return zeroCount;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func trailingZeroes(n int) int {
    // Initialize zero count
    zeroCount := 0
    // Start from 5 until n with an increment of 5 at each iteration
    for i := 5; i <= n; i += 5 {
        // Set current factor as i at each iteration
        currentFactor := i
        // Until the current factor is divisible by 5, keep incrementing the zero count
        for currentFactor%5 == 0 {
            zeroCount++
            currentFactor /= 5
        }
    }

    return zeroCount
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int trailingZeroes(int n) {
        int zeroCount = 0;
        for (int i = 5; i <= n; i += 5) {
            int currentFactor = i;
            while (currentFactor % 5 == 0) {
                zeroCount++;
                currentFactor /= 5;
            }
        }
        return zeroCount;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var trailingZeroes = function (n) {
    // Initialize zero count
    let zeroCount = 0;
    // Start from 5 until n with an increment of 5 at each iteration
    for (let i = 5; i <= n; i += 5) {
        // Set current factor as i at each iteration
        let currentFactor = i;
        // Until the current factor is divisible by 5, keep incrementing the zero count
        while (currentFactor % 5 == 0) {
            zeroCount++;
            currentFactor /= 5;
        }
    }

    return zeroCount;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def trailingZeroes(self, n: int) -> int:

        zero_count = 0
        for i in range(5, n + 1, 5):
            current = i
            while current % 5 == 0:
                zero_count += 1
                current //= 5

        return zero_count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function trailingZeroes(n: number): number {
    // Initialize zero count
    let zeroCount = 0;
    // Start from 5 until n with an increment of 5 at each iteration
    for (let i = 5; i <= n; i += 5) {
        // Set current factor as i at each iteration
        let currentFactor = i;
        // Until the current factor is divisible by 5, keep incrementing the zero count
        while (currentFactor % 5 == 0) {
            zeroCount++;
            currentFactor /= 5;
        }
    }

    return zeroCount;
}
```

</details>

<br>

## Approach 3: Counting Factors of 5 Efficiently

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int trailingZeroes(int n) {
    int zeroCount = 0;
    long currentMultiple = 5;
    while (n >= currentMultiple) {
        zeroCount += (n / currentMultiple);
        currentMultiple *= 5;
    }
    return zeroCount;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int zeroCount = 0;
        long long currentMultiple = 5;
        while (n >= currentMultiple) {
            zeroCount += (n / currentMultiple);
            currentMultiple *= 5;
        }
        return zeroCount;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int TrailingZeroes(int n) {
        int zeroCount = 0;
        long currentMultiple = 5;
        while (n >= currentMultiple) {
            zeroCount += (int)(n / currentMultiple);
            currentMultiple *= 5;
        }

        return zeroCount;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func trailingZeroes(n int) int {
    zeroCount := 0
    currentMultiple := 5
    for n >= currentMultiple {
        zeroCount += n / currentMultiple
        currentMultiple *= 5
    }
    return zeroCount
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int trailingZeroes(int n) {
        int zeroCount = 0;
        // We need to use long because currentMultiple can potentially become
        // larger than an int.
        long currentMultiple = 5;
        while (n >= currentMultiple) {
            zeroCount += (n / currentMultiple);
            currentMultiple *= 5;
        }
        return zeroCount;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var trailingZeroes = function (n) {
    let zeroCount = 0;
    let currentMultiple = 5;
    while (n >= currentMultiple) {
        zeroCount += Math.floor(n / currentMultiple);
        currentMultiple *= 5;
    }
    return zeroCount;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def trailingZeroes(self, n: int) -> int:
        zero_count = 0
        current_multiple = 5
        while n >= current_multiple:
            zero_count += n // current_multiple
            current_multiple *= 5
        return zero_count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function trailingZeroes(n: number): number {
    let zeroCount = 0;
    let currentMultiple = 5;
    while (n >= currentMultiple) {
        zeroCount += Math.floor(n / currentMultiple);
        currentMultiple *= 5;
    }
    return zeroCount;
}
```

</details>
