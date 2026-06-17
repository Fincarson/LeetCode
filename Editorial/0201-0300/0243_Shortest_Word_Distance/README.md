# 243. Shortest Word Distance

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/shortest-word-distance/)  
`Array` `String`

**Problem Link:** [LeetCode 243 - Shortest Word Distance](https://leetcode.com/problems/shortest-word-distance/)

## Problem

Given an array of strings wordsDict and two different strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

### Example 1

```text
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
Output: 3
```

### Example 2

```text
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
```

## Constraints

- 2 <= wordsDict.length <= 3 * 104
- 1 <= wordsDict[i].length <= 10
- wordsDict[i] consists of lowercase English letters.
- word1 and word2 are in wordsDict.
- word1 != word2

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shortest Word Distance II](https://leetcode.com/problems/shortest-word-distance-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Shortest Word Distance III](https://leetcode.com/problems/shortest-word-distance-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find All K-Distant Indices in an Array](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 243. Shortest Word Distance

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Brute Force) | Java |
| Approach #2 (One-pass) | Java |

## Approach #1 (Brute Force)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int minDistance = words.length;
        for (int i = 0; i < words.length; i++) {
            if (words[i].equals(word1)) {
                for (int j = 0; j < words.length; j++) {
                    if (words[j].equals(word2)) {
                        minDistance = Math.min(minDistance, Math.abs(i - j));
                    }
                }
            }
        }
        return minDistance;
    }
}
```

</details>

<br>

## Approach #2 (One-pass)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int i1 = -1, i2 = -1;
        int minDistance = words.length;
        for (int i = 0; i < words.length; i++) {
            if (words[i].equals(word1)) {
                i1 = i;
            } else if (words[i].equals(word2)) {
                i2 = i;
            }

            if (i1 != -1 && i2 != -1) {
                minDistance = Math.min(minDistance, Math.abs(i1 - i2));
            }
        }
        return minDistance;
    }
}
```

</details>
