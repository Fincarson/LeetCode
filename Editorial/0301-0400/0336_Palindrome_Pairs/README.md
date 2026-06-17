# 336. Palindrome Pairs

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/palindrome-pairs/)  
`Array` `Hash Table` `String` `Trie` `Hash Function`

**Problem Link:** [LeetCode 336 - Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/)

## Problem

You are given a 0-indexed array of unique strings words.

A palindrome pair is a pair of integers (i, j) such that:

- 0 <= i, j < words.length,
- i != j, and
- words[i] + words[j] (the concatenation of the two strings) is a palindrome.

Return an array of all the palindrome pairs of words.

You must write an algorithm with O(sum of words[i].length) runtime complexity.

### Example 1

```text
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
```

### Example 2

```text
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
```

### Example 3

```text
Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]
```

## Constraints

- 1 <= words.length <= 5000
- 0 <= words[i].length <= 300
- words[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Longest Palindrome by Concatenating Two Letter Words](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Maximum Number of String Pairs](https://leetcode.com/problems/find-maximum-number-of-string-pairs/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 336. Palindrome Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute force | Java, Python |
| Hashing | Java, Python |
| Using a Trie | Java, Python |

## Approach 1: Brute force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {

        List<List<Integer>> pairs = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words.length; j++) {
                if (i == j) continue;
                String combined = words[i].concat(words[j]);
                String reversed = new StringBuilder(combined).reverse().toString();
                if (combined.equals(reversed)) {
                    pairs.add(Arrays.asList(i, j));
                }
            }   
        }

        return pairs;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def palindromePairs(self, words: List[str]) -> List[List[int]]:

    pairs = []

    for i, word_1 in enumerate(words):
        for j, word_2 in enumerate(words):
            if i == j:
                continue
            combined_word = word_1 + word_2
            if combined_word == combined_word[::-1]:
                pairs.append([i, j])

    return pairs
```

</details>

<br>

## Approach 2: Hashing

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private List<String> allValidPrefixes(String word) {
        List<String> validPrefixes = new ArrayList<>();
        for (int i = 0; i < word.length(); i++) {
            if (isPalindromeBetween(word, i, word.length() - 1)) {
                validPrefixes.add(word.substring(0, i));
            }
        }
        return validPrefixes;
    }

    private List<String> allValidSuffixes(String word) {
        List<String> validSuffixes = new ArrayList<>();
        for (int i = 0; i < word.length(); i++) {
            if (isPalindromeBetween(word, 0, i)) {
                validSuffixes.add(word.substring(i + 1, word.length()));
            }
        }
        return validSuffixes;
    }

    // Is the prefix ending at i a palindrome?
    private boolean isPalindromeBetween(String word, int front, int back) {
        while (front < back) {
            if (word.charAt(front) != word.charAt(back)) return false;
            front++;
            back--;
        }
        return true;
    }

    public List<List<Integer>> palindromePairs(String[] words) {
        // Build a word -> original index mapping for efficient lookup.
        Map<String, Integer> wordSet = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            wordSet.put(words[i], i);
        }

        // Make a list to put all the palindrome pairs we find in.
        List<List<Integer>> solution = new ArrayList<>();

        for (String word : wordSet.keySet()) {

            int currentWordIndex = wordSet.get(word);
            String reversedWord = new StringBuilder(word).reverse().toString();

            // Build solutions of case #1. This word will be word 1.
            if (wordSet.containsKey(reversedWord)
              && wordSet.get(reversedWord) != currentWordIndex) {
                solution.add(Arrays.asList(currentWordIndex, wordSet.get(reversedWord)));
            }

            // Build solutions of case #2. This word will be word 2.
            for (String suffix : allValidSuffixes(word)) {
                String reversedSuffix = new StringBuilder(suffix).reverse().toString();
                if (wordSet.containsKey(reversedSuffix)) {
                    solution.add(Arrays.asList(wordSet.get(reversedSuffix), currentWordIndex));
                }
            }

            // Build solutions of case #3. This word will be word 1.
            for (String prefix : allValidPrefixes(word)) {
                String reversedPrefix = new StringBuilder(prefix).reverse().toString();
                if (wordSet.containsKey(reversedPrefix)) {
                    solution.add(Arrays.asList(currentWordIndex, wordSet.get(reversedPrefix)));
                }
            }
        }
        return solution;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def palindromePairs(self, words):

    def all_valid_prefixes(word):
        valid_prefixes = []
        for i in range(len(word)):
            if word[i:] == word[i:][::-1]:
                valid_prefixes.append(word[:i])
        return valid_prefixes

    def all_valid_suffixes(word):
        valid_suffixes = []
        for i in range(len(word)):
            if word[:i+1] == word[:i+1][::-1]:
                valid_suffixes.append(word[i + 1:])
        return valid_suffixes

    word_lookup = {word: i for i, word in enumerate(words)}
    solutions = []

    for word_index, word in enumerate(words):
        reversed_word = word[::-1]

        # Build solutions of case #1. This word will be word 1.
        if reversed_word in word_lookup and word_index != word_lookup[reversed_word]:
            solutions.append([word_index, word_lookup[reversed_word]])

        # Build solutions of case #2. This word will be word 2.
        for suffix in all_valid_suffixes(word):
            reversed_suffix = suffix[::-1]
            if reversed_suffix in word_lookup:
                solutions.append([word_lookup[reversed_suffix], word_index])

        # Build solutions of case #3. This word will be word 1.
        for prefix in all_valid_prefixes(word):
            reversed_prefix = prefix[::-1]
            if reversed_prefix in word_lookup:
                solutions.append([word_index, word_lookup[reversed_prefix]])

    return solutions
```

