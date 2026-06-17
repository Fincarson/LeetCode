# 632. Smallest Range Covering Elements from K Lists

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)  
`Array` `Hash Table` `Greedy` `Sliding Window` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 632 - Smallest Range Covering Elements from K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)

## Problem

You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

### Example 1

```text
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
```

### Example 2

```text
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
```

## Constraints

- nums.length == k
- 1 <= k <= 3500
- 1 <= nums[i].length <= 50
- -105 <= nums[i][j] <= 105
- nums[i] is sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 632. Smallest Range Covering Elements from K Lists

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Optimal Brute Force | C++, Java, Python3 |
| Priority Queue (Heap) | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |

## Approach 1: Optimal Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        // Stores the current index of each list
        vector<int> indices(k, 0);
        // To track the smallest range
        vector<int> range = {0, INT_MAX};

        while (true) {
            int curMin = INT_MAX, curMax = INT_MIN, minListIndex = 0;

            // Find the current minimum and maximum values across the lists
            for (int i = 0; i < k; i++) {
                int currentElement = nums[i][indices[i]];

                // Update the current minimum
                if (currentElement < curMin) {
                    curMin = currentElement;
                    minListIndex = i;
                }

                // Update the current maximum
                if (currentElement > curMax) {
                    curMax = currentElement;
                }
            }

            // Update the range if a smaller one is found
            if (curMax - curMin < range[1] - range[0]) {
                range[0] = curMin;
                range[1] = curMax;
            }

            // Move to the next element in the list that had the minimum value
            if (++indices[minListIndex] == nums[minListIndex].size()) break;
        }

        return range;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] smallestRange(List<List<Integer>> nums) {
        int k = nums.size();
        // Stores the current index of each list
        int[] indices = new int[k];
        // To track the smallest range
        int[] range = new int[] { 0, Integer.MAX_VALUE };

        while (true) {
            int curMin = Integer.MAX_VALUE, curMax =
                Integer.MIN_VALUE, minListIndex = 0;

            // Find the current minimum and maximum values across the lists
            for (int i = 0; i < k; i++) {
                int currentElement = nums.get(i).get(indices[i]);

                // Update the current minimum
                if (currentElement < curMin) {
                    curMin = currentElement;
                    minListIndex = i;
                }

                // Update the current maximum
                if (currentElement > curMax) {
                    curMax = currentElement;
                }
            }

            // Update the range if a smaller one is found
            if (curMax - curMin < range[1] - range[0]) {
                range[0] = curMin;
                range[1] = curMax;
            }

            // Move to the next element in the list that had the minimum value
            if (++indices[minListIndex] == nums.get(minListIndex).size()) break;
        }

        return range;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        k = len(nums)
        # Stores the current index of each list
        indices = [0] * k
        # To track the smallest range
        range_list = [0, float("inf")]

        while True:
            cur_min, cur_max = float("inf"), float("-inf")
            min_list_index = 0

            # Find the current minimum and maximum values across the lists
            for i in range(k):
                current_element = nums[i][indices[i]]

                # Update the current minimum
                if current_element < cur_min:
                    cur_min = current_element
                    min_list_index = i

                # Update the current maximum
                if current_element > cur_max:
                    cur_max = current_element

            # Update the range if a smaller one is found
            if cur_max - cur_min < range_list[1] - range_list[0]:
                range_list[0] = cur_min
                range_list[1] = cur_max

            # Move to the next element in the list that had the minimum value
            indices[min_list_index] += 1
            if indices[min_list_index] == len(nums[min_list_index]):
                break

        return range_list
```

</details>

<br>

## Approach 2: Priority Queue (Heap)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Priority queue to store (value, list index, element index)
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;

        // Insert the first element from each list into the min-heap
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        // Continue until we can't proceed further
        while (pq.size() == nums.size()) {
            auto [minVal, indices] = pq.top();
            pq.pop();
            int row = indices.first, col = indices.second;

            // Update the smallest range
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // If possible, add the next element from the same row to the heap
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                pq.push({nextVal, {row, col + 1}});
                maxVal = max(maxVal, nextVal);
            }
        }

        return {rangeStart, rangeEnd};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] smallestRange(List<List<Integer>> nums) {
        // Priority queue to store (value, list index, element index)
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            Comparator.comparingInt(a -> a[0])
        );
        int maxVal = Integer.MIN_VALUE, rangeStart = 0, rangeEnd =
            Integer.MAX_VALUE;

        // Insert the first element from each list into the min-heap
        for (int i = 0; i < nums.size(); i++) {
            pq.offer(new int[] { nums.get(i).get(0), i, 0 });
            maxVal = Math.max(maxVal, nums.get(i).get(0));
        }

        // Continue until we can't proceed further
        while (pq.size() == nums.size()) {
            int[] data = pq.poll();
            int minVal = data[0], row = data[1], col = data[2];

            // Update the smallest range
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // If possible, add the next element from the same row to the heap
            if (col + 1 < nums.get(row).size()) {
                int nextVal = nums.get(row).get(col + 1);
                pq.offer(new int[] { nextVal, row, col + 1 });
                maxVal = Math.max(maxVal, nextVal);
            }
        }

        return new int[] { rangeStart, rangeEnd };
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        # Priority queue to store (value, list index, element index)
        pq = []
        max_val = float("-inf")
        range_start = 0
        range_end = float("inf")

        # Insert the first element from each list into the min-heap
        for i in range(len(nums)):
            heapq.heappush(pq, (nums[i][0], i, 0))
            max_val = max(max_val, nums[i][0])

        # Continue until we can't proceed further
        while len(pq) == len(nums):
            min_val, row, col = heapq.heappop(pq)

            # Update the smallest range
            if max_val - min_val < range_end - range_start:
                range_start = min_val
                range_end = max_val

            # If possible, add the next element from the same row to the heap
            if col + 1 < len(nums[row]):
                next_val = nums[row][col + 1]
                heapq.heappush(pq, (next_val, row, col + 1))
                max_val = max(max_val, next_val)

        return [range_start, range_end]
```

</details>

<br>

## Approach 3: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> merged;

        // Merge all lists with their list index
        for (int i = 0; i < nums.size(); i++) {
            for (int num : nums[i]) {
                merged.push_back({num, i});
            }
        }

        // Sort the merged list
        sort(merged.begin(), merged.end());

        // Two pointers to track the smallest range
        unordered_map<int, int> freq;
        int left = 0, count = 0;
        int rangeStart = 0, rangeEnd = INT_MAX;

        for (int right = 0; right < merged.size(); right++) {
            freq[merged[right].second]++;
            if (freq[merged[right].second] == 1) count++;

            // When all lists are represented, try to shrink the window
            while (count == nums.size()) {
                int curRange = merged[right].first - merged[left].first;
                if (curRange < rangeEnd - rangeStart) {
                    rangeStart = merged[left].first;
                    rangeEnd = merged[right].first;
                }

                freq[merged[left].second]--;
                if (freq[merged[left].second] == 0) count--;
                left++;
            }
        }

        return {rangeStart, rangeEnd};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] smallestRange(List<List<Integer>> nums) {
        List<int[]> merged = new ArrayList<>();

        // Merge all lists with their list index
        for (int i = 0; i < nums.size(); i++) {
            for (int num : nums.get(i)) {
                merged.add(new int[] { num, i });
            }
        }

        // Sort the merged list
        merged.sort(Comparator.comparingInt(a -> a[0]));

        // Two pointers to track the smallest range
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0, count = 0;
        int rangeStart = 0, rangeEnd = Integer.MAX_VALUE;

        for (int right = 0; right < merged.size(); right++) {
            freq.put(
                merged.get(right)[1],
                freq.getOrDefault(merged.get(right)[1], 0) + 1
            );
            if (freq.get(merged.get(right)[1]) == 1) count++;

            // When all lists are represented, try to shrink the window
            while (count == nums.size()) {
                int curRange = merged.get(right)[0] - merged.get(left)[0];
                if (curRange < rangeEnd - rangeStart) {
                    rangeStart = merged.get(left)[0];
                    rangeEnd = merged.get(right)[0];
                }

                freq.put(
                    merged.get(left)[1],
                    freq.get(merged.get(left)[1]) - 1
                );
                if (freq.get(merged.get(left)[1]) == 0) count--;
                left++;
            }
        }

        return new int[] { rangeStart, rangeEnd };
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        merged = []

        # Merge all lists with their list index
        for i in range(len(nums)):
            for num in nums[i]:
                merged.append((num, i))

        # Sort the merged list
        merged.sort()

        # Two pointers to track the smallest range
        freq = defaultdict(int)
        left, count = 0, 0
        range_start, range_end = 0, float("inf")

        for right in range(len(merged)):
            freq[merged[right][1]] += 1
            if freq[merged[right][1]] == 1:
                count += 1

            # When all lists are represented, try to shrink the window
            while count == len(nums):
                cur_range = merged[right][0] - merged[left][0]
                if cur_range < range_end - range_start:
                    range_start = merged[left][0]
                    range_end = merged[right][0]

                freq[merged[left][1]] -= 1
                if freq[merged[left][1]] == 0:
                    count -= 1
                left += 1

        return [range_start, range_end]
```

</details>
