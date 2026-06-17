# 1002. Find Common Characters

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-common-characters/)  
`Array` `Hash Table` `String`

**Problem Link:** [LeetCode 1002 - Find Common Characters](https://leetcode.com/problems/find-common-characters/)

## Problem

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

### Example 1

```text
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
```

### Example 2

```text
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
```

## Constraints

- 1 <= words.length <= 100
- 1 <= words[i].length <= 100
- words[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1002. Find Common Characters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Array + Frequency Intersection | C++, Java, Python3 |

## Approach: Array + Frequency Intersection

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int words_size = words.size();
        vector<int> commonCharacterCounts(26), currentCharacterCounts(26);
        vector<string> result;

        // Initialize commonCharacterCounts with the characters from the first
        // word
        for (char& ch : words[0]) {
            commonCharacterCounts[ch - 'a']++;
        }

        for (int i = 1; i < words_size; i++) {
            fill(currentCharacterCounts.begin(), currentCharacterCounts.end(),
                 0);

            // Count characters in the current word
            for (char& ch : words[i]) {
                currentCharacterCounts[ch - 'a']++;
            }

            // Update the common character counts to keep the minimum counts
            for (int letter = 0; letter < 26; letter++) {
                commonCharacterCounts[letter] =
                    min(commonCharacterCounts[letter],
                        currentCharacterCounts[letter]);
            }
        }

        // Collect the common characters based on the final counts
        for (int letter = 0; letter < 26; letter++) {
            for (int commonCount = 0;
                 commonCount < commonCharacterCounts[letter]; commonCount++) {
                result.push_back(string(1, letter + 'a'));
            }
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

    public List<String> commonChars(String[] words) {
        int wordsSize = words.length;
        int[] commonCharacterCounts = new int[26];
        int[] currentCharacterCounts = new int[26];
        List<String> result = new ArrayList<>();

        // Initialize commonCharacterCounts with the characters from the first
        // word
        for (char ch : words[0].toCharArray()) {
            commonCharacterCounts[ch - 'a']++;
        }

        for (int i = 1; i < wordsSize; i++) {
            Arrays.fill(currentCharacterCounts, 0);

            // Count characters in the current word
            for (char ch : words[i].toCharArray()) {
                currentCharacterCounts[ch - 'a']++;
            }

            // Update the common character counts to keep the minimum counts
            for (int letter = 0; letter < 26; letter++) {
                commonCharacterCounts[letter] = Math.min(
                    commonCharacterCounts[letter],
                    currentCharacterCounts[letter]
                );
            }
        }

        // Collect the common characters based on the final counts
        for (int letter = 0; letter < 26; letter++) {
            for (
                int commonCount = 0;
                commonCount < commonCharacterCounts[letter];
                commonCount++
            ) {
                result.add(String.valueOf((char) (letter + 'a')));
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def commonChars(self, words: List[str]) -> List[str]:
        words_size = len(words)
        result = []

        # Initialize common_character_counts with the characters from the first word
        common_character_counts = collections.Counter(words[0])

        for i in range(1, words_size):
            # Count characters in the current word
            current_character_counts = collections.Counter(words[i])

            # Update the common character counts to keep the minimum counts
            for letter in common_character_counts.keys():
                common_character_counts[letter] = min(
                    common_character_counts[letter],
                    current_character_counts[letter],
                )

        # Collect the common characters based on the final counts
        for letter, count in common_character_counts.items():
            for _ in range(count):
                result.append(letter)

        return result
```

</details>
