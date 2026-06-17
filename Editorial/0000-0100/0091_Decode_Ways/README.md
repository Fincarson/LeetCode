# 91. Decode Ways

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/decode-ways/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 91 - Decode Ways](https://leetcode.com/problems/decode-ways/)

## Problem

You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

- "AAJF" with the grouping (1, 1, 10, 6)
- "KJF" with the grouping (11, 10, 6)
- The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).

Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

The test cases are generated so that the answer fits in a 32-bit integer.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= s.length <= 100
- s contains only digits and may contain leading zero(s).

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Decode Ways II](https://leetcode.com/problems/decode-ways-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Number of Ways to Separate Numbers](https://leetcode.com/problems/number-of-ways-to-separate-numbers/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Number of Texts](https://leetcode.com/problems/count-number-of-texts/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 91. Decode Ways

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Approach with Memoization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative, Constant Space | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursive Approach with Memoization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct map {
    int index; /* key */
    int result;
    UT_hash_handle hh; /* makes this structure hashable */
};
struct map *memo = NULL;
void add_num(int index, int result) {
    struct map *s;
    s = malloc(sizeof(struct map));
    s->index = index;
    s->result = result;
    HASH_ADD_INT(memo, index, s); /* index: name of key field */
}
int find_num(int index) {
    struct map *s;
    HASH_FIND_INT(memo, &index, s);
    return (s == NULL) ? -1 : s->result;
}
void delete_all() {
    struct map *curr_element, *tmp;
    HASH_ITER(hh, memo, curr_element, tmp) {
        HASH_DEL(memo, curr_element);
        free(curr_element);
    }
}
int recursiveWithMemo(int index, char *str) {
    int res;
    if ((res = find_num(index)) != -1) {
        return res;
    }
    if (index == strlen(str)) {
        return 1;
    }
    if (str[index] == '0') {
        return 0;
    }
    if (index == strlen(str) - 1) {
        return 1;
    }
    int ans = recursiveWithMemo(index + 1, str);
    if (atoi(strndup(str + index, 2)) <= 26) {
        ans += recursiveWithMemo(index + 2, str);
    }
    add_num(index, ans);
    return ans;
}
int numDecodings(char *s) {
    int res = recursiveWithMemo(0, s);
    delete_all();
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    map<int, int> memo;

    int recursiveWithMemo(int index, string& str) {
        // Have we already seen this substring?
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        // If you reach the end of the string
        // Return 1 for success.
        if (index == str.length()) {
            return 1;
        }

        // If the string starts with a zero, it can't be decoded
        if (str[index] == '0') {
            return 0;
        }

        if (index == str.length() - 1) {
            return 1;
        }

        int ans = recursiveWithMemo(index + 1, str);
        if (stoi(str.substr(index, 2)) <= 26) {
            ans += recursiveWithMemo(index + 2, str);
        }

        // Save for memoization
        memo[index] = ans;

        return ans;
    }

    int numDecodings(string s) { return recursiveWithMemo(0, s); }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private Dictionary<int, int> memo = new Dictionary<int, int>();

    private int RecursiveWithMemo(int index, string s) {
        if (memo.ContainsKey(index)) {
            return memo[index];
        }

        if (index == s.Length) {
            return 1;
        }

        if (s[index] == '0') {
            return 0;
        }

        if (index == s.Length - 1) {
            return 1;
        }

        int ans = RecursiveWithMemo(index + 1, s);
        if (int.Parse(s.Substring(index, 2)) <= 26) {
            ans += RecursiveWithMemo(index + 2, s);
        }

        memo[index] = ans;
        return ans;
    }

    public int NumDecodings(string s) {
        return RecursiveWithMemo(0, s);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func recursiveWithMemo(index int, str string, memo map[int]int) int {
    if val, ok := memo[index]; ok {
        return val
    }
    if index == len(str) {
        return 1
    }
    if str[index] == '0' {
        return 0
    }
    if index == len(str)-1 {
        return 1
    }
    ans := recursiveWithMemo(index+1, str, memo)
    substrNum, _ := strconv.Atoi(str[index : index+2])
    if substrNum <= 26 {
        ans += recursiveWithMemo(index+2, str, memo)
    }
    memo[index] = ans
    return ans
}

func numDecodings(s string) int {
    memo := make(map[int]int)
    return recursiveWithMemo(0, s, memo)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Map<Integer, Integer> memo = new HashMap<>();

    public int numDecodings(String s) {
        return recursiveWithMemo(0, s);
    }

    private int recursiveWithMemo(int index, String str) {
        // Have we already seen this substring?
        if (memo.containsKey(index)) {
            return memo.get(index);
        }

        // If you reach the end of the string
        // Return 1 for success.
        if (index == str.length()) {
            return 1;
        }

        // If the string starts with a zero, it can't be decoded
        if (str.charAt(index) == '0') {
            return 0;
        }

        if (index == str.length() - 1) {
            return 1;
        }

        int ans = recursiveWithMemo(index + 1, str);
        if (Integer.parseInt(str.substring(index, index + 2)) <= 26) {
            ans += recursiveWithMemo(index + 2, str);
        }

        // Save for memoization
        memo.put(index, ans);

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numDecodings = function (s) {
    let memo = new Object();
    return recursiveWithMemo(0, s, memo);
};
const recursiveWithMemo = (index, str, memo) => {
    if (memo.hasOwnProperty(index)) {
        return memo[index];
    }
    if (index == str.length) {
        return 1;
    }
    if (str.charAt(index) == "0") {
        return 0;
    }
    if (index == str.length - 1) {
        return 1;
    }
    let ans = recursiveWithMemo(index + 1, str, memo);
    if (parseInt(str.substring(index, index + 2)) <= 26) {
        ans += recursiveWithMemo(index + 2, str, memo);
    }
    memo[index] = ans;
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    @lru_cache(maxsize=None)
    def recursiveWithMemo(self, index, s) -> int:
        # If you reach the end of the string
        # Return 1 for success.
        if index == len(s):
            return 1

        # If the string starts with a zero, it can't be decoded
        if s[index] == "0":
            return 0

        if index == len(s) - 1:
            return 1

        answer = self.recursiveWithMemo(index + 1, s)
        if int(s[index : index + 2]) <= 26:
            answer += self.recursiveWithMemo(index + 2, s)

        return answer

    def numDecodings(self, s: str) -> int:
        return self.recursiveWithMemo(0, s)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function recursiveWithMemo(
    index: number,
    str: string,
    memo: Map<number, number>,
): number {
    if (memo.has(index)) {
        return memo.get(index);
    }
    if (index == str.length) {
        return 1;
    }
    if (str.charAt(index) == "0") {
        return 0;
    }
    if (index == str.length - 1) {
        return 1;
    }
    let ans = recursiveWithMemo(index + 1, str, memo);
    if (parseInt(str.substring(index, index + 2)) <= 26) {
        ans += recursiveWithMemo(index + 2, str, memo);
    }
    memo.set(index, ans);
    return ans;
}
function numDecodings(s: string): number {
    let memo = new Map();
    return recursiveWithMemo(0, s, memo);
}
```

</details>

<br>

## Approach 2: Iterative Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numDecodings(char* s) {
    // DP array to store the subproblem results
    int sLength = strlen(s);
    int dp[sLength + 1];
    dp[0] = 1;
    // Ways to decode a string of size 1 is 1. Unless the string is '0'.
    // '0' doesn't have a single digit decode.
    dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i < sLength + 1; i++) {
        dp[i] = 0;
        // Check if successful single digit decode is possible.
        if (s[i - 1] != '0') {
            dp[i] = dp[i - 1];
        }
        char twoDigitStr[3];
        strncpy(twoDigitStr, &s[i - 2], 2);
        twoDigitStr[2] = '\0';
        int twoDigit = atoi(twoDigitStr);
        // Check if successful two digit decode is possible.
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[sLength];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numDecodings(string s) {
        // DP array to store the subproblem results
        vector<int> dp(s.length() + 1);
        dp[0] = 1;

        // Ways to decode a string of size 1 is 1. Unless the string is '0'.
        // '0' doesn't have a single digit decode.
        dp[1] = s[0] == '0' ? 0 : 1;

        for (size_t i = 2; i < dp.size(); i++) {
            // Check if successful single digit decode is possible.
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            // Check if successful two digit decode is possible.
            int two_digit = stoi(s.substr(i - 2, 2));
            if (two_digit >= 10 && two_digit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumDecodings(string s) {
        // DP array to store the subproblem results
        var dp = new int[s.Length + 1];
        dp[0] = 1;
        // Ways to decode a string of size 1 is 1. Unless the string is '0'.
        // '0' doesn't have a single digit decode.
        dp[1] = s[0] == '0' ? 0 : 1;
        for (var i = 2; i < dp.Length; i++) {
            // Check if successful single digit decode is possible.
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            // Check if successful two digit decode is possible.
            int twoDigit = Int32.Parse(s.Substring(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.Length];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numDecodings(s string) int {
    // DP array to store the subproblem results
    dp := make([]int, len(s)+1)
    dp[0] = 1
    // Ways to decode a string of size 1 is 1. Unless the string is '0'.
    // '0' doesn't have a single digit decode.
    if s[0] == '0' {
        dp[1] = 0
    } else {
        dp[1] = 1
    }
    for i := 2; i < len(dp); i++ {
        // Check if successful single digit decode is possible.
        if s[i-1] != '0' {
            dp[i] = dp[i-1]
        }
        // Check if successful two digit decode is possible.
        twoDigit, _ := strconv.Atoi(s[i-2 : i])
        if twoDigit >= 10 && twoDigit <= 26 {
            dp[i] += dp[i-2]
        }
    }
    return dp[len(s)]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numDecodings(String s) {
        // DP array to store the subproblem results
        int[] dp = new int[s.length() + 1];
        dp[0] = 1;

        // Ways to decode a string of size 1 is 1. Unless the string is '0'.
        // '0' doesn't have a single digit decode.
        dp[1] = s.charAt(0) == '0' ? 0 : 1;

        for (int i = 2; i < dp.length; i++) {
            // Check if successful single digit decode is possible.
            if (s.charAt(i - 1) != '0') {
                dp[i] = dp[i - 1];
            }

            // Check if successful two digit decode is possible.
            int twoDigit = Integer.valueOf(s.substring(i - 2, i));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.length()];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numDecodings = function (s) {
    // DP array to store the subproblem results
    let dp = new Array(s.length + 1).fill(0);
    dp[0] = 1;
    // Ways to decode a string of size 1 is 1. Unless the string is '0'.
    // '0' doesn't have a single digit decode.
    dp[1] = s.charAt(0) == "0" ? 0 : 1;
    for (let i = 2; i < dp.length; i++) {
        // Check if successful single digit decode is possible.
        if (s.charAt(i - 1) !== "0") {
            dp[i] = dp[i - 1];
        }
        // Check if successful two digit decode is possible.
        let twoDigit = parseInt(s.substring(i - 2, i));
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[s.length];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numDecodings(self, s: str) -> int:
        # Array to store the subproblem results
        dp = [0 for _ in range(len(s) + 1)]

        dp[0] = 1
        # Ways to decode a string of size 1 is 1. Unless the string is '0'.
        # '0' doesn't have a single digit decode.
        dp[1] = 0 if s[0] == "0" else 1

        for i in range(2, len(dp)):

            # Check if successful single digit decode is possible.
            if s[i - 1] != "0":
                dp[i] = dp[i - 1]

            # Check if successful two digit decode is possible.
            two_digit = int(s[i - 2 : i])
            if two_digit >= 10 and two_digit <= 26:
                dp[i] += dp[i - 2]

        return dp[len(s)]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numDecodings(s: string): number {
    // DP array to store the subproblem results
    let dp: number[] = new Array(s.length + 1).fill(0);
    dp[0] = 1;
    // Ways to decode a string of size 1 is 1. Unless the string is '0'.
    // '0' doesn't have a single digit decode.
    dp[1] = s[0] === "0" ? 0 : 1;
    for (let i = 2; i < dp.length; i++) {
        // Check if successful single digit decode is possible.
        if (s[i - 1] !== "0") {
            dp[i] = dp[i - 1];
        }
        // Check if successful two digit decode is possible.
        let twoDigit: number = parseInt(s.substring(i - 2, i));
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[s.length];
}
```

</details>

<br>

## Approach 3: Iterative, Constant Space

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numDecodings(char* s) {
    if (s[0] == '0') {
        return 0;
    }
    int n = strlen(s);
    int twoBack = 1;
    int oneBack = 1;
    for (int i = 1; i < n; i++) {
        int current = 0;
        if (s[i] != '0') {
            current = oneBack;
        }
        char twoDigitChar[3] = {s[i - 1], s[i], '\0'};
        int twoDigit = atoi(twoDigitChar);
        if (twoDigit >= 10 && twoDigit <= 26) {
            current += twoBack;
        }
        twoBack = oneBack;
        oneBack = current;
    }
    return oneBack;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        size_t n = s.length();
        int two_back = 1;
        int one_back = 1;

        for (size_t i = 1; i < n; i++) {
            int current = 0;
            if (s[i] != '0') {
                current = one_back;
            }
            int two_digit = stoi(s.substr(i - 1, 2));
            if (two_digit >= 10 and two_digit <= 26) {
                current += two_back;
            }

            two_back = one_back;
            one_back = current;
        }
        return one_back;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        int n = s.Length;
        int twoBack = 1;
        int oneBack = 1;
        for (int i = 1; i < n; i++) {
            int current = 0;
            if (s[i] != '0') {
                current = oneBack;
            }

            int twoDigit = int.Parse(s.Substring(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += twoBack;
            }

            twoBack = oneBack;
            oneBack = current;
        }

        return oneBack;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numDecodings(s string) int {
    if string(s[0]) == "0" {
        return 0
    }
    n := len(s)
    twoBack := 1
    oneBack := 1
    for i := 1; i < n; i++ {
        current := 0
        if string(s[i]) != "0" {
            current = oneBack
        }
        twoDigit, _ := strconv.Atoi(s[i-1 : i+1])
        if twoDigit >= 10 && twoDigit <= 26 {
            current += twoBack
        }
        twoBack = oneBack
        oneBack = current
    }
    return oneBack
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numDecodings(String s) {
        if (s.charAt(0) == '0') {
            return 0;
        }

        int n = s.length();
        int twoBack = 1;
        int oneBack = 1;
        for (int i = 1; i < n; i++) {
            int current = 0;
            if (s.charAt(i) != '0') {
                current = oneBack;
            }
            int twoDigit = Integer.parseInt(s.substring(i - 1, i + 1));
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += twoBack;
            }

            twoBack = oneBack;
            oneBack = current;
        }
        return oneBack;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numDecodings = function (s) {
    if (s.charAt(0) === "0") {
        return 0;
    }
    let n = s.length;
    let twoBack = 1;
    let oneBack = 1;
    for (let i = 1; i < n; i++) {
        let current = 0;
        if (s.charAt(i) !== "0") {
            current = oneBack;
        }
        let twoDigit = parseInt(s.slice(i - 1, i + 1));
        if (twoDigit >= 10 && twoDigit <= 26) {
            current += twoBack;
        }
        twoBack = oneBack;
        oneBack = current;
    }
    return oneBack;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0

        two_back = 1
        one_back = 1
        for i in range(1, len(s)):
            current = 0
            if s[i] != "0":
                current = one_back
            two_digit = int(s[i - 1 : i + 1])
            if two_digit >= 10 and two_digit <= 26:
                current += two_back
            two_back = one_back
            one_back = current

        return one_back
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numDecodings(s: string): number {
    if (s.charAt(0) === "0") {
        return 0;
    }
    let n = s.length;
    let twoBack = 1;
    let oneBack = 1;
    for (let i = 1; i < n; i++) {
        let current = 0;
        if (s.charAt(i) !== "0") {
            current = oneBack;
        }
        let twoDigit = parseInt(s.slice(i - 1, i + 1));
        if (twoDigit >= 10 && twoDigit <= 26) {
            current += twoBack;
        }
        twoBack = oneBack;
        oneBack = current;
    }
    return oneBack;
}
```

</details>
