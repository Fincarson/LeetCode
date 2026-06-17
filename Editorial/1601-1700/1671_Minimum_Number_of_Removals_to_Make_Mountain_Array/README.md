# 1671. Minimum Number of Removals to Make Mountain Array

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/)  
`Array` `Binary Search` `Dynamic Programming` `Greedy`

**Problem Link:** [LeetCode 1671 - Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/)

## Problem

You may recall that an array arr is a mountain array if and only if:

- arr.length >= 3
- There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:

		arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given an integer array numsÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹, return the minimum number of elements to remove to make numsÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ a mountain array.

### Example 1

```text
Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.
```

### Example 2

```text
Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
```

## Constraints

- 3 <= nums.length <= 1000
- 1 <= nums[i] <= 109
- It is guaranteed that you can make a mountain array out of nums.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Mountain in Array](https://leetcode.com/problems/longest-mountain-in-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Beautiful Towers II](https://leetcode.com/problems/beautiful-towers-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Beautiful Towers I](https://leetcode.com/problems/beautiful-towers-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1671. Minimum Number of Removals to Make Mountain Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| LIS Using Dynamic Programming | C++, Java, Python3 |
| LIS Using Binary Search | C++, Java, Python3 |

## Approach 1: LIS Using Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();

        vector<int> lisLength(N, 1);
        vector<int> ldsLength(N, 1);

        // Stores the length of longest increasing subsequence that ends at i.
        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    lisLength[i] = max(lisLength[i], lisLength[j] + 1);
                }
            }
        }

        // Stores the length of longest decreasing subsequence that starts at i.
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                if (nums[i] > nums[j]) {
                    ldsLength[i] = max(ldsLength[i], ldsLength[j] + 1);
                }
            }
        }

        int minRemovals = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (lisLength[i] > 1 && ldsLength[i] > 1) {
                minRemovals =
                    min(minRemovals, N - lisLength[i] - ldsLength[i] + 1);
            }
        }

        return minRemovals;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumMountainRemovals(int[] nums) {
        int N = nums.length;

        int[] lisLength = new int[N];
        int[] ldsLength = new int[N];

        Arrays.fill(lisLength, 1);
        Arrays.fill(ldsLength, 1);

        // Stores the length of longest increasing subsequence that ends at i.
        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    lisLength[i] = Math.max(lisLength[i], lisLength[j] + 1);
                }
            }
        }

        // Stores the length of longest decreasing subsequence that starts at i.
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                if (nums[i] > nums[j]) {
                    ldsLength[i] = Math.max(ldsLength[i], ldsLength[j] + 1);
                }
            }
        }

        int minRemovals = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            if (lisLength[i] > 1 && ldsLength[i] > 1) {
                minRemovals = Math.min(
                    minRemovals,
                    N - lisLength[i] - ldsLength[i] + 1
                );
            }
        }

        return minRemovals;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        N = len(nums)

        lis_length = [1] * N
        lds_length = [1] * N

        # Stores the length of longest increasing subsequence that ends at i.
        for i in range(N):
            for j in range(i):
                if nums[i] > nums[j]:
                    lis_length[i] = max(lis_length[i], lis_length[j] + 1)

        # Stores the length of longest decreasing subsequence that starts at i.
        for i in range(N - 1, -1, -1):
            for j in range(i + 1, N):
                if nums[i] > nums[j]:
                    lds_length[i] = max(lds_length[i], lds_length[j] + 1)

        min_removals = float("inf")
        for i in range(N):
            if lis_length[i] > 1 and lds_length[i] > 1:
                min_removals = min(
                    min_removals, N - lis_length[i] - lds_length[i] + 1
                )

        return min_removals
