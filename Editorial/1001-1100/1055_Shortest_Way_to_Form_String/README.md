# 1055. Shortest Way to Form String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/shortest-way-to-form-string/)  
`Two Pointers` `String` `Binary Search` `Greedy`

**Problem Link:** [LeetCode 1055 - Shortest Way to Form String](https://leetcode.com/problems/shortest-way-to-form-string/)

## Problem

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

### Example 1

```text
Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
```

### Example 2

```text
Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
```

### Example 3

```text
Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".
```

## Constraints

- 1 <= source.length, target.length <= 1000
- source and target consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1055. Shortest Way to Form String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Concatenate until Subsequence | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Pointers | C, C++, C#, Java, JavaScript, Python3, TypeScript |
| Inverted Index and Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| 2D Array | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Top-Down Dynamic Programming [TLE] | C++, Java, Python3 |
| Bottom-Up Dynamic Programming [TLE] | C, C++, Java, Python3 |

## Approach 2: Concatenate until Subsequence

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// To check if toCheck is a subsequence of inString
bool isSubsequence(char * toCheck, char * inString) {
    int i = 0, j = 0;
    while (toCheck[i] != '\0' && inString[j] != '\0') {
        if (toCheck[i] == inString[j]) {
            i++;
        }
        j++;
    }

    return toCheck[i] == '\0';
}

int shortestWay(char * source, char * target){
    
    // Boolean array to mark all characters of the source
    bool sourceChars[26] = {false};
    for (int i = 0; source[i] != '\0'; i++) {
        sourceChars[source[i] - 'a'] = true;
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for (int i = 0; target[i] != '\0'; i++) {
        if (!sourceChars[target[i] - 'a']) {
            return -1;
        }
    }

    // Concatenate source until target is a subsequence of the concatenated string
    char concatenatedSource[1000001];
    strcpy(concatenatedSource, source);
    int count = 1;
    while (!isSubsequence(target, concatenatedSource)) {
        strcat(concatenatedSource, source);
        count++;
    }

    // Number of concatenations done
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestWay(string source, string target) {

        // Boolean array to mark all characters of the source
        bool sourceChars[26] = {false};
        for (char c : source) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of the target are present in the source
        // If any character is not present, return -1
        for (char c : target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Concatenate source until the target is a subsequence of the concatenated string
        string concatenatedSource = source;
        int count = 1;
        while (!isSubsequence(target, concatenatedSource)) {
            concatenatedSource += source;
            count++;
        }

        // Number of concatenations done
        return count;
    }

    // To check if toCheck is a subsequence of inString
    bool isSubsequence(string toCheck, string inString) {
        int i = 0, j = 0;
        while (i < toCheck.length() && j < inString.length()) {
            if (toCheck[i] == inString[j]) {
                i++;
            }
            j++;
        }

        return i == toCheck.length();
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    public int ShortestWay(string source, string target) {

        // Boolean array to mark all characters of source
        bool[] sourceChars = new bool[26];
        foreach (char c in source) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        foreach (char c in target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Concatenate source until target is a subsequence of concatenated string
        string concatenatedSource = source;
        int count = 1;
        while (!IsSubsequence(target, concatenatedSource)) {
            concatenatedSource += source;
            count++;
        }

        // Number of concatenations done
        return count;
    }

    // To check if toCheck is a subsequence of inString
    bool IsSubsequence(string toCheck, string inString) {
        int i = 0, j = 0;
        while (i < toCheck.Length && j < inString.Length) {
            if (toCheck[i] == inString[j]) {
                i++;
            }
            j++;
        }

        return i == toCheck.Length;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func shortestWay(source string, target string) int {

    // Boolean array to mark all characters of source
    sourceChars := make([]bool, 26)
    for _, c := range source {
        sourceChars[c - 'a'] = true
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for _, c := range target {
        if !sourceChars[c - 'a'] {
            return -1
        }
    }

    // Concatenate source until target is a subsequence of concatenated string
    concatenatedSource := source
    count := 1
    for !isSubsequence(target, concatenatedSource) {
        concatenatedSource += source
        count++
    }

    // Number of concatenations done
    return count
}

// To check if toCheck is a subsequence of inString
func isSubsequence(toCheck string, inString string) bool {
    i, j := 0, 0
    for i < len(toCheck) && j < len(inString) {
        if toCheck[i] == inString[j] {
            i++
        }
        j++
    }

    return i == len(toCheck)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestWay(String source, String target) {

        // Boolean array to mark all characters of source
        boolean[] sourceChars = new boolean[26];
        for (char c : source.toCharArray()) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of the target are present in the source
        // If any character is not present, return -1
        for (char c : target.toCharArray()) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Concatenate source until the target is a subsequence of the concatenated string
        String concatenatedSource = source;
        int count = 1;
        while (!isSubsequence(target, concatenatedSource)) {
            concatenatedSource += source;
            count++;
        }

        // Number of concatenations done
        return count;
    }

    // To check if toCheck is a subsequence of the inString
    public boolean isSubsequence(String toCheck, String inString) {
        int i = 0, j = 0;
        while (i < toCheck.length() && j < inString.length()) {
            if (toCheck.charAt(i) == inString.charAt(j)) {
                i++;
            }
            j++;
        }

        return i == toCheck.length();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} source
 * @param {string} target
 * @return {number}
 */
var shortestWay = function(source, target) {

    // Boolean array to mark all characters of source
    let sourceChars = new Array(26).fill(false);
    for (let c of source) {
        sourceChars[c.charCodeAt(0) - 'a'.charCodeAt(0)] = true;
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for (let c of target) {
        if (!sourceChars[c.charCodeAt(0) - 'a'.charCodeAt(0)]) {
            return -1;
        }
    }

    // Concatenate source until target is a subsequence of concatenated string
    let concatenatedSource = source;
    let count = 1;
    while (!isSubsequence(target, concatenatedSource)) {
        concatenatedSource += source;
        count++;
    }

    // Number of concatenations done
    return count;
};

// To check if toCheck is a subsequence of inString
function isSubsequence(toCheck, inString) {
    let i = 0, j = 0;
    while (i < toCheck.length && j < inString.length) {
        if (toCheck[i] == inString[j]) {
            i++;
        }
        j++;
    }

    return i == toCheck.length;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestWay(self, source: str, target: str) -> int:

        # To check if to_check is subsequence of in_string
        def is_subsequence(to_check, in_string):
            i = j = 0
            while i < len(to_check) and j < len(in_string):
                if to_check[i] == in_string[j]:
                    i += 1
                j += 1

            return i == len(to_check)

        # Set of all characters of the source. We could use a boolean array as well.
        source_chars = set(source)

        # Check if all characters of the target are present in the source
        # If any character is not present, return -1
        for char in target:
            if char not in source_chars:
                return -1

        # Concatenate source until the target is a subsequence
        # of the concatenated string
        concatenated_source = source
        count = 1
        while not is_subsequence(target, concatenated_source):
            concatenated_source += source
            count += 1

        # Number of concatenations done
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function shortestWay(source: string, target: string): number {

    // Boolean array to mark all characters of source
    let sourceChars = new Array(26).fill(false);
    for (let c of source) {
        sourceChars[c.charCodeAt(0) - 'a'.charCodeAt(0)] = true;
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for (let c of target) {
        if (!sourceChars[c.charCodeAt(0) - 'a'.charCodeAt(0)]) {
            return -1;
        }
    }

    // Concatenate source until target is a subsequence of concatenated string
    let concatenatedSource = source;
    let count = 1;
    while (!isSubsequence(target, concatenatedSource)) {
        concatenatedSource += source;
        count++;
    }

    // Number of concatenations done
    return count;
};

// To check if toCheck is a subsequence of inString
function isSubsequence(toCheck: string, inString: string): boolean {
    let i = 0, j = 0;
    while (i < toCheck.length && j < inString.length) {
        if (toCheck[i] == inString[j]) {
            i++;
        }
        j++;
    }

    return i == toCheck.length;
}
```

</details>

<br>

## Approach 3: Two Pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int shortestWay(char * source, char * target){

    // Boolean array to mark all characters of source
    bool sourceChars[26] = {false};
    for (int i = 0; i < strlen(source); i++) {
        sourceChars[source[i] - 'a'] = true;
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for (int i = 0; i < strlen(target); i++) {
        if (!sourceChars[target[i] - 'a']) {
            return -1;
        }
    }

    // Length of source to loop back to start of source using mod
    int m = strlen(source);

    // Pointer for source
    int sourceIterator = 0;

    // Number of times source is traversed. It will be incremented when
    // while finding occurrence of a character in target, sourceIterator
    // reaches the start of source again.
    int count = 0;

    // Find all characters of target in source
    for (int i = 0; i < strlen(target); i++) {

        // If while finding, iterator reaches start of source again,
        // increment count
        if (sourceIterator == 0) {
            count++;
        }

        // Find the first occurrence of c in source
        while (source[sourceIterator] != target[i]) {

            // Formula for incrementing while looping back to start.
            sourceIterator = (sourceIterator + 1) % m;

            // If while finding, iterator reaches start of source again,
            // increment count
            if (sourceIterator == 0) {
                count++;
            }
        }

        // Loop will break when c is found in source. Thus, increment.
        // Don't increment count until it is not clear that target has
        // remaining characters.
        sourceIterator = (sourceIterator + 1) % m;
    }

    // Return count
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestWay(string source, string target) {
        
        // Boolean array to mark all characters of source
        bool sourceChars[26] = {false};
        for (char c : source) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        for (char c : target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Length of source to loop back to start of source using mod
        int m = source.length();

        // Pointer for source
        int sourceIterator = 0;

        // Number of times source is traversed. It will be incremented when
        // while finding occurrence of a character in target, sourceIterator
        // reaches the start of source again.
        int count = 0;

        // Find all characters of target in source
        for (char c : target) {

            // If while finding, iterator reaches start of source again,
            // increment count
            if (sourceIterator == 0) {
                count++;
            }

            // Find the first occurrence of c in source
            while (source[sourceIterator] != c) {

                // Formula for incrementing while looping back to start.
                sourceIterator = (sourceIterator + 1) % m;

                // If while finding, iterator reaches start of source again,
                // increment count
                if (sourceIterator == 0) {
                    count++;
                }
            }

            // Loop will break when c is found in source. Thus, increment.
            // Don't increment count until it is not clear that target has
            // remaining characters.
            sourceIterator = (sourceIterator + 1) % m;
        }

        // Return count
        return count;
    }  
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    public int ShortestWay(string source, string target) {
        
        // Boolean array to mark all characters of source
        bool[] sourceChars = new bool[26];
        foreach (char c in source) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        foreach (char c in target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Length of source to loop back to start of source using mod
        int m = source.Length;

        // Pointer for source
        int sourceIterator = 0;

        // Number of times source is traversed. It will be incremented when
        // while finding occurrence of a character in target, sourceIterator
        // reaches the start of source again.
        int count = 0;

        // Find all characters of target in source
        foreach (char c in target) {

            // If while finding, iterator reaches start of source again,
            // increment count
            if (sourceIterator == 0) {
                count++;
            }

            // Find the first occurrence of c in source
            while (source[sourceIterator] != c) {

                // Formula for incrementing while looping back to start.
                sourceIterator = (sourceIterator + 1) % m;

                // If while finding, iterator reaches start of source again,
                // increment count
                if (sourceIterator == 0) {
                    count++;
                }
            }

            // Loop will break when c is found in source. Thus, increment.
            // Don't increment count until it is not clear that target has
            // remaining characters.
            sourceIterator = (sourceIterator + 1) % m;
        }

        // Return count
        return count;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestWay(String source, String target) {

        // Boolean array to mark all characters of source
        boolean[] sourceChars = new boolean[26];
        for (char c : source.toCharArray()) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        for (char c : target.toCharArray()) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Length of source to loop back to start of source using mod
        int m = source.length();

        // Pointer for source
        int sourceIterator = 0;

        // Number of times source is traversed. It will be incremented when
        // While finding occurrence of a character in target, sourceIterator
        // reaches the start of source again.
        int count = 0;

        // Find all characters of target in source
        for (char c : target.toCharArray()) {

            // If while finding, the iterator reaches the start of source again,
            // increment count
            if (sourceIterator == 0) {
                count++;
            }

            // Find the first occurrence of c in source
            while (source.charAt(sourceIterator) != c) {

                // Formula for incrementing while looping back to start.
                sourceIterator = (sourceIterator + 1) % m;

                // If while finding, iterator reaches start of source again,
                // increment count
                if (sourceIterator == 0) {
                    count++;
                }
            }

            // Loop will break when c is found in source. Thus, increment.
            // Don't increment count until it is not clear that target has
            // remaining characters.
            sourceIterator = (sourceIterator + 1) % m;
        }

        // Return count
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} source
 * @param {string} target
 * @return {number}
 */
var shortestWay = function(source, target) {
    
    // Boolean array to mark all characters of source
    let sourceChars = new Array(26).fill(false);
    for (let c of source) {
        sourceChars[c.charCodeAt(0) - 'a'.charCodeAt(0)] = true;
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for (let c of target) {
        if (!sourceChars[c.charCodeAt(0) - 'a'.charCodeAt(0)]) {
            return -1;
        }
    }

    // Length of source to loop back to start of source using mod
    let m = source.length;

    // Pointer for source
    let sourceIterator = 0;

    // Number of times source is traversed. It will be incremented when
    // while finding occurrence of a character in target, sourceIterator
    // reaches the start of source again.
    let count = 0;

    // Find all characters of target in source
    for (let c of target) {

        // If while finding, iterator reaches start of source again,
        // increment count
        if (sourceIterator == 0) {
            count++;
        }

        // Find the first occurrence of c in source
        while (source[sourceIterator] != c) {

            // Formula for incrementing while looping back to start.
            sourceIterator = (sourceIterator + 1) % m;

            // If while finding, iterator reaches start of source again,
            // increment count
            if (sourceIterator == 0) {
                count++;
            }
        }

        // Loop will break when c is found in source. Thus, increment.
        // Don't increment count until it is not clear that target has
        // remaining characters.
        sourceIterator = (sourceIterator + 1) % m;
    }

    // Return count
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestWay(self, source: str, target: str) -> int:

        # Set of all characters of source. Can use a boolean array too.
        source_chars = set(source)

        # Check if all characters of target are present in source
        # If any character is not present, return -1
        for char in target:
            if char not in source_chars:
                return -1

        # Length of source to loop back to start of source using mod
        m = len(source)

        # Pointer for source
        source_iterator = 0

        # Number of times source is traversed. It will be incremented when
        # while finding the occurrence of a character in target, source_iterator
        # reaches the start of source again.
        count = 0

        # Find all characters of target in source
        for char in target:

            # If while finding, iterator reaches start of source again,
            # increment count
            if source_iterator == 0:
                count += 1

            # Find the first occurrence of char in source
            while source[source_iterator] != char:

                # Formula for incrementing while looping back to start.
                source_iterator = (source_iterator + 1) % m

                # If while finding, iterator reaches the start of source again,
                # increment count
                if source_iterator == 0:
                    count += 1

            # Loop will break when char is found in source. Thus, increment.
            # Don't increment count until it is not clear that target has
            # remaining characters.
            source_iterator = (source_iterator + 1) % m

        # Return count
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function shortestWay(source: string, target: string): number {
    
    // Boolean array to mark all characters of source
    let sourceChars = new Array(26).fill(false);
    for (let c of source) {
        sourceChars[c.charCodeAt(0) - 'a'.charCodeAt(0)] = true;
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for (let c of target) {
        if (!sourceChars[c.charCodeAt(0) - 'a'.charCodeAt(0)]) {
            return -1;
        }
    }

    // Length of source to loop back to start of source using mod
    let m = source.length;

    // Pointer for source
    let sourceIterator = 0;

    // Number of times source is traversed. It will be incremented when
    // while finding occurrence of a character in target, sourceIterator
    // reaches the start of source again.
    let count = 0;

    // Find all characters of target in source
    for (let c of target) {

        // If while finding, iterator reaches start of source again,
        // increment count
        if (sourceIterator == 0) {
            count++;
        }

        // Find the first occurrence of c in source
        while (source[sourceIterator] != c) {

            // Formula for incrementing while looping back to start.
            sourceIterator = (sourceIterator + 1) % m;

            // If while finding, iterator reaches start of source again,
            // increment count
            if (sourceIterator == 0) {
                count++;
            }
        }

        // Loop will break when c is found in source. Thus, increment.
        // Don't increment count until it is not clear that target has
        // remaining characters.
        sourceIterator = (sourceIterator + 1) % m;
    }

    // Return count
    return count;
};
```

</details>

<br>

## Approach 4: Inverted Index and Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int lower_bound(int * arr, int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int shortestWay(char * source, char * target){

    // Array to store the vector of charToIndices of each character in source
    int charToIndices[26][10000];
    int charToIndicesSize[26] = {0};

    for (int i = 0; i < strlen(source); i++) {
        charToIndices[source[i] - 'a'][charToIndicesSize[source[i] - 'a']] = i;
        charToIndicesSize[source[i] - 'a']++;
    }

    // The current index in source
    int sourceIterator = 0;

    // Number of times we have to iterate through source to get target
    int count = 1;

    // Find all characters of target in source
    for (int i = 0; i < strlen(target); i++) {

        // If the character is not present in source, return -1
        if (charToIndicesSize[target[i] - 'a'] == 0) {
            return -1;
        }

        // Binary search to find the index of the character in source next to the source iterator
        int * indices = charToIndices[target[i] - 'a'];
        int index = lower_bound(indices, charToIndicesSize[target[i] - 'a'], sourceIterator);
        
        // If we have reached the end of the list, we need to iterate
        // through source again, hence first index of character in source.
        if (index == charToIndicesSize[target[i] - 'a']) {
            count++;
            sourceIterator = indices[0] + 1;
        } else {
            sourceIterator = indices[index] + 1;
        }
    }

    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public: 
    int shortestWay(string source, string target) {

        // Array to store the vector of charToIndices of each character in source
        vector < int > charToIndices[26];
        for (int i = 0; i < source.size(); i++) {
            charToIndices[source[i] - 'a'].push_back(i);
        }

        // The current index in source
        int sourceIterator = 0;

        // Number of times we have to iterate through source to get target
        int count = 1;

        // Find all characters of target in source
        for (int i = 0; i < target.size(); i++) {

            // If the character is not present in source, return -1
            if (charToIndices[target[i] - 'a'].size() == 0) {
                return -1;
            }

            // Binary search to find the index of the character in source next to the source iterator
            vector < int > indices = charToIndices[target[i] - 'a'];
            int index = lower_bound(indices.begin(), indices.end(), sourceIterator) - indices.begin();

            // If we have reached the end of the list, we need to iterate
            // through source again, hence first index of character in source.
            if (index == indices.size()) {
                count++;
                sourceIterator = indices[0] + 1;
            } else {
                sourceIterator = indices[index] + 1;
            }
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    public int ShortestWay(string source, string target) {

        // List of indices for all characters in source
        List < int > [] charToIndices = new List < int > [26];
        for (int i = 0; i < source.Length; i++) {
            char c = source[i];
            if (charToIndices[c - 'a'] == null) {
                charToIndices[c - 'a'] = new List < int > ();
            }
            charToIndices[c - 'a'].Add(i);
        }

        // Pointer for source
        int sourceIterator = 0;

        // Number of times we need to iterate through source
        int count = 1;

        // Find all characters of target in source
        foreach (char c in target) {

            // If the character is not in the source, return -1
            if (charToIndices[c - 'a'] == null) {
                return -1;
            }

            // Binary search to find the index of the character in source
            // next to the source iterator
            List < int > indices = charToIndices[c - 'a'];
            int index = indices.BinarySearch(sourceIterator);

            // If the index is negative, we need to find the next index
            // that is greater than the source iterator
            if (index < 0) {
                index = ~index;
            }

            // If we have reached the end of the list, we need to iterate
            // through source again, hence first index of character in source.
            if (index == indices.Count) {
                count++;
                sourceIterator = indices[0] + 1;
            } else {
                sourceIterator = indices[index] + 1;
            }
        }

        // Return the number of times we need to iterate through source
        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func shortestWay(source string, target string) int {
    // List of indices for all characters in source
    charToIndices := make([][]int, 26)
    for i := 0; i < len(source); i++ {
        c := source[i]
        if charToIndices[c-'a'] == nil {
            charToIndices[c-'a'] = make([]int, 0)
        }
        charToIndices[c-'a'] = append(charToIndices[c-'a'], i)
    }

    // Pointer for source
    sourceIterator := 0

    // Number of times we need to iterate through source
    count := 1

    // Find all characters of target in source
    for _, c := range target {
        // If the character is not in the source, return -1
        if charToIndices[c-'a'] == nil {
            return -1
        }

        // Binary search to find the index of the character in source
        // next to the source iterator
        indices := charToIndices[c-'a']
        index := sort.Search(len(indices), func(i int) bool {
            return indices[i] >= sourceIterator
        })

        // If we have reached the end of the list, we need to iterate
        // through source again, hence first index of character in source.
        if index == len(indices) {
            count++
            sourceIterator = indices[0] + 1
        } else {
            sourceIterator = indices[index] + 1
        }
    }

    // Return the number of times we need to iterate through source
    return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestWay(String source, String target) {

        // List of indices for all characters in source
        ArrayList<Integer>[] charToIndices = new ArrayList[26];
        for (int i = 0; i < source.length(); i++) {
            char c = source.charAt(i);
            if (charToIndices[c - 'a'] == null) {
                charToIndices[c - 'a'] = new ArrayList<>();
            }
            charToIndices[c - 'a'].add(i);
        }

        // Pointer for source
        int sourceIterator = 0;

        // Number of times we need to iterate through source
        int count = 1;

        // Find all characters of target in source
        for (char c : target.toCharArray()) {

            // If the character is not in the source, return -1
            if (charToIndices[c - 'a'] == null) {
                return -1;
            }

            // Binary search to find the index of the character in source
            // next to the source iterator
            ArrayList<Integer> indices = charToIndices[c - 'a'];
            int index = Collections.binarySearch(indices, sourceIterator);

            // If the index is negative, we need to find the next index
            // that is greater than the source iterator
            if (index < 0) {
                index = -index - 1;
            }

            // If we have reached the end of the list, we need to iterate
            // through source again, hence first index of character in source.
            if (index == indices.size()) {
                count++;
                sourceIterator = indices.get(0) + 1;
            } else {
                sourceIterator = indices.get(index) + 1;
            }
        }

        // Return the number of times we need to iterate through source
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} source
 * @param {string} target
 * @return {number}
 */
var shortestWay = function(source, target) {
    // List of indices for all characters in source
    let charToIndices = new Array(26);
    for (let i = 0; i < source.length; i++) {
        let c = source[i];
        if (charToIndices[c.charCodeAt(0) - 'a'.charCodeAt(0)] == null) {
            charToIndices[c.charCodeAt(0) - 'a'.charCodeAt(0)] = [];
        }
        charToIndices[c.charCodeAt(0) - 'a'.charCodeAt(0)].push(i);
    }

    // Pointer for source
    let sourceIterator = 0;

    // Number of times we need to iterate through source
    let count = 1;

    // Find all characters of target in source
    for (let i = 0; i < target.length; i++) {
        let c = target[i];

        // If the character is not in the source, return -1
        if (charToIndices[c.charCodeAt(0) - 'a'.charCodeAt(0)] == null) {
            return -1;
        }

        // Binary search to find the index of the character in source
        // next to the source iterator
        let indices = charToIndices[c.charCodeAt(0) - 'a'.charCodeAt(0)];
        let index = binarySearch(indices, sourceIterator);

        // If we have reached the end of the list, we need to iterate
        // through source again, hence first index of character in source.
        if (index == indices.length) {
            count++;
            sourceIterator = indices[0] + 1;
        } else {
            sourceIterator = indices[index] + 1;
        }
    }

    // Return the number of times we need to iterate through source
    return count;
};

// Binary search to find the index of the character in source
// next to the source iterator
function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestWay(self, source: str, target: str) -> int:

        # List of indices for all characters in source
        char_to_indices = defaultdict(list)
        for i, c in enumerate(source):
            char_to_indices[c].append(i)

        # Pointer for source
        source_iterator = 0

        # Number of times we need to iterate through source
        count = 1

        # Find all characters of target in source
        for char in target:

            # If character is not in source, return -1
            if char not in char_to_indices:
                return -1

            # Binary Search to find the index of the character in source
            # next to the current source_iterator
            index = bisect.bisect_left(char_to_indices[char], source_iterator)

            # If we have reached the end of the list, we need to iterate
            # through source again, hence first index of character in source.
            if index == len(char_to_indices[char]):
                count += 1
                source_iterator = char_to_indices[char][0] + 1
            else:
                source_iterator = char_to_indices[char][index] + 1

        # Return the number of times we need to iterate through source
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function shortestWay(source: string, target: string): number {
    // List of indices for all characters in source
    let charToIndices: number[][] = new Array(26);
    for (let i = 0; i < source.length; i++) {
        let c = source[i];
        if (charToIndices[c.charCodeAt(0) - 'a'.charCodeAt(0)] == null) {
            charToIndices[c.charCodeAt(0) - 'a'.charCodeAt(0)] = [];
        }
        charToIndices[c.charCodeAt(0) - 'a'.charCodeAt(0)].push(i);
    }

    // Pointer for source
    let sourceIterator = 0;

    // Number of times we need to iterate through source
    let count = 1;

    // Find all characters of target in source
    for (let i = 0; i < target.length; i++) {
        let c = target[i];

        // If the character is not in the source, return -1
        if (charToIndices[c.charCodeAt(0) - 'a'.charCodeAt(0)] == null) {
            return -1;
        }

        // Binary search to find the index of the character in source
        // next to the source iterator
        let indices = charToIndices[c.charCodeAt(0) - 'a'.charCodeAt(0)];
        let index = binarySearch(indices, sourceIterator);

        // If we have reached the end of the list, we need to iterate
        // through source again, hence first index of character in source.
        if (index == indices.length) {
            count++;
            sourceIterator = indices[0] + 1;
        } else {
            sourceIterator = indices[index] + 1;
        }
    }

    // Return the number of times we need to iterate through source
    return count;
}

// Binary search to find the index of the character in source
// next to the source iterator
function binarySearch(arr: number[], target: number): number {
    let left = 0;
    let right = arr.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```

</details>

<br>

## Approach 5: 2D Array

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int shortestWay(char * source, char * target){

    // Length of source
    int sourceLength = strlen(source);

    // Next Occurrence of Character after Index
    int nextOccurrence[sourceLength][26];

    // Base Case
    for (int c = 0; c < 26; c++) {
        nextOccurrence[sourceLength - 1][c] = -1;
    }
    nextOccurrence[sourceLength - 1][source[sourceLength - 1] - 'a'] = sourceLength - 1;

    // Fill using recurrence relation
    for (int idx = sourceLength - 2; idx >= 0; idx--) {
        for (int c = 0; c < 26; c++) {
            nextOccurrence[idx][c] = nextOccurrence[idx + 1][c];
        }
        nextOccurrence[idx][source[idx] - 'a'] = idx;
    }

    // Pointer to the current index in source
    int sourceIterator = 0;

    // Number of times we need to iterate through source
    int count = 1;

    // Find all characters of target in source
    for (int idx = 0; target[idx] != '\0'; idx++) {

        // If the character is not present in source
        if (nextOccurrence[0][target[idx] - 'a'] == -1) {
            return -1;
        }

        // If we have reached the end of source, or the character is not in
        // source after source_iterator, loop back to beginning
        if (sourceIterator == sourceLength || nextOccurrence[sourceIterator][target[idx] - 'a'] == -1) {
            count++;
            sourceIterator = 0;
        }

        // Next occurrence of character in source after source_iterator
        sourceIterator = nextOccurrence[sourceIterator][target[idx] - 'a'] + 1;
    }

    // Return the number of times we need to iterate through source
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestWay(string source, string target) {

        // Next Occurrence of Character after Index
        int nextOccurrence[source.length()][26];

        // Base Case
        for (int c = 0; c < 26; c++) {
            nextOccurrence[source.length() - 1][c] = -1;
        }
        nextOccurrence[source.length() - 1][source[source.length() - 1] - 'a'] = source.length() - 1;

        // Fill using recurrence relation
        for (int idx = source.length() - 2; idx >= 0; idx--) {
            for (int c = 0; c < 26; c++) {
                nextOccurrence[idx][c] = nextOccurrence[idx + 1][c];
            }
            nextOccurrence[idx][source[idx] - 'a'] = idx;
        }

        // Pointer to the current index in source
        int sourceIterator = 0;

        // Number of times we need to iterate through source
        int count = 1;

        // Find all characters of target in source
        for (char c : target) {

            // If the character is not present in source
            if (nextOccurrence[0][c - 'a'] == -1) {
                return -1;
            }

            // If we have reached the end of source, or the character is not in
            // source after source_iterator, loop back to beginning
            if (sourceIterator == source.length() || nextOccurrence[sourceIterator][c - 'a'] == -1) {
                count++;
                sourceIterator = 0;
            }

            // Next occurrence of character in source after source_iterator
            sourceIterator = nextOccurrence[sourceIterator][c - 'a'] + 1;
        }

        // Return the number of times we need to iterate through source
        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    public int ShortestWay(string source, string target) {

        // Next Occurrence of Character after Index
        int[,] nextOccurrence = new int[source.Length, 26];

        // Base Case
        for (int c = 0; c < 26; c++) {
            nextOccurrence[source.Length - 1, c] = -1;
        }
        nextOccurrence[source.Length - 1, source[source.Length - 1] - 'a'] = source.Length - 1;

        // Fill using recurrence relation
        for (int idx = source.Length - 2; idx >= 0; idx--) {
            for (int c = 0; c < 26; c++) {
                nextOccurrence[idx, c] = nextOccurrence[idx + 1, c];
            }
            nextOccurrence[idx, source[idx] - 'a'] = idx;
        }

        // Pointer to the current index in source
        int sourceIterator = 0;

        // Number of times we need to iterate through source
        int count = 1;

        // Find all characters of target in source
        foreach (char c in target) {

            // If the character is not present in source
            if (nextOccurrence[0, c - 'a'] == -1) {
                return -1;
            }

            // If we have reached the end of source, or the character is not in
            // source after source_iterator, loop back to beginning
            if (sourceIterator == source.Length || nextOccurrence[sourceIterator, c - 'a'] == -1) {
                count++;
                sourceIterator = 0;
            }

            // Next occurrence of the character in source after source_iterator
            sourceIterator = nextOccurrence[sourceIterator, c - 'a'] + 1;
        }

        // Return the number of times we need to iterate through source
        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func shortestWay(source string, target string) int {

    // Length of source
    sourceLength := len(source)

    // Next Occurrence of Character after Index
    nextOccurrence := make([][]int, sourceLength)
    for idx := range nextOccurrence {
        nextOccurrence[idx] = make([]int, 26)
    }

    // Base Case
    for c := 0; c < 26; c++ {
        nextOccurrence[sourceLength - 1][c] = -1
    }
    nextOccurrence[sourceLength - 1][source[sourceLength - 1] - 'a'] = sourceLength - 1

    // Fill using recurrence relation
    for idx := sourceLength - 2; idx >= 0; idx-- {
        for c := 0; c < 26; c++ {
            nextOccurrence[idx][c] = nextOccurrence[idx + 1][c]
        }
        nextOccurrence[idx][source[idx] - 'a'] = idx
    }

    // Pointer to the current index in source
    sourceIterator := 0

    // Number of times we need to iterate through source
    count := 1

    // Find all characters of target in source
    for _, c := range target {

        // If the character is not present in source
        if nextOccurrence[0][c - 'a'] == -1 {
            return -1
        }

        // If we have reached the end of source, or the character is not in
        // source after source_iterator, loop back to beginning
        if sourceIterator == sourceLength || nextOccurrence[sourceIterator][c - 'a'] == -1 {
            count++
            sourceIterator = 0
        }

        // Next occurrence of character in source after source_iterator
        sourceIterator = nextOccurrence[sourceIterator][c - 'a'] + 1
    }

    // Return the number of times we need to iterate through source
    return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestWay(String source, String target) {

        // Next occurrence of a character after a given index
        int[][] nextOccurrence = new int[source.length()][26];

        // Base Case
        for (int c = 0; c < 26; c++) {
            nextOccurrence[source.length() - 1][c] = -1;
        }
        nextOccurrence[source.length() - 1][source.charAt(source.length() - 1) - 'a'] = source.length() - 1;

        // Fill using recurrence relation
        for (int idx = source.length() - 2; idx >= 0; idx--) {
            for (int c = 0; c < 26; c++) {
                nextOccurrence[idx][c] = nextOccurrence[idx + 1][c];
            }
            nextOccurrence[idx][source.charAt(idx) - 'a'] = idx;
        }

        // Pointer to the current index in source
        int sourceIterator = 0;

        // Number of times we need to iterate through source
        int count = 1;

        // Find all characters of target in source
        for (char c : target.toCharArray()) {

            // If the character is not present in source
            if (nextOccurrence[0][c - 'a'] == -1) {
                return -1;
            }

            // If we have reached the end of source, or the character is not in
            // source after source_iterator, loop back to beginning
            if (sourceIterator == source.length() || nextOccurrence[sourceIterator][c - 'a'] == -1) {
                count++;
                sourceIterator = 0;
            }

            // Next occurrence of character in source after source_iterator
            sourceIterator = nextOccurrence[sourceIterator][c - 'a'] + 1;
        }

        // Return the number of times we need to iterate through source
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} source
 * @param {string} target
 * @return {number}
 */
var shortestWay = function(source, target) {

    // Length of source
    const sourceLength = source.length

    // Next Occurrence of Character after Index
    const nextOccurrence = Array.from({length: sourceLength}, () => Array(26).fill(-1))

    // Base Case
    for (let c = 0; c < 26; c++) {
        nextOccurrence[sourceLength - 1][c] = -1
    }
    nextOccurrence[sourceLength - 1][source[sourceLength - 1].charCodeAt(0) - 'a'.charCodeAt(0)] = sourceLength - 1

    // Fill using the recurrence relation
    for (let idx = sourceLength - 2; idx >= 0; idx--) {
        for (let c = 0; c < 26; c++) {
            nextOccurrence[idx][c] = nextOccurrence[idx + 1][c]
        }
        nextOccurrence[idx][source[idx].charCodeAt(0) - 'a'.charCodeAt(0)] = idx
    }

    // Pointer to the current index in source
    let sourceIterator = 0

    // Number of times we need to iterate through source
    let count = 1

    // Find all characters of target in source
    for (let idx = 0; idx < target.length; idx++) {

        // If the character is not present in source
        if (nextOccurrence[0][target[idx].charCodeAt(0) - 'a'.charCodeAt(0)] == -1) {
            return -1
        }

        // If we have reached the end of source, or the character is not in
        // source after source_iterator, loop back to beginning
        if (sourceIterator == sourceLength || nextOccurrence[sourceIterator][target[idx].charCodeAt(0) - 'a'.charCodeAt(0)] == -1) {
            count++
            sourceIterator = 0
        }

        // Next occurrence of the character in source after source_iterator
        sourceIterator = nextOccurrence[sourceIterator][target[idx].charCodeAt(0) - 'a'.charCodeAt(0)] + 1
    }

    // Return the number of times we need to iterate through source
    return count
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestWay(self, source: str, target: str) -> int:

        # Length of source
        source_length = len(source)

        # Next Occurrence of Character after Index
        next_occurrence = [defaultdict(int) for idx in range(source_length)]

        # Base Case
        next_occurrence[source_length -
                        1][source[source_length - 1]] = source_length - 1

        # Using Recurrence Relation to fill next_occurrence
        for idx in range(source_length - 2, -1, -1):
            next_occurrence[idx] = next_occurrence[idx + 1].copy()
            next_occurrence[idx][source[idx]] = idx

        # Pointer for source
        source_iterator = 0

        # Number of times we need to iterate through source
        count = 1

        # Find all characters of target in source
        for char in target:

            # If character is not in source, return -1
            if char not in next_occurrence[0]:
                return -1

            # If we have reached the end of source, or the character is not in
            # source after source_iterator, loop back to beginning
            if (source_iterator == source_length or
                    char not in next_occurrence[source_iterator]):
                count += 1
                source_iterator = 0

            # Next occurrence of character in source after source_iterator
            source_iterator = next_occurrence[source_iterator][char] + 1

        # Return the number of times we need to iterate through source
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function shortestWay(source: string, target: string): number {

    // Length of source
    const sourceLength = source.length

    // Next Occurrence of Character after Index
    const nextOccurrence = Array.from({length: sourceLength}, () => Array(26).fill(-1))

    // Base Case
    for (let c = 0; c < 26; c++) {
        nextOccurrence[sourceLength - 1][c] = -1
    }
    nextOccurrence[sourceLength - 1][source.charCodeAt(sourceLength - 1) - 'a'.charCodeAt(0)] = sourceLength - 1

    // Fill using recurrence relation
    for (let idx = sourceLength - 2; idx >= 0; idx--) {
        for (let c = 0; c < 26; c++) {
            nextOccurrence[idx][c] = nextOccurrence[idx + 1][c]
        }
        nextOccurrence[idx][source.charCodeAt(idx) - 'a'.charCodeAt(0)] = idx
    }

    // Pointer to the current index in source
    let sourceIterator = 0

    // Number of times we need to iterate through source
    let count = 1

    // Find all characters of target in source
    for (let idx = 0; idx < target.length; idx++) {

        // If the character is not present in source
        if (nextOccurrence[0][target.charCodeAt(idx) - 'a'.charCodeAt(0)] == -1) {
            return -1
        }

        // If we have reached the end of source, or the character is not in
        // source after source_iterator, loop back to beginning
        if (sourceIterator == sourceLength || nextOccurrence[sourceIterator][target.charCodeAt(idx) - 'a'.charCodeAt(0)] == -1) {
            count++
            sourceIterator = 0
        }

        // Next occurrence of character in source after source_iterator
        sourceIterator = nextOccurrence[sourceIterator][target.charCodeAt(idx) - 'a'.charCodeAt(0)] + 1
    }

    // Return the number of times we need to iterate through source
    return count
};
```

</details>

<br>

## Approach 6: Top-Down Dynamic Programming [TLE]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestWay(string source, string target) {
        
        // Boolean array to mark all characters of source
        bool sourceChars[26] = {false};
        for (char c : source) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        for (char c : target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Optimal Answer for a given ending index. Memoizing using an Array
        int memo[target.length()];
        fill(memo, memo + target.length(), INT_MAX / 2);

        // Want to find optimal answer for the last index.
        // Case when task is not possible is already handled
        return optimalAnswer(target.length() - 1, memo, source, target);
    }
    
    int optimalAnswer(int endingIndex, int memo[], string source, string target) {

        // Base Case
        if (endingIndex == 0) {
            return 1;
        }

        // If already calculated, return
        if (memo[endingIndex] != INT_MAX / 2) {
            return memo[endingIndex];
        }

        // If subsequence, return 1
        if (isSubsequence(0, endingIndex, source, target)) {
            memo[endingIndex] = 1;
            return 1;
        }

        // If not subsequence, partition into two parts and find minimum
        int answer = INT_MAX / 2;

        for (int partitionIndex = 0; partitionIndex < endingIndex; partitionIndex++) {

            // Check for subsequence only if the answer is less
            // than the current answer. Using AND Short Circuiting
            if (optimalAnswer(partitionIndex, memo, source, target) + 1 < answer
                    && isSubsequence(partitionIndex + 1, endingIndex, source, target)) {
                answer = min(answer, optimalAnswer(partitionIndex, memo, source, target) + 1);
            }
        }

        // Memoize and return
        memo[endingIndex] = answer;
        return answer;
    }

    // For toCheck, passing indices of target, both included.
    bool isSubsequence(int start, int end, string toCheck, string inString) {
        int i = start;
        int j = 0;

        while (i <= end && j < inString.length()) {
            if (toCheck[i] == inString[j]) {
                i++;
            }
            j++;
        }

        return i == end + 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestWay(String source, String target) {

        // Boolean array to mark all characters of source
        boolean[] sourceChars = new boolean[26];
        for (char c : source.toCharArray()) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        for (char c : target.toCharArray()) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Optimal Answer for a given ending index. Memoizing using an Array
        int[] memo = new int[target.length()];
        Arrays.fill(memo, Integer.MAX_VALUE / 2);

        // Want to find optimal answer for the last index.
        // Case when task is not possible is already handled
        return optimalAnswer(target.length() - 1, memo, source, target);
    }

    public int optimalAnswer(int endingIndex, int[] memo, String source, String target) {

        // Base Case
        if (endingIndex == 0) {
            return 1;
        }

        // If already calculated, return
        if (memo[endingIndex] != Integer.MAX_VALUE / 2) {
            return memo[endingIndex];
        }

        // If subsequence, return 1
        if (isSubsequence(0, endingIndex, source, target)) {
            memo[endingIndex] = 1;
            return 1;
        }

        // If not subsequence, partition into two parts and find minimum
        int answer = Integer.MAX_VALUE / 2;

        for (int partitionIndex = 0; partitionIndex < endingIndex; partitionIndex++) {

            // Check for subsequence only if the answer is less
            // than the current answer. Using AND Short Circuiting
            if (optimalAnswer(partitionIndex, memo, source, target) + 1 < answer
                    && isSubsequence(partitionIndex + 1, endingIndex, source, target)) {
                answer = Math.min(answer, optimalAnswer(partitionIndex, memo, source, target) + 1);
            }
        }

        // Memoize and return
        memo[endingIndex] = answer;
        return answer;
    }

    // For to_check, passing indices of target, both included.
    public boolean isSubsequence(int start, int end, String toCheck, String inString) {
        int i = start;
        int j = 0;

        while (i <= end && j < inString.length()) {
            if (toCheck.charAt(i) == inString.charAt(j)) {
                i++;
            }
            j++;
        }

        return i == end + 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestWay(self, source: str, target: str) -> int:

        # Check if the Task is possible or not
        # Set of all characters of source. Can use a boolean array too.
        source_chars = set(source)

        # Check if all characters of target are present in source
        # If any character is not present, return -1
        for char in target:
            if char not in source_chars:
                return -1

        # Modified is_subsequence function. in_string will always be source
        # For to_check, passing indices of target, both included

        def is_subsequence(start, end):

            i = start
            j = 0

            while i <= end and j < len(source):
                if target[i] == source[j]:
                    i += 1
                j += 1

            return i == end + 1

        # Optimal Answer for a given ending index. Memoizing using a dictionary
        memo = {}

        def optimal_answer(ending_index):

            # Base case
            if ending_index == 0:
                return 1

            # If already computed, return the value
            if ending_index in memo:
                return memo[ending_index]

            # If is subsequence, return 1
            if is_subsequence(0, ending_index):
                memo[ending_index] = 1
                return 1

            # If not subsequence, partition into two parts and find minimum
            answer = float('inf')

            for partition_index in range(ending_index):

                # Check for subsequence only if the answer is less
                # than the current answer. Using AND Short Circuiting
                if (optimal_answer(partition_index) + 1 < answer and
                        is_subsequence(partition_index + 1, ending_index)):
                    answer = min(answer, optimal_answer(partition_index) + 1)

            # Memoize and return
            memo[ending_index] = answer
            return answer

        # Want to find the optimal answer for the last index.
        # Case when the task is not possible is already handled
        return optimal_answer(len(target) - 1)
```

</details>

<br>

## Approach 7: Bottom-Up Dynamic Programming [TLE]

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// For toCheck passing indices of target, both included.
bool isSubsequence(int start, int end, char * source, char * target) {

    if (end - start + 1 > strlen(source)) {
        return false;
    }

    int i = start;
    int j = 0;

    while (i <= end && j < strlen(source)) {
        if (target[i] == source[j]) {
            i++;
        }
        j++;
    }

    return i == end + 1;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int shortestWay(char * source, char * target){
    
    // Boolean array to mark all characters of source
    bool sourceChars[26] = {false};
    for (int i = 0; i < strlen(source); i++) {
        sourceChars[source[i] - 'a'] = true;
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for (int i = 0; i < strlen(target); i++) {
        if (!sourceChars[target[i] - 'a']) {
            return -1;
        }
    }

    // Optimal Answer for a given ending index. Memoizing using an Array
    int memo[strlen(target)];
    for (int i = 0; i < strlen(target); i++) {
        memo[i] = INT_MAX;
    }
    memo[0] = 1;

    for (int endingIndex = 1; endingIndex < strlen(target); endingIndex++) {
        if (isSubsequence(0, endingIndex, source, target)) {
            memo[endingIndex] = 1;
        } else {
            for (int partitionIndex = endingIndex - 1; partitionIndex >= 0; partitionIndex--) {
                if (memo[partitionIndex] != INT_MAX &&
                        isSubsequence(partitionIndex + 1, endingIndex, source, target)) {
                    memo[endingIndex] = min(memo[endingIndex], memo[partitionIndex] + 1);
                }
            }
        }
    }

    return memo[strlen(target) - 1];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestWay(string source, string target) {
        
        // Boolean array to mark all characters of source
        bool sourceChars[26] = {false};
        for (auto c : source) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        for (auto c : target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Optimal Answer for a given ending index. Memoizing using an Array
        vector <int> memo(target.length(), INT_MAX);
        memo[0] = 1;

        for (int endingIndex = 1; endingIndex < target.length(); endingIndex++) {
            if (isSubsequence(0, endingIndex, source, target)) {
                memo[endingIndex] = 1;
            } else {
                for (int partitionIndex = endingIndex - 1; partitionIndex >= 0; partitionIndex--) {
                    if (memo[partitionIndex] != INT_MAX &&
                            isSubsequence(partitionIndex + 1, endingIndex, source, target)) {
                        memo[endingIndex] = min(memo[endingIndex], memo[partitionIndex] + 1);
                    }
                }
            }
        }

        return memo[target.length() - 1];
    }

    
    // For toCheck passing indices of target, both included.
    bool isSubsequence(int start, int end, string source, string target) {

        if end - start + 1 > source.length() {
            return false;
        }

        int i = start;
        int j = 0;

        while (i <= end && j < source.length()) {
            if (target[i] == source[j]) {
                i++;
            }
            j++;
        }

        return i == end + 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestWay(String source, String target) {

        // Boolean array to mark all characters of source
        boolean[] sourceChars = new boolean[26];
        for (char c : source.toCharArray()) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        for (char c : target.toCharArray()) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Optimal Answer for a given ending index. Memoizing using an Array
        int[] memo = new int[target.length()];
        Arrays.fill(memo, Integer.MAX_VALUE);
        memo[0] = 1;

        for (int endingIndex = 1; endingIndex < target.length(); endingIndex++) {
            if (isSubsequence(0, endingIndex, source, target)) {
                memo[endingIndex] = 1;
            } else {
                for (int partitionIndex = endingIndex - 1; partitionIndex >= 0; partitionIndex--) {
                    if (memo[partitionIndex] != Integer.MAX_VALUE &&
                            isSubsequence(partitionIndex + 1, endingIndex, source, target)) {
                        memo[endingIndex] = Math.min(memo[endingIndex], memo[partitionIndex] + 1);
                    }
                }
            }
        }

        return memo[target.length() - 1];
    }

    // For to_check, passing indices of target, both included.
    public boolean isSubsequence(int start, int end, String source, String target) {
        int i = start;
        int j = 0;

        while (i <= end && j < source.length()) {
            if (target.charAt(i) == source.charAt(j)) {
                i++;
            }
            j++;
        }

        return i == end + 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestWay(self, source: str, target: str) -> int:

        # Check if the Task is possible or not
        # Set of all characters of source. Can use boolean array too.
        source_chars = set(source)

        # Check if all characters of target are present in source
        # If any character is not present, return -1
        for char in target:
            if char not in source_chars:
                return -1

        # Modified is_subsequence function. in_string will always be source
        # For to_check, passing indices of target, both included
        def is_subsequence(start, end):

            i = start
            j = 0

            while i <= end and j < len(source):
                if target[i] == source[j]:
                    i += 1
                j += 1

            return i == end + 1

        # Optimal Answer Array for each ending Index
        opt = [float('inf')] * len(target)
        opt[0] = 1

        for ending_index in range(1, len(target)):
            if is_subsequence(0, ending_index):
                opt[ending_index] = 1
            else:
                for partition_index in range(ending_index):
                    if (opt[partition_index] != float('inf') and
                            is_subsequence(partition_index + 1, ending_index)):
                        opt[ending_index] = min(
                            opt[ending_index], opt[partition_index] + 1)

        # Return Optimal Answer for last index
        return opt[-1]
```

</details>
