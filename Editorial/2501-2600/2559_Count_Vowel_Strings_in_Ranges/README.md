# 2559. Count Vowel Strings in Ranges

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-vowel-strings-in-ranges/)  
`Array` `String` `Prefix Sum`

**Problem Link:** [LeetCode 2559 - Count Vowel Strings in Ranges](https://leetcode.com/problems/count-vowel-strings-in-ranges/)

## Problem

You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present at the indices ranging from li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

### Example 1

```text
Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].
```

### Example 2

```text
Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].
```

## Constraints

- 1 <= words.length <= 105
- 1 <= words[i].length <= 40
- words[i] consists only of lowercase English letters.
- sum(words[i].length) <= 3 * 105
- 1 <= queries.length <= 105
- 0 <= li <= ri < words.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Jump Game VII](https://leetcode.com/problems/jump-game-vii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2559. Count Vowel Strings in Ranges

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Sum | C++, Java, Python3 |

## Approach: Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        vector<int> prefixSum(words.size());
        int sum = 0;
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            if (vowels.count(currentWord[0]) &&
                vowels.count(currentWord[currentWord.size() - 1])) {
                sum++;
            }
            prefixSum[i] = sum;
        }

        for (int i = 0; i < queries.size(); i++) {
            vector<int> currentQuery = queries[i];
            ans[i] =
                prefixSum[currentQuery[1]] -
                (currentQuery[0] == 0 ? 0 : prefixSum[currentQuery[0] - 1]);
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

    public int[] vowelStrings(String[] words, int[][] queries) {
        int[] ans = new int[queries.length];
        HashSet<Character> vowels = new HashSet<>(
            Arrays.asList('a', 'e', 'i', 'o', 'u')
        );
        int[] prefixSum = new int[words.length];
        int sum = 0;
        for (int i = 0; i < words.length; i++) {
            String currentWord = words[i];
            if (
                vowels.contains(currentWord.charAt(0)) &&
                vowels.contains(currentWord.charAt(currentWord.length() - 1))
            ) {
                sum++;
            }
            prefixSum[i] = sum;
        }

        for (int i = 0; i < queries.length; i++) {
            int[] currentQuery = queries[i];
            ans[i] =
                prefixSum[currentQuery[1]] -
                (currentQuery[0] == 0 ? 0 : prefixSum[currentQuery[0] - 1]);
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def vowelStrings(
        self, words: List[str], queries: List[List[int]]
    ) -> List[int]:
        ans = [0] * len(queries)
        vowels = {"a", "e", "i", "o", "u"}
        prefix_sum = [0] * len(words)
        sum = 0
        for i in range(len(words)):
            current_word = words[i]
            if (
                current_word[0] in vowels
                and current_word[len(current_word) - 1] in vowels
            ):
                sum += 1
            prefix_sum[i] = sum

        for i in range(len(queries)):
            current_query = queries[i]
            ans[i] = prefix_sum[current_query[1]] - (
                0 if current_query[0] == 0 else prefix_sum[current_query[0] - 1]
            )

        return ans
```

</details>
