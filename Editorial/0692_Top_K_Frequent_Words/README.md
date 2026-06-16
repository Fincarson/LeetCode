# 692. Top K Frequent Words

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/top-k-frequent-words/)  
`Array` `Hash Table` `String` `Trie` `Sorting` `Heap (Priority Queue)` `Bucket Sort` `Counting`

**Problem Link:** [LeetCode 692 - Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)

## Problem

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

### Example 1

```text
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
```

### Example 2

```text
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
```

## Constraints

- 1 <= words.length <= 500
- 1 <= words[i].length <= 10
- words[i] consists of lowercase English letters.
- k is in the range [1, The number of unique words[i]]

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sort Features by Popularity](https://leetcode.com/problems/sort-features-by-popularity/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sender With Largest Word Count](https://leetcode.com/problems/sender-with-largest-word-count/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Pairs in Array](https://leetcode.com/problems/maximum-number-of-pairs-in-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 692. Top K Frequent Words

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Max Heap | C++, Java, Python3 |
| Min Heap | C++, Java, Python3 |
| Bucket Sorting + Trie | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (string& word : words) {
            cnt[word]++;
        }

        vector<pair<int, string>> candidates;
        for (auto& p : cnt) {
            candidates.push_back({-p.second, p.first});
        }    
        sort(candidates.begin(), candidates.end());
        
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(candidates[i].second);
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String word : words) {
            cnt.put(word, cnt.getOrDefault(word, 0) + 1);
        }
        List<String> candidates = new ArrayList<>(cnt.keySet());
        Collections.sort(candidates,
                (w1, w2) -> cnt.get(w1).equals(cnt.get(w2)) ? w1.compareTo(w2) : cnt.get(w2) - cnt.get(w1));
        return candidates.subList(0, k);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = Counter(words)
        return sorted(list(cnt.keys()), key=lambda x: (-cnt[x], x))[:k]
```

</details>

<br>

## Approach 2: Max Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        vector<pair<int, string>> h;
        vector<string> res;
        for (string& word : words) {
            cnt[word]++;
        }
        for (auto& p : cnt) {
            h.push_back({-p.second, p.first});
        }

        make_heap(h.begin(), h.end(), greater<pair<int, string>>());
        for (int i = 0; i < k; i++) {
            pop_heap(h.begin(), h.end(), greater<pair<int, string>>());
            res.push_back(h.back().second);
            h.pop_back();
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    class Word implements Comparable<Word> {
        private String word;
        private int count;

        public Word(String word, int count) {
            this.word = word;
            this.count = count;
        }

        public int compareTo(Word other) {
            if (this.count == other.count) {
                return this.word.compareTo(other.word);
            }
            return other.count - this.count;
        }
    }

    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String word : words) {
            cnt.put(word, cnt.getOrDefault(word, 0) + 1);
        }

        List<Word> candidates = new ArrayList<>();
        for (var entry : cnt.entrySet()) {
            candidates.add(new Word(entry.getKey(), entry.getValue()));
        }

        Queue<Word> h = new PriorityQueue<>(candidates);
        List<String> res = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            res.add(h.poll().word);
        }
        return res;

    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter
from heapq import heapify, heappop


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = Counter(words)
        heap = [(-freq, word) for word, freq in cnt.items()]
        heapify(heap)

        return [heappop(heap)[1] for _ in range(k)]
```

</details>

<br>

