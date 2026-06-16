# 477. Total Hamming Distance

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/total-hamming-distance/)  
`Array` `Math` `Bit Manipulation`

**Problem Link:** [LeetCode 477 - Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance/)

## Problem

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

### Example 1

```text
Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
```

### Example 2

```text
Input: nums = [4,14,4]
Output: 4
```

## Constraints

- 1 <= nums.length <= 104
- 0 <= nums[i] <= 109
- The answer for the given input will fit in a 32-bit integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Hamming Distance](https://leetcode.com/problems/hamming-distance/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sum of Digit Differences of All Pairs](https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 477. Total Hamming Distance

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | C++ |
| Approach #2 Loop over the bits! [Accepted] | C++ |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int totalHammingDistance(vector<int>& nums)
{
    int ans = 0;

    if (nums.empty())
        return ans;

    for (int i = 0; i < nums.size() - 1; i++)                  // for all unique pairs of elements
        for (int j = i + 1; j < nums.size(); j++)
            ans += __builtin_popcount(nums[i] ^ nums[j]);      // count number of 1 bits in xor resultant

    return ans;
}
```

</details>

<br>

## Approach #2 Loop over the bits! [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int totalHammingDistance(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    int ans = 0, n = nums.size();
    vector<int> cnt(32, 0);         // count of elements with a particular bit ON

    for (auto num : nums) {         // loop over every element
        int i = 0;
        while (num > 0) {           // check every bit
            cnt[i] += (num & 0x1);
            num >>= 1;
            i++;
        }
    }

    for (auto&& k : cnt) {           // loop over every bit count
        ans += k * (n - k);
    }

    return ans;
}
```

</details>
