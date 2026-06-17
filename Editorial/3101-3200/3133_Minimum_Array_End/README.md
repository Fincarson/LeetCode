# 3133. Minimum Array End

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-array-end/)  
`Bit Manipulation`

**Problem Link:** [LeetCode 3133 - Minimum Array End](https://leetcode.com/problems/minimum-array-end/)

## Problem

You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

Return the minimum possible value of nums[n - 1].

### Example 1

### Example 2

## Constraints

- 1 <= n, x <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3133. Minimum Array End

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Consecutive ORing | C++, Java, Python3 |
| Bit Manipulation and Binary Construction | C++, Java, Python3 |
| Bitmasking with Logical Operations | C++, Java, Python3 |

## Approach 1: Consecutive ORing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;

        // Step 1: Iterate n-1 times (since we already initialized result with
        // x)
        while (--n) {
            // Step 2: Increment result and perform bitwise OR with x
            result = (result + 1) | x;
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

    public long minEnd(int n, int x) {
        long result = x;

        // Step 1: Iterate n-1 times (since we already initialized result with x)
        while (--n > 0) {
            // Step 2: Increment result and perform bitwise OR with x
            result = (result + 1) | x;
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
    def minEnd(self, n: int, x: int) -> int:
        result = x

        # Step 1: Iterate n-1 times (since we already initialized result with x)
        while n > 1:
            # Step 2: Increment result and perform bitwise OR with x
            result = (result + 1) | x
            n -= 1

        return result
```

</details>

<br>

## Approach 2: Bit Manipulation and Binary Construction

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
#define ll long long

class Solution {
public:
    long long minEnd(int n, int x) {
        ll result = 0, bit;
        // Reducing n by 1 to exclude x from the iteration
        --n;

        // Step 1: Initialize vectors to hold the binary representation of x and
        // n-1
        vector<int> binaryX(64, 0);  // Binary representation of x
        vector<int> binaryN(64, 0);  // Binary representation of n-1

        ll longX = x;  // Convert x to long long for 64-bit manipulation
        ll longN = n;  // Convert n-1 to long long for 64-bit manipulation

        // Step 2: Build binary representations of x and n-1
        for (int i = 0; i < 64; ++i) {
            bit = (longX >> i) & 1;  // Extract i-th bit of x
            binaryX[i] = bit;

            bit = (longN >> i) & 1;  // Extract i-th bit of n-1
            binaryN[i] = bit;
        }

        int posX = 0, posN = 0;

        // Step 3: Combine binary representation of x and n-1
        while (posX < 63) {
            // Traverse binaryX until we find a 0 bit
            while (binaryX[posX] != 0 && posX < 63) {
                ++posX;
            }
            // Copy bits from binaryN (n-1) into binaryX (x) starting from the
            // first 0
            binaryX[posX] = binaryN[posN];
            ++posX;
            ++posN;
        }

        // Step 4: Rebuild the final result from the combined binary
        // representation
        for (int i = 0; i < 64; ++i) {
            if (binaryX[i] == 1) {
                // convert binary bit to decimal value
                result += pow(2, i);
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
public class Solution {

    public long minEnd(int n, int x) {
        long result = 0, bit;
        // Reducing n by 1 to exclude x from the iteration
        --n;

        // Step 1: Initialize vectors to hold the binary representation of x and n-1
        int[] binaryX = new int[64]; // Binary representation of x
        int[] binaryN = new int[64]; // Binary representation of n-1

        long longX = x; // Convert x to long for 64-bit manipulation
        long longN = n; // Convert n-1 to long for 64-bit manipulation

        // Step 2: Build binary representations of x and n-1
        for (int i = 0; i < 64; ++i) {
            bit = (longX >> i) & 1; // Extract i-th bit of x
            binaryX[i] = (int) bit;

            bit = (longN >> i) & 1; // Extract i-th bit of n-1
            binaryN[i] = (int) bit;
        }

        int posX = 0, posN = 0;

        // Step 3: Combine binary representation of x and n-1
        while (posX < 64) {
            // Traverse binaryX until we find a 0 bit
            while (binaryX[posX] != 0 && posX < 64) {
                ++posX;
            }
            // Copy bits from binaryN (n-1) into binaryX (x) starting from the first 0
            binaryX[posX] = binaryN[posN];
            ++posX;
            ++posN;
        }

        // Step 4: Rebuild the final result from the combined binary representation
        for (int i = 0; i < 64; ++i) {
            if (binaryX[i] == 1) {
                // convert binary bit to decimal value
                result += Math.pow(2, i);
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
    def minEnd(self, n: int, x: int) -> int:

        result = 0
        # Reducing n by 1 to exclude x from the iteration
        n -= 1

        # Step 1: Initialize lists to hold the binary representation of x and n-1
        binaryX = [0] * 64  # Binary representation of x
        binaryN = [0] * 64  # Binary representation of n-1

        # Step 2: Build binary representations of x and n-1
        for i in range(64):
            bit = (x >> i) & 1  # Extract i-th bit of x
            binaryX[i] = bit

            bit = (n >> i) & 1  # Extract i-th bit of n-1
            binaryN[i] = bit

        posX = 0
        posN = 0

        # Step 3: Combine binary representation of x and n-1
        while posX < 63:
            # Traverse binaryX until we find a 0 bit
            while binaryX[posX] != 0 and posX < 63:
                posX += 1
            # Copy bits from binaryN (n-1) into binaryX (x) starting from the first 0
            binaryX[posX] = binaryN[posN]
            posX += 1
            posN += 1

        # Step 4: Rebuild the final result from the combined binary representation
        for i in range(64):
            if binaryX[i] == 1:
                # convert binary bit to decimal value
                result += pow(2, i)

        return result
```

</details>

<br>

## Approach 3: Bitmasking with Logical Operations

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x, mask;
        --n;  // Reducing n by 1 to exclude x from the iteration

        // Step 1: Iterate over each bit position with mask starting at 1 and
        // shifting left
        for (mask = 1; n > 0; mask <<= 1) {
            // Step 2: If the corresponding bit in x is 0
            if ((mask & x) == 0) {
                // Set the bit in result based on the least significant bit of n
                result |= (n & 1) * mask;
                // Shift n to the right by 1 to process the next bit
                n >>= 1;
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
public class Solution {

    public long minEnd(int n, int x) {
        long result = x;
        long mask;
        n--; // Reducing n by 1 to exclude x from the iteration

        // Step 1: Iterate over each bit position with mask starting at 1 and shifting left
        for (mask = 1; n > 0; mask <<= 1) {
            // Step 2: If the corresponding bit in x is 0
            if ((mask & x) == 0) {
                // Set the bit in result based on the least significant bit of n
                result |= (n & 1) * mask;
                // Shift n to the right by 1 to process the next bit
                n >>= 1;
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
    def minEnd(self, n: int, x: int) -> int:
        result = x
        n -= 1  # Reducing n by 1 to exclude x from the iteration
        mask = 1

        # Step 1: Iterate while n > 0, using mask for bit positions
        while n > 0:
            # Step 2: If the corresponding bit in x is 0
            if (mask & x) == 0:
                # Set the bit in result based on least significant bit of n
                result |= (n & 1) * mask
                # Shift n right by 1 to process next bit
                n >>= 1
            # Shift mask left by 1 for next iteration
            mask <<= 1

        return result
```

</details>
