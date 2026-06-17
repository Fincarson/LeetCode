# 32. Longest Valid Parentheses

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/longest-valid-parentheses/)  
`String` `Dynamic Programming` `Stack`

**Problem Link:** [LeetCode 32 - Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)

## Problem

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

### Example 1

```text
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
```

### Example 2

```text
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
```

### Example 3

```text
Input: s = ""
Output: 0
```

## Constraints

- 0 <= s.length <= 3 * 104
- s[i] is '(', or ')'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 32. Longest Valid Parentheses

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using Stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Without extra space | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int longestValidParentheses(char *s) {
    int maxLen = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j <= n; j += 2) {
            if (isValid(s, i, j)) {
                maxLen = (maxLen > j - i) ? maxLen : j - i;
            }
        }
    }
    return maxLen;
}
int isValid(char *s, int start, int end) {
    int stack[end - start];
    int top = -1;
    for (int i = start; i < end; i++) {
        if (s[i] == '(') {
            stack[++top] = '(';
        } else if (top != -1 && stack[top] == '(') {
            top--;
        } else {
            return 0;
        }
    }
    return top == -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push('(');
            } else if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }

    int longestValidParentheses(std::string s) {
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 2; j <= s.length(); j += 2) {
                if (isValid(s.substr(i, j - i))) {
                    maxlen = std::max(maxlen, j - i);
                }
            }
        }
        return maxlen;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsValid(string s) {
        Stack<char> stack = new Stack<char>();
        for (int i = 0; i < s.Length; i++) {
            if (s[i] == '(') {
                stack.Push('(');
            } else if (stack.Count > 0 && stack.Peek() == '(') {
                stack.Pop();
            } else {
                return false;
            }
        }

        return stack.Count == 0;
    }

    public int LongestValidParentheses(string s) {
        int maxlen = 0;
        for (int i = 0; i < s.Length; i++) {
            for (int j = i + 2; j <= s.Length; j += 2) {
                if (IsValid(s.Substring(i, j - i))) {
                    maxlen = Math.Max(maxlen, j - i);
                }
            }
        }

        return maxlen;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isValid(s string) bool {
    stack := []rune{}
    for _, char := range s {
        if char == '(' {
            stack = append(stack, char)
        } else if len(stack) > 0 && stack[len(stack)-1] == '(' {
            stack = stack[:len(stack)-1]
        } else {
            return false
        }
    }
    return len(stack) == 0
}

func longestValidParentheses(s string) int {
    maxlen := 0
    for i := 0; i < len(s); i++ {
        for j := i + 2; j <= len(s); j += 2 {
            if isValid(s[i:j]) {
                if maxlen < j-i {
                    maxlen = j - i
                }
            }
        }
    }
    return maxlen
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push('(');
            } else if (!stack.empty() && stack.peek() == '(') {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }

    public int longestValidParentheses(String s) {
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 2; j <= s.length(); j += 2) {
                if (isValid(s.substring(i, j))) {
                    maxlen = Math.max(maxlen, j - i);
                }
            }
        }
        return maxlen;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isValid = function (s) {
    let stack = [];
    for (let i = 0; i < s.length; i++) {
        if (s.charAt(i) == "(") {
            stack.push("(");
        } else if (stack.length !== 0 && stack[stack.length - 1] == "(") {
            stack.pop();
        } else {
            return false;
        }
    }
    return stack.length === 0;
};
var longestValidParentheses = function (s) {
    let maxlen = 0;
    for (let i = 0; i < s.length; i++) {
        for (let j = i + 2; j <= s.length; j += 2) {
            if (isValid(s.substring(i, j))) {
                maxlen = Math.max(maxlen, j - i);
            }
        }
    }
    return maxlen;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for char in s:
            if char == "(":
                stack.append("(")
            elif stack and stack[-1] == "(":
                stack.pop()
            else:
                return False
        return len(stack) == 0

    def longestValidParentheses(self, s: str) -> int:
        maxlen = 0
        for i in range(len(s)):
            for j in range(i + 2, len(s) + 1, 2):
                if self.isValid(s[i:j]):
                    maxlen = max(maxlen, j - i)
        return maxlen
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isValid(s: string): boolean {
    let stack: string[] = [];
    for (let i = 0; i < s.length; i++) {
        if (s.charAt(i) == "(") {
            stack.push("(");
        } else if (stack.length !== 0 && stack[stack.length - 1] == "(") {
            stack.pop();
        } else {
            return false;
        }
    }
    return stack.length === 0;
}
function longestValidParentheses(s: string): number {
    let maxlen = 0;
    for (let i = 0; i < s.length; i++) {
        for (let j = i + 2; j <= s.length; j += 2) {
            if (isValid(s.substring(i, j))) {
                maxlen = Math.max(maxlen, j - i);
            }
        }
    }
    return maxlen;
}
```

</details>

<br>

## Approach 2: Using Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int longestValidParentheses(char* s) {
    if (!s || strlen(s) <= 0) return 0;
    int sLength = strlen(s);
    int dp[sLength];
    memset(dp, 0, sizeof(int) * sLength);  // initialize all elements as 0
    int maxans = 0;
    for (int i = 1; i < sLength; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] +
                        ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            maxans = maxans > dp[i] ? maxans : dp[i];
        }
    }
    return maxans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        vector<int> dp(s.length());
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] +
                            ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) +
                            2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LongestValidParentheses(string s) {
        int maxans = 0;
        int[] dp = new int[s.Length];
        for (int i = 1; i < s.Length; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] +
                            ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) +
                            2;
                }

                maxans = Math.Max(maxans, dp[i]);
            }
        }

        return maxans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestValidParentheses(s string) int {
    maxans := 0
    dp := make([]int, len(s))
    for i := 1; i < len(s); i++ {
        if s[i] == ')' {
            if s[i-1] == '(' {
                if i >= 2 {
                    dp[i] = dp[i-2] + 2
                } else {
                    dp[i] = 2
                }
            } else if i-dp[i-1] > 0 && s[i-dp[i-1]-1] == '(' {
                if i-dp[i-1] >= 2 {
                    dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
                } else {
                    dp[i] = dp[i-1] + 2
                }
            }
            if dp[i] > maxans {
                maxans = dp[i]
            }
        }
    }
    return maxans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int longestValidParentheses(String s) {
        int maxans = 0;
        int dp[] = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (
                    i - dp[i - 1] > 0 && s.charAt(i - dp[i - 1] - 1) == '('
                ) {
                    dp[i] = dp[i - 1] +
                    ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) +
                    2;
                }
                maxans = Math.max(maxans, dp[i]);
            }
        }
        return maxans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestValidParentheses = function (s) {
    let maxans = 0;
    let dp = new Array(s.length).fill(0);
    for (let i = 1; i < s.length; i++) {
        if (s[i] == ")") {
            if (s[i - 1] == "(") {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == "(") {
                dp[i] =
                    dp[i - 1] +
                    (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) +
                    2;
            }
            maxans = Math.max(maxans, dp[i]);
        }
    }
    return maxans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        maxans = 0
        dp = [0] * len(s)
        for i in range(1, len(s)):
            if s[i] == ")":
                if s[i - 1] == "(":
                    dp[i] = (dp[i - 2] if i >= 2 else 0) + 2
                elif i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == "(":
                    dp[i] = (
                        dp[i - 1]
                        + (dp[i - dp[i - 1] - 2] if i - dp[i - 1] >= 2 else 0)
                        + 2
                    )
                maxans = max(maxans, dp[i])
        return maxans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestValidParentheses(s: string): number {
    let maxans = 0;
    let dp = new Array(s.length).fill(0);
    for (let i = 1; i < s.length; i++) {
        if (s.charAt(i) == ")") {
            if (s.charAt(i - 1) == "(") {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (
                i - dp[i - 1] > 0 &&
                s.charAt(i - dp[i - 1] - 1) == "("
            ) {
                dp[i] =
                    dp[i - 1] +
                    (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) +
                    2;
            }
            maxans = Math.max(maxans, dp[i]);
        }
    }
    return maxans;
}
```

</details>

<br>

## Approach 3: Using Stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C Solution
int longestValidParentheses(char* s) {
    int maxans = 0;
    int n = strlen(s);
    int* stack = malloc((n + 1) * sizeof(int));
    int top = -1;
    stack[++top] = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top < 0) {
                stack[++top] = i;
            } else {
                maxans = fmax(maxans, i - stack[top]);
            }
        }
    }
    free(stack);
    return maxans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++ solution
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        std::stack<int> stack;
        stack.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = std::max(maxans, i - stack.top());
                }
            }
        }
        return maxans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C# Solution

