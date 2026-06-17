# 1508. Range Sum of Sorted Subarray Sums

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/)  
`Array` `Two Pointers` `Binary Search` `Sorting` `Prefix Sum`

**Problem Link:** [LeetCode 1508 - Range Sum of Sorted Subarray Sums](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/)

## Problem

You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

### Example 1

```text
Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13.
```

### Example 2

```text
Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
```

### Example 3

```text
Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50
```

## Constraints

- n == nums.length
- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 100
- 1 <= left <= right <= n * (n + 1) / 2

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1508. Range Sum of Sorted Subarray Sums

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Priority Queue | C++, Java, Python3 |
| Binary Search and Sliding Window | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> storeSubarray;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            // Iterate through all indices ahead of the current index.
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                storeSubarray.push_back(sum);
            }
        }
        // Sort all subarray sum values in increasing order.
        sort(storeSubarray.begin(), storeSubarray.end());

        // Find the sum of all values between left and right.
        int rangeSum = 0, mod = 1e9 + 7;
        for (int i = left - 1; i <= right - 1; i++) {
            rangeSum = (rangeSum + storeSubarray[i]) % mod;
        }
        return rangeSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int rangeSum(int[] nums, int n, int left, int right) {
        ArrayList<Integer> storeSubarray = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            // Iterate through all indices ahead of the current index.
            for (int j = i; j < nums.length; j++) {
                sum += nums[j];
                storeSubarray.add(sum);
            }
        }
        // Sort all subarray sum values in increasing order.
        Collections.sort(storeSubarray);

        // Find the sum of all values between left and right.
        int rangeSum = 0, mod = (int) 1e9 + 7;
        for (int i = left - 1; i <= right - 1; i++) {
            rangeSum = (rangeSum + storeSubarray.get(i)) % mod;
        }
        return rangeSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        store_subarray = []
        for i in range(len(nums)):
            sum = 0
            # Iterate through all indices ahead of the current index.
            for j in range(i, len(nums)):
                sum += nums[j]
                store_subarray.append(sum)

        # Sort all subarray sum values in increasing order.
        store_subarray.sort()

        # Find the sum of all values between left and right.
        range_sum = 0
        mod = 10**9 + 7
        for i in range(left - 1, right):
            range_sum = (range_sum + store_subarray[i]) % mod
        return range_sum
```

</details>

<br>

## Approach 2: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});

        int ans = 0, mod = 1e9 + 7;
        for (int i = 1; i <= right; i++) {
            auto p = pq.top();
            pq.pop();
            // If the current index is greater than or equal to left, add the
            // value to the answer.
            if (i >= left) ans = (ans + p.first) % mod;
            // If index is less than the last index, increment it and add its
            // value to the first pair value.
            if (p.second < n - 1) {
                p.first += nums[++p.second];
                pq.push(p);
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

    public int rangeSum(int[] nums, int n, int left, int right) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    return o1[0] - o2[0];
                }
            }
        );
        for (int i = 0; i < n; i++) {
            pq.offer(new int[] { nums[i], i });
        }

        int ans = 0, mod = 1000000007;
        for (int i = 1; i <= right; i++) {
            int[] p = pq.poll();
            if (i >= left) ans = (ans + p[0]) % mod;
            if (p[1] < n - 1) {
                p[0] += nums[++p[1]];
                pq.offer(p);
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
    import heapq

    def rangeSum(self, nums, n, left, right):
        pq = []
        for i in range(n):
            heapq.heappush(pq, (nums[i], i))

        ans = 0
        mod = 1e9 + 7
        for i in range(1, right + 1):
            p = heapq.heappop(pq)
            # If the current index is greater than or equal to left, add the
            # value to the answer.
            if i >= left:
                ans = (ans + p[0]) % mod
            # If index is less than the last index, increment it and add its
            # value to the first pair value.
            if p[1] < n - 1:
                p = (p[0] + nums[p[1] + 1], p[1] + 1)
                heapq.heappush(pq, p)
        return int(ans)
```

