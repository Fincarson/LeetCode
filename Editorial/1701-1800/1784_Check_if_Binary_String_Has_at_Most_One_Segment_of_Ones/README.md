# 1784. Check if Binary String Has at Most One Segment of Ones

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)  
`String`

**Problem Link:** [LeetCode 1784 - Check if Binary String Has at Most One Segment of Ones](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)

## Problem

Given a binary string s Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹without leading zeros, return trueÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ if s contains at most one contiguous segment of ones. Otherwise, return false.

### Example 1

```text
Input: s = "1001"
Output: false
Explanation: The string has two segments of size 1.
```

### Example 2

```text
Input: s = "110"
Output: true
```

## Constraints

- 1 <= s.length <= 100
- s[i]Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ is either '0' or '1'.
- s[0] is '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longer Contiguous Segments of Ones than Zeros](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1784. Check if Binary String Has at Most One Segment of Ones

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Find the $01$ sequence | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach: Find the $01$ sequence

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool checkOnesSegment(char* s) { return strstr(s, "01") == NULL; }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkOnesSegment(string s) { return s.find("01") == string::npos; }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool CheckOnesSegment(string s) {
        return !s.Contains("01");
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func checkOnesSegment(s string) bool {
	return !strings.Contains(s, "01")
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean checkOnesSegment(String s) {
        return !s.contains("01");
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var checkOnesSegment = function (s) {
    return s.indexOf("01") === -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return "01" not in s
```

</details>
