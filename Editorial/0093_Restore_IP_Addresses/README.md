# 93. Restore IP Addresses

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/restore-ip-addresses/)  
`String` `Backtracking`

**Problem Link:** [LeetCode 93 - Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/)

## Problem

A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

- For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.

Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

### Example 1

```text
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
```

### Example 2

```text
Input: s = "0000"
Output: ["0.0.0.0"]
```

### Example 3

```text
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

## Constraints

- 1 <= s.length <= 20
- s consists of digits only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [IP to CIDR](https://leetcode.com/problems/ip-to-cidr/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 93. Restore IP Addresses

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct List {
    char **strings;
    int size;
};
bool valid(char *s, int start, int length) {
    if (length == 1) return true;
    if (s[start] != '0') {
        return length < 3 || strncmp(s + start, "255", length) <= 0;
    }
    return false;
}
void helper(char *s, int startIndex, int *dots, struct List *ans, int size) {
    const int remainingLength = strlen(s) - startIndex;
    const int remainingNumberOfIntegers = 4 - size;
    if (remainingLength > remainingNumberOfIntegers * 3 ||
        remainingLength < remainingNumberOfIntegers) {
        return;
    }
    char *temp = NULL;
    int last = 0;
    if (size == 3) {
        temp = (char *)calloc(1800, sizeof(char));
        if (valid(s, startIndex, remainingLength)) {
            for (int i = 0; i < size; i++) {
                strncat(temp, s + last, dots[i]);
                last += dots[i];
                strcat(temp, ".");
            }
            strcat(temp, s + startIndex);
            ans->strings[ans->size] = temp;
            ans->size++;
        }
        return;
    }
    for (int curPos = 1; curPos <= 3 && curPos <= remainingLength; ++curPos) {
        dots[size] = curPos;
        if (valid(s, startIndex, curPos)) {
            helper(s, startIndex + curPos, dots, ans, size + 1);
        }
    }
}
char **restoreIpAddresses(char *s, int *returnSize) {
    struct List ans;
    ans.strings = (char **)malloc((1 << 18) * sizeof(char *));
    ans.size = 0;
    int dots[4];
    memset(dots, 0, sizeof(dots));
    helper(s, 0, dots, &ans, 0);
    *returnSize = ans.size;
    return ans.strings;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    bool valid(const string& s, int start, int length) {
        return length == 1 ||
               (s[start] != '0' &&
                (length < 3 || s.substr(start, length) <= "255"));
    }

    void helper(const string& s, int startIndex, vector<int>& dots,
                vector<string>& ans) {
        const int remainingLength = s.length() - startIndex;
        const int remainingNumberOfIntegers = 4 - dots.size();

        if (remainingLength > remainingNumberOfIntegers * 3 ||
            remainingLength < remainingNumberOfIntegers) {
            return;
        }
        if (dots.size() == 3) {
            if (valid(s, startIndex, remainingLength)) {
                string temp;
                int last = 0;
                for (int dot : dots) {
                    temp.append(s.substr(last, dot));
                    last += dot;
                    temp.append(".");
                }
                temp.append(s.substr(startIndex));
                ans.push_back(temp);
            }
            return;
        }
        for (int curPos = 1; curPos <= 3 && curPos <= remainingLength;
             ++curPos) {
            // Append a dot at the current position.
            dots.push_back(curPos);
            // Try making all combinations with the remaining string.
            if (valid(s, startIndex, curPos)) {
                helper(s, startIndex + curPos, dots, ans);
            }
            // Backtrack, i.e. remove the dot to try placing it at the next
            // position.
            dots.pop_back();
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> dots;
        vector<string> ans;
        helper(s, 0, dots, ans);
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private bool valid(string s, int start, int length) {
        return length == 1 ||
               (s[start] != '0' &&
                (length < 3 || int.Parse(s.Substring(start, length)) <= 255));
    }

    private void helper(string s, int startIndex, List<int> dots,
                        List<string> ans) {
        var remainingLength = s.Length - startIndex;
        var remainingNumberOfIntegers = 4 - dots.Count;
        if (remainingLength > remainingNumberOfIntegers * 3 ||
            remainingLength < remainingNumberOfIntegers)
            return;
        if (dots.Count == 3) {
            if (valid(s, startIndex, remainingLength)) {
                var temp = "";
                var last = 0;
                foreach (var dot in dots) {
                    temp += s.Substring(last, dot) + ".";
                    last += dot;
                }

                temp += s.Substring(startIndex);
                ans.Add(temp);
            }

            return;
        }

        for (int curPos = 1; curPos <= 3 && curPos <= remainingLength;
             ++curPos) {
            dots.Add(curPos);
            if (valid(s, startIndex, curPos)) {
                helper(s, startIndex + curPos, dots, ans);
            }

            dots.RemoveAt(dots.Count - 1);
        }
    }

    public IList<string> RestoreIpAddresses(string s) {
        var ans = new List<string>();
        helper(s, 0, new List<int>(), ans);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func restoreIpAddresses(s string) []string {
    var ans []string
    var valid func(s string, start int, length int) bool
    valid = func(s string, start int, length int) bool {
        return length == 1 ||
            (s[start] != '0' && (length < 3 || s[start:start+length] <= "255"))
    }
    var helper func(s string, startIndex int, dots []int)
    helper = func(s string, startIndex int, dots []int) {
        remainingLength := len(s) - startIndex
        remainingNumberOfIntegers := 4 - len(dots)
        if remainingLength > remainingNumberOfIntegers*3 ||
            remainingLength < remainingNumberOfIntegers {
            return
        }
        if len(dots) == 3 {
            if valid(s, startIndex, remainingLength) {
                temp := ""
                last := 0
                for i := 0; i < len(dots); i++ {
                    temp += s[last : last+dots[i]]
                    if last != startIndex {
                        temp += "."
                    }
                    last += dots[i]
                }
                temp += s[startIndex:]
                ans = append(ans, temp)
            }
            return
        }
        for curPos := 1; curPos <= 3 && curPos <= remainingLength; curPos++ {
            dots = append(dots, curPos)
            if valid(s, startIndex, curPos) {
                helper(s, startIndex+curPos, dots)
            }
            dots = dots[:len(dots)-1]
        }
    }
    helper(s, 0, []int{})
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean valid(String s, int start, int length) {
        return (
            length == 1 ||
            (s.charAt(start) != '0' &&
                (length < 3 ||
                    s.substring(start, start + length).compareTo("255") <= 0))
        );
    }

    private void helper(
        String s,
        int startIndex,
        List<Integer> dots,
        List<String> ans
    ) {
        final int remainingLength = s.length() - startIndex;
        final int remainingNumberOfIntegers = 4 - dots.size();
        if (
            remainingLength > remainingNumberOfIntegers * 3 ||
            remainingLength < remainingNumberOfIntegers
        ) {
            return;
        }
        if (dots.size() == 3) {
            if (valid(s, startIndex, remainingLength)) {
                StringBuilder sb = new StringBuilder();
                int last = 0;
                for (Integer dot : dots) {
                    sb.append(s.substring(last, last + dot));
                    last += dot;
                    sb.append('.');
                }
                sb.append(s.substring(startIndex));
                ans.add(sb.toString());
            }
            return;
        }
        for (
            int curPos = 1;
            curPos <= 3 && curPos <= remainingLength;
            ++curPos
        ) {
            // Append a dot at the current position.
            dots.add(curPos);
            // Try making all combinations with the remaining string.
            if (valid(s, startIndex, curPos)) {
                helper(s, startIndex + curPos, dots, ans);
            }
            // Backtrack, i.e. remove the dot to try placing it at the next position.
            dots.remove(dots.size() - 1);
        }
    }

    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        helper(s, 0, new ArrayList<>(), ans);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var restoreIpAddresses = function (s) {
    var ans = [];
    function valid(s, start, length) {
        return (
            length == 1 ||
            (s.charAt(start) != "0" &&
                (length < 3 || s.substring(start, start + length) <= 255))
        );
    }
    function helper(s, startIndex, dots, ans) {
        var remainingLength = s.length - startIndex;
        var remainingNumberOfIntegers = 4 - dots.length;
        if (
            remainingLength > remainingNumberOfIntegers * 3 ||
            remainingLength < remainingNumberOfIntegers
        ) {
            return;
        }
        if (dots.length == 3) {
            if (valid(s, startIndex, remainingLength)) {
                var temp = "";
                var last = 0;
                for (var dot of dots) {
                    temp += s.substring(last, last + dot) + ".";
                    last += dot;
                }
                temp += s.substring(startIndex);
                ans.push(temp);
            }
            return;
        }
        for (
            var curPos = 1;
            curPos <= 3 && curPos <= remainingLength;
            ++curPos
        ) {
            dots.push(curPos);
            if (valid(s, startIndex, curPos)) {
                helper(s, startIndex + curPos, dots, ans);
            }
            dots.pop();
        }
    }
    helper(s, 0, [], ans);
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    # method to check if a part of the string is within the range 0-255,
    # returns True if part is within range 0-255 else False
    def valid(self, s, start, length):
        return length == 1 or (
            s[start] != "0"
            and (length < 3 or s[start : start + length] <= "255")
        )

    # main helper method to solve the problem by backtracking
    def helper(self, s, startIndex, dots, ans):
        remainingLength = len(s) - startIndex
        remainingNumberOfIntegers = 4 - len(dots)
        if (
            remainingLength > remainingNumberOfIntegers * 3
            or remainingLength < remainingNumberOfIntegers
        ):
            return
        if len(dots) == 3:
            if self.valid(s, startIndex, remainingLength):
                temp = ""
                last = 0
                for dot in dots:
                    temp += s[last : last + dot] + "."
                    last += dot
                temp += s[startIndex:]
                ans.append(temp)
            return
        for curPos in range(1, min(4, remainingLength + 1)):
            dots.append(curPos)
            if self.valid(s, startIndex, curPos):
                self.helper(s, startIndex + curPos, dots, ans)
            dots.pop()

    # main method called by leetcode
    def restoreIpAddresses(self, s):
        answer = []
        self.helper(s, 0, [], answer)
        return answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function restoreIpAddresses(s: string): string[] {
    let ans: string[] = [];
    function valid(s: string, start: number, length: number): boolean {
        return (
            length == 1 ||
            (s.charAt(start) != "0" &&
                (length < 3 || s.substring(start, start + length) <= "255"))
        );
    }
    function helper(
        s: string,
        startIndex: number,
        dots: number[],
        ans: string[],
    ): void {
        const remainingLength = s.length - startIndex;
        const remainingNumberOfIntegers = 4 - dots.length;
        if (
            remainingLength > remainingNumberOfIntegers * 3 ||
            remainingLength < remainingNumberOfIntegers
        ) {
            return;
        }
        if (dots.length == 3) {
            if (valid(s, startIndex, remainingLength)) {
                let temp = "";
                let last = 0;
                for (let dot of dots) {
                    temp += s.substring(last, last + dot) + ".";
                    last += dot;
                }
                temp += s.substring(startIndex);
                ans.push(temp);
            }
            return;
        }
        for (
            let curPos = 1;
            curPos <= 3 && curPos <= remainingLength;
            ++curPos
        ) {
            dots.push(curPos);
            if (valid(s, startIndex, curPos)) {
                helper(s, startIndex + curPos, dots, ans);
            }
            dots.pop();
        }
    }
    helper(s, 0, [], ans);
    return ans;
}
```

