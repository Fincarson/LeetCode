# 2940. Find Building Where Alice and Bob Can Meet

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/)  
`Array` `Binary Search` `Stack` `Binary Indexed Tree` `Segment Tree` `Heap (Priority Queue)` `Monotonic Stack`

**Problem Link:** [LeetCode 2940 - Find Building Where Alice and Bob Can Meet](https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/)

## Problem

You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.

If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].

You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.

Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

### Example 1

```text
Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
Output: [2,5,-1,5,2]
Explanation: In the first query, Alice and Bob can move to building 2 since heights[0] < heights[2] and heights[1] < heights[2].
In the second query, Alice and Bob can move to building 5 since heights[0] < heights[5] and heights[3] < heights[5].
In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
In the fourth query, Alice and Bob can move to building 5 since heights[3] < heights[5] and heights[4] < heights[5].
In the fifth query, Alice and Bob are already in the same building.
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.
```

### Example 2

```text
Input: heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
Output: [7,6,-1,4,6]
Explanation: In the first query, Alice can directly move to Bob's building since heights[0] < heights[7].
In the second query, Alice and Bob can move to building 6 since heights[3] < heights[6] and heights[5] < heights[6].
In the third query, Alice cannot meet Bob since Bob cannot move to any other building.
In the fourth query, Alice and Bob can move to building 4 since heights[3] < heights[4] and heights[0] < heights[4].
In the fifth query, Alice can directly move to Bob's building since heights[1] < heights[6].
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.
```

## Constraints

- 1 <= heights.length <= 5 * 104
- 1 <= heights[i] <= 109
- 1 <= queries.length <= 5 * 104
- queries[i] = [ai, bi]
- 0 <= ai, bi <= heights.length - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Visible People in a Queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Furthest Building You Can Reach](https://leetcode.com/problems/furthest-building-you-can-reach/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2940. Find Building Where Alice and Bob Can Meet

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Monotonic Stack | C++, Java, Python3 |
| Priority Queue | C++, Java, Python3 |

## Approach 1: Monotonic Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<pair<int, int>> monoStack;
        vector<int> result(queries.size(), -1);
        vector<vector<pair<int, int>>> newQueries(heights.size());
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);
            if (heights[b] > heights[a] || a == b)
                result[i] = b;
            else
                newQueries[b].push_back({heights[a], i});
        }

        for (int i = heights.size() - 1; i >= 0; i--) {
            int monoStackSize = monoStack.size();
            for (auto& [a, b] : newQueries[i]) {
                int position = search(a, monoStack);
                if (position < monoStackSize && position >= 0)
                    result[b] = monoStack[position].second;
            }
            while (!monoStack.empty() && monoStack.back().first <= heights[i])
                monoStack.pop_back();
            monoStack.push_back({heights[i], i});
        }
        return result;
    }

