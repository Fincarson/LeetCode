# 482. License Key Formatting

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/license-key-formatting/)  
`String`

**Problem Link:** [LeetCode 482 - License Key Formatting](https://leetcode.com/problems/license-key-formatting/)

## Problem

You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.

We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

Return the reformatted license key.

### Example 1

```text
Input: s = "5F3Z-2e-9-w", k = 4
Output: "5F3Z-2E9W"
Explanation: The string s has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.
```

### Example 2

```text
Input: s = "2-5g-3-J", k = 2
Output: "2-5G-3J"
Explanation: The string s has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
```

## Constraints

- 1 <= s.length <= 105
- s consists of English letters, digits, and dashes '-'.
- 1 <= k <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 482. License Key Formatting

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Right to Left Traversal | C++, Java, Python3 |
| Left to Right Traversal | C++, C#, Java, JavaScript |

## Approach 1: Right to Left Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int count = 0;
        int n = s.length();
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '-') {
                ans.push_back(toupper(s[i]));
                count++;
                if (count == k) {
                    ans.push_back('-');
                    count = 0;
                }
            }
        }
        if (ans.size() > 0 && ans.back() == '-') {
           ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String licenseKeyFormatting(String s, int k) {
        int count = 0;
        int n = s.length();
        StringBuilder ans = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) != '-') {
                ans.append(Character.toUpperCase(s.charAt(i)));
                count++;
                if (count == k) {
                    ans.append('-');
                    count = 0;
                }
            }
        }
        // Make sure that the last character is not a dash
        if (ans.length() > 0 && ans.charAt(ans.length()-1) == '-') { 
            ans = new StringBuilder(ans.substring(0, ans.length()-1));
        }
        // Reversing the string
        ans.reverse();
        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        n = len(s)
        count = 0
        ans = ['']
        for i in reversed(range(n)):
            if (s[i] != '-'):
                ans += s[i].upper()
                count = count + 1
                if (count == k):
                    count = 0
                    ans += '-'
     
        # Make sure the output doesn't start with a dash
        if (len(ans) > 0 and ans[len(ans)-1] == '-'):
            ans = ans[:-1]
        ans = ans[::-1]
        result = "".join(ans)
        return result
```

</details>

<br>

## Approach 2: Left to Right Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int totalChars = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '-') {
                totalChars++;
            }
        }
        int sizeOfFirstGroup = (totalChars % k);
        if (sizeOfFirstGroup == 0) {
            sizeOfFirstGroup = k;
        }
        string ans = "";
        int i = 0;
        int count = 0;
        
        while (i < s.length()) {
            if (count == sizeOfFirstGroup) {
                count = 0;
                break;
            }
            if (s[i] != '-') {
                count++;
                ans.push_back(toupper(s[i]));
            }
            i++;
        }
        /* This case will only appear if the value of k is greater than the total number 
           of alphanumeric characters in string s */
        if (i >= s.length()) {
            return ans;
        }
        
        ans.push_back('-');
        
        while (i < s.length()) {
            if (s[i] != '-') {
                /* Whenever count is equal to k, we put a '-' after each group*/
                if (count == k) {
                    ans.push_back('-');
                    count = 0;
                }
                ans.push_back(toupper(s[i]));
                count++;
            }
            i++;
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
    public string LicenseKeyFormatting(string s, int k) {
        int totalChars = 0;
        int i = 0;
        while (i < s.Length) {
            if (s[i] != '-') {
                totalChars++;
            }
            i++;
        }
        int sizeOfFirstGroup = (totalChars % k);
        if (sizeOfFirstGroup == 0) {
            sizeOfFirstGroup = k;
        }
        string ans = "";
        i = 0;
        int count = 0;
        
        while (i < s.Length){
            if (count == sizeOfFirstGroup) {
                count = 0;
                break;
            }
            if (s[i] != '-') {
                count++;
                ans += Char.ToUpper(s[i]);
            }
            i++;
        }
        /* This case will only appear if the value of k is greater than the total number 
           of alphanumeric characters in string s */
        if (i >= s.Length) {
            return ans;
        }
        ans += '-';
        while (i < s.Length) {
            if (s[i] != '-') {
                /* Whenever the count is equal to k, we put a '-' after each group*/
                if (count == k) {
                    ans += '-';
                    count = 0;
                }
                ans += Char.ToUpper(s[i]);
                count++;
            }
            i++;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String licenseKeyFormatting(String s, int k) {
        int totalChars = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '-') {
                totalChars++;
            }
        }
        int sizeOfFirstGroup = (totalChars % k);
        if (sizeOfFirstGroup == 0) {
            sizeOfFirstGroup = k;
        }
        StringBuilder ans = new StringBuilder();
        int i = 0;
        int count = 0;
        
        while (i < s.length()) {
            if (count == sizeOfFirstGroup) {
                count = 0;
                break;
            }
            if (s.charAt(i) != '-') {
                count++;
                ans.append(Character.toUpperCase(s.charAt(i)));
            }
            i++;
        }
        /* This case will only appear if the value of k is greater than the total number 
           of alphanumeric characters in string s */
        if (i >= s.length()) {
            return ans.toString();
        }
        ans.append('-');
        while (i < s.length()) {
            if (s.charAt(i) != '-') {
                /* Whenever the count is equal to k, we put a '-' after each group */
                if (count == k) {
                    ans.append('-');
                    count = 0;
                }
                ans.append(Character.toUpperCase(s.charAt(i)));
                count++;
            }
            i++;
        }
        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var licenseKeyFormatting = function(s, k) {
        let totalChars = 0;
        for (let i = 0; i < s.length; i++) {
            if (s.charAt(i) != '-') {
                totalChars++;
            }
        }
        let sizeOfFirstGroup = (totalChars % k);
        if (sizeOfFirstGroup == 0) {
            sizeOfFirstGroup = k;
        }
        let ans = "";
        let i = 0;
        let count = 0;
        
        while (i < s.length) {
            if (count == sizeOfFirstGroup) {
                count = 0;
                break;
            }
            if (s.charAt(i) != '-') {
                count++;
                ans += s.charAt(i).toUpperCase();
            }
            i++;
        }
        /* This case will only appear if value of k is greater than total number 
           of alphanumeric characters in string s */
        if(i >= s.length) {
            return ans;
        }
        ans += ('-');
        while (i < s.length) {
            if (s.charAt(i) != '-') {
                /* Whenever count is equal to k, we put a '-' after each group */
                if (count == k) {
                    ans += ('-');
                    count = 0;
                }
                ans += s.charAt(i).toUpperCase();
                count++;
            }
            i++;
        }
        return ans;
}
```

</details>