</details>

<br>

## Approach 3: Using a Trie

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {
    public int wordEnding = -1; // We'll use -1 to mean there's no word ending here.
    public Map<Character, TrieNode> next = new HashMap<>();
    public List<Integer> palindromePrefixRemaining = new ArrayList<>();
}

class Solution {

    // Is the given string a palindrome after index i?
    // Tip: Leave this as a method stub in an interview unless you have time
    // or the interviewer tells you to write it. The Trie itself should be
    // the main focus of your time.
    public boolean hasPalindromeRemaining(String s, int i) {
        int p1 = i;
        int p2 = s.length() - 1;
        while (p1 < p2) {
            if (s.charAt(p1) != s.charAt(p2)) return false;
            p1++; p2--;
        }
        return true;
    }

    public List<List<Integer>> palindromePairs(String[] words) {

        TrieNode trie = new TrieNode();

        // Build the Trie
        for (int wordId = 0; wordId < words.length; wordId++) {
            String word = words[wordId];
            String reversedWord = new StringBuilder(word).reverse().toString();
            TrieNode currentTrieLevel = trie;
            for (int j = 0; j < word.length(); j++) {
                if (hasPalindromeRemaining(reversedWord, j)) {
                    currentTrieLevel.palindromePrefixRemaining.add(wordId);
                }
                Character c = reversedWord.charAt(j);
                if (!currentTrieLevel.next.containsKey(c)) {
                    currentTrieLevel.next.put(c, new TrieNode());
                }
                currentTrieLevel = currentTrieLevel.next.get(c);
            }
            currentTrieLevel.wordEnding = wordId;
        }

        // Find pairs
        List<List<Integer>> pairs = new ArrayList<>();
        for (int wordId = 0; wordId < words.length; wordId++) {
            String word = words[wordId];
            TrieNode currentTrieLevel = trie;
            for (int j = 0; j < word.length(); j++) {
                // Check for pairs of case 3.
                if (currentTrieLevel.wordEnding != -1
                   && hasPalindromeRemaining(word, j)) {
                    pairs.add(Arrays.asList(wordId, currentTrieLevel.wordEnding));
                }
                // Move down to the next trie level.
                Character c = word.charAt(j);
                currentTrieLevel = currentTrieLevel.next.get(c);
                if (currentTrieLevel == null) break;
            }
            if (currentTrieLevel == null) continue;
            // Check for pairs of case 1. Note the check to prevent non distinct pairs.
            if (currentTrieLevel.wordEnding != -1 && currentTrieLevel.wordEnding != wordId) {
                pairs.add(Arrays.asList(wordId, currentTrieLevel.wordEnding));
            }
            // Check for pairs of case 2.
            for (int other : currentTrieLevel.palindromePrefixRemaining) {
                pairs.add(Arrays.asList(wordId, other));
            }
        }

        return pairs;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class TrieNode:
    def __init__(self):
        self.next = collections.defaultdict(TrieNode)
        self.ending_word = -1
        self.palindrome_suffixes = []

class Solution:
    def palindromePairs(self, words):

        # Create the Trie and add the reverses of all the words.
        trie = TrieNode()
        for i, word in enumerate(words):
            word = word[::-1] # We want to insert the reverse.
            current_level = trie
            for j, c in enumerate(word):
                # Check if remainder of word is a palindrome.
                if word[j:] == word[j:][::-1]:# Is the word the same as its reverse?
                    current_level.palindrome_suffixes.append(i)
                # Move down the trie.
                current_level = current_level.next[c]
            current_level.ending_word = i

        # Look up each word in the Trie and find palindrome pairs.
        solutions = []
        for i, word in enumerate(words):
            current_level = trie
            for j, c in enumerate(word):
                # Check for case 3.
                if current_level.ending_word != -1:
                    if word[j:] == word[j:][::-1]: # Is the word the same as its reverse?
                        solutions.append([i, current_level.ending_word])
                if c not in current_level.next:
                    break
                current_level = current_level.next[c]
            else: # Case 1 and 2 only come up if whole word was iterated.
                # Check for case 1.
                if current_level.ending_word != -1 and current_level.ending_word != i:
                    solutions.append([i, current_level.ending_word])
                # Check for case 2.
                for j in current_level.palindrome_suffixes:
                    solutions.append([i, j])
        return solutions
```

</details>
