# 1948. Delete Duplicate Folders in System

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/delete-duplicate-folders-in-system/)  
`Array` `Hash Table` `String` `Depth-First Search` `Trie` `Sorting` `Hash Function`

**Problem Link:** [LeetCode 1948 - Delete Duplicate Folders in System](https://leetcode.com/problems/delete-duplicate-folders-in-system/)

## Problem

Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder in the file system.

- For example, ["one", "two", "three"] represents the path "/one/two/three".

Two folders (not necessarily on the same level) are identical if they contain the same non-empty set of identical subfolders and underlying subfolder structure. The folders do not need to be at the root level to be identical. If two or more folders are identical, then mark the folders as well as all their subfolders.

- For example, folders "/a" and "/b" in the file structure below are identical. They (as well as their subfolders) should all be marked:

		/a
		/a/x
		/a/x/y
		/a/z
		/b
		/b/x
		/b/x/y
		/b/z
- However, if the file structure also included the path "/b/w", then the folders "/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" would still be considered identical even with the added folder.

Once all the identical folders and their subfolders have been marked, the file system will delete all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.

Return the 2D array ans containing the paths of the remaining folders after deleting all the marked folders. The paths may be returned in any order.

### Example 1

```text
Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
Output: [["d"],["d","a"]]
Explanation: The file structure is as shown.
Folders "/a" and "/c" (and their subfolders) are marked for deletion because they both contain an empty
folder named "b".
```

### Example 2

```text
Input: paths = [["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
Output: [["c"],["c","b"],["a"],["a","b"]]
Explanation: The file structure is as shown.
Folders "/a/b/x" and "/w" (and their subfolders) are marked for deletion because they both contain an empty folder named "y".
Note that folders "/a" and "/c" are identical after the deletion, but they are not deleted because they were not marked beforehand.
```

### Example 3

```text
Input: paths = [["a","b"],["c","d"],["c"],["a"]]
Output: [["c"],["c","d"],["a"],["a","b"]]
Explanation: All folders are unique in the file system.
Note that the returned array can be in a different order as the order does not matter.
```

## Constraints

- 1 <= paths.length <= 2 * 104
- 1 <= paths[i].length <= 500
- 1 <= paths[i][j].length <= 10
- 1 <= sum(paths[i][j].length) <= 2 * 105
- path[i][j] consists of lowercase English letters.
- No two paths lead to the same folder.
- For any folder not at the root level, its parent folder will also be in the input.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Duplicate File in System](https://leetcode.com/problems/find-duplicate-file-in-system/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1948. Delete Duplicate Folders in System

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Serialization-Based Representation of Subtrees | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Serialization-Based Representation of Subtrees

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
struct Trie {
    // current node structure's serialized representation
    string serial;
    // current node's child nodes
    unordered_map<string, Trie*> children;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(
        vector<vector<string>>& paths) {
        // root node
        Trie* root = new Trie();

        for (const vector<string>& path : paths) {
            Trie* cur = root;
            for (const string& node : path) {
                if (!cur->children.count(node)) {
                    cur->children[node] = new Trie();
                }
                cur = cur->children[node];
            }
        }

        // hash table records the occurrence times of each serialized
        // representation
        unordered_map<string, int> freq;
        // post-order traversal based on depth-first search, calculate the
        // serialized representation of each node structure
        function<void(Trie*)> construct = [&](Trie* node) {
            // if it is a leaf node, then the serialization is represented as an
            // empty string, and no operation is required.
            if (node->children.empty()) {
                return;
            }

            vector<string> v;
            // if it is not a leaf node, the serialization representation of the
            // child node structure needs to be calculated first.
            for (const auto& [folder, child] : node->children) {
                construct(child);
                v.push_back(folder + "(" + child->serial + ")");
            }
            // to prevent issues with order, sorting is needed
            sort(v.begin(), v.end());
            for (string& s : v) {
                node->serial += move(s);
            }
            // add to hash table
            ++freq[node->serial];
        };

        construct(root);

        vector<vector<string>> ans;
        // record the path from the root node to the current node.
        vector<string> path;

        function<void(Trie*)> operate = [&](Trie* node) {
            // if the serialization appears more than once in the hash table, it
            // needs to be deleted.
            if (freq[node->serial] > 1) {
                return;
            }
            // otherwise add the path to the answer
            if (!path.empty()) {
                ans.push_back(path);
            }
            for (const auto& [folder, child] : node->children) {
                path.push_back(folder);
                operate(child);
                path.pop_back();
            }
        };

        operate(root);
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    class Trie {
        public string Serial { get; set; } =
            "";  // current node structure's serialized representation
        public Dictionary<string, Trie> Children { get; } =
            new Dictionary<string, Trie>();  // current node's child nodes
    }

    public IList<IList<string>> DeleteDuplicateFolder(
        IList<IList<string>> paths) {
        // root node
        Trie root = new Trie();
        // build a trie tree
        foreach (var p in paths) {
            Trie current = root;
            foreach (var node in p) {
                if (!current.Children.ContainsKey(node)) {
                    current.Children[node] = new Trie();
                }
                current = current.Children[node];
            }
        }

        // hash table records the occurrence times of each serialized
        // representation
        var freq = new Dictionary<string, int>();

        // post-order traversal based on depth-first search, calculate the
        // serialized representation of each node structure
        void Construct(Trie node) {
            // if it is a leaf node, then the serialization is represented as an
            // empty string, and no operation is required.
            if (node.Children.Count == 0) {
                return;
            }
            var v = new List<string>();
            // if it is not a leaf node, the serialization representation of the
            // child node structure needs to be calculated first.
            foreach (var entry in node.Children) {
                Construct(entry.Value);
                v.Add($"{entry.Key}({entry.Value.Serial})");
            }
            // to prevent issues with order, sorting is needed
            v.Sort();
            node.Serial = string.Join("", v);
            // add to hash table
            if (!freq.ContainsKey(node.Serial)) {
                freq[node.Serial] = 0;
            }
            freq[node.Serial]++;
        }

        Construct(root);
        var ans = new List<IList<string>>();
        // record the path from the root node to the current node.
        var path = new List<string>();

        void Operate(Trie node) {
            // if the serialization appears more than once in the hash table, it
            // needs to be deleted.
            if (freq.TryGetValue(node.Serial, out int count) && count > 1) {
                return;
            }
            // otherwise add the path to the answer
            if (path.Count > 0) {
                ans.Add(new List<string>(path));
            }

            foreach (var entry in node.Children) {
                path.Add(entry.Key);
                Operate(entry.Value);
                path.RemoveAt(path.Count - 1);
            }
        }

        Operate(root);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Trie struct {
	serial   string           // current node structure's serialized representation
	children map[string]*Trie // current node's child nodes
}

func deleteDuplicateFolder(paths [][]string) [][]string {
	root := &Trie{children: make(map[string]*Trie)} // root node
	// build a trie tree
	for _, path := range paths {
		cur := root
		for _, node := range path {
			if _, ok := cur.children[node]; !ok {
				cur.children[node] = &Trie{children: make(map[string]*Trie)}
			}
			cur = cur.children[node]
		}
	}

	freq := make(map[string]int) // hash table records the occurrence times of each serialized representation
	// post-order traversal based on depth-first search, calculate the serialized representation of each node structure
	var construct func(*Trie)
	construct = func(node *Trie) {
		if len(node.children) == 0 {
			return // if it is a leaf node, no operation is needed.
		}
		v := make([]string, 0, len(node.children))
		for folder, child := range node.children {
			construct(child)
			v = append(v, folder+"("+child.serial+")")
		}
		sort.Strings(v)
		node.serial = strings.Join(v, "")
		freq[node.serial]++
	}
	construct(root)
	ans := make([][]string, 0)
	path := make([]string, 0)
	// operate the trie, delete duplicate folders
	var operate func(*Trie)
	operate = func(node *Trie) {
		if freq[node.serial] > 1 {
			return // if the serialization representation appears more than once, it needs to be deleted
		}

		if len(path) > 0 {
			tmp := make([]string, len(path))
			copy(tmp, path)
			ans = append(ans, tmp)
		}

		for folder, child := range node.children {
			path = append(path, folder)
			operate(child)
			path = path[:len(path)-1]
		}
	}
	operate(root)

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    class Trie {

        String serial; // current node structure's serialized representation
        Map<String, Trie> children = new HashMap<>(); // current node's child nodes
    }

    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        Trie root = new Trie(); // root node

        // build a trie tree
        for (List<String> path : paths) {
            Trie cur = root;
            for (String node : path) {
                cur.children.putIfAbsent(node, new Trie());
                cur = cur.children.get(node);
            }
        }

        Map<String, Integer> freq = new HashMap<>(); // hash table records the occurrence times of each serialized representation
        // post-order traversal based on depth-first search, calculate the serialized representation of each node structure
        construct(root, freq);
        List<List<String>> ans = new ArrayList<>();
        List<String> path = new ArrayList<>();
        // operate the trie, delete duplicate folders
        operate(root, freq, path, ans);
        return ans;
    }

    private void construct(Trie node, Map<String, Integer> freq) {
        if (node.children.isEmpty()) return; // if it is a leaf node, no operation is needed.

        List<String> v = new ArrayList<>();
        for (Map.Entry<String, Trie> entry : node.children.entrySet()) {
            construct(entry.getValue(), freq);
            v.add(entry.getKey() + "(" + entry.getValue().serial + ")");
        }

        Collections.sort(v);
        StringBuilder sb = new StringBuilder();
        for (String s : v) {
            sb.append(s);
        }
        node.serial = sb.toString();
        freq.put(node.serial, freq.getOrDefault(node.serial, 0) + 1);
    }

    private void operate(
        Trie node,
        Map<String, Integer> freq,
        List<String> path,
        List<List<String>> ans
    ) {
        if (freq.getOrDefault(node.serial, 0) > 1) return; // if the serialization representation appears more than once, it needs to be deleted

        if (!path.isEmpty()) {
            ans.add(new ArrayList<>(path));
        }

        for (Map.Entry<String, Trie> entry : node.children.entrySet()) {
            path.add(entry.getKey());
            operate(entry.getValue(), freq, path, ans);
            path.remove(path.size() - 1);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var deleteDuplicateFolder = function (paths) {
    class Trie {
        constructor() {
            this.serial = ""; // current node structure's serialized representation
            this.children = new Map(); // current node's child nodes
        }
    }

    const root = new Trie(); // root node
    // build a trie tree
    for (const path of paths) {
        let cur = root;
        for (const node of path) {
            if (!cur.children.has(node)) {
                cur.children.set(node, new Trie());
            }
            cur = cur.children.get(node);
        }
    }

    const freq = new Map(); // hash table records the occurrence times of each serialized representation
    // post-order traversal based on depth-first search, calculate the serialized representation of each node structure
    function construct(node) {
        if (node.children.size === 0) return; // if it is a leaf node, no operation is needed.
        const v = [];
        for (const [folder, child] of node.children) {
            construct(child);
            v.push(`${folder}(${child.serial})`);
        }
        v.sort();
        node.serial = v.join("");
        freq.set(node.serial, (freq.get(node.serial) || 0) + 1);
    }
    construct(root);

    const ans = [];
    const path = [];
    // operate the trie, delete duplicate folders
    function operate(node) {
        if ((freq.get(node.serial) || 0) > 1) return; // if the serialization representation appears more than once, it needs to be deleted
        if (path.length > 0) {
            ans.push([...path]);
        }
        for (const [folder, child] of node.children) {
            path.push(folder);
            operate(child);
            path.pop();
        }
    }
    operate(root);

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Trie:
    # current node structure's serialized representation
    serial: str = ""
    # current node's child nodes
    children: dict

    def __init__(self):
        self.children = dict()


class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        # root node
        root = Trie()

        for path in paths:
            cur = root
            for node in path:
                if node not in cur.children:
                    cur.children[node] = Trie()
                cur = cur.children[node]

        # hash table records the occurrence times of each serialized representation
        freq = Counter()

        # post-order traversal based on depth-first search, calculate the serialized representation of each node structure
        def construct(node: Trie) -> None:
            # if it is a leaf node, then the serialization is represented as an empty string, and no operation is required.
            if not node.children:
                return

            v = list()
            # if it is not a leaf node, the serialization representation of the child node structure needs to be calculated first.
            for folder, child in node.children.items():
                construct(child)
                v.append(folder + "(" + child.serial + ")")

            # to prevent issues with order, sorting is needed
            v.sort()
            node.serial = "".join(v)
            # add to hash table
            freq[node.serial] += 1

        construct(root)

        ans = list()
        # record the path from the root node to the current node.
        path = list()

        def operate(node: Trie) -> None:
            # if the serialization appears more than once in the hash table, it needs to be deleted.
            if freq[node.serial] > 1:
                return
            # otherwise add the path to the answer
            if path:
                ans.append(path[:])

            for folder, child in node.children.items():
                path.append(folder)
                operate(child)
                path.pop()

        operate(root)
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function deleteDuplicateFolder(paths: string[][]): string[][] {
    class Trie {
        serial: string = ""; // current node structure's serialized representation
        children: Map<string, Trie> = new Map(); // current node's child nodes
    }

    const root = new Trie(); // root node

    // build a trie tree
    for (const path of paths) {
        let cur = root;
        for (const node of path) {
            if (!cur.children.has(node)) {
                cur.children.set(node, new Trie());
            }
            cur = cur.children.get(node)!;
        }
    }

    const freq = new Map<string, number>(); // hash table records the occurrence times of each serialized representation
    // post-order traversal based on depth-first search, calculate the serialized representation of each node structure
    function construct(node: Trie) {
        if (node.children.size === 0) return; // if it is a leaf node, no operation is needed.

        const v: string[] = [];
        for (const [folder, child] of node.children) {
            construct(child);
            v.push(`${folder}(${child.serial})`);
        }

        v.sort();
        node.serial = v.join("");
        freq.set(node.serial, (freq.get(node.serial) || 0) + 1);
    }
    construct(root);
    const ans: string[][] = [];
    const path: string[] = [];

    // operate the trie, delete duplicate folders
    function operate(node: Trie) {
        if ((freq.get(node.serial) || 0) > 1) return; // if the serialization representation appears more than once, it needs to be deleted

        if (path.length > 0) {
            ans.push([...path]);
        }

        for (const [folder, child] of node.children) {
            path.push(folder);
            operate(child);
            path.pop();
        }
    }
    operate(root);
    return ans;
}
```

</details>
