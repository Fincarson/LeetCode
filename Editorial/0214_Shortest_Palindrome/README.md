# 214. Shortest Palindrome

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/shortest-palindrome/)  
`String` `Rolling Hash` `String Matching` `Hash Function`

**Problem Link:** [LeetCode 214 - Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/)

## Problem

You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

### Example 1

```text
Input: s = "aacecaaa"
Output: "aaacecaaa"
```

### Example 2

```text
Input: s = "abcd"
Output: "dcbabcd"
```

## Constraints

- 0 <= s.length <= 5 * 104
- s consists of lowercase English letters only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Deletions on a String](https://leetcode.com/problems/maximum-deletions-on-a-string/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Smallest Palindromic Rearrangement I](https://leetcode.com/problems/smallest-palindromic-rearrangement-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 214. Shortest Palindrome

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |
| KMP (Knuth-Morris-Pratt) Algorithm | C++, Java, Python3 |
| Rolling Hash Based Algorithm | C++, Java, Python3 |
| Manacher's Algorithm | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        string reversedString = s;
        // Reverse the original string
        reverse(reversedString.begin(), reversedString.end());

        // Iterate through the string to find the longest palindromic prefix
        for (int i = 0; i < s.size(); ++i) {
            // memcmp to avoid creating substrings
            if (!memcmp(s.c_str(), reversedString.c_str() + i, s.size() - i)) {
                // Append the necessary part to make the palindrome
                return reversedString.substr(0, i) + s;
            }
        }
        // Fallback case, append the whole reversed string to the original
        // string
        return reversedString + s;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String shortestPalindrome(String s) {
        int length = s.length();
        String reversedString = new StringBuilder(s).reverse().toString();

        // Iterate through the string to find the longest palindromic prefix
        for (int i = 0; i < length; i++) {
            if (
                s.substring(0, length - i).equals(reversedString.substring(i))
            ) {
                return new StringBuilder(reversedString.substring(0, i))
                    .append(s)
                    .toString();
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
    def shortestPalindrome(self, s: str) -> str:
        length = len(s)
        reversed_string = s[::-1]  # Reverse the string

        # Iterate through the string to find the longest palindromic prefix
        for i in range(length):
            if s[: length - i] == reversed_string[i:]:
                return reversed_string[:i] + s
        return ""
```

</details>

<br>

## Approach 2: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.length();
        if (length == 0) {
            return s;
        }

        // Find the longest palindromic prefix
        int left = 0;
        for (int right = length - 1; right >= 0; right--) {
            if (s[right] == s[left]) {
                left++;
            }
        }

        // If the whole string is a palindrome, return the original string
        if (left == length) {
            return s;
        }

        // Extract the suffix that is not part of the palindromic prefix
        string nonPalindromeSuffix = s.substr(left);
        string reverseSuffix =
            string(nonPalindromeSuffix.rbegin(), nonPalindromeSuffix.rend());

        // Form the shortest palindrome by prepending the reversed suffix
        return reverseSuffix + shortestPalindrome(s.substr(0, left)) +
               nonPalindromeSuffix;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String shortestPalindrome(String s) {
        int length = s.length();
        if (length == 0) {
            return s;
        }

        // Find the longest palindromic prefix
        int left = 0;
        for (int right = length - 1; right >= 0; right--) {
            if (s.charAt(right) == s.charAt(left)) {
                left++;
            }
        }

        // If the whole string is a palindrome, return the original string
        if (left == length) {
            return s;
        }

        // Extract the suffix that is not part of the palindromic prefix
        String nonPalindromeSuffix = s.substring(left);
        StringBuilder reverseSuffix = new StringBuilder(
            nonPalindromeSuffix
        ).reverse();

        // Form the shortest palindrome by prepending the reversed suffix
        return reverseSuffix
            .append(shortestPalindrome(s.substring(0, left)))
            .append(nonPalindromeSuffix)
            .toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        length = len(s)
        if length == 0:
            return s

        # Find the longest palindromic prefix
        left = 0
        for right in range(length - 1, -1, -1):
            if s[right] == s[left]:
                left += 1

        # If the whole string is a palindrome, return the original string
        if left == length:
            return s

        # Extract the suffix that is not part of the palindromic prefix
        non_palindrome_suffix = s[left:]
        reverse_suffix = non_palindrome_suffix[::-1]

        # Form the shortest palindrome by prepending the reversed suffix
        return (
            reverse_suffix
            + self.shortestPalindrome(s[:left])
            + non_palindrome_suffix
        )
```

</details>

<br>

## Approach 3: KMP (Knuth-Morris-Pratt) Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        // Reverse the original string
        string reversedString = string(s.rbegin(), s.rend());

        // Combine the original and reversed strings with a separator
        string combinedString = s + "#" + reversedString;

        // Build the prefix table for the combined string
        vector<int> prefixTable = buildPrefixTable(combinedString);

        // Get the length of the longest palindromic prefix
        int palindromeLength = prefixTable[combinedString.length() - 1];

        // Construct the shortest palindrome by appending the reverse of the
        // suffix
        string suffix = reversedString.substr(0, s.length() - palindromeLength);
        return suffix + s;
    }

private:
    // Helper function to build the KMP prefix table
    vector<int> buildPrefixTable(const string& s) {
        vector<int> prefixTable(s.length(), 0);
        int length = 0;

        // Build the table by comparing characters
        for (int i = 1; i < s.length(); i++) {
            while (length > 0 && s[i] != s[length]) {
                length = prefixTable[length - 1];
            }
            if (s[i] == s[length]) {
                length++;
            }
            prefixTable[i] = length;
        }
        return prefixTable;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String shortestPalindrome(String s) {
        String reversedString = new StringBuilder(s).reverse().toString();
        String combinedString = s + "#" + reversedString;
        int[] prefixTable = buildPrefixTable(combinedString);

        int palindromeLength = prefixTable[combinedString.length() - 1];
        StringBuilder suffix = new StringBuilder(
            s.substring(palindromeLength)
        ).reverse();
        return suffix.append(s).toString();
    }

    private int[] buildPrefixTable(String s) {
        int[] prefixTable = new int[s.length()];
        int length = 0;
        for (int i = 1; i < s.length(); i++) {
            while (length > 0 && s.charAt(i) != s.charAt(length)) {
                length = prefixTable[length - 1];
            }
            if (s.charAt(i) == s.charAt(length)) {
                length++;
            }
            prefixTable[i] = length;
        }
        return prefixTable;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        # Reverse the original string
        reversed_string = s[::-1]

        # Combine the original and reversed strings with a separator
        combined_string = s + "#" + reversed_string

        # Build the prefix table for the combined string
        prefix_table = self._build_prefix_table(combined_string)

        # Get the length of the longest palindromic prefix
        palindrome_length = prefix_table[-1]

        # Construct the shortest palindrome by appending the reverse of the suffix
        suffix = reversed_string[: len(s) - palindrome_length]
        return suffix + s

    # Helper function to build the KMP prefix table
    def _build_prefix_table(self, s: str) -> list:
        prefix_table = [0] * len(s)
        length = 0

        # Build the table by comparing characters
        for i in range(1, len(s)):
            while length > 0 and s[i] != s[length]:
                length = prefix_table[length - 1]
            if s[i] == s[length]:
                length += 1
            prefix_table[i] = length
        return prefix_table
```

</details>

<br>

## Approach 4: Rolling Hash Based Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        long long hashBase = 29;
        long long modValue = 1e9 + 7;
        long long forwardHash = 0, reverseHash = 0, powerValue = 1;
        int palindromeEndIndex = -1;

        // Calculate rolling hashes and find the longest palindromic prefix
        for (int i = 0; i < s.length(); ++i) {
            char currentChar = s[i];

            // Update forward hash
            forwardHash =
                (forwardHash * hashBase + (currentChar - 'a' + 1)) % modValue;

            // Update reverse hash
            reverseHash =
                (reverseHash + (currentChar - 'a' + 1) * powerValue) % modValue;
            powerValue = (powerValue * hashBase) % modValue;

            // If forward and reverse hashes match, update palindrome end index
            if (forwardHash == reverseHash) {
                palindromeEndIndex = i;
            }
        }

        // Find the remaining suffix after the longest palindromic prefix
        string suffix = s.substr(palindromeEndIndex + 1);
        // Reverse the remaining suffix
        string reversedSuffix(suffix.rbegin(), suffix.rend());

        // Prepend the reversed suffix to the original string and return the
        // result
        return reversedSuffix + s;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String shortestPalindrome(String s) {
        long hashBase = 29;
        long modValue = (long) 1e9 + 7;
        long forwardHash = 0, reverseHash = 0, powerValue = 1;
        int palindromeEndIndex = -1;

        // Calculate rolling hashes and find the longest palindromic prefix
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);

            // Update forward hash
            forwardHash = (forwardHash * hashBase + (currentChar - 'a' + 1)) %
            modValue;

            // Update reverse hash
            reverseHash = (reverseHash + (currentChar - 'a' + 1) * powerValue) %
            modValue;
            powerValue = (powerValue * hashBase) % modValue;

            // If forward and reverse hashes match, update palindrome end index
            if (forwardHash == reverseHash) {
                palindromeEndIndex = i;
            }
        }

        // Find the remaining suffix after the longest palindromic prefix
        String suffix = s.substring(palindromeEndIndex + 1);
        // Reverse the remaining suffix
        StringBuilder reversedSuffix = new StringBuilder(suffix).reverse();

        // Prepend the reversed suffix to the original string and return the result
        return reversedSuffix.append(s).toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        hash_base = 29
        mod_value = int(1e9 + 7)
        forward_hash = 0
        reverse_hash = 0
        power_value = 1
        palindrome_end_index = -1

        # Calculate rolling hashes and find the longest palindromic prefix
        for i, current_char in enumerate(s):
            # Update forward hash
            forward_hash = (
                forward_hash * hash_base + (ord(current_char) - ord("a") + 1)
            ) % mod_value

            # Update reverse hash
            reverse_hash = (
                reverse_hash + (ord(current_char) - ord("a") + 1) * power_value
            ) % mod_value
            power_value = (power_value * hash_base) % mod_value

            # If forward and reverse hashes match, update palindrome end index
            if forward_hash == reverse_hash:
                palindrome_end_index = i

        # Find the remaining suffix after the longest palindromic prefix
        suffix = s[palindrome_end_index + 1 :]

        # Reverse the remaining suffix
        reversed_suffix = suffix[::-1]

        # Prepend the reversed suffix to the original string and return the result
        return reversed_suffix + s
```

</details>

<br>

## Approach 5: Manacher's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        // Return early if the string is null or empty
        if (s.empty()) {
            return s;
        }

        // Preprocess the string to handle palindromes uniformly
        string modifiedString = preprocessString(s);
        int n = modifiedString.size();
        vector<int> palindromeRadiusArray(n, 0);
        int center = 0, rightBoundary = 0;
        int maxPalindromeLength = 0;

        // Iterate through each character in the modified string
        for (int i = 1; i < n - 1; ++i) {
            int mirrorIndex = 2 * center - i;

            // Use previously computed values to avoid redundant calculations
            if (rightBoundary > i) {
                palindromeRadiusArray[i] =
                    min(rightBoundary - i, palindromeRadiusArray[mirrorIndex]);
            }

            // Expand around the current center while characters match
            while (modifiedString[i + 1 + palindromeRadiusArray[i]] ==
                   modifiedString[i - 1 - palindromeRadiusArray[i]]) {
                ++palindromeRadiusArray[i];
            }

            // Update the center and right boundary if the palindrome extends
            // beyond the current boundary
            if (i + palindromeRadiusArray[i] > rightBoundary) {
                center = i;
                rightBoundary = i + palindromeRadiusArray[i];
            }

            // Update the maximum length of palindrome starting at the
            // beginning
            if (i - palindromeRadiusArray[i] == 1) {
                maxPalindromeLength =
                    max(maxPalindromeLength, palindromeRadiusArray[i]);
            }
        }

        // Construct the shortest palindrome by reversing the suffix and
        // prepending it to the original string
        string suffix = s.substr(maxPalindromeLength);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }

private:
    string preprocessString(const string& s) {
        // Add boundaries and separators to handle palindromes uniformly
        string result = "^";
        for (char c : s) {
            result += "#" + string(1, c);
        }
        result += "#$";
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String shortestPalindrome(String s) {
        // Return early if the string is null or empty
        if (s == null || s.length() == 0) {
            return s;
        }

        // Preprocess the string to handle palindromes uniformly
        String modifiedString = preprocessString(s);
        int[] palindromeRadiusArray = new int[modifiedString.length()];
        int center = 0, rightBoundary = 0;
        int maxPalindromeLength = 0;

        // Iterate through each character in the modified string
        for (int i = 1; i < modifiedString.length() - 1; i++) {
            int mirrorIndex = 2 * center - i;

            // Use previously computed values to avoid redundant calculations
            if (rightBoundary > i) {
                palindromeRadiusArray[i] = Math.min(
                    rightBoundary - i,
                    palindromeRadiusArray[mirrorIndex]
                );
            }

            // Expand around the current center while characters match
            while (
                modifiedString.charAt(i + 1 + palindromeRadiusArray[i]) ==
                modifiedString.charAt(i - 1 - palindromeRadiusArray[i])
            ) {
                palindromeRadiusArray[i]++;
            }

            // Update the center and right boundary if the palindrome extends beyond the current boundary
            if (i + palindromeRadiusArray[i] > rightBoundary) {
                center = i;
                rightBoundary = i + palindromeRadiusArray[i];
            }

            // Update the maximum length of palindrome starting at the beginning
            if (i - palindromeRadiusArray[i] == 1) {
                maxPalindromeLength = Math.max(
                    maxPalindromeLength,
                    palindromeRadiusArray[i]
                );
            }
        }

        // Construct the shortest palindrome by reversing the suffix and prepending it to the original string
        StringBuilder suffix = new StringBuilder(
            s.substring(maxPalindromeLength)
        ).reverse();
        return suffix.append(s).toString();
    }

    private String preprocessString(String s) {
        // Add boundaries and separators to handle palindromes uniformly
        StringBuilder sb = new StringBuilder("^");
        for (char c : s.toCharArray()) {
            sb.append("#").append(c);
        }
        return sb.append("#$").toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        # Return early if the string is null or empty
        if not s:
            return s

        # Preprocess the string to handle palindromes uniformly
        modified_string = self._preprocess_string(s)
        n = len(modified_string)
        palindrome_radius_array = [0] * n
        center = 0
        right_boundary = 0
        max_palindrome_length = 0

        # Iterate through each character in the modified string
        for i in range(1, n - 1):
            mirror_index = 2 * center - i

            # Use previously computed values to avoid redundant calculations
            if right_boundary > i:
                palindrome_radius_array[i] = min(
                    right_boundary - i, palindrome_radius_array[mirror_index]
                )

            # Expand around the current center while characters match
            while (
                modified_string[i + 1 + palindrome_radius_array[i]]
                == modified_string[i - 1 - palindrome_radius_array[i]]
            ):
                palindrome_radius_array[i] += 1

            # Update the center and right boundary if the palindrome extends beyond the current boundary
            if i + palindrome_radius_array[i] > right_boundary:
                center = i
                right_boundary = i + palindrome_radius_array[i]

            # Update the maximum length of palindrome starting at the beginning
            if i - palindrome_radius_array[i] == 1:
                max_palindrome_length = max(
                    max_palindrome_length, palindrome_radius_array[i]
                )

        # Construct the shortest palindrome by reversing the suffix and prepending it to the original string
        suffix = s[max_palindrome_length:][::-1]
        return suffix + s

    def _preprocess_string(self, s: str) -> str:
        # Add boundaries and separators to handle palindromes uniformly
        return "^" + "#" + "#".join(s) + "#$"
```

</details>
