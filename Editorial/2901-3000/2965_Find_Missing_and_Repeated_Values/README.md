# 2965. Find Missing and Repeated Values

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-missing-and-repeated-values/)  
`Array` `Hash Table` `Math` `Matrix`

**Problem Link:** [LeetCode 2965 - Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values/)

## Problem

You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

### Example 1

```text
Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
```

### Example 2

```text
Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
Output: [9,5]
Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
```

## Constraints

- 2 <= n == grid.length == grid[i].length <= 50
- 1 <= grid[i][j] <= n * n
- For all x that 1 <= x <= n * n there is exactly one x that is not equal to any of the grid members.
- For all x that 1 <= x <= n * n there is exactly one x that is equal to exactly two of the grid members.
- For all x that 1 <= x <= n * n except two of them there is exactly one pair of i, j that 0 <= i, j <= n - 1 and grid[i][j] == x.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2965. Find Missing and Repeated Values

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Map | C++, Java, Python3 |
| Math | C++, Java, Python3 |

## Approach 1: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int missing = -1, repeat = -1;

        // Store frequency of each number in the grid
        unordered_map<int, int> freq;
        for (auto& row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }

        // Check numbers from 1 to n^2 to find missing and repeated values
        for (int num = 1; num <= n * n; num++) {
            if (!freq.count(num)) {
                missing = num;  // Number not present in grid
            } else if (freq[num] == 2) {
                repeat = num;  // Number appears twice
            }
        }

        return {repeat, missing};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int missing = -1, repeat = -1;

        // Store frequency of each number in the grid
        Map<Integer, Integer> freq = new HashMap<>();
        for (int[] row : grid) {
            for (int num : row) {
                freq.put(num, freq.getOrDefault(num, 0) + 1);
            }
        }

        // Check numbers from 1 to n^2 to find missing and repeated values
        for (int num = 1; num <= n * n; num++) {
            if (!freq.containsKey(num)) {
                missing = num; // Number not present in grid
            } else if (freq.get(num) == 2) {
                repeat = num; // Number appears twice
            }
        }

        return new int[] { repeat, missing };
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        freq = {}

        # Store frequency of each number in the grid
        for row in grid:
            for num in row:
                freq[num] = freq.get(num, 0) + 1

        # Check numbers from 1 to n^2 to find missing and repeated values
        for num in range(1, n * n + 1):
            if num not in freq:
                missing = num  # Number not present in grid
            elif freq[num] == 2:
                repeat = num  # Number appears twice

        return [repeat, missing]
```

</details>

<br>

## Approach 2: Math

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0, sqrSum = 0;
        long long n = grid.size();
        long long total = n * n;

        // Calculate actual sum and squared sum from grid
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                sum += grid[row][col];
                sqrSum +=
                    static_cast<long long>(grid[row][col]) * grid[row][col];
            }
        }

        // Calculate differences from expected sums
        // Expected sum: n(n+1)/2, Expected square sum: n(n+1)(2n+1)/6
        long long sumDiff = sum - total * (total + 1) / 2;
        long long sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;

        // Using math: If x is repeated and y is missing
        // sumDiff = x - y
        // sqrDiff = xÃ‚Â² - yÃ‚Â²
        int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = (sqrDiff / sumDiff - sumDiff) / 2;

        return {repeat, missing};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] findMissingAndRepeatedValues(int[][] grid) {
        long sum = 0, sqrSum = 0;
        long n = grid.length;
        long total = n * n;

        // Calculate actual sum and squared sum from grid
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                sum += grid[row][col];
                sqrSum += (long) grid[row][col] * grid[row][col];
            }
        }

        // Calculate differences from expected sums
        // Expected sum: n(n+1)/2, Expected square sum: n(n+1)(2n+1)/6
        long sumDiff = sum - (total * (total + 1)) / 2;
        long sqrDiff = sqrSum - (total * (total + 1) * (2 * total + 1)) / 6;

        // Using math: If x is repeated and y is missing
        // sumDiff = x - y
        // sqrDiff = xÃ‚Â² - yÃ‚Â²
        int repeat = (int) (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = (int) (sqrDiff / sumDiff - sumDiff) / 2;

        return new int[] { repeat, missing };
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        # Get grid dimensions
        n = len(grid)
        total = n * n

        # Calculate actual sums from grid
        sum_val = sum(num for row in grid for num in row)
        sqr_sum = sum(num * num for row in grid for num in row)

        # Calculate differences from expected sums
        # Expected sum: n(n+1)/2, Expected square sum: n(n+1)(2n+1)/6
        sum_diff = sum_val - total * (total + 1) // 2
        sqr_diff = sqr_sum - total * (total + 1) * (2 * total + 1) // 6

        # Using math: If x is repeated and y is missing
        # sum_diff = x - y
        # sqr_diff = xÃ‚Â² - yÃ‚Â²
        repeat = (sqr_diff // sum_diff + sum_diff) // 2
        missing = (sqr_diff // sum_diff - sum_diff) // 2

        return [repeat, missing]
```

</details>
