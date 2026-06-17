# 115. Distinct Subsequences

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/distinct-subsequences/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 115 - Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)

## Problem

Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

### Example 1

```text
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
```

### Example 2

```text
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
```

## Constraints

- 1 <= s.length, t.length <= 1000
- s and t consist of English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Unique Good Subsequences](https://leetcode.com/problems/number-of-unique-good-subsequences/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 115. Distinct Subsequences

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion + Memoization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Space optimized Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion + Memoization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numDistinct(char* s, char* t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    if (len1 < len2) return 0;
    int i, j;
    unsigned long long int dp[1001][1001];
    dp[0][0] = 1;
    for (i = 1; i <= len2; ++i) dp[0][i] = 0;
    for (i = 1; i <= len1; ++i) dp[i][0] = 1;
    for (i = 1; i <= len1; ++i)
        for (j = 1; j <= len2; ++j)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
    return dp[len1][len2];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    unordered_map<string, int> memo;

public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;
        if (s == t || t.empty()) return 1;
        string key = to_string(s.size()) + "," + to_string(t.size());
        if (memo.find(key) != memo.end()) return memo[key];
        int N = s.size(), M = t.size();
        int ans = numDistinct(s.substr(0, N - 1), t);
        if (s[N - 1] == t[M - 1])
            ans += numDistinct(s.substr(0, N - 1), t.substr(0, M - 1));
        memo[key] = ans;
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private Dictionary<string, int> memo;

    public int NumDistinct(string s, string t) {
        if (s.Length < t.Length)
            return 0;
        if (s == t || t == "")
            return 1;
        memo = new Dictionary<string, int>();
        return DistinctHelper(s.Substring(0, s.Length - 1), t) +
               ((s[s.Length - 1] == t[t.Length - 1])
                    ? DistinctHelper(s.Substring(0, s.Length - 1),
                                     t.Substring(0, t.Length - 1))
                    : 0);
    }

    private int DistinctHelper(string s, string t) {
        if (memo.ContainsKey(s + "," + t))
            return memo[s + "," + t];
        if (s.Length < t.Length)
            return 0;
        if (s == t || t == "")
            return 1;
        memo[s + "," + t] = DistinctHelper(s.Substring(0, s.Length - 1), t) +
                            ((s[s.Length - 1] == t[t.Length - 1])
                                 ? DistinctHelper(s.Substring(0, s.Length - 1),
                                                  t.Substring(0, t.Length - 1))
                                 : 0);
        return memo[s + "," + t];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numDistinct(s string, t string) int {
    memo := make(map[string]int)
    var helper func(i int, j int) int
    helper = func(i int, j int) int {
        if i == len(s) || j == len(t) || len(s)-i < len(t)-j {
            if j == len(t) {
                return 1
            }
            return 0
        }
        key := strconv.Itoa(i) + "," + strconv.Itoa(j)
        if val, ok := memo[key]; ok {
            return val
        }
        ans := helper(i+1, j)
        if s[i] == t[j] {
            ans += helper(i+1, j+1)
        }
        memo[key] = ans
        return ans
    }
    return helper(0, 0)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Dictionary that we will use for memoization
    private HashMap<Pair<Integer, Integer>, Integer> memo;

    private int recurse(String s, String t, int i, int j) {
        int M = s.length();
        int N = t.length();

        // Base case
        if (i == M || j == N || M - i < N - j) {
            return j == t.length() ? 1 : 0;
        }

        Pair<Integer, Integer> key = new Pair<Integer, Integer>(i, j);

        // Check to see if the result for this recursive
        // call is already cached
        if (this.memo.containsKey(key)) {
            return this.memo.get(key);
        }

        // Always calculate this result since it's
        // required for both the cases
        int ans = this.recurse(s, t, i + 1, j);

        // If the characters match, then we make another
        // recursion call and add the result to "ans"
        if (s.charAt(i) == t.charAt(j)) {
            ans += this.recurse(s, t, i + 1, j + 1);
        }

        // Cache the result
        this.memo.put(key, ans);
        return ans;
    }

    public int numDistinct(String s, String t) {
        this.memo = new HashMap<Pair<Integer, Integer>, Integer>();
        return this.recurse(s, t, 0, 0);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numDistinct = function (s, t) {
    let memo = new Map();
    function dp(i, j) {
        if (i === s.length || j === t.length || s.length - i < t.length - j)
            return j === t.length ? 1 : 0;
        let key = [i, j].toString();
        if (memo.has(key)) return memo.get(key);
        let ans = dp(i + 1, j);
        if (s[i] === t[j]) ans += dp(i + 1, j + 1);
        memo.set(key, ans);
        return ans;
    }
    return dp(0, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numDistinct(self, s: str, t: str) -> int:

        # Dictionary for memoization
        memo = {}

        def uniqueSubsequences(i: int, j: int) -> int:

            M, N = len(s), len(t)

            # Base case
            if i == M or j == N or M - i < N - j:
                return int(j == len(t))

            # Check if the result is already cached
            if (i, j) in memo:
                return memo[i, j]

            # Always make this recursive call
            ans = uniqueSubsequences(i + 1, j)

            # If the characters match, make the other
            # one and add the result to "ans"
            if s[i] == t[j]:
                ans += uniqueSubsequences(i + 1, j + 1)

            # Cache the answer and return
            memo[i, j] = ans
            return ans

        return uniqueSubsequences(0, 0)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numDistinct(s: string, t: string): number {
    let memo = new Map<string, number>();
    function helper(i: number, j: number): number {
        if (i === s.length || j === t.length || s.length - i < t.length - j)
            return j === t.length ? 1 : 0;
        let key = i + "," + j;
        if (memo.has(key)) return memo.get(key) as number;
        let ans = helper(i + 1, j);
        if (s[i] === t[j]) ans += helper(i + 1, j + 1);
        memo.set(key, ans);
        return ans;
    }
    return helper(0, 0);
}
```

</details>

<br>

## Approach 2: Iterative Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C
unsigned int numDistinct(char* s, char* t) {
    int M = strlen(s);
    int N = strlen(t);
    unsigned int dp[M + 1][N + 1];
    memset(dp, 0, sizeof(dp));  // Initialize all dp elements to 0
    // Base case initialization
    for (int i = 0; i <= M; ++i) dp[i][N] = 1;
    for (int i = M - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            if (s[i] == t[j])
                dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];
            else
                dp[i][j] = dp[i + 1][j];
        }
    }
    return dp[0][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++
class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size();
        int N = t.size();
        vector<vector<unsigned int>> dp(M + 1, vector<unsigned int>(N + 1, 0));
        // Base case initialization
        for (int j = 0; j <= N; ++j) dp[M][j] = 0;
        // Base case initialization
        for (int i = 0; i <= M; ++i) dp[i][N] = 1;
        // Iterate over the strings in reverse so as to
        // satisfy the way we've modeled our recursive solution
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                // Remember, we always need this result
                dp[i][j] = dp[i + 1][j];
                // If the characters match, we add the
                // result of the next recursion call (in this
                // case, the value of a cell in the dp table)
                if (s[i] == t[j]) dp[i][j] += dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C#

public class Solution {
    public int NumDistinct(string s, string t) {
        int M = s.Length;
        int N = t.Length;
        int[,] dp = new int[M + 1, N + 1];
        // Base case initialization
        for (int j = 0; j <= N; j++) dp[M, j] = 0;
        // Base case initialization
        for (int i = 0; i <= M; i++) dp[i, N] = 1;
        // Iterate over the strings in reverse so as to
        // satisfy the way we've modeled our recursive solution
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                // Remember, we always need this result
                dp[i, j] = dp[i + 1, j];
                // If the characters match, we add the
                // result of the next recursion call (in this
                // case, the value of a cell in the dp table)
                if (s[i] == t[j])
                    dp[i, j] += dp[i + 1, j + 1];
            }
        }

        return dp[0, 0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang
func numDistinct(s string, t string) int {
    M := len(s)
    N := len(t)
    // Dynamic Programming table
    dp := make([][]int, len(s)+1)
    for i := range dp {
        dp[i] = make([]int, len(t)+1)
    }
    // Base case initialization
    for j := 0; j <= N; j++ {
        dp[M][j] = 0
    }
    // Base case initialization
    for i := 0; i <= M; i++ {
        dp[i][N] = 1
    }
    // Iterate over the strings in reverse so as to
    // satisfy the way we've modeled our recursive solution
    for i := M - 1; i >= 0; i-- {
        for j := N - 1; j >= 0; j-- {
            // Remember, we always need this result
            dp[i][j] = dp[i+1][j]
            // If the characters match, we add the
            // result of the next recursion call (in this
            // case, the value of a cell in the dp table)
            if s[i] == t[j] {
                dp[i][j] += dp[i+1][j+1]
            }
        }
    }
    return dp[0][0]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numDistinct(String s, String t) {
        int M = s.length();
        int N = t.length();

        int[][] dp = new int[M + 1][N + 1];

        // Base case initialization
        for (int j = 0; j <= N; j++) {
            dp[M][j] = 0;
        }

        // Base case initialization
        for (int i = 0; i <= M; i++) {
            dp[i][N] = 1;
        }

        // Iterate over the strings in reverse so as to
        // satisfy the way we've modeled our recursive solution
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                // Remember, we always need this result
                dp[i][j] = dp[i + 1][j];

                // If the characters match, we add the
                // result of the next recursion call (in this
                // case, the value of a cell in the dp table
                if (s.charAt(i) == t.charAt(j)) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript
var numDistinct = function (s, t) {
    let M = s.length;
    let N = t.length;
    // Dynamic Programming table
    let dp = Array.from({ length: M + 1 }, () =>
        Array.from({ length: N + 1 }, () => 0),
    );
    // Base case initialization
    for (let j = 0; j <= N; ++j) dp[M][j] = 0;
    // Base case initialization
    for (let i = 0; i <= M; ++i) dp[i][N] = 1;
    // Iterate over the strings in reverse so as to
    // satisfy the way we've modeled our recursive solution
    for (let i = M - 1; i >= 0; --i) {
        for (let j = N - 1; j >= 0; --j) {
            // Remember, we always need this result
            dp[i][j] = dp[i + 1][j];
            // If the characters match, we add the
            // result of the next recursion call (in this
            // case, the value of a cell in the dp table)
            if (s[i] === t[j]) dp[i][j] += dp[i + 1][j + 1];
        }
    }
    return dp[0][0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numDistinct(self, s: str, t: str) -> int:

        M: int = len(s)
        N: int = len(t)

        # Dynamic Programming table
        dp: List[List[int]] = [[0 for _ in range(N + 1)] for _ in range(M + 1)]

        # Base case initialization
        for j in range(N + 1):
            dp[M][j] = 0

        # Base case initialization
        for i in range(M + 1):
            dp[i][N] = 1

        # Iterate over the strings in reverse so as to
        # satisfy the way we've modeled our recursive solution
        for i in range(M - 1, -1, -1):
            for j in range(N - 1, -1, -1):

                # Remember, we always need this result
                dp[i][j] = dp[i + 1][j]

                # If the characters match, we add the
                # result of the next recursion call (in this
                # case, the value of a cell in the dp table)
                if s[i] == t[j]:
                    dp[i][j] += dp[i + 1][j + 1]

        return dp[0][0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript
function numDistinct(s: string, t: string): number {
    let M = s.length;
    let N = t.length;
    // Dynamic Programming table
    let dp: number[][] = Array.from({ length: M + 1 }, () =>
        Array.from({ length: N + 1 }, () => 0),
    );
    // Base case initialization
    for (let j = 0; j <= N; ++j) dp[M][j] = 0;
    // Base case initialization
    for (let i = 0; i <= M; ++i) dp[i][N] = 1;
    // Iterate over the strings in reverse so as to
    // satisfy the way we've modeled our recursive solution
    for (let i = M - 1; i >= 0; --i) {
        for (let j = N - 1; j >= 0; --j) {
            // Remember, we always need this result
            dp[i][j] = dp[i + 1][j];
            // If the characters match, we add the
            // result of the next recursion call (in this
            // case, the value of a cell in the dp table)
            if (s[i] === t[j]) dp[i][j] += dp[i + 1][j + 1];
        }
    }
    return dp[0][0];
}
```

</details>

<br>

## Approach 3: Space optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long MOD = 1e9 + 7;
int numDistinct(char* s, char* t) {
    int M = strlen(s);
    int N = strlen(t);
    long long dp[M + 1][N + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= M; i++) dp[i][N] = 1;
    for (int i = M - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            dp[i][j] = dp[i + 1][j];
            if (s[i] == t[j]) {
                dp[i][j] += dp[i + 1][j + 1];
                dp[i][j] %= MOD;
            }
        }
    }
    return (int)dp[0][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size();
        int N = t.size();
        vector<vector<unsigned int>> dp(M + 1, vector<unsigned int>(N + 1));
        for (int i = 0; i <= M; i++) {
            dp[i][N] = 1;
        }
        for (int j = N - 1; j >= 0; j--) {
            for (int i = M - 1; i >= 0; i--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumDistinct(string s, string t) {
        int M = s.Length;
        int N = t.Length;
        int[] dp = new int[N];
        int prev = 1;
        for (int i = M - 1; i >= 0; i--) {
            prev = 1;
            for (int j = N - 1; j >= 0; j--) {
                int old_dpj = dp[j];
                if (s[i] == t[j]) {
                    dp[j] += prev;
                }

                prev = old_dpj;
            }
        }

        return dp[0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numDistinct(s string, t string) int {
    M := len(s)
    N := len(t)
    dp := make([]int, N)
    prev := 1
    for i := M - 1; i >= 0; i-- {
        prev = 1
        for j := N - 1; j >= 0; j-- {
            old_dpj := dp[j]
            if s[i] == t[j] {
                dp[j] += prev
            }
            prev = old_dpj
        }
    }
    return dp[0]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numDistinct(String s, String t) {
        int M = s.length();
        int N = t.length();

        int[] dp = new int[N];

        int prev = 1;

        // Iterate over the strings in reverse so as to
        // satisfy the way we've modeled our recursive solution
        for (int i = M - 1; i >= 0; i--) {
            // At each step we start with the last value in
            // the row which is always 1. Notice how we are
            // starting the loop from N - 1 instead of N like
            // in the previous solution.
            prev = 1;

            for (int j = N - 1; j >= 0; j--) {
                // Record the current value in this cell so that
                // we can use it to calculate the value of dp[j - 1]
                int old_dpj = dp[j];

                // If the characters match, we add the
                // result of the next recursion call (in this
                // case, the value of a cell in the dp table
                if (s.charAt(i) == t.charAt(j)) {
                    dp[j] += prev;
                }

                // Update the prev variable
                prev = old_dpj;
            }
        }

        return dp[0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numDistinct = function (s, t) {
    let M = s.length;
    let N = t.length;
    let dp = new Array(N).fill(0);
    let prev = 1;
    // Iterate over the strings in reverse so as to
    // satisfy the way we've modeled our recursive solution
    for (let i = M - 1; i >= 0; i--) {
        // At each step we start with the last value in
        // the row which is always 1. Notice how we are
        // starting the loop from N - 1 instead of N like
        // in the previous solution.
        prev = 1;
        for (let j = N - 1; j >= 0; j--) {
            // Record the current value in this cell so that
            // we can use it to calculate the value of dp[j - 1]
            let old_dpj = dp[j];
            // If the characters match, we add the
            // result of the next recursion call (in this
            // case, the value of a cell in the dp table
            if (s.charAt(i) == t.charAt(j)) {
                dp[j] += prev;
            }
            // Update the prev variable
            prev = old_dpj;
        }
    }
    return dp[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numDistinct(self, s: str, t: str) -> int:

        M, N = len(s), len(t)

        # Dynamic Programming table
        dp = [0 for j in range(N)]

        # Iterate over the strings in reverse so as to
        # satisfy the way we've modeled our recursive solution
        for i in range(M - 1, -1, -1):

            # At each step we start with the last value in
            # the row which is always 1. Notice how we are
            # starting the loop from N - 1 instead of N like
            # in the previous solution.
            prev = 1

            for j in range(N - 1, -1, -1):

                # Record the current value in this cell so that
                # we can use it to calculate the value of dp[j - 1]
                old_dpj = dp[j]

                # If the characters match, we add the
                # result of the next recursion call (in this
                # case, the value of a cell in the dp table
                if s[i] == t[j]:
                    dp[j] += prev

                # Update the prev variable
                prev = old_dpj

        return dp[0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numDistinct(s: string, t: string): number {
    let M = s.length;
    let N = t.length;
    let dp: number[] = new Array(N).fill(0);
    let prev = 1;
    for (let i = M - 1; i >= 0; i--) {
        prev = 1;
        for (let j = N - 1; j >= 0; j--) {
            let old_dpj = dp[j];
            if (s.charAt(i) == t.charAt(j)) {
                dp[j] += prev;
            }
            prev = old_dpj;
        }
    }
    return dp[0];
}
```

</details>
