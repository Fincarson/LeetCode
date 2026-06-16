# 2981. Find Longest Special Substring That Occurs Thrice I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/)  
`Hash Table` `String` `Binary Search` `Sliding Window` `Counting`

**Problem Link:** [LeetCode 2981 - Find Longest Special Substring That Occurs Thrice I](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/)

## Problem

You are given a string s that consists of lowercase English letters.

A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.

A substring is a contiguous non-empty sequence of characters within a string.

### Example 1

```text
Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
It can be shown that the maximum length achievable is 2.
```

### Example 2

```text
Input: s = "abcdef"
Output: -1
Explanation: There exists no special substring which occurs at least thrice. Hence return -1.
```

### Example 3

```text
Input: s = "abcaba"
Output: 1
Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
It can be shown that the maximum length achievable is 1.
```

## Constraints

- 3 <= s.length <= 50
- s consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2981. Find Longest Special Substring That Occurs Thrice I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute-Force Approach | C++, Java, Python3 |
| Optimized Hashing | C++, Java, Python3 |

## Approach 1: Brute-Force Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumLength(string s) {
        // Create a map of strings to store the count of all substrings.
        map<string, int> count;
        for (int start = 0; start < s.length(); start++) {
            string currString;
            for (int end = start; end < s.length(); end++) {
                // If the string is empty, or the current character is equal to
                // the previously added character, then add it to the map.
                // Otherwise, break the iteration.
                if (currString.empty() or currString.back() == s[end]) {
                    currString.push_back(s[end]);
                    count[currString]++;
                } else {
                    break;
                }
            }
        }

        // Create a variable ans to store the longest length of substring with
        // frequency atleast 3.
        int ans = 0;
        for (auto i : count) {
            string str = i.first;
            if (i.second >= 3 && str.length() > ans) ans = str.length();
        }
        if (ans == 0) return -1;
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumLength(String s) {
        // Create a HashMap to store the count of all substrings
        HashMap<String, Integer> count = new HashMap<>();

        // Iterate through the string to create substrings
        for (int start = 0; start < s.length(); start++) {
            StringBuilder currString = new StringBuilder();

            for (int end = start; end < s.length(); end++) {
                // If the string is empty, or the current character is equal to
                // the previously added character, then add it to the HashMap.
                // Otherwise, break the iteration.
                if (
                    currString.length() == 0 ||
                    currString.charAt(currString.length() - 1) == s.charAt(end)
                ) {
                    currString.append(s.charAt(end)); // Use append instead of concatenation
                    count.put(
                        currString.toString(),
                        count.getOrDefault(currString.toString(), 0) + 1
                    );
                } else {
                    break;
                }
            }
        }

        // Create a variable ans to store the longest length of substring with
        // frequency at least 3.
        int ans = 0;
        for (String str : count.keySet()) {
            if (count.get(str) >= 3 && str.length() > ans) ans = str.length();
        }

        if (ans == 0) return -1;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumLength(self, s: str) -> int:
        # Create a dictionary (equivalent of map in Python) to store the count of all substrings
        count = {}
        for start in range(len(s)):
            curr_string = (
                []
            )  # Use a list to store the characters of the current substring
            for end in range(start, len(s)):
                # If the string is empty, or the current character is equal to
                # the previously added character, then append it to the list.
                # Otherwise, break the iteration.
                if not curr_string or curr_string[-1] == s[end]:
                    curr_string.append(s[end])
                    curr_to_string = "".join(
                        curr_string
                    )  # Convert the list to a string
                    if curr_to_string in count:
                        count[curr_to_string] += 1
                    else:
                        count[curr_to_string] = 1
                else:
                    break

        # Create a variable ans to store the longest length of substring with
        # frequency at least 3.
        ans = 0
        for str, freq in count.items():
            if freq >= 3 and len(str) > ans:
                ans = len(str)

        if ans == 0:
            return -1
        return ans
```

</details>

<br>

## Approach 2: Optimized Hashing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumLength(string s) {
        // Create a map of strings to store the count of all substrings.
        map<pair<char, int>, int> count;
        int substringLength = 0;
        for (int start = 0; start < s.length(); start++) {
            char character = s[start];
            substringLength = 0;
            for (int end = start; end < s.length(); end++) {
                // If the string is empty, or the current character is equal to
                // the previously added character, then add it to the map.
                // Otherwise, break the iteration.
                if (character == s[end]) {
                    substringLength++;
                    count[{character, substringLength}]++;
                } else {
                    break;
                }
            }
        }

        // Create a variable ans to store the longest length of substring with
        // frequency atleast 3.
        int ans = -1;
        for (auto i : count) {
            int len = i.first.second;
            if (i.second >= 3 && len > ans) ans = len;
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

    public int maximumLength(String s) {
        // Create a map to store the count of all substrings
        Map<Pair<Character, Integer>, Integer> count = new HashMap<>();
        int substringLength = 0;

        for (int start = 0; start < s.length(); start++) {
            char character = s.charAt(start);
            substringLength = 0;

            for (int end = start; end < s.length(); end++) {
                // If the current character matches the initial character, increment the count
                if (character == s.charAt(end)) {
                    substringLength++;
                    Pair<Character, Integer> key = new Pair<>(
                        character,
                        substringLength
                    );
                    count.put(key, count.getOrDefault(key, 0) + 1);
                } else {
                    break;
                }
            }
        }

        // Variable to store the longest substring length with frequency at least 3
        int ans = -1;
        for (Map.Entry<
            Pair<Character, Integer>,
            Integer
        > entry : count.entrySet()) {
            int length = entry.getKey().getValue();
            if (entry.getValue() >= 3 && length > ans) {
                ans = length;
            }
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
    def maximumLength(self, s: str) -> int:
        # Create a dictionary to store the count of all substrings.
        count = {}
        for start in range(len(s)):
            character = s[start]
            substring_length = 0
            for end in range(start, len(s)):
                # If the string is empty, or the current character is equal to
                # the previously added character, then add it to the map.
                # Otherwise, break the iteration.
                if character == s[end]:
                    substring_length += 1
                    count[(character, substring_length)] = (
                        count.get((character, substring_length), 0) + 1
                    )
                else:
                    break

        # Create a variable ans to store the longest length of substring with
        # frequency atleast 3.
        ans = -1
        for i in count.items():
            length = i[0][1]
            if i[1] >= 3 and length > ans:
                ans = length

        return ans
```

</details>
