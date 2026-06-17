# 719. Find K-th Smallest Pair Distance

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)  
`Array` `Two Pointers` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 719 - Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)

## Problem

The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

### Example 1

```text
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
```

### Example 2

```text
Input: nums = [1,1,1], k = 2
Output: 0
```

### Example 3

```text
Input: nums = [1,6,1], k = 3
Output: 5
```

## Constraints

- n == nums.length
- 2 <= n <= 104
- 0 <= nums[i] <= 106
- 1 <= k <= n * (n - 1) / 2

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Median of the Uniqueness Array](https://leetcode.com/problems/find-the-median-of-the-uniqueness-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximize Score of Numbers in Ranges](https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 719. Find K-th Smallest Pair Distance

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bucket Sort | C++, Java, Python3 |
| Binary Search + Dynamic Programming (DP) | C++, Java, Python3 |
| Binary Search + Sliding Window | C++, Java, Python3 |

## Approach 1: Bucket Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int arraySize = nums.size();

        // Find the maximum element in the array
        int maxElement = *max_element(nums.begin(), nums.end());

        // Initialize a bucket array to store counts of each distance
        vector<int> distanceBucket(maxElement + 1, 0);

        // Populate the bucket array with counts of each distance
        for (int i = 0; i < arraySize; ++i) {
            for (int j = i + 1; j < arraySize; ++j) {
                // Compute the distance between nums[i] and nums[j]
                int distance = abs(nums[i] - nums[j]);

                // Increment the count for this distance in the bucket
                ++distanceBucket[distance];
            }
        }

        // Find the k-th smallest distance
        for (int dist = 0; dist <= maxElement; ++dist) {
            // Reduce k by the number of pairs with the current distance
            k -= distanceBucket[dist];

            // If k is less than or equal to 0, return the current distance
            if (k <= 0) {
                return dist;
            }
        }
        return -1;  // Return -1 if no distance found, should not reach here
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int smallestDistancePair(int[] nums, int k) {
        int arrayLength = nums.length;

        // Find the maximum element in the array
        int maxElement = Integer.MIN_VALUE;
        for (int num : nums) {
            maxElement = Math.max(maxElement, num);
        }

        // Initialize a bucket array to store counts of each distance
        int[] distanceBucket = new int[maxElement + 1];

        // Populate the bucket array with counts of each distance
        for (int i = 0; i < arrayLength; ++i) {
            for (int j = i + 1; j < arrayLength; ++j) {
                // Compute the distance between nums[i] and nums[j]
                int distance = Math.abs(nums[i] - nums[j]);

                // Increment the count for this distance in the bucket
                ++distanceBucket[distance];
            }
        }

        // Find the k-th smallest distance
        for (int dist = 0; dist <= maxElement; ++dist) {
            // Reduce k by the number of pairs with the current distance
            k -= distanceBucket[dist];

            // If k is less than or equal to 0, return the current distance
            if (k <= 0) {
                return dist;
            }
        }

        return -1; // Return -1 if no distance found, should not reach here
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        list_size = len(nums)

        # Find the maximum element in the list
        max_element = max(nums)

        # Initialize a bucket list to store counts of each distance
        distance_bucket = [0] * (max_element + 1)

        # Populate the bucket list with counts of each distance
        for i in range(list_size):
            for j in range(i + 1, list_size):
                # Compute the distance between nums[i] and nums[j]
                distance = abs(nums[i] - nums[j])

                # Increment the count for this distance in the bucket
                distance_bucket[distance] += 1

        # Find the k-th smallest distance
        for dist in range(max_element + 1):
            # Reduce k by the number of pairs with the current distance
            k -= distance_bucket[dist]

            # If k is less than or equal to 0, return the current distance
            if k <= 0:
                return dist

        return -1  # Return -1 if no distance found, should not reach here
```

</details>

<br>

## Approach 2: Binary Search + Dynamic Programming (DP)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int arraySize = nums.size();

        // Largest element in the sorted array
        int maxElement = nums[arraySize - 1];

        // Maximum possible distance
        int maxPossibleDistance = maxElement * 2;

        // Initialize arrays for prefix counts and value counts
        vector<int> prefixCount(maxPossibleDistance, 0);
        unordered_map<int, int> valueCount;

        // Populate the prefixCount array
        int index = 0;
        for (int value = 0; value < maxPossibleDistance; ++value) {
            while (index < arraySize && nums[index] <= value) {
                ++index;
            }
            prefixCount[value] = index;
        }

        // Populate the valueCount map
        for (int i = 0; i < arraySize; ++i) {
            ++valueCount[nums[i]];
        }

        // Binary search for the k-th smallest distance
        int low = 0, high = maxElement;
        while (low < high) {
            int mid = (low + high) / 2;

            // Count pairs with distance <= mid
            int count = countPairs(nums, prefixCount, valueCount, mid);

            // Adjust binary search bounds based on count
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

private:
    // Count number of pairs with distance <= m
    int countPairs(vector<int>& nums, vector<int>& prefixCount,
                   unordered_map<int, int>& valueCount, int maxDistance) {
        int count = 0;
        int arraySize = nums.size();
        int index = 0;

        while (index < arraySize) {
            int currentValue = nums[index];
            int valueCountForCurrent = valueCount.at(currentValue);

            // Calculate pairs involving current value with distance <=
            // maxDistance
            int pairsWithLargerValues =
                prefixCount[currentValue + maxDistance] -
                prefixCount[currentValue];
            int pairsWithSameValues =
                valueCountForCurrent * (valueCountForCurrent - 1) / 2;

            count += pairsWithLargerValues * valueCountForCurrent +
                     pairsWithSameValues;

            // Skip duplicate values
            while (index + 1 < arraySize && nums[index] == nums[index + 1]) {
                ++index;
            }
            ++index;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int arraySize = nums.length;
        int maxElement = nums[arraySize - 1];

        // Number of computed prefixes
        int prefixCountSize = maxElement + 1;

        // Initialize prefix counts and value counts
        int[] prefixCount = new int[prefixCountSize];
        int[] valueCount = new int[prefixCountSize];

        // Compute prefix counts and value counts
        int prefixIndex = 0;
        for (int value = 0; value < prefixCountSize; ++value) {
            while (prefixIndex < arraySize && nums[prefixIndex] <= value) {
                ++prefixIndex;
            }
            prefixCount[value] = prefixIndex;
        }
        for (int i = 0; i < arraySize; ++i) {
            ++valueCount[nums[i]];
        }

        // Binary search to find kth smallest distance
        int left = 0;
        int right = maxElement;
        while (left < right) {
            int middle = (left + right) / 2;

            // Compute number of pairs with distance <= middle
            int count = countPairs(nums, prefixCount, valueCount, middle);

            // Adjust bounds for binary search
            if (count < k) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        return left;
    }

    private int countPairs(
        int[] nums,
        int[] prefixCount,
        int[] valueCount,
        int maxDistance
    ) {
        int count = 0;
        int arraySize = nums.length;
        int index = 0;
        while (index < arraySize) {
            int currentValue = nums[index];
            int valueCountForCurrent = valueCount[currentValue];
            int pairsWithLargerValues =
                prefixCount[Math.min(
                        currentValue + maxDistance,
                        prefixCount.length - 1
                    )] -
                prefixCount[currentValue];
            int pairsWithSameValues =
                (valueCountForCurrent * (valueCountForCurrent - 1)) / 2;
            count +=
            pairsWithLargerValues * valueCountForCurrent + pairsWithSameValues;
            while (index + 1 < arraySize && nums[index] == nums[index + 1]) {
                ++index;
            }
            ++index;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestDistancePair(self, nums, k):
        nums.sort()
        array_size = len(nums)

        # Highest element in the sorted array
        max_element = nums[-1]

        # Maximum possible distance
        max_possible_distance = max_element * 2

        # Initialize arrays for prefix counts and value counts
        prefix_count = [0] * max_possible_distance
        value_count = [0] * (max_element + 1)

        # Populate prefix count and value count
        index = 0
        for value in range(max_possible_distance):
            while index < array_size and nums[index] <= value:
                index += 1
            prefix_count[value] = index
        for i in range(array_size):
            value_count[nums[i]] += 1

        # Binary search to find kth smallest distance
        left, right = 0, max_element
        while left < right:
            mid = (left + right) // 2

            # Count pairs with distance <= mid
            count = self._count_pairs(nums, prefix_count, value_count, mid)

            # Adjust binary search bounds based on count
            if count < k:
                left = mid + 1
            else:
                right = mid
        return left

    def _count_pairs(self, nums, prefix_count, value_count, max_distance):
        count = 0
        array_size = len(nums)
        index = 0

        while index < array_size:
            current_value = nums[index]
            value_count_for_current = value_count[current_value]

            # Calculate pairs involving current value with distance <= max_distance
            pairs_with_larger_values = (
                prefix_count[
                    min(current_value + max_distance, len(prefix_count) - 1)
                ]
                - prefix_count[current_value]
            )
            pairs_with_same_values = (
                value_count_for_current * (value_count_for_current - 1) // 2
            )
            count += (
                pairs_with_larger_values * value_count_for_current
                + pairs_with_same_values
            )

            # Skip duplicate values
            while index + 1 < array_size and nums[index] == nums[index + 1]:
                index += 1
            index += 1

        return count
```

</details>

<br>

## Approach 3: Binary Search + Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int arraySize = nums.size();

        // Initialize binary search range
        int low = 0;
        int high = nums[arraySize - 1] - nums[0];

        while (low < high) {
            int mid = (low + high) / 2;

            // Count pairs with distance <= mid
            int count = countPairsWithMaxDistance(nums, mid);

            // Adjust binary search bounds based on count
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

private:
    // Count number of pairs with distance <= maxDistance using a moving window
    int countPairsWithMaxDistance(vector<int>& nums, int maxDistance) {
        int count = 0;
        int arraySize = nums.size();
        int left = 0;

        for (int right = 0; right < arraySize; ++right) {
            // Adjust the left pointer to maintain the window with distances <=
            // maxDistance
            while (nums[right] - nums[left] > maxDistance) {
                ++left;
            }
            // Add the number of valid pairs ending at the current right index
            count += right - left;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int arraySize = nums.length;

        // Initialize binary search range
        int low = 0;
        int high = nums[arraySize - 1] - nums[0];

        while (low < high) {
            int mid = (low + high) / 2;

            // Count pairs with distance <= mid
            int count = countPairsWithMaxDistance(nums, mid);

            // Adjust binary search bounds based on count
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    // Count number of pairs with distance <= maxDistance using a moving window
    private int countPairsWithMaxDistance(int[] nums, int maxDistance) {
        int count = 0;
        int arraySize = nums.length;
        int left = 0;

        for (int right = 0; right < arraySize; ++right) {
            // Adjust the left pointer to maintain the window with distances <=
            // maxDistance
            while (nums[right] - nums[left] > maxDistance) {
                ++left;
            }
            // Add the number of valid pairs ending at the current right index
            count += right - left;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        array_size = len(nums)

        # Initialize binary search range
        low = 0
        high = nums[array_size - 1] - nums[0]

        while low < high:
            mid = (low + high) // 2

            # Count pairs with distance <= mid
            count = self._count_pairs_with_max_distance(nums, mid)

            # Adjust binary search bounds based on count
            if count < k:
                low = mid + 1
            else:
                high = mid

        return low

    # Count number of pairs with distance <= max_distance using a moving window
    def _count_pairs_with_max_distance(
        self, nums: List[int], max_distance: int
    ) -> int:
        count = 0
        array_size = len(nums)
        left = 0

        for right in range(array_size):
            # Adjust the left pointer to maintain the window with distances <=
            # max_distance
            while nums[right] - nums[left] > max_distance:
                left += 1
            # Add the number of valid pairs ending at the current right index
            count += right - left
        return count
```

</details>
