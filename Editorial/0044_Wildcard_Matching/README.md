# 44. Wildcard Matching

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/wildcard-matching/)  
`String` `Dynamic Programming` `Greedy` `Recursion`

**Problem Link:** [LeetCode 44 - Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)

## Problem

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

- '?' Matches any single character.
- '*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

### Example 1

```text
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

### Example 2

```text
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
```

### Example 3

```text
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
```

## Constraints

- 0 <= s.length, p.length <= 2000
- s contains only lowercase English letters.
- p contains only lowercase English letters, '?' or '*'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Substring Matching Pattern](https://leetcode.com/problems/substring-matching-pattern/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 44. Wildcard Matching

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion with Memoization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion with Memoization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    char* id;  // we will use the key as a string, e.g., "5,7"
    bool val;
    UT_hash_handle hh;
} hash_entry;
hash_entry* dp = NULL;
char* remove_duplicate_stars(char* p) {
    char* new_string = malloc(strlen(p) + 1);
    int j = 0;
    for (int i = 0; i < strlen(p); i++) {
        if (j == 0 || p[i] != '*')
            new_string[j++] = p[i];
        else if (new_string[j - 1] != '*')
            new_string[j++] = p[i];
    }
    new_string[j] = '\0';
    return new_string;
}
bool helper(int si, int pi, char* s, char* p) {
    char key[20];
    sprintf(key, "%d,%d", si, pi);
    hash_entry* result;
    HASH_FIND_STR(dp, key, result);
    if (result) return result->val;
    hash_entry* entry = malloc(sizeof(hash_entry));
    entry->id = strdup(key);
    if (pi == strlen(p))
        entry->val = (si == strlen(s));
    else if (si == strlen(s))
        entry->val = (pi + 1 == strlen(p) && p[pi] == '*');
    else if (p[pi] == s[si] || p[pi] == '?')
        entry->val = helper(si + 1, pi + 1, s, p);
    else if (p[pi] == '*')
        entry->val = helper(si, pi + 1, s, p) || helper(si + 1, pi, s, p);
    else
        entry->val = false;
    HASH_ADD_STR(dp, id, entry);
    return entry->val;
}
bool isMatch(char* s, char* p) {
    // Clear the hashmap
    hash_entry* curr_entry;
    hash_entry* tmp_entry;
    HASH_ITER(hh, dp, curr_entry, tmp_entry) {
        HASH_DEL(dp, curr_entry);
        free(curr_entry->id);
        free(curr_entry);
    }
    p = remove_duplicate_stars(p);
    return helper(0, 0, s, p);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    unordered_map<string, bool> dp;
    string p;
    string s;
    string remove_duplicate_stars(string p) {
        string new_string = "";
        for (auto &c : p) {
            if (new_string.empty() || c != '*')
                new_string += c;
            else if (new_string.back() != '*')
                new_string += c;
        }
        return new_string;
    }
    bool helper(int si, int pi) {
        string key = to_string(si) + "," + to_string(pi);
        if (dp.count(key)) return dp[key];
        if (pi == p.size())
            dp[key] = (si == s.size());
        else if (si == s.size())
            dp[key] = (pi + 1 == p.size() && p[pi] == '*');
        else if (p[pi] == s[si] || p[pi] == '?')
            dp[key] = helper(si + 1, pi + 1);
        else if (p[pi] == '*')
            dp[key] = helper(si, pi + 1) || helper(si + 1, pi);
        else
            dp[key] = false;
        return dp[key];
    }
    bool isMatch(string s, string p) {
        dp.clear();
        this->s = s;
        this->p = remove_duplicate_stars(p);
        return helper(0, 0);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    Dictionary<string, bool> dp = new Dictionary<string, bool>();
    string s;
    string p;

    string remove_duplicate_stars(string p) {
        var new_string = new StringBuilder();
        foreach (var c in p) {
            if (new_string.Length == 0 || c != '*')
                new_string.Append(c);
            else if (new_string[new_string.Length - 1] != '*')
                new_string.Append(c);
        }

        return new_string.ToString();
    }

    bool helper(int si, int pi) {
        var key = si + "," + pi;
        if (dp.ContainsKey(key))
            return dp[key];
        if (pi == p.Length)
            dp[key] = si == s.Length;
        else if (si == s.Length)
            dp[key] = pi + 1 == p.Length && p[pi] == '*';
        else if (p[pi] == s[si] || p[pi] == '?')
            dp[key] = helper(si + 1, pi + 1);
        else if (p[pi] == '*')
            dp[key] = helper(si, pi + 1) || helper(si + 1, pi);
        else
            dp[key] = false;
        return dp[key];
    }

    public bool IsMatch(string s, string p) {
        dp.Clear();
        this.s = s;
        this.p = remove_duplicate_stars(p);
        return helper(0, 0);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isMatch(s string, p string) bool {
    dp := make(map[string]bool)
    remove_duplicate_stars := func(p string) string {
        new_string := ""
        for _, c := range p {
            if len(new_string) == 0 || c != '*' {
                new_string += string(c)
            } else if new_string[len(new_string)-1] != '*' {
                new_string += string(c)
            }
        }
        return new_string
    }
    var helper func(int, int) bool
    helper = func(si int, pi int) bool {
        key := fmt.Sprintf("%d,%d", si, pi)
        if _, ok := dp[key]; ok {
            return dp[key]
        }
        if pi == len(p) {
            dp[key] = si == len(s)
        } else if si == len(s) {
            dp[key] = pi+1 == len(p) && p[pi] == '*'
        } else if p[pi] == s[si] || p[pi] == '?' {
            dp[key] = helper(si+1, pi+1)
        } else if p[pi] == '*' {
            dp[key] = helper(si, pi+1) || helper(si+1, pi)
        } else {
            dp[key] = false
        }
        return dp[key]
    }
    p = remove_duplicate_stars(p)
    return helper(0, 0)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Map<String, Boolean> dp = new HashMap<>();
    String s;
    String p;

    String remove_duplicate_stars(String p) {
        StringBuilder new_string = new StringBuilder();
        for (char c : p.toCharArray()) {
            if (new_string.length() == 0 || c != '*') new_string.append(c);
            else if (
                new_string.charAt(new_string.length() - 1) != '*'
            ) new_string.append(c);
        }
        return new_string.toString();
    }

    boolean helper(int si, int pi) {
        String key = si + "," + pi;
        if (dp.containsKey(key)) return dp.get(key);
        if (pi == p.length()) dp.put(key, si == s.length());
        else if (si == s.length()) dp.put(
            key,
            (pi + 1 == p.length() && p.charAt(pi) == '*')
        );
        else if (p.charAt(pi) == s.charAt(si) || p.charAt(pi) == '?') dp.put(
            key,
            helper(si + 1, pi + 1)
        );
        else if (p.charAt(pi) == '*') dp.put(
            key,
            helper(si, pi + 1) || helper(si + 1, pi)
        );
        else dp.put(key, false);
        return dp.get(key);
    }

    public boolean isMatch(String s, String p) {
        dp.clear();
        this.s = s;
        this.p = remove_duplicate_stars(p);
        return helper(0, 0);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isMatch = function (s, p) {
    var dp = {};
    var remove_duplicate_stars = function (p) {
        var new_string = "";
        for (var c of p) {
            if (new_string.length == 0 || c != "*") new_string += c;
            else if (new_string[new_string.length - 1] != "*") new_string += c;
        }
        return new_string;
    };
    var helper = function (si, pi) {
        var key = si + "," + pi;
        if (key in dp) return dp[key];
        if (pi == p.length) dp[key] = si == s.length;
        else if (si == s.length) dp[key] = pi + 1 == p.length && p[pi] == "*";
        else if (p[pi] == s[si] || p[pi] == "?")
            dp[key] = helper(si + 1, pi + 1);
        else if (p[pi] == "*")
            dp[key] = helper(si, pi + 1) || helper(si + 1, pi);
        else dp[key] = false;
        return dp[key];
    };
    p = remove_duplicate_stars(p);
    return helper(0, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:

        def remove_duplicate_stars(p: str) -> str:
            new_string = []
            for char in p:
                if not new_string or char != "*":
                    new_string.append(char)
                elif new_string[-1] != "*":
                    new_string.append(char)
            return "".join(new_string)

        def helper(s: str, p: str) -> bool:
            if (s, p) in dp:
                return dp[(s, p)]

            if p == s or p == "*":
                dp[(s, p)] = True
            elif p == "" or s == "":
                dp[(s, p)] = False
            elif p[0] == s[0] or p[0] == "?":
                dp[(s, p)] = helper(s[1:], p[1:])
            elif p[0] == "*":
                dp[(s, p)] = helper(s, p[1:]) or helper(s[1:], p)
            else:
                dp[(s, p)] = False

            return dp[(s, p)]

        dp = {}
        p = remove_duplicate_stars(p)
        return helper(s, p)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isMatch(s: string, p: string): boolean {
    let dp: { [key: string]: boolean } = {};
    function remove_duplicate_stars(p: string): string {
        let new_string = "";
        for (let c of p) {
            if (new_string.length == 0 || c != "*") new_string += c;
            else if (new_string[new_string.length - 1] != "*") new_string += c;
        }
        return new_string;
    }
    function helper(si: number, pi: number): boolean {
        let key = si + "," + pi;
        if (key in dp) return dp[key];
        if (pi == p.length) dp[key] = si == s.length;
        else if (si == s.length) dp[key] = pi + 1 == p.length && p[pi] == "*";
        else if (p[pi] == s[si] || p[pi] == "?")
            dp[key] = helper(si + 1, pi + 1);
        else if (p[pi] == "*")
            dp[key] = helper(si, pi + 1) || helper(si + 1, pi);
        else dp[key] = false;
        return dp[key];
    }
    p = remove_duplicate_stars(p);
    return helper(0, 0);
}
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void init_bool_matrix(bool **matrix, int r, int c) {
    for (int i = 0; i < r; i++) {
        matrix[i] = (bool *)malloc(sizeof(bool) * c);
        for (int j = 0; j < c; j++) {
            matrix[i][j] = false;
        }
    }
    matrix[0][0] = true;
}
bool isMatch(char *s, char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    // base cases
    if (strcmp(p, s) == 0) {
        return true;
    }
    int star_count = 0;
    for (int i = 0; i < pLen; i++) {
        if (p[i] == '*') star_count++;
    }
    if (pLen > 0 && star_count == pLen) {
        return true;
    }
    if (pLen == 0 || sLen == 0) {
        return false;
    }
    // init all matrix except [0][0] element as False
    bool **d = (bool **)malloc(sizeof(bool *) * (pLen + 1));
    init_bool_matrix(d, pLen + 1, sLen + 1);
    // DP compute
    for (int pIdx = 1; pIdx < pLen + 1; pIdx++) {
        // the current character in the pattern is '*'
        if (p[pIdx - 1] == '*') {
            int sIdx = 1;
            // d[p_idx - 1][s_idx - 1] is a string-pattern match
            // on the previous step, i.e. one character before.
            // Find the first idx in string with the previous math.
            while ((!d[pIdx - 1][sIdx - 1]) && (sIdx < sLen + 1)) {
                sIdx++;
            }
            // If (string) matches (pattern),
            // when (string) matches (pattern)* as well
            d[pIdx][sIdx - 1] = d[pIdx - 1][sIdx - 1];
            // If (string) matches (pattern),
            // when (string)(whatever_characters) matches (pattern)* as well
            while (sIdx < sLen + 1) {
                d[pIdx][sIdx++] = true;
            }
            // the current character in the pattern is '?'
        } else if (p[pIdx - 1] == '?') {
            for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1];
            }
            // the current character in the pattern is not '*' or '?'
        } else {
            for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                // Match is possible if there is a previous match
                // and current characters are the same
                d[pIdx][sIdx] =
                    d[pIdx - 1][sIdx - 1] && (p[pIdx - 1] == s[sIdx - 1]);
            }
        }
    }
    return d[pLen][sLen];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        // base cases
        if (p == s) {
            return true;
        }
        if (pLen > 0 && count(p.begin(), p.end(), '*') == pLen) {
            return true;
        }
        if (p.empty() || s.empty()) {
            return false;
        }
        // init all matrix except [0][0] element as False
        vector<vector<bool>> d(pLen + 1, vector<bool>(sLen + 1, false));
        d[0][0] = true;
        // DP compute
        for (int pIdx = 1; pIdx < pLen + 1; pIdx++) {
            // the current character in the pattern is '*'
            if (p[pIdx - 1] == '*') {
                int sIdx = 1;
                // d[p_idx - 1][s_idx - 1] is a string-pattern match
                // on the previous step, i.e. one character before.
                // Find the first idx in string with the previous math.
                while ((!d[pIdx - 1][sIdx - 1]) && (sIdx < sLen + 1)) {
                    sIdx++;
                }
                // If (string) matches (pattern),
                // when (string) matches (pattern)* as well
                d[pIdx][sIdx - 1] = d[pIdx - 1][sIdx - 1];
                // If (string) matches (pattern),
                // when (string)(whatever_characters) matches (pattern)* as well
                while (sIdx < sLen + 1) {
                    d[pIdx][sIdx++] = true;
                }
                // the current character in the pattern is '?'
            } else if (p[pIdx - 1] == '?') {
                for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                    d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1];
                }
                // the current character in the pattern is not '*' or '?'
            } else {
                for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                    // Match is possible if there is a previous match
                    // and current characters are the same
                    d[pIdx][sIdx] =
                        d[pIdx - 1][sIdx - 1] && (p[pIdx - 1] == s[sIdx - 1]);
                }
            }
        }
        return d[pLen][sLen];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsMatch(string s, string p) {
        int sLen = s.Length, pLen = p.Length;
        // base cases
        if (p == s) {
            return true;
        }

        if (pLen > 0 && p.All(c => c == '*')) {
            return true;
        }

        if (p.Length == 0 || s.Length == 0) {
            return false;
        }

        // init all matrix except [0][0] element as False
        bool[,] d = new bool[pLen + 1, sLen + 1];
        d[0, 0] = true;
        // DP compute
        for (int pIdx = 1; pIdx < pLen + 1; pIdx++) {
            // the current character in the pattern is '*'
            if (p[pIdx - 1] == '*') {
                int sIdx = 1;
                // d[p_idx - 1][s_idx - 1] is a string-pattern match
                // on the previous step, i.e. one character before.
                // Find the first idx in string with the previous math.
                while ((!d[pIdx - 1, sIdx - 1]) && (sIdx < sLen + 1)) {
                    sIdx++;
                }

                // If (string) matches (pattern),
                // when (string) matches (pattern)* as well
                d[pIdx, sIdx - 1] = d[pIdx - 1, sIdx - 1];
                // If (string) matches (pattern),
                // when (string)(whatever_characters) matches (pattern)* as well
                while (sIdx < sLen + 1) {
                    d[pIdx, sIdx++] = true;
                }
                // the current character in the pattern is '?'
            } else if (p[pIdx - 1] == '?') {
                for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                    d[pIdx, sIdx] = d[pIdx - 1, sIdx - 1];
                }
                // the current character in the pattern is not '*' or '?'
            } else {
                for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                    // Match is possible if there is a previous match
                    // and current characters are the same
                    d[pIdx, sIdx] =
                        d[pIdx - 1, sIdx - 1] && (p[pIdx - 1] == s[sIdx - 1]);
                }
            }
        }

        return d[pLen, sLen];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isMatch(s string, p string) bool {
    sLen := len(s)
    pLen := len(p)
    // base cases
    if p == s {
        return true
    }
    if pLen > 0 && strings.Count(p, "*") == pLen {
        return true
    }
    if len(p) == 0 || len(s) == 0 {
        return false
    }
    // init all matrix except [0][0] element as False
    d := make([][]bool, pLen+1)
    for i := range d {
        d[i] = make([]bool, sLen+1)
    }
    d[0][0] = true
    // DP compute
    for pIdx := 1; pIdx < pLen+1; pIdx++ {
        // the current character in the pattern is '*'
        if p[pIdx-1:pIdx] == "*" {
            sIdx := 1
            // d[p_idx - 1][s_idx - 1] is a string-pattern match
            // on the previous step, i.e. one character before.
            // Find the first idx in string with the previous math.
            for !d[pIdx-1][sIdx-1] && sIdx < sLen+1 {
                sIdx++
            }
            // If (string) matches (pattern),
            // when (string) matches (pattern)* as well
            d[pIdx][sIdx-1] = d[pIdx-1][sIdx-1]
            // If (string) matches (pattern),
            // when (string)(whatever_characters) matches (pattern)* as well
            for sIdx < sLen+1 {
                d[pIdx][sIdx] = true
                sIdx++
            }
            // the current character in the pattern is '?'
        } else if p[pIdx-1:pIdx] == "?" {
            for sIdx := 1; sIdx < sLen+1; sIdx++ {
                d[pIdx][sIdx] = d[pIdx-1][sIdx-1]
            }
            // the current character in the pattern is not '*' or '?'
        } else {
            for sIdx := 1; sIdx < sLen+1; sIdx++ {
                // Match is possible if there is a previous match
                // and current characters are the same
                d[pIdx][sIdx] = d[pIdx-1][sIdx-1] && p[pIdx-1:pIdx] == s[sIdx-1:sIdx]
            }
        }
    }
    return d[pLen][sLen]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isMatch(String s, String p) {
        int sLen = s.length(), pLen = p.length();

        // base cases
        if (p.equals(s)) {
            return true;
        }

        if (pLen > 0 && p.chars().allMatch(c -> c == '*')) {
            return true;
        }

        if (p.isEmpty() || s.isEmpty()) {
            return false;
        }

        // init all matrix except [0][0] element as False
        boolean[][] d = new boolean[pLen + 1][sLen + 1];
        d[0][0] = true;

        // DP compute
        for (int pIdx = 1; pIdx < pLen + 1; pIdx++) {
            // the current character in the pattern is '*'
            if (p.charAt(pIdx - 1) == '*') {
                int sIdx = 1;

                // d[p_idx - 1][s_idx - 1] is a string-pattern match
                // on the previous step, i.e. one character before.
                // Find the first idx in string with the previous math.
                while ((!d[pIdx - 1][sIdx - 1]) && (sIdx < sLen + 1)) {
                    sIdx++;
                }

                // If (string) matches (pattern),
                // when (string) matches (pattern)* as well
                d[pIdx][sIdx - 1] = d[pIdx - 1][sIdx - 1];

                // If (string) matches (pattern),
                // when (string)(whatever_characters) matches (pattern)* as well
                while (sIdx < sLen + 1) {
                    d[pIdx][sIdx++] = true;
                }
                // the current character in the pattern is '?'
            } else if (p.charAt(pIdx - 1) == '?') {
                for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                    d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1];
                }
                // the current character in the pattern is not '*' or '?'
            } else {
                for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                    // Match is possible if there is a previous match
                    // and current characters are the same
                    d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1] &&
                    (p.charAt(pIdx - 1) == s.charAt(sIdx - 1));
                }
            }
        }

        return d[pLen][sLen];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isMatch = function (s, p) {
    let sLen = s.length,
        pLen = p.length;
    // base cases
    if (p == s) {
        return true;
    }
    if (
        pLen > 0 &&
        !Array.from(p)
            .map((c) => c != "*")
            .includes(true)
    ) {
        return true;
    }
    if (p.length === 0 || s.length === 0) {
        return false;
    }
    // init all matrix except [0][0] element as False
    let d = Array(pLen + 1)
        .fill(false)
        .map(() => Array(sLen + 1).fill(false));
    d[0][0] = true;
    // DP compute
    for (let pIdx = 1; pIdx < pLen + 1; pIdx++) {
        // the current character in the pattern is '*'
        if (p[pIdx - 1] === "*") {
            let sIdx = 1;
            // d[p_idx - 1][s_idx - 1] is a string-pattern match
            // on the previous step, i.e. one character before.
            // Find the first idx in string with the previous math.
            while (!d[pIdx - 1][sIdx - 1] && sIdx < sLen + 1) {
                sIdx++;
            }
            // If (string) matches (pattern),
            // when (string) matches (pattern)* as well
            d[pIdx][sIdx - 1] = d[pIdx - 1][sIdx - 1];
            // If (string) matches (pattern),
            // when (string)(whatever_characters) matches (pattern)* as well
            while (sIdx < sLen + 1) {
                d[pIdx][sIdx++] = true;
            }
            // the current character in the pattern is '?'
        } else if (p[pIdx - 1] === "?") {
            for (let sIdx = 1; sIdx < sLen + 1; sIdx++) {
                d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1];
            }
            // the current character in the pattern is not '*' or '?'
        } else {
            for (let sIdx = 1; sIdx < sLen + 1; sIdx++) {
                // Match is possible if there is a previous match and
                // current characters are the same
                d[pIdx][sIdx] =
                    d[pIdx - 1][sIdx - 1] && p[pIdx - 1] === s[sIdx - 1];
            }
        }
    }
    return d[pLen][sLen];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s_len = len(s)
        p_len = len(p)

        # The base cases
        if p == s or set(p) == {"*"}:
            return True
        if p == "" or s == "":
            return False

        # Initialize all matrix except [0][0] element as False
        d = [[False] * (s_len + 1) for _ in range(p_len + 1)]
        d[0][0] = True

        # DP compute
        for p_idx in range(1, p_len + 1):
            # The current character in the pattern is '*'
            if p[p_idx - 1] == "*":
                s_idx = 1

                # d[p_idx - 1][s_idx - 1] is a string-pattern match
                # on the previous step, i.e. one character before.
                # Find the first idx in the string with the previous math.
                while not d[p_idx - 1][s_idx - 1] and s_idx < s_len + 1:
                    s_idx += 1

                # If (string) matches (pattern),
                # when (string) matches (pattern)* as well
                d[p_idx][s_idx - 1] = d[p_idx - 1][s_idx - 1]

                # If (string) matches (pattern),
                # when (string)(whatever_characters) matches (pattern)* as well
                while s_idx < s_len + 1:
                    d[p_idx][s_idx] = True
                    s_idx += 1

            # The current character in the pattern is '?'
            elif p[p_idx - 1] == "?":
                for s_idx in range(1, s_len + 1):
                    d[p_idx][s_idx] = d[p_idx - 1][s_idx - 1]

            # The current character in the pattern is not '*' or '?'
            else:
                for s_idx in range(1, s_len + 1):
                    # Match is possible if there is a previous match
                    # and current characters are the same
                    d[p_idx][s_idx] = (
                        d[p_idx - 1][s_idx - 1] and p[p_idx - 1] == s[s_idx - 1]
                    )

        return d[p_len][s_len]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isMatch(s: string, p: string): boolean {
    let sLen = s.length,
        pLen = p.length;
    // base cases
    if (p == s) {
        return true;
    }
    if (
        pLen > 0 &&
        !Array.from(p)
            .map((c) => c != "*")
            .includes(true)
    ) {
        return true;
    }
    if (p.length === 0 || s.length === 0) {
        return false;
    }
    // init all matrix except [0][0] element as False
    let d: boolean[][] = Array(pLen + 1)
        .fill(false)
        .map(() => Array(sLen + 1).fill(false));
    d[0][0] = true;
    // DP compute
    for (let pIdx = 1; pIdx < pLen + 1; pIdx++) {
        // the current character in the pattern is '*'
        if (p[pIdx - 1] === "*") {
            let sIdx = 1;
            // d[p_idx - 1][s_idx - 1] is a string-pattern match
            // on the previous step, i.e. one character before.
            // Find the first idx in string with the previous math.
            while (!d[pIdx - 1][sIdx - 1] && sIdx < sLen + 1) {
                sIdx++;
            }
            // If (string) matches (pattern),
            // when (string) matches (pattern)* as well
            d[pIdx][sIdx - 1] = d[pIdx - 1][sIdx - 1];
            // If (string) matches (pattern),
            // when (string)(whatever_characters) matches (pattern)* as well
            while (sIdx < sLen + 1) {
                d[pIdx][sIdx] = true;
                sIdx++;
            }
            // the current character in the pattern is '?'
        } else if (p[pIdx - 1] === "?") {
            for (let sIdx = 1; sIdx < sLen + 1; sIdx++) {
                d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1];
            }
            // the current character in the pattern is not '*' or '?'
        } else {
            for (let sIdx = 1; sIdx < sLen + 1; sIdx++) {
                // Match is possible if there is a previous match
                // and current characters are the same
                d[pIdx][sIdx] =
                    d[pIdx - 1][sIdx - 1] && p[pIdx - 1] === s[sIdx - 1];
            }
        }
    }
    return d[pLen][sLen];
}
```

