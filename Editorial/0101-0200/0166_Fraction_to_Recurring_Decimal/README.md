# 166. Fraction to Recurring Decimal

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/fraction-to-recurring-decimal/)  
`Hash Table` `Math` `String`

**Problem Link:** [LeetCode 166 - Fraction to Recurring Decimal](https://leetcode.com/problems/fraction-to-recurring-decimal/)

## Problem

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

Note that if the fraction can be represented as a finite length string, you must return it.

### Example 1

```text
Input: numerator = 1, denominator = 2
Output: "0.5"
```

### Example 2

```text
Input: numerator = 2, denominator = 1
Output: "2"
```

### Example 3

```text
Input: numerator = 4, denominator = 333
Output: "0.(012)"
```

## Constraints

- -231 <= numerator, denominator <= 231 - 1
- denominator != 0

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 166. Fraction to Recurring Decimal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Long Division | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Long Division

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string fraction;
        // If either one is negative (not both)
        if (numerator < 0 ^ denominator < 0) {
            fraction.append("-");
        }
        // Convert to Long long to prevent overflow
        long long dividend = labs((long long)numerator);
        long long divisor = labs((long long)denominator);
        fraction.append(to_string(dividend / divisor));
        long long remainder = dividend % divisor;
        if (remainder == 0) {
            return fraction;
        }
        fraction.append(".");
        unordered_map<long long, int> map;
        while (remainder != 0) {
            if (map.find(remainder) != map.end()) {
                fraction.insert(map[remainder], "(");
                fraction.append(")");
                break;
            }
            map[remainder] = fraction.length();
            remainder *= 10;
            fraction.append(to_string(remainder / divisor));
            remainder %= divisor;
        }
        return fraction;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string FractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        StringBuilder fraction = new StringBuilder();
        // If either one is negative (not both)
        if (numerator < 0 ^ denominator < 0) {
            fraction.Append("-");
        }

        // Convert to Long or else abs(-2147483648) overflows
        long dividend = Math.Abs((long)numerator);
        long divisor = Math.Abs((long)denominator);
        fraction.Append(dividend / divisor);
        long remainder = dividend % divisor;
        if (remainder == 0) {
            return fraction.ToString();
        }

        fraction.Append(".");
        Dictionary<long, int> map = new Dictionary<long, int>();
        while (remainder != 0) {
            if (map.ContainsKey(remainder)) {
                fraction.Insert(map[remainder], "(");
                fraction.Append(")");
                break;
            }

            map[remainder] = fraction.Length;
            remainder *= 10;
            fraction.Append(remainder / divisor);
            remainder %= divisor;
        }

        return fraction.ToString();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func fractionToDecimal(numerator int, denominator int) string {
    if numerator == 0 {
        return "0"
    }
    var fraction []string
    // If either one is negative (not both)
    if (numerator < 0) != (denominator < 0) {
        fraction = append(fraction, "-")
    }
    // Convert to Long or else abs(-2147483648) overflows
    dividend := absInt(numerator)
    divisor := absInt(denominator)
    fraction = append(fraction, strconv.Itoa(dividend/divisor))
    remainder := dividend % divisor
    if remainder == 0 {
        return strings.Join(fraction, "")
    }
    fraction = append(fraction, ".")
    valMap := make(map[int]int)
    for remainder != 0 {
        if pos, ok := valMap[remainder]; ok {
            fraction = append(
                fraction[:pos],
                append([]string{"("}, append(fraction[pos:], ")")...)...)
            break
        }
        valMap[remainder] = len(fraction)
        remainder *= 10
        fraction = append(fraction, strconv.Itoa(remainder/divisor))
        remainder %= divisor
    }
    return strings.Join(fraction, "")
}

func absInt(val int) int {
    if val < 0 {
        return -val
    }
    return val
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        StringBuilder fraction = new StringBuilder();
        // If either one is negative (not both)
        if ((numerator < 0) ^ (denominator < 0)) {
            fraction.append("-");
        }
        // Convert to Long or else abs(-2147483648) overflows
        long dividend = Math.abs(Long.valueOf(numerator));
        long divisor = Math.abs(Long.valueOf(denominator));
        fraction.append(String.valueOf(dividend / divisor));
        long remainder = dividend % divisor;
        if (remainder == 0) {
            return fraction.toString();
        }
        fraction.append(".");
        Map<Long, Integer> map = new HashMap<>();
        while (remainder != 0) {
            if (map.containsKey(remainder)) {
                fraction.insert(map.get(remainder), "(");
                fraction.append(")");
                break;
            }
            map.put(remainder, fraction.length());
            remainder *= 10;
            fraction.append(String.valueOf(remainder / divisor));
            remainder %= divisor;
        }
        return fraction.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var fractionToDecimal = function (numerator, denominator) {
    if (numerator === 0) {
        return "0";
    }
    var fraction = [];
    // If either one is negative (not both)
    if ((numerator < 0) ^ (denominator < 0)) {
        fraction.push("-");
    }
    // Convert to Long or else abs(-2147483648) overflows
    var dividend = Math.abs(numerator);
    var divisor = Math.abs(denominator);
    fraction.push(Math.floor(dividend / divisor).toString());
    var remainder = dividend % divisor;
    if (remainder === 0) {
        return fraction.join("");
    }
    fraction.push(".");
    var map = {};
    while (remainder !== 0) {
        if (remainder in map) {
            fraction.splice(map[remainder], 0, "(");
            fraction.push(")");
            break;
        }
        map[remainder] = fraction.length;
        remainder *= 10;
        fraction.push(Math.floor(remainder / divisor).toString());
        remainder %= divisor;
    }
    return fraction.join("");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"

        fraction = []
        if (numerator < 0) != (denominator < 0):
            fraction.append("-")

        dividend = abs(numerator)
        divisor = abs(denominator)

        fraction.append(str(dividend // divisor))
        remainder = dividend % divisor
        if remainder == 0:
            return "".join(fraction)

        fraction.append(".")
        lookup = {}
        while remainder != 0:
            if remainder in lookup:
                fraction.insert(lookup[remainder], "(")
                fraction.append(")")
                break

            lookup[remainder] = len(fraction)
            remainder *= 10
            fraction.append(str(remainder // divisor))
            remainder %= divisor

        return "".join(fraction)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function fractionToDecimal(numerator: number, denominator: number): string {
    if (numerator === 0) {
        return "0";
    }
    var fraction = [];
    if (
        (numerator < 0 && denominator >= 0) ||
        (numerator >= 0 && denominator < 0)
    ) {
        fraction.push("-");
    }
    var dividend = Math.abs(numerator);
    var divisor = Math.abs(denominator);
    fraction.push(Math.floor(dividend / divisor).toString());
    var remainder = dividend % divisor;
    if (remainder === 0) {
        return fraction.join("");
    }
    fraction.push(".");
    var map = new Map<number, number>();
    while (remainder !== 0) {
        if (map.has(remainder)) {
            fraction.splice(map.get(remainder) as number, 0, "(");
            fraction.push(")");
            break;
        }
        map.set(remainder, fraction.length);
        remainder *= 10;
        fraction.push(Math.floor(remainder / divisor).toString());
        remainder %= divisor;
    }
    return fraction.join("");
}
```

</details>