```

</details>

<br>

## Approach 2: LIS Using Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getLongestIncreasingSubsequenceLength(vector<int>& v) {
        vector<int> lisLen(v.size(), 1);
        vector<int> lis = {v[0]};

        for (int i = 1; i < v.size(); i++) {
            // Index of the first element which is equal to or greater than
            // v[i].
            int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();

            // Add to the list if v[i] is greater than the last element.
            if (index == lis.size()) {
                lis.push_back(v[i]);
            } else {
                // Assign the value v[i] to the returned index as it's going to
                // smaller than or equal to the existing element.
                lis[index] = v[i];
            }

            lisLen[i] = lis.size();
        }

        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        vector<int> lisLength = getLongestIncreasingSubsequenceLength(nums);

        reverse(nums.begin(), nums.end());
        vector<int> ldsLength = getLongestIncreasingSubsequenceLength(nums);
        // Reverse the length array to correctly depict the lenght of longest
        // decreasing subsequence for each index.
        reverse(ldsLength.begin(), ldsLength.end());

        int minRemovals = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (lisLength[i] > 1 && ldsLength[i] > 1) {
                minRemovals =
                    min(minRemovals, N - lisLength[i] - ldsLength[i] + 1);
            }
        }

        return minRemovals;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private List<Integer> getLongestIncreasingSubsequenceLength(
        List<Integer> v
    ) {
        List<Integer> lisLen = new ArrayList<>(
            Collections.nCopies(v.size(), 1)
        );
        List<Integer> lis = new ArrayList<>();
        lis.add(v.get(0));

        for (int i = 1; i < v.size(); i++) {
            int index = lowerBound(lis, v.get(i));

            // Add to the list if v[i] is greater than the last element
            if (index == lis.size()) {
                lis.add(v.get(i));
            } else {
                // Replace the element at index with v[i]
                lis.set(index, v.get(i));
            }

            lisLen.set(i, lis.size());
        }

        return lisLen;
    }

    // Returns the index of the first element which is equal to or greater than target.
    private int lowerBound(List<Integer> lis, int target) {
        int left = 0, right = lis.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (lis.get(mid) >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    public int minimumMountainRemovals(int[] nums) {
        int N = nums.length;
        List<Integer> numsList = new ArrayList<>();
        for (int num : nums) numsList.add(num);

        List<Integer> lisLength = getLongestIncreasingSubsequenceLength(
            numsList
        );

        Collections.reverse(numsList);
        List<Integer> ldsLength = getLongestIncreasingSubsequenceLength(
            numsList
        );
        // Reverse the length array to correctly depict the length of longest decreasing subsequence for each index.
        Collections.reverse(ldsLength);

        int minRemovals = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            if (lisLength.get(i) > 1 && ldsLength.get(i) > 1) {
                minRemovals = Math.min(
                    minRemovals,
                    N - lisLength.get(i) - ldsLength.get(i) + 1
                );
            }
        }

        return minRemovals;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getLongestIncreasingSubsequenceLength(self, v: List[int]) -> List[int]:
        lis_len = [1] * len(v)
        lis = [v[0]]

        for i in range(1, len(v)):
            index = self.lowerBound(lis, v[i])

            # Add to the list if v[i] is greater than the last element
            if index == len(lis):
                lis.append(v[i])
            else:
                # Replace the element at index with v[i]
                lis[index] = v[i]

            lis_len[i] = len(lis)

        return lis_len

    # Returns the index of the first element which is equal to or greater than target.
    def lowerBound(self, lis: List[int], target: int) -> int:
        left, right = 0, len(lis)
        while left < right:
            mid = left + (right - left) // 2
            if lis[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left

    def minimumMountainRemovals(self, nums: List[int]) -> int:
        N = len(nums)

        lis_length = self.getLongestIncreasingSubsequenceLength(nums)

        nums.reverse()
        lds_length = self.getLongestIncreasingSubsequenceLength(nums)
        # Reverse the length array to correctly depict the length of longest decreasing subsequence for each index.
        lds_length.reverse()

        min_removals = float("inf")
        for i in range(N):
            if lis_length[i] > 1 and lds_length[i] > 1:
                min_removals = min(
                    min_removals, N - lis_length[i] - lds_length[i] + 1
                )

        return min_removals
```

</details>
