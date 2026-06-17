# 2448. Minimum Cost to Make Array Equal

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-cost-to-make-array-equal/)  
`Array` `Binary Search` `Greedy` `Sorting` `Prefix Sum`

**Problem Link:** [LeetCode 2448 - Minimum Cost to Make Array Equal](https://leetcode.com/problems/minimum-cost-to-make-array-equal/)

## Problem

You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

- Increase or decrease any element of the array nums by 1.

The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.

### Example 1

```text
Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.
```

### Example 2

```text
Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
Output: 0
Explanation: All the elements are already equal, so no operations are needed.
```

## Constraints

- n == nums.length == cost.length
- 1 <= n <= 105
- 1 <= nums[i], cost[i] <= 106
- Test cases are generated in a way that the output doesn't exceed 253-1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Product of the Length of Two Palindromic Substrings](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Amount of Time to Fill Cups](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Operations to Make All Array Elements Equal](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Cost to Make Array Equalindromic](https://leetcode.com/problems/minimum-cost-to-make-array-equalindromic/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2448. Minimum Cost to Make Array Equal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sum | Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Prefix Sum

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long minCost(int[] nums, int[] cost) {
        // Sort integers by values.
        int n = nums.length;
        int[][] numsAndCost = new int[n][2];
        for (int i = 0; i < n; ++i) {
            numsAndCost[i][0] = nums[i];
            numsAndCost[i][1] = cost[i];
        }
        Arrays.sort(numsAndCost, (a, b) -> a[0] - b[0]);

        // Get the prefix sum array of the costs.
        long[] prefixCost = new long[n];
        prefixCost[0] = numsAndCost[0][1];
        for (int i = 1; i < n; ++i)
            prefixCost[i] = numsAndCost[i][1] + prefixCost[i - 1];

        // Then we try every integer nums[i] and make every element equals nums[i],
        // Start with nums[0]
        long totalCost = 0l;
        for (int i = 1; i < n; ++i)
            totalCost += 1l * numsAndCost[i][1] * (numsAndCost[i][0] - numsAndCost[0][0]);
        long answer = totalCost;
        
        // Then we try nums[1], nums[2] and so on. The cost difference is made by the change of
        // two parts: 1. prefix sum of costs. 2. suffix sum of costs. 
        // During the iteration, record the minimum cost we have met.
        for (int i = 1; i < n; ++i) {
            int gap = numsAndCost[i][0] - numsAndCost[i - 1][0];
            totalCost += 1l * prefixCost[i - 1] * gap;
            totalCost -= 1l * (prefixCost[n - 1] - prefixCost[i - 1]) * gap;
            answer = Math.min(answer, totalCost);
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
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        # Sort integers by values.
        num_and_cost = sorted([num, c] for num, c in zip(nums, cost))
        n = len(cost)
        
        # Get the prefix sum array of the costs.
        prefix_cost = [0] * n
        prefix_cost[0] = num_and_cost[0][1]
        for i in range(1, n): 
            prefix_cost[i] = num_and_cost[i][1] + prefix_cost[i - 1]
        
        # Then we try every integer nums[i] and make every element equals nums[i],
        # Start with nums[0]
        total_cost = 0
        for i in range(1, n): 
            total_cost += num_and_cost[i][1] * (num_and_cost[i][0] - num_and_cost[0][0])
        answer = total_cost
        
        # Then we try nums[1], nums[2] and so on. The cost difference is made by the change of
        # two parts: 1. prefix sum of costs. 2. suffix sum of costs. 
        # During the iteration, record the minimum cost we have met.
        for i in range(1, n):
            gap = num_and_cost[i][0] - num_and_cost[i - 1][0]
            total_cost += prefix_cost[i - 1] * gap
            total_cost -= gap * (prefix_cost[n - 1] - prefix_cost[i - 1])
            answer = min(answer, total_cost)
            
        return answer
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Get the cost of making every element equals base.
    long long getCost(vector<int>& nums, vector<int>& cost, int base) {
        long long result = 0;
        for (int i = 0; i < nums.size(); ++i)
            result += 1L * abs(nums[i] - base) * cost[i];
        return result;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // Initialize the left and the right boundary of the binary search.
        long long answer = getCost(nums, cost, nums[0]);
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        
        // As shown in the previous picture, if F(mid) > F(mid + 1), then the minimum
        // is to the right of mid, otherwise, the minimum is to the left of mid.
        while (left < right) {
            int mid = (left + right) / 2;
            long long cost1 = getCost(nums, cost, mid);
            long long cost2 = getCost(nums, cost, mid + 1);
            answer = min(cost1, cost2);
            if (cost1 > cost2)
                left = mid + 1;
            else
                right = mid;
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
    // Get the cost of making every element equals base.
    private long getCost(int[] nums, int[] cost, int base) {
        long result = 0L;
        for (int i = 0; i < nums.length; ++i)
            result += 1L * Math.abs(nums[i] - base) * cost[i];
        return result;
    }
    public long minCost(int[] nums, int[] cost) {
        // Initialize the left and the right boundary of the binary search.
        int left = 1000001, right = 0;
        for (int num : nums) {
            left = Math.min(left, num);
            right = Math.max(right, num);
        }
        long answer = getCost(nums, cost, nums[0]);
        
        // As shown in the previous picture, if F(mid) > F(mid + 1), then the minimum
        // is to the right of mid, otherwise, the minimum is to the left of mid.
        while (left < right) {
            int mid = (right + left) / 2;
            long cost1 = getCost(nums, cost, mid);
            long cost2 = getCost(nums, cost, mid + 1);
            answer = Math.min(cost1, cost2);
            
            if (cost1 > cost2) 
                left = mid + 1;
            else
                right = mid;
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
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        # Get the cost of making every element equals base.
        def get_cost(base):
            return sum(abs(base - num) * c for num, c in zip(nums, cost))
        
        # Initialize the left and the right boundary of the binary search.
        left, right = min(nums), max(nums)
        answer = get_cost(nums[0])
        
        # As shown in the previous picture, if F(mid) > F(mid + 1), then the minimum
        # is to the right of mid, otherwise, the minimum is to the left of mid.
        while left < right:
            mid = (left + right) // 2
            cost_1 = get_cost(mid)
            cost_2 = get_cost(mid + 1)
            answer = min(cost_1, cost_2)
            
            if cost_1 > cost_2:
                left = mid + 1
            else:
                right = mid
        
        return answer
```

</details>
