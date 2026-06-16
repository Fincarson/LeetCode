# 127. Word Ladder

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/word-ladder/)  
`Hash Table` `String` `Breadth-First Search`

**Problem Link:** [LeetCode 127 - Word Ladder](https://leetcode.com/problems/word-ladder/)

## Problem

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

- Every adjacent pair of words differs by a single letter.
- Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
- sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

### Example 1

```text
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
```

### Example 2

```text
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

## Constraints

- 1 <= beginWord.length <= 10
- endWord.length == beginWord.length
- 1 <= wordList.length <= 5000
- wordList[i].length == beginWord.length
- beginWord, endWord, and wordList[i] consist of lowercase English letters.
- beginWord != endWord
- All the words in wordList are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Ladder II](https://leetcode.com/problems/word-ladder-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Words Within Two Edits of Dictionary](https://leetcode.com/problems/words-within-two-edits-of-dictionary/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 127. Word Ladder

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bidirectional Breadth First Search | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Breadth First Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Defining a structure for storing string list
typedef struct StringList {
    char *string;
    struct StringList *next;
} StringList;

// Hash table structure for storing transformations
typedef struct HashTable {
    char *key;
    StringList *list;
    UT_hash_handle hh;
} HashTable;

// Node structure for BFS queue
typedef struct Node {
    char *word;
    int level;
} Node;

// Queue node structure
typedef struct QueueNode {
    Node *node;
    struct QueueNode *next;
} QueueNode;

// Queue structure
typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

// Function prototypes
Queue *createQueue();
void enqueue(Queue *q, Node *node);
Node *dequeue(Queue *q);
int isEmpty(Queue *q);
void addTransformation(HashTable **table, char *key, char *value);
StringList *findList(HashTable *table, char *key);

// Create a new queue
Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Add a node to the queue
void enqueue(Queue *q, Node *node) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

// Remove a node from the queue
Node *dequeue(Queue *q) {
    if (q->front == NULL) return NULL;

    QueueNode *temp = q->front;
    Node *node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return node;
}

// Check if the queue is empty
int isEmpty(Queue *q) { return q->front == NULL; }

// Add a transformation to the hash table
void addTransformation(HashTable **table, char *key, char *value) {
    HashTable *s;
    HASH_FIND_STR(*table, key, s);
    if (s == NULL) {
        s = (HashTable *)malloc(sizeof(HashTable));
        s->key = strdup(key);
        s->list = NULL;
        HASH_ADD_KEYPTR(hh, *table, s->key, strlen(s->key), s);
    }
    StringList *new_string = (StringList *)malloc(sizeof(StringList));
    new_string->string = strdup(value);
    new_string->next = s->list;
    s->list = new_string;
}

// Find list from the hash table
StringList *findList(HashTable *table, char *key) {
    HashTable *s;
    HASH_FIND_STR(table, key, s);
    return (s == NULL) ? NULL : s->list;
}

// Ladder length function (BFS)
int ladderLength(char *beginWord, char *endWord, char **wordList,
                 int wordListSize) {
    int L = strlen(beginWord);

    // Create hash table for transformations
    HashTable *allComboDict = NULL;
    for (int j = 0; j < wordListSize; j++) {
        char *word = wordList[j];
        for (int i = 0; i < L; i++) {
            char newWord[100];
            snprintf(newWord, sizeof(newWord), "%.*s*%s", i, word,
                     word + i + 1);
            addTransformation(&allComboDict, newWord, word);
        }
    }

    // Initialize the BFS queue
    Queue *Q = createQueue();
    Node *startNode = (Node *)malloc(sizeof(Node));
    startNode->word = strdup(beginWord);
    startNode->level = 1;
    enqueue(Q, startNode);

    // Visited hash table
    HashTable *visited = NULL;
    addTransformation(&visited, beginWord, "");

    while (!isEmpty(Q)) {
        Node *node = dequeue(Q);
        char *word = node->word;
        int level = node->level;
        for (int i = 0; i < L; i++) {
            char newWord[100];
            snprintf(newWord, sizeof(newWord), "%.*s*%s", i, word,
                     word + i + 1);
            StringList *transformations = findList(allComboDict, newWord);
            while (transformations != NULL) {
                char *adjacentWord = transformations->string;
                if (strcmp(adjacentWord, endWord) == 0) {
                    return level + 1;
                }
                if (findList(visited, adjacentWord) == NULL) {
                    addTransformation(&visited, adjacentWord, "");
                    Node *newNode = (Node *)malloc(sizeof(Node));
                    newNode->word = strdup(adjacentWord);
                    newNode->level = level + 1;
                    enqueue(Q, newNode);
                }
                transformations = transformations->next;
            }
        }
        free(node->word);
        free(node);
    }

    return 0;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        // Since all words are of same length.
        int L = beginWord.size();
        // Dictionary to hold combination of words that can be formed,
        // from any given word. By changing one letter at a time.
        unordered_map<string, vector<string>> allComboDict;
        for (string word : wordList) {
            for (int i = 0; i < L; i++) {
                // Key is the generic word
                // Value is a list of words which have the same intermediate
                // generic word.
                string newWord =
                    word.substr(0, i) + '*' + word.substr(i + 1, L);
                allComboDict[newWord].push_back(word);
            }
        }
        // Queue for BFS
        queue<pair<string, int>> Q;
        Q.push(make_pair(beginWord, 1));
        // Visited to make sure we don't repeat processing same word.
        unordered_map<string, bool> visited;
        visited[beginWord] = true;
        while (!Q.empty()) {
            pair<string, int> node = Q.front();
            Q.pop();
            string word = node.first;
            int level = node.second;
            for (int i = 0; i < L; i++) {
                // Intermediate words for current word
                string newWord =
                    word.substr(0, i) + '*' + word.substr(i + 1, L);
                // Next states are all the words which share the same
                // intermediate state.
                for (string adjacentWord : allComboDict[newWord]) {
                    // If at any point if we find what we are looking for
                    // i.e. the end word - we can return with the answer.
                    if (adjacentWord == endWord) {
                        return level + 1;
                    }
                    // Otherwise, add it to the BFS Queue. Also mark it visited
                    if (!visited[adjacentWord]) {
                        visited[adjacentWord] = true;
                        Q.push(make_pair(adjacentWord, level + 1));
                    }
                }
            }
        }
        return 0;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LadderLength(string beginWord, string endWord,
                            IList<string> wordList) {
        int L = beginWord.Length;
        Dictionary<string, List<string>> allComboDict =
            new Dictionary<string, List<string>>();
        foreach (string word in wordList) {
            for (int i = 0; i < L; i++) {
                string newWord = word.Substring(0, i) + '*' +
                                 word.Substring(i + 1, L - i - 1);
                if (!allComboDict.ContainsKey(newWord))
                    allComboDict[newWord] = new List<string>();
                allComboDict[newWord].Add(word);
            }
        }

        Queue<Tuple<string, int>> Q = new Queue<Tuple<string, int>>();
        Q.Enqueue(new Tuple<string, int>(beginWord, 1));
        Dictionary<string, bool> visited = new Dictionary<string, bool>();
        visited[beginWord] = true;
        while (Q.Any()) {
            var node = Q.Dequeue();
            string word = node.Item1;
            int level = node.Item2;
            for (int i = 0; i < L; i++) {
                string newWord = word.Substring(0, i) + '*' +
                                 word.Substring(i + 1, L - i - 1);
                foreach (string adjacentWord in allComboDict.GetValueOrDefault(
                             newWord, new List<string>())) {
                    if (adjacentWord.Equals(endWord))
                        return level + 1;
                    if (!visited.ContainsKey(adjacentWord)) {
                        visited[adjacentWord] = true;
                        Q.Enqueue(
                            new Tuple<string, int>(adjacentWord, level + 1));
                    }
                }
            }
        }

        return 0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func ladderLength(beginWord string, endWord string, wordList []string) int {
    L := len(beginWord)
    allComboDict := make(map[string][]string)
    for _, word := range wordList {
        for i := 0; i < L; i++ {
            newWord := word[:i] + "*" + word[i+1:L]
            allComboDict[newWord] = append(allComboDict[newWord], word)
        }
    }
    Q := make([][]interface{}, 0, len(wordList))
    Q = append(Q, []interface{}{beginWord, 1})
    visited := make(map[string]bool)
    visited[beginWord] = true
    for len(Q) > 0 {
        node := Q[0]
        Q = Q[1:]
        word := node[0].(string)
        level := node[1].(int)
        for i := 0; i < L; i++ {
            newWord := word[:i] + "*" + word[i+1:L]
            for _, adjacentWord := range allComboDict[newWord] {
                if adjacentWord == endWord {
                    return level + 1
                }
                if !visited[adjacentWord] {
                    visited[adjacentWord] = true
                    Q = append(Q, []interface{}{adjacentWord, level + 1})
                }
            }
        }
    }
    return 0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int ladderLength(
        String beginWord,
        String endWord,
        List<String> wordList
    ) {
        // Since all words are of same length.
        int L = beginWord.length();

        // Dictionary to hold combination of words that can be formed,
        // from any given word. By changing one letter at a time.
        Map<String, List<String>> allComboDict = new HashMap<>();

        wordList.forEach(word -> {
            for (int i = 0; i < L; i++) {
                // Key is the generic word
                // Value is a list of words which have the same intermediate generic word.
                String newWord =
                    word.substring(0, i) + '*' + word.substring(i + 1, L);
                List<String> transformations = allComboDict.getOrDefault(
                    newWord,
                    new ArrayList<>()
                );
                transformations.add(word);
                allComboDict.put(newWord, transformations);
            }
        });

        // Queue for BFS
        Queue<Pair<String, Integer>> Q = new LinkedList<>();
        Q.add(new Pair(beginWord, 1));

        // Visited to make sure we don't repeat processing same word.
        Map<String, Boolean> visited = new HashMap<>();
        visited.put(beginWord, true);

        while (!Q.isEmpty()) {
            Pair<String, Integer> node = Q.remove();
            String word = node.getKey();
            int level = node.getValue();
            for (int i = 0; i < L; i++) {
                // Intermediate words for current word
                String newWord =
                    word.substring(0, i) + '*' + word.substring(i + 1, L);

                // Next states are all the words which share the same intermediate state.
                for (String adjacentWord : allComboDict.getOrDefault(
                    newWord,
                    new ArrayList<>()
                )) {
                    // If at any point if we find what we are looking for
                    // i.e. the end word - we can return with the answer.
                    if (adjacentWord.equals(endWord)) {
                        return level + 1;
                    }
                    // Otherwise, add it to the BFS Queue. Also mark it visited
                    if (!visited.containsKey(adjacentWord)) {
                        visited.put(adjacentWord, true);
                        Q.add(new Pair(adjacentWord, level + 1));
                    }
                }
            }
        }

        return 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var ladderLength = function (beginWord, endWord, wordList) {
    // Since all words are of same length.
    let L = beginWord.length;
    // Dictionary to hold combination of words that can be formed,
    // from any given word. By changing one letter at a time.
    let allComboDict = {};
    for (let word of wordList) {
        for (let i = 0; i < L; i++) {
            // Key is the generic word
            // Value is a list of words which have the same intermediate generic word.
            let newWord = word.substring(0, i) + "*" + word.substring(i + 1, L);
            if (!allComboDict[newWord]) allComboDict[newWord] = [];
            allComboDict[newWord].push(word);
        }
    }
    // Queue for BFS
    let Q = [[beginWord, 1]];
    // Visited to make sure we don't repeat processing same word.
    let visited = { [beginWord]: true };
    while (Q.length > 0) {
        let node = Q.shift();
        let word = node[0];
        let level = node[1];
        for (let i = 0; i < L; i++) {
            // Intermediate words for current word
            let newWord = word.substring(0, i) + "*" + word.substring(i + 1, L);
            // Next states are all the words which share the same intermediate state.
            for (let adjacentWord of allComboDict[newWord] || []) {
                // If at any point if we find what we are looking for
                // i.e. the end word - we can return with the answer.
                if (adjacentWord === endWord) {
                    return level + 1;
                }
                // Otherwise, add it to the BFS Queue. Also mark it visited
                if (!visited[adjacentWord]) {
                    visited[adjacentWord] = true;
                    Q.push([adjacentWord, level + 1]);
                }
            }
        }
    }
    return 0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import defaultdict


class Solution(object):
    def ladderLength(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> int:

        if (
            endWord not in wordList
            or not endWord
            or not beginWord
            or not wordList
        ):
            return 0

        # Since all words are of same length.
        L = len(beginWord)

        # Dictionary to hold combination of words that can be formed,
        # from any given word. By changing one letter at a time.
        all_combo_dict = defaultdict(list)
        for word in wordList:
            for i in range(L):
                # Key is the generic word
                # Value is a list of words which have the same intermediate generic word.
                all_combo_dict[word[:i] + "*" + word[i + 1 :]].append(word)

        # Queue for BFS
        queue = collections.deque([(beginWord, 1)])
        # Visited to make sure we don't repeat processing same word.
        visited = {beginWord: True}
        while queue:
            current_word, level = queue.popleft()
            for i in range(L):
                # Intermediate words for current word
                intermediate_word = (
                    current_word[:i] + "*" + current_word[i + 1 :]
                )

                # Next states are all the words which share the same intermediate state.
                for word in all_combo_dict[intermediate_word]:
                    # If at any point if we find what we are looking for
                    # i.e. the end word - we can return with the answer.
                    if word == endWord:
                        return level + 1
                    # Otherwise, add it to the BFS Queue. Also mark it visited
                    if word not in visited:
                        visited[word] = True
                        queue.append((word, level + 1))
                all_combo_dict[intermediate_word] = []
        return 0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function ladderLength(
    beginWord: string,
    endWord: string,
    wordList: string[],
): number {
    let L: number = beginWord.length;
    let allComboDict: { [key: string]: string[] } = {};
    for (let word of wordList) {
        for (let i = 0; i < L; i++) {
            let newWord = word.substring(0, i) + "*" + word.substring(i + 1, L);
            if (!allComboDict[newWord]) allComboDict[newWord] = [];
            allComboDict[newWord].push(word);
        }
    }
    let Q: [string, number][] = [[beginWord, 1]];
    let visited: { [key: string]: boolean } = { [beginWord]: true };
    while (Q.length > 0) {
        let node = Q.shift() as [string, number];
        let word: string = node[0];
        let level: number = node[1];
        for (let i = 0; i < L; i++) {
            let newWord = word.substring(0, i) + "*" + word.substring(i + 1, L);
            for (let adjacentWord of allComboDict[newWord] || []) {
                if (adjacentWord === endWord) return level + 1;
                if (!visited[adjacentWord]) {
                    visited[adjacentWord] = true;
                    Q.push([adjacentWord, level + 1]);
                }
            }
        }
    }
    return 0;
}
```

</details>

<br>

## Approach 2: Bidirectional Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    map<string, vector<string>> allComboDict;
    int L = 0;
    int visitWordNode(queue<pair<string, int>>& Q, map<string, int>& Visited,
                      map<string, int>& othersVisited) {
        for (size_t j = Q.size(); j > 0; j--) {
            pair<string, int> node = Q.front();
            Q.pop();
            string word = node.first;
            int level = node.second;
            for (int i = 0; i < this->L; i++) {
                string newWord =
                    word.substr(0, i) + '*' + word.substr(i + 1, L);
                for (string adjacentWord : this->allComboDict[newWord]) {
                    if (othersVisited.find(adjacentWord) !=
                        othersVisited.end()) {
                        return level + othersVisited[adjacentWord];
                    }
                    if (Visited.find(adjacentWord) == Visited.end()) {
                        Visited[adjacentWord] = level + 1;
                        Q.push(make_pair(adjacentWord, level + 1));
                    }
                }
            }
        }
        return -1;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        L = beginWord.size();
        for (string& word : wordList) {
            for (int i = 0; i < L; i++) {
                string newWord =
                    word.substr(0, i) + '*' + word.substr(i + 1, L);
                vector<string>& transformations = this->allComboDict[newWord];
                transformations.push_back(word);
            }
        }
        queue<pair<string, int>> q_beg;
        q_beg.push(make_pair(beginWord, 1));
        queue<pair<string, int>> q_end;
        q_end.push(make_pair(endWord, 1));
        map<string, int> visited_beg;
        visited_beg[beginWord] = 1;
        map<string, int> visited_end;
        visited_end[endWord] = 1;
        int ans = -1;
        while (!q_beg.empty() && !q_end.empty()) {
            if (q_beg.size() <= q_end.size()) {
                ans = visitWordNode(q_beg, visited_beg, visited_end);
            } else {
                ans = visitWordNode(q_end, visited_end, visited_beg);
            }
            if (ans > -1) {
                return ans;
            }
        }
        return 0;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    int L;
    Dictionary<string, List<string>> allComboDict;
    Queue<Tuple<string, int>> Q_begin;
    Queue<Tuple<string, int>> Q_end;
    Dictionary<string, int> visitedBegin;
    Dictionary<string, int> visitedEnd;

    private int visitWordNode(Queue<Tuple<string, int>> Q,
                              Dictionary<string, int> visited,
                              Dictionary<string, int> othersVisited) {
        int x = Q.Count;
        while (x > 0) {
            var node = Q.Dequeue();
            string word = node.Item1;
            int level = node.Item2;
            for (int i = 0; i < L; i++) {
                string newWord = word.Substring(0, i) + '*' +
                                 word.Substring(i + 1, L - i - 1);
                if (this.allComboDict.ContainsKey(newWord)) {
                    foreach (string adjacentWord in this
                                 .allComboDict[newWord]) {
                        if (othersVisited.ContainsKey(adjacentWord)) {
                            return level + othersVisited[adjacentWord];
                        }

                        if (!visited.ContainsKey(adjacentWord)) {
                            visited.Add(adjacentWord, level + 1);
                            Q.Enqueue(new Tuple<string, int>(adjacentWord,
                                                             level + 1));
                        }
                    }
                }
            }

            x--;
        }

        return -1;
    }

    public int LadderLength(string beginWord, string endWord,
                            IList<string> wordList) {
        if (!wordList.Contains(endWord)) {
            return 0;
        }

        this.L = beginWord.Length;
        this.allComboDict = new Dictionary<string, List<string>>();
        foreach (string word in wordList) {
            for (int i = 0; i < this.L; i++) {
                string newWord = word.Substring(0, i) + '*' +
                                 word.Substring(i + 1, this.L - i - 1);
                if (this.allComboDict.ContainsKey(newWord)) {
                    this.allComboDict[newWord].Add(word);
                } else {
                    List<string> tempList = new List<string>();
                    tempList.Add(word);
                    this.allComboDict.Add(newWord, tempList);
                }
            }
        }

        this.Q_begin = new Queue<Tuple<string, int>>();
        this.Q_begin.Enqueue(new Tuple<string, int>(beginWord, 1));
        this.Q_end = new Queue<Tuple<string, int>>();
        this.Q_end.Enqueue(new Tuple<string, int>(endWord, 1));
        this.visitedBegin = new Dictionary<string, int> { { beginWord, 1 } };
        this.visitedEnd = new Dictionary<string, int> { { endWord, 1 } };
        while (this.Q_begin.Count != 0 && this.Q_end.Count != 0) {
            int ans = -1;
            if (this.Q_begin.Count <= this.Q_end.Count) {
                ans = this.visitWordNode(this.Q_begin, this.visitedBegin,
                                         this.visitedEnd);
            } else {
                ans = this.visitWordNode(this.Q_end, this.visitedEnd,
                                         this.visitedBegin);
            }

            if (ans > -1) {
                return ans;
            }
        }

        return 0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
var (
    AllComboDict map[string][]string
    L            int
)

func visitWordNode(
    Q *list.List,
    Visited *map[string]int,
    OthersVisited *map[string]int,
) int {
    for sz := Q.Len(); sz > 0; sz-- {
        element := Q.Front()
        node := element.Value.([2]interface{})
        Q.Remove(element)
        word := node[0].(string)
        level := node[1].(int)
        for i := 0; i < L; i++ {
            newWord := word[:i] + "*" + word[i+1:]
            for _, adjacentWord := range AllComboDict[newWord] {
                if _, ok := (*OthersVisited)[adjacentWord]; ok {
                    return level + (*OthersVisited)[adjacentWord]
                }
                if _, ok := (*Visited)[adjacentWord]; !ok {
                    (*Visited)[adjacentWord] = level + 1
                    Q.PushBack([2]interface{}{adjacentWord, level + 1})
                }
            }
        }
    }
    return -1
}

func ladderLength(beginWord string, endWord string, wordList []string) int {
    wordSet := make(map[string]bool)
    for _, word := range wordList {
        wordSet[word] = true
    }
    if _, ok := wordSet[endWord]; !ok {
        return 0
    }
    AllComboDict = make(map[string][]string)
    L = len(beginWord)
    for _, word := range wordList {
        for i := 0; i < L; i++ {
            newWord := word[:i] + "*" + word[i+1:]
            AllComboDict[newWord] = append(AllComboDict[newWord], word)
        }
    }
    q_beg := list.New()
    q_beg.PushBack([2]interface{}{beginWord, 1})
    q_end := list.New()
    q_end.PushBack([2]interface{}{endWord, 1})
    visited_beg := make(map[string]int)
    visited_beg[beginWord] = 1
    visited_end := make(map[string]int)
    visited_end[endWord] = 1
    for q_beg.Len() > 0 && q_end.Len() > 0 {
        ans := -1
        if q_beg.Len() <= q_end.Len() {
            ans = visitWordNode(q_beg, &visited_beg, &visited_end)
        } else {
            ans = visitWordNode(q_end, &visited_end, &visited_beg)
        }
        if ans > -1 {
            return ans
        }
    }
    return 0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int L;
    private Map<String, List<String>> allComboDict;

    Solution() {
        this.L = 0;

        // Dictionary to hold combination of words that can be formed,
        // from any given word. By changing one letter at a time.
        this.allComboDict = new HashMap<>();
    }

    private int visitWordNode(
        Queue<Pair<String, Integer>> Q,
        Map<String, Integer> visited,
        Map<String, Integer> othersVisited
    ) {
        for (int j = Q.size(); j > 0; j--) {
            Pair<String, Integer> node = Q.remove();
            String word = node.getKey();
            int level = node.getValue();

            for (int i = 0; i < this.L; i++) {
                // Intermediate words for current word
                String newWord =
                    word.substring(0, i) + '*' + word.substring(i + 1, L);

                // Next states are all the words which share the same intermediate state.
                for (String adjacentWord : this.allComboDict.getOrDefault(
                        newWord,
                        new ArrayList<>()
                    )) {
                    // If at any point if we find what we are looking for
                    // i.e. the end word - we can return with the answer.
                    if (othersVisited.containsKey(adjacentWord)) {
                        return level + othersVisited.get(adjacentWord);
                    }

                    if (!visited.containsKey(adjacentWord)) {
                        // Save the level as the value of the dictionary, to save number of hops.
                        visited.put(adjacentWord, level + 1);
                        Q.add(new Pair(adjacentWord, level + 1));
                    }
                }
            }
        }
        return -1;
    }

    public int ladderLength(
        String beginWord,
        String endWord,
        List<String> wordList
    ) {
        if (!wordList.contains(endWord)) {
            return 0;
        }

        // Since all words are of same length.
        this.L = beginWord.length();

        wordList.forEach(word -> {
            for (int i = 0; i < L; i++) {
                // Key is the generic word
                // Value is a list of words which have the same intermediate generic word.
                String newWord =
                    word.substring(0, i) + '*' + word.substring(i + 1, L);
                List<String> transformations =
                    this.allComboDict.getOrDefault(newWord, new ArrayList<>());
                transformations.add(word);
                this.allComboDict.put(newWord, transformations);
            }
        });

        // Queues for birdirectional BFS
        // BFS starting from beginWord
        Queue<Pair<String, Integer>> Q_begin = new LinkedList<>();
        // BFS starting from endWord
        Queue<Pair<String, Integer>> Q_end = new LinkedList<>();
        Q_begin.add(new Pair(beginWord, 1));
        Q_end.add(new Pair(endWord, 1));

        // Visited to make sure we don't repeat processing same word.
        Map<String, Integer> visitedBegin = new HashMap<>();
        Map<String, Integer> visitedEnd = new HashMap<>();
        visitedBegin.put(beginWord, 1);
        visitedEnd.put(endWord, 1);
        int ans = -1;

        while (!Q_begin.isEmpty() && !Q_end.isEmpty()) {
            // Progress forward one step from the shorter queue
            if (Q_begin.size() <= Q_end.size()) {
                ans = visitWordNode(Q_begin, visitedBegin, visitedEnd);
            } else {
                ans = visitWordNode(Q_end, visitedEnd, visitedBegin);
            }

            if (ans > -1) {
                return ans;
            }
        }

        return 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function ladderLength(beginWord, endWord, wordList) {
    if (wordList.indexOf(endWord) === -1) {
        return 0;
    }
    const len = beginWord.length;
    const allComboDict = new Map();
    wordList.forEach((word) => {
        for (let i = 0; i < len; i++) {
            const newWord =
                word.substring(0, i) + "*" + word.substring(i + 1, len);
            const transformations = allComboDict.get(newWord) || [];
            transformations.push(word);
            allComboDict.set(newWord, transformations);
        }
    });
    const queue = [{ word: beginWord, level: 1 }];
    const visited = { beginWord: true };
    while (queue.length) {
        const current = queue.shift();
        for (let i = 0; i < len; i++) {
            const newWord =
                current.word.substring(0, i) +
                "*" +
                current.word.substring(i + 1, len);
            if (allComboDict.has(newWord)) {
                for (const adjacentWord of allComboDict.get(newWord) || []) {
                    if (adjacentWord === endWord) {
                        return current.level + 1;
                    }
                    if (!visited[adjacentWord]) {
                        visited[adjacentWord] = true;
                        queue.push({
                            word: adjacentWord,
                            level: current.level + 1,
                        });
                    }
                }
            }
        }
    }
    return 0;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import defaultdict


class Solution(object):
    def __init__(self):
        self.length: int = 0
        # Dictionary to hold combination of words that can be formed,
        # from any given word. By changing one letter at a time.
        self.all_combo_dict: Dict[str, List[str]] = defaultdict(list)

    def visitWordNode(
        self,
        queue: Deque[str],
        visited: Dict[str, int],
        others_visited: Dict[str, int],
    ) -> Any:
        queue_size: int = len(queue)
        for _ in range(queue_size):
            current_word: str = queue.popleft()
            for i in range(self.length):
                # Intermediate words for current word
                intermediate_word: str = (
                    current_word[:i] + "*" + current_word[i + 1 :]
                )

                # Next states are all the words which share the same intermediate state.
                for word in self.all_combo_dict[intermediate_word]:
                    # If the intermediate state/word has already been visited from the
                    # other parallel traversal this means we have found the answer.
                    if word in others_visited:
                        return visited[current_word] + others_visited[word]
                    if word not in visited:
                        # Save the level as the value of the dictionary, to save number of hops.
                        visited[word] = visited[current_word] + 1
                        queue.append(word)

        return None

    def ladderLength(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> int:
        if (
            endWord not in wordList
            or not endWord
            or not beginWord
            or not wordList
        ):
            return 0

        # Since all words are of same length.
        self.length = len(beginWord)

        for word in wordList:
            for i in range(self.length):
                # Key is the generic word
                # Value is a list of words which have the same intermediate generic word.
                self.all_combo_dict[word[:i] + "*" + word[i + 1 :]].append(word)

        # Queues for birdirectional BFS
        queue_begin: Deque[str] = collections.deque(
            [beginWord]
        )  # BFS starting from beginWord
        queue_end: Deque[str] = collections.deque(
            [endWord]
        )  # BFS starting from endWord

        # Visited to make sure we don't repeat processing same word
        visited_begin: Dict[str, int] = {beginWord: 1}
        visited_end: Dict[str, int] = {endWord: 1}
        ans: Any = None

        # We do a birdirectional search starting one pointer from begin
        # word and one pointer from end word. Hopping one by one.
        while queue_begin and queue_end:

            # Progress forward one step from the shorter queue
            if len(queue_begin) <= len(queue_end):
                ans = self.visitWordNode(
                    queue_begin, visited_begin, visited_end
                )
            else:
                ans = self.visitWordNode(queue_end, visited_end, visited_begin)
            if ans:
                return ans

        return 0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function ladderLength(
    beginWord: string,
    endWord: string,
    wordList: string[],
): number {
    if (wordList.indexOf(endWord) === -1) {
        return 0;
    }
    const len = beginWord.length;
    const allComboDict = new Map<string, string[]>();
    wordList.forEach((word) => {
        for (let i = 0; i < len; i++) {
            const newWord =
                word.substring(0, i) + "*" + word.substring(i + 1, len);
            const transformations = allComboDict.get(newWord) || [];
            transformations.push(word);
            allComboDict.set(newWord, transformations);
        }
    });
    const queue = [{ word: beginWord, level: 1 }];
    const visited = { beginWord: true };
    while (queue.length) {
        const current = queue.shift()!;
        for (let i = 0; i < len; i++) {
            const newWord =
                current.word.substring(0, i) +
                "*" +
                current.word.substring(i + 1, len);
            if (allComboDict.has(newWord)) {
                for (const adjacentWord of allComboDict.get(newWord) || []) {
                    if (adjacentWord === endWord) {
                        return current.level + 1;
                    }
                    if (!visited[adjacentWord]) {
                        visited[adjacentWord] = true;
                        queue.push({
                            word: adjacentWord,
                            level: current.level + 1,
                        });
                    }
                }
            }
        }
    }
    return 0;
}
```

</details>
