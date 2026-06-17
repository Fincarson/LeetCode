# 3120. Count the Number of Special Characters I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/count-the-number-of-special-characters-i/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 3120 - Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/)

## Problem

You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= word.length <= 50
- word consists of only lowercase and uppercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Detect Capital](https://leetcode.com/problems/detect-capital/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Greatest English Letter in Upper and Lower Case](https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3120. Count the Number of Special Characters I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash set | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash set

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numberOfSpecialChars(char* word) {
    int seen[128] = {0};
    for (int i = 0; word[i]; i++) {
        seen[(unsigned char)word[i]] = 1;
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (seen[(int)c] && seen[(int)(c - 'a' + 'A')]) {
            ans++;
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
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.count(c) && s.count(c - 'a' + 'A')) {
                ans++;
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
    public int NumberOfSpecialChars(string word) {
        var s = new HashSet<char>(word);
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.Contains(c) && s.Contains((char)(c - 'a' + 'A'))) {
                ans++;
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
func numberOfSpecialChars(word string) int {
	s := make(map[rune]bool)
	for _, c := range word {
		s[c] = true
	}
	ans := 0
	for c := 'a'; c <= 'z'; c++ {
		if s[c] && s[c-'a'+'A'] {
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

    public int numberOfSpecialChars(String word) {
        Set<Character> s = new HashSet<>();
        for (char c : word.toCharArray()) {
            s.add(c);
        }
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.contains(c) && s.contains((char) (c - 'a' + 'A'))) {
                ans++;
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
var numberOfSpecialChars = function (word) {
    const s = new Set(word);
    let ans = 0;
    for (let i = 0; i < 26; i++) {
        const lo = String.fromCharCode(97 + i);
        const up = String.fromCharCode(65 + i);
        if (s.has(lo) && s.has(up)) {
            ans++;
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
    def numberOfSpecialChars(self, word: str) -> int:
        s = set(word)
        return sum(c in s and c.upper() in s for c in string.ascii_lowercase)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfSpecialChars(word: string): number {
    const s = new Set(word);
    let ans = 0;
    for (let i = 0; i < 26; i++) {
        const lo = String.fromCharCode(97 + i);
        const up = String.fromCharCode(65 + i);
        if (s.has(lo) && s.has(up)) {
            ans++;
        }
    }
    return ans;
}
```

</details>
