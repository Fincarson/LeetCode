# 126. Word Ladder II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/word-ladder-ii/)  
`Hash Table` `String` `Backtracking` `Breadth-First Search`

**Problem Link:** [LeetCode 126 - Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)

## Problem

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

- Every adjacent pair of words differs by a single letter.
- Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
- sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

### Example 1

```text
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
```

### Example 2

```text
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

## Constraints

- 1 <= beginWord.length <= 5
- endWord.length == beginWord.length
- 1 <= wordList.length <= 500
- wordList[i].length == beginWord.length
- beginWord, endWord, and wordList[i] consist of lowercase English letters.
- beginWord != endWord
- All the words in wordList are unique.
- The sum of all shortest transformation sequences does not exceed 105.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Ladder](https://leetcode.com/problems/word-ladder/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Groups of Strings](https://leetcode.com/problems/groups-of-strings/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 126. Word Ladder II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search (BFS) + Backtracking | C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bidirectional Breadth-First Search (BFS) + Backtracking (**Time Limit Exceeded**) | C++, C#, Java, Python3 |

## Approach 1: Breadth-First Search (BFS) + Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;

    vector<string> findNeighbors(string &word,
                                 unordered_set<string> &wordList) {
        vector<string> neighbors;

        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];

            // replace the i-th character with all letters from a to z except
            // the original character
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                // skip if the character is same as original or if the word is
                // not present in the wordList
                if (c == oldChar || !wordList.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }

    void backtrack(string &source, string &destination) {
        // store the path if we reached the endWord
        if (source == destination) {
            shortestPaths.push_back(
                vector<string>(currPath.rbegin(), currPath.rend()));
        }
        for (int i = 0; i < adjList[source].size(); i++) {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }

    void bfs(string &beginWord, string &endWord,
             unordered_set<string> &wordList) {
        queue<string> q;
        q.push(beginWord);

        // remove the root word which is the first layer
        if (wordList.find(beginWord) != wordList.end()) {
            wordList.erase(wordList.find(beginWord));
        }

        unordered_map<string, int> isEnqueued;
        isEnqueued[beginWord] = 1;

        while (!q.empty()) {
            // visited will store the words of current layer
            vector<string> visited;

            for (int i = q.size() - 1; i >= 0; i--) {
                string currWord = q.front();
                q.pop();

                // findNeighbors will have the adjacent words of the currWord
                vector<string> neighbors = findNeighbors(currWord, wordList);
                for (auto word : neighbors) {
                    visited.push_back(word);
                    // add the edge from word to currWord in the list
                    adjList[word].push_back(currWord);

                    if (isEnqueued.find(word) == isEnqueued.end()) {
                        q.push(word);
                        isEnqueued[word] = 1;
                    }
                }
            }
            // removing the words of the previous layer
            for (int i = 0; i < visited.size(); i++) {
                if (wordList.find(visited[i]) != wordList.end()) {
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList) {
        // copying the words into the set for efficient deletion in BFS
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        // build the DAG using BFS
        bfs(beginWord, endWord, copiedWordList);

        // every path will start from the endWord
        currPath = {endWord};
        // traverse the DAG to find all the paths between endWord and beginWord
        backtrack(endWord, beginWord);

        return shortestPaths;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    Dictionary<string, List<string>> adjList =
        new Dictionary<string, List<string>>();

    List<string> currPath = new List<string>();
    List<IList<string>> shortestPaths = new List<IList<string>>();

    private List<string> FindNeighbors(string word, HashSet<string> wordList) {
        List<string> neighbors = new List<string>();
        char[] charList = word.ToCharArray();
        for (int i = 0; i < word.Length; i++) {
            char oldChar = charList[i];

            // replace the i-th character with all letters from a to z except
            // the original character
            for (char c = 'a'; c <= 'z'; c++) {
                charList[i] = c;

                // skip if the character is same as original or if the word is
                // not present in the wordList
                if (c == oldChar ||
                    !wordList.Contains(string.Join("", charList))) {
                    continue;
                }

                neighbors.Add(string.Join("", charList));
            }

            charList[i] = oldChar;
        }

        return neighbors;
    }

    private void Backtrack(string source, string destination) {
        // store the path if we reached the endWord
        if (source.Equals(destination)) {
            List<string> tempPath = new List<string>(currPath);
            tempPath.Reverse();
            shortestPaths.Add(tempPath);
        }

        if (!adjList.ContainsKey(source)) {
            return;
        }

        for (int i = 0; i < adjList[source].Count; i++) {
            currPath.Add(adjList[source][i]);
            Backtrack(adjList[source][i], destination);
            currPath.RemoveAt(currPath.Count - 1);
        }
    }

    private void bfs(string beginWord, string endWord,
                     HashSet<string> wordList) {
        Queue<string> q = new Queue<string>();
        q.Enqueue(beginWord);

        // remove the root word which is the first layer in the BFS
        if (wordList.Contains(beginWord)) {
            wordList.Remove(beginWord);
        }

        Dictionary<string, int> isEnqueued = new Dictionary<string, int>();
        isEnqueued[beginWord] = 1;

        while (q.Count > 0) {
            List<string> visited = new List<string>();
            for (int i = q.Count - 1; i >= 0; i--) {
                string currWord = q.Peek();
                q.Dequeue();

                // findNeighbors will have the adjacent words of the currWord
                List<string> neighbors = FindNeighbors(currWord, wordList);
                foreach (string word in neighbors) {
                    visited.Add(word);
                    if (!adjList.ContainsKey(word)) {
                        adjList[word] = new List<string>();
                    }

                    // add the edge from word to currWord in the list
                    adjList[word].Add(currWord);
                    if (!isEnqueued.ContainsKey(word)) {
                        q.Enqueue(word);
                        isEnqueued[word] = 1;
                    }
                }
            }

            // removing the words of the previous layer
            for (int i = 0; i < visited.Count; i++) {
                if (wordList.Contains(visited[i])) {
                    wordList.Remove(visited[i]);
                }
            }
        }
    }

    public IList<IList<string>> FindLadders(string beginWord, string endWord,
                                            IList<string> wordList) {
        // copying the words into the set for efficient deletion in BFS
        HashSet<string> copiedWordList = new HashSet<string>(wordList);
        bfs(beginWord, endWord, copiedWordList);

        // every path will start from the endWord
        currPath.Add(endWord);
        // traverse the DAG to find all the paths between endWord and beginWord
        Backtrack(endWord, beginWord);

        return shortestPaths;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findLadders(
    beginWord string,
    endWord string,
    wordList []string,
) [][]string {
    adjList := make(map[string][]string)
    var currPath []string
    var shortestPaths [][]string

    wordSet := make(map[string]bool)
    // copying the words into the set for efficient deletion in BFS
    for _, word := range wordList {
        wordSet[word] = true
    }
    // build the DAG using BFS
    bfs(beginWord, endWord, wordSet, adjList)

    // every path will start from the endWord
    currPath = append(currPath, endWord)
    // traverse the DAG to find all the paths between endWord and beginWord
    backtrack(endWord, beginWord, &currPath, &shortestPaths, adjList)

    return shortestPaths
}

func findNeighbors(word string, wordSet map[string]bool) []string {
    var neighbors []string
    charList := []rune(word)
    for i := range charList {
        oldChar := charList[i]
        // replace the i-th character with all letters from a to z except the original character
        for c := 'a'; c <= 'z'; c++ {
            charList[i] = c
            newWord := string(charList)
            // skip if the character is same as original or if the word is not present in the wordSet
            if c == oldChar || !wordSet[newWord] {
                continue
            }
            neighbors = append(neighbors, newWord)
        }
        charList[i] = oldChar
    }
    return neighbors
}

func backtrack(
    source string,
    destination string,
    currPath *[]string,
    shortestPaths *[][]string,
    adjList map[string][]string,
) {
    // store the path if we reached the endWord
    if source == destination {
        tempPath := make([]string, len(*currPath))
        copy(tempPath, *currPath)
        for i, j := 0, len(tempPath)-1; i < j; i, j = i+1, j-1 {
            tempPath[i], tempPath[j] = tempPath[j], tempPath[i]
        }
        *shortestPaths = append(*shortestPaths, tempPath)
    }

    if neighbors, ok := adjList[source]; ok {
        for _, neighbor := range neighbors {
            *currPath = append(*currPath, neighbor)
            backtrack(neighbor, destination, currPath, shortestPaths, adjList)
            *currPath = (*currPath)[:len(*currPath)-1]
        }
    }
}

func bfs(
    beginWord string,
    endWord string,
    wordSet map[string]bool,
    adjList map[string][]string,
) {
    queue := []string{beginWord}
    // remove the root word which is the first layer in the BFS
    delete(wordSet, beginWord)
    isEnqueued := make(map[string]bool)
    isEnqueued[beginWord] = true

    for len(queue) > 0 {
        var visited []string
        for _, currWord := range queue {
            queue = queue[1:]
            // findNeighbors will have the adjacent words of the currWord
            neighbors := findNeighbors(currWord, wordSet)
            for _, neighbor := range neighbors {
                if !isEnqueued[neighbor] {
                    queue = append(queue, neighbor)
                    isEnqueued[neighbor] = true
                }
                adjList[neighbor] = append(adjList[neighbor], currWord)
                visited = append(visited, neighbor)
            }
        }
        // removing the words of the previous layer
        for _, word := range visited {
            delete(wordSet, word)
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Map<String, List<String>> adjList = new HashMap<String, List<String>>();
    List<String> currPath = new ArrayList<String>();
    List<List<String>> shortestPaths = new ArrayList<List<String>>();

    private List<String> findNeighbors(String word, Set<String> wordList) {
        List<String> neighbors = new ArrayList<String>();
        char charList[] = word.toCharArray();

        for (int i = 0; i < word.length(); i++) {
            char oldChar = charList[i];

            // replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++) {
                charList[i] = c;

                // skip if the character is same as original or if the word is not present in the wordList
                if (
                    c == oldChar || !wordList.contains(String.valueOf(charList))
                ) {
                    continue;
                }
                neighbors.add(String.valueOf(charList));
            }
            charList[i] = oldChar;
        }
        return neighbors;
    }

    private void backtrack(String source, String destination) {
        // store the path if we reached the endWord
        if (source.equals(destination)) {
            List<String> tempPath = new ArrayList<String>(currPath);
            Collections.reverse(tempPath);
            shortestPaths.add(tempPath);
        }

        if (!adjList.containsKey(source)) {
            return;
        }

        for (int i = 0; i < adjList.get(source).size(); i++) {
            currPath.add(adjList.get(source).get(i));
            backtrack(adjList.get(source).get(i), destination);
            currPath.remove(currPath.size() - 1);
        }
    }

    private void bfs(String beginWord, String endWord, Set<String> wordList) {
        Queue<String> q = new LinkedList<>();
        q.add(beginWord);

        // remove the root word which is the first layer in the BFS
        if (wordList.contains(beginWord)) {
            wordList.remove(beginWord);
        }

        Map<String, Integer> isEnqueued = new HashMap<String, Integer>();
        isEnqueued.put(beginWord, 1);

        while (q.size() > 0) {
            // visited will store the words of current layer
            List<String> visited = new ArrayList<String>();

            for (int i = q.size() - 1; i >= 0; i--) {
                String currWord = q.peek();
                q.remove();

                // findNeighbors will have the adjacent words of the currWord
                List<String> neighbors = findNeighbors(currWord, wordList);
                for (String word : neighbors) {
                    visited.add(word);

                    if (!adjList.containsKey(word)) {
                        adjList.put(word, new ArrayList<String>());
                    }

                    // add the edge from word to currWord in the list
                    adjList.get(word).add(currWord);
                    if (!isEnqueued.containsKey(word)) {
                        q.add(word);
                        isEnqueued.put(word, 1);
                    }
                }
            }
            // removing the words of the previous layer
            for (int i = 0; i < visited.size(); i++) {
                if (wordList.contains(visited.get(i))) {
                    wordList.remove(visited.get(i));
                }
            }
        }
    }

    public List<List<String>> findLadders(
        String beginWord,
        String endWord,
        List<String> wordList
    ) {
        // copying the words into the set for efficient deletion in BFS
        Set<String> copiedWordList = new HashSet<>(wordList);
        // build the DAG using BFS
        bfs(beginWord, endWord, copiedWordList);

        // every path will start from the endWord
        currPath.add(endWord);
        // traverse the DAG to find all the paths between endWord and beginWord
        backtrack(endWord, beginWord);

        return shortestPaths;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findLadders = function (beginWord, endWord, wordList) {
    let adjList = {};
    let currPath = [];
    let shortestPaths = [];

    function findNeighbors(word, wordSet) {
        let neighbors = [];
        let charList = Array.from(word);
        for (let i = 0; i < charList.length; i++) {
            let oldChar = charList[i];
            // replace the i-th character with all letters from a to z except the original character
            for (let c = "a".charCodeAt(0); c <= "z".charCodeAt(0); c++) {
                charList[i] = String.fromCharCode(c);
                let newWord = charList.join("");
                // skip if the character is same as original or if the word is not present in the wordSet
                if (c === oldChar.charCodeAt(0) || !wordSet.has(newWord)) {
                    continue;
                }
                neighbors.push(newWord);
            }
            charList[i] = oldChar;
        }
        return neighbors;
    }

    function backtrack(source, destination) {
        // store the path if we reached the endWord
        if (source === destination) {
            let tempPath = Array.from(currPath);
            tempPath.reverse();
            shortestPaths.push(tempPath);
        }

        if (!adjList.hasOwnProperty(source)) {
            return;
        }

        adjList[source].forEach((neighbor) => {
            currPath.push(neighbor);
            backtrack(neighbor, destination);
            currPath.pop();
        });
    }

    function bfs(beginWord, endWord, wordSet) {
        let q = [beginWord];
        // remove the root word which is the first layer in the BFS
        wordSet.delete(beginWord);
        let isEnqueued = { [beginWord]: true };
        while (q.length > 0) {
            // visited will store the words of current layer
            let visited = [];
            for (let i = q.length - 1; i >= 0; i--) {
                let currWord = q.shift();
                // findNeighbors will have the adjacent words of the currWord
                let neighbors = findNeighbors(currWord, wordSet);
                neighbors.forEach((neighbor) => {
                    visited.push(neighbor);
                    if (!adjList.hasOwnProperty(neighbor)) {
                        adjList[neighbor] = [];
                    }
                    // add the edge from neighbor to currWord in the list
                    adjList[neighbor].push(currWord);
                    if (!isEnqueued.hasOwnProperty(neighbor)) {
                        q.push(neighbor);
                        isEnqueued[neighbor] = true;
                    }
                });
            }
            // removing the words of the previous layer
            visited.forEach((word) => wordSet.delete(word));
        }
    }

    // copying the words into the set for efficient deletion in BFS
    let wordSet = new Set(wordList);
    bfs(beginWord, endWord, wordSet);

    // every path will start from the endWord
    currPath = [endWord];
    // traverse the DAG to find all the paths between endWord and beginWord
    backtrack(endWord, beginWord);

    return shortestPaths;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.adjList: Dict[str, List[str]] = {}
        self.currPath: List[str] = []
        self.shortestPaths: List[List[str]] = []

    def findNeighbors(self, word: str, wordSet: Set[str]) -> List[str]:
        neighbors: List[str] = []
        charList = list(word)
        for i in range(len(charList)):
            oldChar = charList[i]
            # replace the i-th character with all letters from a to z except the original character
            for c in "abcdefghijklmnopqrstuvwxyz":
                charList[i] = c
                newWord = "".join(charList)
                # skip if the character is same as original or if the word is not present in the wordSet
                if c == oldChar or newWord not in wordSet:
                    continue
                neighbors.append(newWord)
            charList[i] = oldChar
        return neighbors

    def backtrack(self, source: str, destination: str):
        # store the path if we reached the endWord
        if source == destination:
            tempPath = self.currPath.copy()
            tempPath.reverse()
            self.shortestPaths.append(tempPath)

        if source not in self.adjList:
            return

        for neighbor in self.adjList[source]:
            self.currPath.append(neighbor)
            self.backtrack(neighbor, destination)
            self.currPath.pop()

    def bfs(self, beginWord: str, endWord: str, wordSet: Set[str]):
        q: Deque[str] = deque([beginWord])
        # remove the root word which is the first layer in the BFS
        wordSet.discard(
            beginWord
        )  # discard does nothing if element is not found
        isEnqueued: Dict[str, bool] = {beginWord: True}
        while q:
            # visited will store the words of current layer
            visited: List[str] = []
            for _ in range(len(q)):
                currWord = q.popleft()
                # findNeighbors will have the adjacent words of the currWord
                neighbors = self.findNeighbors(currWord, wordSet)
                for neighbor in neighbors:
                    visited.append(neighbor)
                    if neighbor not in self.adjList:
                        self.adjList[neighbor] = []
                    # add the edge from neighbor to currWord in the list
                    self.adjList[neighbor].append(currWord)
                    if neighbor not in isEnqueued:
                        q.append(neighbor)
                        isEnqueued[neighbor] = True
            # removing the words of the previous layer
            for word in visited:
                wordSet.discard(word)

    def findLadders(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> List[List[str]]:
        wordSet: Set[str] = set(
            wordList
        )  # Use a set for efficient removal and checks
        # build the DAG using BFS
        self.bfs(beginWord, endWord, wordSet)

        # every path will start from the endWord
        self.currPath = [endWord]
        # traverse the DAG to find all the paths between endWord and beginWord
        self.backtrack(endWord, beginWord)

        return self.shortestPaths
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type StringList = string[];
type WordSet = Set<string>;
type AdjList = Record<string, StringList>;

function findLadders(
    beginWord: string,
    endWord: string,
    wordList: string[],
): string[][] {
    let adjList: AdjList = {};
    let currPath: StringList = [];
    let shortestPaths: StringList[] = [];

    const findNeighbors = (word: string, wordSet: WordSet): StringList => {
        let neighbors: StringList = [];
        let charList = Array.from(word);
        for (let i = 0; i < charList.length; i++) {
            let oldChar = charList[i];
            // replace the i-th character with all letters from a to z except the original character
            for (let c = "a".charCodeAt(0); c <= "z".charCodeAt(0); c++) {
                charList[i] = String.fromCharCode(c);
                let newWord = charList.join("");
                // skip if the character is same as original or if the word is not present in the wordSet
                if (c === oldChar.charCodeAt(0) || !wordSet.has(newWord)) {
                    continue;
                }
                neighbors.push(newWord);
            }
            charList[i] = oldChar;
        }
        return neighbors;
    };

    const backtrack = (source: string, destination: string) => {
        // store the path if we reached the endWord
        if (source === destination) {
            let tempPath = [...currPath];
            tempPath.reverse();
            shortestPaths.push(tempPath);
        }

        if (!adjList[source]) {
            return;
        }

        adjList[source].forEach((neighbor) => {
            currPath.push(neighbor);
            backtrack(neighbor, destination);
            currPath.pop();
        });
    };

    const bfs = (beginWord: string, endWord: string, wordSet: WordSet) => {
        let q: string[] = [beginWord];
        // remove the root word which is the first layer in the BFS
        wordSet.delete(beginWord);
        let isEnqueued: Record<string, boolean> = { [beginWord]: true };
        while (q.length > 0) {
            // visited will store the words of current layer
            let visited: StringList = [];
            for (let i = q.length - 1; i >= 0; i--) {
                let currWord = q.shift()!;
                // findNeighbors will have the adjacent words of the currWord
                let neighbors = findNeighbors(currWord, wordSet);
                neighbors.forEach((neighbor) => {
                    visited.push(neighbor);
                    if (!adjList[neighbor]) {
                        adjList[neighbor] = [];
                    }
                    // add the edge from neighbor to currWord in the list
                    adjList[neighbor].push(currWord);
                    if (!isEnqueued[neighbor]) {
                        q.push(neighbor);
                        isEnqueued[neighbor] = true;
                    }
                });
            }
            // removing the words of the previous layer
            visited.forEach((word) => wordSet.delete(word));
        }
    };

    // copying the words into the set for efficient deletion in BFS
    let wordSet: WordSet = new Set(wordList);
    bfs(beginWord, endWord, wordSet);

    // every path will start from the endWord
    currPath = [endWord];
    // traverse the DAG to find all the paths between endWord and beginWord
    backtrack(endWord, beginWord);

    return shortestPaths;
}
```

