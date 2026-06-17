# 2161. Partition Array According to Given Pivot

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/partition-array-according-to-given-pivot/)  
`Array` `Two Pointers` `Simulation`

**Problem Link:** [LeetCode 2161 - Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/)

## Problem

You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

- Every element less than pivot appears before every element greater than pivot.
- Every element equal to pivot appears in between the elements less than and greater than pivot.
- The relative order of the elements less than pivot and the elements greater than pivot is maintained.

		More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.

Return nums after the rearrangement.

### Example 1

```text
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation:
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
```

### Example 2

```text
Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
Explanation:
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
```

## Constraints

- 1 <= nums.length <= 105
- -106 <= nums[i] <= 106
- pivot equals to an element of nums.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Partition List](https://leetcode.com/problems/partition-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2161. Partition Array According to Given Pivot

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Lists | C++, Java, Python3 |
| Two Passes With Fixed Array | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |

## Approach 1: Dynamic Lists

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        list<int> less;
        list<int> equal;
        list<int> greater;

        for (auto num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num > pivot) {
                greater.push_back(num);
            } else {
                equal.push_back(num);
            }
        }

        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greater.begin(), greater.end());

        vector<int> ans;
        for (auto num : less) {
            ans.push_back(num);
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

    public int[] pivotArray(int[] nums, int pivot) {
        LinkedList<Integer> less = new LinkedList<>();
        LinkedList<Integer> equal = new LinkedList<>();
        LinkedList<Integer> greater = new LinkedList<>();
        for (int num : nums) {
            if (num < pivot) {
                less.add(num);
            } else if (num > pivot) {
                greater.add(num);
            } else {
                equal.add(num);
            }
        }
        less.addAll(equal);
        less.addAll(greater);

        int i = 0;
        int[] ans = new int[nums.length];
        for (int num : less) {
            ans[i++] = num;
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
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less = []
        equal = []
        greater = []

        for num in nums:
            if num < pivot:
                less.append(num)
            elif num > pivot:
                greater.append(num)
            else:
                equal.append(num)

        less.extend(equal)
        less.extend(greater)

        return less
```

</details>

<br>

## Approach 2: Two Passes With Fixed Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0;
        int equal = 0;
        for (int num : nums) {
            if (num < pivot)
                less++;
            else if (num == pivot)
                equal++;
        }

        vector<int> ans(nums.size());
        int lessI = 0;
        int equalI = less;
        int greaterI = less + equal;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num < pivot) {
                ans[lessI] = num;
                lessI++;
            } else if (num > pivot) {
                ans[greaterI] = num;
                greaterI++;
            } else {
                ans[equalI] = num;
                equalI++;
            }
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

    public int[] pivotArray(int[] nums, int pivot) {
        int less = 0;
        int equal = 0;
        for (int num : nums) {
            if (num < pivot) less++;
            else if (num == pivot) equal++;
        }

        int[] ans = new int[nums.length];
        int lessI = 0;
        int equalI = less;
        int greaterI = less + equal;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            if (num < pivot) {
                ans[lessI] = num;
                lessI++;
            } else if (num > pivot) {
                ans[greaterI] = num;
                greaterI++;
            } else {
                ans[equalI] = num;
                equalI++;
            }
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
    def pivotArray(self, nums, pivot):
        less = 0
        equal = 0
        for num in nums:
            if num < pivot:
                less += 1
            elif num == pivot:
                equal += 1

        ans = [0] * len(nums)
        lessI = 0
        equalI = less
        greaterI = less + equal
        for i in range(len(nums)):
            num = nums[i]
            if num < pivot:
                ans[lessI] = num
                lessI += 1
            elif num > pivot:
                ans[greaterI] = num
                greaterI += 1
            else:
                ans[equalI] = num
                equalI += 1

        return ans
```

</details>

<br>

## Approach 3: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int lessI = 0;
        int greaterI = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            if (nums[i] < pivot) {
                ans[lessI] = nums[i];
                lessI++;
            }
            if (nums[j] > pivot) {
                ans[greaterI] = nums[j];
                greaterI--;
            }
        }
        while (lessI <= greaterI) {
            ans[lessI] = pivot;
            lessI++;
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

    public int[] pivotArray(int[] nums, int pivot) {
        int[] ans = new int[nums.length];
        int lessI = 0;
        int greaterI = nums.length - 1;
        for (int i = 0, j = nums.length - 1; i < nums.length; i++, j--) {
            if (nums[i] < pivot) {
                ans[lessI] = nums[i];
                lessI++;
            }
            if (nums[j] > pivot) {
                ans[greaterI] = nums[j];
                greaterI--;
            }
        }
        while (lessI <= greaterI) {
            ans[lessI] = pivot;
            lessI++;
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
    def pivotArray(self, nums, pivot):
        ans = [0] * len(nums)
        less_i = 0
        greater_i = len(nums) - 1

        for i, j in zip(range(len(nums)), range(len(nums) - 1, -1, -1)):
            if nums[i] < pivot:
                ans[less_i] = nums[i]
                less_i += 1
            if nums[j] > pivot:
                ans[greater_i] = nums[j]
                greater_i -= 1

        while less_i <= greater_i:
            ans[less_i] = pivot
            less_i += 1

        return ans
```

</details>
