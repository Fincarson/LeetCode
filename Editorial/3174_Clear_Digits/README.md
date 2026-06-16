# 3174. Clear Digits

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/clear-digits/)  
`String` `Stack` `Simulation`

**Problem Link:** [LeetCode 3174 - Clear Digits](https://leetcode.com/problems/clear-digits/)

## Problem

You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

- Delete the first digit and the closest non-digit character to its left.

Return the resulting string after removing all digits.

Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 100
- s consists only of lowercase English letters and digits.
- The input is generated such that it is possible to delete all digits.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3174. Clear Digits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Stack-Like | C++, Java, Python3 |
| In-place | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string clearDigits(string s) {
        int charIndex = 0;

        // Until we reach the end of the string
        while (charIndex < s.size()) {
            if (isdigit(s[charIndex])) {
                // Remove the digit from the string
                s.erase(charIndex, 1);
                // Remove the character to the left of the digit
                s.erase(charIndex - 1, 1);
                // Adjust the index to account for the removed character
                charIndex--;
            } else {
                // Move to the next character if it's not a digit
                charIndex++;
            }
        }
        return s;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String clearDigits(String s) {
        int charIndex = 0;

        StringBuilder sb = new StringBuilder(s);

        // Until we reach the end of the string
        while (charIndex < sb.length()) {
            if (Character.isDigit(sb.charAt(charIndex))) {
                // Remove the digit from the string
                sb.deleteCharAt(charIndex);
                // Remove the character to the left of the digit
                sb.deleteCharAt(charIndex - 1);
                // Adjust the index to account for the removed character
                charIndex--;
            } else {
                // Move to the next character if it's not a digit
                charIndex++;
            }
        }
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def clearDigits(self, s: str) -> str:
        s = list(s)
        char_index = 0

        # Until we reach the end of the string
        while char_index < len(s):
            if s[char_index].isdigit():
                # Remove the digit from the string
                del s[char_index]
                # Remove the character to the left of the digit
                del s[char_index - 1]
                # Adjust the index to account for the removed character
                char_index -= 1
            else:
                # Move to the next character if it's not a digit
                char_index += 1
        return "".join(s)
```

</details>

<br>

## Approach 2: Stack-Like

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string clearDigits(string s) {
        string answer;

        // Iterate over each character in the input string
        for (int charIndex = 0; charIndex < s.size(); charIndex++) {
            // If the current character is a digit
            if (isdigit(s[charIndex])) {
                // Remove the last character
                answer.pop_back();
            } else {
                // If the character is not a digit, add it to the answer string
                answer += s[charIndex];
            }
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String clearDigits(String s) {
        StringBuilder answer = new StringBuilder();

        // Iterate over each character in the input string
        for (int charIndex = 0; charIndex < s.length(); charIndex++) {
            // If the current character is a digit
            if (Character.isDigit(s.charAt(charIndex))) {
                // Remove the last character
                answer.setLength(answer.length() - 1);
            } else {
                // If the character is not a digit, add it to the answer
                answer.append(s.charAt(charIndex));
            }
        }

        return answer.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def clearDigits(self, s: str) -> str:
        # Use a list to store characters for efficient modification
        answer = []

        # Iterate over each character in the input string
        for char in s:
            # If the current character is a digit
            if char.isdigit():
                # Remove the last character
                answer.pop()
            else:
                # If the character is not a digit, add it to the answer list
                answer.append(char)

        # Join the list back into a string before returning
        return "".join(answer)
```

</details>

<br>

## Approach 3: In-place

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string clearDigits(string s) {
        // This variable keeps track of the actual length of the resulting
        // string
        int answerLength = 0;

        // Iterate through each character in the input string
        for (int charIndex = 0; charIndex < s.size(); charIndex++) {
            // If the current character is a digit
            if (isdigit(s[charIndex])) {
                // Decrement answerLength to remove the last character from the
                // result
                answerLength--;
            } else {
                // Place the character in the "answer" portion of the string
                s[answerLength++] = s[charIndex];
            }
        }

        // Resize the string to match the actual length of the answer
        s.resize(answerLength);

        return s;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public String clearDigits(String s) {
        // This variable keeps track of the actual length of the resulting string
        int answerLength = 0;
        char[] charArray = s.toCharArray();

        // Iterate through each character in the input string
        for (int charIndex = 0; charIndex < s.length(); charIndex++) {
            // If the current character is a digit
            if (Character.isDigit(s.charAt(charIndex))) {
                // Decrement answerLength to remove the last character from the result
                answerLength--;
            } else {
                // Place the character in the "answer" portion of the string
                charArray[answerLength++] = s.charAt(charIndex);
            }
        }

        // Resize the string to match the actual length of the answer
        s = new String(charArray, 0, answerLength);

        return s;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def clearDigits(self, s: str) -> str:
        # This variable keeps track of the actual length of the resulting string
        answer_length = 0
        s = list(s)

        # Iterate through each character in the input string
        for char_index in range(len(s)):

            # If the current character is a digit
            if s[char_index].isdigit():
                # Decrement answerLength to remove the last character from the result
                answer_length -= 1
            else:
                # Place the character in the "answer" portion of the string
                s[answer_length] = s[char_index]
                answer_length += 1

        # Resize the string to match the actual length of the answer
        s = s[:answer_length]

        return "".join(s)
```

</details>
