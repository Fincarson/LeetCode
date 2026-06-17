# 75. Sort Colors

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sort-colors/)  
`Array` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 75 - Sort Colors](https://leetcode.com/problems/sort-colors/)

## Problem

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

### Example 1

```text
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

### Example 2

```text
Input: nums = [2,0,1]
Output: [0,1,2]
```

## Constraints

- n == nums.length
- 1 <= n <= 300
- nums[i] is either 0, 1, or 2.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort List](https://leetcode.com/problems/sort-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Wiggle Sort](https://leetcode.com/problems/wiggle-sort/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 75. Sort Colors

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| One Pass | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: One Pass

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Dutch National Flag problem solution.
void sortColors(int* nums, int numsSize) {
    // For all idx < p0 : nums[idx < p0] = 0
    // curr is an index of elements under consideration
    int p0 = 0, curr = 0;
    // For all idx > p2 : nums[idx > p2] = 2
    int p2 = numsSize - 1;
    while (curr <= p2) {
        if (nums[curr] == 0) {
            int temp = nums[p0];
            nums[p0++] = nums[curr];
            nums[curr++] = temp;
        } else if (nums[curr] == 2) {
            int temp = nums[curr];
            nums[curr] = nums[p2];
            nums[p2--] = temp;
        } else
            curr++;
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  /*
  Dutch National Flag problem solution.
  */
  void sortColors(vector<int>& nums) {
    // For all idx < p0 : nums[idx < p0] = 0
    // curr is an index of elements under consideration
    int p0 = 0, curr = 0;

    // For all idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    /*
    Dutch National Flag problem solution.
    */
    public void SortColors(int[] nums) {
        // For all idx < i : nums[idx < i] = 0
        // j is an index of elements under consideration
        var p0 = 0;
        var curr = 0;
        // For all idx > k : nums[idx > k] = 2
        var p2 = nums.Length - 1;
        while (curr <= p2) {
            if (nums[curr] == 0) {
                // Swap p0-th and curr-th elements
                // i++ and j++
                int temp = nums[p0];
                nums[p0++] = nums[curr];
                nums[curr++] = temp;
            } else if (nums[curr] == 2) {
                // Swap k-th and curr-th elements
                // p2--
                int temp = nums[curr];
                nums[curr] = nums[p2];
                nums[p2--] = temp;
            } else
                curr++;
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sortColors(nums []int) {
    /*
       Dutch National Flag problem solution.
    */
    p0, curr := 0, 0
    p2 := len(nums) - 1
    for curr <= p2 {
        if nums[curr] == 0 {
            nums[curr], nums[p0] = nums[p0], nums[curr]
            curr++
            p0++
        } else if nums[curr] == 2 {
            nums[curr], nums[p2] = nums[p2], nums[curr]
            p2--
        } else {
            curr++
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    /*
  Dutch National Flag problem solution.
  */
    public void sortColors(int[] nums) {
        // For all idx < i : nums[idx < i] = 0
        // j is an index of elements under consideration
        int p0 = 0, curr = 0;

        // For all idx > k : nums[idx > k] = 2
        int p2 = nums.length - 1;

        int tmp;
        while (curr <= p2) {
            if (nums[curr] == 0) {
                // Swap p0-th and curr-th elements
                // i++ and j++
                tmp = nums[p0];
                nums[p0++] = nums[curr];
                nums[curr++] = tmp;
            } else if (nums[curr] == 2) {
                // Swap k-th and curr-th elements
                // p2--
                tmp = nums[curr];
                nums[curr] = nums[p2];
                nums[p2--] = tmp;
            } else curr++;
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortColors = function (nums) {
    /*
    Dutch National Flag problem solution.
    */
    let p0 = 0,
        curr = 0;
    let p2 = nums.length - 1;
    while (curr <= p2) {
        if (nums[curr] == 0) {
            [nums[curr++], nums[p0++]] = [nums[p0], nums[curr]];
        } else if (nums[curr] == 2) {
            [nums[curr], nums[p2--]] = [nums[p2], nums[curr]];
        } else curr++;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Dutch National Flag problem solution.
        """
        # For all idx < p0 : nums[idx < p0] = 0
        # curr is an index of elements under consideration
        p0 = curr = 0

        # For all idx > p2 : nums[idx > p2] = 2
        p2 = len(nums) - 1

        while curr <= p2:
            if nums[curr] == 0:
                nums[p0], nums[curr] = nums[curr], nums[p0]
                p0 += 1
                curr += 1
            elif nums[curr] == 2:
                nums[curr], nums[p2] = nums[p2], nums[curr]
                p2 -= 1
            else:
                curr += 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sortColors(nums: number[]): void {
    /*
    Dutch National Flag problem solution.
    */
    let p0 = 0,
        curr = 0;
    let p2 = nums.length - 1;
    while (curr <= p2) {
        if (nums[curr] == 0) {
            [nums[curr++], nums[p0++]] = [nums[p0], nums[curr]];
        } else if (nums[curr] == 2) {
            [nums[curr], nums[p2--]] = [nums[p2], nums[curr]];
        } else curr++;
    }
}
```

</details>
