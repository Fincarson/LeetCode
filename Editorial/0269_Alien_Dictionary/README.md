# 269. Alien Dictionary

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/alien-dictionary/)  
`Array` `String` `Depth-First Search` `Breadth-First Search` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 269 - Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)

## Problem

There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary. Now it is claimed that the strings in words are sorted lexicographically by the rules of this new language.

If this claim is incorrect, and the given arrangement of string in words cannot correspond to any order of letters, return "".

Otherwise, return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there are multiple solutions, return any of them.

### Example 1

```text
Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
```

### Example 2

```text
Input: words = ["z","x"]
Output: "zx"
```

### Example 3

```text
Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".
```

## Constraints

- 1 <= words.length <= 100
- 1 <= words[i].length <= 100
- words[i] consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 269. Alien Dictionary

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search | C++, Java, Python |
| Depth-First Search | C++, Java, Python |

## Approach 1: Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string alienOrder(vector<string>& words) {
        // Step 0: Create data structures and find all unique letters.
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> counts;
        for (string word : words) {
            for (char c : word) {
                counts[c] = 0;
                adjList[c] = vector<char>();
            }
        }

        // Step 1: Find all edges.
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            // Check that word2 is not a prefix of word1.
            if (word1.size() > word2.size() &&
                word1.substr(0, word2.size()) == word2) {
                return "";
            }
            // Find the first non match and insert the corresponding relation.
            for (int j = 0; j < min(word1.size(), word2.size()); j++) {
                if (word1[j] != word2[j]) {
                    adjList[word1[j]].push_back(word2[j]);
                    counts[word2[j]]++;
                    break;
                }
            }
        }

        // Step 2: Breadth-first search.
        string sb = "";
        queue<char> queue;
        for (auto item : counts) {
            if (item.second == 0) {
                queue.push(item.first);
            }
        }
        while (!queue.empty()) {
            char c = queue.front();
            queue.pop();
            sb += c;
            for (char next : adjList[c]) {
                counts[next]--;
                if (counts[next] == 0) {
                    queue.push(next);
                }
            }
        }

        if (sb.size() < counts.size()) {
            return "";
        }
        return sb;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public String alienOrder(String[] words) {
    // Step 0: Create data structures and find all unique letters.
    Map<Character, List<Character>> adjList = new HashMap<>();
    Map<Character, Integer> counts = new HashMap<>();
    for (String word : words) {
        for (char c : word.toCharArray()) {
            counts.put(c, 0);
            adjList.put(c, new ArrayList<>());
        }
    }

    // Step 1: Find all edges.
    for (int i = 0; i < words.length - 1; i++) {
        String word1 = words[i];
        String word2 = words[i + 1];
        // Check that word2 is not a prefix of word1.
        if (word1.length() > word2.length() && word1.startsWith(word2)) {
            return "";
        }
        // Find the first non match and insert the corresponding relation.
        for (int j = 0; j < Math.min(word1.length(), word2.length()); j++) {
            if (word1.charAt(j) != word2.charAt(j)) {
                adjList.get(word1.charAt(j)).add(word2.charAt(j));
                counts.put(word2.charAt(j), counts.get(word2.charAt(j)) + 1);
                break;
            }
        }
    }

    // Step 2: Breadth-first search.
    StringBuilder sb = new StringBuilder();
    Queue<Character> queue = new LinkedList<>();
    for (Character c : counts.keySet()) {
        if (counts.get(c).equals(0)) {
            queue.add(c);
        }
    }
    while (!queue.isEmpty()) {
        Character c = queue.remove();
        sb.append(c);
        for (Character next : adjList.get(c)) {
            counts.put(next, counts.get(next) - 1);
            if (counts.get(next).equals(0)) {
                queue.add(next);
            }
        }
    }

    if (sb.length() < counts.size()) {
        return "";
    }
    return sb.toString();
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from collections import defaultdict, Counter, deque

class Solution:
    def alienOrder(self, words: List[str]) -> str:

        # Step 0: create data structures + the in_degree of each unique letter to 0.
        adj_list = defaultdict(set)
        in_degree = Counter({c: 0 for word in words for c in word})

        # Step 1: We need to populate adj_list and in_degree.
        # For each pair of adjacent words...
        for first_word, second_word in zip(words, words[1:]):
            for c, d in zip(first_word, second_word):
                if c != d:
                    if d not in adj_list[c]:
                        adj_list[c].add(d)
                        in_degree[d] += 1
                    break
            else:  # Check that second word isn't a prefix of first word.
                if len(second_word) < len(first_word):
                    return ""

        # Step 2: We need to repeatedly pick off nodes with an indegree of 0.
        output = []
        queue = deque([c for c in in_degree if in_degree[c] == 0])
        while queue:
            c = queue.popleft()
            output.append(c)
            for d in adj_list[c]:
                in_degree[d] -= 1
                if in_degree[d] == 0:
                    queue.append(d)

        # If not all letters are in output, that means there was a cycle and so
        # no valid ordering. Return "" as per the problem description.
        if len(output) < len(in_degree):
            return ""
        # Otherwise, convert the ordering we found into a string and return it.
        return "".join(output)
```

</details>

<br>

## Approach 2: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    unordered_map<char, vector<char>> reverseAdjList;
    unordered_map<char, bool> seen;
    string output;

public:
    string alienOrder(vector<string>& words) {
        // Step 0: Put all unique letters into reverseAdjList as keys.
        for (string word : words) {
            for (char c : word) {
                if (reverseAdjList.find(c) == reverseAdjList.end())
                    reverseAdjList[c] = vector<char>();
            }
        }

        // Step 1: Find all edges and add reverse edges to reverseAdjList.
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            // Check that word2 is not a prefix of word1.
            if (word1.length() > word2.length() &&
                word1.substr(0, word2.size()) == word2)
                return "";

            // Find the first non match and insert the corresponding relation.
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                if (word1[j] != word2[j]) {
                    reverseAdjList[word2[j]].push_back(word1[j]);
                    break;
                }
            }
        }

        // Step 2: DFS to build up the output list.
        for (auto const& iter : reverseAdjList) {
            bool result = dfs(iter.first);
            if (!result) return "";
        }

        return output;
    }

    // Return true iff no cycles detected.
    bool dfs(char c) {
        if (seen.find(c) != seen.end()) {
            // If this node was grey (false), a cycle was detected.
            return seen[c];
        }
        seen[c] = false;
        for (char next : reverseAdjList[c]) {
            bool result = dfs(next);
            if (!result) return false;
        }
        seen[c] = true;
        output += c;
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private Map<Character, List<Character>> reverseAdjList = new HashMap<>();
    private Map<Character, Boolean> seen = new HashMap<>();
    private StringBuilder output = new StringBuilder();

    public String alienOrder(String[] words) {
        // Step 0: Put all unique letters into reverseAdjList as keys.
        for (String word : words) {
            for (char c : word.toCharArray()) {
                reverseAdjList.putIfAbsent(c, new ArrayList<>());
            }
        }

        // Step 1: Find all edges and add reverse edges to reverseAdjList.
        for (int i = 0; i < words.length - 1; i++) {
            String word1 = words[i];
            String word2 = words[i + 1];
            // Check that word2 is not a prefix of word1.
            if (word1.length() > word2.length() && word1.startsWith(word2)) {
                return "";
            }
            // Find the first non match and insert the corresponding relation.
            for (int j = 0; j < Math.min(word1.length(), word2.length()); j++) {
                if (word1.charAt(j) != word2.charAt(j)) {
                    reverseAdjList.get(word2.charAt(j)).add(word1.charAt(j));
                    break;
                }
            }
        }

        // Step 2: DFS to build up the output list.
        for (Character c : reverseAdjList.keySet()) {
            boolean result = dfs(c);
            if (!result) return "";
        }

        return output.toString();
    }

    // Return true iff no cycles detected.
    private boolean dfs(Character c) {
        if (seen.containsKey(c)) {
            return seen.get(c); // If this node was grey (false), a cycle was detected.
        }
        seen.put(c, false);
        for (Character next : reverseAdjList.get(c)) {
            boolean result = dfs(next);
            if (!result) return false;
        }
        seen.put(c, true);
        output.append(c);
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def alienOrder(self, words: List[str]) -> str:

        # Step 0: Put all unique letters into the adj list.
        reverse_adj_list = {c : [] for word in words for c in word}

        # Step 1: Find all edges and put them in reverse_adj_list.
        for first_word, second_word in zip(words, words[1:]):
            for c, d in zip(first_word, second_word):
                if c != d: 
                    reverse_adj_list[d].append(c)
                    break
            else: # Check that second word isn't a prefix of first word.
                if len(second_word) < len(first_word): 
                    return ""

        # Step 2: Depth-first search.
        seen = {} # False = grey, True = black.
        output = []
        def visit(node):  # Return True iff there are no cycles.
            if node in seen:
                return seen[node] # If this node was grey (False), a cycle was detected.
            seen[node] = False # Mark node as grey.
            for next_node in reverse_adj_list[node]:
                result = visit(next_node)
                if not result: 
                    return False # Cycle was detected lower down.
            seen[node] = True # Mark node as black.
            output.append(node)
            return True

        if not all(visit(node) for node in reverse_adj_list):
            return ""

        return "".join(output)
```

</details>
