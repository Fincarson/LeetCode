# 791. Custom Sort String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/custom-sort-string/)  
`Hash Table` `String` `Sorting`

**Problem Link:** [LeetCode 791 - Custom Sort String](https://leetcode.com/problems/custom-sort-string/)

## Problem

You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

### Example 1

### Example 2

## Constraints

- 1 <= order.length <= 26
- 1 <= s.length <= 200
- order and s consist of lowercase English letters.
- All the characters of order are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort the Students by Their Kth Score](https://leetcode.com/problems/sort-the-students-by-their-kth-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 791. Custom Sort String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Custom Comparator | C++, Java, Python3 |
| Frequency Table and Counting | C++, Java, Python3 |

## Approach 1: Custom Comparator

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string customSortString(string order, string s) {
        // Since strings are mutable in C++, we can sort s in-place
        sort(s.begin(), s.end(), [&order](char c1, char c2) {
            return order.find(c1) < order.find(c2);
        });
        return s;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String customSortString(String order, String s) {
        // Create char array for editing
        int N = s.length();
        Character[] result = new Character[N];
        for (int i = 0; i < N; i++) {
            result[i] = s.charAt(i);
        }

        // Define the custom comparator
        Arrays.sort(result, (c1, c2) -> {
            // The index of the character in order determines the value to be sorted by
            return order.indexOf(c1) - order.indexOf(c2);
        });

        // Return the result
        String resultString = "";
        for (Character c: result) {
            resultString += c;
        }
        return resultString;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        # Create a list from s to allow modification (strings are immutable in Python)
        result = list(s)

        # Sort using the index in order as the key
        result.sort(key=lambda c: order.index(c) if c in order else len(order))

        # Concatenate the list into a string
        return ''.join(result)
```

</details>

<br>

## Approach 2: Frequency Table and Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    public:
    string customSortString(string order, string s) {
        // Create a frequency table
        unordered_map<char, int> freq;

        // Initialize frequencies of letters
        // freq[c] = frequency of char c in s
        for (char letter : s) {
            freq[letter]++;
        }

        // Iterate order string to append to result
        string result = "";
        for (char letter : order) {
            while (freq[letter]-- > 0) {
                result += letter;
            }
        }

        // Iterate through freq and append remaining letters
        // This is necessary because some letters may not appear in `order`
        for (auto & [letter, count] : freq) {
            while (count-- > 0) {
                result += letter;
            }
        }

        // Return the result
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String customSortString(String order, String s) {
        // Create a frequency table
        Map<Character, Integer> freq = new HashMap<>();

        // Initialize frequencies of letters
        // freq[c] = frequency of char c in s
        int N = s.length();
        for (int i = 0; i < N; i++) {
            char letter = s.charAt(i);
            freq.put(letter, freq.getOrDefault(letter, 0) + 1);
        }

        // Iterate order string to append to result
        int K = order.length();
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < K; i++) {
            char letter = order.charAt(i);
            while (freq.getOrDefault(letter, 0) > 0) {
                result.append(letter);
                freq.put(letter, freq.get(letter) - 1);
            }
        }

        // Iterate through freq and append remaining letters
        // This is necessary because some letters may not appear in `order`
        for (char letter : freq.keySet()) {
            int count = freq.get(letter);
            while (count > 0) {
                result.append(letter);
                count--;
            }
        }

        // Return the result
        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        s_elem_freq = Counter(s)
        s_permutation = []

        for char in order:
            # Elem to be Ordered
            if char in s_elem_freq:
                s_permutation.append(char * s_elem_freq[char])
                del s_elem_freq[char]

        for unordered_elem in s_elem_freq:
            s_permutation.append(unordered_elem * s_elem_freq[unordered_elem])

        return ''.join(s_permutation)
```

</details>
