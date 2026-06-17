# 2901. Longest Unequal Adjacent Groups Subsequence II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/)  
`Array` `String` `Dynamic Programming`

**Problem Link:** [LeetCode 2901 - Longest Unequal Adjacent Groups Subsequence II](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/)

## Problem

You are given a string array words, and an array groups, both arrays having length n.

The hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.

You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:

- For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
- words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j + 1 < k, for all indices in the subsequence.

Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.

Note: strings in words may be unequal in length.

### Example 1

### Example 2

## Constraints

- 1 <= n == words.length == groups.length <= 1000
- 1 <= words[i].length <= 10
- 1 <= groups[i] <= n
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

# Editorial - 2901. Longest Unequal Adjacent Groups Subsequence II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool check(const char *s1, const char *s2) {
    if (strlen(s1) != strlen(s2)) {
        return false;
    }
    int diff = 0;
    for (int i = 0; s1[i]; i++) {
        if (s1[i] != s2[i]) {
            if (++diff > 1) {
                return false;
            }
        }
    }
    return diff == 1;
}

char **getWordsInLongestSubsequence(char **words, int wordsSize, int *groups,
                                    int groupsSize, int *returnSize) {
    int *dp = (int *)malloc(wordsSize * sizeof(int));
    int *prev = (int *)malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }
    int maxIndex = 0;
    for (int i = 1; i < wordsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (check(words[i], words[j]) && dp[j] + 1 > dp[i] &&
                groups[i] != groups[j]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    int count = 0;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
        count++;
    }

    char **ans = (char **)malloc(count * sizeof(char *));
    int index = 0;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
        ans[index++] = words[i];
    }
    for (int i = 0; i < count / 2; i++) {
        char *temp = ans[i];
        ans[i] = ans[count - 1 - i];
        ans[count - 1 - i] = temp;
    }

    *returnSize = count;
    free(dp);
    free(prev);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = groups.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) == 1 && dp[j] + 1 > dp[i] &&
                    groups[i] != groups[j]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        vector<string> ans;
        for (int i = maxIndex; i >= 0; i = prev[i]) {
            ans.emplace_back(words[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            diff += s1[i] != s2[i];
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<string> GetWordsInLongestSubsequence(string[] words,
                                                      int[] groups) {
        int n = groups.Length;
        int[] dp = new int[n];
        int[] prev = new int[n];
        Array.Fill(dp, 1);
        Array.Fill(prev, -1);
        int maxIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (Check(words[i], words[j]) && dp[j] + 1 > dp[i] &&
                    groups[i] != groups[j]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        List<string> ans = new List<string>();
        for (int i = maxIndex; i >= 0; i = prev[i]) {
            ans.Add(words[i]);
        }
        ans.Reverse();
        return ans;
    }

    private bool Check(string s1, string s2) {
        if (s1.Length != s2.Length) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s1.Length; i++) {
            if (s1[i] != s2[i]) {
                if (++diff > 1) {
                    return false;
                }
            }
        }
        return diff == 1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getWordsInLongestSubsequence(words []string, groups []int) []string {
    n := len(groups)
	dp := make([]int, n)
	prev := make([]int, n)
	for i := range dp {
		dp[i] = 1
		prev[i] = -1
	}
	maxIndex := 0

	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if check(words[i], words[j]) && dp[j]+1 > dp[i] && groups[i] != groups[j] {
				dp[i] = dp[j] + 1
				prev[i] = j
			}
		}
		if dp[i] > dp[maxIndex] {
			maxIndex = i
		}
	}

	ans := []string{}
	for i := maxIndex; i >= 0; i = prev[i] {
		ans = append(ans, words[i])
	}
	reverse(ans)
	return ans
}

func check(s1, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	diff := 0
	for i := 0; i < len(s1); i++ {
		if s1[i] != s2[i] {
			diff++
            if diff > 1 {
                return false
            }
		}
	}
	return diff == 1
}

func reverse(arr []string) {
	for i, j := 0, len(arr) - 1; i < j; i, j = i + 1, j - 1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> getWordsInLongestSubsequence(
        String[] words,
        int[] groups
    ) {
        int n = groups.length;
        int[] dp = new int[n];
        int[] prev = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(prev, -1);
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (
                    check(words[i], words[j]) &&
                    dp[j] + 1 > dp[i] &&
                    groups[i] != groups[j]
                ) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i = maxIndex; i >= 0; i = prev[i]) {
            ans.add(words[i]);
        }
        Collections.reverse(ans);
        return ans;
    }

    private boolean check(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                if (++diff > 1) {
                    return false;
                }
            }
        }
        return diff == 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getWordsInLongestSubsequence = function (words, groups) {
    const n = groups.length;
    const dp = new Array(n).fill(1);
    const prev = new Array(n).fill(-1);
    let maxIndex = 0;

    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (
                check(words[i], words[j]) &&
                dp[j] + 1 > dp[i] &&
                groups[i] !== groups[j]
            ) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    const ans = [];
    for (let i = maxIndex; i >= 0; i = prev[i]) {
        ans.push(words[i]);
    }
    ans.reverse();
    return ans;
};

const check = (s1, s2) => {
    if (s1.length !== s2.length) {
        return false;
    }
    let diff = 0;
    for (let i = 0; i < s1.length; i++) {
        if (s1[i] !== s2[i]) {
            if (++diff > 1) {
                return false;
            }
        }
    }
    return diff === 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getWordsInLongestSubsequence(
        self, words: List[str], groups: List[int]
    ) -> List[str]:
        n = len(groups)
        dp = [1] * n
        prev_ = [-1] * n
        max_index = 0

        for i in range(1, n):
            for j in range(i):
                if (
                    self.check(words[i], words[j])
                    and dp[j] + 1 > dp[i]
                    and groups[i] != groups[j]
                ):
                    dp[i] = dp[j] + 1
                    prev_[i] = j
            if dp[i] > dp[max_index]:
                max_index = i

        ans = []
        i = max_index
        while i >= 0:
            ans.append(words[i])
            i = prev_[i]
        ans.reverse()
        return ans

    def check(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        diff = 0
        for c1, c2 in zip(s1, s2):
            if c1 != c2:
                diff += 1
                if diff > 1:
                    return False
        return diff == 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getWordsInLongestSubsequence(
    words: string[],
    groups: number[],
): string[] {
    const n = groups.length;
    const dp = new Array(n).fill(1);
    const prev = new Array(n).fill(-1);
    let maxIndex = 0;

    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (
                check(words[i], words[j]) &&
                dp[j] + 1 > dp[i] &&
                groups[i] !== groups[j]
            ) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    const ans = [];
    for (let i = maxIndex; i >= 0; i = prev[i]) {
        ans.push(words[i]);
    }
    ans.reverse();
    return ans;
}

function check(s1: string, s2: string): boolean {
    if (s1.length !== s2.length) {
        return false;
    }
    let diff = 0;
    for (let i = 0; i < s1.length; i++) {
        if (s1[i] !== s2[i]) {
            if (++diff > 1) {
                return false;
            }
        }
    }
    return diff === 1;
}
```

</details>
