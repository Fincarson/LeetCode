# 737. Sentence Similarity II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/sentence-similarity-ii/)  
`Array` `Hash Table` `String` `Depth-First Search` `Breadth-First Search` `Union-Find`

**Problem Link:** [LeetCode 737 - Sentence Similarity II](https://leetcode.com/problems/sentence-similarity-ii/)

## Problem

We can represent a sentence as an array of words, for example, the sentence "I am happy with leetcode" can be represented as arr = ["I","am",happy","with","leetcode"].

Given two sentences sentence1 and sentence2 each represented as a string array and given an array of string pairs similarPairs where similarPairs[i] = [xi, yi] indicates that the two words xi and yi are similar.

Return true if sentence1 and sentence2 are similar, or false if they are not similar.

Two sentences are similar if:

- They have the same length (i.e., the same number of words)
- sentence1[i] and sentence2[i] are similar.

Notice that a word is always similar to itself, also notice that the similarity relation is transitive. For example, if the words a and b are similar, and the words b and c are similar, then a and c are similar.

### Example 1

```text
Input: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]
Output: true
Explanation: The two sentences have the same length and each word i of sentence1 is also similar to the corresponding word in sentence2.
```

### Example 2

```text
Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","onepiece"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
Output: true
Explanation: "leetcode" --> "platform" --> "anime" --> "manga" --> "onepiece".
Since "leetcode is similar to "onepiece" and the first two words are the same, the two sentences are similar.
```

### Example 3

```text
Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","hunterXhunter"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
Output: false
Explanation: "leetcode" is not similar to "onepiece".
```

## Constraints

- 1 <= sentence1.length, sentence2.length <= 1000
- 1 <= sentence1[i].length, sentence2[i].length <= 20
- sentence1[i] and sentence2[i] consist of lower-case and upper-case English letters.
- 0 <= similarPairs.length <= 2000
- similarPairs[i].length == 2
- 1 <= xi.length, yi.length <= 20
- xi and yi consist of English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Accounts Merge](https://leetcode.com/problems/accounts-merge/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sentence Similarity](https://leetcode.com/problems/sentence-similarity/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 737. Sentence Similarity II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java |
| Breadth First Search | C++, Java |
| Union Find | C++, Java |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
cclass Solution {
public:
    // Returns true if there is a path from source to dest.
    bool dfs(string& source, unordered_set<string>& visit,
             unordered_map<string, unordered_set<string>>& adj, string& dest) {
        visit.insert(source);
        if (source == dest) {
            return true;
        }
        for (auto neighbor : adj[source]) {
            if (!visit.count(neighbor) && dfs(neighbor, visit, adj, dest)) {
                return true;
            }
        }
        return false;
    }

    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2,
                                vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        // Create the graph using each pair in similarPairs.
        unordered_map<string, unordered_set<string>> adj;
        for (auto& pair : similarPairs) {
            adj[pair[0]].insert(pair[1]);
            adj[pair[1]].insert(pair[0]);
        }
        // The number of nodes in the graph.
        int nodesCount = adj.size();
        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            unordered_set<string> visit;
            if (adj.count(sentence1[i]) && adj.count(sentence2[i]) &&
                dfs(sentence1[i], visit, adj, sentence2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns true if there is a path from node to dest.
    boolean dfs(String node, Map<String, HashSet<String>> adj, Set<String> visit, String dest) {
        visit.add(node);
        if (node.equals(dest)) {
            return true;
        }
        if (!adj.containsKey(node)) {
            return false;
        }
        for (String neighbor : adj.get(node)) {
            if (!visit.contains(neighbor) && dfs(neighbor, adj, visit, dest)) {
                return true;
            }
        }
        return false;
    }

    public boolean areSentencesSimilarTwo(String[] sentence1, String[] sentence2,
            List<List<String>> similarPairs) {
        if (sentence1.length != sentence2.length) {
            return false;
        }
        // Create the graph using each pair in similarPairs.
        Map<String, HashSet<String>> adj = new HashMap<>();
        for (List<String> pair : similarPairs) {
            adj.computeIfAbsent(pair.get(0), value -> new HashSet<String>()).add(pair.get(1));
            adj.computeIfAbsent(pair.get(1), value -> new HashSet<String>()).add(pair.get(0));
        }

        for (int i = 0; i < sentence1.length; i++) {
            if (sentence1[i].equals(sentence2[i])) {
                continue;
            }
            Set<String> visit = new HashSet<>();
            if (adj.containsKey(sentence1[i]) && adj.containsKey(sentence2[i]) &&
                    dfs(sentence1[i], adj, visit, sentence2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
}
```

</details>

<br>

## Approach 2: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Returns true if there is a path from node to dest.
    bool bfs(string& source, unordered_map<string, unordered_set<string>>& adj, string& dest) {
        unordered_set<string> visit;
        queue<string> q;
        q.push(source);
        visit.insert(source);

        while (!q.empty()) {
            string node = q.front();
            q.pop();
            for (auto& neighbor : adj[node]) {
                if (neighbor == dest) {
                    return true;
                }
                if (!visit.count(neighbor)) {
                    visit.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return false;
    }

    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2,
                                vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        // Create the graph using each pair in similarPairs.
        unordered_map<string, unordered_set<string>> adj;
        for (auto& pair : similarPairs) {
            adj[pair[0]].insert(pair[1]);
            adj[pair[1]].insert(pair[0]);
        }

        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            if (adj.count(sentence1[i]) && adj.count(sentence2[i]) &&
                bfs(sentence1[i], adj, sentence2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns true if there is a path from node to dest.
    boolean bfs(String source, Map<String, HashSet<String>> adj, String dest) {
        Set<String> visit = new HashSet<>();
        Queue<String> q = new LinkedList<>();
        q.offer(source);
        visit.add(source);

        while (!q.isEmpty()) {
            String node = q.poll();

            if (!adj.containsKey(node)) {
                continue;
            }
            for (String neighbor : adj.get(node)) {
                if (neighbor.equals(dest)) {
                    return true;
                }
                if (!visit.contains(neighbor)) {
                    visit.add(neighbor);
                    q.offer(neighbor);
                }
            }
        }
        return false;
    }

    public boolean areSentencesSimilarTwo(String[] sentence1, String[] sentence2,
            List<List<String>> similarPairs) {
        if (sentence1.length != sentence2.length) {
            return false;
        }
        // Create the graph using each pair in similarPairs.
        Map<String, HashSet<String>> adj = new HashMap<>();
        for (List<String> pair : similarPairs) {
            adj.computeIfAbsent(pair.get(0), value -> new HashSet<String>()).add(pair.get(1));
            adj.computeIfAbsent(pair.get(1), value -> new HashSet<String>()).add(pair.get(0));
        }

        for (int i = 0; i < sentence1.length; i++) {
            if (sentence1[i].equals(sentence2[i])) {
                continue;
            }
            if (adj.containsKey(sentence1[i]) && adj.containsKey(sentence2[i]) &&
                    bfs(sentence1[i], adj, sentence2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
}
```

</details>

<br>

## Approach 3: Union Find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {
private:
    map<string, string> parent;
    map<string, int> rank;

public:
    void addWord(string x) {
        if (!parent.count(x)) {
            parent[x] = x;
            rank[x] = 0;
        }
    }

    bool isWordPresent(string x) {
        if (parent.count(x)) {
            return true;
        }
        return false;
    }

    string find(string x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(string x, string y) {
        string xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2,
                                vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }

        UnionFind dsu;
        for (auto& pair : similarPairs) {
            // Create the graph using the hashed values of the similarPairs.
            dsu.addWord(pair[0]);
            dsu.addWord(pair[1]);
            dsu.unionSet(pair[0], pair[1]);
        }

        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            if (dsu.isWordPresent(sentence1[i]) && dsu.isWordPresent(sentence2[i]) &&
                dsu.find(sentence1[i]) == dsu.find(sentence2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class UnionFind {
    Map<String, String> parent = new HashMap<>();
    Map<String, Integer> rank = new HashMap<>();

    public void addWord(String x) {
        if (!parent.containsKey(x)) {
            parent.put(x, x);
            rank.put(x, 0);
        }
    }

    public boolean isWordPresent(String x) {
        if (parent.containsKey(x)) {
            return true;
        }
        return false;
    }

    public String find(String x) {
        if (parent.get(x) != x)
            parent.put(x, find(parent.get(x)));
        return parent.get(x);
    }

    public void union(String x, String y) {
        String xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank.get(xset) < rank.get(yset)) {
            parent.put(xset, yset);
        } else if (rank.get(xset) > rank.get(yset)) {
            parent.put(yset, xset);
        } else {
            parent.put(yset, xset);
            rank.put(xset, rank.get(xset) + 1);
        }
    }
}

class Solution {
    public boolean areSentencesSimilarTwo(String[] sentence1, String[] sentence2,
            List<List<String>> similarPairs) {
        if (sentence1.length != sentence2.length) {
            return false;
        }

        UnionFind dsu = new UnionFind();
        for (List<String> pair : similarPairs) {
            // Create the graph using the hashed values of the similarPairs.
            dsu.addWord(pair.get(0));
            dsu.addWord(pair.get(1));
            dsu.union(pair.get(0), pair.get(1));
        }

        for (int i = 0; i < sentence1.length; i++) {
            if (sentence1[i].equals(sentence2[i])) {
                continue;
            }
            if (dsu.isWordPresent(sentence1[i]) && dsu.isWordPresent(sentence2[i]) &&
                    dsu.find(sentence1[i]) == dsu.find(sentence2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
}
```

</details>
