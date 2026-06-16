# 1165. Single-Row Keyboard

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/single-row-keyboard/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 1165 - Single-Row Keyboard](https://leetcode.com/problems/single-row-keyboard/)

## Problem

There is a special keyboard with all keys in a single row.

Given a string keyboard of length 26 indicating the layout of the keyboard (indexed from 0 to 25). Initially, your finger is at index 0. To type a character, you have to move your finger to the index of the desired character. The time taken to move your finger from index i to index j is |i - j|.

You want to type a string word. Write a function to calculate how much time it takes to type it with one finger.

### Example 1

```text
Input: keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"
Output: 4
Explanation: The index moves from 0 to 2 to write 'c' then to 1 to write 'b' then to 0 again to write 'a'.
Total time = 2 + 1 + 1 = 4.
```

### Example 2

```text
Input: keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
Output: 73
```

## Constraints

- keyboard.length == 26
- keyboard contains each English lowercase letter exactly once in some order.
- 1 <= word.length <= 104
- word[i] is an English lowercase letter.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Total Distance to Type a String Using One Finger](https://leetcode.com/problems/total-distance-to-type-a-string-using-one-finger/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1165. Single-Row Keyboard

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Storing indexes for all letters | C++, Java |

## Approach 1: Storing indexes for all letters

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> keyIndices(26, -1);

        // Get the index for each key.
        for (int i = 0; i < keyboard.length(); i++)
            keyIndices[keyboard[i] - 'a'] = i;

        // Initialize previous index as starting index = 0.
        int prev = 0;
        int result = 0;

        // Calculate the total time.
        for (char &c : word) {
            // Add the distance from previous index
            // to current letter's index to the result.
            result += abs(prev - keyIndices[c - 'a']);

            // Update the previous index to current index for next iteration.
            prev = keyIndices[c - 'a'];
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int calculateTime(String keyboard, String word) {
        int[] keyIndices = new int[26];

        // Get the index for each key.
        for (int i = 0; i < keyboard.length(); i++)
            keyIndices[keyboard.charAt(i) - 'a'] = i;

        // Initialize previous index as starting index = 0.
        int prev = 0;
        int result = 0;

        // Calculate the total time.
        for (char c : word.toCharArray()) {
            // Add the distance from previous index
            // to current letter's index to the result.
            result += Math.abs(prev - keyIndices[c - 'a']);

            // Update the previous index to current index for next iteration.
            prev = keyIndices[c - 'a'];
        }
        return result;
    }
}
```

</details>
