# 1233. Remove Sub-Folders from the Filesystem

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/)  
`Array` `String` `Depth-First Search` `Trie`

**Problem Link:** [LeetCode 1233 - Remove Sub-Folders from the Filesystem](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/)

## Problem

Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".

The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

- For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.

### Example 1

```text
Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
```

### Example 2

```text
Input: folder = ["/a","/a/b/c","/a/b/d"]
Output: ["/a"]
Explanation: Folders "/a/b/c" and "/a/b/d" will be removed because they are subfolders of "/a".
```

### Example 3

```text
Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
Output: ["/a/b/c","/a/b/ca","/a/b/d"]
```

## Constraints

- 1 <= folder.length <= 4 * 104
- 2 <= folder[i].length <= 100
- folder[i] contains only lowercase letters and '/'.
- folder[i] always starts with the character '/'.
- Each folder name is unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1233. Remove Sub-Folders from the Filesystem

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Set | C++, Java, Python3 |
| Using Sorting | C++, Java, Python3 |
| Using Trie | C++, Java, Python3 |

## Approach 1: Using Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Create a set to store all folder paths for fast lookup
        unordered_set<string> folderSet(folder.begin(), folder.end());
        vector<string> result;

        // Iterate through each folder to check if it's a sub-folder
        for (string& f : folder) {
            bool isSubFolder = false;
            string prefix = f;

            // Check all prefixes of the current folder path
            while (!prefix.empty()) {
                size_t pos = prefix.find_last_of('/');
                if (pos == string::npos) break;

                // Reduce the prefix to its parent folder
                prefix = prefix.substr(0, pos);

                // If the parent folder exists in the set, mark as sub-folder
                if (folderSet.count(prefix)) {
                    isSubFolder = true;
                    break;
                }
            }

            // If not a sub-folder, add it to the result
            if (!isSubFolder) {
                result.push_back(f);
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> removeSubfolders(String[] folder) {
        // Create a set to store all folder paths for fast lookup
        Set<String> folderSet = new HashSet<>(Arrays.asList(folder));
        List<String> result = new ArrayList<>();

        // Iterate through each folder to check if it's a sub-folder
        for (String f : folder) {
            boolean isSubFolder = false;
            String prefix = f;

            // Check all prefixes of the current folder path
            while (!prefix.isEmpty()) {
                int pos = prefix.lastIndexOf('/');
                if (pos == -1) break;

                // Reduce the prefix to its parent folder
                prefix = prefix.substring(0, pos);

                // If the parent folder exists in the set, mark as sub-folder
                if (folderSet.contains(prefix)) {
                    isSubFolder = true;
                    break;
                }
            }

            // If not a sub-folder, add it to the result
            if (!isSubFolder) {
                result.add(f);
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeSubfolders(self, folder) -> list[str]:
        # Create a set to store all folder paths for fast lookup
        folder_set = set(folder)
        result = []

        # Iterate through each folder to check if it's a sub-folder
        for f in folder:
            is_sub_folder = False
            prefix = f

            # Check all prefixes of the current folder path
            while not prefix == "":
                pos = prefix.rfind("/")
                if pos == -1:
                    break

                # Reduce the prefix to its parent folder
                prefix = prefix[0:pos]

                # If the parent folder exists in the set, mark as sub-folder
                if prefix in folder_set:
                    is_sub_folder = True
                    break

            # If not a sub-folder, add it to the result
            if not is_sub_folder:
                result.append(f)
        return result
```

</details>

<br>

## Approach 2: Using Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folders alphabetically
        sort(folder.begin(), folder.end());

        // Initialize the result vector and add the first folder
        vector<string> result;
        result.push_back(folder[0]);

        // Iterate through each folder and check if it's a sub-folder of the
        // last added folder in the result
        for (int i = 1; i < folder.size(); i++) {
            string lastFolder = result.back();
            lastFolder += '/';

            // Check if the current folder starts with the last added folder
            // path
            if (folder[i].compare(0, lastFolder.size(), lastFolder) != 0) {
                result.push_back(folder[i]);
            }
        }

        // Return the result containing only non-sub-folders
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> removeSubfolders(String[] folder) {
        // Sort the folders alphabetically
        Arrays.sort(folder);

        // Initialize the result list and add the first folder
        List<String> result = new ArrayList<>();
        result.add(folder[0]);

        // Iterate through each folder and check if it's a sub-folder of the last added folder in the result
        for (int i = 1; i < folder.length; i++) {
            String lastFolder = result.get(result.size() - 1);
            lastFolder += '/';

            // Check if the current folder starts with the last added folder path
            if (!folder[i].startsWith(lastFolder)) {
                result.add(folder[i]);
            }
        }

        // Return the result containing only non-sub-folders
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeSubfolders(self, folder):
        # Sort the folders alphabetically
        folder.sort()

        # Initialize the result list and add the first folder
        result = [folder[0]]

        # Iterate through each folder and check if it's a sub-folder of the last added folder in the result
        for i in range(1, len(folder)):
            last_folder = result[-1]
            last_folder += "/"

            # Check if the current folder starts with the last added folder path
            if not folder[i].startswith(last_folder):
                result.append(folder[i])

        # Return the result containing only non-sub-folders
        return result
```

</details>

<br>

## Approach 3: Using Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    struct TrieNode {
        bool isEndOfFolder;
        unordered_map<string, TrieNode*> children;
        TrieNode() : isEndOfFolder(false) {}
    };

    TrieNode* root;

    // Recursively delete all TrieNodes to prevent memory leaks
    void deleteTrie(TrieNode* node) {
        if (node == nullptr) return;
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }

public:
    // Constructor initializes the root of the Trie
    Solution() : root(new TrieNode()) {}

    // Clean up memory
    // A destructor to recursively delete all TrieNodes and prevent memory
    // leaks.
    ~Solution() { deleteTrie(root); }

    vector<string> removeSubfolders(vector<string>& folder) {
        // Build Trie from folder paths
        for (string& path : folder) {
            TrieNode* currentNode = root;
            istringstream iss(path);
            string folderName;

            while (getline(iss, folderName, '/')) {
                // Skip empty folder names
                if (folderName.empty()) continue;
                // Create new node if it doesn't exist
                if (currentNode->children.find(folderName) ==
                    currentNode->children.end()) {
                    currentNode->children[folderName] = new TrieNode();
                }
                currentNode = currentNode->children[folderName];
            }
            // Mark the end of the folder path
            currentNode->isEndOfFolder = true;
        }

        // Check each path for subfolders
        vector<string> result;
        for (string& path : folder) {
            TrieNode* currentNode = root;
            istringstream iss(path);
            string folderName;
            bool isSubFolder = false;

            while (getline(iss, folderName, '/')) {
                // Skip empty folder names
                if (folderName.empty()) continue;
                TrieNode* nextNode = currentNode->children[folderName];
                // Check if the current folder path is a subfolder of an
                // existing folder
                if (nextNode->isEndOfFolder && iss.rdbuf()->in_avail() != 0) {
                    isSubFolder = true;
                    break;  // Found a sub-folder
                }
                currentNode = nextNode;
            }
            // If not a sub-folder, add to the result
            if (!isSubFolder) result.push_back(path);
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    static class TrieNode {

        boolean isEndOfFolder;
        HashMap<String, TrieNode> children;

        TrieNode() {
            this.isEndOfFolder = false;
            this.children = new HashMap<>();
        }
    }

    TrieNode root;

    Solution() {
        this.root = new TrieNode();
    }

    public List<String> removeSubfolders(String[] folder) {
        // Build Trie from folder paths
        for (String path : folder) {
            TrieNode currentNode = root;
            String[] folderNames = path.split("/");

            for (String folderName : folderNames) {
                // Skip empty folder names
                if (folderName.equals("")) continue;
                // Create new node if it doesn't exist
                if (!currentNode.children.containsKey(folderName)) {
                    currentNode.children.put(folderName, new TrieNode());
                }
                currentNode = currentNode.children.get(folderName);
            }
            // Mark the end of the folder path
            currentNode.isEndOfFolder = true;
        }

        // Check each path for subfolders
        List<String> result = new ArrayList<>();
        for (String path : folder) {
            TrieNode currentNode = root;
            String[] folderNames = path.split("/");
            boolean isSubfolder = false;

            for (int i = 0; i < folderNames.length; i++) {
                // Skip empty folder names
                if (folderNames[i].equals("")) continue;

                TrieNode nextNode = currentNode.children.get(folderNames[i]);
                // Check if the current folder path is a subfolder of an
                // existing folder
                if (nextNode.isEndOfFolder && i != folderNames.length - 1) {
                    isSubfolder = true;
                    break; // Found a sub-folder
                }

                currentNode = nextNode;
            }
            // If not a sub-folder, add to the result
            if (!isSubfolder) result.add(path);
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    class TrieNode:
        def __init__(self):
            self.is_end_of_folder = False
            self.children = {}

    def __init__(self):
        self.root = self.TrieNode()

    def removeSubfolders(self, folder):
        # Build Trie from folder paths
        for path in folder:
            current_node = self.root
            folders = path.split("/")

            for folder_name in folders:
                if folder_name == "":
                    continue

                # Create new node if it doesn't exist
                if folder_name not in current_node.children:
                    current_node.children[folder_name] = self.TrieNode()
                current_node = current_node.children[folder_name]

            # Mark the end of the folder path
            current_node.is_end_of_folder = True

        # Check each path for subfolders
        result = []
        for path in folder:
            current_node = self.root
            folders = path.split("/")
            is_subfolder = False

            for i, folder_name in enumerate(folders):
                if folder_name == "":
                    continue
                next_node = current_node.children[folder_name]
                # Check if the current folder path is a subfolder of an existing folder
                if next_node.is_end_of_folder and i != len(folders) - 1:
                    is_subfolder = True
                    break  # Found a subfolder
                current_node = next_node

            # If not a subfolder, add to the result
            if not is_subfolder:
                result.append(path)

        return result
```

</details>
