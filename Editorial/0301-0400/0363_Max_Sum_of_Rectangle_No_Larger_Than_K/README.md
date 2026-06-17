# 363. Max Sum of Rectangle No Larger Than K

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)  
`Array` `Binary Search` `Matrix` `Prefix Sum` `Ordered Set`

**Problem Link:** [LeetCode 363 - Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)

## Problem

Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.

### Example 1

```text
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
```

### Example 2

```text
Input: matrix = [[2,2,-1]], k = 3
Output: 3
```

## Constraints

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 100
- -100 <= matrix[i][j] <= 100
- -105 <= k <= 105

Follow up: What if the number of rows is much larger than the number of columns?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 363. Max Sum of Rectangle No Larger Than K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sum on 1D Array using Sorted Container | C++, Java |
| Follow-up - Larger Number of Rows than Columns | C++, Java |
| Combining it with Kadane's Algorithm | C++, Java |

## Approach 1: Prefix Sum on 1D Array using Sorted Container

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int result = INT_MIN;
    void updateResult(vector<int>& nums, int k) {
        int sum = 0;

        // Container to store sorted prefix sums.
        set<int> sortedSum;
        set<int>::iterator it;

        // Add 0 as the prefix sum for an empty sub-array.
        sortedSum.insert(0);
        for (int& num : nums) {
            // Running Sum.
            sum += num;

            // Get X where Running sum - X <= k such that sum - X is closest to k.
            it = sortedSum.lower_bound(sum - k);

            // If such X is found in the prefix sums.
            // Get the sum of that sub array and update the global maximum resul.
            if (it != sortedSum.end())
                result = max(result, sum - *it);

            // Insert the current running sum to the prefix sums container.
            sortedSum.insert(sum);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // Stores the 1D representation of the matrix.
        vector<int> rowSum(matrix[0].size());
        for (int i = 0; i < matrix.size(); i++) {
            // Initialize the 1D representation with 0s.
            fill(rowSum.begin(), rowSum.end(), 0);

            // We convert the matrix between rows i..row inclusive to 1D array
            for (int row = i; row < matrix.size(); row++) {
                // Add the current row to the previous row.
                // This converts the matrix between i..row to 1D array
                for (int col = 0; col < matrix[0].size(); col++)
                    rowSum[col] += matrix[row][col];

                // Run the 1D algorithm for `rowSum`
                updateResult(rowSum, k);

                // If result is k, this is the best possible answer, so return.
                if (result == k)
                    return result;
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
    int result = Integer.MIN_VALUE;
    void updateResult(int[] nums, int k) {
        int sum = 0;

        // Container to store sorted prefix sums.
        TreeSet<Integer> sortedSum = new TreeSet<>();

        // Add 0 as the prefix sum for an empty sub-array.
        sortedSum.add(0);
        for (int num : nums) {
            // Running Sum.
            sum += num;

            // Get X where Running sum - X <= k such that sum - X is closest to k.
            Integer x = sortedSum.ceiling(sum - k);

            // If such X is found in the prefix sums.
            // Get the sum of that sub array and update the global maximum result.
            if (x != null)
                result = Math.max(result, sum - x);

            // Insert the current running sum to the prefix sums container.
            sortedSum.add(sum);
        }
    }
    public int maxSumSubmatrix(int[][] matrix, int k) {
        // Stores the 1D representation of the matrix.
        int[] rowSum = new int[matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            // Initialize the 1D representation with 0s.
            Arrays.fill(rowSum, 0);
            // We convert the matrix between rows i..row inclusive to 1D array
            for (int row = i; row < matrix.length; row++) {
                // Add the current row to the previous row.
                // This converts the matrix between i..row to 1D array
                for (int col = 0; col < matrix[0].length; col++)
                    rowSum[col] += matrix[row][col];

                // Run the 1D algorithm for `rowSum`
                updateResult(rowSum, k);

                // If result is k, this is the best possible answer, so return.
                if (result == k)
                    return result;
            }
        }
        return result;
    }
}
```

</details>

<br>

## Approach 2: Follow-up - Larger Number of Rows than Columns

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int result = INT_MIN;
    void updateResult(vector<int>& nums, int k) {
        int sum = 0;

        // Container to store sorted prefix sums.
        set<int> sortedSum;
        set<int>::iterator it;

        // Add 0 as the prefix sum for an empty sub-array.
        sortedSum.insert(0);
        for (int& num : nums) {
            // Running Sum.
            sum += num;

            // Get X where Running sum - X <= k such that sum - X is closest to k.
            it = sortedSum.lower_bound(sum - k);

            // If such X is found in the prefix sums.
            // Get the sum of that sub array and update the global maximum result.
            if (it != sortedSum.end())
                result = max(result, sum - *it);

            // Insert the current running sum to the prefix sums container.
            sortedSum.insert(sum);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix[0].size() > matrix.size()) {
            // Stores the 1D representation of the matrix row wise.
            vector<int> rowSum(matrix[0].size());
            for (int i = 0; i < matrix.size(); i++) {
                // Initialize the 1D representation with 0s.
                fill(rowSum.begin(), rowSum.end(), 0);

                // We convert the matrix between rows i..row inclusive to 1D array
                for (int row = i; row < matrix.size(); row++) {
                    // Add the current row to the previous row.
                    // This converts the matrix between i..j to 1D array
                    for (int col = 0; col < matrix[0].size(); col++)
                        rowSum[col] += matrix[row][col];

                    // Run the 1D algorithm for `rowSum`
                    updateResult(rowSum, k);

                    // If result is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        } else {
            // Stores the 1D representation of the matrix column wise.
            vector<int> colSum(matrix.size());
            for (int i = 0; i < matrix[0].size(); i++) {
                // Initialize the 1D representation with 0s.
                fill(colSum.begin(), colSum.end(), 0);

                // We convert the matrix between columns i..col inclusive to 1D array
                for (int col = i; col < matrix[0].size(); col++) {
                    // Add the current column to the previous column.
                    for (int row = 0; row < matrix.size(); row++)
                        colSum[row] += matrix[row][col];

                    // Run the 1D algorithm for `colSum`
                    updateResult(colSum, k);

                    // If Max is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
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
    int result = Integer.MIN_VALUE;
    void updateResult(int[] nums, int k) {
        int sum = 0;

        // Container to store sorted prefix sums.
        TreeSet<Integer> sortedSum = new TreeSet<>();

        // Add 0 as the prefix sum for an empty sub-array.
        sortedSum.add(0);
        for (int num : nums) {
            // Running Sum.
            sum += num;

            // Get X where Running sum - X <= k such that sum - X is closest to k.
            Integer x = sortedSum.ceiling(sum - k);

            // If such X is found in the prefix sums.
            // Get the sum of that sub array and update the global maximum result.
            if (x != null)
                result = Math.max(result, sum - x);

            // Insert the current running sum to the prefix sums container.
            sortedSum.add(sum);
        }
    }
    public int maxSumSubmatrix(int[][] matrix, int k) {
        if (matrix[0].length > matrix.length) {
            // Stores the 1D representation of the matrix.
            int[] rowSum = new int[matrix[0].length];
            for (int i = 0; i < matrix.length; i++) {
                // Initialize the 1D representation with 0s.
                Arrays.fill(rowSum, 0);
                // We convert the matrix between rows i..row inclusive to 1D array
                for (int row = i; row < matrix.length; row++) {
                    // Add the current row to the previous row.
                    // This converts the matrix between i..j to 1D array
                    for (int col = 0; col < matrix[0].length; col++)
                        rowSum[col] += matrix[row][col];

                    // Run the 1D algorithm for `rowSum`
                    updateResult(rowSum, k);

                    // If result is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        } else {
            // Stores the 1D representation of the matrix column wise.
            int[] colSum = new int[matrix.length];
            for (int i = 0; i < matrix[0].length; i++) {
                // Initialize the 1D representation with 0s.
                Arrays.fill(colSum, 0);

                // We convert the matrix between columns i..col inclusive to 1D array
                for (int col = i; col < matrix[0].length; col++) {
                    // Add the current column to the previous column.
                    for (int row = 0; row < matrix.length; row++)
                        colSum[row] += matrix[row][col];

                    // Run the 1D algorithm for `colSum`
                    updateResult(colSum, k);

                    // If result is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        }
        return result;
    }
}
```

</details>

<br>

## Approach 3: Combining it with Kadane's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int result = INT_MIN;

    // Standard Kadane's algorithm.
    int getMaxKadane(vector<int>& nums) {
        int maxKadane = INT_MIN, currentMaxSum = 0;
        for (int& num : nums) {
            currentMaxSum = max(currentMaxSum + num, num);
            maxKadane = max(maxKadane, currentMaxSum);
        }
        return maxKadane;
    }
    void updateResult(vector<int>& nums, int k) {
        int kadaneSum = getMaxKadane(nums);

        // If max possible sum of any subarray of nums is <=k
        // use that result to compare with gobal maxium result and return
        if (kadaneSum <= k) {
            result = max(result, kadaneSum);
            return;
        }
        int sum = 0;

        // Container to store sorted prefix sums.
        set<int> sortedSum;
        set<int>::iterator it;

        // Add 0 as the prefix sum for an empty sub-array.
        sortedSum.insert(0);
        for (int& num : nums) {
            // Running Sum.
            sum += num;

            // Get X where Running sum - X <= k such that sum - X is closest to k.
            it = sortedSum.lower_bound(sum - k);

            // If such X is found in the prefix sums.
            // Get the sum of that sub array and update the global maximum result.
            if (it != sortedSum.end())
                result = max(result, sum - *it);

            // Insert the current running sum to the prefix sums container.
            sortedSum.insert(sum);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix[0].size() > matrix.size()) {
            // Stores the 1D representation of the matrix row wise.
            vector<int> rowSum(matrix[0].size());
            for (int i = 0; i < matrix.size(); i++) {
                // Initialize the 1D representation with 0s.
                fill(rowSum.begin(), rowSum.end(), 0);

                // We convert the matrix between rows i..row inclusive to 1D array
                for (int row = i; row < matrix.size(); row++) {
                    // Add the current row to the previous row.
                    // This converts the matrix between i..j to 1D array
                    for (int col = 0; col < matrix[0].size(); col++)
                        rowSum[col] += matrix[row][col];

                    // Run the 1D algorithm for `rowSum`
                    updateResult(rowSum, k);

                    // If result is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        } else {
            // Stores the 1D representation of the matrix column wise.
            vector<int> colSum(matrix.size());
            for (int i = 0; i < matrix[0].size(); i++) {
                // Initialize the 1D representation with 0s.
                fill(colSum.begin(), colSum.end(), 0);

                // We convert the matrix between columns i..col inclusive to 1D array
                for (int col = i; col < matrix[0].size(); col++) {
                    // Add the current column to the previous column.
                    for (int row = 0; row < matrix.size(); row++)
                        colSum[row] += matrix[row][col];

                    // Run the 1D algorithm for `colSum`
                    updateResult(colSum, k);

                    // If Max is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
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
    int result = Integer.MIN_VALUE;

    // Standard Kadane's algorithm.
    int getMaxKadane(int[] nums) {
        int maxKadane = Integer.MIN_VALUE, currentMaxSum = 0;
        for (int num : nums) {
            currentMaxSum = Math.max(currentMaxSum + num, num);
            maxKadane = Math.max(maxKadane, currentMaxSum);
        }
        return maxKadane;
    }
    void updateResult(int[] nums, int k) {
        int kadaneSum = getMaxKadane(nums);

        // If max possible sum of any subarray of nums is <= k
        // use that result to compare with gobal maxium result and return
        if (kadaneSum <= k) {
            result = Math.max(result, kadaneSum);
            return;
        }
        int sum = 0;

        // Container to store sorted prefix sums.
        TreeSet<Integer> sortedSum = new TreeSet<>();

        // Add 0 as the prefix sum for an empty sub-array.
        sortedSum.add(0);
        for (int num : nums) {
            // Running Sum.
            sum += num;

            // Get X where Running sum - X <= k such that sum - X is closest to k.
            Integer x = sortedSum.ceiling(sum - k);

            // If such X is found in the prefix sums.
            // Get the sum of that sub array and update the global maximum result.
            if (x != null)
                result = Math.max(result, sum - x);

            // Insert the current running sum to the prefix sums container.
            sortedSum.add(sum);
        }
    }
    public int maxSumSubmatrix(int[][] matrix, int k) {
        if (matrix[0].length > matrix.length) {
            // Stores the 1D representation of the matrix.
            int[] rowSum = new int[matrix[0].length];
            for (int i = 0; i < matrix.length; i++) {
                // Initialize the 1D representation with 0s.
                Arrays.fill(rowSum, 0);
                // We convert the matrix between rows i..row inclusive to 1D array
                for (int row = i; row < matrix.length; row++) {
                    // Add the current row to the previous row.
                    // This converts the matrix between i..j to 1D array
                    for (int col = 0; col < matrix[0].length; col++)
                        rowSum[col] += matrix[row][col];

                    // Run the 1D algorithm for `rowSum`
                    updateResult(rowSum, k);

                    // If result is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        } else {
            // Stores the 1D representation of the matrix column wise.
            int[] colSum = new int[matrix.length];
            for (int i = 0; i < matrix[0].length; i++) {
                // Initialize the 1D representation with 0s.
                Arrays.fill(colSum, 0);

                // We convert the matrix between columns i..col inclusive to 1D array
                for (int col = i; col < matrix[0].length; col++) {
                    // Add the current column to the previous column.
                    for (int row = 0; row < matrix.length; row++)
                        colSum[row] += matrix[row][col];

                    // Run the 1D algorithm for `colSum`
                    updateResult(colSum, k);

                    // If result is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        }
        return result;
    }
}
```

</details>