private:
    int search(int height, vector<pair<int, int>>& monoStack) {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
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

    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        List<Pair<Integer, Integer>> monoStack = new ArrayList<>();
        int[] result = new int[queries.length];
        Arrays.fill(result, -1);
        List<List<Pair<Integer, Integer>>> newQueries = new ArrayList<>(
            heights.length
        );

        for (int i = 0; i < heights.length; i++) {
            newQueries.add(new ArrayList<>());
        }

        for (int i = 0; i < queries.length; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
            if (heights[b] > heights[a] || a == b) {
                result[i] = b;
            } else {
                newQueries.get(b).add(new Pair<>(heights[a], i));
            }
        }

        for (int i = heights.length - 1; i >= 0; i--) {
            int monoStackSize = monoStack.size();
            for (Pair<Integer, Integer> pair : newQueries.get(i)) {
                int position = search(pair.getKey(), monoStack);
                if (position < monoStackSize && position >= 0) {
                    result[pair.getValue()] = monoStack
                        .get(position)
                        .getValue();
                }
            }

            while (
                !monoStack.isEmpty() &&
                monoStack.get(monoStack.size() - 1).getKey() <= heights[i]
            ) {
                monoStack.remove(monoStack.size() - 1);
            }

            monoStack.add(new Pair<>(heights[i], i));
        }

        return result;
    }

    private int search(int height, List<Pair<Integer, Integer>> monoStack) {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack.get(mid).getKey() > height) {
                ans = Math.max(ans, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
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
    def leftmostBuildingQueries(self, heights, queries):
        mono_stack = []
        result = [-1 for _ in range(len(queries))]
        new_queries = [[] for _ in range(len(heights))]
        for i in range(len(queries)):
            a = queries[i][0]
            b = queries[i][1]
            if a > b:
                a, b = b, a
            if heights[b] > heights[a] or a == b:
                result[i] = b
            else:
                new_queries[b].append((heights[a], i))

        for i in range(len(heights) - 1, -1, -1):
            mono_stack_size = len(mono_stack)
            for a, b in new_queries[i]:
                position = self.search(a, mono_stack)
                if position < mono_stack_size and position >= 0:
                    result[b] = mono_stack[position][1]
            while mono_stack and mono_stack[-1][0] <= heights[i]:
                mono_stack.pop()
            mono_stack.append((heights[i], i))
        return result

    def search(self, height, mono_stack):
        left = 0
        right = len(mono_stack) - 1
        ans = -1
        while left <= right:
            mid = (left + right) // 2
            if mono_stack[mid][0] > height:
                ans = max(ans, mid)
                left = mid + 1
            else:
                right = mid - 1
        return ans
```

</details>

<br>

## Approach 2: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<vector<vector<int>>> storeQueries(heights.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            maxIndex;
        vector<int> result(queries.size(), -1);

        // Store the mappings for all queries in storeQueries.
        for (int currQuery = 0; currQuery < queries.size(); currQuery++) {
            int a = queries[currQuery][0], b = queries[currQuery][1];
            if (a < b && heights[a] < heights[b]) {
                result[currQuery] = b;
            } else if (a > b && heights[a] > heights[b]) {
                result[currQuery] = a;
            } else if (a == b) {
                result[currQuery] = a;
            } else {
                storeQueries[max(a, b)].push_back(
                    {max(heights[a], heights[b]), currQuery});
            }
        }

        for (int index = 0; index < heights.size(); index++) {
            // If the priority queue's minimum pair value is less than the
            // current index of height, it is an answer to the query.
            while (!maxIndex.empty() && maxIndex.top()[0] < heights[index]) {
                result[maxIndex.top()[1]] = index;
                maxIndex.pop();
            }
            // Push the with their maximum index as the current index in the
            // priority queue.
            for (auto& element : storeQueries[index]) {
                maxIndex.push(element);
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        List<List<List<Integer>>> storeQueries = new ArrayList<>(
            heights.length
        );
        for (int i = 0; i < heights.length; i++) storeQueries.add(
            new ArrayList<>()
        );
        PriorityQueue<List<Integer>> maxIndex = new PriorityQueue<>(
            (a, b) -> a.get(0) - b.get(0)
        );
        int[] result = new int[queries.length];
        Arrays.fill(result, -1);

        //Store the mappings for all queries in storeQueries.
        for (int currQuery = 0; currQuery < queries.length; currQuery++) {
            int a = queries[currQuery][0], b = queries[currQuery][1];
            if (a < b && heights[a] < heights[b]) {
                result[currQuery] = b;
            } else if (a > b && heights[a] > heights[b]) {
                result[currQuery] = a;
            } else if (a == b) {
                result[currQuery] = a;
            } else {
                storeQueries
                    .get(Math.max(a, b))
                    .add(
                        Arrays.asList(
                            Math.max(heights[a], heights[b]),
                            currQuery
                        )
                    );
            }
        }

        //If the priority queue's minimum pair value is less than the current index of height, it is an answer to the query.
        for (int index = 0; index < heights.length; index++) {
            while (
                !maxIndex.isEmpty() && maxIndex.peek().get(0) < heights[index]
            ) {
                result[maxIndex.peek().get(1)] = index;
                maxIndex.poll();
            }
            // Push the with their maximum index as the current index in the priority queue.
            for (List<Integer> element : storeQueries.get(index)) {
                maxIndex.offer(element);
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def leftmostBuildingQueries(self, heights, queries):
        max_idx = []  # Min-heap to simulate priority queue
        results = [-1] * len(queries)
        store_queries = [[] for _ in heights]

        # Store the mappings for all queries in store_queries.
        for idx, query in enumerate(queries):
            a, b = query
            if a < b and heights[a] < heights[b]:
                results[idx] = b
            elif a > b and heights[a] > heights[b]:
                results[idx] = a
            elif a == b:
                results[idx] = a
            else:
                store_queries[max(a, b)].append(
                    (max(heights[a], heights[b]), idx)
                )

        for idx, height in enumerate(heights):
            # If the heap's smallest value is less than the current height, it is an answer to the query.
            while max_idx and max_idx[0][0] < height:
                _, q_idx = heapq.heappop(max_idx)
                results[q_idx] = idx
            # Push the queries with their maximum index as the current index into the heap.
            for element in store_queries[idx]:
                heapq.heappush(max_idx, element)

        return results
```

</details>
