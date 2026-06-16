# 2090. K Radius Subarray Averages

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/k-radius-subarray-averages/)  
`Array` `Sliding Window`

**Problem Link:** [LeetCode 2090 - K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages/)

## Problem

You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.

- For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.

### Example 1

```text
Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]
Explanation:
- avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
- The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
  Using integer division, avg[3] = 37 / 7 = 5.
- For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
- For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
- avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.
```

### Example 2

```text
Input: nums = [100000], k = 0
Output: [100000]
Explanation:
- The sum of the subarray centered at index 0 with radius 0 is: 100000.
  avg[0] = 100000 / 1 = 100000.
```

### Example 3

```text
Input: nums = [8], k = 100000
Output: [-1]
Explanation:
- avg[0] is -1 because there are less than k elements before and after index 0.
```

## Constraints

- n == nums.length
- 1 <= n <= 105
- 0 <= nums[i], k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Moving Average from Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Grid of Region Average](https://leetcode.com/problems/find-the-grid-of-region-average/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2090. K Radius Subarray Averages

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sum | C++, Java, JavaScript, Python3, TypeScript |
| Sliding Window | C++, Java, JavaScript, Python3, TypeScript |

## Approach 1: Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // When a single element is considered then its average will be the number itself only.
        if (k == 0) {
            return nums;
        }

        int windowSize = 2 * k + 1;
        int n = nums.size();
        vector<int> averages(n, -1);

        // Any index will not have 'k' elements in it's left and right.
        if (windowSize > n) {
            return averages;
        }

        // Generate 'prefix' array for 'nums'.
        // 'prefix[i + 1]' will be sum of all elements of 'nums' from index '0' to 'i'.
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        // We iterate only on those indices which have atleast 'k' elements in their left and right.
        // i.e. indices from 'k' to 'n - k'
        for (int i = k; i < (n - k); ++i) {
            int leftBound = i - k, rightBound = i + k;
            long long subArraySum = prefix[rightBound + 1] - prefix[leftBound];
            int average = subArraySum / windowSize;
            averages[i] = average;
        }

        return averages;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] getAverages(int[] nums, int k) {
        // When a single element is considered then its average will be the number itself only.
        if (k == 0) {
            return nums;
        }

        int windowSize = 2 * k + 1;
        int n = nums.length;
        int[] averages = new int[n];
        Arrays.fill(averages, -1);

        // Any index will not have 'k' elements in it's left and right.
        if (windowSize > n) {
            return averages;
        }

        // Generate 'prefix' array for 'nums'.
        // 'prefix[i + 1]' will be sum of all elements of 'nums' from index '0' to 'i'.
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // We iterate only on those indices which have atleast 'k' elements in their left and right.
        // i.e. indices from 'k' to 'n - k'
        for (int i = k; i < (n - k); ++i) {
            int leftBound = i - k, rightBound = i + k;
            long subArraySum = prefix[rightBound + 1] - prefix[leftBound];
            int average = (int) (subArraySum / windowSize);
            averages[i] = average;
        }

        return averages;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getAverages = function(nums, k) {
    // When a single element is considered then its average will be the number itself only.
    if (k === 0) {
        return nums;
    }
    
    const windowSize = 2 * k + 1
    const n = nums.length;
    const averages = new Array(n).fill(-1);

    // Any index will not have 'k' elements in its left and right.
    if (windowSize > n) {
        return averages;
    }

    // Generate 'prefix' array for 'nums'.
    // 'prefix[i + 1]' will be sum of all elements of 'nums' from index '0' to 'i'.
    const prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    // We iterate only on those indices which have at least 'k' elements in their left and right.
    // i.e. indices from 'k' to 'n - k'
    for (let i = k; i < (n - k); ++i) {
        const leftBound = i - k, rightBound = i + k;
        const subArraySum = prefix[rightBound + 1] - prefix[leftBound];
        const average = Math.floor(subArraySum / windowSize);
        averages[i] = average;
    }

    return averages;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        # When a single element is considered then its average will be the number itself only.
        if k == 0:
            return nums

        window_size = 2 * k + 1
        n = len(nums)
        averages = [-1] * n

        # Any index will not have 'k' elements in it's left and right.
        if window_size > n:
            return averages

        # Generate 'prefix' array for 'nums'.
        # 'prefix[i + 1]' will be sum of all elements of 'nums' from index '0' to 'i'.
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        # We iterate only on those indices which have atleast 'k' elements in their left and right.
        # i.e. indices from 'k' to 'n - k'
        for i in range(k, n - k):
            leftBound, rightBound = i - k, i + k
            subArraySum = prefix[rightBound + 1] - prefix[leftBound]
            average = subArraySum // window_size
            averages[i] = average

        return averages
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getAverages(nums: number[], k: number): number[] {
    // When a single element is considered then its average will be the number itself only.
    if (k === 0) {
        return nums;
    }

    const windowSize = 2 * k + 1;
    const n = nums.length;
    const averages = new Array(n).fill(-1);

    // Any index will not have 'k' elements in it's left and right.
    if (windowSize > n) {
        return averages;
    }

    // Generate 'prefix' array for 'nums'.
    // 'prefix[i + 1]' will be sum of all elements of 'nums' from index '0' to 'i'.
    const prefix: number[] = new Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // We iterate only on those indices which have atleast 'k' elements in their left and right.
    // i.e. indices from 'k' to 'n - k'
    for (let i = k; i < n - k; ++i) {
        const leftBound = i - k, rightBound = i + k;
        const subArraySum = prefix[rightBound + 1] - prefix[leftBound];
        const average = Math.floor(subArraySum / windowSize);
        averages[i] = average;
    }

    return averages;
};
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // When a single element is considered then its averafge will be the number itself only.
        if (k == 0) {
            return nums;
        }

        int windowSize = 2 * k + 1;
        int n = nums.size();
        vector<int> averages(n, -1);

        // Any index will not have 'k' elements in it's left and right.
        if (windowSize > n) {
            return averages;
        }

        // First get the sum of first window of the 'nums' arrray.
        long long windowSum = 0;
        for (int i = 0; i < windowSize; ++i) {
            windowSum += nums[i];
        }
        averages[k] = windowSum / windowSize;

        // Iterate on rest indices which have atlest 'k' elements 
        // on its left and right sides.
        for (int i = windowSize; i < n; ++i) {
            // We remove the discarded element and add the new element to get current window sum.
            // 'i' is the index of new inserted element, and
            // 'i - (window size)' is the index of the last removed element.
            windowSum = windowSum - nums[i - windowSize] + nums[i];
            averages[i - k] = windowSum / windowSize;
        }

        return averages;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] getAverages(int[] nums, int k) {
        // When a single element is considered then its average will be the number itself only.
        if (k == 0) {
            return nums;
        }

        int windowSize = 2 * k + 1;
        int n = nums.length;
        int[] averages = new int[n];
        Arrays.fill(averages, -1);

        // Any index will not have 'k' elements in its left and right.
        if (windowSize > n) {
            return averages;
        }

        // First get the sum of first window of the 'nums' array.
        long windowSum = 0;
        for (int i = 0; i < windowSize; ++i) {
            windowSum += nums[i];
        }
        averages[k] = (int) (windowSum / windowSize);

        // Iterate on rest indices which have at least 'k' elements 
        // on its left and right sides.
        for (int i = windowSize; i < n; ++i) {
            // We remove the discarded element and add the new element to get current window sum.
            // 'i' is the index of new inserted element, and
            // 'i - (window size)' is the index of the last removed element.
            windowSum = windowSum - nums[i - windowSize] + nums[i];
            averages[i - k] = (int) (windowSum / windowSize);
        }

        return averages;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getAverages = function(nums, k) {
    // When a single element is considered then its average will be the number itself only.
    if (k === 0) {
        return nums;
    }

    const windowSize = 2 * k + 1;
    const n = nums.length;
    const averages = new Array(n).fill(-1);

    // Any index will not have 'k' elements in its left and right.
    if (windowSize > n) {
        return averages;
    }

    // First get the sum of first window of the 'nums' array.
    let windowSum = 0;
    for (let i = 0; i < windowSize; ++i) {
        windowSum += nums[i];
    }
    averages[k] = Math.floor(windowSum / windowSize);

    // Iterate on rest indices which have at least 'k' elements 
    // on its left and right sides.
    for (let i = windowSize; i < n; ++i) {
        // We remove the discarded element and add the new element to get current window sum.
        // 'i' is the index of new inserted element, and
        // 'i - (window size)' is the index of the last removed element.
        windowSum = windowSum - nums[i - windowSize] + nums[i];
        averages[i - k] = Math.floor(windowSum / windowSize);
    }

    return averages;    
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        averages = [-1] * len(nums)
        # When a single element is considered then its average will be the number itself only.
        if k == 0:
            return nums

        window_size = 2 * k + 1
        n = len(nums)

        # Any index will not have 'k' elements in it's left and right.
        if window_size > n:
            return averages

        # First get the sum of first window of the 'nums' arrray.
        window_sum = sum(nums[:window_size])
        averages[k] = window_sum // window_size

        # Iterate on rest indices which have at least 'k' elements 
        # on its left and right sides.
        for i in range(window_size, n):
            # We remove the discarded element and add the new element to get current window sum.
            # 'i' is the index of new inserted element, and
            # 'i - (window size)' is the index of the last removed element.
            window_sum = window_sum - nums[i - window_size] + nums[i]
            averages[i - k] = window_sum // window_size

        return averages
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getAverages(nums: number[], k: number): number[] {
    // When a single element is considered then its average will be the number itself only.
    if (k === 0) {
        return nums;
    }

    const windowSize = 2 * k + 1;
    const n = nums.length;
    const averages: number[] = new Array(n).fill(-1);

    // Any index will not have 'k' elements in its left and right.
    if (windowSize > n) {
        return averages;
    }

    // First get the sum of first window of the 'nums' array.
    let windowSum = 0;
    for (let i = 0; i < windowSize; ++i) {
        windowSum += nums[i];
    }
    averages[k] = Math.floor(windowSum / windowSize);

    // Iterate on rest indices which have at least 'k' elements 
    // on its left and right sides.
    for (let i = windowSize; i < n; ++i) {
        // We remove the discarded element and add the new element to get current window sum.
        // 'i' is the index of new inserted element, and
        // 'i - (window size)' is the index of the last removed element.
        windowSum = windowSum - nums[i - windowSize] + nums[i];
        averages[i - k] = Math.floor(windowSum / windowSize);
    }

    return averages;
};
```

</details>