public class Solution {
    public int LongestValidParentheses(string s) {
        int maxans = 0;
        Stack<int> stack = new Stack<int>();
        stack.Push(-1);
        for (int i = 0; i < s.Length; i++) {
            if (s[i] == '(') {
                stack.Push(i);
            } else {
                stack.Pop();
                if (stack.Count == 0) {
                    stack.Push(i);
                } else {
                    maxans = Math.Max(maxans, i - stack.Peek());
                }
            }
        }

        return maxans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang Solution
func longestValidParentheses(s string) int {
    maxans := 0
    stack := []int{-1}
    for i := 0; i < len(s); i++ {
        if s[i] == '(' {
            stack = append(stack, i)
        } else {
            stack = stack[:len(stack)-1]
            if len(stack) == 0 {
                stack = append(stack, i)
            } else {
                maxans = max(maxans, i-stack[len(stack)-1])
            }
        }
    }
    return maxans
}

func max(x int, y int) int {
    if x > y {
        return x
    }
    return y
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int longestValidParentheses(String s) {
        int maxans = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = Math.max(maxans, i - stack.peek());
                }
            }
        }
        return maxans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
//Javascript Solution
var longestValidParentheses = function (s) {
    let maxans = 0;
    let stack = [];
    stack.push(-1);
    for (let i = 0; i < s.length; i++) {
        if (s.charAt(i) === "(") {
            stack.push(i);
        } else {
            stack.pop();
            if (stack.length === 0) {
                stack.push(i);
            } else {
                maxans = Math.max(maxans, i - stack[stack.length - 1]);
            }
        }
    }
    return maxans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Python Solution
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        maxans = 0
        stack = []
        stack.append(-1)
        for i in range(len(s)):
            if s[i] == "(":
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    maxans = max(maxans, i - stack[-1])
        return maxans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// Typescript Solution
function longestValidParentheses(s: string): number {
    let maxans = 0;
    let stack: number[] = [];
    stack.push(-1);
    for (let i = 0; i < s.length; i++) {
        if (s.charAt(i) === "(") {
            stack.push(i);
        } else {
            stack.pop();
            if (stack.length === 0) {
                stack.push(i);
            } else {
                maxans = Math.max(maxans, i - stack[stack.length - 1]);
            }
        }
    }
    return maxans;
}
```

</details>

<br>

## Approach 4: Without extra space

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int max(int a, int b) { return (a > b ? a : b); }
int longestValidParentheses(char* s) {
    int left = 0, right = 0, maxlength = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = max(maxlength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }
    left = right = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = max(maxlength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }
    return maxlength;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LongestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.Length; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                maxlength = Math.Max(maxlength, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;
        for (int i = s.Length - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                maxlength = Math.Max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return maxlength;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestValidParentheses(s string) int {
    left, right, maxlength := 0, 0, 0
    for i := 0; i < len(s); i++ {
        if s[i] == '(' {
            left++
        } else {
            right++
        }
        if left == right {
            maxlength = max(maxlength, 2*right)
        } else if right > left {
            left, right = 0, 0
        }
    }
    left, right = 0, 0
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == '(' {
            left++
        } else {
            right++
        }
        if left == right {
            maxlength = max(maxlength, 2*left)
        } else if left > right {
            left, right = 0, 0
        }
    }
    return maxlength
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int longestValidParentheses(String s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestValidParentheses = function (s) {
    let left = 0,
        right = 0,
        maxlength = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === "(") {
            left++;
        } else {
            right++;
        }
        if (left === right) {
            maxlength = Math.max(maxlength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }
    left = right = 0;
    for (let i = s.length - 1; i >= 0; i--) {
        if (s[i] === "(") {
            left++;
        } else {
            right++;
        }
        if (left === right) {
            maxlength = Math.max(maxlength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }
    return maxlength;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        left, right, maxlength = 0, 0, 0
        for i in range(len(s)):
            if s[i] == "(":
                left += 1
            else:
                right += 1
            if left == right:
                maxlength = max(maxlength, 2 * right)
            elif right > left:
                left = right = 0
        left = right = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == "(":
                left += 1
            else:
                right += 1
            if left == right:
                maxlength = max(maxlength, 2 * left)
            elif left > right:
                left = right = 0
        return maxlength
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestValidParentheses(s: string): number {
    let left = 0,
        right = 0,
        maxlength = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === "(") {
            left++;
        } else {
            right++;
        }
        if (left === right) {
            maxlength = Math.max(maxlength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }
    left = right = 0;
    for (let i = s.length - 1; i >= 0; i--) {
        if (s[i] === "(") {
            left++;
        } else {
            right++;
        }
        if (left === right) {
            maxlength = Math.max(maxlength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }
    return maxlength;
}
```

</details>
