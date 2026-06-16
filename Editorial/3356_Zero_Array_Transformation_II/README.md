# 3356. Zero Array Transformation II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/zero-array-transformation-ii/)  
`Array` `Two Pointers` `Binary Search` `Prefix Sum`

**Problem Link:** [LeetCode 3356 - Zero Array Transformation II](https://leetcode.com/problems/zero-array-transformation-ii/)

## Problem

You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

- Decrement the value at each index in the range [li, ri] in nums by at most vali.
- The amount by which each value is decremented can be chosen independently for each index.

A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 5 * 105
- 1 <= queries.length <= 105
- queries[i].length == 3
- 0 <= li <= ri < nums.length
- 1 <= vali <= 5

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Zero Array Transformation IV](https://leetcode.com/problems/zero-array-transformation-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3356. Zero Array Transformation II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Line Sweep | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), left = 0, right = queries.size();

        // Zero array isn't formed after all queries are processed
        if (!canFormZeroArray(nums, queries, right)) return -1;

        // Binary Search
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (canFormZeroArray(nums, queries, middle)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        // Return earliest query that zero array can be formed
        return left;
    }

private:
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries,
                          int k) {
        int n = nums.size(), sum = 0;
        vector<int> differenceArray(n + 1);

        // Process query
        for (int queryIndex = 0; queryIndex < k; queryIndex++) {
            int start = queries[queryIndex][0], end = queries[queryIndex][1],
                val = queries[queryIndex][2];

            // Process start and end of range
            differenceArray[start] += val;
            differenceArray[end + 1] -= val;
        }

        // Check if zero array can be formed
        for (int numIndex = 0; numIndex < n; numIndex++) {
            sum += differenceArray[numIndex];
            if (sum < nums[numIndex]) return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minZeroArray(int[] nums, int[][] queries) {
        int n = nums.length, left = 0, right = queries.length;

        // Zero array isn't formed after all queries are processed
        if (!currentIndexZero(nums, queries, right)) return -1;

        // Binary Search
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (currentIndexZero(nums, queries, middle)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        // Return earliest query that zero array can be formed
        return left;
    }

    private boolean currentIndexZero(int[] nums, int[][] queries, int k) {
        int n = nums.length, sum = 0;
        int[] differenceArray = new int[n + 1];

        // Process query
        for (int queryIndex = 0; queryIndex < k; queryIndex++) {
            int left = queries[queryIndex][0], right =
                queries[queryIndex][1], val = queries[queryIndex][2];

            // Process start and end of range
            differenceArray[left] += val;
            differenceArray[right + 1] -= val;
        }

        // Check if zero array can be formed
        for (int numIndex = 0; numIndex < n; numIndex++) {
            sum += differenceArray[numIndex];
            if (sum < nums[numIndex]) return false;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        left, right = 0, len(queries)

        # Zero array isn't formed after all queries are processed
        if not self.can_form_zero_array(nums, queries, right):
            return -1

        # Binary Search
        while left <= right:
            middle = left + (right - left) // 2
            if self.can_form_zero_array(nums, queries, middle):
                right = middle - 1
            else:
                left = middle + 1

        # Return earliest query that zero array can be formed
        return left

    def can_form_zero_array(
        self, nums: List[int], queries: List[List[int]], k: int
    ) -> bool:
        n = len(nums)
        total_sum = 0
        difference_array = [0] * (n + 1)

        # Process query
        for query_index in range(k):
            start, end, val = queries[query_index]

            # Process start and end of range
            difference_array[start] += val
            difference_array[end + 1] -= val

        # Check if zero array can be formed
        for num_index in range(n):
            total_sum += difference_array[num_index]
            if total_sum < nums[num_index]:
                return False
        return True
```

</details>

<br>

## Approach 2: Line Sweep

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> differenceArray(n + 1);

        // Iterate through nums
        for (int index = 0; index < n; index++) {
            // Iterate through queries while current index of nums cannot equal
            // zero
            while (sum + differenceArray[index] < nums[index]) {
                k++;

                // Zero array isn't formed after all queries are processed
                if (k > queries.size()) {
                    return -1;
                }
                int left = queries[k - 1][0], right = queries[k - 1][1],
                    val = queries[k - 1][2];

                // Process start and end of range
                if (right >= index) {
                    differenceArray[max(left, index)] += val;
                    differenceArray[right + 1] -= val;
                }
            }
            // Update prefix sum at current index
            sum += differenceArray[index];
        }
        return k;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minZeroArray(int[] nums, int[][] queries) {
        int n = nums.length, sum = 0, k = 0;
        int[] differenceArray = new int[n + 1];

        // Iterate through nums
        for (int index = 0; index < n; index++) {
            // Iterate through queries while current index of nums cannot equal zero
            while (sum + differenceArray[index] < nums[index]) {
                k++;

                // Zero array isn't formed after all queries are processed
                if (k > queries.length) {
                    return -1;
                }
                int left = queries[k - 1][0], right = queries[k - 1][1], val =
                    queries[k - 1][2];

                // Process start and end of range
                if (right >= index) {
                    differenceArray[Math.max(left, index)] += val;
                    differenceArray[right + 1] -= val;
                }
            }
            // Update prefix sum at current index
            sum += differenceArray[index];
        }
        return k;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        total_sum = 0
        k = 0
        difference_array = [0] * (n + 1)

        # Iterate through nums
        for index in range(n):
            # Iterate through queries while current index of nums cannot equal zero
            while total_sum + difference_array[index] < nums[index]:
                k += 1

                # Zero array isn't formed after all queries are processed
                if k > len(queries):
                    return -1

                left, right, val = queries[k - 1]

                # Process start and end of range
                if right >= index:
                    difference_array[max(left, index)] += val
                    difference_array[right + 1] -= val

            # Update prefix sum at current index
            total_sum += difference_array[index]

        return k
```

</details>
