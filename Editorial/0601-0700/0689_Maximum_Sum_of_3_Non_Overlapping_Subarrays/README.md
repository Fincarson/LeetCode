# 689. Maximum Sum of 3 Non-Overlapping Subarrays

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/)  
`Array` `Dynamic Programming` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 689 - Maximum Sum of 3 Non-Overlapping Subarrays](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/)

## Problem

Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

### Example 1

```text
Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
```

### Example 2

```text
Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]
```

## Constraints

- 1 <= nums.length <= 2 * 104
- 1 <= nums[i] < 216
- 1 <= k <= floor(nums.length / 3)

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Sum of Variable Length Subarrays](https://leetcode.com/problems/sum-of-variable-length-subarrays/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Maximize YÃ¢â‚¬â€˜Sum by Picking a Triplet of Distinct XÃ¢â‚¬â€˜Values](https://leetcode.com/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 689. Maximum Sum of 3 Non-Overlapping Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Memoization | C++, Java, Python3 |
| Tabulation | C++, Java, Python3 |
| Three Pointers | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |

## Approach 1: Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // Number of possible subarray starting positions
        int n = nums.size() - k + 1;

        // Calculate sum of all possible k-length subarrays
        vector<int> sums(n);
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        sums[0] = windowSum;

        // Sliding window to calculate remaining sums
        for (int i = k; i < nums.size(); i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            sums[i - k + 1] = windowSum;
        }

        // memo[i][j]: max sum possible starting from index i with j subarrays
        // remaining
        vector<vector<int>> memo(n, vector<int>(4, -1));
        vector<int> indices;

        // First find optimal sum using DP
        dp(sums, k, 0, 3, memo);

        // Then reconstruct the path to find indices
        dfs(sums, k, 0, 3, memo, indices);

        return indices;
    }

