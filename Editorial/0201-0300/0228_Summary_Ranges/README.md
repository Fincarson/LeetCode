# 228. Summary Ranges

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/summary-ranges/)  
`Array`

**Problem Link:** [LeetCode 228 - Summary Ranges](https://leetcode.com/problems/summary-ranges/)

## Problem

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

- "a->b" if a != b
- "a" if a == b

### Example 1

```text
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
```

### Example 2

```text
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
```

## Constraints

- 0 <= nums.length <= 20
- -231 <= nums[i] <= 231 - 1
- All the values of nums are unique.
- nums is sorted in ascending order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Missing Ranges](https://leetcode.com/problems/missing-ranges/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find Maximal Uncovered Ranges](https://leetcode.com/problems/find-maximal-uncovered-ranges/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 228. Summary Ranges

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Fix Left Bound | C++, Java, Python3 |

## Approach: Fix Left Bound

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;

        for (int i = 0; i < nums.size(); i++) {
            int start = nums[i];
            // Keep iterating until the next element is one more than the current element.
            while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1]) {
                i++;
            }

            if (start != nums[i]) {
                ranges.push_back(to_string(start) + "->" + to_string(nums[i]));
            } else {
                ranges.push_back(to_string(start));
            }
        }

        return ranges;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ranges = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            int start = nums[i];
            // Keep iterating until the next element is one more than the current element.
            while (i + 1 < nums.length && nums[i] + 1 == nums[i + 1]) {
                i++;
            }

            if (start != nums[i]) {
                ranges.add(start + "->" + nums[i]);
            } else {
                ranges.add(String.valueOf(start));
            }
        }

        return ranges;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ranges = []     
        i = 0 
        
        while i < len(nums): 
            start = nums[i]  
            while i + 1 < len(nums) and nums[i] + 1 == nums[i + 1]: 
                i += 1 
            
            if start != nums[i]: 
                ranges.append(str(start) + "->" + str(nums[i]))
            else: 
                ranges.append(str(nums[i]))
            
            i += 1

        return ranges
```

</details>
