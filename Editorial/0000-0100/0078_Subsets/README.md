# 78. Subsets

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/subsets/)  
`Array` `Backtracking` `Bit Manipulation`

**Problem Link:** [LeetCode 78 - Subsets](https://leetcode.com/problems/subsets/)

## Problem

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

### Example 1

```text
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

### Example 2

```text
Input: nums = [0]
Output: [[],[0]]
```

## Constraints

- 1 <= nums.length <= 10
- -10 <= nums[i] <= 10
- All the numbers of nums are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subsets II](https://leetcode.com/problems/subsets-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Generalized Abbreviation](https://leetcode.com/problems/generalized-abbreviation/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Array Given Subset Sums](https://leetcode.com/problems/find-array-given-subset-sums/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 78. Subsets

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Cascading | C++, Java, Python3 |
| Backtracking | C++, Java, Python3 |
| Lexicographic (Binary Sorted) Subsets | C++, Java, Python3 |

## Approach 1: Cascading

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        output.push_back({});
        for (int num : nums) {
            vector<vector<int>> newSubsets;
            for (vector<int> curr : output) {
                vector<int> temp = curr;
                temp.push_back(num);
                newSubsets.push_back(temp);
            }
            for (vector<int> curr : newSubsets) {
                output.push_back(curr);
            }
        }
        return output;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> output = new ArrayList();
        output.add(new ArrayList());

        for (int num : nums) {
            List<List<Integer>> newSubsets = new ArrayList();
            for (List<Integer> curr : output) {
                List<Integer> temp = new ArrayList(curr);
                temp.add(num);
                newSubsets.add(temp);
            }
            for (List<Integer> curr : newSubsets) {
                output.add(curr);
            }
        }
        return output;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def subsets(self, nums):
        output = [[]]
        for num in nums:
            newSubsets = []
            for curr in output:
                temp = curr.copy()
                temp.append(num)
                newSubsets.append(temp)
            for curr in newSubsets:
                output.append(curr)
        return output
```

</details>

<br>

## Approach 2: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> output;
    int n;
    
    void backtrack(int first, vector<int> curr, vector<int>& nums) {
        // Add the current combination to the output
        output.push_back(curr);
        
        // Explore further combinations
        for (int i = first; i < n; ++i) {
            // Add the next element to the current combination
            curr.push_back(nums[i]);
            // Recurse to form the next combination
            backtrack(i + 1, curr, nums);
            // Backtrack and remove the last element
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        backtrack(0, curr, nums); // Call once to generate all subsets
        return output;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private List<List<Integer>> output = new ArrayList();
    private int n;

    public void backtrack(int first, ArrayList<Integer> curr, int[] nums) {
        // Add the current subset to the output
        output.add(new ArrayList(curr));
        // Generate subsets starting from the current index
        for (int i = first; i < n; ++i) {
            curr.add(nums[i]);
            backtrack(i + 1, curr, nums);
            curr.remove(curr.size() - 1);
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        n = nums.length;
        ArrayList<Integer> currCombo = new ArrayList<Integer>();
        backtrack(0, currCombo, nums); // One call generates all subsets
        return output;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def subsets(self, nums):
        self.output = []
        self.n = len(nums)
        self.backtrack(0, [], nums)
        return self.output

    def backtrack(self, first, curr, nums):
        # Add the current subset to the output
        self.output.append(curr[:])
        # Generate subsets starting from the current index
        for i in range(first, self.n):
            curr.append(nums[i])
            self.backtrack(i + 1, curr, nums)
            curr.pop()
```

</details>

<br>

## Approach 3: Lexicographic (Binary Sorted) Subsets

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int nthBit = 1 << n;
for (int i = 0; i < nthBit; ++i) {  // equivalent to pow(2, n)
    // generate bitmask, from 0..00 to 1..11
    string bitmask = bitset<n + 1>(i | nthBit).to_string().substr(32 - n);
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
int nthBit = 1 << n;
for (int i = 0; i < nthBit; ++i) {  // equivalent to (int)Math.pow(2, n)
    // generate bitmask, from 0..00 to 1..11
    String bitmask = Integer.toBinaryString(i | nthBit).substring(1);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
nth_bit = 1 << n
for i in range(nth_bit):  # equivalent to 2**n
    # generate bitmask, from 0..00 to 1..11
    bitmask = bin(i | nth_bit)[3:]
```

</details>
