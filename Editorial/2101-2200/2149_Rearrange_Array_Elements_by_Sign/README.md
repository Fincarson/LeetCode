# 2149. Rearrange Array Elements by Sign

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/rearrange-array-elements-by-sign/)  
`Array` `Two Pointers` `Simulation`

**Problem Link:** [LeetCode 2149 - Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/)

## Problem

You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the array follows the given conditions:

Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

### Example 1

```text
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.
```

### Example 2

```text
Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
```

## Constraints

- 2 <= nums.length <= 2 * 105
- nums.length is even
- 1 <= |nums[i]| <= 105
- nums consists of equal number of positive and negative integers.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2149. Rearrange Array Elements by Sign

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Two Pointers | C++, Java, JavaScript, Python3, TypeScript |

## Approach: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        // Initializing an answer array of size n
        vector<int> ans(n, 0);

        // Initializing two pointers to track even and 
        // odd indices for positive and negative integers respectively
        int posIndex = 0, negIndex=1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                // Placing the positive integer at the 
                // desired index in ans and incrementing posIndex by 2
                ans[posIndex] = nums[i];
                posIndex+=2;
            } else {
                // Placing the negative integer at the 
                // desired index in ans and incrementing negIndex by 2
                ans[negIndex] = nums[i];
                negIndex += 2;
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
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;

        // Initializing an answer array of size n
        int[] ans = new int[n];

        // Initializing two pointers to track even and 
        // odd indices for positive and negative integers respectively
        int posIndex = 0, negIndex = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                // Placing the positive integer at the 
                // desired index in ans and incrementing posIndex by 2
                ans[posIndex] = nums[i];
                posIndex += 2;
            } else {
                // Placing the negative integer at the 
                // desired index in ans and incrementing negIndex by 2
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var rearrangeArray = function(nums) {
    const n = nums.length;

    // Initializing an answer array of size n
    const ans = new Array(n).fill(0);

    // Initializing two pointers to track even and
    // odd indices for positive and negative integers respectively
    let posIndex = 0, negIndex = 1;

    for (let i = 0; i < n; i++) {
        if (nums[i] > 0) {
            // Placing the positive integer at the
            // desired index in ans and incrementing posIndex by 2
            ans[posIndex] = nums[i];
            posIndex += 2;
        } else {
            // Placing the negative integer at the
            // desired index in ans and incrementing negIndex by 2
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)

        # Initializing an answer array of size n
        ans = [0] * n

        # Initializing two pointers to track even and
        # odd indices for positive and negative integers respectively
        pos_index, neg_index = 0, 1

        for i in range(n):
            if nums[i] > 0:
                # Placing the positive integer at the
                # desired index in ans and incrementing pos_index by 2
                ans[pos_index] = nums[i]
                pos_index += 2
            else:
                # Placing the negative integer at the
                # desired index in ans and incrementing neg_index by 2
                ans[neg_index] = nums[i]
                neg_index += 2

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function rearrangeArray(nums: number[]): number[] {
    const n: number = nums.length;

    // Initializing an answer array of size n
    const ans: number[] = new Array(n);

    // Initializing two pointers to track even and 
    // odd indices for positive and negative integers respectively
    let posIndex: number = 0;
    let negIndex: number = 1;

    for (let i = 0; i < n; i++) {
        if (nums[i] > 0) {
            // Placing the positive integer at the 
            // desired index in ans and incrementing posIndex by 2
            ans[posIndex] = nums[i];
            posIndex += 2;
        } else {
            // Placing the negative integer at the 
            // desired index in ans and incrementing negIndex by 2
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }

    return ans;
};
```

</details>
