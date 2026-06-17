# 1653. Minimum Deletions to Make String Balanced

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/)  
`String` `Dynamic Programming` `Stack`

**Problem Link:** [LeetCode 1653 - Minimum Deletions to Make String Balanced](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/)

## Problem

You are given a string s consisting only of characters 'a' and 'b'Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

### Example 1

```text
Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
```

### Example 2

```text
Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
```

## Constraints

- 1 <= s.length <= 105
- s[i] is 'a' or 'b'Ã¢â‚¬â€¹Ã¢â‚¬â€¹.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1653. Minimum Deletions to Make String Balanced

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Three-Pass Count Method | C++, Java, Python3 |
| Combined Pass Method | C++, Java, Python3 |
| Two-Variable Method | C++, Java, Python3 |
| Using stack (one pass) | C++, Java, Python3 |
| Using DP (One Pass) | C++, Java, Python3 |
| Optimized DP | C++, Java, Python3 |

## Approach 1: Three-Pass Count Method

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> count_a(n, 0);
        vector<int> count_b(n, 0);
        int b_count = 0;

        // First pass: compute count_b which stores the number of
        // 'b' characters to the left of the current position.
        for (int i = 0; i < n; i++) {
            count_b[i] = b_count;
            if (s[i] == 'b') b_count++;
        }

        int a_count = 0;
        // Second pass: compute count_a which stores the number of
        // 'a' characters to the right of the current position
        for (int i = n - 1; i >= 0; i--) {
            count_a[i] = a_count;
            if (s[i] == 'a') a_count++;
        }

        int min_deletions = n;
        // Third pass: iterate through the string to find the minimum deletions
        for (int i = 0; i < n; i++) {
            min_deletions = min(min_deletions, count_a[i] + count_b[i]);
        }

        return min_deletions;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDeletions(String s) {
        int n = s.length();
        int[] countA = new int[n];
        int[] countB = new int[n];
        int bCount = 0;

        // First pass: compute count_b which stores the number of
        // 'b' characters to the left of the current position.
        for (int i = 0; i < n; i++) {
            countB[i] = bCount;
            if (s.charAt(i) == 'b') bCount++;
        }

        int aCount = 0;
        // Second pass: compute count_a which stores the number of
        // 'a' characters to the right of the current position
        for (int i = n - 1; i >= 0; i--) {
            countA[i] = aCount;
            if (s.charAt(i) == 'a') aCount++;
        }

        int minDeletions = n;
        // Third pass: iterate through the string to find the minimum deletions
        for (int i = 0; i < n; i++) {
            minDeletions = Math.min(minDeletions, countA[i] + countB[i]);
        }

        return minDeletions;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        count_a = [0] * n
        count_b = [0] * n
        b_count = 0

        # First pass: compute count_b which stores the number of
        # 'b' characters to the left of the current position.
        for i in range(n):
            count_b[i] = b_count
            if s[i] == "b":
                b_count += 1

        a_count = 0
        # Second pass: compute count_a which stores the number of
        # 'a' characters to the right of the current position
        for i in range(n - 1, -1, -1):
            count_a[i] = a_count
            if s[i] == "a":
                a_count += 1

        min_deletions = n
        # Third pass: iterate through the string to find the minimum deletions
        for i in range(n):
            min_deletions = min(min_deletions, count_a[i] + count_b[i])
        return min_deletions
```

</details>

<br>

## Approach 2: Combined Pass Method

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> count_a(n, 0);
        int a_count = 0;

        // First pass: compute count_a which stores the number of
        // 'a' characters to the right of the current position
        for (int i = n - 1; i >= 0; i--) {
            count_a[i] = a_count;
            if (s[i] == 'a') a_count++;
        }

        int min_deletions = n;
        int b_count = 0;
        // Second pass: compute minimum deletions on the fly
        for (int i = 0; i < n; i++) {
            min_deletions = min(count_a[i] + b_count, min_deletions);
            if (s[i] == 'b') b_count++;
        }

        return min_deletions;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDeletions(String s) {
        int n = s.length();
        int[] countA = new int[n];
        int aCount = 0;

        // First pass: compute count_a which stores the number of
        // 'a' characters to the right of the current position
        for (int i = n - 1; i >= 0; i--) {
            countA[i] = aCount;
            if (s.charAt(i) == 'a') aCount++;
        }

        int minDeletions = n;
        int bCount = 0;
        // Second pass: compute minimum deletions on the fly
        for (int i = 0; i < n; i++) {
            minDeletions = Math.min(countA[i] + bCount, minDeletions);
            if (s.charAt(i) == 'b') bCount++;
        }

        return minDeletions;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        count_a = [0] * n
        a_count = 0

        # First pass: compute count_a which stores the number of
        # 'a' characters to the right of the current position
        for i in range(n - 1, -1, -1):
            count_a[i] = a_count
            if s[i] == "a":
                a_count += 1

        min_deletions = n
        b_count = 0
        # Second pass: compute minimum deletions on the fly
        for i in range(n):
            min_deletions = min(count_a[i] + b_count, min_deletions)
            if s[i] == "b":
                b_count += 1

        return min_deletions
```

</details>

<br>

## Approach 3: Two-Variable Method

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int a_count = 0;

        // First pass: count the number of 'a's
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a_count++;
        }

        int b_count = 0;
        int min_deletions = n;

        // Second pass: iterate through the string to compute minimum deletions
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a_count--;
            min_deletions = min(min_deletions, a_count + b_count);
            if (s[i] == 'b') b_count++;
        }

        return min_deletions;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDeletions(String s) {
        int n = s.length();
        int aCount = 0;

        // First pass: count the number of 'a's
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a') aCount++;
        }

        int bCount = 0;
        int minDeletions = n;

        // Second pass: iterate through the string to compute minimum deletions
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a') aCount--;
            minDeletions = Math.min(minDeletions, aCount + bCount);
            if (s.charAt(i) == 'b') bCount++;
        }

        return minDeletions;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        a_count = sum(1 for ch in s if ch == "a")

        b_count = 0
        min_deletions = n

        # Second pass: iterate through the string to compute minimum deletions
        for ch in s:
            if ch == "a":
                a_count -= 1
            min_deletions = min(min_deletions, a_count + b_count)
            if ch == "b":
                b_count += 1

        return min_deletions
