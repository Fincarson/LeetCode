# 26. Remove Duplicates from Sorted Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)  
`Array` `Two Pointers`

**Problem Link:** [LeetCode 26 - Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

## Problem

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be kÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Custom Judge:

The judge will test your solution with the following code:

```text
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be accepted.

### Example 1

```text
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

### Example 2

```text
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

## Constraints

- 1 <= nums.length <= 3 * 104
- -100 <= nums[i] <= 100
- nums is sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Element](https://leetcode.com/problems/remove-element/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Apply Operations to an Array](https://leetcode.com/problems/apply-operations-to-an-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sum of Distances](https://leetcode.com/problems/sum-of-distances/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 26. Remove Duplicates from Sorted Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Two indexes approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Two indexes approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int removeDuplicates(int* nums, int numsSize) {
    int insertIndex = 1;
    for (int i = 1; i < numsSize; i++) {
        // We skip to next index if we see a duplicate element
        if (nums[i - 1] != nums[i]) {
            /* Storing the unique element at insertIndex index and incrementing
               the insertIndex by 1 */
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }
    return insertIndex;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIndex = 1;
        for (int i = 1; i < nums.size(); i++) {
            // We skip to next index if we see a duplicate element
            if (nums[i - 1] != nums[i]) {
                // Storing the unique element at insertIndex index and
                // incrementing the insertIndex by 1
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }
        return insertIndex;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int insertIndex = 1;
        for (int i = 1; i < nums.Length; i++) {
            // We skip to next index if we see a duplicate element
            if (nums[i - 1] != nums[i]) {
                /* Storing the unique element at insertIndex index and
                   incrementing the insertIndex by 1 */
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }

        return insertIndex;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func removeDuplicates(nums []int) int {
    insertIndex := 1
    for i := 1; i < len(nums); i++ {
        if nums[i-1] != nums[i] {
            nums[insertIndex] = nums[i]
            insertIndex++
        }
    }
    return insertIndex
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int insertIndex = 1;
        for (int i = 1; i < nums.length; i++) {
            // We skip to next index if we see a duplicate element
            if (nums[i - 1] != nums[i]) {
                /* Storing the unique element at insertIndex index and incrementing
                   the insertIndex by 1 */
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }
        return insertIndex;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var removeDuplicates = function (nums) {
    let insertIndex = 1;
    for (let i = 1; i < nums.length; i++) {
        // We skip to next index if we see a duplicate element
        if (nums[i - 1] != nums[i]) {
            /* Storing the unique element at insertIndex index and incrementing
               the insertIndex by 1 */
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }
    return insertIndex;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        size = len(nums)
        insertIndex = 1
        for i in range(1, size):
            # Found unique element
            if nums[i - 1] != nums[i]:
                # Updating insertIndex in our main array
                nums[insertIndex] = nums[i]
                # Incrementing insertIndex count by 1
                insertIndex = insertIndex + 1
        return insertIndex
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function removeDuplicates(nums: number[]): number {
    let insertIndex: number = 1;
    for (let i: number = 1; i < nums.length; i++) {
        // We skip to next index if we see a duplicate element
        if (nums[i - 1] != nums[i]) {
            /* Storing the unique element at insertIndex index and incrementing
               the insertIndex by 1 */
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }
    return insertIndex;
}
```

</details>
