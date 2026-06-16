# 2033. Minimum Operations to Make a Uni-Value Grid

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/)  
`Array` `Math` `Sorting` `Matrix`

**Problem Link:** [LeetCode 2033 - Minimum Operations to Make a Uni-Value Grid](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/)

## Problem

You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

### Example 1

```text
Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following:
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
```

### Example 2

```text
Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.
```

### Example 3

```text
Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 105
- 1 <= m * n <= 105
- 1 <= x, grid[i][j] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2033. Minimum Operations to Make a Uni-Value Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting and Median | C++, Java, Python3 |
| Prefix and Suffix Sums | C++, Java, Python3 |
| Two Pointers | C++, Java, Python3 |

## Approach 1: Sorting and Median

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> numsArray;
        int result = 0;

        // Flatten the grid into numsArray
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                numsArray.push_back(grid[row][col]);
            }
        }

        int length = numsArray.size();

        // Partially sorts the array so that the median element is placed at the
        // middle index
        nth_element(numsArray.begin(), numsArray.begin() + length / 2,
                    numsArray.end());

        // Store the median element as the final common value to make all
        // elements equal to
        int finalCommonNumber = numsArray[length / 2];

        for (int number : numsArray) {
            // If the remainder when divided by x is different for any number,
            // return -1
            if (number % x != finalCommonNumber % x) return -1;
            // Add the number of operations required to make the current number
            // equal to finalCommonNumber
            result += abs(finalCommonNumber - number) / x;
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

    public int minOperations(int[][] grid, int x) {
        // Create a list to store all the numbers from the grid
        ArrayList<Integer> numsArray = new ArrayList<>();
        int result = 0;

        // Flatten the grid into numsArray
        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[0].length; col++) {
                numsArray.add(grid[row][col]);
            }
        }

        // Sort numsArray in non-decreasing order to easily find the median
        Collections.sort(numsArray);

        int length = numsArray.size();
        // Store the median element as the final common value
        int finalCommonNumber = numsArray.get(length / 2);

        // Iterate through each number in numsArray
        for (int number : numsArray) {
            // If the remainder when divided by x is different, return -1
            if (number % x != finalCommonNumber % x) {
                return -1;
            }
            // Add the number of operations required to make the current number equal to finalCommonNumber
            result += Math.abs(finalCommonNumber - number) / x;
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
    def minOperations(self, grid, x):
        # Create a list to store all the numbers from the grid
        nums_array = []
        result = 0

        # Flatten the grid into nums_array
        for row in grid:
            for num in row:
                nums_array.append(num)

        # Sort nums_array in non-decreasing order to easily find the median
        nums_array.sort()

        length = len(nums_array)
        # Store the median element as the final common value
        final_common_number = nums_array[length // 2]

        # Iterate through each number in nums_array
        for number in nums_array:
            # If the remainder when divided by x is different, return -1
            if number % x != final_common_number % x:
                return -1
            # Add the number of operations required to make the current number equal to final_common_number
            result += abs(final_common_number - number) // x

        return result
```

</details>

<br>

