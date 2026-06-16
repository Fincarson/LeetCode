# 2707. Extra Characters in a String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/extra-characters-in-a-string/)  
`Array` `Hash Table` `String` `Dynamic Programming` `Trie`

**Problem Link:** [LeetCode 2707 - Extra Characters in a String](https://leetcode.com/problems/extra-characters-in-a-string/)

## Problem

You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

### Example 1

```text
Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.
```

### Example 2

```text
Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
```

## Constraints

- 1 <= s.length <= 50
- 1 <= dictionary.length <= 50
- 1 <= dictionary[i].length <= 50
- dictionary[i] and s consists of only lowercase English letters
- dictionary contains distinct words

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Break](https://leetcode.com/problems/word-break/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2707. Extra Characters in a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top Down Dynamic Programming with Substring Method | C++, Java, JavaScript, Python3 |
| Bottom Up Dynamic Programming with Substring Method | C++, Java, JavaScript, Python3 |
| Top Down Dynamic Programming with Trie | C++, Java, Python3 |
| Bottom Up Dynamic Programming with Trie | C++, Java, Python3 |

## Approach 1: Top Down Dynamic Programming with Substring Method

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minExtraChar(string s, vector<string> dictionary) {
        int n = s.length();
        unordered_set<string> dictionarySet(dictionary.begin(), dictionary.end());
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int start) {
            if (start == n) {
                return 0;
            }
            if (memo.count(start)) {
                return memo[start];
            }
            // To count this character as a left over character 
            // move to index 'start + 1'
            int ans = dp(start + 1) + 1;
            for (int end = start; end < n; end++) {
                auto curr = s.substr(start, end - start + 1);
                if (dictionarySet.count(curr)) {
                    ans = min(ans, dp(end + 1));
                }
            }

            return memo[start] = ans;
        };

        return dp(0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Integer[] memo;
    HashSet<String> dictionarySet;
    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();
        memo = new Integer[n];
        dictionarySet = new HashSet<>(Arrays.asList(dictionary));
        return dp(0, n, s);
    }
    private int dp(int start, int n, String s) {
        if (start == n) {
            return 0;
        }
        if (memo[start] != null) {
            return memo[start];
        }
        // To count this character as a left over character 
        // move to index 'start + 1'
        int ans = dp(start + 1, n, s) + 1;
        for (int end = start; end < n; end++) {
            var curr = s.substring(start, end + 1);
            if (dictionarySet.contains(curr)) {
                ans = Math.min(ans, dp(end + 1, n, s));
            }
        }

        return memo[start] = ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minExtraChar = function(s, dictionary) {
    const n = s.length;
    const dictionarySet = new Set(dictionary);
    const memo = new Map();

    const dp = function(start) {
        if (start === n) {
            return 0;
        }
        if (memo.has(start)) {
            return memo.get(start);
        }
        // To count this character as a left over character 
        // move to index 'start + 1'
        let ans = dp(start + 1) + 1;
        for (let end = start; end < n; end++) {
            const curr = s.slice(start, end + 1);
            if (dictionarySet.has(curr)) {
                ans = Math.min(ans, dp(end + 1));
            }
        }
        memo.set(start, ans);
        return ans
    };

    return dp(0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n, dictionary_set = len(s), set(dictionary)
        @cache
        def dp(start):
            if start == n:
                return 0
            # To count this character as a left over character 
            # move to index 'start + 1'
            ans = dp(start + 1) + 1
            for end in range(start, n):
                curr = s[start: end + 1]
                if curr in dictionary_set:
                    ans = min(ans, dp(end + 1))
            return ans
            
        return dp(0)
```

</details>

<br>

## Approach 2: Bottom Up Dynamic Programming with Substring Method

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minExtraChar(string s, vector<string> dictionary) {
        int n = s.length();
        unordered_set<string> dictionarySet(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1, 0);

        for (int start = n - 1; start >= 0; start--) {
            dp[start] = dp[start + 1] + 1;
            for (int end = start; end < n; end++) {
                auto curr = s.substr(start, end - start + 1);
                if (dictionarySet.count(curr)) {
                    dp[start] = min(dp[start], dp[end + 1]);
                }
            }
        }

        return dp[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();
        var dictionarySet = new HashSet<>(Arrays.asList(dictionary));
        var dp = new int[n + 1];

        for (int start = n - 1; start >= 0; start--) {
            dp[start] = dp[start + 1] + 1;
            for (int end = start; end < n; end++) {
                var curr = s.substring(start, end + 1);
                if (dictionarySet.contains(curr)) {
                    dp[start] = Math.min(dp[start], dp[end + 1]);
                }
            }
        }

        return dp[0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minExtraChar = function(s, dictionary) {
    const n = s.length;
    const dictionarySet = new Set(dictionary);
    const dp = Array(n + 1).fill(0);

    for (let start = n - 1; start >= 0; start--) {
        dp[start] = dp[start + 1] + 1;
        for (let end = start; end < n; end++) {
            const curr = s.substring(start, end + 1);
            if (dictionarySet.has(curr)) {
                dp[start] = Math.min(dp[start], dp[end + 1]);
            }
        }
    }

    return dp[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n = len(s)
        dictionary_set = set(dictionary)
        dp = [0] * (len(s) + 1)

        for start in range(n - 1, -1, -1):
            dp[start] = 1 + dp[start + 1]
            for end in range(start, n):
                curr = s[start: end + 1]
                if curr in dictionary_set:
                    dp[start] = min(dp[start], dp[end + 1])

        return dp[0]
```

</details>

<br>

## Approach 3: Top Down Dynamic Programming with Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word;
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        auto root = buildTrie(dictionary);
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int start) {
            if (start == n) {
                return 0;
            }
            if (memo.count(start)) {
                return memo[start];
            }
            // To count this character as a left over character 
            // move to index 'start + 1'
            int ans = dp(start + 1) + 1;
            TrieNode* node = root;
            for (int end = start; end < n; end++) {
                char c = s[end];
                if (node->children.find(c) == node->children.end()) {
                    break;
                }
                node = node->children[c];
                if (node->is_word) {
                    ans = min(ans, dp(end + 1));
                }
            }

            return memo[start] = ans;
        };

        return dp(0);
    }

    TrieNode* buildTrie(vector<string>& dictionary) {
        auto root = new TrieNode();
        for (auto& word : dictionary) {
            auto node = root;
            for (auto& c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->is_word = true;
        }
        return root;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {
    Map<Character, TrieNode> children = new HashMap();
    boolean is_word = false;
}

class Solution {
    TrieNode root;
    Integer[] memo;
    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();
        root = buildTrie(dictionary);
        memo = new Integer[n + 1];
        return dp(0, n, s);
    }
    
    private int dp(int start, int n, String s) {
        if (start == n) {
            return 0;
        }
        if (memo[start] != null) {
            return memo[start];
        }

        TrieNode node = root;
        // To count this character as a left over character 
        // move to index 'start + 1'
        int ans = dp(start + 1, n, s) + 1;
        for (int end = start; end < n; end++) {
            char c = s.charAt(end);
            if (!node.children.containsKey(c)) {
                break;
            }
            node = node.children.get(c);
            if (node.is_word) {
                ans = Math.min(ans, dp(end + 1, n, s));
            }
        }
        
        return memo[start] = ans;
    }
    
    private TrieNode buildTrie(String[] dictionary) {
        TrieNode root = new TrieNode();
        for (String word : dictionary) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                node.children.putIfAbsent(c, new TrieNode());
                node = node.children.get(c);
            }
            node.is_word = true;
        }
        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False

class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n = len(s)
        root = self.buildTrie(dictionary)
        
        @cache
        def dp(start):
            if start == n:
                return 0
            # To count this character as a left over character 
            # move to index 'start + 1'
            ans = dp(start + 1) + 1
            node = root
            for end in range(start, n):
                if s[end] not in node.children:
                    break
                node = node.children[s[end]]
                if node.is_word:
                    ans = min(ans, dp(end + 1))
            return ans
        
        return dp(0)
    
    def buildTrie(self, dictionary):
        root = TrieNode()
        for word in dictionary:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.is_word = True
        return root
```

</details>

<br>

## Approach 4: Bottom Up Dynamic Programming with Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word;
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        auto root = buildTrie(dictionary);
        vector<int> dp(n + 1, 0);

        for (int start = n - 1; start >= 0; start--) {
            dp[start] = dp[start + 1] + 1;
            auto node = root;
            for (int end = start; end < n; end++) {
                if (node->children.find(s[end]) == node->children.end()) {
                    break;
                }
                node = node->children[s[end]];
                if (node->is_word) {
                    dp[start] = min(dp[start], dp[end + 1]);
                }
            }
        }

        return dp[0];
    }

    TrieNode* buildTrie(vector<string>& dictionary) {
        auto root = new TrieNode();
        for (auto& word : dictionary) {
            auto node = root;
            for (auto& c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->is_word = true;
        }
        return root;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {
    Map<Character, TrieNode> children = new HashMap();
    boolean isWord = false;
}

class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();
        var root = buildTrie(dictionary);
        var dp = new int[n + 1];

        for (int start = n - 1; start >= 0; start--) {
            dp[start] = dp[start + 1] + 1;
            var node = root;
            for (int end = start; end < n; end++) {
                if (!node.children.containsKey(s.charAt(end))) {
                    break;
                }
                node = node.children.get(s.charAt(end));
                if (node.isWord) {
                    dp[start] = Math.min(dp[start], dp[end + 1]);
                }
            }
        }

        return dp[0];
    }

    private TrieNode buildTrie(String[] dictionary) {
        var root = new TrieNode();
        for (var word : dictionary) {
            var node = root;
            for (var c : word.toCharArray()) {
                node.children.putIfAbsent(c, new TrieNode());
                node = node.children.get(c);
            }
            node.isWord = true;
        }
        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False

class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n = len(s)
        root = self.buildTrie(dictionary)
        dp = [0] * (n + 1)
        
        for start in range(n - 1, -1, -1):
            dp[start] = dp[start + 1] + 1
            node = root
            for end in range(start, n):
                if s[end] not in node.children:
                    break
                node = node.children[s[end]]
                if node.is_word:
                    dp[start] = min(dp[start], dp[end + 1])
        
        return dp[0]
    
    def buildTrie(self, dictionary):
        root = TrieNode()
        for word in dictionary:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.is_word = True
        return root
```

</details>
