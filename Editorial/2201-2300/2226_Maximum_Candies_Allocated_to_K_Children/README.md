# 2226. Maximum Candies Allocated to K Children

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 2226 - Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/)

## Problem

You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

Return the maximum number of candies each child can get.

### Example 1

```text
Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
```

### Example 2

```text
Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.
```

## Constraints

- 1 <= candies.length <= 105
- 1 <= candies[i] <= 107
- 1 <= k <= 1012

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Limit of Balls in a Bag](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Speed to Arrive on Time](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Removable Characters](https://leetcode.com/problems/maximum-number-of-removable-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimize Maximum of Array](https://leetcode.com/problems/minimize-maximum-of-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximize Happiness of Selected Children](https://leetcode.com/problems/maximize-happiness-of-selected-children/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2226. Maximum Candies Allocated to K Children

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
    int maximumCandies(vector<int>& candies, long long k) {
        // Find the maximum number of candies in any pile
        int maxCandiesInPile = 0;
        for (int i = 0; i < candies.size(); i++) {
            maxCandiesInPile = max(maxCandiesInPile, candies[i]);
        }

        // Set the initial search range for binary search
        int left = 0;
        int right = maxCandiesInPile;

        // Binary search to find the maximum number of candies each child can
        // get
        while (left < right) {
            // Calculate the middle value of the current range
            int middle = (left + right + 1) / 2;

            // Check if it's possible to allocate candies so that each child
            // gets 'middle' candies
            if (canAllocateCandies(candies, k, middle)) {
                // If possible, move to the upper half to search for a larger
                // number
                left = middle;
            } else {
                // Otherwise, move to the lower half
                right = middle - 1;
            }
        }

        return left;
    }

private:
    bool canAllocateCandies(vector<int>& candies, long long k,
                            int numOfCandies) {
        // Initialize the total number of children that can be served
        long long int maxNumOfChildren = 0;

        for (int pileIndex = 0; pileIndex < candies.size(); pileIndex++) {
            maxNumOfChildren +=
                candies[pileIndex] /
                numOfCandies;  // Add the number of children this pile can serve
        }

        return maxNumOfChildren >= k;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumCandies(int[] candies, long k) {
        // Find the maximum number of candies in any pile
        int maxCandiesInPile = 0;
        for (int i = 0; i < candies.length; i++) {
            maxCandiesInPile = Math.max(maxCandiesInPile, candies[i]);
        }

        // Set the initial search range for binary search
        int left = 0;
        int right = maxCandiesInPile;

        // Binary search to find the maximum number of candies each child can get
        while (left < right) {
            // Calculate the middle value of the current range
            int middle = (left + right + 1) / 2;

            // Check if it's possible to allocate candies so that each child gets 'middle' candies
            if (canAllocateCandies(candies, k, middle)) {
                // If possible, move to the upper half to search for a larger number
                left = middle;
            } else {
                // Otherwise, move to the lower half
                right = middle - 1;
            }
        }

        return left;
    }

    private boolean canAllocateCandies(
        int[] candies,
        long k,
        int numOfCandies
    ) {
        // Initialize the total number of children that can be served
        long maxNumOfChildren = 0;

        // Iterate over all piles to calculate how many children each pile can serve
        for (int pileIndex = 0; pileIndex < candies.length; pileIndex++) {
            maxNumOfChildren += candies[pileIndex] / numOfCandies;
        }

        return maxNumOfChildren >= k;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumCandies(self, candies, k):
        # Find the maximum number of candies in any pile
        max_candies_in_pile = 0
        for candy in candies:
            max_candies_in_pile = max(max_candies_in_pile, candy)

        # Set the initial search range for binary search
        left = 0
        right = max_candies_in_pile

        # Binary search to find the maximum number of candies each child can get
        while left < right:
            # Calculate the middle value of the current range
            middle = (left + right + 1) // 2

            # Check if it's possible to allocate candies so that each child gets 'middle' candies
            if self._can_allocate_candies(candies, k, middle):
                # If possible, move to the upper half to search for a larger number
                left = middle
            else:
                # Otherwise, move to the lower half
                right = middle - 1

        return left

    def _can_allocate_candies(self, candies, k, num_of_candies):
        # Initialize the total number of children that can be served
        max_num_of_children = 0

        # Iterate over all piles to calculate how many children each pile can serve
        for pile in candies:
            max_num_of_children += pile // num_of_candies

        return max_num_of_children >= k
```

</details>