</details>

<br>

## Approach 3: Binary Search and Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long result =
            (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) %
            mod;
        // Ensure non-negative result
        return (result + mod) % mod;
    }

private:
    int mod = 1e9 + 7;
    // Helper function to count subarrays with sum <= target and their total
    // sum.
    pair<int, long long> countAndSum(vector<int>& nums, int n, int target) {
        int count = 0;
        long long currentSum = 0, totalSum = 0, windowSum = 0;
        for (int j = 0, i = 0; j < n; ++j) {
            currentSum += nums[j];
            windowSum += nums[j] * (j - i + 1);
            while (currentSum > target) {
                windowSum -= currentSum;
                currentSum -= nums[i++];
            }
            count += j - i + 1;
            totalSum += windowSum;
        }
        return {count, totalSum};
    }

    // Helper function to find the sum of the first k smallest subarray sums.
    long long sumOfFirstK(vector<int>& nums, int n, int k) {
        int minSum = *min_element(nums.begin(), nums.end());
        int maxSum = accumulate(nums.begin(), nums.end(), 0);
        int left = minSum, right = maxSum;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countAndSum(nums, n, mid).first >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        auto [count, sum] = countAndSum(nums, n, left);
        // There can be more subarrays with the same sum of left.
        return sum - left * (count - k);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.*;

public class Solution {

    private static final int MOD = 1000000007;

    public int rangeSum(int[] nums, int n, int left, int right) {
        long result =
            (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) %
            MOD;
        // Ensure non-negative result
        return (int) ((result + MOD) % MOD);
    }

    // Helper function to count subarrays with sum <= target and their total sum.
    private Map.Entry<Integer, Long> countAndSum(
        int[] nums,
        int n,
        int target
    ) {
        int count = 0;
        long currentSum = 0, totalSum = 0, windowSum = 0;
        for (int j = 0, i = 0; j < n; ++j) {
            currentSum += nums[j];
            windowSum += nums[j] * (j - i + 1);
            while (currentSum > target) {
                windowSum -= currentSum;
                currentSum -= nums[i++];
            }
            count += j - i + 1;
            totalSum += windowSum;
        }
        return new AbstractMap.SimpleEntry<>(count, totalSum);
    }

    // Helper function to find the sum of the first k smallest subarray sums.
    private long sumOfFirstK(int[] nums, int n, int k) {
        int minSum = Arrays.stream(nums).min().getAsInt();
        int maxSum = Arrays.stream(nums).sum();
        int left = minSum, right = maxSum;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countAndSum(nums, n, mid).getKey() >= k) right = mid - 1;
            else left = mid + 1;
        }
        Map.Entry<Integer, Long> result = countAndSum(nums, n, left);
        // There can be more subarrays with the same sum of left.
        return result.getValue() - left * (result.getKey() - k);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rangeSum(self, nums, n, left, right):
        mod = 10**9 + 7

        def count_and_sum(nums, n, target):
            count = 0
            current_sum = 0
            total_sum = 0
            window_sum = 0
            i = 0
            for j in range(n):
                current_sum += nums[j]
                window_sum += nums[j] * (j - i + 1)
                while current_sum > target:
                    window_sum -= current_sum
                    current_sum -= nums[i]
                    i += 1
                count += j - i + 1
                total_sum += window_sum
            return count, total_sum

        def sum_of_first_k(nums, n, k):
            min_sum = min(nums)
            max_sum = sum(nums)
            left = min_sum
            right = max_sum

            while left <= right:
                mid = left + (right - left) // 2
                if count_and_sum(nums, n, mid)[0] >= k:
                    right = mid - 1
                else:
                    left = mid + 1
            count, total_sum = count_and_sum(nums, n, left)
            # There can be more subarrays with the same sum of left.
            return total_sum - left * (count - k)

        result = (
            sum_of_first_k(nums, n, right) - sum_of_first_k(nums, n, left - 1)
        ) % mod
        # Ensure non-negative result
        return (result + mod) % mod
```

</details>
