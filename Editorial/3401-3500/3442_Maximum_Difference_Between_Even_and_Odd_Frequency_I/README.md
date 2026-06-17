# 3442. Maximum Difference Between Even and Odd Frequency I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 3442 - Maximum Difference Between Even and Odd Frequency I](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/)

## Problem

You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

- a1 has an odd frequency in the string.
- a2 has an even frequency in the string.

Return this maximum difference.

### Example 1

### Example 2

## Constraints

- 3 <= s.length <= 100
- s consists only of lowercase English letters.
- s contains at least one character with an odd frequency and one with an even frequency.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3442. Maximum Difference Between Even and Odd Frequency I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Count The Frequency Of Each Character | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Count The Frequency Of Each Character

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxDifference(char* s) {
    int count[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }
    int maxOdd = 1, minEven = len;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            if (count[i] % 2 == 1) {
                maxOdd = fmax(maxOdd, count[i]);
            } else {
                minEven = fmin(minEven, count[i]);
            }
        }
    }
    return maxOdd - minEven;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> c;
        for (char ch : s) {
            ++c[ch];
        }
        int maxOdd = 1, minEven = s.size();
        for (const auto& [_, value] : c) {
            if (value % 2 == 1) {
                maxOdd = max(maxOdd, value);
            } else {
                minEven = min(minEven, value);
            }
        }
        return maxOdd - minEven;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxDifference(string s) {
        Dictionary<char, int> c = new Dictionary<char, int>();
        foreach (char ch in s) {
            if (c.ContainsKey(ch)) {
                c[ch]++;
            } else {
                c[ch] = 1;
            }
        }
        int maxOdd = 1, minEven = s.Length;
        foreach (var kvp in c) {
            if (kvp.Value % 2 == 1) {
                maxOdd = Math.Max(maxOdd, kvp.Value);
            } else {
                minEven = Math.Min(minEven, kvp.Value);
            }
        }
        return maxOdd - minEven;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDifference(s string) int {
	c := make(map[rune]int)
	for _, ch := range s {
		c[ch]++
	}
	maxOdd, minEven := 1, len(s)
	for _, value := range c {
		if value%2 == 1 {
			maxOdd = max(maxOdd, value)
		} else {
			minEven = min(minEven, value)
		}
	}
	return maxOdd - minEven
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxDifference(String s) {
        Map<Character, Integer> c = new HashMap<>();
        for (char ch : s.toCharArray()) {
            c.put(ch, c.getOrDefault(ch, 0) + 1);
        }
        int maxOdd = 1, minEven = s.length();
        for (int value : c.values()) {
            if (value % 2 == 1) {
                maxOdd = Math.max(maxOdd, value);
            } else {
                minEven = Math.min(minEven, value);
            }
        }
        return maxOdd - minEven;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDifference = function (s) {
    const c = new Map();
    for (const ch of s) {
        c.set(ch, (c.get(ch) || 0) + 1);
    }
    let maxOdd = 1,
        minEven = s.length;
    for (const [_, value] of c) {
        if (value % 2 === 1) {
            maxOdd = Math.max(maxOdd, value);
        } else {
            minEven = Math.min(minEven, value);
        }
    }
    return maxOdd - minEven;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDifference(self, s: str) -> int:
        c = Counter(s)
        maxOdd = max(x for x in c.values() if x % 2 == 1)
        minEven = min(x for x in c.values() if x % 2 == 0)
        return maxOdd - minEven
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDifference(s: string): number {
    const c: Map<string, number> = new Map();
    for (const ch of s) {
        c.set(ch, (c.get(ch) || 0) + 1);
    }
    let maxOdd = 1,
        minEven = s.length;
    for (const [_, value] of c) {
        if (value % 2 === 1) {
            maxOdd = Math.max(maxOdd, value);
        } else {
            minEven = Math.min(minEven, value);
        }
    }
    return maxOdd - minEven;
}
```

</details>
