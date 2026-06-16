# 1746. Maximum Subarray Sum After One Operation

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1746 - Maximum Subarray Sum After One Operation](https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/)

## Problem

You are given an integer array nums. You must perform exactly one operation where you can replace one element nums[i] with nums[i] * nums[i].

Return the maximum possible subarray sum after exactly one operation. The subarray must be non-empty.

### Example 1

```text
Input: nums = [2,-1,-4,-3]
Output: 17
Explanation: You can perform the operation on index 2 (0-indexed) to make nums = [2,-1,16,-3]. Now, the maximum subarray sum is 2 + -1 + 16 = 17.
```

### Example 2

```text
Input: nums = [1,-1,1,1,-1,-1,1]
Output: 4
Explanation: You can perform the operation on index 1 (0-indexed) to make nums = [1,1,1,1,-1,-1,1]. Now, the maximum subarray sum is 1 + 1 + 1 + 1 = 4.
```

## Constraints

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1746. Maximum Subarray Sum After One Operation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| MaxLeft and MaxRight | C++, Java, Python3 |
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Space-optimized Dynamic Programming | C++, Java, Python3 |

## Approach 1: MaxLeft and MaxRight

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();

        // Arrays to store the maximum sum of subarrays ending before and
        // starting after each element
        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        // No subarray ends before the first element, so set maxLeft[0] to 0
        maxLeft[0] = 0;
        for (int i = 1; i < n; i++) {
            // Compute maxLeft[i]: the maximum subarray sum ending just before
            // nums[i]
            maxLeft[i] = max(maxLeft[i - 1] + nums[i - 1], 0);
        }

        // No subarray starts after the last element, so set maxRight[n - 1] to
        // 0
        maxRight[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            // Compute maxRight[i]: the maximum subarray sum starting just after
            // nums[i]
            maxRight[i] = max(maxRight[i + 1] + nums[i + 1], 0);
        }

        // Initialize the maximum sum as 0
        int maxSum = 0;

        // Iterate over each element in the array
        for (int i = 0; i < n; i++) {
            // Calculate the maximum sum by combining the best left and right
            // subarrays found for each element
            maxSum = max(maxSum, maxLeft[i] + nums[i] * nums[i] + maxRight[i]);
        }

        return maxSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxSumAfterOperation(int[] nums) {
        int n = nums.length;

        // Arrays to store the maximum sum of subarrays ending before and starting after each element
        int[] maxLeft = new int[n];
        int[] maxRight = new int[n];

        // No subarray ends before the first element, so set maxLeft[0] to 0
        maxLeft[0] = 0;
        for (int i = 1; i < n; i++) {
            // Compute maxLeft[i]: the maximum subarray sum ending just before nums[i]
            maxLeft[i] = Math.max(maxLeft[i - 1] + nums[i - 1], 0);
        }

        // No subarray starts after the last element, so set maxRight[n - 1] to 0
        maxRight[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            // Compute maxRight[i]: the maximum subarray sum starting just after nums[i]
            maxRight[i] = Math.max(maxRight[i + 1] + nums[i + 1], 0);
        }

        // Initialize the maximum sum as 0
        int maxSum = 0;

        // Iterate over each element in the array
        for (int i = 0; i < n; i++) {
            // Calculate the maximum sum by combining the best left and right subarrays found for each element
            maxSum = Math.max(
                maxSum,
                maxLeft[i] + nums[i] * nums[i] + maxRight[i]
            );
        }

        return maxSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumAfterOperation(self, nums: list[int]) -> int:
        n = len(nums)

        # Arrays to store the maximum sum of subarrays ending before and starting after each element
        max_left = [0] * n
        max_right = [0] * n

        # No subarray ends before the first element, so set max_left[0] to 0
        max_left[0] = 0
        for i in range(1, n):
            # Compute max_left[i]: the maximum subarray sum ending just before nums[i]
            max_left[i] = max(max_left[i - 1] + nums[i - 1], 0)

        # No subarray starts after the last element, so set max_right[n - 1] to 0
        max_right[n - 1] = 0
        for i in range(n - 2, -1, -1):
            # Compute max_right[i]: the maximum subarray sum starting just after nums[i]
            max_right[i] = max(max_right[i + 1] + nums[i + 1], 0)

        # Initialize the maximum sum as 0
        max_sum = 0

        # Iterate over each element in the array
        for i in range(n):
            # Calculate the maximum sum by combining the best left and right subarrays found for each element
            max_sum = max(max_sum, max_left[i] + nums[i] ** 2 + max_right[i])

        return max_sum
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        // Initialize a DP table to store results of subproblems.
        vector<vector<int>> dp(n, vector<int>(2, -1));

        int maxSum = 0;

        // Call the recursive helper function to compute the result.
        getMaxSumHelper(0, nums, true, dp, maxSum);

        return maxSum;
    }

