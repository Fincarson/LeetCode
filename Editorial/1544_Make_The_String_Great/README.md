# 1544. Make The String Great

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/make-the-string-great/)  
`String` `Stack`

**Problem Link:** [LeetCode 1544 - Make The String Great](https://leetcode.com/problems/make-the-string-great/)

## Problem

Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

- 0 <= i <= s.length - 2
- s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.

To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

### Example 1

```text
Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
```

### Example 2

```text
Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
```

### Example 3

```text
Input: s = "s"
Output: "s"
```

## Constraints

- 1 <= s.length <= 100
- s contains only lower and upper case English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1544. Make The String Great

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iteration. | C++, Java, Python3 |
| Recursion | C++, Java, Python |
| Stack | C++, Java, Python3 |
| Two pointers, in-place modify | C++ |

## Approach 1: Iteration.

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string makeGood(string s) {
        // if s has less than 2 characters, we just return itself.
        while (s.size() > 1) {
            // 'find' records if we find any pair to remove.
            bool find = false;
            
            // Check every two adjacent characters, currChar and nextChar.
            for (int i = 0; i < s.size() - 1; ++i) {
                char currChar = s[i], nextChar = s[i + 1];
                
                // If they make a pair, remove them from 's' and let 'find = true'.
                if (abs(currChar - nextChar) == 32) {
                    s = s.substr(0, i) + s.substr(i + 2);
                    find = true;
                    break;
                }
            }
            
            // If we cannot find any pair to remove, break the loop. 
            if (!find)
                break;
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
    public String makeGood(String s) {
        StringBuilder newS = new StringBuilder(s);
        
        // if s has less than 2 characters, we just return itself.
        while (newS.length() > 1) {
            // 'find' records if we find any pair to remove.
            boolean find = false;
            
            // Check every two adjacent characters, currChar and nextChar.
            for (int i = 0; i < newS.length() - 1; ++i) {
                char currChar = newS.charAt(i), nextChar = newS.charAt(i + 1);
                
                // If they make a pair, remove them from 's' and let 'find = true'.
                if (Math.abs(currChar - nextChar) == 32) {
                    newS.deleteCharAt(i);
                    newS.deleteCharAt(i);
                    find = true;
                    break;
                }
            }
            
            // If we cannot find any pair to remove, break the loop. 
            if (!find)
                break;
        }
        return newS.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def makeGood(self, s: str) -> str:
        # if s has less than 2 characters, we just return itself.
        while len(s) > 1:
            # 'find' records if we find any pair to remove.
            find = False
            
            # Check every two adjacent characters, curr_char and next_char.
            for i in range(len(s) - 1):
                curr_char, next_char = s[i], s[i + 1]
                
                # If they make a pair, remove them from 's' and let 'find = True'.
                if abs(ord(curr_char) - ord(next_char)) == 32:
                    s = s[:i] + s[i + 2:]
                    find = True
                    break
            
            # If we cannot find any pair to remove, break the loop. 
            if not find:
                break
        return s
```

</details>

<br>

## Approach 2: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string makeGood(string s) {  
        // If the string is emtpy, just return it.
        if (s.empty()) 
            return s;
        
        // If we find a pair in 's', remove this pair from 's'
        // and solve the remaining string recursively.
        for (int i = 0; i < s.size() - 1; ++i) {
            if (abs(s[i] - s[i + 1]) == 32)
                return  makeGood(s.substr(0, i) + s.substr(i + 2));
        }

        // Base case, if we can't find a pair, just return 's'.
        return s;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String makeGood(String s) {
        // If we find a pair in 's', remove this pair from 's'
        // and solve the remaining string recursively.
        for (int i = 0; i < s.length() - 1; ++i) {
            if (Math.abs(s.charAt(i) - s.charAt(i + 1)) == 32)
                return makeGood(s.substring(0, i) + s.substring(i + 2));
        }

        // Base case, if we can't find a pair, just return 's'.
        return s;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def makeGood(self, s: str) -> str:
        # If we find a pair in 's', remove this pair from 's'
        # and solve the remaining string recursively.
        for i in range(len(s) - 1):
            if abs(ord(s[i]) - ord(s[i + 1])) == 32:
                return self.makeGood(s[:i] + s[i + 2:])
        
        # Base case, if we can't find a pair, just return 's'.
        return s
```

</details>

<br>

## Approach 3: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string makeGood(string s) {
        // Use stack to store the visited characters.
        vector<char> stack;
        
        // Iterate over 's'.
        for (auto currChar : s) {
            // If the current character make a pair with the last character in the stack,
            // remove both of them. Otherwise, we add the current character to stack.
            if (!stack.empty() && abs(stack.back() - currChar) == 32)
                stack.pop_back(); 
            else
                stack.push_back(currChar);
        }
        
        // Returns the string concatenated by all characters left in the stack.
        string ans(stack.begin(), stack.end());
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String makeGood(String s) {
        // Use stack to store the visited characters.
        Stack<Character> stack = new Stack<>();
        
        // Iterate over 's'.
        for (char currChar : s.toCharArray()) {
            // If the current character make a pair with the last character in the stack,
            // remove both of them. Otherwise, we the add current character to stack.
            if (!stack.isEmpty() && Math.abs(stack.lastElement() - currChar) == 32) 
                stack.pop();
            else
                stack.add(currChar);
        }
        
        // Returns the string concatenated by all characters left in the stack.
        StringBuilder ans = new StringBuilder();
        for (char currChar : stack) 
            ans.append(currChar);
        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def makeGood(self, s: str) -> str:
        # Use stack to store the visited characters.
        stack = []
        
        # Iterate over 's'.
        for curr_char in list(s):
            # If the current character make a pair with the last character in the stack,
            # remove both of them. Otherwise, we add the current character to stack.
            if stack and abs(ord(curr_char) - ord(stack[-1])) == 32:
                stack.pop()
            else:
                stack.append(curr_char)
        
        # Returns the string concatenated by all characters left in the stack.
        return "".join(stack)
```

</details>

<br>

## Approach 4: Two pointers, in-place modify

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string makeGood(string s) {
        // Initialize 'end = 0' since the good string is empty.
        int end = 0;
        for (int cur = 0; cur < s.size(); ++cur) {
            // If s[cur] makes a pair with the last character s[end - 1] in good string,
            // remove s[end - 1] by decrementing 'end' by 1. 
            // Otherwise, add s[cur] to the good string by overwritting s[end] by s[cur].
            if (end > 0 && abs(s[cur] - s[end - 1]) == 32)
                end--;
            else {
                s[end] = s[cur];
                end++;
            }
        }
        
        // Once the iteration ends, the string before 'end' is the good string.
        return s.substr(0, end);  
    }
};
```

</details>
