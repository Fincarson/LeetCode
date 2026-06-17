# 1945. Sum of Digits of String After Convert

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/)  
`String` `Simulation`

**Problem Link:** [LeetCode 1945 - Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/)

## Problem

You are given a string s consisting of lowercase English letters, and an integer k. Your task is to convert the string into an integer by a special process, and then transform it by summing its digits repeatedly k times. More specifically, perform the following steps:

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Return the resulting integer after performing the operations described above.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= s.length <= 100
- 1 <= k <= 10
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Happy Number](https://leetcode.com/problems/happy-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Add Digits](https://leetcode.com/problems/add-digits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Integers With Even Digit Sum](https://leetcode.com/problems/count-integers-with-even-digit-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Element After Replacement With Digit Sum](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1945. Sum of Digits of String After Convert

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| String Concatenation to Summation | C++, Java, Python3 |
| Direct Integer Operation | C++, Java, Python3 |

## Approach 1: String Concatenation to Summation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getLucky(string s, int k) {
        // Convert each character to its numerical value and build a string
        string numericString = "";
        for (char ch : s) {
            numericString += to_string(ch - 'a' + 1);
        }

        // Apply digit sum transformations k times
        while (k-- > 0) {
            int digitSum = 0;
            for (char digit : numericString) {
                digitSum += digit - '0';
            }
            // If the digit sum is less than 10, we can break early
            if (digitSum < 10) {
                return digitSum;
            }
            numericString = to_string(digitSum);
        }

        // Convert the final string to integer and return
        return stoi(numericString);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int getLucky(String s, int k) {
        // Convert each character to its numerical value and build a string
        String numericString = "";
        for (char ch : s.toCharArray()) {
            numericString += Integer.toString(ch - 'a' + 1);
        }

        // Apply digit sum transformations k times
        while (k-- > 0) {
            int digitSum = 0;
            for (char digit : numericString.toCharArray()) {
                digitSum += digit - '0';
            }
            // If the digit sum is less than 10, we can break early
            if (digitSum < 10) {
                return digitSum;
            }
            numericString = Integer.toString(digitSum);
        }

        // Convert the final string to integer and return
        return Integer.parseInt(numericString);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getLucky(self, s: str, k: int) -> int:
        # Convert each character to its numerical value and build a string
        numeric_string = ""
        for ch in s:
            numeric_string += str(ord(ch) - ord("a") + 1)

        # Apply digit sum transformations k times
        for _ in range(k):
            digit_sum = 0
            for digit in numeric_string:
                digit_sum += int(digit)
            # Break early if the current number becomes less than 10
            if digit_sum < 10:
                return digit_sum
            numeric_string = str(digit_sum)

        # Convert the final string to integer and return
        return int(numeric_string)
```

</details>

<br>

## Approach 2: Direct Integer Operation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getLucky(string s, int k) {
        // Convert the string to a number by summing digit values
        int currentNumber = 0;
        for (char ch : s) {
            int position = ch - 'a' + 1;
            while (position > 0) {
                currentNumber += position % 10;
                position /= 10;
            }
        }

        // Apply digit sum transformations k-1 times
        for (int i = 1; i < k; ++i) {
            int digitSum = 0;
            while (currentNumber > 0) {
                digitSum += currentNumber % 10;
                currentNumber /= 10;
            }
            currentNumber = digitSum;

            // Break early if the current number becomes less than 10
            if (currentNumber < 10) {
                break;
            }
        }

        return currentNumber;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int getLucky(String s, int k) {
        // Convert the string to a number by summing digit values
        int currentNumber = 0;
        for (char ch : s.toCharArray()) {
            int position = ch - 'a' + 1;
            while (position > 0) {
                currentNumber += position % 10;
                position /= 10;
            }
        }

        // Apply digit sum transformations k-1 times
        for (int i = 1; i < k; ++i) {
            int digitSum = 0;
            while (currentNumber > 0) {
                digitSum += currentNumber % 10;
                currentNumber /= 10;
            }
            currentNumber = digitSum;

            // Break early if the current number becomes less than 10
            if (currentNumber < 10) {
                break;
            }
        }

        return currentNumber;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getLucky(self, s: str, k: int) -> int:
        # Convert the string to a number by summing digit values
        current_number = 0
        for ch in s:
            position = ord(ch) - ord("a") + 1
            while position > 0:
                current_number += position % 10
                position //= 10

        # Apply digit sum transformations k-1 times
        for i in range(1, k):
            digit_sum = 0
            while current_number > 0:
                digit_sum += current_number % 10
                current_number //= 10
            current_number = digit_sum

            # Break early if the current number becomes less than 10
            if current_number < 10:
                break

        return current_number
```

</details>
