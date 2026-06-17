# 1178. Number of Valid Words for Each Puzzle

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/)  
`Array` `Hash Table` `String` `Bit Manipulation` `Trie`

**Problem Link:** [LeetCode 1178 - Number of Valid Words for Each Puzzle](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/)

## Problem

- word contains the first letter of puzzle.
- For each letter in word, that letter is in puzzle.

		For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage", while
		invalid words are "beefed" (does not include 'a') and "based" (includes 's' which is not in the puzzle).

### Example 1

```text
Input: words = ["aaaa","asas","able","ability","actt","actor","access"], puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
Explanation:
1 valid word for "aboveyz" : "aaaa"
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There are no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
```

### Example 2

```text
Input: words = ["apple","pleas","please"], puzzles = ["aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"]
Output: [0,1,3,2,0]
```

## Constraints

- 1 <= words.length <= 105
- 4 <= words[i].length <= 50
- 1 <= puzzles.length <= 104
- puzzles[i].length == 7
- words[i] and puzzles[i] consist of lowercase English letters.
- Each puzzles[i] does not contain repeated characters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1178. Number of Valid Words for Each Puzzle

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashing (Bitmask) | C++, Java, Python3 |
| Trie | C++, Java, Python3 |

## Approach 1: Hashing (Bitmask)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int bitmask(const string& word) {
        // Build a bitmask of chars to represent each word
        // the builtin std::bitset also works
        int mask = 0;
        for (char letter : word) {
            mask |= 1 << (letter - 'a');
        }
        return mask;
    }

