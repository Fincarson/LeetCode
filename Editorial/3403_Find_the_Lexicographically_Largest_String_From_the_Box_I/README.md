# 3403. Find the Lexicographically Largest String From the Box I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/)  
`Two Pointers` `String` `Enumeration`

**Problem Link:** [LeetCode 3403 - Find the Lexicographically Largest String From the Box I](https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/)

## Problem

You are given a string word, and an integer numFriends.

Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

- word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
- All the split words are put into a box.

Find the lexicographically largest string from the box after all the rounds are finished.

### Example 1

### Example 2

## Constraints

- 1 <= word.length <= 5 * 103
- word consists only of lowercase English letters.
- 1 <= numFriends <= word.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Last Substring in Lexicographical Order](https://leetcode.com/problems/last-substring-in-lexicographical-order/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Construct the Lexicographically Largest Valid Sequence](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3403. Find the Lexicographically Largest String From the Box I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char *answerString(char *word, int numFriends) {
    int n = strlen(word);
    char *res = (char *)malloc(n + 1);
    memset(res, 0, n + 1);
    if (numFriends == 1) {
        strcpy(res, word);
        return res;
    }
    for (int i = 0; i < n; i++) {
        int j = fmin(i + n - numFriends + 1, n);
        if (strncmp(res, word + i, j - i) < 0) {
            strncpy(res, word + i, j - i);
            res[j - i] = '\0';
        }
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        string res;
        for (int i = 0; i < n; i++) {
            res = max(res, word.substr(i, min(n - numFriends + 1, n - i)));
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
    public string AnswerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.Length;
        string res = "";
        for (int i = 0; i < n; i++) {
            string s = word.Substring(i, Math.Min(n - numFriends + 1, n - i));
            if (string.Compare(res, s) <= 0) {
                res = s;
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func answerString(word string, numFriends int) string {
	if numFriends == 1 {
		return word
	}
	n := len(word)
	res := ""
	for i := 0; i < n; i++ {
		res = max(res, word[i:min(i+n-numFriends+1, n)])
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String answerString(String word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.length();
        String res = "";
        for (int i = 0; i < n; i++) {
            String s = word.substring(i, Math.min(i + n - numFriends + 1, n));
            if (res.compareTo(s) <= 0) {
                res = s;
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var answerString = function (word, numFriends) {
    if (numFriends === 1) {
        return word;
    }
    let n = word.length;
    let res = "";
    for (let i = 0; i < n; i++) {
        let s = word.substring(i, Math.min(i + n - numFriends + 1, n));
        if (s > res) {
            res = s;
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word
        n = len(word)
        res = ""
        for i in range(n):
            res = max(res, word[i : min(i + n - numFriends + 1, n)])
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function answerString(word: string, numFriends: number): string {
    if (numFriends === 1) {
        return word;
    }
    const n = word.length;
    let res = "";
    for (let i = 0; i < n; i++) {
        const s = word.substring(i, Math.min(i + n - numFriends + 1, n));
        if (s > res) {
            res = s;
        }
    }

    return res;
}
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char *lastSubstring(char *s) {
    int i = 0, j = 1, n = strlen(s);
    while (j < n) {
        int k = 0;
        while (j + k < n && s[i + k] == s[j + k]) {
            k++;
        }
        if (j + k < n && s[i + k] < s[j + k]) {
            int t = i;
            i = j;
            j = fmax(j + 1, t + k + 1);
        } else {
            j = j + k + 1;
        }
    }
    return s + i;
}

char *answerString(char *word, int numFriends) {
    if (numFriends == 1) {
        return word;
    }
    char *last = lastSubstring(word);
    int n = strlen(word);
    int m = strlen(last);
    int len = fmin(m, n - numFriends + 1);
    last[len] = '\0';
    return last;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, n = s.size();
        while (j < n) {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            if (j + k < n && s[i + k] < s[j + k]) {
                int t = i;
                i = j;
                j = max(j + 1, t + k + 1);
            } else {
                j = j + k + 1;
            }
        }
        return s.substr(i, n - i);
    }

    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        string last = lastSubstring(word);
        int n = word.size(), m = last.size();
        return last.substr(0, min(m, n - numFriends + 1));
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string LastSubstring(string s) {
        int i = 0, j = 1, n = s.Length;
        while (j < n) {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            if (j + k < n && s[i + k] < s[j + k]) {
                int t = i;
                i = j;
                j = Math.Max(j + 1, t + k + 1);
            } else {
                j = j + k + 1;
            }
        }
        return s.Substring(i);
    }

    public string AnswerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        string last = LastSubstring(word);
        int n = word.Length, m = last.Length;
        return last.Substring(0, Math.Min(m, n - numFriends + 1));
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func lastSubstring(s string) string {
	i, j, n := 0, 1, len(s)
	for j < n {
		k := 0
		for j+k < n && s[i+k] == s[j+k] {
			k++
		}
		if j+k < n && s[i+k] < s[j+k] {
			i, j = j, max(j+1, i+k+1)
		} else {
			j = j + k + 1
		}
	}
	return s[i:]
}

func answerString(word string, numFriends int) string {
	if numFriends == 1 {
		return word
	}
	last := lastSubstring(word)
	n, m := len(word), len(last)
	return last[:min(m, n-numFriends+1)]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String lastSubstring(String s) {
        int i = 0, j = 1, n = s.length();
        while (j < n) {
            int k = 0;
            while (j + k < n && s.charAt(i + k) == s.charAt(j + k)) {
                k++;
            }
            if (j + k < n && s.charAt(i + k) < s.charAt(j + k)) {
                int t = i;
                i = j;
                j = Math.max(j + 1, t + k + 1);
            } else {
                j = j + k + 1;
            }
        }
        return s.substring(i);
    }

    public String answerString(String word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        String last = lastSubstring(word);
        int n = word.length(), m = last.length();
        return last.substring(0, Math.min(m, n - numFriends + 1));
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lastSubstring = function (s) {
    let i = 0,
        j = 1,
        n = s.length;
    while (j < n) {
        let k = 0;
        while (j + k < n && s[i + k] === s[j + k]) {
            k++;
        }
        if (j + k < n && s[i + k] < s[j + k]) {
            let t = i;
            i = j;
            j = Math.max(j + 1, t + k + 1);
        } else {
            j = j + k + 1;
        }
    }
    return s.substring(i, n);
};

var answerString = function (word, numFriends) {
    if (numFriends === 1) {
        return word;
    }
    let last = lastSubstring(word);
    let n = word.length,
        m = last.length;
    return last.substring(0, Math.min(m, n - numFriends + 1));
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lastSubstring(self, s: str) -> str:
        i, j, n = 0, 1, len(s)
        while j < n:
            k = 0
            while j + k < n and s[i + k] == s[j + k]:
                k += 1
            if j + k < n and s[i + k] < s[j + k]:
                i, j = j, max(j + 1, i + k + 1)
            else:
                j = j + k + 1
        return s[i:]

    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word
        last = self.lastSubstring(word)
        n, m = len(word), len(last)
        return last[: min(m, n - numFriends + 1)]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function lastSubstring(s: string): string {
    let i = 0,
        j = 1,
        n = s.length;
    while (j < n) {
        let k = 0;
        while (j + k < n && s[i + k] === s[j + k]) {
            k++;
        }
        if (j + k < n && s[i + k] < s[j + k]) {
            let t = i;
            i = j;
            j = Math.max(j + 1, t + k + 1);
        } else {
            j = j + k + 1;
        }
    }
    return s.substring(i, n);
}

function answerString(word: string, numFriends: number): string {
    if (numFriends === 1) {
        return word;
    }
    let last: string = lastSubstring(word);
    let n: number = word.length;
    let m: number = last.length;
    return last.substring(0, Math.min(m, n - numFriends + 1));
}
```

</details>
