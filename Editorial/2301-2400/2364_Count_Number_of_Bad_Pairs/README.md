# 2364. Count Number of Bad Pairs

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-number-of-bad-pairs/)  
`Array` `Hash Table` `Math` `Counting`

**Problem Link:** [LeetCode 2364 - Count Number of Bad Pairs](https://leetcode.com/problems/count-number-of-bad-pairs/)

## Problem

You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

### Example 1

```text
Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
```

### Example 2

```text
Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Nice Pairs in an Array](https://leetcode.com/problems/count-nice-pairs-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Equal and Divisible Pairs in an Array](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Number of Pairs Satisfying Inequality](https://leetcode.com/problems/number-of-pairs-satisfying-inequality/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2364. Count Number of Bad Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Map | C++, Java, Python3 |

## Approach: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> diffCount;

        for (int pos = 0; pos < nums.size(); pos++) {
            int diff = pos - nums[pos];

            // Count of previous positions with same difference
            int goodPairsCount = diffCount[diff];

            // Total possible pairs minus good pairs = bad pairs
            badPairs += pos - goodPairsCount;

            // Update count of positions with this difference
            diffCount[diff] = goodPairsCount + 1;
        }

        return badPairs;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long countBadPairs(int[] nums) {
        long badPairs = 0;
        Map<Integer, Integer> diffCount = new HashMap<>();

        for (int pos = 0; pos < nums.length; pos++) {
            int diff = pos - nums[pos];

            // Count of previous positions with same difference
            int goodPairsCount = diffCount.getOrDefault(diff, 0);

            // Total possible pairs minus good pairs = bad pairs
            badPairs += pos - goodPairsCount;

            // Update count of positions with this difference
            diffCount.put(diff, goodPairsCount + 1);
        }

        return badPairs;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        bad_pairs = 0
        diff_count = {}

        for pos in range(len(nums)):
            diff = pos - nums[pos]

            # Count of previous positions with same difference
            good_pairs_count = diff_count.get(diff, 0)

            # Total possible pairs minus good pairs = bad pairs
            bad_pairs += pos - good_pairs_count

            # Update count of positions with this difference
            diff_count[diff] = good_pairs_count + 1

        return bad_pairs
```

</details>
