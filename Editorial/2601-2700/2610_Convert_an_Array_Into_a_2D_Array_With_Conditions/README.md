# 2610. Convert an Array Into a 2D Array With Conditions

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 2610 - Convert an Array Into a 2D Array With Conditions](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/)

## Problem

You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

- The 2D array should contain only the elements of the array nums.
- Each row in the 2D array contains distinct integers.
- The number of rows in the 2D array should be minimal.

Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

### Example 1

```text
Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.
```

### Example 2

```text
Input: nums = [1,2,3,4]
Output: [[4,3,2,1]]
Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
```

## Constraints

- 1 <= nums.length <= 200
- 1 <= nums[i] <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2610. Convert an Array Into a 2D Array With Conditions

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Frequency Counter | C++, Java, Python3 |

## Approach: Frequency Counter

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(nums.size() + 1);

        vector<vector<int>> ans;
        for (int c : nums) {
            if (freq[c] >= ans.size()) {
                ans.push_back({});
            }

            // Store the integer in the list corresponding to its current
            // frequency.
            ans[freq[c]].push_back(c);
            freq[c]++;
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

    public List<List<Integer>> findMatrix(int[] nums) {
        int freq[] = new int[nums.length + 1];

        ArrayList<List<Integer>> ans = new ArrayList<>();
        for (int c : nums) {
            if (freq[c] >= ans.size()) {
                ans.add(new ArrayList<>());
            }

            // Store the integer in the list corresponding to its current frequency.
            ans.get(freq[c]).add(c);
            freq[c]++;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMatrix(self, nums: list[int]) -> list[list[int]]:
        freq = [0] * (len(nums) + 1)

        ans = []
        for c in nums:
            if freq[c] >= len(ans):
                ans.append([])

            # Store the integer in the list corresponding to its current frequency.
            ans[freq[c]].append(c)
            freq[c] += 1

        return ans
```

</details>
