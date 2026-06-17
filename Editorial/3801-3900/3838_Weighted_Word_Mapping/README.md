# 3838. Weighted Word Mapping

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/weighted-word-mapping/)  
`Array` `String` `Simulation`

**Problem Link:** [LeetCode 3838 - Weighted Word Mapping](https://leetcode.com/problems/weighted-word-mapping/)

## Problem

You are given an array of strings words, where each string represents a word containing lowercase English letters.

You are also given an integer array weights of length 26, where weights[i] represents the weight of the ith lowercase English letter.

The weight of a word is defined as the sum of the weights of its characters.

For each word, take its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order (0 -> 'z', 1 -> 'y', ..., 25 -> 'a').

Return a string formed by concatenating the mapped characters for all words in order.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= words.length <= 100
- 1 <= words[i].length <= 10
- weights.length == 26
- 1 <= weights[i] <= 100
- words[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3838. Weighted Word Mapping

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* mapWordWeights(char** words, int wordsSize, int* weights,
                     int weightsSize) {
    char* ans = (char*)malloc((wordsSize + 1) * sizeof(char));
    for (int i = 0; i < wordsSize; i++) {
        int s = 0;
        for (char* p = words[i]; *p; p++) {
            s += weights[*p - 'a'];
        }
        ans[i] = 'z' - s % 26;
    }
    ans[wordsSize] = '\0';
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        ans.reserve(words.size());
        for (string word : words) {
            int s = 0;
            for (char c : word) {
                s += weights[c - 'a'];
            }
            ans += 'z' - s % 26;
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
    public string MapWordWeights(string[] words, int[] weights) {
        var ans = new StringBuilder(words.Length);
        foreach (string word in words) {
            int s = 0;
            foreach (char c in word) {
                s += weights[c - 'a'];
            }
            ans.Append((char)('z' - s % 26));
        }
        return ans.ToString();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func mapWordWeights(words []string, weights []int) string {
	ans := make([]byte, 0, len(words))
	for _, word := range words {
		s := 0
		for _, c := range word {
			s += weights[c-'a']
		}
		ans = append(ans, byte('z'-s%26))
	}
	return string(ans)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder ans = new StringBuilder(words.length);
        for (String word : words) {
            int s = 0;
            for (int i = 0; i < word.length(); i++) {
                s += weights[word.charAt(i) - 'a'];
            }
            ans.append((char) ('z' - (s % 26)));
        }
        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var mapWordWeights = function (words, weights) {
    let ans = "";
    for (const word of words) {
        let s = 0;
        for (const c of word) {
            s += weights[c.charCodeAt(0) - "a".charCodeAt(0)];
        }
        ans += String.fromCharCode("z".charCodeAt(0) - (s % 26));
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = []
        for word in words:
            s = 0
            for c in word:
                s += weights[ord(c) - ord("a")]
            ans.append(chr(ord("z") - s % 26))
        return "".join(ans)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function mapWordWeights(words: string[], weights: number[]): string {
    let ans = "";
    for (const word of words) {
        let s = 0;
        for (const c of word) {
            s += weights[c.charCodeAt(0) - "a".charCodeAt(0)];
        }
        ans += String.fromCharCode("z".charCodeAt(0) - (s % 26));
    }
    return ans;
}
```

</details>
