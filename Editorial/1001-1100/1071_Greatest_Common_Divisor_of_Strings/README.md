# 1071. Greatest Common Divisor of Strings

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/greatest-common-divisor-of-strings/)  
`Math` `String`

**Problem Link:** [LeetCode 1071 - Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

## Problem

For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- 1 <= str1.length, str2.length <= 1000
- str1 and str2 consist of English uppercase letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Smallest Even Multiple](https://leetcode.com/problems/smallest-even-multiple/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Maximum Factor Score of Array](https://leetcode.com/problems/find-the-maximum-factor-score-of-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1071. Greatest Common Divisor of Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Greatest Common Divisor | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool valid(string str1, string str2, int k) {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 % k > 0 || len2 % k > 0) {
            return false;
        } else {
            string base = str1.substr(0, k);
            int n1 = len1 / k, n2 = len2 / k;
            return str1 == joinWords(base, n1) && str2 == joinWords(base, n2);
        }
    }
    string joinWords(string str, int k) {
        string ans = "";
        for (int i = 0; i < k; ++i) {
            ans += str;
        }
        return ans;
    }
    
    
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        for (int i = min(len1, len2); i >= 1; --i) {
            if (valid(str1, str2, i)) {
                return str1.substr(0, i);
            }
        }
        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean valid(String str1, String str2, int k) {
        int len1 = str1.length(), len2 = str2.length();
        if (len1 % k > 0 || len2 % k > 0) {
            return false;
        } else {
            String base = str1.substring(0, k);
            return str1.replace(base, "").isEmpty() && str2.replace(base, "").isEmpty();
        }
    }
    
    
    public String gcdOfStrings(String str1, String str2) {
        int len1 = str1.length(), len2 = str2.length();
        for (int i = Math.min(len1, len2); i >= 1; --i) {
            if (valid(str1, str2, i)) {
                return str1.substring(0, i);
            }
        }
        return "";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        len1, len2 = len(str1), len(str2)
        
        def valid(k):
            if len1 % k or len2 % k: 
                return False
            n1, n2 = len1 // k, len2 // k
            base = str1[:k]
            return str1 == n1 * base and str2 == n2 * base 
        
        for i in range(min(len1, len2), 0, -1):
            if valid(i):
                return str1[:i]
        return ""
```

</details>

<br>

## Approach 2: Greatest Common Divisor

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if they have non-zero GCD string.
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int gcd(int x, int y) {
        if (y == 0) {
            return x;
        } else {
            return gcd(y, x % y);
        }    
    }
    
    public String gcdOfStrings(String str1, String str2) {
        // Check if they have non-zero GCD string.
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        
        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.length(), str2.length());
        return str1.substring(0, gcdLength);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # Check if they have non-zero GCD string.
        if str1 + str2 != str2 + str1:
            return ""

        # Get the GCD of the two lengths.
        max_length = gcd(len(str1), len(str2))
        return str1[:max_length]
```

</details>
