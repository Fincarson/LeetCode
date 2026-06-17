# 1760. Minimum Limit of Balls in a Bag

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 1760 - Minimum Limit of Balls in a Bag](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/)

## Problem

You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

- Take any bag of balls and divide it into two new bags with a positive number of balls.

		For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.

Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.

### Example 1

```text
Input: nums = [9], maxOperations = 2
Output: 3
Explanation:
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.
```

### Example 2

```text
Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2, and you should return 2.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= maxOperations, nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1760. Minimum Limit of Balls in a Bag

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search on The Answer | C++, Java, Python3 |

## Approach: Binary Search on The Answer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Binary search bounds
        int left = 1;
        int right = 0;

        for (auto num : nums) {
            right = max(right, num);
        }

        // Perform binary search to find the optimal maxBallsInBag
        while (left < right) {
            int middle = (left + right) / 2;

            // Check if a valid distribution is possible with the current middle
            // value
            if (isPossible(middle, nums, maxOperations)) {
                right = middle;  // If possible, try a smaller value (shift
                                 // right to middle)
            } else {
                left = middle + 1;  // If not possible, try a larger value
                                    // (shift left to middle + 1)
            }
        }

        // Return the smallest possible value for maxBallsInBag
        return left;
    }

private:
    // Helper function to check if a distribution is possible for a given
    // maxBallsInBag
    bool isPossible(int maxBallsInBag, vector<int>& nums, int maxOperations) {
        int totalOperations = 0;

        // Iterate through each bag in the array
        for (int num : nums) {
            // Calculate the number of operations needed to split this bag
            int operations = ceil(num / (double)maxBallsInBag) - 1;
            totalOperations += operations;

            // Total operations exceed maxOperations, return false
            if (totalOperations > maxOperations) return false;
        }

        // We can split the balls within the allowed operations, return true
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumSize(int[] nums, int maxOperations) {
        // Binary search bounds
        int left = 1;
        int right = 0;

        for (int num : nums) {
            right = Math.max(right, num);
        }

        // Perform binary search to find the optimal maxBallsInBag
        while (left < right) {
            int middle = (left + right) / 2;

            // Check if a valid distribution is possible with the current middle value
            if (isPossible(middle, nums, maxOperations)) {
                right = middle; // If possible, try a smaller value (shift right to middle)
            } else {
                left = middle + 1; // If not possible, try a larger value (shift left to middle + 1)
            }
        }

        // Return the smallest possible value for maxBallsInBag
        return left;
    }

    // Helper function to check if a distribution is possible for a given maxBallsInBag
    private boolean isPossible(
        int maxBallsInBag,
        int[] nums,
        int maxOperations
    ) {
        int totalOperations = 0;

        // Iterate through each bag in the array
        for (int num : nums) {
            // Calculate the number of operations needed to split this bag
            int operations = (int) Math.ceil(num / (double) maxBallsInBag) - 1;
            totalOperations += operations;

            // If total operations exceed maxOperations, return false
            if (totalOperations > maxOperations) {
                return false;
            }
        }

        // We can split the balls within the allowed operations, return true
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumSize(self, nums, max_operations):
        # Binary search bounds
        left = 1
        right = max(nums)

        # Perform binary search to find the optimal max_balls_in_bag
        while left < right:
            middle = (left + right) // 2

            # Check if a valid distribution is possible with the current middle value
            if self._is_possible(middle, nums, max_operations):
                # If possible, try a smaller value (shift right to middle)
                right = middle
            else:
                # If not possible, try a larger value (shift left to middle + 1)
                left = middle + 1

        # Return the smallest possible value for max_balls_in_bag
        return left

    # Helper function to check if a distribution is possible for a given max_balls_in_bag
    def _is_possible(self, max_balls_in_bag, nums, max_operations):
        total_operations = 0

        # Iterate through each bag in the array
        for num in nums:
            # Calculate the number of operations needed to split this bag
            operations = math.ceil(num / max_balls_in_bag) - 1
            total_operations += operations

            # If total operations exceed max_operations, return False
            if total_operations > max_operations:
                return False

        # We can split the balls within the allowed operations, return True
        return True
```

</details>
