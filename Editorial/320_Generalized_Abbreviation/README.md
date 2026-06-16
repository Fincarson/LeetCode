# 320. Generalized Abbreviation

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/generalized-abbreviation/)  
`String` `Backtracking` `Bit Manipulation`

**Problem Link:** [LeetCode 320 - Generalized Abbreviation](https://leetcode.com/problems/generalized-abbreviation/)

## Problem

A word's generalized abbreviation can be constructed by taking any number of non-overlapping and non-adjacent substrings and replacing them with their respective lengths.

- For example, "abcde" can be abbreviated into:

		"a3e" ("bcd" turned into "3")
		"1bcd1" ("a" and "e" both turned into "1")
		"5" ("abcde" turned into "5")
		"abcde" (no substrings replaced)
- However, these abbreviations are invalid:

		"23" ("ab" turned into "2" and "cde" turned into "3") is invalid as the substrings chosen are adjacent.
		"22de" ("ab" turned into "2" and "bc" turned into "2") is invalid as the substring chosen overlap.

Given a string word, return a list of all the possible generalized abbreviations of word. Return the answer in any order.

### Example 1

```text
Input: word = "word"
Output: ["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]
```

### Example 2

```text
Input: word = "a"
Output: ["1","a"]
```

## Constraints

- 1 <= word.length <= 15
- word consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subsets](https://leetcode.com/problems/subsets/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Unique Word Abbreviation](https://leetcode.com/problems/unique-word-abbreviation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Unique Word Abbreviation](https://leetcode.com/problems/minimum-unique-word-abbreviation/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 320. Generalized Abbreviation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C++, Java, Python3 |
| Bit Manipulation | C++, Java, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void storeAbbreviations(vector<string>& abbreviations, string& word,
                            string currWord, int index, int abbreviatedCount) {
        if (index == word.size()) {
            // If the length of the last abbreviated substring is 0, add an
            // empty string.
            currWord +=
                abbreviatedCount == 0 ? "" : to_string(abbreviatedCount);

            abbreviations.push_back(currWord);
            return;
        }

        // Abbreviated string corresponding to the last substring chosen.
        string abbreviatedString =
            abbreviatedCount == 0 ? "" : to_string(abbreviatedCount);

        storeAbbreviations(abbreviations, word,
                           currWord + abbreviatedString + word[index],
                           index + 1, 0);
        storeAbbreviations(abbreviations, word, currWord, index + 1,
                           abbreviatedCount + 1);
    }

    vector<string> generateAbbreviations(string word) {
        vector<string> abbreviations;

        storeAbbreviations(abbreviations, word, "", 0, 0);
        return abbreviations;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private void storeAbbreviations(
        List<String> abbreviations,
        String word,
        StringBuilder currWord,
        int index,
        int abbreviatedCount
    ) {
        if (index == word.length()) {
            // If the length of the last abbreviated substring is 0, add an empty string.
            if (abbreviatedCount > 0) {
                currWord.append(abbreviatedCount);
            }
            abbreviations.add(currWord.toString());
            return;
        }
        int currWordLength = currWord.length();
        // Option 1: Keep the current character.
        if (abbreviatedCount > 0) {
            currWord.append(abbreviatedCount);
        }
        currWord.append(word.charAt(index));
        storeAbbreviations(abbreviations, word, currWord, index + 1, 0);
        currWord.setLength(currWordLength); // Backtrack
        // Option 2: Abbreviate the current character.
        storeAbbreviations(
            abbreviations,
            word,
            currWord,
            index + 1,
            abbreviatedCount + 1
        );
    }

    public List<String> generateAbbreviations(String word) {
        List<String> abbreviations = new ArrayList<>();
        storeAbbreviations(abbreviations, word, new StringBuilder(), 0, 0);
        return abbreviations;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def store_abbreviations(
        self, abbreviations, word, curr_word, index, abbreviated_count
    ):
        if index == len(word):
            # If the length of the last abbreviated substring is 0, add an empty string.
            if abbreviated_count > 0:
                curr_word += str(abbreviated_count)
            abbreviations.append(curr_word)
            return

        # Option 1: Keep the current character.
        self.store_abbreviations(
            abbreviations,
            word,
            curr_word
            + (str(abbreviated_count) if abbreviated_count > 0 else "")
            + word[index],
            index + 1,
            0,
        )

        # Option 2: Abbreviate the current character.
        self.store_abbreviations(
            abbreviations, word, curr_word, index + 1, abbreviated_count + 1
        )

    def generateAbbreviations(self, word):
        abbreviations = []
        self.store_abbreviations(abbreviations, word, "", 0, 0)
        return abbreviations
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
    vector<string> generateAbbreviations(string word) {
        int N = word.size();
        vector<string> abbreviations;

        for (int mask = 0; mask < (1 << N); mask++) {
            string currWord;
            int abbreviatedCount = 0;

            for (int index = 0; index < N; index++) {
                // If the bit at position index is 1, increment the abbreviated
                // substring.
                if (mask & (1 << index)) {
                    abbreviatedCount++;
                } else {
                    // Append the last substring and then the current character.
                    currWord +=
                        (abbreviatedCount == 0 ? ""
                                               : to_string(abbreviatedCount)) +
                        word[index];
                    abbreviatedCount = 0;
                }
            }

            currWord +=
                abbreviatedCount == 0 ? "" : to_string(abbreviatedCount);
            abbreviations.push_back(currWord);
        }

        return abbreviations;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> generateAbbreviations(String word) {
        int N = word.length();
        List<String> abbreviations = new ArrayList<>();

        for (int mask = 0; mask < (1 << N); mask++) {
            StringBuilder currWord = new StringBuilder();
            int abbreviatedCount = 0;

            for (int index = 0; index < N; index++) {
                // If the bit at position index is 1, increment the abbreviated substring.
                if ((mask & (1 << index)) != 0) {
                    abbreviatedCount++;
                } else {
                    // Append the last substring and then the current character.
                    if (abbreviatedCount > 0) {
                        currWord.append(abbreviatedCount);
                        abbreviatedCount = 0;
                    }
                    currWord.append(word.charAt(index));
                }
            }

            if (abbreviatedCount > 0) {
                currWord.append(abbreviatedCount);
            }
            abbreviations.add(currWord.toString());
        }

        return abbreviations;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def generateAbbreviations(self, word):
        N = len(word)
        abbreviations = []

        for mask in range(1 << N):
            curr_word = []
            abbreviated_count = 0

            for index in range(N):
                # If the bit at the position index is 1, increment the abbreviated substring.
                if mask & (1 << index):
                    abbreviated_count += 1
                else:
                    # Append the last substring and then the current character.
                    if abbreviated_count > 0:
                        curr_word.append(str(abbreviated_count))
                        abbreviated_count = 0
                    curr_word.append(word[index])

            if abbreviated_count > 0:
                curr_word.append(str(abbreviated_count))

            abbreviations.append("".join(curr_word))

        return abbreviations
```

</details>