</details>

<br>

## Approach 2: Iterative

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int valid(char *s, int start, int length) {
    if (length == 1) return 1;
    if (s[start] == '0') return 0;
    if (length > 2) {
        char substr[4];
        strncpy(substr, s + start, length);
        substr[length] = '\0';
        if (atoi(substr) > 255) return 0;
    }
    return 1;
}
char **restoreIpAddresses(char *s, int *returnSize) {
    char **ans = malloc(0);
    *returnSize = 0;
    int length = strlen(s);
    for (int len1 = length - 9 > 1 ? length - 9 : 1;
         len1 <= 3 && len1 <= length - 3; ++len1) {
        if (!valid(s, 0, len1)) continue;
        for (int len2 = length - len1 - 6 > 1 ? length - len1 - 6 : 1;
             len2 <= 3 && len2 <= length - len1 - 2; ++len2) {
            if (!valid(s, len1, len2)) continue;
            for (int len3 = length - len1 - len2 - 3 > 1
                                ? length - len1 - len2 - 3
                                : 1;
                 len3 <= 3 && len3 <= length - len1 - len2 - 1; ++len3) {
                if (valid(s, len1 + len2, len3) &&
                    valid(s, len1 + len2 + len3, length - len1 - len2 - len3)) {
                    char *ip = malloc(16);
                    sprintf(ip, "%.*s.%.*s.%.*s.%.*s", len1, s, len2, s + len1,
                            len3, s + len1 + len2, length - len1 - len2 - len3,
                            s + len1 + len2 + len3);
                    ans = realloc(ans, (*returnSize + 1) * sizeof(char *));
                    ans[(*returnSize)++] = ip;
                }
            }
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
    bool valid(const string& s, int start, int length) {
        return length == 1 ||
               (s[start] != '0' &&
                (length < 3 || s.substr(start, length) <= "255"));
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int length = s.length();
        for (int len1 = max(1, length - 9); len1 <= 3 && len1 <= length - 3;
             ++len1) {
            if (!valid(s, 0, len1)) {
                continue;
            }
            for (int len2 = max(1, length - len1 - 6);
                 len2 <= 3 && len2 <= length - len1 - 2; ++len2) {
                if (!valid(s, len1, len2)) {
                    continue;
                }
                for (int len3 = max(1, length - len1 - len2 - 3);
                     len3 <= 3 && len3 <= length - len1 - len2 - 1; ++len3) {
                    if (valid(s, len1 + len2, len3) &&
                        valid(s, len1 + len2 + len3,
                              length - len1 - len2 - len3)) {
                        ans.push_back(s.substr(0, len1) + "." +
                                      s.substr(len1, len2) + "." +
                                      s.substr(len1 + len2, len3) + "." +
                                      s.substr(len1 + len2 + len3));
                    }
                }
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
    private bool valid(string s, int start, int length) {
        return length == 1 ||
               (s[start] != '0' &&
                (length < 3 || int.Parse(s.Substring(start, length)) <= 255));
    }

    public IList<string> RestoreIpAddresses(string s) {
        var ans = new List<string>();
        int length = s.Length;
        for (int len1 = Math.Max(1, length - 9);
             len1 <= 3 && len1 <= length - 3; ++len1) {
            if (!valid(s, 0, len1)) {
                continue;
            }

            for (int len2 = Math.Max(1, length - len1 - 6);
                 len2 <= 3 && len2 <= length - len1 - 2; ++len2) {
                if (!valid(s, len1, len2)) {
                    continue;
                }

                for (int len3 = Math.Max(1, length - len1 - len2 - 3);
                     len3 <= 3 && len3 <= length - len1 - len2 - 1; ++len3) {
                    if (valid(s, len1 + len2, len3) &&
                        valid(s, len1 + len2 + len3,
                              length - len1 - len2 - len3)) {
                        ans.Add(
                            $"{s.Substring(0, len1)}.{s.Substring(len1, len2)}.{s.Substring(len1 + len2, len3)}.{s.Substring(len1 + len2 + len3)}");
                    }
                }
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
func valid(s string, start int, length int) bool {
    if length > 1 && s[start] == '0' {
        return false
    }
    num := 0
    for i := start; i < start+length; i++ {
        num = num*10 + int(s[i]-'0')
    }
    return num >= 0 && num <= 255
}

func restoreIpAddresses(s string) []string {
    var ans []string
    length := len(s)
    for len1 := 1; len1 <= 3; len1++ {
        if len1 > length {
            break
        }
        if !valid(s, 0, len1) {
            continue
        }
        for len2 := 1; len2 <= 3; len2++ {
            if len1+len2 > length {
                break
            }
            if !valid(s, len1, len2) {
                continue
            }
            for len3 := 1; len3 <= 3; len3++ {
                restLen := length - len1 - len2 - len3
                if restLen < 1 ||
                    restLen > 3 { // IP address can't start or end with '.'
                    continue
                }
                if valid(s, len1+len2, len3) &&
                    valid(s, len1+len2+len3, restLen) {
                    ans = append(
                        ans,
                        s[:len1]+"."+s[len1:len1+len2]+"."+s[len1+len2:len1+len2+len3]+"."+s[len1+len2+len3:],
                    )
                }
            }
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
    private boolean isValid(String s, int start, int length) {
        return (
            length == 1 ||
            (s.charAt(start) != '0' &&
                (length < 3 ||
                    s.substring(start, start + length).compareTo("255") <= 0))
        );
    }

    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        for (
            int len1 = Math.max(1, s.length() - 9);
            len1 <= 3 && len1 <= s.length() - 3;
            ++len1
        ) {
            if (!isValid(s, 0, len1)) {
                continue;
            }

            for (
                int len2 = Math.max(1, s.length() - len1 - 6);
                len2 <= 3 && len2 <= s.length() - len1 - 2;
                ++len2
            ) {
                if (!isValid(s, len1, len2)) {
                    continue;
                }
                for (
                    int len3 = Math.max(1, s.length() - len1 - len2 - 3);
                    len3 <= 3 && len3 <= s.length() - len1 - len2 - 1;
                    ++len3
                ) {
                    if (
                        isValid(s, len1 + len2, len3) &&
                        isValid(
                            s,
                            len1 + len2 + len3,
                            s.length() - len1 - len2 - len3
                        )
                    ) {
                        ans.add(
                            String.join(
                                ".",
                                s.substring(0, len1),
                                s.substring(len1, len1 + len2),
                                s.substring(len1 + len2, len1 + len2 + len3),
                                s.substring(len1 + len2 + len3)
                            )
                        );
                    }
                }
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
var valid = function (s, start, length) {
    return (
        length === 1 ||
        (s[start] !== "0" && (length < 3 || s.substr(start, length) <= "255"))
    );
};
var restoreIpAddresses = function (s) {
    let ans = [];
    let length = s.length;
    for (
        let len1 = Math.max(1, length - 9);
        len1 <= 3 && len1 <= length - 3;
        ++len1
    ) {
        if (!valid(s, 0, len1)) {
            continue;
        }
        for (
            let len2 = Math.max(1, length - len1 - 6);
            len2 <= 3 && len2 <= length - len1 - 2;
            ++len2
        ) {
            if (!valid(s, len1, len2)) {
                continue;
            }
            for (
                let len3 = Math.max(1, length - len1 - len2 - 3);
                len3 <= 3 && len3 <= length - len1 - len2 - 1;
                ++len3
            ) {
                if (
                    valid(s, len1 + len2, len3) &&
                    valid(s, len1 + len2 + len3, length - len1 - len2 - len3)
                ) {
                    ans.push(
                        s.substr(0, len1) +
                            "." +
                            s.substr(len1, len2) +
                            "." +
                            s.substr(len1 + len2, len3) +
                            "." +
                            s.substr(len1 + len2 + len3),
                    );
                }
            }
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
    def restoreIpAddresses(self, s):
        def valid(s, start, length):
            if start >= len(s):
                return False
            return length == 1 or (
                s[start] != "0"
                and (length < 3 or int(s[start : start + length]) <= 255)
            )

        ans = []
        length = len(s)
        for len1 in range(max(1, length - 9), min(4, length - 2) + 1):
            if not valid(s, 0, len1):
                continue
            for len2 in range(
                max(1, length - len1 - 6), min(4, length - len1 - 1) + 1
            ):
                if not valid(s, len1, len2):
                    continue
                for len3 in range(
                    max(1, length - len1 - len2 - 3),
                    min(4, length - len1 - len2) + 1,
                ):
                    if valid(s, len1 + len2, len3) and valid(
                        s, len1 + len2 + len3, length - len1 - len2 - len3
                    ):
                        ans.append(
                            s[:len1]
                            + "."
                            + s[len1 : len1 + len2]
                            + "."
                            + s[len1 + len2 : len1 + len2 + len3]
                            + "."
                            + s[len1 + len2 + len3 :]
                        )
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function valid(s: string, start: number, length: number) {
    return (
        length === 1 ||
        (s[start] !== "0" && (length < 3 || s.substr(start, length) <= "255"))
    );
}
function restoreIpAddresses(s: string) {
    let ans = [];
    let length = s.length;
    for (
        let len1 = Math.max(1, length - 9);
        len1 <= 3 && len1 <= length - 3;
        ++len1
    ) {
        if (!valid(s, 0, len1)) {
            continue;
        }
        for (
            let len2 = Math.max(1, length - len1 - 6);
            len2 <= 3 && len2 <= length - len1 - 2;
            ++len2
        ) {
            if (!valid(s, len1, len2)) {
                continue;
            }
            for (
                let len3 = Math.max(1, length - len1 - len2 - 3);
                len3 <= 3 && len3 <= length - len1 - len2 - 1;
                ++len3
            ) {
                if (
                    valid(s, len1 + len2, len3) &&
                    valid(s, len1 + len2 + len3, length - len1 - len2 - len3)
                ) {
                    ans.push(
                        s.substr(0, len1) +
                            "." +
                            s.substr(len1, len2) +
                            "." +
                            s.substr(len1 + len2, len3) +
                            "." +
                            s.substr(len1 + len2 + len3),
                    );
                }
            }
        }
    }
    return ans;
}
```

</details>
