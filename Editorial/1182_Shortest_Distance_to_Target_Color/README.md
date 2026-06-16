# 1182. Shortest Distance to Target Color

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/shortest-distance-to-target-color/)  
`Array` `Binary Search` `Dynamic Programming`

**Problem Link:** [LeetCode 1182 - Shortest Distance to Target Color](https://leetcode.com/problems/shortest-distance-to-target-color/)

## Problem

You are given an array colors, in which there are three colors: 1, 2 and 3.

You are also given some queries. Each query consists of two integers i and c, return the shortest distance between the given index i and the target color c. If there is no solution return -1.

### Example 1

```text
Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
Output: [3,0,3]
Explanation:
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).
```

### Example 2

```text
Input: colors = [1,2], queries = [[0,3]]
Output: [-1]
Explanation: There is no 3 in the array.
```

## Constraints

- 1 <= colors.length <= 5*10^4
- 1 <= colors[i] <= 3
- 1 <= queries.length <= 5*10^4
- queries[i].length == 2
- 0 <= queries[i][0] < colors.length
- 1 <= queries[i][1] <= 3

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1182. Shortest Distance to Target Color

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | Java, Python3 |
| Pre-computed | Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> shortestDistanceColor(int[] colors, int[][] queries) {
        // initialization
        List<Integer> queryResults = new ArrayList<>();
        Map<Integer, List<Integer>> hashmap = new HashMap<>();

        for (int i = 0; i < colors.length; i++) {
            hashmap.putIfAbsent(colors[i], new ArrayList<Integer>());
            hashmap.get(colors[i]).add(i);
        }

        // for each query, apply binary search
        for (int i = 0; i < queries.length; i++) {
            int target = queries[i][0], color = queries[i][1];
            if (!hashmap.containsKey(color)) {
                queryResults.add(-1);
                continue;
            }

            List<Integer> indexList = hashmap.get(color);
            int insert = Collections.binarySearch(indexList, target);

            // due to its nature, we need to convert the returning values
            // from Collections.binarySearch
            // more details: https://docs.oracle.com/en/java/javase/12/docs/api/java.base/java/util/Collections.html#binarySearch(java.util.List,T)
            if (insert < 0) {
                insert = (insert + 1) * -1;
            }

            // Handling cases when:
            // - the target index is smaller than all elements in the indexList
            // - the target index is larger than all elements in the indexList
            // - the target index sits between the left and right boundaries
            if (insert == 0) {
                queryResults.add(indexList.get(insert) - target);
            } else if (insert == indexList.size()) {
                queryResults.add(target - indexList.get(insert - 1));
            } else {
                int leftNearest = target - indexList.get(insert - 1);
                int rightNearest = indexList.get(insert) - target;
                queryResults.add(Math.min(leftNearest, rightNearest));
            }

        }
        return queryResults;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        hashmap = collections.defaultdict(list)
        for i,c in enumerate(colors):
            hashmap[c].append(i)

        query_results = []
        for i, (target, color) in enumerate(queries):
            if color not in hashmap:
                query_results.append(-1)
                continue

            index_list = hashmap[color]
            # use bisect from Python standard library
            # more details: https://docs.python.org/3/library/bisect.html
            insert = bisect.bisect_left(index_list, target)

            # compare the index on the left and right of insert
            # make sure it will not fall out of the index_list
            left_nearest = abs(index_list[max(insert - 1, 0)] - target)
            right_nearest = abs(index_list[min(insert, len(index_list) - 1)] - target)
            query_results.append(min(left_nearest, right_nearest))

        return query_results
```

</details>

<br>

## Approach 2: Pre-computed

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> shortestDistanceColor(int[] colors, int[][] queries) {
        // initializations
        int n = colors.length;
        int[] rightmost = {0, 0, 0};
        int[] leftmost = {n - 1, n - 1, n - 1};

        int[][] distance = new int[3][n];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                distance[i][j] = -1;
            }
        }

        // looking forward
        for (int i = 0; i < n; i++) {
            int color = colors[i] - 1;
            for (int j = rightmost[color]; j < i + 1; j++) {
                distance[color][j] = i - j;
            }
            rightmost[color] = i + 1;
        }

        // looking backward
        for (int i = n - 1; i > -1; i--) {
            int color = colors[i] - 1;
            for (int j = leftmost[color]; j > i - 1; j--) {
                if (distance[color][j] == -1 || distance[color][j] > j - i) {
                    distance[color][j] = j - i;
                }
            }
            leftmost[color] = i - 1;
        }

        List<Integer> queryResults = new ArrayList<>();
        for (int i = 0; i < queries.length; i++) {
            queryResults.add(distance[queries[i][1] - 1][queries[i][0]]);
        }
        return queryResults;

    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        # initializations
        n = len(colors)
        rightmost = [0, 0, 0]
        leftmost = [n - 1, n - 1, n - 1]

        distance = [[-1] * n for _ in range(3)]

        # looking forward
        for i in range(n):
            color = colors[i] - 1
            for j in range(rightmost[color], i + 1):
                distance[color][j] = i - j
            rightmost[color] = i + 1

        # looking backward
        for i in range(n - 1, -1, -1):
            color = colors[i] - 1
            for j in range(leftmost[color], i - 1, -1):
                # if the we did not find a target color on its right
                # or we find out that a target color on its left is
                # closer to the one on its right
                if distance[color][j] == -1 or distance[color][j] > j - i:
                    distance[color][j] = j - i
            leftmost[color] = i - 1

        return [distance[color - 1][index] for index,color in queries]
```

</details>
