# 1323. Maximum 69 Number

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-69-number/)  
`Math` `Greedy`

**Problem Link:** [LeetCode 1323 - Maximum 69 Number](https://leetcode.com/problems/maximum-69-number/)

## Problem

You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

### Example 1

```text
Input: num = 9669
Output: 9969
Explanation:
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
```

### Example 2

```text
Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
```

### Example 3

```text
Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
```

## Constraints

- 1 <= num <= 104
- num consists of only 6 and 9 digits.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1323. Maximum 69 Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Convert the integer to an iterable object | C++, Java, Python |
| Use built-in function | Java, Python |
| Check the remainder | C++, Java, Python |

## Approach 1: Convert the integer to an iterable object

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        // Convert the input 'num' to a string 'numString'.
        string numString = to_string(num);

        // Iterate over the string (from high to low).
        for (auto &currChar : numString) {
            // If we find the first '6', replace it with '9' and break the loop.
            if (currChar == '6') {
                currChar = '9';
                break;
            }
        }

        // Convert the modified string to integer and return it.
        return stoi(numString);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximum69Number (int num) {
        // Convert the input 'num' to a string builder 'numSB'.
        StringBuilder numSB = new StringBuilder();
        numSB.append(num);
        
        // Iterate over the string builer (from high to low).
        for (int i = 0; i < numSB.length(); ++i) {
            // If we find the first '6', replace it with '9' and break the loop.
            if (numSB.charAt(i) == '6') {
                numSB.setCharAt(i, '9');
                break;
            }
        }
        
        // Convert the modified string builder to integer and return it.
        return Integer.parseInt(numSB.toString());
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def maximum69Number (self, num: int) -> int:
        # Convert the input 'num' to a list of character 'num_char_list'.
        num_char_list = list(str(num))
        
        # Iterate over the list (from high to low).
        for i, cur_char in enumerate(num_char_list):
            # If we find the first '6', replace it with '9' and break the loop.
            if cur_char == '6':
                num_char_list[i] = '9'
                break
        
        # Convert the modified char list to integer and return it.
        return int("".join(num_char_list))
```

</details>

<br>

## Approach 2: Use built-in function

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximum69Number (int num) {
        // Convert the input 'num' to the string 'numString'.
        String numString = "" + num;

        // Use the built-in function to replace the first '6' with '9'.
        // Return the integer converted from the modified 'numString'.
        return Integer.parseInt(numString.replaceFirst("6", "9"));
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def maximum69Number (self, num: int) -> int:
        # Convert the input 'num' to the string 'num_string'.
        num_string = str(num)

        # Use the built-in function to replace the first '6' with '9'.
        # Return the integer converted from the modified 'num_string'.
        return int(num_string.replace('6', '9', 1))
```

</details>

<br>

## Approach 3: Check the remainder

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        // Since we start with the lowest digit, initialize currDigit = 0.
        int numCopy = num;
        int indexFirstSix = -1;
        int currDigit = 0;
        
        // Check every digit of 'numCopy' from low to high.
        while (numCopy > 0) {
            // If the current digit is '6', record it as the highest digit of 6.
            if (numCopy % 10 == 6)
                indexFirstSix = currDigit;

            // Move on to the next digit.
            numCopy /= 10;
            currDigit++;
        }

        // If we don't find any digit of '6', return the original number,
        // otherwise, increment 'num' by the difference made by the first '6'.
        // There might be precision loss in pow function if 'indexFirstSix' is large,
        // we can write a for loop to avoid the precision loss.
        return indexFirstSix == -1 ? num : num + 3 * (int)pow(10, indexFirstSix);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximum69Number (int num) {
        // Since we start with the lowest digit, initialize currDigit = 0.
        int numCopy = num;
        int indexSix = -1;
        int currDigit = 0;
        
        // Check every digit of 'numCopy' from low to high.
        while (numCopy > 0) {
            // If the current digit is '6', record it as the highest digit of 6.
            if (numCopy % 10 == 6) 
                indexSix = currDigit;

            // Move on to the next digit.
            numCopy /= 10;
            currDigit++;
        }
        
        // If we don't find any digit of '6', return the original number,
        // otherwise, increment 'num' by the difference made by the first '6'.
        return indexSix == -1 ? num : num + 3 * (int)Math.pow(10, indexSix);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def maximum69Number (self, num: int) -> int:
        # Since we start with the lowest digit, initialize curr_digit = 0.
        curr_digit = 0
        index_first_six = -1
        num_copy = num
        
        # Check every digit of 'num_copy' from low to high.
        while num_copy:
            # If the current digit is '6', record it as the highest digit of 6.
            if num_copy % 10 == 6:
                index_first_six = curr_digit
            
            # Move on to the next digit.
            num_copy //= 10
            curr_digit += 1
        
        # If we don't find any digit of '6', return the original number,
        # otherwise, increment 'num' by the difference made by the first '6'.
        return num if index_first_six == -1 else num + 3 * 10 ** index_first_six
```

</details>
