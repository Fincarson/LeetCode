# 1047. Remove All Adjacent Duplicates In String

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)  
`String` `Stack`

**Problem Link:** [LeetCode 1047 - Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)

## Problem

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

### Example 1

```text
Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
```

### Example 2

```text
Input: s = "azxxzy"
Output: "ay"
```

## Constraints

- 1 <= s.length <= 105
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimize String Length](https://leetcode.com/problems/minimize-string-length/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1047. Remove All Adjacent Duplicates In String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Replace | Java, Python |
| Stack | Java, Python |

## Approach 1: Replace

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public String removeDuplicates(String S) {
    // generate 26 possible duplicates
    HashSet<String> duplicates = new HashSet();
    StringBuilder sb = new StringBuilder();
    for(char i = 'a'; i <= 'z'; ++i) {
      sb.setLength(0);
      sb.append(i); sb.append(i);
      duplicates.add(sb.toString());
    }

    int prevLength = -1;
    while (prevLength != S.length()) {
      prevLength = S.length();
      for (String d : duplicates) S = S.replace(d, "");
    }

    return S;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from string import ascii_lowercase
class Solution:
    def removeDuplicates(self, S: str) -> str:
        # generate 26 possible duplicates
        duplicates = {2 * ch for ch in ascii_lowercase}
        
        prev_length = -1
        while prev_length != len(S):
            prev_length = len(S)
            for d in duplicates:
                S = S.replace(d, '')
                
        return S
```

</details>

<br>

## Approach 2: Stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public String removeDuplicates(String S) {
    StringBuilder sb = new StringBuilder();
    int sbLength = 0;
    for(char character : S.toCharArray()) {
      if (sbLength != 0 && character == sb.charAt(sbLength - 1))
        sb.deleteCharAt(sbLength-- - 1);
      else {
        sb.append(character);
        sbLength++;
      }
    }
    return sb.toString();
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def removeDuplicates(self, S: str) -> str:
        output = []
        for ch in S:
            if output and ch == output[-1]: 
                output.pop()
            else: 
                output.append(ch)
        return ''.join(output)
```

</details>
