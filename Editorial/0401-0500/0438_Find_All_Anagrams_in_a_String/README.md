# 438. Find All Anagrams in a String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-all-anagrams-in-a-string/)  
`Hash Table` `String` `Sliding Window`

**Problem Link:** [LeetCode 438 - Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## Problem

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

### Example 1

```text
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

### Example 2

```text
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
```

## Constraints

- 1 <= s.length, p.length <= 3 * 104
- s and p consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Permutation in String](https://leetcode.com/problems/permutation-in-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 438. Find All Anagrams in a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window with HashMap | Java, Python |
| Sliding Window with Array | Java, Python |

## Approach 1: Sliding Window with HashMap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public List<Integer> findAnagrams(String s, String p) {
    int ns = s.length(), np = p.length();
    if (ns < np) return new ArrayList();

    Map<Character, Integer> pCount = new HashMap();
    Map<Character, Integer> sCount = new HashMap();

    // Build a reference hashmap using string p
    for (char ch : p.toCharArray()) {
      if (pCount.containsKey(ch)) {
        pCount.put(ch, pCount.get(ch) + 1);
      }
      else {
        pCount.put(ch, 1);
      }
    }

    List<Integer> output = new ArrayList();

    // The sliding window on the string s
    for (int i = 0; i < ns; ++i) {
      // Add one more letter 
      // on the right side of the window
      char ch = s.charAt(i);
      if (sCount.containsKey(ch)) {
        sCount.put(ch, sCount.get(ch) + 1);
      }
      else {
        sCount.put(ch, 1);
      }

      // Remove one letter 
      // from the left side of the window
      if (i >= np) {
        ch = s.charAt(i - np);
        if (sCount.get(ch) == 1) {
          sCount.remove(ch);
        }
        else {
          sCount.put(ch, sCount.get(ch) - 1);
        }
      }

      // Compare hashmap in the sliding window
      // with the reference hashmap
      if (pCount.equals(sCount)) {
        output.add(i - np + 1);
      }
    }
    return output;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ns, np = len(s), len(p)
        if ns < np:
            return []

        p_count = Counter(p)
        s_count = Counter()
        
        output = []

        # sliding window on the string s
        for i in range(ns):
            # Add one more letter 
            # on the right side of the window
            s_count[s[i]] += 1

            # Remove one letter 
            # from the left side of the window
            if i >= np:
                if s_count[s[i - np]] == 1:
                    del s_count[s[i - np]]
                else:
                    s_count[s[i - np]] -= 1

            # Compare array in the sliding window
            # with the reference array
            if p_count == s_count:
                output.append(i - np + 1)
        
        return output
```

</details>

<br>

## Approach 2: Sliding Window with Array

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public List<Integer> findAnagrams(String s, String p) {
    int ns = s.length(), np = p.length();
    if (ns < np) return new ArrayList();

    int [] pCount = new int[26];
    int [] sCount = new int[26];
    // build reference array using string p
    for (char ch : p.toCharArray()) {
      pCount[(int)(ch - 'a')]++;
    }

    List<Integer> output = new ArrayList();
    // sliding window on the string s
    for (int i = 0; i < ns; ++i) {
      // add one more letter 
      // on the right side of the window
      sCount[(int)(s.charAt(i) - 'a')]++;
      // remove one letter 
      // from the left side of the window
      if (i >= np) {
        sCount[(int)(s.charAt(i - np) - 'a')]--;
      }
      // compare array in the sliding window
      // with the reference array
      if (Arrays.equals(pCount, sCount)) {
        output.add(i - np + 1);
      }
    }
    return output;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ns, np = len(s), len(p)
        if ns < np:
            return []

        p_count, s_count = [0] * 26, [0] * 26
        # build reference array using string p
        for ch in p:
            p_count[ord(ch) - ord('a')] += 1
        
        output = []
        # sliding window on the string s
        for i in range(ns):
            # add one more letter 
            # on the right side of the window
            s_count[ord(s[i]) - ord('a')] += 1
            # remove one letter 
            # from the left side of the window
            if i >= np:
                s_count[ord(s[i - np]) - ord('a')] -= 1
            # compare array in the sliding window
            # with the reference array
            if p_count == s_count:
                output.append(i - np + 1)
        
        return output
```

</details>
