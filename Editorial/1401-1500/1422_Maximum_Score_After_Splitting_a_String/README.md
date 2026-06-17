# 1422. Maximum Score After Splitting a String

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-score-after-splitting-a-string/)  
`String` `Prefix Sum`

**Problem Link:** [LeetCode 1422 - Maximum Score After Splitting a String](https://leetcode.com/problems/maximum-score-after-splitting-a-string/)

## Problem

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

### Example 1

```text
Input: s = "011101"
Output: 5
Explanation:
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5
left = "01" and right = "1101", score = 1 + 3 = 4
left = "011" and right = "101", score = 1 + 2 = 3
left = "0111" and right = "01", score = 1 + 1 = 2
left = "01110" and right = "1", score = 2 + 1 = 3
```

### Example 2

```text
Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
```

### Example 3

```text
Input: s = "1111"
Output: 3
```

## Constraints

- 2 <= s.length <= 500
- The string s consists of characters '0' and '1' only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1422. Maximum Score After Splitting a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Count Left Zeros and Right Ones | C++, Java, Python3 |
| One Pass | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            int curr = 0;
            for (int j = 0; j <= i; j++) {
                if (s[j] == '0') {
                    curr++;
                }
            }
            
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == '1') {
                    curr++;
                }
            }
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxScore(String s) {
        int ans = 0;
        
        for (int i = 0; i < s.length() - 1; i++) {
            int curr = 0;
            for (int j = 0; j <= i; j++) {
                if (s.charAt(j) == '0') {
                    curr++;
                }
            }
            
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(j) == '1') {
                    curr++;
                }
            }
            
            ans = Math.max(ans, curr);
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxScore(self, s: str) -> int:
        ans = 0
        
        for i in range(len(s) - 1):
            curr = 0
            for j in range(i + 1):
                if s[j] == "0":
                    curr += 1
            
            for j in range(i + 1, len(s)):
                if s[j] == "1":
                    curr += 1
            
            ans = max(ans, curr)
    
        return ans
```

</details>

<br>

## Approach 2: Count Left Zeros and Right Ones

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        
        int ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            
            ans = max(ans, zeros + ones);
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxScore(String s) {
        int ones = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                ones++;
            }
        }
        
        int ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '1') {
                ones--;
            } else {
                zeros++;
            }
            
            ans = Math.max(ans, zeros + ones);
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxScore(self, s: str) -> int:
        ones = s.count("1")
        zeros = 0
        ans = 0 

        for i in range(len(s) - 1):
            if s[i] == "1":
                ones -= 1
            else:
                zeros += 1
        
            ans = max(ans, zeros + ones)
        
        return ans
```

</details>

<br>

## Approach 3: One Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zeros = 0;
        int best = INT_MIN;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }
            
            best = max(best, zeros - ones);
        }
        
        if (s[s.size() - 1] == '1') {
            ones++;
        }
        
        return best + ones;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxScore(String s) {
        int ones = 0;
        int zeros = 0;
        int best = Integer.MIN_VALUE;
        
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '1') {
                ones++;
            } else {
                zeros++;
            }
            
            best = Math.max(best, zeros - ones);
        }
        
        if (s.charAt(s.length() - 1) == '1') {
            ones++;
        }
        
        return best + ones;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxScore(self, s: str) -> int:
        ones = 0
        zeros = 0
        best = -inf

        for i in range(len(s) - 1):
            if s[i] == "1":
                ones += 1
            else:
                zeros += 1
            
            best = max(best, zeros - ones)
            
        if s[-1] == "1":
            ones += 1
        
        return best + ones
```

</details>
