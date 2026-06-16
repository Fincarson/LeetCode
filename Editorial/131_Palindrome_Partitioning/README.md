# 131. Palindrome Partitioning

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/palindrome-partitioning/)  
`String` `Dynamic Programming` `Backtracking`

**Problem Link:** [LeetCode 131 - Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)

## Problem

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

### Example 1

```text
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

### Example 2

```text
Input: s = "a"
Output: [["a"]]
```

## Constraints

- 1 <= s.length <= 16
- s contains only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Palindrome Partitioning IV](https://leetcode.com/problems/palindrome-partitioning-iv/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Number of Non-overlapping Palindrome Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 131. Palindrome Partitioning

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Backtracking with Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    char* str;
    int len;
} Token;

bool is_palindrome(char* start, int len) {
    for (int i = 0; i < len / 2; i++)
        if (start[i] != start[len - i - 1]) return false;
    return true;
}

void dfs(char* s, Token* path, int pathLen, char**** result, int* returnSize,
         int** columnSizes, int* capacity) {
    int len = strlen(s);
    if (len == 0) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *result = realloc(*result, sizeof(char**) * (*capacity));
            *columnSizes = realloc(*columnSizes, sizeof(int) * (*capacity));
        }
        (*columnSizes)[*returnSize] = pathLen;
        (*result)[*returnSize] = malloc(sizeof(char*) * pathLen);
        for (int i = 0; i < pathLen; i++) {
            (*result)[*returnSize][i] =
                malloc(sizeof(char) * (path[i].len + 1));
            strncpy((*result)[*returnSize][i], path[i].str, path[i].len);
            (*result)[*returnSize][i][path[i].len] = '\0';
        }
        (*returnSize)++;
    } else {
        for (int i = 1; i <= len; i++) {
            if (is_palindrome(s, i)) {
                Token* newPath = malloc(sizeof(Token) * (pathLen + 1));
                if (pathLen > 0) memcpy(newPath, path, sizeof(Token) * pathLen);
                newPath[pathLen].str = s;
                newPath[pathLen].len = i;
                dfs(s + i, newPath, pathLen + 1, result, returnSize,
                    columnSizes, capacity);
                free(newPath);
            }
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int capacity = 100;  // Initial capacity; increase if necessary
    char*** result = malloc(sizeof(char**) * capacity);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * capacity);
    dfs(s, NULL, 0, &result, returnSize, returnColumnSizes, &capacity);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start,
             vector<string> &currentList) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                // add current substring in the currentList
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList);
                // backtrack and remove the current substring from currentList
                currentList.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<string>> Partition(string s) {
        var ans = new List<IList<string>>();
        Dfs(0, new List<string>(), s, ans);
        return ans;
    }

    private void Dfs(int start, List<string> currentList, string s,
                     List<IList<string>> result) {
        if (start >= s.Length)
            result.Add(new List<string>(currentList));
        else {
            for (int end = start; end < s.Length; end++) {
                if (IsPalindrome(s, start, end)) {
                    currentList.Add(s.Substring(start, end - start + 1));
                    Dfs(end + 1, currentList, s, result);
                    currentList.RemoveAt(currentList.Count - 1);
                }
            }
        }
    }

    bool IsPalindrome(string s, int low, int high) {
        while (low < high)
            if (s[low++] != s[high--])
                return false;
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func partition(s string) [][]string {
    res := [][]string{}
    dfs(s, []string{}, &res)
    return res
}

func dfs(s string, path []string, res *[][]string) {
    if len(s) == 0 {
        *res = append(*res, append([]string(nil), path...))
        return
    }
    for i := 1; i <= len(s); i++ {
        if isPalindrome(s[:i]) {
            dfs(s[i:], append(path, s[:i]), res)
        }
    }
}

func isPalindrome(s string) bool {
    lo, hi := 0, len(s)-1
    for lo < hi {
        if s[lo] != s[hi] {
            return false
        }
        lo++
        hi--
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<List<String>>();
        dfs(0, result, new ArrayList<String>(), s);
        return result;
    }

    void dfs(
        int start,
        List<List<String>> result,
        List<String> currentList,
        String s
    ) {
        if (start >= s.length()) result.add(new ArrayList<String>(currentList));
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                // add current substring in the currentList
                currentList.add(s.substring(start, end + 1));
                dfs(end + 1, result, currentList, s);
                // backtrack and remove the current substring from currentList
                currentList.remove(currentList.size() - 1);
            }
        }
    }

    boolean isPalindrome(String s, int low, int high) {
        while (low < high) {
            if (s.charAt(low++) != s.charAt(high--)) return false;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var partition = function (s) {
    const res = [];
    dfs(s, [], res);
    return res;
    function dfs(s, path, res) {
        if (!s.length) {
            res.push(path);
            return;
        }
        for (let i = 0; i < s.length; i++) {
            const cur = s.substr(0, i + 1);
            if (isPalindrome(cur)) {
                // add current substring in the currentList
                dfs(s.substr(i + 1), path.concat(cur), res);
                // backtrack and remove the current substring from currentList
            }
        }
    }
    function isPalindrome(s) {
        let lo = 0,
            hi = s.length - 1;
        while (lo < hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        result = []
        self.dfs(s, [], result)
        return result

    def isPalindrome(self, s: str) -> bool:
        return s == s[::-1]

    def dfs(self, s: str, path: List[str], result: List[List[str]]):
        if not s:
            result.append(path)
            return
        for i in range(1, len(s) + 1):
            if self.isPalindrome(s[:i]):
                # add current substring in the currentList
                self.dfs(s[i:], path + [s[:i]], result)
                # backtrack and remove the current substring from currentList
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function partition(s: string): string[][] {
    const res: string[][] = [];
    dfs(s, [], res);
    return res;
    function dfs(s: string, path: string[], res: string[][]) {
        if (!s.length) {
            res.push(path);
            return;
        }
        for (let i = 0; i < s.length; i++) {
            const cur = s.substr(0, i + 1);
            if (isPalindrome(cur)) {
                dfs(s.substr(i + 1), [...path, cur], res);
            }
        }
    }
    function isPalindrome(s: string) {
        let lo = 0,
            hi = s.length - 1;
        while (lo < hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
}
```

