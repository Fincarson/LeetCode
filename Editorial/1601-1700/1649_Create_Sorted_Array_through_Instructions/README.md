# 1649. Create Sorted Array through Instructions

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/create-sorted-array-through-instructions/)  
`Array` `Binary Search` `Divide and Conquer` `Binary Indexed Tree` `Segment Tree` `Merge Sort` `Ordered Set`

**Problem Link:** [LeetCode 1649 - Create Sorted Array through Instructions](https://leetcode.com/problems/create-sorted-array-through-instructions/)

## Problem

Given an integer array instructions, you are asked to create a sorted array from the elements in instructions. You start with an empty container nums. For each element from left to right in instructions, insert it into nums. The cost of each insertion is the minimum of the following:

- The number of elements currently in nums that are strictly less than instructions[i].
- The number of elements currently in nums that are strictly greater than instructions[i].

For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].

Return the total cost to insert all elements from instructions into nums. Since the answer may be large, return it modulo 109 + 7

### Example 1

```text
Input: instructions = [1,5,6,2]
Output: 1
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
The total cost is 0 + 0 + 0 + 1 = 1.
```

### Example 2

```text
Input: instructions = [1,2,3,6,5,4]
Output: 3
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.
```

### Example 3

```text
Input: instructions = [1,3,3,3,2,4,2,1,2]
Output: 4
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3].
Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3].
Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4].
Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Insert 2 with cost min(1, 4) = 1, now nums = [1,2,2,3,3,3,4].
Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4].
Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4].
The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4.
```

## Constraints

- 1 <= instructions.length <= 105
- 1 <= instructions[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Sort Array by Moving Items to Empty Space](https://leetcode.com/problems/sort-array-by-moving-items-to-empty-space/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1649. Create Sorted Array through Instructions

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Segment Tree | C++, Java, Python3 |

## Approach 1: Segment Tree

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int m = (int)1e5 + 1;
        vector<int> tree(m * 2);

        long cost = 0;
        long MOD = (int)1e9 + 7;
        for (int x : instructions) {
            cost += min(query(0, x, tree, m), query(x + 1, m, tree, m));
            update(x, 1, tree, m);
        }
        return (int)(cost % MOD);
    }

    // implement Segment Tree
    void update(int index, int value, vector<int>& tree, int m) {
        index += m;
        tree[index] += value;
        for (index >>= 1; index > 0; index >>= 1)
            tree[index] = tree[index << 1] + tree[(index << 1) + 1];
    }

    int query(int left, int right, vector<int>& tree, int m) {
        int result = 0;
        for (left += m, right += m; left < right; left >>= 1, right >>= 1) {
            if ((left & 1) == 1) result += tree[left++];
            if ((right & 1) == 1) result += tree[--right];
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int createSortedArray(int[] instructions) {
        int m = (int) 1e5 + 1;
        int[] tree = new int[m * 2];

        long cost = 0;
        long MOD = (int) 1e9 + 7;
        for (int x : instructions) {
            cost += Math.min(query(0, x, tree, m), query(x + 1, m, tree, m));
            update(x, 1, tree, m);
        }
        return (int) (cost % MOD);
    }

    // implement Segment Tree
    private void update(int index, int value, int[] tree, int m) {
        index += m;
        tree[index] += value;
        for (index >>= 1; index > 0; index >>= 1)
            tree[index] = tree[index << 1] + tree[(index << 1) + 1];
    }

    private int query(int left, int right, int[] tree, int m) {
        int result = 0;
        for (left += m, right += m; left < right; left >>= 1, right >>= 1) {
            if ((left & 1) == 1)
                result += tree[left++];
            if ((right & 1) == 1)
                result += tree[--right];
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        # implement Segment Tree
        def update(index, value, tree, m):
            index += m
            tree[index] += value
            while index > 1:
                index >>= 1
                tree[index] = tree[index << 1] + tree[(index << 1)+1]

        def query(left, right, tree, m):
            result = 0
            left += m
            right += m
            while left < right:
                if left & 1:
                    result += tree[left]
                    left += 1
                left >>= 1
                if right & 1:
                    right -= 1
                    result += tree[right]
                right >>= 1
            return result

        MOD = 10**9+7
        m = max(instructions)+1
        tree = [0]*(2*m)
        cost = 0
        for x in instructions:
            left_cost = query(0, x, tree, m)
            right_cost = query(x+1, m, tree, m)
            cost += min(left_cost, right_cost)
            update(x, 1, tree, m)
        return cost % MOD
```

</details>
