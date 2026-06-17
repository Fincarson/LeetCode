# 1255. Maximum Score Words Formed by Letters

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-score-words-formed-by-letters/)  
`Array` `Hash Table` `String` `Dynamic Programming` `Backtracking` `Bit Manipulation` `Counting` `Bitmask`

**Problem Link:** [LeetCode 1255 - Maximum Score Words Formed by Letters](https://leetcode.com/problems/maximum-score-words-formed-by-letters/)

## Problem

Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

### Example 1

```text
Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.
```

### Example 2

```text
Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
Output: 27
Explanation:
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.
```

### Example 3

```text
Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
Output: 0
Explanation:
Letter "e" can only be used once.
```

## Constraints

- 1 <= words.length <= 14
- 1 <= words[i].length <= 15
- 1 <= letters.length <= 100
- letters[i].length == 1
- score.length == 26
- 0 <= score[i] <= 10
- words[i], letters[i] contains only lower case English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Good People Based on Statements](https://leetcode.com/problems/maximum-good-people-based-on-statements/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1255. Maximum Score Words Formed by Letters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Loop for Every Subset | C++, Java, Python3 |
| Backtracking | C++, Java, Python3 |

## Approach 1: Iterative Loop for Every Subset

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        int W = words.size();
        // Count how many times each letter occurs
        vector<int> freq(26, 0);
        for (char c : letters) {
            freq[c - 'a']++;
        }
        int maxScore = 0;
        // Iterate over every subset of words
        vector<int> subsetLetters(26, 0);
        for (int mask = 0; mask < (1 << W); mask++) {
            // Reset the subsetLetters array
            fill(subsetLetters.begin(), subsetLetters.end(), 0);
            for (int i = 0; i < W; i++) {
                if ((mask & (1 << i)) > 0) {
                    // Count the letters in this word
                    int L = words[i].length();
                    for (int j = 0; j < L; j++) {
                        subsetLetters[words[i][j] - 'a']++;
                    }
                }
            }
            maxScore = max(maxScore, subsetScore(subsetLetters, score, freq));
        }
        return maxScore;
    }