</details>

<br>

## Approach 2: Backtracking with Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX 1000
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int len = strlen(s);
    bool dp[MAX][MAX] = {false};
    char*** result = (char***)calloc(MAX * MAX, sizeof(char**));
    char** currentList = (char**)calloc(MAX, sizeof(char*));
    *returnSize = 0;
    *returnColumnSizes = (int*)calloc(MAX * MAX, sizeof(int));
    dfs(s, 0, &result, returnSize, returnColumnSizes, &currentList, 0, dp);
    free(currentList);
    return result;
}
void dfs(char* s, int start, char**** result, int* returnSize,
         int** returnColumnSizes, char*** currentList, int currentListSize,
         bool dp[][MAX]) {
    int len = strlen(s);
    if (start >= len) {
        (*result)[*returnSize] =
            (char**)malloc(currentListSize * sizeof(char*));
        memcpy((*result)[*returnSize], *currentList,
               currentListSize * sizeof(char*));
        (*returnColumnSizes)[*returnSize] = currentListSize;
        (*returnSize)++;
    }
    for (int end = start; end < len; end++) {
        if (s[start] == s[end] &&
            (end - start <= 2 || dp[start + 1][end - 1])) {
            dp[start][end] = true;
            char* substr = (char*)calloc((end - start + 2), sizeof(char));
            strncpy(substr, &s[start], end - start + 1);
            (*currentList)[currentListSize] = substr;
            dfs(s, end + 1, result, returnSize, returnColumnSizes, currentList,
                currentListSize + 1, dp);
            (*currentList)[currentListSize] = NULL;
        }
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start,
             vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] &&
                (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<string>> Partition(string s) {
        int len = s.Length;
        bool[,] dp = new bool[len, len];
        IList<IList<string>> result = new List<IList<string>>();
        dfs(result, s, 0, new List<string>(), dp);
        return result;
    }

    void dfs(IList<IList<string>> result, string s, int start,
             IList<string> currentList, bool[,] dp) {
        if (start >= s.Length)
            result.Add(new List<string>(currentList));
        for (int end = start; end < s.Length; end++) {
            if (s[start] == s[end] &&
                (end - start <= 2 || dp[start + 1, end - 1])) {
                dp[start, end] = true;
                currentList.Add(s.Substring(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.RemoveAt(currentList.Count - 1);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func partition(s string) [][]string {
    len_s := len(s)
    dp := make([][]bool, len_s)
    for i := range dp {
        dp[i] = make([]bool, len_s)
    }
    result := make([][]string, 0)
    dfs(&result, s, 0, make([]string, 0), dp)
    return result
}

func dfs(
    result *[][]string,
    s string,
    start int,
    currentList []string,
    dp [][]bool,
) {
    if start >= len(s) {
        newList := make([]string, len(currentList))
        copy(newList, currentList)
        *result = append(*result, newList)
    } else {
        for end := start; end < len(s); end++ {
            if s[start] == s[end] && (end-start <= 2 || dp[start+1][end-1]) {
                dp[start][end] = true
                currentList = append(currentList, s[start:end+1])
                dfs(result, s, end+1, currentList, dp)
                currentList = currentList[:len(currentList)-1]
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<String>> partition(String s) {
        int len = s.length();
        boolean[][] dp = new boolean[len][len];
        List<List<String>> result = new ArrayList<>();
        dfs(result, s, 0, new ArrayList<>(), dp);
        return result;
    }

    void dfs(
        List<List<String>> result,
        String s,
        int start,
        List<String> currentList,
        boolean[][] dp
    ) {
        if (start >= s.length()) result.add(new ArrayList<>(currentList));
        for (int end = start; end < s.length(); end++) {
            if (
                s.charAt(start) == s.charAt(end) &&
                (end - start <= 2 || dp[start + 1][end - 1])
            ) {
                dp[start][end] = true;
                currentList.add(s.substring(start, end + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.remove(currentList.size() - 1);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var partition = function (s) {
    let len = s.length;
    let dp = Array(len)
        .fill()
        .map(() => Array(len).fill(false));
    let result = [];
    dfs(result, s, 0, [], dp);
    return result;
};
function dfs(result, s, start, currentList, dp) {
    if (start >= s.length) result.push([...currentList]);
    for (let end = start; end < s.length; end++) {
        if (
            s[start] === s[end] &&
            (end - start <= 2 || dp[start + 1][end - 1])
        ) {
            dp[start][end] = true;
            currentList.push(s.slice(start, end + 1));
            dfs(result, s, end + 1, currentList, dp);
            currentList.pop();
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        len_s = len(s)
        dp = [[False] * len_s for _ in range(len_s)]
        result = []
        self.dfs(result, s, 0, [], dp)
        return result

    def dfs(
        self,
        result: List[List[str]],
        s: str,
        start: int,
        currentList: List[str],
        dp: List[List[bool]],
    ):
        if start >= len(s):
            result.append(list(currentList))
        for end in range(start, len(s)):
            if s[start] == s[end] and (
                end - start <= 2 or dp[start + 1][end - 1]
            ):
                dp[start][end] = True
                currentList.append(s[start : end + 1])
                self.dfs(result, s, end + 1, currentList, dp)
                currentList.pop()
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function partition(s: string): string[][] {
    let len = s.length;
    let dp: boolean[][] = Array.from({ length: len }, () =>
        Array(len).fill(false),
    );
    let result: string[][] = [];
    dfs(result, s, 0, [], dp);
    return result;
}
function dfs(
    result: string[][],
    s: string,
    start: number,
    currentList: string[],
    dp: boolean[][],
) {
    if (start >= s.length) result.push([...currentList]);
    for (let end = start; end < s.length; end++) {
        if (
            s.charAt(start) === s.charAt(end) &&
            (end - start <= 2 || dp[start + 1][end - 1])
        ) {
            dp[start][end] = true;
            currentList.push(s.slice(start, end + 1));
            dfs(result, s, end + 1, currentList, dp);
            currentList.pop();
        }
    }
}
```

</details>
