# 1166. Design File System

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/design-file-system/)  
`Hash Table` `String` `Design` `Trie`

**Problem Link:** [LeetCode 1166 - Design File System](https://leetcode.com/problems/design-file-system/)

## Problem

You are asked to design a file system that allows you to create new paths and associate them with different values.

The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string "" and "/" are not.

Implement the FileSystem class:

- bool createPath(string path, int value) Creates a new path and associates a value to it if possible and returns true. Returns false if the path already exists or its parent path doesn't exist.
- int get(string path) Returns the value associated with path or returns -1 if the path doesn't exist.

### Example 1

```text
Input:
["FileSystem","createPath","get"]
[[],["/a",1],["/a"]]
Output:
[null,true,1]
Explanation:
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/a", 1); // return true
fileSystem.get("/a"); // return 1
```

### Example 2

```text
Input:
["FileSystem","createPath","createPath","get","createPath","get"]
[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
Output:
[null,true,true,2,false,-1]
Explanation:
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/leet", 1); // return true
fileSystem.createPath("/leet/code", 2); // return true
fileSystem.get("/leet/code"); // return 2
fileSystem.createPath("/c/d", 1); // return false because the parent path "/c" doesn't exist.
fileSystem.get("/c"); // return -1 because this path doesn't exist.
```

## Constraints

- 2 <= path.length <= 100
- 1 <= value <= 109
- Each path is valid and consists of lowercase English letters and '/'.
- At most 104 calls in total will be made to createPath and get.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1166. Design File System

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dictionary for storing paths | Java, Python3 |
| Trie based approach | Java, Python3 |

## Approach 1: Dictionary for storing paths

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class FileSystem {

    HashMap<String, Integer> paths;

    public FileSystem() {
        this.paths = new HashMap<String, Integer>();
    }

    public boolean createPath(String path, int value) {

        // Step-1: basic path validations
        if (path.isEmpty() || (path.length() == 1 && path.equals("/")) || this.paths.containsKey(path)) {
            return false;
        }

        int delimIndex = path.lastIndexOf("/");
        String parent = path.substring(0, delimIndex);

        // Step-2: if the parent doesn't exist. Note that "/" is a valid parent.
        if (parent.length() > 1 && !this.paths.containsKey(parent)) {
            return false;
        }

        // Step-3: add this new path and return true.
        this.paths.put(path, value);
        return true;
    }

    public int get(String path) {
        return this.paths.getOrDefault(path, -1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class FileSystem:

    def __init__(self):
        self.paths = defaultdict()

    def createPath(self, path: str, value: int) -> bool:

        # Step-1: basic path validations
        if path == "/" or len(path) == 0 or path in self.paths:
            return False

        # Step-2: if the parent doesn't exist. Note that "/" is a valid parent.
        parent = path[:path.rfind('/')]
        if len(parent) > 1 and parent not in self.paths:
            return False

        # Step-3: add this new path and return true.
        self.paths[path] = value
        return True

    def get(self, path: str) -> int:
        return self.paths.get(path, -1)
```

</details>

<br>

## Approach 2: Trie based approach

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class FileSystem {

    // The TrieNode data structure.
    class TrieNode {

        String name;
        int val = -1;
        Map<String, TrieNode> map = new HashMap<>();

        TrieNode (String name) {
            this.name = name;
        }
    }

    TrieNode root;

    // Root node contains the empty string.
    public FileSystem() {
        this.root = new TrieNode("");
    }

    public boolean createPath(String path, int value) {

        // Obtain all the components
        String[] components = path.split("/");

        // Start "curr" from the root node.
        TrieNode cur = root;

        // Iterate over all the components.
        for (int i = 1; i < components.length; i++) {

            String currentComponent = components[i];

            // For each component, we check if it exists in the current node's dictionary.
            if (cur.map.containsKey(currentComponent) == false) {

                // If it doesn't and it is the last node, add it to the Trie.
                if (i == components.length - 1) {
                    cur.map.put(currentComponent, new TrieNode(currentComponent));
                } else {
                    return false;
                }
            }

            cur = cur.map.get(currentComponent);
        }

        // Value not equal to -1 means the path already exists in the trie.
        if (cur.val != -1) {
            return false;
        }

        cur.val = value;
        return true;
    }

    public int get(String path) {

        // Obtain all the components
        String[] components = path.split("/");

        // Start "curr" from the root node.
        TrieNode cur = root;

        // Iterate over all the components.
        for (int i = 1; i < components.length; i++) {

            String currentComponent = components[i];

            // For each component, we check if it exists in the current node's dictionary.
            if (cur.map.containsKey(currentComponent) == false) {
                return -1;
            }

            cur = cur.map.get(currentComponent);
        }

        return cur.val;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python

# The TrieNode data structure.
class TrieNode(object):
    def __init__(self, name):
        self.map = defaultdict(TrieNode)
        self.name = name
        self.value = -1

class FileSystem:

    def __init__(self):

        # Root node contains the empty string.
        self.root = TrieNode("")

    def createPath(self, path: str, value: int) -> bool:

        # Obtain all the components
        components = path.split("/")

        # Start "curr" from the root node.
        cur = self.root

        # Iterate over all the components.
        for i in range(1, len(components)):
            name = components[i]

            # For each component, we check if it exists in the current node's dictionary.
            if name not in cur.map:

                # If it doesn't and it is the last node, add it to the Trie.
                if i == len(components) - 1:
                    cur.map[name] = TrieNode(name)
                else:
                    return False
            cur = cur.map[name]

        # Value not equal to -1 means the path already exists in the trie.
        if cur.value!=-1:
            return False

        cur.value = value
        return True

    def get(self, path: str) -> int:

        # Obtain all the components
        cur = self.root

        # Start "curr" from the root node.
        components = path.split("/")

        # Iterate over all the components.
        for i in range(1, len(components)):

            # For each component, we check if it exists in the current node's dictionary.
            name = components[i]
            if name not in cur.map:
                return -1
            cur = cur.map[name]
        return cur.value
```

</details>
