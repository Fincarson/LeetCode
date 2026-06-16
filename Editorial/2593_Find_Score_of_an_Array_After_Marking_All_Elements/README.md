# 2593. Find Score of an Array After Marking All Elements

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/)  
`Array` `Hash Table` `Sorting` `Heap (Priority Queue)` `Simulation`

**Problem Link:** [LeetCode 2593 - Find Score of an Array After Marking All Elements](https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/)

## Problem

You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

- Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
- Add the value of the chosen integer to score.
- Mark the chosen element and its two adjacent elements if they exist.
- Repeat until all the array elements are marked.

Return the score you get after applying the above algorithm.

### Example 1

```text
Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.
```

### Example 2

```text
Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Integers by The Power Value](https://leetcode.com/problems/sort-integers-by-the-power-value/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2593. Find Score of an Array After Marking All Elements

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, Python3 |
| Heap | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long findScore(vector<int>& nums) {
        long ans = 0;
        vector<pair<int, int>> customSorted(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            customSorted[i] = make_pair(nums[i], i);
        }

        sort(customSorted.begin(), customSorted.end());

        vector<bool> marked(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            int number = customSorted[i].first;
            int index = customSorted[i].second;
            if (!marked[index]) {
                ans += number;
                marked[index] = true;
                // mark adjacent elements if they exist
                if (index - 1 >= 0) {
                    marked[index - 1] = true;
                }
                if (index + 1 < nums.size()) {
                    marked[index + 1] = true;
                }
            }
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

    public long findScore(int[] nums) {
        long ans = 0;
        int[][] customSorted = new int[nums.length][2];
        boolean[] marked = new boolean[nums.length];

        for (int i = 0; i < nums.length; i++) {
            customSorted[i][0] = nums[i];
            customSorted[i][1] = i;
        }

        Arrays.sort(customSorted, (arr1, arr2) -> arr1[0] - arr2[0]);

        for (int i = 0; i < nums.length; i++) {
            int number = customSorted[i][0];
            int index = customSorted[i][1];
            if (!marked[index]) {
                ans += number;
                marked[index] = true;
                // mark adjacent elements if they exist
                if (index - 1 >= 0) {
                    marked[index - 1] = true;
                }
                if (index + 1 < nums.length) {
                    marked[index + 1] = true;
                }
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
    def findScore(self, nums: List[int]) -> int:
        ans = 0
        custom_sorted = [(num, idx) for idx, num in enumerate(nums)]
        custom_sorted.sort()
        marked = [False] * len(nums)

        for i in range(len(nums)):
            number = custom_sorted[i][0]
            index = custom_sorted[i][1]
            if not marked[index]:
                ans += number
                marked[index] = True
                # mark adjacent elements if they exist
                if index - 1 >= 0:
                    marked[index - 1] = True
                if index + 1 < len(nums):
                    marked[index + 1] = True

        return ans
```

</details>

<br>

## Approach 2: Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        vector<bool> marked(nums.size());

        auto cmp = [](pair<int, int>& pair1, pair<int, int>& pair2) {
            if (pair1.first != pair2.first) return pair1.first > pair2.first;
            return pair1.second > pair2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            heap(cmp);

        for (int i = 0; i < nums.size(); ++i) {
            heap.push(make_pair(nums[i], i));
        }

        while (!heap.empty()) {
            pair<int, int> element = heap.top();
            heap.pop();
            int number = element.first;
            int index = element.second;

            if (!marked[index]) {
                ans += number;
                marked[index] = true;

                // mark adjacent elements if they exist
                if (index - 1 >= 0) {
                    marked[index - 1] = true;
                }
                if (index + 1 < nums.size()) {
                    marked[index + 1] = true;
                }
            }
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

    public long findScore(int[] nums) {
        long ans = 0;
        boolean[] marked = new boolean[nums.length];

        PriorityQueue<int[]> heap = new PriorityQueue<>((arr1, arr2) -> {
            if (arr1[0] != arr2[0]) return arr1[0] - arr2[0];
            return arr1[1] - arr2[1];
        });

        for (int i = 0; i < nums.length; i++) {
            heap.add(new int[] { nums[i], i });
        }

        while (!heap.isEmpty()) {
            int[] element = heap.remove();
            int number = element[0];
            int index = element[1];
            if (!marked[index]) {
                ans += number;
                marked[index] = true;
                // mark adjacent elements if they exist
                if (index - 1 >= 0) {
                    marked[index - 1] = true;
                }
                if (index + 1 < nums.length) {
                    marked[index + 1] = true;
                }
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
    def findScore(self, nums):
        ans = 0
        marked = [False] * len(nums)

        heap = []
        for i in range(len(nums)):
            heapq.heappush(heap, (nums[i], i))

        while heap:
            number, index = heapq.heappop(heap)
            if not marked[index]:
                ans += number
                marked[index] = True
                # mark adjacent elements if they exist
                if index - 1 >= 0:
                    marked[index - 1] = True
                if index + 1 < len(nums):
                    marked[index + 1] = True

        return ans
```

</details>

<br>

## Approach 3: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            int currentStart = i;
            while (i + 1 < nums.size() && nums[i + 1] < nums[i]) {
                i++;
            }
            for (int currentIndex = i; currentIndex >= currentStart;
                 currentIndex -= 2) {
                ans += nums[currentIndex];
            }
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

    public long findScore(int[] numbers) {
        long ans = 0;
        for (int i = 0; i < numbers.length; i += 2) {
            int currentStart = i;
            while (i + 1 < numbers.length && numbers[i + 1] < numbers[i]) {
                i++;
            }
            for (
                int currentIndex = i;
                currentIndex >= currentStart;
                currentIndex -= 2
            ) {
                ans += numbers[currentIndex];
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
    def findScore(self, nums: List[int]) -> int:
        ans = 0
        i = 0
        while i < len(nums):
            current_start = i
            while i + 1 < len(nums) and nums[i + 1] < nums[i]:
                i += 1
            current_index = i
            while current_index >= current_start:
                ans += nums[current_index]
                current_index -= 2
            i += 2
        return ans
```

</details>
