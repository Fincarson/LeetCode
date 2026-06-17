# 686. Repeated String Match

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/repeated-string-match/)  
`String` `String Matching`

**Problem Link:** [LeetCode 686 - Repeated String Match](https://leetcode.com/problems/repeated-string-match/)

## Problem

Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for bÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

### Example 1

```text
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
```

### Example 2

```text
Input: a = "a", b = "aa"
Output: 2
```

## Constraints

- 1 <= a.length, b.length <= 104
- a and b consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 686. Repeated String Match

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Ad-Hoc [Accepted] | Java, Python |
| Approach #2: Rabin-Karp (Rolling Hash) [Accepted] | Java, Python |

## Approach #1: Ad-Hoc [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int repeatedStringMatch(String A, String B) {
        int q = 1;
        StringBuilder S = new StringBuilder(A);
        for (; S.length() < B.length(); q++) S.append(A);
        if (S.indexOf(B) >= 0) return q;
        if (S.append(A).indexOf(B) >= 0) return q+1;
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def repeatedStringMatch(self, A, B):
        q = (len(B) - 1) // len(A) + 1
        for i in range(2):
            if B in A * (q+i): return q+i
        return -1
```

</details>

<br>

## Approach #2: Rabin-Karp (Rolling Hash) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.math.BigInteger;

class Solution {
    public boolean check(int index, String A, String B) {
        for (int i = 0; i < B.length(); i++) {
            if (A.charAt((i + index) % A.length()) != B.charAt(i)) {
                return false;
            }
        }
        return true;
    }
    public int repeatedStringMatch(String A, String B) {
        int q = (B.length() - 1) / A.length() + 1;
        int p = 113, MOD = 1_000_000_007;
        int pInv = BigInteger.valueOf(p).modInverse(BigInteger.valueOf(MOD)).intValue();

        long bHash = 0, power = 1;
        for (int i = 0; i < B.length(); i++) {
            bHash += power * B.codePointAt(i);
            bHash %= MOD;
            power = (power * p) % MOD;
        }

        long aHash = 0; power = 1;
        for (int i = 0; i < B.length(); i++) {
            aHash += power * A.codePointAt(i % A.length());
            aHash %= MOD;
            power = (power * p) % MOD;
        }

        if (aHash == bHash && check(0, A, B)) return q;
        power = (power * pInv) % MOD;

        for (int i = B.length(); i < (q + 1) * A.length(); i++) {
            aHash -= A.codePointAt((i - B.length()) % A.length());
            aHash *= pInv;
            aHash += power * A.codePointAt(i % A.length());
            aHash %= MOD;
            if (aHash == bHash && check(i - B.length() + 1, A, B)) {
                return i < q * A.length() ? q : q + 1;
            }
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def repeatedStringMatch(self, A, B):
        def check(index):
            return all(A[(i + index) % len(A)] == x
                       for i, x in enumerate(B))

        q = (len(B) - 1) // len(A) + 1

        p, MOD = 113, 10**9 + 7
        p_inv = pow(p, MOD-2, MOD)
        power = 1

        b_hash = 0
        for x in map(ord, B):
            b_hash += power * x
            b_hash %= MOD
            power = (power * p) % MOD

        a_hash = 0
        power = 1
        for i in xrange(len(B)):
            a_hash += power * ord(A[i % len(A)])
            a_hash %= MOD
            power = (power * p) % MOD

        if a_hash == b_hash and check(0): return q

        power = (power * p_inv) % MOD
        for i in xrange(len(B), (q+1) * len(A)):
            a_hash = (a_hash - ord(A[(i - len(B)) % len(A)])) * p_inv
            a_hash += power * ord(A[i % len(A)])
            a_hash %= MOD
            if a_hash == b_hash and check(i - len(B) + 1):
                return q if i < q * len(A) else q+1

        return -1
```

</details>
