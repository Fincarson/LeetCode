# 1639. Number of Ways to Form a Target String Given a Dictionary

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/)  
`Array` `String` `Dynamic Programming`

**Problem Link:** [LeetCode 1639 - Number of Ways to Form a Target String Given a Dictionary](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/)

## Problem

You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

- target should be formed from left to right.
- To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
- Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
- Repeat the process until you form the string target.

Notice that you can use multiple characters from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

### Example 1

```text
Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
```

### Example 2

```text
Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
```

## Constraints

- 1 <= words.length <= 1000
- 1 <= words[i].length <= 1000
- All strings in words have the same length.
- 1 <= target.length <= 1000
- words[i] and target contain only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1639. Number of Ways to Form a Target String Given a Dictionary

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-down Dynamic Programming | C++, Java, Python3 |
| Bottom-up Dynamic Programming | C++, Java, Python3 |
| Optimized Bottom-up Dynamic Programming | C++, Java, Python3 |

## Approach 1: Top-down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> dp(words[0].size(), vector<int>(target.size(), -1));
        vector<vector<int>> charFrequency(words[0].size(), vector<int>(26, 0));

        // Store the frequency of every character at every index.
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[0].size(); j++) {
                int character = words[i][j] - 'a';
                charFrequency[j][character]++;
            }
        }
        return getWords(words, target, 0, 0, dp, charFrequency);
    }

