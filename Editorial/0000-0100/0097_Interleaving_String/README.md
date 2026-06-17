# 97. Interleaving String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/interleaving-string/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 97 - Interleaving String](https://leetcode.com/problems/interleaving-string/)

## Problem

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

- s = s1 + s2 + ... + sn
- t = t1 + t2 + ... + tm
- |n - m| <= 1
- The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...

Note: a + b is the concatenation of strings a and b.

### Example 1

```text
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
```

### Example 2

```text
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
```

### Example 3

```text
Input: s1 = "", s2 = "", s3 = ""
Output: true
```

## Constraints

- 0 <= s1.length, s2.length <= 100
- 0 <= s3.length <= 200
- s1, s2, and s3 consist of lowercase English letters.

Follow up: Could you solve it using only O(s2.length) additional memory space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 97. Interleaving String

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Recursion with memoization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using 2D Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using 1D Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isInterleaveHelper(char* s1, int i, char* s2, int j, char* res, char* s3) {
    if (strcmp(res, s3) == 0 && i == strlen(s1) && j == strlen(s2)) return true;
    bool ans = false;
    if (i < strlen(s1)) {
        char* s1_res = (char*)calloc(strlen(res) + 2, sizeof(char));
        strcpy(s1_res, res);
        char temp[2] = {s1[i], '\0'};
        strcat(s1_res, temp);
        ans |= isInterleaveHelper(s1, i + 1, s2, j, s1_res, s3);
        free(s1_res);
    }
    if (j < strlen(s2)) {
        char* s2_res = (char*)calloc(strlen(res) + 2, sizeof(char));
        strcpy(s2_res, res);
        char temp[2] = {s2[j], '\0'};
        strcat(s2_res, temp);
        ans |= isInterleaveHelper(s1, i, s2, j + 1, s2_res, s3);
        free(s2_res);
    }
    return ans;
}
bool isInterleave(char* s1, char* s2, char* s3) {
    if (strlen(s1) + strlen(s2) != strlen(s3)) return false;
    return isInterleaveHelper(s1, 0, s2, 0, "", s3);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool is_Interleave(string s1, int i, string s2, int j, string res,
                       string s3) {
        // If result matches with third string and we have reached the end of
        // the all strings, return true.
        if (res == s3 && i == s1.length() && j == s2.length()) return true;
        bool ans = false;
        // Recurse for s1 & s2 if "ans" is false
        if (i < s1.length())
            ans |= is_Interleave(s1, i + 1, s2, j, res + s1[i], s3);
        if (j < s2.length())
            ans |= is_Interleave(s1, i, s2, j + 1, res + s2[j], s3);
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // Check if sum of sizes of two strings is equal to the size of third
        // string.
        if (s1.length() + s2.length() != s3.length()) return false;
        return is_Interleave(s1, 0, s2, 0, "", s3);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private bool IsInterleave(string s1, string s2, string s3, int i = 0,
                              int j = 0, string res = "") {
        // If result matches with third string and we have reached the end of
        // the all strings, return true.
        if (res == s3 && i == s1.Length && j == s2.Length)
            return true;
        bool ans = false;
        // Recurse for s1 & s2 if "ans" is false
        if (i < s1.Length)
            ans |= IsInterleave(s1, s2, s3, i + 1, j, res + s1[i]);
        if (j < s2.Length)
            ans |= IsInterleave(s1, s2, s3, i, j + 1, res + s2[j]);
        return ans;
    }

    public bool IsInterleave(string s1, string s2, string s3) {
        // Check if sum of sizes of two strings is equal to the size of third
        // string.
        if (s1.Length + s2.Length != s3.Length)
            return false;
        return IsInterleave(s1, s2, s3, 0, 0, "");
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func is_Interleave(
    s1 string,
    i int,
    s2 string,
    j int,
    res string,
    s3 string,
) bool {
    // If result matches with third string and we have reached the end of the all strings, return true.
    if res == s3 && i == len(s1) && j == len(s2) {
        return true
    }
    ans := false
    // Recurse for s1 & s2 if "ans" is false
    if i < len(s1) {
        ans = is_Interleave(s1, i+1, s2, j, res+string(s1[i]), s3)
    }
    if !ans && j < len(s2) {
        ans = is_Interleave(s1, i, s2, j+1, res+string(s2[j]), s3)
    }
    return ans
}

func isInterleave(s1 string, s2 string, s3 string) bool {
    // Check if sum of sizes of two strings is equal to the size of third string.
    if len(s1)+len(s2) != len(s3) {
        return false
    }
    return is_Interleave(s1, 0, s2, 0, "", s3)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean is_Interleave(
        String s1,
        int i,
        String s2,
        int j,
        String res,
        String s3
    ) {
        if (res.equals(s3) && i == s1.length() && j == s2.length()) return true;
        boolean ans = false;
        if (i < s1.length()) ans |=
        is_Interleave(s1, i + 1, s2, j, res + s1.charAt(i), s3);
        if (j < s2.length()) ans |=
        is_Interleave(s1, i, s2, j + 1, res + s2.charAt(j), s3);
        return ans;
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        return is_Interleave(s1, 0, s2, 0, "", s3);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var is_Interleave = function (s1, i, s2, j, res, s3) {
    // If result matches with third string and we have reached the end of the all strings, return true.
    if (res === s3 && i === s1.length && j === s2.length) {
        return true;
    }
    let ans = false;
    // Recurse for s1 & s2 if "ans" is false
    if (i < s1.length) {
        ans |= is_Interleave(s1, i + 1, s2, j, res + s1[i], s3);
    }
    if (j < s2.length) {
        ans |= is_Interleave(s1, i, s2, j + 1, res + s2[j], s3);
    }
    return Boolean(ans);
};
var isInterleave = function (s1, s2, s3) {
    // Check if sum of sizes of two strings is equal to the size of third string.
    if (s1.length + s2.length !== s3.length) {
        return false;
    }
    return is_Interleave(s1, 0, s2, 0, "", s3);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def is_Interleave(self, s1, i, s2, j, res, s3):
        # If result matches with third string and we have reached the end of the all strings, return true.
        if res == s3 and i == len(s1) and j == len(s2):
            return True
        ans = False
        # Recurse for s1 & s2 if "ans" is False
        if i < len(s1):
            ans |= self.is_Interleave(s1, i + 1, s2, j, res + s1[i], s3)
        if j < len(s2):
            ans |= self.is_Interleave(s1, i, s2, j + 1, res + s2[j], s3)
        return ans

    def isInterleave(self, s1, s2, s3):
        # Check if sum of sizes of two strings is equal to the size of third string.
        if len(s1) + len(s2) != len(s3):
            return False
        return self.is_Interleave(s1, 0, s2, 0, "", s3)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
let is_Interleave = (
    s1: string,
    i: number,
    s2: string,
    j: number,
    res: string,
    s3: string,
): boolean => {
    // If result matches with third string and we have reached the end of the all strings, return true.
    if (res === s3 && i === s1.length && j === s2.length) {
        return true;
    }
    let ans: boolean = false;
    // Recurse for s1 & s2 if "ans" is false
    if (i < s1.length) {
        ans = ans || is_Interleave(s1, i + 1, s2, j, res + s1[i], s3);
    }
    if (j < s2.length) {
        ans = ans || is_Interleave(s1, i, s2, j + 1, res + s2[j], s3);
    }
    return Boolean(ans);
};
let isInterleave = (s1: string, s2: string, s3: string): boolean => {
    // Check if sum of sizes of two strings is equal to the size of third string.
    if (s1.length + s2.length !== s3.length) {
        return false;
    }
    return is_Interleave(s1, 0, s2, 0, "", s3);
};
```

</details>

<br>

## Approach 2: Recursion with memoization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// In C,the logic of hashmap is implemented using uthash library which is
// included by default for hash set or hash map usage.
bool is_Interleave(char* s1, int i, char* s2, int j, char* s3, int k,
                   int** memo) {
    if (i == strlen(s1)) {
        return strcmp(s2 + j, s3 + k) == 0;
    }
    if (j == strlen(s2)) {
        return strcmp(s1 + i, s3 + k) == 0;
    }
    if (memo[i][j] >= 0) {
        return memo[i][j] == 1 ? true : false;
    }
    bool ans = false;
    if ((s3[k] == s1[i] && is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)) ||
        (s3[k] == s2[j] && is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo))) {
        ans = true;
    }
    memo[i][j] = ans ? 1 : 0;
    return ans;
}
bool isInterleave(char* s1, char* s2, char* s3) {
    if (strlen(s1) + strlen(s2) != strlen(s3)) {
        return false;
    }
    int** memo = malloc(strlen(s1) * sizeof(int*));
    for (int i = 0; i < strlen(s1); i++) {
        memo[i] = malloc(strlen(s2) * sizeof(int));
        for (int j = 0; j < strlen(s2); j++) {
            memo[i][j] = -1;
        }
    }
    return is_Interleave(s1, 0, s2, 0, s3, 0, memo);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// The main idea of the solution is to use backtracking and memoization to solve
// the problem, which is the reason why the codes utilizes recursion.
// Memoization helps to optimize the code in terms of runtime by storing the
// results of expensive function calls and returning the cached result when the
// same inputs occur again.
class Solution {
public:
    bool is_Interleave(string s1, int i, string s2, int j, string s3, int k,
                       vector<vector<int>>& memo) {
        if (i == s1.length()) {
            return s2.substr(j) == s3.substr(k);
        }
        if (j == s2.length()) {
            return s1.substr(i) == s3.substr(k);
        }
        if (memo[i][j] >= 0) {
            return memo[i][j] == 1 ? true : false;
        }
        bool ans = false;
        if ((s3[k] == s1[i] &&
             is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)) ||
            (s3[k] == s2[j] &&
             is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo))) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<int>> memo(s1.length(), vector<int>(s2.length(), -1));
        return is_Interleave(s1, 0, s2, 0, s3, 0, memo);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// A recursive function is used to go through all possible interleavings.
// Memoization is used to avoid recomputing the same information and to return
// the cached results.

public class Solution {
    public bool IsInterleave(string s1, string s2, string s3) {
        if (s1.Length + s2.Length != s3.Length) {
            return false;
        }

        int[,] memo = new int[s1.Length, s2.Length];
        for (int i = 0; i < s1.Length; i++) {
            for (int j = 0; j < s2.Length; j++) {
                memo[i, j] = -1;
            }
        }

        return IsInterleave(s1, 0, s2, 0, s3, 0, memo);
    }

    public bool IsInterleave(string s1, int i, string s2, int j, string s3,
                             int k, int[,] memo) {
        if (i == s1.Length) {
            return s2.Substring(j).Equals(s3.Substring(k));
        }

        if (j == s2.Length) {
            return s1.Substring(i).Equals(s3.Substring(k));
        }

        if (memo[i, j] >= 0) {
            return memo[i, j] == 1 ? true : false;
        }

        bool ans = false;
        if (s3[k] == s1[i] && IsInterleave(s1, i + 1, s2, j, s3, k + 1, memo) ||
            s3[k] == s2[j] && IsInterleave(s1, i, s2, j + 1, s3, k + 1, memo)) {
            ans = true;
        }

        memo[i, j] = ans ? 1 : 0;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang does not have an inbuilt memoization function but it supports the usage of recursive functions and slice data structure which make it possible to manually implement memoization.
func isInterleave(s1 string, s2 string, s3 string) bool {
    if len(s1)+len(s2) != len(s3) {
        return false
    }
    memo := make([][]int, len(s1))
    for i := range memo {
        memo[i] = make([]int, len(s2))
        for j := range memo[i] {
            memo[i][j] = -1
        }
    }
    return is_Interleave(s1, 0, s2, 0, s3, 0, memo)
}

func is_Interleave(
    s1 string,
    i int,
    s2 string,
    j int,
    s3 string,
    k int,
    memo [][]int,
) bool {
    if i == len(s1) {
        return s2[j:] == s3[k:]
    }
    if j == len(s2) {
        return s1[i:] == s3[k:]
    }
    if memo[i][j] >= 0 {
        return memo[i][j] == 1
    }
    ans := false
    if (s3[k] == s1[i] && is_Interleave(s1, i+1, s2, j, s3, k+1, memo)) ||
        (s3[k] == s2[j] && is_Interleave(s1, i, s2, j+1, s3, k+1, memo)) {
        ans = true
    }
    if ans {
        memo[i][j] = 1
    } else {
        memo[i][j] = 0
    }
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean is_Interleave(
        String s1,
        int i,
        String s2,
        int j,
        String s3,
        int k,
        int[][] memo
    ) {
        if (i == s1.length()) {
            return s2.substring(j).equals(s3.substring(k));
        }
        if (j == s2.length()) {
            return s1.substring(i).equals(s3.substring(k));
        }
        if (memo[i][j] >= 0) {
            return memo[i][j] == 1 ? true : false;
        }
        boolean ans = false;
        if (
            (s3.charAt(k) == s1.charAt(i) &&
                is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)) ||
            (s3.charAt(k) == s2.charAt(j) &&
                is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo))
        ) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        int memo[][] = new int[s1.length()][s2.length()];
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                memo[i][j] = -1;
            }
        }
        return is_Interleave(s1, 0, s2, 0, s3, 0, memo);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// Here a recursive depth-first-search is used along with memoization to avoid repetetive work as much as possible. JavaScript is used in an expressive and clear way in this problem, which makes it easy for a developer to quickly understand the code logic.
var isInterleave = function (s1, s2, s3) {
    function is_Interleave(i, j, k, memo) {
        if (i == s1.length) {
            return s2.substring(j) == s3.substring(k);
        }
        if (j == s2.length) {
            return s1.substring(i) == s3.substring(k);
        }
        if (memo[i][j] >= 0) {
            return memo[i][j] == 1;
        }
        var ans = false;
        if (
            (s3.charAt(k) == s1.charAt(i) &&
                is_Interleave(i + 1, j, k + 1, memo)) ||
            (s3.charAt(k) == s2.charAt(j) &&
                is_Interleave(i, j + 1, k + 1, memo))
        ) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
    if (s1.length + s2.length != s3.length) {
        return false;
    }
    var memo = Array(s1.length)
        .fill(0)
        .map((x) => Array(s2.length).fill(-1));
    return is_Interleave(0, 0, 0, memo);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def is_Interleave(
        self, s1: str, i: int, s2: str, j: int, s3: str, k: int, memo: list
    ) -> bool:
        if i == len(s1):
            return s2[j:] == s3[k:]
        if j == len(s2):
            return s1[i:] == s3[k:]
        if memo[i][j] >= 0:
            return memo[i][j] == 1
        ans = False
        if (
            s3[k] == s1[i]
            and self.is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)
            or s3[k] == s2[j]
            and self.is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo)
        ):
            ans = True
        memo[i][j] = 1 if ans else 0
        return ans

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        memo = [[-1] * len(s2) for _ in range(len(s1))]
        return self.is_Interleave(s1, 0, s2, 0, s3, 0, memo)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isInterleave(s1: string, s2: string, s3: string): boolean {
    if (s1.length + s2.length !== s3.length) {
        return false;
    }
    let memo: number[][] = Array(s1.length)
        .fill(0)
        .map((x) => Array(s2.length).fill(-1));
    return is_Interleave(s1, 0, s2, 0, s3, 0, memo);
}
function is_Interleave(
    s1: string,
    i: number,
    s2: string,
    j: number,
    s3: string,
    k: number,
    memo: number[][],
): boolean {
    if (i === s1.length) {
        return s2.substring(j) === s3.substring(k);
    }
    if (j === s2.length) {
        return s1.substring(i) === s3.substring(k);
    }
    if (memo[i][j] >= 0) {
        return memo[i][j] === 1;
    }
    let ans = false;
    if (
        (s3.charAt(k) === s1.charAt(i) &&
            is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)) ||
        (s3.charAt(k) === s2.charAt(j) &&
            is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo))
    ) {
        ans = true;
    }
    memo[i][j] = ans ? 1 : 0;
    return ans;
}
```

</details>

<br>

## Approach 3: Using 2D Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isInterleave(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
    if (len3 != len1 + len2) {
        return false;
    }
    bool dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
            } else {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }
    return dp[len1][len2];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1));
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                               (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsInterleave(string s1, string s2, string s3) {
        if (s3.Length != s1.Length + s2.Length) {
            return false;
        }

        bool[,] dp = new bool[s1.Length + 1, s2.Length + 1];
        for (int i = 0; i <= s1.Length; i++) {
            for (int j = 0; j <= s2.Length; j++) {
                if (i == 0 && j == 0) {
                    dp[i, j] = true;
                } else if (i == 0) {
                    dp[i, j] = dp[i, j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    dp[i, j] = dp[i - 1, j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    dp[i, j] = (dp[i - 1, j] && s1[i - 1] == s3[i + j - 1]) ||
                               (dp[i, j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return dp[s1.Length, s2.Length];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isInterleave(s1 string, s2 string, s3 string) bool {
    if len(s3) != len(s1)+len(s2) {
        return false
    }
    dp := make([][]bool, len(s1)+1)
    for i := range dp {
        dp[i] = make([]bool, len(s2)+1)
    }
    for i := 0; i <= len(s1); i++ {
        for j := 0; j <= len(s2); j++ {
            if i == 0 && j == 0 {
                dp[i][j] = true
            } else if i == 0 {
                dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1]
            } else if j == 0 {
                dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1]
            } else {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1])
            }
        }
    }
    return dp[len(s1)][len(s2)]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        boolean dp[][] = new boolean[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] &&
                    s2.charAt(j - 1) == s3.charAt(i + j - 1);
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] &&
                    s1.charAt(i - 1) == s3.charAt(i + j - 1);
                } else {
                    dp[i][j] = (dp[i - 1][j] &&
                        s1.charAt(i - 1) == s3.charAt(i + j - 1)) ||
                    (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isInterleave = function (s1, s2, s3) {
    if (s3.length !== s1.length + s2.length) {
        return false;
    }
    const dp = Array.from({ length: s1.length + 1 }, () =>
        Array(s2.length + 1).fill(false),
    );
    for (let i = 0; i <= s1.length; i++) {
        for (let j = 0; j <= s2.length; j++) {
            if (i === 0 && j === 0) {
                dp[i][j] = true;
            } else if (i === 0) {
                dp[i][j] = dp[i][j - 1] && s2[j - 1] === s3[i + j - 1];
            } else if (j === 0) {
                dp[i][j] = dp[i - 1][j] && s1[i - 1] === s3[i + j - 1];
            } else {
                dp[i][j] =
                    (dp[i - 1][j] && s1[i - 1] === s3[i + j - 1]) ||
                    (dp[i][j - 1] && s2[j - 1] === s3[i + j - 1]);
            }
        }
    }
    return dp[s1.length][s2.length];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3) != len(s1) + len(s2):
            return False
        dp = [[False] * (len(s2) + 1) for _ in range(len(s1) + 1)]
        for i in range(len(s1) + 1):
            for j in range(len(s2) + 1):
                if i == 0 and j == 0:
                    dp[i][j] = True
                elif i == 0:
                    dp[i][j] = dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]
                elif j == 0:
                    dp[i][j] = dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]
                else:
                    dp[i][j] = (
                        dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]
                    ) or (dp[i][j - 1] and s2[j - 1] == s3[i + j - 1])
        return dp[len(s1)][len(s2)]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isInterleave(s1: string, s2: string, s3: string): boolean {
    if (s3.length !== s1.length + s2.length) {
        return false;
    }
    const dp: boolean[][] = Array.from({ length: s1.length + 1 }, () =>
        Array(s2.length + 1).fill(false),
    );
    for (let i = 0; i <= s1.length; i++) {
        for (let j = 0; j <= s2.length; j++) {
            if (i === 0 && j === 0) {
                dp[i][j] = true;
            } else if (i === 0) {
                dp[i][j] = dp[i][j - 1] && s2[j - 1] === s3[i + j - 1];
            } else if (j === 0) {
                dp[i][j] = dp[i - 1][j] && s1[i - 1] === s3[i + j - 1];
            } else {
                dp[i][j] =
                    (dp[i - 1][j] && s1[i - 1] === s3[i + j - 1]) ||
                    (dp[i][j - 1] && s2[j - 1] === s3[i + j - 1]);
            }
        }
    }
    return dp[s1.length][s2.length];
}
```

</details>

<br>

## Approach 4: Using 1D Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isInterleave(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
    if (len3 != len1 + len2) {
        return false;
    }
    bool dp[len2 + 1];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 && j == 0) {
                dp[j] = true;
            } else if (i == 0) {
                dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
            } else if (j == 0) {
                dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
            } else {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                        (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }
    return dp[len2];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        vector<bool> dp(s2.length() + 1, false);
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else if (i == 0) {
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                            (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s2.length()];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsInterleave(string s1, string s2, string s3) {
        if (s3.Length != s1.Length + s2.Length) {
            return false;
        }

        bool[] dp = new bool[s2.Length + 1];
        for (int i = 0; i <= s1.Length; i++) {
            for (int j = 0; j <= s2.Length; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else if (i == 0) {
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                            (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return dp[s2.Length];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isInterleave(s1 string, s2 string, s3 string) bool {
    if len(s3) != len(s1)+len(s2) {
        return false
    }
    dp := make([]bool, len(s2)+1)
    for i := 0; i <= len(s1); i++ {
        for j := 0; j <= len(s2); j++ {
            if i == 0 && j == 0 {
                dp[j] = true
            } else if i == 0 {
                dp[j] = dp[j-1] && s2[j-1] == s3[i+j-1]
            } else if j == 0 {
                dp[j] = dp[j] && s1[i-1] == s3[i+j-1]
            } else {
                dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1])
            }
        }
    }
    return dp[len(s2)]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        boolean dp[] = new boolean[s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else if (i == 0) {
                    dp[j] = dp[j - 1] &&
                    s2.charAt(j - 1) == s3.charAt(i + j - 1);
                } else if (j == 0) {
                    dp[j] = dp[j] && s1.charAt(i - 1) == s3.charAt(i + j - 1);
                } else {
                    dp[j] = (dp[j] &&
                        s1.charAt(i - 1) == s3.charAt(i + j - 1)) ||
                    (dp[j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
                }
            }
        }
        return dp[s2.length()];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isInterleave = function (s1, s2, s3) {
    if (s3.length !== s1.length + s2.length) {
        return false;
    }
    let dp = new Array(s2.length + 1).fill(false);
    for (let i = 0; i <= s1.length; i++) {
        for (let j = 0; j <= s2.length; j++) {
            if (i === 0 && j === 0) {
                dp[j] = true;
            } else if (i === 0) {
                dp[j] = dp[j - 1] && s2[j - 1] === s3[i + j - 1];
            } else if (j === 0) {
                dp[j] = dp[j] && s1[i - 1] === s3[i + j - 1];
            } else {
                dp[j] =
                    (dp[j] && s1[i - 1] === s3[i + j - 1]) ||
                    (dp[j - 1] && s2[j - 1] === s3[i + j - 1]);
            }
        }
    }
    return dp[s2.length];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3) != len(s1) + len(s2):
            return False
        dp = [False] * (len(s2) + 1)
        for i in range(len(s1) + 1):
            for j in range(len(s2) + 1):
                if i == 0 and j == 0:
                    dp[j] = True
                elif i == 0:
                    dp[j] = dp[j - 1] and s2[j - 1] == s3[i + j - 1]
                elif j == 0:
                    dp[j] = dp[j] and s1[i - 1] == s3[i + j - 1]
                else:
                    dp[j] = (dp[j] and s1[i - 1] == s3[i + j - 1]) or (
                        dp[j - 1] and s2[j - 1] == s3[i + j - 1]
                    )
        return dp[len(s2)]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isInterleave(s1: string, s2: string, s3: string): boolean {
    if (s3.length !== s1.length + s2.length) {
        return false;
    }
    let dp: boolean[] = new Array(s2.length + 1).fill(false);
    for (let i = 0; i <= s1.length; i++) {
        for (let j = 0; j <= s2.length; j++) {
            if (i === 0 && j === 0) {
                dp[j] = true;
            } else if (i === 0) {
                dp[j] = dp[j - 1] && s2.charAt(j - 1) === s3.charAt(i + j - 1);
            } else if (j === 0) {
                dp[j] = dp[j] && s1.charAt(i - 1) === s3.charAt(i + j - 1);
            } else {
                dp[j] =
                    (dp[j] && s1.charAt(i - 1) === s3.charAt(i + j - 1)) ||
                    (dp[j - 1] && s2.charAt(j - 1) === s3.charAt(i + j - 1));
            }
        }
    }
    return dp[s2.length];
}
```

</details>
