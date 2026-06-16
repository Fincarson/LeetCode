# 870. Advantage Shuffle

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/advantage-shuffle/)  
`Array` `Two Pointers` `Greedy` `Sorting`

**Problem Link:** [LeetCode 870 - Advantage Shuffle](https://leetcode.com/problems/advantage-shuffle/)

## Problem

You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].

Return any permutation of nums1 that maximizes its advantage with respect to nums2.

### Example 1

```text
Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
Output: [2,11,7,15]
```

### Example 2

```text
Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
Output: [24,32,8,12]
```

## Constraints

- 1 <= nums1.length <= 105
- nums2.length == nums1.length
- 0 <= nums1[i], nums2[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 870. Advantage Shuffle

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | Java, Python |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        int[] sortedA = A.clone();
        Arrays.sort(sortedA);
        int[] sortedB = B.clone();
        Arrays.sort(sortedB);

        // assigned[b] = list of a that are assigned to beat b
        Map<Integer, Deque<Integer>> assigned = new HashMap();
        for (int b: B) assigned.put(b, new LinkedList());

        // remaining = list of a that are not assigned to any b
        Deque<Integer> remaining = new LinkedList();

        // populate (assigned, remaining) appropriately
        // sortedB[j] is always the smallest unassigned element in B
        int j = 0;
        for (int a: sortedA) {
            if (a > sortedB[j]) {
                assigned.get(sortedB[j++]).add(a);
            } else {
                remaining.add(a);
            }
        }

        // Reconstruct the answer from annotations (assigned, remaining)
        int[] ans = new int[B.length];
        for (int i = 0; i < B.length; ++i) {
            // if there is some a assigned to b...
            if (assigned.get(B[i]).size() > 0)
                ans[i] = assigned.get(B[i]).pop();
            else
                ans[i] = remaining.pop();
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
    def advantageCount(self, A, B):
        sortedA = sorted(A)
        sortedB = sorted(B)

        # assigned[b] = list of a that are assigned to beat b
        # remaining = list of a that are not assigned to any b
        assigned = {b: [] for b in B}
        remaining = []

        # populate (assigned, remaining) appropriately
        # sortedB[j] is always the smallest unassigned element in B
        j = 0
        for a in sortedA:
            if a > sortedB[j]:
                assigned[sortedB[j]].append(a)
                j += 1
            else:
                remaining.append(a)

        # Reconstruct the answer from annotations (assigned, remaining)
        return [assigned[b].pop() if assigned[b] else remaining.pop()
                for b in B]
```

</details>
