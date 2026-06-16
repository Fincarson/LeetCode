# 2942. Find Words Containing Character

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-words-containing-character/)  
`Array` `String`

**Problem Link:** [LeetCode 2942 - Find Words Containing Character](https://leetcode.com/problems/find-words-containing-character/)

## Problem

You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.

### Example 1

```text
Input: words = ["leet","code"], x = "e"
Output: [0,1]
Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.
```

### Example 2

```text
Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
Output: [0,2]
Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.
```

### Example 3

```text
Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
Output: []
Explanation: "z" does not occur in any of the words. Hence, we return an empty array.
```

## Constraints

- 1 <= words.length <= 50
- 1 <= words[i].length <= 50
- x is a lowercase English letter.
- words[i] consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2942. Find Words Containing Character

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
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int* res = (int*)malloc(wordsSize * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (strchr(words[i], x) != NULL) {
            res[(*returnSize)++] = i;
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
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i].find(x) != string::npos) {
                res.push_back(i);
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
    public IList<int> FindWordsContaining(string[] words, char x) {
        List<int> res = new List<int>();
        int n = words.Length;
        for (int i = 0; i < n; i++) {
            if (words[i].Contains(x)) {
                res.Add(i);
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
func findWordsContaining(words []string, x byte) []int {
	res := []int{}
	n := len(words)
	for i := 0; i < n; i++ {
		for j := 0; j < len(words[i]); j++ {
			if words[i][j] == x {
				res = append(res, i)
				break
			}
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

    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> res = new ArrayList<>();
        int n = words.length;
        for (int i = 0; i < n; i++) {
            if (words[i].indexOf(x) != -1) {
                res.add(i);
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
var findWordsContaining = function (words, x) {
    const res = [];
    const n = words.length;
    for (let i = 0; i < n; i++) {
        if (words[i].includes(x)) {
            res.push(i);
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
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        res = []
        n = len(words)
        for i in range(n):
            if x in words[i]:
                res.append(i)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findWordsContaining(words: string[], x: string): number[] {
    const res = [];
    const n = words.length;
    for (let i = 0; i < n; i++) {
        if (words[i].includes(x)) {
            res.push(i);
        }
    }
    return res;
}
```

</details>
