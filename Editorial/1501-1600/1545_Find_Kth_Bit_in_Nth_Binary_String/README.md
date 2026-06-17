# 1545. Find Kth Bit in Nth Binary String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/)  
`String` `Recursion` `Simulation`

**Problem Link:** [LeetCode 1545 - Find Kth Bit in Nth Binary String](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/)

## Problem

Given two positive integers n and k, the binary string Sn is formed as follows:

- S1 = "0"
- Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1

Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

- S1 = "0"
- S2 = "011"
- S3 = "0111001"
- S4 = "011100110110001"

Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

### Example 1

```text
Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".
```

### Example 2

```text
Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".
```

## Constraints

- 1 <= n <= 20
- 1 <= k <= 2n - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1545. Find Kth Bit in Nth Binary String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Recursion | C++, Java, Python3 |
| Iterative Divide and Conquer | C++, Java, Python3 |
| Bit Manipulation | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        string sequence = "0";

        // Generate sequence until we have enough elements or reach nth
        // iteration
        for (int i = 1; i < n && k > sequence.length(); ++i) {
            sequence += '1';

            // Append the inverted and reversed part of the existing sequence
            string temp = sequence;
            for (int j = temp.length() - 2; j >= 0; --j) {
                char invertedBit = (temp[j] == '1') ? '0' : '1';
                sequence += invertedBit;
            }
        }

        // Return the kth bit
        return sequence[k - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char findKthBit(int n, int k) {
        StringBuilder sequence = new StringBuilder("0");

        // Generate sequence until we have enough elements or reach nth iteration
        for (int i = 1; i < n && k > sequence.length(); ++i) {
            sequence.append('1');

            // Append the inverted and reversed part of the existing sequence
            for (int j = sequence.length() - 2; j >= 0; --j) {
                char invertedBit = (sequence.charAt(j) == '1') ? '0' : '1';
                sequence.append(invertedBit);
            }
        }

        // Return the kth bit
        return sequence.charAt(k - 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        sequence = "0"

        # Generate sequence until we have enough elements or reach nth iteration
        for i in range(1, n):
            if k <= len(sequence):
                break
            sequence += "1"

            # Append the inverted and reversed part of the existing sequence
            inverted = "".join(
                "1" if bit == "0" else "0" for bit in sequence[:-1]
            )
            sequence += inverted[::-1]

        # Return the kth bit
        return sequence[k - 1]
```

</details>

<br>

## Approach 2: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: for S1, return '0'
        if (n == 1) return '0';

        // Calculate the length of Sn
        int len = 1 << n;  // Equivalent to 2^n

        // If k is in the first half of the string, recurse with n-1
        if (k < len / 2) {
            return findKthBit(n - 1, k);
        }
        // If k is exactly in the middle, return '1'
        else if (k == len / 2) {
            return '1';
        }
        // If k is in the second half of the string
        else {
            // Find the corresponding bit in the first half and invert it
            char correspondingBit = findKthBit(n - 1, len - k);
            return (correspondingBit == '0') ? '1' : '0';
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char findKthBit(int n, int k) {
        // Base case: for S1, return '0'
        if (n == 1) return '0';

        // Calculate the length of Sn
        int len = 1 << n; // Equivalent to 2^n

        // If k is in the first half of the string, recurse with n-1
        if (k < len / 2) {
            return findKthBit(n - 1, k);
        }
        // If k is exactly in the middle, return '1'
        else if (k == len / 2) {
            return '1';
        }
        // If k is in the second half of the string
        else {
            // Find the corresponding bit in the first half and invert it
            char correspondingBit = findKthBit(n - 1, len - k);
            return (correspondingBit == '0') ? '1' : '0';
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        # Base case: for S1, return '0'
        if n == 1:
            return "0"

        # Calculate the length of Sn
        length = 1 << n  # Equivalent to 2^n

        # If k is in the first half of the string, recurse with n-1
        if k < length // 2:
            return self.findKthBit(n - 1, k)

        # If k is exactly in the middle, return '1'
        elif k == length // 2:
            return "1"

        # If k is in the second half of the string
        else:
            # Find the corresponding bit in the first half and invert it
            corresponding_bit = self.findKthBit(n - 1, length - k)
            return "1" if corresponding_bit == "0" else "0"
```

</details>

<br>

## Approach 3: Iterative Divide and Conquer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        int invertCount = 0;
        int len = (1 << n) - 1;  // Length of Sn is 2^n - 1

        while (k > 1) {
            // If k is in the middle, return based on inversion count
            if (k == len / 2 + 1) {
                return invertCount % 2 == 0 ? '1' : '0';
            }

            // If k is in the second half, invert and mirror
            if (k > len / 2) {
                k = len + 1 - k;  // Mirror position
                invertCount++;    // Increment inversion count
            }

            len /= 2;  // Reduce length for next iteration
        }

        // For the first position, return based on inversion count
        return invertCount % 2 == 0 ? '0' : '1';
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char findKthBit(int n, int k) {
        int invertCount = 0;
        int len = (1 << n) - 1; // Length of Sn is 2^n - 1

        while (k > 1) {
            // If k is in the middle, return based on inversion count
            if (k == len / 2 + 1) {
                return invertCount % 2 == 0 ? '1' : '0';
            }

            // If k is in the second half, invert and mirror
            if (k > len / 2) {
                k = len + 1 - k; // Mirror position
                invertCount++; // Increment inversion count
            }

            len /= 2; // Reduce length for next iteration
        }

        // For the first position, return based on inversion count
        return invertCount % 2 == 0 ? '0' : '1';
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        invert_count = 0
        length = (1 << n) - 1  # Length of Sn is 2^n - 1

        while k > 1:
            # If k is in the middle, return based on inversion count
            if k == length // 2 + 1:
                return "1" if invert_count % 2 == 0 else "0"

            # If k is in the second half, invert and mirror
            if k > length // 2:
                k = length + 1 - k  # Mirror position
                invert_count += 1  # Increment inversion count

            length //= 2  # Reduce length for next iteration

        # For the first position, return based on inversion count
        return "0" if invert_count % 2 == 0 else "1"
```

</details>

<br>

## Approach 4: Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        // Find the position of the rightmost set bit in k
        // This helps determine which "section" of the string we're in
        int positionInSection = k & -k;

        // Determine if k is in the inverted part of the string
        // This checks if the bit to the left of the rightmost set bit is 1
        bool isInInvertedPart = ((k / positionInSection) >> 1 & 1) == 1;

        // Determine if the original bit (before any inversion) would be 1
        // This is true if k is even (i.e., its least significant bit is 0)
        bool originalBitIsOne = (k & 1) == 0;

        if (isInInvertedPart) {
            // If we're in the inverted part, we need to flip the bit
            return originalBitIsOne ? '0' : '1';
        } else {
            // If we're not in the inverted part, return the original bit
            return originalBitIsOne ? '1' : '0';
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char findKthBit(int n, int k) {
        // Find the position of the rightmost set bit in k
        // This helps determine which "section" of the string we're in
        int positionInSection = k & -k;

        // Determine if k is in the inverted part of the string
        // This checks if the bit to the left of the rightmost set bit is 1
        boolean isInInvertedPart = (((k / positionInSection) >> 1) & 1) == 1;

        // Determine if the original bit (before any inversion) would be 1
        // This is true if k is even (i.e., its least significant bit is 0)
        boolean originalBitIsOne = (k & 1) == 0;

        if (isInInvertedPart) {
            // If we're in the inverted part, we need to flip the bit
            return originalBitIsOne ? '0' : '1';
        } else {
            // If we're not in the inverted part, return the original bit
            return originalBitIsOne ? '1' : '0';
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        # Find the position of the rightmost set bit in k
        # This helps determine which "section" of the string we're in
        position_in_section = k & -k

        # Determine if k is in the inverted part of the string
        # This checks if the bit to the left of the rightmost set bit is 1
        is_in_inverted_part = ((k // position_in_section) >> 1 & 1) == 1

        # Determine if the original bit (before any inversion) would be 1
        # This is true if k is even (i.e., its least significant bit is 0)
        original_bit_is_one = (k & 1) == 0

        if is_in_inverted_part:
            # If we're in the inverted part, we need to flip the bit
            return "0" if original_bit_is_one else "1"
        else:
            # If we're not in the inverted part, return the original bit
            return "1" if original_bit_is_one else "0"
```

</details>
