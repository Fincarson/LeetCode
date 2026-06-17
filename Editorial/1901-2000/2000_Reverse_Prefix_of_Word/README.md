# 2000. Reverse Prefix of Word

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/reverse-prefix-of-word/)  
`Two Pointers` `String` `Stack`

**Problem Link:** [LeetCode 2000 - Reverse Prefix of Word](https://leetcode.com/problems/reverse-prefix-of-word/)

## Problem

Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

- For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".

Return the resulting string.

### Example 1

```text
Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
```

### Example 2

```text
Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
```

### Example 3

```text
Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
```

## Constraints

- 1 <= word.length <= 250
- word consists of lowercase English letters.
- ch is a lowercase English letter.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2000. Reverse Prefix of Word

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack | C++, Java, Python3 |
| Find the Index and Fill Result | C++, Java, Python3 |
| Two-Pointer Swapping | C++, Java, Python3 |

## Approach 1: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> stack;
        string result;

        int index = 0;
        while (index < word.length()) {
            stack.push(word[index]);
            // Found ch
            if (word[index] == ch) {
                // Add characters through ch to the result in reverse order
                while (!stack.empty()) {
                    result.push_back(stack.top());
                    stack.pop();
                }
                index++;
                // Add the rest of the characters to result
                while (index < word.length()) {
                    result.push_back(word[index]);
                    index++;
                }
                return result;
            }
            index++;
        }

        return word;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String reversePrefix(String word, char ch) {
        Stack<Character> stack = new Stack<>();
        StringBuilder result = new StringBuilder();

        int index = 0;
        while (index < word.length()) {
            stack.push(word.charAt(index));
            // Found ch
            if (word.charAt(index) == ch) {
                // Add characters through ch to the result in reverse order
                while (!stack.isEmpty()) {
                    result.append(stack.pop());
                }
                index++;
                // Add the rest of the characters to result
                while (index < word.length()) {
                    result.append(word.charAt(index));
                    index++;
                }
                return result.toString();
            }
            index++;
        }

        return word;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        stack = []
        result = []

        index = 0
        while index < len(word):
            stack.append(word[index])
            # Found ch
            if word[index] == ch:
                # Add characters through ch to the result in reverse order
                while stack:
                    result.append(stack.pop())
                index += 1
                # Add the rest of the characters to result
                while index < len(word):
                    result.append(word[index])
                    index += 1
                return ''.join(result)
            index += 1

        return word
```

</details>

<br>

## Approach 2: Find the Index and Fill Result

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int chIndex = word.find(ch);
        if (chIndex == -1) {
            return word;
        }

        string result;

        for (int i = 0; i < word.length(); i++) {
            // Add characters through ch to the result in reverse order
            if (i <= chIndex) {
                result += word[chIndex - i];
            }
            // Add the rest of the characters to result
            else {
                result += word[i];
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String reversePrefix(String word, char ch) {
        int chIndex = word.indexOf(ch);
        if (chIndex == -1) {
            return word;
        }

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < word.length(); i++) {
            // Add characters through ch to the result in reverse order
            if (i <= chIndex) {
                result.append(word.charAt(chIndex - i));
            }
            // Add the rest of the characters to result
            else {
                result.append(word.charAt(i));
            }
        }

        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        ch_index = word.find(ch)
        if (ch_index == -1):
            return word

        result = ""

        for i in range(0, len(word)):
            # Add characters through ch to the result in reverse order
            if (i <= ch_index):
                result += word[ch_index - i]
            # Add the rest of the characters to result
            else:
                result += word[i]

        return result
```

</details>

<br>

## Approach 3: Two-Pointer Swapping

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left = 0;

        for (int right = 0; right < word.length(); right++) {
            // We found ch - reverse characters up to ch by swapping
            if (word[right] == ch) {
                while (left < right) {
                    swap(word[right], word[left]);
                    left++;
                    right--;
                }
                return word;
            }
        }
        return word;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String reversePrefix(String word, char ch) {
        // Add characters to the result in the original order
        char[] result = word.toCharArray();
        int left = 0;

        for (int right = 0; right < word.length(); right++) {
            // We found ch - reverse characters up to ch by swapping
            if (result[right] == ch) {
                while (left < right) {
                    swap(result, left, right);
                    left++;
                    right--;
                }
                return new String(result);
            }
        }
        return word;
    }

    private void swap(char[] characters, int index1, int index2) {
        char temp = characters[index2];
        characters[index2] = characters[index1];
        characters[index1] = temp;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        # Add characters to the result in the original order
        result = list(word)
        left = 0

        for right in range(len(word)):
            # We found ch - reverse characters up to ch by swapping
            if result[right] == ch:
                while left < right:
                    result[right], result[left] = result[left], result[right]
                    left += 1
                    right -= 1
                return "".join(result)
        return word
```

</details>
