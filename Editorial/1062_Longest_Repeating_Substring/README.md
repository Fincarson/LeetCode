# 1062. Longest Repeating Substring

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-repeating-substring/)  
`String` `Binary Search` `Dynamic Programming` `Rolling Hash` `Suffix Array` `Hash Function`

**Problem Link:** [LeetCode 1062 - Longest Repeating Substring](https://leetcode.com/problems/longest-repeating-substring/)

## Problem

Given a string s, return the length of the longest repeating substrings. If no repeating substring exists, return 0.

### Example 1

```text
Input: s = "abcd"
Output: 0
Explanation: There is no repeating substring.
```

### Example 2

```text
Input: s = "abbaba"
Output: 2
Explanation: The longest repeating substrings are "ab" and "ba", each of which occurs twice.
```

### Example 3

```text
Input: s = "aabcaabdaab"
Output: 3
Explanation: The longest repeating substring is "aab", which occurs 3 times.
```

## Constraints

- 1 <= s.length <= 2000
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1062. Longest Repeating Substring

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force with Set | C++, Java, Python3 |
| Brute Force with Incremental Search | C++, Java, Python3 |
| Suffix Array with Sorting | C++, Java, Python3 |
| Binary Search with Set | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |
| MSD Radix Sort | C++, Java, Python3 |

## Approach 1: Brute Force with Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        unordered_set<string> seenSubstrings;
        int maxLength = s.length() - 1;

        for (int start = 0; start <= s.length(); start++) {
            int end = start;
            // Check if the remaining characters can form a substring of
            // maxLength
            if (end + maxLength > s.length()) {
                // Reduce maxLength if not possible and reset
                if (--maxLength == 0) break;
                start = -1;
                seenSubstrings.clear();
                continue;
            }
            // Extract the substring from the current start to start +
            // maxLength
            string currentSubstring = s.substr(end, maxLength);
            // If the substring has been seen before, it's a repeating
            // substring
            if (!seenSubstrings.insert(currentSubstring).second) {
                return maxLength;
            }
        }
        return maxLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestRepeatingSubstring(String s) {
        Set<String> seenSubstrings = new HashSet<>();
        int maxLength = s.length() - 1;

        for (int start = 0; start <= s.length(); start++) {
            int end = start;
            // If the remaining substring is shorter than maxLength,
            // reset the loop
            if (end + maxLength > s.length()) {
                if (--maxLength == 0) break;
                start = -1;
                seenSubstrings.clear();
                continue;
            }
            // Extract substring of length maxLength
            String currentSubstring = s.substring(end, end + maxLength);
            // If the substring is already in the set,
            // it means we've found a repeating substring
            if (!seenSubstrings.add(currentSubstring)) {
                return maxLength;
            }
        }
        return maxLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        seen_substrings = set()
        max_length = len(s) - 1

        while max_length > 0:
            seen_substrings.clear()
            for start in range(len(s) - max_length + 1):
                end = start
                # Extract substring of length max_length
                current_substring = s[end : end + max_length]
                # If the substring is already in the set,
                # it means we've found a repeating substring
                if current_substring in seen_substrings:
                    return max_length
                seen_substrings.add(current_substring)
            # If no repeating substring found,
            # decrease max_length and try again
            max_length -= 1
        return 0
```

</details>

<br>

## Approach 2: Brute Force with Incremental Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int length = s.length(), maxLength = 0;
        unordered_set<string> seenSubstrings;

        for (int start = 0; start < length; start++) {
            int end = start;
            // Stop if it's not possible to find a longer repeating substring
            if (end + maxLength >= length) {
                return maxLength;
            }
            // Generate substrings of length maxLength + 1
            string currentSubstring = s.substr(end, maxLength + 1);
            // If a repeating substring is found, increase maxLength and
            // restart
            if (!seenSubstrings.insert(currentSubstring).second) {
                start = -1;  // Restart search for new length
                seenSubstrings.clear();
                maxLength++;
            }
        }
        return maxLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestRepeatingSubstring(String s) {
        int length = s.length(), maxLength = 0;
        Set<String> seenSubstrings = new HashSet<>();

        for (int start = 0; start < length; start++) {
            int end = start;
            // Stop if it's not possible to find a longer repeating substring
            if (end + maxLength >= length) {
                return maxLength;
            }
            // Generate substrings of length maxLength + 1
            String currentSubstring = s.substring(end, end + maxLength + 1);
            // If a repeating substring is found, increase maxLength and restart
            if (!seenSubstrings.add(currentSubstring)) {
                start = -1; // Restart search for new length
                seenSubstrings.clear();
                maxLength++;
            }
        }
        return maxLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        length = len(s)
        max_length = 0
        seen_substrings = set()

        start = 0
        while start < length:
            end = start
            # Stop if it's not possible to find a
            # longer repeating substring
            if end + max_length >= length:
                return max_length
            # Generate substrings of length max_length + 1
            current_substring = s[end : end + max_length + 1]
            # If a repeating substring is found,
            #  increase max_length and restart
            if current_substring in seen_substrings:
                start = -1  # Restart search for new length
                seen_substrings.clear()
                max_length += 1
            else:
                seen_substrings.add(current_substring)
            start += 1

        return max_length
```

</details>

<br>

## Approach 3: Suffix Array with Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int length = s.length();
        vector<string> suffixes(length);

        // Create suffix array by storing all suffixes of the string
        for (int i = 0; i < length; i++) {
            suffixes[i] = s.substr(i);
        }
        // Sort the suffix array
        sort(suffixes.begin(), suffixes.end());

        int maxLength = 0;
        // Compare adjacent suffixes to find the longest common prefix
        for (int i = 1; i < length; i++) {
            int j = 0;
            // Compare characters one by one until they differ or end of one
            // suffix is reached
            while (j < min(suffixes[i].length(), suffixes[i - 1].length()) &&
                   suffixes[i][j] == suffixes[i - 1][j]) {
                j++;
            }
            // Update maxLength with the length of the common prefix
            maxLength = max(maxLength, j);
        }
        return maxLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestRepeatingSubstring(String s) {
        int length = s.length();
        String[] suffixes = new String[length];

        // Create suffix array
        for (int i = 0; i < length; i++) {
            suffixes[i] = s.substring(i);
        }
        // Sort the suffixes
        Arrays.sort(suffixes);

        int maxLength = 0;
        // Find the longest common prefix between consecutive sorted suffixes
        for (int i = 1; i < length; i++) {
            int j = 0;
            while (
                j < Math.min(suffixes[i].length(), suffixes[i - 1].length()) &&
                suffixes[i].charAt(j) == suffixes[i - 1].charAt(j)
            ) {
                j++;
            }
            maxLength = Math.max(maxLength, j);
        }
        return maxLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        length = len(s)
        suffixes = []

        # Create suffix array by storing all suffixes of the string
        for i in range(length):
            suffixes.append(s[i:])
        # Sort the suffix array
        suffixes.sort()

        max_length = 0
        # Compare adjacent suffixes to find the longest common prefix
        for i in range(1, length):
            j = 0
            # Compare characters one by one until
            # they differ or end of one suffix is reached
            while (
                j < min(len(suffixes[i]), len(suffixes[i - 1]))
                and suffixes[i][j] == suffixes[i - 1][j]
            ):
                j += 1
            # Update max_length with the length of the common prefix
            max_length = max(max_length, j)
        return max_length
```

</details>

<br>

## Approach 4: Binary Search with Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int start = 1, end = s.length() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            // Check if there's a repeating substring of length mid
            if (hasRepeatingSubstring(s, mid)) {
                start = mid + 1;  // Try longer substrings
            } else {
                end = mid - 1;  // Try shorter substrings
            }
        }
        return start - 1;
    }

private:
    bool hasRepeatingSubstring(string& s, int length) {
        unordered_set<string> seenSubstrings;
        for (int i = 0; i <= s.length() - length; i++) {
            // Extract a substring of the given length
            string substring = s.substr(i, length);
            // Check if the substring has been seen before
            if (!seenSubstrings.insert(substring).second) {
                return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestRepeatingSubstring(String s) {
        char[] characters = s.toCharArray();
        int start = 1, end = characters.length - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            // Check if there's a repeating substring of length mid
            if (hasRepeatingSubstring(characters, mid)) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start - 1;
    }

    private boolean hasRepeatingSubstring(char[] characters, int length) {
        Set<String> seenSubstrings = new HashSet<>();
        // Check for repeating substrings of given length
        for (int i = 0; i <= characters.length - length; i++) {
            String substring = new String(characters, i, length);
            if (!seenSubstrings.add(substring)) {
                return true;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        start, end = 1, len(s) - 1

        while start <= end:
            mid = (start + end) // 2
            # Check if there's a repeating substring of length mid
            if self._has_repeating_substring(s, mid):
                start = mid + 1  # Try longer substrings
            else:
                end = mid - 1  # Try shorter substrings
        return start - 1

    def _has_repeating_substring(self, s: str, length: int) -> bool:
        seen_substrings = set()
        for i in range(len(s) - length + 1):
            # Extract a substring of the given length
            substring = s[i : i + length]
            # Check if the substring has been seen before
            if substring in seen_substrings:
                return True
            seen_substrings.add(substring)
        return False
```

</details>

<br>

## Approach 5: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int length = s.length();
        vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));
        int maxLength = 0;

        // Populate the DP array
        for (int i = 1; i <= length; i++) {
            for (int j = i + 1; j <= length; j++) {
                // Check if the characters match and update the DP value
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);  // Update maxLength
                }
            }
        }
        return maxLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestRepeatingSubstring(String s) {
        int length = s.length();
        int[][] dp = new int[length + 1][length + 1];
        int maxLength = 0;

        // Use DP to find the longest common substring
        for (int i = 1; i <= length; i++) {
            for (int j = i + 1; j <= length; j++) {
                // If characters match, extend the length of
                // the common substring
                if (s.charAt(i - 1) == s.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = Math.max(maxLength, dp[i][j]);
                }
            }
        }
        return maxLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        length = len(s)
        dp = [[0] * (length + 1) for _ in range(length + 1)]
        max_length = 0

        # Populate the DP array
        for i in range(1, length + 1):
            for j in range(i + 1, length + 1):
                # Check if the characters match and
                # update the DP value
                if s[i - 1] == s[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    # Update max_length
                    max_length = max(max_length, dp[i][j])
        return max_length
```

</details>

<br>

## Approach 6: MSD Radix Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int length = s.length();
        vector<string> suffixes(length);

        // Create suffix array by storing all suffixes of the string
        for (int i = 0; i < length; i++) {
            suffixes[i] = s.substr(i);
        }
        // Sort the suffix array using MSD Radix Sort
        msdRadixSort(suffixes);

        int maxLength = 0;
        // Compare adjacent suffixes to find the longest common prefix
        for (int i = 1; i < length; i++) {
            int j = 0;
            // Compare characters one by one until they differ or end of one
            // suffix is reached
            while (j < min(suffixes[i].length(), suffixes[i - 1].length()) &&
                   suffixes[i][j] == suffixes[i - 1][j]) {
                j++;
            }
            // Update maxLength with the length of the common prefix
            maxLength = max(maxLength, j);
        }
        return maxLength;  // Return the maximum length of repeating substring
                           // found
    }

private:
    void msdRadixSort(vector<string>& input) {
        vector<string> aux(input.size());
        sort(input, 0, input.size() - 1, 0, aux);
    }

    void sort(vector<string>& input, int lo, int hi, int depth,
              vector<string>& aux) {
        if (lo >= hi) return;

        vector<int> count(28, 0);
        // Count frequencies of each character at the current depth
        for (int i = lo; i <= hi; i++) {
            count[charAt(input[i], depth) + 1]++;
        }
        // Compute cumulates which give positions of each character
        for (int i = 1; i < 28; i++) {
            count[i] += count[i - 1];
        }
        // Move items to auxiliary array based on cumulates
        for (int i = lo; i <= hi; i++) {
            aux[count[charAt(input[i], depth)]++] = input[i];
        }
        // Copy back to original array
        for (int i = lo; i <= hi; i++) {
            input[i] = aux[i - lo];
        }
        // Recursively sort for each character value
        for (int i = 0; i < 27; i++) {
            sort(input, lo + count[i], lo + count[i + 1] - 1, depth + 1, aux);
        }
    }

    // Returns the character value or 0 if index exceeds string length
    int charAt(const string& s, int index) {
        if (index >= s.length()) return 0;
        return s[index] - 'a' + 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestRepeatingSubstring(String s) {
        int length = s.length();
        String[] suffixes = new String[length];

        // Create suffix array
        for (int i = 0; i < length; i++) {
            suffixes[i] = s.substring(i);
        }
        // Sort the suffix array using MSD Radix Sort
        msdRadixSort(suffixes);

        int maxLength = 0;
        // Find the longest common prefix between consecutive sorted suffixes
        for (int i = 1; i < length; i++) {
            int j = 0;
            while (
                j < Math.min(suffixes[i].length(), suffixes[i - 1].length()) &&
                suffixes[i].charAt(j) == suffixes[i - 1].charAt(j)
            ) {
                j++;
            }
            maxLength = Math.max(maxLength, j);
        }
        return maxLength;
    }

    // Main method to perform MSD Radix Sort
    private void msdRadixSort(String[] input) {
        sort(input, 0, input.length - 1, 0, new String[input.length]);
    }

    // Helper method for sorting
    private void sort(String[] input, int lo, int hi, int depth, String[] aux) {
        if (lo >= hi) return;

        int[] count = new int[28];
        for (int i = lo; i <= hi; i++) {
            count[charAt(input[i], depth) + 1]++;
        }
        for (int i = 1; i < 28; i++) {
            count[i] += count[i - 1];
        }
        for (int i = lo; i <= hi; i++) {
            aux[count[charAt(input[i], depth)]++] = input[i];
        }
        for (int i = lo; i <= hi; i++) {
            input[i] = aux[i - lo];
        }
        for (int i = 0; i < 27; i++) {
            sort(input, lo + count[i], lo + count[i + 1] - 1, depth + 1, aux);
        }
    }

    // Returns the character value or 0 if index exceeds string length
    private int charAt(String s, int index) {
        if (index >= s.length()) return 0;
        return s.charAt(index) - 'a' + 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        length = len(s)
        suffixes = []

        # Create suffix array by storing all suffixes of the string
        for i in range(length):
            suffixes.append(s[i:])
        # Sort the suffix array using MSD Radix Sort
        self._msd_radix_sort(suffixes)

        max_length = 0
        # Compare adjacent suffixes to find the longest common prefix
        for i in range(1, length):
            j = 0
            # Compare characters one by one until they
            # differ or end of one suffix is reached

            while (
                j < min(len(suffixes[i]), len(suffixes[i - 1]))
                and suffixes[i][j] == suffixes[i - 1][j]
            ):
                j += 1
            # Update max_length with the length of the common prefix
            max_length = max(max_length, j)
        return max_length

    def _msd_radix_sort(self, input: List[str]) -> None:
        aux = ["" for _ in input]
        self._sort(input, 0, len(input) - 1, 0, aux)

    def _sort(
        self, input: List[str], lo: int, hi: int, depth: int, aux: List[str]
    ) -> None:
        if lo >= hi:
            return

        count = [0] * 28
        # Count frequencies of each character at the current depth
        for i in range(lo, hi + 1):
            count[self._char_at(input[i], depth) + 1] += 1

        # Compute cumulates which give positions of each character
        for i in range(1, 28):
            count[i] += count[i - 1]

        # Move items to auxiliary array based on cumulates
        for i in range(lo, hi + 1):
            aux[count[self._char_at(input[i], depth)]] = input[i]
            count[self._char_at(input[i], depth)] += 1

        # Copy back to original array
        for i in range(lo, hi + 1):
            input[i] = aux[i - lo]

        # Recursively sort for each character value
        for i in range(27):
            self._sort(
                input, lo + count[i], lo + count[i + 1] - 1, depth + 1, aux
            )

    def _char_at(self, s: str, index: int) -> int:
        if index >= len(s):
            return 0
        return ord(s[index]) - ord("a") + 1
```

</details>
