# 804. Unique Morse Code Words

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/unique-morse-code-words/)  
`Array` `Hash Table` `String`

**Problem Link:** [LeetCode 804 - Unique Morse Code Words](https://leetcode.com/problems/unique-morse-code-words/)

## Problem

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

- 'a' maps to ".-",
- 'b' maps to "-...",
- 'c' maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

```text
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
```

Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.

- For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.

Return the number of different transformations among all words we have.

### Example 1

```text
Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".
```

### Example 2

```text
Input: words = ["a"]
Output: 1
```

## Constraints

- 1 <= words.length <= 100
- 1 <= words[i].length <= 12
- words[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 804. Unique Morse Code Words

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Set | Java, Python |

## Approach 1: Hash Set

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] MORSE = new String[]{".-","-...","-.-.","-..",".","..-.","--.",
                         "....","..",".---","-.-",".-..","--","-.",
                         "---",".--.","--.-",".-.","...","-","..-",
                         "...-",".--","-..-","-.--","--.."};

        Set<String> seen = new HashSet();
        for (String word: words) {
            StringBuilder code = new StringBuilder();
            for (char c: word.toCharArray())
                code.append(MORSE[c - 'a']);
            seen.add(code.toString());
        }

        return seen.size();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def uniqueMorseRepresentations(self, words):
        MORSE = [".-","-...","-.-.","-..",".","..-.","--.",
                 "....","..",".---","-.-",".-..","--","-.",
                 "---",".--.","--.-",".-.","...","-","..-",
                 "...-",".--","-..-","-.--","--.."]

        seen = {"".join(MORSE[ord(c) - ord('a')] for c in word)
                for word in words}

        return len(seen)
```

</details>
