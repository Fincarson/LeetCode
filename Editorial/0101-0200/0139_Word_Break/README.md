# 139. Word Break

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/word-break/)  
`Array` `Hash Table` `String` `Dynamic Programming` `Trie` `Memoization`

**Problem Link:** [LeetCode 139 - Word Break](https://leetcode.com/problems/word-break/)

## Problem

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

### Example 1

```text
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

### Example 2

```text
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

### Example 3

```text
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

## Constraints

- 1 <= s.length <= 300
- 1 <= wordDict.length <= 1000
- 1 <= wordDict[i].length <= 20
- s and wordDict[i] consist of only lowercase English letters.
- All the strings of wordDict are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Break II](https://leetcode.com/problems/word-break-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Extra Characters in a String](https://leetcode.com/problems/extra-characters-in-a-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 139. Word Break

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Top-Down Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bottom-Up Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Trie Optimization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| A Different DP | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Breadth-First Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    int s_length = strlen(s);
    int *q = (int *)malloc(sizeof(int) * (s_length + 1));
    int q_front = 0;
    int q_back = 0;
    bool *at = (bool *)calloc(s_length + 1, sizeof(bool));
    q[q_back++] = 0;
    while (q_front != q_back) {
        int start = q[q_front++];
        if (start == s_length) {
            free(q);
            free(at);
            return true;
        }
        for (int end = start + 1; end <= s_length; end++) {
            if (at[end]) {
                continue;
            }
            int len = end - start;
            char *substr = (char *)malloc(sizeof(char) * (len + 1));
            strncpy(substr, s + start, len);
            substr[len] = '\0';
            for (int i = 0; i < wordDictSize; i++) {
                if (strcmp(substr, wordDict[i]) == 0) {
                    q[q_back++] = end;
                    at[end] = true;
                    break;
                }
            }
            free(substr);
        }
    }
    free(q);
    free(at);
    return false;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        queue<int> queue;
        vector<bool> seen(s.length(), false);
        queue.push(0);

        while (!queue.empty()) {
            int start = queue.front();
            queue.pop();

            if (start == s.length()) {
                return true;
            }

            for (int end = start + 1; end <= s.length(); end++) {
                if (seen[end]) {
                    continue;
                }

                if (words.find(s.substr(start, end - start)) != words.end()) {
                    queue.push(end);
                    seen[end] = true;
                }
            }
        }

        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        HashSet<string> words = new HashSet<string>(wordDict);
        Queue<int> queue = new Queue<int>();
        bool[] seen = new bool[s.Length + 1];
        queue.Enqueue(0);
        while (queue.Count != 0) {
            int start = queue.Dequeue();
            if (start == s.Length) {
                return true;
            }

            for (int end = start + 1; end <= s.Length; end++) {
                if (seen[end]) {
                    continue;
                }

                if (words.Contains(s.Substring(start, end - start))) {
                    queue.Enqueue(end);
                    seen[end] = true;
                }
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func wordBreak(s string, wordDict []string) bool {
    words := make(map[string]bool)
    queue := make([]int, 0)
    seen := make([]bool, len(s)+1)
    for _, word := range wordDict {
        words[word] = true
    }
    queue = append(queue, 0)
    for len(queue) > 0 {
        start := queue[0]
        queue = queue[1:]
        if start == len(s) {
            return true
        }
        for end := start + 1; end <= len(s); end++ {
            if seen[end] {
                continue
            }
            if _, ok := words[s[start:end]]; ok {
                queue = append(queue, end)
                seen[end] = true
            }
        }
    }
    return false
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<>(wordDict);
        Queue<Integer> queue = new LinkedList<>();
        boolean[] seen = new boolean[s.length() + 1];
        queue.add(0);

        while (!queue.isEmpty()) {
            int start = queue.remove();
            if (start == s.length()) {
                return true;
            }

            for (int end = start + 1; end <= s.length(); end++) {
                if (seen[end]) {
                    continue;
                }

                if (words.contains(s.substring(start, end))) {
                    queue.add(end);
                    seen[end] = true;
                }
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var wordBreak = function (s, wordDict) {
    let words = new Set(wordDict);
    let queue = [0];
    let seen = new Set();
    while (queue.length != 0) {
        let start = queue.shift();
        if (start == s.length) return true;
        for (let end = start + 1; end <= s.length; end++) {
            if (seen.has(end)) continue;
            if (words.has(s.substring(start, end))) {
                queue.push(end);
                seen.add(end);
            }
        }
    }
    return false;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        queue = deque([0])
        seen = set()

        while queue:
            start = queue.popleft()
            if start == len(s):
                return True

            for end in range(start + 1, len(s) + 1):
                if end in seen:
                    continue

                if s[start:end] in words:
                    queue.append(end)
                    seen.add(end)

        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function wordBreak(s: string, wordDict: string[]): boolean {
    let words = new Set(wordDict);
    let queue = [0];
    let seen = new Set();
    while (queue.length !== 0) {
        let start = queue.shift();
        if (start == s.length) return true;
        for (let end = start + 1; end <= s.length; end++) {
            if (seen.has(end)) continue;
            if (words.has(s.substring(start, end))) {
                queue.push(end);
                seen.add(end);
            }
        }
    }
    return false;
}
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX_LENGTH 1000
int memo[MAX_LENGTH];
int memoLength;
char* s;
char** wordDict;
int wordDictLen;
int isValid(int i) {
    if (i < 0) {
        return 1;
    }
    if (memo[i] != -1) {
        return memo[i];
    }
    for (int j = 0; j < wordDictLen; j++) {
        int wordLen = strlen(wordDict[j]);
        if (i - wordLen + 1 < 0) {
            continue;
        }
        if (strncmp(wordDict[j], s + i - wordLen + 1, wordLen) == 0 &&
            isValid(i - wordLen)) {
            memo[i] = 1;
            return 1;
        }
    }
    memo[i] = 0;
    return 0;
}
int wordBreak(char* _s, char** _wordDict, int _wordDictLen) {
    memset(memo, -1, sizeof(memo));
    memoLength = strlen(_s);
    s = _s;
    wordDict = _wordDict;
    wordDictLen = _wordDictLen;
    return isValid(memoLength - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> memo;
    vector<string> wordDict;
    string s;

    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector(s.length(), -1);
        this->wordDict = wordDict;
        this->s = s;
        return dp(s.length() - 1);
    }

    bool dp(int i) {
        if (i < 0) return true;

        if (memo[i] != -1) {
            return memo[i] == 1;
        }

        for (string word : wordDict) {
            int currSize = word.length();
            // Handle out of bounds case
            if (i - currSize + 1 < 0) {
                continue;
            }

            if (s.substr(i - currSize + 1, currSize) == word &&
                dp(i - currSize)) {
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private string s;
    private IList<string> wordDict;
    private int[] memo;

    private bool IsValid(int i) {
        if (i < 0) {
            return true;
        }

        if (memo[i] != -1) {
            return memo[i] == 1;
        }

        foreach (string word in wordDict) {
            // Handle out of bounds case
            if (i - word.Length + 1 < 0) {
                continue;
            }

            if (s.Substring(i - word.Length + 1, word.Length) == word &&
                IsValid(i - word.Length)) {
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
    }

    public bool WordBreak(string s, IList<string> wordDict) {
        this.s = s;
        this.wordDict = wordDict;
        this.memo = new int[s.Length];
        Array.Fill(this.memo, -1);
        return IsValid(s.Length - 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isValid(s string, wordDict []string, memo []int, i int) bool {
    if i < 0 {
        return true
    }
    if memo[i] != -1 {
        return memo[i] == 1
    }
    for _, word := range wordDict {
        wordLen := len(word)
        if i-wordLen+1 < 0 {
            continue
        }
        if s[i-wordLen+1:i+1] == word && isValid(s, wordDict, memo, i-wordLen) {
            memo[i] = 1
            return true
        }
    }
    memo[i] = 0
    return false
}

func wordBreak(s string, wordDict []string) bool {
    memo := make([]int, len(s))
    for i := range memo {
        memo[i] = -1
    }
    return isValid(s, wordDict, memo, len(s)-1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private String s;
    private List<String> wordDict;
    private int[] memo;

    private boolean dp(int i) {
        if (i < 0) return true;

        if (memo[i] != -1) {
            return memo[i] == 1;
        }

        for (String word : wordDict) {
            // Handle out of bounds case
            if (i - word.length() + 1 < 0) {
                continue;
            }

            if (
                s.substring(i - word.length() + 1, i + 1).equals(word) &&
                dp(i - word.length())
            ) {
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        this.s = s;
        this.wordDict = wordDict;
        this.memo = new int[s.length()];
        Arrays.fill(this.memo, -1);
        return dp(s.length() - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var wordBreak = function (s, wordDict) {
    let memo = new Array(s.length).fill(-1);
    function isValid(i) {
        if (i < 0) {
            return true;
        }
        if (memo[i] != -1) {
            return memo[i] === 1;
        }
        for (let word of wordDict) {
            let wordLen = word.length;
            if (i - wordLen + 1 < 0) {
                continue;
            }
            if (
                s.substring(i - wordLen + 1, i + 1) === word &&
                isValid(i - wordLen)
            ) {
                memo[i] = 1;
                return true;
            }
        }
        memo[i] = 0;
        return false;
    }
    return isValid(s.length - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        @cache
        def dp(i):
            if i < 0:
                return True

            for word in wordDict:
                if s[i - len(word) + 1 : i + 1] == word and dp(i - len(word)):
                    return True

            return False

        return dp(len(s) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function wordBreak(s: string, wordDict: string[]): boolean {
    let memo: number[] = new Array(s.length).fill(-1);
    function isValid(i: number): boolean {
        if (i < 0) {
            return true;
        }
        if (memo[i] != -1) {
            return memo[i] === 1;
        }
        for (let word of wordDict) {
            let wordLen: number = word.length;
            if (i - wordLen + 1 < 0) {
                continue;
            }
            if (
                s.substring(i - wordLen + 1, i + 1) === word &&
                isValid(i - wordLen)
            ) {
                memo[i] = 1;
                return true;
            }
        }
        memo[i] = 0;
        return false;
    }
    return isValid(s.length - 1);
}
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    int len = strlen(s);
    int *dp = (int *)malloc(sizeof(int) * len);
    memset(dp, 0, sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            int word_len = strlen(wordDict[j]);
            // Handle out of bounds case
            if (i < word_len - 1) {
                continue;
            }
            if (i == word_len - 1 || dp[i - word_len]) {
                if (strncmp(s + i - word_len + 1, wordDict[j], word_len) == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    bool result = dp[len - 1];
    free(dp);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            for (string word : wordDict) {
                // Handle out of bounds case
                if (i < word.length() - 1) {
                    continue;
                }

                if (i == word.length() - 1 || dp[i - word.length()]) {
                    if (s.substr(i - word.length() + 1, word.length()) ==
                        word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.length() - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        bool[] dp = new bool[s.Length];
        for (int i = 0; i < s.Length; i++) {
            foreach (string word in wordDict) {
                // Handle out of bounds case
                if (i < word.Length - 1) {
                    continue;
                }

                if (i == word.Length - 1 || dp[i - word.Length]) {
                    if (s.Substring(i - word.Length + 1, word.Length) == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.Length - 1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func wordBreak(s string, wordDict []string) bool {
    dp := make([]bool, len(s))
    for i := range s {
        for _, word := range wordDict {
            // Handle out of bounds case
            if i < len(word)-1 {
                continue
            }
            if i == len(word)-1 || dp[i-len(word)] {
                if s[i-len(word)+1:i+1] == word {
                    dp[i] = true
                    break
                }
            }
        }
    }
    return dp[len(s)-1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length()];
        for (int i = 0; i < s.length(); i++) {
            for (String word : wordDict) {
                // Handle out of bounds case
                if (i < word.length() - 1) {
                    continue;
                }

                if (i == word.length() - 1 || dp[i - word.length()]) {
                    if (
                        s.substring(i - word.length() + 1, i + 1).equals(word)
                    ) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.length() - 1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var wordBreak = function (s, wordDict) {
    let dp = new Array(s.length).fill(false);
    for (let i = 0; i < s.length; i++) {
        for (let word of wordDict) {
            // Handle out of bounds case
            if (i < word.length - 1) {
                continue;
            }
            if (i == word.length - 1 || dp[i - word.length]) {
                if (s.substring(i - word.length + 1, i + 1) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.length - 1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * len(s)
        for i in range(len(s)):
            for word in wordDict:
                # Handle out of bounds case
                if i < len(word) - 1:
                    continue

                if i == len(word) - 1 or dp[i - len(word)]:
                    if s[i - len(word) + 1 : i + 1] == word:
                        dp[i] = True
                        break

        return dp[-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function wordBreak(s: string, wordDict: string[]): boolean {
    let dp: boolean[] = new Array(s.length).fill(false);
    for (let i = 0; i < s.length; i++) {
        for (let word of wordDict) {
            // Handle out of bounds case
            if (i < word.length - 1) {
                continue;
            }
            if (i == word.length - 1 || dp[i - word.length]) {
                if (s.substring(i - word.length + 1, i + 1) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.length - 1];
}
```

</details>

<br>

## Approach 4: Trie Optimization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct TrieNode {
    bool isWord;
    struct TrieNode* children[26];
};
struct TrieNode* createNode() {
    struct TrieNode* node = malloc(sizeof(struct TrieNode));
    node->isWord = false;
    for (int i = 0; i < 26; ++i) {
        node->children[i] = NULL;
    }
    return node;
}
bool wordBreak(char* s, char* wordDict[], int wordDictSize) {
    struct TrieNode* root = createNode();
    for (int i = 0; i < wordDictSize; ++i) {
        char* word = wordDict[i];
        struct TrieNode* curr = root;
        for (int j = 0; word[j] != '\0'; j++) {
            char c = word[j];
            if (curr->children[c - 'a'] == NULL) {
                curr->children[c - 'a'] = createNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
    int strLength = strlen(s);
    bool dp[strLength];
    memset(dp, false, strLength);
    for (int i = 0; i < strLength; i++) {
        if (i == 0 || dp[i - 1]) {
            struct TrieNode* curr = root;
            for (int j = i; j < strLength; j++) {
                char c = s[j];
                if (curr->children[c - 'a'] == NULL) {
                    // No words exist
                    break;
                }
                curr = curr->children[c - 'a'];
                if (curr->isWord) {
                    dp[j] = true;
                }
            }
        }
    }
    return dp[strLength - 1];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isWord(false), children(unordered_map<char, TrieNode*>()) {}
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (string word : wordDict) {
            TrieNode* curr = root;
            for (char c : word) {
                if (curr->children.find(c) == curr->children.end()) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }

            curr->isWord = true;
        }

        vector<bool> dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || dp[i - 1]) {
                TrieNode* curr = root;
                for (int j = i; j < s.length(); j++) {
                    char c = s[j];
                    if (curr->children.find(c) == curr->children.end()) {
                        // No words exist
                        break;
                    }

                    curr = curr->children[c];
                    if (curr->isWord) {
                        dp[j] = true;
                    }
                }
            }
        }

        return dp[s.length() - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class TrieNode {
    public bool isWord;
    public Dictionary<char, TrieNode> children;

    public TrieNode() {
        this.children = new Dictionary<char, TrieNode>();
    }
}

public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        TrieNode root = new TrieNode();
        foreach (string word in wordDict) {
            TrieNode curr = root;
            foreach (char c in word) {
                if (!curr.children.ContainsKey(c)) {
                    curr.children[c] = new TrieNode();
                }

                curr = curr.children[c];
            }

            curr.isWord = true;
        }

        bool[] dp = new bool[s.Length];
        for (int i = 0; i < s.Length; i++) {
            if (i == 0 || dp[i - 1]) {
                TrieNode curr = root;
                for (int j = i; j < s.Length; j++) {
                    char c = s[j];
                    if (!curr.children.ContainsKey(c)) {
                        // No words exist
                        break;
                    }

                    curr = curr.children[c];
                    if (curr.isWord) {
                        dp[j] = true;
                    }
                }
            }
        }

        return dp[s.Length - 1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type TrieNode struct {
    isWord   bool
    children map[rune]*TrieNode
}

func wordBreak(s string, wordDict []string) bool {
    root := &TrieNode{children: make(map[rune]*TrieNode)}
    for _, word := range wordDict {
        curr := root
        for _, c := range word {
            if _, ok := curr.children[c]; !ok {
                curr.children[c] = &TrieNode{children: make(map[rune]*TrieNode)}
            }
            curr = curr.children[c]
        }
        curr.isWord = true
    }
    dp := make([]bool, len(s))
    for i := range s {
        if i == 0 || dp[i-1] {
            curr := root
            for j, c := range s[i:] {
                if _, ok := curr.children[c]; !ok {
                    // No words exist
                    break
                }
                curr = curr.children[c]
                if curr.isWord {
                    dp[i+j] = true
                }
            }
        }
    }
    return dp[len(s)-1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {
    boolean isWord;
    Map<Character, TrieNode> children;

    TrieNode() {
        this.children = new HashMap<>();
    }
}

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        TrieNode root = new TrieNode();
        for (String word : wordDict) {
            TrieNode curr = root;
            for (char c : word.toCharArray()) {
                if (!curr.children.containsKey(c)) {
                    curr.children.put(c, new TrieNode());
                }

                curr = curr.children.get(c);
            }

            curr.isWord = true;
        }

        boolean[] dp = new boolean[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || dp[i - 1]) {
                TrieNode curr = root;
                for (int j = i; j < s.length(); j++) {
                    char c = s.charAt(j);
                    if (!curr.children.containsKey(c)) {
                        // No words exist
                        break;
                    }

                    curr = curr.children.get(c);
                    if (curr.isWord) {
                        dp[j] = true;
                    }
                }
            }
        }

        return dp[s.length() - 1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class TrieNode {
    constructor() {
        this.isWord = false;
        this.children = {};
    }
}
function wordBreak(s, wordDict) {
    let root = new TrieNode();
    for (let word of wordDict) {
        let curr = root;
        for (let c of word) {
            if (!curr.children[c]) {
                curr.children[c] = new TrieNode();
            }
            curr = curr.children[c];
        }
        curr.isWord = true;
    }
    const dp = Array(s.length).fill(false);
    for (let i = 0; i < s.length; i++) {
        if (i === 0 || dp[i - 1]) {
            let curr = root;
            for (let j = i; j < s.length; j++) {
                let c = s[j];
                if (!curr.children[c]) {
                    // No words exist
                    break;
                }
                curr = curr.children[c];
                if (curr.isWord) {
                    dp[j] = true;
                }
            }
        }
    }
    return dp[s.length - 1];
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TrieNode:
    def __init__(self):
        self.is_word = False
        self.children = {}


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        root = TrieNode()
        for word in wordDict:
            curr = root
            for c in word:
                if c not in curr.children:
                    curr.children[c] = TrieNode()
                curr = curr.children[c]

            curr.is_word = True

        dp = [False] * len(s)
        for i in range(len(s)):
            if i == 0 or dp[i - 1]:
                curr = root
                for j in range(i, len(s)):
                    c = s[j]
                    if c not in curr.children:
                        # No words exist
                        break

                    curr = curr.children[c]
                    if curr.is_word:
                        dp[j] = True

        return dp[-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class TrieNode {
    isWord: boolean;
    children: { [key: string]: TrieNode };
    constructor() {
        this.isWord = false;
        this.children = {};
    }
}
function wordBreak(s: string, wordDict: string[]): boolean {
    let root = new TrieNode();
    for (let word of wordDict) {
        let curr = root;
        for (let c of word) {
            if (!curr.children[c]) {
                curr.children[c] = new TrieNode();
            }
            curr = curr.children[c];
        }
        curr.isWord = true;
    }
    const dp = new Array(s.length).fill(false);
    for (let i = 0; i < s.length; i++) {
        if (i === 0 || dp[i - 1]) {
            let curr = root;
            for (let j = i; j < s.length; j++) {
                let c = s[j];
                if (!curr.children[c]) {
                    // No words exist
                    break;
                }
                curr = curr.children[c];
                if (curr.isWord) {
                    dp[j] = true;
                }
            }
        }
    }
    return dp[s.length - 1];
}
```

</details>

<br>

## Approach 5: A Different DP

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX_LENGTH 1000
#define MAX_SIZE_DICT 1000
struct hash {
    char key[MAX_LENGTH + 1];
    UT_hash_handle hh;
};
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    struct hash* wordsHash = NULL;
    for (int i = 0; i < wordDictSize; i++) {
        struct hash* wordHash = malloc(sizeof(struct hash));
        strcpy(wordHash->key, wordDict[i]);
        HASH_ADD_STR(wordsHash, key, wordHash);
    }
    bool dp[MAX_LENGTH + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    int slen = strlen(s);
    for (int i = 1; i <= slen; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]) {
                struct hash* wordHash;
                char subWord[MAX_LENGTH + 1];
                strncpy(subWord, &s[j], i - j);
                subWord[i - j] = '\0';  // null terminate
                HASH_FIND_STR(wordsHash, subWord, wordHash);
                if (wordHash) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[slen];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        HashSet<string> words = new HashSet<string>(wordDict);
        bool[] dp = new bool[s.Length + 1];
        dp[0] = true;
        for (int i = 1; i <= s.Length; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.Contains(s.Substring(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.Length];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func wordBreak(s string, wordDict []string) bool {
    words := make(map[string]struct{}, len(wordDict))
    for _, word := range wordDict {
        words[word] = struct{}{}
    }
    dp := make([]bool, len(s)+1)
    dp[0] = true
    for i := 1; i <= len(s); i++ {
        for j := 0; j < i; j++ {
            if dp[j] {
                if _, ok := words[s[j:i]]; ok {
                    dp[i] = true
                    break
                }
            }
        }
    }
    return dp[len(s)]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        Set<String> words = new HashSet<>(wordDict);
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var wordBreak = function (s, wordDict) {
    let n = s.length;
    let words = new Set(wordDict);
    let dp = new Array(n + 1).fill(false);
    dp[0] = true;
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < i; j++) {
            if (dp[j] && words.has(s.substring(j, i))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        words = set(wordDict)
        dp = [False] * (n + 1)
        dp[0] = True

        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j:i] in words:
                    dp[i] = True
                    break

        return dp[-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function wordBreak(s: string, wordDict: string[]): boolean {
    let n = s.length;
    let words = new Set(wordDict);
    let dp = new Array(n + 1).fill(false);
    dp[0] = true;
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < i; j++) {
            if (dp[j] && words.has(s.substring(j, i))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
```

</details>
