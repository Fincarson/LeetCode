# 125. Valid Palindrome

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/valid-palindrome/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 125 - Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)

## Problem

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

### Example 1

```text
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

### Example 2

```text
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

### Example 3

```text
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
```

## Constraints

- 1 <= s.length <= 2 * 105
- s consists only of printable ASCII characters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Product of the Length of Two Palindromic Subsequences](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Valid Palindrome IV](https://leetcode.com/problems/valid-palindrome-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Palindromes After Operations](https://leetcode.com/problems/maximum-palindromes-after-operations/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 125. Valid Palindrome

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Compare with Reverse | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Compare with Reverse

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++, right--;
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
    bool isPalindrome(string s) {
        string filtered_string, reversed_string;

        for (auto ch : s) {
            if (isalnum(ch)) filtered_string += tolower(ch);
        }

        reversed_string.resize(filtered_string.size());
        reverse_copy(filtered_string.begin(), filtered_string.end(),
                     reversed_string.begin());

        return filtered_string == reversed_string;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsPalindrome(string s) {
        string filteredString = String.Empty;
        foreach (char ch in s) {
            if (Char.IsLetterOrDigit(ch)) {
                filteredString += Char.ToLower(ch);
            }
        }

        char[] reversedChars = filteredString.ToCharArray();
        Array.Reverse(reversedChars);
        string reversedString = new string(reversedChars);
        return filteredString == reversedString;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isPalindrome(s string) bool {
    filteredChars := ""
    for _, ch := range s {
        if unicode.IsLetter(ch) || unicode.IsNumber(ch) {
            filteredChars += strings.ToLower(string(ch))
        }
    }
    reversedChars := reverseString(filteredChars)
    return filteredChars == reversedChars
}

func reverseString(s string) string {
    chars := []rune(s)
    for i, j := 0, len(chars)-1; i < j; i, j = i+1, j-1 {
        chars[i], chars[j] = chars[j], chars[i]
    }
    return string(chars)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder builder = new StringBuilder();

        for (char ch : s.toCharArray()) {
            if (Character.isLetterOrDigit(ch)) {
                builder.append(Character.toLowerCase(ch));
            }
        }

        String filteredString = builder.toString();
        String reversedString = builder.reverse().toString();

        return filteredString.equals(reversedString);
    }

    /** An alternate solution using Java 8 Streams */
    public boolean isPalindromeUsingStreams(String s) {
        StringBuilder builder = new StringBuilder();

        s
            .chars()
            .filter(c -> Character.isLetterOrDigit(c))
            .mapToObj(c -> Character.toLowerCase((char) c))
            .forEach(builder::append);

        return builder.toString().equals(builder.reverse().toString());
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isPalindrome = function (s) {
    let filteredChars = "";
    for (let ch of s) {
        if (ch.match(/[a-z0-9]/i)) {
            filteredChars += ch.toLowerCase();
        }
    }
    const reversedChars = filteredChars.split("").reverse().join("");
    return filteredChars === reversedChars;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:

        filtered_chars = filter(lambda ch: ch.isalnum(), s)
        lowercase_filtered_chars = map(lambda ch: ch.lower(), filtered_chars)

        filtered_chars_list = list(lowercase_filtered_chars)
        reversed_chars_list = filtered_chars_list[::-1]

        return filtered_chars_list == reversed_chars_list
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isPalindrome(s: string): boolean {
    let filteredChars = "";
    for (let ch of s) {
        if (ch.match(/[a-z0-9]/i)) {
            filteredChars += ch.toLowerCase();
        }
    }
    const reversedChars = filteredChars.split("").reverse().join("");
    return filteredChars === reversedChars;
}
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isPalindrome(char* s) {
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        while (i < j && !isalnum(s[i])) {
            i++;
        }
        while (i < j && !isalnum(s[j])) {
            j--;
        }
        if (tolower(s[i]) != tolower(s[j])) return false;
        i++;
        j--;
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
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) return false;
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
    public bool IsPalindrome(string s) {
        int i = 0;
        int j = s.Length - 1;
        while (i < j) {
            while (i < j && !Char.IsLetterOrDigit(s[i])) {
                i++;
            }

            while (i < j && !Char.IsLetterOrDigit(s[j])) {
                j--;
            }

            if (char.ToLower(s[i]) != char.ToLower(s[j]))
                return false;
            i++;
            j--;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isPalindrome(s string) bool {
    i := 0
    j := len(s) - 1
    for i < j {
        for i < j && !isalnum(s[i]) {
            i++
        }
        for i < j && !isalnum(s[j]) {
            j--
        }
        if tolower(s[i]) != tolower(s[j]) {
            return false
        }
        i++
        j--
    }
    return true
}

func isalnum(c byte) bool {
    return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z')
}

func tolower(c byte) byte {
    if 'A' <= c && c <= 'Z' {
        return c - 'A' + 'a'
    }
    return c
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isPalindrome(String s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            while (i < j && !Character.isLetterOrDigit(s.charAt(i))) {
                i++;
            }
            while (i < j && !Character.isLetterOrDigit(s.charAt(j))) {
                j--;
            }

            if (
                Character.toLowerCase(s.charAt(i)) !=
                Character.toLowerCase(s.charAt(j))
            ) return false;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isPalindrome = function (s) {
    let i = 0;
    let j = s.length - 1;
    while (i < j) {
        while (i < j && !isLetterOrDigit(s[i])) {
            i++;
        }
        while (i < j && !isLetterOrDigit(s[j])) {
            j--;
        }
        if ((s[i] + "").toLowerCase() !== (s[j] + "").toLowerCase())
            return false;
        i++;
        j--;
    }
    return true;
};
function isLetterOrDigit(character) {
    const charCode = character.charCodeAt();
    return (
        (charCode >= "a".charCodeAt() && charCode <= "z".charCodeAt()) ||
        (charCode >= "A".charCodeAt() && charCode <= "Z".charCodeAt()) ||
        (charCode >= "0".charCodeAt() && charCode <= "9".charCodeAt())
    );
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:

        i, j = 0, len(s) - 1

        while i < j:
            while i < j and not s[i].isalnum():
                i += 1
            while i < j and not s[j].isalnum():
                j -= 1

            if s[i].lower() != s[j].lower():
                return False

            i += 1
            j -= 1

        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isPalindrome(s: string) {
    let i = 0;
    let j = s.length - 1;
    while (i < j) {
        while (i < j && !isLetterOrDigit(s.charAt(i))) {
            i++;
        }
        while (i < j && !isLetterOrDigit(s.charAt(j))) {
            j--;
        }
        if (
            (s.charAt(i) + "").toLowerCase() !==
            (s.charAt(j) + "").toLowerCase()
        )
            return false;
        i++;
        j--;
    }
    return true;
}
function isLetterOrDigit(character: string) {
    const charCode = character.charCodeAt(0);
    return (
        (charCode >= "a".charCodeAt(0) && charCode <= "z".charCodeAt(0)) ||
        (charCode >= "A".charCodeAt(0) && charCode <= "Z".charCodeAt(0)) ||
        (charCode >= "0".charCodeAt(0) && charCode <= "9".charCodeAt(0))
    );
}
```

</details>
