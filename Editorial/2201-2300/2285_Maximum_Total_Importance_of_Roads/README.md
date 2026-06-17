# 2285. Maximum Total Importance of Roads

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-total-importance-of-roads/)  
`Greedy` `Graph Theory` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 2285 - Maximum Total Importance of Roads](https://leetcode.com/problems/maximum-total-importance-of-roads/)

## Problem

You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.

You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.

Return the maximum total importance of all roads possible after assigning the values optimally.

### Example 1

```text
Input: n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
Output: 43
Explanation: The figure above shows the country and the assigned values of [2,4,5,3,1].
- The road (0,1) has an importance of 2 + 4 = 6.
- The road (1,2) has an importance of 4 + 5 = 9.
- The road (2,3) has an importance of 5 + 3 = 8.
- The road (0,2) has an importance of 2 + 5 = 7.
- The road (1,3) has an importance of 4 + 3 = 7.
- The road (2,4) has an importance of 5 + 1 = 6.
The total importance of all roads is 6 + 9 + 8 + 7 + 7 + 6 = 43.
It can be shown that we cannot obtain a greater total importance than 43.
```

### Example 2

```text
Input: n = 5, roads = [[0,3],[2,4],[1,3]]
Output: 20
Explanation: The figure above shows the country and the assigned values of [4,3,2,5,1].
- The road (0,3) has an importance of 4 + 5 = 9.
- The road (2,4) has an importance of 2 + 1 = 3.
- The road (1,3) has an importance of 3 + 5 = 8.
The total importance of all roads is 9 + 3 + 8 = 20.
It can be shown that we cannot obtain a greater total importance than 20.
```

## Constraints

- 2 <= n <= 5 * 104
- 1 <= roads.length <= 5 * 104
- roads[i].length == 2
- 0 <= ai, bi <= n - 1
- ai != bi
- There are no duplicate roads.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2285. Maximum Total Importance of Roads

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting | C++, Java, Python3 |

## Approach: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);

        for (vector<int>& edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        sort(degree.begin(), degree.end());

        long long value = 1;
        long long totalImportance = 0;
        for (long long d : degree) {
            totalImportance += (value * d);
            value++;
        }

        return totalImportance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maximumImportance(int n, int[][] roads) {
        long[] degree = new long[n];

        for (int[] edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        Arrays.sort(degree);

        long value = 1;
        long totalImportance = 0;
        for (long d : degree) {
            totalImportance += (value * d);
            value++;
        }

        return totalImportance;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        degree = [0] * n

        for edge in roads:
            degree[edge[0]] += 1
            degree[edge[1]] += 1

        degree.sort()

        value = 1
        total_importance = 0
        for d in degree:
            total_importance += value * d
            value += 1

        return total_importance
```

</details>
