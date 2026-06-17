# 318. Maximum Product of Word Lengths

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-product-of-word-lengths/)  
`Array` `String` `Bit Manipulation`

**Problem Link:** [LeetCode 318 - Maximum Product of Word Lengths](https://leetcode.com/problems/maximum-product-of-word-lengths/)

## Problem

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

### Example 1

```text
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
```

### Example 2

```text
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
```

### Example 3

```text
Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
```

## Constraints

- 2 <= words.length <= 1000
- 1 <= words[i].length <= 1000
- words[i] consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 318. Maximum Product of Word Lengths

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Optimize noCommonLetters function: Bitmasks + Precomputation | Java, Python |
| Optimise Number of Comparisons: Bitmasks + Precomputation + Hashmap | Java, Python |

## Approach 1: Optimize noCommonLetters function: Bitmasks + Precomputation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean noCommonLetters(String s1, String s2){
  for (char ch : s1.toCharArray())
    if (s2.indexOf(ch) != -1) return false;
  return true;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def no_common_letters(s1, s2):
    for ch in s1:
        if ch in s2:
            return False
    return True
```

</details>

<br>

## Approach 2: Optimise Number of Comparisons: Bitmasks + Precomputation + Hashmap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int bitNumber(char ch){
    return (int)ch - (int)'a';
  }

  public int maxProduct(String[] words) {
    Map<Integer, Integer> hashmap = new HashMap();

    int bitmask = 0, bitNum = 0;
    for (String word : words) {
      bitmask = 0;
      for (char ch : word.toCharArray()) {
        // add bit number bitNumber in bitmask
        bitmask |= 1 << bitNumber(ch);
      }
      // there could be different words with the same bitmask
      // ex. ab and aabb
      hashmap.put(bitmask, Math.max(hashmap.getOrDefault(bitmask, 0), word.length()));
    }

    int maxProd = 0;
    for (int x : hashmap.keySet())
      for (int y : hashmap.keySet())
        if ((x & y) == 0) maxProd = Math.max(maxProd, hashmap.get(x) * hashmap.get(y));

    return maxProd;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from collections import defaultdict
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        hashmap = defaultdict(int)
        bit_number = lambda ch : ord(ch) - ord('a')
        
        for word in words:
            bitmask = 0
            for ch in word:
                # add bit number bit_number in bitmask
                bitmask |= 1 << bit_number(ch)
            # there could be different words with the same bitmask
            # ex. ab and aabb
            hashmap[bitmask] = max(hashmap[bitmask], len(word))
        
        max_prod = 0
        for x in hashmap:
            for y in hashmap:
                if x & y == 0:
                    max_prod = max(max_prod, hashmap[x] * hashmap[y])
        return max_prod
```

</details>
