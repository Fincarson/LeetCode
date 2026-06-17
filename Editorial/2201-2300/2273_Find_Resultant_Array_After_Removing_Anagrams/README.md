# 2273. Find Resultant Array After Removing Anagrams

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/)  
`Array` `Hash Table` `String` `Sorting`

**Problem Link:** [LeetCode 2273 - Find Resultant Array After Removing Anagrams](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/)

## Problem

You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.

In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.

Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".

### Example 1

```text
Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
Explanation:
One of the ways we can obtain the resultant array is by using the following operations:
- Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","baba","cd","cd"].
- Since words[1] = "baba" and words[0] = "abba" are anagrams, we choose index 1 and delete words[1].
  Now words = ["abba","cd","cd"].
- Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","cd"].
We can no longer perform any operations, so ["abba","cd"] is the final answer.
```

### Example 2

```text
Input: words = ["a","b","c","d","e"]
Output: ["a","b","c","d","e"]
Explanation:
No two adjacent strings in words are anagrams of each other, so no operations are performed.
```

## Constraints

- 1 <= words.length <= 100
- 1 <= words[i].length <= 10
- words[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2273. Find Resultant Array After Removing Anagrams

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Judge Individually | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Judge Individually

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// determine if two words are anagrams
bool compare(const char* word1, const char* word2) {
    int freq[26] = {0};
    for (int i = 0; word1[i] != '\0'; i++) {
        freq[word1[i] - 'a']++;
    }
    for (int i = 0; word2[i] != '\0'; i++) {
        freq[word2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }
    return true;
}

char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    char** res = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    res[(*returnSize)++] = words[0];  // result array

    for (int i = 1; i < wordsSize; i++) {
        if (!compare(words[i], words[i - 1])) {
            res[(*returnSize)++] = words[i];
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
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res = {words[0]};  // result array
        int n = words.size();
        // determine if two words are anagrams
        auto compare = [](const string& word1, const string& word2) -> bool {
            vector<int> freq(26);
            for (char ch : word1) {
                ++freq[ch - 'a'];
            }
            for (char ch : word2) {
                --freq[ch - 'a'];
            }
            return all_of(freq.begin(), freq.end(),
                          [](int x) { return x == 0; });
        };

        for (int i = 1; i < n; ++i) {
            if (compare(words[i], words[i - 1])) {
                continue;
            }
            res.push_back(words[i]);
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
    public IList<string> RemoveAnagrams(string[] words) {
        List<string> res = new List<string>();
        res.Add(words[0]);  // result array
        int n = words.Length;

        for (int i = 1; i < n; i++) {
            if (!Compare(words[i], words[i - 1])) {
                res.Add(words[i]);
            }
        }
        return res;
    }

    // determine if two words are anagrams
    private bool Compare(string word1, string word2) {
        int[] freq = new int[26];
        foreach (char ch in word1) {
            freq[ch - 'a']++;
        }
        foreach (char ch in word2) {
            freq[ch - 'a']--;
        }
        foreach (int x in freq) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func removeAnagrams(words []string) []string {
	res := []string{words[0]} // result array
	n := len(words)

	// determine if two words are anagrams
	compare := func(word1, word2 string) bool {
		freq := make([]int, 26)
		for _, ch := range word1 {
			freq[ch-'a']++
		}
		for _, ch := range word2 {
			freq[ch-'a']--
		}
		for _, x := range freq {
			if x != 0 {
				return false
			}
		}
		return true
	}

	for i := 1; i < n; i++ {
		if !compare(words[i], words[i-1]) {
			res = append(res, words[i])
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

    public List<String> removeAnagrams(String[] words) {
        List<String> res = new ArrayList<>();
        res.add(words[0]); // result array
        int n = words.length;
        for (int i = 1; i < n; i++) {
            if (!compare(words[i], words[i - 1])) {
                res.add(words[i]);
            }
        }
        return res;
    }

    // determine if two words are anagrams
    private boolean compare(String word1, String word2) {
        int[] freq = new int[26];
        for (char ch : word1.toCharArray()) {
            freq[ch - 'a']++;
        }
        for (char ch : word2.toCharArray()) {
            freq[ch - 'a']--;
        }
        for (int x : freq) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var removeAnagrams = function (words) {
    let res = [words[0]]; // result array
    let n = words.length;

    for (let i = 1; i < n; i++) {
        if (!compare(words[i], words[i - 1])) {
            res.push(words[i]);
        }
    }
    return res;
};

// determine if two words are anagrams
function compare(word1, word2) {
    let freq = new Array(26).fill(0);
    for (let ch of word1) {
        freq[ch.charCodeAt(0) - "a".charCodeAt(0)]++;
    }
    for (let ch of word2) {
        freq[ch.charCodeAt(0) - "a".charCodeAt(0)]--;
    }
    return freq.every((x) => x === 0);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        res = [words[0]]  # result array
        n = len(words)

        # determine if two words are anagrams
        def compare(word1: str, word2: str) -> bool:
            freq = [0] * 26
            for ch in word1:
                freq[ord(ch) - ord("a")] += 1
            for ch in word2:
                freq[ord(ch) - ord("a")] -= 1
            return all(x == 0 for x in freq)

        for i in range(1, n):
            if compare(words[i], words[i - 1]):
                continue
            res.append(words[i])
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function removeAnagrams(words: string[]): string[] {
    let res: string[] = [words[0]]; // result array
    let n: number = words.length;

    for (let i = 1; i < n; i++) {
        if (!compare(words[i], words[i - 1])) {
            res.push(words[i]);
        }
    }
    return res;
}

// determine if two words are anagrams
function compare(word1: string, word2: string): boolean {
    let freq: number[] = new Array(26).fill(0);
    for (let ch of word1) {
        freq[ch.charCodeAt(0) - "a".charCodeAt(0)]++;
    }
    for (let ch of word2) {
        freq[ch.charCodeAt(0) - "a".charCodeAt(0)]--;
    }
    return freq.every((x) => x === 0);
}
```

</details>
