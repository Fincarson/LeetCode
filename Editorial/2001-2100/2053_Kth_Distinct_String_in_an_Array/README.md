# 2053. Kth Distinct String in an Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/kth-distinct-string-in-an-array/)  
`Array` `Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 2053 - Kth Distinct String in an Array](https://leetcode.com/problems/kth-distinct-string-in-an-array/)

## Problem

A distinct string is a string that is present only once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.

### Example 1

```text
Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned.
```

### Example 2

```text
Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.
```

### Example 3

```text
Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
```

## Constraints

- 1 <= k <= arr.length <= 1000
- 1 <= arr[i].length <= 5
- arr[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Common Words With One Occurrence](https://leetcode.com/problems/count-common-words-with-one-occurrence/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2053. Kth Distinct String in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Hash Set | C++, Java, Python3 |
| Hash Map | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        vector<string> distinctStrings;

        // Iterate through each string in the array
        for (int i = 0; i < n; i++) {
            string currentString = arr[i];
            bool isDistinct = true;

            // Check if the current string is distinct
            for (int j = 0; j < n; j++) {
                if (j == i) continue;  // Skip comparing with itself
                if (arr[j] == currentString) {
                    isDistinct = false;
                    break;
                }
            }

            // If the string is distinct, add it to the vector
            if (isDistinct) {
                distinctStrings.push_back(currentString);
            }
        }

        // Check if there are enough distinct strings
        if (distinctStrings.size() < k) {
            return "";
        }

        return distinctStrings[k - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String kthDistinct(String[] arr, int k) {
        int n = arr.length;
        List<String> distinctStrings = new ArrayList<>();

        // Iterate through each string in the array
        for (int i = 0; i < n; i++) {
            String currentString = arr[i];
            boolean isDistinct = true;

            // Check if the current string is distinct
            for (int j = 0; j < n; j++) {
                if (j == i) continue; // Skip comparing with itself
                if (arr[j].equals(currentString)) {
                    isDistinct = false;
                    break;
                }
            }

            // If the string is distinct, add it to the list
            if (isDistinct) {
                distinctStrings.add(currentString);
            }
        }

        // Check if there are enough distinct strings
        if (distinctStrings.size() < k) {
            return "";
        }

        return distinctStrings.get(k - 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        n = len(arr)
        distinct_strings = []

        # Iterate through each string in the array
        for i in range(n):
            current_string = arr[i]
            is_distinct = True

            # Check if the current string is distinct
            for j in range(n):
                if j == i:
                    continue  # Skip comparing with itself
                if arr[j] == current_string:
                    is_distinct = False
                    break

            # If the string is distinct, add it to the list
            if is_distinct:
                distinct_strings.append(current_string)

        # Check if there are enough distinct strings
        if len(distinct_strings) < k:
            return ""

        return distinct_strings[k - 1]
```

</details>

<br>

## Approach 2: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> distinctStrings;
        unordered_set<string> duplicateStrings;

        // First pass: Identify distinct and duplicate strings
        for (auto& str : arr) {
            // If the string is already in duplicateStrings, skip further
            // processing
            if (duplicateStrings.count(str)) {
                continue;
            }
            // If the string is in distinctStrings, it means we have seen it
            // before, so move it to duplicateStrings
            if (distinctStrings.count(str)) {
                distinctStrings.erase(str);
                duplicateStrings.insert(str);
            } else {
                distinctStrings.insert(str);
            }
        }

        // Second pass: Find the k-th distinct string
        for (auto& str : arr) {
            if (!duplicateStrings.count(str)) {
                // Decrement k for each distinct string encountered
                k--;
            }
            // When k reaches 0, we have found the k-th distinct string
            if (k == 0) {
                return str;
            }
        }

        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String kthDistinct(String[] arr, int k) {
        Set<String> distinctStrings = new HashSet<>();
        Set<String> duplicateStrings = new HashSet<>();

        // First pass: Identify distinct and duplicate strings
        for (String str : arr) {
            // If the string is already in duplicateStrings, skip further processing
            if (duplicateStrings.contains(str)) {
                continue;
            }
            // If the string is in distinctStrings, it means we have seen it before,
            // so move it to duplicateStrings
            if (distinctStrings.contains(str)) {
                distinctStrings.remove(str);
                duplicateStrings.add(str);
            } else {
                distinctStrings.add(str);
            }
        }

        // Second pass: Find the k-th distinct string
        for (String str : arr) {
            if (!duplicateStrings.contains(str)) {
                // Decrement k for each distinct string encountered
                k--;
            }
            // When k reaches 0, we have found the k-th distinct string
            if (k == 0) {
                return str;
            }
        }

        return "";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthDistinct(self, arr, k):
        distinct_strings = set()
        duplicate_strings = set()

        # First pass: Identify distinct and duplicate strings
        for s in arr:
            # If the string is already in duplicate_strings, skip further processing
            if s in duplicate_strings:
                continue
            # If the string is in distinct_strings, it means we have seen it before,
            # so move it to duplicate_strings
            if s in distinct_strings:
                distinct_strings.remove(s)
                duplicate_strings.add(s)
            else:
                distinct_strings.add(s)

        # Second pass: Find the k-th distinct string
        for s in arr:
            if s not in duplicate_strings:
                # Decrement k for each distinct string encountered
                k -= 1
            # When k reaches 0, we have found the k-th distinct string
            if k == 0:
                return s

        return ""
```

</details>

<br>

## Approach 3: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequencyMap;

        // First pass: Populate the frequency map
        for (string& str : arr) {
            frequencyMap[str]++;
        }

        // Second pass: Find the k-th distinct string
        for (string& str : arr) {
            // Check if the current string is distinct
            if (frequencyMap[str] == 1) {
                k--;
            }
            // When k reaches 0, we have found the k-th distinct string
            if (k == 0) {
                return str;
            }
        }

        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> frequencyMap = new HashMap<>();

        // First pass: Populate the frequency map
        for (String str : arr) {
            frequencyMap.put(str, frequencyMap.getOrDefault(str, 0) + 1);
        }

        // Second pass: Find the k-th distinct string
        for (String str : arr) {
            // Check if the current string is distinct
            if (frequencyMap.get(str) == 1) {
                k--;
            }
            // When k reaches 0, we have found the k-th distinct string
            if (k == 0) {
                return str;
            }
        }

        return "";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        frequency_map = {}

        # First pass: Populate the frequency map
        for s in arr:
            frequency_map[s] = frequency_map.get(s, 0) + 1

        # Second pass: Find the k-th distinct string
        for s in arr:
            # Check if the current string is distinct
            if frequency_map[s] == 1:
                k -= 1
            # When k reaches 0, we have found the k-th distinct string
            if k == 0:
                return s

        return ""
```

</details>