</details>

<br>

## Approach 2: Bidirectional Breadth-First Search (BFS) + Backtracking (**Time Limit Exceeded**)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;

    vector<string> findNeighbors(string &word,
                                 unordered_set<string> &wordList) {
        vector<string> neighbors;

        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];

            // replace the i-th character with all letters from a to z except
            // the original character
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                // skip if the character is same as original or if the word is
                // not present in the wordList
                if (c == oldChar || !wordList.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }

    void backtrack(string &source, string &destination) {
        // store the path if we reached the endWord
        if (source == destination) {
            shortestPaths.push_back(currPath);
        }
        for (int i = 0; i < adjList[source].size(); i++) {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }

    void addEdge(string &word1, string &word2, int direction) {
        if (direction == 1) {
            adjList[word1].push_back(word2);
        } else {
            adjList[word2].push_back(word1);
        }
    }

    bool bfs(string beginWord, string endWord, unordered_set<string> wordList) {
        if (wordList.count(endWord) == 0) {
            return false;
        }

        // remove the root word which is the first layer
        if (wordList.find(beginWord) != wordList.end()) {
            wordList.erase(wordList.find(beginWord));
        }

        unordered_set<string> forwardQueue, backwardQueue;
        forwardQueue.insert(beginWord);
        backwardQueue.insert(endWord);

        bool found = false;
        int direction = 1;

        while (forwardQueue.size() != 0) {
            // visited will store the words of current layer
            unordered_set<string> visited;

            // swap the queues because we are always extending the forwardQueue
            if (forwardQueue.size() > backwardQueue.size()) {
                swap(forwardQueue, backwardQueue);
                direction ^= 1;
            }

            for (auto currWord : forwardQueue) {
                vector<string> neighbors = findNeighbors(currWord, wordList);

                for (auto word : neighbors) {
                    // if the backwardQueue already contains it we can stop
                    // after completing this level
                    if (backwardQueue.find(word) != backwardQueue.end()) {
                        found = true;
                        addEdge(currWord, word, direction);

                        /* the word shouldn't be presnt in forwardQueue because
                           if it is then the edge will be between two words at
                           the same level which we don't want */
                    } else if (!found && wordList.count(word) != 0 &&
                               forwardQueue.count(word) == 0) {
                        visited.insert(word);
                        addEdge(currWord, word, direction);
                    }
                }
            }

            // removing the words of the previous layer
            for (auto currWord : forwardQueue) {
                if (wordList.find(currWord) != wordList.end()) {
                    wordList.erase(wordList.find(currWord));
                }
            }
            if (found) {
                break;
            }

            forwardQueue = visited;
        }
        return found;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList) {
        // copying the words into the set for efficient deletion in BFS
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        // build the DAG using BFS
        bool sequence_found = bfs(beginWord, endWord, copiedWordList);

        // There is no valid sequence that connects `beginWord` to `endWord`
        if (sequence_found == false) {
            return shortestPaths;
        }
        // every path will start from the beginWord
        currPath = {beginWord};
        // traverse the DAG to find all the paths between beginWord and endWord
        backtrack(beginWord, endWord);

        return shortestPaths;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    Dictionary<string, List<string>> adjList =
        new Dictionary<string, List<string>>();

    List<string> currPath = new List<string>();
    List<List<string>> shortestPaths = new List<List<string>>();

    private List<string> findNeighbors(string word, HashSet<string> wordList) {
        List<string> neighbors = new List<string>();
        char[] charList = word.ToCharArray();
        for (int i = 0; i < word.Length; i++) {
            char oldChar = charList[i];
            for (char c = 'a'; c <= 'z'; c++) {
                charList[i] = c;
                if (c == oldChar || !wordList.Contains(new String(charList))) {
                    continue;
                }

                neighbors.Add(new String(charList));
            }

            charList[i] = oldChar;
        }

        return neighbors;
    }

    private void backtrack(string source, string destination) {
        if (source.Equals(destination)) {
            List<string> tempPath = new List<string>(currPath);
            shortestPaths.Add(tempPath);
        }

        if (!adjList.ContainsKey(source)) {
            return;
        }

        for (int i = 0; i < adjList[source].Count; i++) {
            currPath.Add(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.RemoveAt(currPath.Count - 1);
        }
    }

    private void addEdge(string word1, string word2, int direction) {
        if (direction == 1) {
            if (!adjList.ContainsKey(word1)) {
                adjList[word1] = new List<string>();
            }

            adjList[word1].Add(word2);
        } else {
            if (!adjList.ContainsKey(word2)) {
                adjList[word2] = new List<string>();
            }

            adjList[word2].Add(word1);
        }
    }

    private bool bfs(string beginWord, string endWord,
                     HashSet<string> wordList) {
        if (!wordList.Contains(endWord)) {
            return false;
        }

        if (wordList.Contains(beginWord)) {
            wordList.Remove(beginWord);
        }

        HashSet<string> forwardQueue = new HashSet<string>();
        HashSet<string> backwardQueue = new HashSet<string>();
        forwardQueue.Add(beginWord);
        backwardQueue.Add(endWord);
        bool found = false;
        int direction = 1;
        while (forwardQueue.Count != 0) {
            HashSet<string> visited = new HashSet<string>();
            if (forwardQueue.Count > backwardQueue.Count) {
                HashSet<string> temp = forwardQueue;
                forwardQueue = backwardQueue;
                backwardQueue = temp;
                direction ^= 1;
            }

            foreach (string currWord in forwardQueue) {
                List<string> neighbors = findNeighbors(currWord, wordList);
                foreach (string word in neighbors) {
                    if (backwardQueue.Contains(word)) {
                        found = true;
                        addEdge(currWord, word, direction);
                    } else if (!found && wordList.Contains(word) &&
                               !forwardQueue.Contains(word)) {
                        visited.Add(word);
                        addEdge(currWord, word, direction);
                    }
                }
            }

            foreach (string currWord in forwardQueue) {
                if (wordList.Contains(currWord)) {
                    wordList.Remove(currWord);
                }
            }

            if (found) {
                break;
            }

            forwardQueue = visited;
        }

        return found;
    }

    public IList<IList<string>> FindLadders(string beginWord, string endWord,
                                            IList<string> wordList) {
        HashSet<string> copiedWordList = new HashSet<string>(wordList);
        bool sequence_found = bfs(beginWord, endWord, copiedWordList);
        if (sequence_found == false) {
            return shortestPaths.ToArray();
        }

        currPath.Add(beginWord);
        backtrack(beginWord, endWord);
        return shortestPaths.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Map<String, List<String>> adjList = new HashMap<String, List<String>>();
    List<String> currPath = new ArrayList<String>();
    List<List<String>> shortestPaths = new ArrayList<List<String>>();

    private List<String> findNeighbors(String word, Set<String> wordList) {
        List<String> neighbors = new ArrayList<String>();
        char charList[] = word.toCharArray();

        for (int i = 0; i < word.length(); i++) {
            char oldChar = charList[i];

            // replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++) {
                charList[i] = c;

                // skip if the character is same as original or if the word is not present in the wordList
                if (
                    c == oldChar || !wordList.contains(String.valueOf(charList))
                ) {
                    continue;
                }
                neighbors.add(String.valueOf(charList));
            }
            charList[i] = oldChar;
        }
        return neighbors;
    }

    private void backtrack(String source, String destination) {
        //System.out.printlen(source);
        // store the path if we reached the endWord
        if (source.equals(destination)) {
            List<String> tempPath = new ArrayList<String>(currPath);
            shortestPaths.add(tempPath);
        }

        if (!adjList.containsKey(source)) {
            return;
        }

        for (int i = 0; i < adjList.get(source).size(); i++) {
            currPath.add(adjList.get(source).get(i));
            backtrack(adjList.get(source).get(i), destination);
            currPath.remove(currPath.size() - 1);
        }
    }

    private void swap(Set<String> forward, Set<String> backward) {
        Set<String> temp = forward;
        forward = backward;
        backward = temp;
    }

    private void addEdge(String word1, String word2, int direction) {
        if (direction == 1) {
            if (!adjList.containsKey(word1)) {
                adjList.put(word1, new ArrayList<String>());
            }
            adjList.get(word1).add(word2);
        } else {
            if (!adjList.containsKey(word2)) {
                adjList.put(word2, new ArrayList<String>());
            }
            adjList.get(word2).add(word1);
        }
    }

    private boolean bfs(
        String beginWord,
        String endWord,
        Set<String> wordList
    ) {
        if (wordList.contains(endWord) == false) {
            return false;
        }

        // remove the root word which is the first layer
        if (wordList.contains(beginWord)) {
            wordList.remove(beginWord);
        }

        Set<String> forwardQueue = new HashSet<String>();
        Set<String> backwardQueue = new HashSet<String>();

        forwardQueue.add(beginWord);
        backwardQueue.add(endWord);

        boolean found = false;
        int direction = 1;

        while (forwardQueue.isEmpty() != true) {
            // visited will store the words of current layer
            Set<String> visited = new HashSet<String>();

            // swap the queues because we are always extending the forwardQueue
            if (forwardQueue.size() > backwardQueue.size()) {
                Set<String> temp = forwardQueue;
                forwardQueue = backwardQueue;
                backwardQueue = temp;
                direction ^= 1;
            }

            for (String currWord : forwardQueue) {
                List<String> neighbors = findNeighbors(currWord, wordList);
                for (String word : neighbors) {
                    // if the backwardQueue already contains it we can stop after completing this level
                    if (backwardQueue.contains(word)) {
                        found = true;
                        addEdge(currWord, word, direction);
                    } /* the word shouldn't be presnt in forwardQueue because if it is then the edge will
                     be between two words at the same level which we don't want */
                    else if (
                        !found &&
                        wordList.contains(word) == true &&
                        forwardQueue.contains(word) == false
                    ) {
                        visited.add(word);
                        addEdge(currWord, word, direction);
                    }
                }
            }

            // removing the words of the previous layer
            for (String currWord : forwardQueue) {
                if (wordList.contains(currWord)) {
                    wordList.remove(currWord);
                }
            }

            if (found) {
                break;
            }

            forwardQueue = visited;
        }
        return found;
    }

    public List<List<String>> findLadders(
        String beginWord,
        String endWord,
        List<String> wordList
    ) {
        // copying the words into the set for efficient deletion in BFS
        Set<String> copiedWordList = new HashSet<>(wordList);
        // build the DAG using BFS
        boolean sequence_found = bfs(beginWord, endWord, copiedWordList);

        // There is no valid sequence that connects `beginWord` to `endWord`
        if (sequence_found == false) {
            return shortestPaths;
        }
        // every path will start from the beginWord
        currPath.add(beginWord);
        // traverse the DAG to find all the paths between beginWord and endWord
        backtrack(beginWord, endWord);

        return shortestPaths;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.adjList = {}
        self.currPath = []
        self.shortestPaths = []

    def findNeighbors(self, word, wordList):
        neighbors = []
        charList = list(word)
        for i in range(len(word)):
            oldChar = charList[i]
            for ch in range(97, 123):
                c = chr(ch)
                charList[i] = c
                if c == oldChar or "".join(charList) not in wordList:
                    continue
                neighbors.append("".join(charList))
            charList[i] = oldChar
        return neighbors

    def backtrack(self, source, destination):
        if source == destination:
            tempPath = list(self.currPath)
            self.shortestPaths.append(tempPath)
        for i in range(len(self.adjList.get(source, []))):
            self.currPath.append(self.adjList[source][i])
            self.backtrack(self.adjList[source][i], destination)
            self.currPath.pop()

    def addEdge(self, word1, word2, direction):
        if direction == 1:
            self.adjList[word1] = self.adjList.get(word1, []) + [word2]
        else:
            self.adjList[word2] = self.adjList.get(word2, []) + [word1]

    def bfs(self, beginWord, endWord, wordList):
        if endWord not in wordList:
            return False
        if beginWord in wordList:
            wordList.remove(beginWord)
        forwardQueue = set([beginWord])
        backwardQueue = set([endWord])
        found = False
        direction = 1
        while len(forwardQueue) != 0:
            visited = set()
            if len(forwardQueue) > len(backwardQueue):
                forwardQueue, backwardQueue = backwardQueue, forwardQueue
                direction ^= 1
            for currWord in forwardQueue:
                neighbors = self.findNeighbors(currWord, wordList)
                for word in neighbors:
                    if word in backwardQueue:
                        found = True
                        self.addEdge(currWord, word, direction)
                    elif (
                        not found
                        and word in wordList
                        and word not in forwardQueue
                    ):
                        visited.add(word)
                        self.addEdge(currWord, word, direction)
            for currWord in forwardQueue:
                if currWord in wordList:
                    wordList.remove(currWord)
            if found:
                break
            forwardQueue = visited
        return found

    def findLadders(self, beginWord, endWord, wordList):
        copiedWordList = set(wordList)
        sequence_found = self.bfs(beginWord, endWord, copiedWordList)
        if sequence_found == False:
            return self.shortestPaths
        self.currPath.append(beginWord)
        self.backtrack(beginWord, endWord)
        return self.shortestPaths
```

</details>
