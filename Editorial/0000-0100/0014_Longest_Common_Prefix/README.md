# 14. Longest Common Prefix

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/longest-common-prefix/)  
`Array` `String` `Trie`

**Problem Link:** [LeetCode 14 - Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)

## Problem

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

### Example 1

```text
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

### Example 2

```text
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

## Constraints

- 1 <= strs.length <= 200
- 0 <= strs[i].length <= 200
- strs[i] consists of only lowercase English letters if it is non-empty.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Smallest Missing Integer Greater Than Sequential Prefix Sum](https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Length of the Longest Common Prefix](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Common Suffix Queries](https://leetcode.com/problems/longest-common-suffix-queries/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Longest Common Prefix After at Most One Removal](https://leetcode.com/problems/longest-common-prefix-after-at-most-one-removal/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 14. Longest Common Prefix

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Horizontal scanning | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Vertical scanning | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Divide and conquer | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Horizontal scanning

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    char* prefix = strs[0];
    for (int i = 1; i < strsSize; i++)
        while (strstr(strs[i], prefix) != strs[i]) {
            prefix[strlen(prefix) - 1] = '\0';
            if (!*prefix) return "";
        }
    return prefix;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        return prefix;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs.Length == 0)
            return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.Length; i++)
            while (strs[i].IndexOf(prefix) != 0) {
                prefix = prefix.Substring(0, prefix.Length - 1);
                if (prefix == "")
                    return "";
            }

        return prefix;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    prefix := strs[0]
    for i := 1; i < len(strs); i++ {
        for strings.Index(strs[i], prefix) != 0 {
            prefix = prefix[:len(prefix)-1]
            if prefix == "" {
                return ""
            }
        }
    }
    return prefix
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        String prefix = strs[0];
        for (int i = 1; i < strs.length; i++) while (
            strs[i].indexOf(prefix) != 0
        ) {
            prefix = prefix.substring(0, prefix.length() - 1);
            if (prefix.isEmpty()) return "";
        }
        return prefix;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestCommonPrefix = function (strs) {
    if (strs.length === 0) return "";
    let prefix = strs[0];
    for (let i = 1; i < strs.length; i++)
        while (strs[i].indexOf(prefix) != 0) {
            prefix = prefix.slice(0, prefix.length - 1);
            if (prefix === "") return "";
        }
    return prefix;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        prefix = strs[0]
        for i in range(1, len(strs)):
            while strs[i].find(prefix) != 0:
                prefix = prefix[0 : len(prefix) - 1]
                if prefix == "":
                    return ""
        return prefix
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestCommonPrefix(strs: string[]): string {
    if (strs.length === 0) return "";
    let prefix = strs[0];
    for (let i = 1; i < strs.length; i++)
        while (strs[i].indexOf(prefix) != 0) {
            prefix = prefix.slice(0, prefix.length - 1);
            if (prefix === "") return "";
        }
    return prefix;
}
```

</details>

<br>

## Approach 2: Vertical scanning

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    for (int i = 0; i < strlen(strs[0]); i++) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (i == strlen(strs[j]) || strs[j][i] != c)
                return strndup(strs[0], i);
        }
    }
    return strs[0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs == null || strs.Length == 0)
            return "";
        for (int i = 0; i < strs[0].Length; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.Length; j++) {
                if (i == strs[j].Length || strs[j][i] != c)
                    return strs[0].Substring(0, i);
            }
        }

        return strs[0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    for i := 0; i < len(strs[0]); i++ {
        c := strs[0][i]
        for j := 1; j < len(strs); j++ {
            if i == len(strs[j]) || strs[j][i] != c {
                return strs[0][:i]
            }
        }
    }
    return strs[0]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (
                    i == strs[j].length() || strs[j].charAt(i) != c
                ) return strs[0].substring(0, i);
            }
        }
        return strs[0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestCommonPrefix = function (strs) {
    if (strs == null || strs.length == 0) return "";
    for (let i = 0; i < strs[0].length; i++) {
        let c = strs[0][i];
        for (let j = 1; j < strs.length; j++) {
            if (i == strs[j].length || strs[j].charAt(i) != c)
                return strs[0].substring(0, i);
        }
    }
    return strs[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs == None or len(strs) == 0:
            return ""
        for i in range(len(strs[0])):
            c = strs[0][i]
            for j in range(1, len(strs)):
                if i == len(strs[j]) or strs[j][i] != c:
                    return strs[0][0:i]
        return strs[0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestCommonPrefix(strs: string[]): string {
    if (strs == null || strs.length == 0) return "";
    for (let i = 0; i < strs[0].length; i++) {
        let c = strs[0][i];
        for (let j = 1; j < strs.length; j++) {
            if (i == strs[j].length || strs[j].charAt(i) != c)
                return strs[0].substring(0, i);
        }
    }
    return strs[0];
}
```

</details>

<br>

## Approach 3: Divide and conquer

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* LCP(char* s1, char* s2) {
    int minLen = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
    char* res = (char*)calloc(minLen + 1, sizeof(char));
    for (int i = 0; i < minLen; i++) {
        if (s1[i] != s2[i]) {
            res[i] = '\0';
            break;
        }
        res[i] = s1[i];
    }
    return res;
}

char* divide_and_conquer(char** strs, int l, int r) {
    if (l == r)
        return strs[l];
    else {
        int mid = (l + r) / 2;
        char* lcpLeft = divide_and_conquer(strs, l, mid);
        char* lcpRight = divide_and_conquer(strs, mid + 1, r);
        char* res = LCP(lcpLeft, lcpRight);
        if (lcpLeft != strs[l]) free(lcpLeft);
        if (lcpRight != strs[mid + 1]) free(lcpRight);
        return res;
    }
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strs == NULL || strsSize == 0) return "";
    return divide_and_conquer(strs, 0, strsSize - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }

private:
    string longestCommonPrefix(vector<string>& strs, int l, int r) {
        if (l == r) {
            return strs[l];
        } else {
            int mid = (l + r) / 2;
            string lcpLeft = longestCommonPrefix(strs, l, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, r);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    string commonPrefix(string left, string right) {
        int min = std::min(left.length(), right.length());
        for (int i = 0; i < min; i++) {
            if (left[i] != right[i]) return left.substr(0, i);
        }
        return left.substr(0, min);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs == null || strs.Length == 0)
            return "";
        return LongestCommonPrefix(strs, 0, strs.Length - 1);
    }

    private string LongestCommonPrefix(string[] strs, int l, int r) {
        if (l == r) {
            return strs[l];
        } else {
            int mid = (l + r) / 2;
            var lcpLeft = LongestCommonPrefix(strs, l, mid);
            var lcpRight = LongestCommonPrefix(strs, mid + 1, r);
            return CommonPrefix(lcpLeft, lcpRight);
        }
    }

    private string CommonPrefix(string left, string right) {
        int min = Math.Min(left.Length, right.Length);
        for (int i = 0; i < min; i++) {
            if (left[i] != right[i])
                return left.Substring(0, i);
        }

        return left.Substring(0, min);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestCommonPrefix(strs []string) string {
    if strs == nil || len(strs) < 1 {
        return ""
    }

    var LCP func(string, string) string
    LCP = func(str1, str2 string) string {
        minLen := min(len(str1), len(str2))
        for i := 0; i < minLen; i++ {
            if str1[i] != str2[i] {
                return str1[0:i]
            }
        }
        return str1[0:minLen]
    }

    var divideAndConquer func([]string, int, int) string
    divideAndConquer = func(strs []string, l, r int) string {
        if l == r {
            return strs[l]
        } else {
            mid := (l + r) / 2
            lcpLeft := divideAndConquer(strs, l, mid)
            lcpRight := divideAndConquer(strs, mid+1, r)
            return LCP(lcpLeft, lcpRight)
        }
    }

    return divideAndConquer(strs, 0, len(strs)-1)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        return longestCommonPrefix(strs, 0, strs.length - 1);
    }

    private String longestCommonPrefix(String[] strs, int l, int r) {
        if (l == r) {
            return strs[l];
        } else {
            int mid = (l + r) / 2;
            String lcpLeft = longestCommonPrefix(strs, l, mid);
            String lcpRight = longestCommonPrefix(strs, mid + 1, r);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    private String commonPrefix(String left, String right) {
        int min = Math.min(left.length(), right.length());
        for (int i = 0; i < min; i++) {
            if (left.charAt(i) != right.charAt(i)) return left.substring(0, i);
        }
        return left.substring(0, min);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestCommonPrefix = function (strs) {
    if (!strs || strs.length < 1) return "";

    let LCP = (str1, str2) => {
        let minLen = Math.min(str1.length, str2.length);
        for (let i = 0; i < minLen; i++) {
            if (str1[i] !== str2[i]) {
                return str1.slice(0, i);
            }
        }
        return str1.slice(0, minLen);
    };

    let divideAndConquer = (strs, l, r) => {
        if (l == r) {
            return strs[l];
        } else {
            let mid = Math.floor((l + r) / 2);
            let lcpLeft = divideAndConquer(strs, l, mid);
            let lcpRight = divideAndConquer(strs, mid + 1, r);
            return LCP(lcpLeft, lcpRight);
        }
    };

    return divideAndConquer(strs, 0, strs.length - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""

        def LCP(left, right):
            min_len = min(len(left), len(right))
            for i in range(min_len):
                if left[i] != right[i]:
                    return left[:i]
            return left[:min_len]

        def divide_and_conquer(strs, l, r):
            if l == r:
                return strs[l]
            else:
                mid = (l + r) // 2
                lcpLeft = divide_and_conquer(strs, l, mid)
                lcpRight = divide_and_conquer(strs, mid + 1, r)
                return LCP(lcpLeft, lcpRight)

        return divide_and_conquer(strs, 0, len(strs) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestCommonPrefix(strs: string[]): string {
    if (!strs || strs.length < 1) return "";

    let LCP = (str1: string, str2: string): string => {
        let minLen = Math.min(str1.length, str2.length);
        for (let i = 0; i < minLen; i++) {
            if (str1[i] !== str2[i]) {
                return str1.slice(0, i);
            }
        }
        return str1.slice(0, minLen);
    };

    let divideAndConquer = (strs: string[], l: number, r: number): string => {
        if (l === r) {
            return strs[l];
        } else {
            let mid = Math.floor((l + r) / 2);
            let lcpLeft = divideAndConquer(strs, l, mid);
            let lcpRight = divideAndConquer(strs, mid + 1, r);
            return LCP(lcpLeft, lcpRight);
        }
    };

    return divideAndConquer(strs, 0, strs.length - 1);
}
```

</details>

<br>

## Approach 4: Binary search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isCommonPrefix(char** strs, int strsSize, int len) {
    for (int i = 1; i < strsSize; i++) {
        if (strncmp(strs[0], strs[i], len) != 0) {
            return false;
        }
    }
    return true;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strs == NULL || strsSize == 0) return "";
    int minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minLen) minLen = len;
    }
    int low = 1, high = minLen;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isCommonPrefix(strs, strsSize, mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    char* prefix = calloc(high + 1, sizeof(char));
    memcpy(prefix, strs[0], high);
    return prefix;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int minLen = INT_MAX;
        for (string str : strs) minLen = min(minLen, (int)str.length());
        int low = 1;
        int high = minLen;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (isCommonPrefix(strs, middle))
                low = middle + 1;
            else
                high = middle - 1;
        }
        return strs[0].substr(0, (low + high) / 2);
    }

private:
    bool isCommonPrefix(vector<string>& strs, int len) {
        string str1 = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++)
            if (strs[i].find(str1) != 0) return false;
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs == null || strs.Length == 0)
            return "";
        int minLen = Int32.MaxValue;
        foreach (string str in strs) minLen = Math.Min(minLen, str.Length);
        int low = 1;
        int high = minLen;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (IsCommonPrefix(strs, middle))
                low = middle + 1;
            else
                high = middle - 1;
        }

        return strs[0].Substring(0, (low + high) / 2);
    }

    private bool IsCommonPrefix(string[] strs, int len) {
        string str1 = strs[0].Substring(0, len);
        for (int i = 1; i < strs.Length; i++)
            if (!strs[i].StartsWith(str1))
                return false;
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    minLen := math.MaxInt32
    for _, str := range strs {
        minLen = int(math.Min(float64(minLen), float64(len(str))))
    }
    low, high := 1, minLen
    for low <= high {
        middle := (low + high) / 2
        if isCommonPrefix(strs, middle) {
            low = middle + 1
        } else {
            high = middle - 1
        }
    }
    return strs[0][0 : (low+high)/2]
}

func isCommonPrefix(strs []string, length int) bool {
    str1 := strs[0][0:length]
    for i := 1; i < len(strs); i++ {
        if !strings.HasPrefix(strs[i], str1) {
            return false
        }
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        int minLen = Integer.MAX_VALUE;
        for (String str : strs) minLen = Math.min(minLen, str.length());
        int low = 1;
        int high = minLen;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (isCommonPrefix(strs, middle)) low = middle + 1;
            else high = middle - 1;
        }
        return strs[0].substring(0, (low + high) / 2);
    }

    private boolean isCommonPrefix(String[] strs, int len) {
        String str1 = strs[0].substring(0, len);
        for (int i = 1; i < strs.length; i++) if (
            !strs[i].startsWith(str1)
        ) return false;
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestCommonPrefix = function (strs) {
    if (strs === null || strs.length === 0) return "";
    let minLen = Number.MAX_SAFE_INTEGER;
    for (let str of strs) minLen = Math.min(minLen, str.length);
    let low = 1;
    let high = minLen;
    while (low <= high) {
        let middle = Math.floor((low + high) / 2);
        if (isCommonPrefix(strs, middle)) low = middle + 1;
        else high = middle - 1;
    }
    return strs[0].substring(0, Math.floor((low + high) / 2));

    function isCommonPrefix(strs, len) {
        let str1 = strs[0].substring(0, len);
        for (let i = 1; i < strs.length; i++)
            if (!strs[i].startsWith(str1)) return false;
        return true;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        minLen = min(len(x) for x in strs)
        low, high = 1, minLen
        while low <= high:
            middle = (low + high) // 2
            if self.isCommonPrefix(strs, middle):
                low = middle + 1
            else:
                high = middle - 1
        return strs[0][: (low + high) // 2]

    def isCommonPrefix(self, strs, l):
        str1 = strs[0][:l]
        for i in range(1, len(strs)):
            if not strs[i].startswith(str1):
                return False
        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestCommonPrefix(strs: string[]): string {
    if (strs === null || strs.length === 0) return "";
    let minLen = Number.MAX_SAFE_INTEGER;
    for (let str of strs) minLen = Math.min(minLen, str.length);
    let low = 1;
    let high = minLen;
    while (low <= high) {
        let middle = Math.floor((low + high) / 2);
        if (isCommonPrefix(strs, middle)) low = middle + 1;
        else high = middle - 1;
    }
    return strs[0].substring(0, Math.floor((low + high) / 2));

    function isCommonPrefix(strs: string[], len: number) {
        let str1 = strs[0].substring(0, len);
        for (let i = 1; i < strs.length; i++)
            if (!strs[i].startsWith(str1)) return false;
        return true;
    }
}
```

</details>
