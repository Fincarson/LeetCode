# 1134. Armstrong Number

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/armstrong-number/)  
`Math`

**Problem Link:** [LeetCode 1134 - Armstrong Number](https://leetcode.com/problems/armstrong-number/)

## Problem

Given an integer n, return true if and only if it is an Armstrong number.

The k-digit number n is an Armstrong number if and only if the kth power of each digit sums to n.

### Example 1

```text
Input: n = 153
Output: true
Explanation: 153 is a 3-digit number, and 153 = 13 + 53 + 33.
```

### Example 2

```text
Input: n = 123
Output: false
Explanation: 123 is a 3-digit number, and 123 != 13 + 23 + 33 = 36.
```

## Constraints

- 1 <= n <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1134. Armstrong Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Calculate k by Converting to String | C++, Java |
| Calculate k by Using Log | C++, Java |
| Calculate k Without Built-in Methods | C++, Java |

## Approach 1: Calculate k by Converting to String

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getSumOfKthPowerOfDigits(int n, int k) {
       // `result` stores the result of sum of k'th power of each digit.
       int result = 0;

       // Run until n is not 0
       while (n != 0) {
           // Modulo 10 gives us the last digit
           // Add digit ^ k to the result
           result += pow(n % 10, k);

           // Remove the last digit.
           n /= 10;
       }
       return result;
    }
    bool isArmstrong(int n) {
        // Get length of the number by converting to string.
        int length = to_string(n).length();

        // Return true if Sum of k'th power of digits equals original number.
        return getSumOfKthPowerOfDigits(n, length) == n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int getSumOfKthPowerOfDigits(int n, int k) {
        // `result` stores the result of sum of k'th power of each digit.
       int result = 0;

       // Run until n is not 0
       while (n != 0) {
           // Modulo 10 gives us the last digit
           // Add digit ^ k to the result
           result += Math.pow(n % 10, k);

           // Remove the last digit.
           n /= 10;
       }
       return result;
    }
    public boolean isArmstrong(int n) {
        // Get length of the number by conveting to string.
        int length = String.valueOf(n).length();

        // Return true if Sum of k'th power of digits equals original number.
        return getSumOfKthPowerOfDigits(n, length) == n;
    }
}
```

</details>

<br>

## Approach 2: Calculate k by Using Log

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getSumOfKthPowerOfDigits(int n, int k) {
       // `result` stores the result of sum of k'th power of each digit.
       int result = 0;

       // Run until n is not 0
       while (n != 0) {
           // Modulo 10 gives us the last digit
           // Add digit ^ k to the result
           result += pow(n % 10, k);

           // Remove the last digit.
           n /= 10;
       }
       return result;
    }
    bool isArmstrong(int n) {
        // Get length of the number by getting floor of log10 and adding 1.
        int length = log10(n) + 1;

        // Return true if Sum of k'th power of digits equals original number.
        return getSumOfKthPowerOfDigits(n, length) == n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int getSumOfKthPowerOfDigits(int n, int k) {
        // `result` stores the result of sum of k'th power of each digit.
       int result = 0;

       // Run until n is not 0
       while (n != 0) {
           // Modulo 10 gives us the last digit
           // Add digit ^ k to the result
           result += Math.pow(n % 10, k);

           // Remove the last digit.
           n /= 10;
       }
       return result;
    }
    public boolean isArmstrong(int n) {
        // Get length of the number by getting floor of log10 and adding 1.
        int length = (int) Math.log10(n) + 1;

        // Return true if Sum of k'th power of digits equals original number.
        return getSumOfKthPowerOfDigits(n, length) == n;
    }
}
```

</details>

<br>

## Approach 3: Calculate k Without Built-in Methods

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getSumOfKthPowerOfDigits(int n, int k) {
       // `result` stores the result of sum of k'th power of each digit.
       int result = 0;

       // Run until n is not 0
       while(n != 0) {
           // Modulo 10 gives us the last digit
           // Add digit ^ k to the result
           result += pow(n % 10, k);

           // Remove the last digit.
           n /= 10;
       }
       return result;
    }
    bool isArmstrong(int n) {
        // Initilize length counter to 0.
        int length = 0;

        // Store `n` in a temporary variable to find the length.
        int tempN = n;

        // Get the number of digits in integer `n`.
        while (tempN) {
            length++;
            tempN /= 10;
        }

        // Return true if Sum of k'th power of digits equals original number.
        return getSumOfKthPowerOfDigits(n, length) == n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int getSumOfKthPowerOfDigits(int n, int k) {
        // `result` stores the result of sum of k'th power of each digit.
       int result = 0;

       // Run until n is not 0
       while(n != 0) {
           // Modulo 10 gives us the last digit
           // Add digit ^ k to the result
           result += Math.pow(n % 10, k);

           // Remove the last digit.
           n /= 10;
       }
       return result;
    }
    public boolean isArmstrong(int n) {
        // Initilize length counter to 0.
        int length = 0;

        // Get the number of digits in integer `n`.
        int tempN = n;

        // Get the length of the integer `n`
        while (tempN != 0) {
            length++;
            tempN /= 10;
        }

        // Return true if Sum of k'th power of digits equals original number.
        return getSumOfKthPowerOfDigits(n, length) == n;
    }
}
```

</details>
