# 1680. Concatenation of Consecutive Binary Numbers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/)  
`Math` `Bit Manipulation` `Simulation`

**Problem Link:** [LeetCode 1680 - Concatenation of Consecutive Binary Numbers](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/)

## Problem

Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

### Example 1

```text
Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1.
```

### Example 2

```text
Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
```

### Example 3

```text
Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
```

## Constraints

- 1 <= n <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Possible Number by Binary Concatenation](https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1680. Concatenation of Consecutive Binary Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Change to Binary String | C++, Java, Python3 |

## Approach 1: Change to Binary String

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1000000007;
        long result = 0;
        for (int i = 1; i <= n; i++) {
            // use a int array to represent the binary
            int length = (int)log2(i) + 1;
            int binary[length];
            int temp = i;
            // keep divide 2 and put into the binary array
            for (int index = length - 1; index >= 0; index--) {
                binary[index] = (temp % 2 == 0 ? 0 : 1);
                temp /= 2;
            }
            // append the value to the result
            for (int j = 0; j < length; j++) {
                result = (result * 2 + binary[j]) % MOD;
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int concatenatedBinary(int n) {
        final int MOD = 1000000007;
        int result = 0;
        for (int i = 1; i <= n; i++) {
            String binary = Integer.toBinaryString(i);
            for (int j = 0; j < binary.length(); j++) {
                result = (result * 2 + (binary.charAt(j) - '0')) % MOD;
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = 10**9 + 7
        concatenation = "".join(bin(i)[2:] for i in range(n + 1))
        return int(concatenation, 2) % MOD
```

</details>
