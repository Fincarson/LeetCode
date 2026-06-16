# 28. Find the Index of the First Occurrence in a String

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)  
`Two Pointers` `String` `String Matching`

**Problem Link:** [LeetCode 28 - Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

## Problem

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

### Example 1

```text
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```

### Example 2

```text
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```

## Constraints

- 1 <= haystack.length, needle.length <= 104
- haystack and needle consist of only lowercase English characters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 28. Find the Index of the First Occurrence in a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Rabin-Karp Algorithm (Single Hash) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Rabin-Karp algorithm (Double Hash) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Knuth–Morris–Pratt Algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sliding Window

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int strStr(char* haystack, char* needle) {
    int m = strlen(needle);
    int n = strlen(haystack);

    for (int windowStart = 0; windowStart <= n - m; windowStart++) {
        for (int i = 0; i < m; i++) {
            if (needle[i] != haystack[windowStart + i]) {
                break;
            }
            if (i == m - 1) {
                return windowStart;
            }
        }
    }

    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();

        for (int windowStart = 0; windowStart <= n - m; windowStart++) {
            for (int i = 0; i < m; i++) {
                if (needle[i] != haystack[windowStart + i]) {
                    break;
                }
                if (i == m - 1) {
                    return windowStart;
                }
            }
        }

        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int StrStr(string haystack, string needle) {
        int m = needle.Length;
        int n = haystack.Length;

        for (int windowStart = 0; windowStart <= n - m; windowStart++) {
            for (int i = 0; i < m; i++) {
                if (needle[i] != haystack[windowStart + i]) {
                    break;
                }

                if (i == m - 1) {
                    return windowStart;
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func strStr(haystack string, needle string) int {
    m := len(needle)
    n := len(haystack)

    for windowStart := 0; windowStart <= n-m; windowStart++ {
        for i := 0; i < m; i++ {
            if needle[i] != haystack[windowStart+i] {
                break
            }
            if i == m-1 {
                return windowStart
            }
        }
    }

    return -1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int strStr(String haystack, String needle) {
        int m = needle.length();
        int n = haystack.length();

        for (int windowStart = 0; windowStart <= n - m; windowStart++) {
            for (int i = 0; i < m; i++) {
                if (needle.charAt(i) != haystack.charAt(windowStart + i)) {
                    break;
                }
                if (i == m - 1) {
                    return windowStart;
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var strStr = function (haystack, needle) {
    let m = needle.length;
    let n = haystack.length;

    for (let windowStart = 0; windowStart <= n - m; windowStart++) {
        for (let i = 0; i < m; i++) {
            if (needle[i] != haystack[windowStart + i]) {
                break;
            }
            if (i == m - 1) {
                return windowStart;
            }
        }
    }

    return -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m = len(needle)
        n = len(haystack)

        for window_start in range(n - m + 1):
            for i in range(m):
                if needle[i] != haystack[window_start + i]:
                    break
                if i == m - 1:
                    return window_start

        return -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function strStr(haystack: string, needle: string): number {
    let m = needle.length;
    let n = haystack.length;

    for (let windowStart = 0; windowStart <= n - m; windowStart++) {
        for (let i = 0; i < m; i++) {
            if (needle[i] != haystack[windowStart + i]) {
                break;
            }
            if (i == m - 1) {
                return windowStart;
            }
        }
    }

    return -1;
}
```

</details>

<br>

## Approach 2: Rabin-Karp Algorithm (Single Hash)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int hashValue(char* string, int RADIX, int MOD, int m) {
    int ans = 0;
    long factor = 1;
    for (int i = m - 1; i >= 0; i--) {
        ans = (ans + (string[i] - 'a') * factor) % MOD;
        factor = (factor * RADIX) % MOD;
    }
    return ans % MOD;
}

int strStr(char* haystack, char* needle) {
    int m = strlen(needle);
    int n = strlen(haystack);
    if (n < m) return -1;

    // CONSTANTS
    int RADIX = 26;
    int MOD = 1000000033;
    long MAX_WEIGHT = 1;

    for (int i = 0; i < m; i++) MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;

    // Compute hash of needle
    long hashNeedle = hashValue(needle, RADIX, MOD, m), hashHay = 0;

    // Check for each m-substring of haystack, starting at index windowStart
    for (int windowStart = 0; windowStart <= n - m; windowStart++) {
        if (windowStart == 0) {
            // Compute hash of the First Substring
            hashHay = hashValue(haystack, RADIX, MOD, m);
        } else {
            // Update Hash using Previous Hash Value in O(1)
            hashHay =
                ((hashHay * RADIX) % MOD -
                 ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT) % MOD +
                 (int)(haystack[windowStart + m - 1] - 'a') + MOD) %
                MOD;
        }
        // If the hash matches, Check Character by Character.
        // Because of Mod, spurious hits can be there.
        if (hashNeedle == hashHay) {
            for (int i = 0; i < m; i++) {
                if (needle[i] != haystack[i + windowStart]) {
                    break;
                }
                if (i == m - 1) {
                    return windowStart;
                }
            }
        }
    }

    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int hashValue(string string, int RADIX, int MOD, int m) {
        int ans = 0;
        long factor = 1;
        for (int i = m - 1; i >= 0; i--) {
            ans = (ans + (string[i] - 'a') * factor) % MOD;
            factor = (factor * RADIX) % MOD;
        }
        return ans;
    }

    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();
        if (n < m) return -1;

        // CONSTANTS
        int RADIX = 26;
        int MOD = 1000000033;
        long MAX_WEIGHT = 1;

        for (int i = 0; i < m; i++) MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;

        // Compute hash of needle
        long hashNeedle = hashValue(needle, RADIX, MOD, m), hashHay = 0;

        // Check for each m-substring of haystack, starting at index windowStart
        for (int windowStart = 0; windowStart <= n - m; windowStart++) {
            if (windowStart == 0) {
                // Compute hash of the First Substring
                hashHay = hashValue(haystack, RADIX, MOD, m);
            } else {
                // Update Hash using Previous Hash Value in O(1)
                hashHay =
                    ((hashHay * RADIX) % MOD -
                     ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT) %
                         MOD +
                     (int)(haystack[windowStart + m - 1] - 'a') + MOD) %
                    MOD;
            }
            // If the hash matches, Check Character by Character.
            // Because of Mod, spurious hits can be there.
            if (hashNeedle == hashHay) {
                for (int i = 0; i < m; i++) {
                    if (needle[i] != haystack[i + windowStart]) {
                        break;
                    }
                    if (i == m - 1) {
                        return windowStart;
                    }
                }
            }
        }

        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private long hashValue(string str, int RADIX, int MOD, int m) {
        long ans = 0;
        long factor = 1;
        for (int i = m - 1; i >= 0; --i) {
            ans = (ans + (str[i] - 'a') * factor % MOD + MOD) % MOD;
            factor = (factor * RADIX) % MOD;
        }

        return ans;
    }

    public int StrStr(string haystack, string needle) {
        int m = needle.Length, n = haystack.Length;
        if (n < m)
            return -1;
        const int RADIX = 26, MOD = 1000000033;
        long MAX_WEIGHT = 1;
        for (int i = 0; i < m; ++i) MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
        long hashNeedle = hashValue(needle, RADIX, MOD, m),
             hashHay = hashValue(haystack, RADIX, MOD, m);
        for (int windowStart = 0; windowStart <= n - m; ++windowStart) {
            if (windowStart != 0) {
                hashHay =
                    ((hashHay * RADIX) % MOD -
                     (haystack[windowStart - 1] - 'a') * MAX_WEIGHT % MOD +
                     (haystack[windowStart + m - 1] - 'a') + MOD) %
                    MOD;
            }

            if (hashNeedle == hashHay) {
                for (int i = 0; i < m; ++i) {
                    if (needle[i] != haystack[i + windowStart])
                        break;
                    if (i == m - 1)
                        return windowStart;
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func hashValue(string string, RADIX int, MOD int, m int) int {
    ans := 0
    factor := 1
    for i := m - 1; i >= 0; i-- {
        ans += ((int(string[i]) - int('a')) * factor) % MOD
        factor = (factor * RADIX) % MOD
    }
    return ans % MOD
}

func strStr(haystack string, needle string) int {
    m := len(needle)
    n := len(haystack)
    if n < m {
        return -1
    }

    // CONSTANTS
    RADIX := 26
    MOD := 1000000033
    MAX_WEIGHT := 1

    for i := 0; i < m; i++ {
        MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD
    }

    // Compute hash of needle
    hashNeedle := hashValue(needle, RADIX, MOD, m)
    hashHay := 0

    // Check for each m-substring of haystack, starting at index windowStart
    for windowStart := 0; windowStart <= n-m; windowStart++ {
        if windowStart == 0 {
            // Compute hash of the First Substring
            hashHay = hashValue(haystack, RADIX, MOD, m)
        } else {
            // Update Hash using Previous Hash Value in O(1)
            hashHay = ((hashHay*RADIX)%MOD - ((int(haystack[windowStart-1])-int('a'))*MAX_WEIGHT)%MOD + (int(haystack[windowStart+m-1]) - int('a')) + MOD) % MOD
        }
        // If the hash matches, Check Character by Character.
        // Because of Mod, spurious hits can be there.
        if hashNeedle == hashHay {
            for i := 0; i < m; i++ {
                if needle[i] != haystack[i+windowStart] {
                    break
                }
                if i == m-1 {
                    return windowStart
                }
            }
        }
    }

    return -1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int hashValue(String string, int RADIX, int MOD, int m) {
        long ans = 0;
        long factor = 1;
        for (int i = m - 1; i >= 0; i--) {
            ans = (ans + (string.charAt(i) - 'a') * factor) % MOD;
            factor = (factor * RADIX) % MOD;
        }
        return (int) ans;
    }

    public int strStr(String haystack, String needle) {
        int m = needle.length();
        int n = haystack.length();
        if (n < m) return -1;

        // CONSTANTS
        int RADIX = 26;
        int MOD = 1000000033;
        long MAX_WEIGHT = 1;

        for (int i = 0; i < m; i++) MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;

        // Compute hash of needle
        long hashNeedle = hashValue(needle, RADIX, MOD, m), hashHay = 0;

        // Check for each m-substring of haystack, starting at index windowStart
        for (int windowStart = 0; windowStart <= n - m; windowStart++) {
            if (windowStart == 0) {
                // Compute hash of the First Substring
                hashHay = hashValue(haystack, RADIX, MOD, m);
            } else {
                // Update Hash using Previous Hash Value in O(1)
                hashHay = (((hashHay * RADIX) % MOD) -
                    (((int) (haystack.charAt(windowStart - 1) - 'a') *
                            MAX_WEIGHT) %
                        MOD) +
                    (int) (haystack.charAt(windowStart + m - 1) - 'a') +
                    MOD) %
                MOD;
            }
            // If the hash matches, Check Character by Character.
            // Because of Mod, spurious hits can be there.
            if (hashNeedle == hashHay) {
                for (int i = 0; i < m; i++) {
                    if (needle.charAt(i) != haystack.charAt(i + windowStart)) {
                        break;
                    }
                    if (i == m - 1) {
                        return windowStart;
                    }
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var hashValue = function (string, RADIX, MOD, m) {
    let ans = 0;
    let factor = 1;
    for (let i = m - 1; i >= 0; i--) {
        ans += ((string.charCodeAt(i) - "a".charCodeAt(0)) * factor) % MOD;
        factor = (factor * RADIX) % MOD;
    }
    return ans % MOD;
};

var strStr = function (haystack, needle) {
    let m = needle.length;
    let n = haystack.length;
    if (n < m) return -1;

    // CONSTANTS
    let RADIX = 26;
    let MOD = 1000000033;
    let MAX_WEIGHT = 1;

    for (let i = 0; i < m; i++) MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;

    // Compute hash of needle
    let hashNeedle = hashValue(needle, RADIX, MOD, m),
        hashHay = 0;

    // Check for each m-substring of haystack, starting at index windowStart
    for (let windowStart = 0; windowStart <= n - m; windowStart++) {
        if (windowStart == 0) {
            // Compute hash of the First Substring
            hashHay = hashValue(haystack, RADIX, MOD, m);
        } else {
            // Update Hash using Previous Hash Value in O(1)
            hashHay =
                (((hashHay * RADIX) % MOD) -
                    (((haystack.charCodeAt(windowStart - 1) -
                        "a".charCodeAt(0)) *
                        MAX_WEIGHT) %
                        MOD) +
                    (haystack.charCodeAt(windowStart + m - 1) -
                        "a".charCodeAt(0)) +
                    MOD) %
                MOD;
        }
        // If the hash matches, Check Character by Character.
        // Because of Mod, spurious hits can be there.
        if (hashNeedle == hashHay) {
            for (let i = 0; i < m; i++) {
                if (needle[i] != haystack[i + windowStart]) {
                    break;
                }
                if (i == m - 1) {
                    return windowStart;
                }
            }
        }
    }

    return -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m = len(needle)
        n = len(haystack)
        if n < m:
            return -1

        # CONSTANTS
        RADIX = 26
        MOD = 1_000_000_033
        MAX_WEIGHT = 1

        for _ in range(m):
            MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD

        # Function to compute the hash of m-String
        def hash_value(string):
            ans = 0
            factor = 1

            for i in range(m - 1, -1, -1):
                ans += ((ord(string[i]) - 97) * (factor)) % MOD
                factor = (factor * RADIX) % MOD

            return ans % MOD

        # Compute the hash of needle
        hash_needle = hash_value(needle)

        # Check for each m-substring of haystack, starting at window_start
        for window_start in range(n - m + 1):
            if window_start == 0:
                # Compute hash of the First Substring
                hash_hay = hash_value(haystack)
            else:
                # Update Hash using Previous Hash Value in O(1)
                hash_hay = (
                    (hash_hay * RADIX) % MOD
                    - ((ord(haystack[window_start - 1]) - 97) * MAX_WEIGHT)
                    % MOD
                    + (ord(haystack[window_start + m - 1]) - 97)
                    + MOD
                ) % MOD

            # If hash matches, Check Character by Character.
            # Because of Mod, spurious hits can be there.
            if hash_needle == hash_hay:
                for i in range(m):
                    if needle[i] != haystack[i + window_start]:
                        break
                if i == m - 1:
                    return window_start

        return -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function hashValue(
    string: string,
    RADIX: number,
    MOD: number,
    m: number,
): number {
    let ans = 0;
    let factor = 1;
    for (let i = m - 1; i >= 0; i--) {
        ans += ((string.charCodeAt(i) - "a".charCodeAt(0)) * factor) % MOD;
        factor = (factor * RADIX) % MOD;
    }
    return ans % MOD;
}

function strStr(haystack: string, needle: string): number {
    let m = needle.length;
    let n = haystack.length;
    if (n < m) return -1;

    // CONSTANTS
    let RADIX = 26;
    let MOD = 1000000033;
    let MAX_WEIGHT = 1;

    for (let i = 0; i < m; i++) MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;

    // Compute hash of needle
    let hashNeedle = hashValue(needle, RADIX, MOD, m),
        hashHay = 0;

    // Check for each m-substring of haystack, starting at index windowStart
    for (let windowStart = 0; windowStart <= n - m; windowStart++) {
        if (windowStart == 0) {
            // Compute hash of the First Substring
            hashHay = hashValue(haystack, RADIX, MOD, m);
        } else {
            // Update Hash using Previous Hash Value in O(1)
            hashHay =
                (((hashHay * RADIX) % MOD) -
                    (((haystack.charCodeAt(windowStart - 1) -
                        "a".charCodeAt(0)) *
                        MAX_WEIGHT) %
                        MOD) +
                    (haystack.charCodeAt(windowStart + m - 1) -
                        "a".charCodeAt(0)) +
                    MOD) %
                MOD;
        }
        // If the hash matches, Check Character by Character.
        // Because of Mod, spurious hits can be there.
        if (hashNeedle == hashHay) {
            for (let i = 0; i < m; i++) {
                if (needle[i] != haystack[i + windowStart]) {
                    break;
                }
                if (i == m - 1) {
                    return windowStart;
                }
            }
        }
    }

    return -1;
}
```

</details>

<br>

## Approach 3: Rabin-Karp algorithm (Double Hash)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// CONSTANTS
int RADIX_1 = 26;
int MOD_1 = 1000000033;
int RADIX_2 = 27;
int MOD_2 = 2147483647;

// Return Pair of Hash Values
long* hashPair(char* string, int m) {
    long* hash = (long*)malloc(2 * sizeof(long));
    hash[0] = 0;
    hash[1] = 0;
    long factor1 = 1;
    long factor2 = 1;

    for (int i = m - 1; i >= 0; i--) {
        hash[0] += ((int)(string[i] - 'a') * (factor1)) % MOD_1;
        factor1 = (factor1 * RADIX_1) % MOD_1;
        hash[1] += ((int)(string[i] - 'a') * (factor2)) % MOD_2;
        factor2 = (factor2 * RADIX_2) % MOD_2;
    }

    hash[0] = hash[0] % MOD_1;
    hash[1] = hash[1] % MOD_2;
    return hash;
}

// Return the index of the first occurrence of needle in haystack, or -1 if
// needle is not part of haystack.
int strStr(char* haystack, char* needle) {
    int m = strlen(needle);
    int n = strlen(haystack);
    if (n < m) return -1;

    // COMPUTING CONSTANTS
    long MAX_WEIGHT_1 = 1;
    long MAX_WEIGHT_2 = 1;
    for (int i = 0; i < m; i++) {
        MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
        MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
    }

    // Compute hash pair of needle
    long* hashNeedle = hashPair(needle, m);
    long* hashHay = (long*)malloc(2 * sizeof(long));

    // Check for each m-substring of haystack, starting at index windowStart
    for (int windowStart = 0; windowStart <= n - m; windowStart++) {
        if (windowStart == 0) {
            // Compute hashPair of First Substring
            hashHay = hashPair(haystack, m);
        } else {
            // Update Hash Pair using Previous Hash Value in O(1)
            hashHay[0] =
                ((hashHay[0] * RADIX_1) % MOD_1 -
                 ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT_1) %
                     MOD_1 +
                 (int)(haystack[windowStart + m - 1] - 'a') + MOD_1) %
                MOD_1;
            hashHay[1] =
                ((hashHay[1] * RADIX_2) % MOD_2 -
                 ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT_2) %
                     MOD_2 +
                 (int)(haystack[windowStart + m - 1] - 'a') + MOD_2) %
                MOD_2;
        }

        // If the hash matches, return immediately. Probability of Spurious Hit
        // tends to zero.
        if (hashNeedle[0] == hashHay[0] && hashNeedle[1] == hashHay[1]) {
            return windowStart;
        }
    }

    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // CONSTANTS
    const int RADIX_1 = 26;
    const int MOD_1 = 1000000033;
    const int RADIX_2 = 27;
    const int MOD_2 = 2147483647;

    // Return Pair of Hash Values
    pair<long, long> hashPair(string string, int m) {
        long hash1 = 0, hash2 = 0;
        long factor1 = 1, factor2 = 1;

        for (int i = m - 1; i >= 0; i--) {
            hash1 += ((int)(string[i] - 'a') * (factor1)) % MOD_1;
            factor1 = (factor1 * RADIX_1) % MOD_1;
            hash2 += ((int)(string[i] - 'a') * (factor2)) % MOD_2;
            factor2 = (factor2 * RADIX_2) % MOD_2;
        }

        return make_pair(hash1 % MOD_1, hash2 % MOD_2);
    }

    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();
        if (n < m) return -1;

        // COMPUTING CONSTANTS
        long MAX_WEIGHT_1 = 1;
        long MAX_WEIGHT_2 = 1;
        for (int i = 0; i < m; i++) {
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        }

        // Compute hash pair of needle
        pair<long, long> hashNeedle = hashPair(needle, m);
        pair<long, long> hashHay = {0, 0};

        // Check for each m-substring of haystack, starting at index windowStart
        for (int windowStart = 0; windowStart <= n - m; windowStart++) {
            if (windowStart == 0) {
                // Compute hashPair of First Substring
                hashHay = hashPair(haystack, m);
            } else {
                // Update Hash Pair using Previous Hash Value in O(1)
                hashHay.first =
                    ((hashHay.first * RADIX_1) % MOD_1 -
                     ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT_1) %
                         MOD_1 +
                     (int)(haystack[windowStart + m - 1] - 'a') + MOD_1) %
                    MOD_1;
                hashHay.second =
                    ((hashHay.second * RADIX_2) % MOD_2 -
                     ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT_2) %
                         MOD_2 +
                     (int)(haystack[windowStart + m - 1] - 'a') + MOD_2) %
                    MOD_2;
            }

            // If the hash matches, return immediately. Probability of Spurious
            // Hit tends to zero.
            if (hashNeedle.first == hashHay.first &&
                hashNeedle.second == hashHay.second) {
                return windowStart;
            }
        }

        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    // CONSTANTS
    const int RADIX_1 = 26;
    const int MOD_1 = 1000000033;
    const int RADIX_2 = 27;
    const int MOD_2 = 2147483647;

    public long[] hashPair(string str, int m) {
        long hash1 = 0, hash2 = 0;
        long factor1 = 1, factor2 = 1;
        for (int i = m - 1; i >= 0; i--) {
            hash1 += ((int)(str[i] - 'a') * (factor1)) % MOD_1;
            factor1 = (factor1 * RADIX_1) % MOD_1;
            hash2 += ((int)(str[i] - 'a') * (factor2)) % MOD_2;
            factor2 = (factor2 * RADIX_2) % MOD_2;
        }

        return new long[] { hash1 % MOD_1, hash2 % MOD_2 };
    }

    public int StrStr(string haystack, string needle) {
        int m = needle.Length;
        int n = haystack.Length;
        if (n < m)
            return -1;
        long MAX_WEIGHT_1 = 1;
        long MAX_WEIGHT_2 = 1;
        for (int i = 0; i < m; i++) {
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        }

        long[] hashNeedle = hashPair(needle, m);
        long[] hashHay = new long[2];
        for (int windowStart = 0; windowStart <= n - m; windowStart++) {
            if (windowStart == 0) {
                hashHay = hashPair(haystack, m);
            } else {
                hashHay[0] =
                    ((hashHay[0] * RADIX_1) % MOD_1 -
                     ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT_1) %
                         MOD_1 +
                     (int)(haystack[windowStart + m - 1] - 'a') + MOD_1) %
                    MOD_1;
                hashHay[1] =
                    ((hashHay[1] * RADIX_2) % MOD_2 -
                     ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT_2) %
                         MOD_2 +
                     (int)(haystack[windowStart + m - 1] - 'a') + MOD_2) %
                    MOD_2;
            }

            if (hashNeedle[0] == hashHay[0] && hashNeedle[1] == hashHay[1]) {
                return windowStart;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// CONSTANTS
const (
    RADIX_1 = 26
    MOD_1   = 1000000033
    RADIX_2 = 27
    MOD_2   = 2147483647
)

// Return Pair of Hash Values
func hashPair(string string, m int) []int {
    hash := make([]int, 2)
    factor1 := 1
    factor2 := 1

    for i := m - 1; i >= 0; i-- {
        hash[0] += ((int(string[i]) - int('a')) * (factor1)) % MOD_1
        factor1 = (factor1 * RADIX_1) % MOD_1
        hash[1] += ((int(string[i]) - int('a')) * (factor2)) % MOD_2
        factor2 = (factor2 * RADIX_2) % MOD_2
    }

    hash[0] = hash[0] % MOD_1
    hash[1] = hash[1] % MOD_2
    return hash
}

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
func strStr(haystack string, needle string) int {
    m := len(needle)
    n := len(haystack)
    if n < m {
        return -1
    }

    // COMPUTING CONSTANTS
    MAX_WEIGHT_1 := 1
    MAX_WEIGHT_2 := 1
    for i := 0; i < m; i++ {
        MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1
        MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2
    }

    // Compute hash pair of needle
    hashNeedle := hashPair(needle, m)
    hashHay := make([]int, 2)

    // Check for each m-substring of haystack, starting at index windowStart
    for windowStart := 0; windowStart <= n-m; windowStart++ {
        if windowStart == 0 {
            // Compute hashPair of First Substring
            hashHay = hashPair(haystack, m)
        } else {
            // Update Hash Pair using Previous Hash Value in O(1)
            hashHay[0] = ((hashHay[0]*RADIX_1)%MOD_1 - ((int(haystack[windowStart-1])-int('a'))*MAX_WEIGHT_1)%MOD_1 + (int(haystack[windowStart+m-1]) - int('a')) + MOD_1) % MOD_1
            hashHay[1] = ((hashHay[1]*RADIX_2)%MOD_2 - ((int(haystack[windowStart-1])-int('a'))*MAX_WEIGHT_2)%MOD_2 + (int(haystack[windowStart+m-1]) - int('a')) + MOD_2) % MOD_2
        }

        // If the hash matches, return immediately. Probability of Spurious Hit tends to zero.
        if hashNeedle[0] == hashHay[0] && hashNeedle[1] == hashHay[1] {
            return windowStart
        }
    }

    return -1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // CONSTANTS
    final int RADIX_1 = 26;
    final int MOD_1 = 1000000033;
    final int RADIX_2 = 27;
    final int MOD_2 = 2147483647;

    // Return Array of Hash Values
    public long[] hashPair(String string, int m) {
        long hash1 = 0, hash2 = 0;
        long factor1 = 1, factor2 = 1;

        for (int i = m - 1; i >= 0; i--) {
            hash1 += ((int) (string.charAt(i) - 'a') * (factor1)) % MOD_1;
            factor1 = (factor1 * RADIX_1) % MOD_1;
            hash2 += ((int) (string.charAt(i) - 'a') * (factor2)) % MOD_2;
            factor2 = (factor2 * RADIX_2) % MOD_2;
        }

        return new long[] { hash1 % MOD_1, hash2 % MOD_2 };
    }

    public int strStr(String haystack, String needle) {
        int m = needle.length();
        int n = haystack.length();
        if (n < m) return -1;

        // COMPUTING CONSTANTS
        long MAX_WEIGHT_1 = 1;
        long MAX_WEIGHT_2 = 1;
        for (int i = 0; i < m; i++) {
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        }

        // Compute hash pair of needle
        long[] hashNeedle = hashPair(needle, m);
        long[] hashHay = { 0, 0 };

        // Check for each m-substring of haystack, starting at index windowStart
        for (int windowStart = 0; windowStart <= n - m; windowStart++) {
            if (windowStart == 0) {
                // Compute hashPair of First Substring
                hashHay = hashPair(haystack, m);
            } else {
                // Update Hash Pair using Previous Hash Value in O(1)
                hashHay[0] = (((hashHay[0] * RADIX_1) % MOD_1) -
                    (((int) (haystack.charAt(windowStart - 1) - 'a') *
                            MAX_WEIGHT_1) %
                        MOD_1) +
                    (int) (haystack.charAt(windowStart + m - 1) - 'a') +
                    MOD_1) %
                MOD_1;
                hashHay[1] = (((hashHay[1] * RADIX_2) % MOD_2) -
                    (((int) (haystack.charAt(windowStart - 1) - 'a') *
                            MAX_WEIGHT_2) %
                        MOD_2) +
                    (int) (haystack.charAt(windowStart + m - 1) - 'a') +
                    MOD_2) %
                MOD_2;
            }

            // If the hash matches, return immediately. Probability of Spurious Hit tends to zero.
            if (hashNeedle[0] == hashHay[0] && hashNeedle[1] == hashHay[1]) {
                return windowStart;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// CONSTANTS
const RADIX_1 = 26;
const MOD_1 = 1000000033;
const RADIX_2 = 27;
const MOD_2 = 2147483647;

// Return Pair of Hash Values
function hashPair(string, m) {
    let hash = [0, 0];
    let factor1 = 1;
    let factor2 = 1;

    for (let i = m - 1; i >= 0; i--) {
        hash[0] +=
            ((string.charCodeAt(i) - "a".charCodeAt(0)) * factor1) % MOD_1;
        factor1 = (factor1 * RADIX_1) % MOD_1;
        hash[1] +=
            ((string.charCodeAt(i) - "a".charCodeAt(0)) * factor2) % MOD_2;
        factor2 = (factor2 * RADIX_2) % MOD_2;
    }

    hash[0] = hash[0] % MOD_1;
    hash[1] = hash[1] % MOD_2;
    return hash;
}

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
var strStr = function (haystack, needle) {
    let m = needle.length;
    let n = haystack.length;
    if (n < m) return -1;

    // COMPUTING CONSTANTS
    let MAX_WEIGHT_1 = 1;
    let MAX_WEIGHT_2 = 1;
    for (let i = 0; i < m; i++) {
        MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
        MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
    }

    // Compute hash pair of needle
    let hashNeedle = hashPair(needle, m);
    let hashHay = [0, 0];

    // Check for each m-substring of haystack, starting at index windowStart
    for (let windowStart = 0; windowStart <= n - m; windowStart++) {
        if (windowStart == 0) {
            // Compute hashPair of First Substring
            hashHay = hashPair(haystack, m);
        } else {
            // Update Hash Pair using Previous Hash Value in O(1)
            hashHay[0] =
                (((hashHay[0] * RADIX_1) % MOD_1) -
                    (((haystack.charCodeAt(windowStart - 1) -
                        "a".charCodeAt(0)) *
                        MAX_WEIGHT_1) %
                        MOD_1) +
                    (haystack.charCodeAt(windowStart + m - 1) -
                        "a".charCodeAt(0)) +
                    MOD_1) %
                MOD_1;
            hashHay[1] =
                (((hashHay[1] * RADIX_2) % MOD_2) -
                    (((haystack.charCodeAt(windowStart - 1) -
                        "a".charCodeAt(0)) *
                        MAX_WEIGHT_2) %
                        MOD_2) +
                    (haystack.charCodeAt(windowStart + m - 1) -
                        "a".charCodeAt(0)) +
                    MOD_2) %
                MOD_2;
        }

        // If the hash matches, return immediately. Probability of Spurious Hit tends to zero.
        if (hashNeedle[0] == hashHay[0] && hashNeedle[1] == hashHay[1]) {
            return windowStart;
        }
    }

    return -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m = len(needle)
        n = len(haystack)

        if n < m:
            return -1

        # CONSTANTS
        RADIX_1 = 26
        MOD_1 = 10**9 + 33
        MAX_WEIGHT_1 = 1
        RADIX_2 = 27
        MOD_2 = 2**31 - 1
        MAX_WEIGHT_2 = 1

        for _ in range(m):
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2

        # Function to compute hash_pair of m-String
        def hash_pair(string):
            hash_1 = hash_2 = 0
            factor_1 = factor_2 = 1
            for i in range(m - 1, -1, -1):
                hash_1 += ((ord(string[i]) - 97) * (factor_1)) % MOD_1
                factor_1 = (factor_1 * RADIX_1) % MOD_1
                hash_2 += ((ord(string[i]) - 97) * (factor_2)) % MOD_2
                factor_2 = (factor_2 * RADIX_2) % MOD_2

            return [hash_1 % MOD_1, hash_2 % MOD_2]

        # Compute hash pairs of needle
        hash_needle = hash_pair(needle)

        # Check for each m-substring of haystack, starting at window_start
        for window_start in range(n - m + 1):
            if window_start == 0:
                # Compute hash pairs of the First Substring
                hash_hay = hash_pair(haystack)
            else:
                # Update Hash pairs using Previous using O(1) Value
                hash_hay[0] = (
                    (hash_hay[0] * RADIX_1) % MOD_1
                    - ((ord(haystack[window_start - 1]) - 97) * (MAX_WEIGHT_1))
                    % MOD_1
                    + (ord(haystack[window_start + m - 1]) - 97)
                ) % MOD_1
                hash_hay[1] = (
                    (hash_hay[1] * RADIX_2) % MOD_2
                    - ((ord(haystack[window_start - 1]) - 97) * (MAX_WEIGHT_2))
                    % MOD_2
                    + (ord(haystack[window_start + m - 1]) - 97)
                ) % MOD_2

            # If the hash matches, return immediately.
            # Probability of Spurious Hit tends to zero
            if hash_needle == hash_hay:
                return window_start
        return -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// CONSTANTS
const RADIX_1 = 26;
const MOD_1 = 1000000033;
const RADIX_2 = 27;
const MOD_2 = 2147483647;

// Return Pair of Hash Values
function hashPair(string: string, m: number): number[] {
    let hash = [0, 0];
    let factor1 = 1;
    let factor2 = 1;

    for (let i = m - 1; i >= 0; i--) {
        hash[0] +=
            ((string.charCodeAt(i) - "a".charCodeAt(0)) * factor1) % MOD_1;
        factor1 = (factor1 * RADIX_1) % MOD_1;
        hash[1] +=
            ((string.charCodeAt(i) - "a".charCodeAt(0)) * factor2) % MOD_2;
        factor2 = (factor2 * RADIX_2) % MOD_2;
    }

    hash[0] = hash[0] % MOD_1;
    hash[1] = hash[1] % MOD_2;
    return hash;
}

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
function strStr(haystack: string, needle: string): number {
    const m = needle.length;
    const n = haystack.length;
    if (n < m) {
        return -1;
    }

    // COMPUTING CONSTANTS
    let MAX_WEIGHT_1 = 1;
    let MAX_WEIGHT_2 = 1;
    for (let i = 0; i < m; i++) {
        MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
        MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
    }

    // Compute hash pair of needle
    let hashNeedle = hashPair(needle, m);
    let hashHay = [0, 0];

    // Check for each m-substring of haystack, starting at index windowStart
    for (let windowStart = 0; windowStart <= n - m; windowStart++) {
        if (windowStart == 0) {
            // Compute hashPair of First Substring
            hashHay = hashPair(haystack, m);
        } else {
            // Update Hash Pair using Previous Hash Value in O(1)
            hashHay[0] =
                (((hashHay[0] * RADIX_1) % MOD_1) -
                    (((haystack.charCodeAt(windowStart - 1) -
                        "a".charCodeAt(0)) *
                        MAX_WEIGHT_1) %
                        MOD_1) +
                    (haystack.charCodeAt(windowStart + m - 1) -
                        "a".charCodeAt(0)) +
                    MOD_1) %
                MOD_1;
            hashHay[1] =
                (((hashHay[1] * RADIX_2) % MOD_2) -
                    (((haystack.charCodeAt(windowStart - 1) -
                        "a".charCodeAt(0)) *
                        MAX_WEIGHT_2) %
                        MOD_2) +
                    (haystack.charCodeAt(windowStart + m - 1) -
                        "a".charCodeAt(0)) +
                    MOD_2) %
                MOD_2;
        }

        // If the hash matches, return immediately. Probability of Spurious Hit tends to zero.
        if (hashNeedle[0] == hashHay[0] && hashNeedle[1] == hashHay[1]) {
            return windowStart;
        }
    }

    return -1;
}
```

</details>

<br>

## Approach 4: Knuth–Morris–Pratt Algorithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int strStr(char* haystack, char* needle) {
    int m = strlen(needle);
    int n = strlen(haystack);

    if (n < m) return -1;

    // PREPROCESSING
    // longest_border array
    int longest_border[m];
    longest_border[0] = 0;
    // Length of Longest Border for prefix before it.
    int prev = 0;
    // Iterating from index-1. longest_border[0] will always be 0
    int i = 1;

    while (i < m) {
        if (needle[i] == needle[prev]) {
            // Length of Longest Border Increased
            prev += 1;
            longest_border[i] = prev;
            i += 1;
        } else {
            // Only empty border exist
            if (prev == 0) {
                longest_border[i] = 0;
                i += 1;
            }
            // Try finding longest border for this i with reduced prev
            else {
                prev = longest_border[prev - 1];
            }
        }
    }

    // SEARCHING
    // Pointer for haystack
    int haystackPointer = 0;
    // Pointer for needle.
    // Also indicates number of characters matched in current window.
    int needlePointer = 0;

    while (haystackPointer < n) {
        if (haystack[haystackPointer] == needle[needlePointer]) {
            // Matched Increment Both
            needlePointer += 1;
            haystackPointer += 1;
            // All characters matched
            if (needlePointer == m) {
                // m characters behind last matching will be start of window
                return haystackPointer - m;
            }
        } else {
            if (needlePointer == 0) {
                // Zero Matched
                haystackPointer += 1;
            } else {
                // Optimally shift left needlePointer. Don't change
                // haystackPointer
                needlePointer = longest_border[needlePointer - 1];
            }
        }
    }

    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();

        if (n < m) return -1;

        // PREPROCESSING
        // longest_border array
        vector<int> longest_border(m);
        // Length of Longest Border for prefix before it.
        int prev = 0;
        // Iterating from index-1. longest_border[0] will always be 0
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[prev]) {
                // Length of Longest Border Increased
                prev += 1;
                longest_border[i] = prev;
                i += 1;
            } else {
                // Only empty border exist
                if (prev == 0) {
                    longest_border[i] = 0;
                    i += 1;
                }
                // Try finding longest border for this i with reduced prev
                else {
                    prev = longest_border[prev - 1];
                }
            }
        }

        // SEARCHING
        // Pointer for haystack
        int haystackPointer = 0;
        // Pointer for needle.
        // Also indicates number of characters matched in current window.
        int needlePointer = 0;

        while (haystackPointer < n) {
            if (haystack[haystackPointer] == needle[needlePointer]) {
                // Matched Increment Both
                needlePointer += 1;
                haystackPointer += 1;
                // All characters matched
                if (needlePointer == m) {
                    // m characters behind last matching will be start of window
                    return haystackPointer - m;
                }
            } else {
                if (needlePointer == 0) {
                    // Zero Matched
                    haystackPointer += 1;
                } else {
                    // Optimally shift left needlePointer. Don't change
                    // haystackPointer
                    needlePointer = longest_border[needlePointer - 1];
                }
            }
        }

        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int StrStr(string haystack, string needle) {
        int m = needle.Length;
        int n = haystack.Length;

        if (n < m)
            return -1;

        // PREPROCESSING
        // longest_border array
        int[] longest_border = new int[m];
        // Length of Longest Border for prefix before it.
        int prev = 0;
        // Iterating from index-1. longest_border[0] will always be 0
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[prev]) {
                // Length of Longest Border Increased
                prev += 1;
                longest_border[i] = prev;
                i += 1;
            } else {
                // Only empty border exist
                if (prev == 0) {
                    longest_border[i] = 0;
                    i += 1;
                }
                // Try finding longest border for this i with reduced prev
                else {
                    prev = longest_border[prev - 1];
                }
            }
        }

        // SEARCHING
        // Pointer for haystack
        int haystackPointer = 0;
        // Pointer for needle.
        // Also indicates number of characters matched in current window.
        int needlePointer = 0;

        while (haystackPointer < n) {
            if (haystack[haystackPointer] == needle[needlePointer]) {
                // Matched Increment Both
                needlePointer += 1;
                haystackPointer += 1;
                // All characters matched
                if (needlePointer == m) {
                    // m characters behind last matching will be start of window
                    return haystackPointer - m;
                }
            } else {
                if (needlePointer == 0) {
                    // Zero Matched
                    haystackPointer += 1;
                } else {
                    // Optimally shift left needlePointer. Don't change
                    // haystackPointer
                    needlePointer = longest_border[needlePointer - 1];
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func strStr(haystack string, needle string) int {
    m := len(needle)
    n := len(haystack)
    if n < m {
        return -1
    }
    // PREPROCESSING
    // longest_border array
    longest_border := make([]int, m)
    longest_border[0] = 0
    // Length of Longest Border for prefix before it.
    prev := 0
    // Iterating from index-1. longest_border[0] will always be 0
    i := 1
    for i < m {
        if needle[i] == needle[prev] {
            // Length of Longest Border Increased
            prev += 1
            longest_border[i] = prev
            i += 1
        } else {
            // Only empty border exist
            if prev == 0 {
                longest_border[i] = 0
                i += 1
            } else {
                // Try finding longest border for this i with reduced prev
                prev = longest_border[prev-1]
            }
        }
    }
    // SEARCHING
    // Pointer for haystack
    haystackPointer := 0
    // Pointer for needle.
    // Also indicates the number of characters matched in the current window.
    needlePointer := 0
    for haystackPointer < n {
        if haystack[haystackPointer] == needle[needlePointer] {
            // Matched Increment Both
            needlePointer += 1
            haystackPointer += 1
            // All characters matched
            if needlePointer == m {
                // m characters behind last matching will be the start of the window
                return haystackPointer - m
            }
        } else {
            if needlePointer == 0 {
                // Zero Matched
                haystackPointer += 1
            } else {
                // Optimally shift left needlePointer. Don't change haystackPointer
                needlePointer = longest_border[needlePointer-1]
            }
        }
    }
    return -1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int strStr(String haystack, String needle) {
        int m = needle.length();
        int n = haystack.length();

        if (n < m) return -1;

        // PREPROCESSING
        // longest_border array
        int[] longest_border = new int[m];
        // Length of Longest Border for prefix before it.
        int prev = 0;
        // Iterating from index-1. longest_border[0] will always be 0
        int i = 1;

        while (i < m) {
            if (needle.charAt(i) == needle.charAt(prev)) {
                // Length of Longest Border Increased
                prev += 1;
                longest_border[i] = prev;
                i += 1;
            } else {
                // Only empty border exist
                if (prev == 0) {
                    longest_border[i] = 0;
                    i += 1;
                }
                // Try finding longest border for this i with reduced prev
                else {
                    prev = longest_border[prev - 1];
                }
            }
        }

        // SEARCHING
        // Pointer for haystack
        int haystackPointer = 0;
        // Pointer for needle.
        // Also indicates number of characters matched in current window.
        int needlePointer = 0;

        while (haystackPointer < n) {
            if (
                haystack.charAt(haystackPointer) == needle.charAt(needlePointer)
            ) {
                // Matched Increment Both
                needlePointer += 1;
                haystackPointer += 1;
                // All characters matched
                if (needlePointer == m) {
                    // m characters behind last matching will be start of window
                    return haystackPointer - m;
                }
            } else {
                if (needlePointer == 0) {
                    // Zero Matched
                    haystackPointer += 1;
                } else {
                    // Optimally shift left needlePointer. Don't change haystackPointer
                    needlePointer = longest_border[needlePointer - 1];
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
    let m = needle.length;
    let n = haystack.length;

    if (n < m) return -1;

    // PREPROCESSING
    // longest_border array
    let longest_border = new Array(m);
    longest_border[0] = 0;
    // Length of Longest Border for prefix before it.
    let prev = 0;
    // Iterating from index-1. longest_border[0] will always be 0
    let i = 1;

    while (i < m) {
        if (needle[i] == needle[prev]) {
            // Length of Longest Border Increased
            prev += 1;
            longest_border[i] = prev;
            i += 1;
        } else {
            // Only empty border exist
            if (prev == 0) {
                longest_border[i] = 0;
                i += 1;
            }
            // Try finding longest border for this i with reduced prev
            else {
                prev = longest_border[prev - 1];
            }
        }
    }

    // SEARCHING
    // Pointer for haystack
    let haystackPointer = 0;
    // Pointer for needle.
    // Also indicates number of characters matched in current window.
    let needlePointer = 0;

    while (haystackPointer < n) {
        if (haystack[haystackPointer] == needle[needlePointer]) {
            // Matched Increment Both
            needlePointer += 1;
            haystackPointer += 1;
            // All characters matched
            if (needlePointer == m) {
                // m characters behind last matching will be start of window
                return haystackPointer - m;
            }
        } else {
            if (needlePointer == 0) {
                // Zero Matched
                haystackPointer += 1;
            } else {
                // Optimally shift left needlePointer. Don't change haystackPointer
                needlePointer = longest_border[needlePointer - 1];
            }
        }
    }

    return -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m = len(needle)
        n = len(haystack)

        if n < m:
            return -1

        # PREPROCESSING
        # longest border array
        longest_border = [0] * m
        # Length of Longest Border for prefix before it.
        prev = 0
        # Iterating from index-1. longest_border[0] will always be 0
        i = 1

        while i < m:
            if needle[i] == needle[prev]:
                # Length of Longest Border Increased
                prev += 1
                longest_border[i] = prev
                i += 1
            else:
                # Only empty border exist
                if prev == 0:
                    longest_border[i] = 0
                    i += 1
                # Try finding longest border for this i with reduced prev
                else:
                    prev = longest_border[prev - 1]

        # SEARCHING
        # Pointer for haystack
        haystack_pointer = 0
        # Pointer for needle.
        # Also indicates number of characters matched in current window.
        needle_pointer = 0

        while haystack_pointer < n:
            if haystack[haystack_pointer] == needle[needle_pointer]:
                # Matched Increment Both
                needle_pointer += 1
                haystack_pointer += 1
                # All characters matched
                if needle_pointer == m:
                    # m characters behind last matching will be window start
                    return haystack_pointer - m
            else:
                if needle_pointer == 0:
                    # Zero Matched
                    haystack_pointer += 1
                else:
                    # Optimally shift left needle_pointer.
                    # Don't change haystack_pointer
                    needle_pointer = longest_border[needle_pointer - 1]

        return -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function strStr(haystack: string, needle: string): number {
    const m = needle.length;
    const n = haystack.length;

    if (n < m) {
        return -1;
    }

    // PREPROCESSING
    // longest_border array
    const longest_border = new Array(m);
    longest_border[0] = 0;
    // Length of Longest Border for prefix before it.
    let prev = 0;
    // Iterating from index-1. longest_border[0] will always be 0
    let i = 1;

    while (i < m) {
        if (needle[i] === needle[prev]) {
            // Length of Longest Border Increased
            prev += 1;
            longest_border[i] = prev;
            i += 1;
        } else {
            // Only empty border exist
            if (prev === 0) {
                longest_border[i] = 0;
                i += 1;
            }
            // Try finding longest border for this i with reduced prev
            else {
                prev = longest_border[prev - 1];
            }
        }
    }

    // SEARCHING
    // Pointer for haystack
    let haystackPointer = 0;
    // Pointer for needle.
    // Also indicates number of characters matched in current window.
    let needlePointer = 0;

    while (haystackPointer < n) {
        if (haystack[haystackPointer] === needle[needlePointer]) {
            // Matched Increment Both
            needlePointer += 1;
            haystackPointer += 1;
            // All characters matched
            if (needlePointer === m) {
                // m characters behind last matching will be start of window
                return haystackPointer - m;
            }
        } else {
            if (needlePointer === 0) {
                // Zero Matched
                haystackPointer += 1;
            } else {
                // Optimally shift left needlePointer. Don't change haystackPointer
                needlePointer = longest_border[needlePointer - 1];
            }
        }
    }

    return -1;
}
```

</details>
