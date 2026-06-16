# 1101. The Earliest Moment When Everyone Become Friends

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/)  
`Array` `Union-Find` `Sorting`

**Problem Link:** [LeetCode 1101 - The Earliest Moment When Everyone Become Friends](https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/)

## Problem

There are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.

Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.

### Example 1

```text
Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
Output: 20190301
Explanation:
The first event occurs at timestamp = 20190101, and after 0 and 1 become friends, we have the following friendship groups [0,1], [2], [3], [4], [5].
The second event occurs at timestamp = 20190104, and after 3 and 4 become friends, we have the following friendship groups [0,1], [2], [3,4], [5].
The third event occurs at timestamp = 20190107, and after 2 and 3 become friends, we have the following friendship groups [0,1], [2,3,4], [5].
The fourth event occurs at timestamp = 20190211, and after 1 and 5 become friends, we have the following friendship groups [0,1,5], [2,3,4].
The fifth event occurs at timestamp = 20190224, and as 2 and 4 are already friends, nothing happens.
The sixth event occurs at timestamp = 20190301, and after 0 and 3 become friends, we all become friends.
```

### Example 2

```text
Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
Output: 3
Explanation: At timestamp = 3, all the persons (i.e., 0, 1, 2, and 3) become friends.
```

## Constraints

- 2 <= n <= 100
- 1 <= logs.length <= 104
- logs[i].length == 3
- 0 <= timestampi <= 109
- 0 <= xi, yi <= n - 1
- xi != yi
- All the values timestampi are unique.
- All the pairs (xi, yi) occur at most one time in the input.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1101. The Earliest Moment When Everyone Become Friends

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Union-Find (Disjoint-Set) | Java, Python3 |

## Approach: Union-Find (Disjoint-Set)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int earliestAcq(int[][] logs, int n) {
        // In order to ensure that we find the _earliest_ moment,
        //  first of all we need to sort the events in chronological order.
        Arrays.sort(logs, new Comparator<int[]>() {
            @Override
            public int compare(int[] log1, int[] log2) {
                Integer tsp1 = new Integer(log1[0]);
                Integer tsp2 = new Integer(log2[0]);
                return tsp1.compareTo(tsp2);
            }
        });

        // Initially, we treat each individual as a separate group.
        int groupCount = n;
        UnionFind uf = new UnionFind(n);

        for (int[] log : logs) {
            int timestamp = log[0];
            int friendA = log[1];
            int friendB = log[2];
            // We merge the groups along the way.
            if (uf.union(friendA, friendB)) {
                groupCount -= 1;
            }

            // The moment when all individuals are connected to each other.
            if (groupCount == 1) {
                return timestamp;
            }
        }

        // There are still more than one groups left,
        //  i.e. not everyone is connected.
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        # In order to ensure that we find the _earliest_ moment,
        #  first of all we need to sort the events in chronological order.
        logs.sort(key = lambda x: x[0])

        uf = UnionFind(n)
        # Initially, we treat each individual as a separate group.
        group_cnt = n

        # We merge the groups along the way.
        for timestamp, friend_a, friend_b in logs:
            if uf.union(friend_a, friend_b):
                group_cnt -= 1

            # The moment when all individuals are connected to each other.
            if group_cnt == 1:
                return timestamp

        # There are still more than one groups left,
        #  i.e. not everyone is connected.
        return -1
```

</details>
