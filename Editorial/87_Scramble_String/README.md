# 87. Scramble String

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/scramble-string/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 87 - Scramble String](https://leetcode.com/problems/scramble-string/)

## Problem

We can scramble a string s to get a string t using the following algorithm:

Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

### Example 1

```text
Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
```

### Example 2

```text
Input: s1 = "abcde", s2 = "caebd"
Output: false
```

### Example 3

```text
Input: s1 = "a", s2 = "a"
Output: true
```

## Constraints

- s1.length == s2.length
- 1 <= s1.length <= 30
- s1 and s2 consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 87. Scramble String

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isScramble(char* s1, char* s2) {
    int n = strlen(s1);
    bool dp[n + 1][n][n];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[1][i][j] = s1[i] == s2[j];
        }
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n + 1 - length; i++) {
            for (int j = 0; j < n + 1 - length; j++) {
                for (int newLength = 1; newLength < length; newLength++) {
                    bool* dp1 = dp[newLength][i];
                    bool* dp2 = dp[length - newLength][i + newLength];
                    dp[length][i][j] =
                        dp[length][i][j] || (dp1[j] && dp2[j + newLength]);
                    dp[length][i][j] = dp[length][i][j] ||
                                       (dp1[j + length - newLength] && dp2[j]);
                }
            }
        }
    }
    return dp[n][0][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector dp(n + 1, vector(n, vector<int>(n)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i < n + 1 - length; i++) {
                for (int j = 0; j < n + 1 - length; j++) {
                    for (int newLength = 1; newLength < length; newLength++) {
                        const vector<int>& dp1 = dp[newLength][i];
                        const vector<int>& dp2 =
                            dp[length - newLength][i + newLength];
                        dp[length][i][j] |= dp1[j] && dp2[j + newLength];
                        dp[length][i][j] |=
                            dp1[j + length - newLength] && dp2[j];
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsScramble(string s1, string s2) {
        int n = s1.Length;
        bool[][][] dp = new bool [n + 1][][];
        for (int i = 0; i < dp.Length; i++) {
            dp[i] = new bool [n][];
            for (int j = 0; j < dp[i].Length; j++) {
                dp[i][j] = new bool[n];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }

        for (int length = 2; length <= n; length++) {
            for (int i = 0; i < n + 1 - length; i++) {
                for (int j = 0; j < n + 1 - length; j++) {
                    for (int newLength = 1; newLength < length; newLength++) {
                        bool[] dp1 = dp[newLength][i];
                        bool[] dp2 = dp[length - newLength][i + newLength];
                        dp[length][i][j] |= dp1[j] && dp2[j + newLength];
                        dp[length][i][j] |=
                            dp1[j + length - newLength] && dp2[j];
                    }
                }
            }
        }

        return dp[n][0][0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isScramble(s1 string, s2 string) bool {
    n := len(s1)
    dp := make([][][]bool, n+1)
    for i := range dp {
        dp[i] = make([][]bool, n)
        for j := range dp[i] {
            dp[i][j] = make([]bool, n)
        }
    }
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            dp[1][i][j] = s1[i] == s2[j]
        }
    }
    for length := 2; length <= n; length++ {
        for i := 0; i < n+1-length; i++ {
            for j := 0; j < n+1-length; j++ {
                for newLength := 1; newLength < length; newLength++ {
                    dp1 := dp[newLength][i]
                    dp2 := dp[length-newLength][i+newLength]
                    dp[length][i][j] = dp[length][i][j] ||
                        (dp1[j] && dp2[j+newLength])
                    dp[length][i][j] = dp[length][i][j] ||
                        (dp1[j+length-newLength] && dp2[j])
                }
            }
        }
    }
    return dp[n][0][0]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isScramble(String s1, String s2) {
        int n = s1.length();
        boolean dp[][][] = new boolean[n + 1][n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = s1.charAt(i) == s2.charAt(j);
            }
        }
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i < n + 1 - length; i++) {
                for (int j = 0; j < n + 1 - length; j++) {
                    for (int newLength = 1; newLength < length; newLength++) {
                        boolean dp1[] = dp[newLength][i];
                        boolean dp2[] = dp[length - newLength][i + newLength];
                        dp[length][i][j] |= dp1[j] && dp2[j + newLength];
                        dp[length][i][j] |=
                        dp1[j + length - newLength] && dp2[j];
                    }
                }
            }
        }
        return dp[n][0][0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isScramble = function (s1, s2) {
    const n = s1.length;
    let dp = new Array(n + 1)
        .fill(0)
        .map(() => new Array(n).fill(0).map(() => new Array(n).fill(false)));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            dp[1][i][j] = s1.charAt(i) == s2.charAt(j);
        }
    }
    for (let length = 2; length <= n; length++) {
        for (let i = 0; i < n + 1 - length; i++) {
            for (let j = 0; j < n + 1 - length; j++) {
                for (let newLength = 1; newLength < length; newLength++) {
                    const dp1 = dp[newLength][i];
                    const dp2 = dp[length - newLength][i + newLength];
                    dp[length][i][j] |= dp1[j] && dp2[j + newLength];
                    dp[length][i][j] |= dp1[j + length - newLength] && dp2[j];
                }
            }
        }
    }
    return dp[n][0][0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        n = len(s1)
        dp = [
            [[False for j in range(n)] for i in range(n)] for l in range(n + 1)
        ]
        for i in range(n):
            for j in range(n):
                dp[1][i][j] = s1[i] == s2[j]
        for length in range(2, n + 1):
            for i in range(n + 1 - length):
                for j in range(n + 1 - length):
                    for new_length in range(1, length):
                        dp1 = dp[new_length][i]
                        dp2 = dp[length - new_length][i + new_length]
                        dp[length][i][j] |= dp1[j] and dp2[j + new_length]
                        dp[length][i][j] |= (
                            dp1[j + length - new_length] and dp2[j]
                        )
        return dp[n][0][0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isScramble(s1: string, s2: string): boolean {
    const n = s1.length;
    let dp: boolean[][][] = Array(n + 1)
        .fill([])
        .map(() =>
            Array(n)
                .fill([])
                .map(() => Array(n).fill(false)),
        );
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            dp[1][i][j] = s1.charAt(i) == s2.charAt(j);
        }
    }
    for (let length = 2; length <= n; length++) {
        for (let i = 0; i < n + 1 - length; i++) {
            for (let j = 0; j < n + 1 - length; j++) {
                for (let newLength = 1; newLength < length; newLength++) {
                    const dp1 = dp[newLength][i];
                    const dp2 = dp[length - newLength][i + newLength];
                    if (dp1[j] && dp2[j + newLength]) dp[length][i][j] = true;
                    if (dp1[j + length - newLength] && dp2[j])
                        dp[length][i][j] = true;
                }
            }
        }
    }
    return dp[n][0][0];
}
```

</details>
