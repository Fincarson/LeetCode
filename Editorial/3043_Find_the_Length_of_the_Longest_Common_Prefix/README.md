# 3043. Find the Length of the Longest Common Prefix

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/)  
`Array` `Hash Table` `String` `Trie`

**Problem Link:** [LeetCode 3043 - Find the Length of the Longest Common Prefix](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/)

## Problem

You are given two arrays with positive integers arr1 and arr2.

A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.

A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have common prefixes 565 and 5655 while 1223 and 43456 do not have a common prefix.

You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.

### Example 1

```text
Input: arr1 = [1,10,100], arr2 = [1000]
Output: 3
Explanation: There are 3 pairs (arr1[i], arr2[j]):
- The longest common prefix of (1, 1000) is 1.
- The longest common prefix of (10, 1000) is 10.
- The longest common prefix of (100, 1000) is 100.
The longest common prefix is 100 with a length of 3.
```

### Example 2

```text
Input: arr1 = [1,2,3], arr2 = [4,4,4]
Output: 0
Explanation: There exists no common prefix for any pair (arr1[i], arr2[j]), hence we return 0.
Note that common prefixes between elements of the same array do not count.
```

## Constraints

- 1 <= arr1.length, arr2.length <= 5 * 104
- 1 <= arr1[i], arr2[i] <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Longest Common Suffix Queries](https://leetcode.com/problems/longest-common-suffix-queries/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3043. Find the Length of the Longest Common Prefix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Hash Table | C++, Java, Python3 |
| Trie | C++, Java, Python3 |

## Approach 1: Using Hash Table

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> arr1Prefixes;  // Set to store all prefixes from arr1

        // Step 1: Build all possible prefixes from arr1
        for (int val : arr1) {
            while (!arr1Prefixes.count(val) && val > 0) {
                // Insert current value as a prefix
                arr1Prefixes.insert(val);
                // Generate the next shorter prefix by removing the last digit
                val /= 10;
            }
        }

        int longestPrefix = 0;

        // Step 2: Check each number in arr2 for the longest matching prefix
        for (int val : arr2) {
            while (!arr1Prefixes.count(val) && val > 0) {
                // Reduce val by removing the last digit if not found in the
                // prefix set
                val /= 10;
            }
            if (val > 0) {
                // Length of the matched prefix using log10 to determine the
                // number of digits
                longestPrefix =
                    max(longestPrefix, static_cast<int>(log10(val) + 1));
            }
        }

        return longestPrefix;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.HashSet;

class Solution {

    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        HashSet<Integer> arr1Prefixes = new HashSet<Integer>(); // Set to store all prefixes from arr1

        // Step 1: Build all possible prefixes from arr1
        for (int val : arr1) {
            while (!arr1Prefixes.contains(val) && val > 0) {
                // Insert current value as a prefix
                arr1Prefixes.add(val);
                // Generate the next shorter prefix by removing the last digit
                val /= 10;
            }
        }

        int longestPrefix = 0;

        // Step 2: Check each number in arr2 for the longest matching prefix
        for (int val : arr2) {
            while (!arr1Prefixes.contains(val) && val > 0) {
                // Reduce val by removing the last digit if not found in the prefix set
                val /= 10;
            }
            if (val > 0) {
                // Length of the matched prefix using log10 to determine the number of digits
                longestPrefix = Math.max(
                    longestPrefix,
                    (int) Math.log10(val) + 1
                );
            }
        }

        return longestPrefix;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestCommonPrefix(self, arr1, arr2):
        arr1_prefixes = set()  # Set to store all prefixes from arr1

        # Step 1: Build all possible prefixes from arr1
        for val in arr1:
            while val not in arr1_prefixes and val > 0:
                # Insert current value as a prefix
                arr1_prefixes.add(val)
                # Generate the next shorter prefix by removing the last digit
                val //= 10

        longest_prefix = 0

        # Step 2: Check each number in arr2 for the longest matching prefix
        for val in arr2:
            while val not in arr1_prefixes and val > 0:
                # Reduce val by removing the last digit if not found in the prefix set
                val //= 10
            if val > 0:
                # Length of the matched prefix using log10 to determine the number of digits
                longest_prefix = max(longest_prefix, len(str(val)))

        return longest_prefix
```

</details>

<br>

## Approach 2: Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TrieNode {
public:
    // Each node has up to 10 possible children (digits 0-9)
    TrieNode* children[10];
    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    // Insert a number into the Trie by treating it as a string of digits
    void insert(int num) {
        TrieNode* node = root;
        string numStr = to_string(num);
        for (char digit : numStr) {
            int idx = digit - '0';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    // Find the longest common prefix for a number in arr2 with the Trie
    int findLongestPrefix(int num) {
        TrieNode* node = root;
        string numStr = to_string(num);
        int len = 0;

        for (char digit : numStr) {
            int idx = digit - '0';
            if (node->children[idx]) {
                // Increase length if the current digit matches
                len++;
                node = node->children[idx];
            } else {
                // Stop if no match for the current digit
                break;
            }
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        // Step 1: Insert all numbers from arr1 into the Trie
        for (int num : arr1) {
            trie.insert(num);
        }

        int longestPrefix = 0;

        // Step 2: Find the longest prefix match for each number in arr2
        for (int num : arr2) {
            int len = trie.findLongestPrefix(num);
            longestPrefix = max(longestPrefix, len);
        }

        return longestPrefix;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {

    // Each node has up to 10 possible children (digits 0-9)
    TrieNode[] children = new TrieNode[10];
}

class Trie {

    TrieNode root = new TrieNode();

    // Insert a number into the Trie by treating it as a string of digits
    void insert(int num) {
        TrieNode node = root;
        String numStr = Integer.toString(num);
        for (char digit : numStr.toCharArray()) {
            int idx = digit - '0';
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
        }
    }

    // Find the longest common prefix for a number in arr2 with the Trie
    int findLongestPrefix(int num) {
        TrieNode node = root;
        String numStr = Integer.toString(num);
        int len = 0;

        for (char digit : numStr.toCharArray()) {
            int idx = digit - '0';
            if (node.children[idx] != null) {
                // Increase length if the current digit matches
                len++;
                node = node.children[idx];
            } else {
                // Stop if no match for the current digit
                break;
            }
        }
        return len;
    }
}

class Solution {

    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Trie trie = new Trie();

        // Step 1: Insert all numbers from arr1 into the Trie
        for (int num : arr1) {
            trie.insert(num);
        }

        int longestPrefix = 0;

        // Step 2: Find the longest prefix match for each number in arr2
        for (int num : arr2) {
            int len = trie.findLongestPrefix(num);
            longestPrefix = Math.max(longestPrefix, len);
        }

        return longestPrefix;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TrieNode:
    def __init__(self):
        # Each node has up to 10 possible children (digits 0-9)
        self.children = [None] * 10


class Trie:
    def __init__(self):
        self.root = TrieNode()

    # Insert a number into the Trie by treating it as a string of digits
    def insert(self, num):
        node = self.root
        num_str = str(num)
        for digit in num_str:
            idx = int(digit)
            if not node.children[idx]:
                node.children[idx] = TrieNode()
            node = node.children[idx]

    # Find the longest common prefix for a number in arr2 with the Trie
    def find_longest_prefix(self, num):
        node = self.root
        num_str = str(num)
        len = 0

        for digit in num_str:
            idx = int(digit)
            if node.children[idx]:
                # Increase length if the current digit matches
                len += 1
                node = node.children[idx]
            else:
                # Stop if no match for the current digit
                break
        return len


class Solution:
    def longestCommonPrefix(self, arr1, arr2):
        trie = Trie()

        # Step 1: Insert all numbers from arr1 into the Trie
        for num in arr1:
            trie.insert(num)

        longest_prefix = 0

        # Step 2: Find the longest prefix match for each number in arr2
        for num in arr2:
            len = trie.find_longest_prefix(num)
            longest_prefix = max(longest_prefix, len)

        return longest_prefix
```

</details>
