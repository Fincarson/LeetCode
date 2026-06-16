# 2429. Minimize XOR

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimize-xor/)  
`Greedy` `Bit Manipulation`

**Problem Link:** [LeetCode 2429 - Minimize XOR](https://leetcode.com/problems/minimize-xor/)

## Problem

Given two positive integers num1 and num2, find the positive integer x such that:

- x has the same number of set bits as num2, and
- The value x XOR num1 is minimal.

Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

### Example 1

```text
Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
```

### Example 2

```text
Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
```

## Constraints

- 1 <= num1, num2 <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum XOR With an Element From Array](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2429. Minimize XOR

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| From Optimal to Valid | C++, Java, Python3 |
| Building the Answer | C++, Java, Python3 |

## Approach 1: From Optimal to Valid

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Initialize result to num1. We will modify result.
        int result = num1;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = __builtin_popcount(result);

        // Start with the least significant bit (bit 0).
        int currentBit = 0;

        // Add bits to result if it has fewer set bits than the target.
        while (setBitsCount < targetSetBitsCount) {
            // If the current bit in result is not set (0), set it to 1.
            if (!isSet(result, currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }
            // Move to the next bit.
            currentBit++;
        }

        // Remove bits from result if it has more set bits than the target.
        while (setBitsCount > targetSetBitsCount) {
            // If the current bit in result is set (1), unset it (make it 0).
            if (isSet(result, currentBit)) {
                unsetBit(result, currentBit);
                setBitsCount--;
            }
            // Move to the next bit.
            currentBit++;
        }

        return result;
    }

private:
    // Helper function to check if the given bit position in x is set (1).
    bool isSet(int x, int bit) { return x & (1 << bit); }

    // Helper function to set the given bit position in x to 1.
    void setBit(int &x, int bit) { x |= (1 << bit); }

    // Helper function to unset the given bit position in x (set it to 0).
    void unsetBit(int &x, int bit) { x &= ~(1 << bit); }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimizeXor(int num1, int num2) {
        // Initialize result to num1. We will modify result.
        int result = num1;

        int targetSetBitsCount = Integer.bitCount(num2);
        int setBitsCount = Integer.bitCount(result);

        // Start with the least significant bit (bit 0).
        int currentBit = 0;

        // Add bits to result if it has fewer set bits than the target.
        while (setBitsCount < targetSetBitsCount) {
            // If the current bit in result is not set (0), set it to 1.
            if (!isSet(result, currentBit)) {
                result = setBit(result, currentBit);
                setBitsCount++;
            }
            // Move to the next bit.
            currentBit++;
        }

        // Remove bits from result if it has more set bits than the target.
        while (setBitsCount > targetSetBitsCount) {
            // If the current bit in result is set (1), unset it (make it 0).
            if (isSet(result, currentBit)) {
                result = unsetBit(result, currentBit);
                setBitsCount--;
            }
            // Move to the next bit.
            currentBit++;
        }

        return result;
    }

    // Helper function to check if the given bit position in result is set (1).
    private boolean isSet(int x, int bit) {
        return (x & (1 << bit)) != 0;
    }

    // Helper function to set the given bit position in result to 1.
    private int setBit(int x, int bit) {
        return x | (1 << bit);
    }

    // Helper function to unset the given bit position in x (set it to 0).
    private int unsetBit(int x, int bit) {
        return x & ~(1 << bit);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        # Initialize result to num1. We will modify result.
        result = num1

        target_set_bits_count = bin(num2).count("1")
        set_bits_count = bin(result).count("1")

        # Start with the least significant bit (bit 0).
        current_bit = 0

        # Add bits to result if it has fewer set bits than the target.
        while set_bits_count < target_set_bits_count:
            # If the current bit in result is not set (0), set it to 1.
            if not self._is_set(result, current_bit):
                result = self._set_bit(result, current_bit)
                set_bits_count += 1
            # Move to the next bit.
            current_bit += 1

        # Remove bits from result if it has more set bits than the target.
        while set_bits_count > target_set_bits_count:
            # If the current bit in result is set (1), unset it (make it 0).
            if self._is_set(result, current_bit):
                result = self._unset_bit(result, current_bit)
                set_bits_count -= 1
            # Move to the next bit.
            current_bit += 1

        return result

    # Helper function to check if the given bit position in result is set (1).
    def _is_set(self, x: int, bit: int) -> bool:
        return (x & (1 << bit)) != 0

    # Helper function to set the given bit position in result to 1.
    def _set_bit(self, x: int, bit: int):
        return x | (1 << bit)

    # Helper function to unset the given bit position in x (set it to 0).
    def _unset_bit(self, x: int, bit: int):
        return x & ~(1 << bit)
```

</details>

<br>

## Approach 2: Building the Answer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int result = 0;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = 0;
        int currentBit = 31;  // Start from the most significant bit.

        // While x has fewer set bits than num2
        while (setBitsCount < targetSetBitsCount) {
            // If the current bit of num1 is set or we must set all remaining
            // bits in result
            if (isSet(num1, currentBit) ||
                (targetSetBitsCount - setBitsCount > currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }
            currentBit--;  // Move to the next bit.
        }

        return result;
    }

private:
    // Helper function to check if the given bit position in x is set (1).
    bool isSet(int x, int bit) { return x & (1 << bit); }

    // Helper function to set the given bit position in x to 1.
    void setBit(int &x, int bit) { x |= (1 << bit); }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int minimizeXor(int num1, int num2) {
        int result = 0;

        int targetSetBitsCount = Integer.bitCount(num2);
        int setBitsCount = 0;
        int currentBit = 31; // Start from the most significant bit.

        // While x has fewer set bits than num2
        while (setBitsCount < targetSetBitsCount) {
            // If the current bit of num1 is set or we must set all remaining bits in result
            if (
                isSet(num1, currentBit) ||
                (targetSetBitsCount - setBitsCount > currentBit)
            ) {
                result = setBit(result, currentBit);
                setBitsCount++;
            }
            currentBit--; // Move to the next bit.
        }

        return result;
    }

    // Helper function to check if the given bit position in x is set (1).
    private boolean isSet(int x, int bit) {
        return (x & (1 << bit)) != 0;
    }

    // Helper function to set the given bit position in x to 1.
    private int setBit(int x, int bit) {
        return x | (1 << bit);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        result = 0

        target_set_bits_count = bin(num2).count("1")
        set_bits_count = 0
        current_bit = 31  # Start from the most significant bit.

        # While result has fewer set bits than num2
        while set_bits_count < target_set_bits_count:
            # If the current bit of num1 is set or we must set all remaining bits in result
            if self._is_set(num1, current_bit) or (
                target_set_bits_count - set_bits_count > current_bit
            ):
                result = self._set_bit(result, current_bit)
                set_bits_count += 1
            current_bit -= 1  # Move to the next bit.

        return result

    # Helper function to check if the given bit position in x is set (1).
    def _is_set(self, x: int, bit: int) -> bool:
        return (x & (1 << bit)) != 0

    # Helper function to set the given bit position in x to 1.
    def _set_bit(self, x: int, bit: int):
        return x | (1 << bit)
```

</details>
