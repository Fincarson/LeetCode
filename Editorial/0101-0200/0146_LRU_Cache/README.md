# 146. LRU Cache

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/lru-cache/)  
`Hash Table` `Linked List` `Design` `Doubly-Linked List`

**Problem Link:** [LeetCode 146 - LRU Cache](https://leetcode.com/problems/lru-cache/)

## Problem

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

- LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
- int get(int key) Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

### Example 1

```text
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```

## Constraints

- 1 <= capacity <= 3000
- 0 <= key <= 104
- 0 <= value <= 105
- At most 2 * 105 calls will be made to get and put.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [LFU Cache](https://leetcode.com/problems/lfu-cache/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Design In-Memory File System](https://leetcode.com/problems/design-in-memory-file-system/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Design Compressed String Iterator](https://leetcode.com/problems/design-compressed-string-iterator/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Design Most Recently Used Queue](https://leetcode.com/problems/design-most-recently-used-queue/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 146. LRU Cache

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Doubly Linked List | C++, Java, Python3 |
| Built-in | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Doubly Linked List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class ListNode {
    int key;
    int val;
    ListNode next;
    ListNode prev;

    public ListNode(int key, int val) {
        this.key = key;
        this.val = val;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class ListNode:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None
```

</details>

<br>

## Approach 2: Built-in

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct Node {
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    struct Node_int* hashTable;
} LRUCache;

typedef struct Node_int {
    int id;
    Node* val;
    UT_hash_handle hh;
} Node_int;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->head = NULL;
    obj->tail = NULL;
    obj->hashTable = NULL;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node_int* tmp;
    HASH_FIND_INT(obj->hashTable, &key, tmp);

    if (tmp == NULL) {
        return -1;
    }

    Node* node = tmp->val;

    if (node != obj->head) {
        if (node == obj->tail) {
            obj->tail = node->prev;
        }

        node->prev->next = node->next;
        if (node->next) {
            node->next->prev = node->prev;
        }

        node->next = obj->head;
        node->prev = NULL;
        obj->head->prev = node;
        obj->head = node;
    }

    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node_int* tmp;
    HASH_FIND_INT(obj->hashTable, &key, tmp);

    if (tmp != NULL) {
        Node* node = tmp->val;
        node->value = value;

        if (node != obj->head) {
            if (node == obj->tail) {
                obj->tail = node->prev;
            }

            node->prev->next = node->next;
            if (node->next) {
                node->next->prev = node->prev;
            }

            node->next = obj->head;
            node->prev = NULL;
            obj->head->prev = node;
            obj->head = node;
        }
    } else {
        Node* node = (Node*)malloc(sizeof(Node));
        node->key = key;
        node->value = value;
        node->prev = NULL;
        node->next = obj->head;
        if (obj->head) {
            obj->head->prev = node;
        }
        obj->head = node;

        Node_int* s = (Node_int*)malloc(sizeof(Node_int));
        s->id = key;
        s->val = node;
        HASH_ADD_INT(obj->hashTable, id, s);

        if (obj->size == obj->capacity) {
            if (obj->tail) {
                Node_int* tmp;
                HASH_FIND_INT(obj->hashTable, &(obj->tail->key), tmp);
                HASH_DEL(obj->hashTable, tmp);
                if (tmp) free(tmp);

                Node* tail = obj->tail;
                obj->tail = tail->prev;
                if (obj->tail) {
                    obj->tail->next = NULL;
                }

                if (tail) free(tail);
            }
        } else if (obj->size < obj->capacity) {
            if (obj->size == 0) {
                obj->tail = node;
            }
            obj->size++;
        }
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* tmp = obj->head;
    while (tmp) {
        Node* next = tmp->next;
        free(tmp);
        tmp = next;
    }

    Node_int *current_entry, *tmp_entry;
    HASH_ITER(hh, obj->hashTable, current_entry, tmp_entry) {
        HASH_DEL(obj->hashTable, current_entry);
        free(current_entry);
    }

    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class LRUCache {
public:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> dic;
    list<pair<int, int>> lru;

    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        auto it = dic.find(key);

        if (it == dic.end()) {
            return -1;
        }

        int value = it->second->second;
        lru.erase(it->second);
        lru.push_front({key, value});

        dic.erase(it);
        dic[key] = lru.begin();
        return value;
    }

    void put(int key, int value) {
        auto it = dic.find(key);

        if (dic.find(key) != dic.end()) {
            lru.erase(it->second);
            dic.erase(it);
        }

        lru.push_front({key, value});
        dic[key] = lru.begin();

        if (dic.size() > capacity) {
            auto it = dic.find(lru.rbegin()->first);
            dic.erase(it);
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C#

public class LRUCache {
    private int capacity;
    private Dictionary<int, LinkedListNode<TwoInt>> dic;

    private LinkedList<TwoInt> lru;

    // Helper class
    private class TwoInt {
        public int Key { get; set; }
        public int Value { get; set; }

        public TwoInt(int key, int val) {
            Key = key;
            Value = val;
        }
    }

    public LRUCache(int capacity) {
        this.capacity = capacity;
        dic = new Dictionary<int, LinkedListNode<TwoInt>>();
        lru = new LinkedList<TwoInt>();
    }

    public int Get(int key) {
        LinkedListNode<TwoInt> node;
        if (dic.TryGetValue(key, out node)) {
            // Move to front
            var value = node.Value.Value;
            lru.Remove(node);
            dic[key] = new LinkedListNode<TwoInt>(new TwoInt(key, value));
            lru.AddFirst(dic[key]);
            return value;
        } else {
            return -1;
        }
    }

    public void Put(int key, int value) {
        if (dic.ContainsKey(key)) {
            // Exist
            lru.Remove(dic[key]);
            dic.Remove(key);
        }

        dic[key] = new LinkedListNode<TwoInt>(new TwoInt(key, value));
        lru.AddFirst(dic[key]);
        // Check capacity
        if (dic.Count > capacity) {
            int lastKey = lru.Last.Value.Key;
            lru.RemoveLast();
            dic.Remove(lastKey);
        }
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang
type DNode struct {
    Key  int
    Val  int
    Prev *DNode
    Next *DNode
}
type LRUCache struct {
    Map      map[int]*DNode
    Capacity int
    Head     *DNode
    Tail     *DNode
}

func (this *LRUCache) removeNode(node *DNode) {
    node.Prev.Next = node.Next
    node.Next.Prev = node.Prev
}

func (this *LRUCache) addToHead(node *DNode) {
    node.Prev = this.Head
    node.Next = this.Head.Next
    this.Head.Next.Prev = node
    this.Head.Next = node
}

func Constructor(capacity int) LRUCache {
    h := &DNode{}
    t := &DNode{}
    h.Next = t
    t.Prev = h
    return LRUCache{
        Map:      make(map[int]*DNode),
        Capacity: capacity,
        Head:     h,
        Tail:     t,
    }
}

func (this *LRUCache) Get(key int) int {
    node, exist := this.Map[key]
    if !exist {
        return -1
    }
    this.removeNode(node)
    this.addToHead(node)
    return node.Val
}

func (this *LRUCache) Put(key int, value int) {
    node, exist := this.Map[key]
    if exist {
        node.Val = value
        this.removeNode(node)
        this.addToHead(node)
    } else {
        newNode := &DNode{
            Key: key,
            Val: value,
        }
        if len(this.Map) == this.Capacity {
            delete(this.Map, this.Tail.Prev.Key)
            this.removeNode(this.Tail.Prev)
        }
        this.addToHead(newNode)
        this.Map[key] = newNode
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class LRUCache {
    int capacity;
    LinkedHashMap<Integer, Integer> dic;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        dic = new LinkedHashMap<>(5, 0.75f, true) {
            @Override
            protected boolean removeEldestEntry(
                Map.Entry<Integer, Integer> eldest
            ) {
                return size() > capacity;
            }
        };
    }

    public int get(int key) {
        return dic.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        dic.put(key, value);
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript
class LRUCache {
    constructor(capacity) {
        this.capacity = capacity;
        this.dic = new Map();
    }
    get(key) {
        // Not present
        if (!this.dic.has(key)) {
            return -1;
        }
        var value = this.dic.get(key);
        this.dic.delete(key);
        this.dic.set(key, value);
        return value;
    }
    put(key, value) {
        if (this.dic.has(key)) {
            this.dic.delete(key);
        }
        this.dic.set(key, value);
        // Capacity overflow
        if (this.dic.size > this.capacity) {
            this.dic.delete(this.dic.keys().next().value);
        }
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity);
 * var param_1 = obj.get(key);
 * obj.put(key,value);
 */
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import collections


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.dic = collections.OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.dic:
            return -1

        self.dic.move_to_end(key)
        return self.dic[key]

    def put(self, key: int, value: int) -> None:
        if key in self.dic:
            self.dic.move_to_end(key)

        self.dic[key] = value
        if len(self.dic) > self.capacity:
            self.dic.popitem(False)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript
class LRUCache {
    capacity: number;
    dic: Map<number, number>;
    constructor(capacity: number) {
        this.capacity = capacity;
        this.dic = new Map();
    }
    get(key: number): number {
        // Not present
        if (!this.dic.has(key)) {
            return -1;
        }
        let value = this.dic.get(key);
        this.dic.delete(key);
        this.dic.set(key, value);
        return value;
    }
    put(key: number, value: number): void {
        if (this.dic.has(key)) {
            this.dic.delete(key);
        }
        this.dic.set(key, value);
        // Capacity overflow
        if (this.dic.size > this.capacity) {
            this.dic.delete(this.dic.keys().next().value);
        }
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = new LRUCache(capacity);
 * let param_1: number = obj.get(key);
 * obj.put(key,value);
 */
```

</details>
