# 1461. Check If a String Contains All Binary Codes of Size K

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)  
`Hash Table` `String` `Bit Manipulation` `Rolling Hash` `Hash Function`

**Problem Link:** [LeetCode 1461 - Check If a String Contains All Binary Codes of Size K](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)

## Problem

Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

### Example 1

```text
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
```

### Example 2

```text
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring.
```

### Example 3

```text
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.
```

## Constraints

- 1 <= s.length <= 5 * 105
- s[i] is either '0' or '1'.
- 1 <= k <= 20

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1461. Check If a String Contains All Binary Codes of Size K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Set | Java, Python3 |
| Hash | Java, Python3 |

## Approach 1: Set

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean hasAllCodes(String s, int k) {
        int need = 1 << k;
        Set<String> got = new HashSet<String>();

        for (int i = k; i <= s.length(); i++) {
            String a = s.substring(i - k, i);
            if (!got.contains(a)) {
                got.add(a);
                need--;
                // return true when found all occurrences
                if (need == 0) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        need = 1 << k
        got = set()

        for i in range(k, len(s)+1):
            tmp = s[i-k:i]
            if tmp not in got:
                got.add(tmp)
                need -= 1
                # return True when found all occurrences
                if need == 0:
                    return True
        return False
```

</details>

<br>

## Approach 2: Hash

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public static boolean hasAllCodes(String s, int k) {
        int need = 1 << k;
        boolean[] got = new boolean[need];
        int allOne = need - 1;
        int hashVal = 0;

        for (int i = 0; i < s.length(); i++) {
            // calculate hash for s.substr(i-k+1,i+1)
            hashVal = ((hashVal << 1) & allOne) | (s.charAt(i) - '0');
            // hash only available when i-k+1 > 0
            if (i >= k - 1 && !got[hashVal]) {
                got[hashVal] = true;
                need--;
                if (need == 0) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        need = 1 << k
        got = [False]*need
        all_one = need - 1
        hash_val = 0

        for i in range(len(s)):
            # calculate hash for s[i-k+1:i+1]
            hash_val = ((hash_val << 1) & all_one) | (int(s[i]))
            # hash only available when i-k+1 > 0
            if i >= k-1 and got[hash_val] is False:
                got[hash_val] = True
                need -= 1
                if need == 0:
                    return True
        return False
```

</details>
