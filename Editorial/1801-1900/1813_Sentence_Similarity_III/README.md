# 1813. Sentence Similarity III

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sentence-similarity-iii/)  
`Array` `Two Pointers` `String`

**Problem Link:** [LeetCode 1813 - Sentence Similarity III](https://leetcode.com/problems/sentence-similarity-iii/)

## Problem

You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

- s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
- s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.

Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= sentence1.length, sentence2.length <= 100
- sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
- The words in sentence1 and sentence2 are separated by a single space.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1813. Sentence Similarity III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Deque | C++, Java, Python3 |
| Two Pointers | C++, Java, Python3 |

## Approach 1: Deque

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        istringstream iss1(s1);
        deque<string> deque1((istream_iterator<string>(iss1)),
                             istream_iterator<string>());
        istringstream iss2(s2);
        deque<string> deque2((istream_iterator<string>(iss2)),
                             istream_iterator<string>());
        // Compare the prefixes or beginning of the strings.
        while (!deque1.empty() && !deque2.empty() &&
               deque1.front() == deque2.front()) {
            deque1.pop_front();
            deque2.pop_front();
        }
        // Compare the suffixes or ending of the strings.
        while (!deque1.empty() && !deque2.empty() &&
               deque1.back() == deque2.back()) {
            deque1.pop_back();
            deque2.pop_back();
        }
        return deque1.empty() || deque2.empty();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean areSentencesSimilar(String s1, String s2) {
        Deque<String> deque1 = new ArrayDeque<>(Arrays.asList(s1.split(" ")));
        Deque<String> deque2 = new ArrayDeque<>(Arrays.asList(s2.split(" ")));
        //Compare the prefixes or beginning of the strings.
        while (
            !deque1.isEmpty() &&
            !deque2.isEmpty() &&
            deque1.peek().equals(deque2.peek())
        ) {
            deque1.poll();
            deque2.poll();
        }
        // Compare the suffixes or ending of the strings.
        while (
            !deque1.isEmpty() &&
            !deque2.isEmpty() &&
            deque1.peekLast().equals(deque2.peekLast())
        ) {
            deque1.pollLast();
            deque2.pollLast();
        }
        return deque1.isEmpty() || deque2.isEmpty();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def areSentencesSimilar(self, s1: str, s2: str) -> bool:
        deque1 = deque(s1.split())
        deque2 = deque(s2.split())
        # Compare the prefixes or beginning of the strings.
        while deque1 and deque2 and deque1[0] == deque2[0]:
            deque1.popleft()
            deque2.popleft()
        # Compare the suffixes or ending of the strings.
        while deque1 and deque2 and deque1[-1] == deque2[-1]:
            deque1.pop()
            deque2.pop()
        return not deque1 or not deque2
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // Convert sentences to lists of words
        stringstream ss1(s1), ss2(s2);
        string word;
        vector<string> s1Words, s2Words;
        while (ss1 >> word) s1Words.push_back(word);
        while (ss2 >> word) s2Words.push_back(word);

        int start = 0, ends1 = s1Words.size() - 1, ends2 = s2Words.size() - 1;

        // If words in s1 are more than s2, swap them and return the answer.
        if (s1Words.size() > s2Words.size()) return areSentencesSimilar(s2, s1);

        // Find the maximum words matching from the beginning.
        while (start < s1Words.size() && s1Words[start] == s2Words[start])
            ++start;

        // Find the maximum words matching in the end.
        while (ends1 >= 0 && s1Words[ends1] == s2Words[ends2]) {
            --ends1;
            --ends2;
        }

        // If ends1 index is less than start, then sentence is similar.
        return ends1 < start;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean areSentencesSimilar(String s1, String s2) {
        // Split the words in sentences and store it in a string array.
        String[] s1Words = s1.split(" "), s2Words = s2.split(" ");
        int start = 0, ends1 = s1Words.length - 1, ends2 =
            s2Words.length - 1, s1WordsLength = s1Words.length, s2WordsLength =
            s2Words.length;

        // If words in s1 are more than s2, swap them and return the answer.
        if (s1WordsLength > s2WordsLength) {
            return areSentencesSimilar(s2, s1);
        }

        // Find the maximum words matching from the beginning.
        while (start < s1WordsLength && s1Words[start].equals(s2Words[start])) {
            ++start;
        }
        // Find the maximum words matching in the end.
        while (ends1 >= 0 && s1Words[ends1].equals(s2Words[ends2])) {
            --ends1;
            --ends2;
        }

        // If i reaches the end of the array, then we return true.
        return ends1 < start;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def areSentencesSimilar(self, s1: str, s2: str) -> bool:
        # Split the words in sentences and store it in a string array.
        s1_words = s1.split(" ")
        s2_words = s2.split(" ")
        start, ends1, ends2 = 0, len(s1_words) - 1, len(s2_words) - 1

        # If words in s1 are more than s2, swap them and return the answer.
        if len(s1_words) > len(s2_words):
            return self.areSentencesSimilar(s2, s1)

        # Find the maximum words matching from the beginning.
        while start < len(s1_words) and s1_words[start] == s2_words[start]:
            start += 1

        # Find the maximum words matching in the end.
        while ends1 >= 0 and s1_words[ends1] == s2_words[ends2]:
            ends1 -= 1
            ends2 -= 1

        # If i reaches the end of the array, then we return true.
        return ends1 < start
```

</details>
