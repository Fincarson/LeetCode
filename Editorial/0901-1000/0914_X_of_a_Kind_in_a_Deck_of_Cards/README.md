# 914. X of a Kind in a Deck of Cards

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/)  
`Array` `Hash Table` `Math` `Counting` `Number Theory`

**Problem Link:** [LeetCode 914 - X of a Kind in a Deck of Cards](https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/)

## Problem

You are given an integer array deck where deck[i] represents the number written on the ith card.

Partition the cards into one or more groups such that:

- Each group has exactly x cards where x > 1, and
- All the cards in one group have the same integer written on them.

Return true if such partition is possible, or false otherwise.

### Example 1

```text
Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
```

### Example 2

```text
Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
```

## Constraints

- 1 <= deck.length <= 104
- 0 <= deck[i] < 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 914. X of a Kind in a Deck of Cards

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python |
| Greatest Common Divisor | Java, Python |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int N = deck.length;
        int[] count = new int[10000];
        for (int c: deck)
            count[c]++;

        List<Integer> values = new ArrayList();
        for (int i = 0; i < 10000; ++i)
            if (count[i] > 0)
                values.add(count[i]);

        search: for (int X = 2; X <= N; ++X)
            if (N % X == 0) {
                for (int v: values)
                    if (v % X != 0)
                        continue search;
                return true;
            }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def hasGroupsSizeX(self, deck):
        count = collections.Counter(deck)
        N = len(deck)
        for X in xrange(2, N+1):
            if N % X == 0:
                if all(v % X == 0 for v in count.values()):
                    return True
        return False
```

</details>

<br>

## Approach 2: Greatest Common Divisor

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] count = new int[10000];
        for (int c: deck)
            count[c]++;

        int g = -1;
        for (int i = 0; i < 10000; ++i)
            if (count[i] > 0) {
                if (g == -1)
                    g = count[i];
                else
                    g = gcd(g, count[i]);
            }

        return g >= 2;
    }

    public int gcd(int x, int y) {
        return x == 0 ? y : gcd(y%x, x);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def hasGroupsSizeX(self, deck):
        from fractions import gcd
        vals = collections.Counter(deck).values()
        return reduce(gcd, vals) >= 2
```

</details>
