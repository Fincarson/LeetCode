# 246. Strobogrammatic Number

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/strobogrammatic-number/)  
`Hash Table` `Two Pointers` `String`

**Problem Link:** [LeetCode 246 - Strobogrammatic Number](https://leetcode.com/problems/strobogrammatic-number/)

## Problem

Given a string num which represents an integer, return true if num is a strobogrammatic number.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

### Example 1

```text
Input: num = "69"
Output: true
```

### Example 2

```text
Input: num = "88"
Output: true
```

### Example 3

```text
Input: num = "962"
Output: false
```

## Constraints

- 1 <= num.length <= 50
- num consists of only digits.
- num does not contain any leading zeros except for zero itself.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Strobogrammatic Number II](https://leetcode.com/problems/strobogrammatic-number-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Strobogrammatic Number III](https://leetcode.com/problems/strobogrammatic-number-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Confusing Number](https://leetcode.com/problems/confusing-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 246. Strobogrammatic Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Make a Rotated Copy | Java, Python3 |
| Two Pointers | Java, Python3 |

## Approach 1: Make a Rotated Copy

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isStrobogrammatic(String num) {
        
        // Note that using a String here and appending to it would be
        // poor programming practice.
        StringBuilder rotatedStringBuilder = new StringBuilder();
        
        // Remember that we want to loop backwards through the string
        for (int i = num.length() - 1; i >= 0; i--) {
            char c = num.charAt(i);
            if (c == '0' || c == '1' || c == '8') {
                rotatedStringBuilder.append(c);
            } else if (c == '6') {
                rotatedStringBuilder.append('9');
            } else if (c == '9') {
                rotatedStringBuilder.append('6');
            } else { // This must be an invalid digit.
                return false;
            }
        }
        
        String rotatedString = rotatedStringBuilder.toString();
        return num.equals(rotatedString);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        
        # In Python, we use a list as a string builder.
        rotated_string_builder = []
        
        # Remember that we want to loop backward through the string.
        for c in reversed(num):
            if c in {'0', '1', '8'}:
                rotated_string_builder.append(c)
            elif c == '6':
                rotated_string_builder.append('9')
            elif c == '9':
                rotated_string_builder.append('6')
            else: # This must be an invalid digit.
                return False
        
        # In Python, we convert a list of characters to
        # a string using join.
        rotated_string = "".join(rotated_string_builder)
        return rotated_string == num
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isStrobogrammatic(String num) {
        
        Map<Character, Character> rotatedDigits = new HashMap<> (
            Map.of('0', '0', '1', '1', '6', '9', '8', '8', '9', '6'));
         
        // Java allows us to have more than one iteration variable. 
        for (int left = 0, right = num.length() - 1; left <= right; left++, right--) {
            char leftChar = num.charAt(left);
            char rightChar = num.charAt(right);            
            if (!rotatedDigits.containsKey(leftChar) || rotatedDigits.get(leftChar) != rightChar) {
                return false;
            }
        }
        return true;
        
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        
        rotated_digits = {'0': '0', '1': '1', '8': '8', '6': '9', '9': '6'}
        
        left = 0 
        right = len(num) - 1
        
        while left <= right:
            if num[left] not in rotated_digits \
                    or rotated_digits[num[left]] != num[right]:
                return False
            left += 1
            right -= 1
        return True
```

</details>
