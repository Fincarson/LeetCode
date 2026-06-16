# 1400. Construct K Palindrome Strings

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/construct-k-palindrome-strings/)  
`Hash Table` `String` `Greedy` `Counting`

**Problem Link:** [LeetCode 1400 - Construct K Palindrome Strings](https://leetcode.com/problems/construct-k-palindrome-strings/)

## Problem

Given a string s and an integer k, return true if you can use all the characters in s to construct non-empty k palindrome strings or false otherwise.

### Example 1

```text
Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
```

### Example 2

```text
Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
```

### Example 3

```text
Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
```

## Constraints

- 1 <= s.length <= 105
- s consists of lowercase English letters.
- 1 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1400. Construct K Palindrome Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count Odd Frequencies | C++, Java, Python3 |
| Bit Manipulation | C++, Java, Python3 |

## Approach 1: Count Odd Frequencies

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canConstruct(string s, int k) {
        // Handle edge cases
        if (s.length() < k) return false;
        if (s.length() == k) return true;

        // Initialize frequency array and oddCount integer
        vector<int> freq(26);
        int oddCount = 0;

        // Increment the value of the index corresponding to the current
        // character
        for (auto& chr : s) freq[chr - 'a']++;

        // Count the number of characters that appear an odd number of times in
        // s
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
            }
        }

        // Return if the number of odd frequencies is less than or equal to k
        return (oddCount <= k);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canConstruct(String s, int k) {
        // Handle edge cases
        if (s.length() < k) return false;
        if (s.length() == k) return true;

        // Initialize frequency array and oddCount
        int[] freq = new int[26];
        int oddCount = 0;

        // Increment the value of the index corresponding to the current character
        for (char chr : s.toCharArray()) {
            freq[chr - 'a']++;
        }

        // Count the number of characters that appear an odd number of times in s
        for (int count : freq) {
            if (count % 2 == 1) {
                oddCount++;
            }
        }

        // Return if the number of odd frequencies is less than or equal to k
        return oddCount <= k;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        # Handle edge cases
        if len(s) < k:
            return False
        if len(s) == k:
            return True
        # Initialize frequency dictionary and odd_count
        freq = [0] * 26
        odd_count = 0

        # Increment the value of the index corresponding to the current character
        for char in s:
            freq[ord(char) - ord("a")] += 1
        # Count the number of characters that appear an odd number of times in s
        for count in freq:
            if count % 2 == 1:
                odd_count += 1
        # Return if the number of odd frequencies is less than or equal to k
        return odd_count <= k
```

</details>

<br>

## Approach 2: Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canConstruct(string s, int k) {
        // Handle edge cases
        if (s.length() < k) return false;
        if (s.length() == k) return true;

        // Initialize oddCount as an integer bitmask
        int oddCount = 0;

        // Update the bitmask for each character in the string
        for (char chr : s) {
            oddCount ^= 1 << (chr - 'a');
        }

        // Count the number of set bits in the bitmask
        int setBits = __builtin_popcount(oddCount);

        // Return if the number of odd frequencies is less than or equal to k
        return setBits <= k;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canConstruct(String s, int k) {
        // Handle edge cases
        if (s.length() < k) return false;
        if (s.length() == k) return true;

        // Initialize oddCount as an integer bitmask
        int oddCount = 0;

        // Update the bitmask for each character in the string
        for (char chr : s.toCharArray()) {
            oddCount ^= 1 << (chr - 'a');
        }

        // Return if the number of odd frequencies is less than or equal to k
        return Integer.bitCount(oddCount) <= k;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        # Handle edge cases
        if len(s) < k:
            return False
        if len(s) == k:
            return True
        # Initialize oddCount as an integer bitmask
        odd_count = 0

        # Update the bitmask for each character in the string
        for chr in s:
            odd_count ^= 1 << (ord(chr) - ord("a"))
        # Return if the number of odd frequencies is less than or equal to
        return bin(odd_count).count("1") <= k
```

</details>
