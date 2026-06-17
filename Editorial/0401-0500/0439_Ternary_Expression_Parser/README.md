# 439. Ternary Expression Parser

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/ternary-expression-parser/)  
`String` `Stack` `Recursion`

**Problem Link:** [LeetCode 439 - Ternary Expression Parser](https://leetcode.com/problems/ternary-expression-parser/)

## Problem

Given a string expression representing arbitrarily nested ternary expressions, evaluate the expression, and return the result of it.

You can always assume that the given expression is valid and only contains digits, '?', ':', 'T', and 'F' where 'T' is true and 'F' is false. All the numbers in the expression are one-digit numbers (i.e., in the range [0, 9]).

The conditional expressions group right-to-left (as usual in most languages), and the result of the expression will always evaluate to either a digit, 'T' or 'F'.

### Example 1

```text
Input: expression = "T?2:3"
Output: "2"
Explanation: If true, then result is 2; otherwise result is 3.
```

### Example 2

```text
Input: expression = "F?1:T?4:5"
Output: "4"
Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:
"(F ? 1 : (T ? 4 : 5))" --> "(F ? 1 : 4)" --> "4"
or "(F ? 1 : (T ? 4 : 5))" --> "(T ? 4 : 5)" --> "4"
```

### Example 3

```text
Input: expression = "T?T?F:5:3"
Output: "F"
Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:
"(T ? (T ? F : 5) : 3)" --> "(T ? F : 3)" --> "F"
"(T ? (T ? F : 5) : 3)" --> "(T ? F : 5)" --> "F"
```

## Constraints

- 5 <= expression.length <= 104
- expression consists of digits, 'T', 'F', '?', and ':'.
- It is guaranteed that expression is a valid ternary expression and that each number is a one-digit number.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Mini Parser](https://leetcode.com/problems/mini-parser/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Remove Comments](https://leetcode.com/problems/remove-comments/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Parse Lisp Expression](https://leetcode.com/problems/parse-lisp-expression/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 439. Ternary Expression Parser

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Find Rightmost Atomic Expression | C++, Java, Python3 |
| Reverse Polish Notation | C++, Java, Python3 |
| Reverse Polish Notation using Stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary Tree | Java, Python3 |
| Recursion | Java, Python3 |
| Constant Space Solution | C++, Java, JavaScript, Python3 |

## Approach 1: Find Rightmost Atomic Expression

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string parseTernary(string expression) {
        
        // Checks if the string s is a valid atomic expression
        auto isValidAtomic = [](string s) {
            return (s[0] == 'T' || s[0] == 'F') && s[1] == '?' && ((s[2] >= '0' && s[2] <= '9') || s[2] == 'T' || s[2] == 'F') && s[3] == ':' && ((s[4] >= '0' && s[4] <= '9') || s[4] == 'T' || s[4] == 'F'); 
        };
        
        // Returns the value of the atomic expression
        auto solveAtomic = [](string s) {
            return s[0] == 'T' ? s[2] : s[4];
        };
        
        // Reduce expression until we are left with a single character
        while (expression.size() != 1) {
            int j = expression.size() - 1;
            while (!isValidAtomic(expression.substr(j-4, 5))) {
                j--;
            }
            expression = expression.substr(0, j-4) + solveAtomic(expression.substr(j-4, 5)) + expression.substr(j+1);
        }
        
        // Return the final character
        return expression;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String parseTernary(String expression) {
        
        // Checks if the string s is a valid atomic expression
        Predicate<String> isValidAtomic = s -> (s.charAt(0) == 'T' || s.charAt(0) == 'F') && s.charAt(1) == '?' && ((s.charAt(2) >= '0' && s.charAt(2) <= '9') || s.charAt(2) == 'T' || s.charAt(2) == 'F') && s.charAt(3) == ':' && ((s.charAt(4) >= '0' && s.charAt(4) <= '9') || s.charAt(4) == 'T' || s.charAt(4) == 'F');
        
        // Returns the value of the atomic expression
        Function<String, String> solveAtomic = s -> s.charAt(0) == 'T' ? s.substring(2, 3) : s.substring(4, 5);
        
        // Reduce expression until we are left with a single character
        while (expression.length() != 1) {
            int j = expression.length() - 1;
            while (!isValidAtomic.test(expression.substring(j-4, j+1))) {
                j--;
            }
            expression = expression.substring(0, j-4) + solveAtomic.apply(expression.substring(j-4, j+1)) + expression.substring(j+1, expression.length());
        }
        
        // Return the final character
        return expression;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def parseTernary(self, expression: str) -> str:

        # Checks if the string s is a valid atomic expression
        def isValidAtomic(s):
            return s[0] in 'TF' and s[1] == '?' and s[2] in 'TF0123456789'\
                and s[3] == ':' and s[4] in 'TF0123456789'

        # Returns the value of the atomic expression
        def solveAtomic(s):
            return s[2] if s[0] == 'T' else s[4]

        # Reduce expression until we are left with a single character
        while len(expression) != 1:
            j = len(expression) - 1
            while not isValidAtomic(expression[j-4:j+1]):
                j -= 1
            expression = expression[:j-4] + \
                solveAtomic(expression[j-4:j+1]) + expression[j+1:]

        # Return the final character
        return expression
```

</details>

<br>

## Approach 2: Reverse Polish Notation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string parseTernary(string expression) {
        
        // Reduce expression until we are left with a single character
        while (expression.size() != 1) {
            int questionMarkIndex = expression.size() - 1;
            while (expression[questionMarkIndex] != '?') {
                questionMarkIndex--;
            }
            
            // Find the value of the expression.
            char value;
            if (expression[questionMarkIndex - 1] == 'T') {
                value = expression[questionMarkIndex + 1];
            } else {
                value = expression[questionMarkIndex + 3];
            }
            
            // Replace the expression with the value
            expression = expression.substr(0, questionMarkIndex - 1) + value + expression.substr(questionMarkIndex + 4);
        }
        
        // Return the final character
        return expression;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String parseTernary(String expression) {
        
        // Reduce expression until we are left with a single character
        while (expression.length() != 1) {
            int questionMarkIndex = expression.length() - 1;
            while (expression.charAt(questionMarkIndex) != '?') {
                questionMarkIndex--;
            }
            
            // Find the value of the expression.
            char value;
            if (expression.charAt(questionMarkIndex - 1) == 'T') {
                value = expression.charAt(questionMarkIndex + 1);
            } else {
                value = expression.charAt(questionMarkIndex + 3);
            }
            
            // Replace the expression with the value
            expression = expression.substring(0, questionMarkIndex - 1) + value + expression.substring(questionMarkIndex + 4);
        }
        
        // Return the final character
        return expression;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def parseTernary(self, expression: str) -> str:

        # Reduce expression until we are left with a single character
        while len(expression) != 1:
            questionMarkIndex = len(expression) - 1
            while expression[questionMarkIndex] != '?':
                questionMarkIndex -= 1

            # Find the value of the expression.
            if expression[questionMarkIndex - 1] == 'T':
                value = expression[questionMarkIndex + 1]
            else:
                value = expression[questionMarkIndex + 3]

            # Replace the expression with the value
            expression = expression[:questionMarkIndex - 1] + value\
                + expression[questionMarkIndex + 4:]

        # Return the final character
        return expression
```

</details>

<br>

## Approach 3: Reverse Polish Notation using Stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char * parseTernary(char * expression){

    // Initialize a stack
    char stack[10001];
    int top = -1;
    int i = strlen(expression) - 1;

    // Traverse the expression from right to left
    while (i >= 0) {

        // Current character
        char curr = expression[i];
        
        // Push every T, F, and digit on the stack
        if (curr >= '0' && curr <= '9' || curr == 'T' || curr == 'F') {
            stack[++top] = curr;
        }
        
        // As soon as we encounter ?, 
        // replace top two elements of the stack with one
        else if (curr == '?') {
            char onTrue = stack[top--];
            char onFalse = stack[top--];
            stack[++top] = (expression[--i] == 'T') ? onTrue : onFalse;
        }
        
        // Go to the previous character
        i--;
    }

    // Return the final character. 
    char *result = (char *)malloc(2 * sizeof(char));
    result[0] = stack[top];
    result[1] = '\0';
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string parseTernary(string expression) {
        
        // Initialize a stack
        stack<char> stack;
        int i = expression.size() - 1;

        // Traverse the expression from right to left
        while (i >= 0) {

            // Current character
            char curr = expression[i];
            
            // Push every T, F, and digit on the stack
            if (curr >= '0' && curr <= '9' || curr == 'T' || curr == 'F') {
                stack.push(curr);
            }
            
            // As soon as we encounter ?, 
            // replace top two elements of the stack with one
            else if (curr == '?') {
                char onTrue = stack.top();
                stack.pop();
                char onFalse = stack.top();
                stack.pop();
                stack.push(expression[i - 1] == 'T' ? onTrue : onFalse);
                
                // Decrement i by 1 as we have already used
                // Previous Boolean character
                i--;
            }
            
            // Go to the previous character
            i--;
        }
        
        // Return the final character
        return string(1, stack.top());
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string ParseTernary(string expression) {
        
        // Initialize a stack
        Stack<char> stack = new Stack<char>();
        int i = expression.Length - 1;

        // Traverse the expression from right to left
        while (i >= 0) {

            // Current character
            char curr = expression[i];
            
            // Push every T, F, and digit on the stack
            if (curr >= '0' && curr <= '9' || curr == 'T' || curr == 'F') {
                stack.Push(curr);
            }
            
            // As soon as we encounter ?, 
            // replace top two elements of the stack with one
            else if (curr == '?') {
                char onTrue = stack.Pop();
                char onFalse = stack.Pop();
                stack.Push(expression[i - 1] == 'T' ? onTrue : onFalse);
                
                // Decrement i by 1 as we have already used
                // Previous Boolean character
                i--;
            }
            
            // Go to the previous character
            i--;
        }
        
        // Return the final character
        return stack.Pop().ToString();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func parseTernary(expression string) string {
    
    // Initialize a stack
    stack := []rune{}
    i := len(expression) - 1

    // Traverse the expression from right to left
    for i >= 0 {

        // Current character
        curr := rune(expression[i])
        
        // Push every T, F, and digit on the stack
        if curr >= '0' && curr <= '9' || curr == 'T' || curr == 'F' {
            stack = append(stack, curr)
        }
        
        // As soon as we encounter ?, 
        // replace top two elements of the stack with one
        if curr == '?' {
            onTrue := stack[len(stack) - 1]
            onFalse := stack[len(stack) - 2]
            stack = stack[:len(stack) - 2]
            if expression[i - 1] == 'T' {
                stack = append(stack, onTrue)
            } else {
                stack = append(stack, onFalse)
            }
            
            // Decrement i by 1 as we have already used
            // Previous Boolean character
            i -= 1
        }
        
        // Go to the previous character
        i -= 1
    }
    
    // Return the final character
    return string(stack[len(stack) - 1])
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String parseTernary(String expression) {
        
        // Initialize a stack
        Stack<Character> stack = new Stack<>();
        int i = expression.length() - 1;

        // Traverse the expression from right to left
        while (i >= 0) {

            // Current character
            char curr = expression.charAt(i);
            
            // Push every T, F, and digit on the stack
            if (curr >= '0' && curr <= '9' || curr == 'T' || curr == 'F') {
                stack.push(curr);
            }
            
            // As soon as we encounter ?, 
            // replace top two elements of the stack with one
            else if (curr == '?') {
                char onTrue = stack.pop();
                char onFalse = stack.pop();
                stack.push(expression.charAt(i - 1) == 'T' ? onTrue : onFalse);
                
                // Decrement i by 1 as we have already used
                // Previous Boolean character
                i--;
            }
            
            // Go to the previous character
            i--;
        }
        
        // Return the final character
        return String.valueOf(stack.peek());
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} expression
 * @return {string}
 */
var parseTernary = function(expression) {
    
    // Initialize a stack
    let stack = [];
    let i = expression.length - 1;

    // Traverse the expression from right to left
    while (i >= 0) {

        // Current character
        let curr = expression[i];
        
        // Push every T, F, and digit on the stack
        if (curr >= '0' && curr <= '9' || curr == 'T' || curr == 'F') {
            stack.push(curr);
        }
        
        // As soon as we encounter ?, 
        // replace top two elements of the stack with one
        else if (curr == '?') {
            let onTrue = stack.pop();
            let onFalse = stack.pop();
            stack.push(expression[i - 1] == 'T' ? onTrue : onFalse);
            
            // Decrement i by 1 as we have already used
            // Previous Boolean character
            i--;
        }
        
        // Go to the previous character
        i--;
    }
    
    // Return the final character
    return stack.pop();
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def parseTernary(self, expression: str) -> str:
        
        # Initialize a stack
        stack = []
        i = len(expression) - 1

        # Traverse the expression from right to left
        while i >= 0:

            # Current character
            char = expression[i]
            
            # Push every T, F, and digit on the stack
            if char in 'TF0123456789':
                stack.append(char)
            
            # As soon as we encounter ?, 
            # replace top two elements of the stack with one
            elif char == '?':
                onTrue = stack.pop()
                onFalse = stack.pop()
                stack.append(onTrue if expression[i - 1] == 'T' else onFalse)
                
                # Decrement i by 1 as we have already used
                # Previous Boolean character
                i -= 1
            
            # Go to the previous character
            i -= 1
        
        # Return the final character
        return stack[0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function parseTernary(expression: string): string {
    // Initialize a stack
    const stack: string[] = [];
    let i = expression.length - 1;

    // Traverse the expression from right to left
    while (i >= 0) {

        // Current character
        const curr = expression[i];

        // Push every T, F, and digit on the stack
        if (curr >= '0' && curr <= '9' || curr === 'T' || curr === 'F') {
            stack.push(curr);
        }

        // As soon as we encounter ?,
        // replace top two elements of the stack with one
        else if (curr === '?') {
            const onTrue = stack.pop();
            const onFalse = stack.pop();
            stack.push(expression[i - 1] === 'T' ? onTrue : onFalse);

            // Decrement i by 1 as we have already used
            // Previous Boolean character
            i -= 1;
        }

        // Go to the previous character
        i -= 1;
    }

    // Return the final character
    return stack.pop();
};
```

</details>

<br>

## Approach 4: Binary Tree

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class TreeNode {
    char val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(char val) {
        this.val = val;
    }
}

class Solution {
    int index = 0;
    
    public String parseTernary(String expression) {
        
        // Construct Binary Tree
        TreeNode root = constructTree(expression);
        
        // Parse the binary tree till we reach the leaf node
        while (root.left != null && root.right != null) {
            if (root.val == 'T') {
                root = root.left;
            } else {
                root = root.right;
            }
        }
        
        return String.valueOf(root.val);
    }
    
    private TreeNode constructTree(String expression) {
        
        // Storing current character of expression
        TreeNode root = new TreeNode(expression.charAt(index));

        // If last character of expression, return
        if (index == expression.length() - 1) {
            return root;
        }
        
        // Check next character
        index++;
        if (expression.charAt(index) == '?') {
            index++;
            root.left = constructTree(expression);
            index++;
            root.right = constructTree(expression);
        }
        
        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def parseTernary(self, expression: str) -> str:
        
        # Global Index to Construct Binary Tree
        self.index = 0
        root = self.constructTree(expression)
        
        # Parse the binary tree till we reach the leaf node
        while root.left and root.right:
            if root.val == 'T':
                root = root.left
            else:
                root = root.right
        
        return root.val

    def constructTree(self, expression):
        
        # Storing current character of expression
        root = TreeNode(expression[self.index])

        # If the last character of expression, return
        if self.index == len(expression) - 1:
            return root
        
        # Check the next character
        self.index += 1
        if expression[self.index] == '?':
            self.index += 1
            root.left = self.constructTree(expression)
            self.index += 1
            root.right = self.constructTree(expression)
            
        return root
```

</details>

<br>

## Approach 5: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String parseTernary(String expression) {
        return solve(expression, 0, expression.length() - 1);
    }
    
    private String solve(String expression, int i, int j) {
        
        // If expression is a single character, return it
        if (i == j) {
            return expression.substring(i, i + 1);
        }
        
        // Find the index of ?
        int questionMarkIndex = i;
        while (expression.charAt(questionMarkIndex) != '?') {
            questionMarkIndex++;
        }
        
        // Find one index after corresponding :
        int aheadColonIndex = questionMarkIndex + 1;
        int count = 1;
        while (count != 0) {
            if (expression.charAt(aheadColonIndex) == '?') {
                count++;
            } else if (expression.charAt(aheadColonIndex) == ':') {
                count--;
            }
            aheadColonIndex++;
        }
        
        // Check the value of B and recursively solve
        if (expression.charAt(i) == 'T') {
            return solve(expression, questionMarkIndex + 1, aheadColonIndex - 2);
        } else {
            return solve(expression, aheadColonIndex, j);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def parseTernary(self, expression: str) -> str:

        # To analyze the expression between two indices
        def solve(i, j):

            # If expression is a single character, return it
            if i == j:
                return expression[i]

            # Find the index of ?
            questionMarkIndex = i
            while expression[questionMarkIndex] != '?':
                questionMarkIndex += 1

            # Find one index after corresponding :
            aheadColonIndex = questionMarkIndex + 1
            count = 1
            while count != 0:
                if expression[aheadColonIndex] == '?':
                    count += 1
                elif expression[aheadColonIndex] == ':':
                    count -= 1
                aheadColonIndex += 1

            # Check the value of B and recursively solve
            if expression[i] == 'T':
                return solve(questionMarkIndex + 1, aheadColonIndex - 2)
            else:
                return solve(aheadColonIndex, j)

        # Solve for the entire expression
        return solve(0, len(expression) - 1)
```

</details>

<br>

## Approach 6: Constant Space Solution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string parseTernary(string expression) {
        
        // Pointer for Traversal. It will maintain Loop Invariant.
        int i = 0;
        
        // Loop invariant: We will always be at the first character of 
        // expression which we should FOCUS on.
        while (true) {
            
            // If this first character is not boolean, it means no nesting
            // is there. Thus, we can simply return this character.
            if (expression[i] != 'T' && expression[i] != 'F') {
                return string(1, expression[i]);
            }
            
            // If this is last character, then we can simply return this
            if (i == expression.length() - 1) {
                return string(1, expression[i]);
            }
            
            // If succeeding character is :, it means we have processed
            // the FOCUS part. Ignore the ahead part and return this character.
            if (expression[i + 1] == ':') {
                return string(1, expression[i]);
            }

            // Now it means this character is boolean followed by ?.
            // If this boolean is T, then process after ? sub-expression.
            if (expression[i] == 'T') {
                i = i + 2;
            }
            
            // If this boolean is F, then make i point to the character
            // after ": of this ?". To have corresponding :, we 
            // can maintain count
            else {
                int count = 1;
                i = i + 2;
                while (count != 0) {
                    if (expression[i] == ':') {
                        count--;
                    } else if (expression[i] == '?') {
                        count++;
                    }
                    i++;
                }
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String parseTernary(String expression) {
        
        // Pointer for Traversal. It will maintain Loop Invariant.
        int i = 0;
        
        // Loop invariant: We will always be at the first character of 
        // expression which we should FOCUS on.
        while (true) {
            
            // If this first character is not boolean, it means no nesting
            // is there. Thus, we can simply return this character.
            if (expression.charAt(i) != 'T' && expression.charAt(i) != 'F') {
                return String.valueOf(expression.charAt(i));
            }
            
            // If this is last character, then we can simply return this
            if (i == expression.length() - 1) {
                return String.valueOf(expression.charAt(i));
            }
            
            // If succeeding character is :, it means we have processed
            // the FOCUS part. Ignore the ahead part and return this character.
            if (expression.charAt(i + 1) == ':') {
                return String.valueOf(expression.charAt(i));
            }

            // Now it means this character is boolean followed by ?.
            // If this boolean is T, then process after ? sub-expression.
            if (expression.charAt(i) == 'T') {
                i = i + 2;
            }
            
            // If this boolean is F, then make i point to the character
            // after ": of this ?". To have corresponding :, we 
            // can maintain count
            else {
                int count = 1;
                i = i + 2;
                while (count != 0) {
                    if (expression.charAt(i) == ':') {
                        count--;
                    } else if (expression.charAt(i) == '?') {
                        count++;
                    }
                    i++;
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var parseTernary = function(expression) {
    
    // Pointer for Traversal. It will maintain Loop Invariant.
    let i = 0;
    
    // Loop invariant: We will always be at the first character of 
    // expression which we should FOCUS on.
    while (true) {
        
        // If this first character is not boolean, it means no nesting
        // is there. Thus, we can simply return this character.
        if (!['T', 'F'].includes(expression[i])) {
            return expression[i];
        }
        
        // If this is last character, then we can simply return this
        if (i == expression.length - 1) {
            return expression[i];
        }
        
        // If succeeding character is :, it means we have processed
        // the FOCUS part. Ignore the ahead part and return this character.
        if (expression[i + 1] == ':') {
            return expression[i];
        }

        // Now it means this character is boolean followed by ?.
        // If this boolean is T, then process after ? sub-expression.
        if (expression[i] == 'T') {
            i = i + 2;
        }
        
        // If this boolean is F, then make i point to the character
        // after ": of this ?". To have corresponding :, we 
        // can maintain count
        else {
            let count = 1;
            i = i + 2;
            while (count != 0) {
                if (expression[i] == ':') {
                    count--;
                } else if (expression[i] == '?') {
                    count++;
                }
                i++;
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def parseTernary(self, expression: str) -> str:
        
        # Pointer for Traversal. It will maintain Loop Invariant.
        i = 0
        
        # Loop invariant: We will always be at the first character of 
        # expression which we should FOCUS on.
        while True:
            
            # If this first character is not boolean, it means no nesting
            # is there. Thus, we can simply return this character.
            if expression[i] not in 'TF':
                answer = expression[i]
                break
            
            # If this is last character, then we can simply return this
            if i == len(expression) - 1:
                answer = expression[i]
                break
            
            # If succeeding character is :, it means we have processed
            # the FOCUS part. Ignore the ahead part and return this character.
            if expression[i + 1] == ':':
                answer = expression[i]
                break

            # Now it means this character is boolean followed by ?.
            # If this boolean is T, then process after ? sub-expression.
            if expression[i] == 'T':
                i = i + 2
            
            # If this boolean is F, then make i point to the character
            # after ": of this ?". To have corresponding :, we 
            # can maintain count
            else:
                count = 1
                i = i + 2
                while count != 0:
                    if expression[i] == ':':
                        count -= 1
                    elif expression[i] == '?':
                        count += 1
                    i += 1
        
        # Return Answer Character
        return answer
```

</details>
