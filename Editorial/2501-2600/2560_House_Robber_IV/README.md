# 2560. House Robber IV

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/house-robber-iv/)  
`Array` `Binary Search` `Dynamic Programming` `Greedy`

**Problem Link:** [LeetCode 2560 - House Robber IV](https://leetcode.com/problems/house-robber-iv/)

## Problem

There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

### Example 1

```text
Input: nums = [2,3,5,9], k = 2
Output: 5
Explanation:
There are three ways to rob at least 2 houses:
- Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
- Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
- Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
Therefore, we return min(5, 9, 9) = 5.
```

### Example 2

```text
Input: nums = [2,7,9,3,1], k = 2
Output: 2
Explanation: There are 7 ways to rob the houses. The way which leads to minimum capability is to rob the house at index 0 and 4. Return max(nums[0], nums[4]) = 2.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 1 <= k <= (nums.length + 1)/2

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [House Robber](https://leetcode.com/problems/house-robber/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2560. House Robber IV

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search | C++, Java, Python3 |

## Approach: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // Store the maximum nums value in maxReward.
        int minReward = 1, maxReward = *max_element(nums.begin(), nums.end()),
            totalHouses = nums.size();

        // Use binary search to find the minimum reward possible.
        while (minReward < maxReward) {
            int midReward = (minReward + maxReward) / 2;
            int possibleThefts = 0;

            for (int index = 0; index < totalHouses; ++index) {
                if (nums[index] <= midReward) {
                    possibleThefts += 1;
                    index++;  // Skip the next house to maintain the
                              // non-adjacent condition
                }
            }

            if (possibleThefts >= k)
                maxReward = midReward;
            else
                minReward = midReward + 1;
        }

        return minReward;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minCapability(int[] nums, int k) {
        // Store the maximum nums value in maxReward.
        int minReward = 1;
        int maxReward = Arrays.stream(nums).max().getAsInt();
        int totalHouses = nums.length;

        // Use binary search to find the minimum reward possible.
        while (minReward < maxReward) {
            int midReward = (minReward + maxReward) / 2;
            int possibleThefts = 0;

            for (int index = 0; index < totalHouses; ++index) {
                if (nums[index] <= midReward) {
                    possibleThefts += 1;
                    index++; // Skip the next house to maintain the
                    // non-adjacent condition
                }
            }

            if (possibleThefts >= k) maxReward = midReward;
            else minReward = midReward + 1;
        }

        return minReward;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCapability(self, nums, k):
        # Store the maximum nums value in maxReward.
        min_reward, max_reward = 1, max(nums)
        total_houses = len(nums)

        # Use binary search to find the minimum reward possible.
        while min_reward < max_reward:
            mid_reward = (min_reward + max_reward) // 2
            possible_thefts = 0

            index = 0
            while index < total_houses:
                if nums[index] <= mid_reward:
                    possible_thefts += 1
                    index += 2  # Skip the next house to maintain the non-adjacent condition
                else:
                    index += 1

            if possible_thefts >= k:
                max_reward = mid_reward
            else:
                min_reward = mid_reward + 1

        return min_reward
```

</details>