```

</details>

<br>

## Approach 4: Using stack (one pass)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        stack<char> charStack;
        int deleteCount = 0;

        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            // If stack is not empty, top of stack is 'b',
            // and current char is 'a'
            if (!charStack.empty() && charStack.top() == 'b' && s[i] == 'a') {
                charStack.pop();  // Remove 'b' from stack
                deleteCount++;    // Increment deletion count
            } else {
                charStack.push(s[i]);  // Push current character onto stack
            }
        }

        return deleteCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDeletions(String s) {
        int n = s.length();
        Stack<Character> charStack = new Stack<>();
        int deleteCount = 0;

        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            // If stack is not empty, top of stack is 'b',
            // and current char is 'a'
            if (
                !charStack.isEmpty() &&
                charStack.peek() == 'b' &&
                s.charAt(i) == 'a'
            ) {
                charStack.pop(); // Remove 'b' from stack
                deleteCount++; // Increment deletion count
            } else {
                charStack.push(s.charAt(i)); // Push current character onto stack
            }
        }

        return deleteCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        char_stack = []
        delete_count = 0

        # Iterate through each character in the string
        for char in s:
            # If stack is not empty, top of stack is 'b',
            # and current char is 'a'
            if char_stack and char_stack[-1] == "b" and char == "a":
                char_stack.pop()  # Remove 'b' from stack
                delete_count += 1  # Increment deletion count
            else:
                char_stack.append(char)  # Append current character to stack

        return delete_count
```

</details>

<br>

## Approach 5: Using DP (One Pass)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        int b_count = 0;

        // dp[i]: The number of deletions required to
        // balance the substring s[0, i)
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                dp[i + 1] = dp[i];
                b_count++;
            } else {
                // Two cases: remove 'a' or keep 'a'
                dp[i + 1] = min(dp[i] + 1, b_count);
            }
        }

        return dp[n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDeletions(String s) {
        int n = s.length();
        int[] dp = new int[n + 1];
        int bCount = 0;

        // dp[i]: The number of deletions required to
        // balance the substring s[0, i)
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'b') {
                dp[i + 1] = dp[i];
                bCount++;
            } else {
                // Two cases: remove 'a' or keep 'a'
                dp[i + 1] = Math.min(dp[i] + 1, bCount);
            }
        }

        return dp[n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        b_count = 0

        # dp[i]: The number of deletions required to
        # balance the substring s[0, i)
        for i in range(n):
            if s[i] == "b":
                dp[i + 1] = dp[i]
                b_count += 1
            else:
                # Two cases: remove 'a' or keep 'a'
                dp[i + 1] = min(dp[i] + 1, b_count)

        return dp[n]
```

</details>

<br>

## Approach 6: Optimized DP

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int min_deletions = 0;
        int b_count = 0;

        // min_deletions variable represents dp[i]
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                b_count++;
            } else {
                // Two cases: remove 'a' or keep 'a'
                min_deletions = min(min_deletions + 1, b_count);
            }
        }

        return min_deletions;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDeletions(String s) {
        int n = s.length();
        int minDeletions = 0;
        int bCount = 0;

        // minDeletions variable represents dp[i]
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'b') {
                bCount++;
            } else {
                // Two cases: remove 'a' or keep 'a'
                minDeletions = Math.min(minDeletions + 1, bCount);
            }
        }

        return minDeletions;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        min_deletions = 0
        b_count = 0

        # min_deletions variable represents dp[i]
        for ch in s:
            if ch == "b":
                b_count += 1
            else:
                # Two cases: remove 'a' or keep 'a'
                min_deletions = min(min_deletions + 1, b_count)

        return min_deletions
```

</details>
