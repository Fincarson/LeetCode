# 245. Shortest Word Distance III

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/shortest-word-distance-iii/)  
`Array` `String`

**Problem Link:** [LeetCode 245 - Shortest Word Distance III](https://leetcode.com/problems/shortest-word-distance-iii/)

## Problem

Given an array of strings wordsDict and two strings that already exist in the array word1 and word2, return the shortest distance between the occurrence of these two words in the list.

Note that word1 and word2 may be the same. It is guaranteed that they represent two individual words in the list.

### Example 1

```text
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
```

### Example 2

```text
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "makes"
Output: 3
```

## Constraints

- 1 <= wordsDict.length <= 105
- 1 <= wordsDict[i].length <= 10
- wordsDict[i] consists of lowercase English letters.
- word1 and word2 are in wordsDict.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shortest Word Distance](https://leetcode.com/problems/shortest-word-distance/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Shortest Word Distance II](https://leetcode.com/problems/shortest-word-distance-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 245. Shortest Word Distance III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java |
| Merging Lists | C++, Java |
| Two Pointer | C++, Java |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> indices1, indices2;
        // Store the indices of word1 in the list indices1 and indices of word2 in the list indices2.
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                indices1.push_back(i);
            }
            if (wordsDict[i] == word2) {
                indices2.push_back(i);
            }
        }

        // Initialize it to maximum integer as it will store the minimum distance.
        int shortestDistance = INT_MAX;
        // Iterate over the indices of word1
        for (int index : indices1) {
            // Find the next greater index in the list indices2
            int x = upper_bound(indices2.begin(), indices2.end(), index) - indices2.begin();
                         
            if (x != indices2.size()) {
                // If x is not pointing to the last iterator, find the difference between these two indices
                shortestDistance = min(shortestDistance, indices2[x] - index);
            }
            
            if (x != 0 && indices2[x - 1] != index) {
                // Find difference betwee index and indices[x - 1], if x > 0 and the indices are not the same.
                shortestDistance = min(shortestDistance, index - indices2[x - 1]);
            }
        }
        
        return shortestDistance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns the index pointing to the first element in the range [0, N - 1]
    // that is greater than value, or N if no such element is found
    int upper_bound(List<Integer> indices, int value) {
        int N = indices.size();

        int left = 0, right = N - 1;
        int index = N;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (indices.get(mid) > value) {
                index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return index;
    }

    public int shortestWordDistance(String[] wordsDict, String word1, String word2) {
        List<Integer> indices1 = new ArrayList<>();
        List<Integer> indices2 = new ArrayList<>();

        // Store the indices of word1 in the list indices1 and indices of word2 in the list indices2.
        for (int i = 0; i < wordsDict.length; i++) {
            if (wordsDict[i].equals(word1)) {
                indices1.add(i);
            }
            if (wordsDict[i].equals(word2)) {
                indices2.add(i);
            }
        }

        // Initialize it to maximum integer as it will store the minimum distance.
        int shortestDistance = Integer.MAX_VALUE;
        // Iterate over the indices of word1
        for (int index : indices1) {
            // Find the next greater index in the list indices2
            int x = upper_bound(indices2, index);

            if (x != indices2.size()) {
                // If x is not pointing to the last iterator, find the difference between these two indices
                shortestDistance = Math.min(shortestDistance, indices2.get(x) - index);
            }

            if (x != 0 && indices2.get(x - 1) != index) {
                // Find difference betwee index and indices[x - 1], if x > 0 and the indices are not the same.
                shortestDistance = Math.min(shortestDistance, index - indices2.get(x - 1));
            }
        }

        return shortestDistance;
    }
}
```

</details>

<br>

## Approach 2: Merging Lists

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<pair<int, int>> indices;
        // Store the indices of word1 or word2 and an extra integer in the pair
        // as 0 if the string is word1 or 1 if the string is word2.
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                indices.push_back({i, 0});
            }
            if (wordsDict[i] == word2) {
                indices.push_back({i, 1});
            }
        }

        // Initialize it to maximum integer as it will store the minimum distance.
        int shortestDistance = INT_MAX;
        for (int i = 0; i < indices.size() - 1; i++) {
            // If the two consecutive pairs have both different values
            if (indices[i].second != indices[i + 1].second && indices[i].first != indices[i + 1].first) {
                // Find the difference between indices and update shortestDistance
                shortestDistance = min(shortestDistance, indices[i + 1].first - indices[i].first);
            }
        }
        return shortestDistance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestWordDistance(String[] wordsDict, String word1, String word2) {
        List<Pair<Integer, Integer>> indices = new ArrayList<>();

        // Store the indices of word1 or word2 and an extra integer in the pair
        // as 0 if the string is word1 or 1 if the string is word2.
        for (int i = 0; i < wordsDict.length; i++) {
            if (wordsDict[i].equals(word1)) {
                indices.add(new Pair(i, 0));
            }
            if (wordsDict[i].equals(word2)) {
                indices.add(new Pair(i, 1));
            }
        }

        // Initialize it to maximum integer as it will store the minimum distance.
        int shortestDistance = Integer.MAX_VALUE;
        for (int i = 0; i < indices.size() - 1; i++) {
            // If the two consecutive pairs have both different values
            if (!indices.get(i).getValue().equals(indices.get(i + 1).getValue())
                    && !indices.get(i).getKey().equals(indices.get(i + 1).getKey())) {
                // Find the difference between indices and update shortestDistance
                shortestDistance = Math.min(shortestDistance, indices.get(i + 1).getKey() - indices.get(i).getKey());
            }
        }
        return shortestDistance;
    }
}
```

</details>

<br>

## Approach 3: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        // Initialize it to maximum integer as it will store the minimum distance.
        int shortestDistance = INT_MAX;
        
        // Initialize it to -1 as it's not pointing to any index yet.
        int prevIndex = -1;
        for (int i = 0; i < wordsDict.size(); i++) {
            // If the string at this index is either word1 or word2
            if (wordsDict[i] == word1 || wordsDict[i] == word2) {
                // If prevIndex is present and pointing to a different string than the string at the current index
                // Or if both word1 and word2 are the same.
                if (prevIndex != -1 && (wordsDict[prevIndex] != wordsDict[i] || word1 == word2)) {
                    shortestDistance = min(shortestDistance, i - prevIndex);
                }
                // Update the prevIndex to point it to the current index.
                prevIndex = i;
            }
        }  
        return shortestDistance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestWordDistance(String[] wordsDict, String word1, String word2) {
        // Initialize it to maximum integer as it will store the minimum distance.
        int shortestDistance = Integer.MAX_VALUE;

        // Initialize it to -1 as it's not pointing to any index yet.
        int prevIndex = -1;
        for (int i = 0; i < wordsDict.length; i++) {
            // If the string at this index is either word1 or word2
            if (wordsDict[i].equals(word1) || wordsDict[i].equals(word2)) {
                // If prevIndex is present and pointing to a different string than the string at the current index
                // Or if both word1 and word2 are the same.
                if (prevIndex != -1 && (!wordsDict[prevIndex].equals(wordsDict[i]) || word1.equals(word2))) {
                    shortestDistance = Math.min(shortestDistance, i - prevIndex);
                }
                // Update the prevIndex to point it to the current index.
                prevIndex = i;
            }
        }
        return shortestDistance;
    }
}
```

</details>
