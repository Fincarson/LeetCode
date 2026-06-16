# 916. Word Subsets

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/word-subsets/)  
`Array` `Hash Table` `String`

**Problem Link:** [LeetCode 916 - Word Subsets](https://leetcode.com/problems/word-subsets/)

## Problem

You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

- For example, "wrr" is a subset of "warrior" but is not a subset of "world".

A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= words1.length, words2.length <= 104
- 1 <= words1[i].length, words2[i].length <= 10
- words1[i] and words2[i] consist only of lowercase English letters.
- All the strings of words1 are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 916. Word Subsets

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Reduce to Single Word in B | C++, Java, Python3 |

## Approach: Reduce to Single Word in B

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> bmax = count("");
        for (const string& b : words2) {
            vector<int> bCount = count(b);
            for (int i = 0; i < 26; ++i) {
                bmax[i] = max(bmax[i], bCount[i]);
            }
        }

        vector<string> ans;
        for (const string& a : words1) {
            vector<int> aCount = count(a);
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (aCount[i] < bmax[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                ans.push_back(a);
            }
        }

        return ans;
    }

private:
    vector<int> count(const string& S) {
        vector<int> ans(26, 0);
        for (char c : S) {
            ans[c - 'a']++;
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] bmax = count("");
        for (String b : words2) {
            int[] bCount = count(b);
            for (int i = 0; i < 26; ++i) bmax[i] = Math.max(bmax[i], bCount[i]);
        }

        List<String> ans = new ArrayList();
        search: for (String a : words1) {
            int[] aCount = count(a);
            for (int i = 0; i < 26; ++i) if (
                aCount[i] < bmax[i]
            ) continue search;
            ans.add(a);
        }

        return ans;
    }

    public int[] count(String S) {
        int[] ans = new int[26];
        for (char c : S.toCharArray()) ans[c - 'a']++;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        def count(word):
            ans = [0] * 26
            for letter in word:
                ans[ord(letter) - ord("a")] += 1
            return ans

        bmax = [0] * 26
        for b in words2:
            for i, c in enumerate(count(b)):
                bmax[i] = max(bmax[i], c)
        ans = []
        for a in words1:
            if all(x >= y for x, y in zip(count(a), bmax)):
                ans.append(a)
        return ans
```

</details>
