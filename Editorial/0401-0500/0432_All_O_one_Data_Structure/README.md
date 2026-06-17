# 432. All O`one Data Structure

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/all-oone-data-structure/)  
`Hash Table` `Linked List` `Design` `Doubly-Linked List`

**Problem Link:** [LeetCode 432 - All O`one Data Structure](https://leetcode.com/problems/all-oone-data-structure/)

## Problem

Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

- AllOne() Initializes the object of the data structure.
- inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
- dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
- getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
- getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".

Note that each function must run in O(1) average time complexity.

### Example 1

```text
Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"
```

## Constraints

- 1 <= key.length <= 10
- key consists of lowercase English letters.
- It is guaranteed that for each call to dec, key is existing in the data structure.
- At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 432. All O`one Data Structure

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Using Doubly Linked List | C++, Java, Python3 |

## Approach: Using Doubly Linked List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Node {
public:
    int freq;
    Node* prev;
    Node* next;
    unordered_set<string> keys;

    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    Node* head;                        // Dummy head
    Node* tail;                        // Dummy tail
    unordered_map<string, Node*> map;  // Mapping from key to its node

public:
    // Initialize your data structure here.
    AllOne() {
        head = new Node(0);  // Create dummy head
        tail = new Node(0);  // Create dummy tail
        head->next = tail;   // Link dummy head to dummy tail
        tail->prev = head;   // Link dummy tail to dummy head
    }

    // Inserts a new key <Key> with value 1. Or increments an existing key by 1.
    void inc(string key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            int freq = node->freq;
            node->keys.erase(key);  // Remove key from current node

            Node* nextNode = node->next;
            if (nextNode == tail || nextNode->freq != freq + 1) {
                // Create a new node if next node does not exist or freq is not
                // freq + 1
                Node* newNode = new Node(freq + 1);
                newNode->keys.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
                node->next = newNode;
                nextNode->prev = newNode;
                map[key] = newNode;
            } else {
                // Increment the existing next node
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }

            // Remove the current node if it has no keys left
            if (node->keys.empty()) {
                removeNode(node);
            }
        } else {  // Key does not exist
            Node* firstNode = head->next;
            if (firstNode == tail || firstNode->freq > 1) {
                // Create a new node
                Node* newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->prev = head;
                newNode->next = firstNode;
                head->next = newNode;
                firstNode->prev = newNode;
                map[key] = newNode;
            } else {
                firstNode->keys.insert(key);
                map[key] = firstNode;
            }
        }
    }

    // Decrements an existing key by 1. If Key's value is 1, remove it from the
    // data structure.
    void dec(string key) {
        if (map.find(key) == map.end()) {
            return;  // Key does not exist
        }

        Node* node = map[key];
        node->keys.erase(key);
        int freq = node->freq;

        if (freq == 1) {
            // Remove the key from the map if freq is 1
            map.erase(key);
        } else {
            Node* prevNode = node->prev;
            if (prevNode == head || prevNode->freq != freq - 1) {
                // Create a new node if the previous node does not exist or freq
                // is not freq - 1
                Node* newNode = new Node(freq - 1);
                newNode->keys.insert(key);
                newNode->prev = prevNode;
                newNode->next = node;
                prevNode->next = newNode;
                node->prev = newNode;
                map[key] = newNode;
            } else {
                // Decrement the existing previous node
                prevNode->keys.insert(key);
                map[key] = prevNode;
            }
        }

        // Remove the node if it has no keys left
        if (node->keys.empty()) {
            removeNode(node);
        }
    }

    // Returns one of the keys with maximal value.
    string getMaxKey() {
        if (tail->prev == head) {
            return "";  // No keys exist
        }
        return *(tail->prev->keys.begin());  // Return one of the keys from the
                                             // tail's previous node
    }

    // Returns one of the keys with minimal value.
    string getMinKey() {
        if (head->next == tail) {
            return "";  // No keys exist
        }
        return *(
            head->next->keys
                .begin());  // Return one of the keys from the head's next node
    }

private:
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;  // Link previous node to next node
        nextNode->prev = prevNode;  // Link next node to previous node

        delete node;  // Free the memory of the removed node
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Node {

    int freq;
    Node prev;
    Node next;
    Set<String> keys = new HashSet<>();

    Node(int freq) {
        this.freq = freq;
    }
}

class AllOne {

