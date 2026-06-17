# 677. Map Sum Pairs

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/map-sum-pairs/)  
`Hash Table` `String` `Design` `Trie`

**Problem Link:** [LeetCode 677 - Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/)

## Problem

Design a map that allows you to do the following:

- Maps a string key to a given value.
- Returns the sum of the values that have a key with a prefix equal to a given string.

Implement the MapSum class:

- MapSum() Initializes the MapSum object.
- void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
- int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.

### Example 1

```text
Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
```

## Constraints

- 1 <= key.length, prefix.length <= 50
- key and prefix consist of only lowercase English letters.
- 1 <= val <= 1000
- At most 50 calls will be made to insert and sum.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort the Jumbled Numbers](https://leetcode.com/problems/sort-the-jumbled-numbers/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sum of Prefix Scores of Strings](https://leetcode.com/problems/sum-of-prefix-scores-of-strings/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 677. Map Sum Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force [Accepted] | Java, Python |
| Approach #2: Prefix Hashmap [Accepted] | Java, Python |
| Approach #3: Trie [Accepted] | Java, Python |

## Approach #1: Brute Force [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class MapSum {
    HashMap<String, Integer> map;
    public MapSum() {
        map = new HashMap<>();
    }
    public void insert(String key, int val) {
        map.put(key, val);
    }
    public int sum(String prefix) {
        int ans = 0;
        for (String key: map.keySet()) {
            if (key.startsWith(prefix)) {
                ans += map.get(key);
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class MapSum(object):
    def __init__(self):
        self.map = {}

    def insert(self, key, val):
        self.map[key] = val

    def sum(self, prefix):
        return sum(val for key, val in self.map.items()
                   if key.startswith(prefix))
```

</details>

<br>

## Approach #2: Prefix Hashmap [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class MapSum {
    Map<String, Integer> map;
    Map<String, Integer> score;
    public MapSum() {
        map = new HashMap();
        score = new HashMap();
    }
    public void insert(String key, int val) {
        int delta = val - map.getOrDefault(key, 0);
        map.put(key, val);
        String prefix = "";
        for (char c: key.toCharArray()) {
            prefix += c;
            score.put(prefix, score.getOrDefault(prefix, 0) + delta);
        }
    }
    public int sum(String prefix) {
        return score.getOrDefault(prefix, 0);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class MapSum(object):
    def __init__(self):
        self.map = {}
        self.score = collections.Counter()

    def insert(self, key, val):
        delta = val - self.map.get(key, 0)
        self.map[key] = val
        for i in xrange(len(key) + 1):
            prefix = key[:i]
            self.score[prefix] += delta

    def sum(self, prefix):
        return self.score[prefix]
```

</details>

<br>

## Approach #3: Trie [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class MapSum {
    HashMap<String, Integer> map;
    TrieNode root;
    public MapSum() {
        map = new HashMap();
        root = new TrieNode();
    }
    public void insert(String key, int val) {
        int delta = val - map.getOrDefault(key, 0);
        map.put(key, val);
        TrieNode cur = root;
        cur.score += delta;
        for (char c: key.toCharArray()) {
            cur.children.putIfAbsent(c, new TrieNode());
            cur = cur.children.get(c);
            cur.score += delta;
        }
    }
    public int sum(String prefix) {
        TrieNode cur = root;
        for (char c: prefix.toCharArray()) {
            cur = cur.children.get(c);
            if (cur == null) return 0;
        }
        return cur.score;
    }
}
class TrieNode {
    Map<Character, TrieNode> children = new HashMap();
    int score;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class TrieNode(object):
    __slots__ = 'children', 'score'
    def __init__(self):
        self.children = {}
        self.score = 0

class MapSum(object):
    def __init__(self):
        self.map = {}
        self.root = TrieNode()

    def insert(self, key, val):
        delta = val - self.map.get(key, 0)
        self.map[key] = val
        cur = self.root
        cur.score += delta
        for char in key:
            cur = cur.children.setdefault(char, TrieNode())
            cur.score += delta

    def sum(self, prefix):
        cur = self.root
        for char in prefix:
            if char not in cur.children:
                return 0
            cur = cur.children[char]
        return cur.score
```

</details>
