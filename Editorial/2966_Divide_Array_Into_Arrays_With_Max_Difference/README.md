# 2966. Divide Array Into Arrays With Max Difference

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 2966 - Divide Array Into Arrays With Max Difference](https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/)

## Problem

You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:

- The difference between any two elements in one array is less than or equal to k.

Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

### Example 1

### Example 2

### Example 3

## Constraints

- n == nums.length
- 1 <= n <= 105
- n is a multiple of 3
- 1 <= nums[i] <= 105
- 1 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2966. Divide Array Into Arrays With Max Difference

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting | C++, Java, JavaScript, Python3 |

## Approach: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
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
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int[][] ans = new int[nums.length / 3][3];
        for (int i = 0; i < nums.length; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return new int[0][0];
            }
            ans[i / 3] = new int[]{nums[i], nums[i + 1], nums[i + 2]};
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var divideArray = function(nums, k) {
    nums.sort((a, b) => a - b);
    const ans = [];
    for (let i = 0; i < nums.length; i += 3) {
        if (nums[i + 2] - nums[i] > k) {
            return [];
        }
        ans.push([nums[i], nums[i + 1], nums[i + 2]]);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(0, len(nums), 3):
            if nums[i + 2] - nums[i] > k:
                return []
            ans.append([nums[i], nums[i + 1], nums[i + 2]])
        return ans
```

</details>
