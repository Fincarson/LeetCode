# 460. LFU Cache

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/lfu-cache/)  
`Hash Table` `Linked List` `Design` `Doubly-Linked List`

**Problem Link:** [LeetCode 460 - LFU Cache](https://leetcode.com/problems/lfu-cache/)

## Problem

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

- LFUCache(int capacity) Initializes the object with the capacity of the data structure.
- int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
- void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

### Example 1

```text
Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
```

## Constraints

- 1 <= capacity <= 104
- 0 <= key <= 105
- 0 <= value <= 109
- At most 2 * 105 calls will be made to get and put.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [LRU Cache](https://leetcode.com/problems/lru-cache/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Design In-Memory File System](https://leetcode.com/problems/design-in-memory-file-system/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 460. LFU Cache

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Maintaining 2 HashMaps | C++, Java, Python3 |

## Approach 1: Maintaining 2 HashMaps

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class LFUCache {
    // key: frequency, value: list of original key-value pairs that have the
    // same frequency.
    unordered_map<int, list<pair<int, int>>> frequencies;
    // key: original key, value: pair of frequency and the iterator
    // corresponding key in the frequencies map's list.
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int capacity;
    int minf;

    void insert(int key, int frequency, int value) {
        frequencies[frequency].push_back({key, value});
        cache[key] = {frequency, --frequencies[frequency].end()};
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {}

    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        const int f = it->second.first;
        const auto iter = it->second.second;
        const pair<int, int> kv = *iter;
        frequencies[f].erase(iter);
        if (frequencies[f].empty()) {
            frequencies.erase(f);

            if (minf == f) {
                ++minf;
            }
        }

        insert(key, f + 1, kv.second);
        return kv.second;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        const auto it = cache.find(key);
        if (it != cache.end()) {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (capacity == cache.size()) {
            cache.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();

            if (frequencies[minf].empty()) {
                frequencies.erase(minf);
            }
        }

        minf = 1;
        insert(key, 1, value);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class LFUCache {

    // key: original key, value: frequency and original value.
    private Map<Integer, Pair<Integer, Integer>> cache;
    // key: frequency, value: All keys that have the same frequency.
    private Map<Integer, LinkedHashSet<Integer>> frequencies;
    private int minf;
    private int capacity;

    private void insert(int key, int frequency, int value) {
        cache.put(key, new Pair<>(frequency, value));
        frequencies.putIfAbsent(frequency, new LinkedHashSet<>());
        frequencies.get(frequency).add(key);
    }

    public LFUCache(int capacity) {
        cache = new HashMap<>();
        frequencies = new HashMap<>();
        minf = 0;
        this.capacity = capacity;
    }

    public int get(int key) {
        Pair<Integer, Integer> frequencyAndValue = cache.get(key);
        if (frequencyAndValue == null) {
            return -1;
        }
        final int frequency = frequencyAndValue.getKey();
        final Set<Integer> keys = frequencies.get(frequency);
        keys.remove(key);
        if (keys.isEmpty()) {
            frequencies.remove(frequency);

            if (minf == frequency) {
                ++minf;
            }
        }
        final int value = frequencyAndValue.getValue();
        insert(key, frequency + 1, value);
        return value;
    }

    public void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        Pair<Integer, Integer> frequencyAndValue = cache.get(key);
        if (frequencyAndValue != null) {
            cache.put(key, new Pair<>(frequencyAndValue.getKey(), value));
            get(key);
            return;
        }
        if (capacity == cache.size()) {
            final Set<Integer> keys = frequencies.get(minf);
            final int keyToDelete = keys.iterator().next();
            cache.remove(keyToDelete);
            keys.remove(keyToDelete);
            if (keys.isEmpty()) {
                frequencies.remove(minf);
            }
        }
        minf = 1;
        insert(key, 1, value);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class LFUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.key2val = {}
        self.key2freq = {}
        self.freq2key = collections.defaultdict(collections.OrderedDict)
        self.minf = 0

    def get(self, key: int) -> int:
        if key not in self.key2val:
            return -1
        oldfreq = self.key2freq[key]
        self.key2freq[key] = oldfreq + 1
        self.freq2key[oldfreq].pop(key)
        if not self.freq2key[oldfreq]:
            del self.freq2key[oldfreq]
        self.freq2key[oldfreq + 1][key] = 1
        if self.minf not in self.freq2key:
            self.minf += 1
        return self.key2val[key]

    def put(self, key: int, value: int) -> None:
        if self.cap <= 0:
            return
        if key in self.key2val:
            self.get(key)
            self.key2val[key] = value
            return

        if len(self.key2val) == self.cap:
            delkey, _ = self.freq2key[self.minf].popitem(last=False)
            del self.key2val[delkey]
            del self.key2freq[delkey]
        self.key2val[key] = value
        self.key2freq[key] = 1
        self.freq2key[1][key] = 1
        self.minf = 1
```

</details>
