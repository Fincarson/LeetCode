# 274. H-Index

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/h-index/)  
`Array` `Sorting` `Counting Sort`

**Problem Link:** [LeetCode 274 - H-Index](https://leetcode.com/problems/h-index/)

## Problem

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

### Example 1

```text
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
```

### Example 2

```text
Input: citations = [1,3,1]
Output: 1
```

## Constraints

- n == citations.length
- 1 <= n <= 5000
- 0 <= citations[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [H-Index II](https://leetcode.com/problems/h-index-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 274. H-Index

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Sorting) [Accepted] | Java |
| Approach #2 (Counting) [Accepted] | Java |

## Approach #1 (Sorting) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int hIndex(int[] citations) {
        // sorting the citations in ascending order
        Arrays.sort(citations);
        // finding h-index by linear search
        int i = 0;
        while (i < citations.length && citations[citations.length - 1 - i] > i) {
            i++;
        }
        return i; // after the while loop, i = i' + 1
    }
}
```

</details>

<br>

## Approach #2 (Counting) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int[] papers = new int[n + 1];
        // counting papers for each citation number
        for (int c: citations)
            papers[Math.min(n, c)]++;
        // finding the h-index
        int k = n;
        for (int s = papers[n]; k > s; s += papers[k])
            k--;
        return k;
    }
}
```

</details>
