# 2460. Apply Operations to an Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/apply-operations-to-an-array/)  
`Array` `Two Pointers` `Simulation`

**Problem Link:** [LeetCode 2460 - Apply Operations to an Array](https://leetcode.com/problems/apply-operations-to-an-array/)

## Problem

You are given a 0-indexed array nums of size n consisting of non-negative integers.

You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply the following on the ith element of nums:

- If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.

After performing all the operations, shift all the 0's to the end of the array.

- For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].

Return the resulting array.

Note that the operations are applied sequentially, not all at once.

### Example 1

```text
Input: nums = [1,2,2,1,1,0]
Output: [1,4,2,0,0,0]
Explanation: We do the following operations:
- i = 0: nums[0] and nums[1] are not equal, so we skip this operation.
- i = 1: nums[1] and nums[2] are equal, we multiply nums[1] by 2 and change nums[2] to 0. The array becomes [1,4,0,1,1,0].
- i = 2: nums[2] and nums[3] are not equal, so we skip this operation.
- i = 3: nums[3] and nums[4] are equal, we multiply nums[3] by 2 and change nums[4] to 0. The array becomes [1,4,0,2,0,0].
- i = 4: nums[4] and nums[5] are equal, we multiply nums[4] by 2 and change nums[5] to 0. The array becomes [1,4,0,2,0,0].
After that, we shift the 0's to the end, which gives the array [1,4,2,0,0,0].
```

### Example 2

```text
Input: nums = [0,1]
Output: [1,0]
Explanation: No operation can be applied, we just shift the 0 to the end.
```

## Constraints

- 2 <= nums.length <= 2000
- 0 <= nums[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2460. Apply Operations to an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force Simulation | C++, Java, Python3 |
| Memory Optimization | C++, Java, Python3 |
| One Pass | C++, Java, Python3 |

## Approach 1: Brute Force Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> modifiedNums;

        // Step 1: Apply operations on the array
        for (int index = 0; index < n - 1; index++) {
            if (nums[index] == nums[index + 1] && nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }
        }

        // Step 2: Move non-zero elements to the front
        for (int num : nums) {
            if (num != 0) {
                modifiedNums.push_back(num);
            }
        }

        // Step 3: Append zeros to maintain the original size
        while (modifiedNums.size() < n) {
            modifiedNums.push_back(0);
        }

        return modifiedNums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] applyOperations(int[] nums) {
        int n = nums.length;
        int[] modifiedNums = new int[n];
        int zeroCount = 0;

        // Step 1: Apply operations on the array
        for (int index = 0; index < n - 1; index++) {
            if (nums[index] == nums[index + 1] && nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }
        }

        // Step 2: Move non-zero elements to the front
        for (int num : nums) {
            if (num != 0) {
                modifiedNums[zeroCount++] = num;
            }
        }

        // Step 3: Append zeros to maintain the original size
        while (zeroCount < n) {
            modifiedNums[zeroCount++] = 0;
        }

        return modifiedNums;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        modified_nums = []

        # Step 1: Apply operations on the array
        for index in range(0, n - 1):
            if (nums[index] == nums[index + 1]) and (nums[index] != 0):
                nums[index] *= 2
                nums[index + 1] = 0

        # Step 2: Move non-zero elements to the front
        for num in nums:
            if num != 0:
                modified_nums.append(num)

        # Step 3: Append zeros to maintain the original size
        while len(modified_nums) < n:
            modified_nums.append(0)

        return modified_nums
```

</details>

<br>

## Approach 2: Memory Optimization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Apply operations on the array
        for (int index = 0; index < n - 1; index++) {
            if (nums[index] == nums[index + 1] && nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }
        }

        // Step 2: Shift non-zero elements to the beginning
        int nonZeroIndex = 0;
        for (int iterateIndex = 0; iterateIndex < n; iterateIndex++) {
            if (nums[iterateIndex] != 0) {
                nums[nonZeroIndex++] = nums[iterateIndex];
            }
        }

        // Step 3: Fill the remaining positions with zeros
        while (nonZeroIndex < n) {
            nums[nonZeroIndex++] = 0;
        }

        return nums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[] applyOperations(int[] nums) {
        int n = nums.length;

        // Step 1: Apply operations on the array
        for (int index = 0; index < n - 1; index++) {
            if (nums[index] == nums[index + 1] && nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }
        }

        // Step 2: Shift non-zero elements to the beginning
        int nonZeroIndex = 0;
        for (int iterateIndex = 0; iterateIndex < n; iterateIndex++) {
            if (nums[iterateIndex] != 0) {
                nums[nonZeroIndex++] = nums[iterateIndex];
            }
        }

        // Step 3: Fill the remaining positions with zeros
        while (nonZeroIndex < n) {
            nums[nonZeroIndex++] = 0;
        }

        return nums;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def applyOperations(self, nums):
        n = len(nums)

        # Step 1: Apply operations on the array
        for index in range(n - 1):
            if nums[index] == nums[index + 1] and nums[index] != 0:
                nums[index] *= 2
                nums[index + 1] = 0

        # Step 2: Shift non-zero elements to the beginning
        non_zero_index = 0
        for iterate_index in range(n):
            if nums[iterate_index] != 0:
                nums[non_zero_index] = nums[iterate_index]
                non_zero_index += 1

        # Step 3: Fill the remaining positions with zeros
        while non_zero_index < n:
            nums[non_zero_index] = 0
            non_zero_index += 1

        return nums
```

</details>

<br>

## Approach 3: One Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int writeIndex = 0;  // Pointer to place non-zero elements

        for (int index = 0; index < n; index++) {
            // Step 1: Merge adjacent equal elements if they are non-zero
            if (index < n - 1 && nums[index] == nums[index + 1] &&
                nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }

            // Step 2: Shift non-zero elements to the front
            if (nums[index] != 0) {
                if (index != writeIndex) {
                    swap(nums[index], nums[writeIndex]);
                }
                writeIndex++;
            }
        }

        return nums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] applyOperations(int[] nums) {
        int n = nums.length;
        int writeIndex = 0; // Pointer to place non-zero elements

        for (int index = 0; index < n; index++) {
            // Step 1: Merge adjacent equal elements if they are non-zero
            if (
                index < n - 1 &&
                nums[index] == nums[index + 1] &&
                nums[index] != 0
            ) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }

            // Step 2: Shift non-zero elements to the front
            if (nums[index] != 0) {
                if (index != writeIndex) {
                    int temp = nums[index];
                    nums[index] = nums[writeIndex];
                    nums[writeIndex] = temp;
                }
                writeIndex++;
            }
        }

        return nums;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        write_index = 0  # Pointer to place non-zero elements

        for index in range(n):
            # Step 1: Merge adjacent equal elements if they are non-zero
            if (
                index < n - 1
                and nums[index] == nums[index + 1]
                and nums[index] != 0
            ):
                nums[index] *= 2
                nums[index + 1] = 0
            # Step 2: Shift non-zero elements to the front
            if nums[index] != 0:
                if index != write_index:
                    nums[index], nums[write_index] = (
                        nums[write_index],
                        nums[index],
                    )
                write_index += 1
        return nums
```

</details>
