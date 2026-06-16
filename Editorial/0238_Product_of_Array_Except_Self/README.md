# 238. Product of Array Except Self

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/product-of-array-except-self/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 238 - Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

## Problem

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

### Example 1

```text
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

### Example 2

```text
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

## Constraints

- 2 <= nums.length <= 105
- -30 <= nums[i] <= 30
- The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Paint House II](https://leetcode.com/problems/paint-house-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Difference in Sums After Removal of Elements](https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Construct Product Matrix](https://leetcode.com/problems/construct-product-matrix/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Sum of Array Product of Magical Sequences](https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 238. Product of Array Except Self

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Left and Right product lists | C++, Java, Python3 |
| O(1) space approach | C++, Java, Python3 |

## Approach 1: Left and Right product lists

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // The length of the input array
        int length = nums.size();

        // The left and right arrays as described in the algorithm
        vector<int> L(length), R(length), answer(length);

        // L[i] contains the product of all the elements to the left
        // Note: for the element at index '0', there are no elements to the
        // left, so the L[0] would be 1
        L[0] = 1;
        for (int i = 1; i < length; i++) {
            // L[i - 1] already contains the product of elements to the left of
            // 'i - 1' Simply multiplying it with nums[i - 1] would give the
            // product of all elements to the left of index 'i'
            L[i] = nums[i - 1] * L[i - 1];
        }

        // R[i] contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to
        // the right, so the R[length - 1] would be 1
        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--) {
            // R[i + 1] already contains the product of elements to the right of
            // 'i + 1' Simply multiplying it with nums[i + 1] would give the
            // product of all elements to the right of index 'i'
            R[i] = nums[i + 1] * R[i + 1];
        }

        // Constructing the answer array
        for (int i = 0; i < length; i++) {
            // For the first element, R[i] would be product except self
            // For the last element of the array, product except self would be
            // L[i] Else, multiple product of all elements to the left and to
            // the right
            answer[i] = L[i] * R[i];
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

    public int[] productExceptSelf(int[] nums) {
        // The length of the input array
        int length = nums.length;

        // The left and right arrays as described in the algorithm
        int[] L = new int[length];
        int[] R = new int[length];

        // Final answer array to be returned
        int[] answer = new int[length];

        // L[i] contains the product of all the elements to the left
        // Note: for the element at index '0', there are no elements to the left,
        // so L[0] would be 1
        L[0] = 1;
        for (int i = 1; i < length; i++) {
            // L[i - 1] already contains the product of elements to the left of 'i - 1'
            // Simply multiplying it with nums[i - 1] would give the product of all
            // elements to the left of index 'i'
            L[i] = nums[i - 1] * L[i - 1];
        }

        // R[i] contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to the right,
        // so the R[length - 1] would be 1
        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--) {
            // R[i + 1] already contains the product of elements to the right of 'i + 1'
            // Simply multiplying it with nums[i + 1] would give the product of all
            // elements to the right of index 'i'
            R[i] = nums[i + 1] * R[i + 1];
        }

        // Constructing the answer array
        for (int i = 0; i < length; i++) {
            // For the first element, R[i] would be product except self
            // For the last element of the array, product except self would be L[i]
            // Else, multiple product of all elements to the left and to the right
            answer[i] = L[i] * R[i];
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
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        # The length of the input array
        length = len(nums)

        # The left and right arrays as described in the algorithm
        L, R, answer = [0] * length, [0] * length, [0] * length

        # L[i] contains the product of all the elements to the left
        # Note: for the element at index '0', there are no elements to the left,
        # so the L[0] would be 1
        L[0] = 1
        for i in range(1, length):

            # L[i - 1] already contains the product of elements to the left of 'i - 1'
            # Simply multiplying it with nums[i - 1] would give the product of all
            # elements to the left of index 'i'
            L[i] = nums[i - 1] * L[i - 1]

        # R[i] contains the product of all the elements to the right
        # Note: for the element at index 'length - 1', there are no elements to the right,
        # so the R[length - 1] would be 1
        R[length - 1] = 1
        for i in reversed(range(length - 1)):

            # R[i + 1] already contains the product of elements to the right of 'i + 1'
            # Simply multiplying it with nums[i + 1] would give the product of all
            # elements to the right of index 'i'
            R[i] = nums[i + 1] * R[i + 1]

        # Constructing the answer array
        for i in range(length):
            # For the first element, R[i] would be product except self
            # For the last element of the array, product except self would be L[i]
            # Else, multiple product of all elements to the left and to the right
            answer[i] = L[i] * R[i]

        return answer
```

</details>

<br>

## Approach 2: O(1) space approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // The length of the input array
        int length = nums.size();

        // The answer vector to be returned
        vector<int> answer(length);

        // answer[i] contains the product of all the elements to the left
        // Note: for the element at index '0', there are no elements to the
        // left, so answer[0] would be 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            // answer[i - 1] already contains the product of elements to the
            // left of 'i - 1' Simply multiplying it with nums[i - 1] would give
            // the product of all elements to the left of index 'i'
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to
        // the right, so R would be 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // For the index 'i', R would contain the
            // product of all elements to the right. We update R accordingly
            answer[i] = answer[i] * R;
            R *= nums[i];
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

    public int[] productExceptSelf(int[] nums) {
        // The length of the input array
        int length = nums.length;

        // Final answer array to be returned
        int[] answer = new int[length];

        // answer[i] contains the product of all the elements to the left
        // Note: for the element at index '0', there are no elements to the left,
        // so the answer[0] would be 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            // answer[i - 1] already contains the product of elements to the left of 'i - 1'
            // Simply multiplying it with nums[i - 1] would give the product of all
            // elements to the left of index 'i'
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to the right,
        // so the R would be 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // For the index 'i', R would contain the
            // product of all elements to the right. We update R accordingly
            answer[i] = answer[i] * R;
            R *= nums[i];
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
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        # The length of the input array
        length = len(nums)

        # The answer array to be returned
        answer = [0] * length

        # answer[i] contains the product of all the elements to the left
        # Note: for the element at index '0', there are no elements to the left,
        # so the answer[0] would be 1
        answer[0] = 1
        for i in range(1, length):

            # answer[i - 1] already contains the product of elements to the left of 'i - 1'
            # Simply multiplying it with nums[i - 1] would give the product of all
            # elements to the left of index 'i'
            answer[i] = nums[i - 1] * answer[i - 1]

        # R contains the product of all the elements to the right
        # Note: for the element at index 'length - 1', there are no elements to the right,
        # so the R would be 1
        R = 1
        for i in reversed(range(length)):

            # For the index 'i', R would contain the
            # product of all elements to the right. We update R accordingly
            answer[i] = answer[i] * R
            R *= nums[i]

        return answer
```

</details>