## Approach 2: Prefix and Suffix Sums

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // Initialize an empty array to store all numbers
        vector<int> numsArray;
        int result = INT_MAX;

        // Flatten the grid into numsArray and check if all elements have the
        // same remainder when divided by x
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                // If remainder of any element doesn't match the first element,
                // return -1
                if (grid[row][col] % x != grid[0][0] % x) return -1;
                numsArray.push_back(grid[row][col]);
            }
        }

        // Sort numsArray in non-decreasing order to easily calculate operations
        sort(numsArray.begin(), numsArray.end());

        int length = numsArray.size();
        vector<int> prefixSum(length, 0);
        vector<int> suffixSum(length, 0);

        // Calculate the prefix sum up to each index (excluding the current
        // element)
        for (int index = 1; index < length; index++) {
            prefixSum[index] = prefixSum[index - 1] + numsArray[index - 1];
        }

        // Calculate the suffix sum from each index (excluding the current
        // element)
        for (int index = length - 2; index >= 0; index--) {
            suffixSum[index] = suffixSum[index + 1] + numsArray[index + 1];
        }

        // Iterate through numsArray to calculate the number of operations for
        // each potential common value
        for (int index = 0; index < length; index++) {
            int leftOperations =
                (numsArray[index] * index - prefixSum[index]) / x;

            int rightOperations =
                (suffixSum[index] - numsArray[index] * (length - index - 1)) /
                x;

            // Update the result with the minimum operations needed
            result = min(result, leftOperations + rightOperations);
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

    public int minOperations(int[][] grid, int x) {
        // Initialize an empty array to store all numbers
        ArrayList<Integer> numsArray = new ArrayList<>();
        int result = Integer.MAX_VALUE;

        // Flatten the grid into numsArray and check if all elements have the same remainder when divided by x
        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[0].length; col++) {
                // If remainder of any element doesn't match the first element, return -1
                if (grid[row][col] % x != grid[0][0] % x) return -1;
                numsArray.add(grid[row][col]);
            }
        }

        // Sort numsArray in non-decreasing order to easily calculate operations
        Collections.sort(numsArray);

        int length = numsArray.size();
        int[] prefixSum = new int[length];
        int[] suffixSum = new int[length];

        // Calculate the prefix sum up to each index (excluding the current element)
        for (int index = 1; index < length; index++) {
            prefixSum[index] = prefixSum[index - 1] + numsArray.get(index - 1);
        }

        // Calculate the suffix sum from each index (excluding the current element)
        for (int index = length - 2; index >= 0; index--) {
            suffixSum[index] = suffixSum[index + 1] + numsArray.get(index + 1);
        }

        // Iterate through numsArray to calculate the number of operations for each potential common value
        for (int index = 0; index < length; index++) {
            int leftOperations =
                (numsArray.get(index) * index - prefixSum[index]) / x;
            int rightOperations =
                (suffixSum[index] -
                    numsArray.get(index) * (length - index - 1)) /
                x;
            // Update the result with the minimum operations needed
            result = Math.min(result, leftOperations + rightOperations);
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
    def minOperations(self, grid, x):
        # Initialize an empty array to store all numbers
        nums_array = []
        result = float("inf")

        # Flatten the grid into nums_array and check if all elements have the same remainder when divided by x
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                # If remainder of any element doesn't match the first element, return -1
                if grid[row][col] % x != grid[0][0] % x:
                    return -1
                nums_array.append(grid[row][col])

        # Sort nums_array in non-decreasing order to easily calculate operations
        nums_array.sort()

        length = len(nums_array)
        prefix_sum = [0] * length
        suffix_sum = [0] * length

        # Calculate the prefix sum up to each index (excluding the current element)
        for index in range(1, length):
            prefix_sum[index] = prefix_sum[index - 1] + nums_array[index - 1]

        # Calculate the suffix sum from each index (excluding the current element)
        for index in range(length - 2, -1, -1):
            suffix_sum[index] = suffix_sum[index + 1] + nums_array[index + 1]

        # Iterate through nums_array to calculate the number of operations for each potential common value
        for index in range(length):
            left_operations = (
                nums_array[index] * index - prefix_sum[index]
            ) // x
            right_operations = (
                suffix_sum[index] - nums_array[index] * (length - index - 1)
            ) // x
            # Update the result with the minimum operations needed
            result = min(result, left_operations + right_operations)

        return result
```

</details>

<br>

## Approach 3: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // Initialize an empty array to store all numbers from the grid
        vector<int> numsArray;
        int result = 0;

        // Flatten the grid into numsArray
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                // If any element has a different remainder than the first
                // element, it is impossible to make all elements equal, so
                // return -1
                if (grid[row][col] % x != grid[0][0] % x) return -1;
                numsArray.push_back(grid[row][col]);
            }
        }

        // Sort numsArray in non-decreasing order to facilitate efficient
        // operations
        sort(numsArray.begin(), numsArray.end());

        int length = numsArray.size();
        int prefixIndex = 0;
        int suffixIndex = length - 1;

        // Gradually move prefixIndex and suffixIndex towards the middle
        while (prefixIndex < suffixIndex) {
            // If the prefix of equal elements is shorter than the suffix
            if (prefixIndex < length - suffixIndex - 1) {
                // Calculate the number of operations required to extend the
                // prefix
                int prefixOperations =
                    (prefixIndex + 1) *
                    (numsArray[prefixIndex + 1] - numsArray[prefixIndex]) / x;

                result += prefixOperations;
                // Move the prefix index forward
                prefixIndex++;
            } else {
                // Calculate the number of operations required to extend the
                // suffix
                int suffixOperations =
                    (length - suffixIndex) *
                    (numsArray[suffixIndex] - numsArray[suffixIndex - 1]) / x;

                result += suffixOperations;
                // Move the suffix index backward
                suffixIndex--;
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

    public int minOperations(int[][] grid, int x) {
        List<Integer> numsArray = new ArrayList<>();
        int result = 0;

        // Flatten the grid into numsArray and check remainder condition
        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[0].length; col++) {
                if (grid[row][col] % x != grid[0][0] % x) return -1;
                // If any element has a different remainder than the first
                // element, it is impossible to make all elements equal, so
                // return -1
                numsArray.add(grid[row][col]);
            }
        }

        Collections.sort(numsArray);

        int length = numsArray.size();
        int prefixIndex = 0;
        int suffixIndex = length - 1;

        // Move prefixIndex and suffixIndex towards the middle
        while (prefixIndex < suffixIndex) {
            // If the prefix of equal elements is shorter than the suffix
            if (prefixIndex < length - suffixIndex - 1) {
                // Calculate the number of operations required to extend the prefix
                int prefixOperations =
                    ((prefixIndex + 1) *
                        (numsArray.get(prefixIndex + 1) -
                            numsArray.get(prefixIndex))) /
                    x;
                result += prefixOperations;
                // Move the prefix index forward
                prefixIndex++;
            } else {
                // Calculate the number of operations required to extend the suffix
                int suffixOperations =
                    ((length - suffixIndex) *
                        (numsArray.get(suffixIndex) -
                            numsArray.get(suffixIndex - 1))) /
                    x;
                result += suffixOperations;
                // Move the suffix index backward
                suffixIndex--;
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
    def minOperations(self, grid: list[list[int]], x: int) -> int:
        nums_array = []
        result = 0

        # Flatten the grid into nums_array and check remainder condition
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                # If any element has a different remainder than the first element,
                # it is impossible to make all elements equal, so
                # return -1
                if grid[row][col] % x != grid[0][0] % x:
                    return -1
                nums_array.append(grid[row][col])

        nums_array.sort()

        length = len(nums_array)
        prefix_index = 0
        suffix_index = length - 1

        # Move prefix_index and suffix_index towards the middle
        while prefix_index < suffix_index:
            # If the prefix of equal elements is shorter than the suffix
            if prefix_index < length - suffix_index - 1:
                # Calculate the number of operations required to extend the prefix
                prefix_operations = (
                    (prefix_index + 1)
                    * (nums_array[prefix_index + 1] - nums_array[prefix_index])
                    // x
                )
                result += prefix_operations
                # Move the prefix index forward
                prefix_index += 1
            else:
                # Calculate the number of operations required to extend the suffix
                suffix_operations = (
                    (length - suffix_index)
                    * (nums_array[suffix_index] - nums_array[suffix_index - 1])
                    // x
                )
                result += suffix_operations
                # Move the suffix index backward
                suffix_index -= 1

        return result
```

</details>
