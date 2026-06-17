# 2490. Circular Sentence

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/circular-sentence/)  
`String`

**Problem Link:** [LeetCode 2490 - Circular Sentence](https://leetcode.com/problems/circular-sentence/)

## Problem

A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

- For example, "Hello World", "HELLO", "hello world hello world" are all sentences.

Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

A sentence is circular if:

- The last character of each word in the sentence is equal to the first character of its next word.
- The last character of the last word is equal to the first character of the first word.

For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

Given a string sentence, return true if it is circular. Otherwise, return false.

### Example 1

```text
Input: sentence = "leetcode exercises sound delightful"
Output: true
Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
- leetcode's last character is equal to exercises's first character.
- exercises's last character is equal to sound's first character.
- sound's last character is equal to delightful's first character.
- delightful's last character is equal to leetcode's first character.
The sentence is circular.
```

### Example 2

```text
Input: sentence = "eetcode"
Output: true
Explanation: The words in sentence are ["eetcode"].
- eetcode's last character is equal to eetcode's first character.
The sentence is circular.
```

### Example 3

```text
Input: sentence = "Leetcode is cool"
Output: false
Explanation: The words in sentence are ["Leetcode", "is", "cool"].
- Leetcode's last character is not equal to is's first character.
The sentence is not circular.
```

## Constraints

- 1 <= sentence.length <= 500
- sentence consist of only lowercase and uppercase English letters and spaces.
- The words in sentence are separated by a single space.
- There are no leading or trailing spaces.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2490. Circular Sentence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Split Sentence | C++, Java, Python3 |
| Space-optimized Approach | C++, Java, Python3 |

## Approach 1: Split Sentence

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Use the split function to store the words in a vector.
        stringstream ss(sentence);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        int n = words.size();

        // Start comparing from the last character of the last word.
        char last = words[n - 1].back();

        for (int i = 0; i < n; i++) {
            // If this character is not equal to the first character of current
            // word, return false.
            if (words[i].front() != last) return false;
            last = words[i].back();
        }

        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isCircularSentence(String sentence) {
        // Use the split function to store the words in an array.
        String words[] = sentence.split(" ");
        int n = words.length;

        // Start comparing from the last character of the last word.
        char last = words[n - 1].charAt(words[n - 1].length() - 1);

        for (int i = 0; i < n; i++) {
            // If this character is not equal to the first character of current word, return
            // false.
            if (words[i].charAt(0) != last) return false;
            last = words[i].charAt(words[i].length() - 1);
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        # Use the split function to store the words in a list.
        words = sentence.split(" ")
        n = len(words)

        # Start comparing from the last character of the last word.
        last = words[n - 1][-1]

        for i in range(n):
            # If this character is not equal to the first character of current word, return
            # false.
            if words[i][0] != last:
                return False
            last = words[i][-1]

        return True
```

</details>

<br>

## Approach 2: Space-optimized Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i = 0; i < sentence.size(); ++i)
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;
        return sentence[0] == sentence[sentence.size() - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean isCircularSentence(String sentence) {
        for (int i = 0; i < sentence.length(); ++i) if (
            sentence.charAt(i) == ' ' &&
            sentence.charAt(i - 1) != sentence.charAt(i + 1)
        ) return false;
        return sentence.charAt(0) == sentence.charAt(sentence.length() - 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        for i in range(len(sentence)):
            if sentence[i] == " " and sentence[i - 1] != sentence[i + 1]:
                return False
        return sentence[0] == sentence[len(sentence) - 1]
```

</details>
