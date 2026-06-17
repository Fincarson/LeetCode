# 2780. Minimum Index of a Valid Split

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-index-of-a-valid-split/)  
`Array` `Hash Table` `Sorting`

**Problem Link:** [LeetCode 2780 - Minimum Index of a Valid Split](https://leetcode.com/problems/minimum-index-of-a-valid-split/)

## Problem

An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

- 0 <= i < n - 1
- nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.

Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.

### Example 1

```text
Input: nums = [1,2,2,2]
Output: 2
Explanation: We can split the array at index 2 to obtain arrays [1,2,2] and [2].
In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 > 3.
In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 > 1.
Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split.
It can be shown that index 2 is the minimum index of a valid split.
```

### Example 2

```text
Input: nums = [2,1,3,1,1,1,7,1,2,1]
Output: 4
Explanation: We can split the array at index 4 to obtain arrays [2,1,3,1,1] and [1,7,1,2,1].
In array [2,1,3,1,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
In array [1,7,1,2,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
Both [2,1,3,1,1] and [1,7,1,2,1] have the same dominant element as nums, so this is a valid split.
It can be shown that index 4 is the minimum index of a valid split.
```

### Example 3

```text
Input: nums = [3,3,3,3,7,2,2]
Output: -1
Explanation: It can be shown that there is no valid split.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- nums has exactly one dominant element.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Majority Element](https://leetcode.com/problems/majority-element/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Partition Array into Disjoint Intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2780. Minimum Index of a Valid Split

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Map | C++, Java, Python3 |
| Boyer-Moore Majority Voting Algorithm | C++, Java, Python3 |

## Approach 1: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> firstMap, secondMap;
        int n = nums.size();

        // Add all elements of nums to second half
        for (auto& num : nums) {
            secondMap[num]++;
        }

        for (int index = 0; index < n; index++) {
            // Create split at current index
            int num = nums[index];
            secondMap[num]--;
            firstMap[num]++;

            // Check if valid split
            if (firstMap[num] * 2 > index + 1 &&
                secondMap[num] * 2 > n - index - 1) {
                return index;
            }
        }

        // No valid split exists
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumIndex(List<Integer> nums) {
        Map<Integer, Integer> firstMap = new HashMap<>();
        Map<Integer, Integer> secondMap = new HashMap<>();
        int n = nums.size();

        // Add all elements of nums to secondMap
        for (int num : nums) {
            secondMap.put(num, secondMap.getOrDefault(num, 0) + 1);
        }

        for (int index = 0; index < n; index++) {
            // Create split at current index
            int num = nums.get(index);
            secondMap.put(num, secondMap.get(num) - 1);
            firstMap.put(num, firstMap.getOrDefault(num, 0) + 1);

            // Check if valid split
            if (
                firstMap.get(num) * 2 > index + 1 &&
                secondMap.get(num) * 2 > n - index - 1
            ) {
                return index;
            }
        }

        // No valid split exists
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        first_map = defaultdict(int)
        second_map = defaultdict(int)
        n = len(nums)

        # Add all elements of nums to second_map
        for num in nums:
            second_map[num] += 1

        for index in range(n):
            # Create split at current index
            num = nums[index]
            second_map[num] -= 1
            first_map[num] += 1

            # Check if valid split
            if (
                first_map[num] * 2 > index + 1
                and second_map[num] * 2 > n - index - 1
            ):
                return index

        # No valid split exists
        return -1
```

</details>

<br>

## Approach 2: Boyer-Moore Majority Voting Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // Find the majority element
        int x = nums[0], count = 0, xCount = 0, n = nums.size();
        for (auto& num : nums) {
            if (num == x) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                x = num;
                count = 1;
            }
        }

        // Count frequency of majority element
        for (auto& num : nums) {
            if (num == x) {
                xCount++;
            }
        }

        // Check if valid split is possible
        count = 0;
        for (int index = 0; index < n; index++) {
            if (nums[index] == x) {
                count++;
            }
            int remainingCount = xCount - count;
            if (count * 2 > index + 1 && remainingCount * 2 > n - index - 1) {
                return index;
            }
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumIndex(List<Integer> nums) {
        // Find the majority element
        int x = nums.get(0), count = 0, xCount = 0, n = nums.size();

        for (int num : nums) {
            if (num == x) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                x = num;
                count = 1;
            }
        }

        // Count frequency of majority element
        for (int num : nums) {
            if (num == x) {
                xCount++;
            }
        }

        // Check if valid split is possible
        count = 0;
        for (int index = 0; index < n; index++) {
            if (nums.get(index) == x) {
                count++;
            }
            int remainingCount = xCount - count;
            // Check if both left and right partitions satisfy the condition
            if (count * 2 > index + 1 && remainingCount * 2 > n - index - 1) {
                return index;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        # Find the majority element
        x = nums[0]
        count = 0
        x_count = 0
        n = len(nums)

        for num in nums:
            if num == x:
                count += 1
            else:
                count -= 1
            if count == 0:
                x = num
                count = 1

        # Count frequency of majority element
        for num in nums:
            if num == x:
                x_count += 1

        # Check if valid split is possible
        count = 0
        for index in range(n):
            if nums[index] == x:
                count += 1
            remaining_count = x_count - count
            if count * 2 > index + 1 and remaining_count * 2 > n - index - 1:
                return index

        return -1
```

</details>
