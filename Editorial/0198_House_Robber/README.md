# 198. House Robber

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/house-robber/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 198 - House Robber](https://leetcode.com/problems/house-robber/)

## Problem

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

### Example 1

```text
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

### Example 2

```text
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

## Constraints

- 1 <= nums.length <= 100
- 0 <= nums[i] <= 400

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [House Robber II](https://leetcode.com/problems/house-robber-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Paint House](https://leetcode.com/problems/paint-house/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Paint Fence](https://leetcode.com/problems/paint-fence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [House Robber III](https://leetcode.com/problems/house-robber-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Non-negative Integers without Consecutive Ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Coin Path](https://leetcode.com/problems/coin-path/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Delete and Earn](https://leetcode.com/problems/delete-and-earn/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Number of Ways to Place Houses](https://leetcode.com/problems/count-number-of-ways-to-place-houses/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [House Robber IV](https://leetcode.com/problems/house-robber-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Mice and Cheese](https://leetcode.com/problems/mice-and-cheese/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Largest Element in an Array after Merge Operations](https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [House Robber V](https://leetcode.com/problems/house-robber-v/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 198. House Robber

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion with Memoization | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |
| Optimized Dynamic Programming | C++, Java, Python3 |

## Approach 1: Recursion with Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> memo;

    int rob(vector<int>& nums) {
        memo.resize(100, -1);

        return robFrom(0, nums);
    }

private:
    int robFrom(int i, vector<int>& nums) {
        // No more houses left to examine.
        if (i >= nums.size()) {
            return 0;
        }

        // Return cached value.
        if (memo[i] > -1) {
            return memo[i];
        }

        // Recursive relation evaluation to get the optimal answer.
        int ans = max(robFrom(i + 1, nums), robFrom(i + 2, nums) + nums[i]);

        // Cache for future use.
        memo[i] = ans;
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int[] memo;

    public int rob(int[] nums) {
        this.memo = new int[100];

        // Fill with sentinel value representing not-calculated recursions.
        Arrays.fill(this.memo, -1);

        return this.robFrom(0, nums);
    }

    private int robFrom(int i, int[] nums) {
        // No more houses left to examine.
        if (i >= nums.length) {
            return 0;
        }

        // Return cached value.
        if (this.memo[i] > -1) {
            return this.memo[i];
        }

        // Recursive relation evaluation to get the optimal answer.
        int ans = Math.max(
            this.robFrom(i + 1, nums),
            this.robFrom(i + 2, nums) + nums[i]
        );

        // Cache for future use.
        this.memo[i] = ans;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def __init__(self):
        self.memo = {}

    def rob(self, nums: List[int]) -> int:

        self.memo = {}

        return self.robFrom(0, nums)

    def robFrom(self, i, nums):

        # No more houses left to examine.
        if i >= len(nums):
            return 0

        # Return cached value.
        if i in self.memo:
            return self.memo[i]

        # Recursive relation evaluation to get the optimal answer.
        ans = max(
            self.robFrom(i + 1, nums), self.robFrom(i + 2, nums) + nums[i]
        )

        # Cache for future use.
        self.memo[i] = ans
        return ans
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();

        // Special handling for empty case.
        if (N == 0) {
            return 0;
        }

        vector<int> maxRobbedAmount(N + 1);

        // Base case initializations.
        maxRobbedAmount[N] = 0;
        maxRobbedAmount[N - 1] = nums[N - 1];

        // DP table calculations.
        for (int i = N - 2; i >= 0; --i) {
            // Same as the recursive solution.
            maxRobbedAmount[i] =
                max(maxRobbedAmount[i + 1], maxRobbedAmount[i + 2] + nums[i]);
        }

        return maxRobbedAmount[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int rob(int[] nums) {
        int N = nums.length;

        // Special handling for empty array case.
        if (N == 0) {
            return 0;
        }

        int[] maxRobbedAmount = new int[nums.length + 1];

        // Base case initializations.
        maxRobbedAmount[N] = 0;
        maxRobbedAmount[N - 1] = nums[N - 1];

        // DP table calculations.
        for (int i = N - 2; i >= 0; --i) {
            // Same as the recursive solution.
            maxRobbedAmount[i] = Math.max(
                maxRobbedAmount[i + 1],
                maxRobbedAmount[i + 2] + nums[i]
            );
        }

        return maxRobbedAmount[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def rob(self, nums: List[int]) -> int:

        # Special handling for empty case.
        if not nums:
            return 0

        maxRobbedAmount = [None for _ in range(len(nums) + 1)]
        N = len(nums)

        # Base case initialization.
        maxRobbedAmount[N], maxRobbedAmount[N - 1] = 0, nums[N - 1]

        # DP table calculations.
        for i in range(N - 2, -1, -1):

            # Same as recursive solution.
            maxRobbedAmount[i] = max(
                maxRobbedAmount[i + 1], maxRobbedAmount[i + 2] + nums[i]
            )

        return maxRobbedAmount[0]
```

</details>

<br>

## Approach 3: Optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();

        // Special handling for empty array case.
        if (N == 0) {
            return 0;
        }

        int robNext, robNextPlusOne;

        // Base case initializations.
        robNextPlusOne = 0;
        robNext = nums[N - 1];

        // DP table calculations. Note: we are not using any
        // table here for storing values. Just using two
        // variables will suffice.
        for (int i = N - 2; i >= 0; --i) {
            // Same as the recursive solution.
            int current = max(robNext, robNextPlusOne + nums[i]);

            // Update the variables
            robNextPlusOne = robNext;
            robNext = current;
        }

        return robNext;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int rob(int[] nums) {
        int N = nums.length;

        // Special handling for empty array case.
        if (N == 0) {
            return 0;
        }

        int robNext, robNextPlusOne;

        // Base case initializations.
        robNextPlusOne = 0;
        robNext = nums[N - 1];

        // DP table calculations. Note: we are not using any
        // table here for storing values. Just using two
        // variables will suffice.
        for (int i = N - 2; i >= 0; --i) {
            // Same as the recursive solution.
            int current = Math.max(robNext, robNextPlusOne + nums[i]);

            // Update the variables
            robNextPlusOne = robNext;
            robNext = current;
        }

        return robNext;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def rob(self, nums: List[int]) -> int:

        # Special handling for empty case.
        if not nums:
            return 0

        N = len(nums)

        rob_next_plus_one = 0
        rob_next = nums[N - 1]

        # DP table calculations.
        for i in range(N - 2, -1, -1):

            # Same as recursive solution.
            current = max(rob_next, rob_next_plus_one + nums[i])

            # Update the variables
            rob_next_plus_one = rob_next
            rob_next = current

        return rob_next
```

</details>
