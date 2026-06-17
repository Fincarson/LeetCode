# 491. Non-decreasing Subsequences

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/non-decreasing-subsequences/)  
`Array` `Hash Table` `Backtracking` `Bit Manipulation`

**Problem Link:** [LeetCode 491 - Non-decreasing Subsequences](https://leetcode.com/problems/non-decreasing-subsequences/)

## Problem

Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

### Example 1

```text
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
```

### Example 2

```text
Input: nums = [4,4,3,2,1]
Output: [[4,4]]
```

## Constraints

- 1 <= nums.length <= 15
- -100 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 491. Non-decreasing Subsequences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C++, Java, Python3 |
| Bitmasks | C++, Java, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> sequence;
        function<void(int)> backtrack;
        backtrack = [&nums, &sequence, &result, &backtrack](int index) -> void {
            // if we have checked all elements
            if (index == nums.size()) {
                if (sequence.size() >= 2) {
                    result.insert(sequence);
                }
                return;
            }
            // if the sequence remains increasing after appending nums[index]
            if (sequence.empty() || sequence.back() <= nums[index]) {
                // append nums[index] to the sequence
                sequence.push_back(nums[index]);
                // call recursively
                backtrack(index + 1);
                // delete nums[index] from the end of the sequence
                sequence.pop_back();
            }
            // call recursively not appending an element
            backtrack(index + 1);
        };
        backtrack(0);
        return vector(result.begin(), result.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private void backtrack(int[] nums, int index, List<Integer> sequence,
            Set<List<Integer>> result) {
        // if we have checked all elements
        if (index == nums.length) {
            if (sequence.size() >= 2) {
                result.add(new ArrayList<>(sequence));
            }
            return;
        }
        // if the sequence remains increasing after appending nums[index]
        if (sequence.isEmpty() ||
                sequence.get(sequence.size() - 1) <= nums[index]) {
            // append nums[index] to the sequence
            sequence.add(nums[index]);
            // call recursively
            backtrack(nums, index + 1, sequence, result);
            // delete nums[index] from the end of the sequence
            sequence.remove(sequence.size() - 1);
        }
        // call recursively not appending an element
        backtrack(nums, index + 1, sequence, result);
    }

    public List<List<Integer>> findSubsequences(int[] nums) {
        Set<List<Integer>> result = new HashSet<List<Integer>>();
        List<Integer> sequence = new ArrayList<Integer>();
        backtrack(nums, 0, sequence, result);
        return new ArrayList(result);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        result = set()
        sequence = []

        def backtrack(index):
            # if we have checked all elements
            if index == len(nums):
                if len(sequence) >= 2:
                    result.add(tuple(sequence))
                return
            # if the sequence remains increasing after appending nums[index]
            if not sequence or sequence[-1] <= nums[index]:
                # append nums[index] to the sequence
                sequence.append(nums[index])
                # call recursively
                backtrack(index + 1)
                # delete nums[index] from the end of the sequence
                sequence.pop()
            # call recursively not appending an element
            backtrack(index + 1)
        backtrack(0)
        return [list(x) for x in result]
```

</details>

<br>

## Approach 2: Bitmasks

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> result;
        for (int bitmask = 1; bitmask < (1 << n); bitmask++) {
            vector<int> sequence;
            for (int i = 0; i < n; i++) {
                // check the i-th bit of the bitmask
                if (((bitmask >> i) & 1) == 1) {
                    sequence.push_back(nums[i]);
                }
            }
            if (sequence.size() >= 2) {
                // check whether the sequence is increasing
                bool isIncreasing = true;
                for (int i = 0; i < sequence.size() - 1; i++) {
                    isIncreasing &= sequence[i] <= sequence[i + 1];
                }
                if (isIncreasing) {
                    result.insert(sequence);
                }
            }
        }
        return vector(result.begin(), result.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        int n = nums.length;
        Set<List<Integer>> result = new HashSet<List<Integer>>();
        for (int bitmask = 1; bitmask < (1 << n); bitmask++) {
            List<Integer> sequence = new ArrayList<Integer>();
            // check the i-th bit of the bitmask
            for (int i = 0; i < n; i++) {
                if (((bitmask >> i) & 1) == 1) {
                    sequence.add(nums[i]);
                }
            }
            if (sequence.size() >= 2) {
                // check whether the sequence is increasing
                boolean isIncreasing = true;
                for (int i = 0; i < sequence.size() - 1; i++) {
                    isIncreasing &= sequence.get(i) <= sequence.get(i + 1);
                }
                if (isIncreasing) {
                    result.add(sequence);
                }
            }
        }
        return new ArrayList(result);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        result = set()
        for bitmask in range(1, 1 << n):
            # build the sequence
            sequence = [nums[i] for i in range(n) if (bitmask >> i) & 1]
            # check if its length is at least 2, and it is increasing
            if len(sequence) >= 2 and all([sequence[i] <= sequence[i + 1]
                                          for i in range(len(sequence) - 1)]):
                result.add(tuple(sequence))
        return [list(x) for x in result]
```

</details>
