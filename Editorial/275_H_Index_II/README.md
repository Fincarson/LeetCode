# 275. H-Index II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/h-index-ii/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 275 - H-Index II](https://leetcode.com/problems/h-index-ii/)

## Problem

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in non-descending order, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

You must write an algorithm that runs in logarithmic time.

### Example 1

```text
Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
```

### Example 2

```text
Input: citations = [1,2,100]
Output: 2
```

## Constraints

- n == citations.length
- 1 <= n <= 105
- 0 <= citations[i] <= 1000
- citations is sorted in ascending order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [H-Index](https://leetcode.com/problems/h-index/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 275. H-Index II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear search, O(k) time | Java, Python |
| Binary Search, O(log N) time | Java, Python |

## Approach 1: Linear search, O(k) time

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int idx = 0;
        for (int c : citations) {
            if (c >= n - idx)
                return n - idx;
            else
                idx++;
        }
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        for idx, c in enumerate(citations):
            if c >= n - idx:
                return n - idx
        return 0
```

</details>

<br>

## Approach 2: Binary Search, O(log N) time

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int left = 0, right = n - 1;

        // We need to find the rightmost 'index' such that: (citations[index] <= n - index)
        while (left <= right) {
            int mid = left + (right - left) / 2;

            //There are (n - mid) papers with an equal or higher citation count than citations[mid]
            // If (citations[mid] == n - mid) it's the optimal result and can be returned right away
            if (citations[mid] == n - mid)
                return citations[mid];

            // If citations[mid] are less than (n - mid), narrow down on the right half to look for a paper
            // at a future index that meets the h-index criteria. Otherwise, narrow down on the left half
            if (citations[mid] < n - mid)
                left = mid + 1;
            else
                right = mid - 1;
        }

        // We didn't find an exact match, so there are exactly (n - left) papers that have citations
        // greater than or equal to citations[left] and that is our answer
        return n - left;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        left, right = 0, n - 1

        # We need to find the rightmost 'index' such that: (citations[index] <= n - index)
        while left <= right:
            mid = left + (right - left) // 2

            # There are (n - mid) papers with an equal or higher citation count than citations[mid]
            # If (citations[mid] == n - mid) it's the optimal result and can be returned right away
            if citations[mid] == n - mid:
                return n - mid

            # If citations[mid] are less than (n - mid), narrow down on the right half to look for a paper
            # at a future index that meets the h-index criteria. Otherwise, narrow down on the left half
            if citations[mid] < n - mid:
                left = mid + 1
            else:
                right = mid - 1

        # We didn't find an exact match, so there are exactly (n - left) papers that have citations
        # greater than or equal to citations[left] and that is our answer
        return n - left
```

</details>
