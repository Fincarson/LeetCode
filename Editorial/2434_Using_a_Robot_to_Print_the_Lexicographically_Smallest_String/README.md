# 2434. Using a Robot to Print the Lexicographically Smallest String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/)  
`Hash Table` `String` `Stack` `Greedy`

**Problem Link:** [LeetCode 2434 - Using a Robot to Print the Lexicographically Smallest String](https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/)

## Problem

You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

- Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
- Remove the last character of a string t and give it to the robot. The robot will write this character on paper.

Return the lexicographically smallest string that can be written on the paper.

### Example 1

```text
Input: s = "zza"
Output: "azz"
Explanation: Let p denote the written string.
Initially p="", s="zza", t="".
Perform first operation three times p="", s="", t="zza".
Perform second operation three times p="azz", s="", t="".
```

### Example 2

```text
Input: s = "bac"
Output: "abc"
Explanation: Let p denote the written string.
Perform first operation twice p="", s="c", t="ba".
Perform second operation twice p="ab", s="c", t="".
Perform first operation p="ab", s="", t="c".
Perform second operation p="abc", s="", t="".
```

### Example 3

```text
Input: s = "bdda"
Output: "addb"
Explanation: Let p denote the written string.
Initially p="", s="bdda", t="".
Perform first operation four times p="", s="", t="bdda".
Perform second operation four times p="addb", s="", t="".
```

## Constraints

- 1 <= s.length <= 105
- s consists of only English lowercase letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Permutation](https://leetcode.com/problems/find-permutation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2434. Using a Robot to Print the Lexicographically Smallest String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy + Stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy + Stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* robotWithString(char* s) {
    int cnt[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        cnt[s[i] - 'a']++;
    }

    char* stack = (char*)malloc(len * sizeof(char));
    int top = 0;
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int pos = 0;
    char minCharacter = 'a';
    for (int i = 0; i < len; i++) {
        stack[top++] = s[i];
        cnt[s[i] - 'a']--;
        while (minCharacter != 'z' && cnt[minCharacter - 'a'] == 0) {
            minCharacter++;
        }
        while (top > 0 && stack[top - 1] <= minCharacter) {
            res[pos++] = stack[--top];
        }
    }

    res[pos] = '\0';
    free(stack);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }

        stack<char> stk;
        string res;
        char minCharacter = 'a';
        for (char c : s) {
            stk.emplace(c);
            cnt[c]--;
            while (minCharacter != 'z' && cnt[minCharacter] == 0) {
                minCharacter++;
            }
            while (!stk.empty() && stk.top() <= minCharacter) {
                res.push_back(stk.top());
                stk.pop();
            }
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string RobotWithString(string s) {
        int[] cnt = new int[26];
        foreach (char c in s) {
            cnt[c - 'a']++;
        }

        Stack<char> stack = new Stack<char>();
        StringBuilder res = new StringBuilder();
        char minCharacter = 'a';
        foreach (char c in s) {
            stack.Push(c);
            cnt[c - 'a']--;
            while (minCharacter != 'z' && cnt[minCharacter - 'a'] == 0) {
                minCharacter++;
            }
            while (stack.Count > 0 && stack.Peek() <= minCharacter) {
                res.Append(stack.Pop());
            }
        }

        return res.ToString();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func robotWithString(s string) string {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}

	stack := []rune{}
	res := []rune{}
	minCharacter := 'a'
	for _, c := range s {
		stack = append(stack, c)
		cnt[c-'a']--
		for minCharacter != 'z' && cnt[minCharacter-'a'] == 0 {
			minCharacter++
		}
		for len(stack) > 0 && stack[len(stack)-1] <= minCharacter {
			res = append(res, stack[len(stack)-1])
			stack = stack[:len(stack)-1]
		}
	}

	return string(res)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String robotWithString(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }

        Stack<Character> stack = new Stack<>();
        StringBuilder res = new StringBuilder();
        char minCharacter = 'a';
        for (char c : s.toCharArray()) {
            stack.push(c);
            cnt[c - 'a']--;
            while (minCharacter != 'z' && cnt[minCharacter - 'a'] == 0) {
                minCharacter++;
            }
            while (!stack.isEmpty() && stack.peek() <= minCharacter) {
                res.append(stack.pop());
            }
        }

        return res.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var robotWithString = function (s) {
    let cnt = new Array(26).fill(0);
    for (let c of s) {
        cnt[c.charCodeAt(0) - "a".charCodeAt(0)]++;
    }

    let stack = [];
    let res = [];
    let minCharacter = "a";
    for (let c of s) {
        stack.push(c);
        cnt[c.charCodeAt(0) - "a".charCodeAt(0)]--;
        while (
            minCharacter !== "z" &&
            cnt[minCharacter.charCodeAt(0) - "a".charCodeAt(0)] === 0
        ) {
            minCharacter = String.fromCharCode(minCharacter.charCodeAt(0) + 1);
        }
        while (stack.length > 0 && stack[stack.length - 1] <= minCharacter) {
            res.push(stack.pop());
        }
    }

    return res.join("");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def robotWithString(self, s: str) -> str:
        cnt = Counter(s)
        stack = []
        res = []
        minCharacter = "a"
        for c in s:
            stack.append(c)
            cnt[c] -= 1
            while minCharacter != "z" and cnt[minCharacter] == 0:
                minCharacter = chr(ord(minCharacter) + 1)
            while stack and stack[-1] <= minCharacter:
                res.append(stack.pop())
        return "".join(res)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function robotWithString(s: string): string {
    let cnt: number[] = new Array(26).fill(0);
    for (let c of s) {
        cnt[c.charCodeAt(0) - "a".charCodeAt(0)]++;
    }

    let stack: string[] = [];
    let res: string[] = [];
    let minCharacter: string = "a";
    for (let c of s) {
        stack.push(c);
        cnt[c.charCodeAt(0) - "a".charCodeAt(0)]--;
        while (
            minCharacter !== "z" &&
            cnt[minCharacter.charCodeAt(0) - "a".charCodeAt(0)] === 0
        ) {
            minCharacter = String.fromCharCode(minCharacter.charCodeAt(0) + 1);
        }
        while (stack.length > 0 && stack[stack.length - 1] <= minCharacter) {
            res.push(stack.pop()!);
        }
    }

    return res.join("");
}
```

</details>
