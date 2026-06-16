# 2070. Most Beautiful Item for Each Query

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/most-beautiful-item-for-each-query/)  
`Array` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 2070 - Most Beautiful Item for Each Query](https://leetcode.com/problems/most-beautiful-item-for-each-query/)

## Problem

You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.

You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.

Return an array answer of the same length as queries where answer[j] is the answer to the jth query.

### Example 1

```text
Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
Output: [2,4,5,5,6,6]
Explanation:
- For queries[0]=1, [1,2] is the only item which has price <= 1. Hence, the answer for this query is 2.
- For queries[1]=2, the items which can be considered are [1,2] and [2,4].
  The maximum beauty among them is 4.
- For queries[2]=3 and queries[3]=4, the items which can be considered are [1,2], [3,2], [2,4], and [3,5].
  The maximum beauty among them is 5.
- For queries[4]=5 and queries[5]=6, all items can be considered.
  Hence, the answer for them is the maximum beauty of all items, i.e., 6.
```

### Example 2

```text
Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
Output: [4]
Explanation:
The price of every item is equal to 1, so we choose the item with the maximum beauty 4.
Note that multiple items can have the same price and/or beauty.
```

### Example 3

```text
Input: items = [[10,1000]], queries = [5]
Output: [0]
Explanation:
No item has a price less than or equal to 5, so no item can be chosen.
Hence, the answer to the query is 0.
```

## Constraints

- 1 <= items.length, queries.length <= 105
- items[i].length == 2
- 1 <= pricei, beautyi, queries[j] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Closest Room](https://leetcode.com/problems/closest-room/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find the Score of All Prefixes of an Array](https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Sum Queries](https://leetcode.com/problems/maximum-sum-queries/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2070. Most Beautiful Item for Each Query

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting Items + Binary Search | C++, Java, Python3 |
| Sorting Items + Sorting Queries | C++, Java, Python3 |

## Approach 1: Sorting Items + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        vector<int> ans(queries.size());

        // Sort and store max beauty
        sort(items.begin(), items.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int maxBeauty = items[0][1];
        for (int i = 0; i < items.size(); i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        for (int i = 0; i < queries.size(); i++) {
            // answer i-th query
            ans[i] = binarySearch(items, queries[i]);
        }

        return ans;
    }

    int binarySearch(vector<vector<int>>& items, int targetPrice) {
        int left = 0;
        int right = items.size() - 1;
        int maxBeauty = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (items[mid][0] > targetPrice) {
                right = mid - 1;
            } else {
                // Found viable price. Keep moving to right
                maxBeauty = max(maxBeauty, items[mid][1]);
                left = mid + 1;
            }
        }
        return maxBeauty;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] maximumBeauty(int[][] items, int[] queries) {
        int[] ans = new int[queries.length];

        // Sort and store max beauty
        Arrays.sort(items, (a, b) -> a[0] - b[0]);
        int max = items[0][1];
        for (int i = 0; i < items.length; i++) {
            max = Math.max(max, items[i][1]);
            items[i][1] = max;
        }

        for (int i = 0; i < queries.length; i++) {
            // answer i-th query
            ans[i] = binarySearch(items, queries[i]);
        }

        return ans;
    }

    private int binarySearch(int[][] items, int targetPrice) {
        int l = 0;
        int r = items.length - 1;
        int maxBeauty = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (items[mid][0] > targetPrice) {
                r = mid - 1;
            } else {
                // Found viable price. Keep moving to right
                maxBeauty = Math.max(maxBeauty, items[mid][1]);
                l = mid + 1;
            }
        }
        return maxBeauty;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumBeauty(
        self, items: List[List[int]], queries: List[int]
    ) -> List[int]:
        # Sort and store max beauty
        items.sort(key=lambda x: x[0])

        max_beauty = items[0][1]
        for i in range(len(items)):
            max_beauty = max(max_beauty, items[i][1])
            items[i][1] = max_beauty

        return [self.binary_search(items, q) for q in queries]

    def binary_search(self, items, target_price):
        left, right = 0, len(items) - 1
        max_beauty = 0
        while left <= right:
            mid = (left + right) // 2
            if items[mid][0] > target_price:
                right = mid - 1
            else:
                # Found viable price. Keep moving to right
                max_beauty = max(max_beauty, items[mid][1])
                left = mid + 1
        return max_beauty
```

</details>

<br>

## Approach 2: Sorting Items + Sorting Queries

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        vector<int> ans(queries.size());
        // sort both items and queries in ascending order
        sort(items.begin(), items.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> queriesWithIndices(queries.size(), vector<int>(2));

        for (int i = 0; i < queries.size(); i++) {
            queriesWithIndices[i][0] = queries[i];
            queriesWithIndices[i][1] = i;
        }

        sort(queriesWithIndices.begin(), queriesWithIndices.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int itemIndex = 0;
        int maxBeauty = 0;

        for (int i = 0; i < queries.size(); i++) {
            int query = queriesWithIndices[i][0];
            int originalIndex = queriesWithIndices[i][1];

            while (itemIndex < items.size() && items[itemIndex][0] <= query) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }

            ans[originalIndex] = maxBeauty;
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] maximumBeauty(int[][] items, int[] queries) {
        int[] ans = new int[queries.length];

        // sort both items and queries in ascending order
        Arrays.sort(items, (a, b) -> a[0] - b[0]);

        int[][] queriesWithIndices = new int[queries.length][2];
        for (int i = 0; i < queries.length; i++) {
            queriesWithIndices[i][0] = queries[i];
            queriesWithIndices[i][1] = i;
        }

        Arrays.sort(queriesWithIndices, (a, b) -> a[0] - b[0]);

        int itemIndex = 0;
        int maxBeauty = 0;

        for (int i = 0; i < queries.length; i++) {
            int query = queriesWithIndices[i][0];
            int originalIndex = queriesWithIndices[i][1];

            while (itemIndex < items.length && items[itemIndex][0] <= query) {
                maxBeauty = Math.max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }

            ans[originalIndex] = maxBeauty;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumBeauty(self, items, queries):
        ans = [0] * len(queries)

        # sort both items and queries in ascending order
        items.sort(key=lambda x: x[0])

        queries_with_indices = [[queries[i], i] for i in range(len(queries))]

        queries_with_indices.sort(key=lambda x: x[0])

        item_index = 0
        max_beauty = 0

        for i in range(len(queries)):
            query = queries_with_indices[i][0]
            original_index = queries_with_indices[i][1]

            while item_index < len(items) and items[item_index][0] <= query:
                max_beauty = max(max_beauty, items[item_index][1])
                item_index += 1

            ans[original_index] = max_beauty

        return ans
```

</details>