private:
    int subsetScore(vector<int>& subsetLetters, vector<int>& score,
                    vector<int>& freq) {
        int totalScore = 0;
        // Calculate score of subset
        for (int c = 0; c < 26; c++) {
            totalScore += subsetLetters[c] * score[c];
            // Check if we have enough of each letter to build this subset of
            // words
            if (subsetLetters[c] > freq[c]) {
                return 0;
            }
        }
        return totalScore;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int W = words.length;
        // Count how many times each letter occurs
        int[] freq = new int[26];
        for (char c : letters) {
            freq[c - 'a']++;
        }
        int maxScore = 0;
        // Iterate over every subset of words
        int[] subsetLetters = new int[26];
        for (int mask = 0; mask < 1 << W; mask++) {
            // Reset the subsetLetters array
            Arrays.fill(subsetLetters, 0);
            for (int i = 0; i < W; i++) {
                if ((mask & (1 << i)) > 0) {
                    // Count the letters in this word
                    int L = words[i].length();
                    for (int j = 0; j < L; j++) {
                        subsetLetters[words[i].charAt(j) - 'a']++;
                    }
                }
            }
            maxScore = Math.max(
                maxScore,
                subsetScore(subsetLetters, score, freq)
            );
        }
        return maxScore;
    }

    private int subsetScore(int[] subsetLetters, int[] score, int[] freq) {
        int totalScore = 0;
        // Calculate score of subset
        for (int c = 0; c < 26; c++) {
            totalScore += subsetLetters[c] * score[c];
            // Check if we have enough of each letter to build this subset of words
            if (subsetLetters[c] > freq[c]) {
                return 0;
            }
        }
        return totalScore;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxScoreWords(
        self, words: List[str], letters: List[str], score: List[int]
    ) -> int:
        W = len(words)

        # Count how many times each letter occurs
        freq = [0 for i in range(26)]
        for c in letters:
            freq[ord(c) - 97] += 1

        # Calculate score of subset
        def subset_score(subset_letters, score, freq):
            total_score = 0
            for c in range(26):
                total_score += subset_letters[c] * score[c]

                # Check if we have enough of each letter
                # to build this subset of words
                if subset_letters[c] > freq[c]:
                    return 0
            return total_score

        max_score = 0

        # Iterate over every subset of words
        subset_letters = {}
        for mask in range(1 << W):

            # Reset the subset_letters map
            subset_letters = [0 for i in range(26)]

            # Find words in this subset
            for i in range(W):
                if (mask & (1 << i)) > 0:

                    # Count the letters in this word
                    L = len(words[i])
                    for j in range(L):
                        subset_letters[ord(words[i][j]) - 97] += 1

            # Calculate score of subset
            max_score = max(
                max_score, subset_score(subset_letters, score, freq)
            )

        # Return max_score as the result
        return max_score
```

</details>

<br>

## Approach 2: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        int W = words.size();
        maxScore = 0;
        freq = vector<int>(26, 0);
        vector<int> subsetLetters = vector<int>(26, 0);
        // Count how many times each letter occurs
        for (char c : letters) {
            freq[c - 'a']++;
        }
        check(W - 1, words, score, subsetLetters, 0);
        return maxScore;
    }

private:
    int maxScore;
    vector<int> freq;

    // Check if adding this word exceeds the frequency of any letter
    bool isValidWord(vector<int>& subsetLetters) {
        for (int c = 0; c < 26; c++) {
            if (freq[c] < subsetLetters[c]) {
                return false;
            }
        }
        return true;
    }

    void check(int w, vector<string>& words, vector<int>& score,
               vector<int>& subsetLetters, int totalScore) {
        if (w == -1) {
            // If all words have been iterated, check the score of this subset
            maxScore = max(maxScore, totalScore);
            return;
        }
        // Not adding words[w] to the current subset
        check(w - 1, words, score, subsetLetters, totalScore);
        // Adding words[w] to the current subset
        int L = words[w].length();
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            subsetLetters[c]++;
            totalScore += score[c];
        }

        if (isValidWord(subsetLetters)) {
            // Consider the next word if this subset is still valid
            check(w - 1, words, score, subsetLetters, totalScore);
        }
        // Rollback effects of this word
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            subsetLetters[c]--;
            totalScore -= score[c];
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int W = words.length;
        // Count how many times each letter occurs
        freq = new int[26];
        for (char c : letters) {
            freq[c - 'a']++;
        }
        maxScore = 0;
        check(W - 1, words, score, new int[26], 0);
        return maxScore;
    }

    // Check if adding this word exceeds the frequency of any letter
    private boolean isValidWord(int[] subsetLetters) {
        for (int c = 0; c < 26; c++) {
            if (freq[c] < subsetLetters[c]) {
                return false;
            }
        }
        return true;
    }

    private int maxScore;
    private int[] freq;

    private void check(
        int w,
        String[] words,
        int[] score,
        int[] subsetLetters,
        int totalScore
    ) {
        if (w == -1) {
            // If all words have been iterated, check the score of this subset
            maxScore = Math.max(maxScore, totalScore);
            return;
        }
        // Not adding words[w] to the current subset
        check(w - 1, words, score, subsetLetters, totalScore);
        // Adding words[w] to the current subset
        int L = words[w].length();
        for (int i = 0; i < L; i++) {
            int c = words[w].charAt(i) - 'a';
            subsetLetters[c]++;
            totalScore += score[c];
        }

        if (isValidWord(subsetLetters)) {
            // Consider the next word if this subset is still valid
            check(w - 1, words, score, subsetLetters, totalScore);
        }
        // Rollback effects of this word
        for (int i = 0; i < L; i++) {
            int c = words[w].charAt(i) - 'a';
            subsetLetters[c]--;
            totalScore -= score[c];
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxScoreWords(
        self, words: List[str], letters: List[str], score: List[int]
    ) -> int:
        W = len(words)
        # Count how many times each letter occurs
        self.max_score = 0
        freq = [0 for i in range(26)]
        subset_letters = [0 for i in range(26)]
        for c in letters:
            freq[ord(c) - 97] += 1

        # Check if adding this word exceeds the frequency of any letter
        def is_valid_word(subset_letters):
            for c in range(26):
                if freq[c] < subset_letters[c]:
                    return False
            else:
                return True

        def check(w, words, score, subset_letters, total_score):
            if w == -1:
                # If all words have been iterated,
                # check the score of this subset
                self.max_score = max(self.max_score, total_score)
                return
            # Not adding words[w] to the current subset
            check(w - 1, words, score, subset_letters, total_score)
            # Adding words[w] to the current subset
            L = len(words[w])
            for i in range(L):
                c = ord(words[w][i]) - 97
                subset_letters[c] += 1
                total_score += score[c]
            if is_valid_word(subset_letters):
                # Consider the next word if this subset is still valid
                check(w - 1, words, score, subset_letters, total_score)
            # Rollback effects of this word
            for i in range(L):
                c = ord(words[w][i]) - 97
                subset_letters[c] -= 1
                total_score -= score[c]

        check(W - 1, words, score, subset_letters, 0)
        # Return max_score as the result
        return self.max_score
```

</details>