private:
    // Recursive helper function to calculate the maximum sum.
    int getMaxSumHelper(int index, vector<int>& nums, bool canSquare,
                        vector<vector<int>>& dp, int& maxSum) {
        if (index == nums.size()) {
            return 0;  // Base case: if we reach the end of the array, return 0.
        }

        // If the result is already computed for this state, return it.
        if (dp[index][canSquare] != -1) {
            return dp[index][canSquare];
        }

        // Case 1: Skip squaring the current element.
        int nextSumWithoutSquare =
            getMaxSumHelper(index + 1, nums, canSquare, dp, maxSum);
        int maxSumWithoutSquare =
            nums[index];  // The value itself if we don't square it.

        if (nextSumWithoutSquare > 0) {
            maxSumWithoutSquare +=
                nextSumWithoutSquare;  // Accumulate if positive.
        }

        // Case 2: Square the current element if allowed.
        int maxSumWithSquare = 0;
        if (canSquare) {
            maxSumWithSquare =
                nums[index] * nums[index];  // Square the current element.
            int nextSumWithSquare = getMaxSumHelper(
                index + 1, nums, false, dp, maxSum);  // Don't square further.

            if (nextSumWithSquare > 0) {
                maxSumWithSquare +=
                    nextSumWithSquare;  // Accumulate if positive.
            }
        }

        // Update the global maxSum if we find a better one.
        maxSum = max(maxSum, max(maxSumWithSquare, maxSumWithoutSquare));

        // Store the result in dp table and return the maximum of the two
        // options.
        dp[index][canSquare] = max(maxSumWithSquare, maxSumWithoutSquare);
        return dp[index][canSquare];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxSumAfterOperation(int[] nums) {
        int n = nums.length;
        // Initialize a DP table to store results of subproblems.
        int[][] dp = new int[n][2];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1); // Initialize all entries to -1.
        }

        // Create array to pass be reference
        int maxSum[] = new int[1];
        maxSum[0] = 0;

        // Call the recursive helper function to compute the result.
        getMaxSumHelper(0, nums, true, dp, maxSum);
        return maxSum[0];
    }

    private int getMaxSumHelper(
        int index,
        int[] nums,
        boolean canSquare,
        int[][] dp,
        int[] maxSum
    ) {
        if (index == nums.length) {
            return 0; // Base case: if we reach the end of the array, return 0.
        }

        // If the result is already computed for this state, return it.
        if (dp[index][canSquare ? 1 : 0] != -1) {
            return dp[index][canSquare ? 1 : 0];
        }

        // Case 1: Skip squaring the current element.
        int nextSumWithoutSquare = getMaxSumHelper(
            index + 1,
            nums,
            canSquare,
            dp,
            maxSum
        );
        int maxSumWithoutSquare = nums[index]; // The value itself if we don't square it.
        if (nextSumWithoutSquare > 0) {
            maxSumWithoutSquare += nextSumWithoutSquare; // Accumulate if positive.
        }

        // Case 2: Square the current element if allowed.
        int maxSumWithSquare = 0;
        if (canSquare) {
            maxSumWithSquare = nums[index] * nums[index]; // Square the current element.
            int nextSumWithSquare = getMaxSumHelper(
                index + 1,
                nums,
                false,
                dp,
                maxSum
            ); // Don't square further.
            if (nextSumWithSquare > 0) {
                maxSumWithSquare += nextSumWithSquare; // Accumulate if positive.
            }
        }

        // Update the global maxSum if we find a better one.
        maxSum[0] = Math.max(
            maxSum[0],
            Math.max(maxSumWithSquare, maxSumWithoutSquare)
        );

        // Store the result in dp table and return the maximum of the two options.
        dp[index][canSquare ? 1 : 0] = Math.max(
            maxSumWithSquare,
            maxSumWithoutSquare
        );
        return dp[index][canSquare ? 1 : 0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumAfterOperation(self, nums):
        n = len(nums)
        # Initialize a DP table to store results of subproblems.
        dp = [[-1, -1] for _ in range(n)]

        max_sum = [0]

        # Call the recursive helper function to compute the result.
        self._get_max_sum_helper(0, nums, True, dp, max_sum)

        return max_sum[0]

    def _get_max_sum_helper(self, index, nums, can_square, dp, max_sum):
        if index == len(nums):
            return 0  # Base case: if we reach the end of the array, return 0.

        # If the result is already computed for this state, return it.
        if dp[index][1 if can_square else 0] != -1:
            return dp[index][1 if can_square else 0]

        # Case 1: Skip squaring the current element.
        next_sum_without_square = self._get_max_sum_helper(
            index + 1, nums, can_square, dp, max_sum
        )
        max_sum_without_square = nums[
            index
        ]  # The value itself if we don't square it.
        if next_sum_without_square > 0:
            max_sum_without_square += (
                next_sum_without_square  # Accumulate if positive.
            )

        # Case 2: Square the current element if allowed.
        max_sum_with_square = 0
        if can_square:
            max_sum_with_square = (
                nums[index] * nums[index]
            )  # Square the current element.
            next_sum_with_square = self._get_max_sum_helper(
                index + 1, nums, False, dp, max_sum
            )  # Don't square further.
            if next_sum_with_square > 0:
                max_sum_with_square += (
                    next_sum_with_square  # Accumulate if positive.
                )

        # Update the global max_sum if we find a better one.
        max_sum[0] = max(
            max_sum[0], max(max_sum_with_square, max_sum_without_square)
        )

        # Store the result in dp table and return the maximum of the two options.
        dp[index][1 if can_square else 0] = max(
            max_sum_with_square, max_sum_without_square
        )
        return dp[index][1 if can_square else 0]
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array.

        // Initialize a DP table
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));

        // Base case
        dp[0][0] = nums[0];  // Maximum sum with no squared element is just the
                             // first element.
        dp[0][1] =
            nums[0] * nums[0];  // Maximum sum with the first element squared.

        int maxSum = nums[0] * nums[0];

        for (int index = 1; index < n; index++) {
            // Option 1: Start a new subarray.
            // Option 2: Continue the previous subarray.
            dp[index][0] = max(nums[index], dp[index - 1][0] + nums[index]);

            // Option 1: Start a new subarray.
            // Option 2: Square the current element
            // Option 3: Do not square the element.
            dp[index][1] =
                max(max(nums[index] * nums[index],
                        dp[index - 1][0] + nums[index] * nums[index]),
                    dp[index - 1][1] + nums[index]);

            // Update maxSum
            maxSum = max(maxSum, dp[index][1]);
        }

        return maxSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxSumAfterOperation(int[] nums) {
        int n = nums.length; // Get the size of the input array.

        // Initialize a DP table
        int[][] dp = new int[n][2];

        // Base case
        dp[0][0] = nums[0]; // Maximum sum with no squared element is just the first element.
        dp[0][1] = nums[0] * nums[0]; // Maximum sum with the first element squared.

        int maxSum = dp[0][1];

        for (int index = 1; index < n; index++) {
            // Option 1: Start a new subarray.
            // Option 2: Continue the previous subarray.
            dp[index][0] = Math.max(
                nums[index],
                dp[index - 1][0] + nums[index]
            );

            // Option 1: Start a new subarray.
            // Option 2: Square the current element.
            // Option 3: Do not square the element.
            dp[index][1] = Math.max(
                Math.max(
                    nums[index] * nums[index],
                    dp[index - 1][0] + nums[index] * nums[index]
                ),
                dp[index - 1][1] + nums[index]
            );

            // Update maxSum
            maxSum = Math.max(maxSum, dp[index][1]);
        }

        return maxSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumAfterOperation(self, nums: list[int]) -> int:
        n = len(nums)  # Get the size of the input array.

        # Initialize a DP table
        dp = [[0, 0] for _ in range(n)]

        # Base case
        dp[0][0] = nums[
            0
        ]  # Maximum sum with no squared element is just the first element.
        dp[0][1] = (
            nums[0] * nums[0]
        )  # Maximum sum with the first element squared.

        max_sum = dp[0][1]

        for index in range(1, n):
            # Option 1: Start a new subarray.
            # Option 2: Continue the previous subarray.
            dp[index][0] = max(nums[index], dp[index - 1][0] + nums[index])

            # Option 1: Start a new subarray.
            # Option 2: Square the current element.
            # Option 3: Do not square the element.
            dp[index][1] = max(
                max(
                    nums[index] * nums[index],
                    dp[index - 1][0] + nums[index] * nums[index],
                ),
                dp[index - 1][1] + nums[index],
            )

            # Update max_sum
            max_sum = max(max_sum, dp[index][1])

        return max_sum
```

</details>

<br>

## Approach 4: Space-optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array.

        // Initialize variables to store the maximum sums.
        int maxSumWithoutSquare = nums[0];
        int maxSumWithSquare = nums[0] * nums[0];
        int maxSum = maxSumWithSquare;

        for (int index = 1; index < n; index++) {
            // Option 1: Start a new subarray.
            // Option 2: Square the current element.
            // Option 3: Do not square the element.
            maxSumWithSquare =
                max(max(nums[index] * nums[index],
                        maxSumWithoutSquare + nums[index] * nums[index]),
                    maxSumWithSquare + nums[index]);

            // Option 1: Start a new subarray.
            // Option 2: Continue the previous subarray.
            maxSumWithoutSquare =
                max(nums[index], maxSumWithoutSquare + nums[index]);

            // Update maxSum
            maxSum = max(maxSum, maxSumWithSquare);
        }

        return maxSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxSumAfterOperation(int[] nums) {
        int n = nums.length; // Get the size of the input array.

        // Initialize variables to store the maximum sums.
        int maxSumWithoutSquare = nums[0];
        int maxSumWithSquare = nums[0] * nums[0];
        int maxSum = maxSumWithSquare;

        for (int index = 1; index < n; index++) {
            // Option 1: Square the current element.
            // Option 2: Add the square of the current element to the previous sum without a square.
            // Option 3: Add the current element to the previous sum with a square.
            maxSumWithSquare = Math.max(
                Math.max(
                    nums[index] * nums[index],
                    maxSumWithoutSquare + nums[index] * nums[index]
                ),
                maxSumWithSquare + nums[index]
            );

            // Option 1: Start a new subarray.
            // Option 2: Continue the previous subarray.
            maxSumWithoutSquare = Math.max(
                nums[index],
                maxSumWithoutSquare + nums[index]
            );

            // Update maxSum
            maxSum = Math.max(maxSum, maxSumWithSquare);
        }

        return maxSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumAfterOperation(self, nums: list[int]) -> int:
        n = len(nums)  # Get the size of the input array.

        # Initialize variables to store the maximum sums.
        max_sum_without_square = nums[0]
        max_sum_with_square = nums[0] * nums[0]
        max_sum = max_sum_with_square

        for index in range(1, n):
            # Option 1: Square the current element.
            # Option 2: Add the square of the current element to the previous sum without a square.
            # Option 3: Add the current element to the previous sum with a square.
            max_sum_with_square = max(
                max(
                    nums[index] * nums[index],
                    max_sum_without_square + nums[index] * nums[index],
                ),
                max_sum_with_square + nums[index],
            )

            # Option 1: Start a new subarray.
            # Option 2: Continue the previous subarray.
            max_sum_without_square = max(
                nums[index], max_sum_without_square + nums[index]
            )

            # Update max_sum to track the global maximum sum with exactly one squared element.
            max_sum = max(max_sum, max_sum_with_square)

        return max_sum
```

</details>
