# 31. Next Permutation

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/next-permutation/)  
`Array` `Two Pointers`

**Problem Link:** [LeetCode 31 - Next Permutation](https://leetcode.com/problems/next-permutation/)

## Problem

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

- For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

- For example, the next permutation of arr = [1,2,3] is [1,3,2].
- Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
- While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

### Example 1

```text
Input: nums = [1,2,3]
Output: [1,3,2]
```

### Example 2

```text
Input: nums = [3,2,1]
Output: [1,2,3]
```

### Example 3

```text
Input: nums = [1,1,5]
Output: [1,5,1]
```

## Constraints

- 1 <= nums.length <= 100
- 0 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Permutations](https://leetcode.com/problems/permutations/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Permutations II](https://leetcode.com/problems/permutations-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Palindrome Permutation II](https://leetcode.com/problems/palindrome-permutation-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Adjacent Swaps to Reach the Kth Smallest Number](https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 31. Next Permutation

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Single Pass Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 2: Single Pass Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void reverse(int* nums, int start, int numsSize) {
    int i = start, j = numsSize - 1;
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}
void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    reverse(nums, i + 1, numsSize);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public void NextPermutation(int[] nums) {
        int i = nums.Length - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }

        if (i >= 0) {
            int j = nums.Length - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }

            Swap(nums, i, j);
        }

        Reverse(nums, i + 1);
    }

    private void Reverse(int[] nums, int start) {
        int i = start, j = nums.Length - 1;
        while (i < j) {
            Swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void Swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func nextPermutation(nums []int) {
    i := len(nums) - 2
    for i >= 0 && nums[i+1] <= nums[i] {
        i--
    }
    if i >= 0 {
        j := len(nums) - 1
        for nums[j] <= nums[i] {
            j--
        }
        swap(nums, i, j)
    }
    reverse(nums, i+1)
}

func reverse(nums []int, start int) {
    i, j := start, len(nums)-1
    for i < j {
        swap(nums, i, j)
        i++
        j--
    }
}

func swap(nums []int, i int, j int) {
    temp := nums[i]
    nums[i] = nums[j]
    nums[j] = temp
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.length - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }

    private void reverse(int[] nums, int start) {
        int i = start, j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var nextPermutation = function (nums) {
    let i = nums.length - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        let j = nums.length - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    reverse(nums, i + 1);
    function reverse(nums, start) {
        let i = start,
            j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    function swap(nums, i, j) {
        let temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0 and nums[i + 1] <= nums[i]:
            i -= 1
        if i >= 0:
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1
            self.swap(nums, i, j)
        self.reverse(nums, i + 1)

    def reverse(self, nums, start):
        i, j = start, len(nums) - 1
        while i < j:
            self.swap(nums, i, j)
            i += 1
            j -= 1

    def swap(self, nums, i, j):
        temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function nextPermutation(nums: number[]): void {
    let i = nums.length - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        let j = nums.length - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    reverse(nums, i + 1);
    function reverse(nums: number[], start: number): void {
        let i = start,
            j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    function swap(nums: number[], i: number, j: number): void {
        let temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```

</details>
