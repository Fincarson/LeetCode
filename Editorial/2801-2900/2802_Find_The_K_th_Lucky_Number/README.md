# 2802. Find The K-th Lucky Number

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-k-th-lucky-number/)  
`Math` `String` `Bit Manipulation`

**Problem Link:** [LeetCode 2802 - Find The K-th Lucky Number](https://leetcode.com/problems/find-the-k-th-lucky-number/)

## Problem

We know that 4 and 7 are lucky digits. Also, a number is called lucky if it contains only lucky digits.

You are given an integer k, return the kth lucky number represented as a string.

### Example 1

```text
Input: k = 4
Output: "47"
Explanation: The first lucky number is 4, the second one is 7, the third one is 44 and the fourth one is 47.
```

### Example 2

```text
Input: k = 10
Output: "477"
Explanation: Here are lucky numbers sorted in increasing order:
4, 7, 44, 47, 74, 77, 444, 447, 474, 477. So the 10th lucky number is 477.
```

### Example 3

```text
Input: k = 1000
Output: "777747447"
Explanation: It can be shown that the 1000th lucky number is 777747447.
```

## Constraints

- 1 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2802. Find The K-th Lucky Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count Digits | C++, Java, Python3 |
| Bit Manipulation | C++, Java, Python3 |
| Optimized Bit Manipulation | C++, Java, Python3 |

## Approach 1: Count Digits

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string kthLuckyNumber(int k) {
        int c = 0;         // The number of digits in the kth lucky number
        int numCount = 0;  // The number of lucky numbers with c or fewer digits
        while (numCount < k) {
            c++;
            numCount += pow(2, c);
        }

        // Calculate the number of lucky numbers with c digits before the kth
        // lucky number
        int x = k - 1 - (numCount - pow(2, c));

        // Build result using x by prepending 4 for 0 and 1 for 7
        string kthLuckyNum;
        for (int i = 0; i < c; i++) {
            string digit;
            if (x % 2 == 1) {
                digit = '7';
            } else {
                digit = '4';
            }
            kthLuckyNum.insert(0, digit);
            x /= 2;
        }

        return kthLuckyNum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public String kthLuckyNumber(int k) {
        int c = 0; // The number of digits in the kth lucky number
        int numCount = 0; // The number of lucky numbers with c or fewer digits
        while (numCount < k) {
            c++;
            numCount += Math.pow(2, c);
        }

        // Calculate the number of lucky numbers with c digits before the kth
        // lucky number
        int x = k - 1 - (int) (numCount - Math.pow(2, c));

        // Build result using x by prepending 4 for 0 and 1 for 7
        StringBuilder kthLuckyNum = new StringBuilder();
        for (int i = 0; i < c; i++) {
            char digit;
            if (x % 2 == 1) {
                digit = '7';
            } else {
                digit = '4';
            }
            kthLuckyNum.insert(0, digit);
            x /= 2;
        }

        return kthLuckyNum.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        c = 0  # The number of digits in the kth lucky number
        num_count = 0  # The number of lucky numbers with c or fewer digits
        while num_count < k:
            c += 1
            num_count += 2**c

        # Calculate the number of lucky numbers with c digits before the kth lucky number
        x = k - 1 - (num_count - (2**c))

        # Build result using x by prepending 4 for 0 and 1 for 7
        kth_lucky_num = ""
        for i in range(0, c):
            if x % 2 == 1:
                digit = "7"
            else:
                digit = "4"
            kth_lucky_num = "".join((digit, kth_lucky_num))
            x //= 2

        return kth_lucky_num
```

</details>

<br>

## Approach 2: Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string kthLuckyNumber(int k) {
        // Increment k to account for 1-based indexing
        k = k + 1;

        // For each digit in the binary representation of k except the most
        // significant Prepend 4 to the result if the digit is 0 and 7 otherwise
        string kthLuckyNum = "";
        while (k > 1) {
            kthLuckyNum.insert(0, ((k & 1) ? "7" : "4"));
            k >>= 1;
        }
        return kthLuckyNum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public String kthLuckyNumber(int k) {
        // Increment k to account for 1-based indexing
        k = k + 1;

        // For each digit in the binary representation of k except the most significant
        // Prepend 4 to the result if the digit is 0 and 7 otherwise
        StringBuilder kthLuckyNumBuilder = new StringBuilder();
        while (k > 1) {
            kthLuckyNumBuilder.insert(0, ((k & 1) == 1 ? "7" : "4"));
            k >>= 1;
        }
        return kthLuckyNumBuilder.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        # Increment k to account for 1-based indexing
        k = k + 1

        # For each digit in the binary representation of k except the most significant
        # Prepend 4 to the result if the digit is 0 and 7 otherwise
        kth_lucky_num = ""
        while k > 1:
            kth_lucky_num = "".join((("7" if k & 1 else "4"), kth_lucky_num))
            k >>= 1
        return kth_lucky_num
```

</details>

<br>

## Approach 3: Optimized Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string kthLuckyNumber(int k) {
        // Increment k to account for 1-based indexing
        k = k + 1;

        int digits = log2(k);

        // Place '4' for '0' and '1' for '7'
        string kthLuckyNum(digits, ' ');
        while (k > 1) {
            digits--;
            kthLuckyNum[digits] = ((k & 1) ? '7' : '4');
            k >>= 1;
        }
        return kthLuckyNum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public String kthLuckyNumber(int k) {
        // Increment k to account for 1-based indexing
        k = k + 1;

        // Convert k to a binary string (up to the most significant '1')
        String binaryString = Integer.toBinaryString(k).substring(1);

        char[] kthLuckyNum = binaryString.toCharArray();

        // Replace '0' with '4' and '1' with '7' in the binary string
        for (int i = 0; i < kthLuckyNum.length; i++) {
            kthLuckyNum[i] = (kthLuckyNum[i] == '1') ? '7' : '4';
        }

        return new String(kthLuckyNum);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        # Increment k to account for 1-based indexing
        k = k + 1

        # Convert k to a binary string (up to the most significant '1')
        kth_lucky_num = bin(k)[3:]

        # Replace '0' with '4' and '1' with '7' in the binary string
        kth_lucky_num = kth_lucky_num.replace("0", "4").replace("1", "7")

        return kth_lucky_num
```

</details>
