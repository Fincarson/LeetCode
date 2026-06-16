# 1100. Find K-Length Substrings With No Repeated Characters

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/)  
`Hash Table` `String` `Sliding Window`

**Problem Link:** [LeetCode 1100 - Find K-Length Substrings With No Repeated Characters](https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/)

## Problem

Given a string s and an integer k, return the number of substrings in s of length k with no repeated characters.

### Example 1

```text
Input: s = "havefunonleetcode", k = 5
Output: 6
Explanation: There are 6 substrings they are: 'havef','avefu','vefun','efuno','etcod','tcode'.
```

### Example 2

```text
Input: s = "home", k = 5
Output: 0
Explanation: Notice k can be larger than the length of s. In this case, it is not possible to find any substring.
```

## Constraints

- 1 <= s.length <= 104
- s consists of lowercase English letters.
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

# Editorial - 1100. Find K-Length Substrings With No Repeated Characters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k > 26) return 0;

        int answer = 0;
        int n = s.size();

        for (int i = 0; i <= n - k; i++) {
            // Initializing an empty frequency array
            int freq[26] = {0};
            bool isUnique = true;

            for (int j = i; j < i + k; j++) {
                // Incrementing the frequency of current character
                freq[s[j] - 'a']++;

                // If a repeated character is found, we stop the loop
                if (freq[s[j] - 'a'] > 1) {
                    isUnique = false;
                    break;
                }
            }

            // If the substring does not have any repeated characters,
            // we increment the answer
            if (isUnique) {
                answer++;
            }
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numKLenSubstrNoRepeats(String s, int k) {
        if (k > 26) return 0;
        int n = s.length();
        int answer = 0;

        for (int i = 0; i <= n - k; i++) {
            // Initializing an empty frequency array
            int freq[] = new int[26];
            boolean isUnique = true;

            for (int j = i; j < i + k; j++) {
                char ch = s.charAt(j);

                // Incrementing the frequency of current character
                freq[ch - 'a']++;

                // If a repeated character is found, we stop the loop
                if (freq[ch - 'a'] > 1) {
                    isUnique = false;
                    break;
                }
            }

            // If the substring does not have any repeated characters,
            // we increment the answer
            if (isUnique) {
                answer++;
            }
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        if k > 26:
            return 0
        answer = 0
        n = len(s)

        for i in range(n - k + 1):
            # Initializing an empty frequency array
            freq = [0] * 26

            for j in range(i, i + k):
                curr_char = ord(s[j]) - ord("a")

                # Incrementing the frequency of current character
                freq[curr_char] += 1

                # If a repeated character is found, we stop the loop
                if freq[curr_char] > 1:
                    break
            else:
                # If the substring does not have any repeated characters,
                # we increment the answer
                answer += 1

        return answer
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        // We can reuse the condition from the first approach
        // as for k > 26, there can be no substrings with only unique characters
        if (k > 26) return 0;

        int answer = 0;
        int n = s.size();

        // Initializing the left and right pointers
        int left = 0, right = 0;
        // Initializing an empty frequency array
        int freq[26] = {0};

        while (right < n) {
            // Add the current character in the frequency array
            freq[s[right] - 'a']++;

            // If the current character appears more than once in the frequency
            // array keep contracting the window and removing characters from
            // the frequency array till the frequency of the current character
            // becomes 1.
            while (freq[s[right] - 'a'] > 1) {
                freq[s[left] - 'a']--;
                left++;
            }

            // Check if the length of the current unique substring is equal to k
            if (right - left + 1 == k) {
                answer++;

                // Contract the window and remove the leftmost character from
                // the frequency array
                freq[s[left] - 'a']--;
                left++;
            }

            // Expand the window
            right++;
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numKLenSubstrNoRepeats(String s, int k) {
        // We can reuse the condition from the first approach
        // as for k > 26, there can be no substrings with only unique characters
        if (k > 26) return 0;

        int answer = 0;
        int n = s.length();

        // Initializing the left and right pointers
        int left = 0, right = 0;
        // Initializing an empty frequency array
        int freq[] = new int[26];

        while (right < n) {
            // Add the current character in the frequency array
            freq[s.charAt(right) - 'a']++;

            // If the current character appears more than once in the frequency array
            // keep contracting the window and removing characters from the
            // frequency array till the frequency of the current character becomes 1.
            while (freq[s.charAt(right) - 'a'] > 1) {
                freq[s.charAt(left) - 'a']--;
                left++;
            }

            // Check if the length of the current unique substring is equal to k
            if (right - left + 1 == k) {
                answer++;

                // Contract the window and remove the leftmost character from the
                // frequency array
                freq[s.charAt(left) - 'a']--;
                left++;
            }

            // Expand the window
            right++;
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        # We can reuse the condition from the first approach
        # as for k > 26, there can be no substrings with only unique characters
        if k > 26:
            return 0
        answer = 0
        n = len(s)

        # Initializing the left and right pointers
        left = right = 0

        # Initializing an empty frequency array
        freq = [0] * 26

        # Function to obtain the index of a character according to the alphabet
        def get_val(ch: str) -> int:
            return ord(ch) - ord("a")

        while right < n:

            # Add the current character in the frequency array
            freq[get_val(s[right])] += 1

            # If the current character appears more than once in the frequency array
            # keep contracting the window and removing characters from the
            # frequency array till the frequency of the current character becomes 1.
            while freq[get_val(s[right])] > 1:
                freq[get_val(s[left])] -= 1
                left += 1

            # Check if the length of the current unique substring is equal to k
            if right - left + 1 == k:
                answer += 1

                # Contract the window and remove the leftmost character from the
                # frequency array
                freq[get_val(s[left])] -= 1
                left += 1

            # Expand the window
            right += 1

        return answer
```

</details>
