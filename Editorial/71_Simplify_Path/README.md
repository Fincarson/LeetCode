# 71. Simplify Path

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/simplify-path/)  
`String` `Stack`

**Problem Link:** [LeetCode 71 - Simplify Path](https://leetcode.com/problems/simplify-path/)

## Problem

You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

- A single period '.' represents the current directory.
- A double period '..' represents the previous/parent directory.
- Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
- Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.

The simplified canonical path should follow these rules:

- The path must start with a single slash '/'.
- Directories within the path must be separated by exactly one slash '/'.
- The path must not end with a slash '/', unless it is the root directory.
- The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.

Return the simplified canonical path.

### Example 1

### Example 2

### Example 3

### Example 4

### Example 5

## Constraints

- 1 <= path.length <= 3000
- path consists of English letters, digits, period '.', slash '/' or '_'.
- path is a valid absolute Unix path.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 71. Simplify Path

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Using Stacks | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Using Stacks

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char *simplifyPath(char *path) {
    // Initialize a stack
    char *stack[1000];
    unsigned stackIdx = 0;
    // Used for split string by '/'
    char *token = strtok(path, "/");
    while (token) {
        // If the current component is a "..", then
        // we pop an entry from the stack if it's non-empty
        if (strcmp(token, "..") == 0) {
            if (stackIdx > 0) {
                stackIdx--;
            }
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            // Finally, a legitimate directory name, so we add it
            // to our stack
            stack[stackIdx] = token;
            stackIdx++;
        }
        token = strtok(NULL, "/");
    }
    // Construct simplified path
    char *res = (char *)malloc(sizeof(char) * 3000);
    memset(res, 0, sizeof(char) * 3000);
    for (unsigned i = 0; i < stackIdx; i++) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }
    if (strcmp(res, "") == 0)
        return "/";
    else
        return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        // Initialize a stack
        vector<string> stack;
        // Used for split string by '/'
        stringstream ss(path);
        string temp;
        while (getline(ss, temp, '/')) {
            // If the current component is a "..", then
            // we pop an entry from the stack if it's non-empty
            if (temp == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (temp != "." && !temp.empty()) {
                // Finally, a legitimate directory name, so we add it
                // to our stack
                stack.push_back(temp);
            }
        }
        // Construct simplified path
        string res = "";
        for (auto str : stack) res += "/" + str;
        if (res.empty())
            return "/";
        else
            return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string SimplifyPath(string path) {
        // Initialize a stack
        Stack<string> stack = new Stack<string>();
        string[] components = path.Split('/');
        // Split the input string on "/" as the delimiter
        // and process each portion one by one
        foreach (string directory in components) {
            // A no-op for a "." or an empty string
            if (directory.Equals(".") || directory.Length == 0) {
                continue;
            } else if (directory.Equals("..")) {
                // If the current component is a "..", then
                // we pop an entry from the stack if it's non-empty
                if (stack.Any()) {
                    stack.Pop();
                }
            } else {
                // Finally, a legitimate directory name, so we add it
                // to our stack
                stack.Push(directory);
            }
        }

        // Stich together all the directory names together
        StringBuilder result = new StringBuilder();
        foreach (string dir in stack.Reverse()) {
            result.Append("/");
            result.Append(dir);
        }

        return result.Length > 0 ? result.ToString() : "/";
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func simplifyPath(path string) string {
    // Split string into portions
    portions := strings.Split(path, "/")
    // Initialize a 'stack'
    stack := []string{}
    // For each portion...
    for _, portion := range portions {
        // If portion is "..", pop the stack unless it's empty
        if portion == ".." {
            if len(stack) > 0 {
                stack = stack[:len(stack)-1]
            }
        } else if portion != "." && len(portion) > 0 {
            // If portion isn't "." and not empty, append to stack
            stack = append(stack, portion)
        }
    }
    // Concatenate portions to simple path and return
    return "/" + strings.Join(stack, "/")
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String simplifyPath(String path) {
        // Initialize a stack
        Stack<String> stack = new Stack<String>();
        String[] components = path.split("/");

        // Split the input string on "/" as the delimiter
        // and process each portion one by one
        for (String directory : components) {
            // A no-op for a "." or an empty string
            if (directory.equals(".") || directory.isEmpty()) {
                continue;
            } else if (directory.equals("..")) {
                // If the current component is a "..", then
                // we pop an entry from the stack if it's non-empty
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                // Finally, a legitimate directory name, so we add it
                // to our stack
                stack.add(directory);
            }
        }

        // Stich together all the directory names together
        StringBuilder result = new StringBuilder();
        for (String dir : stack) {
            result.append("/");
            result.append(dir);
        }

        return result.length() > 0 ? result.toString() : "/";
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var simplifyPath = function (path) {
    // Initialize a stack
    let stack = [];
    // Split the input string on "/" as the delimiter
    // and process each portion one by one
    for (let portion of path.split("/")) {
        // If the current component is a "..", then
        // we pop an entry from the stack if it's non-empty
        if (portion === "..") {
            if (stack.length) {
                stack.pop();
            }
        } else if (portion === "." || !portion) {
            // A no-op for a "." or an empty string
            continue;
        } else {
            // Finally, a legitimate directory name, so we add it
            // to our stack
            stack.push(portion);
        }
    }
    // Stich together all the directory names together
    return "/" + stack.join("/");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def simplifyPath(self, path: str) -> str:

        # Initialize a stack
        stack = []

        # Split the input string on "/" as the delimiter
        # and process each portion one by one
        for portion in path.split("/"):

            # If the current component is a "..", then
            # we pop an entry from the stack if it's non-empty
            if portion == "..":
                if stack:
                    stack.pop()
            elif portion == "." or not portion:
                # A no-op for a "." or an empty string
                continue
            else:
                # Finally, a legitimate directory name, so we add it
                # to our stack
                stack.append(portion)

        # Stich together all the directory names together
        final_str = "/" + "/".join(stack)
        return final_str
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function simplifyPath(path: string): string {
    // Initialize a stack
    let stack: string[] = [];
    // Split the input string on "/" as the delimiter
    // and process each portion one by one
    for (let portion of path.split("/")) {
        // If the current component is a "..", then
        // we pop an entry from the stack if it's non-empty
        if (portion === "..") {
            if (stack.length) {
                stack.pop();
            }
        } else if (portion === "." || !portion) {
            // A no-op for a "." or an empty string
            continue;
        } else {
            // Finally, a legitimate directory name, so we add it
            // to our stack
            stack.push(portion);
        }
    }
    // Stich together all the directory names together
    return "/" + stack.join("/");
}
```

</details>
