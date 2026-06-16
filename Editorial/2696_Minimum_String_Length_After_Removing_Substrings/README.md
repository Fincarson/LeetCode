# 2696. Minimum String Length After Removing Substrings

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/)  
`String` `Stack` `Simulation`

**Problem Link:** [LeetCode 2696 - Minimum String Length After Removing Substrings](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/)

## Problem

You are given a string s consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Return the minimum possible length of the resulting string that you can obtain.

Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

### Example 1

```text
Input: s = "ABFCACDB"
Output: 2
Explanation: We can do the following operations:
- Remove the substring "ABFCACDB", so s = "FCACDB".
- Remove the substring "FCACDB", so s = "FCAB".
- Remove the substring "FCAB", so s = "FC".
So the resulting length of the string is 2.
It can be shown that it is the minimum length that we can obtain.
```

### Example 2

```text
Input: s = "ACBBD"
Output: 5
Explanation: We cannot do any operations on the string so the length remains the same.
```

## Constraints

- 1 <= s.length <= 100
- s consists only of uppercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2696. Minimum String Length After Removing Substrings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| String Replace | C++, Java, Python3 |
| Stack | C++, Java, Python3 |
| In Place Modification | C++, Java, Python3 |

## Approach 1: String Replace

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minLength(string s) {
        // Continue processing while "AB" or "CD" substrings exist
        while (s.find("AB") != -1 || s.find("CD") != -1) {
            if (s.find("AB") != -1) {
                // Remove all occurrences of "AB"
                s.erase(s.find("AB"), 2);
            } else if (s.find("CD") != -1) {
                // Remove all occurrences of "CD"
                s.erase(s.find("CD"), 2);
            }
        }

        return s.length();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minLength(String s) {
        // Continue processing while "AB" or "CD" substrings exist
        while (s.contains("AB") || s.contains("CD")) {
            if (s.contains("AB")) {
                // Remove all occurrences of "AB"
                s = s.replace("AB", "");
            } else if (s.contains("CD")) {
                // Remove all occurrences of "CD"
                s = s.replace("CD", "");
            }
        }

        return s.length();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minLength(self, s: str) -> int:
        # Continue processing while "AB" or "CD" substrings exist
        while "AB" in s or "CD" in s:
            if "AB" in s:
                # Remove all occurrences of "AB"
                s = s.replace("AB", "")
            elif "CD" in s:
                # Remove all occurrences of "CD"
                s = s.replace("CD", "")

        return len(s)
```

</details>

<br>

## Approach 2: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minLength(string s) {
        stack<char> stack;

        // Iterate over each character in the input string
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];

            // If the stack is empty, simply push the current character
            if (stack.empty()) {
                stack.push(currentChar);
                continue;
            }

            // Check for "AB" pattern, remove the pair by popping from the stack
            if (currentChar == 'B' && stack.top() == 'A') {
                stack.pop();
            }
            // Check for "CD" pattern, remove the pair by popping from the stack
            else if (currentChar == 'D' && stack.top() == 'C') {
                stack.pop();
            }
            // Otherwise, push the current character onto the stack
            else {
                stack.push(currentChar);
            }
        }

        return stack.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minLength(String s) {
        Stack<Character> stack = new Stack<>();

        // Iterate over each character in the input string
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);

            // If the stack is empty, simply push the current character
            if (stack.isEmpty()) {
                stack.push(currentChar);
                continue;
            }

            // Check for "AB" pattern, remove the pair by popping from the stack
            if (currentChar == 'B' && stack.peek() == 'A') {
                stack.pop();
            }
            // Check for "CD" pattern, remove the pair by popping from the stack
            else if (currentChar == 'D' && stack.peek() == 'C') {
                stack.pop();
            }
            // Otherwise, push the current character onto the stack
            else {
                stack.push(currentChar);
            }
        }

        return stack.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minLength(self, s: str) -> int:
        stack = []

        # Iterate over each character in the input string
        for current_char in s:
            # If the stack is empty, simply push the current character
            if not stack:
                stack.append(current_char)
                continue

            # Check for "AB" pattern, remove the pair by popping from the stack
            if current_char == "B" and stack[-1] == "A":
                stack.pop()
            # Check for "CD" pattern, remove the pair by popping from the stack
            elif current_char == "D" and stack[-1] == "C":
                stack.pop()
            # Otherwise, push the current character onto the stack
            else:
                stack.append(current_char)

        return len(stack)
```

</details>

<br>

## Approach 3: In Place Modification

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minLength(string s) {
        int writePtr = 0;
        vector<char> charArray(s.begin(), s.end());

        // Iterate over each character in the string
        for (int readPtr = 0; readPtr < s.length(); readPtr++) {
            // Write the current character to the current write position
            charArray[writePtr] = charArray[readPtr];

            // Check if we have a valid pattern to remove
            if (writePtr > 0 &&
                (charArray[writePtr - 1] == 'A' ||
                 charArray[writePtr - 1] == 'C') &&
                charArray[writePtr] == charArray[writePtr - 1] + 1) {
                writePtr--;
            } else {
                writePtr++;  // No match, so move the write pointer forward
            }
        }

        // The writePtr now represents the length of the remaining string
        return writePtr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minLength(String s) {
        int writePtr = 0;
        char[] charArray = s.toCharArray();

        // Iterate over each character in the string
        for (int readPtr = 0; readPtr < s.length(); readPtr++) {
            // Write the current character to the current write position
            charArray[writePtr] = charArray[readPtr];

            // Check if we have a valid pattern to remove
            if (
                writePtr > 0 &&
                (charArray[writePtr - 1] == 'A' ||
                    charArray[writePtr - 1] == 'C') &&
                charArray[writePtr] == charArray[writePtr - 1] + 1
            ) {
                writePtr--;
            } else {
                writePtr++; // No match, so move the write pointer forward
            }
        }

        // The writePtr now represents the length of the remaining string
        return writePtr;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minLength(self, s: str) -> int:
        char_list = list(s)
        write_ptr = 0

        # Iterate over each character in the string
        for read_ptr in range(len(s)):
            # Write the current character to the current write position
            char_list[write_ptr] = char_list[read_ptr]

            # Check if we have a valid pattern to remove
            if (
                write_ptr > 0
                and char_list[write_ptr - 1] in "AC"
                and ord(char_list[write_ptr])
                == ord(char_list[write_ptr - 1]) + 1
            ):
                write_ptr -= 1
            else:
                write_ptr += 1  # No match, so move the write pointer forward

        # The write_ptr now represents the length of the remaining string
        return write_ptr
```

</details>
