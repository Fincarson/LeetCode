# 2452. Words Within Two Edits of Dictionary

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/words-within-two-edits-of-dictionary/)  
`Array` `String` `Trie`

**Problem Link:** [LeetCode 2452 - Words Within Two Edits of Dictionary](https://leetcode.com/problems/words-within-two-edits-of-dictionary/)

## Problem

You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.

In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.

Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.

### Example 1

```text
Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
Output: ["word","note","wood"]
Explanation:
- Changing the 'r' in "word" to 'o' allows it to equal the dictionary word "wood".
- Changing the 'n' to 'j' and the 't' to 'k' in "note" changes it to "joke".
- It would take more than 2 edits for "ants" to equal a dictionary word.
- "wood" can remain unchanged (0 edits) and match the corresponding dictionary word.
Thus, we return ["word","note","wood"].
```

### Example 2

```text
Input: queries = ["yes"], dictionary = ["not"]
Output: []
Explanation:
Applying any two edits to "yes" cannot make it equal to "not". Thus, we return an empty array.
```

## Constraints

- 1 <= queries.length, dictionary.length <= 100
- n == queries[i].length == dictionary[j].length
- 1 <= n <= 100
- All queries[i] and dictionary[j] are composed of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Ladder](https://leetcode.com/problems/word-ladder/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2452. Words Within Two Edits of Dictionary

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Trie | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char** twoEditWords(char** queries, int queriesSize, char** dictionary,
                    int dictionarySize, int* returnSize) {
    char** ans = (char**)malloc(sizeof(char*) * queriesSize);
    int cnt = 0;

    for (int i = 0; i < queriesSize; i++) {
        char* query = queries[i];
        for (int j = 0; j < dictionarySize; j++) {
            char* s = dictionary[j];
            int dis = 0;
            for (int k = 0; query[k] != '\0'; k++) {
                if (query[k] != s[k]) {
                    dis++;
                }
            }
            if (dis <= 2) {
                ans[cnt++] = query;
                break;
            }
        }
    }

    *returnSize = cnt;
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        for (string query : queries) {
            for (string s : dictionary) {
                int dis = 0;
                for (int i = 0; i < query.size(); i++) {
                    if (query[i] != s[i]) {
                        ++dis;
                    }
                }
                if (dis <= 2) {
                    ans.push_back(query);
                    break;
                }
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<string> TwoEditWords(string[] queries, string[] dictionary) {
        var ans = new List<string>();
        foreach (var query in queries) {
            foreach (var s in dictionary) {
                int dis = 0;
                for (int i = 0; i < query.Length; i++) {
                    if (query[i] != s[i]) {
                        dis++;
                    }
                }
                if (dis <= 2) {
                    ans.Add(query);
                    break;
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func twoEditWords(queries []string, dictionary []string) []string {
	var ans []string
	for _, query := range queries {
		for _, s := range dictionary {
			dis := 0
			for i := 0; i < len(query); i++ {
				if query[i] != s[i] {
					dis++
				}
			}
			if dis <= 2 {
				ans = append(ans, query)
				break
			}
		}
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> ans = new ArrayList<>();
        for (String query : queries) {
            for (String s : dictionary) {
                int dis = 0;
                for (int i = 0; i < query.length(); i++) {
                    if (query.charAt(i) != s.charAt(i)) {
                        dis++;
                    }
                }
                if (dis <= 2) {
                    ans.add(query);
                    break;
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var twoEditWords = function (queries, dictionary) {
    const ans = [];
    for (const query of queries) {
        for (const s of dictionary) {
            let dis = 0;
            for (let i = 0; i < query.length; i++) {
                if (query[i] !== s[i]) {
                    dis++;
                }
            }
            if (dis <= 2) {
                ans.push(query);
                break;
            }
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def twoEditWords(self, queries, dictionary):
        ans = []
        for query in queries:
            for s in dictionary:
                dis = 0
                for i in range(len(query)):
                    if query[i] != s[i]:
                        dis += 1
                if dis <= 2:
                    ans.append(query)
                    break
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function twoEditWords(queries: string[], dictionary: string[]): string[] {
    const ans: string[] = [];
    for (const query of queries) {
        for (const s of dictionary) {
            let dis = 0;
            for (let i = 0; i < query.length; i++) {
                if (query[i] !== s[i]) {
                    dis++;
                }
            }
            if (dis <= 2) {
                ans.push(query);
                break;
            }
        }
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Trie

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct TrieNode {
    struct TrieNode* child[26];
    bool isEnd;
} TrieNode;

TrieNode* newNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    memset(node->child, 0, sizeof(node->child));
    node->isEnd = false;
    return node;
}

void insert(TrieNode* root, char* word) {
    TrieNode* node = root;
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!node->child[idx]) node->child[idx] = newNode();
        node = node->child[idx];
    }
    node->isEnd = true;
}

bool dfs(char* word, int i, TrieNode* node, int cnt) {
    if (cnt > 2 || !node) return false;

    if (word[i] == '\0') return node->isEnd;

    int idx = word[i] - 'a';

    // no changes made
    if (node->child[idx] && dfs(word, i + 1, node->child[idx], cnt))
        return true;

    // made changes
    if (cnt < 2) {
        for (int c = 0; c < 26; c++) {
            if (c == idx) continue;
            if (node->child[c] && dfs(word, i + 1, node->child[c], cnt + 1))
                return true;
        }
    }

    return false;
}

char** twoEditWords(char** queries, int queriesSize, char** dictionary,
                    int dictionarySize, int* returnSize) {
    TrieNode* root = newNode();
    for (int i = 0; i < dictionarySize; i++) insert(root, dictionary[i]);

    char** res = (char**)malloc(sizeof(char*) * queriesSize);
    int cnt = 0;

    for (int i = 0; i < queriesSize; i++) {
        if (dfs(queries[i], 0, root, 0)) {
            res[cnt++] = queries[i];
        }
    }

    *returnSize = cnt;
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
struct TrieNode {
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        memset(child, 0, sizeof(child));
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool dfs(string& word, int i, TrieNode* node, int cnt) {
        if (cnt > 2) return false;
        if (!node) return false;

        if (i == word.size()) {
            return node->isEnd;
        }

        int idx = word[i] - 'a';

        // no changes made
        if (node->child[idx]) {
            if (dfs(word, i + 1, node->child[idx], cnt)) return true;
        }

        // made changes
        if (cnt < 2) {
            for (int c = 0; c < 26; c++) {
                if (c == idx) continue;
                if (node->child[c]) {
                    if (dfs(word, i + 1, node->child[c], cnt + 1)) return true;
                }
            }
        }

        return false;
    }

    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        for (auto& w : dictionary) insert(w);

        vector<string> res;
        for (auto& q : queries) {
            if (dfs(q, 0, root, 0)) {
                res.push_back(q);
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    class TrieNode {
        public TrieNode[] child = new TrieNode[26];
        public bool isEnd = false;
    }

    TrieNode root = new TrieNode();

    void Insert(string word) {
        var node = root;
        foreach (char c in word) {
            int idx = c - 'a';
            if (node.child[idx] == null)
                node.child[idx] = new TrieNode();
            node = node.child[idx];
        }
        node.isEnd = true;
    }

    bool Dfs(string word, int i, TrieNode node, int cnt) {
        if (cnt > 2 || node == null)
            return false;

        if (i == word.Length)
            return node.isEnd;

        int idx = word[i] - 'a';

        // no changes made
        if (node.child[idx] != null) {
            if (Dfs(word, i + 1, node.child[idx], cnt))
                return true;
        }

        // made changes
        if (cnt < 2) {
            for (int c = 0; c < 26; c++) {
                if (c == idx)
                    continue;
                if (node.child[c] != null) {
                    if (Dfs(word, i + 1, node.child[c], cnt + 1))
                        return true;
                }
            }
        }

        return false;
    }

    public IList<string> TwoEditWords(string[] queries, string[] dictionary) {
        foreach (var w in dictionary) Insert(w);

        var res = new List<string>();
        foreach (var q in queries) {
            if (Dfs(q, 0, root, 0)) {
                res.Add(q);
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type TrieNode struct {
	child [26]*TrieNode
	isEnd bool
}

var root = &TrieNode{}

func insert(word string) {
	node := root
	for _, c := range word {
		idx := c - 'a'
		if node.child[idx] == nil {
			node.child[idx] = &TrieNode{}
		}
		node = node.child[idx]
	}
	node.isEnd = true
}

func dfs(word string, i int, node *TrieNode, cnt int) bool {
	if cnt > 2 || node == nil {
		return false
	}

	if i == len(word) {
		return node.isEnd
	}

	idx := word[i] - 'a'

	// no changes made
	if node.child[idx] != nil && dfs(word, i+1, node.child[idx], cnt) {
		return true
	}

	// made changes
	if cnt < 2 {
		for c := 0; c < 26; c++ {
			if byte(c) == idx {
				continue
			}
			if node.child[c] != nil && dfs(word, i+1, node.child[c], cnt+1) {
				return true
			}
		}
	}

	return false
}

func twoEditWords(queries []string, dictionary []string) []string {
	root = &TrieNode{}
	for _, w := range dictionary {
		insert(w)
	}

	var res []string
	for _, q := range queries {
		if dfs(q, 0, root, 0) {
			res = append(res, q)
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    static class TrieNode {

        TrieNode[] child = new TrieNode[26];
        boolean isEnd = false;
    }

    TrieNode root = new TrieNode();

    void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.child[idx] == null) node.child[idx] = new TrieNode();
            node = node.child[idx];
        }
        node.isEnd = true;
    }

    boolean dfs(String word, int i, TrieNode node, int cnt) {
        if (cnt > 2 || node == null) return false;

        if (i == word.length()) return node.isEnd;

        int idx = word.charAt(i) - 'a';

        // no changes made
        if (node.child[idx] != null) {
            if (dfs(word, i + 1, node.child[idx], cnt)) return true;
        }

        // made changes
        if (cnt < 2) {
            for (int c = 0; c < 26; c++) {
                if (c == idx) continue;
                if (node.child[c] != null) {
                    if (dfs(word, i + 1, node.child[c], cnt + 1)) return true;
                }
            }
        }

        return false;
    }

    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        for (String w : dictionary) insert(w);

        List<String> res = new ArrayList<>();
        for (String q : queries) {
            if (dfs(q, 0, root, 0)) {
                res.add(q);
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class TrieNode {
    constructor() {
        this.child = new Array(26).fill(null);
        this.isEnd = false;
    }
}

var twoEditWords = function (queries, dictionary) {
    const root = new TrieNode();

    function insert(word) {
        let node = root;
        for (let c of word) {
            let idx = c.charCodeAt(0) - 97;
            if (!node.child[idx]) node.child[idx] = new TrieNode();
            node = node.child[idx];
        }
        node.isEnd = true;
    }

    function dfs(word, i, node, cnt) {
        if (cnt > 2 || !node) return false;
        if (i === word.length) return node.isEnd;

        let idx = word.charCodeAt(i) - 97;

        // made changes
        if (node.child[idx] && dfs(word, i + 1, node.child[idx], cnt))
            return true;

        // no changes made
        if (cnt < 2) {
            for (let c = 0; c < 26; c++) {
                if (c === idx) continue;
                if (node.child[c] && dfs(word, i + 1, node.child[c], cnt + 1))
                    return true;
            }
        }

        return false;
    }

    for (let w of dictionary) insert(w);

    const res = [];
    for (let q of queries) {
        if (dfs(q, 0, root, 0)) res.push(q);
    }

    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TrieNode:
    def __init__(self):
        self.child = [None] * 26
        self.isEnd = False


class Solution:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for c in word:
            idx = ord(c) - ord("a")
            if not node.child[idx]:
                node.child[idx] = TrieNode()
            node = node.child[idx]
        node.isEnd = True

    def dfs(self, word, i, node, cnt):
        if cnt > 2 or not node:
            return False

        if i == len(word):
            return node.isEnd

        idx = ord(word[i]) - ord("a")

        # no changes made
        if node.child[idx] and self.dfs(word, i + 1, node.child[idx], cnt):
            return True

        # made changes
        if cnt < 2:
            for c in range(26):
                if c == idx:
                    continue
                if node.child[c] and self.dfs(
                    word, i + 1, node.child[c], cnt + 1
                ):
                    return True

        return False

    def twoEditWords(self, queries, dictionary):
        for w in dictionary:
            self.insert(w)

        res = []
        for q in queries:
            if self.dfs(q, 0, self.root, 0):
                res.append(q)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class TrieNode {
    child: (TrieNode | null)[] = new Array(26).fill(null);
    isEnd: boolean = false;
}

function twoEditWords(queries: string[], dictionary: string[]): string[] {
    const root = new TrieNode();

    function insert(word: string) {
        let node = root;
        for (const c of word) {
            const idx = c.charCodeAt(0) - 97;
            if (!node.child[idx]) node.child[idx] = new TrieNode();
            node = node.child[idx]!;
        }
        node.isEnd = true;
    }

    function dfs(
        word: string,
        i: number,
        node: TrieNode | null,
        cnt: number,
    ): boolean {
        if (cnt > 2 || !node) return false;
        if (i === word.length) return node.isEnd;

        const idx = word.charCodeAt(i) - 97;

        // no changes made
        if (node.child[idx] && dfs(word, i + 1, node.child[idx], cnt))
            return true;

        // made changes
        if (cnt < 2) {
            for (let c = 0; c < 26; c++) {
                if (c === idx) continue;
                if (node.child[c] && dfs(word, i + 1, node.child[c], cnt + 1))
                    return true;
            }
        }

        return false;
    }

    for (const w of dictionary) insert(w);

    const res: string[] = [];
    for (const q of queries) {
        if (dfs(q, 0, root, 0)) res.push(q);
    }

    return res;
}
```

</details>
