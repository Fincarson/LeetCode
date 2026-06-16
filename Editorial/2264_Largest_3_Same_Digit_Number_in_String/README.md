# 2264. Largest 3-Same-Digit Number in String

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/largest-3-same-digit-number-in-string/)  
`String`

**Problem Link:** [LeetCode 2264 - Largest 3-Same-Digit Number in String](https://leetcode.com/problems/largest-3-same-digit-number-in-string/)

## Problem

You are given a string num representing a large integer. An integer is good if it meets the following conditions:

- It is a substring of num with length 3.
- It consists of only one unique digit.

Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

- A substring is a contiguous sequence of characters within a string.
- There may be leading zeroes in num or a good integer.

### Example 1

```text
Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
```

### Example 2

```text
Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
```

### Example 3

```text
Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
```

## Constraints

- 3 <= num.length <= 1000
- num only consists of digits.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2264. Largest 3-Same-Digit Number in String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Multiple Iterations, One For Each Digit. | C++, Java, JavaScript, Python3 |
| Single Iteration | C++, Java, JavaScript, Python3 |

## Approach 1: Multiple Iterations, One For Each Digit.

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    vector<string> sameDigitNumbers = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

    // Check whether the 'num' string contains the 'sameDigitNumber' string or not.
    bool contains(string sameDigitNumber, string num) {
        for (int index = 0; index <= num.size() - 3; ++index) {
            if (num[index] == sameDigitNumber[0] and 
                num[index + 1] == sameDigitNumber[1] and 
                num[index + 2] == sameDigitNumber[2]) {
                return true;
            }
        }
        return false;
    }

public:
    string largestGoodInteger(string num) {
        // Iterate on all 'sameDigitNumbers' and check if the string 'num' contains it.
        for (auto& sameDigitNumber: sameDigitNumbers) {
            if (contains(sameDigitNumber, num)) {
                // Return the current 'sameDigitNumbers'.
                return sameDigitNumber;
            }
        }
        // No 3 consecutive same digits are present in the string 'num'.
        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private List<String> sameDigitNumbers = List.of("999", "888", "777", "666", "555", "444", "333", "222", "111", "000");

    // Check whether the 'num' string contains the 'sameDigitNumber' string or not.
    private boolean contains(String sameDigitNumber, String num) {
        for (int index = 0; index <= num.length() - 3; ++index) {
            if (num.charAt(index) == sameDigitNumber.charAt(0) &&
                num.charAt(index + 1) == sameDigitNumber.charAt(1) &&
                num.charAt(index + 2) == sameDigitNumber.charAt(2)) {
                return true;
            }
        }
        return false;
    }

    public String largestGoodInteger(String num) {
        // Iterate on all 'sameDigitNumbers' and check if the string 'num' contains it.
        for (String sameDigitNumber : sameDigitNumbers) {
            if (contains(sameDigitNumber, num)) {
                // Return the current 'sameDigitNumbers'.
                return sameDigitNumber;
            }
        }
        // No 3 consecutive same digits are present in the string 'num'.
        return "";
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const sameDigitNumbers = ["999", "888", "777", "666", "555", "444", "333", "222", "111", "000"];

// Check whether the 'num' string contains the 'sameDigitNumber' string or not.
let contains = (sameDigitNumber, num) => {
    for (let index = 0; index <= num.length - 3; ++index) {
        if (num[index] === sameDigitNumber[0] &&
            num[index + 1] === sameDigitNumber[1] &&
            num[index + 2] === sameDigitNumber[2]) {
            return true;
        }
    }
    return false;
};

let largestGoodInteger = num => {
    // Iterate on all 'sameDigitNumbers' and check if the string 'num' contains it.
    for (const sameDigitNumber of sameDigitNumbers) {
        if (contains(sameDigitNumber, num)) {
            // Return the current 'sameDigitNumber'.
            return sameDigitNumber;
        }
    }
    // No 3 consecutive same digits are present in the string 'num'.
    return "";
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestGoodInteger(self, num: str) -> str:
        same_digit_numbers = ["999", "888", "777", "666", "555", "444", "333", "222", "111", "000"]

        # Check whether the 'num' string contains the 'same_digit_number' string or not.
        def contains(same_digit_number):
            for index in range(len(num) - 2):
                if num[index] == same_digit_number[0] and \
                   num[index + 1] == same_digit_number[1] and \
                   num[index + 2] == same_digit_number[2]:
                    return True
            return False

        # Iterate on all 'same_digit_numbers' and check if the string 'num' contains it.
        for same_digit_number in same_digit_numbers:
            if contains(same_digit_number):
                # Return the current 'same_digit_number'.
                return same_digit_number
        # No 3 consecutive same digits are present in the string 'num'.
        return ""
```

</details>

<br>

## Approach 2: Single Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string largestGoodInteger(string num) {
        // Assign 'maxDigit' to the NUL character (smallest ASCII value character)
        char maxDigit = '\0';

        // Iterate on characters of the num string.
        for (int index = 0; index <= num.size() - 3; ++index) {
            // If 3 consecutive characters are the same,
            // store the character in 'maxDigit' if bigger than what it already stores.
            if (num[index] == num[index + 1] && num[index] == num[index + 2]) {
                maxDigit = max(maxDigit, num[index]);
            }
        }

        // If 'maxDigit' is NUL return an empty string, otherwise string of size 3 with 'maxDigit' characters.
        return maxDigit == '\0' ? "" : string(3, maxDigit);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String largestGoodInteger(String num) {
        // Assign 'maxDigit' to the NUL character (smallest ASCII value character)
        char maxDigit = '\0';

        // Iterate on characters of the num string.
        for (int index = 0; index <= num.length() - 3; ++index) {
            // If 3 consecutive characters are the same, 
            // store the character in 'maxDigit' if it's bigger than what it already stores.
            if (num.charAt(index) == num.charAt(index + 1) && num.charAt(index) == num.charAt(index + 2)) {
                maxDigit = (char) Math.max(maxDigit, num.charAt(index));
            }
        }

        // If 'maxDigit' is NUL, return an empty string; otherwise, return a string of size 3 with 'maxDigit' characters.
        return maxDigit == '\0' ? "" : new String(new char[]{maxDigit, maxDigit, maxDigit});
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var largestGoodInteger = function(num) {
    // Assign 'maxDigit' to the NUL character (smallest ASCII value character)
    let maxDigit = '\0';

    // Iterate on characters of the num string.
    for (let index = 0; index <= num.length - 3; ++index) {
        // If 3 consecutive characters are the same,
        // store the character in 'maxDigit' if it's bigger than what it already stores.
        if (num[index] === num[index + 1] && num[index] === num[index + 2]) {
            maxDigit = String.fromCharCode(Math.max(maxDigit.charCodeAt(0), num.charCodeAt(index)));
        }
    }

    // If 'maxDigit' is NUL, return an empty string; otherwise, return a string of size 3 with 'maxDigit' characters.
    return maxDigit === '\0' ? '' : maxDigit.repeat(3);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestGoodInteger(self, num: str) -> str:
        # Assign 'max_digit' to NUL character (smallest ASCII value character)
        max_digit = '\0'

        # Iterate on characters of the num string.
        for index in range(len(num) - 2):
            # If 3 consecutive characters are the same,
            # store the character in 'max_digit' if it's bigger than what it already stores.
            if num[index] == num[index + 1] == num[index + 2]:
                max_digit = max(max_digit, num[index])

        # If 'max_digit' is NUL, return an empty string; otherwise, return a string of size 3 with 'max_digit' characters.
        return '' if max_digit == '\0' else max_digit * 3
```

</details>
