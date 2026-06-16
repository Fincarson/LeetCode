# 2900. Longest Unequal Adjacent Groups Subsequence I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/)  
`Array` `String` `Dynamic Programming` `Greedy`

**Problem Link:** [LeetCode 2900 - Longest Unequal Adjacent Groups Subsequence I](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/)

## Problem

You are given a string array words and a binary array groups both of length n.

A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements at the same indices in groups are different (that is, there cannot be consecutive 0 or 1).

Your task is to select the longest alternating subsequence from words.

Return the selected subsequence. If there are multiple answers, return any of them.

Note: The elements in words are distinct.

### Example 1

### Example 2

## Constraints

- 1 <= n == words.length == groups.length <= 100
- 1 <= words[i].length <= 10
- groups[i] is either 0 or 1.
- words consists of distinct strings.
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

# Editorial - 2900. Longest Unequal Adjacent Groups Subsequence I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char** getLongestSubsequence(char** words, int wordsSize, int* groups,
                             int groupsSize, int* returnSize) {
    int* dp = (int*)malloc(wordsSize * sizeof(int));
    int* prev = (int*)malloc(wordsSize * sizeof(int));
    int maxLen = 1, endIndex = 0;

    for (int i = 0; i < wordsSize; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }
    for (int i = 1; i < wordsSize; i++) {
        int bestLen = 1;
        int bestPrev = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (groups[i] != groups[j] && dp[j] + 1 > bestLen) {
                bestLen = dp[j] + 1;
                bestPrev = j;
            }
        }
        dp[i] = bestLen;
        prev[i] = bestPrev;
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            endIndex = i;
        }
    }

    char** res = (char**)malloc(maxLen * sizeof(char*));
    int pos = 0;
    for (int i = endIndex; i != -1; i = prev[i]) {
        res[pos++] = words[i];
    }
    for (int i = 0; i < pos / 2; i++) {
        char* temp = res[i];
        res[i] = res[pos - 1 - i];
        res[pos - 1 - i] = temp;
    }
    *returnSize = pos;
    free(dp);
    free(prev);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxLen = 1, endIndex = 0;

        for (int i = 1; i < n; i++) {
            int bestLen = 1;
            int bestPrev = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (groups[i] != groups[j] && dp[j] + 1 > bestLen) {
                    bestLen = dp[j] + 1;
                    bestPrev = j;
                }
            }
            dp[i] = bestLen;
            prev[i] = bestPrev;
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }

        vector<string> res;
        for (int i = endIndex; i != -1; i = prev[i]) {
            res.emplace_back(words[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<string> GetLongestSubsequence(string[] words, int[] groups) {
        int n = words.Length;
        int[] dp = new int[n];
        int[] prev = new int[n];
        int maxLen = 1, endIndex = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            prev[i] = -1;
        }
        for (int i = 1; i < n; i++) {
            int bestLen = 1;
            int bestPrev = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (groups[i] != groups[j] && dp[j] + 1 > bestLen) {
                    bestLen = dp[j] + 1;
                    bestPrev = j;
                }
            }
            dp[i] = bestLen;
            prev[i] = bestPrev;
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }

        List<string> res = new List<string>();
        for (int i = endIndex; i != -1; i = prev[i]) {
            res.Add(words[i]);
        }
        res.Reverse();
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getLongestSubsequence(words []string, groups []int) []string {
	n := len(words)
	dp := make([]int, n)
	prev := make([]int, n)
	maxLen, endIndex := 1, 0

	for i := 0; i < n; i++ {
		dp[i] = 1
		prev[i] = -1
	}
	for i := 1; i < n; i++ {
		bestLen, bestPrev := 1, -1
		for j := i - 1; j >= 0; j-- {
			if groups[i] != groups[j] && dp[j]+1 > bestLen {
				bestLen, bestPrev = dp[j]+1, j
			}
		}
		dp[i] = bestLen
		prev[i] = bestPrev
		if dp[i] > maxLen {
			maxLen, endIndex = dp[i], i
		}
	}

	res := make([]string, 0)
	for i := endIndex; i != -1; i = prev[i] {
		res = append(res, words[i])
	}
	reverse(res)
	return res
}

func reverse(s []string) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        int n = words.length;
        int[] dp = new int[n];
        int[] prev = new int[n];
        int maxLen = 1, endIndex = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            prev[i] = -1;
        }
        for (int i = 1; i < n; i++) {
            int bestLen = 1;
            int bestPrev = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (groups[i] != groups[j] && dp[j] + 1 > bestLen) {
                    bestLen = dp[j] + 1;
                    bestPrev = j;
                }
            }
            dp[i] = bestLen;
            prev[i] = bestPrev;
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }

        List<String> res = new ArrayList<>();
        for (int i = endIndex; i != -1; i = prev[i]) {
            res.add(words[i]);
        }
        Collections.reverse(res);
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getLongestSubsequence = function (words, groups) {
    const n = words.length;
    const dp = new Array(n).fill(1);
    const prev = new Array(n).fill(-1);
    let maxLen = 1,
        endIndex = 0;

    for (let i = 1; i < n; i++) {
        let bestLen = 1;
        let bestPrev = -1;
        for (let j = i - 1; j >= 0; j--) {
            if (groups[i] !== groups[j] && dp[j] + 1 > bestLen) {
                bestLen = dp[j] + 1;
                bestPrev = j;
            }
        }
        dp[i] = bestLen;
        prev[i] = bestPrev;
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            endIndex = i;
        }
    }

    const res = [];
    for (let i = endIndex; i !== -1; i = prev[i]) {
        res.push(words[i]);
    }
    return res.reverse();
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getLongestSubsequence(
        self, words: List[str], groups: List[int]
    ) -> List[str]:
        n = len(words)
        dp = [1] * n
        prev = [-1] * n
        max_len, end_index = 1, 0

        for i in range(1, n):
            best_len, best_prev = 1, -1
            for j in range(i - 1, -1, -1):
                if groups[i] != groups[j] and dp[j] + 1 > best_len:
                    best_len, best_prev = dp[j] + 1, j
            dp[i] = best_len
            prev[i] = best_prev
            if dp[i] > max_len:
                max_len, end_index = dp[i], i

        res = []
        i = end_index
        while i != -1:
            res.append(words[i])
            i = prev[i]
        return res[::-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getLongestSubsequence(words: string[], groups: number[]): string[] {
    const n = words.length;
    const dp: number[] = new Array(n).fill(1);
    const prev: number[] = new Array(n).fill(-1);
    let maxLen = 1,
        endIndex = 0;

    for (let i = 1; i < n; i++) {
        let bestLen = 1;
        let bestPrev = -1;
        for (let j = i - 1; j >= 0; j--) {
            if (groups[i] !== groups[j] && dp[j] + 1 > bestLen) {
                bestLen = dp[j] + 1;
                bestPrev = j;
            }
        }
        dp[i] = bestLen;
        prev[i] = bestPrev;
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            endIndex = i;
        }
    }

    const res: string[] = [];
    for (let i = endIndex; i !== -1; i = prev[i]) {
        res.push(words[i]);
    }
    return res.reverse();
}
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char** getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
    char** ans = (char**)malloc(wordsSize * sizeof(char*));
    int pos = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (i == 0 || groups[i] != groups[i - 1]) {
            ans[pos++] = words[i];
        }
    }
    *returnSize = pos;
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.emplace_back(words[i]);
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
    public IList<string> GetLongestSubsequence(string[] words, int[] groups) {
        List<string> ans = new List<string>();
        int n = words.Length;
        for (int i = 0; i < n; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.Add(words[i]);
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
func getLongestSubsequence(words []string, groups []int) []string {
    var ans []string
    n := len(words)
    for i := 0; i < n; i++ {
        if i == 0 || groups[i] != groups[i-1] {
            ans = append(ans, words[i])
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
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        List<String> ans = new ArrayList<>();
        int n = words.length;
        for (int i = 0; i < n; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.add(words[i]);
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
var getLongestSubsequence = function(words, groups) {
    let ans = [];
    let n = words.length;
    for (let i = 0; i < n; i++) {
        if (i === 0 || groups[i] !== groups[i - 1]) {
            ans.push(words[i]);
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
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        return [words[0]] + [words[i] for i in range(1, len(groups)) if groups[i] != groups[i - 1]]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getLongestSubsequence(words: string[], groups: number[]): string[] {
    let ans: string[] = [];
    let n = words.length;
    for (let i = 0; i < n; i++) {
        if (i === 0 || groups[i] !== groups[i - 1]) {
            ans.push(words[i]);
        }
    }
    return ans;
};
```

</details>
