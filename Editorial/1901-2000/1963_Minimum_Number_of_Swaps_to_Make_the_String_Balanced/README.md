# 1963. Minimum Number of Swaps to Make the String Balanced

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/)  
`Two Pointers` `String` `Stack` `Greedy`

**Problem Link:** [LeetCode 1963 - Minimum Number of Swaps to Make the String Balanced](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/)

## Problem

You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

- It is the empty string, or
- It can be written as AB, where both A and B are balanced strings, or
- It can be written as [C], where C is a balanced string.

You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

### Example 1

```text
Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
```

### Example 2

```text
Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
```

### Example 3

```text
Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
```

## Constraints

- n == s.length
- 2 <= n <= 106
- n is even.
- s[i] is either '[' or ']'.
- The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Insertions to Balance a Parentheses String](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1963. Minimum Number of Swaps to Make the String Balanced

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack | C++, Java, Python3 |
| Space-Optimized Stack | C++, Java, Python3 |

## Approach 1: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSwaps(string s) {
        stack<char> stack;
        int unbalanced = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            // If an opening bracket is encountered, push it in the stack.
            if (ch == '[')
                stack.push(ch);
            else {
                // If the stack is not empty, pop it.
                if (!stack.empty()) stack.pop();
                // Otherwise increase the count of unbalanced brackets.
                else
                    unbalanced++;
            }
        }
        return (unbalanced + 1) / 2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minSwaps(String s) {
        Stack<Character> stack = new Stack();
        int unbalanced = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            // If an opening bracket is encountered, push it in the stack.
            if (ch == '[') stack.push(ch);
            else {
                // If the stack is not empty, pop it.
                if (!stack.isEmpty()) stack.pop();
                // Otherwise increase the count of unbalanced brackets.
                else unbalanced++;
            }
        }
        return (unbalanced + 1) / 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSwaps(self, s: str) -> int:
        stack = deque()
        unbalanced = 0
        for ch in s:
            # If an opening bracket is encountered, push it in the deque.
            if ch == "[":
                stack.append(ch)
            else:
                # If the deque is not empty, pop it.
                if stack:
                    stack.pop()
                # Otherwise increase the count of unbalanced brackets.
                else:
                    unbalanced += 1
        return (unbalanced + 1) // 2
```

</details>

<br>

## Approach 2: Space-Optimized Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSwaps(string s) {
        int stackSize = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            // If character is opening bracket, increment the stack size.
            if (ch == '[')
                stackSize++;
            else {
                // If the character is closing bracket, and we have an opening
                // bracket, decrease the stack size.
                if (stackSize > 0) stackSize--;
            }
        }
        return (stackSize + 1) / 2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minSwaps(String s) {
        int stackSize = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            // If character is opening bracket, increment the stack size.
            if (ch == '[') stackSize++;
            else {
                // If the character is closing bracket, and we have an opening bracket, decrease
                // the stack size.
                if (stackSize > 0) stackSize--;
            }
        }
        return (stackSize + 1) / 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSwaps(self, s: str) -> int:
        stack_size = 0
        for ch in s:
            # If character is opening bracket, increment the stack size.
            if ch == "[":
                stack_size += 1
            else:
                # If the character is closing bracket, and we have an opening bracket, decrease
                # the stack size.
                if stack_size > 0:
                    stack_size -= 1
        return (stack_size + 1) // 2
```

</details>
