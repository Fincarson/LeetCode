# 1. Two Sum

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/two-sum/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 1 - Two Sum](https://leetcode.com/problems/two-sum/)

## Problem

You are given an integer array `nums` and an integer `target`.

Return the indices of two different elements whose values add up to `target`.

The input is guaranteed to have exactly one valid answer, and the same array element cannot be used twice. The returned indices may be in any order.

## Examples

### Example 1

```text
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9.
```

### Example 2

```text
Input: nums = [3, 2, 4], target = 6
Output: [1, 2]
```

### Example 3

```text
Input: nums = [3, 3], target = 6
Output: [0, 1]
```

## Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Exactly one valid answer exists.

## Follow-Up

Can this be solved in better than `O(n^2)` time?

## Hints

<details>
<summary><strong>Hint 1</strong></summary>

Start with the brute-force idea: check every pair. It is slower, but it makes the required condition very clear.

</details>

<details>
<summary><strong>Hint 2</strong></summary>

For a fixed value `x`, the other value must be `target - x`. The main problem is finding that complement quickly.

</details>

<details>
<summary><strong>Hint 3</strong></summary>

A hash table can store values you have already seen, letting you check whether the needed complement exists in constant average time.

</details>

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [3Sum](https://leetcode.com/problems/3sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [4Sum](https://leetcode.com/problems/4sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Good Meals](https://leetcode.com/problems/count-good-meals/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find Subarrays With Equal Sum](https://leetcode.com/problems/find-subarrays-with-equal-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