</details>

<br>

## Approach 3: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isMatch(char* s, char* p) {
    int sLen = strlen(s), pLen = strlen(p);
    int sIdx = 0, pIdx = 0;
    int starIdx = -1, sTmpIdx = -1;
    while (sIdx < sLen) {
        // If the pattern character = string character
        // or pattern character = '?'
        if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
            ++sIdx;
            ++pIdx;
        }
        // If pattern character = '*'
        else if (pIdx < pLen && p[pIdx] == '*') {
            // Check the situation
            // when '*' matches no characters
            starIdx = pIdx;
            sTmpIdx = sIdx;
            ++pIdx;
        }
        // If pattern character != string character
        // or pattern is used up
        // and there was no '*' character in pattern
        else if (starIdx == -1) {
            return false;
        }
        // If pattern character != string character
        // or pattern is used up
        // and there was '*' character in pattern before
        else {
            // Backtrack: check the situation
            // when '*' matches one more character
            pIdx = starIdx + 1;
            sIdx = sTmpIdx + 1;
            sTmpIdx = sIdx;
        }
    }
    // The remaining characters in the pattern should all be '*' characters
    for (int i = pIdx; i < pLen; i++) {
        if (p[i] != '*') {
            return false;
        }
    }
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, sTmpIdx = -1;
        while (sIdx < sLen) {
            // If the pattern character = string character
            // or pattern character = '?'
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                ++sIdx;
                ++pIdx;
                // If pattern character = '*'
            } else if (pIdx < pLen && p[pIdx] == '*') {
                // Check the situation
                // when '*' matches no characters
                starIdx = pIdx;
                sTmpIdx = sIdx;
                ++pIdx;
                // If pattern character != string character
                // or pattern is used up
                // and there was no '*' character in pattern
            } else if (starIdx == -1) {
                return false;
                // If pattern character != string character
                // or pattern is used up
                // and there was '*' character in pattern before
            } else {
                // Backtrack: check the situation
                // when '*' matches one more character
                pIdx = starIdx + 1;
                sIdx = sTmpIdx + 1;
                sTmpIdx = sIdx;
            }
        }
        // The remaining characters in the pattern should all be '*' characters
        for (int i = pIdx; i < pLen; i++) {
            if (p[i] != '*') {
                return false;
            }
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
    public bool IsMatch(string s, string p) {
        int sLen = s.Length, pLen = p.Length;
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, sTmpIdx = -1;
        while (sIdx < sLen) {
            // If the pattern character = string character
            // or pattern character = '?'
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                ++sIdx;
                ++pIdx;
            }
            // If pattern character = '*'
            else if (pIdx < pLen && p[pIdx] == '*') {
                // Check the situation
                // when '*' matches no characters
                starIdx = pIdx;
                sTmpIdx = sIdx;
                ++pIdx;
            }
            // If pattern character != string character
            // or pattern is used up
            // and there was no '*' character in pattern
            else if (starIdx == -1) {
                return false;
            }
            // If pattern character != string character
            // or pattern is used up
            // and there was '*' character in pattern before
            else {
                // Backtrack: check the situation
                // when '*' matches one more character
                pIdx = starIdx + 1;
                sIdx = sTmpIdx + 1;
                sTmpIdx = sIdx;
            }
        }

        // The remaining characters in the pattern should all be '*' characters
        for (int i = pIdx; i < pLen; i++) {
            if (p[i] != '*') {
                return false;
            }
        }

        return true;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isMatch(s string, p string) bool {
    sLen, pLen := len(s), len(p)
    sIdx, pIdx, starIdx, sTmpIdx := 0, 0, -1, -1
    for sIdx < sLen {
        if pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx]) {
            sIdx++
            pIdx++
        } else if pIdx < pLen && p[pIdx] == '*' {
            starIdx = pIdx
            sTmpIdx = sIdx
            pIdx++
        } else if starIdx == -1 {
            return false
        } else {
            pIdx = starIdx + 1
            sIdx = sTmpIdx + 1
            sTmpIdx = sIdx
        }
    }
    for i := pIdx; i < pLen; i++ {
        if p[i] != '*' {
            return false
        }
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isMatch(String s, String p) {
        int sLen = s.length(), pLen = p.length();
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, sTmpIdx = -1;

        while (sIdx < sLen) {
            // If the pattern character = string character
            // or pattern character = '?'
            if (
                pIdx < pLen &&
                (p.charAt(pIdx) == '?' || p.charAt(pIdx) == s.charAt(sIdx))
            ) {
                ++sIdx;
                ++pIdx;
                // If pattern character = '*'
            } else if (pIdx < pLen && p.charAt(pIdx) == '*') {
                // Check the situation
                // when '*' matches no characters
                starIdx = pIdx;
                sTmpIdx = sIdx;
                ++pIdx;
                // If pattern character != string character
                // or pattern is used up
                // and there was no '*' character in pattern
            } else if (starIdx == -1) {
                return false;
                // If pattern character != string character
                // or pattern is used up
                // and there was '*' character in pattern before
            } else {
                // Backtrack: check the situation
                // when '*' matches one more character
                pIdx = starIdx + 1;
                sIdx = sTmpIdx + 1;
                sTmpIdx = sIdx;
            }
        }

        // The remaining characters in the pattern should all be '*' characters
        for (int i = pIdx; i < pLen; i++) {
            if (p.charAt(i) != '*') {
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
var isMatch = function (s, p) {
    let sLen = s.length,
        pLen = p.length;
    let sIdx = 0,
        pIdx = 0;
    let starIdx = -1,
        sTmpIdx = -1;
    while (sIdx < sLen) {
        // If the pattern character = string character
        // or pattern character = '?'
        if (pIdx < pLen && (p[pIdx] === "?" || p[pIdx] === s[sIdx])) {
            ++sIdx;
            ++pIdx;
        }
        // If pattern character = '*'
        else if (pIdx < pLen && p[pIdx] === "*") {
            // Check the situation
            // when '*' matches no characters
            starIdx = pIdx;
            sTmpIdx = sIdx;
            ++pIdx;
        }
        // If pattern character != string character
        // or pattern is used up
        // and there was no '*' character in pattern
        else if (starIdx === -1) {
            return false;
        }
        // If pattern character != string character
        // or pattern is used up
        // and there was '*' character in pattern before
        else {
            // Backtrack: check the situation
            // when '*' matches one more character
            pIdx = starIdx + 1;
            sIdx = sTmpIdx + 1;
            sTmpIdx = sIdx;
        }
    }
    // The remaining characters in the pattern should all be '*' characters
    for (let i = pIdx; i < pLen; i++) {
        if (p[i] !== "*") {
            return false;
        }
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s_len, p_len = len(s), len(p)
        s_idx = p_idx = 0
        star_idx = s_tmp_idx = -1

        while s_idx < s_len:
            # If the pattern caracter = string character
            # or pattern character = '?'
            if p_idx < p_len and p[p_idx] in ["?", s[s_idx]]:
                s_idx += 1
                p_idx += 1

            # If pattern character = '*'
            elif p_idx < p_len and p[p_idx] == "*":
                # Check the situation
                # when '*' matches no characters
                star_idx = p_idx
                s_tmp_idx = s_idx
                p_idx += 1

            # If pattern character != string character
            # or pattern is used up
            # and there was no '*' character in pattern
            elif star_idx == -1:
                return False

            # If pattern character != string character
            # or pattern is used up
            # and there was '*' character in pattern before
            else:
                # Backtrack: check the situation
                # when '*' matches one more character
                p_idx = star_idx + 1
                s_idx = s_tmp_idx + 1
                s_tmp_idx = s_idx

        # The remaining characters in the pattern should all be '*' characters
        return all(p[i] == "*" for i in range(p_idx, p_len))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isMatch(s: string, p: string): boolean {
    let sLen = s.length,
        pLen = p.length;
    let sIdx = 0,
        pIdx = 0;
    let starIdx = -1,
        sTmpIdx = -1;
    while (sIdx < sLen) {
        // If the pattern character = string character
        // or pattern character = '?'
        if (pIdx < pLen && (p[pIdx] === "?" || p[pIdx] === s[sIdx])) {
            ++sIdx;
            ++pIdx;
        }
        // If pattern character = '*'
        else if (pIdx < pLen && p[pIdx] === "*") {
            // Check the situation
            // when '*' matches no characters
            starIdx = pIdx;
            sTmpIdx = sIdx;
            ++pIdx;
        }
        // If pattern character != string character
        // or pattern is used up
        // and there was no '*' character in pattern
        else if (starIdx === -1) {
            return false;
        }
        // If pattern character != string character
        // or pattern is used up
        // and there was '*' character in pattern before
        else {
            // Backtrack: check the situation
            // when '*' matches one more character
            pIdx = starIdx + 1;
            sIdx = sTmpIdx + 1;
            sTmpIdx = sIdx;
        }
    }
    // The remaining characters in the pattern should all be '*' characters
    for (let i = pIdx; i < pLen; i++) {
        if (p[i] !== "*") {
            return false;
        }
    }
    return true;
}
```

</details>
