# 1636. Sort Array by Increasing Frequency

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/sort-array-by-increasing-frequency/)  
`Array` `Hash Table` `Sorting`

**Problem Link:** [LeetCode 1636 - Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency/)

## Problem

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

### Example 1

```text
Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
```

### Example 2

```text
Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
```

### Example 3

```text
Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
```

## Constraints

- 1 <= nums.length <= 100
- -100 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Divide Array Into Equal Pairs](https://leetcode.com/problems/divide-array-into-equal-pairs/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Most Frequent Number Following Key In an Array](https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Number of Pairs in Array](https://leetcode.com/problems/maximum-number-of-pairs-in-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Node With Highest Edge Score](https://leetcode.com/problems/node-with-highest-edge-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sort the People](https://leetcode.com/problems/sort-the-people/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1636. Sort Array by Increasing Frequency

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Customized Sorting | C++, Java, Python3 |

## Approach: Customized Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) {
                return a > b;
            }
            return freq[a] < freq[b];
        });

        return nums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        // Java's Arrays.sort method doesn't directly support
        // sorting primitive arrays (int[]) with a lambda comparator.
        // We can convert the primitive int into Integer objects
        // to get around this limitation.
        Integer[] numsObj = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            numsObj[i] = nums[i];
        }

        Arrays.sort(numsObj, (a, b) -> {
            if (freq.get(a).equals(freq.get(b))) {
                return Integer.compare(b, a);
            }
            return Integer.compare(freq.get(a), freq.get(b));
        });

        // Convert numsObj back to a primitive array to match
        // return type.
        for (int i = 0; i < nums.length; i++) {
            nums[i] = numsObj[i];
        }

        return nums;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter


class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        freq = Counter(nums)
        return sorted(nums, key=lambda x: (freq[x], -x))
```

</details>
