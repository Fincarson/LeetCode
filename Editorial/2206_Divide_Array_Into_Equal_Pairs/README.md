# 2206. Divide Array Into Equal Pairs

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/divide-array-into-equal-pairs/)  
`Array` `Hash Table` `Bit Manipulation` `Counting`

**Problem Link:** [LeetCode 2206 - Divide Array Into Equal Pairs](https://leetcode.com/problems/divide-array-into-equal-pairs/)

## Problem

You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

- Each element belongs to exactly one pair.
- The elements present in a pair are equal.

Return true if nums can be divided into n pairs, otherwise return false.

### Example 1

```text
Input: nums = [3,2,3,2,2,2]
Output: true
Explanation:
There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.
```

### Example 2

```text
Input: nums = [1,2,3,4]
Output: false
Explanation:
There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy every condition.
```

## Constraints

- nums.length == 2 * n
- 1 <= n <= 500
- 1 <= nums[i] <= 500

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Distribute Elements Into Two Arrays I](https://leetcode.com/problems/distribute-elements-into-two-arrays-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Distribute Elements Into Two Arrays II](https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2206. Divide Array Into Equal Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, Python3 |
| Map | C++, Java, Python3 |
| Boolean Array | C++, Java, Python3 |
| Hash Set | C++, Java, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Sort array to group equal elements together
        sort(nums.begin(), nums.end());

        // Check consecutive pairs in sorted array
        for (int pos = 0; pos < nums.size(); pos += 2) {
            // If any pair doesn't match, we can't form n equal pairs
            if (nums[pos] != nums[pos + 1]) {
                return false;
            }
        }

        // All pairs found successfully
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean divideArray(int[] nums) {
        // Sort array to group equal elements together
        Arrays.sort(nums);

        // Check consecutive pairs in sorted array
        for (int pos = 0; pos < nums.length; pos += 2) {
            // If any pair doesn't match, we can't form n equal pairs
            if (nums[pos] != nums[pos + 1]) {
                return false;
            }
        }

        // All pairs found successfully
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        # Sort array to group equal elements together
        nums.sort()
        # Check consecutive pairs in sorted array
        return all(nums[i] == nums[i + 1] for i in range(0, len(nums), 2))
```

</details>

<br>

## Approach 2: Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Count frequency of each number
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }

        // Check if each number appears an even number of times
        for (auto& entry : frequency) {
            if (entry.second % 2 != 0) {
                return false;
            }
        }

        // All numbers can be paired
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean divideArray(int[] nums) {
        // Count frequency of each number
        Map<Integer, Integer> frequency = new HashMap<>();
        for (int num : nums) {
            frequency.put(num, frequency.getOrDefault(num, 0) + 1);
        }

        // Check if each number appears even number of times
        for (int num : frequency.keySet()) {
            if (frequency.get(num) % 2 != 0) {
                return false;
            }
        }

        // All numbers can be paired
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        # Count frequency of each number using Counter
        frequency = Counter(nums)

        # Check if each number appears even number of times
        return all(count % 2 == 0 for count in frequency.values())
```

</details>

<br>

## Approach 3: Boolean Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Find maximum value in array
        int maxNum = 0;
        for (int num : nums) {
            maxNum = max(num, maxNum);
        }

        // Toggle pair status for each number
        vector<bool> needsPair(maxNum + 1, false);
        for (int num : nums) {
            needsPair[num] = !needsPair[num];
        }

        // Check if any number remains unpaired
        for (int num : nums) {
            if (needsPair[num]) {
                return false;
            }
        }

        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean divideArray(int[] nums) {
        // Find maximum value in array
        int maxNum = 0;
        for (int num : nums) {
            maxNum = Math.max(num, maxNum);
        }

        // Toggle pair status for each number
        boolean[] needsPair = new boolean[maxNum + 1];
        for (int num : nums) {
            needsPair[num] = !needsPair[num];
        }

        // Check if any number remains unpaired
        for (int num : nums) {
            if (needsPair[num]) {
                return false;
            }
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        # Find maximum value in array
        max_num = max(nums)

        # Toggle pair status for each number
        needs_pair = [False] * (max_num + 1)
        for num in nums:
            needs_pair[num] = not needs_pair[num]

        # Check if any number remains unpaired
        return not any(needs_pair[num] for num in nums)
```

</details>

<br>

## Approach 4: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Track unpaired numbers
        unordered_set<int> unpaired;

        // Add numbers to set if unseen, remove if seen
        for (int num : nums) {
            if (unpaired.count(num)) {
                unpaired.erase(num);
            } else {
                unpaired.insert(num);
            }
        }

        // Return true if all numbers were paired
        return unpaired.empty();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean divideArray(int[] nums) {
        // Track unpaired numbers
        Set<Integer> unpaired = new HashSet<>();

        // Add numbers to set if unseen, remove if seen
        for (int num : nums) {
            if (unpaired.contains(num)) {
                unpaired.remove(num);
            } else {
                unpaired.add(num);
            }
        }

        // Return true if all numbers were paired
        return unpaired.isEmpty();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        # Track unpaired numbers
        unpaired = set()

        # Add numbers to set if unseen, remove if seen
        for num in nums:
            if num in unpaired:
                unpaired.remove(num)
            else:
                unpaired.add(num)

        # Return true if all numbers were paired
        return not unpaired
```

</details>
