# 3330. Find the Original Typed String I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-the-original-typed-string-i/)  
`String`

**Problem Link:** [LeetCode 3330 - Find the Original Typed String I](https://leetcode.com/problems/find-the-original-typed-string-i/)

## Problem

Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.

You are given a string word, which represents the final output displayed on Alice's screen.

Return the total number of possible original strings that Alice might have intended to type.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= word.length <= 100
- word consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Keyboard Row](https://leetcode.com/problems/keyboard-row/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Faulty Keyboard](https://leetcode.com/problems/faulty-keyboard/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3330. Find the Original Typed String I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: One-time Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: One-time Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int possibleStringCount(char* word) {
    int n = strlen(word), ans = 1;
    for (int i = 1; i < n; ++i) {
        if (word[i - 1] == word[i]) {
            ++ans;
        }
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size(), ans = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i - 1] == word[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int PossibleStringCount(string word) {
        int n = word.Length, ans = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i - 1] == word[i]) {
                ++ans;
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func possibleStringCount(word string) int {
	n, ans := len(word), 1
	for i := 1; i < n; i++ {
		if word[i-1] == word[i] {
			ans++
		}
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int possibleStringCount(String word) {
        int n = word.length(), ans = 1;
        for (int i = 1; i < n; ++i) {
            if (word.charAt(i - 1) == word.charAt(i)) {
                ++ans;
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var possibleStringCount = function (word) {
    let n = word.length,
        ans = 1;
    for (let i = 1; i < n; ++i) {
        if (word[i - 1] === word[i]) {
            ++ans;
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def possibleStringCount(self, word: str) -> int:
        n, ans = len(word), 1
        for i in range(1, n):
            if word[i - 1] == word[i]:
                ans += 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function possibleStringCount(word: string): number {
    let n = word.length,
        ans = 1;
    for (let i = 1; i < n; ++i) {
        if (word[i - 1] === word[i]) {
            ++ans;
        }
    }
    return ans;
}
```

</details>
