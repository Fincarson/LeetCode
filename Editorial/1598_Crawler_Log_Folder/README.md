# 1598. Crawler Log Folder

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/crawler-log-folder/)  
`Array` `String` `Stack`

**Problem Link:** [LeetCode 1598 - Crawler Log Folder](https://leetcode.com/problems/crawler-log-folder/)

## Problem

The Leetcode file system keeps a log each time some user performs a change folder operation.

The operations are described below:

- "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
- "./" : Remain in the same folder.
- "x/" : Move to the child folder named x (This folder is guaranteed to always exist).

You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

The file system starts in the main folder, then the operations in logs are performed.

Return the minimum number of operations needed to go back to the main folder after the change folder operations.

### Example 1

```text
Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
```

### Example 2

```text
Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3
```

### Example 3

```text
Input: logs = ["d1/","../","../","../"]
Output: 0
```

## Constraints

- 1 <= logs.length <= 103
- 2 <= logs[i].length <= 10
- logs[i] contains lowercase English letters, digits, '.', and '/'.
- logs[i] follows the format described in the statement.
- Folder names consist of lowercase English letters and digits.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Baseball Game](https://leetcode.com/problems/baseball-game/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1598. Crawler Log Folder

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Counter | C++, Java, Python3 |
| Stack | C++, Java, Python3 |

## Approach 1: Counter

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int folderDepth = 0;

        // Iterate through each log operation
        for (const auto& currentOperation : logs) {
            // Go up one directory if "../" is encountered, but don't go above
            // the root
            if (currentOperation == "../") {
                folderDepth = max(0, folderDepth - 1);
            }
            // Increase depth if the log is not 'stay in the current directory
            else if (currentOperation != "./") {
                // Go down one directory
                ++folderDepth;
            }
            // Ignore "./" operations as they don't change the current folder
        }

        return folderDepth;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minOperations(String[] logs) {
        int folderDepth = 0;

        // Iterate through each log operation
        for (String currentOperation : logs) {
            // Go up one directory if "../" is encountered, but don't go above the root
            if (currentOperation.equals("../")) {
                folderDepth = Math.max(0, folderDepth - 1);
            }
            // Increase depth if the log is not 'stay in the current directory'
            else if (!currentOperation.equals("./")) {
                // Go down one directory
                folderDepth++;
            }
            // Ignore "./" operations as they don't change the current folder
        }

        return folderDepth;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, logs: List[str]) -> int:
        folder_depth = 0

        # Iterate through each log operation
        for current_operation in logs:
            # Go up one directory if "../" is encountered, but don't go above the root
            if current_operation == "../":
                folder_depth = max(0, folder_depth - 1)
            # Increase depth if the log is not 'stay in the current directory'
            elif current_operation != "./":
                # Go down one directory
                folder_depth += 1
            # Ignore "./" operations as they don't change the current folder

        return folder_depth
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
    int minOperations(vector<string>& logs) {
        stack<string> folderStack;

        for (const string& currentOperation : logs) {
            if (currentOperation == "../") {
                // Move up to parent directory if not already at main folder
                if (!folderStack.empty()) {
                    folderStack.pop();
                }
            } else if (currentOperation != "./") {
                // Enter a new folder
                folderStack.push(currentOperation);
            }
            // Ignore "./" operations as they don't change the current folder
        }

        // The stack size represents the number of folders deep we are
        return folderStack.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minOperations(String[] logs) {
        Stack<String> folderStack = new Stack<>();

        for (String currentOperation : logs) {
            if (currentOperation.equals("../")) {
                // Move up to parent directory if not already at main folder
                if (!folderStack.empty()) {
                    folderStack.pop();
                }
            } else if (!currentOperation.equals("./")) {
                // Enter a new folder
                folderStack.push(currentOperation);
            }
            // Ignore "./" operations as they don't change the current folder
        }

        // The stack size represents the number of folders deep we are
        return folderStack.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, logs: List[str]) -> int:
        folder_stack = []

        for current_operation in logs:
            if current_operation == "../":
                # Move up to parent directory if not already at main folder
                if folder_stack:
                    folder_stack.pop()
            elif current_operation != "./":
                # Enter a new folder
                folder_stack.append(current_operation)
            # Ignore "./" operations as they don't change the current folder
        # The stack size represents the number of folders deep we are
        return len(folder_stack)
```

</details>