## Approach 3: Min Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> cnt;
        vector<pair<int, string>> candidates;
        vector<string> res;
        priority_queue<pair<int, string>> h;
        for (string& word : words) {
            cnt[word]++;
        }
        for (auto& p : cnt) {
            h.push({-p.second, p.first});
            if (h.size() > k) h.pop();
        }
        while (!h.empty()) {
            candidates.push_back(h.top());
            h.pop();
        }
        sort(candidates.begin(), candidates.end());
        for (auto& p : candidates) {
            res.push_back(p.second);
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String word : words) {
            cnt.put(word, cnt.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<String> h = new PriorityQueue<>(
                (w1, w2) -> cnt.get(w1).equals(cnt.get(w2)) ? w2.compareTo(w1) : cnt.get(w1) - cnt.get(w2));

        for (String word : cnt.keySet()) {
            h.offer(word);
            if (h.size() > k) {
                h.poll();
            }
        }

        List<String> res = new ArrayList<>();
        while (!h.isEmpty()) {
            res.add(h.poll());
        }
        Collections.reverse(res);
        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter
from heapq import heappush, heappop


class Pair:
    def __init__(self, word, freq):
        self.word = word
        self.freq = freq

    def __lt__(self, p):
        return self.freq < p.freq or (self.freq == p.freq and self.word > p.word)


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = Counter(words)
        h = []
        for word, freq in cnt.items():
            heappush(h, Pair(word, freq))
            if len(h) > k:
                heappop(h)
        return [p.word for p in sorted(h, reverse=True)]
```

</details>

<br>

## Approach 4: Bucket Sorting + Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int k;

    struct TrieNode {
        TrieNode* children[26];
        bool isWord;
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    void addWord(TrieNode& root, const string& word) {
        TrieNode* cur = &root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }

    void getWords(TrieNode& root, const string& prefix, vector<string>& res) {
        if (k == 0) {
            return;
        }    
        if (root.isWord) {
            k--;
            res.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (root.children[i] != nullptr) {
                getWords(*root.children[i], prefix + (char)('a' + i), res);
            }
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = int(words.size());
        this->k = k;

        map<string, int> cnt;
        for (string& word : words) {
            cnt[word]++;
        }
        vector<string> res;
        vector<TrieNode> bucket(n + 1, TrieNode());
        for (auto& p : cnt) {
            addWord(bucket[p.second], p.first);
        }
        for (int i = n; i > 0; i--) {
            getWords(bucket[i], "", res);
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int k;
    private List<String> res;

    class TrieNode {
        TrieNode[] children;
        boolean isWord;

        public TrieNode() {
            children = new TrieNode[26];
            isWord = false;
        }
    }

    public List<String> topKFrequent(String[] words, int k) {
        this.k = k;
        res = new ArrayList<>();
        int n = words.length;
        TrieNode[] bucket = new TrieNode[n + 1];
        Map<String, Integer> cnt = new HashMap<>();

        for (String word : words) {
            cnt.put(word, cnt.getOrDefault(word, 0) + 1);
        }

        for (var entry : cnt.entrySet()) {
            if (bucket[entry.getValue()] == null) {
                bucket[entry.getValue()] = new TrieNode();
            }
            addWord(bucket[entry.getValue()], entry.getKey());
        }

        for (int i = n; i > 0; i--) {
            if (bucket[i] != null) {
                getWords(bucket[i], "");
            }
            if (this.k == 0) {
                break;
            }
        }
        return res;

    }

    private void addWord(TrieNode root, String word) {
        TrieNode cur = root;
        for (char c : word.toCharArray()) {
            if (cur.children[c - 'a'] == null) {
                cur.children[c - 'a'] = new TrieNode();
            }
            cur = cur.children[c - 'a'];
        }
        cur.isWord = true;
    }

    private void getWords(TrieNode root, String prefix) {
        if (k == 0) {
            return;
        }
        if (root.isWord) {
            k--;
            res.add(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (root.children[i] != null) {
                getWords(root.children[i], prefix + (char) (i + 'a'));
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        n = len(words)
        cnt = Counter(words)
        bucket = [{} for _ in range(n+1)]
        self.k = k

        def add_word(trie: Mapping, word: str) -> None:
            root = trie
            for c in word:
                if c not in root:
                    root[c] = {}
                root = root[c]
            root['#'] = {}

        def get_words(trie: Mapping, prefix: str) -> List[str]:
            if self.k == 0:
                return []
            res = []
            if '#' in trie:
                self.k -= 1
                res.append(prefix)
            for i in range(26):
                c = chr(ord('a') + i)
                if c in trie:
                    res += get_words(trie[c], prefix+c)
            return res

        for word, freq in cnt.items():
            add_word(bucket[freq], word)

        res = []
        for i in range(n, 0, -1):
            if self.k == 0:
                return res
            if bucket[i]:
                res += get_words(bucket[i], '')
        return res
```

</details>
