# 3541. Find Most Frequent Vowel and Consonant

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 3541 - Find Most Frequent Vowel and Consonant](https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/)

## Problem

You are given a string s consisting of lowercase English letters ('a' to 'z').

Your task is to:

- Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
- Find the consonant (all other letters excluding vowels) with the maximum frequency.

Return the sum of the two frequencies.

Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 100
- s consists of lowercase English letters only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3541. Find Most Frequent Vowel and Consonant

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxFreqSum(char* s) {
    int mp[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        mp[s[i] - 'a']++;
    }

    int vowel = 0, consonant = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (is_vowel(ch)) {
            vowel = fmax(vowel, mp[ch - 'a']);
        } else {
            consonant = fmax(consonant, mp[ch - 'a']);
        }
    }
    return vowel + consonant;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        int vowel = 0, consonant = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (is_vowel(ch)) {
                vowel = max(vowel, mp[ch]);
            } else {
                consonant = max(consonant, mp[ch]);
            }
        }
        return vowel + consonant;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxFreqSum(string s) {
        Dictionary<char, int> mp = new Dictionary<char, int>();
        foreach (char ch in s) {
            if (mp.ContainsKey(ch)) {
                mp[ch]++;
            } else {
                mp[ch] = 1;
            }
        }
        int vowel = 0, consonant = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int count = mp.ContainsKey(ch) ? mp[ch] : 0;
            if (IsVowel(ch)) {
                vowel = Math.Max(vowel, count);
            } else {
                consonant = Math.Max(consonant, count);
            }
        }
        return vowel + consonant;
    }

    private bool IsVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxFreqSum(s string) int {
	mp := make(map[byte]int)
	for i := 0; i < len(s); i++ {
		mp[s[i]]++
	}

	vowel, consonant := 0, 0
	for ch := 'a'; ch <= 'z'; ch++ {
		count := mp[byte(ch)]
		if isVowel(byte(ch)) {
			vowel = max(vowel, count)
		} else {
			consonant = max(consonant, count)
		}
	}
	return vowel + consonant
}

func isVowel(c byte) bool {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxFreqSum(String s) {
        Map<Character, Integer> mp = new HashMap<>();
        for (char ch : s.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }
        int vowel = 0;
        int consonant = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (isVowel(ch)) {
                vowel = Math.max(vowel, mp.getOrDefault(ch, 0));
            } else {
                consonant = Math.max(consonant, mp.getOrDefault(ch, 0));
            }
        }
        return vowel + consonant;
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxFreqSum = function (s) {
    const isVowel = (c) => {
        return c === "a" || c === "e" || c === "i" || c === "o" || c === "u";
    };

    const mp = {};
    for (const ch of s) {
        mp[ch] = (mp[ch] || 0) + 1;
    }

    let vowel = 0,
        consonant = 0;
    for (let ch = "a".charCodeAt(0); ch <= "z".charCodeAt(0); ch++) {
        const char = String.fromCharCode(ch);
        const count = mp[char] || 0;
        if (isVowel(char)) {
            vowel = Math.max(vowel, count);
        } else {
            consonant = Math.max(consonant, count);
        }
    }
    return vowel + consonant;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter


class Solution:
    def maxFreqSum(self, s: str) -> int:
        mp = Counter(s)
        vowel = max((mp[ch] for ch in mp if ch in "aeiou"), default=0)
        consonant = max((mp[ch] for ch in mp if ch not in "aeiou"), default=0)
        return vowel + consonant
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxFreqSum(s: string): number {
    const isVowel = (c) => {
        return c === "a" || c === "e" || c === "i" || c === "o" || c === "u";
    };

    const mp: { [key: string]: number } = {};
    for (const ch of s) {
        mp[ch] = (mp[ch] || 0) + 1;
    }

    let vowel = 0,
        consonant = 0;
    for (let ch = "a".charCodeAt(0); ch <= "z".charCodeAt(0); ch++) {
        const char = String.fromCharCode(ch);
        const count = mp[char] || 0;
        if (isVowel(char)) {
            vowel = Math.max(vowel, count);
        } else {
            consonant = Math.max(consonant, count);
        }
    }
    return vowel + consonant;
}
```

</details>