private:
    long getWords(vector<string>& words, string& target, int wordsIndex,
                  int targetIndex, vector<vector<int>>& dp,
                  vector<vector<int>>& charFrequency) {
        if (targetIndex == target.size()) return 1;
        if (wordsIndex == words[0].size() ||
            words[0].size() - wordsIndex < target.size() - targetIndex)
            return 0;

        if (dp[wordsIndex][targetIndex] != -1)
            return dp[wordsIndex][targetIndex];

        long countWays = 0;
        int curPos = target[targetIndex] - 'a';
        // Don't match any character of target with any word.
        countWays += getWords(words, target, wordsIndex + 1, targetIndex, dp,
                              charFrequency);
        // Multiply the number of choices with getWords and add it to count.
        countWays += charFrequency[wordsIndex][curPos] *
                     getWords(words, target, wordsIndex + 1, targetIndex + 1,
                              dp, charFrequency);

        return dp[wordsIndex][targetIndex] = countWays % 1000000007;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int numWays(String[] words, String target) {
        int wordLength = words[0].length();
        int targetLength = target.length();

        // Initialize DP table and frequency table
        int[][] dp = new int[wordLength][targetLength];
        for (int i = 0; i < wordLength; i++) {
            Arrays.fill(dp[i], -1);
        }
        int[][] charFrequency = new int[wordLength][26];

        // Store the frequency of every character at each index in the words
        for (String word : words) {
            for (int j = 0; j < wordLength; j++) {
                int character = word.charAt(j) - 'a';
                charFrequency[j][character]++;
            }
        }

        return (int) getWords(words, target, 0, 0, dp, charFrequency);
    }

    private long getWords(
        String[] words,
        String target,
        int wordsIndex,
        int targetIndex,
        int[][] dp,
        int[][] charFrequency
    ) {
        int MOD = 1000000007;

        // If the target is fully matched
        if (targetIndex == target.length()) return 1;

        // If we have no more columns in the words or not enough columns left to match
        // the target
        if (
            wordsIndex == words[0].length() ||
            words[0].length() - wordsIndex < target.length() - targetIndex
        ) return 0;

        // If already computed, return the stored result
        if (
            dp[wordsIndex][targetIndex] != -1
        ) return dp[wordsIndex][targetIndex];

        long countWays = 0;
        int curPos = target.charAt(targetIndex) - 'a';

        // Don't match any character of the target with the current word column
        countWays += getWords(
            words,
            target,
            wordsIndex + 1,
            targetIndex,
            dp,
            charFrequency
        );

        // Match the current character of the target with the current word column
        countWays +=
            charFrequency[wordsIndex][curPos] *
            getWords(
                words,
                target,
                wordsIndex + 1,
                targetIndex + 1,
                dp,
                charFrequency
            );

        // Store the result in dp and return the answer
        dp[wordsIndex][targetIndex] = (int) (countWays % MOD);

        return dp[wordsIndex][targetIndex];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWays(self, words, target):

        dp = [[-1] * len(target) for _ in range(len(words[0]))]
        char_frequency = [[0] * 26 for _ in range(len(words[0]))]

        # Store the frequency of every character at every index.
        for i in range(len(words)):
            for j in range(len(words[0])):
                character = ord(words[i][j]) - 97
                char_frequency[j][character] += 1
        return self.__get_words(words, target, 0, 0, dp, char_frequency)

    def __get_words(
        self, words, target, words_index, target_index, dp, char_frequency
    ):
        if target_index == len(target):
            return 1
        if (
            words_index == len(words[0])
            or len(words[0]) - words_index < len(target) - target_index
        ):
            return 0

        if dp[words_index][target_index] != -1:
            return dp[words_index][target_index]

        count_ways = 0
        cur_pos = ord(target[target_index]) - 97
        # Don't match any character of target with any word.
        count_ways += self.__get_words(
            words, target, words_index + 1, target_index, dp, char_frequency
        )
        # Multiply the number of choices with getWords and add it to count.
        count_ways += char_frequency[words_index][cur_pos] * self.__get_words(
            words, target, words_index + 1, target_index + 1, dp, char_frequency
        )

        dp[words_index][target_index] = count_ways % 1000000007
        return dp[words_index][target_index]
```

</details>

<br>

## Approach 2: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.size();
        const int MOD = 1000000007;

        // Step 1: Calculate frequency of each character at every index in
        // "words".
        vector<vector<int>> charFrequency(wordLength, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFrequency[j][word[j] - 'a']++;
            }
        }

        // Step 2: Initialize a DP table.
        vector<vector<long>> dp(wordLength + 1,
                                vector<long>(targetLength + 1, 0));

        // Base case: There is one way to form an empty target string.
        for (int currWord = 0; currWord <= wordLength; ++currWord) {
            dp[currWord][0] = 1;
        }

        // Step 3: Fill the DP table.
        for (int currWord = 1; currWord <= wordLength; ++currWord) {
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget) {
                // Carry over the previous value (not using this index of
                // "words").
                dp[currWord][currTarget] = dp[currWord - 1][currTarget];

                // Add ways using the current index of "words" if the characters
                // match.
                int curPos = target[currTarget - 1] - 'a';
                dp[currWord][currTarget] +=
                    (charFrequency[currWord - 1][curPos] *
                     dp[currWord - 1][currTarget - 1]) %
                    MOD;
                dp[currWord][currTarget] %= MOD;
            }
        }

        // Step 4: The result is in dp[wordLength][targetLength].
        return dp[wordLength][targetLength];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numWays(String[] words, String target) {
        int wordLength = words[0].length();
        int targetLength = target.length();
        final int MOD = 1000000007;

        // Step 1: Calculate frequency of each character at every index in
        // "words".
        int[][] charFrequency = new int[wordLength][26];
        for (String word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFrequency[j][word.charAt(j) - 'a']++;
            }
        }

        // Step 2: Initialize a DP table.
        long[][] dp = new long[wordLength + 1][targetLength + 1];

        // Base case: There is one way to form an empty target string.
        for (int currWord = 0; currWord <= wordLength; ++currWord) {
            dp[currWord][0] = 1;
        }

        // Step 3: Fill the DP table.
        for (int currWord = 1; currWord <= wordLength; ++currWord) {
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget) {
                // Carry over the previous value (not using this index of
                // "words").
                dp[currWord][currTarget] = dp[currWord - 1][currTarget];

                // Add ways using the current index of "words" if the characters
                // match.
                int curPos = target.charAt(currTarget - 1) - 'a';
                dp[currWord][currTarget] +=
                    (charFrequency[currWord - 1][curPos] *
                        dp[currWord - 1][currTarget - 1]) %
                    MOD;
                dp[currWord][currTarget] %= MOD;
            }
        }

        // Step 4: The result is in dp[wordLength][targetLength].
        return (int) dp[wordLength][targetLength];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        word_length = len(words[0])
        target_length = len(target)
        mod = 1000000007

        # Step 1: Calculate frequency of each character at every index in
        # "words".
        char_frequency = [[0] * 26 for _ in range(word_length)]
        for word in words:
            for j in range(word_length):
                char_frequency[j][ord(word[j]) - ord("a")] += 1

        # Step 2: Initialize a DP table.
        dp = [[0] * (target_length + 1) for _ in range(word_length + 1)]

        # Base case: There is one way to form an empty target string.
        for curr_word in range(word_length + 1):
            dp[curr_word][0] = 1

        # Step 3: Fill the DP table.
        for curr_word in range(1, word_length + 1):
            for curr_target in range(1, target_length + 1):
                # Carry over the previous value (not using this index of
                # "words").
                dp[curr_word][curr_target] = dp[curr_word - 1][curr_target]

                # Add ways using the current index of "words" if the characters
                # match.
                cur_pos = ord(target[curr_target - 1]) - ord("a")
                dp[curr_word][curr_target] += (
                    char_frequency[curr_word - 1][cur_pos]
                    * dp[curr_word - 1][curr_target - 1]
                ) % mod
                dp[curr_word][curr_target] %= mod

        # Step 4: The result is in dp[word_length][target_length].
        return dp[word_length][target_length]
```

</details>

<br>

## Approach 3: Optimized Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.size();
        const int MOD = 1000000007;

        // Step 1: Calculate frequency of each character at every index in
        // "words".
        vector<vector<int>> charFrequency(wordLength, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFrequency[j][word[j] - 'a']++;
            }
        }

        // Step 2: Initialize two DP arrays: prev and curr.
        vector<long> prevCount(targetLength + 1, 0);
        vector<long> currCount(targetLength + 1, 0);

        // Base case: There is one way to form an empty target string.
        prevCount[0] = 1;

        // Step 3: Fill the DP arrays.
        for (int currWord = 1; currWord <= wordLength; ++currWord) {
            // Copy the previous row into the current row for DP.
            currCount = prevCount;
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget) {
                // If characters match, add the number of ways.
                int curPos = target[currTarget - 1] - 'a';
                currCount[currTarget] += (charFrequency[currWord - 1][curPos] *
                                          prevCount[currTarget - 1]) %
                                         MOD;
                currCount[currTarget] %= MOD;
            }
            // Move current row to previous row for the next iteration.
            prevCount = currCount;
        }

        // Step 4: The result is in prev[targetLength].
        return currCount[targetLength];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numWays(String[] words, String target) {
        int wordLength = words[0].length();
        int targetLength = target.length();

        final int MOD = 1_000_000_007;

        //Step 1: Calculate frequency of each character at every index in "words".
        int[][] charFrequency = new int[wordLength][26];
        for (String word : words) {
            for (int j = 0; j < wordLength; j++) {
                charFrequency[j][word.charAt(j) - 'a']++;
            }
        }

        //Step 2: Initialize two DP arrays: prev and curr.
        long[] prevCount = new long[targetLength + 1];
        long[] currCount = new long[targetLength + 1];

        //Base case: There is one way to form an empty target string.
        prevCount[0] = 1;

        //Step 3: Fill the DP arrays.
        for (int currWord = 1; currWord <= wordLength; currWord++) {
            // Copy the previous row into the current row for DP.
            System.arraycopy(prevCount, 0, currCount, 0, currCount.length);
            for (int currTarget = 1; currTarget <= targetLength; currTarget++) {
                // If characters match, add the number of ways.
                int curPos = target.charAt(currTarget - 1) - 'a';
                currCount[currTarget] +=
                    (1L *
                        charFrequency[currWord - 1][curPos] *
                        prevCount[currTarget - 1]) %
                    MOD;
                currCount[currTarget] %= MOD;
            }
            // Move current row to previous row for the next iteration.
            System.arraycopy(currCount, 0, prevCount, 0, prevCount.length);
        }

        //Step 4: The result is in prev[targetLength].
        return (int) prevCount[targetLength];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 1000000007
        word_length = len(words[0])
        target_length = len(target)
        char_frequency = [[0] * 26 for _ in range(word_length)]

        # Step 1: Calculate frequency of each character at every index in "words".
        for word in words:
            for j in range(word_length):
                char_frequency[j][ord(word[j]) - ord("a")] += 1

        # Step 2: Initialize two DP arrays: prev_count and curr_count.
        prev_count = [0] * (target_length + 1)
        curr_count = [0] * (target_length + 1)

        # Base case: There is one way to form an empty target string.
        prev_count[0] = 1

        # Step 3: Fill the DP arrays.
        for curr_word in range(1, word_length + 1):
            curr_count = prev_count.copy()
            for curr_target in range(1, target_length + 1):
                cur_pos = ord(target[curr_target - 1]) - ord("a")

                # If characters match, add the number of ways.
                curr_count[curr_target] += (
                    char_frequency[curr_word - 1][cur_pos]
                    * prev_count[curr_target - 1]
                ) % MOD
                curr_count[curr_target] %= MOD

            # Move current row to previous row for the next iteration.
            prev_count = curr_count.copy()

        # Step 4: The result is in prev[target_length].
        return curr_count[target_length]
```

</details>
