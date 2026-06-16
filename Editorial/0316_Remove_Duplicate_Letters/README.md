# 316. Remove Duplicate Letters

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/remove-duplicate-letters/)  
`String` `Stack` `Greedy` `Monotonic Stack`

**Problem Link:** [LeetCode 316 - Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/)

## Problem

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

### Example 1

```text
Input: s = "bcabc"
Output: "abc"
```

### Example 2

```text
Input: s = "cbacdcbc"
Output: "acdb"
```

## Constraints

- 1 <= s.length <= 104
- s consists of lowercase English letters.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Smallest K-Length Subsequence With Occurrences of a Letter](https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Lexicographically Smallest String After Deleting Duplicate Characters](https://leetcode.com/problems/lexicographically-smallest-string-after-deleting-duplicate-characters/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 316. Remove Duplicate Letters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy - Solving Letter by Letter | Java, Python |
| Greedy - Solving with Stack | Java, Python |

## Approach 1: Greedy - Solving Letter by Letter

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String removeDuplicateLetters(String s) {
        // find pos - the index of the leftmost letter in our solution
        // we create a counter and end the iteration once the suffix doesn't have each unique character
        // pos will be the index of the smallest character we encounter before the iteration ends
        int[] cnt = new int[26];
        int pos = 0;
        for (int i = 0; i < s.length(); i++) cnt[s.charAt(i) - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(pos)) pos = i;
            if (--cnt[s.charAt(i) - 'a'] == 0) break;
        }
        // our answer is the leftmost letter plus the recursive call on the remainder of the string
        // note that we have to get rid of further occurrences of s[pos] to ensure that there are no duplicates
        return s.length() == 0 ? "" : s.charAt(pos) + removeDuplicateLetters(s.substring(pos + 1).replaceAll("" + s.charAt(pos), ""));
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from collections import Counter

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:

        # find pos - the index of the leftmost letter in our solution
        # we create a counter and end the iteration once the suffix doesn't have each unique character
        # pos will be the index of the smallest character we encounter before the iteration ends
        c = Counter(s)
        pos = 0
        for i in range(len(s)):
            if s[i] < s[pos]: pos = i
            c[s[i]] -=1
            if c[s[i]] == 0: break
        # our answer is the leftmost letter plus the recursive call on the remainder of the string
        # note we have to get rid of further occurrences of s[pos] to ensure that there are no duplicates
        return s[pos] + self.removeDuplicateLetters(s[pos:].replace(s[pos], "")) if s else ''
```

</details>

<br>

## Approach 2: Greedy - Solving with Stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String removeDuplicateLetters(String s) {

        Stack<Character> stack = new Stack<>();

        // this lets us keep track of what's in our solution in O(1) time
        HashSet<Character> seen = new HashSet<>();

        // this will let us know if there are any more instances of s[i] left in s
        HashMap<Character, Integer> last_occurrence = new HashMap<>();
        for(int i = 0; i < s.length(); i++) last_occurrence.put(s.charAt(i), i);

        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            // we can only try to add c if it's not already in our solution
            // this is to maintain only one of each character
            if (!seen.contains(c)){
                // if the last letter in our solution:
                //     1. exists
                //     2. is greater than c so removing it will make the string smaller
                //     3. it's not the last occurrence
                // we remove it from the solution to keep the solution optimal
                while(!stack.isEmpty() && c < stack.peek() && last_occurrence.get(stack.peek()) > i){
                    seen.remove(stack.pop());
                }
                seen.add(c);
                stack.push(c);
            }
        }
    StringBuilder sb = new StringBuilder(stack.size());
    for (Character c : stack) sb.append(c.charValue());
    return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def removeDuplicateLetters(self, s) -> str:

        stack = []

        # this lets us keep track of what's in our solution in O(1) time
        seen = set()

        # this will let us know if there are no more instances of s[i] left in s
        last_occurrence = {c: i for i, c in enumerate(s)}


        for i, c in enumerate(s):

            # we can only try to add c if it's not already in our solution
            # this is to maintain only one of each character
            if c not in seen:
                # if the last letter in our solution:
                #    1. exists
                #    2. is greater than c so removing it will make the string smaller
                #    3. it's not the last occurrence
                # we remove it from the solution to keep the solution optimal
                while stack and c < stack[-1] and i < last_occurrence[stack[-1]]:
                    seen.discard(stack.pop())
                seen.add(c)
                stack.append(c)
        return ''.join(stack)
```

</details>
