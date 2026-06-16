# 2220. Minimum Bit Flips to Convert Number

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/)  
`Bit Manipulation`

**Problem Link:** [LeetCode 2220 - Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/)

## Problem

A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

- For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.

Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

### Example 1

```text
Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
```

### Example 2

```text
Input: start = 3, goal = 4
Output: 3
Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4 in 3 steps:
- Flip the first bit from the right: 011 -> 010.
- Flip the second bit from the right: 010 -> 000.
- Flip the third bit from the right: 000 -> 100.
It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.
```

## Constraints

- 0 <= start, goal <= 109

Note: This question is the same as 461: Hamming Distance.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Flips to Make a OR b Equal to c](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Number of Operations to Make Array XOR Equal to K](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Smallest Number With All Set Bits](https://leetcode.com/problems/smallest-number-with-all-set-bits/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2220. Minimum Bit Flips to Convert Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Recursive Approach | C++, Java, Python3 |
| XOR Rules | C++, Java, Python3 |
| Brian Kernighan’s Algorithm | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        while (start > 0 || goal > 0) {
            // Increment count if the current bits differ
            if ((start & 1) != (goal & 1)) {
                count++;
            }
            // Shift both numbers to the right to check the next bits
            start >>= 1;
            goal >>= 1;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minBitFlips(int start, int goal) {
        int count = 0;
        while (start > 0 || goal > 0) {
            // Increment count if the current bits differ
            if ((start & 1) != (goal & 1)) {
                count++;
            }
            // Shift both numbers to the right to check the next bits
            start >>= 1;
            goal >>= 1;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        count = 0
        while start > 0 or goal > 0:
            # Increment count if the current bits differ
            if (start & 1) != (goal & 1):
                count += 1
            # Shift both numbers to the right to check the next bits
            start >>= 1
            goal >>= 1
        return count
```

</details>

<br>

## Approach 2: Recursive Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // Base case: both numbers have been fully processed
        if (start == 0 && goal == 0) return 0;

        // Flip for the current least significant bit
        int flip = (start & 1) != (goal & 1);

        // Recurse for the next bits by right-shifting both numbers
        return flip + minBitFlips(start >> 1, goal >> 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minBitFlips(int start, int goal) {
        // Base case: both numbers have been fully processed
        if (start == 0 && goal == 0) return 0;

        // Flip for the current least significant bit
        int flip = (start & 1) != (goal & 1) ? 1 : 0;

        // Recurse for the next bits by right-shifting both numbers
        return flip + minBitFlips(start >> 1, goal >> 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        # Base case: both numbers have been fully processed
        if start == 0 and goal == 0:
            return 0

        # Flip for the current least significant bit
        flip = 1 if (start & 1) != (goal & 1) else 0

        # Recurse for the next bits by right-shifting both numbers
        return flip + self.minBitFlips(start >> 1, goal >> 1)
```

</details>

<br>

## Approach 3: XOR Rules

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorResult = start ^ goal;
        int count = 0;
        // Count the number of 1s in xorResult (differing bits)
        while (xorResult) {
            count += xorResult & 1;  // Increment if the last bit is 1
            xorResult >>= 1;         // Shift right to process the next bit
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorResult = start ^ goal;
        int count = 0;
        // Count the number of 1s in xorResult (differing bits)
        while (xorResult != 0) {
            count += xorResult & 1; // Increment if the last bit is 1
            xorResult >>= 1; // Shift right to process the next bit
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        # XOR to find differing bits
        xor_result = start ^ goal
        count = 0
        # Count the number of 1s in xor_result (differing bits)
        while xor_result:
            count += xor_result & 1  # Increment if the last bit is 1
            xor_result >>= 1  # Shift right to process the next bit
        return count
```

</details>

<br>

## Approach 4: Brian Kernighan’s Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorResult = start ^ goal;
        int count = 0;
        // Brian Kernighans algorithm to count 1s
        while (xorResult) {
            xorResult &= (xorResult - 1);  // Clear the lowest set bit
            count++;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorResult = start ^ goal;
        int count = 0;
        // Brian Kernighans algorithm to count 1s
        while (xorResult != 0) {
            xorResult &= (xorResult - 1); // Clear the lowest set bit
            count++;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        # XOR to find differing bits
        xor_result = start ^ goal
        count = 0
        # Brian Kernighans algorithm to count 1s
        while xor_result:
            xor_result &= xor_result - 1  # Clear the lowest set bit
            count += 1
        return count
```

</details>
