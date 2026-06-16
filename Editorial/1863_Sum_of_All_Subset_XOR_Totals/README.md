# 1863. Sum of All Subset XOR Totals

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/sum-of-all-subset-xor-totals/)  
`Array` `Math` `Backtracking` `Bit Manipulation` `Combinatorics` `Enumeration`

**Problem Link:** [LeetCode 1863 - Sum of All Subset XOR Totals](https://leetcode.com/problems/sum-of-all-subset-xor-totals/)

## Problem

The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

- For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.

Given an array nums, return the sum of all XOR totals for every subset of nums.

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

### Example 1

```text
Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
```

### Example 2

```text
Input: nums = [5,1,6]
Output: 28
Explanation: The 8 subsets of [5,1,6] are:
- The empty subset has an XOR total of 0.
- [5] has an XOR total of 5.
- [1] has an XOR total of 1.
- [6] has an XOR total of 6.
- [5,1] has an XOR total of 5 XOR 1 = 4.
- [5,6] has an XOR total of 5 XOR 6 = 3.
- [1,6] has an XOR total of 1 XOR 6 = 7.
- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
```

### Example 3

```text
Input: nums = [3,4,5,6,7,8]
Output: 480
Explanation: The sum of all XOR totals for every subset is 480.
```

## Constraints

- 1 <= nums.length <= 12
- 1 <= nums[i] <= 20

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1863. Sum of All Subset XOR Totals

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Generate All Subsets Using Backtracking | C++, Java, Python3 |
| Optimized Backtracking | C++, Java, Python3 |
| Bit Manipulation | C++, Java, Python3 |

## Approach 1: Generate All Subsets Using Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        // Generate all of the subsets
        generateSubsets(nums, 0, {}, subsets);

        // Compute the XOR total for each subset and add to the result
        int result = 0;
        for (auto& subset : subsets) {
            int subsetXORTotal = 0;
            for (int num : subset) {
                subsetXORTotal ^= num;
            }
            result += subsetXORTotal;
        }
        return result;
    }

private:
    void generateSubsets(const vector<int>& nums, int index, vector<int> subset,
                         vector<vector<int>>& subsets) {
        // Base case: index reached end of nums
        // Add the current subset to subsets
        if (index == nums.size()) {
            subsets.push_back(subset);
            return;
        }

        // Generate subsets with nums[i]
        subset.push_back(nums[index]);
        generateSubsets(nums, index + 1, subset, subsets);
        subset.pop_back();

        // Generate subsets without nums[i]
        generateSubsets(nums, index + 1, subset, subsets);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int subsetXORSum(int[] nums) {
        List<List<Integer>> subsets = new ArrayList<>();
        // Generate all of the subsets
        generateSubsets(nums, 0, new ArrayList<>(), subsets);

        // Compute the XOR total for each subset and add to the result
        int result = 0;
        for (List<Integer> subset : subsets) {
            int subsetXORTotal = 0;
            for (int num : subset) {
                subsetXORTotal ^= num;
            }
            result += subsetXORTotal;
        }
        return result;
    }

    private void generateSubsets(int[] nums, int index, List<Integer> subset, List<List<Integer>> subsets) {
        // Base case: index reached end of nums
        // Add the current subset to subsets
        if (index == nums.length) {
            subsets.add(new ArrayList<>(subset));
            return;
        }

        // Generate subsets with nums[i]
        subset.add(nums[index]);
        generateSubsets(nums, index + 1, subset, subsets);
        subset.remove(subset.size() - 1);

        // Generate subsets without nums[i]
        generateSubsets(nums, index + 1, subset, subsets);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def subsetXORSum(self, nums):

        def generate_subsets(nums, index, subset, subsets):
            # Base case: index reached end of nums
            # Add the current subset to subsets
            if index == len(nums):
                subsets.append(subset[:])
                return

            # Generate subsets with nums[i]
            subset.append(nums[index])
            generate_subsets(nums, index + 1, subset, subsets)
            subset.pop()

            # Generate subsets without nums[i]
            generate_subsets(nums, index + 1, subset, subsets)

        # Generate all of the subsets
        subsets = []
        generate_subsets(nums, 0, [], subsets)

        # Compute the XOR total for each subset and add to the result
        result = 0
        for subset in subsets:
            subset_XOR_total = 0
            for num in subset:
                subset_XOR_total ^= num
            result += subset_XOR_total

        return result
```

</details>

<br>

## Approach 2: Optimized Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return XORSum(nums, 0, 0); 
    }

private:
    int XORSum(vector<int>& nums, int index, int currentXOR) {
        // Return currentXOR when all elements in nums are already considered
        if (index == nums.size()) return currentXOR;

        // Calculate sum of subset xor with current element
        int withElement = XORSum(nums, index + 1, currentXOR ^ nums[index]);

        // Calculate sum of subset xor without current element
        int withoutElement = XORSum(nums, index + 1, currentXOR);

        // Return sum of xor totals
        return withElement + withoutElement;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int subsetXORSum(int[] nums) {
        return XORSum(nums, 0, 0);
    }

    private int XORSum(int[] nums, int index, int currentXOR) {
        // Return currentXOR when all elements in nums are already considered
        if (index == nums.length) return currentXOR;

        // Calculate sum of subset xor with current element
        int withElement = XORSum(nums, index + 1, currentXOR ^ nums[index]);

        // Calculate sum of subset xor without current element
        int withoutElement = XORSum(nums, index + 1, currentXOR);

        // Return sum of xor totals
        return withElement + withoutElement;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
    
        def XOR_sum( nums: List[int], index: int, current_XOR: int) -> int:
            # Return current_XOR when all elements in nums are already considered
            if index == len(nums): return current_XOR
            
            # Calculate sum of subset xor with current element
            with_element = XOR_sum(nums, index + 1, current_XOR ^ nums[index])
            
            # Calculate sum of subset xor without current element
            without_element = XOR_sum(nums, index + 1, current_XOR)
            
            # Return sum of xor totals
            return with_element + without_element

        return XOR_sum(nums, 0, 0)
```

</details>

<br>

## Approach 3: Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        // Capture each bit that is set in any of the elements
        for (int num : nums) {
            result |= num;
        }
        // Multiply by the number of subset XOR totals that will have each bit set
        return result << (nums.size() - 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int subsetXORSum(int[] nums) {
        int result = 0;
        // Capture each bit that is set in any of the elements
        for (int num : nums) {
            result |= num;
        }
        // Multiply by the number of subset XOR totals that will have each bit set
        return result << (nums.length - 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        result = 0
        # Capture each bit that is set in any of the elements
        for num in nums:
            result |= num
        # Multiply by the number of subset XOR totals that will have each bit set
        return result << (len(nums) - 1)
```

</details>
