# 3136. Valid Word

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/valid-word/)  
`String`

**Problem Link:** [LeetCode 3136 - Valid Word](https://leetcode.com/problems/valid-word/)

## Problem

A word is considered valid if:

- It contains a minimum of 3 characters.
- It contains only digits (0-9), and English letters (uppercase and lowercase).
- It includes at least one vowel.
- It includes at least one consonant.

You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

- 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
- A consonant is an English letter that is not a vowel.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= word.length <= 20
- word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3136. Valid Word

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: One-Time Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: One-Time Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isValid(char* word) {
    int len = strlen(word);
    if (len < 3) {
        return false;
    }
    bool has_vowel = false;
    bool has_consonant = false;
    for (int i = 0; i < len; i++) {
        char c = word[i];
        if (isalpha(c)) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                has_vowel = true;
            } else {
                has_consonant = true;
            }
        } else if (!isdigit(c)) {
            return false;
        }
    }
    return has_vowel && has_consonant;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool has_vowel = false;
        bool has_consonant = false;
        for (auto c : word) {
            if (isalpha(c)) {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return has_vowel && has_consonant;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsValid(string word) {
        if (word.Length < 3) {
            return false;
        }
        bool hasVowel = false;
        bool hasConsonant = false;
        foreach (char c in word) {
            if (char.IsLetter(c)) {
                char ch = char.ToLower(c);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (!char.IsDigit(c)) {
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isValid(word string) bool {
	if len(word) < 3 {
		return false
	}
	hasVowel := false
	hasConsonant := false
	for _, c := range word {
		if unicode.IsLetter(c) {
			ch := unicode.ToLower(c)
			if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' {
				hasVowel = true
			} else {
				hasConsonant = true
			}
		} else if !unicode.IsDigit(c) {
			return false
		}
	}
	return hasVowel && hasConsonant
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isValid(String word) {
        if (word.length() < 3) {
            return false;
        }
        boolean hasVowel = false;
        boolean hasConsonant = false;
        for (char c : word.toCharArray()) {
            if (Character.isLetter(c)) {
                char ch = Character.toLowerCase(c);
                if (
                    ch == 'a' ||
                    ch == 'e' ||
                    ch == 'i' ||
                    ch == 'o' ||
                    ch == 'u'
                ) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (!Character.isDigit(c)) {
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isValid = function (word) {
    if (word.length < 3) {
        return false;
    }
    let hasVowel = false;
    let hasConsonant = false;
    for (const c of word) {
        if (/[a-zA-Z]/.test(c)) {
            const ch = c.toLowerCase();
            if (
                ch === "a" ||
                ch === "e" ||
                ch === "i" ||
                ch === "o" ||
                ch === "u"
            ) {
                hasVowel = true;
            } else {
                hasConsonant = true;
            }
        } else if (!/\d/.test(c)) {
            return false;
        }
    }
    return hasVowel && hasConsonant;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False

        has_vowel = False
        has_consonant = False

        for c in word:
            if c.isalpha():
                if c.lower() in "aeiou":
                    has_vowel = True
                else:
                    has_consonant = True
            elif not c.isdigit():
                return False

        return has_vowel and has_consonant
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isValid(word: string): boolean {
    if (word.length < 3) {
        return false;
    }
    let hasVowel = false;
    let hasConsonant = false;
    for (const c of word) {
        if (/[a-zA-Z]/.test(c)) {
            const ch = c.toLowerCase();
            if (
                ch === "a" ||
                ch === "e" ||
                ch === "i" ||
                ch === "o" ||
                ch === "u"
            ) {
                hasVowel = true;
            } else {
                hasConsonant = true;
            }
        } else if (!/\d/.test(c)) {
            return false;
        }
    }
    return hasVowel && hasConsonant;
}
```

</details>
