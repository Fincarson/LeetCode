# 212. Word Search II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/word-search-ii/)  
`Array` `String` `Backtracking` `Trie` `Matrix`

**Problem Link:** [LeetCode 212 - Word Search II](https://leetcode.com/problems/word-search-ii/)

## Problem

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

### Example 1

```text
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
```

### Example 2

```text
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
```

## Constraints

- m == board.length
- n == board[i].length
- 1 <= m, n <= 12
- board[i][j] is a lowercase English letter.
- 1 <= words.length <= 3 * 104
- 1 <= words[i].length <= 10
- words[i] consists of lowercase English letters.
- All the strings of words are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Search](https://leetcode.com/problems/word-search/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Unique Paths III](https://leetcode.com/problems/unique-paths-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Encrypt and Decrypt Strings](https://leetcode.com/problems/encrypt-and-decrypt-strings/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 212. Word Search II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking with Trie | C++, Java, Python3 |

## Approach 1: Backtracking with Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;

    TrieNode() : word("") {}
};

class Solution {
private:
    vector<vector<char>> _board;
    vector<string> _result;

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        // Step 1). Construct the Trie
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            TrieNode* node = root;
            for (char letter : word) {
                if (node->children.find(letter) != node->children.end()) {
                    node = node->children[letter];
                } else {
                    TrieNode* newNode = new TrieNode();
                    node->children[letter] = newNode;
                    node = newNode;
                }
            }
            node->word = word;  // store words in Trie
        }

        this->_board = board;
        // Step 2). Backtracking starting for each cell in the board
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                if (root->children.find(board[row][col]) !=
                    root->children.end()) {
                    backtracking(row, col, root);
                }
            }
        }

        return this->_result;
    }

private:
    void backtracking(int row, int col, TrieNode* parent) {
        char letter = this->_board[row][col];
        TrieNode* currNode = parent->children[letter];

        // check if there is any match
        if (currNode->word != "") {
            this->_result.push_back(currNode->word);
            currNode->word = "";  // prevent duplicate entries
        }

        // mark the current letter before the EXPLORATION
        this->_board[row][col] = '#';

        // explore neighbor cells in around-clock directions: up, right, down,
        // left
        int rowOffset[] = {-1, 0, 1, 0};
        int colOffset[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int newRow = row + rowOffset[i];
            int newCol = col + colOffset[i];
            if (newRow < 0 || newRow >= this->_board.size() || newCol < 0 ||
                newCol >= this->_board[0].size()) {
                continue;
            }
            if (currNode->children.find(this->_board[newRow][newCol]) !=
                currNode->children.end()) {
                backtracking(newRow, newCol, currNode);
            }
        }

        // End of EXPLORATION, restore the original letter in the board.
        this->_board[row][col] = letter;

        // Optimization: incrementally remove the leaf nodes
        if (currNode->children.empty()) {
            parent->children.erase(letter);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {

    HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
    String word = null;

    public TrieNode() {}
}

class Solution {

    char[][] _board = null;
    ArrayList<String> _result = new ArrayList<String>();

    public List<String> findWords(char[][] board, String[] words) {
        // Step 1). Construct the Trie
        TrieNode root = new TrieNode();
        for (String word : words) {
            TrieNode node = root;

            for (Character letter : word.toCharArray()) {
                if (node.children.containsKey(letter)) {
                    node = node.children.get(letter);
                } else {
                    TrieNode newNode = new TrieNode();
                    node.children.put(letter, newNode);
                    node = newNode;
                }
            }
            node.word = word; // store words in Trie
        }

        this._board = board;
        // Step 2). Backtracking starting for each cell in the board
        for (int row = 0; row < board.length; ++row) {
            for (int col = 0; col < board[row].length; ++col) {
                if (root.children.containsKey(board[row][col])) {
                    backtracking(row, col, root);
                }
            }
        }

        return this._result;
    }

    private void backtracking(int row, int col, TrieNode parent) {
        Character letter = this._board[row][col];
        TrieNode currNode = parent.children.get(letter);

        // check if there is any match
        if (currNode.word != null) {
            this._result.add(currNode.word);
            currNode.word = null;
        }

        // mark the current letter before the EXPLORATION
        this._board[row][col] = '#';

        // explore neighbor cells in around-clock directions: up, right, down, left
        int[] rowOffset = { -1, 0, 1, 0 };
        int[] colOffset = { 0, 1, 0, -1 };
        for (int i = 0; i < 4; ++i) {
            int newRow = row + rowOffset[i];
            int newCol = col + colOffset[i];
            if (
                newRow < 0 ||
                newRow >= this._board.length ||
                newCol < 0 ||
                newCol >= this._board[0].length
            ) {
                continue;
            }
            if (currNode.children.containsKey(this._board[newRow][newCol])) {
                backtracking(newRow, newCol, currNode);
            }
        }

        // End of EXPLORATION, restore the original letter in the board.
        this._board[row][col] = letter;

        // Optimization: incrementally remove the leaf nodes
        if (currNode.children.isEmpty()) {
            parent.children.remove(letter);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        WORD_KEY = "$"

        trie = {}
        for word in words:
            node = trie
            for letter in word:
                # retrieve the next node; If not found, create a empty node.
                node = node.setdefault(letter, {})
            # mark the existence of a word in trie node
            node[WORD_KEY] = word

        rowNum = len(board)
        colNum = len(board[0])

        matchedWords = []

        def backtracking(row, col, parent):

            letter = board[row][col]
            currNode = parent[letter]

            # check if we find a match of word
            word_match = currNode.pop(WORD_KEY, False)
            if word_match:
                # also we removed the matched word to avoid duplicates,
                #   as well as avoiding using set() for results.
                matchedWords.append(word_match)

            # Before the EXPLORATION, mark the cell as visited
            board[row][col] = "#"

            # Explore the neighbors in 4 directions, i.e. up, right, down, left
            for rowOffset, colOffset in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
                newRow, newCol = row + rowOffset, col + colOffset
                if (
                    newRow < 0
                    or newRow >= rowNum
                    or newCol < 0
                    or newCol >= colNum
                ):
                    continue
                if not board[newRow][newCol] in currNode:
                    continue
                backtracking(newRow, newCol, currNode)

            # End of EXPLORATION, we restore the cell
            board[row][col] = letter

            # Optimization: incrementally remove the matched leaf node in Trie.
            if not currNode:
                parent.pop(letter)

        for row in range(rowNum):
            for col in range(colNum):
                # starting from each of the cells
                if board[row][col] in trie:
                    backtracking(row, col, trie)

        return matchedWords
```

</details>
