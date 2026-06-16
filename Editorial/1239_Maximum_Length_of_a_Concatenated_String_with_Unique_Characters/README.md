# 1239. Maximum Length of a Concatenated String with Unique Characters

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/)  
`Array` `String` `Backtracking` `Bit Manipulation`

**Problem Link:** [LeetCode 1239 - Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/)

## Problem

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

### Example 1

```text
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
```

### Example 2

```text
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
```

### Example 3

```text
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
```

## Constraints

- 1 <= arr.length <= 16
- 1 <= arr[i].length <= 26
- arr[i] contains only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1239. Maximum Length of a Concatenated String with Unique Characters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative | C++, Java, JavaScript, Python3 |
| Backtracking | C++, Java, JavaScript, Python3 |
| Recursion | C++, Java, JavaScript, Python3 |

## Approach 1: Iterative

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Initialize results with an empty string
        // from which to build all future results
        vector<string> results = {""};
        int best = 0;
        for (string word : arr) {
            // We only want to iterate through results
            // that existed prior to this loop
            int resultsLen = results.size();
            for (int i = 0; i < resultsLen; i++) {
                // Form a new result combination and
                // use a set to check for duplicate characters
                string newRes = results[i] + word;
                unordered_set<char> newResSet(newRes.begin(), newRes.end());
                if (newRes.size() != newResSet.size())
                    continue;

                // Add valid options to results and
                // keep track of the longest so far
                results.push_back(newRes);
                best = max(best, (int)newRes.size());
            }
        }
        return best;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxLength(List<String> arr) {
        // Initialize results with an empty string
        // from which to build all future results
        List<String> results = new ArrayList<>();
        results.add("");
        int best = 0;
        for (String word : arr) {
            // We only want to iterate through results
            // that existed prior to this loop
            int resultsLen = results.size();
            for (int i = 0; i < resultsLen; i++) {
                // Form a new result combination and
                // use a set to check for duplicate characters
                String newRes = results.get(i) + word;
                Set<Character> newResSet = new HashSet<>();
                for (char c : newRes.toCharArray())
                    newResSet.add(c);
                if (newRes.length() != newResSet.size())
                    continue;

                // Add valid options to results and
                // keep track of the longest so far
                results.add(newRes);
                best = Math.max(best, newRes.length());
            }
        }
        return best;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxLength = function(arr) {
    // Initialize results with an empty string
    // from which to build all future results
    let results = [""]
    let best = 0
    for (let word of arr) {
        // We only want to iterate through results
        // that existed prior to this loop
        let resultsLen = results.length
        for (let i = 0; i < resultsLen; i++) {
            // Form a new result combination and
            // use a set to check for duplicate characters
            let newRes = results[i] + word,
                newResSet = new Set(newRes.split(""))
            if (newRes.length !== newResSet.size)
                continue
                
            // Add valid options to results and
            // keep track of the longest so far
            results.push(newRes)
            best = Math.max(best, newRes.length)
        }
    }
    return best
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        # Initialize results with an empty string
        # from which to build all future results
        results = [""]
        best = 0
        for word in arr:
            # We only want to iterate through results
            # that existed prior to this loop
            for i in range(len(results)):
                # Form a new result combination and
                # use a set to check for duplicate characters
                new_res = results[i] + word
                if len(new_res) != len(set(new_res)):
                    continue

                # Add valid options to results and
                # keep track of the longest so far
                results.append(new_res)
                best = max(best, len(new_res))
        return best
```

</details>

<br>

## Approach 2: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Use depth first search recursion through arr
        // with backracking and a map for results
        unordered_map<char, int> resMap;
        return backtracking(arr, 0, resMap);
    }
    
private:
    int backtracking(vector<string>& arr, int pos, unordered_map<char, int>& resMap) {
        // Check for duplicate characters
        for (auto& kv : resMap)
            if (kv.second > 1)
                return 0;

        // Recurse through each possible next option
        // and find the best answer
        int best = resMap.size();
        for (int i = pos; i < arr.size(); i++) {
            // Add the current word to the result map
            // and recurse to the next position
            string& word = arr[i];
            for (char& c : word) {
                if (resMap.find(c) != resMap.end()) {
                    resMap[c]++;
                } else {
                    resMap[c] = 1;
                }
            }
            best = max(best, backtracking(arr, i + 1, resMap));

            // Backtrack the result map before continuing
            for (char& c : word) {
                if (resMap[c] == 1) {
                    resMap.erase(c);
                } else {
                    resMap[c]--;
                }
            }
        }
        return best;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxLength(List<String> arr) {    
        // Use depth first search recursion through arr
        // with backracking and a map for results
        return backtracking(arr, 0, new HashMap<Character, Integer>());
    }
    
    private int backtracking(List<String> arr, int pos, Map<Character, Integer> resMap) {    
        // Check for duplicate characters
        for (Integer val : resMap.values())
            if (val > 1)
                return 0;

        // Recurse through each possible next option
        // and find the best answer
        int best = resMap.size();
        for (int i = pos; i < arr.size(); i++) {
            // Add the current word to the result map
            // and recurse to the next position
            char[] wordArr = arr.get(i).toCharArray();
            for (char c : wordArr)
                resMap.put(c, resMap.getOrDefault(c, 0) + 1);
            best = Math.max(best, backtracking(arr, i + 1, resMap));

            // Backtrack the result map before continuing
            for (char c : wordArr) {
                if (resMap.get(c) == 1) {
                    resMap.remove(c);
                } else {
                    resMap.put(c, resMap.get(c) - 1);
                }
            }
        }
        return best;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxLength = function(arr) {    
    // Use depth first search recursion through arr
    // with backracking and a map for results
    return backtracking(arr, 0, new Map())
};

var backtracking = function(arr, pos, resMap) {    
    // Check for duplicate characters
    for (let val of resMap.values())
        if (val > 1)
            return 0
    
    // Recurse through each possible next option
    // and find the best answer
    let best = resMap.size
    for (let i = pos; i < arr.length; i++) {        
        // Add the current word to the result map
        // and recurse to the next position
        let word = arr[i]
        for (let c of word)
            resMap.set(c, (resMap.get(c) || 0) + 1)
        best = Math.max(best, backtracking(arr, i + 1, resMap))
        
        // Backtrack the result map before continuing
        for (let c of word) {
            if (resMap.get(c) === 1) {
                resMap.delete(c)
            } else {
                resMap.set(c, resMap.get(c) - 1)
            }
        }
    }
    return best
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        # Use depth first search recursion through arr
        # with backracking and a map for results
        return self.backtracking(arr, 0, Counter())
    
    def backtracking(self, arr: List[str], pos: int, res_map: Counter[str]) -> int:
        # Check for duplicate characters
        if len(res_map) and res_map.most_common(1)[0][1] > 1:
            return 0

        # Recurse through each possible next option
        # and find the best answer
        best = len(res_map)
        for i in range(pos, len(arr)):
            # Check for duplicate characters in word
            # then add the current word to the result map
            # and recurse to the next position
            word_map = Counter(arr[i])
            if len(word_map) != len(arr[i]):
                 continue
            res_map.update(word_map)
            best = max(best, self.backtracking(arr, i + 1, res_map))
            
            # Backtrack the result map before continuing
            for c in word_map:
                if res_map[c] == word_map[c]:
                    del res_map[c]
                else:
                    res_map[c] -= word_map[c]
        return best
```

</details>

<br>

## Approach 3: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Use depth first search recursion through arr
        // building from an initial empty string
        return dfs(arr, 0, "");
    }

private:
    int dfs(vector<string>& arr, int pos, string res) {    
        // Use a set to check res for duplicate characters
        unordered_set<char> resSet(res.begin(), res.end());
        if (res.size() != resSet.size())
            return 0;
        
        // Recurse through each possible next option
        // and find the best answer
        int best = res.size();
        for (int i = pos; i < arr.size(); i++)
            best = max(best, dfs(arr, i + 1, res + arr[i]));
        return best;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxLength(List<String> arr) {
        // Use depth first search recursion through arr
        // building from an initial empty string
        return dfs(arr, 0, "");
    }

    private int dfs(List<String> arr, int pos, String res) {    
        // Use a set to check res for duplicate characters
        Set<Character> resSet = new HashSet<>();
        for (char c : res.toCharArray())
            resSet.add(c);
        if (res.length() != resSet.size())
            return 0;

        // Recurse through each possible next option
        // and find the best answer
        int best = res.length();
        for (int i = pos; i < arr.size(); i++)
            best = Math.max(best, dfs(arr, i + 1, res + arr.get(i)));
        return best;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxLength = function(arr) {    
    // Use depth first search recursion through arr
    // building from an initial empty string
    return dfs(arr, 0, "")
};

var dfs = function(arr, pos, res) {    
    // Use a set to check res for duplicate characters
    let resSet = new Set(res.split(""))
    if (res.length !== resSet.size)
        return 0
        
    // Recurse through each possible next option
    // and find the best answer
    let best = res.length
    for (let i = pos; i < arr.length; i++)
        best = Math.max(best, dfs(arr, i + 1, res + arr[i]))
    return best
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxLength(self, arr: List[str]) -> int:        
        # Use depth first search recursion through arr
        # building from an initial empty string
        return self.dfs(arr, 0, "")
    
    def dfs(self, arr: List[str], pos: int, res: str) -> int:        
        # Use a set to check res for duplicate characters
        if len(res) != len(set(res)):
            return 0

        # Recurse through each possible next option
        # and find the best answer
        best = len(res)
        for i in range(pos, len(arr)):
            best = max(best, self.dfs(arr, i + 1, res + arr[i]))
        return best
```

</details>
