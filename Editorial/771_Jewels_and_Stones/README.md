# 771. Jewels and Stones

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/jewels-and-stones/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 771 - Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/)

## Problem

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

### Example 1

```text
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
```

### Example 2

```text
Input: jewels = "z", stones = "ZZ"
Output: 0
```

## Constraints

- 1 <= jewels.length, stones.length <= 50
- jewels and stones consist of only English letters.
- All the characters of jewels are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 771. Jewels and Stones

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force [Accepted] | Java, Python |
| Approach #2: Hash Set [Accepted] | Java, Python |

## Approach #1: Brute Force [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        int ans = 0;
        for (char s: S.toCharArray()) // For each stone...
            for (char j: J.toCharArray()) // For each jewel...
                if (j == s) {  // If the stone is a jewel...
                    ans++;
                    break; // Stop searching whether this stone 's' is a jewel
                }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def numJewelsInStones(self, J, S):
        return sum(s in J for s in S)
```

</details>

<br>

## Approach #2: Hash Set [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        Set<Character> Jset = new HashSet();
        for (char j: J.toCharArray())
            Jset.add(j);

        int ans = 0;
        for (char s: S.toCharArray())
            if (Jset.contains(s))
                ans++;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def numJewelsInStones(self, J, S):
        Jset = set(J)
        return sum(s in Jset for s in S)
```

</details>