private:
    // DP function to find maximum possible sum
    int dp(vector<int>& sums, int k, int idx, int rem,
           vector<vector<int>>& memo) {
        if (rem == 0) return 0;
        if (idx >= sums.size()) {
            return rem > 0 ? INT_MIN : 0;
        }

        if (memo[idx][rem] != -1) {
            return memo[idx][rem];
        }

        // Try taking current subarray vs skipping it
        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        memo[idx][rem] = max(withCurrent, skipCurrent);
        return memo[idx][rem];
    }

    // DFS to reconstruct the solution path
    void dfs(vector<int>& sums, int k, int idx, int rem,
             vector<vector<int>>& memo, vector<int>& indices) {
        if (rem == 0) return;
        if (idx >= sums.size()) return;

        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        // Choose path that gave optimal result in DP
        if (withCurrent >= skipCurrent) {  // Take current subarray
            indices.push_back(idx);
            dfs(sums, k, idx + k, rem - 1, memo, indices);
        } else {  // Skip current subarray
            dfs(sums, k, idx + 1, rem, memo, indices);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        // Number of possible subarray starting positions
        int n = nums.length - k + 1;

        // Calculate sum of all possible k-length subarrays
        int[] sums = new int[n];
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        sums[0] = windowSum;

        // Sliding window to calculate remaining sums
        for (int i = k; i < nums.length; i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            sums[i - k + 1] = windowSum;
        }

        // memo[i][j]: max sum possible starting from index i with j subarrays remaining
        int[][] memo = new int[n][4];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        List<Integer> indices = new ArrayList<>();

        // First find optimal sum using DP
        dp(sums, k, 0, 3, memo);

        // Then reconstruct the path to find indices
        dfs(sums, k, 0, 3, memo, indices);

        int[] result = new int[3];
        for (int i = 0; i < 3; i++) {
            result[i] = indices.get(i);
        }

        return result;
    }

    // DP function to find maximum possible sum
    private int dp(int[] sums, int k, int idx, int rem, int[][] memo) {
        if (rem == 0) return 0;
        if (idx >= sums.length) {
            return rem > 0 ? Integer.MIN_VALUE : 0;
        }

        if (memo[idx][rem] != -1) {
            return memo[idx][rem];
        }

        // Try taking current subarray vs skipping it
        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        memo[idx][rem] = Math.max(withCurrent, skipCurrent);
        return memo[idx][rem];
    }

    // DFS to reconstruct the solution path
    private void dfs(
        int[] sums,
        int k,
        int idx,
        int rem,
        int[][] memo,
        List<Integer> indices
    ) {
        if (rem == 0) return;
        if (idx >= sums.length) return;

        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        // Choose path that gave optimal result in DP
        if (withCurrent >= skipCurrent) { // Take current subarray
            indices.add(idx);
            dfs(sums, k, idx + k, rem - 1, memo, indices);
        } else { // Skip current subarray
            dfs(sums, k, idx + 1, rem, memo, indices);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        # Number of possible subarray starting positions
        n = len(nums) - k + 1

        # Calculate sum of all possible k-length subarrays
        sums = [sum(nums[:k])]
        for i in range(k, len(nums)):
            sums.append(sums[-1] - nums[i - k] + nums[i])

        # memo[i][j]: max sum possible starting from index i with j subarrays remaining
        memo = [[-1] * 4 for _ in range(n)]
        indices = []

        # First find optimal sum using DP
        self._dp(sums, k, 0, 3, memo)

        # Then reconstruct the path to find indices
        self._dfs(sums, k, 0, 3, memo, indices)

        return indices

    def _dp(self, sums, k, idx, rem, memo):
        if rem == 0:
            return 0
        if idx >= len(sums):
            return float("-inf") if rem > 0 else 0

        if memo[idx][rem] != -1:
            return memo[idx][rem]

        # Try taking current subarray vs skipping it
        with_current = sums[idx] + self._dp(sums, k, idx + k, rem - 1, memo)
        skip_current = self._dp(sums, k, idx + 1, rem, memo)

        memo[idx][rem] = max(with_current, skip_current)
        return memo[idx][rem]

    def _dfs(self, sums, k, idx, rem, memo, indices):
        if rem == 0 or idx >= len(sums):
            return

        with_current = sums[idx] + self._dp(sums, k, idx + k, rem - 1, memo)
        skip_current = self._dp(sums, k, idx + 1, rem, memo)

        # Choose path that gave optimal result in DP
        if with_current >= skip_current:  # Take current subarray
            indices.append(idx)
            self._dfs(sums, k, idx + k, rem - 1, memo, indices)
        else:  # Skip current subarray
            self._dfs(sums, k, idx + 1, rem, memo, indices)
```

</details>

<br>

## Approach 2: Tabulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Prefix sum array to calculate sum of any subarray in O(1) time
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Arrays to store the best sum and starting indices for up to 3
        // subarrays
        vector<vector<int>> bestSum(4, vector<int>(n + 1, 0));
        vector<vector<int>> bestIndex(4, vector<int>(n + 1, 0));

        // Compute the best sum and indices for 1, 2, and 3 subarrays
        for (int subarrayCount = 1; subarrayCount <= 3; subarrayCount++) {
            for (int endIndex = k * subarrayCount; endIndex <= n; endIndex++) {
                int currentSum = prefixSum[endIndex] - prefixSum[endIndex - k] +
                                 bestSum[subarrayCount - 1][endIndex - k];

                // Check if the current configuration gives a better sum
                if (currentSum > bestSum[subarrayCount][endIndex - 1]) {
                    bestSum[subarrayCount][endIndex] = currentSum;
                    bestIndex[subarrayCount][endIndex] = endIndex - k;
                } else {
                    bestSum[subarrayCount][endIndex] =
                        bestSum[subarrayCount][endIndex - 1];
                    bestIndex[subarrayCount][endIndex] =
                        bestIndex[subarrayCount][endIndex - 1];
                }
            }
        }

        // Trace back the indices of the three subarrays
        vector<int> result(3, 0);
        int currentEnd = n;
        for (int subarrayIndex = 3; subarrayIndex >= 1; subarrayIndex--) {
            result[subarrayIndex - 1] = bestIndex[subarrayIndex][currentEnd];
            currentEnd = result[subarrayIndex - 1];
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

    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;

        // Prefix sum array to calculate sum of any subarray in constant time
        int[] prefixSum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Arrays to store the best sum and starting indices for up to 3 subarrays
        int[][] bestSum = new int[4][n + 1];
        int[][] bestIndex = new int[4][n + 1];

        // Compute the best sum and indices for 1, 2, and 3 subarrays
        for (int subarrayCount = 1; subarrayCount <= 3; subarrayCount++) {
            for (int endIndex = k * subarrayCount; endIndex <= n; endIndex++) {
                int currentSum =
                    prefixSum[endIndex] -
                    prefixSum[endIndex - k] +
                    bestSum[subarrayCount - 1][endIndex - k];

                // Check if the current configuration gives a better sum
                if (currentSum > bestSum[subarrayCount][endIndex - 1]) {
                    bestSum[subarrayCount][endIndex] = currentSum;
                    bestIndex[subarrayCount][endIndex] = endIndex - k;
                } else {
                    bestSum[subarrayCount][endIndex] =
                        bestSum[subarrayCount][endIndex - 1];
                    bestIndex[subarrayCount][endIndex] =
                        bestIndex[subarrayCount][endIndex - 1];
                }
            }
        }

        // Trace back the indices of the three subarrays
        int[] result = new int[3];
        int currentEnd = n;
        for (int subarrayIndex = 3; subarrayIndex >= 1; subarrayIndex--) {
            result[subarrayIndex - 1] = bestIndex[subarrayIndex][currentEnd];
            currentEnd = result[subarrayIndex - 1];
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

    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)

        # Prefix sum array to calculate sum of any subarray in O(1) time
        prefix_sum = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1]

        # Arrays to store the best sum and starting indices for up to 3 subarrays
        best_sum = [[0] * (n + 1) for _ in range(4)]
        best_index = [[0] * (n + 1) for _ in range(4)]

        # Compute the best sum and indices for 1, 2, and 3 subarrays
        for t in range(1, 4):
            for i in range(k * t, n + 1):
                current_sum = (
                    prefix_sum[i] - prefix_sum[i - k] + best_sum[t - 1][i - k]
                )

                # Check if the current configuration gives a better sum
                if current_sum > best_sum[t][i - 1]:
                    best_sum[t][i] = current_sum
                    best_index[t][i] = i - k
                else:
                    best_sum[t][i] = best_sum[t][i - 1]
                    best_index[t][i] = best_index[t][i - 1]

        # Trace back the indices of the three subarrays
        result = [0] * 3
        end = n
        for t in range(3, 0, -1):
            result[t - 1] = best_index[t][end]
            end = result[t - 1]

        return result
```

</details>

<br>

## Approach 3: Three Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = 0;

        // Prefix sum array to calculate sum of any subarray
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Arrays to store the best starting index for the left and right
        // subarrays
        vector<int> leftMaxIndex(n);
        vector<int> rightMaxIndex(n);

        // Result array to store the starting indices of the three subarrays
        vector<int> result(3);

        // Calculate the best starting index for the left subarray for each
        // position
        for (int i = k, currentMaxSum = prefixSum[k] - prefixSum[0]; i < n;
             i++) {
            if (prefixSum[i + 1] - prefixSum[i + 1 - k] > currentMaxSum) {
                leftMaxIndex[i] = i + 1 - k;
                currentMaxSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            } else {
                leftMaxIndex[i] = leftMaxIndex[i - 1];
            }
        }

        // Calculate the best starting index for the right subarray for each
        // position
        rightMaxIndex[n - k] = n - k;
        for (int i = n - k - 1, currentMaxSum = prefixSum[n] - prefixSum[n - k];
             i >= 0; i--) {
            if (prefixSum[i + k] - prefixSum[i] >= currentMaxSum) {
                rightMaxIndex[i] = i;
                currentMaxSum = prefixSum[i + k] - prefixSum[i];
            } else {
                rightMaxIndex[i] = rightMaxIndex[i + 1];
            }
        }

        // Iterate over the middle subarray and calculate the total sum for all
        // valid combinations
        for (int i = k; i <= n - 2 * k; i++) {
            int leftIndex = leftMaxIndex[i - 1];
            int rightIndex = rightMaxIndex[i + k];
            int totalSum = (prefixSum[i + k] - prefixSum[i]) +
                           (prefixSum[leftIndex + k] - prefixSum[leftIndex]) +
                           (prefixSum[rightIndex + k] - prefixSum[rightIndex]);

            if (totalSum > maxSum) {
                maxSum = totalSum;
                result[0] = leftIndex;
                result[1] = i;
                result[2] = rightIndex;
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

    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int maxSum = 0;

        // Prefix sum array to calculate sum of any subarray
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Arrays to store the best starting index for the left and right subarrays
        int[] leftMaxIndex = new int[n];
        int[] rightMaxIndex = new int[n];

        // Result array to store the starting indices of the three subarrays
        int[] result = new int[3];

        // Calculate the best starting index for the left subarray for each position
        for (
            int i = k, currentMaxSum = prefixSum[k] - prefixSum[0];
            i < n;
            i++
        ) {
            if (prefixSum[i + 1] - prefixSum[i + 1 - k] > currentMaxSum) {
                leftMaxIndex[i] = i + 1 - k;
                currentMaxSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            } else {
                leftMaxIndex[i] = leftMaxIndex[i - 1];
            }
        }

        // Calculate the best starting index for the right subarray for each position
        rightMaxIndex[n - k] = n - k;
        for (
            int i = n - k - 1, currentMaxSum = prefixSum[n] - prefixSum[n - k];
            i >= 0;
            i--
        ) {
            if (prefixSum[i + k] - prefixSum[i] >= currentMaxSum) {
                rightMaxIndex[i] = i;
                currentMaxSum = prefixSum[i + k] - prefixSum[i];
            } else {
                rightMaxIndex[i] = rightMaxIndex[i + 1];
            }
        }

        // Iterate over the middle subarray and calculate the total sum for all valid combinations
        for (int i = k; i <= n - 2 * k; i++) {
            int leftIndex = leftMaxIndex[i - 1];
            int rightIndex = rightMaxIndex[i + k];
            int totalSum =
                (prefixSum[i + k] - prefixSum[i]) +
                (prefixSum[leftIndex + k] - prefixSum[leftIndex]) +
                (prefixSum[rightIndex + k] - prefixSum[rightIndex]);

            if (totalSum > maxSum) {
                maxSum = totalSum;
                result[0] = leftIndex;
                result[1] = i;
                result[2] = rightIndex;
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
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        max_sum = 0

        # Create prefix sum array using accumulate
        prefix_sum = [0] + list(accumulate(nums))

        # Initialize arrays for best indices
        left_max_idx = [0] * n
        right_max_idx = [0] * n
        result = [0] * 3

        # Calculate best left subarray positions
        curr_max_sum = prefix_sum[k] - prefix_sum[0]
        for i in range(k, n):
            curr_sum = prefix_sum[i + 1] - prefix_sum[i + 1 - k]
            if curr_sum > curr_max_sum:
                left_max_idx[i] = i + 1 - k
                curr_max_sum = curr_sum
            else:
                left_max_idx[i] = left_max_idx[i - 1]

        # Calculate best right subarray positions
        right_max_idx[n - k] = n - k
        curr_max_sum = prefix_sum[n] - prefix_sum[n - k]
        for i in range(n - k - 1, -1, -1):
            curr_sum = prefix_sum[i + k] - prefix_sum[i]
            if curr_sum >= curr_max_sum:
                right_max_idx[i] = i
                curr_max_sum = curr_sum
            else:
                right_max_idx[i] = right_max_idx[i + 1]

        # Find optimal middle position
        for i in range(k, n - 2 * k + 1):
            left_idx = left_max_idx[i - 1]
            right_idx = right_max_idx[i + k]
            total_sum = (
                prefix_sum[i + k]
                - prefix_sum[i]
                + prefix_sum[left_idx + k]
                - prefix_sum[left_idx]
                + prefix_sum[right_idx + k]
                - prefix_sum[right_idx]
            )

            if total_sum > max_sum:
                max_sum = total_sum
                result = [left_idx, i, right_idx]

        return result
```

</details>

<br>

## Approach 4: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // Variables to track the best indices for one, two, and three subarray
        // configurations
        int bestSingleStart = 0;
        vector<int> bestDoubleStart = {0, k};
        vector<int> bestTripleStart = {0, k, k * 2};

        // Compute the initial sums for the first three subarrays
        int currentWindowSumSingle = 0;
        for (int i = 0; i < k; i++) {
            currentWindowSumSingle += nums[i];
        }

        int currentWindowSumDouble = 0;
        for (int i = k; i < k * 2; i++) {
            currentWindowSumDouble += nums[i];
        }

        int currentWindowSumTriple = 0;
        for (int i = k * 2; i < k * 3; i++) {
            currentWindowSumTriple += nums[i];
        }

        // Track the best sums found so far
        int bestSingleSum = currentWindowSumSingle;
        int bestDoubleSum = currentWindowSumSingle + currentWindowSumDouble;
        int bestTripleSum = currentWindowSumSingle + currentWindowSumDouble +
                            currentWindowSumTriple;

        // Sliding window pointers for the subarrays
        int singleStartIndex = 1;
        int doubleStartIndex = k + 1;
        int tripleStartIndex = k * 2 + 1;

        // Slide the windows across the array
        while (tripleStartIndex <= nums.size() - k) {
            // Update the sums using the sliding window technique
            currentWindowSumSingle = currentWindowSumSingle -
                                     nums[singleStartIndex - 1] +
                                     nums[singleStartIndex + k - 1];
            currentWindowSumDouble = currentWindowSumDouble -
                                     nums[doubleStartIndex - 1] +
                                     nums[doubleStartIndex + k - 1];
            currentWindowSumTriple = currentWindowSumTriple -
                                     nums[tripleStartIndex - 1] +
                                     nums[tripleStartIndex + k - 1];

            // Update the best single subarray start index if a better sum is
            // found
            if (currentWindowSumSingle > bestSingleSum) {
                bestSingleStart = singleStartIndex;
                bestSingleSum = currentWindowSumSingle;
            }

            // Update the best double subarray start indices if a better sum is
            // found
            if (currentWindowSumDouble + bestSingleSum > bestDoubleSum) {
                bestDoubleStart[0] = bestSingleStart;
                bestDoubleStart[1] = doubleStartIndex;
                bestDoubleSum = currentWindowSumDouble + bestSingleSum;
            }

            // Update the best triple subarray start indices if a better sum is
            // found
            if (currentWindowSumTriple + bestDoubleSum > bestTripleSum) {
                bestTripleStart[0] = bestDoubleStart[0];
                bestTripleStart[1] = bestDoubleStart[1];
                bestTripleStart[2] = tripleStartIndex;
                bestTripleSum = currentWindowSumTriple + bestDoubleSum;
            }

            // Move the sliding windows forward
            singleStartIndex += 1;
            doubleStartIndex += 1;
            tripleStartIndex += 1;
        }

        // Return the starting indices of the three subarrays with the maximum
        // sum
        return bestTripleStart;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        // Variables to track the best indices for one, two, and three subarray configurations
        int bestSingleStart = 0;
        int[] bestDoubleStart = { 0, k };
        int[] bestTripleStart = { 0, k, k * 2 };

        // Compute the initial sums for the first three subarrays
        int currentWindowSumSingle = 0;
        for (int i = 0; i < k; i++) {
            currentWindowSumSingle += nums[i];
        }

        int currentWindowSumDouble = 0;
        for (int i = k; i < k * 2; i++) {
            currentWindowSumDouble += nums[i];
        }

        int currentWindowSumTriple = 0;
        for (int i = k * 2; i < k * 3; i++) {
            currentWindowSumTriple += nums[i];
        }

        // Track the best sums found so far
        int bestSingleSum = currentWindowSumSingle;
        int bestDoubleSum = currentWindowSumSingle + currentWindowSumDouble;
        int bestTripleSum =
            currentWindowSumSingle +
            currentWindowSumDouble +
            currentWindowSumTriple;

        // Sliding window pointers for the subarrays
        int singleStartIndex = 1;
        int doubleStartIndex = k + 1;
        int tripleStartIndex = k * 2 + 1;

        // Slide the windows across the array
        while (tripleStartIndex <= nums.length - k) {
            // Update the sums using the sliding window technique
            currentWindowSumSingle =
                currentWindowSumSingle -
                nums[singleStartIndex - 1] +
                nums[singleStartIndex + k - 1];
            currentWindowSumDouble =
                currentWindowSumDouble -
                nums[doubleStartIndex - 1] +
                nums[doubleStartIndex + k - 1];
            currentWindowSumTriple =
                currentWindowSumTriple -
                nums[tripleStartIndex - 1] +
                nums[tripleStartIndex + k - 1];

            // Update the best single subarray start index if a better sum is found
            if (currentWindowSumSingle > bestSingleSum) {
                bestSingleStart = singleStartIndex;
                bestSingleSum = currentWindowSumSingle;
            }

            // Update the best double subarray start indices if a better sum is found
            if (currentWindowSumDouble + bestSingleSum > bestDoubleSum) {
                bestDoubleStart[0] = bestSingleStart;
                bestDoubleStart[1] = doubleStartIndex;
                bestDoubleSum = currentWindowSumDouble + bestSingleSum;
            }

            // Update the best triple subarray start indices if a better sum is found
            if (currentWindowSumTriple + bestDoubleSum > bestTripleSum) {
                bestTripleStart[0] = bestDoubleStart[0];
                bestTripleStart[1] = bestDoubleStart[1];
                bestTripleStart[2] = tripleStartIndex;
                bestTripleSum = currentWindowSumTriple + bestDoubleSum;
            }

            // Move the sliding windows forward
            singleStartIndex += 1;
            doubleStartIndex += 1;
            tripleStartIndex += 1;
        }

        // Return the starting indices of the three subarrays with the maximum sum
        return bestTripleStart;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        # Variables to track the best indices for one, two, and three subarray configurations
        best_single_start = 0
        best_double_start = [0, k]
        best_triple_start = [0, k, k * 2]

        # Compute the initial sums for the first three subarrays
        current_window_sum_single = sum(nums[:k])
        current_window_sum_double = sum(nums[k : k * 2])
        current_window_sum_triple = sum(nums[k * 2 : k * 3])

        # Track the best sums found so far
        best_single_sum = current_window_sum_single
        best_double_sum = current_window_sum_single + current_window_sum_double
        best_triple_sum = (
            current_window_sum_single
            + current_window_sum_double
            + current_window_sum_triple
        )

        # Sliding window pointers for the subarrays
        single_start_index = 1
        double_start_index = k + 1
        triple_start_index = k * 2 + 1

        # Slide the windows across the array
        while triple_start_index <= len(nums) - k:
            # Update the sums using the sliding window technique
            current_window_sum_single = (
                current_window_sum_single
                - nums[single_start_index - 1]
                + nums[single_start_index + k - 1]
            )
            current_window_sum_double = (
                current_window_sum_double
                - nums[double_start_index - 1]
                + nums[double_start_index + k - 1]
            )
            current_window_sum_triple = (
                current_window_sum_triple
                - nums[triple_start_index - 1]
                + nums[triple_start_index + k - 1]
            )

            # Update the best single subarray start index if a better sum is found
            if current_window_sum_single > best_single_sum:
                best_single_start = single_start_index
                best_single_sum = current_window_sum_single

            # Update the best double subarray start indices if a better sum is found
            if current_window_sum_double + best_single_sum > best_double_sum:
                best_double_start[0] = best_single_start
                best_double_start[1] = double_start_index
                best_double_sum = current_window_sum_double + best_single_sum

            # Update the best triple subarray start indices if a better sum is found
            if current_window_sum_triple + best_double_sum > best_triple_sum:
                best_triple_start[0] = best_double_start[0]
                best_triple_start[1] = best_double_start[1]
                best_triple_start[2] = triple_start_index
                best_triple_sum = current_window_sum_triple + best_double_sum

            # Move the sliding windows forward
            single_start_index += 1
            double_start_index += 1
            triple_start_index += 1

        # Return the starting indices of the three subarrays with the maximum sum
        return best_triple_start
```

</details>
