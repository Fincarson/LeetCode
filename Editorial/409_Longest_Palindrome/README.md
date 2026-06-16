# 409. Longest Palindrome

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/longest-palindrome/)  
`Hash Table` `String` `Greedy`

**Problem Link:** [LeetCode 409 - Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)

## Problem

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

### Example 1

```text
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
```

### Example 2

```text
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
```

## Constraints

- 1 <= s.length <= 2000
- s consists of lowercase and/or uppercase English letters only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Longest Palindrome by Concatenating Two Letter Words](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Largest Palindromic Number](https://leetcode.com/problems/largest-palindromic-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 409. Longest Palindrome

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy Way (Hash Table) | C++, Java, Python3 |
| Greedy Way (Optimized) | C++, Java, Python3 |
| Greedy Way (Hash Set) | C++, Java, Python3 |

## Approach 1: Greedy Way (Hash Table)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        // Map to store frequency of occurrence of each character
        unordered_map<char, int> frequencyMap;
        // Count frequencies
        for (char c : s) {
            frequencyMap[c]++;
        }

        int res = 0;
        bool hasOddFrequency = false;
        for (auto& entry : frequencyMap) {
            int freq = entry.second;
            // Check if the frequency is even
            if (freq % 2 == 0) {
                res += freq;
            } else {
                // If the frequency is odd, one occurrence of the
                // character will remain without a match
                res += freq - 1;
                hasOddFrequency = true;
            }
        }
        // If hasOddFrequency is true, we have at least one unmatched
        // character to make the center of an odd length palindrome.
        if (hasOddFrequency) return res + 1;

        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestPalindrome(String s) {
        // Map to store frequency of occurrence of each character
        Map<Character, Integer> frequencyMap = new HashMap<>();
        // Count frequencies
        for (char c : s.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        int res = 0;
        boolean hasOddFrequency = false;
        for (int freq : frequencyMap.values()) {
            // Check is the frequency is even
            if ((freq % 2) == 0) {
                res += freq;
            } else {
                // If the frequency is odd, one occurrence of the
                // character will remain without a match
                res += freq - 1;
                hasOddFrequency = true;
            }
        }
        // If hasOddFrequency is true, we have at least one unmatched
        // character to make the center of an odd length palindrome.
        if (hasOddFrequency) return res + 1;

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        # Dictionary to store frequency of occurrence of each character
        frequency_map = {}
        # Count frequencies
        for c in s:
            frequency_map[c] = frequency_map.get(c, 0) + 1

        res = 0
        has_odd_frequency = False
        for freq in frequency_map.values():
            # Check if the frequency is even
            if (freq % 2) == 0:
                res += freq
            else:
                # If the frequency is odd, one occurrence of the
                # character will remain without a match
                res += freq - 1
                has_odd_frequency = True

        # If has_odd_frequency is true, we have at least one unmatched
        # character to make the center of an odd length palindrome.
        if has_odd_frequency:
            return res + 1

        return res
```

</details>

<br>

## Approach 2: Greedy Way (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int oddFreqCharsCount = 0;
        unordered_map<char, int> frequencyMap;

        // Loop over the string
        for (char c : s) {
            // Update count of current character
            frequencyMap[c]++;

            // If the current freq of the character is odd,
            // increment oddCount
            if ((frequencyMap[c] % 2) == 1) {
                oddFreqCharsCount++;
            } else {
                oddFreqCharsCount--;
            }
        }

        // If there are characters with odd frequencies, we are
        // guaranteed to have at least one letter left unmatched,
        // which can make the center of an odd length palindrome.
        if (oddFreqCharsCount > 0) {
            return s.length() - oddFreqCharsCount + 1;
        } else {
            return s.length();
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestPalindrome(String s) {
        int oddFreqCharsCount = 0;
        Map<Character, Integer> frequencyMap = new HashMap<>();

        // Loop over the string
        for (char c : s.toCharArray()) {
            // Update count of current character
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);

            // If the current freq of the character is odd,
            // increment oddCount
            if ((frequencyMap.get(c) % 2) == 1) {
                oddFreqCharsCount++;
            } else {
                oddFreqCharsCount--;
            }
        }

        // If there are characters with odd frequencies, we are
        // guaranteed to have at least one letter left unmatched,
        // which can make the center of an odd length palindrome.
        if (oddFreqCharsCount > 0) {
            return s.length() - oddFreqCharsCount + 1;
        } else {
            return s.length();
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        odd_freq_chars_count = 0
        frequency_map = {}

        # Loop over the string
        for c in s:
            # Update count of current character
            frequency_map[c] = frequency_map.get(c, 0) + 1

            # If the current frequency of the character is odd,
            # increment odd_freq_chars_count
            if frequency_map[c] % 2 == 1:
                odd_freq_chars_count += 1
            else:
                odd_freq_chars_count -= 1

        # If there are characters with odd frequencies, we are
        # guaranteed to have at least one letter left unmatched,
        # which can make the center of an odd length palindrome.
        if odd_freq_chars_count > 0:
            return len(s) - odd_freq_chars_count + 1
        else:
            return len(s)
```

</details>

<br>

## Approach 3: Greedy Way (Hash Set)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> characterSet;
        int res = 0;

        // Loop over characters in the string
        for (char c : s) {
            // If set contains the character, match found
            if (characterSet.find(c) != characterSet.end()) {
                characterSet.erase(c);
                // add the two occurrences to our palindrome
                res += 2;
            } else {
                // add the character to the set
                characterSet.insert(c);
            }
        }

        // if any character remains, we have at least one unmatched
        // character to make the center of an odd length palindrome.
        if (!characterSet.empty()) {
            res++;
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestPalindrome(String s) {
        Set<Character> characterSet = new HashSet<>();
        int res = 0;

        // Loop over characters in the string
        for (char c : s.toCharArray()) {
            // If set contains the character, match found
            if (characterSet.contains(c)) {
                characterSet.remove(c);
                // add the two occurrences to our palindrome
                res += 2;
            } else {
                // add the character to the set
                characterSet.add(c);
            }
        }

        // if any character remains, we have at least one unmatched
        // character to make the center of an odd length palindrome.
        if (!characterSet.isEmpty()) res++;

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        character_set = set()
        res = 0

        # Loop over characters in the string
        for c in s:
            # If set contains the character, match found
            if c in character_set:
                character_set.remove(c)
                # Add the two occurrences to our palindrome
                res += 2
            else:
                # Add the character to the set
                character_set.add(c)

        # If any character remains, we have at least one unmatched
        # character to make the center of an odd length palindrome.
        if character_set:
            res += 1

        return res
```

</details>
