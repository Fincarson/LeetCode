# 67. Add Binary

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/add-binary/)  
`Math` `String` `Bit Manipulation` `Simulation`

**Problem Link:** [LeetCode 67 - Add Binary](https://leetcode.com/problems/add-binary/)

## Problem

Given two binary strings a and b, return their sum as a binary string.

### Example 1

```text
Input: a = "11", b = "1"
Output: "100"
```

### Example 2

```text
Input: a = "1010", b = "1011"
Output: "10101"
```

## Constraints

- 1 <= a.length, b.length <= 104
- a and b consist only of '0' or '1' characters.
- Each string does not contain leading zeros except for the zero itself.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Plus One](https://leetcode.com/problems/plus-one/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 67. Add Binary

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Bit-by-Bit Computation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bit Manipulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Bit-by-Bit Computation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Function to reverse a string in place
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to add two binary strings
char *addBinary(const char *a, const char *b) {
    int n = strlen(a);
    int m = strlen(b);
    if (n < m) {
        // Ensure 'a' is always the longer string
        return addBinary(b, a);
    }

    // Allocate memory for the result
    char *result = malloc(n + 2);  // +2 for possible carry and null terminator
    if (!result) return NULL;

    int carry = 0, j = m - 1;
    int pos = 0;  // Position to place the next char in result

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == '1') ++carry;
        if (j >= 0 && b[j--] == '1') ++carry;

        result[pos++] =
            (carry % 2) ? '1' : '0';  // Append '1' or '0' based on carry
        carry /= 2;  // Reduce or maintain carry for the next bit addition
    }

    if (carry) {
        result[pos++] = '1';  // If there's still a carry, add a '1' at the end
    }
    result[pos] = '\0';  // Null-terminate the result string

    // Since we built the result in reverse order, reverse it before returning
    reverse(result);
    // Adjust the pointer to skip any extra leading zero
    if (result[0] == '0' && result[1] != '\0') {
        char *adjusted_result = strdup(result + 1);
        free(result);
        return adjusted_result;
    }

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        if (n < m)
            return addBinary(b, a);  // Ensure 'a' is always the longer string

        string result;
        int carry = 0, j = m - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == '1') ++carry;
            if (j >= 0 && b[j--] == '1') ++carry;

            result.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry == 1) result.push_back('1');  // Handle the last carry

        reverse(result.begin(),
                result.end());  // The result is built in reverse
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string AddBinary(string a, string b) {
        int n = a.Length, m = b.Length;
        if (n < m)
            return AddBinary(b, a);

        StringBuilder sb = new StringBuilder();
        int carry = 0, j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == '1')
                ++carry;
            if (j > -1 && b[j--] == '1')
                ++carry;

            sb.Append((carry % 2).ToString());
            carry /= 2;
        }

        if (carry == 1)
            sb.Append('1');
        char[] charArray = sb.ToString().ToCharArray();
        Array.Reverse(charArray);
        return new string(charArray);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func addBinary(a string, b string) string {
    n, m := len(a), len(b)
    if n < m {
        return addBinary(b, a)
    }

    var result strings.Builder
    carry, j := 0, m-1
    for i := n - 1; i >= 0; i-- {
        if a[i] == '1' {
            carry++
        }
        if j >= 0 && b[j] == '1' {
            carry++
        }
        j--
        result.WriteByte('0' + byte(carry%2))
        carry /= 2
    }
    if carry == 1 {
        result.WriteByte('1')
    }
    // Convert result to string and reverse it
    s := result.String()
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String addBinary(String a, String b) {
        int n = a.length(), m = b.length();
        if (n < m) return addBinary(b, a);

        StringBuilder sb = new StringBuilder();
        int carry = 0, j = m - 1;
        for (int i = n - 1; i > -1; --i) {
            if (a.charAt(i) == '1') ++carry;
            if (j > -1 && b.charAt(j--) == '1') ++carry;

            if (carry % 2 == 1) sb.append('1');
            else sb.append('0');

            carry /= 2;
        }
        if (carry == 1) sb.append('1');
        sb.reverse();

        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var addBinary = function (a, b) {
    let n = a.length,
        m = b.length;
    if (n < m) return addBinary(b, a);

    let result = [];
    let carry = 0,
        j = m - 1;
    for (let i = n - 1; i >= 0; --i) {
        if (a[i] === "1") ++carry;
        if (j >= 0 && b[j--] === "1") ++carry;

        result.push((carry % 2).toString());
        carry = Math.floor(carry / 2);
    }
    if (carry === 1) result.push("1");
    return result.reverse().join("");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addBinary(self, a, b) -> str:
        n = max(len(a), len(b))
        a, b = a.zfill(n), b.zfill(n)

        carry = 0
        answer = []
        for i in range(n - 1, -1, -1):
            if a[i] == "1":
                carry += 1
            if b[i] == "1":
                carry += 1

            if carry % 2 == 1:
                answer.append("1")
            else:
                answer.append("0")

            carry //= 2

        if carry == 1:
            answer.append("1")
        answer.reverse()

        return "".join(answer)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function addBinary(a: string, b: string): string {
    let n = a.length,
        m = b.length;
    if (n < m) return addBinary(b, a);

    let result: string[] = [];
    let carry = 0,
        j = m - 1;
    for (let i = n - 1; i >= 0; --i) {
        if (a[i] === "1") ++carry;
        if (j > -1 && b[j--] === "1") ++carry;

        result.push((carry % 2).toString());
        carry = Math.floor(carry / 2);
    }
    if (carry === 1) result.push("1");
    return result.reverse().join("");
}
```

</details>

<br>

## Approach 2: Bit Manipulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Helper function to reverse a string in place
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

// Adds two binary strings using bit manipulation and returns the result as a
// new binary string
char *addBinary(const char *a, const char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;

    // Allocate memory for the result which could be maxLen + 1 characters plus
    // a null terminator
    char *result = malloc(maxLen + 2);
    if (!result) return NULL;
    result[maxLen + 1] = '\0';

    // Reverse both strings for easier processing from least significant bit to
    // most
    char *x = strdup(a);
    char *y = strdup(b);
    if (!x || !y) {
        free(result);
        free(x);
        free(y);
        return NULL;
    }
    reverseString(x);
    reverseString(y);

    int carry = 0;
    for (int i = 0; i <= maxLen; i++) {
        int bitA = i < lenA ? x[i] - '0' : 0;
        int bitB = i < lenB ? y[i] - '0' : 0;

        // Bitwise XOR for current bit sum and AND shifted left for carry
        int sum = bitA ^ bitB ^ carry;
        carry = (bitA & bitB) | (carry & (bitA ^ bitB));

        result[i] = sum + '0';  // Convert sum back to character
    }

    if (carry) {  // If there's a final carry
        result[maxLen] = carry + '0';
    }

    // Reverse the result to return to the original order
    reverseString(result);

    // Trim any leading zero if the string has more than one character
    if (result[0] == '0' && result[1] != '\0') {
        memmove(result, result + 1, strlen(result));
    }

    free(x);
    free(y);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class BigInt {
private:
    string binary;

    // Helper function to ensure strings are the same length
    static void equalizeLength(string& a, string& b) {
        int lengthDifference = a.size() - b.size();
        if (lengthDifference > 0)
            b.insert(0, lengthDifference, '0');
        else
            a.insert(0, -lengthDifference, '0');
    }

    // Helper function to remove leading zeros
    void removeLeadingZeros() {
        // Erase leading zeros while keeping at least one zero if the number is
        // zero
        auto firstNonZero = binary.find_first_not_of('0');
        if (firstNonZero != string::npos) {
            binary.erase(0, firstNonZero);
        } else {
            binary =
                "0";  // Adjust to maintain a minimum representation of zero
        }
    }

public:
    BigInt() : binary("0") {}

    // Constructor from a binary string
    BigInt(const string& bin) : binary(bin) { removeLeadingZeros(); }

    // Bitwise XOR
    BigInt operator^(const BigInt& other) const {
        string a = binary;
        string b = other.binary;
        equalizeLength(a, b);
        string result;
        for (size_t i = 0; i < a.size(); i++) {
            char xorChar = (a[i] == b[i] ? '0' : '1');
            result.push_back(xorChar);
        }
        return BigInt(result);
    }

    // Bitwise AND
    BigInt operator&(const BigInt& other) const {
        string a = binary;
        string b = other.binary;
        equalizeLength(a, b);
        string result;
        for (size_t i = 0; i < a.size(); i++) {
            char andChar = (a[i] == '1' && b[i] == '1' ? '1' : '0');
            result.push_back(andChar);
        }
        return BigInt(result);
    }

    // Left shift
    BigInt operator<<(int shift) const {
        string result = binary;
        result.append(shift, '0');
        return BigInt(result);
    }

    // Check if BigInt is zero
    bool isZero() const {
        for (char c : binary)
            if (c != '0') return false;
        return true;
    }

    // Getter for binary string
    string getBinary() const { return binary; }
};

class Solution {
public:
    string addBinary(string a, string b) {
        BigInt x(a);
        BigInt y(b);
        BigInt carry, answer;

        while (!y.isZero()) {
            answer = x ^ y;
            carry = (x & y) << 1;
            x = answer;
            y = carry;
        }
        return x.getBinary();
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string AddBinary(string a, string b) {
        // Convert binary strings to BigInteger
        BigInteger x = ConvertBinaryToBigInteger(a);
        BigInteger y = ConvertBinaryToBigInteger(b);
        BigInteger zero = BigInteger.Zero;
        BigInteger carry;

        while (y != zero) {
            carry = (x & y) << 1;
            x ^= y;
            y = carry;
        }

        // Convert the final BigInteger back to a binary string properly
        return BigIntegerToBinaryString(x);
    }

    private BigInteger ConvertBinaryToBigInteger(string binary) {
        BigInteger result = 0;
        foreach (char c in binary) {
            result = result * 2 + (c - '0');
        }

        return result;
    }

    private string BigIntegerToBinaryString(BigInteger number) {
        if (number == 0)
            return "0";  // Edge case for zero
        var binary = "";
        while (number > 0) {
            binary = ((number & 1) == 1 ? "1" : "0") + binary;
            number >>= 1;
        }

        return binary;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Bit Manipulation is used to perform operations using bit wise XOR, AND and shift left.
func addBinary(a string, b string) string {
    var x, y, zero, carry, answer big.Int
    _, _ = x.SetString(a, 2)
    _, _ = y.SetString(b, 2)
    zero.SetInt64(0)
    for y.Cmp(&zero) != 0 {
        answer.Xor(&x, &y)
        carry.And(&x, &y)
        carry.Lsh(&carry, 1)
        x.Set(&answer)
        y.Set(&carry)
    }
    return x.Text(2)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.math.BigInteger;

class Solution {
    public String addBinary(String a, String b) {
        BigInteger x = new BigInteger(a, 2);
        BigInteger y = new BigInteger(b, 2);
        BigInteger zero = new BigInteger("0", 2);
        BigInteger carry, answer;
        while (y.compareTo(zero) != 0) {
            answer = x.xor(y);
            carry = x.and(y).shiftLeft(1);
            x = answer;
            y = carry;
        }
        return x.toString(2);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// Bit Manipulation is used to perform operations using bit wise XOR, AND and shift left.
var addBinary = function (a, b) {
    let x = BigInt(`0b${a}`);
    let y = BigInt(`0b${b}`);
    let zero = BigInt(0);
    while (y != zero) {
        let answer = x ^ y;
        let carry = (x & y) << BigInt(1);
        x = answer;
        y = carry;
    }
    return x.toString(2);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addBinary(self, a, b) -> str:
        x, y = int(a, 2), int(b, 2)
        while y:
            answer = x ^ y
            carry = (x & y) << 1
            x, y = answer, carry
        return bin(x)[2:]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// Bit Manipulation is used to perform operations using bit wise XOR, AND and shift left.
function addBinary(a: string, b: string): string {
    let x = BigInt(`0b${a}`);
    let y = BigInt(`0b${b}`);
    while (y) {
        let answer = x ^ y;
        let carry = (x & y) << BigInt(1);
        x = answer;
        y = carry;
    }
    return x.toString(2);
}
```

</details>
