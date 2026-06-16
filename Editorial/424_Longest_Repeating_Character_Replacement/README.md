# 424. Longest Repeating Character Replacement

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-repeating-character-replacement/)  
`Hash Table` `String` `Sliding Window`

**Problem Link:** [LeetCode 424 - Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)

## Problem

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

### Example 1

```text
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
```

### Example 2

```text
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
```

## Constraints

- 1 <= s.length <= 105
- s consists of only uppercase English letters.
- 0 <= k <= s.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Number of Operations to Make Array Continuous](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 424. Longest Repeating Character Replacement

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window + Binary Search | Java, JavaScript, Python3 |
| Sliding Window (Slow) | Java, JavaScript, Python3 |
| Sliding Window (Fast) | Java, JavaScript, Python3 |

## Approach 1: Sliding Window + Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int characterReplacement(String s, int k) {
        // binary search over the length of substring
        // lo contains the valid value, and hi contains the
        // invalid value
        int lo = 1;
        int hi = s.length() + 1;

        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;

            // can we make a valid substring of length `mid`?
            if (canMakeValidSubstring(s, mid, k)) {
                // explore the right half
                lo = mid;
            } else {
                // explore the left half
                hi = mid;
            }
        }

        // length of the longest substring that satisfies
        // the given condition
        return lo;
    }

    private Boolean canMakeValidSubstring(
            String s,
            int substringLength,
            int k) {
        // take a window of length `substringLength` on the given
        // string, and move it from left to right. If this window
        // satisfies the condition of a valid string, then we return
        // true

        int[] freqMap = new int[26];
        int maxFrequency = 0;
        int start = 0;
        for (int end = 0; end < s.length(); end += 1) {
            freqMap[s.charAt(end) - 'A'] += 1;

            // if the window [start, end] exceeds substringLength
            // then move the start pointer one step toward right
            if (end + 1 - start > substringLength) {
                // before moving the pointer toward right, decrease
                // the frequency of the corresponding character
                freqMap[s.charAt(start) - 'A'] -= 1;
                start += 1;
            }

            // record the maximum frequency seen so far
            maxFrequency = Math.max(maxFrequency, freqMap[s.charAt(end) - 'A']);
            if (substringLength - maxFrequency <= k) {
                return true;
            }
        }

        // we didn't a valid substring of the given size
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript

function characterReplacement(s, k) {
    // binary search over the length of substring
    // lo contains the valid value, and hi contains the
    // invalid value
    let lo = 1,
        hi = s.length + 1;
    while (lo + 1 < hi) {
        let mid = lo + Math.floor((hi - lo) / 2);

        // can we make a valid substring of length `mid`?
        if (canMakeValidSubstring(s, mid, k)) {
            // explore the right half
            lo = mid;
        } else {
            // explore the left half
            hi = mid;
        }
    }

    // length of the longest substring that satisfies
    // the given condition
    return lo;
}

function canMakeValidSubstring(s, substringLength, k) {
    // take a window of length `substringLength` on the given
    // string, and move it from left to right. If this window
    // satisfies the condition of a valid string, then we return
    // true
    let freqMap = {};
    let maxFrequency = 0;
    let start = 0;
    for (let end = 0; end < s.length; end += 1) {
        freqMap[s[end]] ||= 0;
        freqMap[s[end]] += 1;

        // if the window [start, end] exceeds substringLength
        // then move the start pointer one step toward right
        if (end + 1 - start > substringLength) {
            // before moving the pointer toward right, decrease
            // the frequency of the corresponding character
            freqMap[s[start]] -= 1;
            start += 1;
        }

        // record the maximum frequency seen so far
        maxFrequency = Math.max(maxFrequency, freqMap[s[end]]);
        if (substringLength - maxFrequency <= k) {
            return true;
        }
    }

    // we didn't a valid substring of the given size
    return false;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # binary search over the length of substring
        # lo contains the valid value, and hi contains the
        # invalid value
        lo = 1
        hi = len(s) + 1
        while lo + 1 < hi:
            mid = lo + (hi - lo) // 2

            # can we make a valid substring of length `mid`?
            if self.__can_make_valid_substring(s, mid, k):
                # explore the right half
                lo = mid
            else:
                # explore the left half
                hi = mid

        # length of the longest substring that satisfies
        # the given condition
        return lo

    def __can_make_valid_substring(self, s: str, substring_length: int, k: int):
        # take a window of length `substring_length` on the given
        # string, and move it from left to right. If this window
        # satisfies the condition of a valid string, then we return
        # true
        freq_map = {}
        max_frequency = 0
        start = 0
        for end in range(len(s)):
            freq_map[s[end]] = freq_map.get(s[end], 0) + 1

            # if the window [start, end] exceeds substring_length
            # then move the start pointer one step toward right
            if end + 1 - start > substring_length:
                # before moving the pointer toward right, decrease
                # the frequency of the corresponding character
                freq_map[s[start]] -= 1
                start += 1

            # record the maximum frequency seen so far
            max_frequency = max(max_frequency, freq_map[s[end]])
            if substring_length - max_frequency <= k:
                return True

        # we didn't a valid substring of the given size
        return False
```

</details>

<br>

## Approach 2: Sliding Window (Slow)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int characterReplacement(String s, int k) {
        HashSet<Character> allLetters = new HashSet();

        // collect all unique letters
        for (int i = 0; i < s.length(); i++) {
            allLetters.add(s.charAt(i));
        }

        int maxLength = 0;
        for (Character letter : allLetters) {
            int start = 0;
            int count = 0;
            // initialize a sliding window for each unique letter
            for (int end = 0; end < s.length(); end += 1) {
                if (s.charAt(end) == letter) {
                    // if the letter matches, increase the count
                    count += 1;
                }
                // bring start forward until the window is valid again
                while (!isWindowValid(start, end, count, k)) {
                    if (s.charAt(start) == letter) {
                        // if the letter matches, decrease the count
                        count -= 1;
                    }
                    start += 1;
                }
                // at this point the window is valid, update maxLength
                maxLength = Math.max(maxLength, end + 1 - start);
            }
        }
        return maxLength;
    }

    private Boolean isWindowValid(int start, int end, int count, int k) {
        return end + 1 - start - count <= k;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript

function characterReplacement(s, k) {
    let allLetters = new Set();
    // collect all unique letters
    for (let char of s) {
        allLetters.add(char);
    }
    let maxLength = 0;
    // iterate over each unique letter
    for (let letter of allLetters) {
        let start = 0,
            count = 0;
        // initialize a sliding window for each unique letter
        for (let end = 0; end < s.length; end += 1) {
            if (s[end] === letter) {
                // if the letter matches, increase the count
                count += 1;
            }
            // bring start forward until the window is valid again
            while (!isWindowValid(start, end, count, k)) {
                if (s[start] === letter) {
                    // if the letter matches, decrease the count
                    count -= 1;
                }
                start += 1;
            }
            // at this point the window is valid, update maxLength
            maxLength = Math.max(maxLength, end + 1 - start);
        }
    }
    return maxLength;
}

function isWindowValid(start, end, charFrequency, maxReplacements) {
    return end + 1 - start - charFrequency <= maxReplacements;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        all_letters = set(s)
        max_length = 0

        # iterate over each unique letter
        for letter in all_letters:
            start = 0
            count = 0

            # initialize a sliding window for each unique letter
            for end in range(len(s)):
                if s[end] == letter:
                    # if the letter matches, increase the count
                    count += 1

                # bring start forward until the window is valid again
                while not self.__is_window_valid(start, end, count, k):
                    if s[start] == letter:
                        # if the letter matches, decrease the count
                        count -= 1
                    start += 1

                # at this point the window is valid, update max_length
                max_length = max(max_length, end + 1 - start)

        return max_length

    def __is_window_valid(self, start: int, end: int, count: int, k: int):
        return end + 1 - start - count <= k
```

</details>

<br>

## Approach 3: Sliding Window (Fast)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int characterReplacement(String s, int k) {
        int start = 0;
        int[] frequencyMap = new int[26];
        int maxFrequency = 0;
        int longestSubstringLength = 0;

        for (int end = 0; end < s.length(); end += 1) {
            // if 'A' is 0, then what is the relative order
            // or offset of the current character entering the window
            // 0 is 'A', 1 is 'B' and so on
            int currentChar = s.charAt(end) - 'A';

            frequencyMap[currentChar] += 1;

            // the maximum frequency we have seen in any window yet
            maxFrequency = Math.max(maxFrequency, frequencyMap[currentChar]);

            // move the start pointer towards right if the current
            // window is invalid
            Boolean isValid = (end + 1 - start - maxFrequency <= k);
            if (!isValid) {
                // offset of the character moving out of the window
                int outgoingChar = s.charAt(start) - 'A';

                // decrease its frequency
                frequencyMap[outgoingChar] -= 1;

                // move the start pointer forward
                start += 1;
            }

            // the window is valid at this point, note down the length
            // size of the window never decreases
            longestSubstringLength = end + 1 - start;
        }

        return longestSubstringLength;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript

function characterReplacement(s, k) {
    let start = 0;
    let frequencyMap = {};
    let maxFrequency = 0;
    let longestSubstringLength = 0;
    for (let end = 0; end < s.length; end += 1) {
        frequencyMap[s[end]] ||= 0;
        frequencyMap[s[end]] += 1;

        // the maximum frequency we have seen in any window yet
        maxFrequency = Math.max(maxFrequency, frequencyMap[s[end]]);

        // move the start pointer towards right if the current
        // window is invalid
        const isValid = (end + 1 - start - maxFrequency <= k);
        if (!isValid) {
            frequencyMap[s[start]] -= 1;
            start += 1;
        }
        
        // the window is valid at this point, store length
        // size of the window never decreases
        longestSubstringLength = end + 1 - start;
    }
    return longestSubstringLength;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        start = 0
        frequency_map = {}
        max_frequency = 0
        longest_substring_length = 0
        for end in range(len(s)):
            frequency_map[s[end]] = frequency_map.get(s[end], 0) + 1

            # the maximum frequency we have seen in any window yet
            max_frequency = max(max_frequency, frequency_map[s[end]])

            # move the start pointer towards right if the current
            # window is invalid
            is_valid = (end + 1 - start - max_frequency <= k)
            if not is_valid:
                frequency_map[s[start]] -= 1
                start += 1

            # the window is valid at this point, store length
            # size of the window never decreases
            longest_substring_length = end + 1 - start

        return longest_substring_length
```

</details>
