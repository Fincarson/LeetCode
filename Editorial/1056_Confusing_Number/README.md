# 1056. Confusing Number

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/confusing-number/)  
`Math`

**Problem Link:** [LeetCode 1056 - Confusing Number](https://leetcode.com/problems/confusing-number/)

## Problem

A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.

We can rotate digits of a number by 180 degrees to form new digits.

- When 0, 1, 6, 8, and 9 are rotated 180 degrees, they become 0, 1, 9, 8, and 6 respectively.
- When 2, 3, 4, 5, and 7 are rotated 180 degrees, they become invalid.

Note that after rotating a number, we can ignore leading zeros.

- For example, after rotating 8000, we have 0008 which is considered as just 8.

Given an integer n, return true if it is a confusing number, or false otherwise.

### Example 1

```text
Input: n = 6
Output: true
Explanation: We get 9 after rotating 6, 9 is a valid number, and 9 != 6.
```

### Example 2

```text
Input: n = 89
Output: true
Explanation: We get 68 after rotating 89, 68 is a valid number and 68 != 89.
```

### Example 3

```text
Input: n = 11
Output: false
Explanation: We get 11 after rotating 11, 11 is a valid number but the value remains the same, thus 11 is not a confusing number
```

## Constraints

- 0 <= n <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Strobogrammatic Number](https://leetcode.com/problems/strobogrammatic-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Confusing Number II](https://leetcode.com/problems/confusing-number-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1056. Confusing Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Invert and Reverse | C++, Java, Python3 |
| Use the remainder | C++, Java, Python |

## Approach 1: Invert and Reverse

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool confusingNumber(int n) {
        // Use 'invertMap' to invert each valid digit.
        unordered_map<char, char> invertMap = {{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};
        string rotatedNumber;

        // Iterate over each digit of 'n'.
        for (auto ch : to_string(n)) {
            if (invertMap.find(ch) == invertMap.end()) {
                return false;
            }

            // Append the inverted digit of 'ch' to the end of 'rotatedNumber'. 
            rotatedNumber += invertMap[ch];
        }
        
        // Check if the reversed 'rotatedNumber' equals 'n'.
        reverse(begin(rotatedNumber), end(rotatedNumber));
        return stoi(rotatedNumber) != n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean confusingNumber(int n) {
        // Use 'invertMap' to invert each valid digit.
        Map<Character, Character> invertMap = new HashMap<>() {{
            put('0', '0');
            put('1', '1');
            put('6', '9');
            put('8', '8');
            put('9', '6');
        }};
        StringBuilder sb = new StringBuilder();

        // Iterate over each digit of 'n'.
        for (char ch : String.valueOf(n).toCharArray()) {
            if (!invertMap.containsKey(ch)) {
                return false;
            }

            // Append the inverted digit of 'ch' to the end of 'rotatedNumber'. 
            sb.append(invertMap.get(ch));
        }

        // Check if the reversed 'rotatedNumber' equals 'n'.
        sb.reverse();
        return Integer.parseInt(sb.toString()) != n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python

class Solution:
    def confusingNumber(self, n: int) -> bool:
        # Use 'invertMap' to invert each valid digit.
        invert_map = {"0":"0", "1":"1", "8":"8", "6":"9", "9":"6"}
        rotated_number = []
        
        # Iterate over each digit of 'n'.
        for ch in str(n):
            if ch not in invert_map:
                return False

            # Append the inverted digit of 'ch' to the end of 'rotated_number'. 
            rotated_number.append(invert_map[ch])
        
        rotated_number = "".join(rotated_number)

        # Check if the reversed 'rotated_number' equals 'n'.
        return int(rotated_number[::-1]) != n
```

</details>

<br>

## Approach 2: Use the remainder

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool confusingNumber(int n) {
        // Use 'invertMap' to invert each valid digit. Since we don't want to modify
        // 'n', we create a copy of it as 'nCopy'. 
        map<int, int> invertMap = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
        int rotatedNumber = 0, nCopy = n;

        // Get every digit of 'nCopy' by taking the remainder of it to 10.
        while (nCopy > 0) {
            int res = nCopy % 10;
            if (invertMap.find(res) == invertMap.end()) {
                return false;
            }

            // Append the inverted digit of 'res' to the end of 'rotatedNumber'. 
            rotatedNumber = rotatedNumber * 10 + invertMap[res];
            nCopy /= 10;
        }
        
        // Check if 'rotatedNumber' equals 'n'.
        return rotatedNumber != n; 
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean confusingNumber(int n) {
        // Use 'invertMap' to invert each valid digit. Since we don't want to modify
        // 'n', we create a copy of it as 'nCopy'.
        Map<Integer, Integer> invertMap = new HashMap<>() {{
            put(0, 0);
            put(1, 1);
            put(6, 9);
            put(8, 8);
            put(9, 6);
        }};
        int nCopy = n, rotatedNumber = 0;
        
        // Get every digit of 'nCopy' by taking the remainder of it to 10.
        while (nCopy > 0) {
            int res = nCopy % 10;
            if (!invertMap.containsKey(res)) {
                return false;
            }

            // Append the inverted digit of 'res' to the end of 'rotatedNumber'. 
            rotatedNumber = rotatedNumber * 10 + invertMap.get(res);
            nCopy /= 10;
        }

        // Check if 'rotatedNumber' equals 'n'.
        return rotatedNumber != n;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def confusingNumber(self, n: int) -> bool:
        # Use 'invert_map' to invert each valid digit. Since we don't want to modify
        # 'n', we create a copy of it as 'nCopy'.
        invert_map = {0:0, 1:1, 8:8, 6:9, 9:6}
        invert_number = 0
        n_copy = n
        
        # Get every digit of 'n_copy' by taking the remainder of it to 10.
        while n_copy:
            res = n_copy % 10
            if res not in invert_map:
                return False
            
            # Append the inverted digit of 'res' to the end of 'rotated_number'. 
            invert_number = invert_number * 10 + invert_map[res]
            n_copy //= 10
        
        # Check if 'rotated_number' equals 'n'.
        return  invert_number != n
```

</details>
