# 1048. Longest String Chain

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-string-chain/)  
`Array` `Hash Table` `Two Pointers` `String` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 1048 - Longest String Chain](https://leetcode.com/problems/longest-string-chain/)

## Problem

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

- For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

### Example 1

```text
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
```

### Example 2

```text
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
```

### Example 3

```text
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
```

## Constraints

- 1 <= words.length <= 1000
- 1 <= words[i].length <= 16
- words[i] only consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1048. Longest String Chain

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming (Recursion + Memoization) | C++, Java |
| Bottom-Up Dynamic Programming | C++, Java |

## Approach 1: Top-Down Dynamic Programming (Recursion + Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp

class Solution {
    
private:

    int dfs(unordered_set<string> &words, unordered_map<string, int> &memo, string currentWord) {
        // If the word is encountered previously we just return its value present in the map (memoization).
        if (memo.find(currentWord) != memo.end()) {
            return memo[currentWord];
        }
        // This stores the maximum length of word sequence possible with the 'currentWord' as the
        int maxLength = 1;

        // creating all possible strings taking out one character at a time from the `currentWord`
        for (int i = 0; i < currentWord.length(); i++) {
            string newWord = currentWord.substr(0, i) + currentWord.substr(i + 1);
            // If the new word formed is present in the list, we do a dfs search with this newWord.
            if (words.find(newWord) != words.end()) {
                int currentLength = 1 + dfs(words, memo, newWord);
                maxLength = max(maxLength, currentLength);
            }
        }
        memo[currentWord] = maxLength;

        return maxLength;
    }

public :
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> memo;
        unordered_set<string> wordsPresent;
        for (const string &word : words) {
            wordsPresent.insert(word);
        }
        int ans = 0;
        for (const string &word : words) {
            ans = max(ans, dfs(wordsPresent, memo, word));
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

    private int dfs(Set<String> words, Map<String, Integer> memo, String currentWord) {
        // If the word is encountered previously we just return its value present in the map (memoization).
        if (memo.containsKey(currentWord)) {
            return memo.get(currentWord);
        }
        // This stores the maximum length of word sequence possible with the 'currentWord' as the
        int maxLength = 1;
        StringBuilder sb = new StringBuilder(currentWord);

        // creating all possible strings taking out one character at a time from the `currentWord`
        for (int i = 0; i < currentWord.length(); i++) {
            sb.deleteCharAt(i);
            String newWord = sb.toString();
            // If the new word formed is present in the list, we do a dfs search with this newWord.
            if (words.contains(newWord)) {
                int currentLength = 1 + dfs(words, memo, newWord);
                maxLength = Math.max(maxLength, currentLength);
            }
            sb.insert(i, currentWord.charAt(i));
        }
        memo.put(currentWord, maxLength);

        return maxLength;
    }

    public int longestStrChain(String[] words) {
        Map<String, Integer> memo = new HashMap<>();
        Set<String> wordsPresent = new HashSet<>();
        Collections.addAll(wordsPresent, words);
        int ans = 0;
        for (String word : words) {
            ans = Math.max(ans, dfs(wordsPresent, memo, word));
        }
        return ans;
    }
}
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp

class Solution {

public :

    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> dp;

        // Sorting the list in terms of the word length.
        std::sort(words.begin(), words.end(), [](const std::string &word1, const std::string &word2) {
            return word1.size() < word2.size();
        });

        int longestWordSequenceLength = 1;

        for (const string &word : words) {
            int presentLength = 1;
            // Find all possible predecessors for the current word by removing one letter at a time.
            for (int i = 0; i < word.length(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1, word.length() + 1);
                if (dp.find(predecessor) != dp.end()) {
                    int previousLength = dp[predecessor];
                    presentLength = max(presentLength, previousLength + 1);
                }
            }
            dp[word] = presentLength;
            longestWordSequenceLength = max(longestWordSequenceLength, presentLength);
        }
        return longestWordSequenceLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java

class Solution {
    public int longestStrChain(String[] words) {
        Map<String, Integer> dp = new HashMap<>();

        // Sorting the list in terms of the word length.
        Arrays.sort(words, (a, b) -> a.length() - b.length());

        int longestWordSequenceLength = 1;

        for (String word : words) {
            int presentLength = 1;
            // Find all possible predecessors for the current word by removing one letter at a time.
            for (int i = 0; i < word.length(); i++) {
                StringBuilder temp = new StringBuilder(word);
                temp.deleteCharAt(i);
                String predecessor = temp.toString();
                int previousLength = dp.getOrDefault(predecessor, 0);
                presentLength = Math.max(presentLength, previousLength + 1);
            }
            dp.put(word, presentLength);
            longestWordSequenceLength = Math.max(longestWordSequenceLength, presentLength);
        }
        return longestWordSequenceLength;
    }
}
```

</details>
