# 20. Valid Parentheses

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/valid-parentheses/)  
`String` `Stack`

**Problem Link:** [LeetCode 20 - Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

## Problem

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

### Example 1

### Example 2

### Example 3

### Example 4

### Example 5

## Constraints

- 1 <= s.length <= 104
- s consists of parentheses only '()[]{}'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Check If Word Is Valid After Substitutions](https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Move Pieces to Obtain a String](https://leetcode.com/problems/move-pieces-to-obtain-a-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 20. Valid Parentheses

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Stacks | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Stacks

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    char key[3];
    char val;
    UT_hash_handle hh;
} my_hash;
my_hash* mappings = NULL;
void initMappings() {
    char keys[3] = {'}', ']', ')'};
    char values[3] = {'{', '[', '('};
    for (int i = 0; i < 3; i++) {
        my_hash* some_data = malloc(sizeof *some_data);
        some_data->key[0] = keys[i];
        some_data->key[1] = '\0';
        some_data->val = values[i];
        HASH_ADD_STR(mappings, key, some_data);
    }
}
bool isValid(char* s) {
    initMappings();  // create mappings
    int top = -1;
    char* stack = (char*)malloc(strlen(s) + 1);
    for (int i = 0; s[i]; i++) {
        my_hash* m = NULL;
        char key[3] = {s[i], '\0'};
        HASH_FIND_STR(mappings, key, m);
        if (m == NULL) {
            stack[++top] = s[i];
        } else {
            if (top < 0 || stack[top--] != m->val) {
                return false;
            }
        }
    }
    bool ret = top == -1;
    HASH_CLEAR(hh, mappings);  // clean mappings for next call
    free(stack);
    return ret;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    unordered_map<char, char> mappings;

public:
    Solution() {
        mappings[')'] = '(';
        mappings['}'] = '{';
        mappings[']'] = '[';
    }
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (mappings.find(c) != mappings.end()) {  // closing bracket
                // get the top element of the stack, if stack is empty, set a
                // dummy value '#'
                char topElement = stk.empty() ? '#' : stk.top();
                stk.pop();
                // if the mapping for this bracket doesn't match the stack's top
                // element, return false.
                if (topElement != mappings[c]) {
                    return false;
                }
            } else {  // opening bracket
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private Dictionary<char, char> mappings;

    public Solution() {
        mappings = new Dictionary<char, char> {
            { ')', '(' }, { '}', '{' }, { ']', '[' }
        };
    }

    public bool IsValid(string s) {
        var stack = new Stack<char>();
        foreach (var c in s) {
            if (mappings.ContainsKey(c)) {
                char topElement = stack.Count == 0 ? '#' : stack.Pop();
                if (topElement != mappings[c]) {
                    return false;
                }
            } else {
                stack.Push(c);
            }
        }

        return stack.Count == 0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isValid(s string) bool {
    mappings := map[rune]rune{')': '(', '}': '{', ']': '['}
    stack := make([]rune, 0)
    for _, c := range s {
        if val, ok := mappings[c]; ok {
            var topElement rune = '#'
            if len(stack) != 0 {
                topElement, stack = stack[len(stack)-1], stack[:len(stack)-1]
            }
            if topElement != val {
                return false
            }
        } else {
            stack = append(stack, c)
        }
    }
    return len(stack) == 0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Hash table that takes care of the mappings.
    private HashMap<Character, Character> mappings;

    // Initialize hash map with mappings. This simply makes the code easier to read.
    public Solution() {
        this.mappings = new HashMap<Character, Character>();
        this.mappings.put(')', '(');
        this.mappings.put('}', '{');
        this.mappings.put(']', '[');
    }

    public boolean isValid(String s) {
        // Initialize a stack to be used in the algorithm.
        Stack<Character> stack = new Stack<Character>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            // If the current character is a closing bracket.
            if (this.mappings.containsKey(c)) {
                // Get the top element of the stack. If the stack is empty, set a dummy value of '#'
                char topElement = stack.empty() ? '#' : stack.pop();

                // If the mapping for this bracket doesn't match the stack's top element, return false.
                if (topElement != this.mappings.get(c)) {
                    return false;
                }
            } else {
                // If it was an opening bracket, push to the stack.
                stack.push(c);
            }
        }

        // If the stack still contains elements, then it is an invalid expression.
        return stack.isEmpty();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isValid = function (s) {
    const mappings = {
        ")": "(",
        "}": "{",
        "]": "[",
    };
    const stack = [];
    for (let c of s) {
        if (mappings[c]) {
            const topElement = stack.length ? stack.pop() : "#";
            if (topElement !== mappings[c]) {
                return false;
            }
        } else {
            stack.push(c);
        }
    }
    return stack.length === 0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def isValid(self, s: str) -> bool:

        # The stack to keep track of opening brackets.
        stack = []

        # Hash map for keeping track of mappings. This keeps the code very clean.
        # Also makes adding more types of parenthesis easier
        mapping = {")": "(", "}": "{", "]": "["}

        # For every bracket in the expression.
        for char in s:

            # If the character is an closing bracket
            if char in mapping:

                # Pop the topmost element from the stack, if it is non empty
                # Otherwise assign a dummy value of '#' to the top_element variable
                top_element = stack.pop() if stack else "#"

                # The mapping for the opening bracket in our hash and the top
                # element of the stack don't match, return False
                if mapping[char] != top_element:
                    return False
            else:
                # We have an opening bracket, simply push it onto the stack.
                stack.append(char)

        # In the end, if the stack is empty, then we have a valid expression.
        # The stack won't be empty for cases like ((()
        return not stack
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isValid(s: string): boolean {
    const mappings: { [key: string]: string } = {
        ")": "(",
        "}": "{",
        "]": "[",
    };
    const stack: string[] = [];
    for (let c of s) {
        if (mappings[c]) {
            const topElement = stack.length ? stack.pop() : "#";
            if (topElement !== mappings[c]) {
                return false;
            }
        } else {
            stack.push(c);
        }
    }
    return stack.length === 0;
}
```

</details>