public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> wordCount;  // a vector instead of unordered_map also works
        for (string& word : words) {
            wordCount[bitmask(word)]++;
        }
        vector<int> result;
        for (string& puzzle : puzzles) {
            int first = 1 << (puzzle[0] - 'a');
            int count = wordCount[first];

            // Make bitmask but ignore the first character since it must always be there.
            int mask = bitmask(puzzle.substr(1));

            // iterate over the submask
            for (int submask = mask; submask; submask = (submask - 1) & mask) {
                count += wordCount[submask | first];  // add first character
            }
            result.push_back(count);
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
    private int bitmask(String word) {
        // Build a bitmask of chars to represent each word
        // the builtin std::bitset also works
        int mask = 0;
        for (char letter : word.toCharArray()) {
            mask |= 1 << (letter - 'a');
        }
        return mask;
    }

    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer, Integer> wordCount = new HashMap<>(); // a vector instead of unordered_map also works
        for (String word : words) {
            int mask = bitmask(word);
            wordCount.put(mask, wordCount.getOrDefault(mask, 0) + 1);
        }
        List<Integer> result = new ArrayList<>();
        for (String puzzle : puzzles) {
            int first = 1 << (puzzle.charAt(0) - 'a');
            int count = wordCount.getOrDefault(first, 0);

            // Make bitmask but ignore the first character since it must always be there.
            int mask = bitmask(puzzle.substring(1));

            // iterate over the submask
            for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                count += wordCount.getOrDefault(submask | first, 0); // add first character
            }
            result.add(count);
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:

        def bitmask(word: str) -> int:
            mask = 0
            for letter in word:
                mask |= 1 << (ord(letter) - ord('a'))
            return mask

        # Create a bitmask for each word.
        word_count = Counter(bitmask(word) for word in words)

        result = []
        for puzzle in puzzles:
            first = 1 << (ord(puzzle[0]) - ord('a'))
            count = word_count[first]

            # Make bitmask but ignore the first character since it must always
            # be there.
            mask = bitmask(puzzle[1:])

            # Iterate over every possible subset of characters.
            submask = mask
            while submask:
                # Increment the count by the number of words that match the
                # current submask.
                count += word_count[submask | first]  # add first character
                submask = (submask - 1) & mask
            result.append(count)
        return result
```

</details>

<br>

## Approach 2: Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int SIZE = 26;                                   // total character size
        vector<vector<int>> trie = {vector<int>(SIZE)};  // we use vector to mimic the trie tree
        vector<int> count = {0};                         // the number of words ending at node i
        for (string word : words) {  // we do not use reference here to avoid modifying the input
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
            if (word.size() <= 7) {  // longer words are never valid
                // insert into trie
                int node = 0;
                for (char& letter : word) {
                    int i = letter - 'a';
                    if (trie[node][i] == 0) {  // push empty node
                        trie.push_back(vector<int>(SIZE));
                        count.push_back(0);
                        trie[node][i] = trie.size() - 1;
                    }
                    node = trie[node][i];
                }
                count[node]++;
            }
        }
        // search for valid words
        function<int(int, bool, string&)> dfs = [&](int node, bool hasFirst, string& puzzle) {
            int total = hasFirst ? count[node] : 0;
            for (char& letter : puzzle) {
                int i = letter - 'a';
                if (trie[node][i]) {
                    total += dfs(trie[node][i], hasFirst || (letter == puzzle[0]), puzzle);
                }
            }
            return total;
        };
        vector<int> result;
        for (string& puzzle : puzzles) {
            result.push_back(dfs(0, false, puzzle));
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
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        int SIZE = 26; // total character size
        ArrayList<Integer[]> trie = new ArrayList<>(); // we use list to mimic the trie tree
        trie.add(Collections.nCopies(SIZE, 0).toArray(new Integer[0]));
        ArrayList<Integer> count = new ArrayList<>(List.of(0)); // the number of words ending at node i
        for (String word : words) {
            // sort and remove duplicates
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            StringBuilder sb = new StringBuilder();
            sb.append(chars[0]);
            for (int i = 1; i < chars.length; i++) {
                if (chars[i] != chars[i - 1]) {
                    sb.append(chars[i]);
                }
            }
            if (sb.length() <= 7) { // longer words are never valid
                // insert into trie
                int node = 0;
                for (char letter : sb.toString().toCharArray()) {
                    int i = letter - 'a';
                    if (trie.get(node)[i] == 0) { // push empty node
                        trie.add(Collections.nCopies(SIZE, 0).toArray(new Integer[0]));
                        count.add(0);
                        trie.get(node)[i] = trie.size() - 1;
                    }
                    node = trie.get(node)[i];
                }
                count.set(node, count.get(node) + 1);
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        for (String puzzle : puzzles) {
            result.add(dfs(0, false, puzzle, trie, count));
        }
        return result;
    }

    // search for valid words
    int dfs(int node, boolean hasFirst, String puzzle, List<Integer[]> trie, List<Integer> cnt) {
        int total = hasFirst ? cnt.get(node) : 0;
        for (char letter : puzzle.toCharArray()) {
            int i = letter - 'a';
            if (trie.get(node)[i] > 0) {
                total += dfs(trie.get(node)[i], hasFirst || (letter == puzzle.charAt(0)), puzzle, trie, cnt);
            }
        }
        return total;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        SIZE = 26  # 26 letters in the alphabet
        trie = [[0] * SIZE]  # we use list to mimic the trie tree
        count = [0]  # the number of words ending at node i
        for word in words:
            word = sorted(set(word))
            if len(word) <= 7:  # longer words are never valid
                # insert into trie
                node = 0
                for letter in word:
                    i = ord(letter) - ord('a')
                    if trie[node][i] == 0:  # push empty node
                        trie.append([0] * SIZE)
                        count.append(0)
                        trie[node][i] = len(trie) - 1
                    node = trie[node][i]
                count[node] += 1

        # search for valid words
        def dfs(node, has_first):
            total = count[node] if has_first else 0
            for letter in puzzle:  # catch puzzle from outside environment
                i = ord(letter) - ord('a')
                if trie[node][i]:
                    total += dfs(trie[node][i], has_first or letter == puzzle[0])
            return total

        result = []
        for puzzle in puzzles:
            result.append(dfs(0, False))
        return result
```

</details>
