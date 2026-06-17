# 394. Decode String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/decode-string/)  
`String` `Stack` `Recursion`

**Problem Link:** [LeetCode 394 - Decode String](https://leetcode.com/problems/decode-string/)

## Problem

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

### Example 1

```text
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
```

### Example 2

```text
Input: s = "3[a2[c]]"
Output: "accaccacc"
```

### Example 3

```text
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
```

## Constraints

- 1 <= s.length <= 30
- s consists of lowercase English letters, digits, and square brackets '[]'.
- s is guaranteed to be a valid input.
- All the integers in s are in the range [1, 300].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Encode String with Shortest Length](https://leetcode.com/problems/encode-string-with-shortest-length/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Number of Atoms](https://leetcode.com/problems/number-of-atoms/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Brace Expansion](https://leetcode.com/problems/brace-expansion/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 394. Decode String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Stack | C++, Java |
| Using 2 Stack | C++, Java |
| Using Recursion | C++, Java |

## Approach 1: Using Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                string decodedString;
                // get the encoded string (in reverse order from stack)
                while (st.top() != '[') {
                    decodedString.push_back(st.top());
                    st.pop();
                }
                // pop '[' from stack
                st.pop();

                // get the number k
                int base = 1;
                int k = 0;
                while (!st.empty() && isdigit(st.top())) {
                    k += (st.top() - '0') * base;
                    st.pop();
                    base *= 10;
                }

                // decodedString is reversed, so fix it
                reverse(decodedString.begin(), decodedString.end());

                // push decodedString k times into stack
                while (k-- > 0) {
                    for (char c : decodedString) {
                        st.push(c);
                    }
                }
            } else {
                st.push(s[i]);
            }
        }

        // build result from stack
        string result;
        result.reserve(st.size());
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ']') {
                List<Character> decodedString = new ArrayList<>();
                // get the encoded string
                while (stack.peek() != '[') {
                    decodedString.add(stack.pop());
                }
                // pop [ from the stack
                stack.pop();
                int base = 1;
                int k = 0;
                // get the number k
                while (!stack.isEmpty() && Character.isDigit(stack.peek())) {
                    k = k + (stack.pop() - '0') * base;
                    base *= 10;
                }
                // decode k[decodedString], by pushing decodedString k times into stack
                while (k != 0) {
                    for (int j = decodedString.size() - 1; j >= 0; j--) {
                        stack.push(decodedString.get(j));
                    }
                    k--;
                }
            }
            // push the current character to stack
            else {
                stack.push(s.charAt(i));
            }
        }      
        // get the result from stack
        char[] result = new char[stack.size()];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = stack.pop();
        }
        return new String(result);
    }
}
```

</details>

<br>

## Approach 2: Using 2 Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString;
        int k = 0;
        for (auto ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + ch - '0';
            } else if (ch == '[') {
                // push the number k to countStack
                countStack.push(k);
                // push the currentString to stringStack
                stringStack.push(currentString);
                // reset currentString and k
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();
                // decode currentK[currentString] by appending currentString k times
                for (int currentK = countStack.top(); currentK > 0; currentK--) {
                    decodedString = decodedString + currentString;
                }
                countStack.pop();
                currentString = decodedString;
            } else {
                currentString = currentString + ch;
            }
        }
        return currentString;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> stringStack = new Stack<>();
        StringBuilder currentString = new StringBuilder();
        int k = 0;
        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                k = k * 10 + ch - '0';
            } else if (ch == '[') {
                // push the number k to countStack
                countStack.push(k);
                // push the currentString to stringStack
                stringStack.push(currentString);
                // reset currentString and k
                currentString = new StringBuilder();
                k = 0;
            } else if (ch == ']') {
                StringBuilder decodedString = stringStack.pop();
                // decode currentK[currentString] by appending currentString k times
                for (int currentK = countStack.pop(); currentK > 0; currentK--) {
                    decodedString.append(currentString);
                }
                currentString = decodedString;
            } else {
                currentString.append(ch);
            }
        }
        return currentString.toString();
    }
}
```

</details>

<br>

## Approach 3: Using Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return decodeString(s, index);
    }
    string decodeString(const string& s, int& index) {
        string result;
        while (index < s.length() && s[index] != ']') {
            if (!isdigit(s[index]))
                result += s[index++];
            else {
                int k = 0;
                // build k while next character is a digit
                while (index < s.length() && isdigit(s[index]))
                    k = k * 10 + s[index++] - '0';  
                // ignore the opening bracket '['    
                index++;
                string decodedString = decodeString(s, index);
                // ignore the closing bracket ']'
                index++;        
                while (k-- > 0)
                    result += decodedString;
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
class Solution {
    int index = 0;
    String decodeString(String s) {
        StringBuilder result = new StringBuilder();
        while (index < s.length() && s.charAt(index) != ']') {
            if (!Character.isDigit(s.charAt(index)))
                result.append(s.charAt(index++));
            else {
                int k = 0;
                // build k while next character is a digit
                while (index < s.length() && Character.isDigit(s.charAt(index)))
                    k = k * 10 + s.charAt(index++) - '0';
                // ignore the opening bracket '['    
                index++;
                String decodedString = decodeString(s);
                // ignore the closing bracket ']'
                index++;
                // build k[decodedString] and append to the result
                while (k-- > 0)
                    result.append(decodedString);
            }
        }
        return new String(result);
    }
}
```

</details>
