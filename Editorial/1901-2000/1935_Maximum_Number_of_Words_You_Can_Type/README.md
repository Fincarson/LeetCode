# 1935. Maximum Number of Words You Can Type

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-number-of-words-you-can-type/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 1935 - Maximum Number of Words You Can Type](https://leetcode.com/problems/maximum-number-of-words-you-can-type/)

## Problem

There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

### Example 1

```text
Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.
```

### Example 2

```text
Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
```

### Example 3

```text
Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.
```

## Constraints

- 1 <= text.length <= 104
- 0 <= brokenLetters.length <= 26
- text consists of words separated by a single space without any leading or trailing spaces.
- Each word only consists of lowercase English letters.
- brokenLetters consists of distinct lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1935. Maximum Number of Words You Can Type

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traversal + Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Traversal + Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int canBeTypedWords(char* text, char* brokenLetters) {
    bool broken[26] = {false};  // set of broken letter keys
    for (int i = 0; brokenLetters[i]; i++) {
        broken[brokenLetters[i] - 'a'] = true;
    }
    int res = 0;  // the number of words that can be fully inputted
    bool flag =
        true;  // is the current character in the word completely inputtable
    for (int i = 0; text[i]; i++) {
        if (text[i] == ' ') {
            // the current character is a space, check the status of the
            // previous word, update the count and initialize the flag
            if (flag) {
                ++res;
            }
            flag = true;
        } else if (broken[text[i] - 'a']) {
            // the current character cannot be entered, the word it is in cannot
            // be fully entered, update flag
            flag = false;
        }
    }
    // judge the status of the last word and update the count
    if (flag) {
        ++res;
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
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;  // set of broken letter keys
        for (char ch : brokenLetters) {
            broken.insert(ch);
        }
        int res = 0;  // the number of words that can be fully inputted
        bool flag =
            true;  // is the current character in the word completely inputtable
        for (char ch : text) {
            if (ch == ' ') {
                // the current character is a space, check the status of the
                // previous word, update the count and initialize the flag
                if (flag) {
                    ++res;
                }
                flag = true;
            } else if (broken.count(ch)) {
                // the current character cannot be entered, the word it is in
                // cannot be fully entered, update flag
                flag = false;
            }
        }
        // judge the status of the last word and update the count
        if (flag) {
            ++res;
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
    public int CanBeTypedWords(string text, string brokenLetters) {
        HashSet<char> broken =
            new HashSet<char>();  // set of broken letter keys
        foreach (char ch in brokenLetters) {
            broken.Add(ch);
        }
        int res = 0;  // the number of words that can be fully inputted
        bool flag =
            true;  // is the current character in the word completely inputtable
        foreach (char ch in text) {
            if (ch == ' ') {
                // the current character is a space, check the status of the
                // previous word, update the count and initialize the flag
                if (flag) {
                    ++res;
                }
                flag = true;
            } else if (broken.Contains(ch)) {
                // the current character cannot be entered, the word it is in
                // cannot be fully entered, update flag
                flag = false;
            }
        }
        // judge the status of the last word and update the count
        if (flag) {
            ++res;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func canBeTypedWords(text string, brokenLetters string) int {
	broken := make(map[rune]bool) // set of broken letter keys
	for _, ch := range brokenLetters {
		broken[ch] = true
	}
	res := 0     // the number of words that can be fully inputted
	flag := true // is the current character in the word completely inputtable
	for _, ch := range text {
		if ch == ' ' {
			// the current character is a space, check the status of the
			// previous word, update the count and initialize the flag
			if flag {
				res++
			}
			flag = true
		} else if broken[ch] {
			// the current character cannot be entered, the word it is in cannot
			// be fully entered, update flag
			flag = false
		}
	}
	// judge the status of the last word and update the count
	if flag {
		res++
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> broken = new HashSet<>(); // set of broken letter keys
        for (char ch : brokenLetters.toCharArray()) {
            broken.add(ch);
        }
        int res = 0; // the number of words that can be fully inputted
        boolean flag = true; // is the current character in the word completely inputtable
        for (char ch : text.toCharArray()) {
            if (ch == ' ') {
                // the current character is a space, check the status of the previous word, update the count and initialize the flag
                if (flag) {
                    ++res;
                }
                flag = true;
            } else if (broken.contains(ch)) {
                // the current character cannot be entered, the word it is in cannot be fully entered, update flag
                flag = false;
            }
        }
        // judge the status of the last word and update the count
        if (flag) {
            ++res;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var canBeTypedWords = function (text, brokenLetters) {
    const broken = new Set(); // set of broken letter keys
    for (const ch of brokenLetters) {
        broken.add(ch);
    }
    let res = 0; // the number of words that can be fully inputted
    let flag = true; // is the current character in the word completely inputtable
    for (const ch of text) {
        if (ch === " ") {
            // the current character is a space, check the status of the previous word, update the count and initialize the flag
            if (flag) {
                ++res;
            }
            flag = true;
        } else if (broken.has(ch)) {
            // the current character cannot be entered, the word it is in cannot be fully entered, update flag
            flag = false;
        }
    }
    // judge the status of the last word and update the count
    if (flag) {
        ++res;
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        broken = set(brokenLetters)  # set of broken letter keys
        res = 0  # the number of words that can be fully inputted
        flag = (
            True  # is the current character in the word completely inputtable
        )
        for ch in text:
            if ch == " ":
                # the current character is a space, check the status of the previous word, update the count and initialize the flag
                if flag:
                    res += 1
                flag = True
            elif ch in broken:
                # the current character cannot be entered, the word it is in cannot be fully entered, update flag
                flag = False
        # judge the status of the last word and update the count
        if flag:
            res += 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function canBeTypedWords(text: string, brokenLetters: string): number {
    const broken = new Set<string>(); // set of broken letter keys
    for (const ch of brokenLetters) {
        broken.add(ch);
    }
    let res = 0; // the number of words that can be fully inputted
    let flag = true; // is the current character in the word completely inputtable
    for (const ch of text) {
        if (ch === " ") {
            // the current character is a space, check the status of the previous word, update the count and initialize the flag
            if (flag) {
                ++res;
            }
            flag = true;
        } else if (broken.has(ch)) {
            // the current character cannot be entered, the word it is in cannot be fully entered, update flag
            flag = false;
        }
    }
    // judge the status of the last word and update the count
    if (flag) {
        ++res;
    }
    return res;
}
```

</details>
