# 3085. Minimum Deletions to Make String K-Special

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/)  
`Hash Table` `String` `Greedy` `Sorting` `Counting`

**Problem Link:** [LeetCode 3085 - Minimum Deletions to Make String K-Special](https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/)

## Problem

You are given a string word and an integer k.

We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.

Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.

Return the minimum number of characters you need to delete to make word k-special.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= word.length <= 105
- 0 <= k <= 105
- word consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Deletions to Make Character Frequencies Unique](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3085. Minimum Deletions to Make String K-Special

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Table + Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash Table + Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumDeletions(char* word, int k) {
    int cnt[26] = {0};
    for (int i = 0; word[i]; i++) {
        cnt[word[i] - 'a']++;
    }
    int res = strlen(word);
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        int a = cnt[i];
        int deleted = 0;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] == 0) {
                continue;
            }
            int b = cnt[j];
            if (a > b) {
                deleted += b;
            } else if (b > a + k) {
                deleted += b - (a + k);
            }
        }
        if (deleted < res) {
            res = deleted;
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
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> cnt;
        for (auto &ch : word) {
            cnt[ch]++;
        }
        int res = word.size();
        for (auto &[_, a] : cnt) {
            int deleted = 0;
            for (auto &[_, b] : cnt) {
                if (a > b) {
                    deleted += b;
                } else if (b > a + k) {
                    deleted += b - (a + k);
                }
            }
            res = min(res, deleted);
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
    public int MinimumDeletions(string word, int k) {
        Dictionary<char, int> cnt = new Dictionary<char, int>();
        foreach (char ch in word) {
            if (cnt.ContainsKey(ch)) {
                cnt[ch]++;
            } else {
                cnt[ch] = 1;
            }
        }
        int res = word.Length;
        foreach (int a in cnt.Values) {
            int deleted = 0;
            foreach (int b in cnt.Values) {
                if (a > b) {
                    deleted += b;
                } else if (b > a + k) {
                    deleted += b - (a + k);
                }
            }
            res = Math.Min(res, deleted);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumDeletions(word string, k int) int {
	cnt := make(map[rune]int)
	for _, ch := range word {
		cnt[ch]++
	}
	res := len(word)
	for _, a := range cnt {
		deleted := 0
		for _, b := range cnt {
			if a > b {
				deleted += b
			} else if b > a+k {
				deleted += b - (a + k)
			}
		}
		if deleted < res {
			res = deleted
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDeletions(String word, int k) {
        Map<Character, Integer> cnt = new HashMap<>();
        for (char ch : word.toCharArray()) {
            cnt.put(ch, cnt.getOrDefault(ch, 0) + 1);
        }
        int res = word.length();
        for (int a : cnt.values()) {
            int deleted = 0;
            for (int b : cnt.values()) {
                if (a > b) {
                    deleted += b;
                } else if (b > a + k) {
                    deleted += b - (a + k);
                }
            }
            res = Math.min(res, deleted);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumDeletions = function (word, k) {
    const cnt = new Map();
    for (const ch of word) {
        cnt.set(ch, (cnt.get(ch) || 0) + 1);
    }
    let res = word.length;
    for (const a of cnt.values()) {
        let deleted = 0;
        for (const b of cnt.values()) {
            if (a > b) {
                deleted += b;
            } else if (b > a + k) {
                deleted += b - (a + k);
            }
        }
        res = Math.min(res, deleted);
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        cnt = defaultdict(int)
        for c in word:
            cnt[c] += 1
        res = len(word)
        for a in cnt.values():
            deleted = 0
            for b in cnt.values():
                if a > b:
                    deleted += b
                elif b > a + k:
                    deleted += b - (a + k)
            res = min(res, deleted)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumDeletions(word: string, k: number): number {
    const cnt = new Map<string, number>();
    for (const ch of word) {
        cnt.set(ch, (cnt.get(ch) || 0) + 1);
    }
    let res = word.length;
    for (const a of cnt.values()) {
        let deleted = 0;
        for (const b of cnt.values()) {
            if (a > b) {
                deleted += b;
            } else if (b > a + k) {
                deleted += b - (a + k);
            }
        }
        res = Math.min(res, deleted);
    }
    return res;
}
```

</details>
