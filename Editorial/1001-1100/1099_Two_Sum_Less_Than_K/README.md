# 1099. Two Sum Less Than K

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/two-sum-less-than-k/)  
`Array` `Two Pointers` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 1099 - Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k/)

## Problem

Given an array nums of integers and integer k, return the maximum sum such that there exists i < j with nums[i] + nums[j] = sum and sum < k. If no i, j exist satisfying this equation, return -1.

### Example 1

```text
Input: nums = [34,23,1,24,75,33,54,8], k = 60
Output: 58
Explanation: We can use 34 and 24 to sum 58 which is less than 60.
```

### Example 2

```text
Input: nums = [10,20,30], k = 15
Output: -1
Explanation: In this case it is not possible to get a pair sum less that 15.
```

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 1000
- 1 <= k <= 2000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum](https://leetcode.com/problems/two-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [3Sum Smaller](https://leetcode.com/problems/3sum-smaller/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1099. Two Sum Less Than K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Two Pointers | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |
| Counting Sort | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int answer = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int sum = nums[i] + nums[j];
                if (sum < k) {
                    answer = max(answer, sum);
                }
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int twoSumLessThanK(int[] nums, int k) {
        int answer = -1;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int sum = nums[i] + nums[j];
                if (sum < k) {
                    answer = Math.max(answer, sum);
                }
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        answer = -1
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                sum = nums[i] + nums[j]
                if sum < k:
                    answer = max(answer, sum)
        return answer
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int answer = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < k) {
                answer = max(answer, sum);
                left++;
            } else {
                right--;
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int twoSumLessThanK(int[] nums, int k) {
        Arrays.sort(nums);
        int answer = -1;
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < k) {
                answer = Math.max(answer, sum);
                left++;
            } else {
                right--;
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        nums.sort()
        answer = -1
        left = 0
        right = len(nums) -1
        while left < right:
            sum = nums[left] + nums[right]
            if (sum < k):
                answer = max(answer, sum)
                left += 1
            else:
                right -= 1
        return answer
```

</details>

<br>

## Approach 3: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int answer = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && nums[i] < k; i++) {
            auto j = lower_bound(nums.begin() + i + 1, nums.end(), k - nums[i]) - nums.begin() - 1;
            if (j > i) {
                answer = max(answer, nums[i] + nums[j]);
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int twoSumLessThanK(int[] nums, int k) {
        int answer = -1;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; ++i) {
            int idx = Arrays.binarySearch(nums, i + 1, nums.length, k - nums[i] - 1);
            int j = (idx >= 0 ? idx : ~idx);
            if (j == nums.length || nums[j] > k - nums[i] - 1) {
                j--;
            }
            if (j > i) {
                answer = Math.max(answer, nums[i] + nums[j]);
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        answer = -1
        nums.sort()
        for i in range(len(nums)):
            j = bisect_left(nums, k - nums[i], i + 1) - 1
            if j > i:
                answer = max(answer, nums[i] + nums[j])
        return answer
```

</details>

<br>

## Approach 4: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int answer = -1;
        int count[1001] = {};
        for (int num : nums) {
            count[num]++;
        }
        int lo = 1;
        int hi = 1000;
        while (lo <= hi) {
            if (lo + hi >= k || count[hi] == 0) {
                hi--;
            } else {
                if (count[lo] > (lo < hi ? 0 : 1)) {
                    answer = max(answer, lo + hi);
                }
                lo++;
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int twoSumLessThanK(int[] nums, int k) {
        int answer = -1;
        int[] count = new int[1001];
        for (int num : nums) {
            count[num]++;
        }
        int lo = 1;
        int hi = 1000;
        while (lo <= hi) {
            if (lo + hi >= k || count[hi] == 0) {
                hi--;
            } else {
                if (count[lo] > (lo < hi ? 0 : 1)) {
                    answer = Math.max(answer, lo + hi);
                }
                lo++;
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        answer = -1
        count = [0] * 1001
        for num in nums:
            count[num] += 1
        lo = 1
        hi = 1000
        while lo <= hi:
            if lo + hi >= k or count[hi] == 0:
                hi -= 1
            else:
                if count[lo] > (0 if lo < hi else 1):
                    answer = max(answer, lo + hi)
                lo += 1
        return answer
```

</details>
