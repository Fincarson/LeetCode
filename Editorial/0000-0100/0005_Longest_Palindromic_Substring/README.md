# 5. Longest Palindromic Substring

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-palindromic-substring/)  
`Two Pointers` `String` `Dynamic Programming`

**Problem Link:** [LeetCode 5 - Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

## Problem

Given a string s, return the longest palindromic substring in s.

### Example 1

```text
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

### Example 2

```text
Input: s = "cbbd"
Output: "bb"
```

## Constraints

- 1 <= s.length <= 1000
- s consist of only digits and English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Non-overlapping Palindrome Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 5. Longest Palindromic Substring

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Check All Substrings | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Expand From Centers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Manacher's Algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Check All Substrings

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool check(char* s, int i, int j);

char* longestPalindrome(char* s) {
    int length = strlen(s);
    char* result = strdup("");

    for (int len = length; len > 0; len--) {
        for (int start = 0; start <= strlen(s) - len; start++) {
            if (check(s, start, start + len)) {
                free(result);
                result = strndup(s + start, len);
                return result;
            }
        }
    }

    return result;
}

bool check(char* s, int i, int j) {
    int left = i;
    int right = j - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }

        left++;
        right--;
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
    string longestPalindrome(string s) {
        for (int length = s.size(); length > 0; length--) {
            for (int start = 0; start <= s.size() - length; start++) {
                if (check(s, start, start + length)) {
                    return s.substr(start, length);
                }
            }
        }

        return "";
    }

private:
    bool check(string s, int i, int j) {
        int left = i;
        int right = j - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
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
    public string LongestPalindrome(string s) {
        for (int length = s.Length; length > 0; length--) {
            for (int start = 0; start <= s.Length - length; start++) {
                if (Check(start, start + length, s)) {
                    return s.Substring(start, length);
                }
            }
        }

        return "";
    }

    private bool Check(int i, int j, string s) {
        int left = i;
        int right = j - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestPalindrome(s string) string {
    check := func(i, j int) bool {
        left := i
        right := j - 1

        for left < right {
            if s[left] != s[right] {
                return false
            }

            left++
            right--
        }

        return true
    }

    for length := len(s); length > 0; length-- {
        for start := 0; start <= len(s)-length; start++ {
            if check(start, start+length) {
                return s[start : start+length]
            }
        }
    }

    return ""
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String longestPalindrome(String s) {
        for (int length = s.length(); length > 0; length--) {
            for (int start = 0; start <= s.length() - length; start++) {
                if (check(start, start + length, s)) {
                    return s.substring(start, start + length);
                }
            }
        }

        return "";
    }

    private boolean check(int i, int j, String s) {
        int left = i;
        int right = j - 1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestPalindrome = function (s) {
    let check = function (i, j) {
        let left = i;
        let right = j - 1;

        while (left < right) {
            if (s.charAt(left) !== s.charAt(right)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    };

    for (let length = s.length; length > 0; length--) {
        for (let start = 0; start <= s.length - length; start++) {
            if (check(start, start + length)) {
                return s.substring(start, start + length);
            }
        }
    }

    return "";
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def check(i, j):
            left = i
            right = j - 1

            while left < right:
                if s[left] != s[right]:
                    return False

                left += 1
                right -= 1

            return True

        for length in range(len(s), 0, -1):
            for start in range(len(s) - length + 1):
                if check(start, start + length):
                    return s[start : start + length]

        return ""
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestPalindrome(s: string): string {
    let check = (i: number, j: number) => {
        let left = i;
        let right = j - 1;

        while (left < right) {
            if (s.charAt(left) !== s.charAt(right)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    };

    for (let length = s.length; length > 0; length--) {
        for (let start = 0; start <= s.length - length; start++) {
            if (check(start, start + length)) {
                return s.substring(start, start + length);
            }
        }
    }

    return "";
}
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#include <stdbool.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    bool dp[n][n];
    memset(dp, false, sizeof dp);
    int ans[2] = {0, 0};

    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            ans[0] = i;
            ans[1] = i + 1;
        } else {
            dp[i][i + 1] = false;
        }
    }

    for (int diff = 2; diff < n; ++diff) {
        for (int i = 0; i < n - diff; ++i) {
            int j = i + diff;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                ans[0] = i;
                ans[1] = j;
            } else {
                dp[i][j] = false;
            }
        }
    }

    s[ans[1] + 1] = '\0';
    return s + ans[0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        array<int, 2> ans = {0, 0};

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans = {i, i + 1};
            }
        }

        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i < n - diff; ++i) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }

        int i = ans[0];
        int j = ans[1];
        return s.substr(i, j - i + 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string LongestPalindrome(string s) {
        int n = s.Length;
        bool[,] dp = new bool[n, n];
        int[] ans = new int[] { 0, 0 };

        for (int i = 0; i < n; i++) {
            dp[i, i] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i, i + 1] = true;
                ans = new int[] { i, i + 1 };
            }
        }

        for (int diff = 2; diff < n; diff++) {
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1, j - 1]) {
                    dp[i, j] = true;
                    ans = new int[] { i, j };
                }
            }
        }

        int start = ans[0];
        int end = ans[1];
        return s.Substring(start, end - start + 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestPalindrome(s string) string {
    n := len(s)
    dp := make([][]bool, n)
    for i := range dp {
        dp[i] = make([]bool, n)
    }
    ans := []int{0, 0}

    for i := 0; i < n; i++ {
        dp[i][i] = true
    }

    for i := 0; i < n-1; i++ {
        if s[i] == s[i+1] {
            dp[i][i+1] = true
            ans = []int{i, i + 1}
        }
    }

    for diff := 2; diff < n; diff++ {
        for i := 0; i < n-diff; i++ {
            j := i + diff
            if s[i] == s[j] && dp[i+1][j-1] {
                dp[i][j] = true
                ans = []int{i, j}
            }
        }
    }
    i, j := ans[0], ans[1]
    return s[i : j+1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int[] ans = new int[] { 0, 0 };

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = true;
                ans[0] = i;
                ans[1] = i + 1;
            }
        }

        for (int diff = 2; diff < n; diff++) {
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }

        int i = ans[0];
        int j = ans[1];
        return s.substring(i, j + 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestPalindrome = function (s) {
    let n = s.length;
    let dp = Array.from({ length: n }, () => new Array(n).fill(false));
    let ans = [0, 0];

    for (let i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (let i = 0; i < n - 1; i++) {
        if (s[i] === s[i + 1]) {
            dp[i][i + 1] = true;
            ans = [i, i + 1];
        }
    }

    for (let diff = 2; diff < n; diff++) {
        for (let i = 0; i < n - diff; i++) {
            let j = i + diff;
            if (s[i] === s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                ans = [i, j];
            }
        }
    }

    let i = ans[0];
    let j = ans[1];
    return s.slice(i, j + 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        ans = [0, 0]

        for i in range(n):
            dp[i][i] = True

        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                ans = [i, i + 1]

        for diff in range(2, n):
            for i in range(n - diff):
                j = i + diff
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    ans = [i, j]

        i, j = ans
        return s[i : j + 1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestPalindrome(s: string): string {
    let n = s.length;
    let dp: boolean[][] = Array.from(Array(n), () => Array(n).fill(false));
    let ans = [0, 0];

    for (let i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (let i = 0; i < n - 1; i++) {
        if (s[i] === s[i + 1]) {
            dp[i][i + 1] = true;
            ans = [i, i + 1];
        }
    }

    for (let diff = 2; diff < n; diff++) {
        for (let i = 0; i < n - diff; i++) {
            let j = i + diff;
            if (s[i] === s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                ans = [i, j];
            }
        }
    }

    let i = ans[0];
    let j = ans[1];
    return s.slice(i, j + 1);
}
```

</details>

<br>

## Approach 3: Expand From Centers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char *longestPalindrome(char *s) {
    if (!s || strlen(s) == 0) return s;

    int stringLength = strlen(s);
    char *palindrome(char *s, int left, int right) {
        int stringLengthLocal = strlen(s);
        while (left >= 0 && right < stringLengthLocal && s[left] == s[right]) {
            left--;
            right++;
        }
        char *p = (char *)malloc(sizeof(char) * (right - left));
        memcpy(p, &s[left + 1], sizeof(char) * (right - left - 1));
        p[right - left - 1] = '\0';  // Add null character at the end
        return p;
    }

    int start = 0, len = 0;
    for (int i = 0; i < stringLength; i++) {
        char *odd = palindrome(s, i, i);
        char *even = palindrome(s, i, i + 1);
        int max_len = strlen(odd) > strlen(even) ? strlen(odd) : strlen(even);

        if (max_len > len) {
            start = i - (max_len - 1) / 2;
            len = max_len;
        }

        free(odd);   // free the allocated memory
        free(even);  // free the allocated memory
    }
    char *ans =
        (char *)malloc(sizeof(char) * (len + 1));  // including space for '\0'
    strncpy(ans, &s[start], len);
    ans[len] = '\0';  // null-terminate the string
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string expand(int i, int j, string s) {
        int left = i;
        int right = j;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            string odd = expand(i, i, s);
            if (odd.size() > ans.size()) {
                ans = odd;
            }

            string even = expand(i, i + 1, s);
            if (even.size() > ans.size()) {
                ans = even;
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
    public string LongestPalindrome(string s) {
        int[] ans = new int[] { 0, 0 };

        for (int i = 0; i < s.Length; i++) {
            int oddLength = Expand(s, i, i);
            if (oddLength > ans[1] - ans[0] + 1) {
                int dist = oddLength / 2;
                ans[0] = i - dist;
                ans[1] = i + dist;
            }

            int evenLength = Expand(s, i, i + 1);
            if (evenLength > ans[1] - ans[0] + 1) {
                int dist = (evenLength / 2) - 1;
                ans[0] = i - dist;
                ans[1] = i + dist + 1;
            }
        }

        return s.Substring(ans[0], ans[1] - ans[0] + 1);
    }

    private int Expand(string s, int i, int j) {
        int left = i;
        int right = j;

        while (left >= 0 && right < s.Length && s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestPalindrome(s string) string {
    expand := func(i, j int) string {
        left := i
        right := j

        for left >= 0 && right < len(s) && s[left] == s[right] {
            left--
            right++
        }

        return s[left+1 : right]
    }

    ans := ""

    for i := 0; i < len(s); i++ {
        odd := expand(i, i)
        if len(odd) > len(ans) {
            ans = odd
        }

        even := expand(i, i+1)
        if len(even) > len(ans) {
            ans = even
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
    public String longestPalindrome(String s) {
        int[] ans = new int[] { 0, 0 };

        for (int i = 0; i < s.length(); i++) {
            int oddLength = expand(i, i, s);
            if (oddLength > ans[1] - ans[0] + 1) {
                int dist = oddLength / 2;
                ans[0] = i - dist;
                ans[1] = i + dist;
            }

            int evenLength = expand(i, i + 1, s);
            if (evenLength > ans[1] - ans[0] + 1) {
                int dist = (evenLength / 2) - 1;
                ans[0] = i - dist;
                ans[1] = i + 1 + dist;
            }
        }

        int i = ans[0];
        int j = ans[1];
        return s.substring(i, j + 1);
    }

    private int expand(int i, int j, String s) {
        int left = i;
        int right = j;

        while (
            left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)
        ) {
            left--;
            right++;
        }

        return right - left - 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestPalindrome = function (s) {
    function expand(i, j) {
        let left = i;
        let right = j;

        while (left >= 0 && right < s.length && s[left] === s[right]) {
            left--;
            right++;
        }

        return s.slice(left + 1, right);
    }

    let ans = "";

    for (let i = 0; i < s.length; i++) {
        let odd = expand(i, i);
        if (odd.length > ans.length) {
            ans = odd;
        }

        let even = expand(i, i + 1);
        if (even.length > ans.length) {
            ans = even;
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
    def longestPalindrome(self, s: str) -> str:
        def expand(i, j):
            left = i
            right = j

            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1

            return right - left - 1

        ans = [0, 0]

        for i in range(len(s)):
            odd_length = expand(i, i)
            if odd_length > ans[1] - ans[0] + 1:
                dist = odd_length // 2
                ans = [i - dist, i + dist]

            even_length = expand(i, i + 1)
            if even_length > ans[1] - ans[0] + 1:
                dist = (even_length // 2) - 1
                ans = [i - dist, i + 1 + dist]

        i, j = ans
        return s[i : j + 1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestPalindrome(s: string): string {
    function expand(i: number, j: number): string {
        let left: number = i;
        let right: number = j;

        while (left >= 0 && right < s.length && s[left] === s[right]) {
            left--;
            right++;
        }

        return s.slice(left + 1, right);
    }

    let ans: string = "";

    for (let i = 0; i < s.length; i++) {
        let odd: string = expand(i, i);
        if (odd.length > ans.length) {
            ans = odd;
        }
        let even: string = expand(i, i + 1);
        if (even.length > ans.length) {
            ans = even;
        }
    }

    return ans;
}
```

</details>

<br>

## Approach 4: Manacher's Algorithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C Implementation
#include "stdlib.h"
#include "string.h"

char* longestPalindrome(char* s) {
    int len = strlen(s);
    char* s_prime = (char*)malloc(sizeof(char) * (2 * len + 2));
    s_prime[0] = '#';
    int j = 1;
    for (int i = 0; i < len; i++) {
        s_prime[j++] = s[i];
        s_prime[j++] = '#';
    }
    s_prime[j] = '\0';

    int n = strlen(s_prime);
    int* palindrome_radii = (int*)malloc(n * sizeof(int));
    memset(palindrome_radii, 0, n * sizeof(int));
    int center = 0;
    int radius = 0;

    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;

        if (i < radius) {
            palindrome_radii[i] = (radius - i > palindrome_radii[mirror]
                                       ? palindrome_radii[mirror]
                                       : radius - i);
        }

        while (i + 1 + palindrome_radii[i] < n &&
               i - 1 - palindrome_radii[i] >= 0 &&
               s_prime[i + 1 + palindrome_radii[i]] ==
                   s_prime[i - 1 - palindrome_radii[i]]) {
            palindrome_radii[i]++;
        }

        if (i + palindrome_radii[i] > radius) {
            center = i;
            radius = i + palindrome_radii[i];
        }
    }

    int max_length = 0;
    int center_index = 0;
    for (int i = 0; i < n; i++) {
        if (palindrome_radii[i] > max_length) {
            max_length = palindrome_radii[i];
            center_index = i;
        }
    }

    int start_index = (center_index - max_length) / 2;
    char* longest_palindrome = (char*)malloc(max_length + 1);
    strncpy(longest_palindrome, &s[start_index], max_length);
    longest_palindrome[max_length] = '\0';

    free(s_prime);
    free(palindrome_radii);

    return longest_palindrome;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        string s_prime = "#";
        for (char c : s) {
            s_prime += c;
            s_prime += "#";
        }

        int n = s_prime.length();
        vector<int> palindrome_radii(n, 0);
        int center = 0;
        int radius = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            if (i < radius) {
                palindrome_radii[i] = min(radius - i, palindrome_radii[mirror]);
            }

            while (i + 1 + palindrome_radii[i] < n &&
                   i - 1 - palindrome_radii[i] >= 0 &&
                   s_prime[i + 1 + palindrome_radii[i]] ==
                       s_prime[i - 1 - palindrome_radii[i]]) {
                palindrome_radii[i]++;
            }

            if (i + palindrome_radii[i] > radius) {
                center = i;
                radius = i + palindrome_radii[i];
            }
        }

        int max_length = 0;
        int center_index = 0;
        for (int i = 0; i < n; i++) {
            if (palindrome_radii[i] > max_length) {
                max_length = palindrome_radii[i];
                center_index = i;
            }
        }

        int start_index = (center_index - max_length) / 2;
        string longest_palindrome = s.substr(start_index, max_length);

        return longest_palindrome;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string LongestPalindrome(string s) {
        string s_prime = "#";
        foreach (char c in s) {
            s_prime += c;
            s_prime += "#";
        }

        int n = s_prime.Length;
        int[] palindromeRadii = new int[n];
        int center = 0;
        int radius = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            if (radius > i)
                palindromeRadii[i] =
                    System.Math.Min(radius - i, palindromeRadii[mirror]);

            while (i + 1 + palindromeRadii[i] < n &&
                   i - 1 - palindromeRadii[i] >= 0 &&
                   s_prime[i + 1 + palindromeRadii[i]] ==
                       s_prime[i - 1 - palindromeRadii[i]])
                palindromeRadii[i]++;

            if (i + palindromeRadii[i] > radius) {
                center = i;
                radius = i + palindromeRadii[i];
            }
        }

        int maxLength = 0;
        int centerIndex = 0;
        for (int i = 0; i < n; i++) {
            if (palindromeRadii[i] > maxLength) {
                maxLength = palindromeRadii[i];
                centerIndex = i;
            }
        }

        int startIndex = (centerIndex - maxLength) / 2;
        return s.Substring(startIndex, maxLength);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestPalindrome(s string) string {
    sPrime := "#"
    for _, c := range s {
        sPrime = sPrime + string(c) + "#"
    }

    n := len(sPrime)
    palindromeRadii := make([]int, n)
    center := 0
    radius := 0

    for i := 0; i < n; i++ {
        mirror := 2*center - i

        if i < radius {
            palindromeRadii[i] = min(radius-i, palindromeRadii[mirror])
        }

        for i+1+palindromeRadii[i] < n && i-1-palindromeRadii[i] >= 0 &&
            sPrime[i+1+palindromeRadii[i]] == sPrime[i-1-palindromeRadii[i]] {
            palindromeRadii[i]++
        }

        if i+palindromeRadii[i] > radius {
            center = i
            radius = i + palindromeRadii[i]
        }
    }

    maxLength := 0
    centerIndex := 0
    for i := 0; i < n; i++ {
        if palindromeRadii[i] > maxLength {
            maxLength = palindromeRadii[i]
            centerIndex = i
        }
    }

    startIndex := (centerIndex - maxLength) / 2
    longestPalindrome := s[startIndex : startIndex+maxLength]

    return longestPalindrome
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String longestPalindrome(String s) {
        StringBuilder sPrime = new StringBuilder("#");
        for (char c : s.toCharArray()) {
            sPrime.append(c).append("#");
        }

        int n = sPrime.length();
        int[] palindromeRadii = new int[n];
        int center = 0;
        int radius = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            if (i < radius) {
                palindromeRadii[i] = Math.min(
                    radius - i,
                    palindromeRadii[mirror]
                );
            }

            while (
                i + 1 + palindromeRadii[i] < n &&
                i - 1 - palindromeRadii[i] >= 0 &&
                sPrime.charAt(i + 1 + palindromeRadii[i]) ==
                    sPrime.charAt(i - 1 - palindromeRadii[i])
            ) {
                palindromeRadii[i]++;
            }

            if (i + palindromeRadii[i] > radius) {
                center = i;
                radius = i + palindromeRadii[i];
            }
        }

        int maxLength = 0;
        int centerIndex = 0;
        for (int i = 0; i < n; i++) {
            if (palindromeRadii[i] > maxLength) {
                maxLength = palindromeRadii[i];
                centerIndex = i;
            }
        }

        int startIndex = (centerIndex - maxLength) / 2;
        String longestPalindrome = s.substring(
            startIndex,
            startIndex + maxLength
        );

        return longestPalindrome;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestPalindrome = function (s) {
    let sPrime = "#";
    for (let c of s) {
        sPrime += c;
        sPrime += "#";
    }

    let n = sPrime.length;
    let palindromeRadii = new Array(n).fill(0);
    let center = 0;
    let radius = 0;

    for (let i = 0; i < n; i++) {
        let mirror = 2 * center - i;

        if (i < radius)
            palindromeRadii[i] = Math.min(radius - i, palindromeRadii[mirror]);

        while (
            i + 1 + palindromeRadii[i] < n &&
            i - 1 - palindromeRadii[i] >= 0 &&
            sPrime.charAt(i + 1 + palindromeRadii[i]) ==
                sPrime.charAt(i - 1 - palindromeRadii[i])
        )
            palindromeRadii[i]++;

        if (i + palindromeRadii[i] > radius) {
            center = i;
            radius = i + palindromeRadii[i];
        }
    }

    let maxLength = 0;
    let centerIndex = 0;
    for (let i = 0; i < n; i++) {
        if (palindromeRadii[i] > maxLength) {
            maxLength = palindromeRadii[i];
            centerIndex = i;
        }
    }

    let startIndex = Math.floor((centerIndex - maxLength) / 2);
    let longestPalindrome = s.slice(startIndex, startIndex + maxLength);

    return longestPalindrome;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        s_prime = "#" + "#".join(s) + "#"
        n = len(s_prime)
        palindrome_radii = [0] * n
        center = radius = 0

        for i in range(n):
            mirror = 2 * center - i

            if i < radius:
                palindrome_radii[i] = min(radius - i, palindrome_radii[mirror])

            while (
                i + 1 + palindrome_radii[i] < n
                and i - 1 - palindrome_radii[i] >= 0
                and s_prime[i + 1 + palindrome_radii[i]]
                == s_prime[i - 1 - palindrome_radii[i]]
            ):
                palindrome_radii[i] += 1

            if i + palindrome_radii[i] > radius:
                center = i
                radius = i + palindrome_radii[i]

        max_length = max(palindrome_radii)
        center_index = palindrome_radii.index(max_length)
        start_index = (center_index - max_length) // 2
        longest_palindrome = s[start_index : start_index + max_length]

        return longest_palindrome
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestPalindrome(s: string): string {
    let sPrime = "#";
    for (let c of s) {
        sPrime += c;
        sPrime += "#";
    }

    let n = sPrime.length;
    let palindromeRadii = new Array(n).fill(0);
    let center = 0;
    let radius = 0;

    for (let i = 0; i < n; i++) {
        let mirror = 2 * center - i;

        if (i < radius)
            palindromeRadii[i] = Math.min(radius - i, palindromeRadii[mirror]);

        while (
            i + 1 + palindromeRadii[i] < n &&
            i - 1 - palindromeRadii[i] >= 0 &&
            sPrime.charAt(i + 1 + palindromeRadii[i]) ==
                sPrime.charAt(i - 1 - palindromeRadii[i])
        )
            palindromeRadii[i]++;

        if (i + palindromeRadii[i] > radius) {
            center = i;
            radius = i + palindromeRadii[i];
        }
    }

    let maxLength = 0;
    let centerIndex = 0;
    for (let i = 0; i < n; i++) {
        if (palindromeRadii[i] > maxLength) {
            maxLength = palindromeRadii[i];
            centerIndex = i;
        }
    }

    let startIndex = Math.floor((centerIndex - maxLength) / 2);
    let longestPalindrome = s.slice(startIndex, startIndex + maxLength);

    return longestPalindrome;
}
```

</details>