    Node head;
    Node tail;
    Map<String, Node> map = new HashMap<>();

    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
    }

    public void inc(String key) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            int freq = node.freq;
            node.keys.remove(key);

            Node nextNode = node.next;
            if (nextNode == tail || nextNode.freq != freq + 1) {
                Node newNode = new Node(freq + 1);
                newNode.keys.add(key);
                newNode.prev = node;
                newNode.next = nextNode;
                node.next = newNode;
                nextNode.prev = newNode;
                map.put(key, newNode);
            } else {
                nextNode.keys.add(key);
                map.put(key, nextNode);
            }

            if (node.keys.isEmpty()) {
                removeNode(node);
            }
        } else {
            Node firstNode = head.next;
            if (firstNode == tail || firstNode.freq > 1) {
                Node newNode = new Node(1);
                newNode.keys.add(key);
                newNode.prev = head;
                newNode.next = firstNode;
                head.next = newNode;
                firstNode.prev = newNode;
                map.put(key, newNode);
            } else {
                firstNode.keys.add(key);
                map.put(key, firstNode);
            }
        }
    }

    public void dec(String key) {
        if (!map.containsKey(key)) {
            return;
        }

        Node node = map.get(key);
        node.keys.remove(key);
        int freq = node.freq;

        if (freq == 1) {
            map.remove(key);
        } else {
            Node prevNode = node.prev;
            if (prevNode == head || prevNode.freq != freq - 1) {
                Node newNode = new Node(freq - 1);
                newNode.keys.add(key);
                newNode.prev = prevNode;
                newNode.next = node;
                prevNode.next = newNode;
                node.prev = newNode;
                map.put(key, newNode);
            } else {
                prevNode.keys.add(key);
                map.put(key, prevNode);
            }
        }

        if (node.keys.isEmpty()) {
            removeNode(node);
        }
    }

    public String getMaxKey() {
        if (tail.prev == head) {
            return "";
        }
        return tail.prev.keys.iterator().next();
    }

    public String getMinKey() {
        if (head.next == tail) {
            return "";
        }
        return head.next.keys.iterator().next();
    }

    private void removeNode(Node node) {
        Node prevNode = node.prev;
        Node nextNode = node.next;

        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Node:
    def __init__(self, freq):
        self.freq = freq
        self.prev = None
        self.next = None
        self.keys = set()


class AllOne:
    def __init__(self):
        self.head = Node(0)  # Dummy head
        self.tail = Node(0)  # Dummy tail
        self.head.next = self.tail  # Link dummy head to dummy tail
        self.tail.prev = self.head  # Link dummy tail to dummy head
        self.map = {}  # Mapping from key to its node

    def inc(self, key: str) -> None:
        if key in self.map:
            node = self.map[key]
            freq = node.freq
            node.keys.remove(key)  # Remove key from current node

            nextNode = node.next
            if nextNode == self.tail or nextNode.freq != freq + 1:
                # Create a new node if next node does not exist or freq is not freq + 1
                newNode = Node(freq + 1)
                newNode.keys.add(key)
                newNode.prev = node
                newNode.next = nextNode
                node.next = newNode
                nextNode.prev = newNode
                self.map[key] = newNode
            else:
                # Increment the existing next node
                nextNode.keys.add(key)
                self.map[key] = nextNode

            # Remove the current node if it has no keys left
            if not node.keys:
                self.removeNode(node)
        else:  # Key does not exist
            firstNode = self.head.next
            if firstNode == self.tail or firstNode.freq > 1:
                # Create a new node
                newNode = Node(1)
                newNode.keys.add(key)
                newNode.prev = self.head
                newNode.next = firstNode
                self.head.next = newNode
                firstNode.prev = newNode
                self.map[key] = newNode
            else:
                firstNode.keys.add(key)
                self.map[key] = firstNode

    def dec(self, key: str) -> None:
        if key not in self.map:
            return  # Key does not exist

        node = self.map[key]
        node.keys.remove(key)
        freq = node.freq

        if freq == 1:
            # Remove the key from the map if freq is 1
            del self.map[key]
        else:
            prevNode = node.prev
            if prevNode == self.head or prevNode.freq != freq - 1:
                # Create a new node if the previous node does not exist or freq is not freq - 1
                newNode = Node(freq - 1)
                newNode.keys.add(key)
                newNode.prev = prevNode
                newNode.next = node
                prevNode.next = newNode
                node.prev = newNode
                self.map[key] = newNode
            else:
                # Decrement the existing previous node
                prevNode.keys.add(key)
                self.map[key] = prevNode

        # Remove the node if it has no keys left
        if not node.keys:
            self.removeNode(node)

    def getMaxKey(self) -> str:
        if self.tail.prev == self.head:
            return ""  # No keys exist
        return next(
            iter(self.tail.prev.keys)
        )  # Return one of the keys from the tail's previous node

    def getMinKey(self) -> str:
        if self.head.next == self.tail:
            return ""  # No keys exist
        return next(
            iter(self.head.next.keys)
        )  # Return one of the keys from the head's next node

    def removeNode(self, node):
        prevNode = node.prev
        nextNode = node.next

        prevNode.next = nextNode  # Link previous node to next node
        nextNode.prev = prevNode  # Link next node to previous node
```

</details>
