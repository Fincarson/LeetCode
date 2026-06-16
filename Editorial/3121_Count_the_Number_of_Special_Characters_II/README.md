# 3121. Count the Number of Special Characters II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-the-number-of-special-characters-ii/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 3121 - Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/)

## Problem

You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

Return the number of special letters in word.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= word.length <= 2 * 105
- word consists of only lowercase and uppercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Detect Capital](https://leetcode.com/problems/detect-capital/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Greatest English Letter in Upper and Lower Case](https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3121. Count the Number of Special Characters II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Record the Start and End Positions | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Record the Start and End Positions

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numberOfSpecialChars(char* word) {
    int lastLow[26], firstUp[26];
    memset(lastLow, -1, sizeof(lastLow));
    memset(firstUp, -1, sizeof(firstUp));
    for (int i = 0; word[i]; i++) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') {
            lastLow[c - 'a'] = i;
        } else {
            if (firstUp[c - 'A'] == -1) {
                firstUp[c - 'A'] = i;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (lastLow[i] != -1 && firstUp[i] != -1 && lastLow[i] < firstUp[i]) {
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
        vector<int> lastLow(26, -1), firstUp(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                lastLow[c - 'a'] = i;
            } else {
                if (firstUp[c - 'A'] == -1) {
                    firstUp[c - 'A'] = i;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLow[i] != -1 && firstUp[i] != -1 &&
                lastLow[i] < firstUp[i]) {
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
        int[] lastLow = new int[26];
        int[] firstUp = new int[26];
        Array.Fill(lastLow, -1);
        Array.Fill(firstUp, -1);
        for (int i = 0; i < word.Length; i++) {
            char c = word[i];
            if (char.IsLower(c)) {
                lastLow[c - 'a'] = i;
            } else {
                if (firstUp[c - 'A'] == -1) {
                    firstUp[c - 'A'] = i;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLow[i] != -1 && firstUp[i] != -1 &&
                lastLow[i] < firstUp[i]) {
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
	lastLow := [26]int{}
	firstUp := [26]int{}
	for i := range lastLow {
		lastLow[i] = -1
		firstUp[i] = -1
	}
	for i, c := range word {
		if c >= 'a' && c <= 'z' {
			lastLow[c-'a'] = i
		} else {
			if firstUp[c-'A'] == -1 {
				firstUp[c-'A'] = i
			}
		}
	}
	ans := 0
	for i := 0; i < 26; i++ {
		if lastLow[i] != -1 && firstUp[i] != -1 && lastLow[i] < firstUp[i] {
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
        int[] lastLow = new int[26];
        int[] firstUp = new int[26];
        Arrays.fill(lastLow, -1);
        Arrays.fill(firstUp, -1);
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (Character.isLowerCase(c)) {
                lastLow[c - 'a'] = i;
            } else {
                if (firstUp[c - 'A'] == -1) {
                    firstUp[c - 'A'] = i;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (
                lastLow[i] != -1 && firstUp[i] != -1 && lastLow[i] < firstUp[i]
            ) {
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
    const lastLow = new Array(26).fill(-1);
    const firstUp = new Array(26).fill(-1);
    for (let i = 0; i < word.length; i++) {
        const c = word[i];
        if (c >= "a" && c <= "z") {
            lastLow[c.charCodeAt(0) - 97] = i;
        } else {
            const idx = c.charCodeAt(0) - 65;
            if (firstUp[idx] === -1) firstUp[idx] = i;
        }
    }
    let ans = 0;
    for (let i = 0; i < 26; i++) {
        if (lastLow[i] !== -1 && firstUp[i] !== -1 && lastLow[i] < firstUp[i]) {
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
        last_low = {}
        first_up = {}
        for i, c in enumerate(word):
            if c.islower():
                last_low[c] = i
            else:
                if c not in first_up:
                    first_up[c] = i
        ans = 0
        for c in string.ascii_lowercase:
            if (
                c in last_low
                and c.upper() in first_up
                and last_low[c] < first_up[c.upper()]
            ):
                ans += 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfSpecialChars(word: string): number {
    const lastLow = new Array(26).fill(-1);
    const firstUp = new Array(26).fill(-1);
    for (let i = 0; i < word.length; i++) {
        const c = word[i];
        if (c >= "a" && c <= "z") {
            lastLow[c.charCodeAt(0) - 97] = i;
        } else {
            const idx = c.charCodeAt(0) - 65;
            if (firstUp[idx] === -1) firstUp[idx] = i;
        }
    }
    let ans = 0;
    for (let i = 0; i < 26; i++) {
        if (lastLow[i] !== -1 && firstUp[i] !== -1 && lastLow[i] < firstUp[i]) {
            ans++;
        }
    }
    return ans;
}
```

</details>
